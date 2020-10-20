.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F84
/* 843B54 80240F84 3C028025 */  lui       $v0, 0x8025
/* 843B58 80240F88 8C42F5C8 */  lw        $v0, -0xa38($v0)
/* 843B5C 80240F8C 8C43000C */  lw        $v1, 0xc($v0)
/* 843B60 80240F90 24020002 */  addiu     $v0, $zero, 2
/* 843B64 80240F94 03E00008 */  jr        $ra
/* 843B68 80240F98 AC62001C */   sw       $v0, 0x1c($v1)
