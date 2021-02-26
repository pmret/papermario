.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055E0C
/* 3120C 80055E0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31210 80055E10 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31214 80055E14 0C015A83 */  jal       func_80056A0C
/* 31218 80055E18 24040001 */   addiu    $a0, $zero, 1
/* 3121C 80055E1C 0C015296 */  jal       func_80054A58
/* 31220 80055E20 0000202D */   daddu    $a0, $zero, $zero
/* 31224 80055E24 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31228 80055E28 03E00008 */  jr        $ra
/* 3122C 80055E2C 27BD0018 */   addiu    $sp, $sp, 0x18
