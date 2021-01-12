.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A223C
/* 3A2BCC E00A223C 27BDFF60 */  addiu     $sp, $sp, -0xa0
/* 3A2BD0 E00A2240 3C07DB06 */  lui       $a3, 0xdb06
/* 3A2BD4 E00A2244 34E70024 */  ori       $a3, $a3, 0x24
/* 3A2BD8 E00A2248 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3A2BDC E00A224C 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3A2BE0 E00A2250 AFB00078 */  sw        $s0, 0x78($sp)
/* 3A2BE4 E00A2254 0040802D */  daddu     $s0, $v0, $zero
/* 3A2BE8 E00A2258 AFB60090 */  sw        $s6, 0x90($sp)
/* 3A2BEC E00A225C 3C16F510 */  lui       $s6, 0xf510
/* 3A2BF0 E00A2260 36D60100 */  ori       $s6, $s6, 0x100
/* 3A2BF4 E00A2264 AFBF009C */  sw        $ra, 0x9c($sp)
/* 3A2BF8 E00A2268 AFBE0098 */  sw        $fp, 0x98($sp)
/* 3A2BFC E00A226C AFB70094 */  sw        $s7, 0x94($sp)
/* 3A2C00 E00A2270 AFB5008C */  sw        $s5, 0x8c($sp)
/* 3A2C04 E00A2274 AFB40088 */  sw        $s4, 0x88($sp)
/* 3A2C08 E00A2278 AFB30084 */  sw        $s3, 0x84($sp)
/* 3A2C0C E00A227C AFB20080 */  sw        $s2, 0x80($sp)
/* 3A2C10 E00A2280 AFB1007C */  sw        $s1, 0x7c($sp)
/* 3A2C14 E00A2284 AFB60060 */  sw        $s6, 0x60($sp)
/* 3A2C18 E00A2288 8E050000 */  lw        $a1, ($s0)
/* 3A2C1C E00A228C 3C02E700 */  lui       $v0, 0xe700
/* 3A2C20 E00A2290 AFA0006C */  sw        $zero, 0x6c($sp)
/* 3A2C24 E00A2294 8C94000C */  lw        $s4, 0xc($a0)
/* 3A2C28 E00A2298 00A0182D */  daddu     $v1, $a1, $zero
/* 3A2C2C E00A229C 24A50008 */  addiu     $a1, $a1, 8
/* 3A2C30 E00A22A0 AE050000 */  sw        $a1, ($s0)
/* 3A2C34 E00A22A4 8E860000 */  lw        $a2, ($s4)
/* 3A2C38 E00A22A8 8E96004C */  lw        $s6, 0x4c($s4)
/* 3A2C3C E00A22AC 0280B82D */  daddu     $s7, $s4, $zero
/* 3A2C40 E00A22B0 AFB60050 */  sw        $s6, 0x50($sp)
/* 3A2C44 E00A22B4 AC620000 */  sw        $v0, ($v1)
/* 3A2C48 E00A22B8 24A20008 */  addiu     $v0, $a1, 8
/* 3A2C4C E00A22BC AC600004 */  sw        $zero, 4($v1)
/* 3A2C50 E00A22C0 AE020000 */  sw        $v0, ($s0)
/* 3A2C54 E00A22C4 ACA70000 */  sw        $a3, ($a1)
/* 3A2C58 E00A22C8 8C830010 */  lw        $v1, 0x10($a0)
/* 3A2C5C E00A22CC 24A20010 */  addiu     $v0, $a1, 0x10
/* 3A2C60 E00A22D0 AE020000 */  sw        $v0, ($s0)
/* 3A2C64 E00A22D4 3C02DE00 */  lui       $v0, 0xde00
/* 3A2C68 E00A22D8 8C63001C */  lw        $v1, 0x1c($v1)
/* 3A2C6C E00A22DC 3C04E00A */  lui       $a0, %hi(D_E00A29DC)
/* 3A2C70 E00A22E0 248429DC */  addiu     $a0, $a0, %lo(D_E00A29DC)
/* 3A2C74 E00A22E4 ACA20008 */  sw        $v0, 8($a1)
/* 3A2C78 E00A22E8 3C028000 */  lui       $v0, 0x8000
/* 3A2C7C E00A22EC 00621821 */  addu      $v1, $v1, $v0
/* 3A2C80 E00A22F0 00061040 */  sll       $v0, $a2, 1
/* 3A2C84 E00A22F4 00461021 */  addu      $v0, $v0, $a2
/* 3A2C88 E00A22F8 000210C0 */  sll       $v0, $v0, 3
/* 3A2C8C E00A22FC 00063080 */  sll       $a2, $a2, 2
/* 3A2C90 E00A2300 ACA30004 */  sw        $v1, 4($a1)
/* 3A2C94 E00A2304 3C03E00A */  lui       $v1, %hi(D_E00A29D0)
/* 3A2C98 E00A2308 00661821 */  addu      $v1, $v1, $a2
/* 3A2C9C E00A230C 8C6329D0 */  lw        $v1, %lo(D_E00A29D0)($v1)
/* 3A2CA0 E00A2310 00448821 */  addu      $s1, $v0, $a0
/* 3A2CA4 E00A2314 ACA3000C */  sw        $v1, 0xc($a1)
.LE00A2318:
/* 3A2CA8 E00A2318 C6EC001C */  lwc1      $f12, 0x1c($s7)
/* 3A2CAC E00A231C C6EE002C */  lwc1      $f14, 0x2c($s7)
/* 3A2CB0 E00A2320 C6E0003C */  lwc1      $f0, 0x3c($s7)
/* 3A2CB4 E00A2324 8E350010 */  lw        $s5, 0x10($s1)
/* 3A2CB8 E00A2328 8E320014 */  lw        $s2, 0x14($s1)
/* 3A2CBC E00A232C 56F4000A */  bnel      $s7, $s4, .LE00A2358
/* 3A2CC0 E00A2330 E7AC0048 */   swc1     $f12, 0x48($sp)
/* 3A2CC4 E00A2334 27A20048 */  addiu     $v0, $sp, 0x48
/* 3A2CC8 E00A2338 AFA20010 */  sw        $v0, 0x10($sp)
/* 3A2CCC E00A233C 27A2004C */  addiu     $v0, $sp, 0x4c
/* 3A2CD0 E00A2340 44060000 */  mfc1      $a2, $f0
/* 3A2CD4 E00A2344 2407FFFF */  addiu     $a3, $zero, -1
/* 3A2CD8 E00A2348 0C08015C */  jal       func_E0200570
/* 3A2CDC E00A234C AFA20014 */   sw       $v0, 0x14($sp)
/* 3A2CE0 E00A2350 080288D9 */  j         .LE00A2364
/* 3A2CE4 E00A2354 0040302D */   daddu    $a2, $v0, $zero
.LE00A2358:
/* 3A2CE8 E00A2358 4600018D */  trunc.w.s $f6, $f0
/* 3A2CEC E00A235C 44063000 */  mfc1      $a2, $f6
/* 3A2CF0 E00A2360 E7AE004C */  swc1      $f14, 0x4c($sp)
.LE00A2364:
/* 3A2CF4 E00A2364 8FB6006C */  lw        $s6, 0x6c($sp)
/* 3A2CF8 E00A2368 03B61021 */  addu      $v0, $sp, $s6
/* 3A2CFC E00A236C AC460018 */  sw        $a2, 0x18($v0)
/* 3A2D00 E00A2370 C7A20048 */  lwc1      $f2, 0x48($sp)
/* 3A2D04 E00A2374 E4420028 */  swc1      $f2, 0x28($v0)
/* 3A2D08 E00A2378 C7A4004C */  lwc1      $f4, 0x4c($sp)
/* 3A2D0C E00A237C 10C0016B */  beqz      $a2, .LE00A292C
/* 3A2D10 E00A2380 E4440038 */   swc1     $f4, 0x38($v0)
/* 3A2D14 E00A2384 44800000 */  mtc1      $zero, $f0
/* 3A2D18 E00A2388 00000000 */  nop       
/* 3A2D1C E00A238C 4600103C */  c.lt.s    $f2, $f0
/* 3A2D20 E00A2390 00000000 */  nop       
/* 3A2D24 E00A2394 45030166 */  bc1tl     .LE00A2930
/* 3A2D28 E00A2398 26F70004 */   addiu    $s7, $s7, 4
/* 3A2D2C E00A239C 4600203C */  c.lt.s    $f4, $f0
/* 3A2D30 E00A23A0 00000000 */  nop       
/* 3A2D34 E00A23A4 45030162 */  bc1tl     .LE00A2930
/* 3A2D38 E00A23A8 26F70004 */   addiu    $s7, $s7, 4
/* 3A2D3C E00A23AC 3C0143A0 */  lui       $at, 0x43a0
/* 3A2D40 E00A23B0 44810000 */  mtc1      $at, $f0
/* 3A2D44 E00A23B4 00000000 */  nop       
/* 3A2D48 E00A23B8 4602003E */  c.le.s    $f0, $f2
/* 3A2D4C E00A23BC 00000000 */  nop       
/* 3A2D50 E00A23C0 4503015B */  bc1tl     .LE00A2930
/* 3A2D54 E00A23C4 26F70004 */   addiu    $s7, $s7, 4
/* 3A2D58 E00A23C8 3C014370 */  lui       $at, 0x4370
/* 3A2D5C E00A23CC 44810000 */  mtc1      $at, $f0
/* 3A2D60 E00A23D0 00000000 */  nop       
/* 3A2D64 E00A23D4 4604003E */  c.le.s    $f0, $f4
/* 3A2D68 E00A23D8 00000000 */  nop       
/* 3A2D6C E00A23DC 45030154 */  bc1tl     .LE00A2930
/* 3A2D70 E00A23E0 26F70004 */   addiu    $s7, $s7, 4
/* 3A2D74 E00A23E4 3C02E00A */  lui       $v0, %hi(D_E00A2A24)
/* 3A2D78 E00A23E8 00561021 */  addu      $v0, $v0, $s6
/* 3A2D7C E00A23EC 8C422A24 */  lw        $v0, %lo(D_E00A2A24)($v0)
/* 3A2D80 E00A23F0 8FB60050 */  lw        $s6, 0x50($sp)
/* 3A2D84 E00A23F4 02C20018 */  mult      $s6, $v0
/* 3A2D88 E00A23F8 00001012 */  mflo      $v0
/* 3A2D8C E00A23FC 3C0351EB */  lui       $v1, 0x51eb
/* 3A2D90 E00A2400 3463851F */  ori       $v1, $v1, 0x851f
/* 3A2D94 E00A2404 00430018 */  mult      $v0, $v1
/* 3A2D98 E00A2408 000217C3 */  sra       $v0, $v0, 0x1f
/* 3A2D9C E00A240C 00001810 */  mfhi      $v1
/* 3A2DA0 E00A2410 00032143 */  sra       $a0, $v1, 5
/* 3A2DA4 E00A2414 8E83005C */  lw        $v1, 0x5c($s4)
/* 3A2DA8 E00A2418 00822023 */  subu      $a0, $a0, $v0
/* 3A2DAC E00A241C 00640018 */  mult      $v1, $a0
/* 3A2DB0 E00A2420 00001812 */  mflo      $v1
/* 3A2DB4 E00A2424 8E820060 */  lw        $v0, 0x60($s4)
/* 3A2DB8 E00A2428 00000000 */  nop       
/* 3A2DBC E00A242C 00440018 */  mult      $v0, $a0
/* 3A2DC0 E00A2430 00003812 */  mflo      $a3
/* 3A2DC4 E00A2434 8E820064 */  lw        $v0, 0x64($s4)
/* 3A2DC8 E00A2438 00000000 */  nop       
/* 3A2DCC E00A243C 00440018 */  mult      $v0, $a0
/* 3A2DD0 E00A2440 00004812 */  mflo      $t1
/* 3A2DD4 E00A2444 8E060000 */  lw        $a2, ($s0)
/* 3A2DD8 E00A2448 00031A43 */  sra       $v1, $v1, 9
/* 3A2DDC E00A244C 00640018 */  mult      $v1, $a0
/* 3A2DE0 E00A2450 00C0282D */  daddu     $a1, $a2, $zero
/* 3A2DE4 E00A2454 24C60008 */  addiu     $a2, $a2, 8
/* 3A2DE8 E00A2458 AE060000 */  sw        $a2, ($s0)
/* 3A2DEC E00A245C 3C02FA00 */  lui       $v0, 0xfa00
/* 3A2DF0 E00A2460 00005812 */  mflo      $t3
/* 3A2DF4 E00A2464 ACA20000 */  sw        $v0, ($a1)
/* 3A2DF8 E00A2468 00071243 */  sra       $v0, $a3, 9
/* 3A2DFC E00A246C 00440018 */  mult      $v0, $a0
/* 3A2E00 E00A2470 246A0020 */  addiu     $t2, $v1, 0x20
/* 3A2E04 E00A2474 24480020 */  addiu     $t0, $v0, 0x20
/* 3A2E08 E00A2478 00091243 */  sra       $v0, $t1, 9
/* 3A2E0C E00A247C 24490020 */  addiu     $t1, $v0, 0x20
/* 3A2E10 E00A2480 00003812 */  mflo      $a3
/* 3A2E14 E00A2484 000B1A03 */  sra       $v1, $t3, 8
/* 3A2E18 E00A2488 00031E00 */  sll       $v1, $v1, 0x18
/* 3A2E1C E00A248C 00440018 */  mult      $v0, $a0
/* 3A2E20 E00A2490 00071203 */  sra       $v0, $a3, 8
/* 3A2E24 E00A2494 304200FF */  andi      $v0, $v0, 0xff
/* 3A2E28 E00A2498 00021400 */  sll       $v0, $v0, 0x10
/* 3A2E2C E00A249C 00621825 */  or        $v1, $v1, $v0
/* 3A2E30 E00A24A0 00005812 */  mflo      $t3
/* 3A2E34 E00A24A4 3162FF00 */  andi      $v0, $t3, 0xff00
/* 3A2E38 E00A24A8 00621825 */  or        $v1, $v1, $v0
/* 3A2E3C E00A24AC 346300FF */  ori       $v1, $v1, 0xff
/* 3A2E40 E00A24B0 29420080 */  slti      $v0, $t2, 0x80
/* 3A2E44 E00A24B4 14400002 */  bnez      $v0, .LE00A24C0
/* 3A2E48 E00A24B8 ACA30004 */   sw       $v1, 4($a1)
/* 3A2E4C E00A24BC 240A007F */  addiu     $t2, $zero, 0x7f
.LE00A24C0:
/* 3A2E50 E00A24C0 29020080 */  slti      $v0, $t0, 0x80
/* 3A2E54 E00A24C4 50400001 */  beql      $v0, $zero, .LE00A24CC
/* 3A2E58 E00A24C8 2408007F */   addiu    $t0, $zero, 0x7f
.LE00A24CC:
/* 3A2E5C E00A24CC 29220080 */  slti      $v0, $t1, 0x80
/* 3A2E60 E00A24D0 50400001 */  beql      $v0, $zero, .LE00A24D8
/* 3A2E64 E00A24D4 2409007F */   addiu    $t1, $zero, 0x7f
.LE00A24D8:
/* 3A2E68 E00A24D8 0000282D */  daddu     $a1, $zero, $zero
/* 3A2E6C E00A24DC 24C20008 */  addiu     $v0, $a2, 8
/* 3A2E70 E00A24E0 AE020000 */  sw        $v0, ($s0)
/* 3A2E74 E00A24E4 3C02FB00 */  lui       $v0, 0xfb00
/* 3A2E78 E00A24E8 000A1E00 */  sll       $v1, $t2, 0x18
/* 3A2E7C E00A24EC ACC20000 */  sw        $v0, ($a2)
/* 3A2E80 E00A24F0 310200FF */  andi      $v0, $t0, 0xff
/* 3A2E84 E00A24F4 00021400 */  sll       $v0, $v0, 0x10
/* 3A2E88 E00A24F8 00621825 */  or        $v1, $v1, $v0
/* 3A2E8C E00A24FC 312200FF */  andi      $v0, $t1, 0xff
/* 3A2E90 E00A2500 00021200 */  sll       $v0, $v0, 8
/* 3A2E94 E00A2504 00621825 */  or        $v1, $v1, $v0
/* 3A2E98 E00A2508 C7A00048 */  lwc1      $f0, 0x48($sp)
/* 3A2E9C E00A250C 44952000 */  mtc1      $s5, $f4
/* 3A2EA0 E00A2510 00000000 */  nop       
/* 3A2EA4 E00A2514 46802120 */  cvt.s.w   $f4, $f4
/* 3A2EA8 E00A2518 ACC30004 */  sw        $v1, 4($a2)
/* 3A2EAC E00A251C 46040001 */  sub.s     $f0, $f0, $f4
/* 3A2EB0 E00A2520 C7A2004C */  lwc1      $f2, 0x4c($sp)
/* 3A2EB4 E00A2524 00151840 */  sll       $v1, $s5, 1
/* 3A2EB8 E00A2528 46041081 */  sub.s     $f2, $f2, $f4
/* 3A2EBC E00A252C 4600018D */  trunc.w.s $f6, $f0
/* 3A2EC0 E00A2530 44133000 */  mfc1      $s3, $f6
/* 3A2EC4 E00A2534 00000000 */  nop       
/* 3A2EC8 E00A2538 02637021 */  addu      $t6, $s3, $v1
/* 3A2ECC E00A253C 4600118D */  trunc.w.s $f6, $f2
/* 3A2ED0 E00A2540 44023000 */  mfc1      $v0, $f6
/* 3A2ED4 E00A2544 00000000 */  nop       
/* 3A2ED8 E00A2548 00432021 */  addu      $a0, $v0, $v1
/* 3A2EDC E00A254C 06610002 */  bgez      $s3, .LE00A2558
/* 3A2EE0 E00A2550 0040582D */   daddu    $t3, $v0, $zero
/* 3A2EE4 E00A2554 00132823 */  negu      $a1, $s3
.LE00A2558:
/* 3A2EE8 E00A2558 05610002 */  bgez      $t3, .LE00A2564
/* 3A2EEC E00A255C 0000182D */   daddu    $v1, $zero, $zero
/* 3A2EF0 E00A2560 000B1823 */  negu      $v1, $t3
.LE00A2564:
/* 3A2EF4 E00A2564 29C20141 */  slti      $v0, $t6, 0x141
/* 3A2EF8 E00A2568 50400001 */  beql      $v0, $zero, .LE00A2570
/* 3A2EFC E00A256C 240E013F */   addiu    $t6, $zero, 0x13f
.LE00A2570:
/* 3A2F00 E00A2570 288200F1 */  slti      $v0, $a0, 0xf1
/* 3A2F04 E00A2574 50400001 */  beql      $v0, $zero, .LE00A257C
/* 3A2F08 E00A2578 240400EF */   addiu    $a0, $zero, 0xef
.LE00A257C:
/* 3A2F0C E00A257C 16400002 */  bnez      $s2, .LE00A2588
/* 3A2F10 E00A2580 0072001A */   div      $zero, $v1, $s2
/* 3A2F14 E00A2584 0007000D */  break     7
.LE00A2588:
/* 3A2F18 E00A2588 2401FFFF */   addiu    $at, $zero, -1
/* 3A2F1C E00A258C 16410004 */  bne       $s2, $at, .LE00A25A0
/* 3A2F20 E00A2590 3C018000 */   lui      $at, 0x8000
/* 3A2F24 E00A2594 14610002 */  bne       $v1, $at, .LE00A25A0
/* 3A2F28 E00A2598 00000000 */   nop      
/* 3A2F2C E00A259C 0006000D */  break     6
.LE00A25A0:
/* 3A2F30 E00A25A0 00005012 */   mflo     $t2
/* 3A2F34 E00A25A4 008B1023 */  subu      $v0, $a0, $t3
/* 3A2F38 E00A25A8 16400002 */  bnez      $s2, .LE00A25B4
/* 3A2F3C E00A25AC 0052001A */   div      $zero, $v0, $s2
/* 3A2F40 E00A25B0 0007000D */  break     7
.LE00A25B4:
/* 3A2F44 E00A25B4 2401FFFF */   addiu    $at, $zero, -1
/* 3A2F48 E00A25B8 16410004 */  bne       $s2, $at, .LE00A25CC
/* 3A2F4C E00A25BC 3C018000 */   lui      $at, 0x8000
/* 3A2F50 E00A25C0 14410002 */  bne       $v0, $at, .LE00A25CC
/* 3A2F54 E00A25C4 00000000 */   nop      
/* 3A2F58 E00A25C8 0006000D */  break     6
.LE00A25CC:
/* 3A2F5C E00A25CC 0000B012 */   mflo     $s6
/* 3A2F60 E00A25D0 0156102A */  slt       $v0, $t2, $s6
/* 3A2F64 E00A25D4 104000D5 */  beqz      $v0, .LE00A292C
/* 3A2F68 E00A25D8 AFB60054 */   sw       $s6, 0x54($sp)
/* 3A2F6C E00A25DC 01520018 */  mult      $t2, $s2
/* 3A2F70 E00A25E0 0265A821 */  addu      $s5, $s3, $a1
/* 3A2F74 E00A25E4 01D51023 */  subu      $v0, $t6, $s5
/* 3A2F78 E00A25E8 00021040 */  sll       $v0, $v0, 1
/* 3A2F7C E00A25EC AFA2005C */  sw        $v0, 0x5c($sp)
/* 3A2F80 E00A25F0 0000B012 */  mflo      $s6
/* 3A2F84 E00A25F4 02CB4821 */  addu      $t1, $s6, $t3
.LE00A25F8:
/* 3A2F88 E00A25F8 01321021 */  addu      $v0, $t1, $s2
/* 3A2F8C E00A25FC 284200F0 */  slti      $v0, $v0, 0xf0
/* 3A2F90 E00A2600 104000CA */  beqz      $v0, .LE00A292C
/* 3A2F94 E00A2604 0120582D */   daddu    $t3, $t1, $zero
/* 3A2F98 E00A2608 00093080 */  sll       $a2, $t1, 2
/* 3A2F9C E00A260C 00C91021 */  addu      $v0, $a2, $t1
/* 3A2FA0 E00A2610 000211C0 */  sll       $v0, $v0, 7
/* 3A2FA4 E00A2614 8FB6005C */  lw        $s6, 0x5c($sp)
/* 3A2FA8 E00A2618 44932000 */  mtc1      $s3, $f4
/* 3A2FAC E00A261C 00000000 */  nop       
/* 3A2FB0 E00A2620 46802120 */  cvt.s.w   $f4, $f4
/* 3A2FB4 E00A2624 AFA20058 */  sw        $v0, 0x58($sp)
/* 3A2FB8 E00A2628 26C20007 */  addiu     $v0, $s6, 7
/* 3A2FBC E00A262C 000210C3 */  sra       $v0, $v0, 3
/* 3A2FC0 E00A2630 304201FF */  andi      $v0, $v0, 0x1ff
/* 3A2FC4 E00A2634 8FB60060 */  lw        $s6, 0x60($sp)
/* 3A2FC8 E00A2638 00021240 */  sll       $v0, $v0, 9
/* 3A2FCC E00A263C 00567825 */  or        $t7, $v0, $s6
/* 3A2FD0 E00A2640 00151080 */  sll       $v0, $s5, 2
/* 3A2FD4 E00A2644 30420FFF */  andi      $v0, $v0, 0xfff
/* 3A2FD8 E00A2648 00026B00 */  sll       $t5, $v0, 0xc
/* 3A2FDC E00A264C 3C16F400 */  lui       $s6, 0xf400
/* 3A2FE0 E00A2650 01B6B025 */  or        $s6, $t5, $s6
/* 3A2FE4 E00A2654 25C2FFFF */  addiu     $v0, $t6, -1
/* 3A2FE8 E00A2658 00021080 */  sll       $v0, $v0, 2
/* 3A2FEC E00A265C 30420FFF */  andi      $v0, $v0, 0xfff
/* 3A2FF0 E00A2660 0002CB00 */  sll       $t9, $v0, 0xc
/* 3A2FF4 E00A2664 2642FFFF */  addiu     $v0, $s2, -1
/* 3A2FF8 E00A2668 00021080 */  sll       $v0, $v0, 2
/* 3A2FFC E00A266C 30580FFF */  andi      $t8, $v0, 0xfff
/* 3A3000 E00A2670 3C020700 */  lui       $v0, 0x700
/* 3A3004 E00A2674 03021025 */  or        $v0, $t8, $v0
/* 3A3008 E00A2678 AFB60064 */  sw        $s6, 0x64($sp)
/* 3A300C E00A267C C6200008 */  lwc1      $f0, 8($s1)
/* 3A3010 E00A2680 03221025 */  or        $v0, $t9, $v0
/* 3A3014 E00A2684 46002002 */  mul.s     $f0, $f4, $f0
/* 3A3018 E00A2688 00000000 */  nop       
/* 3A301C E00A268C AFA20068 */  sw        $v0, 0x68($sp)
/* 3A3020 E00A2690 8E220014 */  lw        $v0, 0x14($s1)
/* 3A3024 E00A2694 8E050000 */  lw        $a1, ($s0)
/* 3A3028 E00A2698 8E230004 */  lw        $v1, 4($s1)
/* 3A302C E00A269C 01420018 */  mult      $t2, $v0
/* 3A3030 E00A26A0 00A0382D */  daddu     $a3, $a1, $zero
/* 3A3034 E00A26A4 00031080 */  sll       $v0, $v1, 2
/* 3A3038 E00A26A8 00431021 */  addu      $v0, $v0, $v1
/* 3A303C E00A26AC 4600018D */  trunc.w.s $f6, $f0
/* 3A3040 E00A26B0 44043000 */  mfc1      $a0, $f6
/* 3A3044 E00A26B4 0000B012 */  mflo      $s6
/* 3A3048 E00A26B8 C620000C */  lwc1      $f0, 0xc($s1)
/* 3A304C E00A26BC 44961000 */  mtc1      $s6, $f2
/* 3A3050 E00A26C0 00000000 */  nop       
/* 3A3054 E00A26C4 468010A0 */  cvt.s.w   $f2, $f2
/* 3A3058 E00A26C8 46001082 */  mul.s     $f2, $f2, $f0
/* 3A305C E00A26CC 00000000 */  nop       
/* 3A3060 E00A26D0 00021080 */  sll       $v0, $v0, 2
/* 3A3064 E00A26D4 24A50008 */  addiu     $a1, $a1, 8
/* 3A3068 E00A26D8 00042080 */  sll       $a0, $a0, 2
/* 3A306C E00A26DC 44820000 */  mtc1      $v0, $f0
/* 3A3070 E00A26E0 00000000 */  nop       
/* 3A3074 E00A26E4 46800020 */  cvt.s.w   $f0, $f0
/* 3A3078 E00A26E8 46020001 */  sub.s     $f0, $f0, $f2
/* 3A307C E00A26EC 30840FFF */  andi      $a0, $a0, 0xfff
/* 3A3080 E00A26F0 00042300 */  sll       $a0, $a0, 0xc
/* 3A3084 E00A26F4 4600018D */  trunc.w.s $f6, $f0
/* 3A3088 E00A26F8 44023000 */  mfc1      $v0, $f6
/* 3A308C E00A26FC 00000000 */  nop       
/* 3A3090 E00A2700 00021080 */  sll       $v0, $v0, 2
/* 3A3094 E00A2704 30420FFF */  andi      $v0, $v0, 0xfff
/* 3A3098 E00A2708 3C16F200 */  lui       $s6, 0xf200
/* 3A309C E00A270C 00561025 */  or        $v0, $v0, $s6
/* 3A30A0 E00A2710 00822025 */  or        $a0, $a0, $v0
/* 3A30A4 E00A2714 32A201FF */  andi      $v0, $s5, 0x1ff
/* 3A30A8 E00A2718 ACE40000 */  sw        $a0, ($a3)
/* 3A30AC E00A271C C6200008 */  lwc1      $f0, 8($s1)
/* 3A30B0 E00A2720 00021540 */  sll       $v0, $v0, 0x15
/* 3A30B4 E00A2724 AFA20070 */  sw        $v0, 0x70($sp)
/* 3A30B8 E00A2728 46002102 */  mul.s     $f4, $f4, $f0
/* 3A30BC E00A272C 00000000 */  nop       
/* 3A30C0 E00A2730 C6200000 */  lwc1      $f0, ($s1)
/* 3A30C4 E00A2734 46800020 */  cvt.s.w   $f0, $f0
/* 3A30C8 E00A2738 AE050000 */  sw        $a1, ($s0)
/* 3A30CC E00A273C 8E220014 */  lw        $v0, 0x14($s1)
/* 3A30D0 E00A2740 01420018 */  mult      $t2, $v0
/* 3A30D4 E00A2744 0000602D */  daddu     $t4, $zero, $zero
/* 3A30D8 E00A2748 30C60FFF */  andi      $a2, $a2, 0xfff
/* 3A30DC E00A274C 01A6F025 */  or        $fp, $t5, $a2
/* 3A30E0 E00A2750 8E240004 */  lw        $a0, 4($s1)
/* 3A30E4 E00A2754 46002100 */  add.s     $f4, $f4, $f0
/* 3A30E8 E00A2758 00041080 */  sll       $v0, $a0, 2
/* 3A30EC E00A275C 00441021 */  addu      $v0, $v0, $a0
/* 3A30F0 E00A2760 4600218D */  trunc.w.s $f6, $f4
/* 3A30F4 E00A2764 44033000 */  mfc1      $v1, $f6
/* 3A30F8 E00A2768 0000B012 */  mflo      $s6
/* 3A30FC E00A276C C620000C */  lwc1      $f0, 0xc($s1)
/* 3A3100 E00A2770 44961000 */  mtc1      $s6, $f2
/* 3A3104 E00A2774 00000000 */  nop       
/* 3A3108 E00A2778 468010A0 */  cvt.s.w   $f2, $f2
/* 3A310C E00A277C 46001082 */  mul.s     $f2, $f2, $f0
/* 3A3110 E00A2780 00000000 */  nop       
/* 3A3114 E00A2784 00021080 */  sll       $v0, $v0, 2
/* 3A3118 E00A2788 00441021 */  addu      $v0, $v0, $a0
/* 3A311C E00A278C 00031880 */  sll       $v1, $v1, 2
/* 3A3120 E00A2790 44820000 */  mtc1      $v0, $f0
/* 3A3124 E00A2794 00000000 */  nop       
/* 3A3128 E00A2798 46800020 */  cvt.s.w   $f0, $f0
/* 3A312C E00A279C 46020001 */  sub.s     $f0, $f0, $f2
/* 3A3130 E00A27A0 30630FFF */  andi      $v1, $v1, 0xfff
/* 3A3134 E00A27A4 00031B00 */  sll       $v1, $v1, 0xc
/* 3A3138 E00A27A8 4600018D */  trunc.w.s $f6, $f0
/* 3A313C E00A27AC 44023000 */  mfc1      $v0, $f6
/* 3A3140 E00A27B0 00000000 */  nop       
/* 3A3144 E00A27B4 00021080 */  sll       $v0, $v0, 2
/* 3A3148 E00A27B8 30420FFF */  andi      $v0, $v0, 0xfff
/* 3A314C E00A27BC 00621825 */  or        $v1, $v1, $v0
/* 3A3150 E00A27C0 ACE30004 */  sw        $v1, 4($a3)
.LE00A27C4:
/* 3A3154 E00A27C4 3C02FD10 */  lui       $v0, 0xfd10
/* 3A3158 E00A27C8 3442013F */  ori       $v0, $v0, 0x13f
/* 3A315C E00A27CC 3C060702 */  lui       $a2, 0x702
/* 3A3160 E00A27D0 34C60090 */  ori       $a2, $a2, 0x90
/* 3A3164 E00A27D4 3C070102 */  lui       $a3, 0x102
/* 3A3168 E00A27D8 34E70090 */  ori       $a3, $a3, 0x90
/* 3A316C E00A27DC 3C080400 */  lui       $t0, 0x400
/* 3A3170 E00A27E0 35080400 */  ori       $t0, $t0, 0x400
/* 3A3174 E00A27E4 258C0001 */  addiu     $t4, $t4, 1
/* 3A3178 E00A27E8 8E050000 */  lw        $a1, ($s0)
/* 3A317C E00A27EC 3C03800A */  lui       $v1, %hi(D_8009A64C)
/* 3A3180 E00A27F0 8C63A64C */  lw        $v1, %lo(D_8009A64C)($v1)
/* 3A3184 E00A27F4 00A0202D */  daddu     $a0, $a1, $zero
/* 3A3188 E00A27F8 24A50008 */  addiu     $a1, $a1, 8
/* 3A318C E00A27FC AE050000 */  sw        $a1, ($s0)
/* 3A3190 E00A2800 AC820000 */  sw        $v0, ($a0)
/* 3A3194 E00A2804 8FB60058 */  lw        $s6, 0x58($sp)
/* 3A3198 E00A2808 3C028000 */  lui       $v0, 0x8000
/* 3A319C E00A280C 00761821 */  addu      $v1, $v1, $s6
/* 3A31A0 E00A2810 00621821 */  addu      $v1, $v1, $v0
/* 3A31A4 E00A2814 24A20008 */  addiu     $v0, $a1, 8
/* 3A31A8 E00A2818 AC830004 */  sw        $v1, 4($a0)
/* 3A31AC E00A281C AE020000 */  sw        $v0, ($s0)
/* 3A31B0 E00A2820 24A20010 */  addiu     $v0, $a1, 0x10
/* 3A31B4 E00A2824 ACAF0000 */  sw        $t7, ($a1)
/* 3A31B8 E00A2828 ACA60004 */  sw        $a2, 4($a1)
/* 3A31BC E00A282C AE020000 */  sw        $v0, ($s0)
/* 3A31C0 E00A2830 3C02E600 */  lui       $v0, 0xe600
/* 3A31C4 E00A2834 ACA20008 */  sw        $v0, 8($a1)
/* 3A31C8 E00A2838 24A20018 */  addiu     $v0, $a1, 0x18
/* 3A31CC E00A283C ACA0000C */  sw        $zero, 0xc($a1)
/* 3A31D0 E00A2840 AE020000 */  sw        $v0, ($s0)
/* 3A31D4 E00A2844 24A20020 */  addiu     $v0, $a1, 0x20
/* 3A31D8 E00A2848 000E2080 */  sll       $a0, $t6, 2
/* 3A31DC E00A284C 30840FFF */  andi      $a0, $a0, 0xfff
/* 3A31E0 E00A2850 8FB60064 */  lw        $s6, 0x64($sp)
/* 3A31E4 E00A2854 00042300 */  sll       $a0, $a0, 0xc
/* 3A31E8 E00A2858 ACB60010 */  sw        $s6, 0x10($a1)
/* 3A31EC E00A285C 8FB60068 */  lw        $s6, 0x68($sp)
/* 3A31F0 E00A2860 3C03E400 */  lui       $v1, 0xe400
/* 3A31F4 E00A2864 ACB60014 */  sw        $s6, 0x14($a1)
/* 3A31F8 E00A2868 3C16E700 */  lui       $s6, 0xe700
/* 3A31FC E00A286C AE020000 */  sw        $v0, ($s0)
/* 3A3200 E00A2870 24A20028 */  addiu     $v0, $a1, 0x28
/* 3A3204 E00A2874 ACB60018 */  sw        $s6, 0x18($a1)
/* 3A3208 E00A2878 ACA0001C */  sw        $zero, 0x1c($a1)
/* 3A320C E00A287C AE020000 */  sw        $v0, ($s0)
/* 3A3210 E00A2880 24A20030 */  addiu     $v0, $a1, 0x30
/* 3A3214 E00A2884 3C16F200 */  lui       $s6, 0xf200
/* 3A3218 E00A2888 ACAF0020 */  sw        $t7, 0x20($a1)
/* 3A321C E00A288C ACA70024 */  sw        $a3, 0x24($a1)
/* 3A3220 E00A2890 AE020000 */  sw        $v0, ($s0)
/* 3A3224 E00A2894 01B61025 */  or        $v0, $t5, $s6
/* 3A3228 E00A2898 ACA20028 */  sw        $v0, 0x28($a1)
/* 3A322C E00A289C 3C020100 */  lui       $v0, 0x100
/* 3A3230 E00A28A0 03021025 */  or        $v0, $t8, $v0
/* 3A3234 E00A28A4 03221025 */  or        $v0, $t9, $v0
/* 3A3238 E00A28A8 ACA2002C */  sw        $v0, 0x2c($a1)
/* 3A323C E00A28AC 24A20038 */  addiu     $v0, $a1, 0x38
/* 3A3240 E00A28B0 AE020000 */  sw        $v0, ($s0)
/* 3A3244 E00A28B4 01721021 */  addu      $v0, $t3, $s2
/* 3A3248 E00A28B8 00021080 */  sll       $v0, $v0, 2
/* 3A324C E00A28BC 30420FFF */  andi      $v0, $v0, 0xfff
/* 3A3250 E00A28C0 00431025 */  or        $v0, $v0, $v1
/* 3A3254 E00A28C4 00822025 */  or        $a0, $a0, $v0
/* 3A3258 E00A28C8 24A20040 */  addiu     $v0, $a1, 0x40
/* 3A325C E00A28CC ACA40030 */  sw        $a0, 0x30($a1)
/* 3A3260 E00A28D0 ACBE0034 */  sw        $fp, 0x34($a1)
/* 3A3264 E00A28D4 AE020000 */  sw        $v0, ($s0)
/* 3A3268 E00A28D8 3C02E100 */  lui       $v0, 0xe100
/* 3A326C E00A28DC ACA20038 */  sw        $v0, 0x38($a1)
/* 3A3270 E00A28E0 8FB60070 */  lw        $s6, 0x70($sp)
/* 3A3274 E00A28E4 24A20048 */  addiu     $v0, $a1, 0x48
/* 3A3278 E00A28E8 ACB6003C */  sw        $s6, 0x3c($a1)
/* 3A327C E00A28EC AE020000 */  sw        $v0, ($s0)
/* 3A3280 E00A28F0 3C02F100 */  lui       $v0, 0xf100
/* 3A3284 E00A28F4 ACA20040 */  sw        $v0, 0x40($a1)
/* 3A3288 E00A28F8 24A20050 */  addiu     $v0, $a1, 0x50
/* 3A328C E00A28FC ACA80044 */  sw        $t0, 0x44($a1)
/* 3A3290 E00A2900 AE020000 */  sw        $v0, ($s0)
/* 3A3294 E00A2904 3C16E700 */  lui       $s6, 0xe700
/* 3A3298 E00A2908 29820002 */  slti      $v0, $t4, 2
/* 3A329C E00A290C ACB60048 */  sw        $s6, 0x48($a1)
/* 3A32A0 E00A2910 1440FFAC */  bnez      $v0, .LE00A27C4
/* 3A32A4 E00A2914 ACA0004C */   sw       $zero, 0x4c($a1)
/* 3A32A8 E00A2918 8FB60054 */  lw        $s6, 0x54($sp)
/* 3A32AC E00A291C 254A0001 */  addiu     $t2, $t2, 1
/* 3A32B0 E00A2920 0156102A */  slt       $v0, $t2, $s6
/* 3A32B4 E00A2924 1440FF34 */  bnez      $v0, .LE00A25F8
/* 3A32B8 E00A2928 01324821 */   addu     $t1, $t1, $s2
.LE00A292C:
/* 3A32BC E00A292C 26F70004 */  addiu     $s7, $s7, 4
.LE00A2930:
/* 3A32C0 E00A2930 26820010 */  addiu     $v0, $s4, 0x10
/* 3A32C4 E00A2934 8FB6006C */  lw        $s6, 0x6c($sp)
/* 3A32C8 E00A2938 02E2102A */  slt       $v0, $s7, $v0
/* 3A32CC E00A293C 26D60004 */  addiu     $s6, $s6, 4
/* 3A32D0 E00A2940 1440FE75 */  bnez      $v0, .LE00A2318
/* 3A32D4 E00A2944 AFB6006C */   sw       $s6, 0x6c($sp)
/* 3A32D8 E00A2948 0000182D */  daddu     $v1, $zero, $zero
/* 3A32DC E00A294C 27A80018 */  addiu     $t0, $sp, 0x18
/* 3A32E0 E00A2950 27A70028 */  addiu     $a3, $sp, 0x28
/* 3A32E4 E00A2954 27A60038 */  addiu     $a2, $sp, 0x38
.LE00A2958:
/* 3A32E8 E00A2958 24650001 */  addiu     $a1, $v1, 1
/* 3A32EC E00A295C 00052080 */  sll       $a0, $a1, 2
/* 3A32F0 E00A2960 02842021 */  addu      $a0, $s4, $a0
/* 3A32F4 E00A2964 00031880 */  sll       $v1, $v1, 2
/* 3A32F8 E00A2968 01031021 */  addu      $v0, $t0, $v1
/* 3A32FC E00A296C C4400000 */  lwc1      $f0, ($v0)
/* 3A3300 E00A2970 46800020 */  cvt.s.w   $f0, $f0
/* 3A3304 E00A2974 00E31021 */  addu      $v0, $a3, $v1
/* 3A3308 E00A2978 E480003C */  swc1      $f0, 0x3c($a0)
/* 3A330C E00A297C C4400000 */  lwc1      $f0, ($v0)
/* 3A3310 E00A2980 00C31821 */  addu      $v1, $a2, $v1
/* 3A3314 E00A2984 E480001C */  swc1      $f0, 0x1c($a0)
/* 3A3318 E00A2988 C4600000 */  lwc1      $f0, ($v1)
/* 3A331C E00A298C 00A0182D */  daddu     $v1, $a1, $zero
/* 3A3320 E00A2990 28620003 */  slti      $v0, $v1, 3
/* 3A3324 E00A2994 1440FFF0 */  bnez      $v0, .LE00A2958
/* 3A3328 E00A2998 E480002C */   swc1     $f0, 0x2c($a0)
/* 3A332C E00A299C 8FBF009C */  lw        $ra, 0x9c($sp)
/* 3A3330 E00A29A0 8FBE0098 */  lw        $fp, 0x98($sp)
/* 3A3334 E00A29A4 8FB70094 */  lw        $s7, 0x94($sp)
/* 3A3338 E00A29A8 8FB60090 */  lw        $s6, 0x90($sp)
/* 3A333C E00A29AC 8FB5008C */  lw        $s5, 0x8c($sp)
/* 3A3340 E00A29B0 8FB40088 */  lw        $s4, 0x88($sp)
/* 3A3344 E00A29B4 8FB30084 */  lw        $s3, 0x84($sp)
/* 3A3348 E00A29B8 8FB20080 */  lw        $s2, 0x80($sp)
/* 3A334C E00A29BC 8FB1007C */  lw        $s1, 0x7c($sp)
/* 3A3350 E00A29C0 8FB00078 */  lw        $s0, 0x78($sp)
/* 3A3354 E00A29C4 03E00008 */  jr        $ra
/* 3A3358 E00A29C8 27BD00A0 */   addiu    $sp, $sp, 0xa0
/* 3A335C E00A29CC 00000000 */  nop       
