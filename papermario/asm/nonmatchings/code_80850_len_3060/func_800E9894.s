.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_enable_ignore_changes
/* 082D44 800E9894 24020001 */  addiu $v0, $zero, 1
/* 082D48 800E9898 3C018011 */  lui   $at, 0x8011
/* 082D4C 800E989C A022EF9C */  sb    $v0, -0x1064($at)
/* 082D50 800E98A0 03E00008 */  jr    $ra
/* 082D54 800E98A4 00000000 */   nop   

/* 082D58 800E98A8 3C028011 */  lui   $v0, 0x8011
/* 082D5C 800E98AC 2442EF58 */  addiu $v0, $v0, -0x10a8
/* 082D60 800E98B0 24030001 */  addiu $v1, $zero, 1
/* 082D64 800E98B4 A0430044 */  sb    $v1, 0x44($v0)
/* 082D68 800E98B8 24030012 */  addiu $v1, $zero, 0x12
/* 082D6C 800E98BC 03E00008 */  jr    $ra
/* 082D70 800E98C0 A4430036 */   sh    $v1, 0x36($v0)

