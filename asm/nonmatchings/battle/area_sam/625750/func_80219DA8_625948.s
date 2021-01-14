.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219DA8_625948
/* 625948 80219DA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 62594C 80219DAC 0000202D */  daddu     $a0, $zero, $zero
/* 625950 80219DB0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 625954 80219DB4 0C01C49C */  jal       func_80071270
/* 625958 80219DB8 24050010 */   addiu    $a1, $zero, 0x10
/* 62595C 80219DBC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 625960 80219DC0 24020002 */  addiu     $v0, $zero, 2
/* 625964 80219DC4 03E00008 */  jr        $ra
/* 625968 80219DC8 27BD0018 */   addiu    $sp, $sp, 0x18
