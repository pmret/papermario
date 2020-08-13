.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80247458
/* 13A798 80247458 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 13A79C 8024745C AFBF0028 */  sw    $ra, 0x28($sp)
/* 13A7A0 80247460 00A0182D */  daddu $v1, $a1, $zero
/* 13A7A4 80247464 00C0382D */  daddu $a3, $a2, $zero
/* 13A7A8 80247468 10800006 */  beqz  $a0, .L80247484
/* 13A7AC 8024746C 24080008 */   addiu $t0, $zero, 8
/* 13A7B0 80247470 24020001 */  addiu $v0, $zero, 1
/* 13A7B4 80247474 1082000B */  beq   $a0, $v0, .L802474A4
/* 13A7B8 80247478 00032080 */   sll   $a0, $v1, 2
/* 13A7BC 8024747C 08091D33 */  j     .L802474CC
/* 13A7C0 80247480 00072880 */   sll   $a1, $a3, 2

.L80247484:
/* 13A7C4 80247484 00032080 */  sll   $a0, $v1, 2
/* 13A7C8 80247488 00072880 */  sll   $a1, $a3, 2
/* 13A7CC 8024748C 24660008 */  addiu $a2, $v1, 8
/* 13A7D0 80247490 00063080 */  sll   $a2, $a2, 2
/* 13A7D4 80247494 24E70008 */  addiu $a3, $a3, 8
/* 13A7D8 80247498 00073880 */  sll   $a3, $a3, 2
/* 13A7DC 8024749C 08091D38 */  j     .L802474E0
/* 13A7E0 802474A0 24020100 */   addiu $v0, $zero, 0x100

.L802474A4:
/* 13A7E4 802474A4 00072880 */  sll   $a1, $a3, 2
/* 13A7E8 802474A8 24660008 */  addiu $a2, $v1, 8
/* 13A7EC 802474AC 00063080 */  sll   $a2, $a2, 2
/* 13A7F0 802474B0 24E70008 */  addiu $a3, $a3, 8
/* 13A7F4 802474B4 00073880 */  sll   $a3, $a3, 2
/* 13A7F8 802474B8 24020400 */  addiu $v0, $zero, 0x400
/* 13A7FC 802474BC AFA00010 */  sw    $zero, 0x10($sp)
/* 13A800 802474C0 AFA00014 */  sw    $zero, 0x14($sp)
/* 13A804 802474C4 08091D3C */  j     .L802474F0
/* 13A808 802474C8 AFA00018 */   sw    $zero, 0x18($sp)
.L802474CC:
/* 13A80C 802474CC 00683021 */  addu  $a2, $v1, $t0
/* 13A810 802474D0 00063080 */  sll   $a2, $a2, 2
/* 13A814 802474D4 00E83821 */  addu  $a3, $a3, $t0
/* 13A818 802474D8 00073880 */  sll   $a3, $a3, 2
/* 13A81C 802474DC 24020200 */  addiu $v0, $zero, 0x200
.L802474E0:
/* 13A820 802474E0 AFA20018 */  sw    $v0, 0x18($sp)
/* 13A824 802474E4 24020400 */  addiu $v0, $zero, 0x400
/* 13A828 802474E8 AFA00010 */  sw    $zero, 0x10($sp)
/* 13A82C 802474EC AFA00014 */  sw    $zero, 0x14($sp)
.L802474F0:
/* 13A830 802474F0 AFA2001C */  sw    $v0, 0x1c($sp)
/* 13A834 802474F4 0C091216 */  jal   func_80244858
/* 13A838 802474F8 AFA20020 */   sw    $v0, 0x20($sp)
/* 13A83C 802474FC 8FBF0028 */  lw    $ra, 0x28($sp)
/* 13A840 80247500 03E00008 */  jr    $ra
/* 13A844 80247504 27BD0030 */   addiu $sp, $sp, 0x30

