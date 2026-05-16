#include <cstdio>
#include "utils/card.h"
#include "libtww/include/MSL_C/math.h"
#include "libtww/include/MSL_C/string.h"
#include "libtww/include/SSystem/SComponent/c_malloc.h"
#include "libtww/include/SSystem/SComponent/c_counter.h"
#include "libtww/include/m_Do/m_Do_printf.h"
#include "fifo_queue.h"
#include "memfiles.h"
#include "save_manager.h"
#include "rels/include/defines.h"
#include "rels/include/cxx.h"
#include "menus/utils/menu_mgr.h"
#include "rels/include/defines.h"
#include "boot/include/commands.h"
#include "boot/include/equip_priority.h"
#include "menus/menu_settings/include/settings_menu.h"
#include "features/pause_buffer_input_tool/include/pause_buffer_input.h"

/**
 * @brief Like CARDWrite, but allows for arbitrary sizes and offsets.
 */
int32_t GZ_storageWrite(Storage* storage, void* data, int32_t size, int32_t offset, int32_t sector_size) {
    uint8_t* buf = new (-32) uint8_t[sector_size];
    int32_t result = Ready;
    int32_t read_bytes = 0;

    while (result == Ready && size > 0) {
        StorageRead(*storage, buf, sector_size, (offset & ~(sector_size - 1)));
        if (result != Ready) {
            break;
        }
        int32_t rem_size = sector_size - (offset & (sector_size - 1));
        memcpy(buf + (offset & (sector_size - 1)), (void*)((uint32_t)data + read_bytes), MIN(rem_size, size));
        StorageWrite(*storage, buf, sector_size, (offset & ~(sector_size - 1)));
        read_bytes += MIN(rem_size, size);
        size -= rem_size;
        offset += rem_size;
    }
    delete[] buf;
    return result;
}

/**
 * @brief Like CARDRead, but allows for arbitrary sizes and offsets.
 */
int32_t GZ_storageRead(Storage* storage, void* data, int32_t size, int32_t offset, int32_t sector_size) {
    uint8_t* buf = new (-32) uint8_t[sector_size];
    int32_t result = Ready;
    int32_t read_bytes = 0;

    while (result == Ready && size > 0) {
        StorageRead(*storage, buf, sector_size, (offset & ~(sector_size - 1)));
        if (result != Ready) {
            break;
        }
        int32_t rem_size = sector_size - (offset & (sector_size - 1));
        memcpy((void*)((uint32_t)data + read_bytes), buf + (offset & (sector_size - 1)), MIN(rem_size, size));
        read_bytes += MIN(rem_size, size);
        size -= rem_size;
        offset += rem_size;
    }
    delete[] buf;
    return result;
}

void GZ_storeSaveLayout(GZSaveLayout& save_layout) {
    memcpy(save_layout.mCheats, g_cheats, sizeof(g_cheats));
    memcpy(save_layout.mItemEquipSettings, g_item_equip_priorities, sizeof(g_item_equip_priorities));
    memcpy(save_layout.mTools, g_tools, sizeof(g_tools));
    memcpy(save_layout.mCommandStates, g_commandStates, sizeof(g_commandStates));
    memcpy(save_layout.mWatches, g_watches, sizeof(g_watches));
    memcpy(save_layout.mSpriteOffsets, g_spriteOffsets, sizeof(g_spriteOffsets));

    save_layout.mDropShadows = g_dropShadows;
    save_layout.mCursorColType = g_cursorColorType;
    save_layout.mFontType = g_fontType;
    save_layout.mEquipPriorityEnabled = g_equipPriorityEnabled;
    save_layout.mWaterSpeed = g_waterSpeed;
    save_layout.mLandSpeed = g_landSpeed;
    save_layout.mAngleValuesInDecimal = g_angleValuesInDecimal;
    save_layout.mCustomPositions = g_customSaveSpawns;
    save_layout.mBufferInput = g_buffer_input;
}

