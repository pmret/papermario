.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetModelCenter
/* 0ED930 802C8F80 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0ED934 802C8F84 AFB00038 */  sw    $s0, 0x38($sp)
/* 0ED938 802C8F88 0080802D */  daddu $s0, $a0, $zero
/* 0ED93C 802C8F8C AFBF003C */  sw    $ra, 0x3c($sp)
/* 0ED940 802C8F90 8E02000C */  lw    $v0, 0xc($s0)
/* 0ED944 802C8F94 0C0B1EAF */  jal   get_variable
/* 0ED948 802C8F98 8C450000 */   lw    $a1, ($v0)
/* 0ED94C 802C8F9C 3044FFFF */  andi  $a0, $v0, 0xffff
/* 0ED950 802C8FA0 27A50020 */  addiu $a1, $sp, 0x20
/* 0ED954 802C8FA4 27A2002C */  addiu $v0, $sp, 0x2c
/* 0ED958 802C8FA8 AFA20010 */  sw    $v0, 0x10($sp)
/* 0ED95C 802C8FAC 27A20030 */  addiu $v0, $sp, 0x30
/* 0ED960 802C8FB0 AFA20014 */  sw    $v0, 0x14($sp)
/* 0ED964 802C8FB4 27A20034 */  addiu $v0, $sp, 0x34
/* 0ED968 802C8FB8 27A60024 */  addiu $a2, $sp, 0x24
/* 0ED96C 802C8FBC 27A70028 */  addiu $a3, $sp, 0x28
/* 0ED970 802C8FC0 0C046C3B */  jal   get_model_center_and_size
/* 0ED974 802C8FC4 AFA20018 */   sw    $v0, 0x18($sp)
/* 0ED978 802C8FC8 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0ED97C 802C8FCC 4600010D */  trunc.w.s $f4, $f0
/* 0ED980 802C8FD0 E6040084 */  swc1  $f4, 0x84($s0)
/* 0ED984 802C8FD4 C7A00024 */  lwc1  $f0, 0x24($sp)
/* 0ED988 802C8FD8 C7A20028 */  lwc1  $f2, 0x28($sp)
/* 0ED98C 802C8FDC 4600010D */  trunc.w.s $f4, $f0
/* 0ED990 802C8FE0 E6040088 */  swc1  $f4, 0x88($s0)
/* 0ED994 802C8FE4 4600110D */  trunc.w.s $f4, $f2
/* 0ED998 802C8FE8 E604008C */  swc1  $f4, 0x8c($s0)
/* 0ED99C 802C8FEC 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0ED9A0 802C8FF0 8FB00038 */  lw    $s0, 0x38($sp)
/* 0ED9A4 802C8FF4 24020002 */  addiu $v0, $zero, 2
/* 0ED9A8 802C8FF8 03E00008 */  jr    $ra
/* 0ED9AC 802C8FFC 27BD0040 */   addiu $sp, $sp, 0x40

