.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E54_C2F9F4
/* C2F9F4 80240E54 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C2F9F8 80240E58 AFB20018 */  sw        $s2, 0x18($sp)
/* C2F9FC 80240E5C 0080902D */  daddu     $s2, $a0, $zero
/* C2FA00 80240E60 AFBF001C */  sw        $ra, 0x1c($sp)
/* C2FA04 80240E64 AFB10014 */  sw        $s1, 0x14($sp)
/* C2FA08 80240E68 AFB00010 */  sw        $s0, 0x10($sp)
/* C2FA0C 80240E6C 8E500148 */  lw        $s0, 0x148($s2)
/* C2FA10 80240E70 86040008 */  lh        $a0, 8($s0)
/* C2FA14 80240E74 0C00EABB */  jal       get_npc_unsafe
/* C2FA18 80240E78 00A0882D */   daddu    $s1, $a1, $zero
/* C2FA1C 80240E7C 0040182D */  daddu     $v1, $v0, $zero
/* C2FA20 80240E80 9462008E */  lhu       $v0, 0x8e($v1)
/* C2FA24 80240E84 2442FFFF */  addiu     $v0, $v0, -1
/* C2FA28 80240E88 A462008E */  sh        $v0, 0x8e($v1)
/* C2FA2C 80240E8C 00021400 */  sll       $v0, $v0, 0x10
/* C2FA30 80240E90 1C400015 */  bgtz      $v0, .L80240EE8
/* C2FA34 80240E94 00000000 */   nop
/* C2FA38 80240E98 8E0200CC */  lw        $v0, 0xcc($s0)
/* C2FA3C 80240E9C 8C420004 */  lw        $v0, 4($v0)
/* C2FA40 80240EA0 AC620028 */  sw        $v0, 0x28($v1)
/* C2FA44 80240EA4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C2FA48 80240EA8 8C420014 */  lw        $v0, 0x14($v0)
/* C2FA4C 80240EAC 04410004 */  bgez      $v0, .L80240EC0
/* C2FA50 80240EB0 00000000 */   nop
/* C2FA54 80240EB4 C6200000 */  lwc1      $f0, ($s1)
/* C2FA58 80240EB8 080903B8 */  j         .L80240EE0
/* C2FA5C 80240EBC E4600018 */   swc1     $f0, 0x18($v1)
.L80240EC0:
/* C2FA60 80240EC0 3C018024 */  lui       $at, %hi(D_802427A8_C31348)
/* C2FA64 80240EC4 D42227A8 */  ldc1      $f2, %lo(D_802427A8_C31348)($at)
/* C2FA68 80240EC8 44820000 */  mtc1      $v0, $f0
/* C2FA6C 80240ECC 00000000 */  nop
/* C2FA70 80240ED0 46800021 */  cvt.d.w   $f0, $f0
/* C2FA74 80240ED4 46220003 */  div.d     $f0, $f0, $f2
/* C2FA78 80240ED8 46200020 */  cvt.s.d   $f0, $f0
/* C2FA7C 80240EDC E4600018 */  swc1      $f0, 0x18($v1)
.L80240EE0:
/* C2FA80 80240EE0 24020029 */  addiu     $v0, $zero, 0x29
/* C2FA84 80240EE4 AE420070 */  sw        $v0, 0x70($s2)
.L80240EE8:
/* C2FA88 80240EE8 8FBF001C */  lw        $ra, 0x1c($sp)
/* C2FA8C 80240EEC 8FB20018 */  lw        $s2, 0x18($sp)
/* C2FA90 80240EF0 8FB10014 */  lw        $s1, 0x14($sp)
/* C2FA94 80240EF4 8FB00010 */  lw        $s0, 0x10($sp)
/* C2FA98 80240EF8 03E00008 */  jr        $ra
/* C2FA9C 80240EFC 27BD0020 */   addiu    $sp, $sp, 0x20
