.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404B0_ED46D0
/* ED46D0 802404B0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* ED46D4 802404B4 AFB60040 */  sw        $s6, 0x40($sp)
/* ED46D8 802404B8 0080B02D */  daddu     $s6, $a0, $zero
/* ED46DC 802404BC 3C028024 */  lui       $v0, %hi(D_80244160_ED8380)
/* ED46E0 802404C0 24424160 */  addiu     $v0, $v0, %lo(D_80244160_ED8380)
/* ED46E4 802404C4 AFBF004C */  sw        $ra, 0x4c($sp)
/* ED46E8 802404C8 AFBE0048 */  sw        $fp, 0x48($sp)
/* ED46EC 802404CC AFB70044 */  sw        $s7, 0x44($sp)
/* ED46F0 802404D0 AFB5003C */  sw        $s5, 0x3c($sp)
/* ED46F4 802404D4 AFB40038 */  sw        $s4, 0x38($sp)
/* ED46F8 802404D8 AFB30034 */  sw        $s3, 0x34($sp)
/* ED46FC 802404DC AFB20030 */  sw        $s2, 0x30($sp)
/* ED4700 802404E0 AFB1002C */  sw        $s1, 0x2c($sp)
/* ED4704 802404E4 AFB00028 */  sw        $s0, 0x28($sp)
/* ED4708 802404E8 AFA50054 */  sw        $a1, 0x54($sp)
/* ED470C 802404EC 8C430000 */  lw        $v1, ($v0)
/* ED4710 802404F0 00C0A02D */  daddu     $s4, $a2, $zero
/* ED4714 802404F4 24630005 */  addiu     $v1, $v1, 5
/* ED4718 802404F8 AC430000 */  sw        $v1, ($v0)
/* ED471C 802404FC 02D4102A */  slt       $v0, $s6, $s4
/* ED4720 80240500 10400177 */  beqz      $v0, .L80240AE0
/* ED4724 80240504 00000000 */   nop
/* ED4728 80240508 8FAA0054 */  lw        $t2, 0x54($sp)
/* ED472C 8024050C 0147102A */  slt       $v0, $t2, $a3
/* ED4730 80240510 10400173 */  beqz      $v0, .L80240AE0
/* ED4734 80240514 00000000 */   nop
/* ED4738 80240518 06C20002 */  bltzl     $s6, .L80240524
/* ED473C 8024051C 0000B02D */   daddu    $s6, $zero, $zero
/* ED4740 80240520 8FAA0054 */  lw        $t2, 0x54($sp)
.L80240524:
/* ED4744 80240524 05420001 */  bltzl     $t2, .L8024052C
/* ED4748 80240528 AFA00054 */   sw       $zero, 0x54($sp)
.L8024052C:
/* ED474C 8024052C 06820001 */  bltzl     $s4, .L80240534
/* ED4750 80240530 0000A02D */   daddu    $s4, $zero, $zero
.L80240534:
/* ED4754 80240534 04E20001 */  bltzl     $a3, .L8024053C
/* ED4758 80240538 0000382D */   daddu    $a3, $zero, $zero
.L8024053C:
/* ED475C 8024053C 2AC20140 */  slti      $v0, $s6, 0x140
/* ED4760 80240540 50400001 */  beql      $v0, $zero, .L80240548
/* ED4764 80240544 2416013F */   addiu    $s6, $zero, 0x13f
.L80240548:
/* ED4768 80240548 8FAA0054 */  lw        $t2, 0x54($sp)
/* ED476C 8024054C 294200F0 */  slti      $v0, $t2, 0xf0
/* ED4770 80240550 14400003 */  bnez      $v0, .L80240560
/* ED4774 80240554 2A820140 */   slti     $v0, $s4, 0x140
/* ED4778 80240558 240A00EF */  addiu     $t2, $zero, 0xef
/* ED477C 8024055C AFAA0054 */  sw        $t2, 0x54($sp)
.L80240560:
/* ED4780 80240560 50400001 */  beql      $v0, $zero, .L80240568
/* ED4784 80240564 2414013F */   addiu    $s4, $zero, 0x13f
.L80240568:
/* ED4788 80240568 28E200F0 */  slti      $v0, $a3, 0xf0
/* ED478C 8024056C 50400001 */  beql      $v0, $zero, .L80240574
/* ED4790 80240570 240700EF */   addiu    $a3, $zero, 0xef
.L80240574:
/* ED4794 80240574 12D4015A */  beq       $s6, $s4, .L80240AE0
/* ED4798 80240578 00000000 */   nop
/* ED479C 8024057C 8FAA0054 */  lw        $t2, 0x54($sp)
/* ED47A0 80240580 11470157 */  beq       $t2, $a3, .L80240AE0
/* ED47A4 80240584 00000000 */   nop
/* ED47A8 80240588 06C10002 */  bgez      $s6, .L80240594
/* ED47AC 8024058C 02C0102D */   daddu    $v0, $s6, $zero
/* ED47B0 80240590 26C20003 */  addiu     $v0, $s6, 3
.L80240594:
/* ED47B4 80240594 00021083 */  sra       $v0, $v0, 2
/* ED47B8 80240598 0002B080 */  sll       $s6, $v0, 2
/* ED47BC 8024059C 06810002 */  bgez      $s4, .L802405A8
/* ED47C0 802405A0 0280102D */   daddu    $v0, $s4, $zero
/* ED47C4 802405A4 26820003 */  addiu     $v0, $s4, 3
.L802405A8:
/* ED47C8 802405A8 3C042AAA */  lui       $a0, 0x2aaa
/* ED47CC 802405AC 3484AAAB */  ori       $a0, $a0, 0xaaab
/* ED47D0 802405B0 8FAA0054 */  lw        $t2, 0x54($sp)
/* ED47D4 802405B4 00021083 */  sra       $v0, $v0, 2
/* ED47D8 802405B8 00EA1823 */  subu      $v1, $a3, $t2
/* ED47DC 802405BC 00640018 */  mult      $v1, $a0
/* ED47E0 802405C0 00021080 */  sll       $v0, $v0, 2
/* ED47E4 802405C4 24540004 */  addiu     $s4, $v0, 4
/* ED47E8 802405C8 0000F02D */  daddu     $fp, $zero, $zero
/* ED47EC 802405CC 000317C3 */  sra       $v0, $v1, 0x1f
/* ED47F0 802405D0 00005010 */  mfhi      $t2
/* ED47F4 802405D4 01425023 */  subu      $t2, $t2, $v0
/* ED47F8 802405D8 000A1040 */  sll       $v0, $t2, 1
/* ED47FC 802405DC 004A1021 */  addu      $v0, $v0, $t2
/* ED4800 802405E0 AFAA0014 */  sw        $t2, 0x14($sp)
/* ED4804 802405E4 AFAA0010 */  sw        $t2, 0x10($sp)
/* ED4808 802405E8 3C0A800A */  lui       $t2, %hi(D_800A15A4)
/* ED480C 802405EC 8D4A15A4 */  lw        $t2, %lo(D_800A15A4)($t2)
/* ED4810 802405F0 00021040 */  sll       $v0, $v0, 1
/* ED4814 802405F4 AFAA0018 */  sw        $t2, 0x18($sp)
/* ED4818 802405F8 8FAA0010 */  lw        $t2, 0x10($sp)
/* ED481C 802405FC 00621823 */  subu      $v1, $v1, $v0
/* ED4820 80240600 194000A6 */  blez      $t2, .L8024089C
/* ED4824 80240604 AFA30014 */   sw       $v1, 0x14($sp)
/* ED4828 80240608 3C13800A */  lui       $s3, %hi(D_800A15C4)
/* ED482C 8024060C 267315C4 */  addiu     $s3, $s3, %lo(D_800A15C4)
/* ED4830 80240610 02961023 */  subu      $v0, $s4, $s6
/* ED4834 80240614 00021040 */  sll       $v0, $v0, 1
/* ED4838 80240618 24420007 */  addiu     $v0, $v0, 7
/* ED483C 8024061C 000210C3 */  sra       $v0, $v0, 3
/* ED4840 80240620 304201FF */  andi      $v0, $v0, 0x1ff
/* ED4844 80240624 00021240 */  sll       $v0, $v0, 9
/* ED4848 80240628 3C03F510 */  lui       $v1, 0xf510
/* ED484C 8024062C 8FB70054 */  lw        $s7, 0x54($sp)
/* ED4850 80240630 00431025 */  or        $v0, $v0, $v1
/* ED4854 80240634 AFA2001C */  sw        $v0, 0x1c($sp)
/* ED4858 80240638 AFA00020 */  sw        $zero, 0x20($sp)
/* ED485C 8024063C 02E0A82D */  daddu     $s5, $s7, $zero
.L80240640:
/* ED4860 80240640 26B2FFFA */  addiu     $s2, $s5, -6
/* ED4864 80240644 0640008C */  bltz      $s2, .L80240878
/* ED4868 80240648 00122840 */   sll      $a1, $s2, 1
/* ED486C 8024064C 28A20100 */  slti      $v0, $a1, 0x100
/* ED4870 80240650 50400001 */  beql      $v0, $zero, .L80240658
/* ED4874 80240654 240500FF */   addiu    $a1, $zero, 0xff
.L80240658:
/* ED4878 80240658 3C02FA00 */  lui       $v0, 0xfa00
/* ED487C 8024065C 8E710000 */  lw        $s1, ($s3)
/* ED4880 80240660 8FA40018 */  lw        $a0, 0x18($sp)
/* ED4884 80240664 0220182D */  daddu     $v1, $s1, $zero
/* ED4888 80240668 26310008 */  addiu     $s1, $s1, 8
/* ED488C 8024066C AE710000 */  sw        $s1, ($s3)
/* ED4890 80240670 AC620000 */  sw        $v0, ($v1)
/* ED4894 80240674 2402FF00 */  addiu     $v0, $zero, -0x100
/* ED4898 80240678 00A21025 */  or        $v0, $a1, $v0
/* ED489C 8024067C AC620004 */  sw        $v0, 4($v1)
/* ED48A0 80240680 26220008 */  addiu     $v0, $s1, 8
/* ED48A4 80240684 0C019BF8 */  jal       func_80066FE0
/* ED48A8 80240688 AE620000 */   sw       $v0, ($s3)
/* ED48AC 8024068C 30420007 */  andi      $v0, $v0, 7
/* ED48B0 80240690 1040000C */  beqz      $v0, .L802406C4
/* ED48B4 80240694 3C02FD10 */   lui      $v0, 0xfd10
/* ED48B8 80240698 8FA40018 */  lw        $a0, 0x18($sp)
/* ED48BC 8024069C 0C019BF8 */  jal       func_80066FE0
/* ED48C0 802406A0 00000000 */   nop
/* ED48C4 802406A4 3C048024 */  lui       $a0, %hi(D_80244BB8_ED8DD8)
/* ED48C8 802406A8 24844BB8 */  addiu     $a0, $a0, %lo(D_80244BB8_ED8DD8)
/* ED48CC 802406AC 3C058024 */  lui       $a1, %hi(D_80244BEC_ED8E0C)
/* ED48D0 802406B0 24A54BEC */  addiu     $a1, $a1, %lo(D_80244BEC_ED8E0C)
/* ED48D4 802406B4 24060053 */  addiu     $a2, $zero, 0x53
/* ED48D8 802406B8 0C00973F */  jal       osSyncPrintf
/* ED48DC 802406BC 0040382D */   daddu    $a3, $v0, $zero
/* ED48E0 802406C0 3C02FD10 */  lui       $v0, 0xfd10
.L802406C4:
/* ED48E4 802406C4 8FA40018 */  lw        $a0, 0x18($sp)
/* ED48E8 802406C8 3442013F */  ori       $v0, $v0, 0x13f
/* ED48EC 802406CC 0C019BF8 */  jal       func_80066FE0
/* ED48F0 802406D0 AE220000 */   sw       $v0, ($s1)
/* ED48F4 802406D4 3C030700 */  lui       $v1, 0x700
/* ED48F8 802406D8 34630090 */  ori       $v1, $v1, 0x90
/* ED48FC 802406DC 00163080 */  sll       $a2, $s6, 2
/* ED4900 802406E0 30C60FFF */  andi      $a2, $a2, 0xfff
/* ED4904 802406E4 00063300 */  sll       $a2, $a2, 0xc
/* ED4908 802406E8 00122080 */  sll       $a0, $s2, 2
/* ED490C 802406EC 30840FFF */  andi      $a0, $a0, 0xfff
/* ED4910 802406F0 26A5FFFF */  addiu     $a1, $s5, -1
/* ED4914 802406F4 8E700000 */  lw        $s0, ($s3)
/* ED4918 802406F8 00052880 */  sll       $a1, $a1, 2
/* ED491C 802406FC AE220004 */  sw        $v0, 4($s1)
/* ED4920 80240700 0200102D */  daddu     $v0, $s0, $zero
/* ED4924 80240704 26100008 */  addiu     $s0, $s0, 8
/* ED4928 80240708 AE700000 */  sw        $s0, ($s3)
/* ED492C 8024070C 8FAA001C */  lw        $t2, 0x1c($sp)
/* ED4930 80240710 30A50FFF */  andi      $a1, $a1, 0xfff
/* ED4934 80240714 AC430004 */  sw        $v1, 4($v0)
/* ED4938 80240718 2683FFFF */  addiu     $v1, $s4, -1
/* ED493C 8024071C 00031880 */  sll       $v1, $v1, 2
/* ED4940 80240720 30630FFF */  andi      $v1, $v1, 0xfff
/* ED4944 80240724 00031B00 */  sll       $v1, $v1, 0xc
/* ED4948 80240728 AC4A0000 */  sw        $t2, ($v0)
/* ED494C 8024072C 26020008 */  addiu     $v0, $s0, 8
/* ED4950 80240730 AE620000 */  sw        $v0, ($s3)
/* ED4954 80240734 3C02E600 */  lui       $v0, 0xe600
/* ED4958 80240738 AE020000 */  sw        $v0, ($s0)
/* ED495C 8024073C 26020010 */  addiu     $v0, $s0, 0x10
/* ED4960 80240740 AE000004 */  sw        $zero, 4($s0)
/* ED4964 80240744 AE620000 */  sw        $v0, ($s3)
/* ED4968 80240748 3C02F400 */  lui       $v0, 0xf400
/* ED496C 8024074C 00821025 */  or        $v0, $a0, $v0
/* ED4970 80240750 00C21025 */  or        $v0, $a2, $v0
/* ED4974 80240754 AE020008 */  sw        $v0, 8($s0)
/* ED4978 80240758 3C020700 */  lui       $v0, 0x700
/* ED497C 8024075C 00A21025 */  or        $v0, $a1, $v0
/* ED4980 80240760 00621025 */  or        $v0, $v1, $v0
/* ED4984 80240764 AE02000C */  sw        $v0, 0xc($s0)
/* ED4988 80240768 26020018 */  addiu     $v0, $s0, 0x18
/* ED498C 8024076C AE620000 */  sw        $v0, ($s3)
/* ED4990 80240770 3C02E700 */  lui       $v0, 0xe700
/* ED4994 80240774 AE020010 */  sw        $v0, 0x10($s0)
/* ED4998 80240778 26020020 */  addiu     $v0, $s0, 0x20
/* ED499C 8024077C AE000014 */  sw        $zero, 0x14($s0)
/* ED49A0 80240780 AE620000 */  sw        $v0, ($s3)
/* ED49A4 80240784 24020090 */  addiu     $v0, $zero, 0x90
/* ED49A8 80240788 AE02001C */  sw        $v0, 0x1c($s0)
/* ED49AC 8024078C 26020028 */  addiu     $v0, $s0, 0x28
/* ED49B0 80240790 AE0A0018 */  sw        $t2, 0x18($s0)
/* ED49B4 80240794 AE620000 */  sw        $v0, ($s3)
/* ED49B8 80240798 3C02F200 */  lui       $v0, 0xf200
/* ED49BC 8024079C 00822025 */  or        $a0, $a0, $v0
/* ED49C0 802407A0 00C42025 */  or        $a0, $a2, $a0
/* ED49C4 802407A4 00651825 */  or        $v1, $v1, $a1
/* ED49C8 802407A8 26020030 */  addiu     $v0, $s0, 0x30
/* ED49CC 802407AC AE040020 */  sw        $a0, 0x20($s0)
/* ED49D0 802407B0 00142080 */  sll       $a0, $s4, 2
/* ED49D4 802407B4 30840FFF */  andi      $a0, $a0, 0xfff
/* ED49D8 802407B8 00042300 */  sll       $a0, $a0, 0xc
/* ED49DC 802407BC AE030024 */  sw        $v1, 0x24($s0)
/* ED49E0 802407C0 AE620000 */  sw        $v0, ($s3)
/* ED49E4 802407C4 26E20006 */  addiu     $v0, $s7, 6
/* ED49E8 802407C8 00021080 */  sll       $v0, $v0, 2
/* ED49EC 802407CC 30420FFF */  andi      $v0, $v0, 0xfff
/* ED49F0 802407D0 3C03E400 */  lui       $v1, 0xe400
/* ED49F4 802407D4 00431025 */  or        $v0, $v0, $v1
/* ED49F8 802407D8 00822025 */  or        $a0, $a0, $v0
/* ED49FC 802407DC 00171080 */  sll       $v0, $s7, 2
/* ED4A00 802407E0 30420FFF */  andi      $v0, $v0, 0xfff
/* ED4A04 802407E4 00C23025 */  or        $a2, $a2, $v0
/* ED4A08 802407E8 26020038 */  addiu     $v0, $s0, 0x38
/* ED4A0C 802407EC AE040028 */  sw        $a0, 0x28($s0)
/* ED4A10 802407F0 AE06002C */  sw        $a2, 0x2c($s0)
/* ED4A14 802407F4 AE620000 */  sw        $v0, ($s3)
/* ED4A18 802407F8 3C02E100 */  lui       $v0, 0xe100
/* ED4A1C 802407FC 00161D40 */  sll       $v1, $s6, 0x15
/* ED4A20 80240800 AE020030 */  sw        $v0, 0x30($s0)
/* ED4A24 80240804 00151140 */  sll       $v0, $s5, 5
/* ED4A28 80240808 3042FFFF */  andi      $v0, $v0, 0xffff
/* ED4A2C 8024080C 00621825 */  or        $v1, $v1, $v0
/* ED4A30 80240810 26020040 */  addiu     $v0, $s0, 0x40
/* ED4A34 80240814 AE030034 */  sw        $v1, 0x34($s0)
/* ED4A38 80240818 AE620000 */  sw        $v0, ($s3)
/* ED4A3C 8024081C 3C038024 */  lui       $v1, %hi(D_80244160_ED8380)
/* ED4A40 80240820 8C634160 */  lw        $v1, %lo(D_80244160_ED8380)($v1)
/* ED4A44 80240824 3C02F100 */  lui       $v0, 0xf100
/* ED4A48 80240828 AE020038 */  sw        $v0, 0x38($s0)
/* ED4A4C 8024082C 8FAA0020 */  lw        $t2, 0x20($sp)
/* ED4A50 80240830 006A1821 */  addu      $v1, $v1, $t2
/* ED4A54 80240834 44836000 */  mtc1      $v1, $f12
/* ED4A58 80240838 00000000 */  nop
/* ED4A5C 8024083C 0C00AD77 */  jal       func_8002B5DC
/* ED4A60 80240840 46806320 */   cvt.s.w  $f12, $f12
/* ED4A64 80240844 3C0143FA */  lui       $at, 0x43fa
/* ED4A68 80240848 44811000 */  mtc1      $at, $f2
/* ED4A6C 8024084C 00000000 */  nop
/* ED4A70 80240850 46020002 */  mul.s     $f0, $f0, $f2
/* ED4A74 80240854 00000000 */  nop
/* ED4A78 80240858 3C030400 */  lui       $v1, 0x400
/* ED4A7C 8024085C 4600010D */  trunc.w.s $f4, $f0
/* ED4A80 80240860 44022000 */  mfc1      $v0, $f4
/* ED4A84 80240864 00000000 */  nop
/* ED4A88 80240868 2442FE0C */  addiu     $v0, $v0, -0x1f4
/* ED4A8C 8024086C 3042FFFF */  andi      $v0, $v0, 0xffff
/* ED4A90 80240870 00431025 */  or        $v0, $v0, $v1
/* ED4A94 80240874 AE02003C */  sw        $v0, 0x3c($s0)
.L80240878:
/* ED4A98 80240878 26F70006 */  addiu     $s7, $s7, 6
/* ED4A9C 8024087C 8FAA0020 */  lw        $t2, 0x20($sp)
/* ED4AA0 80240880 254A001E */  addiu     $t2, $t2, 0x1e
/* ED4AA4 80240884 AFAA0020 */  sw        $t2, 0x20($sp)
/* ED4AA8 80240888 8FAA0010 */  lw        $t2, 0x10($sp)
/* ED4AAC 8024088C 27DE0001 */  addiu     $fp, $fp, 1
/* ED4AB0 80240890 03CA102A */  slt       $v0, $fp, $t2
/* ED4AB4 80240894 1440FF6A */  bnez      $v0, .L80240640
/* ED4AB8 80240898 26B5FFFA */   addiu    $s5, $s5, -6
.L8024089C:
/* ED4ABC 8024089C 8FAA0014 */  lw        $t2, 0x14($sp)
/* ED4AC0 802408A0 1140008F */  beqz      $t2, .L80240AE0
/* ED4AC4 802408A4 001E1040 */   sll      $v0, $fp, 1
/* ED4AC8 802408A8 005E1021 */  addu      $v0, $v0, $fp
/* ED4ACC 802408AC 8FAA0054 */  lw        $t2, 0x54($sp)
/* ED4AD0 802408B0 00029840 */  sll       $s3, $v0, 1
/* ED4AD4 802408B4 01539023 */  subu      $s2, $t2, $s3
/* ED4AD8 802408B8 2642FFFA */  addiu     $v0, $s2, -6
/* ED4ADC 802408BC 04400088 */  bltz      $v0, .L80240AE0
/* ED4AE0 802408C0 00022840 */   sll      $a1, $v0, 1
/* ED4AE4 802408C4 28A20100 */  slti      $v0, $a1, 0x100
/* ED4AE8 802408C8 50400001 */  beql      $v0, $zero, .L802408D0
/* ED4AEC 802408CC 240500FF */   addiu    $a1, $zero, 0xff
.L802408D0:
/* ED4AF0 802408D0 3C11800A */  lui       $s1, %hi(D_800A15C4)
/* ED4AF4 802408D4 263115C4 */  addiu     $s1, $s1, %lo(D_800A15C4)
/* ED4AF8 802408D8 3C02FA00 */  lui       $v0, 0xfa00
/* ED4AFC 802408DC 8E300000 */  lw        $s0, ($s1)
/* ED4B00 802408E0 8FA40018 */  lw        $a0, 0x18($sp)
/* ED4B04 802408E4 0200182D */  daddu     $v1, $s0, $zero
/* ED4B08 802408E8 26100008 */  addiu     $s0, $s0, 8
/* ED4B0C 802408EC AE300000 */  sw        $s0, ($s1)
/* ED4B10 802408F0 AC620000 */  sw        $v0, ($v1)
/* ED4B14 802408F4 2402FF00 */  addiu     $v0, $zero, -0x100
/* ED4B18 802408F8 00A21025 */  or        $v0, $a1, $v0
/* ED4B1C 802408FC AC620004 */  sw        $v0, 4($v1)
/* ED4B20 80240900 26020008 */  addiu     $v0, $s0, 8
/* ED4B24 80240904 0C019BF8 */  jal       func_80066FE0
/* ED4B28 80240908 AE220000 */   sw       $v0, ($s1)
/* ED4B2C 8024090C 30420007 */  andi      $v0, $v0, 7
/* ED4B30 80240910 1040000C */  beqz      $v0, .L80240944
/* ED4B34 80240914 3C02FD10 */   lui      $v0, 0xfd10
/* ED4B38 80240918 8FA40018 */  lw        $a0, 0x18($sp)
/* ED4B3C 8024091C 0C019BF8 */  jal       func_80066FE0
/* ED4B40 80240920 00000000 */   nop
/* ED4B44 80240924 3C048024 */  lui       $a0, %hi(D_80244BB8_ED8DD8)
/* ED4B48 80240928 24844BB8 */  addiu     $a0, $a0, %lo(D_80244BB8_ED8DD8)
/* ED4B4C 8024092C 3C058024 */  lui       $a1, %hi(D_80244BEC_ED8E0C)
/* ED4B50 80240930 24A54BEC */  addiu     $a1, $a1, %lo(D_80244BEC_ED8E0C)
/* ED4B54 80240934 2406006B */  addiu     $a2, $zero, 0x6b
/* ED4B58 80240938 0C00973F */  jal       osSyncPrintf
/* ED4B5C 8024093C 0040382D */   daddu    $a3, $v0, $zero
/* ED4B60 80240940 3C02FD10 */  lui       $v0, 0xfd10
.L80240944:
/* ED4B64 80240944 8FA40018 */  lw        $a0, 0x18($sp)
/* ED4B68 80240948 3442013F */  ori       $v0, $v0, 0x13f
/* ED4B6C 8024094C 0C019BF8 */  jal       func_80066FE0
/* ED4B70 80240950 AE020000 */   sw       $v0, ($s0)
/* ED4B74 80240954 3C050700 */  lui       $a1, 0x700
/* ED4B78 80240958 34A50090 */  ori       $a1, $a1, 0x90
/* ED4B7C 8024095C 3C090400 */  lui       $t1, 0x400
/* ED4B80 80240960 3529FC00 */  ori       $t1, $t1, 0xfc00
/* ED4B84 80240964 02962023 */  subu      $a0, $s4, $s6
/* ED4B88 80240968 00042040 */  sll       $a0, $a0, 1
/* ED4B8C 8024096C 24840007 */  addiu     $a0, $a0, 7
/* ED4B90 80240970 000420C3 */  sra       $a0, $a0, 3
/* ED4B94 80240974 308401FF */  andi      $a0, $a0, 0x1ff
/* ED4B98 80240978 8E260000 */  lw        $a2, ($s1)
/* ED4B9C 8024097C 00042240 */  sll       $a0, $a0, 9
/* ED4BA0 80240980 AE020004 */  sw        $v0, 4($s0)
/* ED4BA4 80240984 3C02F510 */  lui       $v0, 0xf510
/* ED4BA8 80240988 00822025 */  or        $a0, $a0, $v0
/* ED4BAC 8024098C 00164080 */  sll       $t0, $s6, 2
/* ED4BB0 80240990 31080FFF */  andi      $t0, $t0, 0xfff
/* ED4BB4 80240994 00084300 */  sll       $t0, $t0, 0xc
/* ED4BB8 80240998 2647FFFF */  addiu     $a3, $s2, -1
/* ED4BBC 8024099C 00073880 */  sll       $a3, $a3, 2
/* ED4BC0 802409A0 30E70FFF */  andi      $a3, $a3, 0xfff
/* ED4BC4 802409A4 00C0182D */  daddu     $v1, $a2, $zero
/* ED4BC8 802409A8 24C60008 */  addiu     $a2, $a2, 8
/* ED4BCC 802409AC 24C20008 */  addiu     $v0, $a2, 8
/* ED4BD0 802409B0 AE260000 */  sw        $a2, ($s1)
/* ED4BD4 802409B4 AC640000 */  sw        $a0, ($v1)
/* ED4BD8 802409B8 AC650004 */  sw        $a1, 4($v1)
/* ED4BDC 802409BC AE220000 */  sw        $v0, ($s1)
/* ED4BE0 802409C0 3C02E600 */  lui       $v0, 0xe600
/* ED4BE4 802409C4 ACC20000 */  sw        $v0, ($a2)
/* ED4BE8 802409C8 24C20010 */  addiu     $v0, $a2, 0x10
/* ED4BEC 802409CC ACC00004 */  sw        $zero, 4($a2)
/* ED4BF0 802409D0 AE220000 */  sw        $v0, ($s1)
/* ED4BF4 802409D4 3C02F400 */  lui       $v0, 0xf400
/* ED4BF8 802409D8 2683FFFF */  addiu     $v1, $s4, -1
/* ED4BFC 802409DC 00031880 */  sll       $v1, $v1, 2
/* ED4C00 802409E0 30630FFF */  andi      $v1, $v1, 0xfff
/* ED4C04 802409E4 8FAA0014 */  lw        $t2, 0x14($sp)
/* ED4C08 802409E8 00031B00 */  sll       $v1, $v1, 0xc
/* ED4C0C 802409EC 024A2823 */  subu      $a1, $s2, $t2
/* ED4C10 802409F0 00052880 */  sll       $a1, $a1, 2
/* ED4C14 802409F4 30A50FFF */  andi      $a1, $a1, 0xfff
/* ED4C18 802409F8 00A21025 */  or        $v0, $a1, $v0
/* ED4C1C 802409FC 01021025 */  or        $v0, $t0, $v0
/* ED4C20 80240A00 ACC20008 */  sw        $v0, 8($a2)
/* ED4C24 80240A04 3C020700 */  lui       $v0, 0x700
/* ED4C28 80240A08 00E21025 */  or        $v0, $a3, $v0
/* ED4C2C 80240A0C 00621025 */  or        $v0, $v1, $v0
/* ED4C30 80240A10 ACC2000C */  sw        $v0, 0xc($a2)
/* ED4C34 80240A14 24C20018 */  addiu     $v0, $a2, 0x18
/* ED4C38 80240A18 AE220000 */  sw        $v0, ($s1)
/* ED4C3C 80240A1C 3C02E700 */  lui       $v0, 0xe700
/* ED4C40 80240A20 ACC20010 */  sw        $v0, 0x10($a2)
/* ED4C44 80240A24 24C20020 */  addiu     $v0, $a2, 0x20
/* ED4C48 80240A28 ACC00014 */  sw        $zero, 0x14($a2)
/* ED4C4C 80240A2C AE220000 */  sw        $v0, ($s1)
/* ED4C50 80240A30 24020090 */  addiu     $v0, $zero, 0x90
/* ED4C54 80240A34 ACC2001C */  sw        $v0, 0x1c($a2)
/* ED4C58 80240A38 24C20028 */  addiu     $v0, $a2, 0x28
/* ED4C5C 80240A3C ACC40018 */  sw        $a0, 0x18($a2)
/* ED4C60 80240A40 AE220000 */  sw        $v0, ($s1)
/* ED4C64 80240A44 3C02F200 */  lui       $v0, 0xf200
/* ED4C68 80240A48 00A22825 */  or        $a1, $a1, $v0
/* ED4C6C 80240A4C 01052825 */  or        $a1, $t0, $a1
/* ED4C70 80240A50 00671825 */  or        $v1, $v1, $a3
/* ED4C74 80240A54 24C20030 */  addiu     $v0, $a2, 0x30
/* ED4C78 80240A58 ACC30024 */  sw        $v1, 0x24($a2)
/* ED4C7C 80240A5C 00141880 */  sll       $v1, $s4, 2
/* ED4C80 80240A60 30630FFF */  andi      $v1, $v1, 0xfff
/* ED4C84 80240A64 ACC50020 */  sw        $a1, 0x20($a2)
/* ED4C88 80240A68 AE220000 */  sw        $v0, ($s1)
/* ED4C8C 80240A6C 8FAA0054 */  lw        $t2, 0x54($sp)
/* ED4C90 80240A70 00031B00 */  sll       $v1, $v1, 0xc
/* ED4C94 80240A74 01532821 */  addu      $a1, $t2, $s3
/* ED4C98 80240A78 8FAA0014 */  lw        $t2, 0x14($sp)
/* ED4C9C 80240A7C 3C04E400 */  lui       $a0, 0xe400
/* ED4CA0 80240A80 00AA1021 */  addu      $v0, $a1, $t2
/* ED4CA4 80240A84 00021080 */  sll       $v0, $v0, 2
/* ED4CA8 80240A88 30420FFF */  andi      $v0, $v0, 0xfff
/* ED4CAC 80240A8C 00441025 */  or        $v0, $v0, $a0
/* ED4CB0 80240A90 00621825 */  or        $v1, $v1, $v0
/* ED4CB4 80240A94 00052880 */  sll       $a1, $a1, 2
/* ED4CB8 80240A98 30A50FFF */  andi      $a1, $a1, 0xfff
/* ED4CBC 80240A9C 01054025 */  or        $t0, $t0, $a1
/* ED4CC0 80240AA0 24C20038 */  addiu     $v0, $a2, 0x38
/* ED4CC4 80240AA4 ACC30028 */  sw        $v1, 0x28($a2)
/* ED4CC8 80240AA8 ACC8002C */  sw        $t0, 0x2c($a2)
/* ED4CCC 80240AAC AE220000 */  sw        $v0, ($s1)
/* ED4CD0 80240AB0 3C02E100 */  lui       $v0, 0xe100
/* ED4CD4 80240AB4 00161D40 */  sll       $v1, $s6, 0x15
/* ED4CD8 80240AB8 ACC20030 */  sw        $v0, 0x30($a2)
/* ED4CDC 80240ABC 00121140 */  sll       $v0, $s2, 5
/* ED4CE0 80240AC0 3042FFFF */  andi      $v0, $v0, 0xffff
/* ED4CE4 80240AC4 00621825 */  or        $v1, $v1, $v0
/* ED4CE8 80240AC8 24C20040 */  addiu     $v0, $a2, 0x40
/* ED4CEC 80240ACC ACC30034 */  sw        $v1, 0x34($a2)
/* ED4CF0 80240AD0 AE220000 */  sw        $v0, ($s1)
/* ED4CF4 80240AD4 3C02F100 */  lui       $v0, 0xf100
/* ED4CF8 80240AD8 ACC20038 */  sw        $v0, 0x38($a2)
/* ED4CFC 80240ADC ACC9003C */  sw        $t1, 0x3c($a2)
.L80240AE0:
/* ED4D00 80240AE0 8FBF004C */  lw        $ra, 0x4c($sp)
/* ED4D04 80240AE4 8FBE0048 */  lw        $fp, 0x48($sp)
/* ED4D08 80240AE8 8FB70044 */  lw        $s7, 0x44($sp)
/* ED4D0C 80240AEC 8FB60040 */  lw        $s6, 0x40($sp)
/* ED4D10 80240AF0 8FB5003C */  lw        $s5, 0x3c($sp)
/* ED4D14 80240AF4 8FB40038 */  lw        $s4, 0x38($sp)
/* ED4D18 80240AF8 8FB30034 */  lw        $s3, 0x34($sp)
/* ED4D1C 80240AFC 8FB20030 */  lw        $s2, 0x30($sp)
/* ED4D20 80240B00 8FB1002C */  lw        $s1, 0x2c($sp)
/* ED4D24 80240B04 8FB00028 */  lw        $s0, 0x28($sp)
/* ED4D28 80240B08 03E00008 */  jr        $ra
/* ED4D2C 80240B0C 27BD0050 */   addiu    $sp, $sp, 0x50
