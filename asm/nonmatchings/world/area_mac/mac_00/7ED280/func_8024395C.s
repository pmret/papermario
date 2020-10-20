.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024395C
/* 7EE66C 8024395C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7EE670 80243960 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7EE674 80243964 0080882D */  daddu     $s1, $a0, $zero
/* 7EE678 80243968 AFBF0034 */  sw        $ra, 0x34($sp)
/* 7EE67C 8024396C AFB60030 */  sw        $s6, 0x30($sp)
/* 7EE680 80243970 AFB5002C */  sw        $s5, 0x2c($sp)
/* 7EE684 80243974 AFB40028 */  sw        $s4, 0x28($sp)
/* 7EE688 80243978 AFB30024 */  sw        $s3, 0x24($sp)
/* 7EE68C 8024397C AFB20020 */  sw        $s2, 0x20($sp)
/* 7EE690 80243980 AFB00018 */  sw        $s0, 0x18($sp)
/* 7EE694 80243984 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 7EE698 80243988 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 7EE69C 8024398C 8E30000C */  lw        $s0, 0xc($s1)
/* 7EE6A0 80243990 8E160000 */  lw        $s6, ($s0)
/* 7EE6A4 80243994 26100004 */  addiu     $s0, $s0, 4
/* 7EE6A8 80243998 0C0B1EAF */  jal       get_variable
/* 7EE6AC 8024399C 02C0282D */   daddu    $a1, $s6, $zero
/* 7EE6B0 802439A0 44820000 */  mtc1      $v0, $f0
/* 7EE6B4 802439A4 00000000 */  nop       
/* 7EE6B8 802439A8 46800020 */  cvt.s.w   $f0, $f0
/* 7EE6BC 802439AC E7A00010 */  swc1      $f0, 0x10($sp)
/* 7EE6C0 802439B0 8E140000 */  lw        $s4, ($s0)
/* 7EE6C4 802439B4 26100004 */  addiu     $s0, $s0, 4
/* 7EE6C8 802439B8 0220202D */  daddu     $a0, $s1, $zero
/* 7EE6CC 802439BC 0C0B1EAF */  jal       get_variable
/* 7EE6D0 802439C0 0280282D */   daddu    $a1, $s4, $zero
/* 7EE6D4 802439C4 0220202D */  daddu     $a0, $s1, $zero
/* 7EE6D8 802439C8 8E150000 */  lw        $s5, ($s0)
/* 7EE6DC 802439CC 4482B000 */  mtc1      $v0, $f22
/* 7EE6E0 802439D0 00000000 */  nop       
/* 7EE6E4 802439D4 4680B5A0 */  cvt.s.w   $f22, $f22
/* 7EE6E8 802439D8 0C0B1EAF */  jal       get_variable
/* 7EE6EC 802439DC 02A0282D */   daddu    $a1, $s5, $zero
/* 7EE6F0 802439E0 2404FFFC */  addiu     $a0, $zero, -4
/* 7EE6F4 802439E4 44820000 */  mtc1      $v0, $f0
/* 7EE6F8 802439E8 00000000 */  nop       
/* 7EE6FC 802439EC 46800020 */  cvt.s.w   $f0, $f0
/* 7EE700 802439F0 0C00EABB */  jal       get_npc_unsafe
/* 7EE704 802439F4 E7A00014 */   swc1     $f0, 0x14($sp)
/* 7EE708 802439F8 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 7EE70C 802439FC 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 7EE710 80243A00 3C014334 */  lui       $at, 0x4334
/* 7EE714 80243A04 44816000 */  mtc1      $at, $f12
/* 7EE718 80243A08 00041880 */  sll       $v1, $a0, 2
/* 7EE71C 80243A0C 00641821 */  addu      $v1, $v1, $a0
/* 7EE720 80243A10 00031880 */  sll       $v1, $v1, 2
/* 7EE724 80243A14 00641823 */  subu      $v1, $v1, $a0
/* 7EE728 80243A18 000320C0 */  sll       $a0, $v1, 3
/* 7EE72C 80243A1C 00641821 */  addu      $v1, $v1, $a0
/* 7EE730 80243A20 000318C0 */  sll       $v1, $v1, 3
/* 7EE734 80243A24 3C01800B */  lui       $at, 0x800b
/* 7EE738 80243A28 00230821 */  addu      $at, $at, $v1
/* 7EE73C 80243A2C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7EE740 80243A30 460C0300 */  add.s     $f12, $f0, $f12
/* 7EE744 80243A34 0C00A6C9 */  jal       clamp_angle
/* 7EE748 80243A38 0040982D */   daddu    $s3, $v0, $zero
/* 7EE74C 80243A3C 27B00010 */  addiu     $s0, $sp, 0x10
/* 7EE750 80243A40 0200202D */  daddu     $a0, $s0, $zero
/* 7EE754 80243A44 27B20014 */  addiu     $s2, $sp, 0x14
/* 7EE758 80243A48 0240282D */  daddu     $a1, $s2, $zero
/* 7EE75C 80243A4C 3C064170 */  lui       $a2, 0x4170
/* 7EE760 80243A50 8E67000C */  lw        $a3, 0xc($s3)
/* 7EE764 80243A54 0C00A7E7 */  jal       add_vec2D_polar
/* 7EE768 80243A58 46000506 */   mov.s    $f20, $f0
/* 7EE76C 80243A5C 0200202D */  daddu     $a0, $s0, $zero
/* 7EE770 80243A60 3C064120 */  lui       $a2, 0x4120
/* 7EE774 80243A64 4407A000 */  mfc1      $a3, $f20
/* 7EE778 80243A68 0C00A7E7 */  jal       add_vec2D_polar
/* 7EE77C 80243A6C 0240282D */   daddu    $a1, $s2, $zero
/* 7EE780 80243A70 0220202D */  daddu     $a0, $s1, $zero
/* 7EE784 80243A74 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 7EE788 80243A78 4600008D */  trunc.w.s $f2, $f0
/* 7EE78C 80243A7C 44061000 */  mfc1      $a2, $f2
/* 7EE790 80243A80 0C0B2026 */  jal       set_variable
/* 7EE794 80243A84 02C0282D */   daddu    $a1, $s6, $zero
/* 7EE798 80243A88 0220202D */  daddu     $a0, $s1, $zero
/* 7EE79C 80243A8C 4600B08D */  trunc.w.s $f2, $f22
/* 7EE7A0 80243A90 44061000 */  mfc1      $a2, $f2
/* 7EE7A4 80243A94 0C0B2026 */  jal       set_variable
/* 7EE7A8 80243A98 0280282D */   daddu    $a1, $s4, $zero
/* 7EE7AC 80243A9C 0220202D */  daddu     $a0, $s1, $zero
/* 7EE7B0 80243AA0 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 7EE7B4 80243AA4 4600008D */  trunc.w.s $f2, $f0
/* 7EE7B8 80243AA8 44061000 */  mfc1      $a2, $f2
/* 7EE7BC 80243AAC 0C0B2026 */  jal       set_variable
/* 7EE7C0 80243AB0 02A0282D */   daddu    $a1, $s5, $zero
/* 7EE7C4 80243AB4 8FBF0034 */  lw        $ra, 0x34($sp)
/* 7EE7C8 80243AB8 8FB60030 */  lw        $s6, 0x30($sp)
/* 7EE7CC 80243ABC 8FB5002C */  lw        $s5, 0x2c($sp)
/* 7EE7D0 80243AC0 8FB40028 */  lw        $s4, 0x28($sp)
/* 7EE7D4 80243AC4 8FB30024 */  lw        $s3, 0x24($sp)
/* 7EE7D8 80243AC8 8FB20020 */  lw        $s2, 0x20($sp)
/* 7EE7DC 80243ACC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7EE7E0 80243AD0 8FB00018 */  lw        $s0, 0x18($sp)
/* 7EE7E4 80243AD4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 7EE7E8 80243AD8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 7EE7EC 80243ADC 24020002 */  addiu     $v0, $zero, 2
/* 7EE7F0 80243AE0 03E00008 */  jr        $ra
/* 7EE7F4 80243AE4 27BD0048 */   addiu    $sp, $sp, 0x48
