.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuSiMgrInit
/* 008230 8002CE30 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 008234 8002CE34 AFB00030 */  sw    $s0, 0x30($sp)
/* 008238 8002CE38 3C10800E */  lui   $s0, 0x800e
/* 00823C 8002CE3C 2610AC78 */  addiu $s0, $s0, -0x5388
/* 008240 8002CE40 0200202D */  daddu $a0, $s0, $zero
/* 008244 8002CE44 3C05800A */  lui   $a1, 0x800a
/* 008248 8002CE48 24A5E6F0 */  addiu $a1, $a1, -0x1910
/* 00824C 8002CE4C AFBF0034 */  sw    $ra, 0x34($sp)
/* 008250 8002CE50 0C019560 */  jal   osCreateMesgQueue
/* 008254 8002CE54 24060008 */   addiu $a2, $zero, 8
/* 008258 8002CE58 24040005 */  addiu $a0, $zero, 5
/* 00825C 8002CE5C 0200282D */  daddu $a1, $s0, $zero
/* 008260 8002CE60 0C019654 */  jal   osSetEventMesg
/* 008264 8002CE64 0000302D */   daddu $a2, $zero, $zero
/* 008268 8002CE68 0200202D */  daddu $a0, $s0, $zero
/* 00826C 8002CE6C 27A50028 */  addiu $a1, $sp, 0x28
/* 008270 8002CE70 0C0186E0 */  jal   osContInit
/* 008274 8002CE74 27A60018 */   addiu $a2, $sp, 0x18
/* 008278 8002CE78 0000182D */  daddu $v1, $zero, $zero
/* 00827C 8002CE7C 24070005 */  addiu $a3, $zero, 5
/* 008280 8002CE80 24060001 */  addiu $a2, $zero, 1
/* 008284 8002CE84 27A40018 */  addiu $a0, $sp, 0x18
.L8002CE88:
/* 008288 8002CE88 93A50028 */  lbu   $a1, 0x28($sp)
/* 00828C 8002CE8C 00651007 */  srav  $v0, $a1, $v1
/* 008290 8002CE90 30420001 */  andi  $v0, $v0, 1
/* 008294 8002CE94 5040000D */  beql  $v0, $zero, .L8002CECC
/* 008298 8002CE98 24630001 */   addiu $v1, $v1, 1
/* 00829C 8002CE9C 90820003 */  lbu   $v0, 3($a0)
/* 0082A0 8002CEA0 5440000A */  bnel  $v0, $zero, .L8002CECC
/* 0082A4 8002CEA4 24630001 */   addiu $v1, $v1, 1
/* 0082A8 8002CEA8 94820000 */  lhu   $v0, ($a0)
/* 0082AC 8002CEAC 30421F07 */  andi  $v0, $v0, 0x1f07
/* 0082B0 8002CEB0 50470006 */  beql  $v0, $a3, .L8002CECC
/* 0082B4 8002CEB4 24630001 */   addiu $v1, $v1, 1
/* 0082B8 8002CEB8 00661004 */  sllv  $v0, $a2, $v1
/* 0082BC 8002CEBC 00021027 */  nor   $v0, $zero, $v0
/* 0082C0 8002CEC0 00A21024 */  and   $v0, $a1, $v0
/* 0082C4 8002CEC4 A3A20028 */  sb    $v0, 0x28($sp)
/* 0082C8 8002CEC8 24630001 */  addiu $v1, $v1, 1
.L8002CECC:
/* 0082CC 8002CECC 2C620004 */  sltiu $v0, $v1, 4
/* 0082D0 8002CED0 1440FFED */  bnez  $v0, .L8002CE88
/* 0082D4 8002CED4 24840004 */   addiu $a0, $a0, 4
/* 0082D8 8002CED8 3C10800A */  lui   $s0, 0x800a
/* 0082DC 8002CEDC 2610E710 */  addiu $s0, $s0, -0x18f0
/* 0082E0 8002CEE0 0200202D */  daddu $a0, $s0, $zero
/* 0082E4 8002CEE4 24050006 */  addiu $a1, $zero, 6
/* 0082E8 8002CEE8 3C068003 */  lui   $a2, 0x8003
/* 0082EC 8002CEEC 24C6CFD0 */  addiu $a2, $a2, -0x3030
/* 0082F0 8002CEF0 3C02800A */  lui   $v0, 0x800a
/* 0082F4 8002CEF4 244208C0 */  addiu $v0, $v0, 0x8c0
/* 0082F8 8002CEF8 AFA20010 */  sw    $v0, 0x10($sp)
/* 0082FC 8002CEFC 24020073 */  addiu $v0, $zero, 0x73
/* 008300 8002CF00 0000382D */  daddu $a3, $zero, $zero
/* 008304 8002CF04 0C019798 */  jal   osCreateThread
/* 008308 8002CF08 AFA20014 */   sw    $v0, 0x14($sp)
/* 00830C 8002CF0C 0C019808 */  jal   osStartThread
/* 008310 8002CF10 0200202D */   daddu $a0, $s0, $zero
/* 008314 8002CF14 93A20028 */  lbu   $v0, 0x28($sp)
/* 008318 8002CF18 8FBF0034 */  lw    $ra, 0x34($sp)
/* 00831C 8002CF1C 8FB00030 */  lw    $s0, 0x30($sp)
/* 008320 8002CF20 03E00008 */  jr    $ra
/* 008324 8002CF24 27BD0038 */   addiu $sp, $sp, 0x38

