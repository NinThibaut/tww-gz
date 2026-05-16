#include "features/turbo_inputs/include/turbo_inputs.h"
#include "libtww/include/d/com/d_com_inf_game.h"
#include "menus/menu_tools/include/tools_menu.h"
#include "controller.h"

namespace TurboInputs {

bool skipFrame = false;

KEEP_FUNC void GZ_turboInputs() {
    if (!g_tools[TURBO_INPUTS_INDEX].active) {
        return;
    }
    if (skipFrame) {
        mPadButton.mButton = CButton::B;
    } else {
        mPadButton.mButton = 0;
    }

    skipFrame = !skipFrame;
}

}  // namespace TurboInputs