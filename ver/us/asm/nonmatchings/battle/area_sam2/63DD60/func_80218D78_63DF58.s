.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D78_63DF58
/* 63DF58 80218D78 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63DF5C 80218D7C 0000202D */  daddu     $a0, $zero, $zero
/* 63DF60 80218D80 AFBF0010 */  sw        $ra, 0x10($sp)
/* 63DF64 80218D84 0C01C49C */  jal       func_80071270
/* 63DF68 80218D88 24050010 */   addiu    $a1, $zero, 0x10
/* 63DF6C 80218D8C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63DF70 80218D90 24020002 */  addiu     $v0, $zero, 2
/* 63DF74 80218D94 03E00008 */  jr        $ra
/* 63DF78 80218D98 27BD0018 */   addiu    $sp, $sp, 0x18
