.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241104_99DA94
/* 99DA94 80241104 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 99DA98 80241108 AFB10014 */  sw        $s1, 0x14($sp)
/* 99DA9C 8024110C 0080882D */  daddu     $s1, $a0, $zero
/* 99DAA0 80241110 AFBF001C */  sw        $ra, 0x1c($sp)
/* 99DAA4 80241114 AFB20018 */  sw        $s2, 0x18($sp)
/* 99DAA8 80241118 AFB00010 */  sw        $s0, 0x10($sp)
/* 99DAAC 8024111C 8E300148 */  lw        $s0, 0x148($s1)
/* 99DAB0 80241120 86040008 */  lh        $a0, 8($s0)
/* 99DAB4 80241124 0C00EABB */  jal       get_npc_unsafe
/* 99DAB8 80241128 00A0902D */   daddu    $s2, $a1, $zero
/* 99DABC 8024112C 8E0300CC */  lw        $v1, 0xcc($s0)
/* 99DAC0 80241130 8C630004 */  lw        $v1, 4($v1)
/* 99DAC4 80241134 0040202D */  daddu     $a0, $v0, $zero
/* 99DAC8 80241138 AC830028 */  sw        $v1, 0x28($a0)
/* 99DACC 8024113C 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 99DAD0 80241140 8C420014 */  lw        $v0, 0x14($v0)
/* 99DAD4 80241144 04410009 */  bgez      $v0, .L8024116C
/* 99DAD8 80241148 00000000 */   nop
/* 99DADC 8024114C C640000C */  lwc1      $f0, 0xc($s2)
/* 99DAE0 80241150 3C018024 */  lui       $at, %hi(D_802444A8_9A0E38)
/* 99DAE4 80241154 D42244A8 */  ldc1      $f2, %lo(D_802444A8_9A0E38)($at)
/* 99DAE8 80241158 46000021 */  cvt.d.s   $f0, $f0
/* 99DAEC 8024115C 46220002 */  mul.d     $f0, $f0, $f2
/* 99DAF0 80241160 00000000 */  nop
/* 99DAF4 80241164 08090462 */  j         .L80241188
/* 99DAF8 80241168 46200020 */   cvt.s.d  $f0, $f0
.L8024116C:
/* 99DAFC 8024116C 3C018024 */  lui       $at, %hi(D_802444B0_9A0E40)
/* 99DB00 80241170 D42244B0 */  ldc1      $f2, %lo(D_802444B0_9A0E40)($at)
/* 99DB04 80241174 44820000 */  mtc1      $v0, $f0
/* 99DB08 80241178 00000000 */  nop
/* 99DB0C 8024117C 46800021 */  cvt.d.w   $f0, $f0
/* 99DB10 80241180 46220003 */  div.d     $f0, $f0, $f2
/* 99DB14 80241184 46200020 */  cvt.s.d   $f0, $f0
.L80241188:
/* 99DB18 80241188 E4800018 */  swc1      $f0, 0x18($a0)
/* 99DB1C 8024118C 24020010 */  addiu     $v0, $zero, 0x10
/* 99DB20 80241190 AE200074 */  sw        $zero, 0x74($s1)
/* 99DB24 80241194 AE220070 */  sw        $v0, 0x70($s1)
/* 99DB28 80241198 8FBF001C */  lw        $ra, 0x1c($sp)
/* 99DB2C 8024119C 8FB20018 */  lw        $s2, 0x18($sp)
/* 99DB30 802411A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 99DB34 802411A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 99DB38 802411A8 03E00008 */  jr        $ra
/* 99DB3C 802411AC 27BD0020 */   addiu    $sp, $sp, 0x20
