.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B24B0
/* 3B4C40 E00B24B0 27BDFF00 */  addiu     $sp, $sp, -0x100
/* 3B4C44 E00B24B4 0080482D */  daddu     $t1, $a0, $zero
/* 3B4C48 E00B24B8 3C0ADB06 */  lui       $t2, 0xdb06
/* 3B4C4C E00B24BC 354A0024 */  ori       $t2, $t2, 0x24
/* 3B4C50 E00B24C0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B4C54 E00B24C4 AFB300B4 */  sw        $s3, 0xb4($sp)
/* 3B4C58 E00B24C8 3C130001 */  lui       $s3, 1
/* 3B4C5C E00B24CC 36731630 */  ori       $s3, $s3, 0x1630
/* 3B4C60 E00B24D0 AFB500BC */  sw        $s5, 0xbc($sp)
/* 3B4C64 E00B24D4 0000A82D */  daddu     $s5, $zero, $zero
/* 3B4C68 E00B24D8 3C18E00B */  lui       $t8, %hi(D_E00B2BA0)
/* 3B4C6C E00B24DC 27182BA0 */  addiu     $t8, $t8, %lo(D_E00B2BA0)
/* 3B4C70 E00B24E0 AFB800A0 */  sw        $t8, 0xa0($sp)
/* 3B4C74 E00B24E4 24180004 */  addiu     $t8, $zero, 4
/* 3B4C78 E00B24E8 AFB100AC */  sw        $s1, 0xac($sp)
/* 3B4C7C E00B24EC 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 3B4C80 E00B24F0 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 3B4C84 E00B24F4 3C02E700 */  lui       $v0, 0xe700
/* 3B4C88 E00B24F8 AFBF00CC */  sw        $ra, 0xcc($sp)
/* 3B4C8C E00B24FC AFBE00C8 */  sw        $fp, 0xc8($sp)
/* 3B4C90 E00B2500 AFB700C4 */  sw        $s7, 0xc4($sp)
/* 3B4C94 E00B2504 AFB600C0 */  sw        $s6, 0xc0($sp)
/* 3B4C98 E00B2508 AFB400B8 */  sw        $s4, 0xb8($sp)
/* 3B4C9C E00B250C AFB200B0 */  sw        $s2, 0xb0($sp)
/* 3B4CA0 E00B2510 AFB000A8 */  sw        $s0, 0xa8($sp)
/* 3B4CA4 E00B2514 F7BE00F8 */  sdc1      $f30, 0xf8($sp)
/* 3B4CA8 E00B2518 F7BC00F0 */  sdc1      $f28, 0xf0($sp)
/* 3B4CAC E00B251C F7BA00E8 */  sdc1      $f26, 0xe8($sp)
/* 3B4CB0 E00B2520 F7B800E0 */  sdc1      $f24, 0xe0($sp)
/* 3B4CB4 E00B2524 F7B600D8 */  sdc1      $f22, 0xd8($sp)
/* 3B4CB8 E00B2528 F7B400D0 */  sdc1      $f20, 0xd0($sp)
/* 3B4CBC E00B252C AFA0009C */  sw        $zero, 0x9c($sp)
/* 3B4CC0 E00B2530 AFB800A4 */  sw        $t8, 0xa4($sp)
/* 3B4CC4 E00B2534 8E280000 */  lw        $t0, ($s1)
/* 3B4CC8 E00B2538 3C013FE0 */  lui       $at, 0x3fe0
/* 3B4CCC E00B253C 4481E800 */  mtc1      $at, $f29
/* 3B4CD0 E00B2540 4480E000 */  mtc1      $zero, $f28
/* 3B4CD4 E00B2544 3C0141A0 */  lui       $at, 0x41a0
/* 3B4CD8 E00B2548 4481D000 */  mtc1      $at, $f26
/* 3B4CDC E00B254C 44800000 */  mtc1      $zero, $f0
/* 3B4CE0 E00B2550 8D37000C */  lw        $s7, 0xc($t1)
/* 3B4CE4 E00B2554 0100182D */  daddu     $v1, $t0, $zero
/* 3B4CE8 E00B2558 44050000 */  mfc1      $a1, $f0
/* 3B4CEC E00B255C 25080008 */  addiu     $t0, $t0, 8
/* 3B4CF0 E00B2560 AE280000 */  sw        $t0, ($s1)
/* 3B4CF4 E00B2564 8EF80000 */  lw        $t8, ($s7)
/* 3B4CF8 E00B2568 4485F000 */  mtc1      $a1, $f30
/* 3B4CFC E00B256C 00A0302D */  daddu     $a2, $a1, $zero
/* 3B4D00 E00B2570 AFB80090 */  sw        $t8, 0x90($sp)
/* 3B4D04 E00B2574 C6E40050 */  lwc1      $f4, 0x50($s7)
/* 3B4D08 E00B2578 00A0382D */  daddu     $a3, $a1, $zero
/* 3B4D0C E00B257C E7A40098 */  swc1      $f4, 0x98($sp)
/* 3B4D10 E00B2580 AC620000 */  sw        $v0, ($v1)
/* 3B4D14 E00B2584 AC600004 */  sw        $zero, 4($v1)
/* 3B4D18 E00B2588 AD0A0000 */  sw        $t2, ($t0)
/* 3B4D1C E00B258C 8D230010 */  lw        $v1, 0x10($t1)
/* 3B4D20 E00B2590 25020008 */  addiu     $v0, $t0, 8
/* 3B4D24 E00B2594 AE220000 */  sw        $v0, ($s1)
/* 3B4D28 E00B2598 8C62001C */  lw        $v0, 0x1c($v1)
/* 3B4D2C E00B259C 3C038000 */  lui       $v1, 0x8000
/* 3B4D30 E00B25A0 00431021 */  addu      $v0, $v0, $v1
/* 3B4D34 E00B25A4 0C080108 */  jal       func_E0200420
/* 3B4D38 E00B25A8 AD020004 */   sw       $v0, 4($t0)
/* 3B4D3C E00B25AC 02E0B02D */  daddu     $s6, $s7, $zero
/* 3B4D40 E00B25B0 3C013D4C */  lui       $at, 0x3d4c
/* 3B4D44 E00B25B4 3421CCCD */  ori       $at, $at, 0xcccd
/* 3B4D48 E00B25B8 44810000 */  mtc1      $at, $f0
/* 3B4D4C E00B25BC 27B00050 */  addiu     $s0, $sp, 0x50
/* 3B4D50 E00B25C0 44050000 */  mfc1      $a1, $f0
/* 3B4D54 E00B25C4 0200202D */  daddu     $a0, $s0, $zero
/* 3B4D58 E00B25C8 00A0302D */  daddu     $a2, $a1, $zero
/* 3B4D5C E00B25CC 0C080110 */  jal       func_E0200440
/* 3B4D60 E00B25D0 00A0382D */   daddu    $a3, $a1, $zero
/* 3B4D64 E00B25D4 0200202D */  daddu     $a0, $s0, $zero
/* 3B4D68 E00B25D8 27A50010 */  addiu     $a1, $sp, 0x10
/* 3B4D6C E00B25DC 0C080114 */  jal       func_E0200450
/* 3B4D70 E00B25E0 00A0302D */   daddu    $a2, $a1, $zero
/* 3B4D74 E00B25E4 27A40010 */  addiu     $a0, $sp, 0x10
/* 3B4D78 E00B25E8 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3B4D7C E00B25EC 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3B4D80 E00B25F0 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 3B4D84 E00B25F4 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 3B4D88 E00B25F8 96050000 */  lhu       $a1, ($s0)
/* 3B4D8C E00B25FC 8E420000 */  lw        $v0, ($s2)
/* 3B4D90 E00B2600 00052980 */  sll       $a1, $a1, 6
/* 3B4D94 E00B2604 00B32821 */  addu      $a1, $a1, $s3
/* 3B4D98 E00B2608 0C080118 */  jal       func_E0200460
/* 3B4D9C E00B260C 00452821 */   addu     $a1, $v0, $a1
/* 3B4DA0 E00B2610 3C03DA38 */  lui       $v1, 0xda38
/* 3B4DA4 E00B2614 8E240000 */  lw        $a0, ($s1)
/* 3B4DA8 E00B2618 34630002 */  ori       $v1, $v1, 2
/* 3B4DAC E00B261C 0080282D */  daddu     $a1, $a0, $zero
/* 3B4DB0 E00B2620 24840008 */  addiu     $a0, $a0, 8
/* 3B4DB4 E00B2624 24980018 */  addiu     $t8, $a0, 0x18
/* 3B4DB8 E00B2628 0300F02D */  daddu     $fp, $t8, $zero
/* 3B4DBC E00B262C AFB80094 */  sw        $t8, 0x94($sp)
/* 3B4DC0 E00B2630 96020000 */  lhu       $v0, ($s0)
/* 3B4DC4 E00B2634 24940027 */  addiu     $s4, $a0, 0x27
/* 3B4DC8 E00B2638 AE240000 */  sw        $a0, ($s1)
/* 3B4DCC E00B263C ACA30000 */  sw        $v1, ($a1)
/* 3B4DD0 E00B2640 24430001 */  addiu     $v1, $v0, 1
/* 3B4DD4 E00B2644 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B4DD8 E00B2648 00021180 */  sll       $v0, $v0, 6
/* 3B4DDC E00B264C A6030000 */  sh        $v1, ($s0)
/* 3B4DE0 E00B2650 8E430000 */  lw        $v1, ($s2)
/* 3B4DE4 E00B2654 00531021 */  addu      $v0, $v0, $s3
/* 3B4DE8 E00B2658 00621821 */  addu      $v1, $v1, $v0
/* 3B4DEC E00B265C 24820008 */  addiu     $v0, $a0, 8
/* 3B4DF0 E00B2660 ACA30004 */  sw        $v1, 4($a1)
/* 3B4DF4 E00B2664 AE220000 */  sw        $v0, ($s1)
/* 3B4DF8 E00B2668 3C02FA00 */  lui       $v0, 0xfa00
/* 3B4DFC E00B266C AC820000 */  sw        $v0, ($a0)
/* 3B4E00 E00B2670 92E20037 */  lbu       $v0, 0x37($s7)
/* 3B4E04 E00B2674 92E5003B */  lbu       $a1, 0x3b($s7)
/* 3B4E08 E00B2678 92E6003F */  lbu       $a2, 0x3f($s7)
/* 3B4E0C E00B267C 92E70043 */  lbu       $a3, 0x43($s7)
/* 3B4E10 E00B2680 24830010 */  addiu     $v1, $a0, 0x10
/* 3B4E14 E00B2684 AE230000 */  sw        $v1, ($s1)
/* 3B4E18 E00B2688 3C03FB00 */  lui       $v1, 0xfb00
/* 3B4E1C E00B268C AC830008 */  sw        $v1, 8($a0)
/* 3B4E20 E00B2690 00021600 */  sll       $v0, $v0, 0x18
/* 3B4E24 E00B2694 00052C00 */  sll       $a1, $a1, 0x10
/* 3B4E28 E00B2698 00451025 */  or        $v0, $v0, $a1
/* 3B4E2C E00B269C 00063200 */  sll       $a2, $a2, 8
/* 3B4E30 E00B26A0 00461025 */  or        $v0, $v0, $a2
/* 3B4E34 E00B26A4 00471025 */  or        $v0, $v0, $a3
/* 3B4E38 E00B26A8 AC820004 */  sw        $v0, 4($a0)
/* 3B4E3C E00B26AC 92E20047 */  lbu       $v0, 0x47($s7)
/* 3B4E40 E00B26B0 92E5004B */  lbu       $a1, 0x4b($s7)
/* 3B4E44 E00B26B4 92E6004F */  lbu       $a2, 0x4f($s7)
/* 3B4E48 E00B26B8 3C03DE01 */  lui       $v1, 0xde01
/* 3B4E4C E00B26BC AC830010 */  sw        $v1, 0x10($a0)
/* 3B4E50 E00B26C0 24830198 */  addiu     $v1, $a0, 0x198
/* 3B4E54 E00B26C4 AC830014 */  sw        $v1, 0x14($a0)
/* 3B4E58 E00B26C8 AE230000 */  sw        $v1, ($s1)
/* 3B4E5C E00B26CC 00021600 */  sll       $v0, $v0, 0x18
/* 3B4E60 E00B26D0 00052C00 */  sll       $a1, $a1, 0x10
/* 3B4E64 E00B26D4 00451025 */  or        $v0, $v0, $a1
/* 3B4E68 E00B26D8 00063200 */  sll       $a2, $a2, 8
/* 3B4E6C E00B26DC 00461025 */  or        $v0, $v0, $a2
/* 3B4E70 E00B26E0 344200C8 */  ori       $v0, $v0, 0xc8
/* 3B4E74 E00B26E4 AC82000C */  sw        $v0, 0xc($a0)
.LE00B26E8:
/* 3B4E78 E00B26E8 12A00008 */  beqz      $s5, .LE00B270C
/* 3B4E7C E00B26EC 0000C02D */   daddu    $t8, $zero, $zero
/* 3B4E80 E00B26F0 13150006 */  beq       $t8, $s5, .LE00B270C
/* 3B4E84 E00B26F4 2402000B */   addiu    $v0, $zero, 0xb
/* 3B4E88 E00B26F8 12A2000F */  beq       $s5, $v0, .LE00B2738
/* 3B4E8C E00B26FC 00000000 */   nop      
/* 3B4E90 E00B2700 8EC20178 */  lw        $v0, 0x178($s6)
/* 3B4E94 E00B2704 1440000C */  bnez      $v0, .LE00B2738
/* 3B4E98 E00B2708 00000000 */   nop      
.LE00B270C:
/* 3B4E9C E00B270C 8FB800A4 */  lw        $t8, 0xa4($sp)
/* 3B4EA0 E00B2710 8EC60118 */  lw        $a2, 0x118($s6)
/* 3B4EA4 E00B2714 C6C000E8 */  lwc1      $f0, 0xe8($s6)
/* 3B4EA8 E00B2718 02F81021 */  addu      $v0, $s7, $t8
/* 3B4EAC E00B271C 46000007 */  neg.s     $f0, $f0
/* 3B4EB0 E00B2720 C44C0118 */  lwc1      $f12, 0x118($v0)
/* 3B4EB4 E00B2724 C44E00E8 */  lwc1      $f14, 0xe8($v0)
/* 3B4EB8 E00B2728 44070000 */  mfc1      $a3, $f0
/* 3B4EBC E00B272C 0C080148 */  jal       func_E0200520
/* 3B4EC0 E00B2730 46007387 */   neg.s    $f14, $f14
/* 3B4EC4 E00B2734 46000607 */  neg.s     $f24, $f0
.LE00B2738:
/* 3B4EC8 E00B2738 8EE20000 */  lw        $v0, ($s7)
/* 3B4ECC E00B273C 14400015 */  bnez      $v0, .LE00B2794
/* 3B4ED0 E00B2740 00000000 */   nop      
/* 3B4ED4 E00B2744 C6C001A8 */  lwc1      $f0, 0x1a8($s6)
/* 3B4ED8 E00B2748 46800020 */  cvt.s.w   $f0, $f0
/* 3B4EDC E00B274C 46000021 */  cvt.d.s   $f0, $f0
/* 3B4EE0 E00B2750 463C0002 */  mul.d     $f0, $f0, $f28
/* 3B4EE4 E00B2754 00000000 */  nop       
/* 3B4EE8 E00B2758 3C014000 */  lui       $at, 0x4000
/* 3B4EEC E00B275C 44811800 */  mtc1      $at, $f3
/* 3B4EF0 E00B2760 44801000 */  mtc1      $zero, $f2
/* 3B4EF4 E00B2764 00000000 */  nop       
/* 3B4EF8 E00B2768 46220000 */  add.d     $f0, $f0, $f2
/* 3B4EFC E00B276C 3C0140C0 */  lui       $at, 0x40c0
/* 3B4F00 E00B2770 44812000 */  mtc1      $at, $f4
/* 3B4F04 E00B2774 462005A0 */  cvt.s.d   $f22, $f0
/* 3B4F08 E00B2778 4616203C */  c.lt.s    $f4, $f22
/* 3B4F0C E00B277C 00000000 */  nop       
/* 3B4F10 E00B2780 45030001 */  bc1tl     .LE00B2788
/* 3B4F14 E00B2784 46002586 */   mov.s    $f22, $f4
.LE00B2788:
/* 3B4F18 E00B2788 8FB800A0 */  lw        $t8, 0xa0($sp)
/* 3B4F1C E00B278C 0802CA04 */  j         .LE00B2810
/* 3B4F20 E00B2790 93110000 */   lbu      $s1, ($t8)
.LE00B2794:
/* 3B4F24 E00B2794 C6C001A8 */  lwc1      $f0, 0x1a8($s6)
/* 3B4F28 E00B2798 46800020 */  cvt.s.w   $f0, $f0
/* 3B4F2C E00B279C 46000021 */  cvt.d.s   $f0, $f0
/* 3B4F30 E00B27A0 463C0002 */  mul.d     $f0, $f0, $f28
/* 3B4F34 E00B27A4 00000000 */  nop       
/* 3B4F38 E00B27A8 3C013FF0 */  lui       $at, 0x3ff0
/* 3B4F3C E00B27AC 44811800 */  mtc1      $at, $f3
/* 3B4F40 E00B27B0 44801000 */  mtc1      $zero, $f2
/* 3B4F44 E00B27B4 00000000 */  nop       
/* 3B4F48 E00B27B8 46220000 */  add.d     $f0, $f0, $f2
/* 3B4F4C E00B27BC 3C0141F0 */  lui       $at, 0x41f0
/* 3B4F50 E00B27C0 44811000 */  mtc1      $at, $f2
/* 3B4F54 E00B27C4 462005A0 */  cvt.s.d   $f22, $f0
/* 3B4F58 E00B27C8 4616103C */  c.lt.s    $f2, $f22
/* 3B4F5C E00B27CC 00000000 */  nop       
/* 3B4F60 E00B27D0 45030001 */  bc1tl     .LE00B27D8
/* 3B4F64 E00B27D4 46001586 */   mov.s    $f22, $f2
.LE00B27D8:
/* 3B4F68 E00B27D8 02F51021 */  addu      $v0, $s7, $s5
/* 3B4F6C E00B27DC 8FB800A0 */  lw        $t8, 0xa0($sp)
/* 3B4F70 E00B27E0 904201D8 */  lbu       $v0, 0x1d8($v0)
/* 3B4F74 E00B27E4 93030000 */  lbu       $v1, ($t8)
/* 3B4F78 E00B27E8 00620018 */  mult      $v1, $v0
/* 3B4F7C E00B27EC 00001812 */  mflo      $v1
/* 3B4F80 E00B27F0 3C028080 */  lui       $v0, 0x8080
/* 3B4F84 E00B27F4 34428081 */  ori       $v0, $v0, 0x8081
/* 3B4F88 E00B27F8 00620018 */  mult      $v1, $v0
/* 3B4F8C E00B27FC 00001010 */  mfhi      $v0
/* 3B4F90 E00B2800 00431021 */  addu      $v0, $v0, $v1
/* 3B4F94 E00B2804 000211C3 */  sra       $v0, $v0, 7
/* 3B4F98 E00B2808 00031FC3 */  sra       $v1, $v1, 0x1f
/* 3B4F9C E00B280C 00438823 */  subu      $s1, $v0, $v1
.LE00B2810:
/* 3B4FA0 E00B2810 C7A40098 */  lwc1      $f4, 0x98($sp)
/* 3B4FA4 E00B2814 8FB8009C */  lw        $t8, 0x9c($sp)
/* 3B4FA8 E00B2818 4604B582 */  mul.s     $f22, $f22, $f4
/* 3B4FAC E00B281C 00000000 */  nop       
/* 3B4FB0 E00B2820 4600C306 */  mov.s     $f12, $f24
/* 3B4FB4 E00B2824 03158021 */  addu      $s0, $t8, $s5
/* 3B4FB8 E00B2828 0C080140 */  jal       func_E0200500
/* 3B4FBC E00B282C 00108180 */   sll      $s0, $s0, 6
/* 3B4FC0 E00B2830 4600B502 */  mul.s     $f20, $f22, $f0
/* 3B4FC4 E00B2834 00000000 */  nop       
/* 3B4FC8 E00B2838 0C080144 */  jal       func_E0200510
/* 3B4FCC E00B283C 4600C306 */   mov.s    $f12, $f24
/* 3B4FD0 E00B2840 C6C200E8 */  lwc1      $f2, 0xe8($s6)
/* 3B4FD4 E00B2844 46141080 */  add.s     $f2, $f2, $f20
/* 3B4FD8 E00B2848 461A1082 */  mul.s     $f2, $f2, $f26
/* 3B4FDC E00B284C 00000000 */  nop       
/* 3B4FE0 E00B2850 4600B002 */  mul.s     $f0, $f22, $f0
/* 3B4FE4 E00B2854 00000000 */  nop       
/* 3B4FE8 E00B2858 4600110D */  trunc.w.s $f4, $f2
/* 3B4FEC E00B285C 44022000 */  mfc1      $v0, $f4
/* 3B4FF0 E00B2860 00000000 */  nop       
/* 3B4FF4 E00B2864 A7C20000 */  sh        $v0, ($fp)
/* 3B4FF8 E00B2868 C6C20118 */  lwc1      $f2, 0x118($s6)
/* 3B4FFC E00B286C 46001080 */  add.s     $f2, $f2, $f0
/* 3B5000 E00B2870 461A1082 */  mul.s     $f2, $f2, $f26
/* 3B5004 E00B2874 00000000 */  nop       
/* 3B5008 E00B2878 4600110D */  trunc.w.s $f4, $f2
/* 3B500C E00B287C 44022000 */  mfc1      $v0, $f4
/* 3B5010 E00B2880 00000000 */  nop       
/* 3B5014 E00B2884 A682FFF3 */  sh        $v0, -0xd($s4)
/* 3B5018 E00B2888 32A20001 */  andi      $v0, $s5, 1
/* 3B501C E00B288C 00022A00 */  sll       $a1, $v0, 8
/* 3B5020 E00B2890 00A22823 */  subu      $a1, $a1, $v0
/* 3B5024 E00B2894 00151043 */  sra       $v0, $s5, 1
/* 3B5028 E00B2898 30420001 */  andi      $v0, $v0, 1
/* 3B502C E00B289C 00022200 */  sll       $a0, $v0, 8
/* 3B5030 E00B28A0 00822023 */  subu      $a0, $a0, $v0
/* 3B5034 E00B28A4 00151083 */  sra       $v0, $s5, 2
/* 3B5038 E00B28A8 30420001 */  andi      $v0, $v0, 1
/* 3B503C E00B28AC 00021A00 */  sll       $v1, $v0, 8
/* 3B5040 E00B28B0 C6C20148 */  lwc1      $f2, 0x148($s6)
/* 3B5044 E00B28B4 00621823 */  subu      $v1, $v1, $v0
/* 3B5048 E00B28B8 461E1080 */  add.s     $f2, $f2, $f30
/* 3B504C E00B28BC A690FFF9 */  sh        $s0, -7($s4)
/* 3B5050 E00B28C0 A680FFFB */  sh        $zero, -5($s4)
/* 3B5054 E00B28C4 461A1082 */  mul.s     $f2, $f2, $f26
/* 3B5058 E00B28C8 00000000 */  nop       
/* 3B505C E00B28CC A285FFFD */  sb        $a1, -3($s4)
/* 3B5060 E00B28D0 A284FFFE */  sb        $a0, -2($s4)
/* 3B5064 E00B28D4 A283FFFF */  sb        $v1, -1($s4)
/* 3B5068 E00B28D8 A2910000 */  sb        $s1, ($s4)
/* 3B506C E00B28DC 4600110D */  trunc.w.s $f4, $f2
/* 3B5070 E00B28E0 44022000 */  mfc1      $v0, $f4
/* 3B5074 E00B28E4 00000000 */  nop       
/* 3B5078 E00B28E8 A682FFF5 */  sh        $v0, -0xb($s4)
/* 3B507C E00B28EC C6C200E8 */  lwc1      $f2, 0xe8($s6)
/* 3B5080 E00B28F0 46141081 */  sub.s     $f2, $f2, $f20
/* 3B5084 E00B28F4 461A1082 */  mul.s     $f2, $f2, $f26
/* 3B5088 E00B28F8 00000000 */  nop       
/* 3B508C E00B28FC 27DE0010 */  addiu     $fp, $fp, 0x10
/* 3B5090 E00B2900 26B50001 */  addiu     $s5, $s5, 1
/* 3B5094 E00B2904 26940010 */  addiu     $s4, $s4, 0x10
/* 3B5098 E00B2908 4600110D */  trunc.w.s $f4, $f2
/* 3B509C E00B290C 44022000 */  mfc1      $v0, $f4
/* 3B50A0 E00B2910 00000000 */  nop       
/* 3B50A4 E00B2914 A7C20000 */  sh        $v0, ($fp)
/* 3B50A8 E00B2918 8FB8009C */  lw        $t8, 0x9c($sp)
/* 3B50AC E00B291C C6C20118 */  lwc1      $f2, 0x118($s6)
/* 3B50B0 E00B2920 27180004 */  addiu     $t8, $t8, 4
/* 3B50B4 E00B2924 AFB8009C */  sw        $t8, 0x9c($sp)
/* 3B50B8 E00B2928 8FB800A0 */  lw        $t8, 0xa0($sp)
/* 3B50BC E00B292C 46001081 */  sub.s     $f2, $f2, $f0
/* 3B50C0 E00B2930 27180001 */  addiu     $t8, $t8, 1
/* 3B50C4 E00B2934 AFB800A0 */  sw        $t8, 0xa0($sp)
/* 3B50C8 E00B2938 461A1082 */  mul.s     $f2, $f2, $f26
/* 3B50CC E00B293C 00000000 */  nop       
/* 3B50D0 E00B2940 8FB800A4 */  lw        $t8, 0xa4($sp)
/* 3B50D4 E00B2944 27DE0010 */  addiu     $fp, $fp, 0x10
/* 3B50D8 E00B2948 27180004 */  addiu     $t8, $t8, 4
/* 3B50DC E00B294C AFB800A4 */  sw        $t8, 0xa4($sp)
/* 3B50E0 E00B2950 4600110D */  trunc.w.s $f4, $f2
/* 3B50E4 E00B2954 44022000 */  mfc1      $v0, $f4
/* 3B50E8 E00B2958 00000000 */  nop       
/* 3B50EC E00B295C A682FFF3 */  sh        $v0, -0xd($s4)
/* 3B50F0 E00B2960 C6C00148 */  lwc1      $f0, 0x148($s6)
/* 3B50F4 E00B2964 26D60004 */  addiu     $s6, $s6, 4
/* 3B50F8 E00B2968 24020400 */  addiu     $v0, $zero, 0x400
/* 3B50FC E00B296C 461E0000 */  add.s     $f0, $f0, $f30
/* 3B5100 E00B2970 A690FFF9 */  sh        $s0, -7($s4)
/* 3B5104 E00B2974 A682FFFB */  sh        $v0, -5($s4)
/* 3B5108 E00B2978 461A0002 */  mul.s     $f0, $f0, $f26
/* 3B510C E00B297C 00000000 */  nop       
/* 3B5110 E00B2980 A285FFFD */  sb        $a1, -3($s4)
/* 3B5114 E00B2984 A284FFFE */  sb        $a0, -2($s4)
/* 3B5118 E00B2988 A283FFFF */  sb        $v1, -1($s4)
/* 3B511C E00B298C A2910000 */  sb        $s1, ($s4)
/* 3B5120 E00B2990 4600010D */  trunc.w.s $f4, $f0
/* 3B5124 E00B2994 44022000 */  mfc1      $v0, $f4
/* 3B5128 E00B2998 00000000 */  nop       
/* 3B512C E00B299C A682FFF5 */  sh        $v0, -0xb($s4)
/* 3B5130 E00B29A0 2AA2000C */  slti      $v0, $s5, 0xc
/* 3B5134 E00B29A4 1440FF50 */  bnez      $v0, .LE00B26E8
/* 3B5138 E00B29A8 26940010 */   addiu    $s4, $s4, 0x10
/* 3B513C E00B29AC 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* 3B5140 E00B29B0 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* 3B5144 E00B29B4 3C080900 */  lui       $t0, 0x900
/* 3B5148 E00B29B8 250808A8 */  addiu     $t0, $t0, 0x8a8
/* 3B514C E00B29BC 00151040 */  sll       $v0, $s5, 1
/* 3B5150 E00B29C0 304400FF */  andi      $a0, $v0, 0xff
/* 3B5154 E00B29C4 00042300 */  sll       $a0, $a0, 0xc
/* 3B5158 E00B29C8 3042007F */  andi      $v0, $v0, 0x7f
/* 3B515C E00B29CC 00021040 */  sll       $v0, $v0, 1
/* 3B5160 E00B29D0 3C030100 */  lui       $v1, 0x100
/* 3B5164 E00B29D4 00431025 */  or        $v0, $v0, $v1
/* 3B5168 E00B29D8 8CE60000 */  lw        $a2, ($a3)
/* 3B516C E00B29DC 00822025 */  or        $a0, $a0, $v0
/* 3B5170 E00B29E0 00C0282D */  daddu     $a1, $a2, $zero
/* 3B5174 E00B29E4 24C60008 */  addiu     $a2, $a2, 8
/* 3B5178 E00B29E8 ACE60000 */  sw        $a2, ($a3)
/* 3B517C E00B29EC ACA40000 */  sw        $a0, ($a1)
/* 3B5180 E00B29F0 8FB80094 */  lw        $t8, 0x94($sp)
/* 3B5184 E00B29F4 24C20008 */  addiu     $v0, $a2, 8
/* 3B5188 E00B29F8 ACB80004 */  sw        $t8, 4($a1)
/* 3B518C E00B29FC ACE20000 */  sw        $v0, ($a3)
/* 3B5190 E00B2A00 3C02DE00 */  lui       $v0, 0xde00
/* 3B5194 E00B2A04 ACC20000 */  sw        $v0, ($a2)
/* 3B5198 E00B2A08 8FB80090 */  lw        $t8, 0x90($sp)
/* 3B519C E00B2A0C 17000003 */  bnez      $t8, .LE00B2A1C
/* 3B51A0 E00B2A10 02A0102D */   daddu    $v0, $s5, $zero
/* 3B51A4 E00B2A14 3C080900 */  lui       $t0, 0x900
/* 3B51A8 E00B2A18 25080800 */  addiu     $t0, $t0, 0x800
.LE00B2A1C:
/* 3B51AC E00B2A1C ACC80004 */  sw        $t0, 4($a2)
/* 3B51B0 E00B2A20 2442FFFF */  addiu     $v0, $v0, -1
/* 3B51B4 E00B2A24 18400039 */  blez      $v0, .LE00B2B0C
/* 3B51B8 E00B2A28 0000A82D */   daddu    $s5, $zero, $zero
/* 3B51BC E00B2A2C 00E0582D */  daddu     $t3, $a3, $zero
/* 3B51C0 E00B2A30 3C0A0600 */  lui       $t2, 0x600
/* 3B51C4 E00B2A34 24090001 */  addiu     $t1, $zero, 1
/* 3B51C8 E00B2A38 3C0F0606 */  lui       $t7, 0x606
/* 3B51CC E00B2A3C 35EF0402 */  ori       $t7, $t7, 0x402
/* 3B51D0 E00B2A40 3C0E0002 */  lui       $t6, 2
/* 3B51D4 E00B2A44 35CE0406 */  ori       $t6, $t6, 0x406
/* 3B51D8 E00B2A48 3C0D0006 */  lui       $t5, 6
/* 3B51DC E00B2A4C 35AD0804 */  ori       $t5, $t5, 0x804
/* 3B51E0 E00B2A50 0040602D */  daddu     $t4, $v0, $zero
/* 3B51E4 E00B2A54 24070004 */  addiu     $a3, $zero, 4
/* 3B51E8 E00B2A58 24060002 */  addiu     $a2, $zero, 2
/* 3B51EC E00B2A5C 24080006 */  addiu     $t0, $zero, 6
.LE00B2A60:
/* 3B51F0 E00B2A60 2AA20000 */  slti      $v0, $s5, 0
/* 3B51F4 E00B2A64 14400023 */  bnez      $v0, .LE00B2AF4
/* 3B51F8 E00B2A68 00152840 */   sll      $a1, $s5, 1
/* 3B51FC E00B2A6C 8D640000 */  lw        $a0, ($t3)
/* 3B5200 E00B2A70 24820008 */  addiu     $v0, $a0, 8
/* 3B5204 E00B2A74 14A00004 */  bnez      $a1, .LE00B2A88
/* 3B5208 E00B2A78 AD620000 */   sw       $v0, ($t3)
/* 3B520C E00B2A7C 00151440 */  sll       $v0, $s5, 0x11
/* 3B5210 E00B2A80 0802CAAC */  j         .LE00B2AB0
/* 3B5214 E00B2A84 34420402 */   ori      $v0, $v0, 0x402
.LE00B2A88:
/* 3B5218 E00B2A88 14A90003 */  bne       $a1, $t1, .LE00B2A98
/* 3B521C E00B2A8C 30C200FF */   andi     $v0, $a2, 0xff
/* 3B5220 E00B2A90 0802CAAE */  j         .LE00B2AB8
/* 3B5224 E00B2A94 AC8F0000 */   sw       $t7, ($a0)
.LE00B2A98:
/* 3B5228 E00B2A98 00021400 */  sll       $v0, $v0, 0x10
/* 3B522C E00B2A9C 00151A80 */  sll       $v1, $s5, 0xa
/* 3B5230 E00B2AA0 3063FC00 */  andi      $v1, $v1, 0xfc00
/* 3B5234 E00B2AA4 00431025 */  or        $v0, $v0, $v1
/* 3B5238 E00B2AA8 30E300FF */  andi      $v1, $a3, 0xff
/* 3B523C E00B2AAC 00431025 */  or        $v0, $v0, $v1
.LE00B2AB0:
/* 3B5240 E00B2AB0 004A1025 */  or        $v0, $v0, $t2
/* 3B5244 E00B2AB4 AC820000 */  sw        $v0, ($a0)
.LE00B2AB8:
/* 3B5248 E00B2AB8 14A00003 */  bnez      $a1, .LE00B2AC8
/* 3B524C E00B2ABC 00000000 */   nop      
/* 3B5250 E00B2AC0 0802CABD */  j         .LE00B2AF4
/* 3B5254 E00B2AC4 AC8E0004 */   sw       $t6, 4($a0)
.LE00B2AC8:
/* 3B5258 E00B2AC8 14A90003 */  bne       $a1, $t1, .LE00B2AD8
/* 3B525C E00B2ACC 310200FF */   andi     $v0, $t0, 0xff
/* 3B5260 E00B2AD0 0802CABD */  j         .LE00B2AF4
/* 3B5264 E00B2AD4 AC8D0004 */   sw       $t5, 4($a0)
.LE00B2AD8:
/* 3B5268 E00B2AD8 00021400 */  sll       $v0, $v0, 0x10
/* 3B526C E00B2ADC 30C300FF */  andi      $v1, $a2, 0xff
/* 3B5270 E00B2AE0 00031A00 */  sll       $v1, $v1, 8
/* 3B5274 E00B2AE4 00431025 */  or        $v0, $v0, $v1
/* 3B5278 E00B2AE8 30E300FF */  andi      $v1, $a3, 0xff
/* 3B527C E00B2AEC 00431025 */  or        $v0, $v0, $v1
/* 3B5280 E00B2AF0 AC820004 */  sw        $v0, 4($a0)
.LE00B2AF4:
/* 3B5284 E00B2AF4 24E70004 */  addiu     $a3, $a3, 4
/* 3B5288 E00B2AF8 24C60004 */  addiu     $a2, $a2, 4
/* 3B528C E00B2AFC 26B50001 */  addiu     $s5, $s5, 1
/* 3B5290 E00B2B00 02AC102A */  slt       $v0, $s5, $t4
/* 3B5294 E00B2B04 1440FFD6 */  bnez      $v0, .LE00B2A60
/* 3B5298 E00B2B08 25080004 */   addiu    $t0, $t0, 4
.LE00B2B0C:
/* 3B529C E00B2B0C 3C03D838 */  lui       $v1, 0xd838
/* 3B52A0 E00B2B10 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3B52A4 E00B2B14 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3B52A8 E00B2B18 8C820000 */  lw        $v0, ($a0)
/* 3B52AC E00B2B1C 34630002 */  ori       $v1, $v1, 2
/* 3B52B0 E00B2B20 0040282D */  daddu     $a1, $v0, $zero
/* 3B52B4 E00B2B24 24420008 */  addiu     $v0, $v0, 8
/* 3B52B8 E00B2B28 AC820000 */  sw        $v0, ($a0)
/* 3B52BC E00B2B2C ACA30000 */  sw        $v1, ($a1)
/* 3B52C0 E00B2B30 24030040 */  addiu     $v1, $zero, 0x40
/* 3B52C4 E00B2B34 ACA30004 */  sw        $v1, 4($a1)
/* 3B52C8 E00B2B38 24430008 */  addiu     $v1, $v0, 8
/* 3B52CC E00B2B3C AC830000 */  sw        $v1, ($a0)
/* 3B52D0 E00B2B40 3C03E700 */  lui       $v1, 0xe700
/* 3B52D4 E00B2B44 AC430000 */  sw        $v1, ($v0)
/* 3B52D8 E00B2B48 AC400004 */  sw        $zero, 4($v0)
/* 3B52DC E00B2B4C 8FBF00CC */  lw        $ra, 0xcc($sp)
/* 3B52E0 E00B2B50 8FBE00C8 */  lw        $fp, 0xc8($sp)
/* 3B52E4 E00B2B54 8FB700C4 */  lw        $s7, 0xc4($sp)
/* 3B52E8 E00B2B58 8FB600C0 */  lw        $s6, 0xc0($sp)
/* 3B52EC E00B2B5C 8FB500BC */  lw        $s5, 0xbc($sp)
/* 3B52F0 E00B2B60 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 3B52F4 E00B2B64 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 3B52F8 E00B2B68 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 3B52FC E00B2B6C 8FB100AC */  lw        $s1, 0xac($sp)
/* 3B5300 E00B2B70 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 3B5304 E00B2B74 D7BE00F8 */  ldc1      $f30, 0xf8($sp)
/* 3B5308 E00B2B78 D7BC00F0 */  ldc1      $f28, 0xf0($sp)
/* 3B530C E00B2B7C D7BA00E8 */  ldc1      $f26, 0xe8($sp)
/* 3B5310 E00B2B80 D7B800E0 */  ldc1      $f24, 0xe0($sp)
/* 3B5314 E00B2B84 D7B600D8 */  ldc1      $f22, 0xd8($sp)
/* 3B5318 E00B2B88 D7B400D0 */  ldc1      $f20, 0xd0($sp)
/* 3B531C E00B2B8C 03E00008 */  jr        $ra
/* 3B5320 E00B2B90 27BD0100 */   addiu    $sp, $sp, 0x100
/* 3B5324 E00B2B94 00000000 */  nop       
/* 3B5328 E00B2B98 00000000 */  nop       
/* 3B532C E00B2B9C 00000000 */  nop       
