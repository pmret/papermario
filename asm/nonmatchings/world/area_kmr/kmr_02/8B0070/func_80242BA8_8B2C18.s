.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242BA8_8B2C18
/* 8B2C18 80242BA8 3C038015 */  lui       $v1, 0x8015
/* 8B2C1C 80242BAC 8C6312F0 */  lw        $v1, 0x12f0($v1)
/* 8B2C20 80242BB0 24020001 */  addiu     $v0, $zero, 1
/* 8B2C24 80242BB4 A0620000 */  sb        $v0, ($v1)
/* 8B2C28 80242BB8 03E00008 */  jr        $ra
/* 8B2C2C 80242BBC 24020002 */   addiu    $v0, $zero, 2
