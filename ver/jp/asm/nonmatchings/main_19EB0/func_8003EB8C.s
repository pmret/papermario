.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003EB8C
/* 19F8C 8003EB8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19F90 8003EB90 10A00004 */  beqz      $a1, .L8003EBA4
/* 19F94 8003EB94 AFBF0010 */   sw       $ra, 0x10($sp)
/* 19F98 8003EB98 24040001 */  addiu     $a0, $zero, 1
/* 19F9C 8003EB9C 0C011670 */  jal       func_800459C0
/* 19FA0 8003EBA0 2405003C */   addiu    $a1, $zero, 0x3c
.L8003EBA4:
/* 19FA4 8003EBA4 0C011714 */  jal       func_80045C50
/* 19FA8 8003EBA8 00000000 */   nop
/* 19FAC 8003EBAC 2C420001 */  sltiu     $v0, $v0, 1
/* 19FB0 8003EBB0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19FB4 8003EBB4 00021040 */  sll       $v0, $v0, 1
/* 19FB8 8003EBB8 03E00008 */  jr        $ra
/* 19FBC 8003EBBC 27BD0018 */   addiu    $sp, $sp, 0x18
