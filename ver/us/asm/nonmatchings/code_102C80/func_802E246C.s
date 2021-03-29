.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802EB130
.double 2.7

.section .text

glabel func_802E246C
/* 103CEC 802E246C 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 103CF0 802E2470 AFB500A4 */  sw        $s5, 0xa4($sp)
/* 103CF4 802E2474 0080A82D */  daddu     $s5, $a0, $zero
/* 103CF8 802E2478 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 103CFC 802E247C 00C0B02D */  daddu     $s6, $a2, $zero
/* 103D00 802E2480 27A40050 */  addiu     $a0, $sp, 0x50
/* 103D04 802E2484 30A5FFFF */  andi      $a1, $a1, 0xffff
/* 103D08 802E2488 AFBF00B0 */  sw        $ra, 0xb0($sp)
/* 103D0C 802E248C AFB700AC */  sw        $s7, 0xac($sp)
/* 103D10 802E2490 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 103D14 802E2494 AFB3009C */  sw        $s3, 0x9c($sp)
/* 103D18 802E2498 AFB20098 */  sw        $s2, 0x98($sp)
/* 103D1C 802E249C AFB10094 */  sw        $s1, 0x94($sp)
/* 103D20 802E24A0 AFB00090 */  sw        $s0, 0x90($sp)
/* 103D24 802E24A4 F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* 103D28 802E24A8 8EA20044 */  lw        $v0, 0x44($s5)
/* 103D2C 802E24AC 8EB00040 */  lw        $s0, 0x40($s5)
/* 103D30 802E24B0 00451021 */  addu      $v0, $v0, $a1
/* 103D34 802E24B4 AE020034 */  sw        $v0, 0x34($s0)
/* 103D38 802E24B8 3C02802E */  lui       $v0, %hi(func_802E2BA4)
/* 103D3C 802E24BC 24422BA4 */  addiu     $v0, $v0, %lo(func_802E2BA4)
/* 103D40 802E24C0 AEA2003C */  sw        $v0, 0x3c($s5)
/* 103D44 802E24C4 240200FF */  addiu     $v0, $zero, 0xff
/* 103D48 802E24C8 A2A2000B */  sb        $v0, 0xb($s5)
/* 103D4C 802E24CC C6000038 */  lwc1      $f0, 0x38($s0)
/* 103D50 802E24D0 8EA50048 */  lw        $a1, 0x48($s5)
/* 103D54 802E24D4 8EA70050 */  lw        $a3, 0x50($s5)
/* 103D58 802E24D8 44060000 */  mfc1      $a2, $f0
/* 103D5C 802E24DC 24170002 */  addiu     $s7, $zero, 2
/* 103D60 802E24E0 0C019E40 */  jal       guTranslateF
/* 103D64 802E24E4 AEA6004C */   sw       $a2, 0x4c($s5)
/* 103D68 802E24E8 0C044AC8 */  jal       func_80112B20
/* 103D6C 802E24EC 02A0202D */   daddu    $a0, $s5, $zero
/* 103D70 802E24F0 50400001 */  beql      $v0, $zero, .L802E24F8
/* 103D74 802E24F4 24170001 */   addiu    $s7, $zero, 1
.L802E24F8:
/* 103D78 802E24F8 0000A02D */  daddu     $s4, $zero, $zero
/* 103D7C 802E24FC 0200902D */  daddu     $s2, $s0, $zero
/* 103D80 802E2500 0240882D */  daddu     $s1, $s2, $zero
/* 103D84 802E2504 0240982D */  daddu     $s3, $s2, $zero
/* 103D88 802E2508 240200FF */  addiu     $v0, $zero, 0xff
/* 103D8C 802E250C A640003E */  sh        $zero, 0x3e($s2)
/* 103D90 802E2510 A642003C */  sh        $v0, 0x3c($s2)
.L802E2514:
/* 103D94 802E2514 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 103D98 802E2518 26D60040 */  addiu     $s6, $s6, 0x40
/* 103D9C 802E251C 8EA50044 */  lw        $a1, 0x44($s5)
/* 103DA0 802E2520 27A40010 */  addiu     $a0, $sp, 0x10
/* 103DA4 802E2524 0C019D60 */  jal       guMtxL2F
/* 103DA8 802E2528 00A22821 */   addu     $a1, $a1, $v0
/* 103DAC 802E252C 27A40050 */  addiu     $a0, $sp, 0x50
/* 103DB0 802E2530 27A50010 */  addiu     $a1, $sp, 0x10
/* 103DB4 802E2534 0C019D80 */  jal       guMtxCatF
/* 103DB8 802E2538 00A0302D */   daddu    $a2, $a1, $zero
/* 103DBC 802E253C C7A00040 */  lwc1      $f0, 0x40($sp)
/* 103DC0 802E2540 E64000C0 */  swc1      $f0, 0xc0($s2)
/* 103DC4 802E2544 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 103DC8 802E2548 E6400124 */  swc1      $f0, 0x124($s2)
/* 103DCC 802E254C C7A00048 */  lwc1      $f0, 0x48($sp)
/* 103DD0 802E2550 240400FF */  addiu     $a0, $zero, 0xff
/* 103DD4 802E2554 0C00A67F */  jal       rand_int
/* 103DD8 802E2558 E6400188 */   swc1     $f0, 0x188($s2)
/* 103DDC 802E255C 00021023 */  negu      $v0, $v0
/* 103DE0 802E2560 A2220072 */  sb        $v0, 0x72($s1)
/* 103DE4 802E2564 24020001 */  addiu     $v0, $zero, 1
/* 103DE8 802E2568 16E20008 */  bne       $s7, $v0, .L802E258C
/* 103DEC 802E256C 24100028 */   addiu    $s0, $zero, 0x28
/* 103DF0 802E2570 24100014 */  addiu     $s0, $zero, 0x14
/* 103DF4 802E2574 96620000 */  lhu       $v0, ($s3)
/* 103DF8 802E2578 3C0140CC */  lui       $at, 0x40cc
/* 103DFC 802E257C 3421CCCD */  ori       $at, $at, 0xcccd
/* 103E00 802E2580 4481A000 */  mtc1      $at, $f20
/* 103E04 802E2584 080B8968 */  j         .L802E25A0
/* 103E08 802E2588 34420001 */   ori      $v0, $v0, 1
.L802E258C:
/* 103E0C 802E258C 96620000 */  lhu       $v0, ($s3)
/* 103E10 802E2590 3C014109 */  lui       $at, 0x4109
/* 103E14 802E2594 3421999A */  ori       $at, $at, 0x999a
/* 103E18 802E2598 4481A000 */  mtc1      $at, $f20
/* 103E1C 802E259C 34420002 */  ori       $v0, $v0, 2
.L802E25A0:
/* 103E20 802E25A0 A6620000 */  sh        $v0, ($s3)
/* 103E24 802E25A4 0C00A67F */  jal       rand_int
/* 103E28 802E25A8 2404000A */   addiu    $a0, $zero, 0xa
/* 103E2C 802E25AC 02028021 */  addu      $s0, $s0, $v0
/* 103E30 802E25B0 32820001 */  andi      $v0, $s4, 1
/* 103E34 802E25B4 14400003 */  bnez      $v0, .L802E25C4
/* 103E38 802E25B8 A2300059 */   sb       $s0, 0x59($s1)
/* 103E3C 802E25BC 00101023 */  negu      $v0, $s0
/* 103E40 802E25C0 A2220059 */  sb        $v0, 0x59($s1)
.L802E25C4:
/* 103E44 802E25C4 0C00A64D */  jal       func_80029934
/* 103E48 802E25C8 26730002 */   addiu    $s3, $s3, 2
/* 103E4C 802E25CC 3C01802F */  lui       $at, %hi(D_802EB130)
/* 103E50 802E25D0 D422B130 */  ldc1      $f2, %lo(D_802EB130)($at)
/* 103E54 802E25D4 46000021 */  cvt.d.s   $f0, $f0
/* 103E58 802E25D8 46220002 */  mul.d     $f0, $f0, $f2
/* 103E5C 802E25DC 00000000 */  nop
/* 103E60 802E25E0 46200020 */  cvt.s.d   $f0, $f0
/* 103E64 802E25E4 4600A000 */  add.s     $f0, $f20, $f0
/* 103E68 802E25E8 26940001 */  addiu     $s4, $s4, 1
/* 103E6C 802E25EC 2A820018 */  slti      $v0, $s4, 0x18
/* 103E70 802E25F0 E64001EC */  swc1      $f0, 0x1ec($s2)
/* 103E74 802E25F4 26520004 */  addiu     $s2, $s2, 4
/* 103E78 802E25F8 A2200040 */  sb        $zero, 0x40($s1)
/* 103E7C 802E25FC A220008B */  sb        $zero, 0x8b($s1)
/* 103E80 802E2600 A22000A4 */  sb        $zero, 0xa4($s1)
/* 103E84 802E2604 1440FFC3 */  bnez      $v0, .L802E2514
/* 103E88 802E2608 26310001 */   addiu    $s1, $s1, 1
/* 103E8C 802E260C 8FBF00B0 */  lw        $ra, 0xb0($sp)
/* 103E90 802E2610 8FB700AC */  lw        $s7, 0xac($sp)
/* 103E94 802E2614 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 103E98 802E2618 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 103E9C 802E261C 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 103EA0 802E2620 8FB3009C */  lw        $s3, 0x9c($sp)
/* 103EA4 802E2624 8FB20098 */  lw        $s2, 0x98($sp)
/* 103EA8 802E2628 8FB10094 */  lw        $s1, 0x94($sp)
/* 103EAC 802E262C 8FB00090 */  lw        $s0, 0x90($sp)
/* 103EB0 802E2630 D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* 103EB4 802E2634 03E00008 */  jr        $ra
/* 103EB8 802E2638 27BD00C0 */   addiu    $sp, $sp, 0xc0
