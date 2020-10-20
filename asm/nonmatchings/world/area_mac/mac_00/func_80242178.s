.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242178
/* 7ECE88 80242178 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7ECE8C 8024217C 3C05F5DE */  lui       $a1, 0xf5de
/* 7ECE90 80242180 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7ECE94 80242184 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ECE98 80242188 8C900148 */  lw        $s0, 0x148($a0)
/* 7ECE9C 8024218C 0C0B1EAF */  jal       get_variable
/* 7ECEA0 80242190 34A5019C */   ori      $a1, $a1, 0x19c
/* 7ECEA4 80242194 82030004 */  lb        $v1, 4($s0)
/* 7ECEA8 80242198 00021080 */  sll       $v0, $v0, 2
/* 7ECEAC 8024219C 00031880 */  sll       $v1, $v1, 2
/* 7ECEB0 802421A0 3C04800B */  lui       $a0, 0x800b
/* 7ECEB4 802421A4 00832021 */  addu      $a0, $a0, $v1
/* 7ECEB8 802421A8 8C840F38 */  lw        $a0, 0xf38($a0)
/* 7ECEBC 802421AC 3C038025 */  lui       $v1, 0x8025
/* 7ECEC0 802421B0 00621821 */  addu      $v1, $v1, $v0
/* 7ECEC4 802421B4 9463A632 */  lhu       $v1, -0x59ce($v1)
/* 7ECEC8 802421B8 A4830044 */  sh        $v1, 0x44($a0)
/* 7ECECC 802421BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7ECED0 802421C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ECED4 802421C4 24020002 */  addiu     $v0, $zero, 2
/* 7ECED8 802421C8 03E00008 */  jr        $ra
/* 7ECEDC 802421CC 27BD0018 */   addiu    $sp, $sp, 0x18
