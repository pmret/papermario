.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A3E8_625F88
/* 625F88 8021A3E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 625F8C 8021A3EC 0000202D */  daddu     $a0, $zero, $zero
/* 625F90 8021A3F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 625F94 8021A3F4 0C01C49C */  jal       func_80071270
/* 625F98 8021A3F8 24050010 */   addiu    $a1, $zero, 0x10
/* 625F9C 8021A3FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 625FA0 8021A400 24020002 */  addiu     $v0, $zero, 2
/* 625FA4 8021A404 03E00008 */  jr        $ra
/* 625FA8 8021A408 27BD0018 */   addiu    $sp, $sp, 0x18
