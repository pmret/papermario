.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F68
/* 843B38 80240F68 3C028025 */  lui       $v0, 0x8025
/* 843B3C 80240F6C 8C42F5C8 */  lw        $v0, -0xa38($v0)
/* 843B40 80240F70 8C43000C */  lw        $v1, 0xc($v0)
/* 843B44 80240F74 24020001 */  addiu     $v0, $zero, 1
/* 843B48 80240F78 AC62001C */  sw        $v0, 0x1c($v1)
/* 843B4C 80240F7C 03E00008 */  jr        $ra
/* 843B50 80240F80 24020002 */   addiu    $v0, $zero, 2
