.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802186A0_557A80
/* 557A80 802186A0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 557A84 802186A4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 557A88 802186A8 AC800084 */  sw        $zero, 0x84($a0)
/* 557A8C 802186AC 904200AA */  lbu       $v0, 0xaa($v0)
/* 557A90 802186B0 30420001 */  andi      $v0, $v0, 1
/* 557A94 802186B4 10400002 */  beqz      $v0, .L802186C0
/* 557A98 802186B8 24020001 */   addiu    $v0, $zero, 1
/* 557A9C 802186BC AC820084 */  sw        $v0, 0x84($a0)
.L802186C0:
/* 557AA0 802186C0 03E00008 */  jr        $ra
/* 557AA4 802186C4 24020002 */   addiu    $v0, $zero, 2
