.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238000_714CF0
/* 714CF0 80238000 3C02800E */  lui       $v0, %hi(gBattleStatus+0x4)
/* 714CF4 80238004 8C42C074 */  lw        $v0, %lo(gBattleStatus+0x4)($v0)
/* 714CF8 80238008 30420040 */  andi      $v0, $v0, 0x40
/* 714CFC 8023800C 10400003 */  beqz      $v0, .L8023801C
/* 714D00 80238010 24020001 */   addiu    $v0, $zero, 1
/* 714D04 80238014 0808E008 */  j         .L80238020
/* 714D08 80238018 AC820084 */   sw       $v0, 0x84($a0)
.L8023801C:
/* 714D0C 8023801C AC800084 */  sw        $zero, 0x84($a0)
.L80238020:
/* 714D10 80238020 03E00008 */  jr        $ra
/* 714D14 80238024 24020002 */   addiu    $v0, $zero, 2
