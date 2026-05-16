#pragma once
#include "libtww/include/d/com/d_com_inf_game.h"
#include "libtww/include/d/a/d_a_player_main.h"
#include "libtww/include/d/d_procname.h"

// =================== UTILITIES ===================

inline void SaveMngSpecial_SetActorPos(fopAc_ac_c* actor, f32 x, f32 y, f32 z) {
    actor->current.pos.set(x, y, z);

    if (actor->mBase.mProcName == PROC_PLAYER) {
        l_debug_keep_pos.x = x;
        l_debug_keep_pos.y = y;
        l_debug_keep_pos.z = z;
    }
}

inline void SaveMngSpecial_SetActorYaw(fopAc_ac_c* actor, s16 yRot) {
    actor->current.angle.y = actor->shape_angle.y = yRot;

    if (actor->mBase.mProcName == PROC_PLAYER) {
        l_debug_current_angle.y = l_debug_shape_angle.y = yRot;
    }
}

inline void SaveMngSpecial_SetActorRot(fopAc_ac_c* actor, s16 xRot, s16 yRot, s16 zRot) {
    actor->current.angle.set(xRot, yRot, zRot);
    actor->shape_angle.set(xRot, yRot, zRot);

    if (actor->mBase.mProcName == PROC_PLAYER) {
        l_debug_current_angle.set(xRot, yRot, zRot);
        l_debug_shape_angle.set(xRot, yRot, zRot);
    }
}

inline void SaveMngSpecial_SetActorPosAndYaw(fopAc_ac_c* actor, f32 x, f32 y, f32 z, s16 yRot) {
    SaveMngSpecial_SetActorPos(actor, x, y, z);
    SaveMngSpecial_SetActorYaw(actor, yRot);
}

inline void SaveMngSpecial_SetHealth(u16 health) {
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setLife(health);
}

inline void SaveMngSpecial_SetMagic(u8 magic) {
    g_dComIfG_gameInfo.info.getPlayer().getPlayerStatusA().setMagic(magic);
}

inline void SaveMngSpecial_SetBombCount(u8 bombs) {
    g_dComIfG_gameInfo.info.getPlayer().getItemRecord().setBombNum(bombs);
}

inline void SaveMngSpecial_ChestStorage(fopAc_ac_c* actor) {
    u16* collision_ptr = dComIfGs_getCollision();
    *collision_ptr = (*collision_ptr & (0xFFFF ^ 0x4000)) | 0x4;
}

inline void SaveMngSpecial_DoorCancel(fopAc_ac_c* actor) {
    u16* collision_ptr = dComIfGs_getCollision();
    *collision_ptr |= 0x4004;
}


void SaveMngSpecial_SetLayer0();
void SaveMngSpecial_SetLayer1();
void SaveMngSpecial_SetLayer2();
void SaveMngSpecial_SetLayer3();
void SaveMngSpecial_SetLayer4();
void SaveMngSpecial_SetLayer5();
void SaveMngSpecial_SetLayer8();

void SaveMngSpecial_GiveChestStorage();
void SaveMngSpecial_BombsSwim_FHSwim_NoMSS();
void SaveMngSpecial_EarlyLeafHover();
void SaveMngSpecial_DTCS();
void SaveMngSpecial_LeafHover();
void SaveMngSpecial_PostLeafHover();
void SaveMngSpecial_ExitThornedFairy();
void SaveMngSpecial_Helmaroc();
void SaveMngSpecial_Hyrule2Skip_AD();
void SaveMngSpecial_BarrierSkip();
void SaveMngSpecial_TrialsSkip();
void SaveMngSpecial_TrialsSkip_AD();
void SaveMngSpecial_PuppetGanon();
void SaveMngSpecial_MorthHover();
void SaveMngSpecial_Ganondorf();

void SaveMngSpecial_Outside_FH_DC();
void SaveMngSpecial_GanonHover();

void SaveMngSpecial_TrialsSkipAny();
void SaveMngSpecial_LightArrowSkip_Any();
void SaveMngSpecial_PGCutsceneSkip_Any();
void SaveMngSpecial_PGSkip_AD();
void SaveMngSpecial_PGSkip_Any();
void SaveMngSpecial_BarrierSkip_Any();
void SaveMngSpecial_Post_MSS();
void SaveMngSpecial_FF1_Exterior();
void SaveMngSpecial_Door_Cancel_Leaf();
void SaveMngSpecial_FH_Swim();
void SaveMngSpecial_FF2_Climb();

