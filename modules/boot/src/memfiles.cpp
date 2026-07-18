#include "memfiles.h"
#include "save_specials.h"
#include "save_manager.h"
#include "libtww/include/d/com/d_com_inf_game.h"
#include "libtww/include/d/a/d_a_player_main.h"
#include "libtww/include/d/d_procname.h"
#include "rels/include/defines.h"
#include "libtww/include/addrs.h"

KEEP_VAR PositionData memfile_posdata;

KEEP_FUNC void GZ_setLinkPosition() {
    gSaveManager.modifyActor(memfile_posdata.korl ? PROC_SHIP : PROC_PLAYER, [](fopAc_ac_c* actor) {
        SaveMngSpecial_SetActorPosAndYaw(actor, memfile_posdata.link.x, memfile_posdata.link.y, memfile_posdata.link.z,
                                         memfile_posdata.angle);
        dComIfg_setCamPosAndTarget(memfile_posdata.cam);
    });
    gSaveManager.modifyActor(PROC_PLAYER, [](fopAc_ac_c* actor) {
        u16* collision_ptr = dComIfGs_getCollision();
        if (memfile_posdata.collision == DOORCANCEL) {
            *collision_ptr |= 0x4004;
        } else if (memfile_posdata.collision == CHESTSTORAGE) {
            *collision_ptr |= 0x4;
        }
    });
}

KEEP_FUNC bool GZ_checkWorkingMemfile(char* stage) {
    return strcmp(stage, "TF_01") != 0 && strcmp(stage, "TF_02") != 0 && strcmp(stage, "Obshop") != 0 &&
           strcmp(stage, "Abship") != 0;
}

KEEP_FUNC int GZ_validSpawnPoint(char* stage, int room, int point) {
    if (strcmp(stage, "M_NewD2") == 0) {
        switch (room) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 1;
        case 3:
            return 6;
        case 4:
            return 7;
        case 6:
            return 9;
        case 7:
            return 0;
        case 8:
            return 14;
        case 10:
            return 15;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 18;
        default:
            return 0;
        }
    } else if (strcmp(stage, "kaze") == 0) {
        if (room == 16) {
            return 19;
        }
        return room;
    } else if (strcmp(stage, "M_Dai") == 0) {
        if (0 <= room && room <= 3) {
            return room;
        } else if ((4 <= room && room <= 7) || (13 <= room && room <= 15)) {
            return room + 1;
        } else if (room == 19) {
            return 25;
        } else {
            return room + 2;
        }
    } else if (strcmp(stage, "ma3room") == 0 || strcmp(stage, "ma2room") == 0 || strcmp(stage, "majroom") == 0) {
        switch (room) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 15;
        case 3:
            return 10;
        case 4:
            return 5;
        }
    } else if (strcmp(stage, "sea") == 0) {
        int link_animation = ((daPy_lk_c*)dComIfGp_getPlayer(0))->mCurProcID;
        if (link_animation == daPy_lk_c::PROC_SHIP_PADDLE_e || link_animation == daPy_lk_c::PROC_SHIP_STEER_e ||
            link_animation == daPy_lk_c::PROC_SHIP_CRANE_e || link_animation == daPy_lk_c::PROC_SHIP_CANNON_e) {
            return 102;
        }
        return 0;
    }
    if (point == -1) {
        return 0;
    }
    return point;
}