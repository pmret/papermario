.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021AA28_6265C8
/* 6265C8 8021AA28 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6265CC 8021AA2C 0000202D */  daddu     $a0, $zero, $zero
/* 6265D0 8021AA30 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6265D4 8021AA34 0C01C49C */  jal       func_80071270
/* 6265D8 8021AA38 24050010 */   addiu    $a1, $zero, 0x10
/* 6265DC 8021AA3C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6265E0 8021AA40 24020002 */  addiu     $v0, $zero, 2
/* 6265E4 8021AA44 03E00008 */  jr        $ra
/* 6265E8 8021AA48 27BD0018 */   addiu    $sp, $sp, 0x18
