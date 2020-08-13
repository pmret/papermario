.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800558D4
/* 030CD4 800558D4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 030CD8 800558D8 AFB00018 */  sw    $s0, 0x18($sp)
/* 030CDC 800558DC 0080802D */  daddu $s0, $a0, $zero
/* 030CE0 800558E0 00A0202D */  daddu $a0, $a1, $zero
/* 030CE4 800558E4 27A50010 */  addiu $a1, $sp, 0x10
/* 030CE8 800558E8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 030CEC 800558EC 0C014F16 */  jal   func_80053C58
/* 030CF0 800558F0 27A60014 */   addiu $a2, $sp, 0x14
/* 030CF4 800558F4 8FA50010 */  lw    $a1, 0x10($sp)
/* 030CF8 800558F8 10A00004 */  beqz  $a1, .L8005590C
/* 030CFC 800558FC 24020003 */   addiu $v0, $zero, 3
/* 030D00 80055900 8FA60014 */  lw    $a2, 0x14($sp)
/* 030D04 80055904 0C014F3E */  jal   func_80053CF8
/* 030D08 80055908 0200202D */   daddu $a0, $s0, $zero
.L8005590C:
/* 030D0C 8005590C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 030D10 80055910 8FB00018 */  lw    $s0, 0x18($sp)
/* 030D14 80055914 03E00008 */  jr    $ra
/* 030D18 80055918 27BD0020 */   addiu $sp, $sp, 0x20

/* 030D1C 8005591C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 030D20 80055920 AFB00030 */  sw    $s0, 0x30($sp)
/* 030D24 80055924 3C108008 */  lui   $s0, 0x8008
/* 030D28 80055928 26108DB0 */  addiu $s0, $s0, -0x7250
/* 030D2C 8005592C 24020001 */  addiu $v0, $zero, 1
/* 030D30 80055930 AFBF0034 */  sw    $ra, 0x34($sp)
/* 030D34 80055934 AE020000 */  sw    $v0, ($s0)
/* 030D38 80055938 2402007F */  addiu $v0, $zero, 0x7f
/* 030D3C 8005593C AFA40010 */  sw    $a0, 0x10($sp)
/* 030D40 80055940 27A40010 */  addiu $a0, $sp, 0x10
/* 030D44 80055944 AFA00014 */  sw    $zero, 0x14($sp)
/* 030D48 80055948 AFA20018 */  sw    $v0, 0x18($sp)
/* 030D4C 8005594C AFA2001C */  sw    $v0, 0x1c($sp)
/* 030D50 80055950 AFA00020 */  sw    $zero, 0x20($sp)
/* 030D54 80055954 0C0135F8 */  jal   func_8004D7E0
/* 030D58 80055958 AFA00024 */   sw    $zero, 0x24($sp)
/* 030D5C 8005595C AE000000 */  sw    $zero, ($s0)
/* 030D60 80055960 8FBF0034 */  lw    $ra, 0x34($sp)
/* 030D64 80055964 8FB00030 */  lw    $s0, 0x30($sp)
/* 030D68 80055968 03E00008 */  jr    $ra
/* 030D6C 8005596C 27BD0038 */   addiu $sp, $sp, 0x38

