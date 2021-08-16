.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E005A1FC
/* 3604BC E005A1FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3604C0 E005A200 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3604C4 E005A204 8C85000C */  lw        $a1, 0xc($a0)
/* 3604C8 E005A208 8CA20028 */  lw        $v0, 0x28($a1)
/* 3604CC E005A20C 8CA30024 */  lw        $v1, 0x24($a1)
/* 3604D0 E005A210 24420001 */  addiu     $v0, $v0, 1
/* 3604D4 E005A214 2463FFFF */  addiu     $v1, $v1, -1
/* 3604D8 E005A218 ACA20028 */  sw        $v0, 0x28($a1)
/* 3604DC E005A21C 04610005 */  bgez      $v1, .LE005A234
/* 3604E0 E005A220 ACA30024 */   sw       $v1, 0x24($a1)
/* 3604E4 E005A224 0C080128 */  jal       func_E02004A0
/* 3604E8 E005A228 00000000 */   nop
/* 3604EC E005A22C 080168E9 */  j         .LE005A3A4
/* 3604F0 E005A230 00000000 */   nop
.LE005A234:
/* 3604F4 E005A234 8CA7002C */  lw        $a3, 0x2c($a1)
/* 3604F8 E005A238 8C820008 */  lw        $v0, 8($a0)
/* 3604FC E005A23C 24060001 */  addiu     $a2, $zero, 1
/* 360500 E005A240 00C2102A */  slt       $v0, $a2, $v0
/* 360504 E005A244 10400057 */  beqz      $v0, .LE005A3A4
/* 360508 E005A248 24A50034 */   addiu    $a1, $a1, 0x34
/* 36050C E005A24C 28690006 */  slti      $t1, $v1, 6
/* 360510 E005A250 28680005 */  slti      $t0, $v1, 5
/* 360514 E005A254 00C31004 */  sllv      $v0, $v1, $a2
/* 360518 E005A258 0047382A */  slt       $a3, $v0, $a3
/* 36051C E005A25C 24A3001C */  addiu     $v1, $a1, 0x1c
/* 360520 E005A260 3C01E006 */  lui       $at, %hi(D_E005A750)
/* 360524 E005A264 D428A750 */  ldc1      $f8, %lo(D_E005A750)($at)
/* 360528 E005A268 3C01E006 */  lui       $at, %hi(D_E005A758)
/* 36052C E005A26C D42AA758 */  ldc1      $f10, %lo(D_E005A758)($at)
/* 360530 E005A270 3C01E006 */  lui       $at, %hi(D_E005A760)
/* 360534 E005A274 D42CA760 */  ldc1      $f12, %lo(D_E005A760)($at)
.LE005A278:
/* 360538 E005A278 15200013 */  bnez      $t1, .LE005A2C8
/* 36053C E005A27C 00000000 */   nop
/* 360540 E005A280 C464FFF4 */  lwc1      $f4, -0xc($v1)
/* 360544 E005A284 46002121 */  cvt.d.s   $f4, $f4
/* 360548 E005A288 46282102 */  mul.d     $f4, $f4, $f8
/* 36054C E005A28C 00000000 */  nop
/* 360550 E005A290 C462FFF8 */  lwc1      $f2, -8($v1)
/* 360554 E005A294 460010A1 */  cvt.d.s   $f2, $f2
/* 360558 E005A298 46281082 */  mul.d     $f2, $f2, $f8
/* 36055C E005A29C 00000000 */  nop
/* 360560 E005A2A0 C460FFFC */  lwc1      $f0, -4($v1)
/* 360564 E005A2A4 46000021 */  cvt.d.s   $f0, $f0
/* 360568 E005A2A8 46280002 */  mul.d     $f0, $f0, $f8
/* 36056C E005A2AC 00000000 */  nop
/* 360570 E005A2B0 46202120 */  cvt.s.d   $f4, $f4
/* 360574 E005A2B4 462010A0 */  cvt.s.d   $f2, $f2
/* 360578 E005A2B8 46200020 */  cvt.s.d   $f0, $f0
/* 36057C E005A2BC E464FFF4 */  swc1      $f4, -0xc($v1)
/* 360580 E005A2C0 E462FFF8 */  swc1      $f2, -8($v1)
/* 360584 E005A2C4 E460FFFC */  swc1      $f0, -4($v1)
.LE005A2C8:
/* 360588 E005A2C8 11000019 */  beqz      $t0, .LE005A330
/* 36058C E005A2CC 00000000 */   nop
/* 360590 E005A2D0 C4660004 */  lwc1      $f6, 4($v1)
/* 360594 E005A2D4 460031A1 */  cvt.d.s   $f6, $f6
/* 360598 E005A2D8 46283182 */  mul.d     $f6, $f6, $f8
/* 36059C E005A2DC 00000000 */  nop
/* 3605A0 E005A2E0 C464FFF4 */  lwc1      $f4, -0xc($v1)
/* 3605A4 E005A2E4 46002121 */  cvt.d.s   $f4, $f4
/* 3605A8 E005A2E8 462A2102 */  mul.d     $f4, $f4, $f10
/* 3605AC E005A2EC 00000000 */  nop
/* 3605B0 E005A2F0 C462FFF8 */  lwc1      $f2, -8($v1)
/* 3605B4 E005A2F4 460010A1 */  cvt.d.s   $f2, $f2
/* 3605B8 E005A2F8 462A1082 */  mul.d     $f2, $f2, $f10
/* 3605BC E005A2FC 00000000 */  nop
/* 3605C0 E005A300 C460FFFC */  lwc1      $f0, -4($v1)
/* 3605C4 E005A304 46000021 */  cvt.d.s   $f0, $f0
/* 3605C8 E005A308 462A0002 */  mul.d     $f0, $f0, $f10
/* 3605CC E005A30C 00000000 */  nop
/* 3605D0 E005A310 462031A0 */  cvt.s.d   $f6, $f6
/* 3605D4 E005A314 46202120 */  cvt.s.d   $f4, $f4
/* 3605D8 E005A318 462010A0 */  cvt.s.d   $f2, $f2
/* 3605DC E005A31C 46200020 */  cvt.s.d   $f0, $f0
/* 3605E0 E005A320 E4660004 */  swc1      $f6, 4($v1)
/* 3605E4 E005A324 E464FFF4 */  swc1      $f4, -0xc($v1)
/* 3605E8 E005A328 E462FFF8 */  swc1      $f2, -8($v1)
/* 3605EC E005A32C E460FFFC */  swc1      $f0, -4($v1)
.LE005A330:
/* 3605F0 E005A330 10E0000A */  beqz      $a3, .LE005A35C
/* 3605F4 E005A334 00000000 */   nop
/* 3605F8 E005A338 C4600014 */  lwc1      $f0, 0x14($v1)
/* 3605FC E005A33C 46000087 */  neg.s     $f2, $f0
/* 360600 E005A340 460010A1 */  cvt.d.s   $f2, $f2
/* 360604 E005A344 462C1082 */  mul.d     $f2, $f2, $f12
/* 360608 E005A348 00000000 */  nop
/* 36060C E005A34C 46000021 */  cvt.d.s   $f0, $f0
/* 360610 E005A350 46220000 */  add.d     $f0, $f0, $f2
/* 360614 E005A354 46200020 */  cvt.s.d   $f0, $f0
/* 360618 E005A358 E4600014 */  swc1      $f0, 0x14($v1)
.LE005A35C:
/* 36061C E005A35C C466FFE8 */  lwc1      $f6, -0x18($v1)
/* 360620 E005A360 C460FFF4 */  lwc1      $f0, -0xc($v1)
/* 360624 E005A364 C462FFEC */  lwc1      $f2, -0x14($v1)
/* 360628 E005A368 46003180 */  add.s     $f6, $f6, $f0
/* 36062C E005A36C C460FFF8 */  lwc1      $f0, -8($v1)
/* 360630 E005A370 C4640004 */  lwc1      $f4, 4($v1)
/* 360634 E005A374 46001080 */  add.s     $f2, $f2, $f0
/* 360638 E005A378 C4600000 */  lwc1      $f0, ($v1)
/* 36063C E005A37C 24C60001 */  addiu     $a2, $a2, 1
/* 360640 E005A380 AC60FFF0 */  sw        $zero, -0x10($v1)
/* 360644 E005A384 46040000 */  add.s     $f0, $f0, $f4
/* 360648 E005A388 E466FFE8 */  swc1      $f6, -0x18($v1)
/* 36064C E005A38C E462FFEC */  swc1      $f2, -0x14($v1)
/* 360650 E005A390 E4600000 */  swc1      $f0, ($v1)
/* 360654 E005A394 8C820008 */  lw        $v0, 8($a0)
/* 360658 E005A398 00C2102A */  slt       $v0, $a2, $v0
/* 36065C E005A39C 1440FFB6 */  bnez      $v0, .LE005A278
/* 360660 E005A3A0 24630034 */   addiu    $v1, $v1, 0x34
.LE005A3A4:
/* 360664 E005A3A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 360668 E005A3A8 03E00008 */  jr        $ra
/* 36066C E005A3AC 27BD0018 */   addiu    $sp, $sp, 0x18
