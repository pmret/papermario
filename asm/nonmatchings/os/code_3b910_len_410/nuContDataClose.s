.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContDataClose
/* 3BA0C 8006060C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BA10 80060610 3C04800E */  lui       $a0, %hi(D_800DC040)
/* 3BA14 80060614 2484C040 */  addiu     $a0, $a0, %lo(D_800DC040)
/* 3BA18 80060618 0000282D */  daddu     $a1, $zero, $zero
/* 3BA1C 8006061C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BA20 80060620 0C019608 */  jal       osSendMesg
/* 3BA24 80060624 24060001 */   addiu    $a2, $zero, 1
/* 3BA28 80060628 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BA2C 8006062C 03E00008 */  jr        $ra
/* 3BA30 80060630 27BD0018 */   addiu    $sp, $sp, 0x18
