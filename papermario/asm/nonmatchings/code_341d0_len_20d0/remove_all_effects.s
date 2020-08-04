.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel remove_all_effects
/* 0358E0 8005A4E0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0358E4 8005A4E4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0358E8 8005A4E8 0000902D */  daddu $s2, $zero, $zero
/* 0358EC 8005A4EC AFB10014 */  sw    $s1, 0x14($sp)
/* 0358F0 8005A4F0 3C11800B */  lui   $s1, 0x800b
/* 0358F4 8005A4F4 26314398 */  addiu $s1, $s1, 0x4398
/* 0358F8 8005A4F8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0358FC 8005A4FC AFB00010 */  sw    $s0, 0x10($sp)
.L8005A500:
/* 035900 8005A500 8E300000 */  lw    $s0, ($s1)
/* 035904 8005A504 5200000E */  beql  $s0, $zero, .L8005A540
/* 035908 8005A508 26520001 */   addiu $s2, $s2, 1
/* 03590C 8005A50C 8E020000 */  lw    $v0, ($s0)
/* 035910 8005A510 30420004 */  andi  $v0, $v0, 4
/* 035914 8005A514 5040000A */  beql  $v0, $zero, .L8005A540
/* 035918 8005A518 26520001 */   addiu $s2, $s2, 1
/* 03591C 8005A51C 8E04000C */  lw    $a0, 0xc($s0)
/* 035920 8005A520 10800003 */  beqz  $a0, .L8005A530
/* 035924 8005A524 00000000 */   nop   
/* 035928 8005A528 0C00AB1E */  jal   general_heap_free
/* 03592C 8005A52C 00000000 */   nop   
.L8005A530:
/* 035930 8005A530 0C00AB1E */  jal   general_heap_free
/* 035934 8005A534 0200202D */   daddu $a0, $s0, $zero
/* 035938 8005A538 AE200000 */  sw    $zero, ($s1)
/* 03593C 8005A53C 26520001 */  addiu $s2, $s2, 1
.L8005A540:
/* 035940 8005A540 2A420060 */  slti  $v0, $s2, 0x60
/* 035944 8005A544 1440FFEE */  bnez  $v0, .L8005A500
/* 035948 8005A548 26310004 */   addiu $s1, $s1, 4
/* 03594C 8005A54C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 035950 8005A550 8FB20018 */  lw    $s2, 0x18($sp)
/* 035954 8005A554 8FB10014 */  lw    $s1, 0x14($sp)
/* 035958 8005A558 8FB00010 */  lw    $s0, 0x10($sp)
/* 03595C 8005A55C 03E00008 */  jr    $ra
/* 035960 8005A560 27BD0020 */   addiu $sp, $sp, 0x20

