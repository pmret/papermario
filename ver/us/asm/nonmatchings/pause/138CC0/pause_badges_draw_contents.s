.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_8026FFB0
.word 0x3FC99999, 0x9999999A, 0x00000000, 0x00000000, 0x6C657474, 0x65725F70, 0x65616368, 0x00000000, 0x70617274, 0x795F706F, 0x6B6F7069, 0x00000000, 0x70617274, 0x795F6F70, 0x756B7500, 0x70617274, 0x795F616B, 0x61726900, 0x70617274, 0x795F7265, 0x73610000, 0x70617274, 0x795F7061, 0x72657461, 0x00000000, 0x70617274, 0x795F7069, 0x6E6B6900, 0x70617274, 0x795F6B61, 0x6D656B69, 0x00000000, 0x70617274, 0x795F6B75, 0x72696F00, 0x00000000

.section .text

glabel pause_badges_draw_contents
/* 13A848 80247508 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 13A84C 8024750C 240A0001 */  addiu     $t2, $zero, 1
/* 13A850 80247510 3C028027 */  lui       $v0, %hi(gBadgeMenuCurrentPage)
/* 13A854 80247514 8C420280 */  lw        $v0, %lo(gBadgeMenuCurrentPage)($v0)
/* 13A858 80247518 3C038027 */  lui       $v1, %hi(gBadgeMenuPages)
/* 13A85C 8024751C 24630288 */  addiu     $v1, $v1, %lo(gBadgeMenuPages)
/* 13A860 80247520 AFBF00BC */  sw        $ra, 0xbc($sp)
/* 13A864 80247524 AFBE00B8 */  sw        $fp, 0xb8($sp)
/* 13A868 80247528 AFB700B4 */  sw        $s7, 0xb4($sp)
/* 13A86C 8024752C AFB600B0 */  sw        $s6, 0xb0($sp)
/* 13A870 80247530 AFB500AC */  sw        $s5, 0xac($sp)
/* 13A874 80247534 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 13A878 80247538 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 13A87C 8024753C AFB200A0 */  sw        $s2, 0xa0($sp)
/* 13A880 80247540 AFB1009C */  sw        $s1, 0x9c($sp)
/* 13A884 80247544 AFB00098 */  sw        $s0, 0x98($sp)
/* 13A888 80247548 AFA500C4 */  sw        $a1, 0xc4($sp)
/* 13A88C 8024754C AFA600C8 */  sw        $a2, 0xc8($sp)
/* 13A890 80247550 AFA700CC */  sw        $a3, 0xcc($sp)
/* 13A894 80247554 AFA00070 */  sw        $zero, 0x70($sp)
/* 13A898 80247558 AFA00074 */  sw        $zero, 0x74($sp)
/* 13A89C 8024755C AFAA0064 */  sw        $t2, 0x64($sp)
/* 13A8A0 80247560 01428004 */  sllv      $s0, $v0, $t2
/* 13A8A4 80247564 02028021 */  addu      $s0, $s0, $v0
/* 13A8A8 80247568 00108080 */  sll       $s0, $s0, 2
/* 13A8AC 8024756C 0C0911FD */  jal       pause_get_total_equipped_bp_cost
/* 13A8B0 80247570 02038021 */   addu     $s0, $s0, $v1
/* 13A8B4 80247574 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13A8B8 80247578 92090002 */  lbu       $t1, 2($s0)
/* 13A8BC 8024757C 8FAA00CC */  lw        $t2, 0xcc($sp)
/* 13A8C0 80247580 25660054 */  addiu     $a2, $t3, 0x54
/* 13A8C4 80247584 8FAB00D0 */  lw        $t3, 0xd0($sp)
/* 13A8C8 80247588 2543FFAC */  addiu     $v1, $t2, -0x54
/* 13A8CC 8024758C AFA30014 */  sw        $v1, 0x14($sp)
/* 13A8D0 80247590 240300FF */  addiu     $v1, $zero, 0xff
/* 13A8D4 80247594 AFA3001C */  sw        $v1, 0x1c($sp)
/* 13A8D8 80247598 24030140 */  addiu     $v1, $zero, 0x140
/* 13A8DC 8024759C AFA30044 */  sw        $v1, 0x44($sp)
/* 13A8E0 802475A0 240300F0 */  addiu     $v1, $zero, 0xf0
/* 13A8E4 802475A4 AFA30048 */  sw        $v1, 0x48($sp)
/* 13A8E8 802475A8 3C038027 */  lui       $v1, %hi(gBadgeMenuSelectedIndex)
/* 13A8EC 802475AC 8C630378 */  lw        $v1, %lo(gBadgeMenuSelectedIndex)($v1)
/* 13A8F0 802475B0 AFAB0018 */  sw        $t3, 0x18($sp)
/* 13A8F4 802475B4 15200002 */  bnez      $t1, .L802475C0
/* 13A8F8 802475B8 0069001A */   div      $zero, $v1, $t1
/* 13A8FC 802475BC 0007000D */  break     7
.L802475C0:
/* 13A900 802475C0 2401FFFF */   addiu    $at, $zero, -1
/* 13A904 802475C4 15210004 */  bne       $t1, $at, .L802475D8
/* 13A908 802475C8 3C018000 */   lui      $at, 0x8000
/* 13A90C 802475CC 14610002 */  bne       $v1, $at, .L802475D8
/* 13A910 802475D0 00000000 */   nop
/* 13A914 802475D4 0006000D */  break     6
.L802475D8:
/* 13A918 802475D8 00005012 */   mflo     $t2
/* 13A91C 802475DC 00005810 */  mfhi      $t3
/* 13A920 802475E0 24040004 */  addiu     $a0, $zero, 4
/* 13A924 802475E4 8FA700C8 */  lw        $a3, 0xc8($sp)
/* 13A928 802475E8 3C088011 */  lui       $t0, %hi(gPlayerData+0x8)
/* 13A92C 802475EC 8108F298 */  lb        $t0, %lo(gPlayerData+0x8)($t0)
/* 13A930 802475F0 3C058027 */  lui       $a1, %hi(D_8026FC48)
/* 13A934 802475F4 24A5FC48 */  addiu     $a1, $a1, %lo(D_8026FC48)
/* 13A938 802475F8 AFA00010 */  sw        $zero, 0x10($sp)
/* 13A93C 802475FC AFA00020 */  sw        $zero, 0x20($sp)
/* 13A940 80247600 AFA00024 */  sw        $zero, 0x24($sp)
/* 13A944 80247604 AFA00028 */  sw        $zero, 0x28($sp)
/* 13A948 80247608 AFA0002C */  sw        $zero, 0x2c($sp)
/* 13A94C 8024760C AFA00030 */  sw        $zero, 0x30($sp)
/* 13A950 80247610 AFA00034 */  sw        $zero, 0x34($sp)
/* 13A954 80247614 AFA00038 */  sw        $zero, 0x38($sp)
/* 13A958 80247618 AFA0003C */  sw        $zero, 0x3c($sp)
/* 13A95C 8024761C AFA00040 */  sw        $zero, 0x40($sp)
/* 13A960 80247620 AFA0004C */  sw        $zero, 0x4c($sp)
/* 13A964 80247624 01024023 */  subu      $t0, $t0, $v0
/* 13A968 80247628 AFA8006C */  sw        $t0, 0x6c($sp)
/* 13A96C 8024762C AFAA0060 */  sw        $t2, 0x60($sp)
/* 13A970 80247630 0C03D4B8 */  jal       draw_box
/* 13A974 80247634 AFAB005C */   sw       $t3, 0x5c($sp)
/* 13A978 80247638 3C108027 */  lui       $s0, %hi(gBadgeMenuIconIDs)
/* 13A97C 8024763C 261003A8 */  addiu     $s0, $s0, %lo(gBadgeMenuIconIDs)
/* 13A980 80247640 8FAA00C4 */  lw        $t2, 0xc4($sp)
/* 13A984 80247644 8E040050 */  lw        $a0, 0x50($s0)
/* 13A988 80247648 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13A98C 8024764C 254500F1 */  addiu     $a1, $t2, 0xf1
/* 13A990 80247650 0C051261 */  jal       set_hud_element_render_pos
/* 13A994 80247654 2566000B */   addiu    $a2, $t3, 0xb
/* 13A998 80247658 8E040050 */  lw        $a0, 0x50($s0)
/* 13A99C 8024765C 240A000A */  addiu     $t2, $zero, 0xa
/* 13A9A0 80247660 0C0511F8 */  jal       draw_hud_element_3
/* 13A9A4 80247664 AFAA0068 */   sw       $t2, 0x68($sp)
/* 13A9A8 80247668 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13A9AC 8024766C 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13A9B0 80247670 2546000E */  addiu     $a2, $t2, 0xe
/* 13A9B4 80247674 8FAA00CC */  lw        $t2, 0xcc($sp)
/* 13A9B8 80247678 25640001 */  addiu     $a0, $t3, 1
/* 13A9BC 8024767C 016A1021 */  addu      $v0, $t3, $t2
/* 13A9C0 80247680 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13A9C4 80247684 8FAA00D0 */  lw        $t2, 0xd0($sp)
/* 13A9C8 80247688 2447FFFF */  addiu     $a3, $v0, -1
/* 13A9CC 8024768C 016A1021 */  addu      $v0, $t3, $t2
/* 13A9D0 80247690 1C800002 */  bgtz      $a0, .L8024769C
/* 13A9D4 80247694 2448FFF7 */   addiu    $t0, $v0, -9
/* 13A9D8 80247698 24040001 */  addiu     $a0, $zero, 1
.L8024769C:
/* 13A9DC 8024769C 58C00001 */  blezl     $a2, .L802476A4
/* 13A9E0 802476A0 24060001 */   addiu    $a2, $zero, 1
.L802476A4:
/* 13A9E4 802476A4 18E005AD */  blez      $a3, .L80248D5C
/* 13A9E8 802476A8 00000000 */   nop
/* 13A9EC 802476AC 190005AB */  blez      $t0, .L80248D5C
/* 13A9F0 802476B0 2882013F */   slti     $v0, $a0, 0x13f
/* 13A9F4 802476B4 104005A9 */  beqz      $v0, .L80248D5C
/* 13A9F8 802476B8 28C200EF */   slti     $v0, $a2, 0xef
/* 13A9FC 802476BC 104005A7 */  beqz      $v0, .L80248D5C
/* 13AA00 802476C0 28E2013F */   slti     $v0, $a3, 0x13f
/* 13AA04 802476C4 50400001 */  beql      $v0, $zero, .L802476CC
/* 13AA08 802476C8 2407013F */   addiu    $a3, $zero, 0x13f
.L802476CC:
/* 13AA0C 802476CC 290200EF */  slti      $v0, $t0, 0xef
/* 13AA10 802476D0 50400001 */  beql      $v0, $zero, .L802476D8
/* 13AA14 802476D4 240800EF */   addiu    $t0, $zero, 0xef
.L802476D8:
/* 13AA18 802476D8 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 13AA1C 802476DC 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 13AA20 802476E0 44841000 */  mtc1      $a0, $f2
/* 13AA24 802476E4 00000000 */  nop
/* 13AA28 802476E8 468010A0 */  cvt.s.w   $f2, $f2
/* 13AA2C 802476EC 44860000 */  mtc1      $a2, $f0
/* 13AA30 802476F0 00000000 */  nop
/* 13AA34 802476F4 46800020 */  cvt.s.w   $f0, $f0
/* 13AA38 802476F8 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13AA3C 802476FC 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13AA40 80247700 3C014080 */  lui       $at, 0x4080
/* 13AA44 80247704 44812000 */  mtc1      $at, $f4
/* 13AA48 80247708 3C04ED00 */  lui       $a0, 0xed00
/* 13AA4C 8024770C AFA00058 */  sw        $zero, 0x58($sp)
/* 13AA50 80247710 AFA00054 */  sw        $zero, 0x54($sp)
/* 13AA54 80247714 256B0077 */  addiu     $t3, $t3, 0x77
/* 13AA58 80247718 46041082 */  mul.s     $f2, $f2, $f4
/* 13AA5C 8024771C 00000000 */  nop
/* 13AA60 80247720 254A0011 */  addiu     $t2, $t2, 0x11
/* 13AA64 80247724 AFAB007C */  sw        $t3, 0x7c($sp)
/* 13AA68 80247728 AFAA0080 */  sw        $t2, 0x80($sp)
/* 13AA6C 8024772C 8C620000 */  lw        $v0, ($v1)
/* 13AA70 80247730 46040002 */  mul.s     $f0, $f0, $f4
/* 13AA74 80247734 00000000 */  nop
/* 13AA78 80247738 0040282D */  daddu     $a1, $v0, $zero
/* 13AA7C 8024773C 24420008 */  addiu     $v0, $v0, 8
/* 13AA80 80247740 AC620000 */  sw        $v0, ($v1)
/* 13AA84 80247744 4600118D */  trunc.w.s $f6, $f2
/* 13AA88 80247748 44023000 */  mfc1      $v0, $f6
/* 13AA8C 8024774C 00000000 */  nop
/* 13AA90 80247750 30420FFF */  andi      $v0, $v0, 0xfff
/* 13AA94 80247754 00021300 */  sll       $v0, $v0, 0xc
/* 13AA98 80247758 4600018D */  trunc.w.s $f6, $f0
/* 13AA9C 8024775C 44033000 */  mfc1      $v1, $f6
/* 13AAA0 80247760 44871000 */  mtc1      $a3, $f2
/* 13AAA4 80247764 00000000 */  nop
/* 13AAA8 80247768 468010A0 */  cvt.s.w   $f2, $f2
/* 13AAAC 8024776C 46041082 */  mul.s     $f2, $f2, $f4
/* 13AAB0 80247770 00000000 */  nop
/* 13AAB4 80247774 30630FFF */  andi      $v1, $v1, 0xfff
/* 13AAB8 80247778 00641825 */  or        $v1, $v1, $a0
/* 13AABC 8024777C 00431025 */  or        $v0, $v0, $v1
/* 13AAC0 80247780 44880000 */  mtc1      $t0, $f0
/* 13AAC4 80247784 00000000 */  nop
/* 13AAC8 80247788 46800020 */  cvt.s.w   $f0, $f0
/* 13AACC 8024778C 46040002 */  mul.s     $f0, $f0, $f4
/* 13AAD0 80247790 00000000 */  nop
/* 13AAD4 80247794 ACA20000 */  sw        $v0, ($a1)
/* 13AAD8 80247798 4600118D */  trunc.w.s $f6, $f2
/* 13AADC 8024779C 44023000 */  mfc1      $v0, $f6
/* 13AAE0 802477A0 00000000 */  nop
/* 13AAE4 802477A4 30420FFF */  andi      $v0, $v0, 0xfff
/* 13AAE8 802477A8 00021300 */  sll       $v0, $v0, 0xc
/* 13AAEC 802477AC 4600018D */  trunc.w.s $f6, $f0
/* 13AAF0 802477B0 44033000 */  mfc1      $v1, $f6
/* 13AAF4 802477B4 00000000 */  nop
/* 13AAF8 802477B8 30630FFF */  andi      $v1, $v1, 0xfff
/* 13AAFC 802477BC 00431025 */  or        $v0, $v0, $v1
/* 13AB00 802477C0 ACA20004 */  sw        $v0, 4($a1)
.L802477C4:
/* 13AB04 802477C4 AFA00050 */  sw        $zero, 0x50($sp)
.L802477C8:
/* 13AB08 802477C8 8FAB0050 */  lw        $t3, 0x50($sp)
/* 13AB0C 802477CC 3C028027 */  lui       $v0, %hi(gBadgeMenuPages)
/* 13AB10 802477D0 24420288 */  addiu     $v0, $v0, %lo(gBadgeMenuPages)
/* 13AB14 802477D4 000B1840 */  sll       $v1, $t3, 1
/* 13AB18 802477D8 006B1821 */  addu      $v1, $v1, $t3
/* 13AB1C 802477DC 00031880 */  sll       $v1, $v1, 2
/* 13AB20 802477E0 00621821 */  addu      $v1, $v1, $v0
/* 13AB24 802477E4 AFA30078 */  sw        $v1, 0x78($sp)
/* 13AB28 802477E8 90620000 */  lbu       $v0, ($v1)
/* 13AB2C 802477EC 10400261 */  beqz      $v0, .L80248174
/* 13AB30 802477F0 0160202D */   daddu    $a0, $t3, $zero
/* 13AB34 802477F4 0C091C5A */  jal       pause_badges_get_pos_y
/* 13AB38 802477F8 0000282D */   daddu    $a1, $zero, $zero
/* 13AB3C 802477FC 8FAA0078 */  lw        $t2, 0x78($sp)
/* 13AB40 80247800 8D420008 */  lw        $v0, 8($t2)
/* 13AB44 80247804 18400256 */  blez      $v0, .L80248160
/* 13AB48 80247808 0000F02D */   daddu    $fp, $zero, $zero
/* 13AB4C 8024780C 3C0BE3E3 */  lui       $t3, 0xe3e3
/* 13AB50 80247810 356BE3FF */  ori       $t3, $t3, 0xe3ff
/* 13AB54 80247814 AFAB0090 */  sw        $t3, 0x90($sp)
/* 13AB58 80247818 3C0A6666 */  lui       $t2, 0x6666
/* 13AB5C 8024781C 354A6667 */  ori       $t2, $t2, 0x6667
/* 13AB60 80247820 AFAA0094 */  sw        $t2, 0x94($sp)
.L80247824:
/* 13AB64 80247824 8FAB0078 */  lw        $t3, 0x78($sp)
/* 13AB68 80247828 3C128011 */  lui       $s2, %hi(gPlayerData+0x208)
/* 13AB6C 8024782C 2652F498 */  addiu     $s2, $s2, %lo(gPlayerData+0x208)
/* 13AB70 80247830 AFA00084 */  sw        $zero, 0x84($sp)
/* 13AB74 80247834 8D620004 */  lw        $v0, 4($t3)
/* 13AB78 80247838 24037FFF */  addiu     $v1, $zero, 0x7fff
/* 13AB7C 8024783C AFA0008C */  sw        $zero, 0x8c($sp)
/* 13AB80 80247840 005E1021 */  addu      $v0, $v0, $fp
/* 13AB84 80247844 00021040 */  sll       $v0, $v0, 1
/* 13AB88 80247848 3C118027 */  lui       $s1, %hi(gBadgeMenuItemIDs)
/* 13AB8C 8024784C 02228821 */  addu      $s1, $s1, $v0
/* 13AB90 80247850 86310180 */  lh        $s1, %lo(gBadgeMenuItemIDs)($s1)
/* 13AB94 80247854 3C138027 */  lui       $s3, %hi(gBadgeMenuItemIDs)
/* 13AB98 80247858 02629821 */  addu      $s3, $s3, $v0
/* 13AB9C 8024785C 96730180 */  lhu       $s3, %lo(gBadgeMenuItemIDs)($s3)
/* 13ABA0 80247860 12230239 */  beq       $s1, $v1, .L80248148
/* 13ABA4 80247864 0000A82D */   daddu    $s5, $zero, $zero
/* 13ABA8 80247868 8FA40050 */  lw        $a0, 0x50($sp)
/* 13ABAC 8024786C 0C091C43 */  jal       pause_badges_get_pos_x
/* 13ABB0 80247870 03C0282D */   daddu    $a1, $fp, $zero
/* 13ABB4 80247874 03C0282D */  daddu     $a1, $fp, $zero
/* 13ABB8 80247878 8FA40050 */  lw        $a0, 0x50($sp)
/* 13ABBC 8024787C 0C091C5A */  jal       pause_badges_get_pos_y
/* 13ABC0 80247880 0040B82D */   daddu    $s7, $v0, $zero
/* 13ABC4 80247884 0040B02D */  daddu     $s6, $v0, $zero
/* 13ABC8 80247888 3A227FFE */  xori      $v0, $s1, 0x7ffe
/* 13ABCC 8024788C 2C420001 */  sltiu     $v0, $v0, 1
/* 13ABD0 80247890 02A0802D */  daddu     $s0, $s5, $zero
/* 13ABD4 80247894 0220182D */  daddu     $v1, $s1, $zero
/* 13ABD8 80247898 AFA20088 */  sw        $v0, 0x88($sp)
.L8024789C:
/* 13ABDC 8024789C 86420000 */  lh        $v0, ($s2)
/* 13ABE0 802478A0 1062007D */  beq       $v1, $v0, .L80247A98
/* 13ABE4 802478A4 26100001 */   addiu    $s0, $s0, 1
/* 13ABE8 802478A8 2A020040 */  slti      $v0, $s0, 0x40
/* 13ABEC 802478AC 1440FFFB */  bnez      $v0, .L8024789C
/* 13ABF0 802478B0 26520002 */   addiu    $s2, $s2, 2
.L802478B4:
/* 13ABF4 802478B4 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 13ABF8 802478B8 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 13ABFC 802478BC 24020002 */  addiu     $v0, $zero, 2
/* 13AC00 802478C0 14620029 */  bne       $v1, $v0, .L80247968
/* 13AC04 802478C4 24020001 */   addiu    $v0, $zero, 1
/* 13AC08 802478C8 3C038027 */  lui       $v1, %hi(gBadgeMenuLevel)
/* 13AC0C 802478CC 8C630398 */  lw        $v1, %lo(gBadgeMenuLevel)($v1)
/* 13AC10 802478D0 14620025 */  bne       $v1, $v0, .L80247968
/* 13AC14 802478D4 00000000 */   nop
/* 13AC18 802478D8 8FA40050 */  lw        $a0, 0x50($sp)
/* 13AC1C 802478DC 0C091C76 */  jal       pause_badges_get_column
/* 13AC20 802478E0 03C0282D */   daddu    $a1, $fp, $zero
/* 13AC24 802478E4 8FAA005C */  lw        $t2, 0x5c($sp)
/* 13AC28 802478E8 144A001F */  bne       $v0, $t2, .L80247968
/* 13AC2C 802478EC 00000000 */   nop
/* 13AC30 802478F0 8FA40050 */  lw        $a0, 0x50($sp)
/* 13AC34 802478F4 0C091C88 */  jal       pause_badges_get_row
/* 13AC38 802478F8 03C0282D */   daddu    $a1, $fp, $zero
/* 13AC3C 802478FC 8FAB0060 */  lw        $t3, 0x60($sp)
/* 13AC40 80247900 144B0019 */  bne       $v0, $t3, .L80247968
/* 13AC44 80247904 00131400 */   sll      $v0, $s3, 0x10
/* 13AC48 80247908 24150001 */  addiu     $s5, $zero, 1
/* 13AC4C 8024790C 8FAA0088 */  lw        $t2, 0x88($sp)
/* 13AC50 80247910 1540002A */  bnez      $t2, .L802479BC
/* 13AC54 80247914 00021403 */   sra      $v0, $v0, 0x10
/* 13AC58 80247918 00021140 */  sll       $v0, $v0, 5
/* 13AC5C 8024791C 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 13AC60 80247920 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 13AC64 80247924 004B1021 */  addu      $v0, $v0, $t3
/* 13AC68 80247928 3C0A8009 */  lui       $t2, %hi(gMoveTable)
/* 13AC6C 8024792C 254AF060 */  addiu     $t2, $t2, %lo(gMoveTable)
/* 13AC70 80247930 9043001A */  lbu       $v1, 0x1a($v0)
/* 13AC74 80247934 8FAB0084 */  lw        $t3, 0x84($sp)
/* 13AC78 80247938 00031080 */  sll       $v0, $v1, 2
/* 13AC7C 8024793C 00431021 */  addu      $v0, $v0, $v1
/* 13AC80 80247940 00021080 */  sll       $v0, $v0, 2
/* 13AC84 80247944 004A1021 */  addu      $v0, $v0, $t2
/* 13AC88 80247948 80420012 */  lb        $v0, 0x12($v0)
/* 13AC8C 8024794C 15600006 */  bnez      $t3, .L80247968
/* 13AC90 80247950 AFA20070 */   sw       $v0, 0x70($sp)
/* 13AC94 80247954 8FAA006C */  lw        $t2, 0x6c($sp)
/* 13AC98 80247958 0142102A */  slt       $v0, $t2, $v0
/* 13AC9C 8024795C 14400002 */  bnez      $v0, .L80247968
/* 13ACA0 80247960 02A0582D */   daddu    $t3, $s5, $zero
/* 13ACA4 80247964 AFAB0074 */  sw        $t3, 0x74($sp)
.L80247968:
/* 13ACA8 80247968 8FAA0088 */  lw        $t2, 0x88($sp)
/* 13ACAC 8024796C 15400014 */  bnez      $t2, .L802479C0
/* 13ACB0 80247970 0000902D */   daddu    $s2, $zero, $zero
/* 13ACB4 80247974 00131400 */  sll       $v0, $s3, 0x10
/* 13ACB8 80247978 000212C3 */  sra       $v0, $v0, 0xb
/* 13ACBC 8024797C 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 13ACC0 80247980 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 13ACC4 80247984 004B1021 */  addu      $v0, $v0, $t3
/* 13ACC8 80247988 3C0A8009 */  lui       $t2, %hi(gMoveTable)
/* 13ACCC 8024798C 254AF060 */  addiu     $t2, $t2, %lo(gMoveTable)
/* 13ACD0 80247990 9043001A */  lbu       $v1, 0x1a($v0)
/* 13ACD4 80247994 8FAB006C */  lw        $t3, 0x6c($sp)
/* 13ACD8 80247998 00031080 */  sll       $v0, $v1, 2
/* 13ACDC 8024799C 00431021 */  addu      $v0, $v0, $v1
/* 13ACE0 802479A0 00021080 */  sll       $v0, $v0, 2
/* 13ACE4 802479A4 004A1021 */  addu      $v0, $v0, $t2
/* 13ACE8 802479A8 80420012 */  lb        $v0, 0x12($v0)
/* 13ACEC 802479AC 0162102A */  slt       $v0, $t3, $v0
/* 13ACF0 802479B0 10400003 */  beqz      $v0, .L802479C0
/* 13ACF4 802479B4 240A0001 */   addiu    $t2, $zero, 1
/* 13ACF8 802479B8 AFAA008C */  sw        $t2, 0x8c($sp)
.L802479BC:
/* 13ACFC 802479BC 0000902D */  daddu     $s2, $zero, $zero
.L802479C0:
/* 13AD00 802479C0 12A00003 */  beqz      $s5, .L802479D0
/* 13AD04 802479C4 0240A02D */   daddu    $s4, $s2, $zero
/* 13AD08 802479C8 2412FFFF */  addiu     $s2, $zero, -1
/* 13AD0C 802479CC 0240A02D */  daddu     $s4, $s2, $zero
.L802479D0:
/* 13AD10 802479D0 8FAB0054 */  lw        $t3, 0x54($sp)
/* 13AD14 802479D4 15600037 */  bnez      $t3, .L80247AB4
/* 13AD18 802479D8 240A0001 */   addiu    $t2, $zero, 1
/* 13AD1C 802479DC 240B000A */  addiu     $t3, $zero, 0xa
/* 13AD20 802479E0 AFAA0064 */  sw        $t2, 0x64($sp)
/* 13AD24 802479E4 12A00003 */  beqz      $s5, .L802479F4
/* 13AD28 802479E8 AFAB0068 */   sw       $t3, 0x68($sp)
/* 13AD2C 802479EC 240A0009 */  addiu     $t2, $zero, 9
/* 13AD30 802479F0 AFAA0064 */  sw        $t2, 0x64($sp)
.L802479F4:
/* 13AD34 802479F4 8FAB0084 */  lw        $t3, 0x84($sp)
/* 13AD38 802479F8 1160002A */  beqz      $t3, .L80247AA4
/* 13AD3C 802479FC 00000000 */   nop
/* 13AD40 80247A00 0C091CAA */  jal       pause_badges_scroll_offset_x
/* 13AD44 80247A04 02E0202D */   daddu    $a0, $s7, $zero
/* 13AD48 80247A08 8FAA007C */  lw        $t2, 0x7c($sp)
/* 13AD4C 80247A0C 02C0202D */  daddu     $a0, $s6, $zero
/* 13AD50 80247A10 01428021 */  addu      $s0, $t2, $v0
/* 13AD54 80247A14 0C091CA6 */  jal       pause_badges_scroll_offset_y
/* 13AD58 80247A18 2610FFEC */   addiu    $s0, $s0, -0x14
/* 13AD5C 80247A1C 24040004 */  addiu     $a0, $zero, 4
/* 13AD60 80247A20 3C058027 */  lui       $a1, %hi(D_8026FC10)
/* 13AD64 80247A24 24A5FC10 */  addiu     $a1, $a1, %lo(D_8026FC10)
/* 13AD68 80247A28 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13AD6C 80247A2C 0200302D */  daddu     $a2, $s0, $zero
/* 13AD70 80247A30 AFA00010 */  sw        $zero, 0x10($sp)
/* 13AD74 80247A34 AFA00020 */  sw        $zero, 0x20($sp)
/* 13AD78 80247A38 AFA00024 */  sw        $zero, 0x24($sp)
/* 13AD7C 80247A3C AFA00028 */  sw        $zero, 0x28($sp)
/* 13AD80 80247A40 AFA0002C */  sw        $zero, 0x2c($sp)
/* 13AD84 80247A44 AFA00030 */  sw        $zero, 0x30($sp)
/* 13AD88 80247A48 AFA00034 */  sw        $zero, 0x34($sp)
/* 13AD8C 80247A4C AFA00038 */  sw        $zero, 0x38($sp)
/* 13AD90 80247A50 AFA0003C */  sw        $zero, 0x3c($sp)
/* 13AD94 80247A54 AFA00040 */  sw        $zero, 0x40($sp)
/* 13AD98 80247A58 AFA0004C */  sw        $zero, 0x4c($sp)
/* 13AD9C 80247A5C 01621021 */  addu      $v0, $t3, $v0
/* 13ADA0 80247A60 24470011 */  addiu     $a3, $v0, 0x11
/* 13ADA4 80247A64 240200C8 */  addiu     $v0, $zero, 0xc8
/* 13ADA8 80247A68 AFA20014 */  sw        $v0, 0x14($sp)
/* 13ADAC 80247A6C 2402000D */  addiu     $v0, $zero, 0xd
/* 13ADB0 80247A70 AFA20018 */  sw        $v0, 0x18($sp)
/* 13ADB4 80247A74 240200FF */  addiu     $v0, $zero, 0xff
/* 13ADB8 80247A78 AFA2001C */  sw        $v0, 0x1c($sp)
/* 13ADBC 80247A7C 24020140 */  addiu     $v0, $zero, 0x140
/* 13ADC0 80247A80 AFA20044 */  sw        $v0, 0x44($sp)
/* 13ADC4 80247A84 240200F0 */  addiu     $v0, $zero, 0xf0
/* 13ADC8 80247A88 0C03D4B8 */  jal       draw_box
/* 13ADCC 80247A8C AFA20048 */   sw       $v0, 0x48($sp)
/* 13ADD0 80247A90 08091EAD */  j         .L80247AB4
/* 13ADD4 80247A94 00000000 */   nop
.L80247A98:
/* 13ADD8 80247A98 240A0001 */  addiu     $t2, $zero, 1
/* 13ADDC 80247A9C 08091E2D */  j         .L802478B4
/* 13ADE0 80247AA0 AFAA0084 */   sw       $t2, 0x84($sp)
.L80247AA4:
/* 13ADE4 80247AA4 8FAB008C */  lw        $t3, 0x8c($sp)
/* 13ADE8 80247AA8 11600002 */  beqz      $t3, .L80247AB4
/* 13ADEC 80247AAC 240A000B */   addiu    $t2, $zero, 0xb
/* 13ADF0 80247AB0 AFAA0068 */  sw        $t2, 0x68($sp)
.L80247AB4:
/* 13ADF4 80247AB4 0C091C9C */  jal       pause_badges_is_visible
/* 13ADF8 80247AB8 02C0202D */   daddu    $a0, $s6, $zero
/* 13ADFC 80247ABC 104001A2 */  beqz      $v0, .L80248148
/* 13AE00 80247AC0 00000000 */   nop
/* 13AE04 80247AC4 8FAB0054 */  lw        $t3, 0x54($sp)
/* 13AE08 80247AC8 15600058 */  bnez      $t3, .L80247C2C
/* 13AE0C 80247ACC 24020001 */   addiu    $v0, $zero, 1
/* 13AE10 80247AD0 8FAA0088 */  lw        $t2, 0x88($sp)
/* 13AE14 80247AD4 11400018 */  beqz      $t2, .L80247B38
/* 13AE18 80247AD8 00131400 */   sll      $v0, $s3, 0x10
/* 13AE1C 80247ADC 0C093BA0 */  jal       pause_get_menu_msg
/* 13AE20 80247AE0 24040045 */   addiu    $a0, $zero, 0x45
/* 13AE24 80247AE4 02E0202D */  daddu     $a0, $s7, $zero
/* 13AE28 80247AE8 0C091CAA */  jal       pause_badges_scroll_offset_x
/* 13AE2C 80247AEC 0040882D */   daddu    $s1, $v0, $zero
/* 13AE30 80247AF0 8FAB007C */  lw        $t3, 0x7c($sp)
/* 13AE34 80247AF4 02C0202D */  daddu     $a0, $s6, $zero
/* 13AE38 80247AF8 01628021 */  addu      $s0, $t3, $v0
/* 13AE3C 80247AFC 0C091CA6 */  jal       pause_badges_scroll_offset_y
/* 13AE40 80247B00 02128021 */   addu     $s0, $s0, $s2
/* 13AE44 80247B04 0220202D */  daddu     $a0, $s1, $zero
/* 13AE48 80247B08 0200282D */  daddu     $a1, $s0, $zero
/* 13AE4C 80247B0C 240700FF */  addiu     $a3, $zero, 0xff
/* 13AE50 80247B10 8FAA0080 */  lw        $t2, 0x80($sp)
/* 13AE54 80247B14 8FAB0068 */  lw        $t3, 0x68($sp)
/* 13AE58 80247B18 01421021 */  addu      $v0, $t2, $v0
/* 13AE5C 80247B1C 8FAA0064 */  lw        $t2, 0x64($sp)
/* 13AE60 80247B20 00543021 */  addu      $a2, $v0, $s4
/* 13AE64 80247B24 AFAB0010 */  sw        $t3, 0x10($sp)
/* 13AE68 80247B28 0C04993B */  jal       draw_msg
/* 13AE6C 80247B2C AFAA0014 */   sw       $t2, 0x14($sp)
/* 13AE70 80247B30 08091F09 */  j         .L80247C24
/* 13AE74 80247B34 00000000 */   nop
.L80247B38:
/* 13AE78 80247B38 000212C3 */  sra       $v0, $v0, 0xb
/* 13AE7C 80247B3C 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 13AE80 80247B40 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 13AE84 80247B44 004B8821 */  addu      $s1, $v0, $t3
/* 13AE88 80247B48 8E220000 */  lw        $v0, ($s1)
/* 13AE8C 80247B4C 10400015 */  beqz      $v0, .L80247BA4
/* 13AE90 80247B50 00000000 */   nop
/* 13AE94 80247B54 18400013 */  blez      $v0, .L80247BA4
/* 13AE98 80247B58 00000000 */   nop
/* 13AE9C 80247B5C 0C091CAA */  jal       pause_badges_scroll_offset_x
/* 13AEA0 80247B60 02E0202D */   daddu    $a0, $s7, $zero
/* 13AEA4 80247B64 8FAA007C */  lw        $t2, 0x7c($sp)
/* 13AEA8 80247B68 02C0202D */  daddu     $a0, $s6, $zero
/* 13AEAC 80247B6C 01428021 */  addu      $s0, $t2, $v0
/* 13AEB0 80247B70 0C091CA6 */  jal       pause_badges_scroll_offset_y
/* 13AEB4 80247B74 02128021 */   addu     $s0, $s0, $s2
/* 13AEB8 80247B78 0200282D */  daddu     $a1, $s0, $zero
/* 13AEBC 80247B7C 8FAB0080 */  lw        $t3, 0x80($sp)
/* 13AEC0 80247B80 8FAA0068 */  lw        $t2, 0x68($sp)
/* 13AEC4 80247B84 01621021 */  addu      $v0, $t3, $v0
/* 13AEC8 80247B88 8FAB0064 */  lw        $t3, 0x64($sp)
/* 13AECC 80247B8C 240700FF */  addiu     $a3, $zero, 0xff
/* 13AED0 80247B90 AFAA0010 */  sw        $t2, 0x10($sp)
/* 13AED4 80247B94 AFAB0014 */  sw        $t3, 0x14($sp)
/* 13AED8 80247B98 8E240000 */  lw        $a0, ($s1)
/* 13AEDC 80247B9C 0C04993B */  jal       draw_msg
/* 13AEE0 80247BA0 00543021 */   addu     $a2, $v0, $s4
.L80247BA4:
/* 13AEE4 80247BA4 0C091CAA */  jal       pause_badges_scroll_offset_x
/* 13AEE8 80247BA8 02E0202D */   daddu    $a0, $s7, $zero
/* 13AEEC 80247BAC 02C0202D */  daddu     $a0, $s6, $zero
/* 13AEF0 80247BB0 8FAA00C4 */  lw        $t2, 0xc4($sp)
/* 13AEF4 80247BB4 245000EB */  addiu     $s0, $v0, 0xeb
/* 13AEF8 80247BB8 0C091CA6 */  jal       pause_badges_scroll_offset_y
/* 13AEFC 80247BBC 01508021 */   addu     $s0, $t2, $s0
/* 13AF00 80247BC0 0200282D */  daddu     $a1, $s0, $zero
/* 13AF04 80247BC4 24420011 */  addiu     $v0, $v0, 0x11
/* 13AF08 80247BC8 00131C00 */  sll       $v1, $s3, 0x10
/* 13AF0C 80247BCC 00031AC3 */  sra       $v1, $v1, 0xb
/* 13AF10 80247BD0 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 13AF14 80247BD4 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 13AF18 80247BD8 006B1821 */  addu      $v1, $v1, $t3
/* 13AF1C 80247BDC 3C0B8009 */  lui       $t3, %hi(gMoveTable)
/* 13AF20 80247BE0 256BF060 */  addiu     $t3, $t3, %lo(gMoveTable)
/* 13AF24 80247BE4 24070001 */  addiu     $a3, $zero, 1
/* 13AF28 80247BE8 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13AF2C 80247BEC 9063001A */  lbu       $v1, 0x1a($v1)
/* 13AF30 80247BF0 01423021 */  addu      $a2, $t2, $v0
/* 13AF34 80247BF4 00031080 */  sll       $v0, $v1, 2
/* 13AF38 80247BF8 00431021 */  addu      $v0, $v0, $v1
/* 13AF3C 80247BFC 00021080 */  sll       $v0, $v0, 2
/* 13AF40 80247C00 004B1021 */  addu      $v0, $v0, $t3
/* 13AF44 80247C04 80440012 */  lb        $a0, 0x12($v0)
/* 13AF48 80247C08 8FAA0068 */  lw        $t2, 0x68($sp)
/* 13AF4C 80247C0C 240200FF */  addiu     $v0, $zero, 0xff
/* 13AF50 80247C10 AFA20014 */  sw        $v0, 0x14($sp)
/* 13AF54 80247C14 24020003 */  addiu     $v0, $zero, 3
/* 13AF58 80247C18 AFA20018 */  sw        $v0, 0x18($sp)
/* 13AF5C 80247C1C 0C049DA7 */  jal       draw_number
/* 13AF60 80247C20 AFAA0010 */   sw       $t2, 0x10($sp)
.L80247C24:
/* 13AF64 80247C24 8FAB0054 */  lw        $t3, 0x54($sp)
/* 13AF68 80247C28 24020001 */  addiu     $v0, $zero, 1
.L80247C2C:
/* 13AF6C 80247C2C 15620060 */  bne       $t3, $v0, .L80247DB0
/* 13AF70 80247C30 3C052000 */   lui      $a1, 0x2000
/* 13AF74 80247C34 8FAA0058 */  lw        $t2, 0x58($sp)
/* 13AF78 80247C38 000A1080 */  sll       $v0, $t2, 2
/* 13AF7C 80247C3C 3C0B8027 */  lui       $t3, %hi(gBadgeMenuIconIDs)
/* 13AF80 80247C40 256B03A8 */  addiu     $t3, $t3, %lo(gBadgeMenuIconIDs)
/* 13AF84 80247C44 004B1021 */  addu      $v0, $v0, $t3
/* 13AF88 80247C48 8C510000 */  lw        $s1, ($v0)
/* 13AF8C 80247C4C 0C05128B */  jal       clear_hud_element_flags
/* 13AF90 80247C50 0220202D */   daddu    $a0, $s1, $zero
/* 13AF94 80247C54 0220202D */  daddu     $a0, $s1, $zero
/* 13AF98 80247C58 0C051280 */  jal       set_hud_element_flags
/* 13AF9C 80247C5C 34058000 */   ori      $a1, $zero, 0x8000
/* 13AFA0 80247C60 8FAA0088 */  lw        $t2, 0x88($sp)
/* 13AFA4 80247C64 11400005 */  beqz      $t2, .L80247C7C
/* 13AFA8 80247C68 00000000 */   nop
/* 13AFAC 80247C6C 3C118027 */  lui       $s1, %hi(D_802703FC)
/* 13AFB0 80247C70 8E3103FC */  lw        $s1, %lo(D_802703FC)($s1)
/* 13AFB4 80247C74 08091F51 */  j         .L80247D44
/* 13AFB8 80247C78 00000000 */   nop
.L80247C7C:
/* 13AFBC 80247C7C 12A00010 */  beqz      $s5, .L80247CC0
/* 13AFC0 80247C80 0220202D */   daddu    $a0, $s1, $zero
/* 13AFC4 80247C84 0C051280 */  jal       set_hud_element_flags
/* 13AFC8 80247C88 3C052000 */   lui      $a1, 0x2000
/* 13AFCC 80247C8C 00131400 */  sll       $v0, $s3, 0x10
/* 13AFD0 80247C90 000212C3 */  sra       $v0, $v0, 0xb
/* 13AFD4 80247C94 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 13AFD8 80247C98 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 13AFDC 80247C9C 004B1021 */  addu      $v0, $v0, $t3
/* 13AFE0 80247CA0 84420004 */  lh        $v0, 4($v0)
/* 13AFE4 80247CA4 3C0A8009 */  lui       $t2, %hi(D_8008A680)
/* 13AFE8 80247CA8 254AA680 */  addiu     $t2, $t2, %lo(D_8008A680)
/* 13AFEC 80247CAC 000210C0 */  sll       $v0, $v0, 3
/* 13AFF0 80247CB0 004A1021 */  addu      $v0, $v0, $t2
/* 13AFF4 80247CB4 8C420000 */  lw        $v0, ($v0)
/* 13AFF8 80247CB8 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescIconScript)
/* 13AFFC 80247CBC AC2200CC */  sw        $v0, %lo(gPauseMenuCurrentDescIconScript)($at)
.L80247CC0:
/* 13B000 80247CC0 8FAB0084 */  lw        $t3, 0x84($sp)
/* 13B004 80247CC4 1560000F */  bnez      $t3, .L80247D04
/* 13B008 80247CC8 00131400 */   sll      $v0, $s3, 0x10
/* 13B00C 80247CCC 8FAA008C */  lw        $t2, 0x8c($sp)
/* 13B010 80247CD0 1140000B */  beqz      $t2, .L80247D00
/* 13B014 80247CD4 000212C3 */   sra      $v0, $v0, 0xb
/* 13B018 80247CD8 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 13B01C 80247CDC 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 13B020 80247CE0 004B1021 */  addu      $v0, $v0, $t3
/* 13B024 80247CE4 84420004 */  lh        $v0, 4($v0)
/* 13B028 80247CE8 3C0A8009 */  lui       $t2, %hi(D_8008A680)
/* 13B02C 80247CEC 254AA680 */  addiu     $t2, $t2, %lo(D_8008A680)
/* 13B030 80247CF0 000210C0 */  sll       $v0, $v0, 3
/* 13B034 80247CF4 004A1021 */  addu      $v0, $v0, $t2
/* 13B038 80247CF8 08091F4B */  j         .L80247D2C
/* 13B03C 80247CFC 8C450004 */   lw       $a1, 4($v0)
.L80247D00:
/* 13B040 80247D00 00131400 */  sll       $v0, $s3, 0x10
.L80247D04:
/* 13B044 80247D04 000212C3 */  sra       $v0, $v0, 0xb
/* 13B048 80247D08 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 13B04C 80247D0C 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 13B050 80247D10 004B1021 */  addu      $v0, $v0, $t3
/* 13B054 80247D14 84420004 */  lh        $v0, 4($v0)
/* 13B058 80247D18 3C0A8009 */  lui       $t2, %hi(D_8008A680)
/* 13B05C 80247D1C 254AA680 */  addiu     $t2, $t2, %lo(D_8008A680)
/* 13B060 80247D20 000210C0 */  sll       $v0, $v0, 3
/* 13B064 80247D24 004A1021 */  addu      $v0, $v0, $t2
/* 13B068 80247D28 8C450000 */  lw        $a1, ($v0)
.L80247D2C:
/* 13B06C 80247D2C 0C0511FF */  jal       set_hud_element_anim
/* 13B070 80247D30 0220202D */   daddu    $a0, $s1, $zero
/* 13B074 80247D34 3C053F2B */  lui       $a1, 0x3f2b
/* 13B078 80247D38 34A5BA99 */  ori       $a1, $a1, 0xba99
/* 13B07C 80247D3C 0C051308 */  jal       set_hud_element_scale
/* 13B080 80247D40 0220202D */   daddu    $a0, $s1, $zero
.L80247D44:
/* 13B084 80247D44 0C091CAA */  jal       pause_badges_scroll_offset_x
/* 13B088 80247D48 02E0202D */   daddu    $a0, $s7, $zero
/* 13B08C 80247D4C 02C0202D */  daddu     $a0, $s6, $zero
/* 13B090 80247D50 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B094 80247D54 2450006B */  addiu     $s0, $v0, 0x6b
/* 13B098 80247D58 01708021 */  addu      $s0, $t3, $s0
/* 13B09C 80247D5C 0C091CA6 */  jal       pause_badges_scroll_offset_y
/* 13B0A0 80247D60 02128021 */   addu     $s0, $s0, $s2
/* 13B0A4 80247D64 0220202D */  daddu     $a0, $s1, $zero
/* 13B0A8 80247D68 0200282D */  daddu     $a1, $s0, $zero
/* 13B0AC 80247D6C 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13B0B0 80247D70 24420017 */  addiu     $v0, $v0, 0x17
/* 13B0B4 80247D74 01421021 */  addu      $v0, $t2, $v0
/* 13B0B8 80247D78 0C051261 */  jal       set_hud_element_render_pos
/* 13B0BC 80247D7C 00543021 */   addu     $a2, $v0, $s4
/* 13B0C0 80247D80 8FAB0058 */  lw        $t3, 0x58($sp)
/* 13B0C4 80247D84 15600005 */  bnez      $t3, .L80247D9C
/* 13B0C8 80247D88 00000000 */   nop
/* 13B0CC 80247D8C 0C0511F8 */  jal       draw_hud_element_3
/* 13B0D0 80247D90 0220202D */   daddu    $a0, $s1, $zero
/* 13B0D4 80247D94 08091F69 */  j         .L80247DA4
/* 13B0D8 80247D98 00000000 */   nop
.L80247D9C:
/* 13B0DC 80247D9C 0C0511F1 */  jal       draw_hud_element_2
/* 13B0E0 80247DA0 0220202D */   daddu    $a0, $s1, $zero
.L80247DA4:
/* 13B0E4 80247DA4 8FAA0058 */  lw        $t2, 0x58($sp)
/* 13B0E8 80247DA8 254A0001 */  addiu     $t2, $t2, 1
/* 13B0EC 80247DAC AFAA0058 */  sw        $t2, 0x58($sp)
.L80247DB0:
/* 13B0F0 80247DB0 8FAB0054 */  lw        $t3, 0x54($sp)
/* 13B0F4 80247DB4 24020002 */  addiu     $v0, $zero, 2
/* 13B0F8 80247DB8 156200E3 */  bne       $t3, $v0, .L80248148
/* 13B0FC 80247DBC 00000000 */   nop
/* 13B100 80247DC0 8FAA0088 */  lw        $t2, 0x88($sp)
/* 13B104 80247DC4 154000E0 */  bnez      $t2, .L80248148
/* 13B108 80247DC8 00131400 */   sll      $v0, $s3, 0x10
/* 13B10C 80247DCC 000212C3 */  sra       $v0, $v0, 0xb
/* 13B110 80247DD0 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 13B114 80247DD4 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 13B118 80247DD8 004B1021 */  addu      $v0, $v0, $t3
/* 13B11C 80247DDC 9043001A */  lbu       $v1, 0x1a($v0)
/* 13B120 80247DE0 3C0A8009 */  lui       $t2, %hi(gMoveTable)
/* 13B124 80247DE4 254AF060 */  addiu     $t2, $t2, %lo(gMoveTable)
/* 13B128 80247DE8 00031080 */  sll       $v0, $v1, 2
/* 13B12C 80247DEC 00431021 */  addu      $v0, $v0, $v1
/* 13B130 80247DF0 00021080 */  sll       $v0, $v0, 2
/* 13B134 80247DF4 004A1021 */  addu      $v0, $v0, $t2
/* 13B138 80247DF8 80530012 */  lb        $s3, 0x12($v0)
/* 13B13C 80247DFC 2A62000B */  slti      $v0, $s3, 0xb
/* 13B140 80247E00 10400002 */  beqz      $v0, .L80247E0C
/* 13B144 80247E04 24150001 */   addiu    $s5, $zero, 1
/* 13B148 80247E08 24150004 */  addiu     $s5, $zero, 4
.L80247E0C:
/* 13B14C 80247E0C 3C04E300 */  lui       $a0, 0xe300
/* 13B150 80247E10 34841201 */  ori       $a0, $a0, 0x1201
/* 13B154 80247E14 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 13B158 80247E18 8CA5A66C */  lw        $a1, %lo(gMasterGfxPos)($a1)
/* 13B15C 80247E1C 3C02DE00 */  lui       $v0, 0xde00
/* 13B160 80247E20 00A0182D */  daddu     $v1, $a1, $zero
/* 13B164 80247E24 24A50008 */  addiu     $a1, $a1, 8
/* 13B168 80247E28 AC620000 */  sw        $v0, ($v1)
/* 13B16C 80247E2C 3C028027 */  lui       $v0, %hi(D_8026F348)
/* 13B170 80247E30 2442F348 */  addiu     $v0, $v0, %lo(D_8026F348)
/* 13B174 80247E34 AC620004 */  sw        $v0, 4($v1)
/* 13B178 80247E38 24A20008 */  addiu     $v0, $a1, 8
/* 13B17C 80247E3C 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 13B180 80247E40 AC25A66C */  sw        $a1, %lo(gMasterGfxPos)($at)
/* 13B184 80247E44 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 13B188 80247E48 AC22A66C */  sw        $v0, %lo(gMasterGfxPos)($at)
/* 13B18C 80247E4C 24022000 */  addiu     $v0, $zero, 0x2000
/* 13B190 80247E50 ACA40000 */  sw        $a0, ($a1)
/* 13B194 80247E54 ACA20004 */  sw        $v0, 4($a1)
/* 13B198 80247E58 8FAB0084 */  lw        $t3, 0x84($sp)
/* 13B19C 80247E5C 15600081 */  bnez      $t3, .L80248064
/* 13B1A0 80247E60 3C0300FF */   lui      $v1, 0xff
/* 13B1A4 80247E64 1A600032 */  blez      $s3, .L80247F30
/* 13B1A8 80247E68 0000802D */   daddu    $s0, $zero, $zero
/* 13B1AC 80247E6C 2A740005 */  slti      $s4, $s3, 5
.L80247E70:
/* 13B1B0 80247E70 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 13B1B4 80247E74 8C42A66C */  lw        $v0, %lo(gMasterGfxPos)($v0)
/* 13B1B8 80247E78 02E0202D */  daddu     $a0, $s7, $zero
/* 13B1BC 80247E7C 0040182D */  daddu     $v1, $v0, $zero
/* 13B1C0 80247E80 3C0AFA00 */  lui       $t2, 0xfa00
/* 13B1C4 80247E84 AC6A0000 */  sw        $t2, ($v1)
/* 13B1C8 80247E88 8FAB0090 */  lw        $t3, 0x90($sp)
/* 13B1CC 80247E8C 24420008 */  addiu     $v0, $v0, 8
/* 13B1D0 80247E90 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 13B1D4 80247E94 AC22A66C */  sw        $v0, %lo(gMasterGfxPos)($at)
/* 13B1D8 80247E98 0C091CAA */  jal       pause_badges_scroll_offset_x
/* 13B1DC 80247E9C AC6B0004 */   sw       $t3, 4($v1)
/* 13B1E0 80247EA0 8FAA0094 */  lw        $t2, 0x94($sp)
/* 13B1E4 80247EA4 02C0202D */  daddu     $a0, $s6, $zero
/* 13B1E8 80247EA8 020A0018 */  mult      $s0, $t2
/* 13B1EC 80247EAC 244200EB */  addiu     $v0, $v0, 0xeb
/* 13B1F0 80247EB0 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B1F4 80247EB4 00101FC3 */  sra       $v1, $s0, 0x1f
/* 13B1F8 80247EB8 01621021 */  addu      $v0, $t3, $v0
/* 13B1FC 80247EBC 00005010 */  mfhi      $t2
/* 13B200 80247EC0 000A2843 */  sra       $a1, $t2, 1
/* 13B204 80247EC4 00A38823 */  subu      $s1, $a1, $v1
/* 13B208 80247EC8 00112880 */  sll       $a1, $s1, 2
/* 13B20C 80247ECC 00B12821 */  addu      $a1, $a1, $s1
/* 13B210 80247ED0 02052823 */  subu      $a1, $s0, $a1
/* 13B214 80247ED4 00051840 */  sll       $v1, $a1, 1
/* 13B218 80247ED8 00651821 */  addu      $v1, $v1, $a1
/* 13B21C 80247EDC 00031840 */  sll       $v1, $v1, 1
/* 13B220 80247EE0 24630001 */  addiu     $v1, $v1, 1
/* 13B224 80247EE4 0C091CA6 */  jal       pause_badges_scroll_offset_y
/* 13B228 80247EE8 00439021 */   addu     $s2, $v0, $v1
/* 13B22C 80247EEC 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13B230 80247EF0 24420011 */  addiu     $v0, $v0, 0x11
/* 13B234 80247EF4 01621021 */  addu      $v0, $t3, $v0
/* 13B238 80247EF8 16800006 */  bnez      $s4, .L80247F14
/* 13B23C 80247EFC 00553021 */   addu     $a2, $v0, $s5
/* 13B240 80247F00 24C3FFFD */  addiu     $v1, $a2, -3
/* 13B244 80247F04 00111040 */  sll       $v0, $s1, 1
/* 13B248 80247F08 00511021 */  addu      $v0, $v0, $s1
/* 13B24C 80247F0C 00021040 */  sll       $v0, $v0, 1
/* 13B250 80247F10 00623021 */  addu      $a2, $v1, $v0
.L80247F14:
/* 13B254 80247F14 0000202D */  daddu     $a0, $zero, $zero
/* 13B258 80247F18 0C091D16 */  jal       pause_badges_draw_bp_orbs
/* 13B25C 80247F1C 0240282D */   daddu    $a1, $s2, $zero
/* 13B260 80247F20 26100001 */  addiu     $s0, $s0, 1
/* 13B264 80247F24 0213102A */  slt       $v0, $s0, $s3
/* 13B268 80247F28 1440FFD1 */  bnez      $v0, .L80247E70
/* 13B26C 80247F2C 00000000 */   nop
.L80247F30:
/* 13B270 80247F30 3C06E200 */  lui       $a2, 0xe200
/* 13B274 80247F34 34C6001C */  ori       $a2, $a2, 0x1c
/* 13B278 80247F38 3C050050 */  lui       $a1, 0x50
/* 13B27C 80247F3C 34A54340 */  ori       $a1, $a1, 0x4340
/* 13B280 80247F40 0000802D */  daddu     $s0, $zero, $zero
/* 13B284 80247F44 3C02E700 */  lui       $v0, 0xe700
/* 13B288 80247F48 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 13B28C 80247F4C 8C84A66C */  lw        $a0, %lo(gMasterGfxPos)($a0)
/* 13B290 80247F50 240B00FF */  addiu     $t3, $zero, 0xff
/* 13B294 80247F54 0080182D */  daddu     $v1, $a0, $zero
/* 13B298 80247F58 24840008 */  addiu     $a0, $a0, 8
/* 13B29C 80247F5C AC620000 */  sw        $v0, ($v1)
/* 13B2A0 80247F60 24820008 */  addiu     $v0, $a0, 8
/* 13B2A4 80247F64 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 13B2A8 80247F68 AC24A66C */  sw        $a0, %lo(gMasterGfxPos)($at)
/* 13B2AC 80247F6C 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 13B2B0 80247F70 AC22A66C */  sw        $v0, %lo(gMasterGfxPos)($at)
/* 13B2B4 80247F74 24820010 */  addiu     $v0, $a0, 0x10
/* 13B2B8 80247F78 AC600004 */  sw        $zero, 4($v1)
/* 13B2BC 80247F7C 3C0AFA00 */  lui       $t2, 0xfa00
/* 13B2C0 80247F80 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 13B2C4 80247F84 AC22A66C */  sw        $v0, %lo(gMasterGfxPos)($at)
/* 13B2C8 80247F88 000B1400 */  sll       $v0, $t3, 0x10
/* 13B2CC 80247F8C AC8A0008 */  sw        $t2, 8($a0)
/* 13B2D0 80247F90 240A0064 */  addiu     $t2, $zero, 0x64
/* 13B2D4 80247F94 000A1A00 */  sll       $v1, $t2, 8
/* 13B2D8 80247F98 00431025 */  or        $v0, $v0, $v1
/* 13B2DC 80247F9C 34420080 */  ori       $v0, $v0, 0x80
/* 13B2E0 80247FA0 AC860000 */  sw        $a2, ($a0)
/* 13B2E4 80247FA4 AC850004 */  sw        $a1, 4($a0)
/* 13B2E8 80247FA8 1A600067 */  blez      $s3, .L80248148
/* 13B2EC 80247FAC AC82000C */   sw       $v0, 0xc($a0)
/* 13B2F0 80247FB0 2A740005 */  slti      $s4, $s3, 5
.L80247FB4:
/* 13B2F4 80247FB4 8FAB006C */  lw        $t3, 0x6c($sp)
/* 13B2F8 80247FB8 020B102A */  slt       $v0, $s0, $t3
/* 13B2FC 80247FBC 50400024 */  beql      $v0, $zero, .L80248050
/* 13B300 80247FC0 26100001 */   addiu    $s0, $s0, 1
/* 13B304 80247FC4 0C091CAA */  jal       pause_badges_scroll_offset_x
/* 13B308 80247FC8 02E0202D */   daddu    $a0, $s7, $zero
/* 13B30C 80247FCC 8FAA0094 */  lw        $t2, 0x94($sp)
/* 13B310 80247FD0 02C0202D */  daddu     $a0, $s6, $zero
/* 13B314 80247FD4 020A0018 */  mult      $s0, $t2
/* 13B318 80247FD8 244200EB */  addiu     $v0, $v0, 0xeb
/* 13B31C 80247FDC 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B320 80247FE0 00101FC3 */  sra       $v1, $s0, 0x1f
/* 13B324 80247FE4 01621021 */  addu      $v0, $t3, $v0
/* 13B328 80247FE8 00005010 */  mfhi      $t2
/* 13B32C 80247FEC 000A2843 */  sra       $a1, $t2, 1
/* 13B330 80247FF0 00A38823 */  subu      $s1, $a1, $v1
/* 13B334 80247FF4 00112880 */  sll       $a1, $s1, 2
/* 13B338 80247FF8 00B12821 */  addu      $a1, $a1, $s1
/* 13B33C 80247FFC 02052823 */  subu      $a1, $s0, $a1
/* 13B340 80248000 00051840 */  sll       $v1, $a1, 1
/* 13B344 80248004 00651821 */  addu      $v1, $v1, $a1
/* 13B348 80248008 00031840 */  sll       $v1, $v1, 1
/* 13B34C 8024800C 24630001 */  addiu     $v1, $v1, 1
/* 13B350 80248010 0C091CA6 */  jal       pause_badges_scroll_offset_y
/* 13B354 80248014 00439021 */   addu     $s2, $v0, $v1
/* 13B358 80248018 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13B35C 8024801C 24420011 */  addiu     $v0, $v0, 0x11
/* 13B360 80248020 01621021 */  addu      $v0, $t3, $v0
/* 13B364 80248024 16800006 */  bnez      $s4, .L80248040
/* 13B368 80248028 00553021 */   addu     $a2, $v0, $s5
/* 13B36C 8024802C 24C3FFFD */  addiu     $v1, $a2, -3
/* 13B370 80248030 00111040 */  sll       $v0, $s1, 1
/* 13B374 80248034 00511021 */  addu      $v0, $v0, $s1
/* 13B378 80248038 00021040 */  sll       $v0, $v0, 1
/* 13B37C 8024803C 00623021 */  addu      $a2, $v1, $v0
.L80248040:
/* 13B380 80248040 24040001 */  addiu     $a0, $zero, 1
/* 13B384 80248044 0C091D16 */  jal       pause_badges_draw_bp_orbs
/* 13B388 80248048 0240282D */   daddu    $a1, $s2, $zero
/* 13B38C 8024804C 26100001 */  addiu     $s0, $s0, 1
.L80248050:
/* 13B390 80248050 0213102A */  slt       $v0, $s0, $s3
/* 13B394 80248054 1440FFD7 */  bnez      $v0, .L80247FB4
/* 13B398 80248058 00000000 */   nop
/* 13B39C 8024805C 08092052 */  j         .L80248148
/* 13B3A0 80248060 00000000 */   nop
.L80248064:
/* 13B3A4 80248064 346364FF */  ori       $v1, $v1, 0x64ff
/* 13B3A8 80248068 0000802D */  daddu     $s0, $zero, $zero
/* 13B3AC 8024806C 24A20010 */  addiu     $v0, $a1, 0x10
/* 13B3B0 80248070 3C0AFA00 */  lui       $t2, 0xfa00
/* 13B3B4 80248074 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 13B3B8 80248078 AC22A66C */  sw        $v0, %lo(gMasterGfxPos)($at)
/* 13B3BC 8024807C ACAA0008 */  sw        $t2, 8($a1)
/* 13B3C0 80248080 1A600028 */  blez      $s3, .L80248124
/* 13B3C4 80248084 ACA3000C */   sw       $v1, 0xc($a1)
/* 13B3C8 80248088 2A740005 */  slti      $s4, $s3, 5
.L8024808C:
/* 13B3CC 8024808C 0C091CAA */  jal       pause_badges_scroll_offset_x
/* 13B3D0 80248090 02E0202D */   daddu    $a0, $s7, $zero
/* 13B3D4 80248094 8FAA0094 */  lw        $t2, 0x94($sp)
/* 13B3D8 80248098 02C0202D */  daddu     $a0, $s6, $zero
/* 13B3DC 8024809C 020A0018 */  mult      $s0, $t2
/* 13B3E0 802480A0 244200EB */  addiu     $v0, $v0, 0xeb
/* 13B3E4 802480A4 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B3E8 802480A8 00101FC3 */  sra       $v1, $s0, 0x1f
/* 13B3EC 802480AC 01621021 */  addu      $v0, $t3, $v0
/* 13B3F0 802480B0 00005010 */  mfhi      $t2
/* 13B3F4 802480B4 000A2843 */  sra       $a1, $t2, 1
/* 13B3F8 802480B8 00A38823 */  subu      $s1, $a1, $v1
/* 13B3FC 802480BC 00112880 */  sll       $a1, $s1, 2
/* 13B400 802480C0 00B12821 */  addu      $a1, $a1, $s1
/* 13B404 802480C4 02052823 */  subu      $a1, $s0, $a1
/* 13B408 802480C8 00051840 */  sll       $v1, $a1, 1
/* 13B40C 802480CC 00651821 */  addu      $v1, $v1, $a1
/* 13B410 802480D0 00031840 */  sll       $v1, $v1, 1
/* 13B414 802480D4 24630001 */  addiu     $v1, $v1, 1
/* 13B418 802480D8 0C091CA6 */  jal       pause_badges_scroll_offset_y
/* 13B41C 802480DC 00439021 */   addu     $s2, $v0, $v1
/* 13B420 802480E0 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13B424 802480E4 24420011 */  addiu     $v0, $v0, 0x11
/* 13B428 802480E8 01621021 */  addu      $v0, $t3, $v0
/* 13B42C 802480EC 16800006 */  bnez      $s4, .L80248108
/* 13B430 802480F0 00553021 */   addu     $a2, $v0, $s5
/* 13B434 802480F4 24C3FFFD */  addiu     $v1, $a2, -3
/* 13B438 802480F8 00111040 */  sll       $v0, $s1, 1
/* 13B43C 802480FC 00511021 */  addu      $v0, $v0, $s1
/* 13B440 80248100 00021040 */  sll       $v0, $v0, 1
/* 13B444 80248104 00623021 */  addu      $a2, $v1, $v0
.L80248108:
/* 13B448 80248108 24040002 */  addiu     $a0, $zero, 2
/* 13B44C 8024810C 0C091D16 */  jal       pause_badges_draw_bp_orbs
/* 13B450 80248110 0240282D */   daddu    $a1, $s2, $zero
/* 13B454 80248114 26100001 */  addiu     $s0, $s0, 1
/* 13B458 80248118 0213102A */  slt       $v0, $s0, $s3
/* 13B45C 8024811C 1440FFDB */  bnez      $v0, .L8024808C
/* 13B460 80248120 00000000 */   nop
.L80248124:
/* 13B464 80248124 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 13B468 80248128 8C42A66C */  lw        $v0, %lo(gMasterGfxPos)($v0)
/* 13B46C 8024812C 0040182D */  daddu     $v1, $v0, $zero
/* 13B470 80248130 24420008 */  addiu     $v0, $v0, 8
/* 13B474 80248134 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 13B478 80248138 AC22A66C */  sw        $v0, %lo(gMasterGfxPos)($at)
/* 13B47C 8024813C 3C02E700 */  lui       $v0, 0xe700
/* 13B480 80248140 AC620000 */  sw        $v0, ($v1)
/* 13B484 80248144 AC600004 */  sw        $zero, 4($v1)
.L80248148:
/* 13B488 80248148 8FAA0078 */  lw        $t2, 0x78($sp)
/* 13B48C 8024814C 8D420008 */  lw        $v0, 8($t2)
/* 13B490 80248150 27DE0001 */  addiu     $fp, $fp, 1
/* 13B494 80248154 03C2102A */  slt       $v0, $fp, $v0
/* 13B498 80248158 1440FDB2 */  bnez      $v0, .L80247824
/* 13B49C 8024815C 00000000 */   nop
.L80248160:
/* 13B4A0 80248160 8FAB0050 */  lw        $t3, 0x50($sp)
/* 13B4A4 80248164 256B0001 */  addiu     $t3, $t3, 1
/* 13B4A8 80248168 29620014 */  slti      $v0, $t3, 0x14
/* 13B4AC 8024816C 1440FD96 */  bnez      $v0, .L802477C8
/* 13B4B0 80248170 AFAB0050 */   sw       $t3, 0x50($sp)
.L80248174:
/* 13B4B4 80248174 8FAA0054 */  lw        $t2, 0x54($sp)
/* 13B4B8 80248178 254A0001 */  addiu     $t2, $t2, 1
/* 13B4BC 8024817C 29420003 */  slti      $v0, $t2, 3
/* 13B4C0 80248180 1440FD90 */  bnez      $v0, .L802477C4
/* 13B4C4 80248184 AFAA0054 */   sw       $t2, 0x54($sp)
/* 13B4C8 80248188 3C09800A */  lui       $t1, %hi(gMasterGfxPos)
/* 13B4CC 8024818C 2529A66C */  addiu     $t1, $t1, %lo(gMasterGfxPos)
/* 13B4D0 80248190 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B4D4 80248194 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13B4D8 80248198 8D250000 */  lw        $a1, ($t1)
/* 13B4DC 8024819C 25640001 */  addiu     $a0, $t3, 1
/* 13B4E0 802481A0 25460001 */  addiu     $a2, $t2, 1
/* 13B4E4 802481A4 00A0182D */  daddu     $v1, $a1, $zero
/* 13B4E8 802481A8 8FAA00CC */  lw        $t2, 0xcc($sp)
/* 13B4EC 802481AC 24A50008 */  addiu     $a1, $a1, 8
/* 13B4F0 802481B0 016A1021 */  addu      $v0, $t3, $t2
/* 13B4F4 802481B4 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13B4F8 802481B8 8FAA00D0 */  lw        $t2, 0xd0($sp)
/* 13B4FC 802481BC 2447FFFF */  addiu     $a3, $v0, -1
/* 13B500 802481C0 016A1021 */  addu      $v0, $t3, $t2
/* 13B504 802481C4 2448FFFF */  addiu     $t0, $v0, -1
/* 13B508 802481C8 3C02E700 */  lui       $v0, 0xe700
/* 13B50C 802481CC AD250000 */  sw        $a1, ($t1)
/* 13B510 802481D0 AC620000 */  sw        $v0, ($v1)
/* 13B514 802481D4 1C800002 */  bgtz      $a0, .L802481E0
/* 13B518 802481D8 AC600004 */   sw       $zero, 4($v1)
/* 13B51C 802481DC 24040001 */  addiu     $a0, $zero, 1
.L802481E0:
/* 13B520 802481E0 58C00001 */  blezl     $a2, .L802481E8
/* 13B524 802481E4 24060001 */   addiu    $a2, $zero, 1
.L802481E8:
/* 13B528 802481E8 18E002DC */  blez      $a3, .L80248D5C
/* 13B52C 802481EC 00000000 */   nop
/* 13B530 802481F0 190002DA */  blez      $t0, .L80248D5C
/* 13B534 802481F4 2882013F */   slti     $v0, $a0, 0x13f
/* 13B538 802481F8 104002D8 */  beqz      $v0, .L80248D5C
/* 13B53C 802481FC 28C200EF */   slti     $v0, $a2, 0xef
/* 13B540 80248200 104002D6 */  beqz      $v0, .L80248D5C
/* 13B544 80248204 28E2013F */   slti     $v0, $a3, 0x13f
/* 13B548 80248208 50400001 */  beql      $v0, $zero, .L80248210
/* 13B54C 8024820C 2407013F */   addiu    $a3, $zero, 0x13f
.L80248210:
/* 13B550 80248210 290200EF */  slti      $v0, $t0, 0xef
/* 13B554 80248214 50400001 */  beql      $v0, $zero, .L8024821C
/* 13B558 80248218 240800EF */   addiu    $t0, $zero, 0xef
.L8024821C:
/* 13B55C 8024821C 3C014080 */  lui       $at, 0x4080
/* 13B560 80248220 44812000 */  mtc1      $at, $f4
/* 13B564 80248224 44840000 */  mtc1      $a0, $f0
/* 13B568 80248228 00000000 */  nop
/* 13B56C 8024822C 46800020 */  cvt.s.w   $f0, $f0
/* 13B570 80248230 46040002 */  mul.s     $f0, $f0, $f4
/* 13B574 80248234 00000000 */  nop
/* 13B578 80248238 24A20008 */  addiu     $v0, $a1, 8
/* 13B57C 8024823C 44861000 */  mtc1      $a2, $f2
/* 13B580 80248240 00000000 */  nop
/* 13B584 80248244 468010A0 */  cvt.s.w   $f2, $f2
/* 13B588 80248248 3C04ED00 */  lui       $a0, 0xed00
/* 13B58C 8024824C 46041082 */  mul.s     $f2, $f2, $f4
/* 13B590 80248250 00000000 */  nop
/* 13B594 80248254 AD220000 */  sw        $v0, ($t1)
/* 13B598 80248258 4600018D */  trunc.w.s $f6, $f0
/* 13B59C 8024825C 44023000 */  mfc1      $v0, $f6
/* 13B5A0 80248260 00000000 */  nop
/* 13B5A4 80248264 30420FFF */  andi      $v0, $v0, 0xfff
/* 13B5A8 80248268 00021300 */  sll       $v0, $v0, 0xc
/* 13B5AC 8024826C 4600118D */  trunc.w.s $f6, $f2
/* 13B5B0 80248270 44033000 */  mfc1      $v1, $f6
/* 13B5B4 80248274 44871000 */  mtc1      $a3, $f2
/* 13B5B8 80248278 00000000 */  nop
/* 13B5BC 8024827C 468010A0 */  cvt.s.w   $f2, $f2
/* 13B5C0 80248280 46041082 */  mul.s     $f2, $f2, $f4
/* 13B5C4 80248284 00000000 */  nop
/* 13B5C8 80248288 30630FFF */  andi      $v1, $v1, 0xfff
/* 13B5CC 8024828C 00641825 */  or        $v1, $v1, $a0
/* 13B5D0 80248290 00431025 */  or        $v0, $v0, $v1
/* 13B5D4 80248294 44880000 */  mtc1      $t0, $f0
/* 13B5D8 80248298 00000000 */  nop
/* 13B5DC 8024829C 46800020 */  cvt.s.w   $f0, $f0
/* 13B5E0 802482A0 46040002 */  mul.s     $f0, $f0, $f4
/* 13B5E4 802482A4 00000000 */  nop
/* 13B5E8 802482A8 ACA20000 */  sw        $v0, ($a1)
/* 13B5EC 802482AC 4600118D */  trunc.w.s $f6, $f2
/* 13B5F0 802482B0 44023000 */  mfc1      $v0, $f6
/* 13B5F4 802482B4 00000000 */  nop
/* 13B5F8 802482B8 30420FFF */  andi      $v0, $v0, 0xfff
/* 13B5FC 802482BC 00021300 */  sll       $v0, $v0, 0xc
/* 13B600 802482C0 4600018D */  trunc.w.s $f6, $f0
/* 13B604 802482C4 44033000 */  mfc1      $v1, $f6
/* 13B608 802482C8 00000000 */  nop
/* 13B60C 802482CC 30630FFF */  andi      $v1, $v1, 0xfff
/* 13B610 802482D0 00431025 */  or        $v0, $v0, $v1
/* 13B614 802482D4 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 13B618 802482D8 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 13B61C 802482DC ACA20004 */  sw        $v0, 4($a1)
/* 13B620 802482E0 24020002 */  addiu     $v0, $zero, 2
/* 13B624 802482E4 1462002A */  bne       $v1, $v0, .L80248390
/* 13B628 802482E8 24020001 */   addiu    $v0, $zero, 1
/* 13B62C 802482EC 3C038027 */  lui       $v1, %hi(gBadgeMenuLevel)
/* 13B630 802482F0 8C630398 */  lw        $v1, %lo(gBadgeMenuLevel)($v1)
/* 13B634 802482F4 14620026 */  bne       $v1, $v0, .L80248390
/* 13B638 802482F8 00000000 */   nop
/* 13B63C 802482FC 3C118027 */  lui       $s1, %hi(gBadgeMenuCurrentPage)
/* 13B640 80248300 26310280 */  addiu     $s1, $s1, %lo(gBadgeMenuCurrentPage)
/* 13B644 80248304 8E220000 */  lw        $v0, ($s1)
/* 13B648 80248308 1840000E */  blez      $v0, .L80248344
/* 13B64C 8024830C 24420001 */   addiu    $v0, $v0, 1
/* 13B650 80248310 3C108027 */  lui       $s0, %hi(gBadgeMenuIconIDs)
/* 13B654 80248314 261003A8 */  addiu     $s0, $s0, %lo(gBadgeMenuIconIDs)
/* 13B658 80248318 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B65C 8024831C 8E040044 */  lw        $a0, 0x44($s0)
/* 13B660 80248320 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13B664 80248324 25650116 */  addiu     $a1, $t3, 0x116
/* 13B668 80248328 0C051261 */  jal       set_hud_element_render_pos
/* 13B66C 8024832C 2546000E */   addiu    $a2, $t2, 0xe
/* 13B670 80248330 8E040044 */  lw        $a0, 0x44($s0)
/* 13B674 80248334 0C0511F8 */  jal       draw_hud_element_3
/* 13B678 80248338 00000000 */   nop
/* 13B67C 8024833C 8E220000 */  lw        $v0, ($s1)
/* 13B680 80248340 24420001 */  addiu     $v0, $v0, 1
.L80248344:
/* 13B684 80248344 00021840 */  sll       $v1, $v0, 1
/* 13B688 80248348 00621821 */  addu      $v1, $v1, $v0
/* 13B68C 8024834C 00031880 */  sll       $v1, $v1, 2
/* 13B690 80248350 3C028027 */  lui       $v0, %hi(gBadgeMenuPages)
/* 13B694 80248354 00431021 */  addu      $v0, $v0, $v1
/* 13B698 80248358 90420288 */  lbu       $v0, %lo(gBadgeMenuPages)($v0)
/* 13B69C 8024835C 1040000C */  beqz      $v0, .L80248390
/* 13B6A0 80248360 00000000 */   nop
/* 13B6A4 80248364 3C108027 */  lui       $s0, %hi(gBadgeMenuIconIDs)
/* 13B6A8 80248368 261003A8 */  addiu     $s0, $s0, %lo(gBadgeMenuIconIDs)
/* 13B6AC 8024836C 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B6B0 80248370 8E040048 */  lw        $a0, 0x48($s0)
/* 13B6B4 80248374 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13B6B8 80248378 25650116 */  addiu     $a1, $t3, 0x116
/* 13B6BC 8024837C 0C051261 */  jal       set_hud_element_render_pos
/* 13B6C0 80248380 25460092 */   addiu    $a2, $t2, 0x92
/* 13B6C4 80248384 8E040048 */  lw        $a0, 0x48($s0)
/* 13B6C8 80248388 0C0511F8 */  jal       draw_hud_element_3
/* 13B6CC 8024838C 00000000 */   nop
.L80248390:
/* 13B6D0 80248390 3C108027 */  lui       $s0, %hi(gBadgeMenuIconIDs)
/* 13B6D4 80248394 261003A8 */  addiu     $s0, $s0, %lo(gBadgeMenuIconIDs)
/* 13B6D8 80248398 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B6DC 8024839C 8E040040 */  lw        $a0, 0x40($s0)
/* 13B6E0 802483A0 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13B6E4 802483A4 2565002B */  addiu     $a1, $t3, 0x2b
/* 13B6E8 802483A8 0C051261 */  jal       set_hud_element_render_pos
/* 13B6EC 802483AC 25460051 */   addiu    $a2, $t2, 0x51
/* 13B6F0 802483B0 8E040040 */  lw        $a0, 0x40($s0)
/* 13B6F4 802483B4 0C0511F8 */  jal       draw_hud_element_3
/* 13B6F8 802483B8 2413000A */   addiu    $s3, $zero, 0xa
/* 13B6FC 802483BC 0C093BA0 */  jal       pause_get_menu_msg
/* 13B700 802483C0 24040046 */   addiu    $a0, $zero, 0x46
/* 13B704 802483C4 0040202D */  daddu     $a0, $v0, $zero
/* 13B708 802483C8 240700FF */  addiu     $a3, $zero, 0xff
/* 13B70C 802483CC 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B710 802483D0 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13B714 802483D4 24020001 */  addiu     $v0, $zero, 1
/* 13B718 802483D8 AFB30010 */  sw        $s3, 0x10($sp)
/* 13B71C 802483DC AFA20014 */  sw        $v0, 0x14($sp)
/* 13B720 802483E0 25650010 */  addiu     $a1, $t3, 0x10
/* 13B724 802483E4 2550004A */  addiu     $s0, $t2, 0x4a
/* 13B728 802483E8 0C04993B */  jal       draw_msg
/* 13B72C 802483EC 0200302D */   daddu    $a2, $s0, $zero
/* 13B730 802483F0 0200302D */  daddu     $a2, $s0, $zero
/* 13B734 802483F4 24070001 */  addiu     $a3, $zero, 1
/* 13B738 802483F8 241500FF */  addiu     $s5, $zero, 0xff
/* 13B73C 802483FC 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B740 80248400 3C048011 */  lui       $a0, %hi(gPlayerData+0x8)
/* 13B744 80248404 8084F298 */  lb        $a0, %lo(gPlayerData+0x8)($a0)
/* 13B748 80248408 24140003 */  addiu     $s4, $zero, 3
/* 13B74C 8024840C AFB30010 */  sw        $s3, 0x10($sp)
/* 13B750 80248410 AFB50014 */  sw        $s5, 0x14($sp)
/* 13B754 80248414 AFB40018 */  sw        $s4, 0x18($sp)
/* 13B758 80248418 0C049DA7 */  jal       draw_number
/* 13B75C 8024841C 25650045 */   addiu    $a1, $t3, 0x45
/* 13B760 80248420 0C0911FD */  jal       pause_get_total_equipped_bp_cost
/* 13B764 80248424 0000902D */   daddu    $s2, $zero, $zero
/* 13B768 80248428 3C056666 */  lui       $a1, 0x6666
/* 13B76C 8024842C 3C048011 */  lui       $a0, %hi(gPlayerData+0x8)
/* 13B770 80248430 8084F298 */  lb        $a0, %lo(gPlayerData+0x8)($a0)
/* 13B774 80248434 34A56667 */  ori       $a1, $a1, 0x6667
/* 13B778 80248438 2483FFFF */  addiu     $v1, $a0, -1
/* 13B77C 8024843C 00650018 */  mult      $v1, $a1
/* 13B780 80248440 00828823 */  subu      $s1, $a0, $v0
/* 13B784 80248444 00031FC3 */  sra       $v1, $v1, 0x1f
/* 13B788 80248448 00005010 */  mfhi      $t2
/* 13B78C 8024844C 000A1083 */  sra       $v0, $t2, 2
/* 13B790 80248450 00431023 */  subu      $v0, $v0, $v1
/* 13B794 80248454 02828004 */  sllv      $s0, $v0, $s4
/* 13B798 80248458 0233102A */  slt       $v0, $s1, $s3
/* 13B79C 8024845C 54400001 */  bnel      $v0, $zero, .L80248464
/* 13B7A0 80248460 2412FFFC */   addiu    $s2, $zero, -4
.L80248464:
/* 13B7A4 80248464 24040007 */  addiu     $a0, $zero, 7
/* 13B7A8 80248468 26100064 */  addiu     $s0, $s0, 0x64
/* 13B7AC 8024846C 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B7B0 80248470 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13B7B4 80248474 2565000C */  addiu     $a1, $t3, 0xc
/* 13B7B8 80248478 01508021 */  addu      $s0, $t2, $s0
/* 13B7BC 8024847C 0C093BA5 */  jal       pause_draw_menu_label
/* 13B7C0 80248480 0200302D */   daddu    $a2, $s0, $zero
/* 13B7C4 80248484 0220202D */  daddu     $a0, $s1, $zero
/* 13B7C8 80248488 26450049 */  addiu     $a1, $s2, 0x49
/* 13B7CC 8024848C 0200302D */  daddu     $a2, $s0, $zero
/* 13B7D0 80248490 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B7D4 80248494 24070001 */  addiu     $a3, $zero, 1
/* 13B7D8 80248498 AFB30010 */  sw        $s3, 0x10($sp)
/* 13B7DC 8024849C AFB50014 */  sw        $s5, 0x14($sp)
/* 13B7E0 802484A0 AFB40018 */  sw        $s4, 0x18($sp)
/* 13B7E4 802484A4 0C049DA7 */  jal       draw_number
/* 13B7E8 802484A8 01652821 */   addu     $a1, $t3, $a1
/* 13B7EC 802484AC 3C05E300 */  lui       $a1, 0xe300
/* 13B7F0 802484B0 34A51201 */  ori       $a1, $a1, 0x1201
/* 13B7F4 802484B4 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 13B7F8 802484B8 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 13B7FC 802484BC 0000882D */  daddu     $s1, $zero, $zero
/* 13B800 802484C0 3C02DE00 */  lui       $v0, 0xde00
/* 13B804 802484C4 0220B02D */  daddu     $s6, $s1, $zero
/* 13B808 802484C8 8CC30000 */  lw        $v1, ($a2)
/* 13B80C 802484CC 241700FF */  addiu     $s7, $zero, 0xff
/* 13B810 802484D0 0060202D */  daddu     $a0, $v1, $zero
/* 13B814 802484D4 24630008 */  addiu     $v1, $v1, 8
/* 13B818 802484D8 ACC30000 */  sw        $v1, ($a2)
/* 13B81C 802484DC 3C108011 */  lui       $s0, %hi(gPlayerData+0x8)
/* 13B820 802484E0 8210F298 */  lb        $s0, %lo(gPlayerData+0x8)($s0)
/* 13B824 802484E4 241E0064 */  addiu     $fp, $zero, 0x64
/* 13B828 802484E8 AC820000 */  sw        $v0, ($a0)
/* 13B82C 802484EC 3C028027 */  lui       $v0, %hi(D_8026F348)
/* 13B830 802484F0 2442F348 */  addiu     $v0, $v0, %lo(D_8026F348)
/* 13B834 802484F4 AC820004 */  sw        $v0, 4($a0)
/* 13B838 802484F8 24620008 */  addiu     $v0, $v1, 8
/* 13B83C 802484FC ACC20000 */  sw        $v0, ($a2)
/* 13B840 80248500 24022000 */  addiu     $v0, $zero, 0x2000
/* 13B844 80248504 AC650000 */  sw        $a1, ($v1)
/* 13B848 80248508 1A000026 */  blez      $s0, .L802485A4
/* 13B84C 8024850C AC620004 */   sw       $v0, 4($v1)
/* 13B850 80248510 00C0902D */  daddu     $s2, $a2, $zero
/* 13B854 80248514 3C15FA00 */  lui       $s5, 0xfa00
/* 13B858 80248518 3C14E3E3 */  lui       $s4, 0xe3e3
/* 13B85C 8024851C 3694E3FF */  ori       $s4, $s4, 0xe3ff
/* 13B860 80248520 3C136666 */  lui       $s3, 0x6666
/* 13B864 80248524 36736667 */  ori       $s3, $s3, 0x6667
/* 13B868 80248528 0000202D */  daddu     $a0, $zero, $zero
.L8024852C:
/* 13B86C 8024852C 8E420000 */  lw        $v0, ($s2)
/* 13B870 80248530 02330018 */  mult      $s1, $s3
/* 13B874 80248534 0040182D */  daddu     $v1, $v0, $zero
/* 13B878 80248538 24420008 */  addiu     $v0, $v0, 8
/* 13B87C 8024853C AE420000 */  sw        $v0, ($s2)
/* 13B880 80248540 001117C3 */  sra       $v0, $s1, 0x1f
/* 13B884 80248544 AC750000 */  sw        $s5, ($v1)
/* 13B888 80248548 AC740004 */  sw        $s4, 4($v1)
/* 13B88C 8024854C 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B890 80248550 00005010 */  mfhi      $t2
/* 13B894 80248554 000A3083 */  sra       $a2, $t2, 2
/* 13B898 80248558 00C23023 */  subu      $a2, $a2, $v0
/* 13B89C 8024855C 00061080 */  sll       $v0, $a2, 2
/* 13B8A0 80248560 00461021 */  addu      $v0, $v0, $a2
/* 13B8A4 80248564 00021040 */  sll       $v0, $v0, 1
/* 13B8A8 80248568 02221023 */  subu      $v0, $s1, $v0
/* 13B8AC 8024856C 00022840 */  sll       $a1, $v0, 1
/* 13B8B0 80248570 00A22821 */  addu      $a1, $a1, $v0
/* 13B8B4 80248574 00052840 */  sll       $a1, $a1, 1
/* 13B8B8 80248578 24A5000B */  addiu     $a1, $a1, 0xb
/* 13B8BC 8024857C 01652821 */  addu      $a1, $t3, $a1
/* 13B8C0 80248580 000630C0 */  sll       $a2, $a2, 3
/* 13B8C4 80248584 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13B8C8 80248588 24C6005C */  addiu     $a2, $a2, 0x5c
/* 13B8CC 8024858C 0C091D16 */  jal       pause_badges_draw_bp_orbs
/* 13B8D0 80248590 01463021 */   addu     $a2, $t2, $a2
/* 13B8D4 80248594 26310001 */  addiu     $s1, $s1, 1
/* 13B8D8 80248598 0230102A */  slt       $v0, $s1, $s0
/* 13B8DC 8024859C 1440FFE3 */  bnez      $v0, .L8024852C
/* 13B8E0 802485A0 0000202D */   daddu    $a0, $zero, $zero
.L802485A4:
/* 13B8E4 802485A4 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 13B8E8 802485A8 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 13B8EC 802485AC 8CA40000 */  lw        $a0, ($a1)
/* 13B8F0 802485B0 3C02E700 */  lui       $v0, 0xe700
/* 13B8F4 802485B4 0080182D */  daddu     $v1, $a0, $zero
/* 13B8F8 802485B8 24840008 */  addiu     $a0, $a0, 8
/* 13B8FC 802485BC ACA40000 */  sw        $a0, ($a1)
/* 13B900 802485C0 AC620000 */  sw        $v0, ($v1)
/* 13B904 802485C4 AC600004 */  sw        $zero, 4($v1)
/* 13B908 802485C8 8FAB0074 */  lw        $t3, 0x74($sp)
/* 13B90C 802485CC 11600089 */  beqz      $t3, .L802487F4
/* 13B910 802485D0 24820008 */   addiu    $v0, $a0, 8
/* 13B914 802485D4 ACA20000 */  sw        $v0, ($a1)
/* 13B918 802485D8 3C02FA00 */  lui       $v0, 0xfa00
/* 13B91C 802485DC AC820000 */  sw        $v0, ($a0)
/* 13B920 802485E0 00171400 */  sll       $v0, $s7, 0x10
/* 13B924 802485E4 001E1A00 */  sll       $v1, $fp, 8
/* 13B928 802485E8 00431025 */  or        $v0, $v0, $v1
/* 13B92C 802485EC 344200FF */  ori       $v0, $v0, 0xff
/* 13B930 802485F0 AC820004 */  sw        $v0, 4($a0)
/* 13B934 802485F4 8FAA006C */  lw        $t2, 0x6c($sp)
/* 13B938 802485F8 8FAB0070 */  lw        $t3, 0x70($sp)
/* 13B93C 802485FC 014B1023 */  subu      $v0, $t2, $t3
/* 13B940 80248600 1840001D */  blez      $v0, .L80248678
/* 13B944 80248604 0000882D */   daddu    $s1, $zero, $zero
/* 13B948 80248608 3C126666 */  lui       $s2, 0x6666
/* 13B94C 8024860C 36526667 */  ori       $s2, $s2, 0x6667
/* 13B950 80248610 0040802D */  daddu     $s0, $v0, $zero
/* 13B954 80248614 02320018 */  mult      $s1, $s2
.L80248618:
/* 13B958 80248618 24040002 */  addiu     $a0, $zero, 2
/* 13B95C 8024861C 001117C3 */  sra       $v0, $s1, 0x1f
/* 13B960 80248620 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13B964 80248624 00005010 */  mfhi      $t2
/* 13B968 80248628 008A3007 */  srav      $a2, $t2, $a0
/* 13B96C 8024862C 00C23023 */  subu      $a2, $a2, $v0
/* 13B970 80248630 00861004 */  sllv      $v0, $a2, $a0
/* 13B974 80248634 00461021 */  addu      $v0, $v0, $a2
/* 13B978 80248638 00021040 */  sll       $v0, $v0, 1
/* 13B97C 8024863C 02221023 */  subu      $v0, $s1, $v0
/* 13B980 80248640 00022840 */  sll       $a1, $v0, 1
/* 13B984 80248644 00A22821 */  addu      $a1, $a1, $v0
/* 13B988 80248648 00052840 */  sll       $a1, $a1, 1
/* 13B98C 8024864C 24A5000B */  addiu     $a1, $a1, 0xb
/* 13B990 80248650 01652821 */  addu      $a1, $t3, $a1
/* 13B994 80248654 000630C0 */  sll       $a2, $a2, 3
/* 13B998 80248658 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13B99C 8024865C 24C6005C */  addiu     $a2, $a2, 0x5c
/* 13B9A0 80248660 0C091D16 */  jal       pause_badges_draw_bp_orbs
/* 13B9A4 80248664 01463021 */   addu     $a2, $t2, $a2
/* 13B9A8 80248668 26310001 */  addiu     $s1, $s1, 1
/* 13B9AC 8024866C 0230102A */  slt       $v0, $s1, $s0
/* 13B9B0 80248670 1440FFE9 */  bnez      $v0, .L80248618
/* 13B9B4 80248674 02320018 */   mult     $s1, $s2
.L80248678:
/* 13B9B8 80248678 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 13B9BC 8024867C 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 13B9C0 80248680 3C02E700 */  lui       $v0, 0xe700
/* 13B9C4 80248684 8E030000 */  lw        $v1, ($s0)
/* 13B9C8 80248688 8FAB006C */  lw        $t3, 0x6c($sp)
/* 13B9CC 8024868C 8FAA0070 */  lw        $t2, 0x70($sp)
/* 13B9D0 80248690 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* 13B9D4 80248694 8CA5419C */  lw        $a1, %lo(gGameStatusPtr)($a1)
/* 13B9D8 80248698 016A8823 */  subu      $s1, $t3, $t2
/* 13B9DC 8024869C 0060202D */  daddu     $a0, $v1, $zero
/* 13B9E0 802486A0 AC820000 */  sw        $v0, ($a0)
/* 13B9E4 802486A4 AC800004 */  sw        $zero, 4($a0)
/* 13B9E8 802486A8 94A40134 */  lhu       $a0, 0x134($a1)
/* 13B9EC 802486AC 24630008 */  addiu     $v1, $v1, 8
/* 13B9F0 802486B0 00041100 */  sll       $v0, $a0, 4
/* 13B9F4 802486B4 00441023 */  subu      $v0, $v0, $a0
/* 13B9F8 802486B8 44826000 */  mtc1      $v0, $f12
/* 13B9FC 802486BC 00000000 */  nop
/* 13BA00 802486C0 46806320 */  cvt.s.w   $f12, $f12
/* 13BA04 802486C4 0C00A8BB */  jal       sin_deg
/* 13BA08 802486C8 AE030000 */   sw       $v1, ($s0)
/* 13BA0C 802486CC 3C04E200 */  lui       $a0, 0xe200
/* 13BA10 802486D0 3484001C */  ori       $a0, $a0, 0x1c
/* 13BA14 802486D4 3C030050 */  lui       $v1, 0x50
/* 13BA18 802486D8 34634340 */  ori       $v1, $v1, 0x4340
/* 13BA1C 802486DC 3C013F80 */  lui       $at, 0x3f80
/* 13BA20 802486E0 44811000 */  mtc1      $at, $f2
/* 13BA24 802486E4 8E050000 */  lw        $a1, ($s0)
/* 13BA28 802486E8 46020000 */  add.s     $f0, $f0, $f2
/* 13BA2C 802486EC 00A0102D */  daddu     $v0, $a1, $zero
/* 13BA30 802486F0 3C018027 */  lui       $at, %hi(D_8026FFB0)
/* 13BA34 802486F4 D422FFB0 */  ldc1      $f2, %lo(D_8026FFB0)($at)
/* 13BA38 802486F8 46000021 */  cvt.d.s   $f0, $f0
/* 13BA3C 802486FC 46220002 */  mul.d     $f0, $f0, $f2
/* 13BA40 80248700 00000000 */  nop
/* 13BA44 80248704 24A50008 */  addiu     $a1, $a1, 8
/* 13BA48 80248708 AE050000 */  sw        $a1, ($s0)
/* 13BA4C 8024870C AC440000 */  sw        $a0, ($v0)
/* 13BA50 80248710 AC430004 */  sw        $v1, 4($v0)
/* 13BA54 80248714 3C013FE0 */  lui       $at, 0x3fe0
/* 13BA58 80248718 44811800 */  mtc1      $at, $f3
/* 13BA5C 8024871C 44801000 */  mtc1      $zero, $f2
/* 13BA60 80248720 24A20008 */  addiu     $v0, $a1, 8
/* 13BA64 80248724 AE020000 */  sw        $v0, ($s0)
/* 13BA68 80248728 46220000 */  add.d     $f0, $f0, $f2
/* 13BA6C 8024872C 3C02FA00 */  lui       $v0, 0xfa00
/* 13BA70 80248730 3C01437F */  lui       $at, 0x437f
/* 13BA74 80248734 44811000 */  mtc1      $at, $f2
/* 13BA78 80248738 46200020 */  cvt.s.d   $f0, $f0
/* 13BA7C 8024873C 46020002 */  mul.s     $f0, $f0, $f2
/* 13BA80 80248740 00000000 */  nop
/* 13BA84 80248744 ACA20000 */  sw        $v0, ($a1)
/* 13BA88 80248748 00171400 */  sll       $v0, $s7, 0x10
/* 13BA8C 8024874C 001E1A00 */  sll       $v1, $fp, 8
/* 13BA90 80248750 00431025 */  or        $v0, $v0, $v1
/* 13BA94 80248754 4600018D */  trunc.w.s $f6, $f0
/* 13BA98 80248758 44043000 */  mfc1      $a0, $f6
/* 13BA9C 8024875C 00000000 */  nop
/* 13BAA0 80248760 308400FF */  andi      $a0, $a0, 0xff
/* 13BAA4 80248764 00441025 */  or        $v0, $v0, $a0
/* 13BAA8 80248768 ACA20004 */  sw        $v0, 4($a1)
/* 13BAAC 8024876C 8FAB006C */  lw        $t3, 0x6c($sp)
/* 13BAB0 80248770 022B102A */  slt       $v0, $s1, $t3
/* 13BAB4 80248774 10400046 */  beqz      $v0, .L80248890
/* 13BAB8 80248778 00000000 */   nop
/* 13BABC 8024877C 3C106666 */  lui       $s0, 0x6666
/* 13BAC0 80248780 36106667 */  ori       $s0, $s0, 0x6667
/* 13BAC4 80248784 02300018 */  mult      $s1, $s0
.L80248788:
/* 13BAC8 80248788 24040002 */  addiu     $a0, $zero, 2
/* 13BACC 8024878C 001117C3 */  sra       $v0, $s1, 0x1f
/* 13BAD0 80248790 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13BAD4 80248794 00005010 */  mfhi      $t2
/* 13BAD8 80248798 008A3007 */  srav      $a2, $t2, $a0
/* 13BADC 8024879C 00C23023 */  subu      $a2, $a2, $v0
/* 13BAE0 802487A0 00861004 */  sllv      $v0, $a2, $a0
/* 13BAE4 802487A4 00461021 */  addu      $v0, $v0, $a2
/* 13BAE8 802487A8 00021040 */  sll       $v0, $v0, 1
/* 13BAEC 802487AC 02221023 */  subu      $v0, $s1, $v0
/* 13BAF0 802487B0 00022840 */  sll       $a1, $v0, 1
/* 13BAF4 802487B4 00A22821 */  addu      $a1, $a1, $v0
/* 13BAF8 802487B8 00052840 */  sll       $a1, $a1, 1
/* 13BAFC 802487BC 24A5000B */  addiu     $a1, $a1, 0xb
/* 13BB00 802487C0 01652821 */  addu      $a1, $t3, $a1
/* 13BB04 802487C4 000630C0 */  sll       $a2, $a2, 3
/* 13BB08 802487C8 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13BB0C 802487CC 24C6005C */  addiu     $a2, $a2, 0x5c
/* 13BB10 802487D0 0C091D16 */  jal       pause_badges_draw_bp_orbs
/* 13BB14 802487D4 01463021 */   addu     $a2, $t2, $a2
/* 13BB18 802487D8 8FAB006C */  lw        $t3, 0x6c($sp)
/* 13BB1C 802487DC 26310001 */  addiu     $s1, $s1, 1
/* 13BB20 802487E0 022B102A */  slt       $v0, $s1, $t3
/* 13BB24 802487E4 1440FFE8 */  bnez      $v0, .L80248788
/* 13BB28 802487E8 02300018 */   mult     $s1, $s0
/* 13BB2C 802487EC 08092224 */  j         .L80248890
/* 13BB30 802487F0 00000000 */   nop
.L802487F4:
/* 13BB34 802487F4 ACA20000 */  sw        $v0, ($a1)
/* 13BB38 802487F8 3C02FA00 */  lui       $v0, 0xfa00
/* 13BB3C 802487FC AC820000 */  sw        $v0, ($a0)
/* 13BB40 80248800 00171400 */  sll       $v0, $s7, 0x10
/* 13BB44 80248804 001E1A00 */  sll       $v1, $fp, 8
/* 13BB48 80248808 00431025 */  or        $v0, $v0, $v1
/* 13BB4C 8024880C 344200FF */  ori       $v0, $v0, 0xff
/* 13BB50 80248810 AC820004 */  sw        $v0, 4($a0)
/* 13BB54 80248814 8FAA006C */  lw        $t2, 0x6c($sp)
/* 13BB58 80248818 1940001D */  blez      $t2, .L80248890
/* 13BB5C 8024881C 0000882D */   daddu    $s1, $zero, $zero
/* 13BB60 80248820 3C106666 */  lui       $s0, 0x6666
/* 13BB64 80248824 36106667 */  ori       $s0, $s0, 0x6667
/* 13BB68 80248828 02300018 */  mult      $s1, $s0
.L8024882C:
/* 13BB6C 8024882C 24040002 */  addiu     $a0, $zero, 2
/* 13BB70 80248830 001117C3 */  sra       $v0, $s1, 0x1f
/* 13BB74 80248834 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13BB78 80248838 00005010 */  mfhi      $t2
/* 13BB7C 8024883C 008A3007 */  srav      $a2, $t2, $a0
/* 13BB80 80248840 00C23023 */  subu      $a2, $a2, $v0
/* 13BB84 80248844 00861004 */  sllv      $v0, $a2, $a0
/* 13BB88 80248848 00461021 */  addu      $v0, $v0, $a2
/* 13BB8C 8024884C 00021040 */  sll       $v0, $v0, 1
/* 13BB90 80248850 02221023 */  subu      $v0, $s1, $v0
/* 13BB94 80248854 00022840 */  sll       $a1, $v0, 1
/* 13BB98 80248858 00A22821 */  addu      $a1, $a1, $v0
/* 13BB9C 8024885C 00052840 */  sll       $a1, $a1, 1
/* 13BBA0 80248860 24A5000B */  addiu     $a1, $a1, 0xb
/* 13BBA4 80248864 01652821 */  addu      $a1, $t3, $a1
/* 13BBA8 80248868 000630C0 */  sll       $a2, $a2, 3
/* 13BBAC 8024886C 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13BBB0 80248870 24C6005C */  addiu     $a2, $a2, 0x5c
/* 13BBB4 80248874 0C091D16 */  jal       pause_badges_draw_bp_orbs
/* 13BBB8 80248878 01463021 */   addu     $a2, $t2, $a2
/* 13BBBC 8024887C 8FAB006C */  lw        $t3, 0x6c($sp)
/* 13BBC0 80248880 26310001 */  addiu     $s1, $s1, 1
/* 13BBC4 80248884 022B102A */  slt       $v0, $s1, $t3
/* 13BBC8 80248888 1440FFE8 */  bnez      $v0, .L8024882C
/* 13BBCC 8024888C 02300018 */   mult     $s1, $s0
.L80248890:
/* 13BBD0 80248890 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 13BBD4 80248894 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 13BBD8 80248898 8C620000 */  lw        $v0, ($v1)
/* 13BBDC 8024889C 0040202D */  daddu     $a0, $v0, $zero
/* 13BBE0 802488A0 24420008 */  addiu     $v0, $v0, 8
/* 13BBE4 802488A4 AC620000 */  sw        $v0, ($v1)
/* 13BBE8 802488A8 3C02E700 */  lui       $v0, 0xe700
/* 13BBEC 802488AC AC820000 */  sw        $v0, ($a0)
/* 13BBF0 802488B0 AC800004 */  sw        $zero, 4($a0)
/* 13BBF4 802488B4 3C038027 */  lui       $v1, %hi(gBadgeMenuCurrentTab)
/* 13BBF8 802488B8 8C63039C */  lw        $v1, %lo(gBadgeMenuCurrentTab)($v1)
/* 13BBFC 802488BC 8FA600C4 */  lw        $a2, 0xc4($sp)
/* 13BC00 802488C0 50600001 */  beql      $v1, $zero, .L802488C8
/* 13BC04 802488C4 24C60009 */   addiu    $a2, $a2, 9
.L802488C8:
/* 13BC08 802488C8 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13BC0C 802488CC 2402005B */  addiu     $v0, $zero, 0x5b
/* 13BC10 802488D0 AFA20014 */  sw        $v0, 0x14($sp)
/* 13BC14 802488D4 24020022 */  addiu     $v0, $zero, 0x22
/* 13BC18 802488D8 AFA20018 */  sw        $v0, 0x18($sp)
/* 13BC1C 802488DC 240200FF */  addiu     $v0, $zero, 0xff
/* 13BC20 802488E0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 13BC24 802488E4 24020001 */  addiu     $v0, $zero, 1
/* 13BC28 802488E8 AFA00010 */  sw        $zero, 0x10($sp)
/* 13BC2C 802488EC 14620004 */  bne       $v1, $v0, .L80248900
/* 13BC30 802488F0 25470007 */   addiu    $a3, $t2, 7
/* 13BC34 802488F4 24020080 */  addiu     $v0, $zero, 0x80
/* 13BC38 802488F8 08092241 */  j         .L80248904
/* 13BC3C 802488FC AFA20020 */   sw       $v0, 0x20($sp)
.L80248900:
/* 13BC40 80248900 AFA00020 */  sw        $zero, 0x20($sp)
.L80248904:
/* 13BC44 80248904 24040004 */  addiu     $a0, $zero, 4
/* 13BC48 80248908 3C058027 */  lui       $a1, %hi(D_8026FBD8)
/* 13BC4C 8024890C 24A5FBD8 */  addiu     $a1, $a1, %lo(D_8026FBD8)
/* 13BC50 80248910 24020140 */  addiu     $v0, $zero, 0x140
/* 13BC54 80248914 AFA20044 */  sw        $v0, 0x44($sp)
/* 13BC58 80248918 240200F0 */  addiu     $v0, $zero, 0xf0
/* 13BC5C 8024891C AFA00024 */  sw        $zero, 0x24($sp)
/* 13BC60 80248920 AFA00028 */  sw        $zero, 0x28($sp)
/* 13BC64 80248924 AFA0002C */  sw        $zero, 0x2c($sp)
/* 13BC68 80248928 AFA00030 */  sw        $zero, 0x30($sp)
/* 13BC6C 8024892C AFA00034 */  sw        $zero, 0x34($sp)
/* 13BC70 80248930 AFA00038 */  sw        $zero, 0x38($sp)
/* 13BC74 80248934 AFA0003C */  sw        $zero, 0x3c($sp)
/* 13BC78 80248938 AFA00040 */  sw        $zero, 0x40($sp)
/* 13BC7C 8024893C AFA20048 */  sw        $v0, 0x48($sp)
/* 13BC80 80248940 0C03D4B8 */  jal       draw_box
/* 13BC84 80248944 AFA0004C */   sw       $zero, 0x4c($sp)
/* 13BC88 80248948 0C093BA0 */  jal       pause_get_menu_msg
/* 13BC8C 8024894C 24040047 */   addiu    $a0, $zero, 0x47
/* 13BC90 80248950 3C118027 */  lui       $s1, %hi(gBadgeMenuCurrentTab)
/* 13BC94 80248954 2631039C */  addiu     $s1, $s1, %lo(gBadgeMenuCurrentTab)
/* 13BC98 80248958 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13BC9C 8024895C 8E230000 */  lw        $v1, ($s1)
/* 13BCA0 80248960 14600002 */  bnez      $v1, .L8024896C
/* 13BCA4 80248964 2565000A */   addiu    $a1, $t3, 0xa
/* 13BCA8 80248968 25650013 */  addiu     $a1, $t3, 0x13
.L8024896C:
/* 13BCAC 8024896C 240700FF */  addiu     $a3, $zero, 0xff
/* 13BCB0 80248970 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13BCB4 80248974 24100001 */  addiu     $s0, $zero, 1
/* 13BCB8 80248978 14700002 */  bne       $v1, $s0, .L80248984
/* 13BCBC 8024897C 25460011 */   addiu    $a2, $t2, 0x11
/* 13BCC0 80248980 240700BF */  addiu     $a3, $zero, 0xbf
.L80248984:
/* 13BCC4 80248984 0040202D */  daddu     $a0, $v0, $zero
/* 13BCC8 80248988 AFA00010 */  sw        $zero, 0x10($sp)
/* 13BCCC 8024898C 0C04993B */  jal       draw_msg
/* 13BCD0 80248990 AFB00014 */   sw       $s0, 0x14($sp)
/* 13BCD4 80248994 8E230000 */  lw        $v1, ($s1)
/* 13BCD8 80248998 8FA600C4 */  lw        $a2, 0xc4($sp)
/* 13BCDC 8024899C 50700001 */  beql      $v1, $s0, .L802489A4
/* 13BCE0 802489A0 24C60009 */   addiu    $a2, $a2, 9
.L802489A4:
/* 13BCE4 802489A4 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13BCE8 802489A8 2402005B */  addiu     $v0, $zero, 0x5b
/* 13BCEC 802489AC AFA20014 */  sw        $v0, 0x14($sp)
/* 13BCF0 802489B0 24020022 */  addiu     $v0, $zero, 0x22
/* 13BCF4 802489B4 AFA20018 */  sw        $v0, 0x18($sp)
/* 13BCF8 802489B8 240200FF */  addiu     $v0, $zero, 0xff
/* 13BCFC 802489BC AFA00010 */  sw        $zero, 0x10($sp)
/* 13BD00 802489C0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 13BD04 802489C4 14600004 */  bnez      $v1, .L802489D8
/* 13BD08 802489C8 25670025 */   addiu    $a3, $t3, 0x25
/* 13BD0C 802489CC 24020080 */  addiu     $v0, $zero, 0x80
/* 13BD10 802489D0 08092277 */  j         .L802489DC
/* 13BD14 802489D4 AFA20020 */   sw       $v0, 0x20($sp)
.L802489D8:
/* 13BD18 802489D8 AFA00020 */  sw        $zero, 0x20($sp)
.L802489DC:
/* 13BD1C 802489DC 24040004 */  addiu     $a0, $zero, 4
/* 13BD20 802489E0 3C058027 */  lui       $a1, %hi(D_8026FBD8)
/* 13BD24 802489E4 24A5FBD8 */  addiu     $a1, $a1, %lo(D_8026FBD8)
/* 13BD28 802489E8 24020140 */  addiu     $v0, $zero, 0x140
/* 13BD2C 802489EC AFA20044 */  sw        $v0, 0x44($sp)
/* 13BD30 802489F0 240200F0 */  addiu     $v0, $zero, 0xf0
/* 13BD34 802489F4 AFA00024 */  sw        $zero, 0x24($sp)
/* 13BD38 802489F8 AFA00028 */  sw        $zero, 0x28($sp)
/* 13BD3C 802489FC AFA0002C */  sw        $zero, 0x2c($sp)
/* 13BD40 80248A00 AFA00030 */  sw        $zero, 0x30($sp)
/* 13BD44 80248A04 AFA00034 */  sw        $zero, 0x34($sp)
/* 13BD48 80248A08 AFA00038 */  sw        $zero, 0x38($sp)
/* 13BD4C 80248A0C AFA0003C */  sw        $zero, 0x3c($sp)
/* 13BD50 80248A10 AFA00040 */  sw        $zero, 0x40($sp)
/* 13BD54 80248A14 AFA20048 */  sw        $v0, 0x48($sp)
/* 13BD58 80248A18 0C03D4B8 */  jal       draw_box
/* 13BD5C 80248A1C AFA0004C */   sw       $zero, 0x4c($sp)
/* 13BD60 80248A20 0C093BA0 */  jal       pause_get_menu_msg
/* 13BD64 80248A24 24040048 */   addiu    $a0, $zero, 0x48
/* 13BD68 80248A28 3C118027 */  lui       $s1, %hi(gBadgeMenuCurrentTab)
/* 13BD6C 80248A2C 2631039C */  addiu     $s1, $s1, %lo(gBadgeMenuCurrentTab)
/* 13BD70 80248A30 24100001 */  addiu     $s0, $zero, 1
/* 13BD74 80248A34 8FAA00C4 */  lw        $t2, 0xc4($sp)
/* 13BD78 80248A38 8E230000 */  lw        $v1, ($s1)
/* 13BD7C 80248A3C 14700002 */  bne       $v1, $s0, .L80248A48
/* 13BD80 80248A40 2545000C */   addiu    $a1, $t2, 0xc
/* 13BD84 80248A44 25450015 */  addiu     $a1, $t2, 0x15
.L80248A48:
/* 13BD88 80248A48 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13BD8C 80248A4C 240700FF */  addiu     $a3, $zero, 0xff
/* 13BD90 80248A50 14600002 */  bnez      $v1, .L80248A5C
/* 13BD94 80248A54 2566002A */   addiu    $a2, $t3, 0x2a
/* 13BD98 80248A58 240700BF */  addiu     $a3, $zero, 0xbf
.L80248A5C:
/* 13BD9C 80248A5C 0040202D */  daddu     $a0, $v0, $zero
/* 13BDA0 80248A60 AFA00010 */  sw        $zero, 0x10($sp)
/* 13BDA4 80248A64 0C04993B */  jal       draw_msg
/* 13BDA8 80248A68 AFB00014 */   sw       $s0, 0x14($sp)
/* 13BDAC 80248A6C 0C093BA0 */  jal       pause_get_menu_msg
/* 13BDB0 80248A70 24040049 */   addiu    $a0, $zero, 0x49
/* 13BDB4 80248A74 8FAA00C4 */  lw        $t2, 0xc4($sp)
/* 13BDB8 80248A78 8E230000 */  lw        $v1, ($s1)
/* 13BDBC 80248A7C 14700002 */  bne       $v1, $s0, .L80248A88
/* 13BDC0 80248A80 2545001A */   addiu    $a1, $t2, 0x1a
/* 13BDC4 80248A84 25450023 */  addiu     $a1, $t2, 0x23
.L80248A88:
/* 13BDC8 80248A88 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13BDCC 80248A8C 240700FF */  addiu     $a3, $zero, 0xff
/* 13BDD0 80248A90 14600002 */  bnez      $v1, .L80248A9C
/* 13BDD4 80248A94 25660034 */   addiu    $a2, $t3, 0x34
/* 13BDD8 80248A98 240700BF */  addiu     $a3, $zero, 0xbf
.L80248A9C:
/* 13BDDC 80248A9C 0040202D */  daddu     $a0, $v0, $zero
/* 13BDE0 80248AA0 AFA00010 */  sw        $zero, 0x10($sp)
/* 13BDE4 80248AA4 0C04993B */  jal       draw_msg
/* 13BDE8 80248AA8 AFB00014 */   sw       $s0, 0x14($sp)
/* 13BDEC 80248AAC 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 13BDF0 80248AB0 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 13BDF4 80248AB4 24020002 */  addiu     $v0, $zero, 2
/* 13BDF8 80248AB8 14620050 */  bne       $v1, $v0, .L80248BFC
/* 13BDFC 80248ABC 00000000 */   nop
/* 13BE00 80248AC0 3C028027 */  lui       $v0, %hi(gBadgeMenuLevel)
/* 13BE04 80248AC4 8C420398 */  lw        $v0, %lo(gBadgeMenuLevel)($v0)
/* 13BE08 80248AC8 14400009 */  bnez      $v0, .L80248AF0
/* 13BE0C 80248ACC 24040020 */   addiu    $a0, $zero, 0x20
/* 13BE10 80248AD0 8E260000 */  lw        $a2, ($s1)
/* 13BE14 80248AD4 8FAA00C4 */  lw        $t2, 0xc4($sp)
/* 13BE18 80248AD8 8FAB00C8 */  lw        $t3, 0xc8($sp)
/* 13BE1C 80248ADC 2545000A */  addiu     $a1, $t2, 0xa
/* 13BE20 80248AE0 00063140 */  sll       $a2, $a2, 5
/* 13BE24 80248AE4 24C6001A */  addiu     $a2, $a2, 0x1a
/* 13BE28 80248AE8 080922FD */  j         .L80248BF4
/* 13BE2C 80248AEC 01663021 */   addu     $a2, $t3, $a2
.L80248AF0:
/* 13BE30 80248AF0 3C118027 */  lui       $s1, %hi(gBadgeMenuCurrentPage)
/* 13BE34 80248AF4 26310280 */  addiu     $s1, $s1, %lo(gBadgeMenuCurrentPage)
/* 13BE38 80248AF8 8E240000 */  lw        $a0, ($s1)
/* 13BE3C 80248AFC 3C128027 */  lui       $s2, %hi(gBadgeMenuPages)
/* 13BE40 80248B00 26520288 */  addiu     $s2, $s2, %lo(gBadgeMenuPages)
/* 13BE44 80248B04 00041040 */  sll       $v0, $a0, 1
/* 13BE48 80248B08 00441021 */  addu      $v0, $v0, $a0
/* 13BE4C 80248B0C 00021080 */  sll       $v0, $v0, 2
/* 13BE50 80248B10 00521021 */  addu      $v0, $v0, $s2
/* 13BE54 80248B14 90430001 */  lbu       $v1, 1($v0)
/* 13BE58 80248B18 90420002 */  lbu       $v0, 2($v0)
/* 13BE5C 80248B1C 00620018 */  mult      $v1, $v0
/* 13BE60 80248B20 3C108027 */  lui       $s0, %hi(gBadgeMenuSelectedIndex)
/* 13BE64 80248B24 26100378 */  addiu     $s0, $s0, %lo(gBadgeMenuSelectedIndex)
/* 13BE68 80248B28 8E050000 */  lw        $a1, ($s0)
/* 13BE6C 80248B2C 00005012 */  mflo      $t2
/* 13BE70 80248B30 0C091C43 */  jal       pause_badges_get_pos_x
/* 13BE74 80248B34 00AA2823 */   subu     $a1, $a1, $t2
/* 13BE78 80248B38 8E240000 */  lw        $a0, ($s1)
/* 13BE7C 80248B3C 00041840 */  sll       $v1, $a0, 1
/* 13BE80 80248B40 00641821 */  addu      $v1, $v1, $a0
/* 13BE84 80248B44 00031880 */  sll       $v1, $v1, 2
/* 13BE88 80248B48 00721821 */  addu      $v1, $v1, $s2
/* 13BE8C 80248B4C 90650001 */  lbu       $a1, 1($v1)
/* 13BE90 80248B50 90630002 */  lbu       $v1, 2($v1)
/* 13BE94 80248B54 00A30018 */  mult      $a1, $v1
/* 13BE98 80248B58 8E050000 */  lw        $a1, ($s0)
/* 13BE9C 80248B5C 0040802D */  daddu     $s0, $v0, $zero
/* 13BEA0 80248B60 00005012 */  mflo      $t2
/* 13BEA4 80248B64 0C091C5A */  jal       pause_badges_get_pos_y
/* 13BEA8 80248B68 00AA2823 */   subu     $a1, $a1, $t2
/* 13BEAC 80248B6C 0200202D */  daddu     $a0, $s0, $zero
/* 13BEB0 80248B70 0C091CAA */  jal       pause_badges_scroll_offset_x
/* 13BEB4 80248B74 0040802D */   daddu    $s0, $v0, $zero
/* 13BEB8 80248B78 0200202D */  daddu     $a0, $s0, $zero
/* 13BEBC 80248B7C 0C091CA6 */  jal       pause_badges_scroll_offset_y
/* 13BEC0 80248B80 0040802D */   daddu    $s0, $v0, $zero
/* 13BEC4 80248B84 0040302D */  daddu     $a2, $v0, $zero
/* 13BEC8 80248B88 04C10003 */  bgez      $a2, .L80248B98
/* 13BECC 80248B8C 28C20071 */   slti     $v0, $a2, 0x71
/* 13BED0 80248B90 080922E8 */  j         .L80248BA0
/* 13BED4 80248B94 0000302D */   daddu    $a2, $zero, $zero
.L80248B98:
/* 13BED8 80248B98 50400001 */  beql      $v0, $zero, .L80248BA0
/* 13BEDC 80248B9C 24060070 */   addiu    $a2, $zero, 0x70
.L80248BA0:
/* 13BEE0 80248BA0 3C038027 */  lui       $v1, %hi(gBadgeMenuCurrentScrollPos)
/* 13BEE4 80248BA4 8C63038C */  lw        $v1, %lo(gBadgeMenuCurrentScrollPos)($v1)
/* 13BEE8 80248BA8 3C028027 */  lui       $v0, %hi(gBadgeMenuTargetScrollPos)
/* 13BEEC 80248BAC 8C420390 */  lw        $v0, %lo(gBadgeMenuTargetScrollPos)($v0)
/* 13BEF0 80248BB0 1062000A */  beq       $v1, $v0, .L80248BDC
/* 13BEF4 80248BB4 24040020 */   addiu    $a0, $zero, 0x20
/* 13BEF8 80248BB8 2605005D */  addiu     $a1, $s0, 0x5d
/* 13BEFC 80248BBC 24C60017 */  addiu     $a2, $a2, 0x17
/* 13BF00 80248BC0 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13BF04 80248BC4 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13BF08 80248BC8 01652821 */  addu      $a1, $t3, $a1
/* 13BF0C 80248BCC 0C090AEB */  jal       func_80242BAC
/* 13BF10 80248BD0 01463021 */   addu     $a2, $t2, $a2
/* 13BF14 80248BD4 080922FF */  j         .L80248BFC
/* 13BF18 80248BD8 00000000 */   nop
.L80248BDC:
/* 13BF1C 80248BDC 2605005D */  addiu     $a1, $s0, 0x5d
/* 13BF20 80248BE0 24C60017 */  addiu     $a2, $a2, 0x17
/* 13BF24 80248BE4 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13BF28 80248BE8 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13BF2C 80248BEC 01652821 */  addu      $a1, $t3, $a1
/* 13BF30 80248BF0 01463021 */  addu      $a2, $t2, $a2
.L80248BF4:
/* 13BF34 80248BF4 0C090B41 */  jal       func_80242D04
/* 13BF38 80248BF8 00000000 */   nop
.L80248BFC:
/* 13BF3C 80248BFC 3C108027 */  lui       $s0, %hi(gBadgeMenuBShowNotEnoughBP)
/* 13BF40 80248C00 261003A0 */  addiu     $s0, $s0, %lo(gBadgeMenuBShowNotEnoughBP)
/* 13BF44 80248C04 8E020000 */  lw        $v0, ($s0)
/* 13BF48 80248C08 10400054 */  beqz      $v0, .L80248D5C
/* 13BF4C 80248C0C 00000000 */   nop
/* 13BF50 80248C10 0C090AE8 */  jal       pause_set_cursor_opacity
/* 13BF54 80248C14 0000202D */   daddu    $a0, $zero, $zero
/* 13BF58 80248C18 8E020000 */  lw        $v0, ($s0)
/* 13BF5C 80248C1C 24100001 */  addiu     $s0, $zero, 1
/* 13BF60 80248C20 14500027 */  bne       $v0, $s0, .L80248CC0
/* 13BF64 80248C24 24040004 */   addiu    $a0, $zero, 4
/* 13BF68 80248C28 3C058027 */  lui       $a1, %hi(D_8026FBD8)
/* 13BF6C 80248C2C 24A5FBD8 */  addiu     $a1, $a1, %lo(D_8026FBD8)
/* 13BF70 80248C30 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13BF74 80248C34 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13BF78 80248C38 24020089 */  addiu     $v0, $zero, 0x89
/* 13BF7C 80248C3C AFA20014 */  sw        $v0, 0x14($sp)
/* 13BF80 80248C40 2402001A */  addiu     $v0, $zero, 0x1a
/* 13BF84 80248C44 AFA20018 */  sw        $v0, 0x18($sp)
/* 13BF88 80248C48 240200FF */  addiu     $v0, $zero, 0xff
/* 13BF8C 80248C4C AFA2001C */  sw        $v0, 0x1c($sp)
/* 13BF90 80248C50 24020140 */  addiu     $v0, $zero, 0x140
/* 13BF94 80248C54 AFA20044 */  sw        $v0, 0x44($sp)
/* 13BF98 80248C58 240200F0 */  addiu     $v0, $zero, 0xf0
/* 13BF9C 80248C5C AFA00010 */  sw        $zero, 0x10($sp)
/* 13BFA0 80248C60 AFA00020 */  sw        $zero, 0x20($sp)
/* 13BFA4 80248C64 AFA00024 */  sw        $zero, 0x24($sp)
/* 13BFA8 80248C68 AFA00028 */  sw        $zero, 0x28($sp)
/* 13BFAC 80248C6C AFA0002C */  sw        $zero, 0x2c($sp)
/* 13BFB0 80248C70 AFA00030 */  sw        $zero, 0x30($sp)
/* 13BFB4 80248C74 AFA00034 */  sw        $zero, 0x34($sp)
/* 13BFB8 80248C78 AFA00038 */  sw        $zero, 0x38($sp)
/* 13BFBC 80248C7C AFA0003C */  sw        $zero, 0x3c($sp)
/* 13BFC0 80248C80 AFA00040 */  sw        $zero, 0x40($sp)
/* 13BFC4 80248C84 AFA20048 */  sw        $v0, 0x48($sp)
/* 13BFC8 80248C88 AFA0004C */  sw        $zero, 0x4c($sp)
/* 13BFCC 80248C8C 25660043 */  addiu     $a2, $t3, 0x43
/* 13BFD0 80248C90 0C03D4B8 */  jal       draw_box
/* 13BFD4 80248C94 2547003C */   addiu    $a3, $t2, 0x3c
/* 13BFD8 80248C98 0C093BA0 */  jal       pause_get_menu_msg
/* 13BFDC 80248C9C 2404004A */   addiu    $a0, $zero, 0x4a
/* 13BFE0 80248CA0 0040202D */  daddu     $a0, $v0, $zero
/* 13BFE4 80248CA4 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13BFE8 80248CA8 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13BFEC 80248CAC 240700FF */  addiu     $a3, $zero, 0xff
/* 13BFF0 80248CB0 AFA00010 */  sw        $zero, 0x10($sp)
/* 13BFF4 80248CB4 AFB00014 */  sw        $s0, 0x14($sp)
/* 13BFF8 80248CB8 08092355 */  j         .L80248D54
/* 13BFFC 80248CBC 25650056 */   addiu    $a1, $t3, 0x56
.L80248CC0:
/* 13C000 80248CC0 3C058027 */  lui       $a1, %hi(D_8026FBD8)
/* 13C004 80248CC4 24A5FBD8 */  addiu     $a1, $a1, %lo(D_8026FBD8)
/* 13C008 80248CC8 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13C00C 80248CCC 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13C010 80248CD0 240200AD */  addiu     $v0, $zero, 0xad
/* 13C014 80248CD4 AFA20014 */  sw        $v0, 0x14($sp)
/* 13C018 80248CD8 2402001A */  addiu     $v0, $zero, 0x1a
/* 13C01C 80248CDC AFA20018 */  sw        $v0, 0x18($sp)
/* 13C020 80248CE0 240200FF */  addiu     $v0, $zero, 0xff
/* 13C024 80248CE4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 13C028 80248CE8 24020140 */  addiu     $v0, $zero, 0x140
/* 13C02C 80248CEC AFA20044 */  sw        $v0, 0x44($sp)
/* 13C030 80248CF0 240200F0 */  addiu     $v0, $zero, 0xf0
/* 13C034 80248CF4 AFA00010 */  sw        $zero, 0x10($sp)
/* 13C038 80248CF8 AFA00020 */  sw        $zero, 0x20($sp)
/* 13C03C 80248CFC AFA00024 */  sw        $zero, 0x24($sp)
/* 13C040 80248D00 AFA00028 */  sw        $zero, 0x28($sp)
/* 13C044 80248D04 AFA0002C */  sw        $zero, 0x2c($sp)
/* 13C048 80248D08 AFA00030 */  sw        $zero, 0x30($sp)
/* 13C04C 80248D0C AFA00034 */  sw        $zero, 0x34($sp)
/* 13C050 80248D10 AFA00038 */  sw        $zero, 0x38($sp)
/* 13C054 80248D14 AFA0003C */  sw        $zero, 0x3c($sp)
/* 13C058 80248D18 AFA00040 */  sw        $zero, 0x40($sp)
/* 13C05C 80248D1C AFA20048 */  sw        $v0, 0x48($sp)
/* 13C060 80248D20 AFA0004C */  sw        $zero, 0x4c($sp)
/* 13C064 80248D24 25660043 */  addiu     $a2, $t3, 0x43
/* 13C068 80248D28 0C03D4B8 */  jal       draw_box
/* 13C06C 80248D2C 2547003C */   addiu    $a3, $t2, 0x3c
/* 13C070 80248D30 0C093BA0 */  jal       pause_get_menu_msg
/* 13C074 80248D34 2404004B */   addiu    $a0, $zero, 0x4b
/* 13C078 80248D38 0040202D */  daddu     $a0, $v0, $zero
/* 13C07C 80248D3C 8FAB00C4 */  lw        $t3, 0xc4($sp)
/* 13C080 80248D40 8FAA00C8 */  lw        $t2, 0xc8($sp)
/* 13C084 80248D44 240700FF */  addiu     $a3, $zero, 0xff
/* 13C088 80248D48 AFA00010 */  sw        $zero, 0x10($sp)
/* 13C08C 80248D4C AFB00014 */  sw        $s0, 0x14($sp)
/* 13C090 80248D50 2565005A */  addiu     $a1, $t3, 0x5a
.L80248D54:
/* 13C094 80248D54 0C04993B */  jal       draw_msg
/* 13C098 80248D58 25460042 */   addiu    $a2, $t2, 0x42
.L80248D5C:
/* 13C09C 80248D5C 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 13C0A0 80248D60 8FBE00B8 */  lw        $fp, 0xb8($sp)
/* 13C0A4 80248D64 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 13C0A8 80248D68 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 13C0AC 80248D6C 8FB500AC */  lw        $s5, 0xac($sp)
/* 13C0B0 80248D70 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 13C0B4 80248D74 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 13C0B8 80248D78 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 13C0BC 80248D7C 8FB1009C */  lw        $s1, 0x9c($sp)
/* 13C0C0 80248D80 8FB00098 */  lw        $s0, 0x98($sp)
/* 13C0C4 80248D84 03E00008 */  jr        $ra
/* 13C0C8 80248D88 27BD00C0 */   addiu    $sp, $sp, 0xc0
