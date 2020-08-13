.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel guPerspectiveF
/* 03EF90 80063B90 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 03EF94 80063B94 F7BA0038 */  sdc1  $f26, 0x38($sp)
/* 03EF98 80063B98 C7BA0060 */  lwc1  $f26, 0x60($sp)
/* 03EF9C 80063B9C F7BC0040 */  sdc1  $f28, 0x40($sp)
/* 03EFA0 80063BA0 C7BC0064 */  lwc1  $f28, 0x64($sp)
/* 03EFA4 80063BA4 F7BE0048 */  sdc1  $f30, 0x48($sp)
/* 03EFA8 80063BA8 C7BE0068 */  lwc1  $f30, 0x68($sp)
/* 03EFAC 80063BAC F7B80030 */  sdc1  $f24, 0x30($sp)
/* 03EFB0 80063BB0 4486C000 */  mtc1  $a2, $f24
/* 03EFB4 80063BB4 AFB00010 */  sw    $s0, 0x10($sp)
/* 03EFB8 80063BB8 00808021 */  addu  $s0, $a0, $zero
/* 03EFBC 80063BBC AFB10014 */  sw    $s1, 0x14($sp)
/* 03EFC0 80063BC0 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 03EFC4 80063BC4 4487B000 */  mtc1  $a3, $f22
/* 03EFC8 80063BC8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 03EFCC 80063BCC F7B40020 */  sdc1  $f20, 0x20($sp)
/* 03EFD0 80063BD0 0C019D28 */  jal   guMtxIdentF
/* 03EFD4 80063BD4 00A08821 */   addu  $s1, $a1, $zero
/* 03EFD8 80063BD8 3C01800A */  lui   $at, 0x800a
/* 03EFDC 80063BDC D4229BB0 */  ldc1  $f2, -0x6450($at)
/* 03EFE0 80063BE0 4600C021 */  cvt.d.s $f0, $f24
/* 03EFE4 80063BE4 46220002 */  mul.d $f0, $f0, $f2
/* 03EFE8 80063BE8 3C014000 */  lui   $at, 0x4000
/* 03EFEC 80063BEC 4481A000 */  mtc1  $at, $f20
/* 03EFF0 80063BF0 46200620 */  cvt.s.d $f24, $f0
/* 03EFF4 80063BF4 4614C503 */  div.s $f20, $f24, $f20
/* 03EFF8 80063BF8 0C00A874 */  jal   cos_rad
/* 03EFFC 80063BFC 4600A306 */   mov.s $f12, $f20
/* 03F000 80063C00 4600A306 */  mov.s $f12, $f20
/* 03F004 80063C04 0C00A85B */  jal   sin_rad
/* 03F008 80063C08 46000506 */   mov.s $f20, $f0
/* 03F00C 80063C0C 4600A503 */  div.s $f20, $f20, $f0
/* 03F010 80063C10 461CD100 */  add.s $f4, $f26, $f28
/* 03F014 80063C14 461CD081 */  sub.s $f2, $f26, $f28
/* 03F018 80063C18 46022103 */  div.s $f4, $f4, $f2
/* 03F01C 80063C1C 461AD000 */  add.s $f0, $f26, $f26
/* 03F020 80063C20 461C0002 */  mul.s $f0, $f0, $f28
/* 03F024 80063C24 46020003 */  div.s $f0, $f0, $f2
/* 03F028 80063C28 4616A583 */  div.s $f22, $f20, $f22
/* 03F02C 80063C2C 3C01BF80 */  lui   $at, 0xbf80
/* 03F030 80063C30 44811000 */  mtc1  $at, $f2
/* 03F034 80063C34 00002821 */  addu  $a1, $zero, $zero
/* 03F038 80063C38 AE00003C */  sw    $zero, 0x3c($s0)
/* 03F03C 80063C3C E602002C */  swc1  $f2, 0x2c($s0)
/* 03F040 80063C40 E6140014 */  swc1  $f20, 0x14($s0)
/* 03F044 80063C44 E6040028 */  swc1  $f4, 0x28($s0)
/* 03F048 80063C48 E6000038 */  swc1  $f0, 0x38($s0)
/* 03F04C 80063C4C E6160000 */  swc1  $f22, ($s0)
.L80063C50:
/* 03F050 80063C50 00002021 */  addu  $a0, $zero, $zero
/* 03F054 80063C54 02001821 */  addu  $v1, $s0, $zero
.L80063C58:
/* 03F058 80063C58 C4600000 */  lwc1  $f0, ($v1)
/* 03F05C 80063C5C 461E0002 */  mul.s $f0, $f0, $f30
/* 03F060 80063C60 24840001 */  addiu $a0, $a0, 1
/* 03F064 80063C64 28820004 */  slti  $v0, $a0, 4
/* 03F068 80063C68 E4600000 */  swc1  $f0, ($v1)
/* 03F06C 80063C6C 1440FFFA */  bnez  $v0, .L80063C58
/* 03F070 80063C70 24630004 */   addiu $v1, $v1, 4
/* 03F074 80063C74 24A50001 */  addiu $a1, $a1, 1
/* 03F078 80063C78 28A20004 */  slti  $v0, $a1, 4
/* 03F07C 80063C7C 1440FFF4 */  bnez  $v0, .L80063C50
/* 03F080 80063C80 26100010 */   addiu $s0, $s0, 0x10
/* 03F084 80063C84 12200023 */  beqz  $s1, .L80063D14
/* 03F088 80063C88 00000000 */   nop   
/* 03F08C 80063C8C 461CD080 */  add.s $f2, $f26, $f28
/* 03F090 80063C90 3C01800A */  lui   $at, 0x800a
/* 03F094 80063C94 D4209BB8 */  ldc1  $f0, -0x6448($at)
/* 03F098 80063C98 460010A1 */  cvt.d.s $f2, $f2
/* 03F09C 80063C9C 4620103E */  c.le.d $f2, $f0
/* 03F0A0 80063CA0 00000000 */  nop   
/* 03F0A4 80063CA4 00000000 */  nop   
/* 03F0A8 80063CA8 45010019 */  bc1t  .L80063D10
/* 03F0AC 80063CAC 3402FFFF */   ori   $v0, $zero, 0xffff
/* 03F0B0 80063CB0 3C01800A */  lui   $at, 0x800a
/* 03F0B4 80063CB4 D4209BC0 */  ldc1  $f0, -0x6440($at)
/* 03F0B8 80063CB8 46220083 */  div.d $f2, $f0, $f2
/* 03F0BC 80063CBC 3C01800A */  lui   $at, 0x800a
/* 03F0C0 80063CC0 D4209BC8 */  ldc1  $f0, -0x6438($at)
/* 03F0C4 80063CC4 4622003E */  c.le.d $f0, $f2
/* 03F0C8 80063CC8 00000000 */  nop   
/* 03F0CC 80063CCC 00000000 */  nop   
/* 03F0D0 80063CD0 45030006 */  bc1tl .L80063CEC
/* 03F0D4 80063CD4 46201001 */   sub.d $f0, $f2, $f0
/* 03F0D8 80063CD8 4620100D */  trunc.w.d $f0, $f2
/* 03F0DC 80063CDC 44030000 */  mfc1  $v1, $f0
/* 03F0E0 80063CE0 00000000 */  nop   
/* 03F0E4 80063CE4 08018F40 */  j     .L80063D00
/* 03F0E8 80063CE8 00601021 */   addu  $v0, $v1, $zero

