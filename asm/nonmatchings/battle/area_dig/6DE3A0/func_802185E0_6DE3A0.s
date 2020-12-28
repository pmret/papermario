.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802185E0_6DE3A0
/* 6DE3A0 802185E0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 6DE3A4 802185E4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 6DE3A8 802185E8 AC800084 */  sw        $zero, 0x84($a0)
/* 6DE3AC 802185EC 904200AA */  lbu       $v0, 0xaa($v0)
/* 6DE3B0 802185F0 30420001 */  andi      $v0, $v0, 1
/* 6DE3B4 802185F4 10400002 */  beqz      $v0, .L80218600
/* 6DE3B8 802185F8 24020001 */   addiu    $v0, $zero, 1
/* 6DE3BC 802185FC AC820084 */  sw        $v0, 0x84($a0)
.L80218600:
/* 6DE3C0 80218600 03E00008 */  jr        $ra
/* 6DE3C4 80218604 24020002 */   addiu    $v0, $zero, 2
