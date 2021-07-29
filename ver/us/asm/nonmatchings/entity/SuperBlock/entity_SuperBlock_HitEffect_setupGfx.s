.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_SuperBlock_HitEffect_setupGfx
/* 1070EC 802E586C 27BDFF68 */  addiu     $sp, $sp, -0x98
/* 1070F0 802E5870 AFB60088 */  sw        $s6, 0x88($sp)
/* 1070F4 802E5874 3C16800A */  lui       $s6, %hi(gMasterGfxPos)
/* 1070F8 802E5878 8ED6A66C */  lw        $s6, %lo(gMasterGfxPos)($s6)
/* 1070FC 802E587C AFBF0094 */  sw        $ra, 0x94($sp)
/* 107100 802E5880 AFBE0090 */  sw        $fp, 0x90($sp)
/* 107104 802E5884 AFB7008C */  sw        $s7, 0x8c($sp)
/* 107108 802E5888 AFB50084 */  sw        $s5, 0x84($sp)
/* 10710C 802E588C AFB40080 */  sw        $s4, 0x80($sp)
/* 107110 802E5890 AFB3007C */  sw        $s3, 0x7c($sp)
/* 107114 802E5894 AFB20078 */  sw        $s2, 0x78($sp)
/* 107118 802E5898 AFB10074 */  sw        $s1, 0x74($sp)
/* 10711C 802E589C 0C04417A */  jal       get_entity_by_index
/* 107120 802E58A0 AFB00070 */   sw       $s0, 0x70($sp)
/* 107124 802E58A4 AFA20060 */  sw        $v0, 0x60($sp)
/* 107128 802E58A8 8C570040 */  lw        $s7, 0x40($v0)
/* 10712C 802E58AC 92E20008 */  lbu       $v0, 8($s7)
/* 107130 802E58B0 14400011 */  bnez      $v0, .L802E58F8
/* 107134 802E58B4 2442FFFF */   addiu    $v0, $v0, -1
/* 107138 802E58B8 92E30009 */  lbu       $v1, 9($s7)
/* 10713C 802E58BC 3C05802F */  lui       $a1, %hi(D_802EA870)
/* 107140 802E58C0 24A5A870 */  addiu     $a1, $a1, %lo(D_802EA870)
/* 107144 802E58C4 24630002 */  addiu     $v1, $v1, 2
/* 107148 802E58C8 3C02802F */  lui       $v0, %hi(D_802EA870)
/* 10714C 802E58CC 00431021 */  addu      $v0, $v0, $v1
/* 107150 802E58D0 8042A870 */  lb        $v0, %lo(D_802EA870)($v0)
/* 107154 802E58D4 3C04802F */  lui       $a0, %hi(D_802EA870)
/* 107158 802E58D8 00832021 */  addu      $a0, $a0, $v1
/* 10715C 802E58DC 18400004 */  blez      $v0, .L802E58F0
/* 107160 802E58E0 9084A870 */   lbu      $a0, %lo(D_802EA870)($a0)
/* 107164 802E58E4 A2E40008 */  sb        $a0, 8($s7)
/* 107168 802E58E8 080B963F */  j         .L802E58FC
/* 10716C 802E58EC A2E30009 */   sb       $v1, 9($s7)
.L802E58F0:
/* 107170 802E58F0 90A20000 */  lbu       $v0, ($a1)
/* 107174 802E58F4 A2E00009 */  sb        $zero, 9($s7)
.L802E58F8:
/* 107178 802E58F8 A2E20008 */  sb        $v0, 8($s7)
.L802E58FC:
/* 10717C 802E58FC 02C0382D */  daddu     $a3, $s6, $zero
/* 107180 802E5900 26D60008 */  addiu     $s6, $s6, 8
/* 107184 802E5904 02E0202D */  daddu     $a0, $s7, $zero
/* 107188 802E5908 24050001 */  addiu     $a1, $zero, 1
/* 10718C 802E590C 92E20009 */  lbu       $v0, 9($s7)
/* 107190 802E5910 8FAF0060 */  lw        $t7, 0x60($sp)
/* 107194 802E5914 8EF5012C */  lw        $s5, 0x12c($s7)
/* 107198 802E5918 3C01802F */  lui       $at, %hi(D_802EA871)
/* 10719C 802E591C 00220821 */  addu      $at, $at, $v0
/* 1071A0 802E5920 8022A871 */  lb        $v0, %lo(D_802EA871)($at)
/* 1071A4 802E5924 8DE30044 */  lw        $v1, 0x44($t7)
/* 1071A8 802E5928 00021080 */  sll       $v0, $v0, 2
/* 1071AC 802E592C 3C06802F */  lui       $a2, %hi(D_802EA862)
/* 1071B0 802E5930 00C23021 */  addu      $a2, $a2, $v0
/* 1071B4 802E5934 94C6A862 */  lhu       $a2, %lo(D_802EA862)($a2)
/* 1071B8 802E5938 3C02E700 */  lui       $v0, 0xe700
/* 1071BC 802E593C AFB50058 */  sw        $s5, 0x58($sp)
/* 1071C0 802E5940 ACE20000 */  sw        $v0, ($a3)
/* 1071C4 802E5944 ACE00004 */  sw        $zero, 4($a3)
/* 1071C8 802E5948 00661821 */  addu      $v1, $v1, $a2
/* 1071CC 802E594C 0C0B959C */  jal       entity_SuperBlockContent_get_previous_yaw
/* 1071D0 802E5950 AFA3005C */   sw       $v1, 0x5c($sp)
/* 1071D4 802E5954 44050000 */  mfc1      $a1, $f0
/* 1071D8 802E5958 44800000 */  mtc1      $zero, $f0
/* 1071DC 802E595C 3C073F80 */  lui       $a3, 0x3f80
/* 1071E0 802E5960 44060000 */  mfc1      $a2, $f0
/* 1071E4 802E5964 27A40018 */  addiu     $a0, $sp, 0x18
/* 1071E8 802E5968 0C019EC8 */  jal       guRotateF
/* 1071EC 802E596C AFA60010 */   sw       $a2, 0x10($sp)
/* 1071F0 802E5970 27A40018 */  addiu     $a0, $sp, 0x18
/* 1071F4 802E5974 26F00010 */  addiu     $s0, $s7, 0x10
/* 1071F8 802E5978 0C019D40 */  jal       guMtxF2L
/* 1071FC 802E597C 0200282D */   daddu    $a1, $s0, $zero
/* 107200 802E5980 3C040001 */  lui       $a0, 1
/* 107204 802E5984 34841630 */  ori       $a0, $a0, 0x1630
/* 107208 802E5988 26E50050 */  addiu     $a1, $s7, 0x50
/* 10720C 802E598C 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 107210 802E5990 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* 107214 802E5994 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 107218 802E5998 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 10721C 802E599C 00021180 */  sll       $v0, $v0, 6
/* 107220 802E59A0 00621821 */  addu      $v1, $v1, $v0
/* 107224 802E59A4 00641821 */  addu      $v1, $v1, $a0
.L802E59A8:
/* 107228 802E59A8 8E180000 */  lw        $t8, ($s0)
/* 10722C 802E59AC 8E190004 */  lw        $t9, 4($s0)
/* 107230 802E59B0 8E0F0008 */  lw        $t7, 8($s0)
/* 107234 802E59B4 8E15000C */  lw        $s5, 0xc($s0)
/* 107238 802E59B8 AC780000 */  sw        $t8, ($v1)
/* 10723C 802E59BC AC790004 */  sw        $t9, 4($v1)
/* 107240 802E59C0 AC6F0008 */  sw        $t7, 8($v1)
/* 107244 802E59C4 AC75000C */  sw        $s5, 0xc($v1)
/* 107248 802E59C8 26100010 */  addiu     $s0, $s0, 0x10
/* 10724C 802E59CC 1605FFF6 */  bne       $s0, $a1, .L802E59A8
/* 107250 802E59D0 24630010 */   addiu    $v1, $v1, 0x10
/* 107254 802E59D4 02C0702D */  daddu     $t6, $s6, $zero
/* 107258 802E59D8 26D60008 */  addiu     $s6, $s6, 8
/* 10725C 802E59DC 3C180001 */  lui       $t8, 1
/* 107260 802E59E0 37181630 */  ori       $t8, $t8, 0x1630
/* 107264 802E59E4 02C0682D */  daddu     $t5, $s6, $zero
/* 107268 802E59E8 26D60008 */  addiu     $s6, $s6, 8
/* 10726C 802E59EC 3C19E200 */  lui       $t9, 0xe200
/* 107270 802E59F0 3739001C */  ori       $t9, $t9, 0x1c
/* 107274 802E59F4 3C140055 */  lui       $s4, 0x55
/* 107278 802E59F8 36943078 */  ori       $s4, $s4, 0x3078
/* 10727C 802E59FC 02C0582D */  daddu     $t3, $s6, $zero
/* 107280 802E5A00 26D60008 */  addiu     $s6, $s6, 8
/* 107284 802E5A04 3C12FC12 */  lui       $s2, 0xfc12
/* 107288 802E5A08 36521824 */  ori       $s2, $s2, 0x1824
/* 10728C 802E5A0C 3C10FF33 */  lui       $s0, 0xff33
/* 107290 802E5A10 3610FFFF */  ori       $s0, $s0, 0xffff
/* 107294 802E5A14 02C0202D */  daddu     $a0, $s6, $zero
/* 107298 802E5A18 26D60008 */  addiu     $s6, $s6, 8
/* 10729C 802E5A1C 02C0282D */  daddu     $a1, $s6, $zero
/* 1072A0 802E5A20 26D60008 */  addiu     $s6, $s6, 8
/* 1072A4 802E5A24 02C0402D */  daddu     $t0, $s6, $zero
/* 1072A8 802E5A28 26D60008 */  addiu     $s6, $s6, 8
/* 1072AC 802E5A2C 3C0FF500 */  lui       $t7, 0xf500
/* 1072B0 802E5A30 35EF0100 */  ori       $t7, $t7, 0x100
/* 1072B4 802E5A34 02C0302D */  daddu     $a2, $s6, $zero
/* 1072B8 802E5A38 26D60008 */  addiu     $s6, $s6, 8
/* 1072BC 802E5A3C 02C0482D */  daddu     $t1, $s6, $zero
/* 1072C0 802E5A40 26D60008 */  addiu     $s6, $s6, 8
/* 1072C4 802E5A44 3C130703 */  lui       $s3, 0x703
/* 1072C8 802E5A48 3673C000 */  ori       $s3, $s3, 0xc000
/* 1072CC 802E5A4C 02C0382D */  daddu     $a3, $s6, $zero
/* 1072D0 802E5A50 26D60008 */  addiu     $s6, $s6, 8
/* 1072D4 802E5A54 02C0502D */  daddu     $t2, $s6, $zero
/* 1072D8 802E5A58 26D60008 */  addiu     $s6, $s6, 8
/* 1072DC 802E5A5C 02C0602D */  daddu     $t4, $s6, $zero
/* 1072E0 802E5A60 3C11D838 */  lui       $s1, 0xd838
/* 1072E4 802E5A64 36310002 */  ori       $s1, $s1, 2
/* 1072E8 802E5A68 3C1E8007 */  lui       $fp, %hi(gMatrixListPos)
/* 1072EC 802E5A6C 27DE41F0 */  addiu     $fp, $fp, %lo(gMatrixListPos)
/* 1072F0 802E5A70 AFB80064 */  sw        $t8, 0x64($sp)
/* 1072F4 802E5A74 97C20000 */  lhu       $v0, ($fp)
/* 1072F8 802E5A78 3C03DA38 */  lui       $v1, 0xda38
/* 1072FC 802E5A7C ADC30000 */  sw        $v1, ($t6)
/* 107300 802E5A80 24430001 */  addiu     $v1, $v0, 1
/* 107304 802E5A84 3042FFFF */  andi      $v0, $v0, 0xffff
/* 107308 802E5A88 00021180 */  sll       $v0, $v0, 6
/* 10730C 802E5A8C A7C30000 */  sh        $v1, ($fp)
/* 107310 802E5A90 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 107314 802E5A94 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 107318 802E5A98 00581021 */  addu      $v0, $v0, $t8
/* 10731C 802E5A9C 00621821 */  addu      $v1, $v1, $v0
/* 107320 802E5AA0 3C02FD10 */  lui       $v0, 0xfd10
/* 107324 802E5AA4 ADC30004 */  sw        $v1, 4($t6)
/* 107328 802E5AA8 ADB90000 */  sw        $t9, ($t5)
/* 10732C 802E5AAC ADB40004 */  sw        $s4, 4($t5)
/* 107330 802E5AB0 AD720000 */  sw        $s2, ($t3)
/* 107334 802E5AB4 AD700004 */  sw        $s0, 4($t3)
/* 107338 802E5AB8 AC820000 */  sw        $v0, ($a0)
/* 10733C 802E5ABC 8FB5005C */  lw        $s5, 0x5c($sp)
/* 107340 802E5AC0 3C02E800 */  lui       $v0, 0xe800
/* 107344 802E5AC4 AC950004 */  sw        $s5, 4($a0)
/* 107348 802E5AC8 ACA20000 */  sw        $v0, ($a1)
/* 10734C 802E5ACC 3C020700 */  lui       $v0, 0x700
/* 107350 802E5AD0 ACA00004 */  sw        $zero, 4($a1)
/* 107354 802E5AD4 AD020004 */  sw        $v0, 4($t0)
/* 107358 802E5AD8 3C02E600 */  lui       $v0, 0xe600
/* 10735C 802E5ADC AD0F0000 */  sw        $t7, ($t0)
/* 107360 802E5AE0 ACC20000 */  sw        $v0, ($a2)
/* 107364 802E5AE4 3C02F000 */  lui       $v0, 0xf000
/* 107368 802E5AE8 ACC00004 */  sw        $zero, 4($a2)
/* 10736C 802E5AEC 3C06E700 */  lui       $a2, 0xe700
/* 107370 802E5AF0 AD220000 */  sw        $v0, ($t1)
/* 107374 802E5AF4 3C02DE00 */  lui       $v0, 0xde00
/* 107378 802E5AF8 AD330004 */  sw        $s3, 4($t1)
/* 10737C 802E5AFC ACE60000 */  sw        $a2, ($a3)
/* 107380 802E5B00 ACE00004 */  sw        $zero, 4($a3)
/* 107384 802E5B04 AD420000 */  sw        $v0, ($t2)
/* 107388 802E5B08 8FB80058 */  lw        $t8, 0x58($sp)
/* 10738C 802E5B0C 24020040 */  addiu     $v0, $zero, 0x40
/* 107390 802E5B10 AD580004 */  sw        $t8, 4($t2)
/* 107394 802E5B14 AD910000 */  sw        $s1, ($t4)
/* 107398 802E5B18 AD820004 */  sw        $v0, 4($t4)
/* 10739C 802E5B1C 8FB90060 */  lw        $t9, 0x60($sp)
/* 1073A0 802E5B20 9323000B */  lbu       $v1, 0xb($t9)
/* 1073A4 802E5B24 24110078 */  addiu     $s1, $zero, 0x78
/* 1073A8 802E5B28 0071102A */  slt       $v0, $v1, $s1
/* 1073AC 802E5B2C 10400002 */  beqz      $v0, .L802E5B38
/* 1073B0 802E5B30 26D60008 */   addiu    $s6, $s6, 8
/* 1073B4 802E5B34 0060882D */  daddu     $s1, $v1, $zero
.L802E5B38:
/* 1073B8 802E5B38 02C0102D */  daddu     $v0, $s6, $zero
/* 1073BC 802E5B3C 26D60008 */  addiu     $s6, $s6, 8
/* 1073C0 802E5B40 02E0202D */  daddu     $a0, $s7, $zero
/* 1073C4 802E5B44 24050006 */  addiu     $a1, $zero, 6
/* 1073C8 802E5B48 AC460000 */  sw        $a2, ($v0)
/* 1073CC 802E5B4C 0C0B959C */  jal       entity_SuperBlockContent_get_previous_yaw
/* 1073D0 802E5B50 AC400004 */   sw       $zero, 4($v0)
/* 1073D4 802E5B54 44050000 */  mfc1      $a1, $f0
/* 1073D8 802E5B58 44800000 */  mtc1      $zero, $f0
/* 1073DC 802E5B5C 3C073F80 */  lui       $a3, 0x3f80
/* 1073E0 802E5B60 44060000 */  mfc1      $a2, $f0
/* 1073E4 802E5B64 27A40018 */  addiu     $a0, $sp, 0x18
/* 1073E8 802E5B68 0C019EC8 */  jal       guRotateF
/* 1073EC 802E5B6C AFA60010 */   sw       $a2, 0x10($sp)
/* 1073F0 802E5B70 27A40018 */  addiu     $a0, $sp, 0x18
/* 1073F4 802E5B74 26F00050 */  addiu     $s0, $s7, 0x50
/* 1073F8 802E5B78 0C019D40 */  jal       guMtxF2L
/* 1073FC 802E5B7C 0200282D */   daddu    $a1, $s0, $zero
/* 107400 802E5B80 26E40090 */  addiu     $a0, $s7, 0x90
/* 107404 802E5B84 97C20000 */  lhu       $v0, ($fp)
/* 107408 802E5B88 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 10740C 802E5B8C 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 107410 802E5B90 8FAF0064 */  lw        $t7, 0x64($sp)
/* 107414 802E5B94 00021180 */  sll       $v0, $v0, 6
/* 107418 802E5B98 00621821 */  addu      $v1, $v1, $v0
/* 10741C 802E5B9C 006F1821 */  addu      $v1, $v1, $t7
.L802E5BA0:
/* 107420 802E5BA0 8E150000 */  lw        $s5, ($s0)
/* 107424 802E5BA4 8E180004 */  lw        $t8, 4($s0)
/* 107428 802E5BA8 8E190008 */  lw        $t9, 8($s0)
/* 10742C 802E5BAC 8E0F000C */  lw        $t7, 0xc($s0)
/* 107430 802E5BB0 AC750000 */  sw        $s5, ($v1)
/* 107434 802E5BB4 AC780004 */  sw        $t8, 4($v1)
/* 107438 802E5BB8 AC790008 */  sw        $t9, 8($v1)
/* 10743C 802E5BBC AC6F000C */  sw        $t7, 0xc($v1)
/* 107440 802E5BC0 26100010 */  addiu     $s0, $s0, 0x10
/* 107444 802E5BC4 1604FFF6 */  bne       $s0, $a0, .L802E5BA0
/* 107448 802E5BC8 24630010 */   addiu    $v1, $v1, 0x10
/* 10744C 802E5BCC 02C0482D */  daddu     $t1, $s6, $zero
/* 107450 802E5BD0 26D60008 */  addiu     $s6, $s6, 8
/* 107454 802E5BD4 3C130001 */  lui       $s3, 1
/* 107458 802E5BD8 36731630 */  ori       $s3, $s3, 0x1630
/* 10745C 802E5BDC 02C0402D */  daddu     $t0, $s6, $zero
/* 107460 802E5BE0 26D60008 */  addiu     $s6, $s6, 8
/* 107464 802E5BE4 3C0EE200 */  lui       $t6, 0xe200
/* 107468 802E5BE8 35CE001C */  ori       $t6, $t6, 0x1c
/* 10746C 802E5BEC 3C0D0050 */  lui       $t5, 0x50
/* 107470 802E5BF0 35AD4358 */  ori       $t5, $t5, 0x4358
/* 107474 802E5BF4 02C0382D */  daddu     $a3, $s6, $zero
/* 107478 802E5BF8 26D60008 */  addiu     $s6, $s6, 8
/* 10747C 802E5BFC 3C0CFCFF */  lui       $t4, 0xfcff
/* 107480 802E5C00 358CB3FF */  ori       $t4, $t4, 0xb3ff
/* 107484 802E5C04 3C0BFF2C */  lui       $t3, 0xff2c
/* 107488 802E5C08 356BFE7F */  ori       $t3, $t3, 0xfe7f
/* 10748C 802E5C0C 02C0202D */  daddu     $a0, $s6, $zero
/* 107490 802E5C10 26D60008 */  addiu     $s6, $s6, 8
/* 107494 802E5C14 02C0282D */  daddu     $a1, $s6, $zero
/* 107498 802E5C18 26D60008 */  addiu     $s6, $s6, 8
/* 10749C 802E5C1C 02C0302D */  daddu     $a2, $s6, $zero
/* 1074A0 802E5C20 3C0AD838 */  lui       $t2, 0xd838
/* 1074A4 802E5C24 354A0002 */  ori       $t2, $t2, 2
/* 1074A8 802E5C28 3C128007 */  lui       $s2, %hi(gMatrixListPos)
/* 1074AC 802E5C2C 265241F0 */  addiu     $s2, $s2, %lo(gMatrixListPos)
/* 1074B0 802E5C30 3C03DA38 */  lui       $v1, 0xda38
/* 1074B4 802E5C34 96420000 */  lhu       $v0, ($s2)
/* 1074B8 802E5C38 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 1074BC 802E5C3C 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 1074C0 802E5C40 AD230000 */  sw        $v1, ($t1)
/* 1074C4 802E5C44 24430001 */  addiu     $v1, $v0, 1
/* 1074C8 802E5C48 3042FFFF */  andi      $v0, $v0, 0xffff
/* 1074CC 802E5C4C 00021180 */  sll       $v0, $v0, 6
/* 1074D0 802E5C50 A6430000 */  sh        $v1, ($s2)
/* 1074D4 802E5C54 8E830000 */  lw        $v1, ($s4)
/* 1074D8 802E5C58 00531021 */  addu      $v0, $v0, $s3
/* 1074DC 802E5C5C 00621821 */  addu      $v1, $v1, $v0
/* 1074E0 802E5C60 3C02FA00 */  lui       $v0, 0xfa00
/* 1074E4 802E5C64 AD230004 */  sw        $v1, 4($t1)
/* 1074E8 802E5C68 AD0E0000 */  sw        $t6, ($t0)
/* 1074EC 802E5C6C AD0D0004 */  sw        $t5, 4($t0)
/* 1074F0 802E5C70 ACEC0000 */  sw        $t4, ($a3)
/* 1074F4 802E5C74 ACEB0004 */  sw        $t3, 4($a3)
/* 1074F8 802E5C78 AC820000 */  sw        $v0, ($a0)
/* 1074FC 802E5C7C 3C02DE00 */  lui       $v0, 0xde00
/* 107500 802E5C80 AC910004 */  sw        $s1, 4($a0)
/* 107504 802E5C84 ACA20000 */  sw        $v0, ($a1)
/* 107508 802E5C88 8FB50058 */  lw        $s5, 0x58($sp)
/* 10750C 802E5C8C 24020040 */  addiu     $v0, $zero, 0x40
/* 107510 802E5C90 ACB50004 */  sw        $s5, 4($a1)
/* 107514 802E5C94 ACCA0000 */  sw        $t2, ($a2)
/* 107518 802E5C98 ACC20004 */  sw        $v0, 4($a2)
/* 10751C 802E5C9C 8FB80060 */  lw        $t8, 0x60($sp)
/* 107520 802E5CA0 9303000B */  lbu       $v1, 0xb($t8)
/* 107524 802E5CA4 24110050 */  addiu     $s1, $zero, 0x50
/* 107528 802E5CA8 0071102A */  slt       $v0, $v1, $s1
/* 10752C 802E5CAC 10400002 */  beqz      $v0, .L802E5CB8
/* 107530 802E5CB0 26D60008 */   addiu    $s6, $s6, 8
/* 107534 802E5CB4 0060882D */  daddu     $s1, $v1, $zero
.L802E5CB8:
/* 107538 802E5CB8 02C0182D */  daddu     $v1, $s6, $zero
/* 10753C 802E5CBC 26D60008 */  addiu     $s6, $s6, 8
/* 107540 802E5CC0 02E0202D */  daddu     $a0, $s7, $zero
/* 107544 802E5CC4 2405000A */  addiu     $a1, $zero, 0xa
/* 107548 802E5CC8 3C02E700 */  lui       $v0, 0xe700
/* 10754C 802E5CCC AC620000 */  sw        $v0, ($v1)
/* 107550 802E5CD0 0C0B959C */  jal       entity_SuperBlockContent_get_previous_yaw
/* 107554 802E5CD4 AC600004 */   sw       $zero, 4($v1)
/* 107558 802E5CD8 44050000 */  mfc1      $a1, $f0
/* 10755C 802E5CDC 44800000 */  mtc1      $zero, $f0
/* 107560 802E5CE0 3C073F80 */  lui       $a3, 0x3f80
/* 107564 802E5CE4 44060000 */  mfc1      $a2, $f0
/* 107568 802E5CE8 27A40018 */  addiu     $a0, $sp, 0x18
/* 10756C 802E5CEC 0C019EC8 */  jal       guRotateF
/* 107570 802E5CF0 AFA60010 */   sw       $a2, 0x10($sp)
/* 107574 802E5CF4 27A40018 */  addiu     $a0, $sp, 0x18
/* 107578 802E5CF8 26F00090 */  addiu     $s0, $s7, 0x90
/* 10757C 802E5CFC 0C019D40 */  jal       guMtxF2L
/* 107580 802E5D00 0200282D */   daddu    $a1, $s0, $zero
/* 107584 802E5D04 26E400D0 */  addiu     $a0, $s7, 0xd0
/* 107588 802E5D08 96420000 */  lhu       $v0, ($s2)
/* 10758C 802E5D0C 8E830000 */  lw        $v1, ($s4)
/* 107590 802E5D10 00021180 */  sll       $v0, $v0, 6
/* 107594 802E5D14 00621821 */  addu      $v1, $v1, $v0
/* 107598 802E5D18 00731821 */  addu      $v1, $v1, $s3
.L802E5D1C:
/* 10759C 802E5D1C 8E190000 */  lw        $t9, ($s0)
/* 1075A0 802E5D20 8E0F0004 */  lw        $t7, 4($s0)
/* 1075A4 802E5D24 8E150008 */  lw        $s5, 8($s0)
/* 1075A8 802E5D28 8E18000C */  lw        $t8, 0xc($s0)
/* 1075AC 802E5D2C AC790000 */  sw        $t9, ($v1)
/* 1075B0 802E5D30 AC6F0004 */  sw        $t7, 4($v1)
/* 1075B4 802E5D34 AC750008 */  sw        $s5, 8($v1)
/* 1075B8 802E5D38 AC78000C */  sw        $t8, 0xc($v1)
/* 1075BC 802E5D3C 26100010 */  addiu     $s0, $s0, 0x10
/* 1075C0 802E5D40 1604FFF6 */  bne       $s0, $a0, .L802E5D1C
/* 1075C4 802E5D44 24630010 */   addiu    $v1, $v1, 0x10
/* 1075C8 802E5D48 02C0502D */  daddu     $t2, $s6, $zero
/* 1075CC 802E5D4C 26D60008 */  addiu     $s6, $s6, 8
/* 1075D0 802E5D50 3C100001 */  lui       $s0, 1
/* 1075D4 802E5D54 36101630 */  ori       $s0, $s0, 0x1630
/* 1075D8 802E5D58 02C0482D */  daddu     $t1, $s6, $zero
/* 1075DC 802E5D5C 26D60008 */  addiu     $s6, $s6, 8
/* 1075E0 802E5D60 3C19E200 */  lui       $t9, 0xe200
/* 1075E4 802E5D64 3739001C */  ori       $t9, $t9, 0x1c
/* 1075E8 802E5D68 3C0E0050 */  lui       $t6, 0x50
/* 1075EC 802E5D6C 35CE4358 */  ori       $t6, $t6, 0x4358
/* 1075F0 802E5D70 02C0402D */  daddu     $t0, $s6, $zero
/* 1075F4 802E5D74 26D60008 */  addiu     $s6, $s6, 8
/* 1075F8 802E5D78 3C0DFCFF */  lui       $t5, 0xfcff
/* 1075FC 802E5D7C 35ADB3FF */  ori       $t5, $t5, 0xb3ff
/* 107600 802E5D80 3C0CFF2C */  lui       $t4, 0xff2c
/* 107604 802E5D84 358CFE7F */  ori       $t4, $t4, 0xfe7f
/* 107608 802E5D88 02C0282D */  daddu     $a1, $s6, $zero
/* 10760C 802E5D8C 26D60008 */  addiu     $s6, $s6, 8
/* 107610 802E5D90 02C0302D */  daddu     $a2, $s6, $zero
/* 107614 802E5D94 26D60008 */  addiu     $s6, $s6, 8
/* 107618 802E5D98 02C0382D */  daddu     $a3, $s6, $zero
/* 10761C 802E5D9C 26D60008 */  addiu     $s6, $s6, 8
/* 107620 802E5DA0 3C0BD838 */  lui       $t3, 0xd838
/* 107624 802E5DA4 356B0002 */  ori       $t3, $t3, 2
/* 107628 802E5DA8 3C048007 */  lui       $a0, %hi(gMatrixListPos)
/* 10762C 802E5DAC 248441F0 */  addiu     $a0, $a0, %lo(gMatrixListPos)
/* 107630 802E5DB0 94820000 */  lhu       $v0, ($a0)
/* 107634 802E5DB4 3C03DA38 */  lui       $v1, 0xda38
/* 107638 802E5DB8 AD430000 */  sw        $v1, ($t2)
/* 10763C 802E5DBC 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 107640 802E5DC0 AC36A66C */  sw        $s6, %lo(gMasterGfxPos)($at)
/* 107644 802E5DC4 24430001 */  addiu     $v1, $v0, 1
/* 107648 802E5DC8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 10764C 802E5DCC 00021180 */  sll       $v0, $v0, 6
/* 107650 802E5DD0 A4830000 */  sh        $v1, ($a0)
/* 107654 802E5DD4 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 107658 802E5DD8 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 10765C 802E5DDC 00501021 */  addu      $v0, $v0, $s0
/* 107660 802E5DE0 00621821 */  addu      $v1, $v1, $v0
/* 107664 802E5DE4 3C02FA00 */  lui       $v0, 0xfa00
/* 107668 802E5DE8 AD430004 */  sw        $v1, 4($t2)
/* 10766C 802E5DEC AD390000 */  sw        $t9, ($t1)
/* 107670 802E5DF0 AD2E0004 */  sw        $t6, 4($t1)
/* 107674 802E5DF4 AD0D0000 */  sw        $t5, ($t0)
/* 107678 802E5DF8 AD0C0004 */  sw        $t4, 4($t0)
/* 10767C 802E5DFC ACA20000 */  sw        $v0, ($a1)
/* 107680 802E5E00 3C02DE00 */  lui       $v0, 0xde00
/* 107684 802E5E04 ACB10004 */  sw        $s1, 4($a1)
/* 107688 802E5E08 ACC20000 */  sw        $v0, ($a2)
/* 10768C 802E5E0C 8FAF0058 */  lw        $t7, 0x58($sp)
/* 107690 802E5E10 24020040 */  addiu     $v0, $zero, 0x40
/* 107694 802E5E14 ACCF0004 */  sw        $t7, 4($a2)
/* 107698 802E5E18 ACEB0000 */  sw        $t3, ($a3)
/* 10769C 802E5E1C ACE20004 */  sw        $v0, 4($a3)
/* 1076A0 802E5E20 8FBF0094 */  lw        $ra, 0x94($sp)
/* 1076A4 802E5E24 8FBE0090 */  lw        $fp, 0x90($sp)
/* 1076A8 802E5E28 8FB7008C */  lw        $s7, 0x8c($sp)
/* 1076AC 802E5E2C 8FB60088 */  lw        $s6, 0x88($sp)
/* 1076B0 802E5E30 8FB50084 */  lw        $s5, 0x84($sp)
/* 1076B4 802E5E34 8FB40080 */  lw        $s4, 0x80($sp)
/* 1076B8 802E5E38 8FB3007C */  lw        $s3, 0x7c($sp)
/* 1076BC 802E5E3C 8FB20078 */  lw        $s2, 0x78($sp)
/* 1076C0 802E5E40 8FB10074 */  lw        $s1, 0x74($sp)
/* 1076C4 802E5E44 8FB00070 */  lw        $s0, 0x70($sp)
/* 1076C8 802E5E48 03E00008 */  jr        $ra
/* 1076CC 802E5E4C 27BD0098 */   addiu    $sp, $sp, 0x98