void SaveMngSpecial_FF1CS_AD();
void SaveMngSpecial_KalleDemos_AD();
void SaveMngSpecial_DTCS_AD();
void SaveMngSpecial_EnterDRC_AD();
void SaveMngSpecial_DRCMiniboss_AD();
void SaveMngSpecial_DRCBossKeySkip_AD();
void SaveMngSpecial_EnterTOTG_AD();
void SaveMngSpecial_NayrusPearl_AD();
void SaveMngSpecial_TOTG_AD();
void SaveMngSpecial_Darknut_AD();
void SaveMngSpecial_AfterStatue2_AD();
void SaveMngSpecial_HyruleEscape_AD();
void SaveMngSpecial_BarrierSkip_AD();
void SaveMngSpecial_BoomerangSkip_AD();
void SaveMngSpecial_PhantomGanon_AD();
void SaveMngSpecial_EnterHelmaroc_AD();
void SaveMngSpecial_FireMountain_AD();
void SaveMngSpecial_EarlyET_AD();
void SaveMngSpecial_ET_AD();
void SaveMngSpecial_SongstoneSkip_AD();
void SaveMngSpecial_Jalhalla_AD();
void SaveMngSpecial_IceRing_AD();
void SaveMngSpecial_Makar_AD();
void SaveMngSpecial_EnterWT_AD();
void SaveMngSpecial_WT_AD();
void SaveMngSpecial_Wizzrobe_AD();
void SaveMngSpecial_AfterHS_AD();
void SaveMngSpecial_Swim2FCP_AD();

void SaveMngSpecial_Greatfish_PST();
void SaveMngSpecial_ForbiddenWoods_PST();
void SaveMngSpecial_EnterDRC_PST();
void SaveMngSpecial_DRC_PST();
void SaveMngSpecial_Tingle_PST();
void SaveMngSpecial_EnterHelmaroc_PST();
void SaveMngSpecial_MirorShield_PST();
void SaveMngSpecial_SongStoneSkip_PST();

void SaveMngSpecial_SubmarineSwim_PMG();
void SaveMngSpecial_DeliveryBagSkip_PMG();
void SaveMngSpecial_DRCChestStorage_PMG();
void SaveMngSpecial_DRCClimb_PMG();
void SaveMngSpecial_FWSmallKeySkip_PMG();

void SaveMngSpecial_MailGame_Hundo();
void SaveMngSpecial_DRC_BK_Skip_Hundo();
void SaveMngSpecial_WindfallSwim_Hundo();
void SaveMngSpecial_WindfallToFHSwim_Hundo();
void SaveMngSpecial_DTCS_Hundo();
void SaveMngSpecial_LeafToFoF_Hundo();
void SaveMngSpecial_RollClipLeafGreatFairyFoF_Hundo();
void SaveMngSpecial_LeafToInvisPirateShip_Hundo();
void SaveMngSpecial_EnterTotg_Hundo();
void SaveMngSpecial_CrescentMoonSub_Hundo();
void SaveMngSpecial_FF2HelmCSSkip_Hundo();
void SaveMngSpecial_ETFloormastersRoom_Hundo();
void SaveMngSpecial_BushStorageNeedleRock_Hundo();
void SaveMngSpecial_ChestStorageFiveEyeReef_Hundo();
void SaveMngSpecial_TingleIslandStorage_Hundo();
void SaveMngSpecial_WindTempleLockedRoom_Hundo();
void SaveMngSpecial_6EyeSwim_Hundo();
void SaveMngSpecial_6EyeSub_Hundo();
void SaveMngSpecial_PawprintSwim_Hundo();
void SaveMngSpecial_Orca500_Hundo();
void SaveMngSpecial_HeadstoneSubSwim();
void SaveMngSpecial_FourEyeStorageOnChest_Hundo();
void SaveMngSpecial_FHStorageOnChestCabanaSwim_Hundo();
void SaveMngSpecial_TwoEyeTo5Star_Hundo();
void SaveMngSpecial_5StarChestStorage_Hundo();
void SaveMngSpecial_CliffPlateauToThornedFairy_Hundo();
void SaveMngSpecial_FF3Swim_Hundo();
