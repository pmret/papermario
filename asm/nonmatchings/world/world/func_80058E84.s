.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80058E84
/* 34284 80058E84 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 34288 80058E88 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3428C 80058E8C 0080982D */  daddu     $s3, $a0, $zero
/* 34290 80058E90 AFB20018 */  sw        $s2, 0x18($sp)
/* 34294 80058E94 00C0902D */  daddu     $s2, $a2, $zero
/* 34298 80058E98 0240202D */  daddu     $a0, $s2, $zero
/* 3429C 80058E9C AFB40020 */  sw        $s4, 0x20($sp)
/* 342A0 80058EA0 00A0A02D */  daddu     $s4, $a1, $zero
/* 342A4 80058EA4 24050004 */  addiu     $a1, $zero, 4
/* 342A8 80058EA8 24060030 */  addiu     $a2, $zero, 0x30
/* 342AC 80058EAC AFBF0024 */  sw        $ra, 0x24($sp)
/* 342B0 80058EB0 AFB10014 */  sw        $s1, 0x14($sp)
/* 342B4 80058EB4 0C015FE4 */  jal       alHeapAlloc
/* 342B8 80058EB8 AFB00010 */   sw       $s0, 0x10($sp)
/* 342BC 80058EBC 0240202D */  daddu     $a0, $s2, $zero
/* 342C0 80058EC0 24050A10 */  addiu     $a1, $zero, 0xa10
/* 342C4 80058EC4 24060002 */  addiu     $a2, $zero, 2
/* 342C8 80058EC8 0C015FE4 */  jal       alHeapAlloc
/* 342CC 80058ECC AE62000C */   sw       $v0, 0xc($s3)
/* 342D0 80058ED0 0000882D */  daddu     $s1, $zero, $zero
/* 342D4 80058ED4 AE620000 */  sw        $v0, ($s3)
/* 342D8 80058ED8 0240202D */  daddu     $a0, $s2, $zero
.L80058EDC:
/* 342DC 80058EDC 24050001 */  addiu     $a1, $zero, 1
/* 342E0 80058EE0 24060010 */  addiu     $a2, $zero, 0x10
/* 342E4 80058EE4 3223FFFF */  andi      $v1, $s1, 0xffff
/* 342E8 80058EE8 00A31004 */  sllv      $v0, $v1, $a1
/* 342EC 80058EEC 00431021 */  addu      $v0, $v0, $v1
/* 342F0 80058EF0 8E70000C */  lw        $s0, 0xc($s3)
/* 342F4 80058EF4 00021100 */  sll       $v0, $v0, 4
/* 342F8 80058EF8 0C015FE4 */  jal       alHeapAlloc
/* 342FC 80058EFC 02028021 */   addu     $s0, $s0, $v0
/* 34300 80058F00 0240202D */  daddu     $a0, $s2, $zero
/* 34304 80058F04 24050001 */  addiu     $a1, $zero, 1
/* 34308 80058F08 24060020 */  addiu     $a2, $zero, 0x20
/* 3430C 80058F0C 0C015FE4 */  jal       alHeapAlloc
/* 34310 80058F10 AE02002C */   sw       $v0, 0x2c($s0)
/* 34314 80058F14 0240202D */  daddu     $a0, $s2, $zero
/* 34318 80058F18 24050001 */  addiu     $a1, $zero, 1
/* 3431C 80058F1C 8E03002C */  lw        $v1, 0x2c($s0)
/* 34320 80058F20 24060030 */  addiu     $a2, $zero, 0x30
/* 34324 80058F24 0C015FE4 */  jal       alHeapAlloc
/* 34328 80058F28 AC620000 */   sw       $v0, ($v1)
/* 3432C 80058F2C 0240202D */  daddu     $a0, $s2, $zero
/* 34330 80058F30 24050001 */  addiu     $a1, $zero, 1
/* 34334 80058F34 24060008 */  addiu     $a2, $zero, 8
/* 34338 80058F38 0C015FE4 */  jal       alHeapAlloc
/* 3433C 80058F3C AE020024 */   sw       $v0, 0x24($s0)
/* 34340 80058F40 8E030024 */  lw        $v1, 0x24($s0)
/* 34344 80058F44 26310001 */  addiu     $s1, $s1, 1
/* 34348 80058F48 AC620028 */  sw        $v0, 0x28($v1)
/* 3434C 80058F4C 3222FFFF */  andi      $v0, $s1, 0xffff
/* 34350 80058F50 2C420004 */  sltiu     $v0, $v0, 4
/* 34354 80058F54 1440FFE1 */  bnez      $v0, .L80058EDC
/* 34358 80058F58 0240202D */   daddu    $a0, $s2, $zero
/* 3435C 80058F5C 0260202D */  daddu     $a0, $s3, $zero
/* 34360 80058F60 0C016413 */  jal       func_8005904C
/* 34364 80058F64 328500FF */   andi     $a1, $s4, 0xff
/* 34368 80058F68 8FBF0024 */  lw        $ra, 0x24($sp)
/* 3436C 80058F6C 8FB40020 */  lw        $s4, 0x20($sp)
/* 34370 80058F70 8FB3001C */  lw        $s3, 0x1c($sp)
/* 34374 80058F74 8FB20018 */  lw        $s2, 0x18($sp)
/* 34378 80058F78 8FB10014 */  lw        $s1, 0x14($sp)
/* 3437C 80058F7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 34380 80058F80 03E00008 */  jr        $ra
/* 34384 80058F84 27BD0028 */   addiu    $sp, $sp, 0x28
