.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219D18_63EEF8
/* 63EEF8 80219D18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63EEFC 80219D1C 0000202D */  daddu     $a0, $zero, $zero
/* 63EF00 80219D20 AFBF0010 */  sw        $ra, 0x10($sp)
/* 63EF04 80219D24 0C01C49C */  jal       func_80071270
/* 63EF08 80219D28 24050010 */   addiu    $a1, $zero, 0x10
/* 63EF0C 80219D2C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63EF10 80219D30 24020002 */  addiu     $v0, $zero, 2
/* 63EF14 80219D34 03E00008 */  jr        $ra
/* 63EF18 80219D38 27BD0018 */   addiu    $sp, $sp, 0x18
