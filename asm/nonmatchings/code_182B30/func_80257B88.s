.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80257B88
/* 186468 80257B88 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18646C 80257B8C 3C05800E */  lui       $a1, 0x800e
/* 186470 80257B90 8CA5C14C */  lw        $a1, -0x3eb4($a1)
/* 186474 80257B94 AFBF0010 */  sw        $ra, 0x10($sp)
/* 186478 80257B98 0C095C7C */  jal       func_802571F0
/* 18647C 80257B9C 24040001 */   addiu    $a0, $zero, 1
/* 186480 80257BA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 186484 80257BA4 03E00008 */  jr        $ra
/* 186488 80257BA8 27BD0018 */   addiu    $sp, $sp, 0x18
