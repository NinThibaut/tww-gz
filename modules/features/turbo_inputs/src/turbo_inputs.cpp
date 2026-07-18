#include "features/turbo_inputs/include/turbo_inputs.h"
#include "libtww/include/d/com/d_com_inf_game.h"
#include "menus/menu_tools/include/tools_menu.h"
#include "libtww/include/d/a/d_a_player_main.h"
#include "libtww/include/d/a/d_a_player.h"
#include "controller.h"
#include "global_data.h"

namespace TurboInputs {

bool skipFrame = false;
u32 moveLinkButtonsPressed;

KEEP_FUNC void GZ_turboInputs() {
    if (!g_tools[TURBO_INPUTS_INDEX].active) {
        return;
    }
    if (g_moveLinkEnabled) {
        moveLinkButtonsPressed = (mPadButton.mButton & CButton::Z) | (mPadButton.mButton & CButton::R) | (mPadButton.mButton & CButton::A) | (mPadButton.mButton & CButton::L);
    }
    if (skipFrame) {
        mPadButton.mButton = CButton::B;
    } else {
        mPadButton.mButton = 0;
    }
    if (g_moveLinkEnabled) {
        mPadButton.mButton |= moveLinkButtonsPressed;
    }

    skipFrame = !skipFrame;
}

}  // namespace TurboInputs