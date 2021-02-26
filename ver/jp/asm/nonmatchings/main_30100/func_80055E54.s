.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055E54
/* 31254 80055E54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31258 80055E58 0080282D */  daddu     $a1, $a0, $zero
/* 3125C 80055E5C AFBF0010 */  sw        $ra, 0x10($sp)
/* 31260 80055E60 0C015264 */  jal       func_80054990
/* 31264 80055E64 24040001 */   addiu    $a0, $zero, 1
/* 31268 80055E68 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3126C 80055E6C 03E00008 */  jr        $ra
/* 31270 80055E70 27BD0018 */   addiu    $sp, $sp, 0x18
