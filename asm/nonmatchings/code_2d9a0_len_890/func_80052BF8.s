.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80052BF8
/* 02DFF8 80052BF8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 02DFFC 80052BFC AFB00010 */  sw    $s0, 0x10($sp)
/* 02E000 80052C00 0080802D */  daddu $s0, $a0, $zero
/* 02E004 80052C04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 02E008 80052C08 8CA20000 */  lw    $v0, ($a1)
/* 02E00C 80052C0C AE020014 */  sw    $v0, 0x14($s0)
/* 02E010 80052C10 AE02001C */  sw    $v0, 0x1c($s0)
/* 02E014 80052C14 8CA30004 */  lw    $v1, 4($a1)
/* 02E018 80052C18 24020080 */  addiu $v0, $zero, 0x80
/* 02E01C 80052C1C AE020030 */  sw    $v0, 0x30($s0)
/* 02E020 80052C20 AE000034 */  sw    $zero, 0x34($s0)
/* 02E024 80052C24 0C014B3F */  jal   func_80052CFC
/* 02E028 80052C28 AE030018 */   sw    $v1, 0x18($s0)
/* 02E02C 80052C2C 8E03001C */  lw    $v1, 0x1c($s0)
/* 02E030 80052C30 A200003D */  sb    $zero, 0x3d($s0)
/* 02E034 80052C34 A2000039 */  sb    $zero, 0x39($s0)
/* 02E038 80052C38 90640000 */  lbu   $a0, ($v1)
/* 02E03C 80052C3C 24630001 */  addiu $v1, $v1, 1
/* 02E040 80052C40 AE03001C */  sw    $v1, 0x1c($s0)
/* 02E044 80052C44 86030040 */  lh    $v1, 0x40($s0)
/* 02E048 80052C48 A204003A */  sb    $a0, 0x3a($s0)
/* 02E04C 80052C4C 308400FF */  andi  $a0, $a0, 0xff
/* 02E050 80052C50 00830018 */  mult  $a0, $v1
/* 02E054 80052C54 304200FF */  andi  $v0, $v0, 0xff
/* 02E058 80052C58 A202003B */  sb    $v0, 0x3b($s0)
/* 02E05C 80052C5C 00021080 */  sll   $v0, $v0, 2
/* 02E060 80052C60 00003012 */  mflo  $a2
/* 02E064 80052C64 8E030030 */  lw    $v1, 0x30($s0)
/* 02E068 80052C68 3C018008 */  lui   $at, 0x8008
/* 02E06C 80052C6C 00220821 */  addu  $at, $at, $v0
/* 02E070 80052C70 8C2285A0 */  lw    $v0, -0x7a60($at)
/* 02E074 80052C74 00C30018 */  mult  $a2, $v1
/* 02E078 80052C78 AE020024 */  sw    $v0, 0x24($s0)
/* 02E07C 80052C7C 0040202D */  daddu $a0, $v0, $zero
/* 02E080 80052C80 AE020028 */  sw    $v0, 0x28($s0)
/* 02E084 80052C84 00003012 */  mflo  $a2
/* 02E088 80052C88 00061383 */  sra   $v0, $a2, 0xe
/* 02E08C 80052C8C 0C014AF0 */  jal   func_80052BC0
/* 02E090 80052C90 A602000C */   sh    $v0, 0xc($s0)
/* 02E094 80052C94 8E040024 */  lw    $a0, 0x24($s0)
/* 02E098 80052C98 10800010 */  beqz  $a0, .L80052CDC
/* 02E09C 80052C9C AE020008 */   sw    $v0, 8($s0)
/* 02E0A0 80052CA0 9202003A */  lbu   $v0, 0x3a($s0)
/* 02E0A4 80052CA4 92030039 */  lbu   $v1, 0x39($s0)
/* 02E0A8 80052CA8 44820000 */  mtc1  $v0, $f0
/* 02E0AC 80052CAC 00000000 */  nop   
/* 02E0B0 80052CB0 46800020 */  cvt.s.w $f0, $f0
/* 02E0B4 80052CB4 44831000 */  mtc1  $v1, $f2
/* 02E0B8 80052CB8 00000000 */  nop   
/* 02E0BC 80052CBC 468010A0 */  cvt.s.w $f2, $f2
/* 02E0C0 80052CC0 46020001 */  sub.s $f0, $f0, $f2
/* 02E0C4 80052CC4 44841000 */  mtc1  $a0, $f2
/* 02E0C8 80052CC8 00000000 */  nop   
/* 02E0CC 80052CCC 468010A0 */  cvt.s.w $f2, $f2
/* 02E0D0 80052CD0 46020003 */  div.s $f0, $f0, $f2
/* 02E0D4 80052CD4 08014B38 */  j     .L80052CE0
/* 02E0D8 80052CD8 E600002C */   swc1  $f0, 0x2c($s0)

.L80052CDC:
/* 02E0DC 80052CDC AE00002C */  sw    $zero, 0x2c($s0)
.L80052CE0:
/* 02E0E0 80052CE0 24020080 */  addiu $v0, $zero, 0x80
/* 02E0E4 80052CE4 A200003E */  sb    $zero, 0x3e($s0)
/* 02E0E8 80052CE8 A202003F */  sb    $v0, 0x3f($s0)
/* 02E0EC 80052CEC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 02E0F0 80052CF0 8FB00010 */  lw    $s0, 0x10($sp)
/* 02E0F4 80052CF4 03E00008 */  jr    $ra
/* 02E0F8 80052CF8 27BD0018 */   addiu $sp, $sp, 0x18

