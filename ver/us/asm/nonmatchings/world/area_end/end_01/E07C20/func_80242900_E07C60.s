.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242900_E07C60
/* E07C60 80242900 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E07C64 80242904 AFB00010 */  sw        $s0, 0x10($sp)
/* E07C68 80242908 0080802D */  daddu     $s0, $a0, $zero
/* E07C6C 8024290C 10A00003 */  beqz      $a1, .L8024291C
/* E07C70 80242910 AFBF0014 */   sw       $ra, 0x14($sp)
/* E07C74 80242914 240200FF */  addiu     $v0, $zero, 0xff
/* E07C78 80242918 AE020074 */  sw        $v0, 0x74($s0)
.L8024291C:
/* E07C7C 8024291C 8E020074 */  lw        $v0, 0x74($s0)
/* E07C80 80242920 2442FFF6 */  addiu     $v0, $v0, -0xa
/* E07C84 80242924 04410002 */  bgez      $v0, .L80242930
/* E07C88 80242928 AE020074 */   sw       $v0, 0x74($s0)
/* E07C8C 8024292C AE000074 */  sw        $zero, 0x74($s0)
.L80242930:
/* E07C90 80242930 0000202D */  daddu     $a0, $zero, $zero
/* E07C94 80242934 0080282D */  daddu     $a1, $a0, $zero
/* E07C98 80242938 92070077 */  lbu       $a3, 0x77($s0)
/* E07C9C 8024293C 0C046F97 */  jal       set_background_color_blend
/* E07CA0 80242940 0080302D */   daddu    $a2, $a0, $zero
/* E07CA4 80242944 8E020074 */  lw        $v0, 0x74($s0)
/* E07CA8 80242948 14400007 */  bnez      $v0, .L80242968
/* E07CAC 8024294C 0000102D */   daddu    $v0, $zero, $zero
/* E07CB0 80242950 2404005B */  addiu     $a0, $zero, 0x5b
/* E07CB4 80242954 2405FFFF */  addiu     $a1, $zero, -1
/* E07CB8 80242958 0000302D */  daddu     $a2, $zero, $zero
/* E07CBC 8024295C 0C046E54 */  jal       func_8011B950
/* E07CC0 80242960 00C0382D */   daddu    $a3, $a2, $zero
/* E07CC4 80242964 24020002 */  addiu     $v0, $zero, 2
.L80242968:
/* E07CC8 80242968 8FBF0014 */  lw        $ra, 0x14($sp)
/* E07CCC 8024296C 8FB00010 */  lw        $s0, 0x10($sp)
/* E07CD0 80242970 03E00008 */  jr        $ra
/* E07CD4 80242974 27BD0018 */   addiu    $sp, $sp, 0x18
