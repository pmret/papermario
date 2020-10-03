.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011B660
/* B1D60 8011B660 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B1D64 8011B664 3084FFFF */  andi      $a0, $a0, 0xffff
/* B1D68 8011B668 AFBF0018 */  sw        $ra, 0x18($sp)
/* B1D6C 8011B66C AFB10014 */  sw        $s1, 0x14($sp)
/* B1D70 8011B670 0C046C24 */  jal       func_8011B090
/* B1D74 8011B674 AFB00010 */   sw       $s0, 0x10($sp)
/* B1D78 8011B678 0C046C70 */  jal       func_8011B1C0
/* B1D7C 8011B67C 0040202D */   daddu    $a0, $v0, $zero
/* B1D80 8011B680 0040882D */  daddu     $s1, $v0, $zero
/* B1D84 8011B684 9230009C */  lbu       $s0, 0x9c($s1)
/* B1D88 8011B688 96220000 */  lhu       $v0, ($s1)
/* B1D8C 8011B68C 9223009D */  lbu       $v1, 0x9d($s1)
/* B1D90 8011B690 34420004 */  ori       $v0, $v0, 4
/* B1D94 8011B694 0070182A */  slt       $v1, $v1, $s0
/* B1D98 8011B698 14600010 */  bnez      $v1, .L8011B6DC
/* B1D9C 8011B69C A6220000 */   sh       $v0, ($s1)
.L8011B6A0:
/* B1DA0 8011B6A0 0C046B4C */  jal       get_model_from_list_index
/* B1DA4 8011B6A4 0200202D */   daddu    $a0, $s0, $zero
/* B1DA8 8011B6A8 0040202D */  daddu     $a0, $v0, $zero
/* B1DAC 8011B6AC 94820000 */  lhu       $v0, ($a0)
/* B1DB0 8011B6B0 8C830004 */  lw        $v1, 4($a0)
/* B1DB4 8011B6B4 3042FFF7 */  andi      $v0, $v0, 0xfff7
/* B1DB8 8011B6B8 10600003 */  beqz      $v1, .L8011B6C8
/* B1DBC 8011B6BC A4820000 */   sh       $v0, ($a0)
/* B1DC0 8011B6C0 34421000 */  ori       $v0, $v0, 0x1000
/* B1DC4 8011B6C4 A4820000 */  sh        $v0, ($a0)
.L8011B6C8:
/* B1DC8 8011B6C8 9222009D */  lbu       $v0, 0x9d($s1)
/* B1DCC 8011B6CC 26100001 */  addiu     $s0, $s0, 1
/* B1DD0 8011B6D0 0050102A */  slt       $v0, $v0, $s0
/* B1DD4 8011B6D4 1040FFF2 */  beqz      $v0, .L8011B6A0
/* B1DD8 8011B6D8 00000000 */   nop      
.L8011B6DC:
/* B1DDC 8011B6DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* B1DE0 8011B6E0 8FB10014 */  lw        $s1, 0x14($sp)
/* B1DE4 8011B6E4 8FB00010 */  lw        $s0, 0x10($sp)
/* B1DE8 8011B6E8 03E00008 */  jr        $ra
/* B1DEC 8011B6EC 27BD0020 */   addiu    $sp, $sp, 0x20
