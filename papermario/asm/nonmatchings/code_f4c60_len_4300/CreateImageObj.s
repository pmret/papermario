.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CreateImageObj
/* 0F7E24 802D3474 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F7E28 802D3478 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F7E2C 802D347C 0080902D */  daddu $s2, $a0, $zero
/* 0F7E30 802D3480 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F7E34 802D3484 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F7E38 802D3488 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F7E3C 802D348C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7E40 802D3490 8E42000C */  lw    $v0, 0xc($s2)
/* 0F7E44 802D3494 8C450004 */  lw    $a1, 4($v0)
/* 0F7E48 802D3498 8C530000 */  lw    $s3, ($v0)
/* 0F7E4C 802D349C 0C0B1EAF */  jal   get_variable
/* 0F7E50 802D34A0 0000882D */   daddu $s1, $zero, $zero
/* 0F7E54 802D34A4 0040202D */  daddu $a0, $v0, $zero
/* 0F7E58 802D34A8 3C03802E */  lui   $v1, 0x802e
/* 0F7E5C 802D34AC 8C63B7C0 */  lw    $v1, -0x4840($v1)
.L802D34B0:
/* 0F7E60 802D34B0 8C700000 */  lw    $s0, ($v1)
/* 0F7E64 802D34B4 8E020000 */  lw    $v0, ($s0)
/* 0F7E68 802D34B8 04400006 */  bltz  $v0, .L802D34D4
/* 0F7E6C 802D34BC 2A220040 */   slti  $v0, $s1, 0x40
/* 0F7E70 802D34C0 26310001 */  addiu $s1, $s1, 1
/* 0F7E74 802D34C4 2A220040 */  slti  $v0, $s1, 0x40
/* 0F7E78 802D34C8 1440FFF9 */  bnez  $v0, .L802D34B0
/* 0F7E7C 802D34CC 24630004 */   addiu $v1, $v1, 4
/* 0F7E80 802D34D0 2A220040 */  slti  $v0, $s1, 0x40
.L802D34D4:
/* 0F7E84 802D34D4 10400016 */  beqz  $v0, .L802D3530
/* 0F7E88 802D34D8 24020002 */   addiu $v0, $zero, 2
/* 0F7E8C 802D34DC 0C048338 */  jal   func_80120CE0
/* 0F7E90 802D34E0 00000000 */   nop   
/* 0F7E94 802D34E4 3C013F80 */  lui   $at, 0x3f80
/* 0F7E98 802D34E8 44810000 */  mtc1  $at, $f0
/* 0F7E9C 802D34EC AE020000 */  sw    $v0, ($s0)
/* 0F7EA0 802D34F0 0040202D */  daddu $a0, $v0, $zero
/* 0F7EA4 802D34F4 AE000004 */  sw    $zero, 4($s0)
/* 0F7EA8 802D34F8 AE000008 */  sw    $zero, 8($s0)
/* 0F7EAC 802D34FC AE00000C */  sw    $zero, 0xc($s0)
/* 0F7EB0 802D3500 AE000010 */  sw    $zero, 0x10($s0)
/* 0F7EB4 802D3504 AE000014 */  sw    $zero, 0x14($s0)
/* 0F7EB8 802D3508 AE000018 */  sw    $zero, 0x18($s0)
/* 0F7EBC 802D350C E600001C */  swc1  $f0, 0x1c($s0)
/* 0F7EC0 802D3510 E6000020 */  swc1  $f0, 0x20($s0)
/* 0F7EC4 802D3514 0C0483C1 */  jal   func_80120F04
/* 0F7EC8 802D3518 E6000024 */   swc1  $f0, 0x24($s0)
/* 0F7ECC 802D351C 0240202D */  daddu $a0, $s2, $zero
/* 0F7ED0 802D3520 0260282D */  daddu $a1, $s3, $zero
/* 0F7ED4 802D3524 0C0B2026 */  jal   set_variable
/* 0F7ED8 802D3528 0220302D */   daddu $a2, $s1, $zero
/* 0F7EDC 802D352C 24020002 */  addiu $v0, $zero, 2
.L802D3530:
/* 0F7EE0 802D3530 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F7EE4 802D3534 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F7EE8 802D3538 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F7EEC 802D353C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F7EF0 802D3540 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F7EF4 802D3544 03E00008 */  jr    $ra
/* 0F7EF8 802D3548 27BD0028 */   addiu $sp, $sp, 0x28

