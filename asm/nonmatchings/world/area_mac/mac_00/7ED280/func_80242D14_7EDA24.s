.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D14_7EDA24
/* 7EDA24 80242D14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EDA28 80242D18 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EDA2C 80242D1C 0080802D */  daddu     $s0, $a0, $zero
/* 7EDA30 80242D20 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7EDA34 80242D24 8E020148 */  lw        $v0, 0x148($s0)
/* 7EDA38 80242D28 0C00EABB */  jal       get_npc_unsafe
/* 7EDA3C 80242D2C 84440008 */   lh       $a0, 8($v0)
/* 7EDA40 80242D30 0040202D */  daddu     $a0, $v0, $zero
/* 7EDA44 80242D34 C482003C */  lwc1      $f2, 0x3c($a0)
/* 7EDA48 80242D38 C480001C */  lwc1      $f0, 0x1c($a0)
/* 7EDA4C 80242D3C 46001080 */  add.s     $f2, $f2, $f0
/* 7EDA50 80242D40 C4840014 */  lwc1      $f4, 0x14($a0)
/* 7EDA54 80242D44 46040001 */  sub.s     $f0, $f0, $f4
/* 7EDA58 80242D48 C4840064 */  lwc1      $f4, 0x64($a0)
/* 7EDA5C 80242D4C 4602203C */  c.lt.s    $f4, $f2
/* 7EDA60 80242D50 E482003C */  swc1      $f2, 0x3c($a0)
/* 7EDA64 80242D54 45010009 */  bc1t      .L80242D7C
/* 7EDA68 80242D58 E480001C */   swc1     $f0, 0x1c($a0)
/* 7EDA6C 80242D5C 8C820000 */  lw        $v0, ($a0)
/* 7EDA70 80242D60 2403F7FF */  addiu     $v1, $zero, -0x801
/* 7EDA74 80242D64 E484003C */  swc1      $f4, 0x3c($a0)
/* 7EDA78 80242D68 AC80001C */  sw        $zero, 0x1c($a0)
/* 7EDA7C 80242D6C 00431024 */  and       $v0, $v0, $v1
/* 7EDA80 80242D70 AC820000 */  sw        $v0, ($a0)
/* 7EDA84 80242D74 2402000C */  addiu     $v0, $zero, 0xc
/* 7EDA88 80242D78 AE020070 */  sw        $v0, 0x70($s0)
.L80242D7C:
/* 7EDA8C 80242D7C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7EDA90 80242D80 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EDA94 80242D84 03E00008 */  jr        $ra
/* 7EDA98 80242D88 27BD0018 */   addiu    $sp, $sp, 0x18
