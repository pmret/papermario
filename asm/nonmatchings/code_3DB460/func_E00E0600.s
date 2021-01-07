.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E0600
/* 3DBA60 E00E0600 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 3DBA64 E00E0604 AFBE00B0 */  sw        $fp, 0xb0($sp)
/* 3DBA68 E00E0608 0080F02D */  daddu     $fp, $a0, $zero
/* 3DBA6C E00E060C 3C06DB06 */  lui       $a2, 0xdb06
/* 3DBA70 E00E0610 34C60024 */  ori       $a2, $a2, 0x24
/* 3DBA74 E00E0614 27A40010 */  addiu     $a0, $sp, 0x10
/* 3DBA78 E00E0618 AFB3009C */  sw        $s3, 0x9c($sp)
/* 3DBA7C E00E061C 3C130001 */  lui       $s3, 1
/* 3DBA80 E00E0620 36731630 */  ori       $s3, $s3, 0x1630
/* 3DBA84 E00E0624 AFB500A4 */  sw        $s5, 0xa4($sp)
/* 3DBA88 E00E0628 24150001 */  addiu     $s5, $zero, 1
/* 3DBA8C E00E062C AFB600A8 */  sw        $s6, 0xa8($sp)
/* 3DBA90 E00E0630 3C16800A */  lui       $s6, %hi(D_8009A66C)
/* 3DBA94 E00E0634 26D6A66C */  addiu     $s6, $s6, %lo(D_8009A66C)
/* 3DBA98 E00E0638 AFBF00B4 */  sw        $ra, 0xb4($sp)
/* 3DBA9C E00E063C AFB700AC */  sw        $s7, 0xac($sp)
/* 3DBAA0 E00E0640 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 3DBAA4 E00E0644 AFB20098 */  sw        $s2, 0x98($sp)
/* 3DBAA8 E00E0648 AFB10094 */  sw        $s1, 0x94($sp)
/* 3DBAAC E00E064C AFB00090 */  sw        $s0, 0x90($sp)
/* 3DBAB0 E00E0650 8EC50000 */  lw        $a1, ($s6)
/* 3DBAB4 E00E0654 8FD4000C */  lw        $s4, 0xc($fp)
/* 3DBAB8 E00E0658 00A0182D */  daddu     $v1, $a1, $zero
/* 3DBABC E00E065C 24A50008 */  addiu     $a1, $a1, 8
/* 3DBAC0 E00E0660 AEC50000 */  sw        $a1, ($s6)
/* 3DBAC4 E00E0664 8E92002C */  lw        $s2, 0x2c($s4)
/* 3DBAC8 E00E0668 3C02E700 */  lui       $v0, 0xe700
/* 3DBACC E00E066C AC620000 */  sw        $v0, ($v1)
/* 3DBAD0 E00E0670 AC600004 */  sw        $zero, 4($v1)
/* 3DBAD4 E00E0674 ACA60000 */  sw        $a2, ($a1)
/* 3DBAD8 E00E0678 8FC30010 */  lw        $v1, 0x10($fp)
/* 3DBADC E00E067C 24A20008 */  addiu     $v0, $a1, 8
/* 3DBAE0 E00E0680 AEC20000 */  sw        $v0, ($s6)
/* 3DBAE4 E00E0684 8C62001C */  lw        $v0, 0x1c($v1)
/* 3DBAE8 E00E0688 3C038000 */  lui       $v1, 0x8000
/* 3DBAEC E00E068C 00431021 */  addu      $v0, $v0, $v1
/* 3DBAF0 E00E0690 3C03800B */  lui       $v1, %hi(gCameras)
/* 3DBAF4 E00E0694 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3DBAF8 E00E0698 ACA20004 */  sw        $v0, 4($a1)
/* 3DBAFC E00E069C 8E850004 */  lw        $a1, 4($s4)
/* 3DBB00 E00E06A0 8E860008 */  lw        $a2, 8($s4)
/* 3DBB04 E00E06A4 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3DBB08 E00E06A8 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3DBB0C E00E06AC 8E87000C */  lw        $a3, 0xc($s4)
/* 3DBB10 E00E06B0 00028080 */  sll       $s0, $v0, 2
/* 3DBB14 E00E06B4 02028021 */  addu      $s0, $s0, $v0
/* 3DBB18 E00E06B8 00108080 */  sll       $s0, $s0, 2
/* 3DBB1C E00E06BC 02028023 */  subu      $s0, $s0, $v0
/* 3DBB20 E00E06C0 001010C0 */  sll       $v0, $s0, 3
/* 3DBB24 E00E06C4 02028021 */  addu      $s0, $s0, $v0
/* 3DBB28 E00E06C8 001080C0 */  sll       $s0, $s0, 3
/* 3DBB2C E00E06CC 0C080108 */  jal       func_E0200420
/* 3DBB30 E00E06D0 02038021 */   addu     $s0, $s0, $v1
/* 3DBB34 E00E06D4 27B10050 */  addiu     $s1, $sp, 0x50
/* 3DBB38 E00E06D8 8E850040 */  lw        $a1, 0x40($s4)
/* 3DBB3C E00E06DC 0220202D */  daddu     $a0, $s1, $zero
/* 3DBB40 E00E06E0 00A0302D */  daddu     $a2, $a1, $zero
/* 3DBB44 E00E06E4 0C080110 */  jal       func_E0200440
/* 3DBB48 E00E06E8 00A0382D */   daddu    $a3, $a1, $zero
/* 3DBB4C E00E06EC 0220202D */  daddu     $a0, $s1, $zero
/* 3DBB50 E00E06F0 27A50010 */  addiu     $a1, $sp, 0x10
/* 3DBB54 E00E06F4 0C080114 */  jal       func_E0200450
/* 3DBB58 E00E06F8 00A0302D */   daddu    $a2, $a1, $zero
/* 3DBB5C E00E06FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3DBB60 E00E0700 3C118007 */  lui       $s1, %hi(D_800741F0)
/* 3DBB64 E00E0704 263141F0 */  addiu     $s1, $s1, %lo(D_800741F0)
/* 3DBB68 E00E0708 3C17800A */  lui       $s7, %hi(D_8009A674)
/* 3DBB6C E00E070C 26F7A674 */  addiu     $s7, $s7, %lo(D_8009A674)
/* 3DBB70 E00E0710 96250000 */  lhu       $a1, ($s1)
/* 3DBB74 E00E0714 8EE20000 */  lw        $v0, ($s7)
/* 3DBB78 E00E0718 00052980 */  sll       $a1, $a1, 6
/* 3DBB7C E00E071C 00B32821 */  addu      $a1, $a1, $s3
/* 3DBB80 E00E0720 0C080118 */  jal       func_E0200460
/* 3DBB84 E00E0724 00452821 */   addu     $a1, $v0, $a1
/* 3DBB88 E00E0728 3C03DA38 */  lui       $v1, 0xda38
/* 3DBB8C E00E072C 34630002 */  ori       $v1, $v1, 2
/* 3DBB90 E00E0730 3C06DA38 */  lui       $a2, 0xda38
/* 3DBB94 E00E0734 00D53025 */  or        $a2, $a2, $s5
/* 3DBB98 E00E0738 325200FF */  andi      $s2, $s2, 0xff
/* 3DBB9C E00E073C 8EC40000 */  lw        $a0, ($s6)
/* 3DBBA0 E00E0740 96220000 */  lhu       $v0, ($s1)
/* 3DBBA4 E00E0744 0080282D */  daddu     $a1, $a0, $zero
/* 3DBBA8 E00E0748 24840008 */  addiu     $a0, $a0, 8
/* 3DBBAC E00E074C AEC40000 */  sw        $a0, ($s6)
/* 3DBBB0 E00E0750 ACA30000 */  sw        $v1, ($a1)
/* 3DBBB4 E00E0754 00551821 */  addu      $v1, $v0, $s5
/* 3DBBB8 E00E0758 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3DBBBC E00E075C 00021180 */  sll       $v0, $v0, 6
/* 3DBBC0 E00E0760 A6230000 */  sh        $v1, ($s1)
/* 3DBBC4 E00E0764 8EE30000 */  lw        $v1, ($s7)
/* 3DBBC8 E00E0768 00531021 */  addu      $v0, $v0, $s3
/* 3DBBCC E00E076C 00621821 */  addu      $v1, $v1, $v0
/* 3DBBD0 E00E0770 24820008 */  addiu     $v0, $a0, 8
/* 3DBBD4 E00E0774 ACA30004 */  sw        $v1, 4($a1)
/* 3DBBD8 E00E0778 AEC20000 */  sw        $v0, ($s6)
/* 3DBBDC E00E077C 24820010 */  addiu     $v0, $a0, 0x10
/* 3DBBE0 E00E0780 AC860000 */  sw        $a2, ($a0)
/* 3DBBE4 E00E0784 AEC20000 */  sw        $v0, ($s6)
/* 3DBBE8 E00E0788 8E030204 */  lw        $v1, 0x204($s0)
/* 3DBBEC E00E078C 3C02FA00 */  lui       $v0, 0xfa00
/* 3DBBF0 E00E0790 AC820008 */  sw        $v0, 8($a0)
/* 3DBBF4 E00E0794 AC830004 */  sw        $v1, 4($a0)
/* 3DBBF8 E00E0798 92820023 */  lbu       $v0, 0x23($s4)
/* 3DBBFC E00E079C 92850027 */  lbu       $a1, 0x27($s4)
/* 3DBC00 E00E07A0 9286002B */  lbu       $a2, 0x2b($s4)
/* 3DBC04 E00E07A4 24830018 */  addiu     $v1, $a0, 0x18
/* 3DBC08 E00E07A8 AEC30000 */  sw        $v1, ($s6)
/* 3DBC0C E00E07AC 3C03FB00 */  lui       $v1, 0xfb00
/* 3DBC10 E00E07B0 AC830010 */  sw        $v1, 0x10($a0)
/* 3DBC14 E00E07B4 00021600 */  sll       $v0, $v0, 0x18
/* 3DBC18 E00E07B8 00052C00 */  sll       $a1, $a1, 0x10
/* 3DBC1C E00E07BC 00451025 */  or        $v0, $v0, $a1
/* 3DBC20 E00E07C0 00063200 */  sll       $a2, $a2, 8
/* 3DBC24 E00E07C4 00461025 */  or        $v0, $v0, $a2
/* 3DBC28 E00E07C8 00521025 */  or        $v0, $v0, $s2
/* 3DBC2C E00E07CC AC82000C */  sw        $v0, 0xc($a0)
/* 3DBC30 E00E07D0 92820033 */  lbu       $v0, 0x33($s4)
/* 3DBC34 E00E07D4 92850037 */  lbu       $a1, 0x37($s4)
/* 3DBC38 E00E07D8 9286003B */  lbu       $a2, 0x3b($s4)
/* 3DBC3C E00E07DC 9287003F */  lbu       $a3, 0x3f($s4)
/* 3DBC40 E00E07E0 3C03DE00 */  lui       $v1, 0xde00
/* 3DBC44 E00E07E4 AC830018 */  sw        $v1, 0x18($a0)
/* 3DBC48 E00E07E8 00021600 */  sll       $v0, $v0, 0x18
/* 3DBC4C E00E07EC 00052C00 */  sll       $a1, $a1, 0x10
/* 3DBC50 E00E07F0 00451025 */  or        $v0, $v0, $a1
/* 3DBC54 E00E07F4 00063200 */  sll       $a2, $a2, 8
/* 3DBC58 E00E07F8 00461025 */  or        $v0, $v0, $a2
/* 3DBC5C E00E07FC 00471025 */  or        $v0, $v0, $a3
/* 3DBC60 E00E0800 AC820014 */  sw        $v0, 0x14($a0)
/* 3DBC64 E00E0804 3C02E00E */  lui       $v0, %hi(D_E00E0A44)
/* 3DBC68 E00E0808 8C420A44 */  lw        $v0, %lo(D_E00E0A44)($v0)
/* 3DBC6C E00E080C 26940070 */  addiu     $s4, $s4, 0x70
/* 3DBC70 E00E0810 AC82001C */  sw        $v0, 0x1c($a0)
/* 3DBC74 E00E0814 8FC20008 */  lw        $v0, 8($fp)
/* 3DBC78 E00E0818 24840020 */  addiu     $a0, $a0, 0x20
/* 3DBC7C E00E081C 02A2102A */  slt       $v0, $s5, $v0
/* 3DBC80 E00E0820 10400070 */  beqz      $v0, .LE00E09E4
/* 3DBC84 E00E0824 AEC40000 */   sw       $a0, ($s6)
/* 3DBC88 E00E0828 0220982D */  daddu     $s3, $s1, $zero
/* 3DBC8C E00E082C 3C120001 */  lui       $s2, 1
/* 3DBC90 E00E0830 36521630 */  ori       $s2, $s2, 0x1630
/* 3DBC94 E00E0834 02C0882D */  daddu     $s1, $s6, $zero
/* 3DBC98 E00E0838 3C16F200 */  lui       $s6, 0xf200
/* 3DBC9C E00E083C 26900060 */  addiu     $s0, $s4, 0x60
.LE00E0840:
/* 3DBCA0 E00E0840 8E020004 */  lw        $v0, 4($s0)
/* 3DBCA4 E00E0844 04420063 */  bltzl     $v0, .LE00E09D4
/* 3DBCA8 E00E0848 26B50001 */   addiu    $s5, $s5, 1
/* 3DBCAC E00E084C 8E05FFA4 */  lw        $a1, -0x5c($s0)
/* 3DBCB0 E00E0850 8E06FFA8 */  lw        $a2, -0x58($s0)
/* 3DBCB4 E00E0854 8E07FFAC */  lw        $a3, -0x54($s0)
/* 3DBCB8 E00E0858 0C080108 */  jal       func_E0200420
/* 3DBCBC E00E085C 27A40010 */   addiu    $a0, $sp, 0x10
/* 3DBCC0 E00E0860 27A40010 */  addiu     $a0, $sp, 0x10
/* 3DBCC4 E00E0864 96650000 */  lhu       $a1, ($s3)
/* 3DBCC8 E00E0868 8EE20000 */  lw        $v0, ($s7)
/* 3DBCCC E00E086C 00052980 */  sll       $a1, $a1, 6
/* 3DBCD0 E00E0870 00B22821 */  addu      $a1, $a1, $s2
/* 3DBCD4 E00E0874 0C080118 */  jal       func_E0200460
/* 3DBCD8 E00E0878 00452821 */   addu     $a1, $v0, $a1
/* 3DBCDC E00E087C 8E260000 */  lw        $a2, ($s1)
/* 3DBCE0 E00E0880 02A0382D */  daddu     $a3, $s5, $zero
/* 3DBCE4 E00E0884 00C0202D */  daddu     $a0, $a2, $zero
/* 3DBCE8 E00E0888 24C60008 */  addiu     $a2, $a2, 8
/* 3DBCEC E00E088C AE260000 */  sw        $a2, ($s1)
/* 3DBCF0 E00E0890 96620000 */  lhu       $v0, ($s3)
/* 3DBCF4 E00E0894 3C03DA38 */  lui       $v1, 0xda38
/* 3DBCF8 E00E0898 AC830000 */  sw        $v1, ($a0)
/* 3DBCFC E00E089C 24430001 */  addiu     $v1, $v0, 1
/* 3DBD00 E00E08A0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3DBD04 E00E08A4 00021180 */  sll       $v0, $v0, 6
/* 3DBD08 E00E08A8 A6630000 */  sh        $v1, ($s3)
/* 3DBD0C E00E08AC 8EE30000 */  lw        $v1, ($s7)
/* 3DBD10 E00E08B0 00521021 */  addu      $v0, $v0, $s2
/* 3DBD14 E00E08B4 00621821 */  addu      $v1, $v1, $v0
/* 3DBD18 E00E08B8 24C20008 */  addiu     $v0, $a2, 8
/* 3DBD1C E00E08BC AC830004 */  sw        $v1, 4($a0)
/* 3DBD20 E00E08C0 06A10002 */  bgez      $s5, .LE00E08CC
/* 3DBD24 E00E08C4 AE220000 */   sw       $v0, ($s1)
/* 3DBD28 E00E08C8 26A70003 */  addiu     $a3, $s5, 3
.LE00E08CC:
/* 3DBD2C E00E08CC 3C040003 */  lui       $a0, 3
/* 3DBD30 E00E08D0 3484C000 */  ori       $a0, $a0, 0xc000
/* 3DBD34 E00E08D4 3C05D838 */  lui       $a1, 0xd838
/* 3DBD38 E00E08D8 34A50002 */  ori       $a1, $a1, 2
/* 3DBD3C E00E08DC 00071883 */  sra       $v1, $a3, 2
/* 3DBD40 E00E08E0 00031880 */  sll       $v1, $v1, 2
/* 3DBD44 E00E08E4 02A31823 */  subu      $v1, $s5, $v1
/* 3DBD48 E00E08E8 00031180 */  sll       $v0, $v1, 6
/* 3DBD4C E00E08EC 30420FFF */  andi      $v0, $v0, 0xfff
/* 3DBD50 E00E08F0 00561025 */  or        $v0, $v0, $s6
/* 3DBD54 E00E08F4 00031980 */  sll       $v1, $v1, 6
/* 3DBD58 E00E08F8 3463003C */  ori       $v1, $v1, 0x3c
/* 3DBD5C E00E08FC 30630FFF */  andi      $v1, $v1, 0xfff
/* 3DBD60 E00E0900 00641825 */  or        $v1, $v1, $a0
/* 3DBD64 E00E0904 ACC20000 */  sw        $v0, ($a2)
/* 3DBD68 E00E0908 24C20010 */  addiu     $v0, $a2, 0x10
/* 3DBD6C E00E090C ACC30004 */  sw        $v1, 4($a2)
/* 3DBD70 E00E0910 AE220000 */  sw        $v0, ($s1)
/* 3DBD74 E00E0914 24C20018 */  addiu     $v0, $a2, 0x18
/* 3DBD78 E00E0918 C600FFFC */  lwc1      $f0, -4($s0)
/* 3DBD7C E00E091C 3C040100 */  lui       $a0, 0x100
/* 3DBD80 E00E0920 AE220000 */  sw        $v0, ($s1)
/* 3DBD84 E00E0924 4600010D */  trunc.w.s $f4, $f0
/* 3DBD88 E00E0928 44032000 */  mfc1      $v1, $f4
/* 3DBD8C E00E092C 00000000 */  nop       
/* 3DBD90 E00E0930 00031880 */  sll       $v1, $v1, 2
/* 3DBD94 E00E0934 30630FFF */  andi      $v1, $v1, 0xfff
/* 3DBD98 E00E0938 C6000000 */  lwc1      $f0, ($s0)
/* 3DBD9C E00E093C 00031B00 */  sll       $v1, $v1, 0xc
/* 3DBDA0 E00E0940 4600010D */  trunc.w.s $f4, $f0
/* 3DBDA4 E00E0944 44022000 */  mfc1      $v0, $f4
/* 3DBDA8 E00E0948 00000000 */  nop       
/* 3DBDAC E00E094C 00021080 */  sll       $v0, $v0, 2
/* 3DBDB0 E00E0950 30420FFF */  andi      $v0, $v0, 0xfff
/* 3DBDB4 E00E0954 00561025 */  or        $v0, $v0, $s6
/* 3DBDB8 E00E0958 00621825 */  or        $v1, $v1, $v0
/* 3DBDBC E00E095C ACC30008 */  sw        $v1, 8($a2)
/* 3DBDC0 E00E0960 C600FFFC */  lwc1      $f0, -4($s0)
/* 3DBDC4 E00E0964 C6020000 */  lwc1      $f2, ($s0)
/* 3DBDC8 E00E0968 3C02DE00 */  lui       $v0, 0xde00
/* 3DBDCC E00E096C ACC20010 */  sw        $v0, 0x10($a2)
/* 3DBDD0 E00E0970 4600010D */  trunc.w.s $f4, $f0
/* 3DBDD4 E00E0974 44032000 */  mfc1      $v1, $f4
/* 3DBDD8 E00E0978 00000000 */  nop       
/* 3DBDDC E00E097C 2463000F */  addiu     $v1, $v1, 0xf
/* 3DBDE0 E00E0980 00031880 */  sll       $v1, $v1, 2
/* 3DBDE4 E00E0984 30630FFF */  andi      $v1, $v1, 0xfff
/* 3DBDE8 E00E0988 00031B00 */  sll       $v1, $v1, 0xc
/* 3DBDEC E00E098C 4600110D */  trunc.w.s $f4, $f2
/* 3DBDF0 E00E0990 44022000 */  mfc1      $v0, $f4
/* 3DBDF4 E00E0994 00000000 */  nop       
/* 3DBDF8 E00E0998 2442000F */  addiu     $v0, $v0, 0xf
/* 3DBDFC E00E099C 00021080 */  sll       $v0, $v0, 2
/* 3DBE00 E00E09A0 30420FFF */  andi      $v0, $v0, 0xfff
/* 3DBE04 E00E09A4 00441025 */  or        $v0, $v0, $a0
/* 3DBE08 E00E09A8 00621825 */  or        $v1, $v1, $v0
/* 3DBE0C E00E09AC ACC3000C */  sw        $v1, 0xc($a2)
/* 3DBE10 E00E09B0 3C03E00E */  lui       $v1, %hi(D_E00E0A40)
/* 3DBE14 E00E09B4 8C630A40 */  lw        $v1, %lo(D_E00E0A40)($v1)
/* 3DBE18 E00E09B8 24C20020 */  addiu     $v0, $a2, 0x20
/* 3DBE1C E00E09BC AE220000 */  sw        $v0, ($s1)
/* 3DBE20 E00E09C0 24020040 */  addiu     $v0, $zero, 0x40
/* 3DBE24 E00E09C4 ACC50018 */  sw        $a1, 0x18($a2)
/* 3DBE28 E00E09C8 ACC2001C */  sw        $v0, 0x1c($a2)
/* 3DBE2C E00E09CC ACC30014 */  sw        $v1, 0x14($a2)
/* 3DBE30 E00E09D0 26B50001 */  addiu     $s5, $s5, 1
.LE00E09D4:
/* 3DBE34 E00E09D4 8FC20008 */  lw        $v0, 8($fp)
/* 3DBE38 E00E09D8 02A2102A */  slt       $v0, $s5, $v0
/* 3DBE3C E00E09DC 1440FF98 */  bnez      $v0, .LE00E0840
/* 3DBE40 E00E09E0 26100070 */   addiu    $s0, $s0, 0x70
.LE00E09E4:
/* 3DBE44 E00E09E4 3C05D838 */  lui       $a1, 0xd838
/* 3DBE48 E00E09E8 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 3DBE4C E00E09EC 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 3DBE50 E00E09F0 8C620000 */  lw        $v0, ($v1)
/* 3DBE54 E00E09F4 34A50002 */  ori       $a1, $a1, 2
/* 3DBE58 E00E09F8 0040202D */  daddu     $a0, $v0, $zero
/* 3DBE5C E00E09FC 24420008 */  addiu     $v0, $v0, 8
/* 3DBE60 E00E0A00 AC620000 */  sw        $v0, ($v1)
/* 3DBE64 E00E0A04 24020040 */  addiu     $v0, $zero, 0x40
/* 3DBE68 E00E0A08 AC850000 */  sw        $a1, ($a0)
/* 3DBE6C E00E0A0C AC820004 */  sw        $v0, 4($a0)
/* 3DBE70 E00E0A10 8FBF00B4 */  lw        $ra, 0xb4($sp)
/* 3DBE74 E00E0A14 8FBE00B0 */  lw        $fp, 0xb0($sp)
/* 3DBE78 E00E0A18 8FB700AC */  lw        $s7, 0xac($sp)
/* 3DBE7C E00E0A1C 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 3DBE80 E00E0A20 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 3DBE84 E00E0A24 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 3DBE88 E00E0A28 8FB3009C */  lw        $s3, 0x9c($sp)
/* 3DBE8C E00E0A2C 8FB20098 */  lw        $s2, 0x98($sp)
/* 3DBE90 E00E0A30 8FB10094 */  lw        $s1, 0x94($sp)
/* 3DBE94 E00E0A34 8FB00090 */  lw        $s0, 0x90($sp)
/* 3DBE98 E00E0A38 03E00008 */  jr        $ra
/* 3DBE9C E00E0A3C 27BD00B8 */   addiu    $sp, $sp, 0xb8
