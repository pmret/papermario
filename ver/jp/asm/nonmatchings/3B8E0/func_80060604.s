.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060604
/* 3BA04 80060604 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BA08 80060608 3C04800E */  lui       $a0, %hi(D_800DC020)
/* 3BA0C 8006060C 2484C020 */  addiu     $a0, $a0, %lo(D_800DC020)
/* 3BA10 80060610 0000282D */  daddu     $a1, $zero, $zero
/* 3BA14 80060614 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BA18 80060618 0C0195B0 */  jal       func_800656C0
/* 3BA1C 8006061C 24060001 */   addiu    $a2, $zero, 1
/* 3BA20 80060620 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BA24 80060624 03E00008 */  jr        $ra
/* 3BA28 80060628 27BD0018 */   addiu    $sp, $sp, 0x18
