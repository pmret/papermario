.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055E74
/* 31274 80055E74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31278 80055E78 0080282D */  daddu     $a1, $a0, $zero
/* 3127C 80055E7C AFBF0010 */  sw        $ra, 0x10($sp)
/* 31280 80055E80 0C015264 */  jal       func_80054990
/* 31284 80055E84 24040010 */   addiu    $a0, $zero, 0x10
/* 31288 80055E88 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3128C 80055E8C 03E00008 */  jr        $ra
/* 31290 80055E90 27BD0018 */   addiu    $sp, $sp, 0x18
