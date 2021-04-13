.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005AB50
/* 35F50 8005AB50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 35F54 8005AB54 AFB00010 */  sw        $s0, 0x10($sp)
/* 35F58 8005AB58 3C10800B */  lui       $s0, %hi(D_800B42C0)
/* 35F5C 8005AB5C 261042C0 */  addiu     $s0, $s0, %lo(D_800B42C0)
/* 35F60 8005AB60 AFBF0014 */  sw        $ra, 0x14($sp)
/* 35F64 8005AB64 8604000C */  lh        $a0, 0xc($s0)
/* 35F68 8005AB68 0C00AAFA */  jal       func_8002ABE8
/* 35F6C 8005AB6C 000420C0 */   sll      $a0, $a0, 3
/* 35F70 8005AB70 0040202D */  daddu     $a0, $v0, $zero
/* 35F74 8005AB74 8602000C */  lh        $v0, 0xc($s0)
/* 35F78 8005AB78 3C01800A */  lui       $at, %hi(D_800A2074)
/* 35F7C 8005AB7C AC242074 */  sw        $a0, %lo(D_800A2074)($at)
/* 35F80 8005AB80 1840000E */  blez      $v0, .L8005ABBC
/* 35F84 8005AB84 0000282D */   daddu    $a1, $zero, $zero
/* 35F88 8005AB88 00A0302D */  daddu     $a2, $a1, $zero
.L8005AB8C:
/* 35F8C 8005AB8C 8E020004 */  lw        $v0, 4($s0)
/* 35F90 8005AB90 00461821 */  addu      $v1, $v0, $a2
/* 35F94 8005AB94 8C620000 */  lw        $v0, ($v1)
/* 35F98 8005AB98 24A50001 */  addiu     $a1, $a1, 1
/* 35F9C 8005AB9C AC820000 */  sw        $v0, ($a0)
/* 35FA0 8005ABA0 94620008 */  lhu       $v0, 8($v1)
/* 35FA4 8005ABA4 24C6001C */  addiu     $a2, $a2, 0x1c
/* 35FA8 8005ABA8 A4820004 */  sh        $v0, 4($a0)
/* 35FAC 8005ABAC 8602000C */  lh        $v0, 0xc($s0)
/* 35FB0 8005ABB0 00A2102A */  slt       $v0, $a1, $v0
/* 35FB4 8005ABB4 1440FFF5 */  bnez      $v0, .L8005AB8C
/* 35FB8 8005ABB8 24840008 */   addiu    $a0, $a0, 8
.L8005ABBC:
/* 35FBC 8005ABBC 3C10800E */  lui       $s0, %hi(D_800D91B0)
/* 35FC0 8005ABC0 261091B0 */  addiu     $s0, $s0, %lo(D_800D91B0)
/* 35FC4 8005ABC4 8604000C */  lh        $a0, 0xc($s0)
/* 35FC8 8005ABC8 0C00AAFA */  jal       func_8002ABE8
/* 35FCC 8005ABCC 000420C0 */   sll      $a0, $a0, 3
/* 35FD0 8005ABD0 0040202D */  daddu     $a0, $v0, $zero
/* 35FD4 8005ABD4 8602000C */  lh        $v0, 0xc($s0)
/* 35FD8 8005ABD8 3C01800A */  lui       $at, %hi(D_800A2078)
/* 35FDC 8005ABDC AC242078 */  sw        $a0, %lo(D_800A2078)($at)
/* 35FE0 8005ABE0 1840000E */  blez      $v0, .L8005AC1C
/* 35FE4 8005ABE4 0000282D */   daddu    $a1, $zero, $zero
/* 35FE8 8005ABE8 00A0302D */  daddu     $a2, $a1, $zero
.L8005ABEC:
/* 35FEC 8005ABEC 8E020004 */  lw        $v0, 4($s0)
/* 35FF0 8005ABF0 00461821 */  addu      $v1, $v0, $a2
/* 35FF4 8005ABF4 8C620000 */  lw        $v0, ($v1)
/* 35FF8 8005ABF8 24A50001 */  addiu     $a1, $a1, 1
/* 35FFC 8005ABFC AC820000 */  sw        $v0, ($a0)
/* 36000 8005AC00 94620008 */  lhu       $v0, 8($v1)
/* 36004 8005AC04 24C6001C */  addiu     $a2, $a2, 0x1c
/* 36008 8005AC08 A4820004 */  sh        $v0, 4($a0)
/* 3600C 8005AC0C 8602000C */  lh        $v0, 0xc($s0)
/* 36010 8005AC10 00A2102A */  slt       $v0, $a1, $v0
/* 36014 8005AC14 1440FFF5 */  bnez      $v0, .L8005ABEC
/* 36018 8005AC18 24840008 */   addiu    $a0, $a0, 8
.L8005AC1C:
/* 3601C 8005AC1C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 36020 8005AC20 8FB00010 */  lw        $s0, 0x10($sp)
/* 36024 8005AC24 3C01800E */  lui       $at, %hi(D_800D91BC)
/* 36028 8005AC28 A42091BC */  sh        $zero, %lo(D_800D91BC)($at)
/* 3602C 8005AC2C 03E00008 */  jr        $ra
/* 36030 8005AC30 27BD0018 */   addiu    $sp, $sp, 0x18
