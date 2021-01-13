.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400FC_B1B66C
/* B1B66C 802400FC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B1B670 80240100 AFB10014 */  sw        $s1, 0x14($sp)
/* B1B674 80240104 0080882D */  daddu     $s1, $a0, $zero
/* B1B678 80240108 AFBF0018 */  sw        $ra, 0x18($sp)
/* B1B67C 8024010C AFB00010 */  sw        $s0, 0x10($sp)
/* B1B680 80240110 F7BE0048 */  sdc1      $f30, 0x48($sp)
/* B1B684 80240114 F7BC0040 */  sdc1      $f28, 0x40($sp)
/* B1B688 80240118 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* B1B68C 8024011C F7B80030 */  sdc1      $f24, 0x30($sp)
/* B1B690 80240120 F7B60028 */  sdc1      $f22, 0x28($sp)
/* B1B694 80240124 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B1B698 80240128 0C00EAD2 */  jal       get_npc_safe
/* B1B69C 8024012C 2404FFFC */   addiu    $a0, $zero, -4
/* B1B6A0 80240130 0040802D */  daddu     $s0, $v0, $zero
/* B1B6A4 80240134 1200003F */  beqz      $s0, .L80240234
/* B1B6A8 80240138 24020002 */   addiu    $v0, $zero, 2
/* B1B6AC 8024013C C60C0038 */  lwc1      $f12, 0x38($s0)
/* B1B6B0 80240140 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B1B6B4 80240144 3C06C37A */  lui       $a2, 0xc37a
/* B1B6B8 80240148 0C00A7B5 */  jal       dist2D
/* B1B6BC 8024014C 3C07C2C8 */   lui      $a3, 0xc2c8
/* B1B6C0 80240150 0220202D */  daddu     $a0, $s1, $zero
/* B1B6C4 80240154 3C05FE36 */  lui       $a1, 0xfe36
/* B1B6C8 80240158 34A53C80 */  ori       $a1, $a1, 0x3c80
/* B1B6CC 8024015C 0C0B1EAF */  jal       get_variable
/* B1B6D0 80240160 46000606 */   mov.s    $f24, $f0
/* B1B6D4 80240164 2442FFFF */  addiu     $v0, $v0, -1
/* B1B6D8 80240168 3C0140C9 */  lui       $at, 0x40c9
/* B1B6DC 8024016C 34210FD0 */  ori       $at, $at, 0xfd0
/* B1B6E0 80240170 4481B000 */  mtc1      $at, $f22
/* B1B6E4 80240174 44820000 */  mtc1      $v0, $f0
/* B1B6E8 80240178 00000000 */  nop
/* B1B6EC 8024017C 46800020 */  cvt.s.w   $f0, $f0
/* B1B6F0 80240180 46160502 */  mul.s     $f20, $f0, $f22
/* B1B6F4 80240184 00000000 */  nop
/* B1B6F8 80240188 3C0143B4 */  lui       $at, 0x43b4
/* B1B6FC 8024018C 4481D000 */  mtc1      $at, $f26
/* B1B700 80240190 00000000 */  nop
/* B1B704 80240194 461AA503 */  div.s     $f20, $f20, $f26
/* B1B708 80240198 0C00A85B */  jal       sin_rad
/* B1B70C 8024019C 4600A306 */   mov.s    $f12, $f20
/* B1B710 802401A0 46000786 */  mov.s     $f30, $f0
/* B1B714 802401A4 0C00A874 */  jal       cos_rad
/* B1B718 802401A8 4600A306 */   mov.s    $f12, $f20
/* B1B71C 802401AC 4600C702 */  mul.s     $f28, $f24, $f0
/* B1B720 802401B0 00000000 */  nop
/* B1B724 802401B4 0220202D */  daddu     $a0, $s1, $zero
/* B1B728 802401B8 4600F507 */  neg.s     $f20, $f30
/* B1B72C 802401BC 4614C502 */  mul.s     $f20, $f24, $f20
/* B1B730 802401C0 00000000 */  nop
/* B1B734 802401C4 3C05FE36 */  lui       $a1, 0xfe36
/* B1B738 802401C8 0C0B1EAF */  jal       get_variable
/* B1B73C 802401CC 34A53C80 */   ori      $a1, $a1, 0x3c80
/* B1B740 802401D0 44820000 */  mtc1      $v0, $f0
/* B1B744 802401D4 00000000 */  nop
/* B1B748 802401D8 46800020 */  cvt.s.w   $f0, $f0
/* B1B74C 802401DC 46160582 */  mul.s     $f22, $f0, $f22
/* B1B750 802401E0 00000000 */  nop
/* B1B754 802401E4 461AB583 */  div.s     $f22, $f22, $f26
/* B1B758 802401E8 0C00A85B */  jal       sin_rad
/* B1B75C 802401EC 4600B306 */   mov.s    $f12, $f22
/* B1B760 802401F0 46000786 */  mov.s     $f30, $f0
/* B1B764 802401F4 0C00A874 */  jal       cos_rad
/* B1B768 802401F8 4600B306 */   mov.s    $f12, $f22
/* B1B76C 802401FC 4600C002 */  mul.s     $f0, $f24, $f0
/* B1B770 80240200 00000000 */  nop
/* B1B774 80240204 4600F087 */  neg.s     $f2, $f30
/* B1B778 80240208 4602C602 */  mul.s     $f24, $f24, $f2
/* B1B77C 8024020C 00000000 */  nop
/* B1B780 80240210 461C0001 */  sub.s     $f0, $f0, $f28
/* B1B784 80240214 4614C601 */  sub.s     $f24, $f24, $f20
/* B1B788 80240218 C6020038 */  lwc1      $f2, 0x38($s0)
/* B1B78C 8024021C 46001080 */  add.s     $f2, $f2, $f0
/* B1B790 80240220 C6000040 */  lwc1      $f0, 0x40($s0)
/* B1B794 80240224 46180000 */  add.s     $f0, $f0, $f24
/* B1B798 80240228 24020002 */  addiu     $v0, $zero, 2
/* B1B79C 8024022C E6020038 */  swc1      $f2, 0x38($s0)
/* B1B7A0 80240230 E6000040 */  swc1      $f0, 0x40($s0)
.L80240234:
/* B1B7A4 80240234 8FBF0018 */  lw        $ra, 0x18($sp)
/* B1B7A8 80240238 8FB10014 */  lw        $s1, 0x14($sp)
/* B1B7AC 8024023C 8FB00010 */  lw        $s0, 0x10($sp)
/* B1B7B0 80240240 D7BE0048 */  ldc1      $f30, 0x48($sp)
/* B1B7B4 80240244 D7BC0040 */  ldc1      $f28, 0x40($sp)
/* B1B7B8 80240248 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* B1B7BC 8024024C D7B80030 */  ldc1      $f24, 0x30($sp)
/* B1B7C0 80240250 D7B60028 */  ldc1      $f22, 0x28($sp)
/* B1B7C4 80240254 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B1B7C8 80240258 03E00008 */  jr        $ra
/* B1B7CC 8024025C 27BD0050 */   addiu    $sp, $sp, 0x50