void GZ_loadSaveLayout(GZSaveLayout& save_layout) {
    memcpy(g_cheats, save_layout.mCheats, sizeof(g_cheats));
    memcpy(g_item_equip_priorities, save_layout.mItemEquipSettings, sizeof(g_item_equip_priorities));
    memcpy(g_tools, save_layout.mTools, sizeof(g_tools));
    memcpy(g_commandStates, save_layout.mCommandStates, sizeof(g_commandStates));
    memcpy(g_watches, save_layout.mWatches, sizeof(g_watches));
    memcpy(g_spriteOffsets, save_layout.mSpriteOffsets, sizeof(g_spriteOffsets));

    g_dropShadows = save_layout.mDropShadows;
    g_cursorColorType = save_layout.mCursorColType;
    g_fontType = save_layout.mFontType;
    g_equipPriorityEnabled = save_layout.mEquipPriorityEnabled;
    g_waterSpeed = save_layout.mWaterSpeed;
    g_landSpeed = save_layout.mLandSpeed;
    g_angleValuesInDecimal = save_layout.mAngleValuesInDecimal;
    g_customSaveSpawns = save_layout.mCustomPositions;
    g_buffer_input = save_layout.mBufferInput;
}

void GZ_setupSaveFile(GZSaveFile& save_file) {
    save_file.header.version = GZ_SAVE_VERSION_NUMBER;
    save_file.header.entries = SV_ENTRY_AMNT;
    save_file.header.offsetsLoc = offsetof(GZSaveFile, offsets);
    save_file.header.sizesLoc = offsetof(GZSaveFile, sizes);
#define set_entry(idx, attr)                                                                                           \
    save_file.offsets[idx] = offsetof(GZSaveFile, data) + offsetof(GZSaveLayout, attr);                                \
    save_file.sizes[idx] = sizeof(save_file.data.attr)

    set_entry(SV_CHEATS_INDEX, mCheats);
    set_entry(SV_ITEM_EQUIP_INDEX, mItemEquipSettings);
    set_entry(SV_TOOLS_INDEX, mTools);
    set_entry(SV_WATCHES_INDEX, mWatches);
    set_entry(SV_COMMANDS, mCommandStates);
    set_entry(SV_DROP_SHADOW_INDEX, mDropShadows);
    set_entry(SV_CURSOR_COLOR_INDEX, mCursorColType);
    set_entry(SV_FONT_INDEX, mFontType);
    set_entry(SV_SPRITES_INDEX, mSpriteOffsets);
    set_entry(SV_EQUIP_PRIORITY_INDEX, mEquipPriorityEnabled);
    set_entry(SV_WATERSPEED_INDEX, mWaterSpeed);
    set_entry(SV_LANDSPEED_INDEX, mLandSpeed);
    set_entry(SV_ANGLE_CONVERSION_INDEX, mAngleValuesInDecimal);
    set_entry(SV_CUSTOM_POSITIONS_INDEX, mCustomPositions);
    set_entry(SV_BUFFER_INPUT_INDEX, mBufferInput);
#undef set_entry
}

