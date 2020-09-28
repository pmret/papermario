.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80257B68
/* 186448 80257B68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18644C 80257B6C 0080282D */  daddu     $a1, $a0, $zero
/* 186450 80257B70 AFBF0010 */  sw        $ra, 0x10($sp)
/* 186454 80257B74 0C095C7C */  jal       func_802571F0
/* 186458 80257B78 0000202D */   daddu    $a0, $zero, $zero
/* 18645C 80257B7C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 186460 80257B80 03E00008 */  jr        $ra
/* 186464 80257B84 27BD0018 */   addiu    $sp, $sp, 0x18
