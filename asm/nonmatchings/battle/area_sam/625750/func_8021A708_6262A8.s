.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A708_6262A8
/* 6262A8 8021A708 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6262AC 8021A70C 0000202D */  daddu     $a0, $zero, $zero
/* 6262B0 8021A710 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6262B4 8021A714 0C01C49C */  jal       func_80071270
/* 6262B8 8021A718 24050010 */   addiu    $a1, $zero, 0x10
/* 6262BC 8021A71C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6262C0 8021A720 24020002 */  addiu     $v0, $zero, 2
/* 6262C4 8021A724 03E00008 */  jr        $ra
/* 6262C8 8021A728 27BD0018 */   addiu    $sp, $sp, 0x18
