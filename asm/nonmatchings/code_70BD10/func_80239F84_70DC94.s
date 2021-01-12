.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80239F84_70DC94
/* 70DC94 80239F84 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 70DC98 80239F88 AFB10014 */  sw        $s1, 0x14($sp)
/* 70DC9C 80239F8C AFBF001C */  sw        $ra, 0x1c($sp)
/* 70DCA0 80239F90 AFB20018 */  sw        $s2, 0x18($sp)
/* 70DCA4 80239F94 AFB00010 */  sw        $s0, 0x10($sp)
/* 70DCA8 80239F98 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 70DCAC 80239F9C 10A00006 */  beqz      $a1, .L80239FB8
/* 70DCB0 80239FA0 0080882D */   daddu    $s1, $a0, $zero
/* 70DCB4 80239FA4 8E2400AC */  lw        $a0, 0xac($s1)
/* 70DCB8 80239FA8 0C09A75B */  jal       get_actor
/* 70DCBC 80239FAC 00000000 */   nop
/* 70DCC0 80239FB0 AE220074 */  sw        $v0, 0x74($s1)
/* 70DCC4 80239FB4 AE200070 */  sw        $zero, 0x70($s1)
.L80239FB8:
/* 70DCC8 80239FB8 8E300074 */  lw        $s0, 0x74($s1)
/* 70DCCC 80239FBC 8E230070 */  lw        $v1, 0x70($s1)
/* 70DCD0 80239FC0 10600006 */  beqz      $v1, .L80239FDC
/* 70DCD4 80239FC4 2612000C */   addiu    $s2, $s0, 0xc
/* 70DCD8 80239FC8 24020001 */  addiu     $v0, $zero, 1
/* 70DCDC 80239FCC 1062001B */  beq       $v1, $v0, .L8023A03C
/* 70DCE0 80239FD0 00000000 */   nop
/* 70DCE4 80239FD4 0808E859 */  j         .L8023A164
/* 70DCE8 80239FD8 00000000 */   nop
.L80239FDC:
/* 70DCEC 80239FDC 3C038024 */  lui       $v1, %hi(D_8023D330)
/* 70DCF0 80239FE0 2463D330 */  addiu     $v1, $v1, %lo(D_8023D330)
/* 70DCF4 80239FE4 0200202D */  daddu     $a0, $s0, $zero
/* 70DCF8 80239FE8 C6000144 */  lwc1      $f0, 0x144($s0)
/* 70DCFC 80239FEC C6020148 */  lwc1      $f2, 0x148($s0)
/* 70DD00 80239FF0 C604014C */  lwc1      $f4, 0x14c($s0)
/* 70DD04 80239FF4 3C0140B0 */  lui       $at, 0x40b0
/* 70DD08 80239FF8 44813000 */  mtc1      $at, $f6
/* 70DD0C 80239FFC 8C620000 */  lw        $v0, ($v1)
/* 70DD10 8023A000 24050016 */  addiu     $a1, $zero, 0x16
/* 70DD14 8023A004 A6000070 */  sh        $zero, 0x70($s0)
/* 70DD18 8023A008 24420001 */  addiu     $v0, $v0, 1
/* 70DD1C 8023A00C E600000C */  swc1      $f0, 0xc($s0)
/* 70DD20 8023A010 E6020010 */  swc1      $f2, 0x10($s0)
/* 70DD24 8023A014 E6040014 */  swc1      $f4, 0x14($s0)
/* 70DD28 8023A018 E606004C */  swc1      $f6, 0x4c($s0)
/* 70DD2C 8023A01C AC620000 */  sw        $v0, ($v1)
/* 70DD30 8023A020 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 70DD34 8023A024 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 70DD38 8023A028 0C09DC58 */  jal       dispatch_event_actor
/* 70DD3C 8023A02C AC400188 */   sw       $zero, 0x188($v0)
/* 70DD40 8023A030 24020001 */  addiu     $v0, $zero, 1
/* 70DD44 8023A034 0808E859 */  j         .L8023A164
/* 70DD48 8023A038 AE220070 */   sw       $v0, 0x70($s1)
.L8023A03C:
/* 70DD4C 8023A03C C602000C */  lwc1      $f2, 0xc($s0)
/* 70DD50 8023A040 C600004C */  lwc1      $f0, 0x4c($s0)
/* 70DD54 8023A044 86020070 */  lh        $v0, 0x70($s0)
/* 70DD58 8023A048 46001080 */  add.s     $f2, $f2, $f0
/* 70DD5C 8023A04C 3C0140C9 */  lui       $at, 0x40c9
/* 70DD60 8023A050 34210FD0 */  ori       $at, $at, 0xfd0
/* 70DD64 8023A054 44810000 */  mtc1      $at, $f0
/* 70DD68 8023A058 44826000 */  mtc1      $v0, $f12
/* 70DD6C 8023A05C 00000000 */  nop
/* 70DD70 8023A060 46806320 */  cvt.s.w   $f12, $f12
/* 70DD74 8023A064 46006302 */  mul.s     $f12, $f12, $f0
/* 70DD78 8023A068 00000000 */  nop
/* 70DD7C 8023A06C C6140010 */  lwc1      $f20, 0x10($s0)
/* 70DD80 8023A070 3C0143B4 */  lui       $at, 0x43b4
/* 70DD84 8023A074 44810000 */  mtc1      $at, $f0
/* 70DD88 8023A078 4600A521 */  cvt.d.s   $f20, $f20
/* 70DD8C 8023A07C E602000C */  swc1      $f2, 0xc($s0)
/* 70DD90 8023A080 0C00A85B */  jal       sin_rad
/* 70DD94 8023A084 46006303 */   div.s    $f12, $f12, $f0
/* 70DD98 8023A088 46000000 */  add.s     $f0, $f0, $f0
/* 70DD9C 8023A08C 3C014049 */  lui       $at, 0x4049
/* 70DDA0 8023A090 34210FD0 */  ori       $at, $at, 0xfd0
/* 70DDA4 8023A094 44816000 */  mtc1      $at, $f12
/* 70DDA8 8023A098 00000000 */  nop
/* 70DDAC 8023A09C 460C0302 */  mul.s     $f12, $f0, $f12
/* 70DDB0 8023A0A0 0C00A85B */  jal       sin_rad
/* 70DDB4 8023A0A4 00000000 */   nop
/* 70DDB8 8023A0A8 3C018024 */  lui       $at, %hi(D_8023D1D0)
/* 70DDBC 8023A0AC D422D1D0 */  ldc1      $f2, %lo(D_8023D1D0)($at)
/* 70DDC0 8023A0B0 46000021 */  cvt.d.s   $f0, $f0
/* 70DDC4 8023A0B4 46220002 */  mul.d     $f0, $f0, $f2
/* 70DDC8 8023A0B8 00000000 */  nop
/* 70DDCC 8023A0BC 96030070 */  lhu       $v1, 0x70($s0)
/* 70DDD0 8023A0C0 3C013FE0 */  lui       $at, 0x3fe0
/* 70DDD4 8023A0C4 44811800 */  mtc1      $at, $f3
/* 70DDD8 8023A0C8 44801000 */  mtc1      $zero, $f2
/* 70DDDC 8023A0CC 24630006 */  addiu     $v1, $v1, 6
/* 70DDE0 8023A0D0 46220000 */  add.d     $f0, $f0, $f2
/* 70DDE4 8023A0D4 00031400 */  sll       $v0, $v1, 0x10
/* 70DDE8 8023A0D8 00021403 */  sra       $v0, $v0, 0x10
/* 70DDEC 8023A0DC 4620A500 */  add.d     $f20, $f20, $f0
/* 70DDF0 8023A0E0 44826000 */  mtc1      $v0, $f12
/* 70DDF4 8023A0E4 00000000 */  nop
/* 70DDF8 8023A0E8 46806320 */  cvt.s.w   $f12, $f12
/* 70DDFC 8023A0EC A6030070 */  sh        $v1, 0x70($s0)
/* 70DE00 8023A0F0 4620A520 */  cvt.s.d   $f20, $f20
/* 70DE04 8023A0F4 0C00A6C9 */  jal       clamp_angle
/* 70DE08 8023A0F8 E6140010 */   swc1     $f20, 0x10($s0)
/* 70DE0C 8023A0FC C60C018C */  lwc1      $f12, 0x18c($s0)
/* 70DE10 8023A100 3C014204 */  lui       $at, 0x4204
/* 70DE14 8023A104 44811000 */  mtc1      $at, $f2
/* 70DE18 8023A108 00000000 */  nop
/* 70DE1C 8023A10C 46026300 */  add.s     $f12, $f12, $f2
/* 70DE20 8023A110 4600020D */  trunc.w.s $f8, $f0
/* 70DE24 8023A114 44024000 */  mfc1      $v0, $f8
/* 70DE28 8023A118 00000000 */  nop
/* 70DE2C 8023A11C A6020070 */  sh        $v0, 0x70($s0)
/* 70DE30 8023A120 0C00A6C9 */  jal       clamp_angle
/* 70DE34 8023A124 E60C018C */   swc1     $f12, 0x18c($s0)
/* 70DE38 8023A128 C604000C */  lwc1      $f4, 0xc($s0)
/* 70DE3C 8023A12C 3C014370 */  lui       $at, 0x4370
/* 70DE40 8023A130 44811000 */  mtc1      $at, $f2
/* 70DE44 8023A134 00000000 */  nop
/* 70DE48 8023A138 4604103C */  c.lt.s    $f2, $f4
/* 70DE4C 8023A13C 00000000 */  nop
/* 70DE50 8023A140 45000008 */  bc1f      .L8023A164
/* 70DE54 8023A144 E600018C */   swc1     $f0, 0x18c($s0)
/* 70DE58 8023A148 3C048024 */  lui       $a0, %hi(D_8023D330)
/* 70DE5C 8023A14C 2484D330 */  addiu     $a0, $a0, %lo(D_8023D330)
/* 70DE60 8023A150 8C830000 */  lw        $v1, ($a0)
/* 70DE64 8023A154 24020002 */  addiu     $v0, $zero, 2
/* 70DE68 8023A158 2463FFFF */  addiu     $v1, $v1, -1
/* 70DE6C 8023A15C 0808E860 */  j         .L8023A180
/* 70DE70 8023A160 AC830000 */   sw       $v1, ($a0)
.L8023A164:
/* 70DE74 8023A164 C6400000 */  lwc1      $f0, ($s2)
/* 70DE78 8023A168 E6000144 */  swc1      $f0, 0x144($s0)
/* 70DE7C 8023A16C C6400004 */  lwc1      $f0, 4($s2)
/* 70DE80 8023A170 E6000148 */  swc1      $f0, 0x148($s0)
/* 70DE84 8023A174 C6400008 */  lwc1      $f0, 8($s2)
/* 70DE88 8023A178 0000102D */  daddu     $v0, $zero, $zero
/* 70DE8C 8023A17C E600014C */  swc1      $f0, 0x14c($s0)
.L8023A180:
/* 70DE90 8023A180 8FBF001C */  lw        $ra, 0x1c($sp)
/* 70DE94 8023A184 8FB20018 */  lw        $s2, 0x18($sp)
/* 70DE98 8023A188 8FB10014 */  lw        $s1, 0x14($sp)
/* 70DE9C 8023A18C 8FB00010 */  lw        $s0, 0x10($sp)
/* 70DEA0 8023A190 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 70DEA4 8023A194 03E00008 */  jr        $ra
/* 70DEA8 8023A198 27BD0028 */   addiu    $sp, $sp, 0x28
