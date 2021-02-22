.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238C88_700A08
/* 700A08 80238C88 3C02800E */  lui       $v0, %hi(gBattleStatus+0xDC)
/* 700A0C 80238C8C 8C42C14C */  lw        $v0, %lo(gBattleStatus+0xDC)($v0)
/* 700A10 80238C90 8C420008 */  lw        $v0, 8($v0)
/* 700A14 80238C94 90430006 */  lbu       $v1, 6($v0)
/* 700A18 80238C98 24020001 */  addiu     $v0, $zero, 1
/* 700A1C 80238C9C 1062000C */  beq       $v1, $v0, .L80238CD0
/* 700A20 80238CA0 0000282D */   daddu    $a1, $zero, $zero
/* 700A24 80238CA4 28620002 */  slti      $v0, $v1, 2
/* 700A28 80238CA8 10400005 */  beqz      $v0, .L80238CC0
/* 700A2C 80238CAC 24020002 */   addiu    $v0, $zero, 2
/* 700A30 80238CB0 50600008 */  beql      $v1, $zero, .L80238CD4
/* 700A34 80238CB4 24050005 */   addiu    $a1, $zero, 5
/* 700A38 80238CB8 03E00008 */  jr        $ra
/* 700A3C 80238CBC AC8500C0 */   sw       $a1, 0xc0($a0)
.L80238CC0:
/* 700A40 80238CC0 50620004 */  beql      $v1, $v0, .L80238CD4
/* 700A44 80238CC4 24050007 */   addiu    $a1, $zero, 7
/* 700A48 80238CC8 03E00008 */  jr        $ra
/* 700A4C 80238CCC AC8500C0 */   sw       $a1, 0xc0($a0)
.L80238CD0:
/* 700A50 80238CD0 24050006 */  addiu     $a1, $zero, 6
.L80238CD4:
/* 700A54 80238CD4 AC8500C0 */  sw        $a1, 0xc0($a0)
/* 700A58 80238CD8 03E00008 */  jr        $ra
/* 700A5C 80238CDC 24020002 */   addiu    $v0, $zero, 2
