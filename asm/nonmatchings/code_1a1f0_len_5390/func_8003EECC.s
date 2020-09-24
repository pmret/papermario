.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003EECC
/* 1A2CC 8003EECC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A2D0 8003EED0 10A00004 */  beqz      $a1, .L8003EEE4
/* 1A2D4 8003EED4 AFBF0010 */   sw       $ra, 0x10($sp)
/* 1A2D8 8003EED8 24040001 */  addiu     $a0, $zero, 1
/* 1A2DC 8003EEDC 0C011740 */  jal       func_80045D00
/* 1A2E0 8003EEE0 2405003C */   addiu    $a1, $zero, 0x3c
.L8003EEE4:
/* 1A2E4 8003EEE4 0C0117E9 */  jal       func_80045FA4
/* 1A2E8 8003EEE8 00000000 */   nop      
/* 1A2EC 8003EEEC 2C420001 */  sltiu     $v0, $v0, 1
/* 1A2F0 8003EEF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A2F4 8003EEF4 00021040 */  sll       $v0, $v0, 1
/* 1A2F8 8003EEF8 03E00008 */  jr        $ra
/* 1A2FC 8003EEFC 27BD0018 */   addiu    $sp, $sp, 0x18
