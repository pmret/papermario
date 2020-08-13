.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80055A18
/* 030E18 80055A18 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 030E1C 80055A1C AFB00030 */  sw    $s0, 0x30($sp)
/* 030E20 80055A20 3C108008 */  lui   $s0, 0x8008
/* 030E24 80055A24 26108DB0 */  addiu $s0, $s0, -0x7250
/* 030E28 80055A28 8FA30048 */  lw    $v1, 0x48($sp)
/* 030E2C 80055A2C 24020001 */  addiu $v0, $zero, 1
/* 030E30 80055A30 AFBF0034 */  sw    $ra, 0x34($sp)
/* 030E34 80055A34 AE020000 */  sw    $v0, ($s0)
/* 030E38 80055A38 AFA40010 */  sw    $a0, 0x10($sp)
/* 030E3C 80055A3C 27A40010 */  addiu $a0, $sp, 0x10
/* 030E40 80055A40 AFA60014 */  sw    $a2, 0x14($sp)
/* 030E44 80055A44 AFA70018 */  sw    $a3, 0x18($sp)
/* 030E48 80055A48 AFA50020 */  sw    $a1, 0x20($sp)
/* 030E4C 80055A4C AFA00024 */  sw    $zero, 0x24($sp)
/* 030E50 80055A50 0C0135F8 */  jal   func_8004D7E0
/* 030E54 80055A54 AFA3001C */   sw    $v1, 0x1c($sp)
/* 030E58 80055A58 AE000000 */  sw    $zero, ($s0)
/* 030E5C 80055A5C 8FBF0034 */  lw    $ra, 0x34($sp)
/* 030E60 80055A60 8FB00030 */  lw    $s0, 0x30($sp)
/* 030E64 80055A64 03E00008 */  jr    $ra
/* 030E68 80055A68 27BD0038 */   addiu $sp, $sp, 0x38

/* 030E6C 80055A6C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 030E70 80055A70 AFB00030 */  sw    $s0, 0x30($sp)
/* 030E74 80055A74 3C108008 */  lui   $s0, 0x8008
/* 030E78 80055A78 26108DB0 */  addiu $s0, $s0, -0x7250
/* 030E7C 80055A7C 24020001 */  addiu $v0, $zero, 1
/* 030E80 80055A80 AFBF0034 */  sw    $ra, 0x34($sp)
/* 030E84 80055A84 AE020000 */  sw    $v0, ($s0)
/* 030E88 80055A88 AFA40010 */  sw    $a0, 0x10($sp)
/* 030E8C 80055A8C 27A40010 */  addiu $a0, $sp, 0x10
/* 030E90 80055A90 AFA50014 */  sw    $a1, 0x14($sp)
/* 030E94 80055A94 AFA60018 */  sw    $a2, 0x18($sp)
/* 030E98 80055A98 AFA7001C */  sw    $a3, 0x1c($sp)
/* 030E9C 80055A9C AFA00020 */  sw    $zero, 0x20($sp)
/* 030EA0 80055AA0 0C0135F8 */  jal   func_8004D7E0
/* 030EA4 80055AA4 AFA00024 */   sw    $zero, 0x24($sp)
/* 030EA8 80055AA8 AE000000 */  sw    $zero, ($s0)
/* 030EAC 80055AAC 8FBF0034 */  lw    $ra, 0x34($sp)
/* 030EB0 80055AB0 8FB00030 */  lw    $s0, 0x30($sp)
/* 030EB4 80055AB4 03E00008 */  jr    $ra
/* 030EB8 80055AB8 27BD0038 */   addiu $sp, $sp, 0x38

