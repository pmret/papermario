.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_model_list_index_from_tree_index
/* 0B1710 8011B010 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0B1714 8011B014 AFB10014 */  sw    $s1, 0x14($sp)
/* 0B1718 8011B018 0080882D */  daddu $s1, $a0, $zero
/* 0B171C 8011B01C 2A220100 */  slti  $v0, $s1, 0x100
/* 0B1720 8011B020 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0B1724 8011B024 10400009 */  beqz  $v0, .L8011B04C
/* 0B1728 8011B028 AFB00010 */   sw    $s0, 0x10($sp)
/* 0B172C 8011B02C 3C02800A */  lui   $v0, 0x800a
/* 0B1730 8011B030 8C42A5F4 */  lw    $v0, -0x5a0c($v0)
/* 0B1734 8011B034 00111880 */  sll   $v1, $s1, 2
/* 0B1738 8011B038 00621821 */  addu  $v1, $v1, $v0
/* 0B173C 8011B03C 90630000 */  lbu   $v1, ($v1)
/* 0B1740 8011B040 240200FF */  addiu $v0, $zero, 0xff
/* 0B1744 8011B044 1462000D */  bne   $v1, $v0, .L8011B07C
/* 0B1748 8011B048 0060102D */   daddu $v0, $v1, $zero
.L8011B04C:
/* 0B174C 8011B04C 0000802D */  daddu $s0, $zero, $zero
.L8011B050:
/* 0B1750 8011B050 0C046B4C */  jal   get_model_from_list_index
/* 0B1754 8011B054 0200202D */   daddu $a0, $s0, $zero
/* 0B1758 8011B058 50400005 */  beql  $v0, $zero, .L8011B070
/* 0B175C 8011B05C 26100001 */   addiu $s0, $s0, 1
/* 0B1760 8011B060 94420002 */  lhu   $v0, 2($v0)
/* 0B1764 8011B064 10510005 */  beq   $v0, $s1, .L8011B07C
/* 0B1768 8011B068 0200102D */   daddu $v0, $s0, $zero
/* 0B176C 8011B06C 26100001 */  addiu $s0, $s0, 1
.L8011B070:
/* 0B1770 8011B070 2A020100 */  slti  $v0, $s0, 0x100
/* 0B1774 8011B074 1440FFF6 */  bnez  $v0, .L8011B050
/* 0B1778 8011B078 0000102D */   daddu $v0, $zero, $zero
.L8011B07C:
/* 0B177C 8011B07C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0B1780 8011B080 8FB10014 */  lw    $s1, 0x14($sp)
/* 0B1784 8011B084 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B1788 8011B088 03E00008 */  jr    $ra
/* 0B178C 8011B08C 27BD0020 */   addiu $sp, $sp, 0x20

