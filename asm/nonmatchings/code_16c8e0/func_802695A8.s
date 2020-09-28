.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802695A8
/* 197E88 802695A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197E8C 802695AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 197E90 802695B0 8C82000C */  lw        $v0, 0xc($a0)
/* 197E94 802695B4 3C06800E */  lui       $a2, 0x800e
/* 197E98 802695B8 80C6C0F4 */  lb        $a2, -0x3f0c($a2)
/* 197E9C 802695BC 0C0B2026 */  jal       set_variable
/* 197EA0 802695C0 8C450000 */   lw       $a1, ($v0)
/* 197EA4 802695C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197EA8 802695C8 24020002 */  addiu     $v0, $zero, 2
/* 197EAC 802695CC 03E00008 */  jr        $ra
/* 197EB0 802695D0 27BD0018 */   addiu    $sp, $sp, 0x18
