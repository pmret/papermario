.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006A610
/* 45A10 8006A610 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 45A14 8006A614 AFBF0010 */  sw        $ra, 0x10($sp)
/* 45A18 8006A618 0C01B1B8 */  jal       func_8006C6E0
/* 45A1C 8006A61C 00002021 */   addu     $a0, $zero, $zero
/* 45A20 8006A620 8FBF0010 */  lw        $ra, 0x10($sp)
/* 45A24 8006A624 03E00008 */  jr        $ra
/* 45A28 8006A628 27BD0018 */   addiu    $sp, $sp, 0x18
/* 45A2C 8006A62C 00000000 */  nop
