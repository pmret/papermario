.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetActionSuccess
/* 197BA0 802692C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197BA4 802692C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197BA8 802692C8 8C82000C */  lw        $v0, 0xc($a0)
/* 197BAC 802692CC 0C0B1EAF */  jal       get_variable
/* 197BB0 802692D0 8C450000 */   lw       $a1, ($v0)
/* 197BB4 802692D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197BB8 802692D8 3C01800E */  lui       $at, 0x800e
/* 197BBC 802692DC A022C0F1 */  sb        $v0, -0x3f0f($at)
/* 197BC0 802692E0 24020002 */  addiu     $v0, $zero, 2
/* 197BC4 802692E4 03E00008 */  jr        $ra
/* 197BC8 802692E8 27BD0018 */   addiu    $sp, $sp, 0x18
