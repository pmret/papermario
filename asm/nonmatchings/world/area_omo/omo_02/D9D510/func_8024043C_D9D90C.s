.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024043C_D9D90C
/* D9D90C 8024043C 27BDFEB0 */  addiu     $sp, $sp, -0x150
/* D9D910 80240440 AFB70134 */  sw        $s7, 0x134($sp)
/* D9D914 80240444 AFBF013C */  sw        $ra, 0x13c($sp)
/* D9D918 80240448 AFBE0138 */  sw        $fp, 0x138($sp)
/* D9D91C 8024044C AFB60130 */  sw        $s6, 0x130($sp)
/* D9D920 80240450 AFB5012C */  sw        $s5, 0x12c($sp)
/* D9D924 80240454 AFB40128 */  sw        $s4, 0x128($sp)
/* D9D928 80240458 AFB30124 */  sw        $s3, 0x124($sp)
/* D9D92C 8024045C AFB20120 */  sw        $s2, 0x120($sp)
/* D9D930 80240460 AFB1011C */  sw        $s1, 0x11c($sp)
/* D9D934 80240464 AFB00118 */  sw        $s0, 0x118($sp)
/* D9D938 80240468 F7B60148 */  sdc1      $f22, 0x148($sp)
/* D9D93C 8024046C F7B40140 */  sdc1      $f20, 0x140($sp)
/* D9D940 80240470 10A0007E */  beqz      $a1, .L8024066C
/* D9D944 80240474 0080B82D */   daddu    $s7, $a0, $zero
/* D9D948 80240478 0C00AB39 */  jal       heap_malloc
/* D9D94C 8024047C 24040690 */   addiu    $a0, $zero, 0x690
/* D9D950 80240480 0000982D */  daddu     $s3, $zero, $zero
/* D9D954 80240484 AEE20070 */  sw        $v0, 0x70($s7)
/* D9D958 80240488 0040882D */  daddu     $s1, $v0, $zero
/* D9D95C 8024048C 3C148024 */  lui       $s4, 0x8024
/* D9D960 80240490 26943580 */  addiu     $s4, $s4, 0x3580
/* D9D964 80240494 3C014120 */  lui       $at, 0x4120
/* D9D968 80240498 4481A000 */  mtc1      $at, $f20
/* D9D96C 8024049C 26300088 */  addiu     $s0, $s1, 0x88
/* D9D970 802404A0 AEE00074 */  sw        $zero, 0x74($s7)
.L802404A4:
/* D9D974 802404A4 8E820000 */  lw        $v0, ($s4)
/* D9D978 802404A8 AE02FFB8 */  sw        $v0, -0x48($s0)
/* D9D97C 802404AC 0040202D */  daddu     $a0, $v0, $zero
/* D9D980 802404B0 00131080 */  sll       $v0, $s3, 2
/* D9D984 802404B4 3C018024 */  lui       $at, 0x8024
/* D9D988 802404B8 00220821 */  addu      $at, $at, $v0
/* D9D98C 802404BC 8C2235B0 */  lw        $v0, 0x35b0($at)
/* D9D990 802404C0 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D9D994 802404C4 AE02FFBC */   sw       $v0, -0x44($s0)
/* D9D998 802404C8 0C046B4C */  jal       get_model_from_list_index
/* D9D99C 802404CC 0040202D */   daddu    $a0, $v0, $zero
/* D9D9A0 802404D0 0040902D */  daddu     $s2, $v0, $zero
/* D9D9A4 802404D4 AE200000 */  sw        $zero, ($s1)
/* D9D9A8 802404D8 C6400098 */  lwc1      $f0, 0x98($s2)
/* D9D9AC 802404DC E600FF7C */  swc1      $f0, -0x84($s0)
/* D9D9B0 802404E0 C640009C */  lwc1      $f0, 0x9c($s2)
/* D9D9B4 802404E4 E600FF80 */  swc1      $f0, -0x80($s0)
/* D9D9B8 802404E8 C64000A0 */  lwc1      $f0, 0xa0($s2)
/* D9D9BC 802404EC C602FF80 */  lwc1      $f2, -0x80($s0)
/* D9D9C0 802404F0 E600FF84 */  swc1      $f0, -0x7c($s0)
/* D9D9C4 802404F4 C600FF7C */  lwc1      $f0, -0x84($s0)
/* D9D9C8 802404F8 C604FF84 */  lwc1      $f4, -0x7c($s0)
/* D9D9CC 802404FC 24040014 */  addiu     $a0, $zero, 0x14
/* D9D9D0 80240500 AE00FF94 */  sw        $zero, -0x6c($s0)
/* D9D9D4 80240504 AE00FF98 */  sw        $zero, -0x68($s0)
/* D9D9D8 80240508 AE00FF9C */  sw        $zero, -0x64($s0)
/* D9D9DC 8024050C E602FF8C */  swc1      $f2, -0x74($s0)
/* D9D9E0 80240510 E600FF88 */  swc1      $f0, -0x78($s0)
/* D9D9E4 80240514 0C00A67F */  jal       rand_int
/* D9D9E8 80240518 E604FF90 */   swc1     $f4, -0x70($s0)
/* D9D9EC 8024051C 24040014 */  addiu     $a0, $zero, 0x14
/* D9D9F0 80240520 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D9D9F4 80240524 44820000 */  mtc1      $v0, $f0
/* D9D9F8 80240528 00000000 */  nop       
/* D9D9FC 8024052C 46800020 */  cvt.s.w   $f0, $f0
/* D9DA00 80240530 0C00A67F */  jal       rand_int
/* D9DA04 80240534 E600FFA0 */   swc1     $f0, -0x60($s0)
/* D9DA08 80240538 24040014 */  addiu     $a0, $zero, 0x14
/* D9DA0C 8024053C 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D9DA10 80240540 44820000 */  mtc1      $v0, $f0
/* D9DA14 80240544 00000000 */  nop       
/* D9DA18 80240548 46800020 */  cvt.s.w   $f0, $f0
/* D9DA1C 8024054C 0C00A67F */  jal       rand_int
/* D9DA20 80240550 E600FFA4 */   swc1     $f0, -0x5c($s0)
/* D9DA24 80240554 24040028 */  addiu     $a0, $zero, 0x28
/* D9DA28 80240558 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D9DA2C 8024055C 44820000 */  mtc1      $v0, $f0
/* D9DA30 80240560 00000000 */  nop       
/* D9DA34 80240564 46800020 */  cvt.s.w   $f0, $f0
/* D9DA38 80240568 0C00A67F */  jal       rand_int
/* D9DA3C 8024056C E600FFA8 */   swc1     $f0, -0x58($s0)
/* D9DA40 80240570 3C0142C8 */  lui       $at, 0x42c8
/* D9DA44 80240574 44811000 */  mtc1      $at, $f2
/* D9DA48 80240578 44820000 */  mtc1      $v0, $f0
/* D9DA4C 8024057C 00000000 */  nop       
/* D9DA50 80240580 46800020 */  cvt.s.w   $f0, $f0
/* D9DA54 80240584 46020000 */  add.s     $f0, $f0, $f2
/* D9DA58 80240588 2404001E */  addiu     $a0, $zero, 0x1e
/* D9DA5C 8024058C 46140003 */  div.s     $f0, $f0, $f20
/* D9DA60 80240590 0C00A67F */  jal       rand_int
/* D9DA64 80240594 E600FFAC */   swc1     $f0, -0x54($s0)
/* D9DA68 80240598 3C014270 */  lui       $at, 0x4270
/* D9DA6C 8024059C 44811000 */  mtc1      $at, $f2
/* D9DA70 802405A0 44820000 */  mtc1      $v0, $f0
/* D9DA74 802405A4 00000000 */  nop       
/* D9DA78 802405A8 46800020 */  cvt.s.w   $f0, $f0
/* D9DA7C 802405AC 46020000 */  add.s     $f0, $f0, $f2
/* D9DA80 802405B0 24040064 */  addiu     $a0, $zero, 0x64
/* D9DA84 802405B4 46140003 */  div.s     $f0, $f0, $f20
/* D9DA88 802405B8 0C00A67F */  jal       rand_int
/* D9DA8C 802405BC E600FFB0 */   swc1     $f0, -0x50($s0)
/* D9DA90 802405C0 00021FC2 */  srl       $v1, $v0, 0x1f
/* D9DA94 802405C4 00431821 */  addu      $v1, $v0, $v1
/* D9DA98 802405C8 00031843 */  sra       $v1, $v1, 1
/* D9DA9C 802405CC 00031840 */  sll       $v1, $v1, 1
/* D9DAA0 802405D0 00431023 */  subu      $v0, $v0, $v1
/* D9DAA4 802405D4 3C014334 */  lui       $at, 0x4334
/* D9DAA8 802405D8 44811000 */  mtc1      $at, $f2
/* D9DAAC 802405DC 44820000 */  mtc1      $v0, $f0
/* D9DAB0 802405E0 00000000 */  nop       
/* D9DAB4 802405E4 46800020 */  cvt.s.w   $f0, $f0
/* D9DAB8 802405E8 46020002 */  mul.s     $f0, $f0, $f2
/* D9DABC 802405EC 00000000 */  nop       
/* D9DAC0 802405F0 3C0142B4 */  lui       $at, 0x42b4
/* D9DAC4 802405F4 44811000 */  mtc1      $at, $f2
/* D9DAC8 802405F8 00000000 */  nop       
/* D9DACC 802405FC 46020000 */  add.s     $f0, $f0, $f2
/* D9DAD0 80240600 E600FFB4 */  swc1      $f0, -0x4c($s0)
/* D9DAD4 80240604 8E420008 */  lw        $v0, 8($s2)
/* D9DAD8 80240608 8C420004 */  lw        $v0, 4($v0)
/* D9DADC 8024060C 8C440000 */  lw        $a0, ($v0)
/* D9DAE0 80240610 0C0900B0 */  jal       func_802402C0_D9D790
/* D9DAE4 80240614 0200282D */   daddu    $a1, $s0, $zero
/* D9DAE8 80240618 0000302D */  daddu     $a2, $zero, $zero
/* D9DAEC 8024061C 0000282D */  daddu     $a1, $zero, $zero
.L80240620:
/* D9DAF0 80240620 00062100 */  sll       $a0, $a2, 4
.L80240624:
/* D9DAF4 80240624 02241821 */  addu      $v1, $s1, $a0
/* D9DAF8 80240628 02441021 */  addu      $v0, $s2, $a0
/* D9DAFC 8024062C 24840004 */  addiu     $a0, $a0, 4
/* D9DB00 80240630 24A50001 */  addiu     $a1, $a1, 1
/* D9DB04 80240634 C4400058 */  lwc1      $f0, 0x58($v0)
/* D9DB08 80240638 28A20004 */  slti      $v0, $a1, 4
/* D9DB0C 8024063C 1440FFF9 */  bnez      $v0, .L80240624
/* D9DB10 80240640 E4600048 */   swc1     $f0, 0x48($v1)
/* D9DB14 80240644 24C60001 */  addiu     $a2, $a2, 1
/* D9DB18 80240648 28C20004 */  slti      $v0, $a2, 4
/* D9DB1C 8024064C 1440FFF4 */  bnez      $v0, .L80240620
/* D9DB20 80240650 0000282D */   daddu    $a1, $zero, $zero
/* D9DB24 80240654 26940004 */  addiu     $s4, $s4, 4
/* D9DB28 80240658 26730001 */  addiu     $s3, $s3, 1
/* D9DB2C 8024065C 2610008C */  addiu     $s0, $s0, 0x8c
/* D9DB30 80240660 2E62000C */  sltiu     $v0, $s3, 0xc
/* D9DB34 80240664 1440FF8F */  bnez      $v0, .L802404A4
/* D9DB38 80240668 2631008C */   addiu    $s1, $s1, 0x8c
.L8024066C:
/* D9DB3C 8024066C 0000982D */  daddu     $s3, $zero, $zero
/* D9DB40 80240670 241E0064 */  addiu     $fp, $zero, 0x64
/* D9DB44 80240674 27B50058 */  addiu     $s5, $sp, 0x58
/* D9DB48 80240678 27B40098 */  addiu     $s4, $sp, 0x98
/* D9DB4C 8024067C 27B600D8 */  addiu     $s6, $sp, 0xd8
/* D9DB50 80240680 8EF10070 */  lw        $s1, 0x70($s7)
/* D9DB54 80240684 4480A000 */  mtc1      $zero, $f20
/* D9DB58 80240688 3C013F80 */  lui       $at, 0x3f80
/* D9DB5C 8024068C 4481B000 */  mtc1      $at, $f22
/* D9DB60 80240690 26300024 */  addiu     $s0, $s1, 0x24
.L80240694:
/* D9DB64 80240694 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D9DB68 80240698 8E04001C */   lw       $a0, 0x1c($s0)
/* D9DB6C 8024069C 0C046B4C */  jal       get_model_from_list_index
/* D9DB70 802406A0 0040202D */   daddu    $a0, $v0, $zero
/* D9DB74 802406A4 8E230000 */  lw        $v1, ($s1)
/* D9DB78 802406A8 107E0036 */  beq       $v1, $fp, .L80240784
/* D9DB7C 802406AC 0040902D */   daddu    $s2, $v0, $zero
/* D9DB80 802406B0 28620065 */  slti      $v0, $v1, 0x65
/* D9DB84 802406B4 1040003C */  beqz      $v0, .L802407A8
/* D9DB88 802406B8 0000302D */   daddu    $a2, $zero, $zero
/* D9DB8C 802406BC 1460003B */  bnez      $v1, .L802407AC
/* D9DB90 802406C0 0000282D */   daddu    $a1, $zero, $zero
/* D9DB94 802406C4 26240004 */  addiu     $a0, $s1, 4
/* D9DB98 802406C8 8E060014 */  lw        $a2, 0x14($s0)
/* D9DB9C 802406CC 8E070018 */  lw        $a3, 0x18($s0)
/* D9DBA0 802406D0 0C00A7E7 */  jal       add_vec2D_polar
/* D9DBA4 802406D4 2625000C */   addiu    $a1, $s1, 0xc
/* D9DBA8 802406D8 C6020010 */  lwc1      $f2, 0x10($s0)
/* D9DBAC 802406DC 3C013F4C */  lui       $at, 0x3f4c
/* D9DBB0 802406E0 3421CCCD */  ori       $at, $at, 0xcccd
/* D9DBB4 802406E4 44810000 */  mtc1      $at, $f0
/* D9DBB8 802406E8 00000000 */  nop       
/* D9DBBC 802406EC 46001081 */  sub.s     $f2, $f2, $f0
/* D9DBC0 802406F0 C600FFE4 */  lwc1      $f0, -0x1c($s0)
/* D9DBC4 802406F4 E6020010 */  swc1      $f2, 0x10($s0)
/* D9DBC8 802406F8 46020080 */  add.s     $f2, $f0, $f2
/* D9DBCC 802406FC C6000010 */  lwc1      $f0, 0x10($s0)
/* D9DBD0 80240700 4614003E */  c.le.s    $f0, $f20
/* D9DBD4 80240704 00000000 */  nop       
/* D9DBD8 80240708 45000026 */  bc1f      .L802407A4
/* D9DBDC 8024070C E602FFE4 */   swc1     $f2, -0x1c($s0)
/* D9DBE0 80240710 C6040064 */  lwc1      $f4, 0x64($s0)
/* D9DBE4 80240714 46802120 */  cvt.s.w   $f4, $f4
/* D9DBE8 80240718 4604103C */  c.lt.s    $f2, $f4
/* D9DBEC 8024071C 00000000 */  nop       
/* D9DBF0 80240720 45000020 */  bc1f      .L802407A4
/* D9DBF4 80240724 46000086 */   mov.s    $f2, $f0
/* D9DBF8 80240728 3C01BF33 */  lui       $at, 0xbf33
/* D9DBFC 8024072C 34213333 */  ori       $at, $at, 0x3333
/* D9DC00 80240730 44810000 */  mtc1      $at, $f0
/* D9DC04 80240734 00000000 */  nop       
/* D9DC08 80240738 46001082 */  mul.s     $f2, $f2, $f0
/* D9DC0C 8024073C 00000000 */  nop       
/* D9DC10 80240740 E604FFE4 */  swc1      $f4, -0x1c($s0)
/* D9DC14 80240744 4616103C */  c.lt.s    $f2, $f22
/* D9DC18 80240748 00000000 */  nop       
/* D9DC1C 8024074C 45000005 */  bc1f      .L80240764
/* D9DC20 80240750 E6020010 */   swc1     $f2, 0x10($s0)
/* D9DC24 80240754 AE3E0000 */  sw        $fp, ($s1)
/* D9DC28 80240758 E6140004 */  swc1      $f20, 4($s0)
/* D9DC2C 8024075C E6140008 */  swc1      $f20, 8($s0)
/* D9DC30 80240760 E614000C */  swc1      $f20, 0xc($s0)
.L80240764:
/* D9DC34 80240764 32620001 */  andi      $v0, $s3, 1
/* D9DC38 80240768 1040000E */  beqz      $v0, .L802407A4
/* D9DC3C 8024076C 0000202D */   daddu    $a0, $zero, $zero
/* D9DC40 80240770 0080282D */  daddu     $a1, $a0, $zero
/* D9DC44 80240774 0C0B2D5B */  jal       exec_ShakeCam1
/* D9DC48 80240778 24060001 */   addiu    $a2, $zero, 1
/* D9DC4C 8024077C 080901EA */  j         .L802407A8
/* D9DC50 80240780 0000302D */   daddu    $a2, $zero, $zero
.L80240784:
/* D9DC54 80240784 86040022 */  lh        $a0, 0x22($s0)
/* D9DC58 80240788 0C016E89 */  jal       update_collider_transform
/* D9DC5C 8024078C 00000000 */   nop      
/* D9DC60 80240790 8EE20074 */  lw        $v0, 0x74($s7)
/* D9DC64 80240794 24420001 */  addiu     $v0, $v0, 1
/* D9DC68 80240798 AEE20074 */  sw        $v0, 0x74($s7)
/* D9DC6C 8024079C 24020065 */  addiu     $v0, $zero, 0x65
/* D9DC70 802407A0 AE220000 */  sw        $v0, ($s1)
.L802407A4:
/* D9DC74 802407A4 0000302D */  daddu     $a2, $zero, $zero
.L802407A8:
/* D9DC78 802407A8 0000282D */  daddu     $a1, $zero, $zero
.L802407AC:
/* D9DC7C 802407AC 00062100 */  sll       $a0, $a2, 4
.L802407B0:
/* D9DC80 802407B0 02441821 */  addu      $v1, $s2, $a0
/* D9DC84 802407B4 02241021 */  addu      $v0, $s1, $a0
/* D9DC88 802407B8 24840004 */  addiu     $a0, $a0, 4
/* D9DC8C 802407BC 24A50001 */  addiu     $a1, $a1, 1
/* D9DC90 802407C0 C4400048 */  lwc1      $f0, 0x48($v0)
/* D9DC94 802407C4 28A20004 */  slti      $v0, $a1, 4
/* D9DC98 802407C8 1440FFF9 */  bnez      $v0, .L802407B0
/* D9DC9C 802407CC E4600058 */   swc1     $f0, 0x58($v1)
/* D9DCA0 802407D0 24C60001 */  addiu     $a2, $a2, 1
/* D9DCA4 802407D4 28C20004 */  slti      $v0, $a2, 4
/* D9DCA8 802407D8 1440FFF4 */  bnez      $v0, .L802407AC
/* D9DCAC 802407DC 0000282D */   daddu    $a1, $zero, $zero
/* D9DCB0 802407E0 96420000 */  lhu       $v0, ($s2)
/* D9DCB4 802407E4 34421400 */  ori       $v0, $v0, 0x1400
/* D9DCB8 802407E8 A6420000 */  sh        $v0, ($s2)
/* D9DCBC 802407EC C602FFE0 */  lwc1      $f2, -0x20($s0)
/* D9DCC0 802407F0 C600FFEC */  lwc1      $f0, -0x14($s0)
/* D9DCC4 802407F4 46001081 */  sub.s     $f2, $f2, $f0
/* D9DCC8 802407F8 C600FFF0 */  lwc1      $f0, -0x10($s0)
/* D9DCCC 802407FC 44051000 */  mfc1      $a1, $f2
/* D9DCD0 80240800 C602FFE4 */  lwc1      $f2, -0x1c($s0)
/* D9DCD4 80240804 46001081 */  sub.s     $f2, $f2, $f0
/* D9DCD8 80240808 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* D9DCDC 8024080C 44061000 */  mfc1      $a2, $f2
/* D9DCE0 80240810 C602FFE8 */  lwc1      $f2, -0x18($s0)
/* D9DCE4 80240814 46001081 */  sub.s     $f2, $f2, $f0
/* D9DCE8 80240818 44071000 */  mfc1      $a3, $f2
/* D9DCEC 8024081C 0C019E40 */  jal       guTranslateF
/* D9DCF0 80240820 27A40018 */   addiu    $a0, $sp, 0x18
/* D9DCF4 80240824 C602FFF8 */  lwc1      $f2, -8($s0)
/* D9DCF8 80240828 C6000004 */  lwc1      $f0, 4($s0)
/* D9DCFC 8024082C C604FFFC */  lwc1      $f4, -4($s0)
/* D9DD00 80240830 46001080 */  add.s     $f2, $f2, $f0
/* D9DD04 80240834 C6000008 */  lwc1      $f0, 8($s0)
/* D9DD08 80240838 46002100 */  add.s     $f4, $f4, $f0
/* D9DD0C 8024083C C6000000 */  lwc1      $f0, ($s0)
/* D9DD10 80240840 E602FFF8 */  swc1      $f2, -8($s0)
/* D9DD14 80240844 C602000C */  lwc1      $f2, 0xc($s0)
/* D9DD18 80240848 C60CFFF8 */  lwc1      $f12, -8($s0)
/* D9DD1C 8024084C 46020000 */  add.s     $f0, $f0, $f2
/* D9DD20 80240850 E604FFFC */  swc1      $f4, -4($s0)
/* D9DD24 80240854 0C00A6C9 */  jal       clamp_angle
/* D9DD28 80240858 E6000000 */   swc1     $f0, ($s0)
/* D9DD2C 8024085C C60CFFFC */  lwc1      $f12, -4($s0)
/* D9DD30 80240860 26730001 */  addiu     $s3, $s3, 1
/* D9DD34 80240864 0C00A6C9 */  jal       clamp_angle
/* D9DD38 80240868 E600FFF8 */   swc1     $f0, -8($s0)
/* D9DD3C 8024086C C60C0000 */  lwc1      $f12, ($s0)
/* D9DD40 80240870 2631008C */  addiu     $s1, $s1, 0x8c
/* D9DD44 80240874 0C00A6C9 */  jal       clamp_angle
/* D9DD48 80240878 E600FFFC */   swc1     $f0, -4($s0)
/* D9DD4C 8024087C E6000000 */  swc1      $f0, ($s0)
/* D9DD50 80240880 E7B40010 */  swc1      $f20, 0x10($sp)
/* D9DD54 80240884 8E05FFF8 */  lw        $a1, -8($s0)
/* D9DD58 80240888 4406B000 */  mfc1      $a2, $f22
/* D9DD5C 8024088C 4407A000 */  mfc1      $a3, $f20
/* D9DD60 80240890 0C019EC8 */  jal       guRotateF
/* D9DD64 80240894 02A0202D */   daddu    $a0, $s5, $zero
/* D9DD68 80240898 E7B40010 */  swc1      $f20, 0x10($sp)
/* D9DD6C 8024089C 8E05FFFC */  lw        $a1, -4($s0)
/* D9DD70 802408A0 4406A000 */  mfc1      $a2, $f20
/* D9DD74 802408A4 4407B000 */  mfc1      $a3, $f22
/* D9DD78 802408A8 0C019EC8 */  jal       guRotateF
/* D9DD7C 802408AC 0280202D */   daddu    $a0, $s4, $zero
/* D9DD80 802408B0 02C0202D */  daddu     $a0, $s6, $zero
/* D9DD84 802408B4 E7B60010 */  swc1      $f22, 0x10($sp)
/* D9DD88 802408B8 8E050000 */  lw        $a1, ($s0)
/* D9DD8C 802408BC 4406A000 */  mfc1      $a2, $f20
/* D9DD90 802408C0 4407A000 */  mfc1      $a3, $f20
/* D9DD94 802408C4 0C019EC8 */  jal       guRotateF
/* D9DD98 802408C8 2610008C */   addiu    $s0, $s0, 0x8c
/* D9DD9C 802408CC 02C0202D */  daddu     $a0, $s6, $zero
/* D9DDA0 802408D0 02A0282D */  daddu     $a1, $s5, $zero
/* D9DDA4 802408D4 0C019D80 */  jal       guMtxCatF
/* D9DDA8 802408D8 02A0302D */   daddu    $a2, $s5, $zero
/* D9DDAC 802408DC 02A0202D */  daddu     $a0, $s5, $zero
/* D9DDB0 802408E0 0280282D */  daddu     $a1, $s4, $zero
/* D9DDB4 802408E4 0C019D80 */  jal       guMtxCatF
/* D9DDB8 802408E8 0280302D */   daddu    $a2, $s4, $zero
/* D9DDBC 802408EC 0280202D */  daddu     $a0, $s4, $zero
/* D9DDC0 802408F0 27A50018 */  addiu     $a1, $sp, 0x18
/* D9DDC4 802408F4 0C019D80 */  jal       guMtxCatF
/* D9DDC8 802408F8 00A0302D */   daddu    $a2, $a1, $zero
/* D9DDCC 802408FC 26440058 */  addiu     $a0, $s2, 0x58
/* D9DDD0 80240900 27A50018 */  addiu     $a1, $sp, 0x18
/* D9DDD4 80240904 0C019D80 */  jal       guMtxCatF
/* D9DDD8 80240908 0080302D */   daddu    $a2, $a0, $zero
/* D9DDDC 8024090C 2E62000C */  sltiu     $v0, $s3, 0xc
/* D9DDE0 80240910 1440FF60 */  bnez      $v0, .L80240694
/* D9DDE4 80240914 00000000 */   nop      
/* D9DDE8 80240918 8EE20074 */  lw        $v0, 0x74($s7)
/* D9DDEC 8024091C 2C42000C */  sltiu     $v0, $v0, 0xc
/* D9DDF0 80240920 14400005 */  bnez      $v0, .L80240938
/* D9DDF4 80240924 0000102D */   daddu    $v0, $zero, $zero
/* D9DDF8 80240928 8EE40070 */  lw        $a0, 0x70($s7)
/* D9DDFC 8024092C 0C00AB4B */  jal       heap_free
/* D9DE00 80240930 00000000 */   nop      
/* D9DE04 80240934 24020002 */  addiu     $v0, $zero, 2
.L80240938:
/* D9DE08 80240938 8FBF013C */  lw        $ra, 0x13c($sp)
/* D9DE0C 8024093C 8FBE0138 */  lw        $fp, 0x138($sp)
/* D9DE10 80240940 8FB70134 */  lw        $s7, 0x134($sp)
/* D9DE14 80240944 8FB60130 */  lw        $s6, 0x130($sp)
/* D9DE18 80240948 8FB5012C */  lw        $s5, 0x12c($sp)
/* D9DE1C 8024094C 8FB40128 */  lw        $s4, 0x128($sp)
/* D9DE20 80240950 8FB30124 */  lw        $s3, 0x124($sp)
/* D9DE24 80240954 8FB20120 */  lw        $s2, 0x120($sp)
/* D9DE28 80240958 8FB1011C */  lw        $s1, 0x11c($sp)
/* D9DE2C 8024095C 8FB00118 */  lw        $s0, 0x118($sp)
/* D9DE30 80240960 D7B60148 */  ldc1      $f22, 0x148($sp)
/* D9DE34 80240964 D7B40140 */  ldc1      $f20, 0x140($sp)
/* D9DE38 80240968 03E00008 */  jr        $ra
/* D9DE3C 8024096C 27BD0150 */   addiu    $sp, $sp, 0x150
