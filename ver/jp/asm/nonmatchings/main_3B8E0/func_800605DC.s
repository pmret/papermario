.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800605DC
/* 3B9DC 800605DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B9E0 800605E0 3C04800E */  lui       $a0, %hi(D_800DC020)
/* 3B9E4 800605E4 2484C020 */  addiu     $a0, $a0, %lo(D_800DC020)
/* 3B9E8 800605E8 0000282D */  daddu     $a1, $zero, $zero
/* 3B9EC 800605EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B9F0 800605F0 0C0195FC */  jal       func_800657F0
/* 3B9F4 800605F4 24060001 */   addiu    $a2, $zero, 1
/* 3B9F8 800605F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B9FC 800605FC 03E00008 */  jr        $ra
/* 3BA00 80060600 27BD0018 */   addiu    $sp, $sp, 0x18
