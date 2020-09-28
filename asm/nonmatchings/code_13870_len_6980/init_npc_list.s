.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel init_npc_list
/* 1392C 8003852C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 13930 80038530 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 13934 80038534 80420070 */  lb        $v0, 0x70($v0)
/* 13938 80038538 14400005 */  bnez      $v0, .L80038550
/* 1393C 8003853C 00000000 */   nop      
/* 13940 80038540 3C02800A */  lui       $v0, %hi(gWorldNpcList)
/* 13944 80038544 24420990 */  addiu     $v0, $v0, %lo(gWorldNpcList)
/* 13948 80038548 0800E156 */  j         .L80038558
/* 1394C 8003854C 00000000 */   nop      
.L80038550:
/* 13950 80038550 3C02800A */  lui       $v0, %hi(gBattleNpcList)
/* 13954 80038554 24420A90 */  addiu     $v0, $v0, %lo(gBattleNpcList)
.L80038558:
/* 13958 80038558 3C01800A */  lui       $at, %hi(gCurrentNpcListPtr)
/* 1395C 8003855C AC220B90 */  sw        $v0, %lo(gCurrentNpcListPtr)($at)
/* 13960 80038560 24020001 */  addiu     $v0, $zero, 1
/* 13964 80038564 3C01800A */  lui       $at, 0x800a
/* 13968 80038568 A420A604 */  sh        $zero, -0x59fc($at)
/* 1396C 8003856C 3C01800A */  lui       $at, 0x800a
/* 13970 80038570 A0220B94 */  sb        $v0, 0xb94($at)
/* 13974 80038574 03E00008 */  jr        $ra
/* 13978 80038578 00000000 */   nop      
