.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80257B28
/* 186408 80257B28 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18640C 80257B2C 0080282D */  daddu     $a1, $a0, $zero
/* 186410 80257B30 AFBF0010 */  sw        $ra, 0x10($sp)
/* 186414 80257B34 0C0957F8 */  jal       func_80255FE0
/* 186418 80257B38 0000202D */   daddu    $a0, $zero, $zero
/* 18641C 80257B3C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 186420 80257B40 03E00008 */  jr        $ra
/* 186424 80257B44 27BD0018 */   addiu    $sp, $sp, 0x18
