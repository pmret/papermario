.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181F8_4CF3A8
/* 4CF3A8 802181F8 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 4CF3AC 802181FC 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 4CF3B0 80218200 94620290 */  lhu       $v0, 0x290($v1)
/* 4CF3B4 80218204 24420020 */  addiu     $v0, $v0, 0x20
/* 4CF3B8 80218208 A4620290 */  sh        $v0, 0x290($v1)
/* 4CF3BC 8021820C 03E00008 */  jr        $ra
/* 4CF3C0 80218210 24020002 */   addiu    $v0, $zero, 2
/* 4CF3C4 80218214 00000000 */  nop       
/* 4CF3C8 80218218 00000000 */  nop       
/* 4CF3CC 8021821C 00000000 */  nop       
