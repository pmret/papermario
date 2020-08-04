.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80055BB8
/* 030FB8 80055BB8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 030FBC 80055BBC 24020001 */  addiu $v0, $zero, 1
/* 030FC0 80055BC0 AFA40010 */  sw    $a0, 0x10($sp)
/* 030FC4 80055BC4 27A40010 */  addiu $a0, $sp, 0x10
/* 030FC8 80055BC8 AFBF0030 */  sw    $ra, 0x30($sp)
/* 030FCC 80055BCC AFA50014 */  sw    $a1, 0x14($sp)
/* 030FD0 80055BD0 AFA00018 */  sw    $zero, 0x18($sp)
/* 030FD4 80055BD4 AFA0001C */  sw    $zero, 0x1c($sp)
/* 030FD8 80055BD8 AFA00020 */  sw    $zero, 0x20($sp)
/* 030FDC 80055BDC 0C0136D3 */  jal   func_8004DB4C
/* 030FE0 80055BE0 AFA20024 */   sw    $v0, 0x24($sp)
/* 030FE4 80055BE4 8FBF0030 */  lw    $ra, 0x30($sp)
/* 030FE8 80055BE8 03E00008 */  jr    $ra
/* 030FEC 80055BEC 27BD0038 */   addiu $sp, $sp, 0x38

/* 030FF0 80055BF0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 030FF4 80055BF4 24020001 */  addiu $v0, $zero, 1
/* 030FF8 80055BF8 AFA40010 */  sw    $a0, 0x10($sp)
/* 030FFC 80055BFC 27A40010 */  addiu $a0, $sp, 0x10
/* 031000 80055C00 0000282D */  daddu $a1, $zero, $zero
/* 031004 80055C04 AFBF0030 */  sw    $ra, 0x30($sp)
/* 031008 80055C08 AFA00014 */  sw    $zero, 0x14($sp)
/* 03100C 80055C0C AFA00018 */  sw    $zero, 0x18($sp)
/* 031010 80055C10 AFA0001C */  sw    $zero, 0x1c($sp)
/* 031014 80055C14 AFA00020 */  sw    $zero, 0x20($sp)
/* 031018 80055C18 0C01372E */  jal   func_8004DCB8
/* 03101C 80055C1C AFA20024 */   sw    $v0, 0x24($sp)
/* 031020 80055C20 8FBF0030 */  lw    $ra, 0x30($sp)
/* 031024 80055C24 03E00008 */  jr    $ra
/* 031028 80055C28 27BD0038 */   addiu $sp, $sp, 0x38

/* 03102C 80055C2C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 031030 80055C30 24020001 */  addiu $v0, $zero, 1
/* 031034 80055C34 AFA40010 */  sw    $a0, 0x10($sp)
/* 031038 80055C38 27A40010 */  addiu $a0, $sp, 0x10
/* 03103C 80055C3C AFBF0030 */  sw    $ra, 0x30($sp)
/* 031040 80055C40 AFA00014 */  sw    $zero, 0x14($sp)
/* 031044 80055C44 AFA00018 */  sw    $zero, 0x18($sp)
/* 031048 80055C48 AFA0001C */  sw    $zero, 0x1c($sp)
/* 03104C 80055C4C AFA00020 */  sw    $zero, 0x20($sp)
/* 031050 80055C50 0C01378B */  jal   func_8004DE2C
/* 031054 80055C54 AFA20024 */   sw    $v0, 0x24($sp)
/* 031058 80055C58 8FBF0030 */  lw    $ra, 0x30($sp)
/* 03105C 80055C5C 03E00008 */  jr    $ra
/* 031060 80055C60 27BD0038 */   addiu $sp, $sp, 0x38

/* 031064 80055C64 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 031068 80055C68 240201F4 */  addiu $v0, $zero, 0x1f4
/* 03106C 80055C6C AFA20014 */  sw    $v0, 0x14($sp)
/* 031070 80055C70 24022000 */  addiu $v0, $zero, 0x2000
/* 031074 80055C74 AFA40010 */  sw    $a0, 0x10($sp)
/* 031078 80055C78 27A40010 */  addiu $a0, $sp, 0x10
/* 03107C 80055C7C AFBF0030 */  sw    $ra, 0x30($sp)
/* 031080 80055C80 0C01383D */  jal   func_8004E0F4
/* 031084 80055C84 AFA2001C */   sw    $v0, 0x1c($sp)
/* 031088 80055C88 8FBF0030 */  lw    $ra, 0x30($sp)
/* 03108C 80055C8C 03E00008 */  jr    $ra
/* 031090 80055C90 27BD0038 */   addiu $sp, $sp, 0x38

/* 031094 80055C94 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 031098 80055C98 240201F4 */  addiu $v0, $zero, 0x1f4
/* 03109C 80055C9C AFA20014 */  sw    $v0, 0x14($sp)
/* 0310A0 80055CA0 24027FFF */  addiu $v0, $zero, 0x7fff
/* 0310A4 80055CA4 AFA40010 */  sw    $a0, 0x10($sp)
/* 0310A8 80055CA8 27A40010 */  addiu $a0, $sp, 0x10
/* 0310AC 80055CAC AFBF0030 */  sw    $ra, 0x30($sp)
/* 0310B0 80055CB0 0C01383D */  jal   func_8004E0F4
/* 0310B4 80055CB4 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0310B8 80055CB8 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0310BC 80055CBC 03E00008 */  jr    $ra
/* 0310C0 80055CC0 27BD0038 */   addiu $sp, $sp, 0x38

