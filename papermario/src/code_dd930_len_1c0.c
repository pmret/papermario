#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} struct_80147230;

extern struct_80147230 D_8014F140;
extern struct_80147230 D_8015C7C0;

void func_80147230(void) {
    D_8015C7C0 = D_8014F140;
}

INCLUDE_ASM(code_dd930_len_1c0, UpdateMusicPlayers);

INCLUDE_ASM(code_dd930_len_1c0, play_ambient_sounds);

// matches, but clearly isn't correct. Investigate later.
/*int play_ambient_sounds(int a0, int a1)
{
  struct_80147230 *temp2 = &D_8015C7C0;
  struct_80147230 **temp3 = &temp2;

  if ((*gGameStatusPtr)->musicEnabled == 0)
  {
    func_800554A4(temp2->unk8);
    temp2->unk0 &= ~1;
    return 1;
  }


  if (temp2->unk8 == a0)
  {
    return 2;
  }

  temp2->unk8 = a0;
  temp2->unk4 = a1;
  temp2->unk2 = 1;
  return 1;
}*/