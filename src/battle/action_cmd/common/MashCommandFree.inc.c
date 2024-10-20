#include "common.h"

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElemIDs[0]);
    hud_element_free(gActionCommandStatus.hudElemIDs[1]);
    hud_element_free(gActionCommandStatus.hudElemIDs[2]);
}
