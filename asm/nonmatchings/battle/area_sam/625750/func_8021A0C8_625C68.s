.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A0C8_625C68
/* 625C68 8021A0C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 625C6C 8021A0CC 0000202D */  daddu     $a0, $zero, $zero
/* 625C70 8021A0D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 625C74 8021A0D4 0C01C49C */  jal       func_80071270
/* 625C78 8021A0D8 24050010 */   addiu    $a1, $zero, 0x10
/* 625C7C 8021A0DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 625C80 8021A0E0 24020002 */  addiu     $v0, $zero, 2
/* 625C84 8021A0E4 03E00008 */  jr        $ra
/* 625C88 8021A0E8 27BD0018 */   addiu    $sp, $sp, 0x18
