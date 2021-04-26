#include "flo_13.h"

typedef struct {
    /* 0x00 */ s32* unk_00;
    /* 0x04 */ s32* unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} N(Unk_bss_struct);

static s8 N(D_80247B00)[0x200];
static s8 N(D_80247D00)[0x3D90];
static N(Unk_bss_struct) N(D_8024BA90);

ApiStatus N(func_802435D0_CC6DE0)(ScriptInstance *script, s32 isInitialCall) {
    s32 var;
    void* temp_s0 = load_asset_by_name("party_pokopi", &var);

    decode_yay0(temp_s0, N(D_80247B00));
    general_heap_free(temp_s0);

    N(D_8024BA90).unk_00 = N(D_80247D00);
    N(D_8024BA90).unk_08 = 0x96;
    N(D_8024BA90).unk_0A = 0x69;
    N(D_8024BA90).unk_0C = 2;
    N(D_8024BA90).unk_04 = N(D_80247B00);
    N(D_8024BA90).unk_10 = 1;
    set_message_images(&N(D_8024BA90));
    return ApiStatus_DONE2;
}
