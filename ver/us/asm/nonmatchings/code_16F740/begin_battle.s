.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel begin_battle
/* 16FAF8 80241218 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 16FAFC 8024121C AFB60038 */  sw        $s6, 0x38($sp)
/* 16FB00 80241220 3C16800E */  lui       $s6, %hi(gBattleStatus+0x48C)
/* 16FB04 80241224 8ED6C4FC */  lw        $s6, %lo(gBattleStatus+0x48C)($s6)
/* 16FB08 80241228 3C02800E */  lui       $v0, %hi(gBattleStatus+0x484)
/* 16FB0C 8024122C 8C42C4F4 */  lw        $v0, %lo(gBattleStatus+0x484)($v0)
/* 16FB10 80241230 AFB40030 */  sw        $s4, 0x30($sp)
/* 16FB14 80241234 3C14800E */  lui       $s4, %hi(gBattleStatus)
/* 16FB18 80241238 2694C070 */  addiu     $s4, $s4, %lo(gBattleStatus)
/* 16FB1C 8024123C AFBE0040 */  sw        $fp, 0x40($sp)
/* 16FB20 80241240 3C1E800B */  lui       $fp, %hi(gCurrentEncounter)
/* 16FB24 80241244 27DE0F10 */  addiu     $fp, $fp, %lo(gCurrentEncounter)
/* 16FB28 80241248 AFBF0044 */  sw        $ra, 0x44($sp)
/* 16FB2C 8024124C AFB7003C */  sw        $s7, 0x3c($sp)
/* 16FB30 80241250 AFB50034 */  sw        $s5, 0x34($sp)
/* 16FB34 80241254 AFB3002C */  sw        $s3, 0x2c($sp)
/* 16FB38 80241258 AFB20028 */  sw        $s2, 0x28($sp)
/* 16FB3C 8024125C AFB10024 */  sw        $s1, 0x24($sp)
/* 16FB40 80241260 10400002 */  beqz      $v0, .L8024126C
/* 16FB44 80241264 AFB00020 */   sw       $s0, 0x20($sp)
/* 16FB48 80241268 0040B02D */  daddu     $s6, $v0, $zero
.L8024126C:
/* 16FB4C 8024126C 3C04800E */  lui       $a0, %hi(D_800DC064)
/* 16FB50 80241270 8C84C064 */  lw        $a0, %lo(D_800DC064)($a0)
/* 16FB54 80241274 14800003 */  bnez      $a0, .L80241284
/* 16FB58 80241278 00000000 */   nop
/* 16FB5C 8024127C 080904A2 */  j         .L80241288
/* 16FB60 80241280 8ED5000C */   lw       $s5, 0xc($s6)
.L80241284:
/* 16FB64 80241284 8C950004 */  lw        $s5, 4($a0)
.L80241288:
/* 16FB68 80241288 3C03800E */  lui       $v1, %hi(gBattleStatus+0x46C)
/* 16FB6C 8024128C 8C63C4DC */  lw        $v1, %lo(gBattleStatus+0x46C)($v1)
/* 16FB70 80241290 2C620009 */  sltiu     $v0, $v1, 9
/* 16FB74 80241294 104001FC */  beqz      $v0, .L80241A88
/* 16FB78 80241298 AE950438 */   sw       $s5, 0x438($s4)
/* 16FB7C 8024129C 00031080 */  sll       $v0, $v1, 2
/* 16FB80 802412A0 3C01802A */  lui       $at, %hi(jtbl_8029CA88)
/* 16FB84 802412A4 00220821 */  addu      $at, $at, $v0
/* 16FB88 802412A8 8C22CA88 */  lw        $v0, %lo(jtbl_8029CA88)($at)
/* 16FB8C 802412AC 00400008 */  jr        $v0
/* 16FB90 802412B0 00000000 */   nop
glabel L802412B4_16FB94
/* 16FB94 802412B4 3C05BF80 */  lui       $a1, 0xbf80
/* 16FB98 802412B8 8EC20004 */  lw        $v0, 4($s6)
/* 16FB9C 802412BC 3C01802A */  lui       $at, %hi(D_8029F240)
/* 16FBA0 802412C0 AC22F240 */  sw        $v0, %lo(D_8029F240)($at)
/* 16FBA4 802412C4 0C04DF69 */  jal       set_transition_stencil_zoom_1
/* 16FBA8 802412C8 240400FF */   addiu    $a0, $zero, 0xff
/* 16FBAC 802412CC 8EA40004 */  lw        $a0, 4($s5)
/* 16FBB0 802412D0 0C016B3A */  jal       load_asset_by_name
/* 16FBB4 802412D4 27A50018 */   addiu    $a1, $sp, 0x18
/* 16FBB8 802412D8 0040802D */  daddu     $s0, $v0, $zero
/* 16FBBC 802412DC 3C058021 */  lui       $a1, %hi(D_80210000)
/* 16FBC0 802412E0 24A50000 */  addiu     $a1, $a1, %lo(D_80210000)
/* 16FBC4 802412E4 0C01BB7C */  jal       decode_yay0
/* 16FBC8 802412E8 0200202D */   daddu    $a0, $s0, $zero
/* 16FBCC 802412EC 0C00AB1E */  jal       general_heap_free
/* 16FBD0 802412F0 0200202D */   daddu    $a0, $s0, $zero
/* 16FBD4 802412F4 8FA30018 */  lw        $v1, 0x18($sp)
/* 16FBD8 802412F8 34028000 */  ori       $v0, $zero, 0x8000
/* 16FBDC 802412FC 0043102A */  slt       $v0, $v0, $v1
/* 16FBE0 80241300 10400003 */  beqz      $v0, .L80241310
/* 16FBE4 80241304 00000000 */   nop
.L80241308:
/* 16FBE8 80241308 080904C2 */  j         .L80241308
/* 16FBEC 8024130C 00000000 */   nop
.L80241310:
/* 16FBF0 80241310 8EA40000 */  lw        $a0, ($s5)
/* 16FBF4 80241314 3C108021 */  lui       $s0, 0x8021
/* 16FBF8 80241318 8E100000 */  lw        $s0, ($s0)
/* 16FBFC 8024131C 0C016B74 */  jal       get_asset_offset
/* 16FC00 80241320 27A50018 */   addiu    $a1, $sp, 0x18
/* 16FC04 80241324 12000004 */  beqz      $s0, .L80241338
/* 16FC08 80241328 0200202D */   daddu    $a0, $s0, $zero
/* 16FC0C 8024132C 8FA60018 */  lw        $a2, 0x18($sp)
/* 16FC10 80241330 0C046B52 */  jal       load_data_for_models
/* 16FC14 80241334 0040282D */   daddu    $a1, $v0, $zero
.L80241338:
/* 16FC18 80241338 8EA40008 */  lw        $a0, 8($s5)
/* 16FC1C 8024133C 0C016C68 */  jal       load_stage_collision
/* 16FC20 80241340 00000000 */   nop
/* 16FC24 80241344 8EA40014 */  lw        $a0, 0x14($s5)
/* 16FC28 80241348 10800007 */  beqz      $a0, .L80241368
/* 16FC2C 8024134C 00000000 */   nop
/* 16FC30 80241350 0C05175C */  jal       load_map_bg
/* 16FC34 80241354 00000000 */   nop
/* 16FC38 80241358 3C048020 */  lui       $a0, %hi(gBackgroundImage)
/* 16FC3C 8024135C 24840000 */  addiu     $a0, $a0, %lo(gBackgroundImage)
/* 16FC40 80241360 0C05178A */  jal       read_background_size
/* 16FC44 80241364 00000000 */   nop
.L80241368:
/* 16FC48 80241368 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 16FC4C 8024136C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 16FC50 80241370 904200AA */  lbu       $v0, 0xaa($v0)
/* 16FC54 80241374 30420001 */  andi      $v0, $v0, 1
/* 16FC58 80241378 10400005 */  beqz      $v0, .L80241390
/* 16FC5C 8024137C 00000000 */   nop
/* 16FC60 80241380 3C013F80 */  lui       $at, 0x3f80
/* 16FC64 80241384 44816000 */  mtc1      $at, $f12
/* 16FC68 80241388 0C00AFB7 */  jal       set_curtain_scale_goal
/* 16FC6C 8024138C 00000000 */   nop
.L80241390:
/* 16FC70 80241390 3C05800B */  lui       $a1, %hi(gCameras)
/* 16FC74 80241394 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 16FC78 80241398 94A20000 */  lhu       $v0, ($a1)
/* 16FC7C 8024139C 24040006 */  addiu     $a0, $zero, 6
/* 16FC80 802413A0 AE8000BC */  sw        $zero, 0xbc($s4)
/* 16FC84 802413A4 AE8000C4 */  sw        $zero, 0xc4($s4)
/* 16FC88 802413A8 A6800090 */  sh        $zero, 0x90($s4)
/* 16FC8C 802413AC AE8000B4 */  sw        $zero, 0xb4($s4)
/* 16FC90 802413B0 AE8000B8 */  sw        $zero, 0xb8($s4)
/* 16FC94 802413B4 A2800048 */  sb        $zero, 0x48($s4)
/* 16FC98 802413B8 A2800049 */  sb        $zero, 0x49($s4)
/* 16FC9C 802413BC A280004A */  sb        $zero, 0x4a($s4)
/* 16FCA0 802413C0 A280004B */  sb        $zero, 0x4b($s4)
/* 16FCA4 802413C4 A2800078 */  sb        $zero, 0x78($s4)
/* 16FCA8 802413C8 A2800079 */  sb        $zero, 0x79($s4)
/* 16FCAC 802413CC A280007A */  sb        $zero, 0x7a($s4)
/* 16FCB0 802413D0 A280007B */  sb        $zero, 0x7b($s4)
/* 16FCB4 802413D4 A280008A */  sb        $zero, 0x8a($s4)
/* 16FCB8 802413D8 A2800083 */  sb        $zero, 0x83($s4)
/* 16FCBC 802413DC 94A30AB0 */  lhu       $v1, 0xab0($a1)
/* 16FCC0 802413E0 34420002 */  ori       $v0, $v0, 2
/* 16FCC4 802413E4 A4A20000 */  sh        $v0, ($a1)
/* 16FCC8 802413E8 94A20558 */  lhu       $v0, 0x558($a1)
/* 16FCCC 802413EC 34630002 */  ori       $v1, $v1, 2
/* 16FCD0 802413F0 A4A30AB0 */  sh        $v1, 0xab0($a1)
/* 16FCD4 802413F4 34420002 */  ori       $v0, $v0, 2
/* 16FCD8 802413F8 0C03A752 */  jal       is_ability_active
/* 16FCDC 802413FC A4A20558 */   sh       $v0, 0x558($a1)
/* 16FCE0 80241400 10400002 */  beqz      $v0, .L8024140C
/* 16FCE4 80241404 24020001 */   addiu    $v0, $zero, 1
/* 16FCE8 80241408 A2820083 */  sb        $v0, 0x83($s4)
.L8024140C:
/* 16FCEC 8024140C 2405FFFF */  addiu     $a1, $zero, -1
/* 16FCF0 80241410 2402FFFF */  addiu     $v0, $zero, -1
/* 16FCF4 80241414 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 16FCF8 80241418 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 16FCFC 8024141C A2800081 */  sb        $zero, 0x81($s4)
/* 16FD00 80241420 A2800082 */  sb        $zero, 0x82($s4)
/* 16FD04 80241424 A6850070 */  sh        $a1, 0x70($s4)
/* 16FD08 80241428 AE820074 */  sw        $v0, 0x74($s4)
/* 16FD0C 8024142C A2800088 */  sb        $zero, 0x88($s4)
/* 16FD10 80241430 A2800096 */  sb        $zero, 0x96($s4)
/* 16FD14 80241434 A2800097 */  sb        $zero, 0x97($s4)
/* 16FD18 80241438 A2800098 */  sb        $zero, 0x98($s4)
/* 16FD1C 8024143C A2800089 */  sb        $zero, 0x89($s4)
/* 16FD20 80241440 8CC20004 */  lw        $v0, 4($a2)
/* 16FD24 80241444 83C30011 */  lb        $v1, 0x11($fp)
/* 16FD28 80241448 34440020 */  ori       $a0, $v0, 0x20
/* 16FD2C 8024144C 10600004 */  beqz      $v1, .L80241460
/* 16FD30 80241450 ACC40004 */   sw       $a0, 4($a2)
/* 16FD34 80241454 2402FFDF */  addiu     $v0, $zero, -0x21
/* 16FD38 80241458 00821024 */  and       $v0, $a0, $v0
/* 16FD3C 8024145C ACC20004 */  sw        $v0, 4($a2)
.L80241460:
/* 16FD40 80241460 2411000F */  addiu     $s1, $zero, 0xf
/* 16FD44 80241464 2684003C */  addiu     $a0, $s4, 0x3c
/* 16FD48 80241468 2402000A */  addiu     $v0, $zero, 0xa
/* 16FD4C 8024146C A282008D */  sb        $v0, 0x8d($s4)
/* 16FD50 80241470 240200FF */  addiu     $v0, $zero, 0xff
/* 16FD54 80241474 A2800095 */  sb        $zero, 0x95($s4)
/* 16FD58 80241478 A28500AE */  sb        $a1, 0xae($s4)
/* 16FD5C 8024147C A28500AF */  sb        $a1, 0xaf($s4)
/* 16FD60 80241480 A28500B0 */  sb        $a1, 0xb0($s4)
/* 16FD64 80241484 A280009A */  sb        $zero, 0x9a($s4)
/* 16FD68 80241488 A280009D */  sb        $zero, 0x9d($s4)
/* 16FD6C 8024148C A280009E */  sb        $zero, 0x9e($s4)
/* 16FD70 80241490 AE8000A0 */  sw        $zero, 0xa0($s4)
/* 16FD74 80241494 A28000A4 */  sb        $zero, 0xa4($s4)
/* 16FD78 80241498 A28000A5 */  sb        $zero, 0xa5($s4)
/* 16FD7C 8024149C AE8000A8 */  sw        $zero, 0xa8($s4)
/* 16FD80 802414A0 A2800092 */  sb        $zero, 0x92($s4)
/* 16FD84 802414A4 A280009B */  sb        $zero, 0x9b($s4)
/* 16FD88 802414A8 A280009C */  sb        $zero, 0x9c($s4)
/* 16FD8C 802414AC A280008C */  sb        $zero, 0x8c($s4)
/* 16FD90 802414B0 A28000AC */  sb        $zero, 0xac($s4)
/* 16FD94 802414B4 A28000AD */  sb        $zero, 0xad($s4)
/* 16FD98 802414B8 A2800432 */  sb        $zero, 0x432($s4)
/* 16FD9C 802414BC A2820433 */  sb        $v0, 0x433($s4)
/* 16FDA0 802414C0 A280008B */  sb        $zero, 0x8b($s4)
/* 16FDA4 802414C4 A2800093 */  sb        $zero, 0x93($s4)
/* 16FDA8 802414C8 A2800094 */  sb        $zero, 0x94($s4)
/* 16FDAC 802414CC 8CC20004 */  lw        $v0, 4($a2)
/* 16FDB0 802414D0 2403FFFD */  addiu     $v1, $zero, -3
/* 16FDB4 802414D4 00431024 */  and       $v0, $v0, $v1
/* 16FDB8 802414D8 2403FFFB */  addiu     $v1, $zero, -5
/* 16FDBC 802414DC 00431024 */  and       $v0, $v0, $v1
/* 16FDC0 802414E0 2403FFF7 */  addiu     $v1, $zero, -9
/* 16FDC4 802414E4 00431024 */  and       $v0, $v0, $v1
/* 16FDC8 802414E8 2403FFEF */  addiu     $v1, $zero, -0x11
/* 16FDCC 802414EC 00431024 */  and       $v0, $v0, $v1
/* 16FDD0 802414F0 2403FEFF */  addiu     $v1, $zero, -0x101
/* 16FDD4 802414F4 00431024 */  and       $v0, $v0, $v1
/* 16FDD8 802414F8 2403FDFF */  addiu     $v1, $zero, -0x201
/* 16FDDC 802414FC 00431024 */  and       $v0, $v0, $v1
/* 16FDE0 80241500 ACC20004 */  sw        $v0, 4($a2)
.L80241504:
/* 16FDE4 80241504 AC800008 */  sw        $zero, 8($a0)
/* 16FDE8 80241508 2631FFFF */  addiu     $s1, $s1, -1
/* 16FDEC 8024150C 0621FFFD */  bgez      $s1, .L80241504
/* 16FDF0 80241510 2484FFFC */   addiu    $a0, $a0, -4
/* 16FDF4 80241514 3C03000F */  lui       $v1, 0xf
/* 16FDF8 80241518 3463EF3F */  ori       $v1, $v1, 0xef3f
/* 16FDFC 8024151C 44800000 */  mtc1      $zero, $f0
/* 16FE00 80241520 0000202D */  daddu     $a0, $zero, $zero
/* 16FE04 80241524 44050000 */  mfc1      $a1, $f0
/* 16FE08 80241528 240200FF */  addiu     $v0, $zero, 0xff
/* 16FE0C 8024152C 3C018028 */  lui       $at, %hi(D_80280A30)
/* 16FE10 80241530 AC220A30 */  sw        $v0, %lo(D_80280A30)($at)
/* 16FE14 80241534 AE830224 */  sw        $v1, 0x224($s4)
/* 16FE18 80241538 AFA00014 */  sw        $zero, 0x14($sp)
/* 16FE1C 8024153C 00A0302D */  daddu     $a2, $a1, $zero
/* 16FE20 80241540 00A0382D */  daddu     $a3, $a1, $zero
/* 16FE24 80241544 0C01CA0C */  jal       func_80072830
/* 16FE28 80241548 AFA50010 */   sw       $a1, 0x10($sp)
/* 16FE2C 8024154C 0C03A604 */  jal       func_800E9810
/* 16FE30 80241550 AE82043C */   sw       $v0, 0x43c($s4)
/* 16FE34 80241554 3C048028 */  lui       $a0, %hi(D_80280EB8)
/* 16FE38 80241558 24840EB8 */  addiu     $a0, $a0, %lo(D_80280EB8)
/* 16FE3C 8024155C 2405000A */  addiu     $a1, $zero, 0xa
/* 16FE40 80241560 24100001 */  addiu     $s0, $zero, 1
/* 16FE44 80241564 3C018007 */  lui       $at, %hi(gCurrentCameraID)
/* 16FE48 80241568 AC307410 */  sw        $s0, %lo(gCurrentCameraID)($at)
/* 16FE4C 8024156C 0C0B0CF8 */  jal       start_script
/* 16FE50 80241570 0000302D */   daddu    $a2, $zero, $zero
/* 16FE54 80241574 0040182D */  daddu     $v1, $v0, $zero
/* 16FE58 80241578 AE8300C4 */  sw        $v1, 0xc4($s4)
/* 16FE5C 8024157C 8C620144 */  lw        $v0, 0x144($v1)
/* 16FE60 80241580 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 16FE64 80241584 AC30C4DC */  sw        $s0, %lo(gBattleStatus+0x46C)($at)
/* 16FE68 80241588 080906A2 */  j         .L80241A88
/* 16FE6C 8024158C AE8200C8 */   sw       $v0, 0xc8($s4)
glabel L80241590_16FE70
/* 16FE70 80241590 8E8400C8 */  lw        $a0, 0xc8($s4)
/* 16FE74 80241594 0C0B1059 */  jal       does_script_exist
/* 16FE78 80241598 00000000 */   nop
/* 16FE7C 8024159C 1440013A */  bnez      $v0, .L80241A88
/* 16FE80 802415A0 00000000 */   nop
/* 16FE84 802415A4 8EA4000C */  lw        $a0, 0xc($s5)
/* 16FE88 802415A8 10800009 */  beqz      $a0, .L802415D0
/* 16FE8C 802415AC 24110017 */   addiu    $s1, $zero, 0x17
/* 16FE90 802415B0 2405000A */  addiu     $a1, $zero, 0xa
/* 16FE94 802415B4 0C0B0CF8 */  jal       start_script
/* 16FE98 802415B8 0000302D */   daddu    $a2, $zero, $zero
/* 16FE9C 802415BC 0040182D */  daddu     $v1, $v0, $zero
/* 16FEA0 802415C0 AE8300BC */  sw        $v1, 0xbc($s4)
/* 16FEA4 802415C4 8C620144 */  lw        $v0, 0x144($v1)
/* 16FEA8 802415C8 AE8200C0 */  sw        $v0, 0xc0($s4)
/* 16FEAC 802415CC 24110017 */  addiu     $s1, $zero, 0x17
.L802415D0:
/* 16FEB0 802415D0 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 16FEB4 802415D4 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 16FEB8 802415D8 2685005C */  addiu     $a1, $s4, 0x5c
/* 16FEBC 802415DC 8C830000 */  lw        $v1, ($a0)
/* 16FEC0 802415E0 3C028011 */  lui       $v0, %hi(gUIStatus)
/* 16FEC4 802415E4 2442EF58 */  addiu     $v0, $v0, %lo(gUIStatus)
/* 16FEC8 802415E8 A040003A */  sb        $zero, 0x3a($v0)
/* 16FECC 802415EC 34630001 */  ori       $v1, $v1, 1
/* 16FED0 802415F0 AC830000 */  sw        $v1, ($a0)
.L802415F4:
/* 16FED4 802415F4 ACA000E0 */  sw        $zero, 0xe0($a1)
/* 16FED8 802415F8 2631FFFF */  addiu     $s1, $s1, -1
/* 16FEDC 802415FC 0621FFFD */  bgez      $s1, .L802415F4
/* 16FEE0 80241600 24A5FFFC */   addiu    $a1, $a1, -4
/* 16FEE4 80241604 A280008E */  sb        $zero, 0x8e($s4)
/* 16FEE8 80241608 3C02802A */  lui       $v0, %hi(D_8029F240)
/* 16FEEC 8024160C 8C42F240 */  lw        $v0, %lo(D_8029F240)($v0)
/* 16FEF0 80241610 18400029 */  blez      $v0, .L802416B8
/* 16FEF4 80241614 0000882D */   daddu    $s1, $zero, $zero
/* 16FEF8 80241618 2417FFFF */  addiu     $s7, $zero, -1
/* 16FEFC 8024161C 0280982D */  daddu     $s3, $s4, $zero
/* 16FF00 80241620 0220902D */  daddu     $s2, $s1, $zero
.L80241624:
/* 16FF04 80241624 8EC40008 */  lw        $a0, 8($s6)
/* 16FF08 80241628 0C0994E9 */  jal       create_actor
/* 16FF0C 8024162C 00922021 */   addu     $a0, $a0, $s2
/* 16FF10 80241630 3C048028 */  lui       $a0, %hi(D_80281454)
/* 16FF14 80241634 24841454 */  addiu     $a0, $a0, %lo(D_80281454)
/* 16FF18 80241638 8E7000E0 */  lw        $s0, 0xe0($s3)
.L8024163C:
/* 16FF1C 8024163C 8C830000 */  lw        $v1, ($a0)
/* 16FF20 80241640 10770006 */  beq       $v1, $s7, .L8024165C
/* 16FF24 80241644 00000000 */   nop
/* 16FF28 80241648 92020136 */  lbu       $v0, 0x136($s0)
/* 16FF2C 8024164C 10430006 */  beq       $v0, $v1, .L80241668
/* 16FF30 80241650 24840004 */   addiu    $a0, $a0, 4
/* 16FF34 80241654 0809058F */  j         .L8024163C
/* 16FF38 80241658 00000000 */   nop
.L8024165C:
/* 16FF3C 8024165C 9282008E */  lbu       $v0, 0x8e($s4)
/* 16FF40 80241660 24420001 */  addiu     $v0, $v0, 1
/* 16FF44 80241664 A282008E */  sb        $v0, 0x8e($s4)
.L80241668:
/* 16FF48 80241668 1620000C */  bnez      $s1, .L8024169C
/* 16FF4C 8024166C A2000208 */   sb       $zero, 0x208($s0)
/* 16FF50 80241670 93C20010 */  lbu       $v0, 0x10($fp)
/* 16FF54 80241674 A2020208 */  sb        $v0, 0x208($s0)
/* 16FF58 80241678 83C300A0 */  lb        $v1, 0xa0($fp)
/* 16FF5C 8024167C 24020004 */  addiu     $v0, $zero, 4
/* 16FF60 80241680 54620007 */  bnel      $v1, $v0, .L802416A0
/* 16FF64 80241684 26730004 */   addiu    $s3, $s3, 4
/* 16FF68 80241688 0200202D */  daddu     $a0, $s0, $zero
/* 16FF6C 8024168C 0040282D */  daddu     $a1, $v0, $zero
/* 16FF70 80241690 87C700A2 */  lh        $a3, 0xa2($fp)
/* 16FF74 80241694 0C099B3C */  jal       inflict_status_set_duration
/* 16FF78 80241698 24060024 */   addiu    $a2, $zero, 0x24
.L8024169C:
/* 16FF7C 8024169C 26730004 */  addiu     $s3, $s3, 4
.L802416A0:
/* 16FF80 802416A0 3C02802A */  lui       $v0, %hi(D_8029F240)
/* 16FF84 802416A4 8C42F240 */  lw        $v0, %lo(D_8029F240)($v0)
/* 16FF88 802416A8 26310001 */  addiu     $s1, $s1, 1
/* 16FF8C 802416AC 0222102A */  slt       $v0, $s1, $v0
/* 16FF90 802416B0 1440FFDC */  bnez      $v0, .L80241624
/* 16FF94 802416B4 2652001C */   addiu    $s2, $s2, 0x1c
.L802416B8:
/* 16FF98 802416B8 8EA2001C */  lw        $v0, 0x1c($s5)
/* 16FF9C 802416BC 1040002C */  beqz      $v0, .L80241770
/* 16FFA0 802416C0 00000000 */   nop
/* 16FFA4 802416C4 8EA40024 */  lw        $a0, 0x24($s5)
/* 16FFA8 802416C8 10800007 */  beqz      $a0, .L802416E8
/* 16FFAC 802416CC 00000000 */   nop
/* 16FFB0 802416D0 18800027 */  blez      $a0, .L80241770
/* 16FFB4 802416D4 00000000 */   nop
/* 16FFB8 802416D8 0C00A67F */  jal       rand_int
/* 16FFBC 802416DC 00000000 */   nop
/* 16FFC0 802416E0 14400023 */  bnez      $v0, .L80241770
/* 16FFC4 802416E4 00000000 */   nop
.L802416E8:
/* 16FFC8 802416E8 3C02802A */  lui       $v0, %hi(D_8029F240)
/* 16FFCC 802416EC 2442F240 */  addiu     $v0, $v0, %lo(D_8029F240)
/* 16FFD0 802416F0 8C430000 */  lw        $v1, ($v0)
/* 16FFD4 802416F4 8EA4001C */  lw        $a0, 0x1c($s5)
/* 16FFD8 802416F8 00641821 */  addu      $v1, $v1, $a0
/* 16FFDC 802416FC AC430000 */  sw        $v1, ($v0)
/* 16FFE0 80241700 0223182A */  slt       $v1, $s1, $v1
/* 16FFE4 80241704 1060001A */  beqz      $v1, .L80241770
/* 16FFE8 80241708 24160004 */   addiu    $s6, $zero, 4
/* 16FFEC 8024170C 0000982D */  daddu     $s3, $zero, $zero
/* 16FFF0 80241710 00111080 */  sll       $v0, $s1, 2
/* 16FFF4 80241714 00549021 */  addu      $s2, $v0, $s4
.L80241718:
/* 16FFF8 80241718 8EA40020 */  lw        $a0, 0x20($s5)
/* 16FFFC 8024171C 0C0994E9 */  jal       create_actor
/* 170000 80241720 00932021 */   addu     $a0, $a0, $s3
/* 170004 80241724 8E5000E0 */  lw        $s0, 0xe0($s2)
/* 170008 80241728 1620000A */  bnez      $s1, .L80241754
/* 17000C 8024172C A2000208 */   sb       $zero, 0x208($s0)
/* 170010 80241730 A2000208 */  sb        $zero, 0x208($s0)
/* 170014 80241734 83C200A0 */  lb        $v0, 0xa0($fp)
/* 170018 80241738 54560007 */  bnel      $v0, $s6, .L80241758
/* 17001C 8024173C 26520004 */   addiu    $s2, $s2, 4
/* 170020 80241740 0200202D */  daddu     $a0, $s0, $zero
/* 170024 80241744 24050004 */  addiu     $a1, $zero, 4
/* 170028 80241748 87C700A2 */  lh        $a3, 0xa2($fp)
/* 17002C 8024174C 0C099B3C */  jal       inflict_status_set_duration
/* 170030 80241750 24060024 */   addiu    $a2, $zero, 0x24
.L80241754:
/* 170034 80241754 26520004 */  addiu     $s2, $s2, 4
.L80241758:
/* 170038 80241758 26310001 */  addiu     $s1, $s1, 1
/* 17003C 8024175C 3C02802A */  lui       $v0, %hi(D_8029F240)
/* 170040 80241760 8C42F240 */  lw        $v0, %lo(D_8029F240)($v0)
/* 170044 80241764 0222102A */  slt       $v0, $s1, $v0
/* 170048 80241768 1440FFEB */  bnez      $v0, .L80241718
/* 17004C 8024176C 2673001C */   addiu    $s3, $s3, 0x1c
.L80241770:
/* 170050 80241770 0C099129 */  jal       load_player_actor
/* 170054 80241774 00000000 */   nop
/* 170058 80241778 3C02800E */  lui       $v0, %hi(gBattleStatus+0x4)
/* 17005C 8024177C 8C42C074 */  lw        $v0, %lo(gBattleStatus+0x4)($v0)
/* 170060 80241780 8E9000D8 */  lw        $s0, 0xd8($s4)
/* 170064 80241784 30420040 */  andi      $v0, $v0, 0x40
/* 170068 80241788 3C048028 */  lui       $a0, %hi(D_80284A20)
/* 17006C 8024178C 24844A20 */  addiu     $a0, $a0, %lo(D_80284A20)
/* 170070 80241790 10400003 */  beqz      $v0, .L802417A0
/* 170074 80241794 2405000A */   addiu    $a1, $zero, 0xa
/* 170078 80241798 3C048028 */  lui       $a0, %hi(D_80284A30)
/* 17007C 8024179C 24844A30 */  addiu     $a0, $a0, %lo(D_80284A30)
.L802417A0:
/* 170080 802417A0 0C0B0CF8 */  jal       start_script
/* 170084 802417A4 0000302D */   daddu    $a2, $zero, $zero
/* 170088 802417A8 0040182D */  daddu     $v1, $v0, $zero
/* 17008C 802417AC AE0301D4 */  sw        $v1, 0x1d4($s0)
/* 170090 802417B0 8C620144 */  lw        $v0, 0x144($v1)
/* 170094 802417B4 AE0201E4 */  sw        $v0, 0x1e4($s0)
/* 170098 802417B8 0C0992DD */  jal       load_partner_actor
/* 17009C 802417BC AC600148 */   sw       $zero, 0x148($v1)
/* 1700A0 802417C0 24020004 */  addiu     $v0, $zero, 4
/* 1700A4 802417C4 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 1700A8 802417C8 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 1700AC 802417CC 080906A2 */  j         .L80241A88
/* 1700B0 802417D0 00000000 */   nop
.L802417D4:
/* 1700B4 802417D4 08090608 */  j         .L80241820
/* 1700B8 802417D8 24130001 */   addiu    $s3, $zero, 1
glabel L802417DC_1700BC
/* 1700BC 802417DC 0000882D */  daddu     $s1, $zero, $zero
/* 1700C0 802417E0 3C02802A */  lui       $v0, %hi(D_8029F240)
/* 1700C4 802417E4 8C42F240 */  lw        $v0, %lo(D_8029F240)($v0)
/* 1700C8 802417E8 1840000D */  blez      $v0, .L80241820
/* 1700CC 802417EC 0220982D */   daddu    $s3, $s1, $zero
/* 1700D0 802417F0 0280902D */  daddu     $s2, $s4, $zero
.L802417F4:
/* 1700D4 802417F4 8E5000E0 */  lw        $s0, 0xe0($s2)
/* 1700D8 802417F8 0C0B1059 */  jal       does_script_exist
/* 1700DC 802417FC 8E0401E4 */   lw       $a0, 0x1e4($s0)
/* 1700E0 80241800 1440FFF4 */  bnez      $v0, .L802417D4
/* 1700E4 80241804 26520004 */   addiu    $s2, $s2, 4
/* 1700E8 80241808 3C02802A */  lui       $v0, %hi(D_8029F240)
/* 1700EC 8024180C 8C42F240 */  lw        $v0, %lo(D_8029F240)($v0)
/* 1700F0 80241810 26310001 */  addiu     $s1, $s1, 1
/* 1700F4 80241814 0222102A */  slt       $v0, $s1, $v0
/* 1700F8 80241818 1440FFF6 */  bnez      $v0, .L802417F4
/* 1700FC 8024181C AE0001D4 */   sw       $zero, 0x1d4($s0)
.L80241820:
/* 170100 80241820 16600099 */  bnez      $s3, .L80241A88
/* 170104 80241824 00000000 */   nop
/* 170108 80241828 8E9000D8 */  lw        $s0, 0xd8($s4)
/* 17010C 8024182C 0C0B1059 */  jal       does_script_exist
/* 170110 80241830 8E0401E4 */   lw       $a0, 0x1e4($s0)
/* 170114 80241834 14400094 */  bnez      $v0, .L80241A88
/* 170118 80241838 00000000 */   nop
/* 17011C 8024183C AE0001D4 */  sw        $zero, 0x1d4($s0)
/* 170120 80241840 8E9000DC */  lw        $s0, 0xdc($s4)
/* 170124 80241844 12000006 */  beqz      $s0, .L80241860
/* 170128 80241848 00000000 */   nop
/* 17012C 8024184C 0C0B1059 */  jal       does_script_exist
/* 170130 80241850 8E0401E4 */   lw       $a0, 0x1e4($s0)
/* 170134 80241854 1440008C */  bnez      $v0, .L80241A88
/* 170138 80241858 00000000 */   nop
/* 17013C 8024185C AE0001D4 */  sw        $zero, 0x1d4($s0)
.L80241860:
/* 170140 80241860 8EC40010 */  lw        $a0, 0x10($s6)
/* 170144 80241864 10800007 */  beqz      $a0, .L80241884
/* 170148 80241868 2405000A */   addiu    $a1, $zero, 0xa
/* 17014C 8024186C 0C0B0CF8 */  jal       start_script
/* 170150 80241870 0000302D */   daddu    $a2, $zero, $zero
/* 170154 80241874 0040182D */  daddu     $v1, $v0, $zero
/* 170158 80241878 AE8300BC */  sw        $v1, 0xbc($s4)
/* 17015C 8024187C 8C620144 */  lw        $v0, 0x144($v1)
/* 170160 80241880 AE8200C0 */  sw        $v0, 0xc0($s4)
.L80241884:
/* 170164 80241884 82820432 */  lb        $v0, 0x432($s4)
/* 170168 80241888 18400008 */  blez      $v0, .L802418AC
/* 17016C 8024188C 24040001 */   addiu    $a0, $zero, 1
/* 170170 80241890 0000282D */  daddu     $a1, $zero, $zero
/* 170174 80241894 00A0302D */  daddu     $a2, $a1, $zero
/* 170178 80241898 0C04DF84 */  jal       set_transition_stencil_color
/* 17017C 8024189C 00A0382D */   daddu    $a3, $a1, $zero
/* 170180 802418A0 3C054357 */  lui       $a1, 0x4357
/* 170184 802418A4 0C04DF69 */  jal       set_transition_stencil_zoom_1
/* 170188 802418A8 0000202D */   daddu    $a0, $zero, $zero
.L802418AC:
/* 17018C 802418AC 0C03A752 */  jal       is_ability_active
/* 170190 802418B0 24040011 */   addiu    $a0, $zero, 0x11
/* 170194 802418B4 10400004 */  beqz      $v0, .L802418C8
/* 170198 802418B8 24020002 */   addiu    $v0, $zero, 2
/* 17019C 802418BC 83C30004 */  lb        $v1, 4($fp)
/* 1701A0 802418C0 50620001 */  beql      $v1, $v0, .L802418C8
/* 1701A4 802418C4 A3C00004 */   sb       $zero, 4($fp)
.L802418C8:
/* 1701A8 802418C8 83C30004 */  lb        $v1, 4($fp)
/* 1701AC 802418CC 24020001 */  addiu     $v0, $zero, 1
/* 1701B0 802418D0 10620005 */  beq       $v1, $v0, .L802418E8
/* 1701B4 802418D4 24020002 */   addiu    $v0, $zero, 2
/* 1701B8 802418D8 10620069 */  beq       $v1, $v0, .L80241A80
/* 1701BC 802418DC 24040004 */   addiu    $a0, $zero, 4
/* 1701C0 802418E0 0809063C */  j         .L802418F0
/* 1701C4 802418E4 00000000 */   nop
.L802418E8:
/* 1701C8 802418E8 080906A0 */  j         .L80241A80
/* 1701CC 802418EC 24040002 */   addiu    $a0, $zero, 2
.L802418F0:
/* 1701D0 802418F0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1701D4 802418F4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 1701D8 802418F8 904200AA */  lbu       $v0, 0xaa($v0)
/* 1701DC 802418FC 30420001 */  andi      $v0, $v0, 1
/* 1701E0 80241900 14400012 */  bnez      $v0, .L8024194C
/* 1701E4 80241904 00000000 */   nop
/* 1701E8 80241908 3C02800E */  lui       $v0, %hi(gBattleStatus+0x4)
/* 1701EC 8024190C 8C42C074 */  lw        $v0, %lo(gBattleStatus+0x4)($v0)
/* 1701F0 80241910 8E9000D8 */  lw        $s0, 0xd8($s4)
/* 1701F4 80241914 30420040 */  andi      $v0, $v0, 0x40
/* 1701F8 80241918 3C048028 */  lui       $a0, %hi(MarioEnterStage)
/* 1701FC 8024191C 24844A40 */  addiu     $a0, $a0, %lo(MarioEnterStage)
/* 170200 80241920 10400003 */  beqz      $v0, .L80241930
/* 170204 80241924 2405000A */   addiu    $a1, $zero, 0xa
/* 170208 80241928 3C048028 */  lui       $a0, %hi(PeachEnterStage)
/* 17020C 8024192C 24844D04 */  addiu     $a0, $a0, %lo(PeachEnterStage)
.L80241930:
/* 170210 80241930 0C0B0CF8 */  jal       start_script
/* 170214 80241934 0000302D */   daddu    $a2, $zero, $zero
/* 170218 80241938 0040182D */  daddu     $v1, $v0, $zero
/* 17021C 8024193C AE0301D4 */  sw        $v1, 0x1d4($s0)
/* 170220 80241940 8C620144 */  lw        $v0, 0x144($v1)
/* 170224 80241944 AE0201E4 */  sw        $v0, 0x1e4($s0)
/* 170228 80241948 AC600148 */  sw        $zero, 0x148($v1)
.L8024194C:
/* 17022C 8024194C 8FC2008C */  lw        $v0, 0x8c($fp)
/* 170230 80241950 50400015 */  beql      $v0, $zero, .L802419A8
/* 170234 80241954 24020131 */   addiu    $v0, $zero, 0x131
/* 170238 80241958 80430005 */  lb        $v1, 5($v0)
/* 17023C 8024195C 24020003 */  addiu     $v0, $zero, 3
/* 170240 80241960 14620011 */  bne       $v1, $v0, .L802419A8
/* 170244 80241964 24020131 */   addiu    $v0, $zero, 0x131
/* 170248 80241968 0C03A752 */  jal       is_ability_active
/* 17024C 8024196C 2404002D */   addiu    $a0, $zero, 0x2d
/* 170250 80241970 1040000C */  beqz      $v0, .L802419A4
/* 170254 80241974 2405000A */   addiu    $a1, $zero, 0xa
/* 170258 80241978 3C048029 */  lui       $a0, %hi(DoDizzyAttack)
/* 17025C 8024197C 2484907C */  addiu     $a0, $a0, %lo(DoDizzyAttack)
/* 170260 80241980 8E9000E0 */  lw        $s0, 0xe0($s4)
/* 170264 80241984 0C0B0CF8 */  jal       start_script
/* 170268 80241988 0000302D */   daddu    $a2, $zero, $zero
/* 17026C 8024198C 0040182D */  daddu     $v1, $v0, $zero
/* 170270 80241990 AE0301D4 */  sw        $v1, 0x1d4($s0)
/* 170274 80241994 8C620144 */  lw        $v0, 0x144($v1)
/* 170278 80241998 AE0201E4 */  sw        $v0, 0x1e4($s0)
/* 17027C 8024199C 24020200 */  addiu     $v0, $zero, 0x200
/* 170280 802419A0 AC620148 */  sw        $v0, 0x148($v1)
.L802419A4:
/* 170284 802419A4 24020131 */  addiu     $v0, $zero, 0x131
.L802419A8:
/* 170288 802419A8 3C018028 */  lui       $at, %hi(D_80280A30)
/* 17028C 802419AC AC220A30 */  sw        $v0, %lo(D_80280A30)($at)
/* 170290 802419B0 24020007 */  addiu     $v0, $zero, 7
/* 170294 802419B4 3C01802A */  lui       $at, %hi(D_8029F248)
/* 170298 802419B8 AC20F248 */  sw        $zero, %lo(D_8029F248)($at)
/* 17029C 802419BC 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 1702A0 802419C0 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 1702A4 802419C4 080906A2 */  j         .L80241A88
/* 1702A8 802419C8 00000000 */   nop
glabel L802419CC_1702AC
/* 1702AC 802419CC 3C108028 */  lui       $s0, %hi(D_80280A30)
/* 1702B0 802419D0 26100A30 */  addiu     $s0, $s0, %lo(D_80280A30)
/* 1702B4 802419D4 8E020000 */  lw        $v0, ($s0)
/* 1702B8 802419D8 14400005 */  bnez      $v0, .L802419F0
/* 1702BC 802419DC 24020008 */   addiu    $v0, $zero, 8
/* 1702C0 802419E0 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 1702C4 802419E4 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 1702C8 802419E8 080906A2 */  j         .L80241A88
/* 1702CC 802419EC 00000000 */   nop
.L802419F0:
/* 1702D0 802419F0 3C02802A */  lui       $v0, %hi(D_8029F248)
/* 1702D4 802419F4 2442F248 */  addiu     $v0, $v0, %lo(D_8029F248)
/* 1702D8 802419F8 8C430000 */  lw        $v1, ($v0)
/* 1702DC 802419FC 24630001 */  addiu     $v1, $v1, 1
/* 1702E0 80241A00 AC430000 */  sw        $v1, ($v0)
/* 1702E4 80241A04 2402000F */  addiu     $v0, $zero, 0xf
/* 1702E8 80241A08 14620003 */  bne       $v1, $v0, .L80241A18
/* 1702EC 80241A0C 00000000 */   nop
/* 1702F0 80241A10 0C093903 */  jal       func_8024E40C
/* 1702F4 80241A14 24040002 */   addiu    $a0, $zero, 2
.L80241A18:
/* 1702F8 80241A18 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1702FC 80241A1C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 170300 80241A20 904200AA */  lbu       $v0, 0xaa($v0)
/* 170304 80241A24 30420001 */  andi      $v0, $v0, 1
/* 170308 80241A28 14400004 */  bnez      $v0, .L80241A3C
/* 17030C 80241A2C 00000000 */   nop
/* 170310 80241A30 8E020000 */  lw        $v0, ($s0)
/* 170314 80241A34 08090691 */  j         .L80241A44
/* 170318 80241A38 2442FFF6 */   addiu    $v0, $v0, -0xa
.L80241A3C:
/* 17031C 80241A3C 8E020000 */  lw        $v0, ($s0)
/* 170320 80241A40 2442FFCE */  addiu     $v0, $v0, -0x32
.L80241A44:
/* 170324 80241A44 AE020000 */  sw        $v0, ($s0)
/* 170328 80241A48 3C038028 */  lui       $v1, %hi(D_80280A30)
/* 17032C 80241A4C 24630A30 */  addiu     $v1, $v1, %lo(D_80280A30)
/* 170330 80241A50 8C620000 */  lw        $v0, ($v1)
/* 170334 80241A54 0442000C */  bltzl     $v0, .L80241A88
/* 170338 80241A58 AC600000 */   sw       $zero, ($v1)
/* 17033C 80241A5C 080906A2 */  j         .L80241A88
/* 170340 80241A60 00000000 */   nop
glabel L80241A64_170344
/* 170344 80241A64 8282008C */  lb        $v0, 0x8c($s4)
/* 170348 80241A68 14400007 */  bnez      $v0, .L80241A88
/* 17034C 80241A6C 00000000 */   nop
/* 170350 80241A70 3C05BF80 */  lui       $a1, 0xbf80
/* 170354 80241A74 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* 170358 80241A78 240400FF */   addiu    $a0, $zero, 0xff
/* 17035C 80241A7C 24040005 */  addiu     $a0, $zero, 5
.L80241A80:
/* 170360 80241A80 0C090464 */  jal       func_80241190
/* 170364 80241A84 00000000 */   nop
.L80241A88:
glabel L80241A88_170368
/* 170368 80241A88 8FBF0044 */  lw        $ra, 0x44($sp)
/* 17036C 80241A8C 8FBE0040 */  lw        $fp, 0x40($sp)
/* 170370 80241A90 8FB7003C */  lw        $s7, 0x3c($sp)
/* 170374 80241A94 8FB60038 */  lw        $s6, 0x38($sp)
/* 170378 80241A98 8FB50034 */  lw        $s5, 0x34($sp)
/* 17037C 80241A9C 8FB40030 */  lw        $s4, 0x30($sp)
/* 170380 80241AA0 8FB3002C */  lw        $s3, 0x2c($sp)
/* 170384 80241AA4 8FB20028 */  lw        $s2, 0x28($sp)
/* 170388 80241AA8 8FB10024 */  lw        $s1, 0x24($sp)
/* 17038C 80241AAC 8FB00020 */  lw        $s0, 0x20($sp)
/* 170390 80241AB0 03E00008 */  jr        $ra
/* 170394 80241AB4 27BD0048 */   addiu    $sp, $sp, 0x48
