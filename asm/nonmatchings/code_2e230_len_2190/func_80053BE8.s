.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80053BE8
/* 02EFE8 80053BE8 30A20070 */  andi  $v0, $a1, 0x70
/* 02EFEC 80053BEC 00021082 */  srl   $v0, $v0, 2
/* 02EFF0 80053BF0 00822021 */  addu  $a0, $a0, $v0
/* 02EFF4 80053BF4 8C8212EC */  lw    $v0, 0x12ec($a0)
/* 02EFF8 80053BF8 00063080 */  sll   $a2, $a2, 2
/* 02EFFC 80053BFC 00C23021 */  addu  $a2, $a2, $v0
/* 02F000 80053C00 8CC60000 */  lw    $a2, ($a2)
/* 02F004 80053C04 8CC4002C */  lw    $a0, 0x2c($a2)
/* 02F008 80053C08 90820000 */  lbu   $v0, ($a0)
/* 02F00C 80053C0C 30A50003 */  andi  $a1, $a1, 3
/* 02F010 80053C10 00A2102B */  sltu  $v0, $a1, $v0
/* 02F014 80053C14 10400009 */  beqz  $v0, .L80053C3C
/* 02F018 80053C18 00000000 */   nop   
/* 02F01C 80053C1C 00051080 */  sll   $v0, $a1, 2
/* 02F020 80053C20 00821021 */  addu  $v0, $a0, $v0
/* 02F024 80053C24 94430004 */  lhu   $v1, 4($v0)
/* 02F028 80053C28 00641821 */  addu  $v1, $v1, $a0
/* 02F02C 80053C2C ACE30000 */  sw    $v1, ($a3)
/* 02F030 80053C30 94420006 */  lhu   $v0, 6($v0)
/* 02F034 80053C34 08014F13 */  j     .L80053C4C
/* 02F038 80053C38 00441021 */   addu  $v0, $v0, $a0

.L80053C3C:
/* 02F03C 80053C3C 3C028008 */  lui   $v0, 0x8008
/* 02F040 80053C40 2442854C */  addiu $v0, $v0, -0x7ab4
/* 02F044 80053C44 ACE20000 */  sw    $v0, ($a3)
/* 02F048 80053C48 24420004 */  addiu $v0, $v0, 4
.L80053C4C:
/* 02F04C 80053C4C ACE20004 */  sw    $v0, 4($a3)
/* 02F050 80053C50 03E00008 */  jr    $ra
/* 02F054 80053C54 00C0102D */   daddu $v0, $a2, $zero

