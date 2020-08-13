.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024C154
/* 13F494 8024C154 AC500000 */  sw    $s0, ($v0)
/* 13F498 8024C158 ACA30000 */  sw    $v1, ($a1)
/* 13F49C 8024C15C 26100001 */  addiu $s0, $s0, 1
.L8024C160:
/* 13F4A0 8024C160 2A020008 */  slti  $v0, $s0, 8
/* 13F4A4 8024C164 1440FFF1 */  bnez  $v0, .L8024C12C
/* 13F4A8 8024C168 24840004 */   addiu $a0, $a0, 4
/* 13F4AC 8024C16C 3C028027 */  lui   $v0, 0x8027
/* 13F4B0 8024C170 8C4206B0 */  lw    $v0, 0x6b0($v0)
/* 13F4B4 8024C174 1440000A */  bnez  $v0, .L8024C1A0
/* 13F4B8 8024C178 0000802D */   daddu $s0, $zero, $zero
/* 13F4BC 8024C17C 24040022 */  addiu $a0, $zero, 0x22
/* 13F4C0 8024C180 0C051F9F */  jal   func_80147E7C
/* 13F4C4 8024C184 24050002 */   addiu $a1, $zero, 2
/* 13F4C8 8024C188 080930C6 */  j     func_8024C318
/* 13F4CC 8024C18C A2800000 */   sb    $zero, ($s4)

.L8024C190:
/* 13F4D0 8024C190 3C018027 */  lui   $at, 0x8027
/* 13F4D4 8024C194 AC3006A0 */  sw    $s0, 0x6a0($at)
/* 13F4D8 8024C198 080930A6 */  j     func_8024C298
/* 13F4DC 8024C19C 00000000 */   nop   

.L8024C1A0:
/* 13F4E0 8024C1A0 3C128027 */  lui   $s2, 0x8027
/* 13F4E4 8024C1A4 26520660 */  addiu $s2, $s2, 0x660
/* 13F4E8 8024C1A8 3C118025 */  lui   $s1, 0x8025
/* 13F4EC 8024C1AC 2631F630 */  addiu $s1, $s1, -0x9d0
.L8024C1B0:
/* 13F4F0 8024C1B0 0220282D */  daddu $a1, $s1, $zero
/* 13F4F4 8024C1B4 8E240000 */  lw    $a0, ($s1)
/* 13F4F8 8024C1B8 26310010 */  addiu $s1, $s1, 0x10
/* 13F4FC 8024C1BC 0C0B783B */  jal   func_802DE0EC
/* 13F500 8024C1C0 26100001 */   addiu $s0, $s0, 1
/* 13F504 8024C1C4 AE420000 */  sw    $v0, ($s2)
/* 13F508 8024C1C8 2A020008 */  slti  $v0, $s0, 8
/* 13F50C 8024C1CC 1440FFF8 */  bnez  $v0, .L8024C1B0
/* 13F510 8024C1D0 26520004 */   addiu $s2, $s2, 4
/* 13F514 8024C1D4 0000802D */  daddu $s0, $zero, $zero
/* 13F518 8024C1D8 3C128027 */  lui   $s2, 0x8027
/* 13F51C 8024C1DC 26520640 */  addiu $s2, $s2, 0x640
/* 13F520 8024C1E0 3C118025 */  lui   $s1, 0x8025
/* 13F524 8024C1E4 2631F600 */  addiu $s1, $s1, -0xa00
.L8024C1E8:
/* 13F528 8024C1E8 8E240000 */  lw    $a0, ($s1)
/* 13F52C 8024C1EC 26310004 */  addiu $s1, $s1, 4
/* 13F530 8024C1F0 0C050529 */  jal   create_icon
/* 13F534 8024C1F4 26100001 */   addiu $s0, $s0, 1
/* 13F538 8024C1F8 0040202D */  daddu $a0, $v0, $zero
/* 13F53C 8024C1FC 24050080 */  addiu $a1, $zero, 0x80
/* 13F540 8024C200 0C051280 */  jal   set_icon_flags
/* 13F544 8024C204 AE440000 */   sw    $a0, ($s2)
/* 13F548 8024C208 2A020008 */  slti  $v0, $s0, 8
/* 13F54C 8024C20C 1440FFF6 */  bnez  $v0, .L8024C1E8
/* 13F550 8024C210 26520004 */   addiu $s2, $s2, 4
/* 13F554 8024C214 24100004 */  addiu $s0, $zero, 4
/* 13F558 8024C218 3C028025 */  lui   $v0, 0x8025
/* 13F55C 8024C21C 2442F858 */  addiu $v0, $v0, -0x7a8
.L8024C220:
/* 13F560 8024C220 AC540010 */  sw    $s4, 0x10($v0)
/* 13F564 8024C224 2610FFFF */  addiu $s0, $s0, -1
/* 13F568 8024C228 0601FFFD */  bgez  $s0, .L8024C220
/* 13F56C 8024C22C 2442FFDC */   addiu $v0, $v0, -0x24
/* 13F570 8024C230 3C048025 */  lui   $a0, 0x8025
/* 13F574 8024C234 2484F7C8 */  addiu $a0, $a0, -0x838
/* 13F578 8024C238 0C051FCC */  jal   func_80147F30
/* 13F57C 8024C23C 24050005 */   addiu $a1, $zero, 5
/* 13F580 8024C240 3C028027 */  lui   $v0, 0x8027
/* 13F584 8024C244 8C4206B0 */  lw    $v0, 0x6b0($v0)
/* 13F588 8024C248 3C018027 */  lui   $at, 0x8027
/* 13F58C 8024C24C AC2006A0 */  sw    $zero, 0x6a0($at)
/* 13F590 8024C250 18400011 */  blez  $v0, .L8024C298
/* 13F594 8024C254 0000802D */   daddu $s0, $zero, $zero
/* 13F598 8024C258 82650012 */  lb    $a1, 0x12($s3)
/* 13F59C 8024C25C 3C068025 */  lui   $a2, 0x8025
/* 13F5A0 8024C260 24C6F6B0 */  addiu $a2, $a2, -0x950
/* 13F5A4 8024C264 0040202D */  daddu $a0, $v0, $zero
/* 13F5A8 8024C268 3C038027 */  lui   $v1, 0x8027
/* 13F5AC 8024C26C 24630680 */  addiu $v1, $v1, 0x680
.L8024C270:
/* 13F5B0 8024C270 8C620000 */  lw    $v0, ($v1)
/* 13F5B4 8024C274 00021080 */  sll   $v0, $v0, 2
/* 13F5B8 8024C278 00461021 */  addu  $v0, $v0, $a2
/* 13F5BC 8024C27C 8C420000 */  lw    $v0, ($v0)
/* 13F5C0 8024C280 10A2FFC3 */  beq   $a1, $v0, .L8024C190
/* 13F5C4 8024C284 00000000 */   nop   
/* 13F5C8 8024C288 26100001 */  addiu $s0, $s0, 1
/* 13F5CC 8024C28C 0204102A */  slt   $v0, $s0, $a0
/* 13F5D0 8024C290 1440FFF7 */  bnez  $v0, .L8024C270
/* 13F5D4 8024C294 24630004 */   addiu $v1, $v1, 4
