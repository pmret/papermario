.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024C298
.L8024C298:
/* 13F5D8 8024C298 3C028027 */  lui   $v0, 0x8027
/* 13F5DC 8024C29C 8C4206A0 */  lw    $v0, 0x6a0($v0)
/* 13F5E0 8024C2A0 00021840 */  sll   $v1, $v0, 1
/* 13F5E4 8024C2A4 00621821 */  addu  $v1, $v1, $v0
/* 13F5E8 8024C2A8 00031100 */  sll   $v0, $v1, 4
/* 13F5EC 8024C2AC 00431023 */  subu  $v0, $v0, $v1
/* 13F5F0 8024C2B0 3C038027 */  lui   $v1, 0x8027
/* 13F5F4 8024C2B4 8C6306B0 */  lw    $v1, 0x6b0($v1)
/* 13F5F8 8024C2B8 000210C0 */  sll   $v0, $v0, 3
/* 13F5FC 8024C2BC 14600002 */  bnez  $v1, .L8024C2C8
/* 13F600 8024C2C0 0043001A */   div   $zero, $v0, $v1
/* 13F604 8024C2C4 0007000D */  break 7
.L8024C2C8:
/* 13F608 8024C2C8 2401FFFF */  addiu $at, $zero, -1
/* 13F60C 8024C2CC 14610004 */  bne   $v1, $at, .L8024C2E0
/* 13F610 8024C2D0 3C018000 */   lui   $at, 0x8000
/* 13F614 8024C2D4 14410002 */  bne   $v0, $at, .L8024C2E0
/* 13F618 8024C2D8 00000000 */   nop   
/* 13F61C 8024C2DC 0006000D */  break 6
.L8024C2E0:
/* 13F620 8024C2E0 00001012 */  mflo  $v0
/* 13F624 8024C2E4 3C018027 */  lui   $at, 0x8027
/* 13F628 8024C2E8 AC2006A4 */  sw    $zero, 0x6a4($at)
/* 13F62C 8024C2EC 3C018027 */  lui   $at, 0x8027
/* 13F630 8024C2F0 AC2006AC */  sw    $zero, 0x6ac($at)
/* 13F634 8024C2F4 44820000 */  mtc1  $v0, $f0
/* 13F638 8024C2F8 00000000 */  nop   
/* 13F63C 8024C2FC 46800020 */  cvt.s.w $f0, $f0
/* 13F640 8024C300 3C018027 */  lui   $at, 0x8027
/* 13F644 8024C304 E42006A8 */  swc1  $f0, 0x6a8($at)
/* 13F648 8024C308 0C092B78 */  jal   func_8024ADE0
/* 13F64C 8024C30C 0000202D */   daddu $a0, $zero, $zero
/* 13F650 8024C310 24020001 */  addiu $v0, $zero, 1
/* 13F654 8024C314 A2820000 */  sb    $v0, ($s4)
