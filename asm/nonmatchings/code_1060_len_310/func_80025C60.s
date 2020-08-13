.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80025C60
/* 001060 80025C60 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 001064 80025C64 3C05B3FF */  lui   $a1, 0xb3ff
/* 001068 80025C68 34A50014 */  ori   $a1, $a1, 0x14
/* 00106C 80025C6C AFB00010 */  sw    $s0, 0x10($sp)
/* 001070 80025C70 3C10800A */  lui   $s0, 0x800a
/* 001074 80025C74 2610A638 */  addiu $s0, $s0, -0x59c8
/* 001078 80025C78 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00107C 80025C7C 8E040000 */  lw    $a0, ($s0)
/* 001080 80025C80 0C018358 */  jal   osEPiWriteIo
/* 001084 80025C84 0000302D */   daddu $a2, $zero, $zero
/* 001088 80025C88 3C05B3FF */  lui   $a1, 0xb3ff
/* 00108C 80025C8C 34A50004 */  ori   $a1, $a1, 4
/* 001090 80025C90 8E040000 */  lw    $a0, ($s0)
/* 001094 80025C94 0C018358 */  jal   osEPiWriteIo
/* 001098 80025C98 0000302D */   daddu $a2, $zero, $zero
/* 00109C 80025C9C 3C05B3FF */  lui   $a1, 0xb3ff
/* 0010A0 80025CA0 3C064953 */  lui   $a2, 0x4953
/* 0010A4 80025CA4 8E040000 */  lw    $a0, ($s0)
/* 0010A8 80025CA8 0C018358 */  jal   osEPiWriteIo
/* 0010AC 80025CAC 34C63634 */   ori   $a2, $a2, 0x3634
/* 0010B0 80025CB0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0010B4 80025CB4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0010B8 80025CB8 03E00008 */  jr    $ra
/* 0010BC 80025CBC 27BD0018 */   addiu $sp, $sp, 0x18

/* 0010C0 80025CC0 AFA40000 */  sw    $a0, ($sp)
/* 0010C4 80025CC4 AFA50004 */  sw    $a1, 4($sp)
/* 0010C8 80025CC8 AFA60008 */  sw    $a2, 8($sp)
/* 0010CC 80025CCC AFA7000C */  sw    $a3, 0xc($sp)
/* 0010D0 80025CD0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0010D4 80025CD4 0080302D */  daddu $a2, $a0, $zero
/* 0010D8 80025CD8 3C048002 */  lui   $a0, 0x8002
/* 0010DC 80025CDC 24845D74 */  addiu $a0, $a0, 0x5d74
/* 0010E0 80025CE0 0000282D */  daddu $a1, $zero, $zero
/* 0010E4 80025CE4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0010E8 80025CE8 0C0192A8 */  jal   _Printf
/* 0010EC 80025CEC 27A7001C */   addiu $a3, $sp, 0x1c
/* 0010F0 80025CF0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0010F4 80025CF4 03E00008 */  jr    $ra
/* 0010F8 80025CF8 27BD0018 */   addiu $sp, $sp, 0x18

