.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F30_9F6970
/* 9F6970 80241F30 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 9F6974 80241F34 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 9F6978 80241F38 9462000C */  lhu       $v0, 0xc($v1)
/* 9F697C 80241F3C 2442FF9C */  addiu     $v0, $v0, -0x64
/* 9F6980 80241F40 A462000C */  sh        $v0, 0xc($v1)
/* 9F6984 80241F44 03E00008 */  jr        $ra
/* 9F6988 80241F48 24020002 */   addiu    $v0, $zero, 2
/* 9F698C 80241F4C 00000000 */  nop
