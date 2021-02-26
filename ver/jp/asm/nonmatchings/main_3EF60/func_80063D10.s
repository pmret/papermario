.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80063D10
/* 3F110 80063D10 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 3F114 80063D14 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 3F118 80063D18 C7B80098 */  lwc1      $f24, 0x98($sp)
/* 3F11C 80063D1C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 3F120 80063D20 C7BA009C */  lwc1      $f26, 0x9c($sp)
/* 3F124 80063D24 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 3F128 80063D28 C7BC00A0 */  lwc1      $f28, 0xa0($sp)
/* 3F12C 80063D2C F7B40060 */  sdc1      $f20, 0x60($sp)
/* 3F130 80063D30 4486A000 */  mtc1      $a2, $f20
/* 3F134 80063D34 AFB20058 */  sw        $s2, 0x58($sp)
/* 3F138 80063D38 00809021 */  addu      $s2, $a0, $zero
/* 3F13C 80063D3C AFB10054 */  sw        $s1, 0x54($sp)
/* 3F140 80063D40 00A08821 */  addu      $s1, $a1, $zero
/* 3F144 80063D44 AFB00050 */  sw        $s0, 0x50($sp)
/* 3F148 80063D48 27B00010 */  addiu     $s0, $sp, 0x10
/* 3F14C 80063D4C F7B60068 */  sdc1      $f22, 0x68($sp)
/* 3F150 80063D50 4487B000 */  mtc1      $a3, $f22
/* 3F154 80063D54 AFBF005C */  sw        $ra, 0x5c($sp)
/* 3F158 80063D58 0C019D20 */  jal       func_80067480
/* 3F15C 80063D5C 02002021 */   addu     $a0, $s0, $zero
/* 3F160 80063D60 3C01800A */  lui       $at, %hi(D_80099BB0)
/* 3F164 80063D64 D4209BB0 */  ldc1      $f0, %lo(D_80099BB0)($at)
/* 3F168 80063D68 4600A521 */  cvt.d.s   $f20, $f20
/* 3F16C 80063D6C 4620A502 */  mul.d     $f20, $f20, $f0
/* 3F170 80063D70 3C014000 */  lui       $at, 0x4000
/* 3F174 80063D74 44810000 */  mtc1      $at, $f0
/* 3F178 80063D78 4620A520 */  cvt.s.d   $f20, $f20
/* 3F17C 80063D7C 4600A503 */  div.s     $f20, $f20, $f0
/* 3F180 80063D80 0C00A864 */  jal       func_8002A190
/* 3F184 80063D84 4600A306 */   mov.s    $f12, $f20
/* 3F188 80063D88 4600A306 */  mov.s     $f12, $f20
/* 3F18C 80063D8C 0C00A84B */  jal       func_8002A12C
/* 3F190 80063D90 46000506 */   mov.s    $f20, $f0
/* 3F194 80063D94 4600A503 */  div.s     $f20, $f20, $f0
/* 3F198 80063D98 461AC100 */  add.s     $f4, $f24, $f26
/* 3F19C 80063D9C 461AC081 */  sub.s     $f2, $f24, $f26
/* 3F1A0 80063DA0 46022103 */  div.s     $f4, $f4, $f2
/* 3F1A4 80063DA4 4618C000 */  add.s     $f0, $f24, $f24
/* 3F1A8 80063DA8 461A0002 */  mul.s     $f0, $f0, $f26
/* 3F1AC 80063DAC 46020003 */  div.s     $f0, $f0, $f2
/* 3F1B0 80063DB0 4616A583 */  div.s     $f22, $f20, $f22
/* 3F1B4 80063DB4 3C01BF80 */  lui       $at, 0xbf80
/* 3F1B8 80063DB8 44811000 */  mtc1      $at, $f2
/* 3F1BC 80063DBC 00002821 */  addu      $a1, $zero, $zero
/* 3F1C0 80063DC0 AFA0004C */  sw        $zero, 0x4c($sp)
/* 3F1C4 80063DC4 E7A2003C */  swc1      $f2, 0x3c($sp)
/* 3F1C8 80063DC8 E7B40024 */  swc1      $f20, 0x24($sp)
/* 3F1CC 80063DCC E7A40038 */  swc1      $f4, 0x38($sp)
/* 3F1D0 80063DD0 E7A00048 */  swc1      $f0, 0x48($sp)
/* 3F1D4 80063DD4 E7B60010 */  swc1      $f22, 0x10($sp)
.L80063DD8:
/* 3F1D8 80063DD8 00002021 */  addu      $a0, $zero, $zero
/* 3F1DC 80063DDC 02001821 */  addu      $v1, $s0, $zero
.L80063DE0:
/* 3F1E0 80063DE0 C4600000 */  lwc1      $f0, ($v1)
/* 3F1E4 80063DE4 461C0002 */  mul.s     $f0, $f0, $f28
/* 3F1E8 80063DE8 24840001 */  addiu     $a0, $a0, 1
/* 3F1EC 80063DEC 28820004 */  slti      $v0, $a0, 4
/* 3F1F0 80063DF0 E4600000 */  swc1      $f0, ($v1)
/* 3F1F4 80063DF4 1440FFFA */  bnez      $v0, .L80063DE0
/* 3F1F8 80063DF8 24630004 */   addiu    $v1, $v1, 4
/* 3F1FC 80063DFC 24A50001 */  addiu     $a1, $a1, 1
/* 3F200 80063E00 28A20004 */  slti      $v0, $a1, 4
/* 3F204 80063E04 1440FFF4 */  bnez      $v0, .L80063DD8
/* 3F208 80063E08 26100010 */   addiu    $s0, $s0, 0x10
/* 3F20C 80063E0C 52200025 */  beql      $s1, $zero, .L80063EA4
/* 3F210 80063E10 27A40010 */   addiu    $a0, $sp, 0x10
/* 3F214 80063E14 461AC080 */  add.s     $f2, $f24, $f26
/* 3F218 80063E18 3C01800A */  lui       $at, %hi(D_80099BB8)
/* 3F21C 80063E1C D4209BB8 */  ldc1      $f0, %lo(D_80099BB8)($at)
/* 3F220 80063E20 460010A1 */  cvt.d.s   $f2, $f2
/* 3F224 80063E24 4620103E */  c.le.d    $f2, $f0
/* 3F228 80063E28 00000000 */  nop
/* 3F22C 80063E2C 00000000 */  nop
/* 3F230 80063E30 4501001A */  bc1t      .L80063E9C
/* 3F234 80063E34 3402FFFF */   ori      $v0, $zero, 0xffff
/* 3F238 80063E38 3C01800A */  lui       $at, %hi(D_80099BC0)
/* 3F23C 80063E3C D4209BC0 */  ldc1      $f0, %lo(D_80099BC0)($at)
/* 3F240 80063E40 46220083 */  div.d     $f2, $f0, $f2
/* 3F244 80063E44 3C01800A */  lui       $at, %hi(D_80099BC8)
/* 3F248 80063E48 D4209BC8 */  ldc1      $f0, %lo(D_80099BC8)($at)
/* 3F24C 80063E4C 4622003E */  c.le.d    $f0, $f2
/* 3F250 80063E50 00000000 */  nop
/* 3F254 80063E54 00000000 */  nop
/* 3F258 80063E58 45030006 */  bc1tl     .L80063E74
/* 3F25C 80063E5C 46201001 */   sub.d    $f0, $f2, $f0
/* 3F260 80063E60 4620100D */  trunc.w.d $f0, $f2
/* 3F264 80063E64 44030000 */  mfc1      $v1, $f0
/* 3F268 80063E68 00000000 */  nop
/* 3F26C 80063E6C 08018FA2 */  j         .L80063E88
/* 3F270 80063E70 00601021 */   addu     $v0, $v1, $zero
.L80063E74:
/* 3F274 80063E74 4620008D */  trunc.w.d $f2, $f0
/* 3F278 80063E78 44031000 */  mfc1      $v1, $f2
/* 3F27C 80063E7C 3C028000 */  lui       $v0, 0x8000
/* 3F280 80063E80 00621825 */  or        $v1, $v1, $v0
/* 3F284 80063E84 00601021 */  addu      $v0, $v1, $zero
.L80063E88:
/* 3F288 80063E88 A6220000 */  sh        $v0, ($s1)
/* 3F28C 80063E8C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3F290 80063E90 14400004 */  bnez      $v0, .L80063EA4
/* 3F294 80063E94 27A40010 */   addiu    $a0, $sp, 0x10
/* 3F298 80063E98 24020001 */  addiu     $v0, $zero, 1
.L80063E9C:
/* 3F29C 80063E9C A6220000 */  sh        $v0, ($s1)
/* 3F2A0 80063EA0 27A40010 */  addiu     $a0, $sp, 0x10
.L80063EA4:
/* 3F2A4 80063EA4 0C019D38 */  jal       func_800674E0
/* 3F2A8 80063EA8 02402821 */   addu     $a1, $s2, $zero
/* 3F2AC 80063EAC 8FBF005C */  lw        $ra, 0x5c($sp)
/* 3F2B0 80063EB0 8FB20058 */  lw        $s2, 0x58($sp)
/* 3F2B4 80063EB4 8FB10054 */  lw        $s1, 0x54($sp)
/* 3F2B8 80063EB8 8FB00050 */  lw        $s0, 0x50($sp)
/* 3F2BC 80063EBC D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 3F2C0 80063EC0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 3F2C4 80063EC4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 3F2C8 80063EC8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 3F2CC 80063ECC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 3F2D0 80063ED0 03E00008 */  jr        $ra
/* 3F2D4 80063ED4 27BD0088 */   addiu    $sp, $sp, 0x88
/* 3F2D8 80063ED8 00000000 */  nop
/* 3F2DC 80063EDC 00000000 */  nop
