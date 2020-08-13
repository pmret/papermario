.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel init_item_entity_list
/* 0C77CC 801310CC 3C028007 */  lui   $v0, 0x8007
/* 0C77D0 801310D0 8C42419C */  lw    $v0, 0x419c($v0)
/* 0C77D4 801310D4 80420070 */  lb    $v0, 0x70($v0)
/* 0C77D8 801310D8 14400005 */  bnez  $v0, .L801310F0
/* 0C77DC 801310DC 00000000 */   nop   
/* 0C77E0 801310E0 3C028015 */  lui   $v0, 0x8015
/* 0C77E4 801310E4 24425DA0 */  addiu $v0, $v0, 0x5da0
/* 0C77E8 801310E8 0804C43E */  j     .L801310F8
/* 0C77EC 801310EC 00000000 */   nop   

.L801310F0:
/* 0C77F0 801310F0 3C028015 */  lui   $v0, 0x8015
/* 0C77F4 801310F4 244261A0 */  addiu $v0, $v0, 0x61a0
.L801310F8:
/* 0C77F8 801310F8 3C018015 */  lui   $at, 0x8015
/* 0C77FC 801310FC AC2265A0 */  sw    $v0, 0x65a0($at)
/* 0C7800 80131100 3C018015 */  lui   $at, 0x8015
/* 0C7804 80131104 A42065A4 */  sh    $zero, 0x65a4($at)
/* 0C7808 80131108 3C018015 */  lui   $at, 0x8015
/* 0C780C 8013110C A42065A8 */  sh    $zero, 0x65a8($at)
/* 0C7810 80131110 3C018015 */  lui   $at, 0x8015
/* 0C7814 80131114 AC2012F8 */  sw    $zero, 0x12f8($at)
/* 0C7818 80131118 3C018015 */  lui   $at, 0x8015
/* 0C781C 8013111C AC205D84 */  sw    $zero, 0x5d84($at)
/* 0C7820 80131120 03E00008 */  jr    $ra
/* 0C7824 80131124 00000000 */   nop   

