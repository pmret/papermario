.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055E30
/* 31230 80055E30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31234 80055E34 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31238 80055E38 0C015A83 */  jal       func_80056A0C
/* 3123C 80055E3C 0000202D */   daddu    $a0, $zero, $zero
/* 31240 80055E40 0C015296 */  jal       func_80054A58
/* 31244 80055E44 24040001 */   addiu    $a0, $zero, 1
/* 31248 80055E48 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3124C 80055E4C 03E00008 */  jr        $ra
/* 31250 80055E50 27BD0018 */   addiu    $sp, $sp, 0x18
