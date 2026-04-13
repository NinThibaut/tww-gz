#include <main.h>
#include "features/turbo_inputs/include/turbo_inputs.h"
#include "rels/include/cxx.h"
#include "events/pre_loop_listener.h"

namespace twwgz::modules {
void main() {
    g_PreLoopListener->addListener(TurboInputs::GZ_turboInputs);
}
void exit() {
    g_PreLoopListener->removeListener(TurboInputs::GZ_turboInputs);
}

}  // namespace twwgz::modules