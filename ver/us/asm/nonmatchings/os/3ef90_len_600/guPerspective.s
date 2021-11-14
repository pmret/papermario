.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80099BD0
.double 0.017453292222222222

dlabel D_80099BD8
.double 2.0

dlabel D_80099BE0
.double 131072.0

dlabel D_80099BE8
.double 2147483648.0

.section .text

glabel guPerspective
/* 3F140 80063D40 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 3F144 80063D44 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 3F148 80063D48 C7B80098 */  lwc1      $f24, 0x98($sp)
/* 3F14C 80063D4C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 3F150 80063D50 C7BA009C */  lwc1      $f26, 0x9c($sp)
/* 3F154 80063D54 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 3F158 80063D58 C7BC00A0 */  lwc1      $f28, 0xa0($sp)
/* 3F15C 80063D5C F7B40060 */  sdc1      $f20, 0x60($sp)
/* 3F160 80063D60 4486A000 */  mtc1      $a2, $f20
/* 3F164 80063D64 AFB20058 */  sw        $s2, 0x58($sp)
/* 3F168 80063D68 00809021 */  addu      $s2, $a0, $zero
/* 3F16C 80063D6C AFB10054 */  sw        $s1, 0x54($sp)
/* 3F170 80063D70 00A08821 */  addu      $s1, $a1, $zero
/* 3F174 80063D74 AFB00050 */  sw        $s0, 0x50($sp)
/* 3F178 80063D78 27B00010 */  addiu     $s0, $sp, 0x10
/* 3F17C 80063D7C F7B60068 */  sdc1      $f22, 0x68($sp)
/* 3F180 80063D80 4487B000 */  mtc1      $a3, $f22
/* 3F184 80063D84 AFBF005C */  sw        $ra, 0x5c($sp)
/* 3F188 80063D88 0C019D28 */  jal       guMtxIdentF
/* 3F18C 80063D8C 02002021 */   addu     $a0, $s0, $zero
/* 3F190 80063D90 3C01800A */  lui       $at, %hi(D_80099BD0)
/* 3F194 80063D94 D4209BD0 */  ldc1      $f0, %lo(D_80099BD0)($at)
/* 3F198 80063D98 4600A521 */  cvt.d.s   $f20, $f20
/* 3F19C 80063D9C 4620A502 */  mul.d     $f20, $f20, $f0
/* 3F1A0 80063DA0 3C014000 */  lui       $at, 0x4000
/* 3F1A4 80063DA4 44810000 */  mtc1      $at, $f0
/* 3F1A8 80063DA8 4620A520 */  cvt.s.d   $f20, $f20
/* 3F1AC 80063DAC 4600A503 */  div.s     $f20, $f20, $f0
/* 3F1B0 80063DB0 0C00A874 */  jal       cos_rad
/* 3F1B4 80063DB4 4600A306 */   mov.s    $f12, $f20
/* 3F1B8 80063DB8 4600A306 */  mov.s     $f12, $f20
/* 3F1BC 80063DBC 0C00A85B */  jal       sin_rad
/* 3F1C0 80063DC0 46000506 */   mov.s    $f20, $f0
/* 3F1C4 80063DC4 4600A503 */  div.s     $f20, $f20, $f0
/* 3F1C8 80063DC8 461AC100 */  add.s     $f4, $f24, $f26
/* 3F1CC 80063DCC 461AC081 */  sub.s     $f2, $f24, $f26
/* 3F1D0 80063DD0 46022103 */  div.s     $f4, $f4, $f2
/* 3F1D4 80063DD4 4618C000 */  add.s     $f0, $f24, $f24
/* 3F1D8 80063DD8 461A0002 */  mul.s     $f0, $f0, $f26
/* 3F1DC 80063DDC 46020003 */  div.s     $f0, $f0, $f2
/* 3F1E0 80063DE0 4616A583 */  div.s     $f22, $f20, $f22
/* 3F1E4 80063DE4 3C01BF80 */  lui       $at, 0xbf80
/* 3F1E8 80063DE8 44811000 */  mtc1      $at, $f2
/* 3F1EC 80063DEC 00002821 */  addu      $a1, $zero, $zero
/* 3F1F0 80063DF0 AFA0004C */  sw        $zero, 0x4c($sp)
/* 3F1F4 80063DF4 E7A2003C */  swc1      $f2, 0x3c($sp)
/* 3F1F8 80063DF8 E7B40024 */  swc1      $f20, 0x24($sp)
/* 3F1FC 80063DFC E7A40038 */  swc1      $f4, 0x38($sp)
/* 3F200 80063E00 E7A00048 */  swc1      $f0, 0x48($sp)
/* 3F204 80063E04 E7B60010 */  swc1      $f22, 0x10($sp)
.L80063E08:
/* 3F208 80063E08 00002021 */  addu      $a0, $zero, $zero
/* 3F20C 80063E0C 02001821 */  addu      $v1, $s0, $zero
.L80063E10:
/* 3F210 80063E10 C4600000 */  lwc1      $f0, ($v1)
/* 3F214 80063E14 461C0002 */  mul.s     $f0, $f0, $f28
/* 3F218 80063E18 24840001 */  addiu     $a0, $a0, 1
/* 3F21C 80063E1C 28820004 */  slti      $v0, $a0, 4
/* 3F220 80063E20 E4600000 */  swc1      $f0, ($v1)
/* 3F224 80063E24 1440FFFA */  bnez      $v0, .L80063E10
/* 3F228 80063E28 24630004 */   addiu    $v1, $v1, 4
/* 3F22C 80063E2C 24A50001 */  addiu     $a1, $a1, 1
/* 3F230 80063E30 28A20004 */  slti      $v0, $a1, 4
/* 3F234 80063E34 1440FFF4 */  bnez      $v0, .L80063E08
/* 3F238 80063E38 26100010 */   addiu    $s0, $s0, 0x10
/* 3F23C 80063E3C 52200025 */  beql      $s1, $zero, .L80063ED4
/* 3F240 80063E40 27A40010 */   addiu    $a0, $sp, 0x10
/* 3F244 80063E44 461AC080 */  add.s     $f2, $f24, $f26
/* 3F248 80063E48 3C01800A */  lui       $at, %hi(D_80099BD8)
/* 3F24C 80063E4C D4209BD8 */  ldc1      $f0, %lo(D_80099BD8)($at)
/* 3F250 80063E50 460010A1 */  cvt.d.s   $f2, $f2
/* 3F254 80063E54 4620103E */  c.le.d    $f2, $f0
/* 3F258 80063E58 00000000 */  nop
/* 3F25C 80063E5C 00000000 */  nop
/* 3F260 80063E60 4501001A */  bc1t      .L80063ECC
/* 3F264 80063E64 3402FFFF */   ori      $v0, $zero, 0xffff
/* 3F268 80063E68 3C01800A */  lui       $at, %hi(D_80099BE0)
/* 3F26C 80063E6C D4209BE0 */  ldc1      $f0, %lo(D_80099BE0)($at)
/* 3F270 80063E70 46220083 */  div.d     $f2, $f0, $f2
/* 3F274 80063E74 3C01800A */  lui       $at, %hi(D_80099BE8)
/* 3F278 80063E78 D4209BE8 */  ldc1      $f0, %lo(D_80099BE8)($at)
/* 3F27C 80063E7C 4622003E */  c.le.d    $f0, $f2
/* 3F280 80063E80 00000000 */  nop
/* 3F284 80063E84 00000000 */  nop
/* 3F288 80063E88 45030006 */  bc1tl     .L80063EA4
/* 3F28C 80063E8C 46201001 */   sub.d    $f0, $f2, $f0
/* 3F290 80063E90 4620100D */  trunc.w.d $f0, $f2
/* 3F294 80063E94 44030000 */  mfc1      $v1, $f0
/* 3F298 80063E98 00000000 */  nop
/* 3F29C 80063E9C 08018FAE */  j         .L80063EB8
/* 3F2A0 80063EA0 00601021 */   addu     $v0, $v1, $zero
.L80063EA4:
/* 3F2A4 80063EA4 4620008D */  trunc.w.d $f2, $f0
/* 3F2A8 80063EA8 44031000 */  mfc1      $v1, $f2
/* 3F2AC 80063EAC 3C028000 */  lui       $v0, 0x8000
/* 3F2B0 80063EB0 00621825 */  or        $v1, $v1, $v0
/* 3F2B4 80063EB4 00601021 */  addu      $v0, $v1, $zero
.L80063EB8:
/* 3F2B8 80063EB8 A6220000 */  sh        $v0, ($s1)
/* 3F2BC 80063EBC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3F2C0 80063EC0 14400004 */  bnez      $v0, .L80063ED4
/* 3F2C4 80063EC4 27A40010 */   addiu    $a0, $sp, 0x10
/* 3F2C8 80063EC8 24020001 */  addiu     $v0, $zero, 1
.L80063ECC:
/* 3F2CC 80063ECC A6220000 */  sh        $v0, ($s1)
/* 3F2D0 80063ED0 27A40010 */  addiu     $a0, $sp, 0x10
.L80063ED4:
/* 3F2D4 80063ED4 0C019D40 */  jal       guMtxF2L
/* 3F2D8 80063ED8 02402821 */   addu     $a1, $s2, $zero
/* 3F2DC 80063EDC 8FBF005C */  lw        $ra, 0x5c($sp)
/* 3F2E0 80063EE0 8FB20058 */  lw        $s2, 0x58($sp)
/* 3F2E4 80063EE4 8FB10054 */  lw        $s1, 0x54($sp)
/* 3F2E8 80063EE8 8FB00050 */  lw        $s0, 0x50($sp)
/* 3F2EC 80063EEC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 3F2F0 80063EF0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 3F2F4 80063EF4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 3F2F8 80063EF8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 3F2FC 80063EFC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 3F300 80063F00 03E00008 */  jr        $ra
/* 3F304 80063F04 27BD0088 */   addiu    $sp, $sp, 0x88
/* 3F308 80063F08 00000000 */  nop
/* 3F30C 80063F0C 00000000 */  nop
