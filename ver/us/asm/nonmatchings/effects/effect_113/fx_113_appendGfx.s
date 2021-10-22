.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_113_appendGfx
/* 3DC528 E00E2218 27BDFF18 */  addiu     $sp, $sp, -0xe8
/* 3DC52C E00E221C 0080302D */  daddu     $a2, $a0, $zero
/* 3DC530 E00E2220 3C07DB06 */  lui       $a3, 0xdb06
/* 3DC534 E00E2224 34E70024 */  ori       $a3, $a3, 0x24
/* 3DC538 E00E2228 27A40020 */  addiu     $a0, $sp, 0x20
/* 3DC53C E00E222C AFB300BC */  sw        $s3, 0xbc($sp)
/* 3DC540 E00E2230 3C130001 */  lui       $s3, 1
/* 3DC544 E00E2234 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 3DC548 E00E2238 244241F0 */  addiu     $v0, $v0, %lo(gMatrixListPos)
/* 3DC54C E00E223C AFB700CC */  sw        $s7, 0xcc($sp)
/* 3DC550 E00E2240 0040B82D */  daddu     $s7, $v0, $zero
/* 3DC554 E00E2244 3C0F0001 */  lui       $t7, 1
/* 3DC558 E00E2248 35EF1630 */  ori       $t7, $t7, 0x1630
/* 3DC55C E00E224C 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3DC560 E00E2250 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3DC564 E00E2254 AFB600C8 */  sw        $s6, 0xc8($sp)
/* 3DC568 E00E2258 0040B02D */  daddu     $s6, $v0, $zero
/* 3DC56C E00E225C AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 3DC570 E00E2260 AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 3DC574 E00E2264 AFB500C4 */  sw        $s5, 0xc4($sp)
/* 3DC578 E00E2268 AFB400C0 */  sw        $s4, 0xc0($sp)
/* 3DC57C E00E226C AFB200B8 */  sw        $s2, 0xb8($sp)
/* 3DC580 E00E2270 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 3DC584 E00E2274 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 3DC588 E00E2278 F7B600E0 */  sdc1      $f22, 0xe0($sp)
/* 3DC58C E00E227C F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 3DC590 E00E2280 AFAF00A8 */  sw        $t7, 0xa8($sp)
/* 3DC594 E00E2284 8EC50000 */  lw        $a1, ($s6)
/* 3DC598 E00E2288 8CD5000C */  lw        $s5, 0xc($a2)
/* 3DC59C E00E228C 00A0182D */  daddu     $v1, $a1, $zero
/* 3DC5A0 E00E2290 24A50008 */  addiu     $a1, $a1, 8
/* 3DC5A4 E00E2294 AEC50000 */  sw        $a1, ($s6)
/* 3DC5A8 E00E2298 8EAF0014 */  lw        $t7, 0x14($s5)
/* 3DC5AC E00E229C 36731630 */  ori       $s3, $s3, 0x1630
/* 3DC5B0 E00E22A0 AFAF00A0 */  sw        $t7, 0xa0($sp)
/* 3DC5B4 E00E22A4 8EB10024 */  lw        $s1, 0x24($s5)
/* 3DC5B8 E00E22A8 3C02E700 */  lui       $v0, 0xe700
/* 3DC5BC E00E22AC AC620000 */  sw        $v0, ($v1)
/* 3DC5C0 E00E22B0 AC600004 */  sw        $zero, 4($v1)
/* 3DC5C4 E00E22B4 ACA70000 */  sw        $a3, ($a1)
/* 3DC5C8 E00E22B8 8CC30010 */  lw        $v1, 0x10($a2)
/* 3DC5CC E00E22BC 24A20008 */  addiu     $v0, $a1, 8
/* 3DC5D0 E00E22C0 AEC20000 */  sw        $v0, ($s6)
/* 3DC5D4 E00E22C4 8C62001C */  lw        $v0, 0x1c($v1)
/* 3DC5D8 E00E22C8 3C038000 */  lui       $v1, 0x8000
/* 3DC5DC E00E22CC 00431021 */  addu      $v0, $v0, $v1
/* 3DC5E0 E00E22D0 3C03800B */  lui       $v1, %hi(gCameras)
/* 3DC5E4 E00E22D4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3DC5E8 E00E22D8 ACA20004 */  sw        $v0, 4($a1)
/* 3DC5EC E00E22DC 8EA50004 */  lw        $a1, 4($s5)
/* 3DC5F0 E00E22E0 8EA60008 */  lw        $a2, 8($s5)
/* 3DC5F4 E00E22E4 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3DC5F8 E00E22E8 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3DC5FC E00E22EC 8EA7000C */  lw        $a3, 0xc($s5)
/* 3DC600 E00E22F0 00028080 */  sll       $s0, $v0, 2
/* 3DC604 E00E22F4 02028021 */  addu      $s0, $s0, $v0
/* 3DC608 E00E22F8 00108080 */  sll       $s0, $s0, 2
/* 3DC60C E00E22FC 02028023 */  subu      $s0, $s0, $v0
/* 3DC610 E00E2300 001010C0 */  sll       $v0, $s0, 3
/* 3DC614 E00E2304 02028021 */  addu      $s0, $s0, $v0
/* 3DC618 E00E2308 001080C0 */  sll       $s0, $s0, 3
/* 3DC61C E00E230C 0C080108 */  jal       shim_guTranslateF
/* 3DC620 E00E2310 02038021 */   addu     $s0, $s0, $v1
/* 3DC624 E00E2314 27B20060 */  addiu     $s2, $sp, 0x60
/* 3DC628 E00E2318 8EA50038 */  lw        $a1, 0x38($s5)
/* 3DC62C E00E231C 0240202D */  daddu     $a0, $s2, $zero
/* 3DC630 E00E2320 00A0302D */  daddu     $a2, $a1, $zero
/* 3DC634 E00E2324 0C080110 */  jal       shim_guScaleF
/* 3DC638 E00E2328 00A0382D */   daddu    $a3, $a1, $zero
/* 3DC63C E00E232C 0240202D */  daddu     $a0, $s2, $zero
/* 3DC640 E00E2330 27A50020 */  addiu     $a1, $sp, 0x20
/* 3DC644 E00E2334 0C080114 */  jal       shim_guMtxCatF
/* 3DC648 E00E2338 00A0302D */   daddu    $a2, $a1, $zero
/* 3DC64C E00E233C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3DC650 E00E2340 96E50000 */  lhu       $a1, ($s7)
/* 3DC654 E00E2344 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3DC658 E00E2348 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3DC65C E00E234C 00052980 */  sll       $a1, $a1, 6
/* 3DC660 E00E2350 00B32821 */  addu      $a1, $a1, $s3
/* 3DC664 E00E2354 0C080118 */  jal       shim_guMtxF2L
/* 3DC668 E00E2358 00452821 */   addu     $a1, $v0, $a1
/* 3DC66C E00E235C 3C03DA38 */  lui       $v1, 0xda38
/* 3DC670 E00E2360 34630002 */  ori       $v1, $v1, 2
/* 3DC674 E00E2364 3C0ADA38 */  lui       $t2, 0xda38
/* 3DC678 E00E2368 354A0001 */  ori       $t2, $t2, 1
/* 3DC67C E00E236C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3DC680 E00E2370 323100FF */  andi      $s1, $s1, 0xff
/* 3DC684 E00E2374 8EC80000 */  lw        $t0, ($s6)
/* 3DC688 E00E2378 3C0541A0 */  lui       $a1, 0x41a0
/* 3DC68C E00E237C 3C013F80 */  lui       $at, 0x3f80
/* 3DC690 E00E2380 4481B000 */  mtc1      $at, $f22
/* 3DC694 E00E2384 4480A000 */  mtc1      $zero, $f20
/* 3DC698 E00E2388 96E20000 */  lhu       $v0, ($s7)
/* 3DC69C E00E238C 0100482D */  daddu     $t1, $t0, $zero
/* 3DC6A0 E00E2390 25080008 */  addiu     $t0, $t0, 8
/* 3DC6A4 E00E2394 AEC80000 */  sw        $t0, ($s6)
/* 3DC6A8 E00E2398 AD230000 */  sw        $v1, ($t1)
/* 3DC6AC E00E239C 24430001 */  addiu     $v1, $v0, 1
/* 3DC6B0 E00E23A0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3DC6B4 E00E23A4 00021180 */  sll       $v0, $v0, 6
/* 3DC6B8 E00E23A8 4406B000 */  mfc1      $a2, $f22
/* 3DC6BC E00E23AC 00531021 */  addu      $v0, $v0, $s3
/* 3DC6C0 E00E23B0 A6E30000 */  sh        $v1, ($s7)
/* 3DC6C4 E00E23B4 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 3DC6C8 E00E23B8 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 3DC6CC E00E23BC 4407A000 */  mfc1      $a3, $f20
/* 3DC6D0 E00E23C0 00621821 */  addu      $v1, $v1, $v0
/* 3DC6D4 E00E23C4 25020008 */  addiu     $v0, $t0, 8
/* 3DC6D8 E00E23C8 AD230004 */  sw        $v1, 4($t1)
/* 3DC6DC E00E23CC AEC20000 */  sw        $v0, ($s6)
/* 3DC6E0 E00E23D0 25020010 */  addiu     $v0, $t0, 0x10
/* 3DC6E4 E00E23D4 AD0A0000 */  sw        $t2, ($t0)
/* 3DC6E8 E00E23D8 AEC20000 */  sw        $v0, ($s6)
/* 3DC6EC E00E23DC 8E030204 */  lw        $v1, 0x204($s0)
/* 3DC6F0 E00E23E0 3C02FA00 */  lui       $v0, 0xfa00
/* 3DC6F4 E00E23E4 AD020008 */  sw        $v0, 8($t0)
/* 3DC6F8 E00E23E8 AD030004 */  sw        $v1, 4($t0)
/* 3DC6FC E00E23EC 92A2001B */  lbu       $v0, 0x1b($s5)
/* 3DC700 E00E23F0 92A9001F */  lbu       $t1, 0x1f($s5)
/* 3DC704 E00E23F4 92AA0023 */  lbu       $t2, 0x23($s5)
/* 3DC708 E00E23F8 25030018 */  addiu     $v1, $t0, 0x18
/* 3DC70C E00E23FC AEC30000 */  sw        $v1, ($s6)
/* 3DC710 E00E2400 3C03FB00 */  lui       $v1, 0xfb00
/* 3DC714 E00E2404 AD030010 */  sw        $v1, 0x10($t0)
/* 3DC718 E00E2408 00021600 */  sll       $v0, $v0, 0x18
/* 3DC71C E00E240C 00094C00 */  sll       $t1, $t1, 0x10
/* 3DC720 E00E2410 00491025 */  or        $v0, $v0, $t1
/* 3DC724 E00E2414 000A5200 */  sll       $t2, $t2, 8
/* 3DC728 E00E2418 004A1025 */  or        $v0, $v0, $t2
/* 3DC72C E00E241C 00511025 */  or        $v0, $v0, $s1
/* 3DC730 E00E2420 AD02000C */  sw        $v0, 0xc($t0)
/* 3DC734 E00E2424 92A3002B */  lbu       $v1, 0x2b($s5)
/* 3DC738 E00E2428 92A9002F */  lbu       $t1, 0x2f($s5)
/* 3DC73C E00E242C 92AA0033 */  lbu       $t2, 0x33($s5)
/* 3DC740 E00E2430 92AB0037 */  lbu       $t3, 0x37($s5)
/* 3DC744 E00E2434 25020020 */  addiu     $v0, $t0, 0x20
/* 3DC748 E00E2438 AEC20000 */  sw        $v0, ($s6)
/* 3DC74C E00E243C 3C02DE00 */  lui       $v0, 0xde00
/* 3DC750 E00E2440 AD020018 */  sw        $v0, 0x18($t0)
/* 3DC754 E00E2444 25020030 */  addiu     $v0, $t0, 0x30
/* 3DC758 E00E2448 AEC20000 */  sw        $v0, ($s6)
/* 3DC75C E00E244C 00031E00 */  sll       $v1, $v1, 0x18
/* 3DC760 E00E2450 00094C00 */  sll       $t1, $t1, 0x10
/* 3DC764 E00E2454 00691825 */  or        $v1, $v1, $t1
/* 3DC768 E00E2458 000A5200 */  sll       $t2, $t2, 8
/* 3DC76C E00E245C 006A1825 */  or        $v1, $v1, $t2
/* 3DC770 E00E2460 006B1825 */  or        $v1, $v1, $t3
/* 3DC774 E00E2464 AD030014 */  sw        $v1, 0x14($t0)
/* 3DC778 E00E2468 3C09E00E */  lui       $t1, %hi(D_E00E29F0)
/* 3DC77C E00E246C 8D2929F0 */  lw        $t1, %lo(D_E00E29F0)($t1)
/* 3DC780 E00E2470 3C02DE01 */  lui       $v0, 0xde01
/* 3DC784 E00E2474 AD020020 */  sw        $v0, 0x20($t0)
/* 3DC788 E00E2478 250201C0 */  addiu     $v0, $t0, 0x1c0
/* 3DC78C E00E247C AD020024 */  sw        $v0, 0x24($t0)
/* 3DC790 E00E2480 8FAF00A0 */  lw        $t7, 0xa0($sp)
/* 3DC794 E00E2484 3C03F200 */  lui       $v1, 0xf200
/* 3DC798 E00E2488 000F80C0 */  sll       $s0, $t7, 3
/* 3DC79C E00E248C 32020FFF */  andi      $v0, $s0, 0xfff
/* 3DC7A0 E00E2490 00021300 */  sll       $v0, $v0, 0xc
/* 3DC7A4 E00E2494 00431025 */  or        $v0, $v0, $v1
/* 3DC7A8 E00E2498 AD020028 */  sw        $v0, 0x28($t0)
/* 3DC7AC E00E249C 0200102D */  daddu     $v0, $s0, $zero
/* 3DC7B0 E00E24A0 244201FC */  addiu     $v0, $v0, 0x1fc
/* 3DC7B4 E00E24A4 30420FFF */  andi      $v0, $v0, 0xfff
/* 3DC7B8 E00E24A8 00021300 */  sll       $v0, $v0, 0xc
/* 3DC7BC E00E24AC 3442007C */  ori       $v0, $v0, 0x7c
/* 3DC7C0 E00E24B0 AD02002C */  sw        $v0, 0x2c($t0)
/* 3DC7C4 E00E24B4 AD09001C */  sw        $t1, 0x1c($t0)
/* 3DC7C8 E00E24B8 25080028 */  addiu     $t0, $t0, 0x28
/* 3DC7CC E00E24BC E7B40010 */  swc1      $f20, 0x10($sp)
/* 3DC7D0 E00E24C0 0C080104 */  jal       shim_guRotateF
/* 3DC7D4 E00E24C4 AFA800A4 */   sw       $t0, 0xa4($sp)
/* 3DC7D8 E00E24C8 3C01E00E */  lui       $at, %hi(D_E00E2A30)
/* 3DC7DC E00E24CC D4202A30 */  ldc1      $f0, %lo(D_E00E2A30)($at)
/* 3DC7E0 E00E24D0 44906000 */  mtc1      $s0, $f12
/* 3DC7E4 E00E24D4 00000000 */  nop
/* 3DC7E8 E00E24D8 46806321 */  cvt.d.w   $f12, $f12
/* 3DC7EC E00E24DC 46206300 */  add.d     $f12, $f12, $f0
/* 3DC7F0 E00E24E0 0000A02D */  daddu     $s4, $zero, $zero
/* 3DC7F4 E00E24E4 0C080140 */  jal       shim_sin_deg
/* 3DC7F8 E00E24E8 46206320 */   cvt.s.d  $f12, $f12
/* 3DC7FC E00E24EC 3C01C1F0 */  lui       $at, 0xc1f0
/* 3DC800 E00E24F0 44811000 */  mtc1      $at, $f2
/* 3DC804 E00E24F4 3C1E0900 */  lui       $fp, 0x900
/* 3DC808 E00E24F8 27DE10A8 */  addiu     $fp, $fp, 0x10a8
/* 3DC80C E00E24FC 46020002 */  mul.s     $f0, $f0, $f2
/* 3DC810 E00E2500 00000000 */  nop
/* 3DC814 E00E2504 24110002 */  addiu     $s1, $zero, 2
/* 3DC818 E00E2508 4405A000 */  mfc1      $a1, $f20
/* 3DC81C E00E250C 4407A000 */  mfc1      $a3, $f20
/* 3DC820 E00E2510 3C0140C0 */  lui       $at, 0x40c0
/* 3DC824 E00E2514 44812000 */  mtc1      $at, $f4
/* 3DC828 E00E2518 44060000 */  mfc1      $a2, $f0
/* 3DC82C E00E251C 0240202D */  daddu     $a0, $s2, $zero
/* 3DC830 E00E2520 E7B60010 */  swc1      $f22, 0x10($sp)
/* 3DC834 E00E2524 E7B40018 */  swc1      $f20, 0x18($sp)
/* 3DC838 E00E2528 E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3DC83C E00E252C 0C080180 */  jal       shim_guPositionF
/* 3DC840 E00E2530 E7A40014 */   swc1     $f4, 0x14($sp)
/* 3DC844 E00E2534 0240202D */  daddu     $a0, $s2, $zero
/* 3DC848 E00E2538 27A50020 */  addiu     $a1, $sp, 0x20
/* 3DC84C E00E253C 0C080114 */  jal       shim_guMtxCatF
/* 3DC850 E00E2540 00A0302D */   daddu    $a2, $a1, $zero
/* 3DC854 E00E2544 27A40020 */  addiu     $a0, $sp, 0x20
/* 3DC858 E00E2548 96E50000 */  lhu       $a1, ($s7)
/* 3DC85C E00E254C 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3DC860 E00E2550 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3DC864 E00E2554 00052980 */  sll       $a1, $a1, 6
/* 3DC868 E00E2558 00B32821 */  addu      $a1, $a1, $s3
/* 3DC86C E00E255C 0C080118 */  jal       shim_guMtxF2L
/* 3DC870 E00E2560 00452821 */   addu     $a1, $v0, $a1
/* 3DC874 E00E2564 8EC20000 */  lw        $v0, ($s6)
/* 3DC878 E00E2568 0280802D */  daddu     $s0, $s4, $zero
/* 3DC87C E00E256C 0040202D */  daddu     $a0, $v0, $zero
/* 3DC880 E00E2570 24420008 */  addiu     $v0, $v0, 8
/* 3DC884 E00E2574 AEC20000 */  sw        $v0, ($s6)
/* 3DC888 E00E2578 96E20000 */  lhu       $v0, ($s7)
/* 3DC88C E00E257C 3C03DA38 */  lui       $v1, 0xda38
/* 3DC890 E00E2580 AC830000 */  sw        $v1, ($a0)
/* 3DC894 E00E2584 24430001 */  addiu     $v1, $v0, 1
/* 3DC898 E00E2588 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3DC89C E00E258C 00021180 */  sll       $v0, $v0, 6
/* 3DC8A0 E00E2590 A6E30000 */  sh        $v1, ($s7)
/* 3DC8A4 E00E2594 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 3DC8A8 E00E2598 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 3DC8AC E00E259C 00531021 */  addu      $v0, $v0, $s3
/* 3DC8B0 E00E25A0 00621821 */  addu      $v1, $v1, $v0
/* 3DC8B4 E00E25A4 AC830004 */  sw        $v1, 4($a0)
.LE00E25A8:
/* 3DC8B8 E00E25A8 8FAF00A0 */  lw        $t7, 0xa0($sp)
/* 3DC8BC E00E25AC 000F10C0 */  sll       $v0, $t7, 3
/* 3DC8C0 E00E25B0 02021021 */  addu      $v0, $s0, $v0
/* 3DC8C4 E00E25B4 44826000 */  mtc1      $v0, $f12
/* 3DC8C8 E00E25B8 00000000 */  nop
/* 3DC8CC E00E25BC 46806320 */  cvt.s.w   $f12, $f12
/* 3DC8D0 E00E25C0 0C080140 */  jal       shim_sin_deg
/* 3DC8D4 E00E25C4 26100030 */   addiu    $s0, $s0, 0x30
/* 3DC8D8 E00E25C8 44941000 */  mtc1      $s4, $f2
/* 3DC8DC E00E25CC 00000000 */  nop
/* 3DC8E0 E00E25D0 468010A0 */  cvt.s.w   $f2, $f2
/* 3DC8E4 E00E25D4 3C01E00E */  lui       $at, %hi(D_E00E2A38)
/* 3DC8E8 E00E25D8 D4242A38 */  ldc1      $f4, %lo(D_E00E2A38)($at)
/* 3DC8EC E00E25DC 460010A1 */  cvt.d.s   $f2, $f2
/* 3DC8F0 E00E25E0 46241082 */  mul.d     $f2, $f2, $f4
/* 3DC8F4 E00E25E4 00000000 */  nop
/* 3DC8F8 E00E25E8 27A40020 */  addiu     $a0, $sp, 0x20
/* 3DC8FC E00E25EC 3C0141F0 */  lui       $at, 0x41f0
/* 3DC900 E00E25F0 44812000 */  mtc1      $at, $f4
/* 3DC904 E00E25F4 00000000 */  nop
/* 3DC908 E00E25F8 46040002 */  mul.s     $f0, $f0, $f4
/* 3DC90C E00E25FC 00000000 */  nop
/* 3DC910 E00E2600 4405A000 */  mfc1      $a1, $f20
/* 3DC914 E00E2604 3C0740C0 */  lui       $a3, 0x40c0
/* 3DC918 E00E2608 26940001 */  addiu     $s4, $s4, 1
/* 3DC91C E00E260C E7B40018 */  swc1      $f20, 0x18($sp)
/* 3DC920 E00E2610 44060000 */  mfc1      $a2, $f0
/* 3DC924 E00E2614 3C013FF0 */  lui       $at, 0x3ff0
/* 3DC928 E00E2618 44810800 */  mtc1      $at, $f1
/* 3DC92C E00E261C 44800000 */  mtc1      $zero, $f0
/* 3DC930 E00E2620 3C014100 */  lui       $at, 0x4100
/* 3DC934 E00E2624 44812000 */  mtc1      $at, $f4
/* 3DC938 E00E2628 46201080 */  add.d     $f2, $f2, $f0
/* 3DC93C E00E262C E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3DC940 E00E2630 E7A40014 */  swc1      $f4, 0x14($sp)
/* 3DC944 E00E2634 462010A0 */  cvt.s.d   $f2, $f2
/* 3DC948 E00E2638 0C080180 */  jal       shim_guPositionF
/* 3DC94C E00E263C E7A20010 */   swc1     $f2, 0x10($sp)
/* 3DC950 E00E2640 27A40020 */  addiu     $a0, $sp, 0x20
/* 3DC954 E00E2644 96E50000 */  lhu       $a1, ($s7)
/* 3DC958 E00E2648 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3DC95C E00E264C 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3DC960 E00E2650 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 3DC964 E00E2654 00052980 */  sll       $a1, $a1, 6
/* 3DC968 E00E2658 00AF2821 */  addu      $a1, $a1, $t7
/* 3DC96C E00E265C 0C080118 */  jal       shim_guMtxF2L
/* 3DC970 E00E2660 00452821 */   addu     $a1, $v0, $a1
/* 3DC974 E00E2664 3C02DA38 */  lui       $v0, 0xda38
/* 3DC978 E00E2668 34420001 */  ori       $v0, $v0, 1
/* 3DC97C E00E266C 3C080100 */  lui       $t0, 0x100
/* 3DC980 E00E2670 35082000 */  ori       $t0, $t0, 0x2000
/* 3DC984 E00E2674 3226007F */  andi      $a2, $s1, 0x7f
/* 3DC988 E00E2678 26310002 */  addiu     $s1, $s1, 2
/* 3DC98C E00E267C 00063040 */  sll       $a2, $a2, 1
/* 3DC990 E00E2680 00C83025 */  or        $a2, $a2, $t0
/* 3DC994 E00E2684 8EC40000 */  lw        $a0, ($s6)
/* 3DC998 E00E2688 96E50000 */  lhu       $a1, ($s7)
/* 3DC99C E00E268C 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 3DC9A0 E00E2690 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 3DC9A4 E00E2694 0080382D */  daddu     $a3, $a0, $zero
/* 3DC9A8 E00E2698 24840008 */  addiu     $a0, $a0, 8
/* 3DC9AC E00E269C ACE20000 */  sw        $v0, ($a3)
/* 3DC9B0 E00E26A0 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 3DC9B4 E00E26A4 00021180 */  sll       $v0, $v0, 6
/* 3DC9B8 E00E26A8 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 3DC9BC E00E26AC 24A50001 */  addiu     $a1, $a1, 1
/* 3DC9C0 E00E26B0 004F1021 */  addu      $v0, $v0, $t7
/* 3DC9C4 E00E26B4 00621821 */  addu      $v1, $v1, $v0
/* 3DC9C8 E00E26B8 ACE30004 */  sw        $v1, 4($a3)
/* 3DC9CC E00E26BC AC9E0004 */  sw        $fp, 4($a0)
/* 3DC9D0 E00E26C0 27DE0020 */  addiu     $fp, $fp, 0x20
/* 3DC9D4 E00E26C4 24820008 */  addiu     $v0, $a0, 8
/* 3DC9D8 E00E26C8 AEC40000 */  sw        $a0, ($s6)
/* 3DC9DC E00E26CC A6E50000 */  sh        $a1, ($s7)
/* 3DC9E0 E00E26D0 AEC20000 */  sw        $v0, ($s6)
/* 3DC9E4 E00E26D4 2A820010 */  slti      $v0, $s4, 0x10
/* 3DC9E8 E00E26D8 1440FFB3 */  bnez      $v0, .LE00E25A8
/* 3DC9EC E00E26DC AC860000 */   sw       $a2, ($a0)
/* 3DC9F0 E00E26E0 0000A02D */  daddu     $s4, $zero, $zero
/* 3DC9F4 E00E26E4 3C0B800A */  lui       $t3, %hi(gMasterGfxPos)
/* 3DC9F8 E00E26E8 256BA66C */  addiu     $t3, $t3, %lo(gMasterGfxPos)
/* 3DC9FC E00E26EC 3C0A0600 */  lui       $t2, 0x600
/* 3DCA00 E00E26F0 24090001 */  addiu     $t1, $zero, 1
/* 3DCA04 E00E26F4 3C0E0606 */  lui       $t6, 0x606
/* 3DCA08 E00E26F8 35CE0402 */  ori       $t6, $t6, 0x402
/* 3DCA0C E00E26FC 3C0D0002 */  lui       $t5, 2
/* 3DCA10 E00E2700 35AD0406 */  ori       $t5, $t5, 0x406
/* 3DCA14 E00E2704 3C0C0006 */  lui       $t4, 6
/* 3DCA18 E00E2708 358C0804 */  ori       $t4, $t4, 0x804
/* 3DCA1C E00E270C 24070004 */  addiu     $a3, $zero, 4
/* 3DCA20 E00E2710 24060002 */  addiu     $a2, $zero, 2
/* 3DCA24 E00E2714 24080006 */  addiu     $t0, $zero, 6
.LE00E2718:
/* 3DCA28 E00E2718 8D640000 */  lw        $a0, ($t3)
/* 3DCA2C E00E271C 00142840 */  sll       $a1, $s4, 1
/* 3DCA30 E00E2720 24820008 */  addiu     $v0, $a0, 8
/* 3DCA34 E00E2724 14A00004 */  bnez      $a1, .LE00E2738
/* 3DCA38 E00E2728 AD620000 */   sw       $v0, ($t3)
/* 3DCA3C E00E272C 00141440 */  sll       $v0, $s4, 0x11
/* 3DCA40 E00E2730 080389D8 */  j         .LE00E2760
/* 3DCA44 E00E2734 34420402 */   ori      $v0, $v0, 0x402
.LE00E2738:
/* 3DCA48 E00E2738 14A90003 */  bne       $a1, $t1, .LE00E2748
/* 3DCA4C E00E273C 30C200FF */   andi     $v0, $a2, 0xff
/* 3DCA50 E00E2740 080389DA */  j         .LE00E2768
/* 3DCA54 E00E2744 AC8E0000 */   sw       $t6, ($a0)
.LE00E2748:
/* 3DCA58 E00E2748 00021400 */  sll       $v0, $v0, 0x10
/* 3DCA5C E00E274C 00141A80 */  sll       $v1, $s4, 0xa
/* 3DCA60 E00E2750 3063FC00 */  andi      $v1, $v1, 0xfc00
/* 3DCA64 E00E2754 00431025 */  or        $v0, $v0, $v1
/* 3DCA68 E00E2758 30E300FF */  andi      $v1, $a3, 0xff
/* 3DCA6C E00E275C 00431025 */  or        $v0, $v0, $v1
.LE00E2760:
/* 3DCA70 E00E2760 004A1025 */  or        $v0, $v0, $t2
/* 3DCA74 E00E2764 AC820000 */  sw        $v0, ($a0)
.LE00E2768:
/* 3DCA78 E00E2768 14A00003 */  bnez      $a1, .LE00E2778
/* 3DCA7C E00E276C 00000000 */   nop
/* 3DCA80 E00E2770 080389E9 */  j         .LE00E27A4
/* 3DCA84 E00E2774 AC8D0004 */   sw       $t5, 4($a0)
.LE00E2778:
/* 3DCA88 E00E2778 14A90003 */  bne       $a1, $t1, .LE00E2788
/* 3DCA8C E00E277C 310200FF */   andi     $v0, $t0, 0xff
/* 3DCA90 E00E2780 080389E9 */  j         .LE00E27A4
/* 3DCA94 E00E2784 AC8C0004 */   sw       $t4, 4($a0)
.LE00E2788:
/* 3DCA98 E00E2788 00021400 */  sll       $v0, $v0, 0x10
/* 3DCA9C E00E278C 30C300FF */  andi      $v1, $a2, 0xff
/* 3DCAA0 E00E2790 00031A00 */  sll       $v1, $v1, 8
/* 3DCAA4 E00E2794 00431025 */  or        $v0, $v0, $v1
/* 3DCAA8 E00E2798 30E300FF */  andi      $v1, $a3, 0xff
/* 3DCAAC E00E279C 00431025 */  or        $v0, $v0, $v1
/* 3DCAB0 E00E27A0 AC820004 */  sw        $v0, 4($a0)
.LE00E27A4:
/* 3DCAB4 E00E27A4 24E70004 */  addiu     $a3, $a3, 4
/* 3DCAB8 E00E27A8 24C60004 */  addiu     $a2, $a2, 4
/* 3DCABC E00E27AC 26940001 */  addiu     $s4, $s4, 1
/* 3DCAC0 E00E27B0 2A82000F */  slti      $v0, $s4, 0xf
/* 3DCAC4 E00E27B4 1440FFD8 */  bnez      $v0, .LE00E2718
/* 3DCAC8 E00E27B8 25080004 */   addiu    $t0, $t0, 4
/* 3DCACC E00E27BC 3C03D838 */  lui       $v1, 0xd838
/* 3DCAD0 E00E27C0 34630002 */  ori       $v1, $v1, 2
/* 3DCAD4 E00E27C4 0000A02D */  daddu     $s4, $zero, $zero
/* 3DCAD8 E00E27C8 3C1E800A */  lui       $fp, %hi(gDisplayContext)
/* 3DCADC E00E27CC 27DEA674 */  addiu     $fp, $fp, %lo(gDisplayContext)
/* 3DCAE0 E00E27D0 3C178007 */  lui       $s7, %hi(gMatrixListPos)
/* 3DCAE4 E00E27D4 26F741F0 */  addiu     $s7, $s7, %lo(gMatrixListPos)
/* 3DCAE8 E00E27D8 3C160001 */  lui       $s6, 1
/* 3DCAEC E00E27DC 36D61630 */  ori       $s6, $s6, 0x1630
/* 3DCAF0 E00E27E0 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3DCAF4 E00E27E4 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3DCAF8 E00E27E8 0040902D */  daddu     $s2, $v0, $zero
/* 3DCAFC E00E27EC 2413FEE6 */  addiu     $s3, $zero, -0x11a
/* 3DCB00 E00E27F0 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3DCB04 E00E27F4 8E420000 */  lw        $v0, ($s2)
/* 3DCB08 E00E27F8 4480A000 */  mtc1      $zero, $f20
/* 3DCB0C E00E27FC 0040202D */  daddu     $a0, $v0, $zero
/* 3DCB10 E00E2800 24420008 */  addiu     $v0, $v0, 8
/* 3DCB14 E00E2804 AE420000 */  sw        $v0, ($s2)
/* 3DCB18 E00E2808 AC830000 */  sw        $v1, ($a0)
/* 3DCB1C E00E280C 24030040 */  addiu     $v1, $zero, 0x40
/* 3DCB20 E00E2810 AC830004 */  sw        $v1, 4($a0)
/* 3DCB24 E00E2814 24430008 */  addiu     $v1, $v0, 8
/* 3DCB28 E00E2818 AE430000 */  sw        $v1, ($s2)
/* 3DCB2C E00E281C 3C03DF00 */  lui       $v1, 0xdf00
/* 3DCB30 E00E2820 AC430000 */  sw        $v1, ($v0)
/* 3DCB34 E00E2824 AC400004 */  sw        $zero, 4($v0)
.LE00E2828:
/* 3DCB38 E00E2828 3C027878 */  lui       $v0, 0x7878
/* 3DCB3C E00E282C 34427879 */  ori       $v0, $v0, 0x7879
/* 3DCB40 E00E2830 27A40020 */  addiu     $a0, $sp, 0x20
/* 3DCB44 E00E2834 44933000 */  mtc1      $s3, $f6
/* 3DCB48 E00E2838 00000000 */  nop
/* 3DCB4C E00E283C 468031A0 */  cvt.s.w   $f6, $f6
/* 3DCB50 E00E2840 26730024 */  addiu     $s3, $s3, 0x24
/* 3DCB54 E00E2844 26940001 */  addiu     $s4, $s4, 1
/* 3DCB58 E00E2848 02020018 */  mult      $s0, $v0
/* 3DCB5C E00E284C 44073000 */  mfc1      $a3, $f6
/* 3DCB60 E00E2850 4405A000 */  mfc1      $a1, $f20
/* 3DCB64 E00E2854 4406A000 */  mfc1      $a2, $f20
/* 3DCB68 E00E2858 3C013F80 */  lui       $at, 0x3f80
/* 3DCB6C E00E285C 44810000 */  mtc1      $at, $f0
/* 3DCB70 E00E2860 001017C3 */  sra       $v0, $s0, 0x1f
/* 3DCB74 E00E2864 E7B40014 */  swc1      $f20, 0x14($sp)
/* 3DCB78 E00E2868 E7B40018 */  swc1      $f20, 0x18($sp)
/* 3DCB7C E00E286C E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3DCB80 E00E2870 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3DCB84 E00E2874 00007810 */  mfhi      $t7
/* 3DCB88 E00E2878 000F18C3 */  sra       $v1, $t7, 3
/* 3DCB8C E00E287C 00628823 */  subu      $s1, $v1, $v0
/* 3DCB90 E00E2880 00111100 */  sll       $v0, $s1, 4
/* 3DCB94 E00E2884 00511021 */  addu      $v0, $v0, $s1
/* 3DCB98 E00E2888 0C080180 */  jal       shim_guPositionF
/* 3DCB9C E00E288C 02028823 */   subu     $s1, $s0, $v0
/* 3DCBA0 E00E2890 27A40020 */  addiu     $a0, $sp, 0x20
/* 3DCBA4 E00E2894 26100004 */  addiu     $s0, $s0, 4
/* 3DCBA8 E00E2898 96E50000 */  lhu       $a1, ($s7)
/* 3DCBAC E00E289C 8FC20000 */  lw        $v0, ($fp)
/* 3DCBB0 E00E28A0 00052980 */  sll       $a1, $a1, 6
/* 3DCBB4 E00E28A4 00B62821 */  addu      $a1, $a1, $s6
/* 3DCBB8 E00E28A8 0C080118 */  jal       shim_guMtxF2L
/* 3DCBBC E00E28AC 00452821 */   addu     $a1, $v0, $a1
/* 3DCBC0 E00E28B0 3C09D838 */  lui       $t1, 0xd838
/* 3DCBC4 E00E28B4 35290002 */  ori       $t1, $t1, 2
/* 3DCBC8 E00E28B8 8E440000 */  lw        $a0, ($s2)
/* 3DCBCC E00E28BC 3C03DA38 */  lui       $v1, 0xda38
/* 3DCBD0 E00E28C0 0080282D */  daddu     $a1, $a0, $zero
/* 3DCBD4 E00E28C4 24840008 */  addiu     $a0, $a0, 8
/* 3DCBD8 E00E28C8 AE440000 */  sw        $a0, ($s2)
/* 3DCBDC E00E28CC 96E20000 */  lhu       $v0, ($s7)
/* 3DCBE0 E00E28D0 24080040 */  addiu     $t0, $zero, 0x40
/* 3DCBE4 E00E28D4 ACA30000 */  sw        $v1, ($a1)
/* 3DCBE8 E00E28D8 24430001 */  addiu     $v1, $v0, 1
/* 3DCBEC E00E28DC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3DCBF0 E00E28E0 00021180 */  sll       $v0, $v0, 6
/* 3DCBF4 E00E28E4 A6E30000 */  sh        $v1, ($s7)
/* 3DCBF8 E00E28E8 8FC30000 */  lw        $v1, ($fp)
/* 3DCBFC E00E28EC 00561021 */  addu      $v0, $v0, $s6
/* 3DCC00 E00E28F0 00621821 */  addu      $v1, $v1, $v0
/* 3DCC04 E00E28F4 24820008 */  addiu     $v0, $a0, 8
/* 3DCC08 E00E28F8 ACA30004 */  sw        $v1, 4($a1)
/* 3DCC0C E00E28FC AE420000 */  sw        $v0, ($s2)
/* 3DCC10 E00E2900 3C02FA00 */  lui       $v0, 0xfa00
/* 3DCC14 E00E2904 AC820000 */  sw        $v0, ($a0)
/* 3DCC18 E00E2908 3C03E00E */  lui       $v1, %hi(D_E00E29F4)
/* 3DCC1C E00E290C 00711821 */  addu      $v1, $v1, $s1
/* 3DCC20 E00E2910 906329F4 */  lbu       $v1, %lo(D_E00E29F4)($v1)
/* 3DCC24 E00E2914 3C05E00E */  lui       $a1, %hi(D_E00E2A08)
/* 3DCC28 E00E2918 00B12821 */  addu      $a1, $a1, $s1
/* 3DCC2C E00E291C 90A52A08 */  lbu       $a1, %lo(D_E00E2A08)($a1)
/* 3DCC30 E00E2920 3C06E00E */  lui       $a2, %hi(D_E00E2A1C)
/* 3DCC34 E00E2924 00D13021 */  addu      $a2, $a2, $s1
/* 3DCC38 E00E2928 90C62A1C */  lbu       $a2, %lo(D_E00E2A1C)($a2)
/* 3DCC3C E00E292C 92A70027 */  lbu       $a3, 0x27($s5)
/* 3DCC40 E00E2930 24820010 */  addiu     $v0, $a0, 0x10
/* 3DCC44 E00E2934 AE420000 */  sw        $v0, ($s2)
/* 3DCC48 E00E2938 3C02FB00 */  lui       $v0, 0xfb00
/* 3DCC4C E00E293C AC820008 */  sw        $v0, 8($a0)
/* 3DCC50 E00E2940 2402FF00 */  addiu     $v0, $zero, -0x100
/* 3DCC54 E00E2944 AC82000C */  sw        $v0, 0xc($a0)
/* 3DCC58 E00E2948 24820018 */  addiu     $v0, $a0, 0x18
/* 3DCC5C E00E294C AE420000 */  sw        $v0, ($s2)
/* 3DCC60 E00E2950 3C02DE00 */  lui       $v0, 0xde00
/* 3DCC64 E00E2954 AC820010 */  sw        $v0, 0x10($a0)
/* 3DCC68 E00E2958 24820020 */  addiu     $v0, $a0, 0x20
/* 3DCC6C E00E295C 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 3DCC70 E00E2960 00031E00 */  sll       $v1, $v1, 0x18
/* 3DCC74 E00E2964 00052C00 */  sll       $a1, $a1, 0x10
/* 3DCC78 E00E2968 00651825 */  or        $v1, $v1, $a1
/* 3DCC7C E00E296C 00063200 */  sll       $a2, $a2, 8
/* 3DCC80 E00E2970 00661825 */  or        $v1, $v1, $a2
/* 3DCC84 E00E2974 00671825 */  or        $v1, $v1, $a3
/* 3DCC88 E00E2978 AC8F0014 */  sw        $t7, 0x14($a0)
/* 3DCC8C E00E297C AE420000 */  sw        $v0, ($s2)
/* 3DCC90 E00E2980 2A820002 */  slti      $v0, $s4, 2
/* 3DCC94 E00E2984 AC890018 */  sw        $t1, 0x18($a0)
/* 3DCC98 E00E2988 AC88001C */  sw        $t0, 0x1c($a0)
/* 3DCC9C E00E298C 1440FFA6 */  bnez      $v0, .LE00E2828
/* 3DCCA0 E00E2990 AC830004 */   sw       $v1, 4($a0)
/* 3DCCA4 E00E2994 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3DCCA8 E00E2998 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3DCCAC E00E299C 8C430000 */  lw        $v1, ($v0)
/* 3DCCB0 E00E29A0 0060202D */  daddu     $a0, $v1, $zero
/* 3DCCB4 E00E29A4 24630008 */  addiu     $v1, $v1, 8
/* 3DCCB8 E00E29A8 AC430000 */  sw        $v1, ($v0)
/* 3DCCBC E00E29AC AC890000 */  sw        $t1, ($a0)
/* 3DCCC0 E00E29B0 AC880004 */  sw        $t0, 4($a0)
/* 3DCCC4 E00E29B4 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 3DCCC8 E00E29B8 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 3DCCCC E00E29BC 8FB700CC */  lw        $s7, 0xcc($sp)
/* 3DCCD0 E00E29C0 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 3DCCD4 E00E29C4 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 3DCCD8 E00E29C8 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 3DCCDC E00E29CC 8FB300BC */  lw        $s3, 0xbc($sp)
/* 3DCCE0 E00E29D0 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 3DCCE4 E00E29D4 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 3DCCE8 E00E29D8 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 3DCCEC E00E29DC D7B600E0 */  ldc1      $f22, 0xe0($sp)
/* 3DCCF0 E00E29E0 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 3DCCF4 E00E29E4 03E00008 */  jr        $ra
/* 3DCCF8 E00E29E8 27BD00E8 */   addiu    $sp, $sp, 0xe8
/* 3DCCFC E00E29EC 00000000 */  nop
