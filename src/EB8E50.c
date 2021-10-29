#include "dead.h"
#include "common.h"

// Should be related to flo_00
// The function is in (C9DF20.c) the loading zones in (C9DF60.c)

#define NAMESPACE EB8E50

const char ascii_EC2000[] = "mac_01";
const char ascii_EC2008[] = "flo_14";
const char ascii_EC2010[] = "flo_23";
const char ascii_EC2018[] = "flo_25";
const char ascii_EC2020[] = "flo_16";
const char ascii_EC2028[] = "flo_09";
const char ascii_EC2030[] = "flo_08";
static const f64 rodata_alignment = 0.0;

ApiStatus func_80240000_EB8E50(void) {
    dead_playFX_82(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
