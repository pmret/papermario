.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12FC_723A7C
/* 723A7C 802A12FC 3C048011 */  lui       $a0, %hi(gPlayerData)
/* 723A80 802A1300 2484F290 */  addiu     $a0, $a0, %lo(gPlayerData)
/* 723A84 802A1304 90820002 */  lbu       $v0, 2($a0)
/* 723A88 802A1308 80830003 */  lb        $v1, 3($a0)
/* 723A8C 802A130C 2442000A */  addiu     $v0, $v0, 0xa
/* 723A90 802A1310 A0820002 */  sb        $v0, 2($a0)
/* 723A94 802A1314 00021600 */  sll       $v0, $v0, 0x18
/* 723A98 802A1318 00021603 */  sra       $v0, $v0, 0x18
/* 723A9C 802A131C 0062182A */  slt       $v1, $v1, $v0
/* 723AA0 802A1320 90820003 */  lbu       $v0, 3($a0)
/* 723AA4 802A1324 54600001 */  bnel      $v1, $zero, .L802A132C
/* 723AA8 802A1328 A0820002 */   sb       $v0, 2($a0)
.L802A132C:
/* 723AAC 802A132C 03E00008 */  jr        $ra
nop
