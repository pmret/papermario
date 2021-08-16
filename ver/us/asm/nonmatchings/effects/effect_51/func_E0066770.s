.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0066770
/* 3667A0 E0066770 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 3667A4 E0066774 AFB700C4 */  sw        $s7, 0xc4($sp)
/* 3667A8 E0066778 0080B82D */  daddu     $s7, $a0, $zero
/* 3667AC E006677C 3C06DB06 */  lui       $a2, 0xdb06
/* 3667B0 E0066780 34C60024 */  ori       $a2, $a2, 0x24
/* 3667B4 E0066784 27A40020 */  addiu     $a0, $sp, 0x20
/* 3667B8 E0066788 AFB200B0 */  sw        $s2, 0xb0($sp)
/* 3667BC E006678C 3C120001 */  lui       $s2, 1
/* 3667C0 E0066790 36521630 */  ori       $s2, $s2, 0x1630
/* 3667C4 E0066794 AFB600C0 */  sw        $s6, 0xc0($sp)
/* 3667C8 E0066798 3C16800A */  lui       $s6, %hi(gMasterGfxPos)
/* 3667CC E006679C 26D6A66C */  addiu     $s6, $s6, %lo(gMasterGfxPos)
/* 3667D0 E00667A0 AFBF00CC */  sw        $ra, 0xcc($sp)
/* 3667D4 E00667A4 AFBE00C8 */  sw        $fp, 0xc8($sp)
/* 3667D8 E00667A8 AFB500BC */  sw        $s5, 0xbc($sp)
/* 3667DC E00667AC AFB400B8 */  sw        $s4, 0xb8($sp)
/* 3667E0 E00667B0 AFB300B4 */  sw        $s3, 0xb4($sp)
/* 3667E4 E00667B4 AFB100AC */  sw        $s1, 0xac($sp)
/* 3667E8 E00667B8 AFB000A8 */  sw        $s0, 0xa8($sp)
/* 3667EC E00667BC F7B400D0 */  sdc1      $f20, 0xd0($sp)
/* 3667F0 E00667C0 8EC50000 */  lw        $a1, ($s6)
/* 3667F4 E00667C4 8EF4000C */  lw        $s4, 0xc($s7)
/* 3667F8 E00667C8 00A0182D */  daddu     $v1, $a1, $zero
/* 3667FC E00667CC 8E950000 */  lw        $s5, ($s4)
/* 366800 E00667D0 24A50008 */  addiu     $a1, $a1, 8
/* 366804 E00667D4 AEC50000 */  sw        $a1, ($s6)
/* 366808 E00667D8 00151080 */  sll       $v0, $s5, 2
/* 36680C E00667DC 3C13E006 */  lui       $s3, %hi(D_E0066C8C)
/* 366810 E00667E0 02629821 */  addu      $s3, $s3, $v0
/* 366814 E00667E4 8E736C8C */  lw        $s3, %lo(D_E0066C8C)($s3)
/* 366818 E00667E8 3C1EE006 */  lui       $fp, %hi(D_E0066C50)
/* 36681C E00667EC 03C2F021 */  addu      $fp, $fp, $v0
/* 366820 E00667F0 8FDE6C50 */  lw        $fp, %lo(D_E0066C50)($fp)
/* 366824 E00667F4 3C02E700 */  lui       $v0, 0xe700
/* 366828 E00667F8 AC620000 */  sw        $v0, ($v1)
/* 36682C E00667FC AC600004 */  sw        $zero, 4($v1)
/* 366830 E0066800 ACA60000 */  sw        $a2, ($a1)
/* 366834 E0066804 8EE30010 */  lw        $v1, 0x10($s7)
/* 366838 E0066808 24A20008 */  addiu     $v0, $a1, 8
/* 36683C E006680C AEC20000 */  sw        $v0, ($s6)
/* 366840 E0066810 8C62001C */  lw        $v0, 0x1c($v1)
/* 366844 E0066814 3C038000 */  lui       $v1, 0x8000
/* 366848 E0066818 00431021 */  addu      $v0, $v0, $v1
/* 36684C E006681C 3C03800B */  lui       $v1, %hi(gCameras)
/* 366850 E0066820 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 366854 E0066824 ACA20004 */  sw        $v0, 4($a1)
/* 366858 E0066828 8E850010 */  lw        $a1, 0x10($s4)
/* 36685C E006682C 8E860014 */  lw        $a2, 0x14($s4)
/* 366860 E0066830 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 366864 E0066834 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 366868 E0066838 8E870018 */  lw        $a3, 0x18($s4)
/* 36686C E006683C 00028080 */  sll       $s0, $v0, 2
/* 366870 E0066840 02028021 */  addu      $s0, $s0, $v0
/* 366874 E0066844 00108080 */  sll       $s0, $s0, 2
/* 366878 E0066848 02028023 */  subu      $s0, $s0, $v0
/* 36687C E006684C 001010C0 */  sll       $v0, $s0, 3
/* 366880 E0066850 02028021 */  addu      $s0, $s0, $v0
/* 366884 E0066854 001080C0 */  sll       $s0, $s0, 3
/* 366888 E0066858 0C080108 */  jal       func_E0200420
/* 36688C E006685C 02038021 */   addu     $s0, $s0, $v1
/* 366890 E0066860 27B10060 */  addiu     $s1, $sp, 0x60
/* 366894 E0066864 0220202D */  daddu     $a0, $s1, $zero
/* 366898 E0066868 3C013F80 */  lui       $at, 0x3f80
/* 36689C E006686C 4481A000 */  mtc1      $at, $f20
/* 3668A0 E0066870 8E85001C */  lw        $a1, 0x1c($s4)
/* 3668A4 E0066874 4407A000 */  mfc1      $a3, $f20
/* 3668A8 E0066878 0C080110 */  jal       func_E0200440
/* 3668AC E006687C 00A0302D */   daddu    $a2, $a1, $zero
/* 3668B0 E0066880 0220202D */  daddu     $a0, $s1, $zero
/* 3668B4 E0066884 27A50020 */  addiu     $a1, $sp, 0x20
/* 3668B8 E0066888 0C080114 */  jal       func_E0200450
/* 3668BC E006688C 00A0302D */   daddu    $a2, $a1, $zero
/* 3668C0 E0066890 8602000A */  lh        $v0, 0xa($s0)
/* 3668C4 E0066894 8603000C */  lh        $v1, 0xc($s0)
/* 3668C8 E0066898 3C014080 */  lui       $at, 0x4080
/* 3668CC E006689C 44810000 */  mtc1      $at, $f0
/* 3668D0 E00668A0 3C014680 */  lui       $at, 0x4680
/* 3668D4 E00668A4 44811000 */  mtc1      $at, $f2
/* 3668D8 E00668A8 0220202D */  daddu     $a0, $s1, $zero
/* 3668DC E00668AC E7B40018 */  swc1      $f20, 0x18($sp)
/* 3668E0 E00668B0 E7A20014 */  swc1      $f2, 0x14($sp)
/* 3668E4 E00668B4 44821000 */  mtc1      $v0, $f2
/* 3668E8 E00668B8 00000000 */  nop
/* 3668EC E00668BC 468010A0 */  cvt.s.w   $f2, $f2
/* 3668F0 E00668C0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3668F4 E00668C4 44830000 */  mtc1      $v1, $f0
/* 3668F8 E00668C8 00000000 */  nop
/* 3668FC E00668CC 46800020 */  cvt.s.w   $f0, $f0
/* 366900 E00668D0 46001083 */  div.s     $f2, $f2, $f0
/* 366904 E00668D4 8E860060 */  lw        $a2, 0x60($s4)
/* 366908 E00668D8 44071000 */  mfc1      $a3, $f2
/* 36690C E00668DC 0C080160 */  jal       func_E0200580
/* 366910 E00668E0 27A500A0 */   addiu    $a1, $sp, 0xa0
/* 366914 E00668E4 0220202D */  daddu     $a0, $s1, $zero
/* 366918 E00668E8 27A50020 */  addiu     $a1, $sp, 0x20
/* 36691C E00668EC 0C080114 */  jal       func_E0200450
/* 366920 E00668F0 00A0302D */   daddu    $a2, $a1, $zero
/* 366924 E00668F4 27A40020 */  addiu     $a0, $sp, 0x20
/* 366928 E00668F8 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 36692C E00668FC 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 366930 E0066900 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 366934 E0066904 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 366938 E0066908 96050000 */  lhu       $a1, ($s0)
/* 36693C E006690C 8E220000 */  lw        $v0, ($s1)
/* 366940 E0066910 00052980 */  sll       $a1, $a1, 6
/* 366944 E0066914 00B22821 */  addu      $a1, $a1, $s2
/* 366948 E0066918 0C080118 */  jal       func_E0200460
/* 36694C E006691C 00452821 */   addu     $a1, $v0, $a1
/* 366950 E0066920 3C02DA38 */  lui       $v0, 0xda38
/* 366954 E0066924 34420007 */  ori       $v0, $v0, 7
/* 366958 E0066928 27A40020 */  addiu     $a0, $sp, 0x20
/* 36695C E006692C 44800000 */  mtc1      $zero, $f0
/* 366960 E0066930 8EC90000 */  lw        $t1, ($s6)
/* 366964 E0066934 96080000 */  lhu       $t0, ($s0)
/* 366968 E0066938 0120382D */  daddu     $a3, $t1, $zero
/* 36696C E006693C ACE20000 */  sw        $v0, ($a3)
/* 366970 E0066940 3102FFFF */  andi      $v0, $t0, 0xffff
/* 366974 E0066944 00021180 */  sll       $v0, $v0, 6
/* 366978 E0066948 00521021 */  addu      $v0, $v0, $s2
/* 36697C E006694C 25290008 */  addiu     $t1, $t1, 8
/* 366980 E0066950 25080001 */  addiu     $t0, $t0, 1
/* 366984 E0066954 8E230000 */  lw        $v1, ($s1)
/* 366988 E0066958 44050000 */  mfc1      $a1, $f0
/* 36698C E006695C 00621821 */  addu      $v1, $v1, $v0
/* 366990 E0066960 ACE30004 */  sw        $v1, 4($a3)
/* 366994 E0066964 8E870064 */  lw        $a3, 0x64($s4)
/* 366998 E0066968 00A0302D */  daddu     $a2, $a1, $zero
/* 36699C E006696C AEC90000 */  sw        $t1, ($s6)
/* 3669A0 E0066970 0C080108 */  jal       func_E0200420
/* 3669A4 E0066974 A6080000 */   sh       $t0, ($s0)
/* 3669A8 E0066978 27A40020 */  addiu     $a0, $sp, 0x20
/* 3669AC E006697C 96050000 */  lhu       $a1, ($s0)
/* 3669B0 E0066980 8E220000 */  lw        $v0, ($s1)
/* 3669B4 E0066984 00052980 */  sll       $a1, $a1, 6
/* 3669B8 E0066988 00B22821 */  addu      $a1, $a1, $s2
/* 3669BC E006698C 0C080118 */  jal       func_E0200460
/* 3669C0 E0066990 00452821 */   addu     $a1, $v0, $a1
/* 3669C4 E0066994 3C03DA38 */  lui       $v1, 0xda38
/* 3669C8 E0066998 34630002 */  ori       $v1, $v1, 2
/* 3669CC E006699C 0000602D */  daddu     $t4, $zero, $zero
/* 3669D0 E00669A0 8EC50000 */  lw        $a1, ($s6)
/* 3669D4 E00669A4 96020000 */  lhu       $v0, ($s0)
/* 3669D8 E00669A8 00A0202D */  daddu     $a0, $a1, $zero
/* 3669DC E00669AC 24A50008 */  addiu     $a1, $a1, 8
/* 3669E0 E00669B0 AEC50000 */  sw        $a1, ($s6)
/* 3669E4 E00669B4 AC830000 */  sw        $v1, ($a0)
/* 3669E8 E00669B8 24430001 */  addiu     $v1, $v0, 1
/* 3669EC E00669BC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3669F0 E00669C0 00021180 */  sll       $v0, $v0, 6
/* 3669F4 E00669C4 A6030000 */  sh        $v1, ($s0)
/* 3669F8 E00669C8 8E230000 */  lw        $v1, ($s1)
/* 3669FC E00669CC 00521021 */  addu      $v0, $v0, $s2
/* 366A00 E00669D0 00621821 */  addu      $v1, $v1, $v0
/* 366A04 E00669D4 24A20008 */  addiu     $v0, $a1, 8
/* 366A08 E00669D8 AC830004 */  sw        $v1, 4($a0)
/* 366A0C E00669DC AEC20000 */  sw        $v0, ($s6)
/* 366A10 E00669E0 8E870024 */  lw        $a3, 0x24($s4)
/* 366A14 E00669E4 3C02FB00 */  lui       $v0, 0xfb00
/* 366A18 E00669E8 ACA20000 */  sw        $v0, ($a1)
/* 366A1C E00669EC 9282006B */  lbu       $v0, 0x6b($s4)
/* 366A20 E00669F0 9284006C */  lbu       $a0, 0x6c($s4)
/* 366A24 E00669F4 9286006D */  lbu       $a2, 0x6d($s4)
/* 366A28 E00669F8 3C03DE00 */  lui       $v1, 0xde00
/* 366A2C E00669FC ACA30008 */  sw        $v1, 8($a1)
/* 366A30 E0066A00 ACB3000C */  sw        $s3, 0xc($a1)
/* 366A34 E0066A04 00021600 */  sll       $v0, $v0, 0x18
/* 366A38 E0066A08 00042400 */  sll       $a0, $a0, 0x10
/* 366A3C E0066A0C 00441025 */  or        $v0, $v0, $a0
/* 366A40 E0066A10 00063200 */  sll       $a2, $a2, 8
/* 366A44 E0066A14 00461025 */  or        $v0, $v0, $a2
/* 366A48 E0066A18 3442007F */  ori       $v0, $v0, 0x7f
/* 366A4C E0066A1C ACA20004 */  sw        $v0, 4($a1)
/* 366A50 E0066A20 8EE20008 */  lw        $v0, 8($s7)
/* 366A54 E0066A24 24A50010 */  addiu     $a1, $a1, 0x10
/* 366A58 E0066A28 1840005E */  blez      $v0, .LE0066BA4
/* 366A5C E0066A2C AEC50000 */   sw       $a1, ($s6)
/* 366A60 E0066A30 02C0582D */  daddu     $t3, $s6, $zero
/* 366A64 E0066A34 3C16FA00 */  lui       $s6, 0xfa00
/* 366A68 E0066A38 30F000FF */  andi      $s0, $a3, 0xff
/* 366A6C E0066A3C 24130008 */  addiu     $s3, $zero, 8
/* 366A70 E0066A40 2AAF0009 */  slti      $t7, $s5, 9
/* 366A74 E0066A44 2412000B */  addiu     $s2, $zero, 0xb
/* 366A78 E0066A48 2AAE0002 */  slti      $t6, $s5, 2
/* 366A7C E0066A4C 3C0DF200 */  lui       $t5, 0xf200
/* 366A80 E0066A50 3C110100 */  lui       $s1, 0x100
/* 366A84 E0066A54 268A0048 */  addiu     $t2, $s4, 0x48
.LE0066A58:
/* 366A88 E0066A58 8D620000 */  lw        $v0, ($t3)
/* 366A8C E0066A5C 0040282D */  daddu     $a1, $v0, $zero
/* 366A90 E0066A60 24420008 */  addiu     $v0, $v0, 8
/* 366A94 E0066A64 AD620000 */  sw        $v0, ($t3)
/* 366A98 E0066A68 ACB60000 */  sw        $s6, ($a1)
/* 366A9C E0066A6C 91420020 */  lbu       $v0, 0x20($t2)
/* 366AA0 E0066A70 91440021 */  lbu       $a0, 0x21($t2)
/* 366AA4 E0066A74 91430022 */  lbu       $v1, 0x22($t2)
/* 366AA8 E0066A78 00021600 */  sll       $v0, $v0, 0x18
/* 366AAC E0066A7C 00042400 */  sll       $a0, $a0, 0x10
/* 366AB0 E0066A80 00441025 */  or        $v0, $v0, $a0
/* 366AB4 E0066A84 00031A00 */  sll       $v1, $v1, 8
/* 366AB8 E0066A88 00431025 */  or        $v0, $v0, $v1
/* 366ABC E0066A8C 00501025 */  or        $v0, $v0, $s0
/* 366AC0 E0066A90 12B30007 */  beq       $s5, $s3, .LE0066AB0
/* 366AC4 E0066A94 ACA20004 */   sw       $v0, 4($a1)
/* 366AC8 E0066A98 15E00008 */  bnez      $t7, .LE0066ABC
/* 366ACC E0066A9C 2409003F */   addiu    $t1, $zero, 0x3f
/* 366AD0 E0066AA0 12B20007 */  beq       $s5, $s2, .LE0066AC0
/* 366AD4 E0066AA4 240700FF */   addiu    $a3, $zero, 0xff
/* 366AD8 E0066AA8 08019AB0 */  j         .LE0066AC0
/* 366ADC E0066AAC 240701FF */   addiu    $a3, $zero, 0x1ff
.LE0066AB0:
/* 366AE0 E0066AB0 2409003F */  addiu     $t1, $zero, 0x3f
/* 366AE4 E0066AB4 08019AB0 */  j         .LE0066AC0
/* 366AE8 E0066AB8 2407007F */   addiu    $a3, $zero, 0x7f
.LE0066ABC:
/* 366AEC E0066ABC 240701FF */  addiu     $a3, $zero, 0x1ff
.LE0066AC0:
/* 366AF0 E0066AC0 258C0001 */  addiu     $t4, $t4, 1
/* 366AF4 E0066AC4 C540FFE8 */  lwc1      $f0, -0x18($t2)
/* 366AF8 E0066AC8 C542FFF8 */  lwc1      $f2, -8($t2)
/* 366AFC E0066ACC C544FFF0 */  lwc1      $f4, -0x10($t2)
/* 366B00 E0066AD0 C5460000 */  lwc1      $f6, ($t2)
/* 366B04 E0066AD4 254A0070 */  addiu     $t2, $t2, 0x70
/* 366B08 E0066AD8 00094880 */  sll       $t1, $t1, 2
/* 366B0C E0066ADC 8D660000 */  lw        $a2, ($t3)
/* 366B10 E0066AE0 00073880 */  sll       $a3, $a3, 2
/* 366B14 E0066AE4 00C0402D */  daddu     $t0, $a2, $zero
/* 366B18 E0066AE8 24C60008 */  addiu     $a2, $a2, 8
/* 366B1C E0066AEC 4600020D */  trunc.w.s $f8, $f0
/* 366B20 E0066AF0 44044000 */  mfc1      $a0, $f8
/* 366B24 E0066AF4 4600120D */  trunc.w.s $f8, $f2
/* 366B28 E0066AF8 44054000 */  mfc1      $a1, $f8
/* 366B2C E0066AFC 30830FFF */  andi      $v1, $a0, 0xfff
/* 366B30 E0066B00 00031B00 */  sll       $v1, $v1, 0xc
/* 366B34 E0066B04 30A20FFF */  andi      $v0, $a1, 0xfff
/* 366B38 E0066B08 004D1025 */  or        $v0, $v0, $t5
/* 366B3C E0066B0C 00621825 */  or        $v1, $v1, $v0
/* 366B40 E0066B10 00892021 */  addu      $a0, $a0, $t1
/* 366B44 E0066B14 30840FFF */  andi      $a0, $a0, 0xfff
/* 366B48 E0066B18 00042300 */  sll       $a0, $a0, 0xc
/* 366B4C E0066B1C 00A72821 */  addu      $a1, $a1, $a3
/* 366B50 E0066B20 30A50FFF */  andi      $a1, $a1, 0xfff
/* 366B54 E0066B24 00852025 */  or        $a0, $a0, $a1
/* 366B58 E0066B28 24C20008 */  addiu     $v0, $a2, 8
/* 366B5C E0066B2C AD660000 */  sw        $a2, ($t3)
/* 366B60 E0066B30 AD040004 */  sw        $a0, 4($t0)
/* 366B64 E0066B34 4600220D */  trunc.w.s $f8, $f4
/* 366B68 E0066B38 44044000 */  mfc1      $a0, $f8
/* 366B6C E0066B3C 4600320D */  trunc.w.s $f8, $f6
/* 366B70 E0066B40 44054000 */  mfc1      $a1, $f8
/* 366B74 E0066B44 AD030000 */  sw        $v1, ($t0)
/* 366B78 E0066B48 30830FFF */  andi      $v1, $a0, 0xfff
/* 366B7C E0066B4C 00031B00 */  sll       $v1, $v1, 0xc
/* 366B80 E0066B50 AD620000 */  sw        $v0, ($t3)
/* 366B84 E0066B54 30A20FFF */  andi      $v0, $a1, 0xfff
/* 366B88 E0066B58 004D1025 */  or        $v0, $v0, $t5
/* 366B8C E0066B5C 00621825 */  or        $v1, $v1, $v0
/* 366B90 E0066B60 00892021 */  addu      $a0, $a0, $t1
/* 366B94 E0066B64 30840FFF */  andi      $a0, $a0, 0xfff
/* 366B98 E0066B68 00042300 */  sll       $a0, $a0, 0xc
/* 366B9C E0066B6C 00A72821 */  addu      $a1, $a1, $a3
/* 366BA0 E0066B70 30A50FFF */  andi      $a1, $a1, 0xfff
/* 366BA4 E0066B74 00B12825 */  or        $a1, $a1, $s1
/* 366BA8 E0066B78 00852025 */  or        $a0, $a0, $a1
/* 366BAC E0066B7C 3C02DE00 */  lui       $v0, 0xde00
/* 366BB0 E0066B80 ACC30000 */  sw        $v1, ($a2)
/* 366BB4 E0066B84 ACC40004 */  sw        $a0, 4($a2)
/* 366BB8 E0066B88 ACC20008 */  sw        $v0, 8($a2)
/* 366BBC E0066B8C ACDE000C */  sw        $fp, 0xc($a2)
/* 366BC0 E0066B90 8EE20008 */  lw        $v0, 8($s7)
/* 366BC4 E0066B94 24C60010 */  addiu     $a2, $a2, 0x10
/* 366BC8 E0066B98 0182102A */  slt       $v0, $t4, $v0
/* 366BCC E0066B9C 1440FFAE */  bnez      $v0, .LE0066A58
/* 366BD0 E0066BA0 AD660000 */   sw       $a2, ($t3)
.LE0066BA4:
/* 366BD4 E0066BA4 3C02D838 */  lui       $v0, 0xd838
/* 366BD8 E0066BA8 34420002 */  ori       $v0, $v0, 2
/* 366BDC E0066BAC 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 366BE0 E0066BB0 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 366BE4 E0066BB4 8CA40000 */  lw        $a0, ($a1)
/* 366BE8 E0066BB8 3C06DA38 */  lui       $a2, 0xda38
/* 366BEC E0066BBC 0080182D */  daddu     $v1, $a0, $zero
/* 366BF0 E0066BC0 24840008 */  addiu     $a0, $a0, 8
/* 366BF4 E0066BC4 ACA40000 */  sw        $a0, ($a1)
/* 366BF8 E0066BC8 AC620000 */  sw        $v0, ($v1)
/* 366BFC E0066BCC 24020040 */  addiu     $v0, $zero, 0x40
/* 366C00 E0066BD0 AC620004 */  sw        $v0, 4($v1)
/* 366C04 E0066BD4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 366C08 E0066BD8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 366C0C E0066BDC 24820008 */  addiu     $v0, $a0, 8
/* 366C10 E0066BE0 ACA20000 */  sw        $v0, ($a1)
/* 366C14 E0066BE4 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 366C18 E0066BE8 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 366C1C E0066BEC 34C60007 */  ori       $a2, $a2, 7
/* 366C20 E0066BF0 AC860000 */  sw        $a2, ($a0)
/* 366C24 E0066BF4 00031980 */  sll       $v1, $v1, 6
/* 366C28 E0066BF8 24630030 */  addiu     $v1, $v1, 0x30
/* 366C2C E0066BFC 00431021 */  addu      $v0, $v0, $v1
/* 366C30 E0066C00 AC820004 */  sw        $v0, 4($a0)
/* 366C34 E0066C04 24820010 */  addiu     $v0, $a0, 0x10
/* 366C38 E0066C08 ACA20000 */  sw        $v0, ($a1)
/* 366C3C E0066C0C 3C02E700 */  lui       $v0, 0xe700
/* 366C40 E0066C10 AC820008 */  sw        $v0, 8($a0)
/* 366C44 E0066C14 AC80000C */  sw        $zero, 0xc($a0)
/* 366C48 E0066C18 8FBF00CC */  lw        $ra, 0xcc($sp)
/* 366C4C E0066C1C 8FBE00C8 */  lw        $fp, 0xc8($sp)
/* 366C50 E0066C20 8FB700C4 */  lw        $s7, 0xc4($sp)
/* 366C54 E0066C24 8FB600C0 */  lw        $s6, 0xc0($sp)
/* 366C58 E0066C28 8FB500BC */  lw        $s5, 0xbc($sp)
/* 366C5C E0066C2C 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 366C60 E0066C30 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 366C64 E0066C34 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 366C68 E0066C38 8FB100AC */  lw        $s1, 0xac($sp)
/* 366C6C E0066C3C 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 366C70 E0066C40 D7B400D0 */  ldc1      $f20, 0xd0($sp)
/* 366C74 E0066C44 03E00008 */  jr        $ra
/* 366C78 E0066C48 27BD00D8 */   addiu    $sp, $sp, 0xd8
/* 366C7C E0066C4C 00000000 */  nop
