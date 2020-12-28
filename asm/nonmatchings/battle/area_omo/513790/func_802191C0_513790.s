.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802191C0_513790
/* 513790 802191C0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 513794 802191C4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 513798 802191C8 AC800084 */  sw        $zero, 0x84($a0)
/* 51379C 802191CC 904200AA */  lbu       $v0, 0xaa($v0)
/* 5137A0 802191D0 30420001 */  andi      $v0, $v0, 1
/* 5137A4 802191D4 10400002 */  beqz      $v0, .L802191E0
/* 5137A8 802191D8 24020001 */   addiu    $v0, $zero, 1
/* 5137AC 802191DC AC820084 */  sw        $v0, 0x84($a0)
.L802191E0:
/* 5137B0 802191E0 03E00008 */  jr        $ra
/* 5137B4 802191E4 24020002 */   addiu    $v0, $zero, 2
