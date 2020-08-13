.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AssignAreaFlag
/* 0A86F8 80111FF8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A86FC 80111FFC 24020001 */  addiu $v0, $zero, 1
/* 0A8700 80112000 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0A8704 80112004 AFB10014 */  sw    $s1, 0x14($sp)
/* 0A8708 80112008 AFB00010 */  sw    $s0, 0x10($sp)
/* 0A870C 8011200C 14A20012 */  bne   $a1, $v0, .L80112058
/* 0A8710 80112010 8C83000C */   lw    $v1, 0xc($a0)
/* 0A8714 80112014 0C0B1EAF */  jal   get_variable
/* 0A8718 80112018 8C650000 */   lw    $a1, ($v1)
/* 0A871C 8011201C 3C048015 */  lui   $a0, 0x8015
/* 0A8720 80112020 8C8412EC */  lw    $a0, 0x12ec($a0)
/* 0A8724 80112024 0C04417A */  jal   get_entity_by_index
/* 0A8728 80112028 0040802D */   daddu $s0, $v0, $zero
/* 0A872C 8011202C 0040882D */  daddu $s1, $v0, $zero
/* 0A8730 80112030 8E220040 */  lw    $v0, 0x40($s1)
/* 0A8734 80112034 0200202D */  daddu $a0, $s0, $zero
/* 0A8738 80112038 0C05157C */  jal   get_area_flag
/* 0A873C 8011203C A4440020 */   sh    $a0, 0x20($v0)
/* 0A8740 80112040 10400004 */  beqz  $v0, .L80112054
/* 0A8744 80112044 3C032000 */   lui   $v1, 0x2000
/* 0A8748 80112048 8E220000 */  lw    $v0, ($s1)
/* 0A874C 8011204C 00431025 */  or    $v0, $v0, $v1
/* 0A8750 80112050 AE220000 */  sw    $v0, ($s1)
.L80112054:
/* 0A8754 80112054 24020002 */  addiu $v0, $zero, 2
.L80112058:
/* 0A8758 80112058 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0A875C 8011205C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0A8760 80112060 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A8764 80112064 03E00008 */  jr    $ra
/* 0A8768 80112068 27BD0020 */   addiu $sp, $sp, 0x20

