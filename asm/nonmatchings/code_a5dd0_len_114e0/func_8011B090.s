.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011B090
/* B1790 8011B090 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B1794 8011B094 AFB10014 */  sw        $s1, 0x14($sp)
/* B1798 8011B098 0080882D */  daddu     $s1, $a0, $zero
/* B179C 8011B09C AFB00010 */  sw        $s0, 0x10($sp)
/* B17A0 8011B0A0 0000802D */  daddu     $s0, $zero, $zero
/* B17A4 8011B0A4 AFBF0018 */  sw        $ra, 0x18($sp)
.L8011B0A8:
/* B17A8 8011B0A8 0C046C70 */  jal       func_8011B1C0
/* B17AC 8011B0AC 0200202D */   daddu    $a0, $s0, $zero
/* B17B0 8011B0B0 50400006 */  beql      $v0, $zero, .L8011B0CC
/* B17B4 8011B0B4 26100001 */   addiu    $s0, $s0, 1
/* B17B8 8011B0B8 94420002 */  lhu       $v0, 2($v0)
/* B17BC 8011B0BC 54510003 */  bnel      $v0, $s1, .L8011B0CC
/* B17C0 8011B0C0 26100001 */   addiu    $s0, $s0, 1
/* B17C4 8011B0C4 08046C36 */  j         .L8011B0D8
/* B17C8 8011B0C8 0200102D */   daddu    $v0, $s0, $zero
.L8011B0CC:
/* B17CC 8011B0CC 2A020004 */  slti      $v0, $s0, 4
/* B17D0 8011B0D0 1440FFF5 */  bnez      $v0, .L8011B0A8
/* B17D4 8011B0D4 2402FFFF */   addiu    $v0, $zero, -1
.L8011B0D8:
/* B17D8 8011B0D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* B17DC 8011B0DC 8FB10014 */  lw        $s1, 0x14($sp)
/* B17E0 8011B0E0 8FB00010 */  lw        $s0, 0x10($sp)
/* B17E4 8011B0E4 03E00008 */  jr        $ra
/* B17E8 8011B0E8 27BD0020 */   addiu    $sp, $sp, 0x20
