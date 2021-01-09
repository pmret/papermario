.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007A000
/* 37C540 E007A000 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 37C544 E007A004 F7B60098 */  sdc1      $f22, 0x98($sp)
/* 37C548 E007A008 C7B600D0 */  lwc1      $f22, 0xd0($sp)
/* 37C54C E007A00C F7B800A0 */  sdc1      $f24, 0xa0($sp)
/* 37C550 E007A010 C7B800D4 */  lwc1      $f24, 0xd4($sp)
/* 37C554 E007A014 F7BA00A8 */  sdc1      $f26, 0xa8($sp)
/* 37C558 E007A018 C7BA00D8 */  lwc1      $f26, 0xd8($sp)
/* 37C55C E007A01C AFB20080 */  sw        $s2, 0x80($sp)
/* 37C560 E007A020 8FB200DC */  lw        $s2, 0xdc($sp)
/* 37C564 E007A024 AFB1007C */  sw        $s1, 0x7c($sp)
/* 37C568 E007A028 0080882D */  daddu     $s1, $a0, $zero
/* 37C56C E007A02C AFB00078 */  sw        $s0, 0x78($sp)
/* 37C570 E007A030 27B00018 */  addiu     $s0, $sp, 0x18
/* 37C574 E007A034 AFBF008C */  sw        $ra, 0x8c($sp)
/* 37C578 E007A038 AFB40088 */  sw        $s4, 0x88($sp)
/* 37C57C E007A03C AFB30084 */  sw        $s3, 0x84($sp)
/* 37C580 E007A040 F7BE00B8 */  sdc1      $f30, 0xb8($sp)
/* 37C584 E007A044 F7BC00B0 */  sdc1      $f28, 0xb0($sp)
/* 37C588 E007A048 F7B40090 */  sdc1      $f20, 0x90($sp)
/* 37C58C E007A04C AFA500C4 */  sw        $a1, 0xc4($sp)
/* 37C590 E007A050 AFA600C8 */  sw        $a2, 0xc8($sp)
/* 37C594 E007A054 1240011D */  beqz      $s2, .LE007A4CC
/* 37C598 E007A058 AFA700CC */   sw       $a3, 0xcc($sp)
/* 37C59C E007A05C 4616B002 */  mul.s     $f0, $f22, $f22
/* 37C5A0 E007A060 00000000 */  nop       
/* 37C5A4 E007A064 4618C082 */  mul.s     $f2, $f24, $f24
/* 37C5A8 E007A068 00000000 */  nop       
/* 37C5AC E007A06C 461AD102 */  mul.s     $f4, $f26, $f26
/* 37C5B0 E007A070 00000000 */  nop       
/* 37C5B4 E007A074 46020000 */  add.s     $f0, $f0, $f2
/* 37C5B8 E007A078 46040300 */  add.s     $f12, $f0, $f4
/* 37C5BC E007A07C 4480A000 */  mtc1      $zero, $f20
/* 37C5C0 E007A080 00000000 */  nop       
/* 37C5C4 E007A084 46146032 */  c.eq.s    $f12, $f20
/* 37C5C8 E007A088 00000000 */  nop       
/* 37C5CC E007A08C 4501010F */  bc1t      .LE007A4CC
/* 37C5D0 E007A090 26520001 */   addiu    $s2, $s2, 1
/* 37C5D4 E007A094 0C080154 */  jal       func_E0200550
/* 37C5D8 E007A098 00000000 */   nop      
/* 37C5DC E007A09C 3C01BF80 */  lui       $at, 0xbf80
/* 37C5E0 E007A0A0 44811000 */  mtc1      $at, $f2
/* 37C5E4 E007A0A4 00000000 */  nop       
/* 37C5E8 E007A0A8 46001303 */  div.s     $f12, $f2, $f0
/* 37C5EC E007A0AC 460CB582 */  mul.s     $f22, $f22, $f12
/* 37C5F0 E007A0B0 00000000 */  nop       
/* 37C5F4 E007A0B4 460CC602 */  mul.s     $f24, $f24, $f12
/* 37C5F8 E007A0B8 00000000 */  nop       
/* 37C5FC E007A0BC 460CD682 */  mul.s     $f26, $f26, $f12
/* 37C600 E007A0C0 00000000 */  nop       
/* 37C604 E007A0C4 4614B032 */  c.eq.s    $f22, $f20
/* 37C608 E007A0C8 00000000 */  nop       
/* 37C60C E007A0CC 45010007 */  bc1t      .LE007A0EC
/* 37C610 E007A0D0 4600A706 */   mov.s    $f28, $f20
/* 37C614 E007A0D4 4600C007 */  neg.s     $f0, $f24
/* 37C618 E007A0D8 46160783 */  div.s     $f30, $f0, $f22
/* 37C61C E007A0DC 3C013F80 */  lui       $at, 0x3f80
/* 37C620 E007A0E0 44817000 */  mtc1      $at, $f14
/* 37C624 E007A0E4 0801E849 */  j         .LE007A124
/* 37C628 E007A0E8 E7AE0070 */   swc1     $f14, 0x70($sp)
.LE007A0EC:
/* 37C62C E007A0EC 4614C032 */  c.eq.s    $f24, $f20
/* 37C630 E007A0F0 00000000 */  nop       
/* 37C634 E007A0F4 45010007 */  bc1t      .LE007A114
/* 37C638 E007A0F8 4600B007 */   neg.s    $f0, $f22
/* 37C63C E007A0FC 46180003 */  div.s     $f0, $f0, $f24
/* 37C640 E007A100 3C013F80 */  lui       $at, 0x3f80
/* 37C644 E007A104 4481F000 */  mtc1      $at, $f30
/* 37C648 E007A108 4600A706 */  mov.s     $f28, $f20
/* 37C64C E007A10C 0801E849 */  j         .LE007A124
/* 37C650 E007A110 E7A00070 */   swc1     $f0, 0x70($sp)
.LE007A114:
/* 37C654 E007A114 3C013F80 */  lui       $at, 0x3f80
/* 37C658 E007A118 4481F000 */  mtc1      $at, $f30
/* 37C65C E007A11C 461A0703 */  div.s     $f28, $f0, $f26
/* 37C660 E007A120 E7B40070 */  swc1      $f20, 0x70($sp)
.LE007A124:
/* 37C664 E007A124 461EF002 */  mul.s     $f0, $f30, $f30
/* 37C668 E007A128 00000000 */  nop       
/* 37C66C E007A12C 461CE102 */  mul.s     $f4, $f28, $f28
/* 37C670 E007A130 00000000 */  nop       
/* 37C674 E007A134 C7B00070 */  lwc1      $f16, 0x70($sp)
/* 37C678 E007A138 46008386 */  mov.s     $f14, $f16
/* 37C67C E007A13C 460E8082 */  mul.s     $f2, $f16, $f14
/* 37C680 E007A140 00000000 */  nop       
/* 37C684 E007A144 46020000 */  add.s     $f0, $f0, $f2
/* 37C688 E007A148 46040300 */  add.s     $f12, $f0, $f4
/* 37C68C E007A14C 44800000 */  mtc1      $zero, $f0
/* 37C690 E007A150 00000000 */  nop       
/* 37C694 E007A154 46006032 */  c.eq.s    $f12, $f0
/* 37C698 E007A158 00000000 */  nop       
/* 37C69C E007A15C 450100DB */  bc1t      .LE007A4CC
/* 37C6A0 E007A160 00000000 */   nop      
/* 37C6A4 E007A164 0C080154 */  jal       func_E0200550
/* 37C6A8 E007A168 00000000 */   nop      
/* 37C6AC E007A16C 3C013F80 */  lui       $at, 0x3f80
/* 37C6B0 E007A170 44811000 */  mtc1      $at, $f2
/* 37C6B4 E007A174 00000000 */  nop       
/* 37C6B8 E007A178 46001303 */  div.s     $f12, $f2, $f0
/* 37C6BC E007A17C 460CF782 */  mul.s     $f30, $f30, $f12
/* 37C6C0 E007A180 00000000 */  nop       
/* 37C6C4 E007A184 C7B00070 */  lwc1      $f16, 0x70($sp)
/* 37C6C8 E007A188 460C8402 */  mul.s     $f16, $f16, $f12
/* 37C6CC E007A18C 00000000 */  nop       
/* 37C6D0 E007A190 460CE702 */  mul.s     $f28, $f28, $f12
/* 37C6D4 E007A194 00000000 */  nop       
/* 37C6D8 E007A198 3C014100 */  lui       $at, 0x4100
/* 37C6DC E007A19C 44810000 */  mtc1      $at, $f0
/* 37C6E0 E007A1A0 00000000 */  nop       
/* 37C6E4 E007A1A4 4600B582 */  mul.s     $f22, $f22, $f0
/* 37C6E8 E007A1A8 00000000 */  nop       
/* 37C6EC E007A1AC 4600C602 */  mul.s     $f24, $f24, $f0
/* 37C6F0 E007A1B0 00000000 */  nop       
/* 37C6F4 E007A1B4 4600D682 */  mul.s     $f26, $f26, $f0
/* 37C6F8 E007A1B8 00000000 */  nop       
/* 37C6FC E007A1BC 4600F782 */  mul.s     $f30, $f30, $f0
/* 37C700 E007A1C0 00000000 */  nop       
/* 37C704 E007A1C4 0200202D */  daddu     $a0, $s0, $zero
/* 37C708 E007A1C8 3C02E008 */  lui       $v0, %hi(func_E007A504)
/* 37C70C E007A1CC 2442A504 */  addiu     $v0, $v0, %lo(func_E007A504)
/* 37C710 E007A1D0 AC820008 */  sw        $v0, 8($a0)
/* 37C714 E007A1D4 46008402 */  mul.s     $f16, $f16, $f0
/* 37C718 E007A1D8 00000000 */  nop       
/* 37C71C E007A1DC 3C02E008 */  lui       $v0, %hi(func_E007A50C)
/* 37C720 E007A1E0 2442A50C */  addiu     $v0, $v0, %lo(func_E007A50C)
/* 37C724 E007A1E4 AC82000C */  sw        $v0, 0xc($a0)
/* 37C728 E007A1E8 3C02E008 */  lui       $v0, %hi(func_E007A840)
/* 37C72C E007A1EC 2442A840 */  addiu     $v0, $v0, %lo(func_E007A840)
/* 37C730 E007A1F0 AC800000 */  sw        $zero, ($a0)
/* 37C734 E007A1F4 4600E702 */  mul.s     $f28, $f28, $f0
/* 37C738 E007A1F8 00000000 */  nop       
/* 37C73C E007A1FC E7B00070 */  swc1      $f16, 0x70($sp)
/* 37C740 E007A200 AC820010 */  sw        $v0, 0x10($a0)
/* 37C744 E007A204 2402003D */  addiu     $v0, $zero, 0x3d
/* 37C748 E007A208 AC800014 */  sw        $zero, 0x14($a0)
/* 37C74C E007A20C 0C080124 */  jal       func_E0200490
/* 37C750 E007A210 AC820004 */   sw       $v0, 4($a0)
/* 37C754 E007A214 00122040 */  sll       $a0, $s2, 1
/* 37C758 E007A218 00922021 */  addu      $a0, $a0, $s2
/* 37C75C E007A21C 00042080 */  sll       $a0, $a0, 2
/* 37C760 E007A220 00922021 */  addu      $a0, $a0, $s2
/* 37C764 E007A224 000420C0 */  sll       $a0, $a0, 3
/* 37C768 E007A228 0040A02D */  daddu     $s4, $v0, $zero
/* 37C76C E007A22C 0C08012C */  jal       func_E02004B0
/* 37C770 E007A230 AE920008 */   sw       $s2, 8($s4)
/* 37C774 E007A234 0040182D */  daddu     $v1, $v0, $zero
/* 37C778 E007A238 14600003 */  bnez      $v1, .LE007A248
/* 37C77C E007A23C AE83000C */   sw       $v1, 0xc($s4)
.LE007A240:
/* 37C780 E007A240 0801E890 */  j         .LE007A240
/* 37C784 E007A244 00000000 */   nop      
.LE007A248:
/* 37C788 E007A248 AC600004 */  sw        $zero, 4($v1)
/* 37C78C E007A24C AC710000 */  sw        $s1, ($v1)
/* 37C790 E007A250 C7AE00C4 */  lwc1      $f14, 0xc4($sp)
/* 37C794 E007A254 E46E0008 */  swc1      $f14, 8($v1)
/* 37C798 E007A258 C7B000C8 */  lwc1      $f16, 0xc8($sp)
/* 37C79C E007A25C 2402000A */  addiu     $v0, $zero, 0xa
/* 37C7A0 E007A260 E470000C */  swc1      $f16, 0xc($v1)
/* 37C7A4 E007A264 C7AE00CC */  lwc1      $f14, 0xcc($sp)
/* 37C7A8 E007A268 24110001 */  addiu     $s1, $zero, 1
/* 37C7AC E007A26C E46E0010 */  swc1      $f14, 0x10($v1)
/* 37C7B0 E007A270 AC62005C */  sw        $v0, 0x5c($v1)
/* 37C7B4 E007A274 AC600060 */  sw        $zero, 0x60($v1)
/* 37C7B8 E007A278 0232102A */  slt       $v0, $s1, $s2
/* 37C7BC E007A27C 10400091 */  beqz      $v0, .LE007A4C4
/* 37C7C0 E007A280 24630068 */   addiu    $v1, $v1, 0x68
/* 37C7C4 E007A284 2470005C */  addiu     $s0, $v1, 0x5c
/* 37C7C8 E007A288 24130048 */  addiu     $s3, $zero, 0x48
/* 37C7CC E007A28C 3C014010 */  lui       $at, 0x4010
/* 37C7D0 E007A290 4481A800 */  mtc1      $at, $f21
/* 37C7D4 E007A294 4480A000 */  mtc1      $zero, $f20
.LE007A298:
/* 37C7D8 E007A298 44938000 */  mtc1      $s3, $f16
/* 37C7DC E007A29C 00000000 */  nop       
/* 37C7E0 E007A2A0 46808420 */  cvt.s.w   $f16, $f16
/* 37C7E4 E007A2A4 4406B000 */  mfc1      $a2, $f22
/* 37C7E8 E007A2A8 4407C000 */  mfc1      $a3, $f24
/* 37C7EC E007A2AC 44058000 */  mfc1      $a1, $f16
/* 37C7F0 E007A2B0 27A40030 */  addiu     $a0, $sp, 0x30
/* 37C7F4 E007A2B4 AE00FFAC */  sw        $zero, -0x54($s0)
/* 37C7F8 E007A2B8 AE00FFB0 */  sw        $zero, -0x50($s0)
/* 37C7FC E007A2BC AE00FFB4 */  sw        $zero, -0x4c($s0)
/* 37C800 E007A2C0 0C080104 */  jal       func_E0200410
/* 37C804 E007A2C4 E7BA0010 */   swc1     $f26, 0x10($sp)
/* 37C808 E007A2C8 3C01E008 */  lui       $at, %hi(D_E007AC00)
/* 37C80C E007A2CC D42EAC00 */  ldc1      $f14, %lo(D_E007AC00)($at)
/* 37C810 E007A2D0 4600B107 */  neg.s     $f4, $f22
/* 37C814 E007A2D4 46002121 */  cvt.d.s   $f4, $f4
/* 37C818 E007A2D8 462E2102 */  mul.d     $f4, $f4, $f14
/* 37C81C E007A2DC 00000000 */  nop       
/* 37C820 E007A2E0 4600C087 */  neg.s     $f2, $f24
/* 37C824 E007A2E4 460010A1 */  cvt.d.s   $f2, $f2
/* 37C828 E007A2E8 462E1082 */  mul.d     $f2, $f2, $f14
/* 37C82C E007A2EC 00000000 */  nop       
/* 37C830 E007A2F0 4600D007 */  neg.s     $f0, $f26
/* 37C834 E007A2F4 46000021 */  cvt.d.s   $f0, $f0
/* 37C838 E007A2F8 462E0002 */  mul.d     $f0, $f0, $f14
/* 37C83C E007A2FC 00000000 */  nop       
/* 37C840 E007A300 46342102 */  mul.d     $f4, $f4, $f20
/* 37C844 E007A304 00000000 */  nop       
/* 37C848 E007A308 46341082 */  mul.d     $f2, $f2, $f20
/* 37C84C E007A30C 00000000 */  nop       
/* 37C850 E007A310 4616B180 */  add.s     $f6, $f22, $f22
/* 37C854 E007A314 4618C200 */  add.s     $f8, $f24, $f24
/* 37C858 E007A318 461AD280 */  add.s     $f10, $f26, $f26
/* 37C85C E007A31C E606FFC4 */  swc1      $f6, -0x3c($s0)
/* 37C860 E007A320 46340002 */  mul.d     $f0, $f0, $f20
/* 37C864 E007A324 00000000 */  nop       
/* 37C868 E007A328 E606FFB8 */  swc1      $f6, -0x48($s0)
/* 37C86C E007A32C E608FFC8 */  swc1      $f8, -0x38($s0)
/* 37C870 E007A330 E608FFBC */  swc1      $f8, -0x44($s0)
/* 37C874 E007A334 E60AFFCC */  swc1      $f10, -0x34($s0)
/* 37C878 E007A338 E60AFFC0 */  swc1      $f10, -0x40($s0)
/* 37C87C E007A33C 46202120 */  cvt.s.d   $f4, $f4
/* 37C880 E007A340 462010A0 */  cvt.s.d   $f2, $f2
/* 37C884 E007A344 46200020 */  cvt.s.d   $f0, $f0
/* 37C888 E007A348 E604FFDC */  swc1      $f4, -0x24($s0)
/* 37C88C E007A34C E602FFE0 */  swc1      $f2, -0x20($s0)
/* 37C890 E007A350 E600FFE4 */  swc1      $f0, -0x1c($s0)
/* 37C894 E007A354 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 37C898 E007A358 461E0002 */  mul.s     $f0, $f0, $f30
/* 37C89C E007A35C 00000000 */  nop       
/* 37C8A0 E007A360 C7A40040 */  lwc1      $f4, 0x40($sp)
/* 37C8A4 E007A364 C7B00070 */  lwc1      $f16, 0x70($sp)
/* 37C8A8 E007A368 46102102 */  mul.s     $f4, $f4, $f16
/* 37C8AC E007A36C 00000000 */  nop       
/* 37C8B0 E007A370 C7A20050 */  lwc1      $f2, 0x50($sp)
/* 37C8B4 E007A374 461C1082 */  mul.s     $f2, $f2, $f28
/* 37C8B8 E007A378 00000000 */  nop       
/* 37C8BC E007A37C 46040000 */  add.s     $f0, $f0, $f4
/* 37C8C0 E007A380 46020000 */  add.s     $f0, $f0, $f2
/* 37C8C4 E007A384 3C01E008 */  lui       $at, %hi(D_E007AC08)
/* 37C8C8 E007A388 D42EAC08 */  ldc1      $f14, %lo(D_E007AC08)($at)
/* 37C8CC E007A38C 46000021 */  cvt.d.s   $f0, $f0
/* 37C8D0 E007A390 462E0002 */  mul.d     $f0, $f0, $f14
/* 37C8D4 E007A394 00000000 */  nop       
/* 37C8D8 E007A398 46340002 */  mul.d     $f0, $f0, $f20
/* 37C8DC E007A39C 00000000 */  nop       
/* 37C8E0 E007A3A0 46200020 */  cvt.s.d   $f0, $f0
/* 37C8E4 E007A3A4 E600FFD0 */  swc1      $f0, -0x30($s0)
/* 37C8E8 E007A3A8 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 37C8EC E007A3AC 461E0002 */  mul.s     $f0, $f0, $f30
/* 37C8F0 E007A3B0 00000000 */  nop       
/* 37C8F4 E007A3B4 C7A40044 */  lwc1      $f4, 0x44($sp)
/* 37C8F8 E007A3B8 46102102 */  mul.s     $f4, $f4, $f16
/* 37C8FC E007A3BC 00000000 */  nop       
/* 37C900 E007A3C0 C7A20054 */  lwc1      $f2, 0x54($sp)
/* 37C904 E007A3C4 461C1082 */  mul.s     $f2, $f2, $f28
/* 37C908 E007A3C8 00000000 */  nop       
/* 37C90C E007A3CC 46040000 */  add.s     $f0, $f0, $f4
/* 37C910 E007A3D0 46020000 */  add.s     $f0, $f0, $f2
/* 37C914 E007A3D4 46000021 */  cvt.d.s   $f0, $f0
/* 37C918 E007A3D8 462E0002 */  mul.d     $f0, $f0, $f14
/* 37C91C E007A3DC 00000000 */  nop       
/* 37C920 E007A3E0 46340002 */  mul.d     $f0, $f0, $f20
/* 37C924 E007A3E4 00000000 */  nop       
/* 37C928 E007A3E8 46200020 */  cvt.s.d   $f0, $f0
/* 37C92C E007A3EC E600FFD4 */  swc1      $f0, -0x2c($s0)
/* 37C930 E007A3F0 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 37C934 E007A3F4 461E0002 */  mul.s     $f0, $f0, $f30
/* 37C938 E007A3F8 00000000 */  nop       
/* 37C93C E007A3FC C7A40048 */  lwc1      $f4, 0x48($sp)
/* 37C940 E007A400 46102102 */  mul.s     $f4, $f4, $f16
/* 37C944 E007A404 00000000 */  nop       
/* 37C948 E007A408 C7A20058 */  lwc1      $f2, 0x58($sp)
/* 37C94C E007A40C 461C1082 */  mul.s     $f2, $f2, $f28
/* 37C950 E007A410 00000000 */  nop       
/* 37C954 E007A414 46040000 */  add.s     $f0, $f0, $f4
/* 37C958 E007A418 46020000 */  add.s     $f0, $f0, $f2
/* 37C95C E007A41C 46000021 */  cvt.d.s   $f0, $f0
/* 37C960 E007A420 462E0002 */  mul.d     $f0, $f0, $f14
/* 37C964 E007A424 00000000 */  nop       
/* 37C968 E007A428 26730048 */  addiu     $s3, $s3, 0x48
/* 37C96C E007A42C 46340002 */  mul.d     $f0, $f0, $f20
/* 37C970 E007A430 00000000 */  nop       
/* 37C974 E007A434 3C0141A0 */  lui       $at, 0x41a0
/* 37C978 E007A438 44813000 */  mtc1      $at, $f6
/* 37C97C E007A43C 3C014080 */  lui       $at, 0x4080
/* 37C980 E007A440 44812000 */  mtc1      $at, $f4
/* 37C984 E007A444 3C013F00 */  lui       $at, 0x3f00
/* 37C988 E007A448 44811000 */  mtc1      $at, $f2
/* 37C98C E007A44C 24040168 */  addiu     $a0, $zero, 0x168
/* 37C990 E007A450 E606FFF4 */  swc1      $f6, -0xc($s0)
/* 37C994 E007A454 E604FFEC */  swc1      $f4, -0x14($s0)
/* 37C998 E007A458 E602FFE8 */  swc1      $f2, -0x18($s0)
/* 37C99C E007A45C 46200020 */  cvt.s.d   $f0, $f0
/* 37C9A0 E007A460 0C080000 */  jal       func_E0200000
/* 37C9A4 E007A464 E600FFD8 */   swc1     $f0, -0x28($s0)
/* 37C9A8 E007A468 3C046666 */  lui       $a0, 0x6666
/* 37C9AC E007A46C 34846667 */  ori       $a0, $a0, 0x6667
/* 37C9B0 E007A470 2623FFFF */  addiu     $v1, $s1, -1
/* 37C9B4 E007A474 26310001 */  addiu     $s1, $s1, 1
/* 37C9B8 E007A478 44820000 */  mtc1      $v0, $f0
/* 37C9BC E007A47C 00000000 */  nop       
/* 37C9C0 E007A480 46800020 */  cvt.s.w   $f0, $f0
/* 37C9C4 E007A484 240200FF */  addiu     $v0, $zero, 0xff
/* 37C9C8 E007A488 AE02FFFC */  sw        $v0, -4($s0)
/* 37C9CC E007A48C 2402000A */  addiu     $v0, $zero, 0xa
/* 37C9D0 E007A490 00640018 */  mult      $v1, $a0
/* 37C9D4 E007A494 00031FC3 */  sra       $v1, $v1, 0x1f
/* 37C9D8 E007A498 E600FFF8 */  swc1      $f0, -8($s0)
/* 37C9DC E007A49C E600FFF0 */  swc1      $f0, -0x10($s0)
/* 37C9E0 E007A4A0 AE020000 */  sw        $v0, ($s0)
/* 37C9E4 E007A4A4 00004010 */  mfhi      $t0
/* 37C9E8 E007A4A8 00081043 */  sra       $v0, $t0, 1
/* 37C9EC E007A4AC 00431023 */  subu      $v0, $v0, $v1
/* 37C9F0 E007A4B0 00021040 */  sll       $v0, $v0, 1
/* 37C9F4 E007A4B4 AE020008 */  sw        $v0, 8($s0)
/* 37C9F8 E007A4B8 0232102A */  slt       $v0, $s1, $s2
/* 37C9FC E007A4BC 1440FF76 */  bnez      $v0, .LE007A298
/* 37CA00 E007A4C0 26100068 */   addiu    $s0, $s0, 0x68
.LE007A4C4:
/* 37CA04 E007A4C4 8FA200E0 */  lw        $v0, 0xe0($sp)
/* 37CA08 E007A4C8 AC540000 */  sw        $s4, ($v0)
.LE007A4CC:
/* 37CA0C E007A4CC 8FBF008C */  lw        $ra, 0x8c($sp)
/* 37CA10 E007A4D0 8FB40088 */  lw        $s4, 0x88($sp)
/* 37CA14 E007A4D4 8FB30084 */  lw        $s3, 0x84($sp)
/* 37CA18 E007A4D8 8FB20080 */  lw        $s2, 0x80($sp)
/* 37CA1C E007A4DC 8FB1007C */  lw        $s1, 0x7c($sp)
/* 37CA20 E007A4E0 8FB00078 */  lw        $s0, 0x78($sp)
/* 37CA24 E007A4E4 D7BE00B8 */  ldc1      $f30, 0xb8($sp)
/* 37CA28 E007A4E8 D7BC00B0 */  ldc1      $f28, 0xb0($sp)
/* 37CA2C E007A4EC D7BA00A8 */  ldc1      $f26, 0xa8($sp)
/* 37CA30 E007A4F0 D7B800A0 */  ldc1      $f24, 0xa0($sp)
/* 37CA34 E007A4F4 D7B60098 */  ldc1      $f22, 0x98($sp)
/* 37CA38 E007A4F8 D7B40090 */  ldc1      $f20, 0x90($sp)
/* 37CA3C E007A4FC 03E00008 */  jr        $ra
/* 37CA40 E007A500 27BD00C0 */   addiu    $sp, $sp, 0xc0
