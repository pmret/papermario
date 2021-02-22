.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050E6C
/* 2C26C 80050E6C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2C270 80050E70 AFB10014 */  sw        $s1, 0x14($sp)
/* 2C274 80050E74 0080882D */  daddu     $s1, $a0, $zero
/* 2C278 80050E78 0000382D */  daddu     $a3, $zero, $zero
/* 2C27C 80050E7C 24080001 */  addiu     $t0, $zero, 1
/* 2C280 80050E80 00E0302D */  daddu     $a2, $a3, $zero
/* 2C284 80050E84 240507B4 */  addiu     $a1, $zero, 0x7b4
/* 2C288 80050E88 AFBF0024 */  sw        $ra, 0x24($sp)
/* 2C28C 80050E8C AFB40020 */  sw        $s4, 0x20($sp)
/* 2C290 80050E90 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2C294 80050E94 AFB20018 */  sw        $s2, 0x18($sp)
/* 2C298 80050E98 AFB00010 */  sw        $s0, 0x10($sp)
.L80050E9C:
/* 2C29C 80050E9C 02252021 */  addu      $a0, $s1, $a1
/* 2C2A0 80050EA0 90820003 */  lbu       $v0, 3($a0)
/* 2C2A4 80050EA4 54480008 */  bnel      $v0, $t0, .L80050EC8
/* 2C2A8 80050EA8 24C60048 */   addiu    $a2, $a2, 0x48
/* 2C2AC 80050EAC 8E220000 */  lw        $v0, ($s1)
/* 2C2B0 80050EB0 00461021 */  addu      $v0, $v0, $a2
/* 2C2B4 80050EB4 90431365 */  lbu       $v1, 0x1365($v0)
/* 2C2B8 80050EB8 92220022 */  lbu       $v0, 0x22($s1)
/* 2C2BC 80050EBC 54620001 */  bnel      $v1, $v0, .L80050EC4
/* 2C2C0 80050EC0 AC800000 */   sw       $zero, ($a0)
.L80050EC4:
/* 2C2C4 80050EC4 24C60048 */  addiu     $a2, $a2, 0x48
.L80050EC8:
/* 2C2C8 80050EC8 24E70001 */  addiu     $a3, $a3, 1
/* 2C2CC 80050ECC 2CE20010 */  sltiu     $v0, $a3, 0x10
/* 2C2D0 80050ED0 1440FFF2 */  bnez      $v0, .L80050E9C
/* 2C2D4 80050ED4 24A50008 */   addiu    $a1, $a1, 8
/* 2C2D8 80050ED8 0000982D */  daddu     $s3, $zero, $zero
/* 2C2DC 80050EDC 24140001 */  addiu     $s4, $zero, 1
/* 2C2E0 80050EE0 24120024 */  addiu     $s2, $zero, 0x24
/* 2C2E4 80050EE4 02328021 */  addu      $s0, $s1, $s2
.L80050EE8:
/* 2C2E8 80050EE8 8E020008 */  lw        $v0, 8($s0)
/* 2C2EC 80050EEC 50400030 */  beql      $v0, $zero, .L80050FB0
/* 2C2F0 80050EF0 265201E4 */   addiu    $s2, $s2, 0x1e4
/* 2C2F4 80050EF4 92220021 */  lbu       $v0, 0x21($s1)
/* 2C2F8 80050EF8 10400003 */  beqz      $v0, .L80050F08
/* 2C2FC 80050EFC 0220202D */   daddu    $a0, $s1, $zero
/* 2C300 80050F00 0C0143F9 */  jal       func_80050FE4
/* 2C304 80050F04 0200282D */   daddu    $a1, $s0, $zero
.L80050F08:
/* 2C308 80050F08 92030024 */  lbu       $v1, 0x24($s0)
/* 2C30C 80050F0C 10600018 */  beqz      $v1, .L80050F70
/* 2C310 80050F10 24020003 */   addiu    $v0, $zero, 3
/* 2C314 80050F14 1462000A */  bne       $v1, $v0, .L80050F40
/* 2C318 80050F18 24020002 */   addiu    $v0, $zero, 2
/* 2C31C 80050F1C A2020024 */  sb        $v0, 0x24($s0)
/* 2C320 80050F20 0220202D */  daddu     $a0, $s1, $zero
/* 2C324 80050F24 0C0147D6 */  jal       func_80051F58
/* 2C328 80050F28 0200282D */   daddu    $a1, $s0, $zero
/* 2C32C 80050F2C 0220202D */  daddu     $a0, $s1, $zero
/* 2C330 80050F30 0C0147A6 */  jal       func_80051E98
/* 2C334 80050F34 0200282D */   daddu    $a1, $s0, $zero
/* 2C338 80050F38 080143EC */  j         .L80050FB0
/* 2C33C 80050F3C 265201E4 */   addiu    $s2, $s2, 0x1e4
.L80050F40:
/* 2C340 80050F40 5474001B */  bnel      $v1, $s4, .L80050FB0
/* 2C344 80050F44 265201E4 */   addiu    $s2, $s2, 0x1e4
/* 2C348 80050F48 96020028 */  lhu       $v0, 0x28($s0)
/* 2C34C 80050F4C 10400003 */  beqz      $v0, .L80050F5C
/* 2C350 80050F50 A2000024 */   sb       $zero, 0x24($s0)
/* 2C354 80050F54 0C014280 */  jal       func_80050A00
/* 2C358 80050F58 0200202D */   daddu    $a0, $s0, $zero
.L80050F5C:
/* 2C35C 80050F5C 0220202D */  daddu     $a0, $s1, $zero
/* 2C360 80050F60 0C0147F7 */  jal       func_80051FDC
/* 2C364 80050F64 0200282D */   daddu    $a1, $s0, $zero
/* 2C368 80050F68 080143EC */  j         .L80050FB0
/* 2C36C 80050F6C 265201E4 */   addiu    $s2, $s2, 0x1e4
.L80050F70:
/* 2C370 80050F70 96020028 */  lhu       $v0, 0x28($s0)
/* 2C374 80050F74 10400003 */  beqz      $v0, .L80050F84
/* 2C378 80050F78 00000000 */   nop
/* 2C37C 80050F7C 0C014280 */  jal       func_80050A00
/* 2C380 80050F80 0200202D */   daddu    $a0, $s0, $zero
.L80050F84:
/* 2C384 80050F84 92030025 */  lbu       $v1, 0x25($s0)
/* 2C388 80050F88 24020002 */  addiu     $v0, $zero, 2
/* 2C38C 80050F8C 14620005 */  bne       $v1, $v0, .L80050FA4
/* 2C390 80050F90 0220202D */   daddu    $a0, $s1, $zero
/* 2C394 80050F94 0C0147A6 */  jal       func_80051E98
/* 2C398 80050F98 0200282D */   daddu    $a1, $s0, $zero
/* 2C39C 80050F9C A2140025 */  sb        $s4, 0x25($s0)
/* 2C3A0 80050FA0 0220202D */  daddu     $a0, $s1, $zero
.L80050FA4:
/* 2C3A4 80050FA4 0C014439 */  jal       func_800510E4
/* 2C3A8 80050FA8 0200282D */   daddu    $a1, $s0, $zero
/* 2C3AC 80050FAC 265201E4 */  addiu     $s2, $s2, 0x1e4
.L80050FB0:
/* 2C3B0 80050FB0 26730001 */  addiu     $s3, $s3, 1
/* 2C3B4 80050FB4 2A620004 */  slti      $v0, $s3, 4
/* 2C3B8 80050FB8 1440FFCB */  bnez      $v0, .L80050EE8
/* 2C3BC 80050FBC 02328021 */   addu     $s0, $s1, $s2
/* 2C3C0 80050FC0 A2200021 */  sb        $zero, 0x21($s1)
/* 2C3C4 80050FC4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 2C3C8 80050FC8 8FB40020 */  lw        $s4, 0x20($sp)
/* 2C3CC 80050FCC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2C3D0 80050FD0 8FB20018 */  lw        $s2, 0x18($sp)
/* 2C3D4 80050FD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 2C3D8 80050FD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 2C3DC 80050FDC 03E00008 */  jr        $ra
/* 2C3E0 80050FE0 27BD0028 */   addiu    $sp, $sp, 0x28