.L80063CEC:
/* 03F0EC 80063CEC 4620008D */  trunc.w.d $f2, $f0
/* 03F0F0 80063CF0 44031000 */  mfc1  $v1, $f2
/* 03F0F4 80063CF4 3C028000 */  lui   $v0, 0x8000
/* 03F0F8 80063CF8 00621825 */  or    $v1, $v1, $v0
/* 03F0FC 80063CFC 00601021 */  addu  $v0, $v1, $zero
.L80063D00:
/* 03F100 80063D00 A6220000 */  sh    $v0, ($s1)
/* 03F104 80063D04 3042FFFF */  andi  $v0, $v0, 0xffff
/* 03F108 80063D08 14400002 */  bnez  $v0, .L80063D14
/* 03F10C 80063D0C 24020001 */   addiu $v0, $zero, 1
.L80063D10:
/* 03F110 80063D10 A6220000 */  sh    $v0, ($s1)
.L80063D14:
/* 03F114 80063D14 8FBF0018 */  lw    $ra, 0x18($sp)
/* 03F118 80063D18 8FB10014 */  lw    $s1, 0x14($sp)
/* 03F11C 80063D1C 8FB00010 */  lw    $s0, 0x10($sp)
/* 03F120 80063D20 D7BE0048 */  ldc1  $f30, 0x48($sp)
/* 03F124 80063D24 D7BC0040 */  ldc1  $f28, 0x40($sp)
/* 03F128 80063D28 D7BA0038 */  ldc1  $f26, 0x38($sp)
/* 03F12C 80063D2C D7B80030 */  ldc1  $f24, 0x30($sp)
/* 03F130 80063D30 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 03F134 80063D34 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 03F138 80063D38 03E00008 */  jr    $ra
/* 03F13C 80063D3C 27BD0050 */   addiu $sp, $sp, 0x50

