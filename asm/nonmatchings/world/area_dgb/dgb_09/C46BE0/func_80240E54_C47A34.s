.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E54_C47A34
/* C47A34 80240E54 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C47A38 80240E58 AFB20018 */  sw        $s2, 0x18($sp)
/* C47A3C 80240E5C 0080902D */  daddu     $s2, $a0, $zero
/* C47A40 80240E60 AFBF001C */  sw        $ra, 0x1c($sp)
/* C47A44 80240E64 AFB10014 */  sw        $s1, 0x14($sp)
/* C47A48 80240E68 AFB00010 */  sw        $s0, 0x10($sp)
/* C47A4C 80240E6C 8E500148 */  lw        $s0, 0x148($s2)
/* C47A50 80240E70 86040008 */  lh        $a0, 8($s0)
/* C47A54 80240E74 0C00EABB */  jal       get_npc_unsafe
/* C47A58 80240E78 00A0882D */   daddu    $s1, $a1, $zero
/* C47A5C 80240E7C 0040182D */  daddu     $v1, $v0, $zero
/* C47A60 80240E80 9462008E */  lhu       $v0, 0x8e($v1)
/* C47A64 80240E84 2442FFFF */  addiu     $v0, $v0, -1
/* C47A68 80240E88 A462008E */  sh        $v0, 0x8e($v1)
/* C47A6C 80240E8C 00021400 */  sll       $v0, $v0, 0x10
/* C47A70 80240E90 1C400015 */  bgtz      $v0, .L80240EE8
/* C47A74 80240E94 00000000 */   nop
/* C47A78 80240E98 8E0200CC */  lw        $v0, 0xcc($s0)
/* C47A7C 80240E9C 8C420004 */  lw        $v0, 4($v0)
/* C47A80 80240EA0 AC620028 */  sw        $v0, 0x28($v1)
/* C47A84 80240EA4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C47A88 80240EA8 8C420014 */  lw        $v0, 0x14($v0)
/* C47A8C 80240EAC 04410004 */  bgez      $v0, .L80240EC0
/* C47A90 80240EB0 00000000 */   nop
/* C47A94 80240EB4 C6200000 */  lwc1      $f0, ($s1)
/* C47A98 80240EB8 080903B8 */  j         .L80240EE0
/* C47A9C 80240EBC E4600018 */   swc1     $f0, 0x18($v1)
.L80240EC0:
/* C47AA0 80240EC0 3C018024 */  lui       $at, %hi(D_80245528)
/* C47AA4 80240EC4 D4225528 */  ldc1      $f2, %lo(D_80245528)($at)
/* C47AA8 80240EC8 44820000 */  mtc1      $v0, $f0
/* C47AAC 80240ECC 00000000 */  nop
/* C47AB0 80240ED0 46800021 */  cvt.d.w   $f0, $f0
/* C47AB4 80240ED4 46220003 */  div.d     $f0, $f0, $f2
/* C47AB8 80240ED8 46200020 */  cvt.s.d   $f0, $f0
/* C47ABC 80240EDC E4600018 */  swc1      $f0, 0x18($v1)
.L80240EE0:
/* C47AC0 80240EE0 24020029 */  addiu     $v0, $zero, 0x29
/* C47AC4 80240EE4 AE420070 */  sw        $v0, 0x70($s2)
.L80240EE8:
/* C47AC8 80240EE8 8FBF001C */  lw        $ra, 0x1c($sp)
/* C47ACC 80240EEC 8FB20018 */  lw        $s2, 0x18($sp)
/* C47AD0 80240EF0 8FB10014 */  lw        $s1, 0x14($sp)
/* C47AD4 80240EF4 8FB00010 */  lw        $s0, 0x10($sp)
/* C47AD8 80240EF8 03E00008 */  jr        $ra
/* C47ADC 80240EFC 27BD0020 */   addiu    $sp, $sp, 0x20
