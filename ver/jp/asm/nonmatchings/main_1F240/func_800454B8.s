.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800454B8
/* 208B8 800454B8 24020001 */  addiu     $v0, $zero, 1
/* 208BC 800454BC 3C01800B */  lui       $at, %hi(D_800B0F02)
/* 208C0 800454C0 A0220F02 */  sb        $v0, %lo(D_800B0F02)($at)
/* 208C4 800454C4 03E00008 */  jr        $ra
/* 208C8 800454C8 24020002 */   addiu    $v0, $zero, 2
