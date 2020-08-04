.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel open_status_menu_long
/* 082C10 800E9760 3C038011 */  lui   $v1, 0x8011
/* 082C14 800E9764 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082C18 800E9768 8062003A */  lb    $v0, 0x3a($v1)
/* 082C1C 800E976C 10400005 */  beqz  $v0, .L800E9784
/* 082C20 800E9770 240200D2 */   addiu $v0, $zero, 0xd2
/* 082C24 800E9774 A4620038 */  sh    $v0, 0x38($v1)
/* 082C28 800E9778 24020001 */  addiu $v0, $zero, 1
/* 082C2C 800E977C A060003A */  sb    $zero, 0x3a($v1)
/* 082C30 800E9780 A062003B */  sb    $v0, 0x3b($v1)
.L800E9784:
/* 082C34 800E9784 03E00008 */  jr    $ra
/* 082C38 800E9788 00000000 */   nop   