/* 13A848 80247508 27BDFF40 */  addiu $sp, $sp, -0xc0
/* 13A84C 8024750C 240A0001 */  addiu $t2, $zero, 1
/* 13A850 80247510 3C028027 */  lui   $v0, 0x8027
/* 13A854 80247514 8C420280 */  lw    $v0, 0x280($v0)
/* 13A858 80247518 3C038027 */  lui   $v1, 0x8027
/* 13A85C 8024751C 24630288 */  addiu $v1, $v1, 0x288
/* 13A860 80247520 AFBF00BC */  sw    $ra, 0xbc($sp)
/* 13A864 80247524 AFBE00B8 */  sw    $fp, 0xb8($sp)
/* 13A868 80247528 AFB700B4 */  sw    $s7, 0xb4($sp)
/* 13A86C 8024752C AFB600B0 */  sw    $s6, 0xb0($sp)
/* 13A870 80247530 AFB500AC */  sw    $s5, 0xac($sp)
/* 13A874 80247534 AFB400A8 */  sw    $s4, 0xa8($sp)
/* 13A878 80247538 AFB300A4 */  sw    $s3, 0xa4($sp)
/* 13A87C 8024753C AFB200A0 */  sw    $s2, 0xa0($sp)
/* 13A880 80247540 AFB1009C */  sw    $s1, 0x9c($sp)
/* 13A884 80247544 AFB00098 */  sw    $s0, 0x98($sp)
/* 13A888 80247548 AFA500C4 */  sw    $a1, 0xc4($sp)
/* 13A88C 8024754C AFA600C8 */  sw    $a2, 0xc8($sp)
/* 13A890 80247550 AFA700CC */  sw    $a3, 0xcc($sp)
/* 13A894 80247554 AFA00070 */  sw    $zero, 0x70($sp)
/* 13A898 80247558 AFA00074 */  sw    $zero, 0x74($sp)
/* 13A89C 8024755C AFAA0064 */  sw    $t2, 0x64($sp)
/* 13A8A0 80247560 01428004 */  sllv  $s0, $v0, $t2
/* 13A8A4 80247564 02028021 */  addu  $s0, $s0, $v0
/* 13A8A8 80247568 00108080 */  sll   $s0, $s0, 2
/* 13A8AC 8024756C 0C0911FD */  jal   func_802447F4
/* 13A8B0 80247570 02038021 */   addu  $s0, $s0, $v1
/* 13A8B4 80247574 8FAB00C4 */  lw    $t3, 0xc4($sp)
/* 13A8B8 80247578 92090002 */  lbu   $t1, 2($s0)
/* 13A8BC 8024757C 8FAA00CC */  lw    $t2, 0xcc($sp)
/* 13A8C0 80247580 25660054 */  addiu $a2, $t3, 0x54
/* 13A8C4 80247584 8FAB00D0 */  lw    $t3, 0xd0($sp)
/* 13A8C8 80247588 2543FFAC */  addiu $v1, $t2, -0x54
/* 13A8CC 8024758C AFA30014 */  sw    $v1, 0x14($sp)
/* 13A8D0 80247590 240300FF */  addiu $v1, $zero, 0xff
/* 13A8D4 80247594 AFA3001C */  sw    $v1, 0x1c($sp)
/* 13A8D8 80247598 24030140 */  addiu $v1, $zero, 0x140
/* 13A8DC 8024759C AFA30044 */  sw    $v1, 0x44($sp)
/* 13A8E0 802475A0 240300F0 */  addiu $v1, $zero, 0xf0
/* 13A8E4 802475A4 AFA30048 */  sw    $v1, 0x48($sp)
/* 13A8E8 802475A8 3C038027 */  lui   $v1, 0x8027
/* 13A8EC 802475AC 8C630378 */  lw    $v1, 0x378($v1)
/* 13A8F0 802475B0 AFAB0018 */  sw    $t3, 0x18($sp)
/* 13A8F4 802475B4 15200002 */  bnez  $t1, .L802475C0
/* 13A8F8 802475B8 0069001A */   div   $zero, $v1, $t1
/* 13A8FC 802475BC 0007000D */  break 7
.L802475C0:
/* 13A900 802475C0 2401FFFF */  addiu $at, $zero, -1
/* 13A904 802475C4 15210004 */  bne   $t1, $at, .L802475D8
/* 13A908 802475C8 3C018000 */   lui   $at, 0x8000
/* 13A90C 802475CC 14610002 */  bne   $v1, $at, .L802475D8
/* 13A910 802475D0 00000000 */   nop   
/* 13A914 802475D4 0006000D */  break 6
.L802475D8:
/* 13A918 802475D8 00005012 */  mflo  $t2
/* 13A91C 802475DC 00005810 */  mfhi  $t3
/* 13A920 802475E0 24040004 */  addiu $a0, $zero, 4
/* 13A924 802475E4 8FA700C8 */  lw    $a3, 0xc8($sp)
/* 13A928 802475E8 3C088011 */  lui   $t0, 0x8011
/* 13A92C 802475EC 8108F298 */  lb    $t0, -0xd68($t0)
/* 13A930 802475F0 3C058027 */  lui   $a1, 0x8027
/* 13A934 802475F4 24A5FC48 */  addiu $a1, $a1, -0x3b8
/* 13A938 802475F8 AFA00010 */  sw    $zero, 0x10($sp)
/* 13A93C 802475FC AFA00020 */  sw    $zero, 0x20($sp)
/* 13A940 80247600 AFA00024 */  sw    $zero, 0x24($sp)
/* 13A944 80247604 AFA00028 */  sw    $zero, 0x28($sp)
/* 13A948 80247608 AFA0002C */  sw    $zero, 0x2c($sp)
/* 13A94C 8024760C AFA00030 */  sw    $zero, 0x30($sp)
/* 13A950 80247610 AFA00034 */  sw    $zero, 0x34($sp)
/* 13A954 80247614 AFA00038 */  sw    $zero, 0x38($sp)
/* 13A958 80247618 AFA0003C */  sw    $zero, 0x3c($sp)
/* 13A95C 8024761C AFA00040 */  sw    $zero, 0x40($sp)
/* 13A960 80247620 AFA0004C */  sw    $zero, 0x4c($sp)
/* 13A964 80247624 01024023 */  subu  $t0, $t0, $v0
/* 13A968 80247628 AFA8006C */  sw    $t0, 0x6c($sp)
/* 13A96C 8024762C AFAA0060 */  sw    $t2, 0x60($sp)
/* 13A970 80247630 0C03D4B8 */  jal   draw_box
/* 13A974 80247634 AFAB005C */   sw    $t3, 0x5c($sp)
/* 13A978 80247638 3C108027 */  lui   $s0, 0x8027
/* 13A97C 8024763C 261003A8 */  addiu $s0, $s0, 0x3a8
/* 13A980 80247640 8FAA00C4 */  lw    $t2, 0xc4($sp)
/* 13A984 80247644 8E040050 */  lw    $a0, 0x50($s0)
/* 13A988 80247648 8FAB00C8 */  lw    $t3, 0xc8($sp)
/* 13A98C 8024764C 254500F1 */  addiu $a1, $t2, 0xf1
/* 13A990 80247650 0C051261 */  jal   set_icon_render_pos
/* 13A994 80247654 2566000B */   addiu $a2, $t3, 0xb
/* 13A998 80247658 8E040050 */  lw    $a0, 0x50($s0)
/* 13A99C 8024765C 240A000A */  addiu $t2, $zero, 0xa
/* 13A9A0 80247660 0C0511F8 */  jal   func_801447E0
/* 13A9A4 80247664 AFAA0068 */   sw    $t2, 0x68($sp)
/* 13A9A8 80247668 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 13A9AC 8024766C 8FAB00C4 */  lw    $t3, 0xc4($sp)
/* 13A9B0 80247670 2546000E */  addiu $a2, $t2, 0xe
/* 13A9B4 80247674 8FAA00CC */  lw    $t2, 0xcc($sp)
/* 13A9B8 80247678 25640001 */  addiu $a0, $t3, 1
/* 13A9BC 8024767C 016A1021 */  addu  $v0, $t3, $t2
/* 13A9C0 80247680 8FAB00C8 */  lw    $t3, 0xc8($sp)
/* 13A9C4 80247684 8FAA00D0 */  lw    $t2, 0xd0($sp)
/* 13A9C8 80247688 2447FFFF */  addiu $a3, $v0, -1
/* 13A9CC 8024768C 016A1021 */  addu  $v0, $t3, $t2
/* 13A9D0 80247690 1C800002 */  bgtz  $a0, .L8024769C
/* 13A9D4 80247694 2448FFF7 */   addiu $t0, $v0, -9
/* 13A9D8 80247698 24040001 */  addiu $a0, $zero, 1
.L8024769C:
/* 13A9DC 8024769C 58C00001 */  blezl $a2, .L802476A4
/* 13A9E0 802476A0 24060001 */   addiu $a2, $zero, 1
.L802476A4:
/* 13A9E4 802476A4 18E005AD */  blez  $a3, .L80248D5C
/* 13A9E8 802476A8 00000000 */   nop   
/* 13A9EC 802476AC 190005AB */  blez  $t0, .L80248D5C
/* 13A9F0 802476B0 2882013F */   slti  $v0, $a0, 0x13f
/* 13A9F4 802476B4 104005A9 */  beqz  $v0, .L80248D5C
/* 13A9F8 802476B8 28C200EF */   slti  $v0, $a2, 0xef
/* 13A9FC 802476BC 104005A7 */  beqz  $v0, .L80248D5C
/* 13AA00 802476C0 28E2013F */   slti  $v0, $a3, 0x13f
/* 13AA04 802476C4 50400001 */  beql  $v0, $zero, .L802476CC
/* 13AA08 802476C8 2407013F */   addiu $a3, $zero, 0x13f
.L802476CC:
/* 13AA0C 802476CC 290200EF */  slti  $v0, $t0, 0xef
/* 13AA10 802476D0 50400001 */  beql  $v0, $zero, .L802476D8
/* 13AA14 802476D4 240800EF */   addiu $t0, $zero, 0xef
.L802476D8:
/* 13AA18 802476D8 3C03800A */  lui   $v1, 0x800a
/* 13AA1C 802476DC 2463A66C */  addiu $v1, $v1, -0x5994
/* 13AA20 802476E0 44841000 */  mtc1  $a0, $f2
/* 13AA24 802476E4 00000000 */  nop   
/* 13AA28 802476E8 468010A0 */  cvt.s.w $f2, $f2
/* 13AA2C 802476EC 44860000 */  mtc1  $a2, $f0
/* 13AA30 802476F0 00000000 */  nop   
/* 13AA34 802476F4 46800020 */  cvt.s.w $f0, $f0
/* 13AA38 802476F8 8FAB00C4 */  lw    $t3, 0xc4($sp)
/* 13AA3C 802476FC 8FAA00C8 */  lw    $t2, 0xc8($sp)
/* 13AA40 80247700 3C014080 */  lui   $at, 0x4080
/* 13AA44 80247704 44812000 */  mtc1  $at, $f4
/* 13AA48 80247708 3C04ED00 */  lui   $a0, 0xed00
/* 13AA4C 8024770C AFA00058 */  sw    $zero, 0x58($sp)
/* 13AA50 80247710 AFA00054 */  sw    $zero, 0x54($sp)
/* 13AA54 80247714 256B0077 */  addiu $t3, $t3, 0x77
/* 13AA58 80247718 46041082 */  mul.s $f2, $f2, $f4
/* 13AA5C 8024771C 00000000 */  nop   
/* 13AA60 80247720 254A0011 */  addiu $t2, $t2, 0x11
/* 13AA64 80247724 AFAB007C */  sw    $t3, 0x7c($sp)
/* 13AA68 80247728 AFAA0080 */  sw    $t2, 0x80($sp)
/* 13AA6C 8024772C 8C620000 */  lw    $v0, ($v1)
/* 13AA70 80247730 46040002 */  mul.s $f0, $f0, $f4
/* 13AA74 80247734 00000000 */  nop   
/* 13AA78 80247738 0040282D */  daddu $a1, $v0, $zero
/* 13AA7C 8024773C 24420008 */  addiu $v0, $v0, 8
/* 13AA80 80247740 AC620000 */  sw    $v0, ($v1)
/* 13AA84 80247744 4600118D */  trunc.w.s $f6, $f2
/* 13AA88 80247748 44023000 */  mfc1  $v0, $f6
/* 13AA8C 8024774C 00000000 */  nop   
/* 13AA90 80247750 30420FFF */  andi  $v0, $v0, 0xfff
/* 13AA94 80247754 00021300 */  sll   $v0, $v0, 0xc
/* 13AA98 80247758 4600018D */  trunc.w.s $f6, $f0
/* 13AA9C 8024775C 44033000 */  mfc1  $v1, $f6
/* 13AAA0 80247760 44871000 */  mtc1  $a3, $f2
/* 13AAA4 80247764 00000000 */  nop   
/* 13AAA8 80247768 468010A0 */  cvt.s.w $f2, $f2
/* 13AAAC 8024776C 46041082 */  mul.s $f2, $f2, $f4
/* 13AAB0 80247770 00000000 */  nop   
/* 13AAB4 80247774 30630FFF */  andi  $v1, $v1, 0xfff
/* 13AAB8 80247778 00641825 */  or    $v1, $v1, $a0
/* 13AABC 8024777C 00431025 */  or    $v0, $v0, $v1
/* 13AAC0 80247780 44880000 */  mtc1  $t0, $f0
/* 13AAC4 80247784 00000000 */  nop   
/* 13AAC8 80247788 46800020 */  cvt.s.w $f0, $f0
/* 13AACC 8024778C 46040002 */  mul.s $f0, $f0, $f4
/* 13AAD0 80247790 00000000 */  nop   
/* 13AAD4 80247794 ACA20000 */  sw    $v0, ($a1)
/* 13AAD8 80247798 4600118D */  trunc.w.s $f6, $f2
/* 13AADC 8024779C 44023000 */  mfc1  $v0, $f6
/* 13AAE0 802477A0 00000000 */  nop   
/* 13AAE4 802477A4 30420FFF */  andi  $v0, $v0, 0xfff
/* 13AAE8 802477A8 00021300 */  sll   $v0, $v0, 0xc
/* 13AAEC 802477AC 4600018D */  trunc.w.s $f6, $f0
/* 13AAF0 802477B0 44033000 */  mfc1  $v1, $f6
/* 13AAF4 802477B4 00000000 */  nop   
/* 13AAF8 802477B8 30630FFF */  andi  $v1, $v1, 0xfff
/* 13AAFC 802477BC 00431025 */  or    $v0, $v0, $v1
/* 13AB00 802477C0 ACA20004 */  sw    $v0, 4($a1)
.L802477C4:
/* 13AB04 802477C4 AFA00050 */  sw    $zero, 0x50($sp)
.L802477C8:
/* 13AB08 802477C8 8FAB0050 */  lw    $t3, 0x50($sp)
/* 13AB0C 802477CC 3C028027 */  lui   $v0, 0x8027
/* 13AB10 802477D0 24420288 */  addiu $v0, $v0, 0x288
/* 13AB14 802477D4 000B1840 */  sll   $v1, $t3, 1
/* 13AB18 802477D8 006B1821 */  addu  $v1, $v1, $t3
/* 13AB1C 802477DC 00031880 */  sll   $v1, $v1, 2
/* 13AB20 802477E0 00621821 */  addu  $v1, $v1, $v0
/* 13AB24 802477E4 AFA30078 */  sw    $v1, 0x78($sp)
/* 13AB28 802477E8 90620000 */  lbu   $v0, ($v1)
/* 13AB2C 802477EC 10400261 */  beqz  $v0, .L80248174
/* 13AB30 802477F0 0160202D */   daddu $a0, $t3, $zero
/* 13AB34 802477F4 0C091C5A */  jal   func_80247168
/* 13AB38 802477F8 0000282D */   daddu $a1, $zero, $zero
/* 13AB3C 802477FC 8FAA0078 */  lw    $t2, 0x78($sp)
/* 13AB40 80247800 8D420008 */  lw    $v0, 8($t2)
/* 13AB44 80247804 18400256 */  blez  $v0, .L80248160
/* 13AB48 80247808 0000F02D */   daddu $fp, $zero, $zero
/* 13AB4C 8024780C 3C0BE3E3 */  lui   $t3, 0xe3e3
/* 13AB50 80247810 356BE3FF */  ori   $t3, $t3, 0xe3ff
/* 13AB54 80247814 AFAB0090 */  sw    $t3, 0x90($sp)
/* 13AB58 80247818 3C0A6666 */  lui   $t2, 0x6666
/* 13AB5C 8024781C 354A6667 */  ori   $t2, $t2, 0x6667
/* 13AB60 80247820 AFAA0094 */  sw    $t2, 0x94($sp)
.L80247824:
/* 13AB64 80247824 8FAB0078 */  lw    $t3, 0x78($sp)
/* 13AB68 80247828 3C128011 */  lui   $s2, 0x8011
/* 13AB6C 8024782C 2652F498 */  addiu $s2, $s2, -0xb68
/* 13AB70 80247830 AFA00084 */  sw    $zero, 0x84($sp)
/* 13AB74 80247834 8D620004 */  lw    $v0, 4($t3)
/* 13AB78 80247838 24037FFF */  addiu $v1, $zero, 0x7fff
/* 13AB7C 8024783C AFA0008C */  sw    $zero, 0x8c($sp)
/* 13AB80 80247840 005E1021 */  addu  $v0, $v0, $fp
/* 13AB84 80247844 00021040 */  sll   $v0, $v0, 1
/* 13AB88 80247848 3C118027 */  lui   $s1, 0x8027
/* 13AB8C 8024784C 02228821 */  addu  $s1, $s1, $v0
/* 13AB90 80247850 86310180 */  lh    $s1, 0x180($s1)
/* 13AB94 80247854 3C138027 */  lui   $s3, 0x8027
/* 13AB98 80247858 02629821 */  addu  $s3, $s3, $v0
/* 13AB9C 8024785C 96730180 */  lhu   $s3, 0x180($s3)
/* 13ABA0 80247860 12230239 */  beq   $s1, $v1, .L80248148
/* 13ABA4 80247864 0000A82D */   daddu $s5, $zero, $zero
/* 13ABA8 80247868 8FA40050 */  lw    $a0, 0x50($sp)
/* 13ABAC 8024786C 0C091C43 */  jal   func_8024710C
/* 13ABB0 80247870 03C0282D */   daddu $a1, $fp, $zero
/* 13ABB4 80247874 03C0282D */  daddu $a1, $fp, $zero
/* 13ABB8 80247878 8FA40050 */  lw    $a0, 0x50($sp)
/* 13ABBC 8024787C 0C091C5A */  jal   func_80247168
/* 13ABC0 80247880 0040B82D */   daddu $s7, $v0, $zero
/* 13ABC4 80247884 0040B02D */  daddu $s6, $v0, $zero
/* 13ABC8 80247888 3A227FFE */  xori  $v0, $s1, 0x7ffe
/* 13ABCC 8024788C 2C420001 */  sltiu $v0, $v0, 1
/* 13ABD0 80247890 02A0802D */  daddu $s0, $s5, $zero
/* 13ABD4 80247894 0220182D */  daddu $v1, $s1, $zero
/* 13ABD8 80247898 AFA20088 */  sw    $v0, 0x88($sp)
.L8024789C:
/* 13ABDC 8024789C 86420000 */  lh    $v0, ($s2)
/* 13ABE0 802478A0 1062007D */  beq   $v1, $v0, .L80247A98
/* 13ABE4 802478A4 26100001 */   addiu $s0, $s0, 1
/* 13ABE8 802478A8 2A020040 */  slti  $v0, $s0, 0x40
/* 13ABEC 802478AC 1440FFFB */  bnez  $v0, .L8024789C
/* 13ABF0 802478B0 26520002 */   addiu $s2, $s2, 2
.L802478B4:
/* 13ABF4 802478B4 3C038027 */  lui   $v1, 0x8027
/* 13ABF8 802478B8 806300D4 */  lb    $v1, 0xd4($v1)
/* 13ABFC 802478BC 24020002 */  addiu $v0, $zero, 2
/* 13AC00 802478C0 14620029 */  bne   $v1, $v0, .L80247968
/* 13AC04 802478C4 24020001 */   addiu $v0, $zero, 1
/* 13AC08 802478C8 3C038027 */  lui   $v1, 0x8027
/* 13AC0C 802478CC 8C630398 */  lw    $v1, 0x398($v1)
/* 13AC10 802478D0 14620025 */  bne   $v1, $v0, .L80247968
/* 13AC14 802478D4 00000000 */   nop   
/* 13AC18 802478D8 8FA40050 */  lw    $a0, 0x50($sp)
/* 13AC1C 802478DC 0C091C76 */  jal   func_802471D8
/* 13AC20 802478E0 03C0282D */   daddu $a1, $fp, $zero
/* 13AC24 802478E4 8FAA005C */  lw    $t2, 0x5c($sp)
/* 13AC28 802478E8 144A001F */  bne   $v0, $t2, .L80247968
/* 13AC2C 802478EC 00000000 */   nop   
/* 13AC30 802478F0 8FA40050 */  lw    $a0, 0x50($sp)
/* 13AC34 802478F4 0C091C88 */  jal   func_80247220
/* 13AC38 802478F8 03C0282D */   daddu $a1, $fp, $zero
/* 13AC3C 802478FC 8FAB0060 */  lw    $t3, 0x60($sp)
/* 13AC40 80247900 144B0019 */  bne   $v0, $t3, .L80247968
/* 13AC44 80247904 00131400 */   sll   $v0, $s3, 0x10
/* 13AC48 80247908 24150001 */  addiu $s5, $zero, 1
/* 13AC4C 8024790C 8FAA0088 */  lw    $t2, 0x88($sp)
/* 13AC50 80247910 1540002A */  bnez  $t2, .L802479BC
/* 13AC54 80247914 00021403 */   sra   $v0, $v0, 0x10
/* 13AC58 80247918 00021140 */  sll   $v0, $v0, 5
/* 13AC5C 8024791C 3C0B8008 */  lui   $t3, 0x8008
/* 13AC60 80247920 256B78E0 */  addiu $t3, $t3, 0x78e0
/* 13AC64 80247924 004B1021 */  addu  $v0, $v0, $t3
/* 13AC68 80247928 3C0A8009 */  lui   $t2, 0x8009
/* 13AC6C 8024792C 254AF060 */  addiu $t2, $t2, -0xfa0
/* 13AC70 80247930 9043001A */  lbu   $v1, 0x1a($v0)
/* 13AC74 80247934 8FAB0084 */  lw    $t3, 0x84($sp)
/* 13AC78 80247938 00031080 */  sll   $v0, $v1, 2
/* 13AC7C 8024793C 00431021 */  addu  $v0, $v0, $v1
/* 13AC80 80247940 00021080 */  sll   $v0, $v0, 2
/* 13AC84 80247944 004A1021 */  addu  $v0, $v0, $t2
/* 13AC88 80247948 80420012 */  lb    $v0, 0x12($v0)
/* 13AC8C 8024794C 15600006 */  bnez  $t3, .L80247968
/* 13AC90 80247950 AFA20070 */   sw    $v0, 0x70($sp)
/* 13AC94 80247954 8FAA006C */  lw    $t2, 0x6c($sp)
/* 13AC98 80247958 0142102A */  slt   $v0, $t2, $v0
/* 13AC9C 8024795C 14400002 */  bnez  $v0, .L80247968
/* 13ACA0 80247960 02A0582D */   daddu $t3, $s5, $zero
/* 13ACA4 80247964 AFAB0074 */  sw    $t3, 0x74($sp)
.L80247968:
/* 13ACA8 80247968 8FAA0088 */  lw    $t2, 0x88($sp)
/* 13ACAC 8024796C 15400014 */  bnez  $t2, .L802479C0
/* 13ACB0 80247970 0000902D */   daddu $s2, $zero, $zero
/* 13ACB4 80247974 00131400 */  sll   $v0, $s3, 0x10
/* 13ACB8 80247978 000212C3 */  sra   $v0, $v0, 0xb
/* 13ACBC 8024797C 3C0B8008 */  lui   $t3, 0x8008
/* 13ACC0 80247980 256B78E0 */  addiu $t3, $t3, 0x78e0
/* 13ACC4 80247984 004B1021 */  addu  $v0, $v0, $t3
/* 13ACC8 80247988 3C0A8009 */  lui   $t2, 0x8009
/* 13ACCC 8024798C 254AF060 */  addiu $t2, $t2, -0xfa0
/* 13ACD0 80247990 9043001A */  lbu   $v1, 0x1a($v0)
/* 13ACD4 80247994 8FAB006C */  lw    $t3, 0x6c($sp)
/* 13ACD8 80247998 00031080 */  sll   $v0, $v1, 2
/* 13ACDC 8024799C 00431021 */  addu  $v0, $v0, $v1
/* 13ACE0 802479A0 00021080 */  sll   $v0, $v0, 2
/* 13ACE4 802479A4 004A1021 */  addu  $v0, $v0, $t2
/* 13ACE8 802479A8 80420012 */  lb    $v0, 0x12($v0)
/* 13ACEC 802479AC 0162102A */  slt   $v0, $t3, $v0
/* 13ACF0 802479B0 10400003 */  beqz  $v0, .L802479C0
/* 13ACF4 802479B4 240A0001 */   addiu $t2, $zero, 1
/* 13ACF8 802479B8 AFAA008C */  sw    $t2, 0x8c($sp)
.L802479BC:
/* 13ACFC 802479BC 0000902D */  daddu $s2, $zero, $zero
.L802479C0:
/* 13AD00 802479C0 12A00003 */  beqz  $s5, .L802479D0
/* 13AD04 802479C4 0240A02D */   daddu $s4, $s2, $zero
/* 13AD08 802479C8 2412FFFF */  addiu $s2, $zero, -1
/* 13AD0C 802479CC 0240A02D */  daddu $s4, $s2, $zero
.L802479D0:
/* 13AD10 802479D0 8FAB0054 */  lw    $t3, 0x54($sp)
/* 13AD14 802479D4 15600037 */  bnez  $t3, .L80247AB4
/* 13AD18 802479D8 240A0001 */   addiu $t2, $zero, 1
/* 13AD1C 802479DC 240B000A */  addiu $t3, $zero, 0xa
/* 13AD20 802479E0 AFAA0064 */  sw    $t2, 0x64($sp)
/* 13AD24 802479E4 12A00003 */  beqz  $s5, .L802479F4
/* 13AD28 802479E8 AFAB0068 */   sw    $t3, 0x68($sp)
/* 13AD2C 802479EC 240A0009 */  addiu $t2, $zero, 9
/* 13AD30 802479F0 AFAA0064 */  sw    $t2, 0x64($sp)
.L802479F4:
/* 13AD34 802479F4 8FAB0084 */  lw    $t3, 0x84($sp)
/* 13AD38 802479F8 1160002A */  beqz  $t3, .L80247AA4
/* 13AD3C 802479FC 00000000 */   nop   
/* 13AD40 80247A00 0C091CAA */  jal   func_802472A8
/* 13AD44 80247A04 02E0202D */   daddu $a0, $s7, $zero
/* 13AD48 80247A08 8FAA007C */  lw    $t2, 0x7c($sp)
/* 13AD4C 80247A0C 02C0202D */  daddu $a0, $s6, $zero
/* 13AD50 80247A10 01428021 */  addu  $s0, $t2, $v0
/* 13AD54 80247A14 0C091CA6 */  jal   func_80247298
/* 13AD58 80247A18 2610FFEC */   addiu $s0, $s0, -0x14
/* 13AD5C 80247A1C 24040004 */  addiu $a0, $zero, 4
/* 13AD60 80247A20 3C058027 */  lui   $a1, 0x8027
/* 13AD64 80247A24 24A5FC10 */  addiu $a1, $a1, -0x3f0
/* 13AD68 80247A28 8FAB00C8 */  lw    $t3, 0xc8($sp)
/* 13AD6C 80247A2C 0200302D */  daddu $a2, $s0, $zero
/* 13AD70 80247A30 AFA00010 */  sw    $zero, 0x10($sp)
/* 13AD74 80247A34 AFA00020 */  sw    $zero, 0x20($sp)
/* 13AD78 80247A38 AFA00024 */  sw    $zero, 0x24($sp)
/* 13AD7C 80247A3C AFA00028 */  sw    $zero, 0x28($sp)
/* 13AD80 80247A40 AFA0002C */  sw    $zero, 0x2c($sp)
/* 13AD84 80247A44 AFA00030 */  sw    $zero, 0x30($sp)
/* 13AD88 80247A48 AFA00034 */  sw    $zero, 0x34($sp)
/* 13AD8C 80247A4C AFA00038 */  sw    $zero, 0x38($sp)
/* 13AD90 80247A50 AFA0003C */  sw    $zero, 0x3c($sp)
/* 13AD94 80247A54 AFA00040 */  sw    $zero, 0x40($sp)
/* 13AD98 80247A58 AFA0004C */  sw    $zero, 0x4c($sp)
/* 13AD9C 80247A5C 01621021 */  addu  $v0, $t3, $v0
/* 13ADA0 80247A60 24470011 */  addiu $a3, $v0, 0x11
/* 13ADA4 80247A64 240200C8 */  addiu $v0, $zero, 0xc8
/* 13ADA8 80247A68 AFA20014 */  sw    $v0, 0x14($sp)
/* 13ADAC 80247A6C 2402000D */  addiu $v0, $zero, 0xd
/* 13ADB0 80247A70 AFA20018 */  sw    $v0, 0x18($sp)
/* 13ADB4 80247A74 240200FF */  addiu $v0, $zero, 0xff
/* 13ADB8 80247A78 AFA2001C */  sw    $v0, 0x1c($sp)
/* 13ADBC 80247A7C 24020140 */  addiu $v0, $zero, 0x140
/* 13ADC0 80247A80 AFA20044 */  sw    $v0, 0x44($sp)
/* 13ADC4 80247A84 240200F0 */  addiu $v0, $zero, 0xf0
/* 13ADC8 80247A88 0C03D4B8 */  jal   draw_box
/* 13ADCC 80247A8C AFA20048 */   sw    $v0, 0x48($sp)
/* 13ADD0 80247A90 08091EAD */  j     .L80247AB4
/* 13ADD4 80247A94 00000000 */   nop   
.L80247A98:
/* 13ADD8 80247A98 240A0001 */  addiu $t2, $zero, 1
/* 13ADDC 80247A9C 08091E2D */  j     .L802478B4
/* 13ADE0 80247AA0 AFAA0084 */   sw    $t2, 0x84($sp)
.L80247AA4:
/* 13ADE4 80247AA4 8FAB008C */  lw    $t3, 0x8c($sp)
/* 13ADE8 80247AA8 11600002 */  beqz  $t3, .L80247AB4
/* 13ADEC 80247AAC 240A000B */   addiu $t2, $zero, 0xb
/* 13ADF0 80247AB0 AFAA0068 */  sw    $t2, 0x68($sp)
.L80247AB4:
/* 13ADF4 80247AB4 0C091C9C */  jal   func_80247270
/* 13ADF8 80247AB8 02C0202D */   daddu $a0, $s6, $zero
/* 13ADFC 80247ABC 104001A2 */  beqz  $v0, .L80248148
/* 13AE00 80247AC0 00000000 */   nop   
/* 13AE04 80247AC4 8FAB0054 */  lw    $t3, 0x54($sp)
/* 13AE08 80247AC8 15600058 */  bnez  $t3, .L80247C2C
/* 13AE0C 80247ACC 24020001 */   addiu $v0, $zero, 1
/* 13AE10 80247AD0 8FAA0088 */  lw    $t2, 0x88($sp)
/* 13AE14 80247AD4 11400018 */  beqz  $t2, .L80247B38
/* 13AE18 80247AD8 00131400 */   sll   $v0, $s3, 0x10
/* 13AE1C 80247ADC 0C093BA0 */  jal   func_8024EE80
/* 13AE20 80247AE0 24040045 */   addiu $a0, $zero, 0x45
/* 13AE24 80247AE4 02E0202D */  daddu $a0, $s7, $zero
/* 13AE28 80247AE8 0C091CAA */  jal   func_802472A8
/* 13AE2C 80247AEC 0040882D */   daddu $s1, $v0, $zero
/* 13AE30 80247AF0 8FAB007C */  lw    $t3, 0x7c($sp)
/* 13AE34 80247AF4 02C0202D */  daddu $a0, $s6, $zero
/* 13AE38 80247AF8 01628021 */  addu  $s0, $t3, $v0
/* 13AE3C 80247AFC 0C091CA6 */  jal   func_80247298
/* 13AE40 80247B00 02128021 */   addu  $s0, $s0, $s2
/* 13AE44 80247B04 0220202D */  daddu $a0, $s1, $zero
/* 13AE48 80247B08 0200282D */  daddu $a1, $s0, $zero
/* 13AE4C 80247B0C 240700FF */  addiu $a3, $zero, 0xff
/* 13AE50 80247B10 8FAA0080 */  lw    $t2, 0x80($sp)
/* 13AE54 80247B14 8FAB0068 */  lw    $t3, 0x68($sp)
/* 13AE58 80247B18 01421021 */  addu  $v0, $t2, $v0
/* 13AE5C 80247B1C 8FAA0064 */  lw    $t2, 0x64($sp)
/* 13AE60 80247B20 00543021 */  addu  $a2, $v0, $s4
/* 13AE64 80247B24 AFAB0010 */  sw    $t3, 0x10($sp)
/* 13AE68 80247B28 0C04993B */  jal   draw_string
/* 13AE6C 80247B2C AFAA0014 */   sw    $t2, 0x14($sp)
/* 13AE70 80247B30 08091F09 */  j     func_80247C24
/* 13AE74 80247B34 00000000 */   nop   

