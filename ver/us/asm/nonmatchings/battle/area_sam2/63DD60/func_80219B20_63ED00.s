.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219B20_63ED00
/* 63ED00 80219B20 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 63ED04 80219B24 AFB60038 */  sw        $s6, 0x38($sp)
/* 63ED08 80219B28 0080B02D */  daddu     $s6, $a0, $zero
/* 63ED0C 80219B2C 27A50010 */  addiu     $a1, $sp, 0x10
/* 63ED10 80219B30 27A60014 */  addiu     $a2, $sp, 0x14
/* 63ED14 80219B34 27A70018 */  addiu     $a3, $sp, 0x18
/* 63ED18 80219B38 AFBF003C */  sw        $ra, 0x3c($sp)
/* 63ED1C 80219B3C AFB50034 */  sw        $s5, 0x34($sp)
/* 63ED20 80219B40 AFB40030 */  sw        $s4, 0x30($sp)
/* 63ED24 80219B44 AFB3002C */  sw        $s3, 0x2c($sp)
/* 63ED28 80219B48 AFB20028 */  sw        $s2, 0x28($sp)
/* 63ED2C 80219B4C AFB10024 */  sw        $s1, 0x24($sp)
/* 63ED30 80219B50 0C0470AC */  jal       mdl_get_copied_vertices
/* 63ED34 80219B54 AFB00020 */   sw       $s0, 0x20($sp)
/* 63ED38 80219B58 8FA20018 */  lw        $v0, 0x18($sp)
/* 63ED3C 80219B5C 18400052 */  blez      $v0, .L80219CA8
/* 63ED40 80219B60 0000802D */   daddu    $s0, $zero, $zero
/* 63ED44 80219B64 3C038022 */  lui       $v1, %hi(D_80223080_648260)
/* 63ED48 80219B68 24633080 */  addiu     $v1, $v1, %lo(D_80223080_648260)
/* 63ED4C 80219B6C 00161040 */  sll       $v0, $s6, 1
/* 63ED50 80219B70 0043A021 */  addu      $s4, $v0, $v1
/* 63ED54 80219B74 3C135555 */  lui       $s3, 0x5555
/* 63ED58 80219B78 36735556 */  ori       $s3, $s3, 0x5556
/* 63ED5C 80219B7C 34158000 */  ori       $s5, $zero, 0x8000
/* 63ED60 80219B80 02130018 */  mult      $s0, $s3
.L80219B84:
/* 63ED64 80219B84 001097C3 */  sra       $s2, $s0, 0x1f
/* 63ED68 80219B88 00001810 */  mfhi      $v1
/* 63ED6C 80219B8C 00721823 */  subu      $v1, $v1, $s2
/* 63ED70 80219B90 00031040 */  sll       $v0, $v1, 1
/* 63ED74 80219B94 00431021 */  addu      $v0, $v0, $v1
/* 63ED78 80219B98 02021023 */  subu      $v0, $s0, $v0
/* 63ED7C 80219B9C 96830000 */  lhu       $v1, ($s4)
/* 63ED80 80219BA0 24420001 */  addiu     $v0, $v0, 1
/* 63ED84 80219BA4 00620018 */  mult      $v1, $v0
/* 63ED88 80219BA8 00101100 */  sll       $v0, $s0, 4
/* 63ED8C 80219BAC 00001812 */  mflo      $v1
/* 63ED90 80219BB0 00702021 */  addu      $a0, $v1, $s0
/* 63ED94 80219BB4 8FA30014 */  lw        $v1, 0x14($sp)
/* 63ED98 80219BB8 3084FFFF */  andi      $a0, $a0, 0xffff
/* 63ED9C 80219BBC 0C01917C */  jal       sins
/* 63EDA0 80219BC0 00628821 */   addu     $s1, $v1, $v0
/* 63EDA4 80219BC4 00021400 */  sll       $v0, $v0, 0x10
/* 63EDA8 80219BC8 00021403 */  sra       $v0, $v0, 0x10
/* 63EDAC 80219BCC 00551021 */  addu      $v0, $v0, $s5
/* 63EDB0 80219BD0 00021FC2 */  srl       $v1, $v0, 0x1f
/* 63EDB4 80219BD4 00431021 */  addu      $v0, $v0, $v1
/* 63EDB8 80219BD8 000213C0 */  sll       $v0, $v0, 0xf
/* 63EDBC 80219BDC 00021403 */  sra       $v0, $v0, 0x10
/* 63EDC0 80219BE0 00021880 */  sll       $v1, $v0, 2
/* 63EDC4 80219BE4 00621821 */  addu      $v1, $v1, $v0
/* 63EDC8 80219BE8 00031140 */  sll       $v0, $v1, 5
/* 63EDCC 80219BEC 00431823 */  subu      $v1, $v0, $v1
/* 63EDD0 80219BF0 04610002 */  bgez      $v1, .L80219BFC
/* 63EDD4 80219BF4 0060102D */   daddu    $v0, $v1, $zero
/* 63EDD8 80219BF8 24627FFF */  addiu     $v0, $v1, 0x7fff
.L80219BFC:
/* 63EDDC 80219BFC 000223C3 */  sra       $a0, $v0, 0xf
/* 63EDE0 80219C00 24820064 */  addiu     $v0, $a0, 0x64
/* 63EDE4 80219C04 A222000E */  sb        $v0, 0xe($s1)
/* 63EDE8 80219C08 24820032 */  addiu     $v0, $a0, 0x32
/* 63EDEC 80219C0C 02121823 */  subu      $v1, $s0, $s2
/* 63EDF0 80219C10 00032843 */  sra       $a1, $v1, 1
/* 63EDF4 80219C14 00B30018 */  mult      $a1, $s3
/* 63EDF8 80219C18 A222000D */  sb        $v0, 0xd($s1)
/* 63EDFC 80219C1C 96840000 */  lhu       $a0, ($s4)
/* 63EE00 80219C20 00031FC3 */  sra       $v1, $v1, 0x1f
/* 63EE04 80219C24 000433C2 */  srl       $a2, $a0, 0xf
/* 63EE08 80219C28 00004810 */  mfhi      $t1
/* 63EE0C 80219C2C 01231823 */  subu      $v1, $t1, $v1
/* 63EE10 80219C30 00031040 */  sll       $v0, $v1, 1
/* 63EE14 80219C34 00431021 */  addu      $v0, $v0, $v1
/* 63EE18 80219C38 00A22823 */  subu      $a1, $a1, $v0
/* 63EE1C 80219C3C 24A50001 */  addiu     $a1, $a1, 1
/* 63EE20 80219C40 00052BC0 */  sll       $a1, $a1, 0xf
/* 63EE24 80219C44 00C50018 */  mult      $a2, $a1
/* 63EE28 80219C48 00042382 */  srl       $a0, $a0, 0xe
/* 63EE2C 80219C4C 000423C0 */  sll       $a0, $a0, 0xf
/* 63EE30 80219C50 00001812 */  mflo      $v1
/* 63EE34 80219C54 00642021 */  addu      $a0, $v1, $a0
/* 63EE38 80219C58 00902021 */  addu      $a0, $a0, $s0
/* 63EE3C 80219C5C 0C01917C */  jal       sins
/* 63EE40 80219C60 3084FFFF */   andi     $a0, $a0, 0xffff
/* 63EE44 80219C64 00021400 */  sll       $v0, $v0, 0x10
/* 63EE48 80219C68 00021403 */  sra       $v0, $v0, 0x10
/* 63EE4C 80219C6C 9223000C */  lbu       $v1, 0xc($s1)
/* 63EE50 80219C70 00551021 */  addu      $v0, $v0, $s5
/* 63EE54 80219C74 00620018 */  mult      $v1, $v0
/* 63EE58 80219C78 00001812 */  mflo      $v1
/* 63EE5C 80219C7C 04610004 */  bgez      $v1, .L80219C90
/* 63EE60 80219C80 00031403 */   sra      $v0, $v1, 0x10
/* 63EE64 80219C84 3402FFFF */  ori       $v0, $zero, 0xffff
/* 63EE68 80219C88 00621821 */  addu      $v1, $v1, $v0
/* 63EE6C 80219C8C 00031403 */  sra       $v0, $v1, 0x10
.L80219C90:
/* 63EE70 80219C90 A222000C */  sb        $v0, 0xc($s1)
/* 63EE74 80219C94 8FA20018 */  lw        $v0, 0x18($sp)
/* 63EE78 80219C98 26100001 */  addiu     $s0, $s0, 1
/* 63EE7C 80219C9C 0202102A */  slt       $v0, $s0, $v0
/* 63EE80 80219CA0 1440FFB8 */  bnez      $v0, .L80219B84
/* 63EE84 80219CA4 02130018 */   mult     $s0, $s3
.L80219CA8:
/* 63EE88 80219CA8 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 63EE8C 80219CAC 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 63EE90 80219CB0 8C620000 */  lw        $v0, ($v1)
/* 63EE94 80219CB4 02C0202D */  daddu     $a0, $s6, $zero
/* 63EE98 80219CB8 0040802D */  daddu     $s0, $v0, $zero
/* 63EE9C 80219CBC 24420008 */  addiu     $v0, $v0, 8
/* 63EEA0 80219CC0 AC620000 */  sw        $v0, ($v1)
/* 63EEA4 80219CC4 3C02DE00 */  lui       $v0, 0xde00
/* 63EEA8 80219CC8 0C0470BB */  jal       mdl_get_copied_gfx
/* 63EEAC 80219CCC AE020000 */   sw       $v0, ($s0)
/* 63EEB0 80219CD0 AE020004 */  sw        $v0, 4($s0)
/* 63EEB4 80219CD4 3C028022 */  lui       $v0, %hi(D_80223080_648260)
/* 63EEB8 80219CD8 24423080 */  addiu     $v0, $v0, %lo(D_80223080_648260)
/* 63EEBC 80219CDC 00161840 */  sll       $v1, $s6, 1
/* 63EEC0 80219CE0 00621821 */  addu      $v1, $v1, $v0
/* 63EEC4 80219CE4 94620000 */  lhu       $v0, ($v1)
/* 63EEC8 80219CE8 24420253 */  addiu     $v0, $v0, 0x253
/* 63EECC 80219CEC A4620000 */  sh        $v0, ($v1)
/* 63EED0 80219CF0 8FBF003C */  lw        $ra, 0x3c($sp)
/* 63EED4 80219CF4 8FB60038 */  lw        $s6, 0x38($sp)
/* 63EED8 80219CF8 8FB50034 */  lw        $s5, 0x34($sp)
/* 63EEDC 80219CFC 8FB40030 */  lw        $s4, 0x30($sp)
/* 63EEE0 80219D00 8FB3002C */  lw        $s3, 0x2c($sp)
/* 63EEE4 80219D04 8FB20028 */  lw        $s2, 0x28($sp)
/* 63EEE8 80219D08 8FB10024 */  lw        $s1, 0x24($sp)
/* 63EEEC 80219D0C 8FB00020 */  lw        $s0, 0x20($sp)
/* 63EEF0 80219D10 03E00008 */  jr        $ra
/* 63EEF4 80219D14 27BD0040 */   addiu    $sp, $sp, 0x40
