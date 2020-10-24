.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A00_803280
/* 803280 80242A00 3C028026 */  lui       $v0, 0x8026
/* 803284 80242A04 8C422A68 */  lw        $v0, 0x2a68($v0)
/* 803288 80242A08 8C42000C */  lw        $v0, 0xc($v0)
/* 80328C 80242A0C AC40001C */  sw        $zero, 0x1c($v0)
/* 803290 80242A10 03E00008 */  jr        $ra
/* 803294 80242A14 24020002 */   addiu    $v0, $zero, 2