int32_t GZ_readSaveFile(Storage* storage, GZSaveFile& save_file, int32_t sector_size) {
    int32_t result = Ready;
#define assert_result(stmt)                                                                                            \
    if ((result = (stmt)) != Ready) {                                                                                  \
        return result;                                                                                                 \
    }

    uint32_t pos = 0;
    assert_result(GZ_storageRead(storage, &save_file.header, sizeof(save_file.header), pos, sector_size));
    pos += sizeof(save_file.header);
    if (save_file.header.version != GZ_SAVE_VERSION_NUMBER) {
        return -30;  // Custom error code for "Version" (means a mismatch in the version number).
    }
    assert_result(GZ_storageRead(storage, save_file.offsets, save_file.header.entries * sizeof(save_file.offsets[0]),
                                 save_file.header.offsetsLoc, sector_size));
    assert_result(GZ_storageRead(storage, save_file.sizes, save_file.header.entries * sizeof(save_file.sizes[0]),
                                 save_file.header.sizesLoc, sector_size));

#define assert_read_entry(idx, ptr, size)                                                                              \
    if (idx < save_file.header.entries) {                                                                              \
        assert_result(                                                                                                 \
            GZ_storageRead(storage, ptr, MIN(size, save_file.sizes[idx]), save_file.offsets[idx], sector_size));       \
    }
    assert_read_entry(SV_CHEATS_INDEX, save_file.data.mCheats, sizeof(save_file.data.mCheats));
    assert_read_entry(SV_ITEM_EQUIP_INDEX, save_file.data.mItemEquipSettings,
                      sizeof(save_file.data.mItemEquipSettings));
    assert_read_entry(SV_TOOLS_INDEX, save_file.data.mTools, sizeof(save_file.data.mTools));
    assert_read_entry(SV_WATCHES_INDEX, save_file.data.mWatches, sizeof(save_file.data.mWatches));
    assert_read_entry(SV_COMMANDS, save_file.data.mCommandStates, sizeof(save_file.data.mCommandStates));
    assert_read_entry(SV_DROP_SHADOW_INDEX, &save_file.data.mDropShadows, sizeof(save_file.data.mDropShadows));
    assert_read_entry(SV_CURSOR_COLOR_INDEX, &save_file.data.mCursorColType, sizeof(save_file.data.mCursorColType));
    assert_read_entry(SV_FONT_INDEX, &save_file.data.mFontType, sizeof(save_file.data.mFontType));
    assert_read_entry(SV_SPRITES_INDEX, save_file.data.mSpriteOffsets, sizeof(save_file.data.mSpriteOffsets));
    assert_read_entry(SV_EQUIP_PRIORITY_INDEX, &save_file.data.mEquipPriorityEnabled,
                      sizeof(save_file.data.mEquipPriorityEnabled));
    assert_read_entry(SV_WATERSPEED_INDEX, &save_file.data.mWaterSpeed, sizeof(save_file.data.mWaterSpeed));
    assert_read_entry(SV_LANDSPEED_INDEX, &save_file.data.mLandSpeed, sizeof(save_file.data.mLandSpeed));
    assert_read_entry(SV_ANGLE_CONVERSION_INDEX, &save_file.data.mAngleValuesInDecimal,
                      sizeof(save_file.data.mAngleValuesInDecimal));
    assert_read_entry(SV_CUSTOM_POSITIONS_INDEX, &save_file.data.mCustomPositions,
                      sizeof(save_file.data.mCustomPositions));
    assert_read_entry(SV_BUFFER_INPUT_INDEX, &save_file.data.mBufferInput, sizeof(save_file.data.mBufferInput));
#undef assert_read_entry
#undef assert_result

    return result;
}

KEEP_FUNC void GZ_storeMemCard(Storage& storage) {
    GZSaveFile save_file;
    GZ_setupSaveFile(save_file);
    GZ_storeSaveLayout(save_file.data);
    uint32_t file_size =
        (uint32_t)(ceil((double)sizeof(save_file) / (double)storage.sector_size) * storage.sector_size);
    storage.result = StorageDelete(0, storage.file_name_buffer);
    storage.result = StorageCreate(0, storage.file_name_buffer, file_size, &storage.info);
    if (storage.result == Ready || storage.result == Exist) {
        storage.result = StorageOpen(0, storage.file_name_buffer, &storage.info, OPEN_MODE_RW);
        if (storage.result == Ready) {
            storage.result = GZ_storageWrite(&storage, &save_file, sizeof(save_file), 0, storage.sector_size);
            if (storage.result == Ready) {
                OSReport("saved card!\n");
                FIFOQueue::push("saved card!", Queue);
            } else {
                OSReport("failed to save\n");
                char buff[32];
                snprintf(buff, sizeof(buff), "failed to save: %d", storage.result);
                FIFOQueue::push(buff, Queue);
            }
            storage.result = StorageClose(&storage.info);
        }
    }
}

KEEP_FUNC void GZ_deleteMemCard(Storage& storage) {
    storage.result = StorageDelete(0, storage.file_name_buffer);
    if (storage.result == Ready) {
        FIFOQueue::push("deleted card!", Queue);
    } else {
        char buff[32];
        snprintf(buff, sizeof(buff), "failed to delete: %d", storage.result);
        FIFOQueue::push(buff, Queue);
    }
}

