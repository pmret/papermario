.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12FC_72453C
/* 72453C 802A12FC 3C048011 */  lui       $a0, %hi(gPlayerData)
/* 724540 802A1300 2484F290 */  addiu     $a0, $a0, %lo(gPlayerData)
/* 724544 802A1304 90820002 */  lbu       $v0, 2($a0)
/* 724548 802A1308 80830003 */  lb        $v1, 3($a0)
/* 72454C 802A130C 24420014 */  addiu     $v0, $v0, 0x14
/* 724550 802A1310 A0820002 */  sb        $v0, 2($a0)
/* 724554 802A1314 00021600 */  sll       $v0, $v0, 0x18
/* 724558 802A1318 00021603 */  sra       $v0, $v0, 0x18
/* 72455C 802A131C 0062182A */  slt       $v1, $v1, $v0
/* 724560 802A1320 90820003 */  lbu       $v0, 3($a0)
/* 724564 802A1324 54600001 */  bnel      $v1, $zero, .L802A132C
/* 724568 802A1328 A0820002 */   sb       $v0, 2($a0)
.L802A132C:
/* 72456C 802A132C 03E00008 */  jr        $ra
