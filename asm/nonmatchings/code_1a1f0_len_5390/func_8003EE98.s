.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003EE98
/* 1A298 8003EE98 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A29C 8003EE9C 10A00004 */  beqz      $a1, .L8003EEB0
/* 1A2A0 8003EEA0 AFBF0010 */   sw       $ra, 0x10($sp)
/* 1A2A4 8003EEA4 0000202D */  daddu     $a0, $zero, $zero
/* 1A2A8 8003EEA8 0C011740 */  jal       func_80045D00
/* 1A2AC 8003EEAC 2405003C */   addiu    $a1, $zero, 0x3c
.L8003EEB0:
/* 1A2B0 8003EEB0 0C0117E9 */  jal       func_80045FA4
/* 1A2B4 8003EEB4 00000000 */   nop      
/* 1A2B8 8003EEB8 2C420001 */  sltiu     $v0, $v0, 1
/* 1A2BC 8003EEBC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A2C0 8003EEC0 00021040 */  sll       $v0, $v0, 1
/* 1A2C4 8003EEC4 03E00008 */  jr        $ra
/* 1A2C8 8003EEC8 27BD0018 */   addiu    $sp, $sp, 0x18
