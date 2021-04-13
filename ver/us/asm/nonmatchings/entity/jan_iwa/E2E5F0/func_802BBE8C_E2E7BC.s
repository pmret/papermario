.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BBE8C_E2E7BC
/* E2E7BC 802BBE8C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* E2E7C0 802BBE90 AFB10024 */  sw        $s1, 0x24($sp)
/* E2E7C4 802BBE94 0080882D */  daddu     $s1, $a0, $zero
/* E2E7C8 802BBE98 AFBF0028 */  sw        $ra, 0x28($sp)
/* E2E7CC 802BBE9C AFB00020 */  sw        $s0, 0x20($sp)
/* E2E7D0 802BBEA0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* E2E7D4 802BBEA4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* E2E7D8 802BBEA8 0C0AEF5E */  jal       func_802BBD78_E2E6A8
/* E2E7DC 802BBEAC 8E300040 */   lw       $s0, 0x40($s1)
/* E2E7E0 802BBEB0 8E020000 */  lw        $v0, ($s0)
/* E2E7E4 802BBEB4 28420003 */  slti      $v0, $v0, 3
/* E2E7E8 802BBEB8 1040004D */  beqz      $v0, .L802BBFF0
/* E2E7EC 802BBEBC 00000000 */   nop
/* E2E7F0 802BBEC0 0C00A6C9 */  jal       clamp_angle
/* E2E7F4 802BBEC4 C62C0064 */   lwc1     $f12, 0x64($s1)
/* E2E7F8 802BBEC8 3C0140C9 */  lui       $at, 0x40c9
/* E2E7FC 802BBECC 34210FD0 */  ori       $at, $at, 0xfd0
/* E2E800 802BBED0 44811000 */  mtc1      $at, $f2
/* E2E804 802BBED4 00000000 */  nop
/* E2E808 802BBED8 46020502 */  mul.s     $f20, $f0, $f2
/* E2E80C 802BBEDC 00000000 */  nop
/* E2E810 802BBEE0 3C0143B4 */  lui       $at, 0x43b4
/* E2E814 802BBEE4 44810000 */  mtc1      $at, $f0
/* E2E818 802BBEE8 00000000 */  nop
/* E2E81C 802BBEEC 4600A503 */  div.s     $f20, $f20, $f0
/* E2E820 802BBEF0 0C00A874 */  jal       cos_rad
/* E2E824 802BBEF4 4600A306 */   mov.s    $f12, $f20
/* E2E828 802BBEF8 3C01C03A */  lui       $at, 0xc03a
/* E2E82C 802BBEFC 44811800 */  mtc1      $at, $f3
/* E2E830 802BBF00 44801000 */  mtc1      $zero, $f2
/* E2E834 802BBF04 46000021 */  cvt.d.s   $f0, $f0
/* E2E838 802BBF08 46220002 */  mul.d     $f0, $f0, $f2
/* E2E83C 802BBF0C 00000000 */  nop
/* E2E840 802BBF10 4600A306 */  mov.s     $f12, $f20
/* E2E844 802BBF14 0C00A85B */  jal       sin_rad
/* E2E848 802BBF18 46200520 */   cvt.s.d  $f20, $f0
/* E2E84C 802BBF1C 3C014018 */  lui       $at, 0x4018
/* E2E850 802BBF20 44811800 */  mtc1      $at, $f3
/* E2E854 802BBF24 44801000 */  mtc1      $zero, $f2
/* E2E858 802BBF28 46000021 */  cvt.d.s   $f0, $f0
/* E2E85C 802BBF2C 46220002 */  mul.d     $f0, $f0, $f2
/* E2E860 802BBF30 00000000 */  nop
/* E2E864 802BBF34 24040020 */  addiu     $a0, $zero, 0x20
/* E2E868 802BBF38 0C00A67F */  jal       rand_int
/* E2E86C 802BBF3C 462005A0 */   cvt.s.d  $f22, $f0
/* E2E870 802BBF40 28420011 */  slti      $v0, $v0, 0x11
/* E2E874 802BBF44 1440002A */  bnez      $v0, .L802BBFF0
/* E2E878 802BBF48 3C025555 */   lui      $v0, 0x5555
/* E2E87C 802BBF4C 8E050000 */  lw        $a1, ($s0)
/* E2E880 802BBF50 34425556 */  ori       $v0, $v0, 0x5556
/* E2E884 802BBF54 00A20018 */  mult      $a1, $v0
/* E2E888 802BBF58 C6260064 */  lwc1      $f6, 0x64($s1)
/* E2E88C 802BBF5C 3C0142DC */  lui       $at, 0x42dc
/* E2E890 802BBF60 44810000 */  mtc1      $at, $f0
/* E2E894 802BBF64 24A20001 */  addiu     $v0, $a1, 1
/* E2E898 802BBF68 46003181 */  sub.s     $f6, $f6, $f0
/* E2E89C 802BBF6C AE020000 */  sw        $v0, ($s0)
/* E2E8A0 802BBF70 C6240050 */  lwc1      $f4, 0x50($s1)
/* E2E8A4 802BBF74 46162100 */  add.s     $f4, $f4, $f22
/* E2E8A8 802BBF78 00051FC3 */  sra       $v1, $a1, 0x1f
/* E2E8AC 802BBF7C 00004010 */  mfhi      $t0
/* E2E8B0 802BBF80 01031823 */  subu      $v1, $t0, $v1
/* E2E8B4 802BBF84 00031040 */  sll       $v0, $v1, 1
/* E2E8B8 802BBF88 00431021 */  addu      $v0, $v0, $v1
/* E2E8BC 802BBF8C 00A22823 */  subu      $a1, $a1, $v0
/* E2E8C0 802BBF90 00051100 */  sll       $v0, $a1, 4
/* E2E8C4 802BBF94 00451023 */  subu      $v0, $v0, $a1
/* E2E8C8 802BBF98 00021040 */  sll       $v0, $v0, 1
/* E2E8CC 802BBF9C 44820000 */  mtc1      $v0, $f0
/* E2E8D0 802BBFA0 00000000 */  nop
/* E2E8D4 802BBFA4 46800020 */  cvt.s.w   $f0, $f0
/* E2E8D8 802BBFA8 46003180 */  add.s     $f6, $f6, $f0
/* E2E8DC 802BBFAC C6200048 */  lwc1      $f0, 0x48($s1)
/* E2E8E0 802BBFB0 46140000 */  add.s     $f0, $f0, $f20
/* E2E8E4 802BBFB4 C622004C */  lwc1      $f2, 0x4c($s1)
/* E2E8E8 802BBFB8 44072000 */  mfc1      $a3, $f4
/* E2E8EC 802BBFBC 44050000 */  mfc1      $a1, $f0
/* E2E8F0 802BBFC0 3C014278 */  lui       $at, 0x4278
/* E2E8F4 802BBFC4 44810000 */  mtc1      $at, $f0
/* E2E8F8 802BBFC8 24020003 */  addiu     $v0, $zero, 3
/* E2E8FC 802BBFCC AFA20010 */  sw        $v0, 0x10($sp)
/* E2E900 802BBFD0 46001080 */  add.s     $f2, $f2, $f0
/* E2E904 802BBFD4 AFA00014 */  sw        $zero, 0x14($sp)
/* E2E908 802BBFD8 AFA0001C */  sw        $zero, 0x1c($sp)
/* E2E90C 802BBFDC 44061000 */  mfc1      $a2, $f2
/* E2E910 802BBFE0 4600320D */  trunc.w.s $f8, $f6
/* E2E914 802BBFE4 E7A80018 */  swc1      $f8, 0x18($sp)
/* E2E918 802BBFE8 0C04C4FD */  jal       make_item_entity
/* E2E91C 802BBFEC 24040157 */   addiu    $a0, $zero, 0x157
.L802BBFF0:
/* E2E920 802BBFF0 8FBF0028 */  lw        $ra, 0x28($sp)
/* E2E924 802BBFF4 8FB10024 */  lw        $s1, 0x24($sp)
/* E2E928 802BBFF8 8FB00020 */  lw        $s0, 0x20($sp)
/* E2E92C 802BBFFC D7B60038 */  ldc1      $f22, 0x38($sp)
/* E2E930 802BC000 D7B40030 */  ldc1      $f20, 0x30($sp)
/* E2E934 802BC004 03E00008 */  jr        $ra
/* E2E938 802BC008 27BD0040 */   addiu    $sp, $sp, 0x40
