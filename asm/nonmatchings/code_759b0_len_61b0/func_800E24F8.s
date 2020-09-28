.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E24F8
/* 7B9A8 800E24F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7B9AC 800E24FC AFB00010 */  sw        $s0, 0x10($sp)
/* 7B9B0 800E2500 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7B9B4 800E2504 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7B9B8 800E2508 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7B9BC 800E250C 0C044181 */  jal       get_shadow_by_index
/* 7B9C0 800E2510 8E0400CC */   lw       $a0, 0xcc($s0)
/* 7B9C4 800E2514 C4400028 */  lwc1      $f0, 0x28($v0)
/* 7B9C8 800E2518 3C018011 */  lui       $at, 0x8011
/* 7B9CC 800E251C D424BD30 */  ldc1      $f4, -0x42d0($at)
/* 7B9D0 800E2520 C4420030 */  lwc1      $f2, 0x30($v0)
/* 7B9D4 800E2524 46000021 */  cvt.d.s   $f0, $f0
/* 7B9D8 800E2528 46240000 */  add.d     $f0, $f0, $f4
/* 7B9DC 800E252C 3C05800B */  lui       $a1, %hi(gCameras)
/* 7B9E0 800E2530 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 7B9E4 800E2534 460010A1 */  cvt.d.s   $f2, $f2
/* 7B9E8 800E2538 46241080 */  add.d     $f2, $f2, $f4
/* 7B9EC 800E253C 44802000 */  mtc1      $zero, $f4
/* 7B9F0 800E2540 46200020 */  cvt.s.d   $f0, $f0
/* 7B9F4 800E2544 46040032 */  c.eq.s    $f0, $f4
/* 7B9F8 800E2548 00000000 */  nop       
/* 7B9FC 800E254C 45000005 */  bc1f      .L800E2564
/* 7BA00 800E2550 462010A0 */   cvt.s.d  $f2, $f2
/* 7BA04 800E2554 46041032 */  c.eq.s    $f2, $f4
/* 7BA08 800E2558 00000000 */  nop       
/* 7BA0C 800E255C 4501003D */  bc1t      .L800E2654
/* 7BA10 800E2560 00000000 */   nop      
.L800E2564:
/* 7BA14 800E2564 920200B4 */  lbu       $v0, 0xb4($s0)
/* 7BA18 800E2568 2442FFFF */  addiu     $v0, $v0, -1
/* 7BA1C 800E256C 00021600 */  sll       $v0, $v0, 0x18
/* 7BA20 800E2570 00021E03 */  sra       $v1, $v0, 0x18
/* 7BA24 800E2574 2C620011 */  sltiu     $v0, $v1, 0x11
/* 7BA28 800E2578 1040002D */  beqz      $v0, .L800E2630
/* 7BA2C 800E257C 00031080 */   sll      $v0, $v1, 2
/* 7BA30 800E2580 3C018011 */  lui       $at, 0x8011
/* 7BA34 800E2584 00220821 */  addu      $at, $at, $v0
/* 7BA38 800E2588 8C22BD38 */  lw        $v0, -0x42c8($at)
/* 7BA3C 800E258C 00400008 */  jr        $v0
/* 7BA40 800E2590 00000000 */   nop      
/* 7BA44 800E2594 3C014200 */  lui       $at, 0x4200
/* 7BA48 800E2598 44812000 */  mtc1      $at, $f4
/* 7BA4C 800E259C 080389A5 */  j         .L800E2694
/* 7BA50 800E25A0 E4A4049C */   swc1     $f4, 0x49c($a1)
/* 7BA54 800E25A4 84A20034 */  lh        $v0, 0x34($a1)
/* 7BA58 800E25A8 28420082 */  slti      $v0, $v0, 0x82
/* 7BA5C 800E25AC 10400005 */  beqz      $v0, .L800E25C4
/* 7BA60 800E25B0 00000000 */   nop      
/* 7BA64 800E25B4 3C014040 */  lui       $at, 0x4040
/* 7BA68 800E25B8 44810000 */  mtc1      $at, $f0
/* 7BA6C 800E25BC 080389A5 */  j         .L800E2694
/* 7BA70 800E25C0 E4A0049C */   swc1     $f0, 0x49c($a1)
.L800E25C4:
/* 7BA74 800E25C4 3C048011 */  lui       $a0, 0x8011
/* 7BA78 800E25C8 2484C9A0 */  addiu     $a0, $a0, -0x3660
/* 7BA7C 800E25CC 8C820000 */  lw        $v0, ($a0)
/* 7BA80 800E25D0 3C014040 */  lui       $at, 0x4040
/* 7BA84 800E25D4 44812000 */  mtc1      $at, $f4
/* 7BA88 800E25D8 0040182D */  daddu     $v1, $v0, $zero
/* 7BA8C 800E25DC 24420001 */  addiu     $v0, $v0, 1
/* 7BA90 800E25E0 2863000B */  slti      $v1, $v1, 0xb
/* 7BA94 800E25E4 1460002B */  bnez      $v1, .L800E2694
/* 7BA98 800E25E8 AC820000 */   sw       $v0, ($a0)
/* 7BA9C 800E25EC C4A0049C */  lwc1      $f0, 0x49c($a1)
/* 7BAA0 800E25F0 3C014000 */  lui       $at, 0x4000
/* 7BAA4 800E25F4 44811000 */  mtc1      $at, $f2
/* 7BAA8 800E25F8 00000000 */  nop       
/* 7BAAC 800E25FC 46020001 */  sub.s     $f0, $f0, $f2
/* 7BAB0 800E2600 2402000A */  addiu     $v0, $zero, 0xa
/* 7BAB4 800E2604 AC820000 */  sw        $v0, ($a0)
.L800E2608:
/* 7BAB8 800E2608 4604003C */  c.lt.s    $f0, $f4
/* 7BABC 800E260C 00000000 */  nop       
/* 7BAC0 800E2610 45000020 */  bc1f      .L800E2694
/* 7BAC4 800E2614 E4A0049C */   swc1     $f0, 0x49c($a1)
/* 7BAC8 800E2618 080389A5 */  j         .L800E2694
/* 7BACC 800E261C E4A4049C */   swc1     $f4, 0x49c($a1)
/* 7BAD0 800E2620 3C014040 */  lui       $at, 0x4040
/* 7BAD4 800E2624 44812000 */  mtc1      $at, $f4
/* 7BAD8 800E2628 080389A5 */  j         .L800E2694
/* 7BADC 800E262C E4A4049C */   swc1     $f4, 0x49c($a1)
.L800E2630:
/* 7BAE0 800E2630 C4A0049C */  lwc1      $f0, 0x49c($a1)
/* 7BAE4 800E2634 3C014000 */  lui       $at, 0x4000
/* 7BAE8 800E2638 44811000 */  mtc1      $at, $f2
/* 7BAEC 800E263C 3C014040 */  lui       $at, 0x4040
/* 7BAF0 800E2640 44812000 */  mtc1      $at, $f4
/* 7BAF4 800E2644 3C018011 */  lui       $at, 0x8011
/* 7BAF8 800E2648 AC20C9A0 */  sw        $zero, -0x3660($at)
/* 7BAFC 800E264C 08038982 */  j         .L800E2608
/* 7BB00 800E2650 46020001 */   sub.s    $f0, $f0, $f2
.L800E2654:
/* 7BB04 800E2654 820300B4 */  lb        $v1, 0xb4($s0)
/* 7BB08 800E2658 1860000A */  blez      $v1, .L800E2684
/* 7BB0C 800E265C 28620004 */   slti     $v0, $v1, 4
/* 7BB10 800E2660 14400003 */  bnez      $v0, .L800E2670
/* 7BB14 800E2664 24020011 */   addiu    $v0, $zero, 0x11
/* 7BB18 800E2668 14620006 */  bne       $v1, $v0, .L800E2684
/* 7BB1C 800E266C 00000000 */   nop      
.L800E2670:
/* 7BB20 800E2670 3C0140E6 */  lui       $at, 0x40e6
/* 7BB24 800E2674 34216666 */  ori       $at, $at, 0x6666
/* 7BB28 800E2678 44812000 */  mtc1      $at, $f4
/* 7BB2C 800E267C 080389A5 */  j         .L800E2694
/* 7BB30 800E2680 E4A4049C */   swc1     $f4, 0x49c($a1)
.L800E2684:
/* 7BB34 800E2684 3C0141C0 */  lui       $at, 0x41c0
/* 7BB38 800E2688 44812000 */  mtc1      $at, $f4
/* 7BB3C 800E268C 00000000 */  nop       
/* 7BB40 800E2690 E4A4049C */  swc1      $f4, 0x49c($a1)
.L800E2694:
/* 7BB44 800E2694 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7BB48 800E2698 8FB00010 */  lw        $s0, 0x10($sp)
/* 7BB4C 800E269C 03E00008 */  jr        $ra
/* 7BB50 800E26A0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 7BB54 800E26A4 00000000 */  nop       
/* 7BB58 800E26A8 00000000 */  nop       
/* 7BB5C 800E26AC 00000000 */  nop       
