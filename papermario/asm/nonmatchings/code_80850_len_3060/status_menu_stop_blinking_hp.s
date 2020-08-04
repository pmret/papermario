.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel status_menu_stop_blinking_hp
/* 082E14 800E9964 3C038011 */  lui   $v1, 0x8011
/* 082E18 800E9968 2463EF58 */  addiu $v1, $v1, -0x10a8
/* 082E1C 800E996C 8062004A */  lb    $v0, 0x4a($v1)
/* 082E20 800E9970 10400004 */  beqz  $v0, .L800E9984
/* 082E24 800E9974 00000000 */   nop   
/* 082E28 800E9978 A060004A */  sb    $zero, 0x4a($v1)
/* 082E2C 800E997C A060004B */  sb    $zero, 0x4b($v1)
/* 082E30 800E9980 A060004C */  sb    $zero, 0x4c($v1)
.L800E9984:
/* 082E34 800E9984 03E00008 */  jr    $ra
/* 082E38 800E9988 00000000 */   nop   

