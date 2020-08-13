.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_801230B8
/* 0B97B8 801230B8 3C028007 */  lui   $v0, 0x8007
/* 0B97BC 801230BC 8C42419C */  lw    $v0, 0x419c($v0)
/* 0B97C0 801230C0 80420070 */  lb    $v0, 0x70($v0)
/* 0B97C4 801230C4 14400005 */  bnez  $v0, .L801230DC
/* 0B97C8 801230C8 00000000 */   nop   
/* 0B97CC 801230CC 3C028015 */  lui   $v0, 0x8015
/* 0B97D0 801230D0 244243A0 */  addiu $v0, $v0, 0x43a0
/* 0B97D4 801230D4 08048C39 */  j     .L801230E4
/* 0B97D8 801230D8 00000000 */   nop   

.L801230DC:
/* 0B97DC 801230DC 3C028015 */  lui   $v0, 0x8015
/* 0B97E0 801230E0 244243E0 */  addiu $v0, $v0, 0x43e0
.L801230E4:
/* 0B97E4 801230E4 3C018015 */  lui   $at, 0x8015
/* 0B97E8 801230E8 AC224420 */  sw    $v0, 0x4420($at)
/* 0B97EC 801230EC 3C028015 */  lui   $v0, 0x8015
/* 0B97F0 801230F0 8C424420 */  lw    $v0, 0x4420($v0)
/* 0B97F4 801230F4 2403000F */  addiu $v1, $zero, 0xf
/* 0B97F8 801230F8 2442003C */  addiu $v0, $v0, 0x3c
.L801230FC:
/* 0B97FC 801230FC AC400000 */  sw    $zero, ($v0)
/* 0B9800 80123100 2463FFFF */  addiu $v1, $v1, -1
/* 0B9804 80123104 0461FFFD */  bgez  $v1, .L801230FC
/* 0B9808 80123108 2442FFFC */   addiu $v0, $v0, -4
/* 0B980C 8012310C 03E00008 */  jr    $ra
/* 0B9810 80123110 00000000 */   nop   

