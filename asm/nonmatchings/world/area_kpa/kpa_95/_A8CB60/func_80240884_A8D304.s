.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240884_A8D304
/* A8D304 80240884 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8D308 80240888 AFB00010 */  sw        $s0, 0x10($sp)
/* A8D30C 8024088C 0080802D */  daddu     $s0, $a0, $zero
/* A8D310 80240890 AFBF0014 */  sw        $ra, 0x14($sp)
/* A8D314 80240894 8E020148 */  lw        $v0, 0x148($s0)
/* A8D318 80240898 0C00EABB */  jal       get_npc_unsafe
/* A8D31C 8024089C 84440008 */   lh       $a0, 8($v0)
/* A8D320 802408A0 0040202D */  daddu     $a0, $v0, $zero
/* A8D324 802408A4 C482003C */  lwc1      $f2, 0x3c($a0)
/* A8D328 802408A8 C480001C */  lwc1      $f0, 0x1c($a0)
/* A8D32C 802408AC 46001080 */  add.s     $f2, $f2, $f0
/* A8D330 802408B0 C4840014 */  lwc1      $f4, 0x14($a0)
/* A8D334 802408B4 46040001 */  sub.s     $f0, $f0, $f4
/* A8D338 802408B8 C4840064 */  lwc1      $f4, 0x64($a0)
/* A8D33C 802408BC 4602203C */  c.lt.s    $f4, $f2
/* A8D340 802408C0 E482003C */  swc1      $f2, 0x3c($a0)
/* A8D344 802408C4 45010009 */  bc1t      .L802408EC
/* A8D348 802408C8 E480001C */   swc1     $f0, 0x1c($a0)
/* A8D34C 802408CC 8C820000 */  lw        $v0, ($a0)
/* A8D350 802408D0 2403F7FF */  addiu     $v1, $zero, -0x801
/* A8D354 802408D4 E484003C */  swc1      $f4, 0x3c($a0)
/* A8D358 802408D8 AC80001C */  sw        $zero, 0x1c($a0)
/* A8D35C 802408DC 00431024 */  and       $v0, $v0, $v1
/* A8D360 802408E0 AC820000 */  sw        $v0, ($a0)
/* A8D364 802408E4 2402000C */  addiu     $v0, $zero, 0xc
/* A8D368 802408E8 AE020070 */  sw        $v0, 0x70($s0)
.L802408EC:
/* A8D36C 802408EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A8D370 802408F0 8FB00010 */  lw        $s0, 0x10($sp)
/* A8D374 802408F4 03E00008 */  jr        $ra
/* A8D378 802408F8 27BD0018 */   addiu    $sp, $sp, 0x18
