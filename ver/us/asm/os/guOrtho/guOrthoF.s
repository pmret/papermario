.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel guOrthoF
/* 3ED10 80063910 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3ED14 80063914 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 3ED18 80063918 C7B80060 */  lwc1      $f24, 0x60($sp)
/* 3ED1C 8006391C F7BE0048 */  sdc1      $f30, 0x48($sp)
/* 3ED20 80063920 C7BE0064 */  lwc1      $f30, 0x64($sp)
/* 3ED24 80063924 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 3ED28 80063928 C7B60068 */  lwc1      $f22, 0x68($sp)
/* 3ED2C 8006392C AFB10014 */  sw        $s1, 0x14($sp)
/* 3ED30 80063930 8FB1006C */  lw        $s1, 0x6c($sp)
/* 3ED34 80063934 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* 3ED38 80063938 4485D000 */  mtc1      $a1, $f26
/* 3ED3C 8006393C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 3ED40 80063940 4486A000 */  mtc1      $a2, $f20
/* 3ED44 80063944 AFB00010 */  sw        $s0, 0x10($sp)
/* 3ED48 80063948 F7BC0040 */  sdc1      $f28, 0x40($sp)
/* 3ED4C 8006394C 4487E000 */  mtc1      $a3, $f28
/* 3ED50 80063950 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3ED54 80063954 0C019D28 */  jal       guMtxIdentF
/* 3ED58 80063958 00808021 */   addu     $s0, $a0, $zero
/* 3ED5C 8006395C 461AA001 */  sub.s     $f0, $f20, $f26
/* 3ED60 80063960 3C014000 */  lui       $at, 0x4000
/* 3ED64 80063964 44811000 */  mtc1      $at, $f2
/* 3ED68 80063968 00000000 */  nop
/* 3ED6C 8006396C 46001283 */  div.s     $f10, $f2, $f0
/* 3ED70 80063970 461CC181 */  sub.s     $f6, $f24, $f28
/* 3ED74 80063974 46061083 */  div.s     $f2, $f2, $f6
/* 3ED78 80063978 461EB201 */  sub.s     $f8, $f22, $f30
/* 3ED7C 8006397C 3C01C000 */  lui       $at, 0xc000
/* 3ED80 80063980 44812000 */  mtc1      $at, $f4
/* 3ED84 80063984 00000000 */  nop
/* 3ED88 80063988 46082103 */  div.s     $f4, $f4, $f8
/* 3ED8C 8006398C 461AA500 */  add.s     $f20, $f20, $f26
/* 3ED90 80063990 4600A507 */  neg.s     $f20, $f20
/* 3ED94 80063994 4600A503 */  div.s     $f20, $f20, $f0
/* 3ED98 80063998 461CC600 */  add.s     $f24, $f24, $f28
/* 3ED9C 8006399C 4600C607 */  neg.s     $f24, $f24
/* 3EDA0 800639A0 4606C603 */  div.s     $f24, $f24, $f6
/* 3EDA4 800639A4 461EB580 */  add.s     $f22, $f22, $f30
/* 3EDA8 800639A8 4600B587 */  neg.s     $f22, $f22
/* 3EDAC 800639AC 4608B583 */  div.s     $f22, $f22, $f8
/* 3EDB0 800639B0 3C013F80 */  lui       $at, 0x3f80
/* 3EDB4 800639B4 44810000 */  mtc1      $at, $f0
/* 3EDB8 800639B8 00002821 */  addu      $a1, $zero, $zero
/* 3EDBC 800639BC E600003C */  swc1      $f0, 0x3c($s0)
/* 3EDC0 800639C0 E60A0000 */  swc1      $f10, ($s0)
/* 3EDC4 800639C4 E6140030 */  swc1      $f20, 0x30($s0)
/* 3EDC8 800639C8 E6020014 */  swc1      $f2, 0x14($s0)
/* 3EDCC 800639CC E6040028 */  swc1      $f4, 0x28($s0)
/* 3EDD0 800639D0 E6180034 */  swc1      $f24, 0x34($s0)
/* 3EDD4 800639D4 E6160038 */  swc1      $f22, 0x38($s0)
.L800639D8:
/* 3EDD8 800639D8 00002021 */  addu      $a0, $zero, $zero
/* 3EDDC 800639DC 02001821 */  addu      $v1, $s0, $zero
.L800639E0:
/* 3EDE0 800639E0 C4600000 */  lwc1      $f0, ($v1)
/* 3EDE4 800639E4 44916000 */  mtc1      $s1, $f12
/* 3EDE8 800639E8 00000000 */  nop
/* 3EDEC 800639EC 460C0002 */  mul.s     $f0, $f0, $f12
/* 3EDF0 800639F0 24840001 */  addiu     $a0, $a0, 1
/* 3EDF4 800639F4 28820004 */  slti      $v0, $a0, 4
/* 3EDF8 800639F8 E4600000 */  swc1      $f0, ($v1)
/* 3EDFC 800639FC 1440FFF8 */  bnez      $v0, .L800639E0
/* 3EE00 80063A00 24630004 */   addiu    $v1, $v1, 4
/* 3EE04 80063A04 24A50001 */  addiu     $a1, $a1, 1
/* 3EE08 80063A08 28A20004 */  slti      $v0, $a1, 4
/* 3EE0C 80063A0C 1440FFF2 */  bnez      $v0, .L800639D8
/* 3EE10 80063A10 26100010 */   addiu    $s0, $s0, 0x10
/* 3EE14 80063A14 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3EE18 80063A18 8FB10014 */  lw        $s1, 0x14($sp)
/* 3EE1C 80063A1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3EE20 80063A20 D7BE0048 */  ldc1      $f30, 0x48($sp)
/* 3EE24 80063A24 D7BC0040 */  ldc1      $f28, 0x40($sp)
/* 3EE28 80063A28 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* 3EE2C 80063A2C D7B80030 */  ldc1      $f24, 0x30($sp)
/* 3EE30 80063A30 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 3EE34 80063A34 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 3EE38 80063A38 03E00008 */  jr        $ra
/* 3EE3C 80063A3C 27BD0050 */   addiu    $sp, $sp, 0x50
