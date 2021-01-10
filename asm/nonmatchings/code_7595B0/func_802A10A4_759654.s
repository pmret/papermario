.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10A4_759654
/* 759654 802A10A4 AC800084 */  sw        $zero, 0x84($a0)
/* 759658 802A10A8 3C02800E */  lui       $v0, %hi(gBattleStatus+0x96)
/* 75965C 802A10AC 8042C106 */  lb        $v0, %lo(gBattleStatus+0x96)($v0)
/* 759660 802A10B0 28420063 */  slti      $v0, $v0, 0x63
/* 759664 802A10B4 14400002 */  bnez      $v0, .L802A10C0
/* 759668 802A10B8 24020001 */   addiu    $v0, $zero, 1
/* 75966C 802A10BC AC820084 */  sw        $v0, 0x84($a0)
.L802A10C0:
/* 759670 802A10C0 03E00008 */  jr        $ra
/* 759674 802A10C4 24020002 */   addiu    $v0, $zero, 2
