.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A44_C6D364
/* C6D364 80240A44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C6D368 80240A48 0000202D */  daddu     $a0, $zero, $zero
/* C6D36C 80240A4C AFBF0010 */  sw        $ra, 0x10($sp)
/* C6D370 80240A50 0C015586 */  jal       func_80055618
/* C6D374 80240A54 24050001 */   addiu    $a1, $zero, 1
/* C6D378 80240A58 8FBF0010 */  lw        $ra, 0x10($sp)
/* C6D37C 80240A5C 24020002 */  addiu     $v0, $zero, 2
/* C6D380 80240A60 03E00008 */  jr        $ra
/* C6D384 80240A64 27BD0018 */   addiu    $sp, $sp, 0x18
/* C6D388 80240A68 00000000 */  nop
/* C6D38C 80240A6C 00000000 */  nop
