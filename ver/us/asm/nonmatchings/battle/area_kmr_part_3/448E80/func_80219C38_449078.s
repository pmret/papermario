.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219C38_449078
/* 449078 80219C38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 44907C 80219C3C 0000202D */  daddu     $a0, $zero, $zero
/* 449080 80219C40 AFBF0010 */  sw        $ra, 0x10($sp)
/* 449084 80219C44 0C01C49C */  jal       func_80071270
/* 449088 80219C48 24050010 */   addiu    $a1, $zero, 0x10
/* 44908C 80219C4C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 449090 80219C50 24020002 */  addiu     $v0, $zero, 2
/* 449094 80219C54 03E00008 */  jr        $ra
/* 449098 80219C58 27BD0018 */   addiu    $sp, $sp, 0x18
