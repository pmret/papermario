.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80261388
/* 18FC68 80261388 3C02800E */  lui       $v0, 0x800e
/* 18FC6C 8026138C 8C42C14C */  lw        $v0, -0x3eb4($v0)
/* 18FC70 80261390 10400003 */  beqz      $v0, .L802613A0
/* 18FC74 80261394 AC800084 */   sw       $zero, 0x84($a0)
/* 18FC78 80261398 24020001 */  addiu     $v0, $zero, 1
/* 18FC7C 8026139C AC820084 */  sw        $v0, 0x84($a0)
.L802613A0:
/* 18FC80 802613A0 03E00008 */  jr        $ra
/* 18FC84 802613A4 24020002 */   addiu    $v0, $zero, 2
