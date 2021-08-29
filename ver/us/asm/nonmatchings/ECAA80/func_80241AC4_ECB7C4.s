.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AC4_ECB7C4
/* ECB7C4 80241AC4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ECB7C8 80241AC8 AFB10014 */  sw        $s1, 0x14($sp)
/* ECB7CC 80241ACC 0080882D */  daddu     $s1, $a0, $zero
/* ECB7D0 80241AD0 AFBF0020 */  sw        $ra, 0x20($sp)
/* ECB7D4 80241AD4 AFB3001C */  sw        $s3, 0x1c($sp)
/* ECB7D8 80241AD8 AFB20018 */  sw        $s2, 0x18($sp)
/* ECB7DC 80241ADC AFB00010 */  sw        $s0, 0x10($sp)
/* ECB7E0 80241AE0 8E30000C */  lw        $s0, 0xc($s1)
/* ECB7E4 80241AE4 8E050000 */  lw        $a1, ($s0)
/* ECB7E8 80241AE8 0C0B53A3 */  jal       dead_evt_get_variable
/* ECB7EC 80241AEC 26100004 */   addiu    $s0, $s0, 4
/* ECB7F0 80241AF0 8E050000 */  lw        $a1, ($s0)
/* ECB7F4 80241AF4 26100004 */  addiu     $s0, $s0, 4
/* ECB7F8 80241AF8 0220202D */  daddu     $a0, $s1, $zero
/* ECB7FC 80241AFC 0C0B53A3 */  jal       dead_evt_get_variable
/* ECB800 80241B00 0040982D */   daddu    $s3, $v0, $zero
/* ECB804 80241B04 8E050000 */  lw        $a1, ($s0)
/* ECB808 80241B08 26100004 */  addiu     $s0, $s0, 4
/* ECB80C 80241B0C 0220202D */  daddu     $a0, $s1, $zero
/* ECB810 80241B10 0C0B53A3 */  jal       dead_evt_get_variable
/* ECB814 80241B14 0040902D */   daddu    $s2, $v0, $zero
/* ECB818 80241B18 0220202D */  daddu     $a0, $s1, $zero
/* ECB81C 80241B1C 8E050000 */  lw        $a1, ($s0)
/* ECB820 80241B20 0C0B53A3 */  jal       dead_evt_get_variable
/* ECB824 80241B24 0040882D */   daddu    $s1, $v0, $zero
/* ECB828 80241B28 0260202D */  daddu     $a0, $s3, $zero
/* ECB82C 80241B2C 0C04F3E6 */  jal       func_8013CF98
/* ECB830 80241B30 0040802D */   daddu    $s0, $v0, $zero
/* ECB834 80241B34 0040182D */  daddu     $v1, $v0, $zero
/* ECB838 80241B38 44920000 */  mtc1      $s2, $f0
/* ECB83C 80241B3C 00000000 */  nop
/* ECB840 80241B40 46800020 */  cvt.s.w   $f0, $f0
/* ECB844 80241B44 E4600008 */  swc1      $f0, 8($v1)
/* ECB848 80241B48 44910000 */  mtc1      $s1, $f0
/* ECB84C 80241B4C 00000000 */  nop
/* ECB850 80241B50 46800020 */  cvt.s.w   $f0, $f0
/* ECB854 80241B54 E460000C */  swc1      $f0, 0xc($v1)
/* ECB858 80241B58 44900000 */  mtc1      $s0, $f0
/* ECB85C 80241B5C 00000000 */  nop
/* ECB860 80241B60 46800020 */  cvt.s.w   $f0, $f0
/* ECB864 80241B64 E4600010 */  swc1      $f0, 0x10($v1)
/* ECB868 80241B68 8FBF0020 */  lw        $ra, 0x20($sp)
/* ECB86C 80241B6C 8FB3001C */  lw        $s3, 0x1c($sp)
/* ECB870 80241B70 8FB20018 */  lw        $s2, 0x18($sp)
/* ECB874 80241B74 8FB10014 */  lw        $s1, 0x14($sp)
/* ECB878 80241B78 8FB00010 */  lw        $s0, 0x10($sp)
/* ECB87C 80241B7C 24020002 */  addiu     $v0, $zero, 2
/* ECB880 80241B80 03E00008 */  jr        $ra
/* ECB884 80241B84 27BD0028 */   addiu    $sp, $sp, 0x28
