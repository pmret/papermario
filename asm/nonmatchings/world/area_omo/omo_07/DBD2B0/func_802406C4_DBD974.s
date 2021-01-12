.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406C4_DBD974
/* DBD974 802406C4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* DBD978 802406C8 AFB20038 */  sw        $s2, 0x38($sp)
/* DBD97C 802406CC 0080902D */  daddu     $s2, $a0, $zero
/* DBD980 802406D0 AFBF0044 */  sw        $ra, 0x44($sp)
/* DBD984 802406D4 AFB40040 */  sw        $s4, 0x40($sp)
/* DBD988 802406D8 AFB3003C */  sw        $s3, 0x3c($sp)
/* DBD98C 802406DC AFB10034 */  sw        $s1, 0x34($sp)
/* DBD990 802406E0 AFB00030 */  sw        $s0, 0x30($sp)
/* DBD994 802406E4 F7B60050 */  sdc1      $f22, 0x50($sp)
/* DBD998 802406E8 F7B40048 */  sdc1      $f20, 0x48($sp)
/* DBD99C 802406EC 8E510148 */  lw        $s1, 0x148($s2)
/* DBD9A0 802406F0 00A0982D */  daddu     $s3, $a1, $zero
/* DBD9A4 802406F4 86240008 */  lh        $a0, 8($s1)
/* DBD9A8 802406F8 0C00EABB */  jal       get_npc_unsafe
/* DBD9AC 802406FC 00C0A02D */   daddu    $s4, $a2, $zero
/* DBD9B0 80240700 8E630014 */  lw        $v1, 0x14($s3)
/* DBD9B4 80240704 04600030 */  bltz      $v1, .L802407C8
/* DBD9B8 80240708 0040802D */   daddu    $s0, $v0, $zero
/* DBD9BC 8024070C 8E420074 */  lw        $v0, 0x74($s2)
/* DBD9C0 80240710 1C40002C */  bgtz      $v0, .L802407C4
/* DBD9C4 80240714 2442FFFF */   addiu    $v0, $v0, -1
/* DBD9C8 80240718 0280202D */  daddu     $a0, $s4, $zero
/* DBD9CC 8024071C AE430074 */  sw        $v1, 0x74($s2)
/* DBD9D0 80240720 AFA00010 */  sw        $zero, 0x10($sp)
/* DBD9D4 80240724 8E66000C */  lw        $a2, 0xc($s3)
/* DBD9D8 80240728 8E670010 */  lw        $a3, 0x10($s3)
/* DBD9DC 8024072C 0C01242D */  jal       func_800490B4
/* DBD9E0 80240730 0220282D */   daddu    $a1, $s1, $zero
/* DBD9E4 80240734 10400021 */  beqz      $v0, .L802407BC
/* DBD9E8 80240738 0000202D */   daddu    $a0, $zero, $zero
/* DBD9EC 8024073C 0200282D */  daddu     $a1, $s0, $zero
/* DBD9F0 80240740 0000302D */  daddu     $a2, $zero, $zero
/* DBD9F4 80240744 860300A8 */  lh        $v1, 0xa8($s0)
/* DBD9F8 80240748 3C013F80 */  lui       $at, 0x3f80
/* DBD9FC 8024074C 44810000 */  mtc1      $at, $f0
/* DBDA00 80240750 3C014000 */  lui       $at, 0x4000
/* DBDA04 80240754 44811000 */  mtc1      $at, $f2
/* DBDA08 80240758 3C01C1A0 */  lui       $at, 0xc1a0
/* DBDA0C 8024075C 44812000 */  mtc1      $at, $f4
/* DBDA10 80240760 2402000F */  addiu     $v0, $zero, 0xf
/* DBDA14 80240764 AFA2001C */  sw        $v0, 0x1c($sp)
/* DBDA18 80240768 44833000 */  mtc1      $v1, $f6
/* DBDA1C 8024076C 00000000 */  nop
/* DBDA20 80240770 468031A0 */  cvt.s.w   $f6, $f6
/* DBDA24 80240774 44073000 */  mfc1      $a3, $f6
/* DBDA28 80240778 27A20028 */  addiu     $v0, $sp, 0x28
/* DBDA2C 8024077C AFA20020 */  sw        $v0, 0x20($sp)
/* DBDA30 80240780 E7A00010 */  swc1      $f0, 0x10($sp)
/* DBDA34 80240784 E7A20014 */  swc1      $f2, 0x14($sp)
/* DBDA38 80240788 0C01BFA4 */  jal       fx_emote
/* DBDA3C 8024078C E7A40018 */   swc1     $f4, 0x18($sp)
/* DBDA40 80240790 0200202D */  daddu     $a0, $s0, $zero
/* DBDA44 80240794 240502F4 */  addiu     $a1, $zero, 0x2f4
/* DBDA48 80240798 0C012530 */  jal       func_800494C0
/* DBDA4C 8024079C 3C060020 */   lui      $a2, 0x20
/* DBDA50 802407A0 8E220018 */  lw        $v0, 0x18($s1)
/* DBDA54 802407A4 9442002A */  lhu       $v0, 0x2a($v0)
/* DBDA58 802407A8 30420001 */  andi      $v0, $v0, 1
/* DBDA5C 802407AC 14400064 */  bnez      $v0, .L80240940
/* DBDA60 802407B0 2402000A */   addiu    $v0, $zero, 0xa
/* DBDA64 802407B4 08090250 */  j         .L80240940
/* DBDA68 802407B8 2402000C */   addiu    $v0, $zero, 0xc
.L802407BC:
/* DBDA6C 802407BC 8E420074 */  lw        $v0, 0x74($s2)
/* DBDA70 802407C0 2442FFFF */  addiu     $v0, $v0, -1
.L802407C4:
/* DBDA74 802407C4 AE420074 */  sw        $v0, 0x74($s2)
.L802407C8:
/* DBDA78 802407C8 8602008C */  lh        $v0, 0x8c($s0)
/* DBDA7C 802407CC 1440005D */  bnez      $v0, .L80240944
/* DBDA80 802407D0 00000000 */   nop
/* DBDA84 802407D4 C6000018 */  lwc1      $f0, 0x18($s0)
/* DBDA88 802407D8 3C014010 */  lui       $at, 0x4010
/* DBDA8C 802407DC 44811800 */  mtc1      $at, $f3
/* DBDA90 802407E0 44801000 */  mtc1      $zero, $f2
/* DBDA94 802407E4 46000021 */  cvt.d.s   $f0, $f0
/* DBDA98 802407E8 4622003C */  c.lt.d    $f0, $f2
/* DBDA9C 802407EC 00000000 */  nop
/* DBDAA0 802407F0 45000003 */  bc1f      .L80240800
/* DBDAA4 802407F4 0200202D */   daddu    $a0, $s0, $zero
/* DBDAA8 802407F8 08090201 */  j         .L80240804
/* DBDAAC 802407FC 0000282D */   daddu    $a1, $zero, $zero
.L80240800:
/* DBDAB0 80240800 24050001 */  addiu     $a1, $zero, 1
.L80240804:
/* DBDAB4 80240804 0C00F598 */  jal       func_8003D660
/* DBDAB8 80240808 00000000 */   nop
/* DBDABC 8024080C C60C0038 */  lwc1      $f12, 0x38($s0)
/* DBDAC0 80240810 8E430078 */  lw        $v1, 0x78($s2)
/* DBDAC4 80240814 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DBDAC8 80240818 00031040 */  sll       $v0, $v1, 1
/* DBDACC 8024081C 00431021 */  addu      $v0, $v0, $v1
/* DBDAD0 80240820 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBDAD4 80240824 00021080 */  sll       $v0, $v0, 2
/* DBDAD8 80240828 00431021 */  addu      $v0, $v0, $v1
/* DBDADC 8024082C C4560004 */  lwc1      $f22, 4($v0)
/* DBDAE0 80240830 4680B5A0 */  cvt.s.w   $f22, $f22
/* DBDAE4 80240834 C454000C */  lwc1      $f20, 0xc($v0)
/* DBDAE8 80240838 4680A520 */  cvt.s.w   $f20, $f20
/* DBDAEC 8024083C 4406B000 */  mfc1      $a2, $f22
/* DBDAF0 80240840 4407A000 */  mfc1      $a3, $f20
/* DBDAF4 80240844 0C00A720 */  jal       atan2
/* DBDAF8 80240848 00000000 */   nop
/* DBDAFC 8024084C 8E050018 */  lw        $a1, 0x18($s0)
/* DBDB00 80240850 44060000 */  mfc1      $a2, $f0
/* DBDB04 80240854 0200202D */  daddu     $a0, $s0, $zero
/* DBDB08 80240858 0C00EA95 */  jal       npc_move_heading
/* DBDB0C 8024085C AE06000C */   sw       $a2, 0xc($s0)
/* DBDB10 80240860 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DBDB14 80240864 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DBDB18 80240868 4406B000 */  mfc1      $a2, $f22
/* DBDB1C 8024086C 4407A000 */  mfc1      $a3, $f20
/* DBDB20 80240870 0C00A7B5 */  jal       dist2D
/* DBDB24 80240874 00000000 */   nop
/* DBDB28 80240878 C6020018 */  lwc1      $f2, 0x18($s0)
/* DBDB2C 8024087C 4602003E */  c.le.s    $f0, $f2
/* DBDB30 80240880 00000000 */  nop
/* DBDB34 80240884 4500002F */  bc1f      .L80240944
/* DBDB38 80240888 240403E8 */   addiu    $a0, $zero, 0x3e8
/* DBDB3C 8024088C 24020002 */  addiu     $v0, $zero, 2
/* DBDB40 80240890 0C00A67F */  jal       rand_int
/* DBDB44 80240894 AE420070 */   sw       $v0, 0x70($s2)
/* DBDB48 80240898 3C035555 */  lui       $v1, 0x5555
/* DBDB4C 8024089C 34635556 */  ori       $v1, $v1, 0x5556
/* DBDB50 802408A0 00430018 */  mult      $v0, $v1
/* DBDB54 802408A4 000227C3 */  sra       $a0, $v0, 0x1f
/* DBDB58 802408A8 00004010 */  mfhi      $t0
/* DBDB5C 802408AC 01042023 */  subu      $a0, $t0, $a0
/* DBDB60 802408B0 00041840 */  sll       $v1, $a0, 1
/* DBDB64 802408B4 00641821 */  addu      $v1, $v1, $a0
/* DBDB68 802408B8 00431023 */  subu      $v0, $v0, $v1
/* DBDB6C 802408BC 24430002 */  addiu     $v1, $v0, 2
/* DBDB70 802408C0 AE430074 */  sw        $v1, 0x74($s2)
/* DBDB74 802408C4 8E62002C */  lw        $v0, 0x2c($s3)
/* DBDB78 802408C8 18400009 */  blez      $v0, .L802408F0
/* DBDB7C 802408CC 24020004 */   addiu    $v0, $zero, 4
/* DBDB80 802408D0 8E620004 */  lw        $v0, 4($s3)
/* DBDB84 802408D4 18400006 */  blez      $v0, .L802408F0
/* DBDB88 802408D8 24020004 */   addiu    $v0, $zero, 4
/* DBDB8C 802408DC 8E620008 */  lw        $v0, 8($s3)
/* DBDB90 802408E0 18400003 */  blez      $v0, .L802408F0
/* DBDB94 802408E4 24020004 */   addiu    $v0, $zero, 4
/* DBDB98 802408E8 14600002 */  bnez      $v1, .L802408F4
/* DBDB9C 802408EC 00000000 */   nop
.L802408F0:
/* DBDBA0 802408F0 AE420070 */  sw        $v0, 0x70($s2)
.L802408F4:
/* DBDBA4 802408F4 0C00A67F */  jal       rand_int
/* DBDBA8 802408F8 24042710 */   addiu    $a0, $zero, 0x2710
/* DBDBAC 802408FC 3C0351EB */  lui       $v1, 0x51eb
/* DBDBB0 80240900 3463851F */  ori       $v1, $v1, 0x851f
/* DBDBB4 80240904 00430018 */  mult      $v0, $v1
/* DBDBB8 80240908 00021FC3 */  sra       $v1, $v0, 0x1f
/* DBDBBC 8024090C 00004010 */  mfhi      $t0
/* DBDBC0 80240910 00082143 */  sra       $a0, $t0, 5
/* DBDBC4 80240914 00832023 */  subu      $a0, $a0, $v1
/* DBDBC8 80240918 00041840 */  sll       $v1, $a0, 1
/* DBDBCC 8024091C 00641821 */  addu      $v1, $v1, $a0
/* DBDBD0 80240920 000318C0 */  sll       $v1, $v1, 3
/* DBDBD4 80240924 00641821 */  addu      $v1, $v1, $a0
/* DBDBD8 80240928 00031880 */  sll       $v1, $v1, 2
/* DBDBDC 8024092C 8E640004 */  lw        $a0, 4($s3)
/* DBDBE0 80240930 00431023 */  subu      $v0, $v0, $v1
/* DBDBE4 80240934 0044102A */  slt       $v0, $v0, $a0
/* DBDBE8 80240938 10400002 */  beqz      $v0, .L80240944
/* DBDBEC 8024093C 24020004 */   addiu    $v0, $zero, 4
.L80240940:
/* DBDBF0 80240940 AE420070 */  sw        $v0, 0x70($s2)
.L80240944:
/* DBDBF4 80240944 8FBF0044 */  lw        $ra, 0x44($sp)
/* DBDBF8 80240948 8FB40040 */  lw        $s4, 0x40($sp)
/* DBDBFC 8024094C 8FB3003C */  lw        $s3, 0x3c($sp)
/* DBDC00 80240950 8FB20038 */  lw        $s2, 0x38($sp)
/* DBDC04 80240954 8FB10034 */  lw        $s1, 0x34($sp)
/* DBDC08 80240958 8FB00030 */  lw        $s0, 0x30($sp)
/* DBDC0C 8024095C D7B60050 */  ldc1      $f22, 0x50($sp)
/* DBDC10 80240960 D7B40048 */  ldc1      $f20, 0x48($sp)
/* DBDC14 80240964 03E00008 */  jr        $ra
/* DBDC18 80240968 27BD0058 */   addiu    $sp, $sp, 0x58
