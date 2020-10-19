.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417AC_D06EDC
/* D06EDC 802417AC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D06EE0 802417B0 AFB20018 */  sw        $s2, 0x18($sp)
/* D06EE4 802417B4 0080902D */  daddu     $s2, $a0, $zero
/* D06EE8 802417B8 AFBF0030 */  sw        $ra, 0x30($sp)
/* D06EEC 802417BC AFB7002C */  sw        $s7, 0x2c($sp)
/* D06EF0 802417C0 AFB60028 */  sw        $s6, 0x28($sp)
/* D06EF4 802417C4 AFB50024 */  sw        $s5, 0x24($sp)
/* D06EF8 802417C8 AFB40020 */  sw        $s4, 0x20($sp)
/* D06EFC 802417CC AFB3001C */  sw        $s3, 0x1c($sp)
/* D06F00 802417D0 AFB10014 */  sw        $s1, 0x14($sp)
/* D06F04 802417D4 AFB00010 */  sw        $s0, 0x10($sp)
/* D06F08 802417D8 F7B60040 */  sdc1      $f22, 0x40($sp)
/* D06F0C 802417DC F7B40038 */  sdc1      $f20, 0x38($sp)
/* D06F10 802417E0 8E50000C */  lw        $s0, 0xc($s2)
/* D06F14 802417E4 8E050000 */  lw        $a1, ($s0)
/* D06F18 802417E8 0C0B1EAF */  jal       get_variable
/* D06F1C 802417EC 26100004 */   addiu    $s0, $s0, 4
/* D06F20 802417F0 8E050000 */  lw        $a1, ($s0)
/* D06F24 802417F4 26100004 */  addiu     $s0, $s0, 4
/* D06F28 802417F8 0240202D */  daddu     $a0, $s2, $zero
/* D06F2C 802417FC 0C0B1EAF */  jal       get_variable
/* D06F30 80241800 0040B82D */   daddu    $s7, $v0, $zero
/* D06F34 80241804 8E050000 */  lw        $a1, ($s0)
/* D06F38 80241808 26100004 */  addiu     $s0, $s0, 4
/* D06F3C 8024180C 0240202D */  daddu     $a0, $s2, $zero
/* D06F40 80241810 0C0B1EAF */  jal       get_variable
/* D06F44 80241814 0040B02D */   daddu    $s6, $v0, $zero
/* D06F48 80241818 0240202D */  daddu     $a0, $s2, $zero
/* D06F4C 8024181C 3C05F4AC */  lui       $a1, 0xf4ac
/* D06F50 80241820 34A5D481 */  ori       $a1, $a1, 0xd481
/* D06F54 80241824 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* D06F58 80241828 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* D06F5C 8024182C 8E140000 */  lw        $s4, ($s0)
/* D06F60 80241830 00061880 */  sll       $v1, $a2, 2
/* D06F64 80241834 00661821 */  addu      $v1, $v1, $a2
/* D06F68 80241838 00031880 */  sll       $v1, $v1, 2
/* D06F6C 8024183C 00661823 */  subu      $v1, $v1, $a2
/* D06F70 80241840 000330C0 */  sll       $a2, $v1, 3
/* D06F74 80241844 00661821 */  addu      $v1, $v1, $a2
/* D06F78 80241848 000318C0 */  sll       $v1, $v1, 3
/* D06F7C 8024184C 3C01800B */  lui       $at, 0x800b
/* D06F80 80241850 00230821 */  addu      $at, $at, $v1
/* D06F84 80241854 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* D06F88 80241858 8E150004 */  lw        $s5, 4($s0)
/* D06F8C 8024185C 4600010D */  trunc.w.s $f4, $f0
/* D06F90 80241860 44112000 */  mfc1      $s1, $f4
/* D06F94 80241864 0C0B1EAF */  jal       get_variable
/* D06F98 80241868 0040982D */   daddu    $s3, $v0, $zero
/* D06F9C 8024186C 4491B000 */  mtc1      $s1, $f22
/* D06FA0 80241870 00000000 */  nop       
/* D06FA4 80241874 4680B5A0 */  cvt.s.w   $f22, $f22
/* D06FA8 80241878 4600B306 */  mov.s     $f12, $f22
/* D06FAC 8024187C 0C00A8D4 */  jal       cos_deg
/* D06FB0 80241880 0040802D */   daddu    $s0, $v0, $zero
/* D06FB4 80241884 4493A000 */  mtc1      $s3, $f20
/* D06FB8 80241888 00000000 */  nop       
/* D06FBC 8024188C 4680A520 */  cvt.s.w   $f20, $f20
/* D06FC0 80241890 4600A002 */  mul.s     $f0, $f20, $f0
/* D06FC4 80241894 00000000 */  nop       
/* D06FC8 80241898 0240202D */  daddu     $a0, $s2, $zero
/* D06FCC 8024189C 44901000 */  mtc1      $s0, $f2
/* D06FD0 802418A0 00000000 */  nop       
/* D06FD4 802418A4 468010A0 */  cvt.s.w   $f2, $f2
/* D06FD8 802418A8 46001081 */  sub.s     $f2, $f2, $f0
/* D06FDC 802418AC 3C05F4AC */  lui       $a1, 0xf4ac
/* D06FE0 802418B0 4600110D */  trunc.w.s $f4, $f2
/* D06FE4 802418B4 44102000 */  mfc1      $s0, $f4
/* D06FE8 802418B8 0C0B1EAF */  jal       get_variable
/* D06FEC 802418BC 34A5D483 */   ori      $a1, $a1, 0xd483
/* D06FF0 802418C0 4600B306 */  mov.s     $f12, $f22
/* D06FF4 802418C4 0C00A8BB */  jal       sin_deg
/* D06FF8 802418C8 0040882D */   daddu    $s1, $v0, $zero
/* D06FFC 802418CC 4600A502 */  mul.s     $f20, $f20, $f0
/* D07000 802418D0 00000000 */  nop       
/* D07004 802418D4 0240202D */  daddu     $a0, $s2, $zero
/* D07008 802418D8 44910000 */  mtc1      $s1, $f0
/* D0700C 802418DC 00000000 */  nop       
/* D07010 802418E0 46800020 */  cvt.s.w   $f0, $f0
/* D07014 802418E4 46140001 */  sub.s     $f0, $f0, $f20
/* D07018 802418E8 0280282D */  daddu     $a1, $s4, $zero
/* D0701C 802418EC 02173023 */  subu      $a2, $s0, $s7
/* D07020 802418F0 4600010D */  trunc.w.s $f4, $f0
/* D07024 802418F4 44102000 */  mfc1      $s0, $f4
/* D07028 802418F8 0C0B2026 */  jal       set_variable
/* D0702C 802418FC 02168023 */   subu     $s0, $s0, $s6
/* D07030 80241900 0240202D */  daddu     $a0, $s2, $zero
/* D07034 80241904 02A0282D */  daddu     $a1, $s5, $zero
/* D07038 80241908 0C0B2026 */  jal       set_variable
/* D0703C 8024190C 0200302D */   daddu    $a2, $s0, $zero
/* D07040 80241910 8FBF0030 */  lw        $ra, 0x30($sp)
/* D07044 80241914 8FB7002C */  lw        $s7, 0x2c($sp)
/* D07048 80241918 8FB60028 */  lw        $s6, 0x28($sp)
/* D0704C 8024191C 8FB50024 */  lw        $s5, 0x24($sp)
/* D07050 80241920 8FB40020 */  lw        $s4, 0x20($sp)
/* D07054 80241924 8FB3001C */  lw        $s3, 0x1c($sp)
/* D07058 80241928 8FB20018 */  lw        $s2, 0x18($sp)
/* D0705C 8024192C 8FB10014 */  lw        $s1, 0x14($sp)
/* D07060 80241930 8FB00010 */  lw        $s0, 0x10($sp)
/* D07064 80241934 D7B60040 */  ldc1      $f22, 0x40($sp)
/* D07068 80241938 D7B40038 */  ldc1      $f20, 0x38($sp)
/* D0706C 8024193C 24020002 */  addiu     $v0, $zero, 2
/* D07070 80241940 03E00008 */  jr        $ra
/* D07074 80241944 27BD0048 */   addiu    $sp, $sp, 0x48