KEEP_FUNC void GZ_loadMemCard(Storage& storage) {
    storage.result = StorageOpen(0, storage.file_name_buffer, &storage.info, OPEN_MODE_RW);
    if (storage.result == Ready) {
        GZSaveFile save_file;
        GZ_storeSaveLayout(save_file.data);
        storage.result = GZ_readSaveFile(&storage, save_file, storage.sector_size);
        if (storage.result == Ready) {
            FIFOQueue::push("loaded card!", Queue);
            GZ_loadSaveLayout(save_file.data);
            GZ_initFont();
        } else {
            char buff[32];
            snprintf(buff, sizeof(buff), "failed to load: %d", storage.result);
            FIFOQueue::push(buff, Queue);
        }
        storage.result = StorageClose(&storage.info);
    }
}

#define FILE_NAME "twwgz01"

KEEP_FUNC void GZ_loadGZSave(bool& card_load) {
    if (card_load) {
        static Storage storage;
        storage.file_name = FILE_NAME;
        storage.sector_size = SECTOR_SIZE;
        snprintf(storage.file_name_buffer, sizeof(storage.file_name_buffer), (char*)storage.file_name);

        storage.result = CARDProbeEx(0, NULL, &storage.sector_size);
        if (storage.result == Ready) {
            GZ_loadMemCard(storage);
        }

        card_load = false;
    }
}

KEEP_FUNC bool GZ_memfileExists(Storage& storage) {
    storage.result = CARDProbeEx(0, NULL, &storage.sector_size);
    if (storage.result != Ready) {
        return false;
    }
    storage.result = StorageOpen(0, storage.file_name_buffer, &storage.info, OPEN_MODE_READ);
    if (storage.result == Ready) {
        storage.result = StorageClose(&storage.info);
        return true;
    }
    return false;
}

KEEP_FUNC void GZ_loadMemfile(Storage& storage) {
    storage.result = StorageOpen(0, storage.file_name_buffer, &storage.info, OPEN_MODE_RW);
    if (storage.result == Ready) {
        PositionData posData;
        OSReport("GZ_loadMemfile: reading position data at 0x%x\n", sizeof(dSv_info_c) + 1);
        storage.result = GZ_readMemfile(&storage, posData, storage.sector_size);
        OSReport("GZ_loadMemfile: result: %d\n", storage.result);
        OSReport("GZ_loadMemfile: position: {%f, %f, %f}\n", posData.link.x, posData.link.y, posData.link.z);
        OSReport("GZ_loadMemfile: angle: %f\n", posData.angle);
        OSReport("GZ_loadMemfile: cam target: {%f, %f, %f}\n", posData.cam.target.x, posData.cam.target.y,
                 posData.cam.target.z);
        OSReport("GZ_loadMemfile: cam pos: {%f, %f, %f}\n", posData.cam.pos.x, posData.cam.pos.y, posData.cam.pos.z);

        if (storage.result == Ready) {
            FIFOQueue::push("loaded memfile!", Queue);
            gSaveManager.mPracticeFileOpts.inject_options_during_load = GZ_setLinkPosition;
            SaveManager::prepareStage();
            GZ_loadPositionData(posData);
            g_menuMgr->hide();
        } else {
            char buff[32];
            snprintf(buff, sizeof(buff), "failed to load: %d", storage.result);
            FIFOQueue::push(buff, Queue);
        }
        storage.result = StorageClose(&storage.info);
        SaveManager::s_injectMemfile = true;
    }
}

KEEP_FUNC int32_t GZ_readMemfile(Storage* storage, PositionData& posData, int32_t sector_size) {
    int32_t result = Ready;
#define assert_result(stmt)                                                                                            \
    if ((result = (stmt)) != Ready) {                                                                                  \
        return result;                                                                                                 \
    }

    assert_result(GZ_storageRead(storage, MEMFILE_BUF, sizeof(dSv_save_c), 0, sector_size));

    assert_result(GZ_storageRead(storage, &posData, sizeof(posData), sizeof(dSv_save_c) + 1, sector_size));

#undef assert_result
    return result;
}

