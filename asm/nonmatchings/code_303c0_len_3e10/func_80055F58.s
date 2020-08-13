.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80055F58
/* 031358 80055F58 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 03135C 80055F5C AFB00018 */  sw    $s0, 0x18($sp)
/* 031360 80055F60 00A0802D */  daddu $s0, $a1, $zero
/* 031364 80055F64 AFB1001C */  sw    $s1, 0x1c($sp)
/* 031368 80055F68 00C0882D */  daddu $s1, $a2, $zero
/* 03136C 80055F6C 27A50010 */  addiu $a1, $sp, 0x10
/* 031370 80055F70 27A60014 */  addiu $a2, $sp, 0x14
/* 031374 80055F74 AFBF0024 */  sw    $ra, 0x24($sp)
/* 031378 80055F78 0C01573A */  jal   func_80055CE8
/* 03137C 80055F7C AFB20020 */   sw    $s2, 0x20($sp)
/* 031380 80055F80 0040902D */  daddu $s2, $v0, $zero
/* 031384 80055F84 1640000D */  bnez  $s2, .L80055FBC
/* 031388 80055F88 0240102D */   daddu $v0, $s2, $zero
/* 03138C 80055F8C 2E220080 */  sltiu $v0, $s1, 0x80
/* 031390 80055F90 50400001 */  beql  $v0, $zero, .L80055F98
/* 031394 80055F94 2411007F */   addiu $s1, $zero, 0x7f
.L80055F98:
/* 031398 80055F98 2E020010 */  sltiu $v0, $s0, 0x10
/* 03139C 80055F9C 50400001 */  beql  $v0, $zero, .L80055FA4
/* 0313A0 80055FA0 2410000F */   addiu $s0, $zero, 0xf
.L80055FA4:
/* 0313A4 80055FA4 8FA40014 */  lw    $a0, 0x14($sp)
/* 0313A8 80055FA8 0200282D */  daddu $a1, $s0, $zero
/* 0313AC 80055FAC 24060060 */  addiu $a2, $zero, 0x60
/* 0313B0 80055FB0 0C01420F */  jal   func_8005083C
/* 0313B4 80055FB4 322700FF */   andi  $a3, $s1, 0xff
/* 0313B8 80055FB8 0240102D */  daddu $v0, $s2, $zero
.L80055FBC:
/* 0313BC 80055FBC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0313C0 80055FC0 8FB20020 */  lw    $s2, 0x20($sp)
/* 0313C4 80055FC4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0313C8 80055FC8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0313CC 80055FCC 03E00008 */  jr    $ra
/* 0313D0 80055FD0 27BD0028 */   addiu $sp, $sp, 0x28

/* 0313D4 80055FD4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0313D8 80055FD8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0313DC 80055FDC 0C0157D6 */  jal   func_80055F58
/* 0313E0 80055FE0 0000302D */   daddu $a2, $zero, $zero
/* 0313E4 80055FE4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0313E8 80055FE8 03E00008 */  jr    $ra
/* 0313EC 80055FEC 27BD0018 */   addiu $sp, $sp, 0x18

/* 0313F0 80055FF0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0313F4 80055FF4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0313F8 80055FF8 0C0157D6 */  jal   func_80055F58
/* 0313FC 80055FFC 2406003F */   addiu $a2, $zero, 0x3f
/* 031400 80056000 8FBF0010 */  lw    $ra, 0x10($sp)
/* 031404 80056004 03E00008 */  jr    $ra
/* 031408 80056008 27BD0018 */   addiu $sp, $sp, 0x18

/* 03140C 8005600C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 031410 80056010 AFBF0010 */  sw    $ra, 0x10($sp)
/* 031414 80056014 0C0157D6 */  jal   func_80055F58
/* 031418 80056018 2406007F */   addiu $a2, $zero, 0x7f
/* 03141C 8005601C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 031420 80056020 03E00008 */  jr    $ra
/* 031424 80056024 27BD0018 */   addiu $sp, $sp, 0x18

