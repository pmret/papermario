.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80257B48
/* 186428 80257B48 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18642C 80257B4C 0080282D */  daddu     $a1, $a0, $zero
/* 186430 80257B50 AFBF0010 */  sw        $ra, 0x10($sp)
/* 186434 80257B54 0C0957F8 */  jal       func_80255FE0
/* 186438 80257B58 24040001 */   addiu    $a0, $zero, 1
/* 18643C 80257B5C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 186440 80257B60 03E00008 */  jr        $ra
/* 186444 80257B64 27BD0018 */   addiu    $sp, $sp, 0x18
