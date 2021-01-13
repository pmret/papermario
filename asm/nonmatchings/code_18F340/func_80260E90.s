.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80260E90
/* 18F770 80260E90 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 18F774 80260E94 AFB50044 */  sw        $s5, 0x44($sp)
/* 18F778 80260E98 0080A82D */  daddu     $s5, $a0, $zero
/* 18F77C 80260E9C AFB10034 */  sw        $s1, 0x34($sp)
/* 18F780 80260EA0 0000882D */  daddu     $s1, $zero, $zero
/* 18F784 80260EA4 2405001D */  addiu     $a1, $zero, 0x1d
/* 18F788 80260EA8 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 18F78C 80260EAC 4480A000 */  mtc1      $zero, $f20
/* 18F790 80260EB0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 18F794 80260EB4 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 18F798 80260EB8 AFBF0048 */  sw        $ra, 0x48($sp)
/* 18F79C 80260EBC AFB40040 */  sw        $s4, 0x40($sp)
/* 18F7A0 80260EC0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 18F7A4 80260EC4 AFB20038 */  sw        $s2, 0x38($sp)
/* 18F7A8 80260EC8 AFB00030 */  sw        $s0, 0x30($sp)
/* 18F7AC 80260ECC F7B80060 */  sdc1      $f24, 0x60($sp)
/* 18F7B0 80260ED0 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 18F7B4 80260ED4 8C5300D8 */  lw        $s3, 0xd8($v0)
/* 18F7B8 80260ED8 8442017A */  lh        $v0, 0x17a($v0)
/* 18F7BC 80260EDC 0260202D */  daddu     $a0, $s3, $zero
/* 18F7C0 80260EE0 00021140 */  sll       $v0, $v0, 5
/* 18F7C4 80260EE4 3C128008 */  lui       $s2, %hi(gItemTable+0xC)
/* 18F7C8 80260EE8 02429021 */  addu      $s2, $s2, $v0
/* 18F7CC 80260EEC 865278EC */  lh        $s2, %lo(gItemTable+0xC)($s2)
/* 18F7D0 80260EF0 92620191 */  lbu       $v0, 0x191($s3)
/* 18F7D4 80260EF4 C6620148 */  lwc1      $f2, 0x148($s3)
/* 18F7D8 80260EF8 44820000 */  mtc1      $v0, $f0
/* 18F7DC 80260EFC 00000000 */  nop
/* 18F7E0 80260F00 46800020 */  cvt.s.w   $f0, $f0
/* 18F7E4 80260F04 0C099CAB */  jal       heroes_is_ability_active
/* 18F7E8 80260F08 46001580 */   add.s    $f22, $f2, $f0
/* 18F7EC 80260F0C 50400048 */  beql      $v0, $zero, .L80261030
/* 18F7F0 80260F10 AEB10084 */   sw       $s1, 0x84($s5)
/* 18F7F4 80260F14 1A400045 */  blez      $s2, .L8026102C
/* 18F7F8 80260F18 3C0451EB */   lui      $a0, 0x51eb
/* 18F7FC 80260F1C 3484851F */  ori       $a0, $a0, 0x851f
/* 18F800 80260F20 00121880 */  sll       $v1, $s2, 2
/* 18F804 80260F24 00721821 */  addu      $v1, $v1, $s2
/* 18F808 80260F28 00031100 */  sll       $v0, $v1, 4
/* 18F80C 80260F2C 00431023 */  subu      $v0, $v0, $v1
/* 18F810 80260F30 24420063 */  addiu     $v0, $v0, 0x63
/* 18F814 80260F34 00440018 */  mult      $v0, $a0
/* 18F818 80260F38 000217C3 */  sra       $v0, $v0, 0x1f
/* 18F81C 80260F3C 00004010 */  mfhi      $t0
/* 18F820 80260F40 00081943 */  sra       $v1, $t0, 5
/* 18F824 80260F44 00629023 */  subu      $s2, $v1, $v0
/* 18F828 80260F48 0232102A */  slt       $v0, $s1, $s2
/* 18F82C 80260F4C 10400019 */  beqz      $v0, .L80260FB4
/* 18F830 80260F50 0220802D */   daddu    $s0, $s1, $zero
/* 18F834 80260F54 24140017 */  addiu     $s4, $zero, 0x17
/* 18F838 80260F58 3C0141F0 */  lui       $at, 0x41f0
/* 18F83C 80260F5C 4481C000 */  mtc1      $at, $f24
/* 18F840 80260F60 24110001 */  addiu     $s1, $zero, 1
.L80260F64:
/* 18F844 80260F64 C6600144 */  lwc1      $f0, 0x144($s3)
/* 18F848 80260F68 C662014C */  lwc1      $f2, 0x14c($s3)
/* 18F84C 80260F6C 4600A10D */  trunc.w.s $f4, $f20
/* 18F850 80260F70 E7A40018 */  swc1      $f4, 0x18($sp)
/* 18F854 80260F74 24040157 */  addiu     $a0, $zero, 0x157
/* 18F858 80260F78 AFB10014 */  sw        $s1, 0x14($sp)
/* 18F85C 80260F7C 26310003 */  addiu     $s1, $s1, 3
/* 18F860 80260F80 26100001 */  addiu     $s0, $s0, 1
/* 18F864 80260F84 4406B000 */  mfc1      $a2, $f22
/* 18F868 80260F88 44050000 */  mfc1      $a1, $f0
/* 18F86C 80260F8C 44071000 */  mfc1      $a3, $f2
/* 18F870 80260F90 4618A500 */  add.s     $f20, $f20, $f24
/* 18F874 80260F94 AFB40010 */  sw        $s4, 0x10($sp)
/* 18F878 80260F98 0C04C4FD */  jal       make_item_entity
/* 18F87C 80260F9C AFA0001C */   sw       $zero, 0x1c($sp)
/* 18F880 80260FA0 0C03A830 */  jal       add_coins
/* 18F884 80260FA4 24040001 */   addiu    $a0, $zero, 1
/* 18F888 80260FA8 0212102A */  slt       $v0, $s0, $s2
/* 18F88C 80260FAC 1440FFED */  bnez      $v0, .L80260F64
/* 18F890 80260FB0 00000000 */   nop
.L80260FB4:
/* 18F894 80260FB4 00101040 */  sll       $v0, $s0, 1
/* 18F898 80260FB8 00501021 */  addu      $v0, $v0, $s0
/* 18F89C 80260FBC 2451001E */  addiu     $s1, $v0, 0x1e
/* 18F8A0 80260FC0 C6600144 */  lwc1      $f0, 0x144($s3)
/* 18F8A4 80260FC4 C6760148 */  lwc1      $f22, 0x148($s3)
/* 18F8A8 80260FC8 C662014C */  lwc1      $f2, 0x14c($s3)
/* 18F8AC 80260FCC 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 18F8B0 80260FD0 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 18F8B4 80260FD4 27A20020 */  addiu     $v0, $sp, 0x20
/* 18F8B8 80260FD8 AFA20010 */  sw        $v0, 0x10($sp)
/* 18F8BC 80260FDC 27A20024 */  addiu     $v0, $sp, 0x24
/* 18F8C0 80260FE0 AFA20014 */  sw        $v0, 0x14($sp)
/* 18F8C4 80260FE4 44050000 */  mfc1      $a1, $f0
/* 18F8C8 80260FE8 4406B000 */  mfc1      $a2, $f22
/* 18F8CC 80260FEC 44071000 */  mfc1      $a3, $f2
/* 18F8D0 80260FF0 27A20028 */  addiu     $v0, $sp, 0x28
/* 18F8D4 80260FF4 0C00B94E */  jal       get_screen_coords
/* 18F8D8 80260FF8 AFA20018 */   sw       $v0, 0x18($sp)
/* 18F8DC 80260FFC 3C048011 */  lui       $a0, %hi(D_80108A64)
/* 18F8E0 80261000 24848A64 */  addiu     $a0, $a0, %lo(D_80108A64)
/* 18F8E4 80261004 0C050529 */  jal       create_icon
/* 18F8E8 80261008 00000000 */   nop
/* 18F8EC 8026100C 8FA50020 */  lw        $a1, 0x20($sp)
/* 18F8F0 80261010 8FA60024 */  lw        $a2, 0x24($sp)
/* 18F8F4 80261014 0040202D */  daddu     $a0, $v0, $zero
/* 18F8F8 80261018 3C01802A */  lui       $at, %hi(D_8029FBA0)
/* 18F8FC 8026101C AC24FBA0 */  sw        $a0, %lo(D_8029FBA0)($at)
/* 18F900 80261020 24A50024 */  addiu     $a1, $a1, 0x24
/* 18F904 80261024 0C051261 */  jal       set_icon_render_pos
/* 18F908 80261028 24C6FFC1 */   addiu    $a2, $a2, -0x3f
.L8026102C:
/* 18F90C 8026102C AEB10084 */  sw        $s1, 0x84($s5)
.L80261030:
/* 18F910 80261030 8FBF0048 */  lw        $ra, 0x48($sp)
/* 18F914 80261034 8FB50044 */  lw        $s5, 0x44($sp)
/* 18F918 80261038 8FB40040 */  lw        $s4, 0x40($sp)
/* 18F91C 8026103C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 18F920 80261040 8FB20038 */  lw        $s2, 0x38($sp)
/* 18F924 80261044 8FB10034 */  lw        $s1, 0x34($sp)
/* 18F928 80261048 8FB00030 */  lw        $s0, 0x30($sp)
/* 18F92C 8026104C D7B80060 */  ldc1      $f24, 0x60($sp)
/* 18F930 80261050 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 18F934 80261054 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 18F938 80261058 24020002 */  addiu     $v0, $zero, 2
/* 18F93C 8026105C 03E00008 */  jr        $ra
/* 18F940 80261060 27BD0068 */   addiu    $sp, $sp, 0x68
