.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10E4_74D654
/* 74D654 802A10E4 AC800084 */  sw        $zero, 0x84($a0)
/* 74D658 802A10E8 3C02800E */  lui       $v0, %hi(gBattleStatus+0x97)
/* 74D65C 802A10EC 8042C107 */  lb        $v0, %lo(gBattleStatus+0x97)($v0)
/* 74D660 802A10F0 28420063 */  slti      $v0, $v0, 0x63
/* 74D664 802A10F4 14400002 */  bnez      $v0, .L802A1100
/* 74D668 802A10F8 24020001 */   addiu    $v0, $zero, 1
/* 74D66C 802A10FC AC820084 */  sw        $v0, 0x84($a0)
.L802A1100:
/* 74D670 802A1100 03E00008 */  jr        $ra
/* 74D674 802A1104 24020002 */   addiu    $v0, $zero, 2
