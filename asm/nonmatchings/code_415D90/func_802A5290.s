.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A5290
/* 41A020 802A5290 3C02802B */  lui       $v0, %hi(D_802AD604)
/* 41A024 802A5294 9042D604 */  lbu       $v0, %lo(D_802AD604)($v0)
/* 41A028 802A5298 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 41A02C 802A529C AFB70034 */  sw        $s7, 0x34($sp)
/* 41A030 802A52A0 00A0B82D */  daddu     $s7, $a1, $zero
/* 41A034 802A52A4 AFBF003C */  sw        $ra, 0x3c($sp)
/* 41A038 802A52A8 AFBE0038 */  sw        $fp, 0x38($sp)
/* 41A03C 802A52AC AFB60030 */  sw        $s6, 0x30($sp)
/* 41A040 802A52B0 AFB5002C */  sw        $s5, 0x2c($sp)
/* 41A044 802A52B4 AFB40028 */  sw        $s4, 0x28($sp)
/* 41A048 802A52B8 AFB30024 */  sw        $s3, 0x24($sp)
/* 41A04C 802A52BC AFB20020 */  sw        $s2, 0x20($sp)
/* 41A050 802A52C0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 41A054 802A52C4 AFB00018 */  sw        $s0, 0x18($sp)
/* 41A058 802A52C8 24420001 */  addiu     $v0, $v0, 1
/* 41A05C 802A52CC 00021600 */  sll       $v0, $v0, 0x18
/* 41A060 802A52D0 00021E03 */  sra       $v1, $v0, 0x18
/* 41A064 802A52D4 2C62002B */  sltiu     $v0, $v1, 0x2b
/* 41A068 802A52D8 104000FB */  beqz      $v0, .L802A56C8
/* 41A06C 802A52DC AFA60048 */   sw       $a2, 0x48($sp)
/* 41A070 802A52E0 00031080 */  sll       $v0, $v1, 2
/* 41A074 802A52E4 3C01802B */  lui       $at, %hi(jtbl_802ABAA8)
/* 41A078 802A52E8 00220821 */  addu      $at, $at, $v0
/* 41A07C 802A52EC 8C22BAA8 */  lw        $v0, %lo(jtbl_802ABAA8)($at)
/* 41A080 802A52F0 00400008 */  jr        $v0
/* 41A084 802A52F4 00000000 */   nop
glabel L802A52F8_41A088
/* 41A088 802A52F8 3C03802B */  lui       $v1, %hi(D_802AD608)
/* 41A08C 802A52FC 8063D608 */  lb        $v1, %lo(D_802AD608)($v1)
/* 41A090 802A5300 3C08802B */  lui       $t0, %hi(D_802AD60C)
/* 41A094 802A5304 8508D60C */  lh        $t0, %lo(D_802AD60C)($t0)
/* 41A098 802A5308 3C013FE0 */  lui       $at, 0x3fe0
/* 41A09C 802A530C 44811800 */  mtc1      $at, $f3
/* 41A0A0 802A5310 44801000 */  mtc1      $zero, $f2
/* 41A0A4 802A5314 00031823 */  negu      $v1, $v1
/* 41A0A8 802A5318 00031040 */  sll       $v0, $v1, 1
/* 41A0AC 802A531C 00431021 */  addu      $v0, $v0, $v1
/* 41A0B0 802A5320 00021080 */  sll       $v0, $v0, 2
/* 41A0B4 802A5324 00438821 */  addu      $s1, $v0, $v1
/* 41A0B8 802A5328 02281023 */  subu      $v0, $s1, $t0
/* 41A0BC 802A532C 44820000 */  mtc1      $v0, $f0
/* 41A0C0 802A5330 00000000 */  nop
/* 41A0C4 802A5334 46800021 */  cvt.d.w   $f0, $f0
/* 41A0C8 802A5338 46220002 */  mul.d     $f0, $f0, $f2
/* 41A0CC 802A533C 00000000 */  nop
/* 41A0D0 802A5340 4620018D */  trunc.w.d $f6, $f0
/* 41A0D4 802A5344 44023000 */  mfc1      $v0, $f6
/* 41A0D8 802A5348 00000000 */  nop
/* 41A0DC 802A534C 14400002 */  bnez      $v0, .L802A5358
/* 41A0E0 802A5350 01024021 */   addu     $t0, $t0, $v0
/* 41A0E4 802A5354 0220402D */  daddu     $t0, $s1, $zero
.L802A5358:
/* 41A0E8 802A5358 26F50004 */  addiu     $s5, $s7, 4
/* 41A0EC 802A535C 44951000 */  mtc1      $s5, $f2
/* 41A0F0 802A5360 00000000 */  nop
/* 41A0F4 802A5364 468010A0 */  cvt.s.w   $f2, $f2
/* 41A0F8 802A5368 26F50021 */  addiu     $s5, $s7, 0x21
/* 41A0FC 802A536C 0000B02D */  daddu     $s6, $zero, $zero
/* 41A100 802A5370 02C0982D */  daddu     $s3, $s6, $zero
/* 41A104 802A5374 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 41A108 802A5378 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 41A10C 802A537C 8FA90048 */  lw        $t1, 0x48($sp)
/* 41A110 802A5380 8CC40000 */  lw        $a0, ($a2)
/* 41A114 802A5384 3C03802B */  lui       $v1, %hi(D_802AD60A)
/* 41A118 802A5388 8063D60A */  lb        $v1, %lo(D_802AD60A)($v1)
/* 41A11C 802A538C 3C014080 */  lui       $at, 0x4080
/* 41A120 802A5390 44812000 */  mtc1      $at, $f4
/* 41A124 802A5394 3C05802B */  lui       $a1, %hi(D_802AD60C)
/* 41A128 802A5398 24A5D60C */  addiu     $a1, $a1, %lo(D_802AD60C)
/* 41A12C 802A539C A4A80000 */  sh        $t0, ($a1)
/* 41A130 802A53A0 25310012 */  addiu     $s1, $t1, 0x12
/* 41A134 802A53A4 00031040 */  sll       $v0, $v1, 1
/* 41A138 802A53A8 00431021 */  addu      $v0, $v0, $v1
/* 41A13C 802A53AC 00021080 */  sll       $v0, $v0, 2
/* 41A140 802A53B0 00431021 */  addu      $v0, $v0, $v1
/* 41A144 802A53B4 24420001 */  addiu     $v0, $v0, 1
/* 41A148 802A53B8 02224021 */  addu      $t0, $s1, $v0
/* 41A14C 802A53BC 46041082 */  mul.s     $f2, $f2, $f4
/* 41A150 802A53C0 00000000 */  nop
/* 41A154 802A53C4 0080382D */  daddu     $a3, $a0, $zero
/* 41A158 802A53C8 24840008 */  addiu     $a0, $a0, 8
/* 41A15C 802A53CC 44910000 */  mtc1      $s1, $f0
/* 41A160 802A53D0 00000000 */  nop
/* 41A164 802A53D4 46800020 */  cvt.s.w   $f0, $f0
/* 41A168 802A53D8 84A20000 */  lh        $v0, ($a1)
/* 41A16C 802A53DC 46040002 */  mul.s     $f0, $f0, $f4
/* 41A170 802A53E0 00000000 */  nop
/* 41A174 802A53E4 ACC40000 */  sw        $a0, ($a2)
/* 41A178 802A53E8 24420013 */  addiu     $v0, $v0, 0x13
/* 41A17C 802A53EC 01228821 */  addu      $s1, $t1, $v0
/* 41A180 802A53F0 26E2008E */  addiu     $v0, $s7, 0x8e
/* 41A184 802A53F4 4600118D */  trunc.w.s $f6, $f2
/* 41A188 802A53F8 44033000 */  mfc1      $v1, $f6
/* 41A18C 802A53FC 00000000 */  nop
/* 41A190 802A5400 30630FFF */  andi      $v1, $v1, 0xfff
/* 41A194 802A5404 00031B00 */  sll       $v1, $v1, 0xc
/* 41A198 802A5408 4600018D */  trunc.w.s $f6, $f0
/* 41A19C 802A540C 44043000 */  mfc1      $a0, $f6
/* 41A1A0 802A5410 00000000 */  nop
/* 41A1A4 802A5414 30840FFF */  andi      $a0, $a0, 0xfff
/* 41A1A8 802A5418 44821000 */  mtc1      $v0, $f2
/* 41A1AC 802A541C 00000000 */  nop
/* 41A1B0 802A5420 468010A0 */  cvt.s.w   $f2, $f2
/* 41A1B4 802A5424 3C02ED00 */  lui       $v0, 0xed00
/* 41A1B8 802A5428 46041082 */  mul.s     $f2, $f2, $f4
/* 41A1BC 802A542C 00000000 */  nop
/* 41A1C0 802A5430 00822025 */  or        $a0, $a0, $v0
/* 41A1C4 802A5434 00641825 */  or        $v1, $v1, $a0
/* 41A1C8 802A5438 44880000 */  mtc1      $t0, $f0
/* 41A1CC 802A543C 00000000 */  nop
/* 41A1D0 802A5440 46800020 */  cvt.s.w   $f0, $f0
/* 41A1D4 802A5444 3C04802B */  lui       $a0, %hi(D_802AD66C)
/* 41A1D8 802A5448 8C84D66C */  lw        $a0, %lo(D_802AD66C)($a0)
/* 41A1DC 802A544C 46040002 */  mul.s     $f0, $f0, $f4
/* 41A1E0 802A5450 00000000 */  nop
/* 41A1E4 802A5454 ACE30000 */  sw        $v1, ($a3)
/* 41A1E8 802A5458 4600118D */  trunc.w.s $f6, $f2
/* 41A1EC 802A545C 44023000 */  mfc1      $v0, $f6
/* 41A1F0 802A5460 00000000 */  nop
/* 41A1F4 802A5464 30420FFF */  andi      $v0, $v0, 0xfff
/* 41A1F8 802A5468 00021300 */  sll       $v0, $v0, 0xc
/* 41A1FC 802A546C 4600018D */  trunc.w.s $f6, $f0
/* 41A200 802A5470 44033000 */  mfc1      $v1, $f6
/* 41A204 802A5474 00000000 */  nop
/* 41A208 802A5478 30630FFF */  andi      $v1, $v1, 0xfff
/* 41A20C 802A547C 00431025 */  or        $v0, $v0, $v1
/* 41A210 802A5480 18800028 */  blez      $a0, .L802A5524
/* 41A214 802A5484 ACE20004 */   sw       $v0, 4($a3)
/* 41A218 802A5488 241E0001 */  addiu     $fp, $zero, 1
/* 41A21C 802A548C 3C14802B */  lui       $s4, %hi(D_802AD690)
/* 41A220 802A5490 2694D690 */  addiu     $s4, $s4, %lo(D_802AD690)
/* 41A224 802A5494 3C12802B */  lui       $s2, %hi(D_802AD678)
/* 41A228 802A5498 2652D678 */  addiu     $s2, $s2, %lo(D_802AD678)
.L802A549C:
/* 41A22C 802A549C 24090005 */  addiu     $t1, $zero, 5
/* 41A230 802A54A0 8E420000 */  lw        $v0, ($s2)
/* 41A234 802A54A4 3C10802B */  lui       $s0, %hi(D_802AD614)
/* 41A238 802A54A8 8210D614 */  lb        $s0, %lo(D_802AD614)($s0)
/* 41A23C 802A54AC 14490005 */  bne       $v0, $t1, .L802A54C4
/* 41A240 802A54B0 00000000 */   nop
/* 41A244 802A54B4 0C03A752 */  jal       is_ability_active
/* 41A248 802A54B8 2404001A */   addiu    $a0, $zero, 0x1a
/* 41A24C 802A54BC 54400001 */  bnel      $v0, $zero, .L802A54C4
/* 41A250 802A54C0 24100037 */   addiu    $s0, $zero, 0x37
.L802A54C4:
/* 41A254 802A54C4 8E820000 */  lw        $v0, ($s4)
/* 41A258 802A54C8 14400002 */  bnez      $v0, .L802A54D4
/* 41A25C 802A54CC 00161880 */   sll      $v1, $s6, 2
/* 41A260 802A54D0 2410000B */  addiu     $s0, $zero, 0xb
.L802A54D4:
/* 41A264 802A54D4 02A0282D */  daddu     $a1, $s5, $zero
/* 41A268 802A54D8 0220302D */  daddu     $a2, $s1, $zero
/* 41A26C 802A54DC 2631000D */  addiu     $s1, $s1, 0xd
/* 41A270 802A54E0 26520004 */  addiu     $s2, $s2, 4
/* 41A274 802A54E4 26730001 */  addiu     $s3, $s3, 1
/* 41A278 802A54E8 3C09802B */  lui       $t1, %hi(D_802AD658)
/* 41A27C 802A54EC 2529D658 */  addiu     $t1, $t1, %lo(D_802AD658)
/* 41A280 802A54F0 00691021 */  addu      $v0, $v1, $t1
/* 41A284 802A54F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 41A288 802A54F8 AFBE0014 */  sw        $fp, 0x14($sp)
/* 41A28C 802A54FC 8C440000 */  lw        $a0, ($v0)
/* 41A290 802A5500 3C07802B */  lui       $a3, %hi(D_802AD624)
/* 41A294 802A5504 8CE7D624 */  lw        $a3, %lo(D_802AD624)($a3)
/* 41A298 802A5508 0C04993B */  jal       draw_string
/* 41A29C 802A550C 26940004 */   addiu    $s4, $s4, 4
/* 41A2A0 802A5510 3C02802B */  lui       $v0, %hi(D_802AD66C)
/* 41A2A4 802A5514 8C42D66C */  lw        $v0, %lo(D_802AD66C)($v0)
/* 41A2A8 802A5518 0262102A */  slt       $v0, $s3, $v0
/* 41A2AC 802A551C 1440FFDF */  bnez      $v0, .L802A549C
/* 41A2B0 802A5520 26D60001 */   addiu    $s6, $s6, 1
.L802A5524:
/* 41A2B4 802A5524 26F50018 */  addiu     $s5, $s7, 0x18
/* 41A2B8 802A5528 0000982D */  daddu     $s3, $zero, $zero
/* 41A2BC 802A552C 3C02802B */  lui       $v0, %hi(D_802AD60C)
/* 41A2C0 802A5530 8442D60C */  lh        $v0, %lo(D_802AD60C)($v0)
/* 41A2C4 802A5534 8FA90048 */  lw        $t1, 0x48($sp)
/* 41A2C8 802A5538 3C03802B */  lui       $v1, %hi(D_802AD66C)
/* 41A2CC 802A553C 8C63D66C */  lw        $v1, %lo(D_802AD66C)($v1)
/* 41A2D0 802A5540 00491021 */  addu      $v0, $v0, $t1
/* 41A2D4 802A5544 18600015 */  blez      $v1, .L802A559C
/* 41A2D8 802A5548 24510018 */   addiu    $s1, $v0, 0x18
/* 41A2DC 802A554C 3C12802B */  lui       $s2, %hi(D_802AD628)
/* 41A2E0 802A5550 2652D628 */  addiu     $s2, $s2, %lo(D_802AD628)
.L802A5554:
/* 41A2E4 802A5554 02A0282D */  daddu     $a1, $s5, $zero
/* 41A2E8 802A5558 0220302D */  daddu     $a2, $s1, $zero
/* 41A2EC 802A555C 2631000D */  addiu     $s1, $s1, 0xd
/* 41A2F0 802A5560 8E500000 */  lw        $s0, ($s2)
/* 41A2F4 802A5564 26730001 */  addiu     $s3, $s3, 1
/* 41A2F8 802A5568 0C051261 */  jal       set_icon_render_pos
/* 41A2FC 802A556C 0200202D */   daddu    $a0, $s0, $zero
/* 41A300 802A5570 3C05802B */  lui       $a1, %hi(D_802AD624)
/* 41A304 802A5574 8CA5D624 */  lw        $a1, %lo(D_802AD624)($a1)
/* 41A308 802A5578 0C0513AC */  jal       icon_set_opacity
/* 41A30C 802A557C 0200202D */   daddu    $a0, $s0, $zero
/* 41A310 802A5580 0C0511F8 */  jal       draw_icon_2
/* 41A314 802A5584 0200202D */   daddu    $a0, $s0, $zero
/* 41A318 802A5588 3C02802B */  lui       $v0, %hi(D_802AD66C)
/* 41A31C 802A558C 8C42D66C */  lw        $v0, %lo(D_802AD66C)($v0)
/* 41A320 802A5590 0262102A */  slt       $v0, $s3, $v0
/* 41A324 802A5594 1440FFEF */  bnez      $v0, .L802A5554
/* 41A328 802A5598 26520004 */   addiu    $s2, $s2, 4
.L802A559C:
/* 41A32C 802A559C 3C03802B */  lui       $v1, %hi(D_802AD605)
/* 41A330 802A55A0 8063D605 */  lb        $v1, %lo(D_802AD605)($v1)
/* 41A334 802A55A4 3C02802B */  lui       $v0, %hi(D_802AD608)
/* 41A338 802A55A8 8042D608 */  lb        $v0, %lo(D_802AD608)($v0)
/* 41A33C 802A55AC 3C08802B */  lui       $t0, %hi(D_802AD60E)
/* 41A340 802A55B0 8508D60E */  lh        $t0, %lo(D_802AD60E)($t0)
/* 41A344 802A55B4 00621823 */  subu      $v1, $v1, $v0
/* 41A348 802A55B8 00031040 */  sll       $v0, $v1, 1
/* 41A34C 802A55BC 00431021 */  addu      $v0, $v0, $v1
/* 41A350 802A55C0 00021080 */  sll       $v0, $v0, 2
/* 41A354 802A55C4 00438821 */  addu      $s1, $v0, $v1
/* 41A358 802A55C8 02281023 */  subu      $v0, $s1, $t0
/* 41A35C 802A55CC 44820000 */  mtc1      $v0, $f0
/* 41A360 802A55D0 00000000 */  nop
/* 41A364 802A55D4 46800021 */  cvt.d.w   $f0, $f0
/* 41A368 802A55D8 4620018D */  trunc.w.d $f6, $f0
/* 41A36C 802A55DC 44023000 */  mfc1      $v0, $f6
/* 41A370 802A55E0 00000000 */  nop
/* 41A374 802A55E4 10400003 */  beqz      $v0, .L802A55F4
/* 41A378 802A55E8 26F5000A */   addiu    $s5, $s7, 0xa
/* 41A37C 802A55EC 080A957E */  j         .L802A55F8
/* 41A380 802A55F0 01024021 */   addu     $t0, $t0, $v0
.L802A55F4:
/* 41A384 802A55F4 0220402D */  daddu     $t0, $s1, $zero
.L802A55F8:
/* 41A388 802A55F8 02A0282D */  daddu     $a1, $s5, $zero
/* 41A38C 802A55FC 00083400 */  sll       $a2, $t0, 0x10
/* 41A390 802A5600 00063403 */  sra       $a2, $a2, 0x10
/* 41A394 802A5604 3C10802B */  lui       $s0, %hi(D_802AD618)
/* 41A398 802A5608 8E10D618 */  lw        $s0, %lo(D_802AD618)($s0)
/* 41A39C 802A560C 8FA90048 */  lw        $t1, 0x48($sp)
/* 41A3A0 802A5610 24C6001A */  addiu     $a2, $a2, 0x1a
/* 41A3A4 802A5614 3C01802B */  lui       $at, %hi(D_802AD60E)
/* 41A3A8 802A5618 A428D60E */  sh        $t0, %lo(D_802AD60E)($at)
/* 41A3AC 802A561C 01263021 */  addu      $a2, $t1, $a2
/* 41A3B0 802A5620 0C051261 */  jal       set_icon_render_pos
/* 41A3B4 802A5624 0200202D */   daddu    $a0, $s0, $zero
/* 41A3B8 802A5628 3C11802B */  lui       $s1, %hi(D_802AD624)
/* 41A3BC 802A562C 2631D624 */  addiu     $s1, $s1, %lo(D_802AD624)
/* 41A3C0 802A5630 8E250000 */  lw        $a1, ($s1)
/* 41A3C4 802A5634 0C0513AC */  jal       icon_set_opacity
/* 41A3C8 802A5638 0200202D */   daddu    $a0, $s0, $zero
/* 41A3CC 802A563C 0C0511EA */  jal       draw_icon_0
/* 41A3D0 802A5640 0200202D */   daddu    $a0, $s0, $zero
/* 41A3D4 802A5644 3C02802B */  lui       $v0, %hi(D_802AD608)
/* 41A3D8 802A5648 8042D608 */  lb        $v0, %lo(D_802AD608)($v0)
/* 41A3DC 802A564C 1840000C */  blez      $v0, .L802A5680
/* 41A3E0 802A5650 26E50043 */   addiu    $a1, $s7, 0x43
/* 41A3E4 802A5654 8FA90048 */  lw        $t1, 0x48($sp)
/* 41A3E8 802A5658 3C10802B */  lui       $s0, %hi(D_802AD61C)
/* 41A3EC 802A565C 8E10D61C */  lw        $s0, %lo(D_802AD61C)($s0)
/* 41A3F0 802A5660 25260010 */  addiu     $a2, $t1, 0x10
/* 41A3F4 802A5664 0C051261 */  jal       set_icon_render_pos
/* 41A3F8 802A5668 0200202D */   daddu    $a0, $s0, $zero
/* 41A3FC 802A566C 8E250000 */  lw        $a1, ($s1)
/* 41A400 802A5670 0C0513AC */  jal       icon_set_opacity
/* 41A404 802A5674 0200202D */   daddu    $a0, $s0, $zero
/* 41A408 802A5678 0C0511EA */  jal       draw_icon_0
/* 41A40C 802A567C 0200202D */   daddu    $a0, $s0, $zero
.L802A5680:
/* 41A410 802A5680 3C02802B */  lui       $v0, %hi(D_802AD609)
/* 41A414 802A5684 8042D609 */  lb        $v0, %lo(D_802AD609)($v0)
/* 41A418 802A5688 3C03802B */  lui       $v1, %hi(D_802AD66C)
/* 41A41C 802A568C 8C63D66C */  lw        $v1, %lo(D_802AD66C)($v1)
/* 41A420 802A5690 0043102A */  slt       $v0, $v0, $v1
/* 41A424 802A5694 1040000C */  beqz      $v0, .L802A56C8
/* 41A428 802A5698 26E50043 */   addiu    $a1, $s7, 0x43
/* 41A42C 802A569C 8FA90048 */  lw        $t1, 0x48($sp)
/* 41A430 802A56A0 3C10802B */  lui       $s0, %hi(D_802AD620)
/* 41A434 802A56A4 8E10D620 */  lw        $s0, %lo(D_802AD620)($s0)
/* 41A438 802A56A8 25260064 */  addiu     $a2, $t1, 0x64
/* 41A43C 802A56AC 0C051261 */  jal       set_icon_render_pos
/* 41A440 802A56B0 0200202D */   daddu    $a0, $s0, $zero
/* 41A444 802A56B4 8E250000 */  lw        $a1, ($s1)
/* 41A448 802A56B8 0C0513AC */  jal       icon_set_opacity
/* 41A44C 802A56BC 0200202D */   daddu    $a0, $s0, $zero
/* 41A450 802A56C0 0C0511EA */  jal       draw_icon_0
/* 41A454 802A56C4 0200202D */   daddu    $a0, $s0, $zero
.L802A56C8:
glabel L802A56C8_41A458
/* 41A458 802A56C8 8FBF003C */  lw        $ra, 0x3c($sp)
/* 41A45C 802A56CC 8FBE0038 */  lw        $fp, 0x38($sp)
/* 41A460 802A56D0 8FB70034 */  lw        $s7, 0x34($sp)
/* 41A464 802A56D4 8FB60030 */  lw        $s6, 0x30($sp)
/* 41A468 802A56D8 8FB5002C */  lw        $s5, 0x2c($sp)
/* 41A46C 802A56DC 8FB40028 */  lw        $s4, 0x28($sp)
/* 41A470 802A56E0 8FB30024 */  lw        $s3, 0x24($sp)
/* 41A474 802A56E4 8FB20020 */  lw        $s2, 0x20($sp)
/* 41A478 802A56E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 41A47C 802A56EC 8FB00018 */  lw        $s0, 0x18($sp)
/* 41A480 802A56F0 03E00008 */  jr        $ra
/* 41A484 802A56F4 27BD0040 */   addiu    $sp, $sp, 0x40
