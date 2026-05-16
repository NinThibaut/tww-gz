#include "modules.h"
#include "libtww/include/defines.h"
#include "libtww/include/f_op/f_op_scene_req.h"

#include "commands.h"
#include "global_data.h"
#include "settings.h"
#include "tools.h"

KEEP_VAR twwgz::containers::deque<Module*> g_modules;

/**
 * @brief   Handles when to load or unload REL modules.
 *          Registered to run before the main loop.
 */
KEEP_FUNC void GZ_handleModules() {
    for (auto mod : g_modules) {
        if (mod->active() && !mod->rel.isLoaded()) {
            mod->rel.load(true);
        }
        if (!mod->active() && mod->rel.isLoaded()) {
            mod->rel.close();
        }
    }
}

KEEP_FUNC bool inputViewer_active() {
    if (l_fopScnRq_IsUsingOfOverlap) {
        return false;
    }
    return g_tools[INPUT_VIEWER_INDEX].active;
}

KEEP_FUNC bool actorView_active() {
    return g_actorViewEnabled;
}

KEEP_FUNC bool moveLink_active() {
    if (l_fopScnRq_IsUsingOfOverlap) {
        return false;
    }
    return g_tools[MOVE_LINK_INDEX].active;
}

KEEP_FUNC bool rollClipTool_active() {
    if (l_fopScnRq_IsUsingOfOverlap) {
        return false;
    }
    return g_tools[ROLL_CLIP_INDEX].active;
}

KEEP_FUNC bool pauseBufferInputTool_active() {
    if (l_fopScnRq_IsUsingOfOverlap) {
        return false;
    }

    return g_tools[PAUSE_BUFFER_INPUT_INDEX].active;
}