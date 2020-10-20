.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405A4_93FB54
/* 93FB54 802405A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 93FB58 802405A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 93FB5C 802405AC 0080802D */  daddu     $s0, $a0, $zero
/* 93FB60 802405B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 93FB64 802405B4 8E020148 */  lw        $v0, 0x148($s0)
/* 93FB68 802405B8 0C00EABB */  jal       get_npc_unsafe
/* 93FB6C 802405BC 84440008 */   lh       $a0, 8($v0)
/* 93FB70 802405C0 0040202D */  daddu     $a0, $v0, $zero
/* 93FB74 802405C4 C482003C */  lwc1      $f2, 0x3c($a0)
/* 93FB78 802405C8 C480001C */  lwc1      $f0, 0x1c($a0)
/* 93FB7C 802405CC 46001080 */  add.s     $f2, $f2, $f0
/* 93FB80 802405D0 C4840014 */  lwc1      $f4, 0x14($a0)
/* 93FB84 802405D4 46040001 */  sub.s     $f0, $f0, $f4
/* 93FB88 802405D8 C4840064 */  lwc1      $f4, 0x64($a0)
/* 93FB8C 802405DC 4602203C */  c.lt.s    $f4, $f2
/* 93FB90 802405E0 E482003C */  swc1      $f2, 0x3c($a0)
/* 93FB94 802405E4 45010009 */  bc1t      .L8024060C
/* 93FB98 802405E8 E480001C */   swc1     $f0, 0x1c($a0)
/* 93FB9C 802405EC 8C820000 */  lw        $v0, ($a0)
/* 93FBA0 802405F0 2403F7FF */  addiu     $v1, $zero, -0x801
/* 93FBA4 802405F4 E484003C */  swc1      $f4, 0x3c($a0)
/* 93FBA8 802405F8 AC80001C */  sw        $zero, 0x1c($a0)
/* 93FBAC 802405FC 00431024 */  and       $v0, $v0, $v1
/* 93FBB0 80240600 AC820000 */  sw        $v0, ($a0)
/* 93FBB4 80240604 2402000C */  addiu     $v0, $zero, 0xc
/* 93FBB8 80240608 AE020070 */  sw        $v0, 0x70($s0)
.L8024060C:
/* 93FBBC 8024060C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 93FBC0 80240610 8FB00010 */  lw        $s0, 0x10($sp)
/* 93FBC4 80240614 03E00008 */  jr        $ra
/* 93FBC8 80240618 27BD0018 */   addiu    $sp, $sp, 0x18
