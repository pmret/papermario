.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10E4_761A04
/* 761A04 802A10E4 AC800084 */  sw        $zero, 0x84($a0)
/* 761A08 802A10E8 3C02800E */  lui       $v0, %hi(gBattleStatus+0x97)
/* 761A0C 802A10EC 8042C107 */  lb        $v0, %lo(gBattleStatus+0x97)($v0)
/* 761A10 802A10F0 28420063 */  slti      $v0, $v0, 0x63
/* 761A14 802A10F4 14400002 */  bnez      $v0, .L802A1100
/* 761A18 802A10F8 24020001 */   addiu    $v0, $zero, 1
/* 761A1C 802A10FC AC820084 */  sw        $v0, 0x84($a0)
.L802A1100:
/* 761A20 802A1100 03E00008 */  jr        $ra
/* 761A24 802A1104 24020002 */   addiu    $v0, $zero, 2
