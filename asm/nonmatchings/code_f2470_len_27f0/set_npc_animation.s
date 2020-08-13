.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_npc_animation
/* 0F24BC 802CDB0C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F24C0 802CDB10 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F24C4 802CDB14 0080882D */  daddu $s1, $a0, $zero
/* 0F24C8 802CDB18 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F24CC 802CDB1C 00A0802D */  daddu $s0, $a1, $zero
/* 0F24D0 802CDB20 2604FEFF */  addiu $a0, $s0, -0x101
/* 0F24D4 802CDB24 2C820009 */  sltiu $v0, $a0, 9
/* 0F24D8 802CDB28 1040000D */  beqz  $v0, .L802CDB60
/* 0F24DC 802CDB2C AFBF0018 */   sw    $ra, 0x18($sp)
/* 0F24E0 802CDB30 3C028011 */  lui   $v0, 0x8011
/* 0F24E4 802CDB34 2442F290 */  addiu $v0, $v0, -0xd70
/* 0F24E8 802CDB38 80430012 */  lb    $v1, 0x12($v0)
/* 0F24EC 802CDB3C 000310C0 */  sll   $v0, $v1, 3
/* 0F24F0 802CDB40 00431021 */  addu  $v0, $v0, $v1
/* 0F24F4 802CDB44 00441021 */  addu  $v0, $v0, $a0
/* 0F24F8 802CDB48 00021080 */  sll   $v0, $v0, 2
/* 0F24FC 802CDB4C 3C018010 */  lui   $at, 0x8010
/* 0F2500 802CDB50 00220821 */  addu  $at, $at, $v0
/* 0F2504 802CDB54 8C228348 */  lw    $v0, -0x7cb8($at)
/* 0F2508 802CDB58 080B36E4 */  j     .L802CDB90
/* 0F250C 802CDB5C AE220028 */   sw    $v0, 0x28($s1)

.L802CDB60:
/* 0F2510 802CDB60 2602FDFF */  addiu $v0, $s0, -0x201
/* 0F2514 802CDB64 2C420010 */  sltiu $v0, $v0, 0x10
/* 0F2518 802CDB68 50400009 */  beql  $v0, $zero, .L802CDB90
/* 0F251C 802CDB6C AE300028 */   sw    $s0, 0x28($s1)
/* 0F2520 802CDB70 822400A4 */  lb    $a0, 0xa4($s1)
/* 0F2524 802CDB74 0C00FB3A */  jal   get_enemy
/* 0F2528 802CDB78 00000000 */   nop   
/* 0F252C 802CDB7C 8C4200CC */  lw    $v0, 0xcc($v0)
/* 0F2530 802CDB80 00101880 */  sll   $v1, $s0, 2
/* 0F2534 802CDB84 00621821 */  addu  $v1, $v1, $v0
/* 0F2538 802CDB88 8C62F7FC */  lw    $v0, -0x804($v1)
/* 0F253C 802CDB8C AE220028 */  sw    $v0, 0x28($s1)
.L802CDB90:
/* 0F2540 802CDB90 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F2544 802CDB94 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2548 802CDB98 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F254C 802CDB9C 03E00008 */  jr    $ra
/* 0F2550 802CDBA0 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F2554 802CDBA4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F2558 802CDBA8 AFB10024 */  sw    $s1, 0x24($sp)
/* 0F255C 802CDBAC 0080882D */  daddu $s1, $a0, $zero
/* 0F2560 802CDBB0 AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F2564 802CDBB4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F2568 802CDBB8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F256C 802CDBBC 8E050000 */  lw    $a1, ($s0)
/* 0F2570 802CDBC0 0C0B1EAF */  jal   get_variable
/* 0F2574 802CDBC4 26100004 */   addiu $s0, $s0, 4
/* 0F2578 802CDBC8 0220202D */  daddu $a0, $s1, $zero
/* 0F257C 802CDBCC 8E050000 */  lw    $a1, ($s0)
/* 0F2580 802CDBD0 0C0B1EAF */  jal   get_variable
/* 0F2584 802CDBD4 0040802D */   daddu $s0, $v0, $zero
/* 0F2588 802CDBD8 27A40010 */  addiu $a0, $sp, 0x10
/* 0F258C 802CDBDC AFA00010 */  sw    $zero, 0x10($sp)
/* 0F2590 802CDBE0 AFA20014 */  sw    $v0, 0x14($sp)
/* 0F2594 802CDBE4 AFA00018 */  sw    $zero, 0x18($sp)
/* 0F2598 802CDBE8 0C00E211 */  jal   func_80038844
/* 0F259C 802CDBEC AFA0001C */   sw    $zero, 0x1c($sp)
/* 0F25A0 802CDBF0 0C00E2B7 */  jal   get_npc_by_index
/* 0F25A4 802CDBF4 0040202D */   daddu $a0, $v0, $zero
/* 0F25A8 802CDBF8 0040202D */  daddu $a0, $v0, $zero
/* 0F25AC 802CDBFC 0C00EAFF */  jal   disable_npc_shadow
/* 0F25B0 802CDC00 A09000A4 */   sb    $s0, 0xa4($a0)
/* 0F25B4 802CDC04 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F25B8 802CDC08 8FB10024 */  lw    $s1, 0x24($sp)
/* 0F25BC 802CDC0C 8FB00020 */  lw    $s0, 0x20($sp)
/* 0F25C0 802CDC10 24020002 */  addiu $v0, $zero, 2
/* 0F25C4 802CDC14 03E00008 */  jr    $ra
/* 0F25C8 802CDC18 27BD0030 */   addiu $sp, $sp, 0x30

