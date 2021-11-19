.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013BC88
/* D2388 8013BC88 0080C02D */  daddu     $t8, $a0, $zero
/* D238C 8013BC8C 3C068015 */  lui       $a2, %hi(fold_currentImage)
/* D2390 8013BC90 24C6EE10 */  addiu     $a2, $a2, %lo(fold_currentImage)
/* D2394 8013BC94 8CC40000 */  lw        $a0, ($a2)
/* D2398 8013BC98 94830008 */  lhu       $v1, 8($a0)
/* D239C 8013BC9C 24021000 */  addiu     $v0, $zero, 0x1000
/* D23A0 8013BCA0 14600002 */  bnez      $v1, .L8013BCAC
/* D23A4 8013BCA4 0043001A */   div      $zero, $v0, $v1
/* D23A8 8013BCA8 0007000D */  break     7
.L8013BCAC:
/* D23AC 8013BCAC 2401FFFF */   addiu    $at, $zero, -1
/* D23B0 8013BCB0 14610004 */  bne       $v1, $at, .L8013BCC4
/* D23B4 8013BCB4 3C018000 */   lui      $at, 0x8000
/* D23B8 8013BCB8 14410002 */  bne       $v0, $at, .L8013BCC4
/* D23BC 8013BCBC 00000000 */   nop
/* D23C0 8013BCC0 0006000D */  break     6
.L8013BCC4:
/* D23C4 8013BCC4 00006812 */   mflo     $t5
/* D23C8 8013BCC8 9483000A */  lhu       $v1, 0xa($a0)
/* D23CC 8013BCCC 006D102A */  slt       $v0, $v1, $t5
/* D23D0 8013BCD0 54400001 */  bnel      $v0, $zero, .L8013BCD8
/* D23D4 8013BCD4 0060682D */   daddu    $t5, $v1, $zero
.L8013BCD8:
/* D23D8 8013BCD8 01A0502D */  daddu     $t2, $t5, $zero
/* D23DC 8013BCDC 00C0782D */  daddu     $t7, $a2, $zero
/* D23E0 8013BCE0 3C028015 */  lui       $v0, %hi(fold_vtxCount)
/* D23E4 8013BCE4 2442EE14 */  addiu     $v0, $v0, %lo(fold_vtxCount)
/* D23E8 8013BCE8 0040482D */  daddu     $t1, $v0, $zero
/* D23EC 8013BCEC 3C068015 */  lui       $a2, %hi(fold_vtxBuf)
/* D23F0 8013BCF0 24C66950 */  addiu     $a2, $a2, %lo(fold_vtxBuf)
/* D23F4 8013BCF4 24072000 */  addiu     $a3, $zero, 0x2000
/* D23F8 8013BCF8 00C0602D */  daddu     $t4, $a2, $zero
/* D23FC 8013BCFC 8488000E */  lh        $t0, 0xe($a0)
/* D2400 8013BD00 848E000C */  lh        $t6, 0xc($a0)
/* D2404 8013BD04 94430000 */  lhu       $v1, ($v0)
/* D2408 8013BD08 00E0C82D */  daddu     $t9, $a3, $zero
/* D240C 8013BD0C A7030008 */  sh        $v1, 8($t8)
/* D2410 8013BD10 95220000 */  lhu       $v0, ($t1)
/* D2414 8013BD14 8CC50000 */  lw        $a1, ($a2)
/* D2418 8013BD18 95230000 */  lhu       $v1, ($t1)
/* D241C 8013BD1C 00021100 */  sll       $v0, $v0, 4
/* D2420 8013BD20 00451021 */  addu      $v0, $v0, $a1
/* D2424 8013BD24 00031900 */  sll       $v1, $v1, 4
/* D2428 8013BD28 A44E0000 */  sh        $t6, ($v0)
/* D242C 8013BD2C 95220000 */  lhu       $v0, ($t1)
/* D2430 8013BD30 00651821 */  addu      $v1, $v1, $a1
/* D2434 8013BD34 A4680002 */  sh        $t0, 2($v1)
/* D2438 8013BD38 95230000 */  lhu       $v1, ($t1)
/* D243C 8013BD3C 00021100 */  sll       $v0, $v0, 4
/* D2440 8013BD40 00451021 */  addu      $v0, $v0, $a1
/* D2444 8013BD44 00031900 */  sll       $v1, $v1, 4
/* D2448 8013BD48 00651821 */  addu      $v1, $v1, $a1
/* D244C 8013BD4C A4400004 */  sh        $zero, 4($v0)
/* D2450 8013BD50 95240000 */  lhu       $a0, ($t1)
/* D2454 8013BD54 24022000 */  addiu     $v0, $zero, 0x2000
/* D2458 8013BD58 A4620008 */  sh        $v0, 8($v1)
/* D245C 8013BD5C 95220000 */  lhu       $v0, ($t1)
/* D2460 8013BD60 00042100 */  sll       $a0, $a0, 4
/* D2464 8013BD64 00852021 */  addu      $a0, $a0, $a1
/* D2468 8013BD68 00021100 */  sll       $v0, $v0, 4
/* D246C 8013BD6C 00451021 */  addu      $v0, $v0, $a1
/* D2470 8013BD70 A487000A */  sh        $a3, 0xa($a0)
/* D2474 8013BD74 240400F0 */  addiu     $a0, $zero, 0xf0
/* D2478 8013BD78 A044000C */  sb        $a0, 0xc($v0)
/* D247C 8013BD7C 95220000 */  lhu       $v0, ($t1)
/* D2480 8013BD80 8CC30000 */  lw        $v1, ($a2)
/* D2484 8013BD84 00021100 */  sll       $v0, $v0, 4
/* D2488 8013BD88 00431021 */  addu      $v0, $v0, $v1
/* D248C 8013BD8C A044000D */  sb        $a0, 0xd($v0)
/* D2490 8013BD90 95220000 */  lhu       $v0, ($t1)
/* D2494 8013BD94 8CC30000 */  lw        $v1, ($a2)
/* D2498 8013BD98 00021100 */  sll       $v0, $v0, 4
/* D249C 8013BD9C 00431021 */  addu      $v0, $v0, $v1
/* D24A0 8013BDA0 A044000E */  sb        $a0, 0xe($v0)
/* D24A4 8013BDA4 95240000 */  lhu       $a0, ($t1)
/* D24A8 8013BDA8 8D850000 */  lw        $a1, ($t4)
/* D24AC 8013BDAC 8DE60000 */  lw        $a2, ($t7)
/* D24B0 8013BDB0 95230000 */  lhu       $v1, ($t1)
/* D24B4 8013BDB4 00042100 */  sll       $a0, $a0, 4
/* D24B8 8013BDB8 00852021 */  addu      $a0, $a0, $a1
/* D24BC 8013BDBC 00031900 */  sll       $v1, $v1, 4
/* D24C0 8013BDC0 94C20008 */  lhu       $v0, 8($a2)
/* D24C4 8013BDC4 00651821 */  addu      $v1, $v1, $a1
/* D24C8 8013BDC8 004E1021 */  addu      $v0, $v0, $t6
/* D24CC 8013BDCC A4820010 */  sh        $v0, 0x10($a0)
/* D24D0 8013BDD0 95220000 */  lhu       $v0, ($t1)
/* D24D4 8013BDD4 24040078 */  addiu     $a0, $zero, 0x78
/* D24D8 8013BDD8 A4680012 */  sh        $t0, 0x12($v1)
/* D24DC 8013BDDC 95230000 */  lhu       $v1, ($t1)
/* D24E0 8013BDE0 00021100 */  sll       $v0, $v0, 4
/* D24E4 8013BDE4 00451021 */  addu      $v0, $v0, $a1
/* D24E8 8013BDE8 00031900 */  sll       $v1, $v1, 4
/* D24EC 8013BDEC A4400014 */  sh        $zero, 0x14($v0)
/* D24F0 8013BDF0 94C20008 */  lhu       $v0, 8($a2)
/* D24F4 8013BDF4 00651821 */  addu      $v1, $v1, $a1
/* D24F8 8013BDF8 24420100 */  addiu     $v0, $v0, 0x100
/* D24FC 8013BDFC 00021140 */  sll       $v0, $v0, 5
/* D2500 8013BE00 A4620018 */  sh        $v0, 0x18($v1)
/* D2504 8013BE04 95220000 */  lhu       $v0, ($t1)
/* D2508 8013BE08 95230000 */  lhu       $v1, ($t1)
/* D250C 8013BE0C 00021100 */  sll       $v0, $v0, 4
/* D2510 8013BE10 00451021 */  addu      $v0, $v0, $a1
/* D2514 8013BE14 00031900 */  sll       $v1, $v1, 4
/* D2518 8013BE18 00651821 */  addu      $v1, $v1, $a1
/* D251C 8013BE1C A447001A */  sh        $a3, 0x1a($v0)
/* D2520 8013BE20 A064001C */  sb        $a0, 0x1c($v1)
/* D2524 8013BE24 95220000 */  lhu       $v0, ($t1)
/* D2528 8013BE28 8D830000 */  lw        $v1, ($t4)
/* D252C 8013BE2C 00021100 */  sll       $v0, $v0, 4
/* D2530 8013BE30 00431021 */  addu      $v0, $v0, $v1
/* D2534 8013BE34 A044001D */  sb        $a0, 0x1d($v0)
/* D2538 8013BE38 95220000 */  lhu       $v0, ($t1)
/* D253C 8013BE3C 8D830000 */  lw        $v1, ($t4)
/* D2540 8013BE40 00021100 */  sll       $v0, $v0, 4
/* D2544 8013BE44 00431021 */  addu      $v0, $v0, $v1
/* D2548 8013BE48 A044001E */  sb        $a0, 0x1e($v0)
.L8013BE4C:
/* D254C 8013BE4C 000A3100 */  sll       $a2, $t2, 4
/* D2550 8013BE50 8DE20000 */  lw        $v0, ($t7)
/* D2554 8013BE54 00CA3023 */  subu      $a2, $a2, $t2
/* D2558 8013BE58 9442000A */  lhu       $v0, 0xa($v0)
/* D255C 8013BE5C 000630C0 */  sll       $a2, $a2, 3
/* D2560 8013BE60 14400002 */  bnez      $v0, .L8013BE6C
/* D2564 8013BE64 00C2001A */   div      $zero, $a2, $v0
/* D2568 8013BE68 0007000D */  break     7
.L8013BE6C:
/* D256C 8013BE6C 2401FFFF */   addiu    $at, $zero, -1
/* D2570 8013BE70 14410004 */  bne       $v0, $at, .L8013BE84
/* D2574 8013BE74 3C018000 */   lui      $at, 0x8000
/* D2578 8013BE78 14C10002 */  bne       $a2, $at, .L8013BE84
/* D257C 8013BE7C 00000000 */   nop
/* D2580 8013BE80 0006000D */  break     6
.L8013BE84:
/* D2584 8013BE84 00003012 */   mflo     $a2
/* D2588 8013BE88 010D5823 */  subu      $t3, $t0, $t5
/* D258C 8013BE8C 25480100 */  addiu     $t0, $t2, 0x100
/* D2590 8013BE90 95220000 */  lhu       $v0, ($t1)
/* D2594 8013BE94 00084140 */  sll       $t0, $t0, 5
/* D2598 8013BE98 24420002 */  addiu     $v0, $v0, 2
/* D259C 8013BE9C A5220000 */  sh        $v0, ($t1)
/* D25A0 8013BEA0 3042FFFF */  andi      $v0, $v0, 0xffff
/* D25A4 8013BEA4 00021100 */  sll       $v0, $v0, 4
/* D25A8 8013BEA8 8D850000 */  lw        $a1, ($t4)
/* D25AC 8013BEAC 95230000 */  lhu       $v1, ($t1)
/* D25B0 8013BEB0 00451021 */  addu      $v0, $v0, $a1
/* D25B4 8013BEB4 00031900 */  sll       $v1, $v1, 4
/* D25B8 8013BEB8 A44E0000 */  sh        $t6, ($v0)
/* D25BC 8013BEBC 95220000 */  lhu       $v0, ($t1)
/* D25C0 8013BEC0 00651821 */  addu      $v1, $v1, $a1
/* D25C4 8013BEC4 A46B0002 */  sh        $t3, 2($v1)
/* D25C8 8013BEC8 95230000 */  lhu       $v1, ($t1)
/* D25CC 8013BECC 00021100 */  sll       $v0, $v0, 4
/* D25D0 8013BED0 00451021 */  addu      $v0, $v0, $a1
/* D25D4 8013BED4 00031900 */  sll       $v1, $v1, 4
/* D25D8 8013BED8 A4400004 */  sh        $zero, 4($v0)
/* D25DC 8013BEDC 95220000 */  lhu       $v0, ($t1)
/* D25E0 8013BEE0 00651821 */  addu      $v1, $v1, $a1
/* D25E4 8013BEE4 A4790008 */  sh        $t9, 8($v1)
/* D25E8 8013BEE8 00021100 */  sll       $v0, $v0, 4
/* D25EC 8013BEEC 00451021 */  addu      $v0, $v0, $a1
/* D25F0 8013BEF0 A448000A */  sh        $t0, 0xa($v0)
/* D25F4 8013BEF4 95220000 */  lhu       $v0, ($t1)
/* D25F8 8013BEF8 00021100 */  sll       $v0, $v0, 4
/* D25FC 8013BEFC 00451021 */  addu      $v0, $v0, $a1
/* D2600 8013BF00 24C40078 */  addiu     $a0, $a2, 0x78
/* D2604 8013BF04 A044000C */  sb        $a0, 0xc($v0)
/* D2608 8013BF08 95220000 */  lhu       $v0, ($t1)
/* D260C 8013BF0C 8D830000 */  lw        $v1, ($t4)
/* D2610 8013BF10 00021100 */  sll       $v0, $v0, 4
/* D2614 8013BF14 00431021 */  addu      $v0, $v0, $v1
/* D2618 8013BF18 A044000D */  sb        $a0, 0xd($v0)
/* D261C 8013BF1C 95220000 */  lhu       $v0, ($t1)
/* D2620 8013BF20 8D830000 */  lw        $v1, ($t4)
/* D2624 8013BF24 00021100 */  sll       $v0, $v0, 4
/* D2628 8013BF28 00431021 */  addu      $v0, $v0, $v1
/* D262C 8013BF2C A044000E */  sb        $a0, 0xe($v0)
/* D2630 8013BF30 95240000 */  lhu       $a0, ($t1)
/* D2634 8013BF34 8D850000 */  lw        $a1, ($t4)
/* D2638 8013BF38 8DE70000 */  lw        $a3, ($t7)
/* D263C 8013BF3C 95230000 */  lhu       $v1, ($t1)
/* D2640 8013BF40 00042100 */  sll       $a0, $a0, 4
/* D2644 8013BF44 00852021 */  addu      $a0, $a0, $a1
/* D2648 8013BF48 94E20008 */  lhu       $v0, 8($a3)
/* D264C 8013BF4C 00031900 */  sll       $v1, $v1, 4
/* D2650 8013BF50 004E1021 */  addu      $v0, $v0, $t6
/* D2654 8013BF54 A4820010 */  sh        $v0, 0x10($a0)
/* D2658 8013BF58 95220000 */  lhu       $v0, ($t1)
/* D265C 8013BF5C 00651821 */  addu      $v1, $v1, $a1
/* D2660 8013BF60 A46B0012 */  sh        $t3, 0x12($v1)
/* D2664 8013BF64 95230000 */  lhu       $v1, ($t1)
/* D2668 8013BF68 00021100 */  sll       $v0, $v0, 4
/* D266C 8013BF6C 00451021 */  addu      $v0, $v0, $a1
/* D2670 8013BF70 00031900 */  sll       $v1, $v1, 4
/* D2674 8013BF74 A4400014 */  sh        $zero, 0x14($v0)
/* D2678 8013BF78 94E20008 */  lhu       $v0, 8($a3)
/* D267C 8013BF7C 00651821 */  addu      $v1, $v1, $a1
/* D2680 8013BF80 24420100 */  addiu     $v0, $v0, 0x100
/* D2684 8013BF84 00021140 */  sll       $v0, $v0, 5
/* D2688 8013BF88 A4620018 */  sh        $v0, 0x18($v1)
/* D268C 8013BF8C 95220000 */  lhu       $v0, ($t1)
/* D2690 8013BF90 95230000 */  lhu       $v1, ($t1)
/* D2694 8013BF94 00021100 */  sll       $v0, $v0, 4
/* D2698 8013BF98 00451021 */  addu      $v0, $v0, $a1
/* D269C 8013BF9C 00031900 */  sll       $v1, $v1, 4
/* D26A0 8013BFA0 00651821 */  addu      $v1, $v1, $a1
/* D26A4 8013BFA4 A448001A */  sh        $t0, 0x1a($v0)
/* D26A8 8013BFA8 A066001C */  sb        $a2, 0x1c($v1)
/* D26AC 8013BFAC 95220000 */  lhu       $v0, ($t1)
/* D26B0 8013BFB0 8D830000 */  lw        $v1, ($t4)
/* D26B4 8013BFB4 00021100 */  sll       $v0, $v0, 4
/* D26B8 8013BFB8 00431021 */  addu      $v0, $v0, $v1
/* D26BC 8013BFBC A046001D */  sb        $a2, 0x1d($v0)
/* D26C0 8013BFC0 95220000 */  lhu       $v0, ($t1)
/* D26C4 8013BFC4 8D830000 */  lw        $v1, ($t4)
/* D26C8 8013BFC8 00021100 */  sll       $v0, $v0, 4
/* D26CC 8013BFCC 00431021 */  addu      $v0, $v0, $v1
/* D26D0 8013BFD0 A046001E */  sb        $a2, 0x1e($v0)
/* D26D4 8013BFD4 8DE20000 */  lw        $v0, ($t7)
/* D26D8 8013BFD8 9443000A */  lhu       $v1, 0xa($v0)
/* D26DC 8013BFDC 15430005 */  bne       $t2, $v1, .L8013BFF4
/* D26E0 8013BFE0 014D1021 */   addu     $v0, $t2, $t5
/* D26E4 8013BFE4 95220000 */  lhu       $v0, ($t1)
/* D26E8 8013BFE8 24420002 */  addiu     $v0, $v0, 2
/* D26EC 8013BFEC 0804F003 */  j         .L8013C00C
/* D26F0 8013BFF0 A5220000 */   sh       $v0, ($t1)
.L8013BFF4:
/* D26F4 8013BFF4 0062102A */  slt       $v0, $v1, $v0
/* D26F8 8013BFF8 10400002 */  beqz      $v0, .L8013C004
/* D26FC 8013BFFC 0160402D */   daddu    $t0, $t3, $zero
/* D2700 8013C000 006A6823 */  subu      $t5, $v1, $t2
.L8013C004:
/* D2704 8013C004 0804EF93 */  j         .L8013BE4C
/* D2708 8013C008 014D5021 */   addu     $t2, $t2, $t5
.L8013C00C:
/* D270C 8013C00C 3C028015 */  lui       $v0, %hi(fold_vtxCount)
/* D2710 8013C010 9442EE14 */  lhu       $v0, %lo(fold_vtxCount)($v0)
/* D2714 8013C014 97040008 */  lhu       $a0, 8($t8)
/* D2718 8013C018 24030001 */  addiu     $v1, $zero, 1
/* D271C 8013C01C A3030003 */  sb        $v1, 3($t8)
/* D2720 8013C020 2442FFFF */  addiu     $v0, $v0, -1
/* D2724 8013C024 A702000A */  sh        $v0, 0xa($t8)
/* D2728 8013C028 3042FFFF */  andi      $v0, $v0, 0xffff
/* D272C 8013C02C 00441023 */  subu      $v0, $v0, $a0
/* D2730 8013C030 2442FFFF */  addiu     $v0, $v0, -1
/* D2734 8013C034 00021FC2 */  srl       $v1, $v0, 0x1f
/* D2738 8013C038 00431021 */  addu      $v0, $v0, $v1
/* D273C 8013C03C 00021043 */  sra       $v0, $v0, 1
/* D2740 8013C040 03E00008 */  jr        $ra
/* D2744 8013C044 A3020004 */   sb       $v0, 4($t8)
