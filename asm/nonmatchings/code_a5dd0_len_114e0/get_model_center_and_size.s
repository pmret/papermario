.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_model_center_and_size
/* 0B17EC 8011B0EC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0B17F0 8011B0F0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0B17F4 8011B0F4 8FB30040 */  lw    $s3, 0x40($sp)
/* 0B17F8 8011B0F8 AFB40020 */  sw    $s4, 0x20($sp)
/* 0B17FC 8011B0FC 8FB40044 */  lw    $s4, 0x44($sp)
/* 0B1800 8011B100 AFB00010 */  sw    $s0, 0x10($sp)
/* 0B1804 8011B104 00A0802D */  daddu $s0, $a1, $zero
/* 0B1808 8011B108 AFB10014 */  sw    $s1, 0x14($sp)
/* 0B180C 8011B10C 00C0882D */  daddu $s1, $a2, $zero
/* 0B1810 8011B110 AFB20018 */  sw    $s2, 0x18($sp)
/* 0B1814 8011B114 00E0902D */  daddu $s2, $a3, $zero
/* 0B1818 8011B118 AFB50024 */  sw    $s5, 0x24($sp)
/* 0B181C 8011B11C 8FB50048 */  lw    $s5, 0x48($sp)
/* 0B1820 8011B120 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0B1824 8011B124 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0B1828 8011B128 3084FFFF */   andi  $a0, $a0, 0xffff
/* 0B182C 8011B12C 0C046B4C */  jal   get_model_from_list_index
/* 0B1830 8011B130 0040202D */   daddu $a0, $v0, $zero
/* 0B1834 8011B134 C4400098 */  lwc1  $f0, 0x98($v0)
/* 0B1838 8011B138 8C440008 */  lw    $a0, 8($v0)
/* 0B183C 8011B13C E6000000 */  swc1  $f0, ($s0)
/* 0B1840 8011B140 C440009C */  lwc1  $f0, 0x9c($v0)
/* 0B1844 8011B144 E6200000 */  swc1  $f0, ($s1)
/* 0B1848 8011B148 C44000A0 */  lwc1  $f0, 0xa0($v0)
/* 0B184C 8011B14C 24050061 */  addiu $a1, $zero, 0x61
/* 0B1850 8011B150 0C0456C3 */  jal   get_model_property
/* 0B1854 8011B154 E6400000 */   swc1  $f0, ($s2)
/* 0B1858 8011B158 1040000B */  beqz  $v0, .L8011B188
/* 0B185C 8011B15C 00000000 */   nop   
/* 0B1860 8011B160 C4400004 */  lwc1  $f0, 4($v0)
/* 0B1864 8011B164 46800020 */  cvt.s.w $f0, $f0
/* 0B1868 8011B168 E6600000 */  swc1  $f0, ($s3)
/* 0B186C 8011B16C C4400010 */  lwc1  $f0, 0x10($v0)
/* 0B1870 8011B170 46800020 */  cvt.s.w $f0, $f0
/* 0B1874 8011B174 E6800000 */  swc1  $f0, ($s4)
/* 0B1878 8011B178 C440001C */  lwc1  $f0, 0x1c($v0)
/* 0B187C 8011B17C 46800020 */  cvt.s.w $f0, $f0
/* 0B1880 8011B180 08046C67 */  j     .L8011B19C
/* 0B1884 8011B184 E6A00000 */   swc1  $f0, ($s5)

.L8011B188:
/* 0B1888 8011B188 44800000 */  mtc1  $zero, $f0
/* 0B188C 8011B18C 00000000 */  nop   
/* 0B1890 8011B190 E6A00000 */  swc1  $f0, ($s5)
/* 0B1894 8011B194 E6800000 */  swc1  $f0, ($s4)
/* 0B1898 8011B198 E6600000 */  swc1  $f0, ($s3)
.L8011B19C:
/* 0B189C 8011B19C 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0B18A0 8011B1A0 8FB50024 */  lw    $s5, 0x24($sp)
/* 0B18A4 8011B1A4 8FB40020 */  lw    $s4, 0x20($sp)
/* 0B18A8 8011B1A8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0B18AC 8011B1AC 8FB20018 */  lw    $s2, 0x18($sp)
/* 0B18B0 8011B1B0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0B18B4 8011B1B4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B18B8 8011B1B8 03E00008 */  jr    $ra
/* 0B18BC 8011B1BC 27BD0030 */   addiu $sp, $sp, 0x30

