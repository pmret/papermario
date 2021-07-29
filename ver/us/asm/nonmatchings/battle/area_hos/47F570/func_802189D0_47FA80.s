.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802189D0_47FA80
/* 47FA80 802189D0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 47FA84 802189D4 AFB20028 */  sw        $s2, 0x28($sp)
/* 47FA88 802189D8 2492FFFF */  addiu     $s2, $a0, -1
/* 47FA8C 802189DC 0240202D */  daddu     $a0, $s2, $zero
/* 47FA90 802189E0 27A50010 */  addiu     $a1, $sp, 0x10
/* 47FA94 802189E4 27A60014 */  addiu     $a2, $sp, 0x14
/* 47FA98 802189E8 AFBF003C */  sw        $ra, 0x3c($sp)
/* 47FA9C 802189EC AFB60038 */  sw        $s6, 0x38($sp)
/* 47FAA0 802189F0 AFB50034 */  sw        $s5, 0x34($sp)
/* 47FAA4 802189F4 AFB40030 */  sw        $s4, 0x30($sp)
/* 47FAA8 802189F8 AFB3002C */  sw        $s3, 0x2c($sp)
/* 47FAAC 802189FC AFB10024 */  sw        $s1, 0x24($sp)
/* 47FAB0 80218A00 AFB00020 */  sw        $s0, 0x20($sp)
/* 47FAB4 80218A04 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 47FAB8 80218A08 0C0470AC */  jal       mdl_get_copied_vertices
/* 47FABC 80218A0C 27A70018 */   addiu    $a3, $sp, 0x18
/* 47FAC0 80218A10 8FA20018 */  lw        $v0, 0x18($sp)
/* 47FAC4 80218A14 18400098 */  blez      $v0, .L80218C78
/* 47FAC8 80218A18 0000802D */   daddu    $s0, $zero, $zero
/* 47FACC 80218A1C 3C038022 */  lui       $v1, %hi(D_80224BB0_48BC60)
/* 47FAD0 80218A20 24634BB0 */  addiu     $v1, $v1, %lo(D_80224BB0_48BC60)
/* 47FAD4 80218A24 00121040 */  sll       $v0, $s2, 1
/* 47FAD8 80218A28 0043A021 */  addu      $s4, $v0, $v1
/* 47FADC 80218A2C 3C135555 */  lui       $s3, 0x5555
/* 47FAE0 80218A30 36735556 */  ori       $s3, $s3, 0x5556
/* 47FAE4 80218A34 34168000 */  ori       $s6, $zero, 0x8000
/* 47FAE8 80218A38 3C0141E0 */  lui       $at, 0x41e0
/* 47FAEC 80218A3C 4481A800 */  mtc1      $at, $f21
/* 47FAF0 80218A40 4480A000 */  mtc1      $zero, $f20
/* 47FAF4 80218A44 3C158000 */  lui       $s5, 0x8000
/* 47FAF8 80218A48 02130018 */  mult      $s0, $s3
.L80218A4C:
/* 47FAFC 80218A4C 00101FC3 */  sra       $v1, $s0, 0x1f
/* 47FB00 80218A50 00004810 */  mfhi      $t1
/* 47FB04 80218A54 01231823 */  subu      $v1, $t1, $v1
/* 47FB08 80218A58 00031040 */  sll       $v0, $v1, 1
/* 47FB0C 80218A5C 00431021 */  addu      $v0, $v0, $v1
/* 47FB10 80218A60 02021023 */  subu      $v0, $s0, $v0
/* 47FB14 80218A64 96830000 */  lhu       $v1, ($s4)
/* 47FB18 80218A68 24420001 */  addiu     $v0, $v0, 1
/* 47FB1C 80218A6C 00620018 */  mult      $v1, $v0
/* 47FB20 80218A70 8FA20014 */  lw        $v0, 0x14($sp)
/* 47FB24 80218A74 00001812 */  mflo      $v1
/* 47FB28 80218A78 00702021 */  addu      $a0, $v1, $s0
/* 47FB2C 80218A7C 3084FFFF */  andi      $a0, $a0, 0xffff
/* 47FB30 80218A80 00101900 */  sll       $v1, $s0, 4
/* 47FB34 80218A84 00431021 */  addu      $v0, $v0, $v1
/* 47FB38 80218A88 0C01917C */  jal       sins
/* 47FB3C 80218A8C 2451000C */   addiu    $s1, $v0, 0xc
/* 47FB40 80218A90 00021400 */  sll       $v0, $v0, 0x10
/* 47FB44 80218A94 00021403 */  sra       $v0, $v0, 0x10
/* 47FB48 80218A98 00561021 */  addu      $v0, $v0, $s6
/* 47FB4C 80218A9C 00021FC2 */  srl       $v1, $v0, 0x1f
/* 47FB50 80218AA0 00431021 */  addu      $v0, $v0, $v1
/* 47FB54 80218AA4 00021043 */  sra       $v0, $v0, 1
/* 47FB58 80218AA8 00021C00 */  sll       $v1, $v0, 0x10
/* 47FB5C 80218AAC 00031C03 */  sra       $v1, $v1, 0x10
/* 47FB60 80218AB0 00032080 */  sll       $a0, $v1, 2
/* 47FB64 80218AB4 00832021 */  addu      $a0, $a0, $v1
/* 47FB68 80218AB8 00041940 */  sll       $v1, $a0, 5
/* 47FB6C 80218ABC 00641823 */  subu      $v1, $v1, $a0
/* 47FB70 80218AC0 04610002 */  bgez      $v1, .L80218ACC
/* 47FB74 80218AC4 0040202D */   daddu    $a0, $v0, $zero
/* 47FB78 80218AC8 24637FFF */  addiu     $v1, $v1, 0x7fff
.L80218ACC:
/* 47FB7C 80218ACC 000313C3 */  sra       $v0, $v1, 0xf
/* 47FB80 80218AD0 3C018022 */  lui       $at, %hi(D_80225FC8_48D078)
/* 47FB84 80218AD4 D4225FC8 */  ldc1      $f2, %lo(D_80225FC8_48D078)($at)
/* 47FB88 80218AD8 44820000 */  mtc1      $v0, $f0
/* 47FB8C 80218ADC 00000000 */  nop
/* 47FB90 80218AE0 46800021 */  cvt.d.w   $f0, $f0
/* 47FB94 80218AE4 46220000 */  add.d     $f0, $f0, $f2
/* 47FB98 80218AE8 4620A03E */  c.le.d    $f20, $f0
/* 47FB9C 80218AEC 00000000 */  nop
/* 47FBA0 80218AF0 45030005 */  bc1tl     .L80218B08
/* 47FBA4 80218AF4 46340001 */   sub.d    $f0, $f0, $f20
/* 47FBA8 80218AF8 4620010D */  trunc.w.d $f4, $f0
/* 47FBAC 80218AFC 44022000 */  mfc1      $v0, $f4
/* 47FBB0 80218B00 080862C7 */  j         .L80218B1C
/* 47FBB4 80218B04 A2220000 */   sb       $v0, ($s1)
.L80218B08:
/* 47FBB8 80218B08 4620010D */  trunc.w.d $f4, $f0
/* 47FBBC 80218B0C 44022000 */  mfc1      $v0, $f4
/* 47FBC0 80218B10 00000000 */  nop
/* 47FBC4 80218B14 00551025 */  or        $v0, $v0, $s5
/* 47FBC8 80218B18 A2220000 */  sb        $v0, ($s1)
.L80218B1C:
/* 47FBCC 80218B1C 00041400 */  sll       $v0, $a0, 0x10
/* 47FBD0 80218B20 00021403 */  sra       $v0, $v0, 0x10
/* 47FBD4 80218B24 00021880 */  sll       $v1, $v0, 2
/* 47FBD8 80218B28 00621821 */  addu      $v1, $v1, $v0
/* 47FBDC 80218B2C 00031140 */  sll       $v0, $v1, 5
/* 47FBE0 80218B30 00431023 */  subu      $v0, $v0, $v1
/* 47FBE4 80218B34 04410002 */  bgez      $v0, .L80218B40
/* 47FBE8 80218B38 26230001 */   addiu    $v1, $s1, 1
/* 47FBEC 80218B3C 24427FFF */  addiu     $v0, $v0, 0x7fff
.L80218B40:
/* 47FBF0 80218B40 000213C3 */  sra       $v0, $v0, 0xf
/* 47FBF4 80218B44 3C014059 */  lui       $at, 0x4059
/* 47FBF8 80218B48 44811800 */  mtc1      $at, $f3
/* 47FBFC 80218B4C 44801000 */  mtc1      $zero, $f2
/* 47FC00 80218B50 44820000 */  mtc1      $v0, $f0
/* 47FC04 80218B54 00000000 */  nop
/* 47FC08 80218B58 46800021 */  cvt.d.w   $f0, $f0
/* 47FC0C 80218B5C 46220000 */  add.d     $f0, $f0, $f2
/* 47FC10 80218B60 4620A03E */  c.le.d    $f20, $f0
/* 47FC14 80218B64 00000000 */  nop
/* 47FC18 80218B68 45030005 */  bc1tl     .L80218B80
/* 47FC1C 80218B6C 46340001 */   sub.d    $f0, $f0, $f20
/* 47FC20 80218B70 4620010D */  trunc.w.d $f4, $f0
/* 47FC24 80218B74 44022000 */  mfc1      $v0, $f4
/* 47FC28 80218B78 080862E5 */  j         .L80218B94
/* 47FC2C 80218B7C A0620000 */   sb       $v0, ($v1)
.L80218B80:
/* 47FC30 80218B80 4620010D */  trunc.w.d $f4, $f0
/* 47FC34 80218B84 44022000 */  mfc1      $v0, $f4
/* 47FC38 80218B88 00000000 */  nop
/* 47FC3C 80218B8C 00551025 */  or        $v0, $v0, $s5
/* 47FC40 80218B90 A0620000 */  sb        $v0, ($v1)
.L80218B94:
/* 47FC44 80218B94 00101FC2 */  srl       $v1, $s0, 0x1f
/* 47FC48 80218B98 02031821 */  addu      $v1, $s0, $v1
/* 47FC4C 80218B9C 00032843 */  sra       $a1, $v1, 1
/* 47FC50 80218BA0 00B30018 */  mult      $a1, $s3
/* 47FC54 80218BA4 96840000 */  lhu       $a0, ($s4)
/* 47FC58 80218BA8 00031FC3 */  sra       $v1, $v1, 0x1f
/* 47FC5C 80218BAC 000433C2 */  srl       $a2, $a0, 0xf
/* 47FC60 80218BB0 00004810 */  mfhi      $t1
/* 47FC64 80218BB4 01231823 */  subu      $v1, $t1, $v1
/* 47FC68 80218BB8 00031040 */  sll       $v0, $v1, 1
/* 47FC6C 80218BBC 00431021 */  addu      $v0, $v0, $v1
/* 47FC70 80218BC0 00A22823 */  subu      $a1, $a1, $v0
/* 47FC74 80218BC4 24A50001 */  addiu     $a1, $a1, 1
/* 47FC78 80218BC8 00052BC0 */  sll       $a1, $a1, 0xf
/* 47FC7C 80218BCC 00C50018 */  mult      $a2, $a1
/* 47FC80 80218BD0 00042382 */  srl       $a0, $a0, 0xe
/* 47FC84 80218BD4 000423C0 */  sll       $a0, $a0, 0xf
/* 47FC88 80218BD8 00001812 */  mflo      $v1
/* 47FC8C 80218BDC 00642021 */  addu      $a0, $v1, $a0
/* 47FC90 80218BE0 00902021 */  addu      $a0, $a0, $s0
/* 47FC94 80218BE4 0C01917C */  jal       sins
/* 47FC98 80218BE8 3084FFFF */   andi     $a0, $a0, 0xffff
/* 47FC9C 80218BEC 00021400 */  sll       $v0, $v0, 0x10
/* 47FCA0 80218BF0 00021403 */  sra       $v0, $v0, 0x10
/* 47FCA4 80218BF4 92230000 */  lbu       $v1, ($s1)
/* 47FCA8 80218BF8 00561021 */  addu      $v0, $v0, $s6
/* 47FCAC 80218BFC 00620018 */  mult      $v1, $v0
/* 47FCB0 80218C00 00001812 */  mflo      $v1
/* 47FCB4 80218C04 04610003 */  bgez      $v1, .L80218C14
/* 47FCB8 80218C08 26240002 */   addiu    $a0, $s1, 2
/* 47FCBC 80218C0C 3402FFFF */  ori       $v0, $zero, 0xffff
/* 47FCC0 80218C10 00621821 */  addu      $v1, $v1, $v0
.L80218C14:
/* 47FCC4 80218C14 00031403 */  sra       $v0, $v1, 0x10
/* 47FCC8 80218C18 3C018022 */  lui       $at, %hi(D_80225FD0_48D080)
/* 47FCCC 80218C1C D4225FD0 */  ldc1      $f2, %lo(D_80225FD0_48D080)($at)
/* 47FCD0 80218C20 44820000 */  mtc1      $v0, $f0
/* 47FCD4 80218C24 00000000 */  nop
/* 47FCD8 80218C28 46800021 */  cvt.d.w   $f0, $f0
/* 47FCDC 80218C2C 46220000 */  add.d     $f0, $f0, $f2
/* 47FCE0 80218C30 4620A03E */  c.le.d    $f20, $f0
/* 47FCE4 80218C34 00000000 */  nop
/* 47FCE8 80218C38 45030005 */  bc1tl     .L80218C50
/* 47FCEC 80218C3C 46340001 */   sub.d    $f0, $f0, $f20
/* 47FCF0 80218C40 4620010D */  trunc.w.d $f4, $f0
/* 47FCF4 80218C44 44022000 */  mfc1      $v0, $f4
/* 47FCF8 80218C48 08086319 */  j         .L80218C64
/* 47FCFC 80218C4C A0820000 */   sb       $v0, ($a0)
.L80218C50:
/* 47FD00 80218C50 4620010D */  trunc.w.d $f4, $f0
/* 47FD04 80218C54 44022000 */  mfc1      $v0, $f4
/* 47FD08 80218C58 00000000 */  nop
/* 47FD0C 80218C5C 00551025 */  or        $v0, $v0, $s5
/* 47FD10 80218C60 A0820000 */  sb        $v0, ($a0)
.L80218C64:
/* 47FD14 80218C64 8FA20018 */  lw        $v0, 0x18($sp)
/* 47FD18 80218C68 26100001 */  addiu     $s0, $s0, 1
/* 47FD1C 80218C6C 0202102A */  slt       $v0, $s0, $v0
/* 47FD20 80218C70 1440FF76 */  bnez      $v0, .L80218A4C
/* 47FD24 80218C74 02130018 */   mult     $s0, $s3
.L80218C78:
/* 47FD28 80218C78 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 47FD2C 80218C7C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 47FD30 80218C80 8C620000 */  lw        $v0, ($v1)
/* 47FD34 80218C84 0240202D */  daddu     $a0, $s2, $zero
/* 47FD38 80218C88 0040802D */  daddu     $s0, $v0, $zero
/* 47FD3C 80218C8C 24420008 */  addiu     $v0, $v0, 8
/* 47FD40 80218C90 AC620000 */  sw        $v0, ($v1)
/* 47FD44 80218C94 3C02DE00 */  lui       $v0, 0xde00
/* 47FD48 80218C98 0C0470BB */  jal       mdl_get_copied_gfx
/* 47FD4C 80218C9C AE020000 */   sw       $v0, ($s0)
/* 47FD50 80218CA0 AE020004 */  sw        $v0, 4($s0)
/* 47FD54 80218CA4 3C028022 */  lui       $v0, %hi(D_80224BB0_48BC60)
/* 47FD58 80218CA8 24424BB0 */  addiu     $v0, $v0, %lo(D_80224BB0_48BC60)
/* 47FD5C 80218CAC 00121840 */  sll       $v1, $s2, 1
/* 47FD60 80218CB0 00621821 */  addu      $v1, $v1, $v0
/* 47FD64 80218CB4 94620000 */  lhu       $v0, ($v1)
/* 47FD68 80218CB8 24420253 */  addiu     $v0, $v0, 0x253
/* 47FD6C 80218CBC A4620000 */  sh        $v0, ($v1)
/* 47FD70 80218CC0 8FBF003C */  lw        $ra, 0x3c($sp)
/* 47FD74 80218CC4 8FB60038 */  lw        $s6, 0x38($sp)
/* 47FD78 80218CC8 8FB50034 */  lw        $s5, 0x34($sp)
/* 47FD7C 80218CCC 8FB40030 */  lw        $s4, 0x30($sp)
/* 47FD80 80218CD0 8FB3002C */  lw        $s3, 0x2c($sp)
/* 47FD84 80218CD4 8FB20028 */  lw        $s2, 0x28($sp)
/* 47FD88 80218CD8 8FB10024 */  lw        $s1, 0x24($sp)
/* 47FD8C 80218CDC 8FB00020 */  lw        $s0, 0x20($sp)
/* 47FD90 80218CE0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 47FD94 80218CE4 03E00008 */  jr        $ra
/* 47FD98 80218CE8 27BD0048 */   addiu    $sp, $sp, 0x48