.L80247B38:
/* 13AE78 80247B38 000212C3 */  sra   $v0, $v0, 0xb
/* 13AE7C 80247B3C 3C0B8008 */  lui   $t3, 0x8008
/* 13AE80 80247B40 256B78E0 */  addiu $t3, $t3, 0x78e0
/* 13AE84 80247B44 004B8821 */  addu  $s1, $v0, $t3
/* 13AE88 80247B48 8E220000 */  lw    $v0, ($s1)
/* 13AE8C 80247B4C 10400015 */  beqz  $v0, .L80247BA4
/* 13AE90 80247B50 00000000 */   nop   
/* 13AE94 80247B54 18400013 */  blez  $v0, .L80247BA4
/* 13AE98 80247B58 00000000 */   nop   
/* 13AE9C 80247B5C 0C091CAA */  jal   func_802472A8
/* 13AEA0 80247B60 02E0202D */   daddu $a0, $s7, $zero
/* 13AEA4 80247B64 8FAA007C */  lw    $t2, 0x7c($sp)
/* 13AEA8 80247B68 02C0202D */  daddu $a0, $s6, $zero
/* 13AEAC 80247B6C 01428021 */  addu  $s0, $t2, $v0
/* 13AEB0 80247B70 0C091CA6 */  jal   func_80247298
/* 13AEB4 80247B74 02128021 */   addu  $s0, $s0, $s2
/* 13AEB8 80247B78 0200282D */  daddu $a1, $s0, $zero
/* 13AEBC 80247B7C 8FAB0080 */  lw    $t3, 0x80($sp)
/* 13AEC0 80247B80 8FAA0068 */  lw    $t2, 0x68($sp)
/* 13AEC4 80247B84 01621021 */  addu  $v0, $t3, $v0
/* 13AEC8 80247B88 8FAB0064 */  lw    $t3, 0x64($sp)
/* 13AECC 80247B8C 240700FF */  addiu $a3, $zero, 0xff
/* 13AED0 80247B90 AFAA0010 */  sw    $t2, 0x10($sp)
/* 13AED4 80247B94 AFAB0014 */  sw    $t3, 0x14($sp)
/* 13AED8 80247B98 8E240000 */  lw    $a0, ($s1)
/* 13AEDC 80247B9C 0C04993B */  jal   draw_string
/* 13AEE0 80247BA0 00543021 */   addu  $a2, $v0, $s4
.L80247BA4:
/* 13AEE4 80247BA4 0C091CAA */  jal   func_802472A8
/* 13AEE8 80247BA8 02E0202D */   daddu $a0, $s7, $zero
/* 13AEEC 80247BAC 02C0202D */  daddu $a0, $s6, $zero
