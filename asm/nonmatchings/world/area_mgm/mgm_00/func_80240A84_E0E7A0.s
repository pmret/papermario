.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A84_E0F224
/* E0F224 80240A84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E0F228 80240A88 AFB00010 */  sw        $s0, 0x10($sp)
/* E0F22C 80240A8C 0080802D */  daddu     $s0, $a0, $zero
/* E0F230 80240A90 AFBF0014 */  sw        $ra, 0x14($sp)
/* E0F234 80240A94 8E020148 */  lw        $v0, 0x148($s0)
/* E0F238 80240A98 0C00EABB */  jal       get_npc_unsafe
/* E0F23C 80240A9C 84440008 */   lh       $a0, 8($v0)
/* E0F240 80240AA0 0040202D */  daddu     $a0, $v0, $zero
/* E0F244 80240AA4 C482003C */  lwc1      $f2, 0x3c($a0)
/* E0F248 80240AA8 C480001C */  lwc1      $f0, 0x1c($a0)
/* E0F24C 80240AAC 46001080 */  add.s     $f2, $f2, $f0
/* E0F250 80240AB0 C4840014 */  lwc1      $f4, 0x14($a0)
/* E0F254 80240AB4 46040001 */  sub.s     $f0, $f0, $f4
/* E0F258 80240AB8 C4840064 */  lwc1      $f4, 0x64($a0)
/* E0F25C 80240ABC 4602203C */  c.lt.s    $f4, $f2
/* E0F260 80240AC0 E482003C */  swc1      $f2, 0x3c($a0)
/* E0F264 80240AC4 45010009 */  bc1t      .L80240AEC
/* E0F268 80240AC8 E480001C */   swc1     $f0, 0x1c($a0)
/* E0F26C 80240ACC 8C820000 */  lw        $v0, ($a0)
/* E0F270 80240AD0 2403F7FF */  addiu     $v1, $zero, -0x801
/* E0F274 80240AD4 E484003C */  swc1      $f4, 0x3c($a0)
/* E0F278 80240AD8 AC80001C */  sw        $zero, 0x1c($a0)
/* E0F27C 80240ADC 00431024 */  and       $v0, $v0, $v1
/* E0F280 80240AE0 AC820000 */  sw        $v0, ($a0)
/* E0F284 80240AE4 2402000C */  addiu     $v0, $zero, 0xc
/* E0F288 80240AE8 AE020070 */  sw        $v0, 0x70($s0)
.L80240AEC:
/* E0F28C 80240AEC 8FBF0014 */  lw        $ra, 0x14($sp)
/* E0F290 80240AF0 8FB00010 */  lw        $s0, 0x10($sp)
/* E0F294 80240AF4 03E00008 */  jr        $ra
/* E0F298 80240AF8 27BD0018 */   addiu    $sp, $sp, 0x18
