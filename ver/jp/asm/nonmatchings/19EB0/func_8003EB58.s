.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003EB58
/* 19F58 8003EB58 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19F5C 8003EB5C 10A00004 */  beqz      $a1, .L8003EB70
/* 19F60 8003EB60 AFBF0010 */   sw       $ra, 0x10($sp)
/* 19F64 8003EB64 0000202D */  daddu     $a0, $zero, $zero
/* 19F68 8003EB68 0C011670 */  jal       func_800459C0
/* 19F6C 8003EB6C 2405003C */   addiu    $a1, $zero, 0x3c
.L8003EB70:
/* 19F70 8003EB70 0C011714 */  jal       func_80045C50
/* 19F74 8003EB74 00000000 */   nop
/* 19F78 8003EB78 2C420001 */  sltiu     $v0, $v0, 1
/* 19F7C 8003EB7C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19F80 8003EB80 00021040 */  sll       $v0, $v0, 1
/* 19F84 8003EB84 03E00008 */  jr        $ra
/* 19F88 8003EB88 27BD0018 */   addiu    $sp, $sp, 0x18
