#include "common.h"

// determines the 'brightness' of inspect and speech bubble icons as a function of angle,
// making them appear more three-dimensional.
s32 N(GetIconBrightnessForAngle)(f32 angle) {
    s32 angleDiff;

    if (angle >= 270.0f) {
        angleDiff = 360.0f - angle;
    } else if (angle >= 180.0f) {
        angleDiff = angle - 180.0f;
    } else if (angle >= 90.0f) {
        angleDiff = 180.0f - angle;
    } else {
        angleDiff = angle;
    }
    return 0xFF - angleDiff - angleDiff;
}