/* 0F7EFC 802D354C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F7F00 802D3550 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F7F04 802D3554 0080902D */  daddu $s2, $a0, $zero
/* 0F7F08 802D3558 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F7F0C 802D355C AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F7F10 802D3560 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F7F14 802D3564 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F7F18 802D3568 8E42000C */  lw    $v0, 0xc($s2)
/* 0F7F1C 802D356C 8C450004 */  lw    $a1, 4($v0)
/* 0F7F20 802D3570 8C530000 */  lw    $s3, ($v0)
/* 0F7F24 802D3574 0C0B1EAF */  jal   get_variable
/* 0F7F28 802D3578 0000882D */   daddu $s1, $zero, $zero
/* 0F7F2C 802D357C 0040202D */  daddu $a0, $v0, $zero
/* 0F7F30 802D3580 3C03802E */  lui   $v1, 0x802e
/* 0F7F34 802D3584 8C63B7C0 */  lw    $v1, -0x4840($v1)
.L802D3588:
/* 0F7F38 802D3588 8C700000 */  lw    $s0, ($v1)
/* 0F7F3C 802D358C 8E020000 */  lw    $v0, ($s0)
/* 0F7F40 802D3590 04400006 */  bltz  $v0, .L802D35AC
/* 0F7F44 802D3594 2A220040 */   slti  $v0, $s1, 0x40
/* 0F7F48 802D3598 26310001 */  addiu $s1, $s1, 1
/* 0F7F4C 802D359C 2A220040 */  slti  $v0, $s1, 0x40
/* 0F7F50 802D35A0 1440FFF9 */  bnez  $v0, .L802D3588
/* 0F7F54 802D35A4 24630004 */   addiu $v1, $v1, 4
/* 0F7F58 802D35A8 2A220040 */  slti  $v0, $s1, 0x40
.L802D35AC:
/* 0F7F5C 802D35AC 10400016 */  beqz  $v0, .L802D3608
/* 0F7F60 802D35B0 24020002 */   addiu $v0, $zero, 2
/* 0F7F64 802D35B4 0C048379 */  jal   func_80120DE4
/* 0F7F68 802D35B8 00000000 */   nop   
/* 0F7F6C 802D35BC 3C013F80 */  lui   $at, 0x3f80
/* 0F7F70 802D35C0 44810000 */  mtc1  $at, $f0
/* 0F7F74 802D35C4 AE020000 */  sw    $v0, ($s0)
/* 0F7F78 802D35C8 0040202D */  daddu $a0, $v0, $zero
/* 0F7F7C 802D35CC AE000004 */  sw    $zero, 4($s0)
/* 0F7F80 802D35D0 AE000008 */  sw    $zero, 8($s0)
/* 0F7F84 802D35D4 AE00000C */  sw    $zero, 0xc($s0)
/* 0F7F88 802D35D8 AE000010 */  sw    $zero, 0x10($s0)
/* 0F7F8C 802D35DC AE000014 */  sw    $zero, 0x14($s0)
/* 0F7F90 802D35E0 AE000018 */  sw    $zero, 0x18($s0)
/* 0F7F94 802D35E4 E600001C */  swc1  $f0, 0x1c($s0)
/* 0F7F98 802D35E8 E6000020 */  swc1  $f0, 0x20($s0)
/* 0F7F9C 802D35EC 0C0483C1 */  jal   func_80120F04
/* 0F7FA0 802D35F0 E6000024 */   swc1  $f0, 0x24($s0)
/* 0F7FA4 802D35F4 0240202D */  daddu $a0, $s2, $zero
/* 0F7FA8 802D35F8 0260282D */  daddu $a1, $s3, $zero
/* 0F7FAC 802D35FC 0C0B2026 */  jal   set_variable
/* 0F7FB0 802D3600 0220302D */   daddu $a2, $s1, $zero
/* 0F7FB4 802D3604 24020002 */  addiu $v0, $zero, 2
.L802D3608:
/* 0F7FB8 802D3608 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F7FBC 802D360C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F7FC0 802D3610 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F7FC4 802D3614 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F7FC8 802D3618 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F7FCC 802D361C 03E00008 */  jr    $ra
/* 0F7FD0 802D3620 27BD0028 */   addiu $sp, $sp, 0x28

