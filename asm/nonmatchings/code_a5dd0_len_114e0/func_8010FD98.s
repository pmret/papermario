.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8010FD98
/* 0A6498 8010FD98 00A0382D */  daddu $a3, $a1, $zero
/* 0A649C 8010FD9C 28E200FF */  slti  $v0, $a3, 0xff
/* 0A64A0 8010FDA0 14400016 */  bnez  $v0, .L8010FDFC
/* 0A64A4 8010FDA4 3C06FCFF */   lui   $a2, 0xfcff
/* 0A64A8 8010FDA8 3C07E200 */  lui   $a3, 0xe200
/* 0A64AC 8010FDAC 34E7001C */  ori   $a3, $a3, 0x1c
/* 0A64B0 8010FDB0 3C050055 */  lui   $a1, 0x55
/* 0A64B4 8010FDB4 34A52078 */  ori   $a1, $a1, 0x2078
/* 0A64B8 8010FDB8 3C08FC12 */  lui   $t0, 0xfc12
/* 0A64BC 8010FDBC 35081824 */  ori   $t0, $t0, 0x1824
/* 0A64C0 8010FDC0 3C06FF33 */  lui   $a2, 0xff33
/* 0A64C4 8010FDC4 3C04800A */  lui   $a0, 0x800a
/* 0A64C8 8010FDC8 2484A66C */  addiu $a0, $a0, -0x5994
/* 0A64CC 8010FDCC 8C820000 */  lw    $v0, ($a0)
/* 0A64D0 8010FDD0 34C6FFFF */  ori   $a2, $a2, 0xffff
/* 0A64D4 8010FDD4 0040182D */  daddu $v1, $v0, $zero
/* 0A64D8 8010FDD8 24420008 */  addiu $v0, $v0, 8
/* 0A64DC 8010FDDC AC820000 */  sw    $v0, ($a0)
/* 0A64E0 8010FDE0 AC670000 */  sw    $a3, ($v1)
/* 0A64E4 8010FDE4 AC650004 */  sw    $a1, 4($v1)
/* 0A64E8 8010FDE8 24430008 */  addiu $v1, $v0, 8
/* 0A64EC 8010FDEC AC830000 */  sw    $v1, ($a0)
/* 0A64F0 8010FDF0 AC480000 */  sw    $t0, ($v0)
/* 0A64F4 8010FDF4 03E00008 */  jr    $ra
/* 0A64F8 8010FDF8 AC460004 */   sw    $a2, 4($v0)

.L8010FDFC:
/* 0A64FC 8010FDFC 34C6B3FF */  ori   $a2, $a2, 0xb3ff
/* 0A6500 8010FE00 3C05FF2C */  lui   $a1, 0xff2c
/* 0A6504 8010FE04 3C04800A */  lui   $a0, 0x800a
/* 0A6508 8010FE08 2484A66C */  addiu $a0, $a0, -0x5994
/* 0A650C 8010FE0C 8C820000 */  lw    $v0, ($a0)
/* 0A6510 8010FE10 34A5FE7F */  ori   $a1, $a1, 0xfe7f
/* 0A6514 8010FE14 0040182D */  daddu $v1, $v0, $zero
/* 0A6518 8010FE18 24420008 */  addiu $v0, $v0, 8
/* 0A651C 8010FE1C AC820000 */  sw    $v0, ($a0)
/* 0A6520 8010FE20 AC660000 */  sw    $a2, ($v1)
/* 0A6524 8010FE24 AC650004 */  sw    $a1, 4($v1)
/* 0A6528 8010FE28 24430008 */  addiu $v1, $v0, 8
/* 0A652C 8010FE2C AC830000 */  sw    $v1, ($a0)
/* 0A6530 8010FE30 3C03FA00 */  lui   $v1, 0xfa00
/* 0A6534 8010FE34 AC430000 */  sw    $v1, ($v0)
/* 0A6538 8010FE38 30E300FF */  andi  $v1, $a3, 0xff
/* 0A653C 8010FE3C 03E00008 */  jr    $ra
/* 0A6540 8010FE40 AC430004 */   sw    $v1, 4($v0)

/* 0A6544 8010FE44 3C058015 */  lui   $a1, 0x8015
/* 0A6548 8010FE48 8CA5AFB0 */  lw    $a1, -0x5050($a1)
/* 0A654C 8010FE4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A6550 8010FE50 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0A6554 8010FE54 0C043F66 */  jal   func_8010FD98
/* 0A6558 8010FE58 00000000 */   nop   
/* 0A655C 8010FE5C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0A6560 8010FE60 03E00008 */  jr    $ra
/* 0A6564 8010FE64 27BD0018 */   addiu $sp, $sp, 0x18

/* 0A6568 8010FE68 3C07FCFF */  lui   $a3, 0xfcff
/* 0A656C 8010FE6C 34E7B3FF */  ori   $a3, $a3, 0xb3ff
/* 0A6570 8010FE70 3C06FF2F */  lui   $a2, 0xff2f
/* 0A6574 8010FE74 3C05800A */  lui   $a1, 0x800a
/* 0A6578 8010FE78 24A5A66C */  addiu $a1, $a1, -0x5994
/* 0A657C 8010FE7C 34C6FFFF */  ori   $a2, $a2, 0xffff
/* 0A6580 8010FE80 8CA20000 */  lw    $v0, ($a1)
/* 0A6584 8010FE84 308400FF */  andi  $a0, $a0, 0xff
/* 0A6588 8010FE88 0040182D */  daddu $v1, $v0, $zero
/* 0A658C 8010FE8C 24420008 */  addiu $v0, $v0, 8
/* 0A6590 8010FE90 ACA20000 */  sw    $v0, ($a1)
/* 0A6594 8010FE94 AC670000 */  sw    $a3, ($v1)
/* 0A6598 8010FE98 AC660004 */  sw    $a2, 4($v1)
/* 0A659C 8010FE9C 24430008 */  addiu $v1, $v0, 8
/* 0A65A0 8010FEA0 ACA30000 */  sw    $v1, ($a1)
/* 0A65A4 8010FEA4 3C03FA00 */  lui   $v1, 0xfa00
/* 0A65A8 8010FEA8 AC430000 */  sw    $v1, ($v0)
/* 0A65AC 8010FEAC 03E00008 */  jr    $ra
/* 0A65B0 8010FEB0 AC440004 */   sw    $a0, 4($v0)

