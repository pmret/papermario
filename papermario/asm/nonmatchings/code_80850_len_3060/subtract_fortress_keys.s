.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel subtract_fortress_keys
/* 083868 800EA3B8 3C038011 */  lui   $v1, 0x8011
/* 08386C 800EA3BC 2463F290 */  addiu $v1, $v1, -0xd70
/* 083870 800EA3C0 9062000E */  lbu   $v0, 0xe($v1)
/* 083874 800EA3C4 00441023 */  subu  $v0, $v0, $a0
/* 083878 800EA3C8 A062000E */  sb    $v0, 0xe($v1)
/* 08387C 800EA3CC 00021600 */  sll   $v0, $v0, 0x18
/* 083880 800EA3D0 04410002 */  bgez  $v0, .L800EA3DC
/* 083884 800EA3D4 0060202D */   daddu $a0, $v1, $zero
/* 083888 800EA3D8 A060000E */  sb    $zero, 0xe($v1)
.L800EA3DC:
/* 08388C 800EA3DC 03E00008 */  jr    $ra
/* 083890 800EA3E0 8082000E */   lb    $v0, 0xe($a0)

