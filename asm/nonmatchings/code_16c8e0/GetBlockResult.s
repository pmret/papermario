.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetBlockResult
/* 197E5C 8026957C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197E60 80269580 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197E64 80269584 8C82000C */  lw        $v0, 0xc($a0)
/* 197E68 80269588 3C06800E */  lui       $a2, 0x800e
/* 197E6C 8026958C 80C6C0F7 */  lb        $a2, -0x3f09($a2)
/* 197E70 80269590 0C0B2026 */  jal       set_variable
/* 197E74 80269594 8C450000 */   lw       $a1, ($v0)
/* 197E78 80269598 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197E7C 8026959C 24020002 */  addiu     $v0, $zero, 2
/* 197E80 802695A0 03E00008 */  jr        $ra
/* 197E84 802695A4 27BD0018 */   addiu    $sp, $sp, 0x18
