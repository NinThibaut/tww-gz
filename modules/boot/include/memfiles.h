#pragma once

#include <cstdint>
#include "libtww/include/dolphin/mtx/vec.h"
#include "libtww/include/SSystem/SComponent/c_xyz.h"

enum Collision {
    NORMAL,
    CHESTSTORAGE,
    DOORCANCEL
};

struct PositionData {
    cXyz link;
    CameraMatrix cam;
    s16 angle;
    bool korl;
    Collision collision;
};

extern PositionData memfile_posdata;

void GZ_setLinkPosition();

/*
Some rooms may crash or not load the correct room if the spawn point is not in the current room.
Mostly happens in DRC, ET and WT.
Return a correct spawn point based on my testing */
int GZ_validSpawnPoint(char* stage, int room, int point);

/* Checks whether a memfile will work (loads successfully) based on my testing*/
bool GZ_checkWorkingMemfile(char* stage);