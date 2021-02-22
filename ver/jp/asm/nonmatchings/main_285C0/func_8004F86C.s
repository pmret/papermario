.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004F86C
/* 2AC6C 8004F86C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2AC70 8004F870 AFB00010 */  sw        $s0, 0x10($sp)
/* 2AC74 8004F874 0080802D */  daddu     $s0, $a0, $zero
/* 2AC78 8004F878 AFBF0014 */  sw        $ra, 0x14($sp)
/* 2AC7C 8004F87C 960500D4 */  lhu       $a1, 0xd4($s0)
/* 2AC80 8004F880 0C013E2E */  jal       func_8004F8B8
/* 2AC84 8004F884 A6050208 */   sh       $a1, 0x208($s0)
/* 2AC88 8004F888 00021880 */  sll       $v1, $v0, 2
/* 2AC8C 8004F88C 00621821 */  addu      $v1, $v1, $v0
/* 2AC90 8004F890 00031840 */  sll       $v1, $v1, 1
/* 2AC94 8004F894 AE0200B0 */  sw        $v0, 0xb0($s0)
/* 2AC98 8004F898 AE030008 */  sw        $v1, 8($s0)
/* 2AC9C 8004F89C AE0000BC */  sw        $zero, 0xbc($s0)
/* 2ACA0 8004F8A0 AE0000B8 */  sw        $zero, 0xb8($s0)
/* 2ACA4 8004F8A4 AE0000B4 */  sw        $zero, 0xb4($s0)
/* 2ACA8 8004F8A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2ACAC 8004F8AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 2ACB0 8004F8B0 03E00008 */  jr        $ra
/* 2ACB4 8004F8B4 27BD0018 */   addiu    $sp, $sp, 0x18
