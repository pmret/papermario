typedef struct
{
  int unk0;
  int unk4;
  int unk8;
  int unkC;
} struct_80147230;

extern struct_80147230 unk1;
extern struct_80147230 unk2;

void func_80147230(void)
{
  unk2 = unk1;
}

void __attribute__((naked)) UpdateMusicPlayers(void)
{
  __asm__(
    ".include \"asm/code_dd930_len_1c0/UpdateMusicPlayers.s\"\n"
  );
}

void __attribute__((naked)) play_ambient_sounds(void)
{
  __asm__(
    ".include \"asm/code_dd930_len_1c0/play_ambient_sounds.s\"\n"
  );
}