void GZ_loadPositionData(PositionData& pos_data) {
    memfile_posdata.link = pos_data.link;
    memfile_posdata.cam.target = pos_data.cam.target;
    memfile_posdata.cam.pos = pos_data.cam.pos;
    memfile_posdata.angle = pos_data.angle;
}

KEEP_FUNC void GZ_storeMemfile(Storage& storage) {
    PositionData posData;
    posData.link = dComIfGp_getPlayer(0)->current.pos;
    posData.cam = dComIfg_getCamPosAndTarget();
    posData.angle = dComIfGp_getPlayer(0)->shape_angle.y;
    OSReport("GZ_storeMemfile: stage: {%s, %d, %d}\n", dComIfGp_getStartStage()->mName, dStage_roomControl_c__mStayNo,
             GZ_validSpawnPoint(dComIfGp_getStartStage()->mName, dStage_roomControl_c__mStayNo,
                                dComIfGp_getStartStage()->mPoint));
    OSReport("GZ_storeMemfile: position: {%f, %f, %f}\n", posData.link.x, posData.link.y, posData.link.z);
    OSReport("GZ_storeMemfile: angle: %d\n", posData.angle);
    OSReport("GZ_storeMemfile: cam target: {%f, %f, %f}\n", posData.cam.target.x, posData.cam.target.y,
             posData.cam.target.z);
    OSReport("GZ_storeMemfile: cam pos: {%f, %f, %f}\n", posData.cam.pos.x, posData.cam.pos.y, posData.cam.pos.z);
    uint32_t file_size =
        (uint32_t)(ceil((double)(sizeof(dSv_save_c) + 1 + sizeof(PositionData)) / (double)storage.sector_size) *
                   storage.sector_size);

    storage.result = StorageDelete(0, storage.file_name_buffer);
    storage.result = StorageCreate(0, storage.file_name_buffer, file_size, &storage.info);

    if (storage.result == Ready || storage.result == Exist) {
        storage.result = StorageOpen(0, storage.file_name_buffer, &storage.info, OPEN_MODE_RW);
        if (storage.result == Ready) {
            dComIfGs_putSave(g_dComIfG_gameInfo.info.mDan.mStageNo);

            strcpy(g_dComIfG_gameInfo.info.getPlayer().mReturnPlace.mName, dComIfGp_getStartStage()->mName);
            g_dComIfG_gameInfo.info.getPlayer().mReturnPlace.mPoint = GZ_validSpawnPoint(
                dComIfGp_getStartStage()->mName, dStage_roomControl_c__mStayNo, dComIfGp_getStartStage()->mPoint);
            g_dComIfG_gameInfo.info.getPlayer().mReturnPlace.mRoomNo = dStage_roomControl_c__mStayNo;

            uint8_t* data = new (-32) uint8_t[sizeof(dSv_save_c) + 1 + sizeof(PositionData)];
            memcpy(data, &g_dComIfG_gameInfo.info.mSavedata, sizeof(dSv_save_c));
            memcpy(&data[sizeof(dSv_save_c) + 1], &posData, sizeof(PositionData));
            storage.result =
                GZ_storageWrite(&storage, data, sizeof(dSv_save_c) + 1 + sizeof(PositionData), 0, storage.sector_size);
            OSReport("GZ_storeMemfile: data write result: %d\n", storage.result);
            delete[] data;
            if (storage.result == Ready) {
                FIFOQueue::push("saved memfile!", Queue);
            } else {
                char buff[32];
                snprintf(buff, sizeof(buff), "failed to save: %d", storage.result);
                FIFOQueue::push(buff, Queue);
            }
            storage.result = StorageClose(&storage.info);
        }
    }
}

KEEP_FUNC void GZ_deleteMemfile(Storage& storage) {
    storage.result = StorageDelete(0, storage.file_name_buffer);
    if (storage.result == Ready) {
        FIFOQueue::push("deleted memfile!", Queue);
    } else {
        char buff[32];
        snprintf(buff, sizeof(buff), "failed to delete: %d", storage.result);
        FIFOQueue::push(buff, Queue);
    }
}