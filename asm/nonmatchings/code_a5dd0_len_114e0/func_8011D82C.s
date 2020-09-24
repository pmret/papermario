.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011D82C
/* B3F2C 8011D82C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B3F30 8011D830 AFB10014 */  sw        $s1, 0x14($sp)
/* B3F34 8011D834 3C118015 */  lui       $s1, 0x8015
/* B3F38 8011D838 8E3112CC */  lw        $s1, 0x12cc($s1)
/* B3F3C 8011D83C AFB20018 */  sw        $s2, 0x18($sp)
/* B3F40 8011D840 0080902D */  daddu     $s2, $a0, $zero
/* B3F44 8011D844 AFB00010 */  sw        $s0, 0x10($sp)
/* B3F48 8011D848 0000802D */  daddu     $s0, $zero, $zero
/* B3F4C 8011D84C AFBF001C */  sw        $ra, 0x1c($sp)
.L8011D850:
/* B3F50 8011D850 8E240000 */  lw        $a0, ($s1)
/* B3F54 8011D854 50800005 */  beql      $a0, $zero, .L8011D86C
/* B3F58 8011D858 26100001 */   addiu    $s0, $s0, 1
/* B3F5C 8011D85C 2405FFFF */  addiu     $a1, $zero, -1
/* B3F60 8011D860 0C046F1F */  jal       func_8011BC7C
/* B3F64 8011D864 0240302D */   daddu    $a2, $s2, $zero
/* B3F68 8011D868 26100001 */  addiu     $s0, $s0, 1
.L8011D86C:
/* B3F6C 8011D86C 2A020100 */  slti      $v0, $s0, 0x100
/* B3F70 8011D870 1440FFF7 */  bnez      $v0, .L8011D850
/* B3F74 8011D874 26310004 */   addiu    $s1, $s1, 4
/* B3F78 8011D878 8FBF001C */  lw        $ra, 0x1c($sp)
/* B3F7C 8011D87C 8FB20018 */  lw        $s2, 0x18($sp)
/* B3F80 8011D880 8FB10014 */  lw        $s1, 0x14($sp)
/* B3F84 8011D884 8FB00010 */  lw        $s0, 0x10($sp)
/* B3F88 8011D888 03E00008 */  jr        $ra
/* B3F8C 8011D88C 27BD0020 */   addiu    $sp, $sp, 0x20
