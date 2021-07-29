.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_status_menu
/* 81564 800E80B4 27BDFF70 */  addiu     $sp, $sp, -0x90
/* 81568 800E80B8 AFB00068 */  sw        $s0, 0x68($sp)
/* 8156C 800E80BC 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 81570 800E80C0 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 81574 800E80C4 AFBF008C */  sw        $ra, 0x8c($sp)
/* 81578 800E80C8 AFBE0088 */  sw        $fp, 0x88($sp)
/* 8157C 800E80CC AFB70084 */  sw        $s7, 0x84($sp)
/* 81580 800E80D0 AFB60080 */  sw        $s6, 0x80($sp)
/* 81584 800E80D4 AFB5007C */  sw        $s5, 0x7c($sp)
/* 81588 800E80D8 AFB40078 */  sw        $s4, 0x78($sp)
/* 8158C 800E80DC AFB30074 */  sw        $s3, 0x74($sp)
/* 81590 800E80E0 AFB20070 */  sw        $s2, 0x70($sp)
/* 81594 800E80E4 AFB1006C */  sw        $s1, 0x6c($sp)
/* 81598 800E80E8 8E030000 */  lw        $v1, ($s0)
/* 8159C 800E80EC 3C138011 */  lui       $s3, %hi(gUIStatus)
/* 815A0 800E80F0 2673EF58 */  addiu     $s3, $s3, %lo(gUIStatus)
/* 815A4 800E80F4 806200A8 */  lb        $v0, 0xa8($v1)
/* 815A8 800E80F8 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 815AC 800E80FC 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 815B0 800E8100 04410469 */  bgez      $v0, .L800E92A8
/* 815B4 800E8104 00000000 */   nop
/* 815B8 800E8108 80620071 */  lb        $v0, 0x71($v1)
/* 815BC 800E810C 14400466 */  bnez      $v0, .L800E92A8
/* 815C0 800E8110 00000000 */   nop
/* 815C4 800E8114 9062007E */  lbu       $v0, 0x7e($v1)
/* 815C8 800E8118 30420001 */  andi      $v0, $v0, 1
/* 815CC 800E811C 14400462 */  bnez      $v0, .L800E92A8
/* 815D0 800E8120 0000202D */   daddu    $a0, $zero, $zero
/* 815D4 800E8124 3C05F5DE */  lui       $a1, 0xf5de
/* 815D8 800E8128 0C0B1EAF */  jal       get_variable
/* 815DC 800E812C 34A50180 */   ori      $a1, $a1, 0x180
/* 815E0 800E8130 28420060 */  slti      $v0, $v0, 0x60
/* 815E4 800E8134 1040045C */  beqz      $v0, .L800E92A8
/* 815E8 800E8138 00000000 */   nop
/* 815EC 800E813C 8E020000 */  lw        $v0, ($s0)
/* 815F0 800E8140 80420070 */  lb        $v0, 0x70($v0)
/* 815F4 800E8144 14400008 */  bnez      $v0, .L800E8168
/* 815F8 800E8148 00000000 */   nop
/* 815FC 800E814C 3C038011 */  lui       $v1, %hi(gPlayerData+0xC)
/* 81600 800E8150 8463F29C */  lh        $v1, %lo(gPlayerData+0xC)($v1)
/* 81604 800E8154 86620040 */  lh        $v0, 0x40($s3)
/* 81608 800E8158 10620007 */  beq       $v1, $v0, .L800E8178
/* 8160C 800E815C 00628023 */   subu     $s0, $v1, $v0
/* 81610 800E8160 0C03A67D */  jal       status_menu_start_blinking_coins
/* 81614 800E8164 00000000 */   nop
.L800E8168:
/* 81618 800E8168 3C038011 */  lui       $v1, %hi(gPlayerData+0xC)
/* 8161C 800E816C 8463F29C */  lh        $v1, %lo(gPlayerData+0xC)($v1)
/* 81620 800E8170 86620040 */  lh        $v0, 0x40($s3)
/* 81624 800E8174 00628023 */  subu      $s0, $v1, $v0
.L800E8178:
/* 81628 800E8178 06010004 */  bgez      $s0, .L800E818C
/* 8162C 800E817C 3C036666 */   lui      $v1, 0x6666
/* 81630 800E8180 34636667 */  ori       $v1, $v1, 0x6667
/* 81634 800E8184 0803A065 */  j         .L800E8194
/* 81638 800E8188 2602FFFC */   addiu    $v0, $s0, -4
.L800E818C:
/* 8163C 800E818C 34636667 */  ori       $v1, $v1, 0x6667
/* 81640 800E8190 26020004 */  addiu     $v0, $s0, 4
.L800E8194:
/* 81644 800E8194 00430018 */  mult      $v0, $v1
/* 81648 800E8198 000217C3 */  sra       $v0, $v0, 0x1f
/* 8164C 800E819C 00004810 */  mfhi      $t1
/* 81650 800E81A0 00091843 */  sra       $v1, $t1, 1
/* 81654 800E81A4 00628023 */  subu      $s0, $v1, $v0
/* 81658 800E81A8 96620040 */  lhu       $v0, 0x40($s3)
/* 8165C 800E81AC 8264003D */  lb        $a0, 0x3d($s3)
/* 81660 800E81B0 3C038011 */  lui       $v1, %hi(gPlayerData+0x2)
/* 81664 800E81B4 8063F292 */  lb        $v1, %lo(gPlayerData+0x2)($v1)
/* 81668 800E81B8 00501021 */  addu      $v0, $v0, $s0
/* 8166C 800E81BC 1083000C */  beq       $a0, $v1, .L800E81F0
/* 81670 800E81C0 A6620040 */   sh       $v0, 0x40($s3)
/* 81674 800E81C4 82620044 */  lb        $v0, 0x44($s3)
/* 81678 800E81C8 14400009 */  bnez      $v0, .L800E81F0
/* 8167C 800E81CC 00000000 */   nop
/* 81680 800E81D0 8262003A */  lb        $v0, 0x3a($s3)
/* 81684 800E81D4 10400005 */  beqz      $v0, .L800E81EC
/* 81688 800E81D8 24020046 */   addiu    $v0, $zero, 0x46
/* 8168C 800E81DC A6620038 */  sh        $v0, 0x38($s3)
/* 81690 800E81E0 A260003A */  sb        $zero, 0x3a($s3)
/* 81694 800E81E4 0803A07C */  j         .L800E81F0
/* 81698 800E81E8 A260003B */   sb       $zero, 0x3b($s3)
.L800E81EC:
/* 8169C 800E81EC A6620038 */  sh        $v0, 0x38($s3)
.L800E81F0:
/* 816A0 800E81F0 8263003E */  lb        $v1, 0x3e($s3)
/* 816A4 800E81F4 3C028011 */  lui       $v0, %hi(gPlayerData+0x5)
/* 816A8 800E81F8 8042F295 */  lb        $v0, %lo(gPlayerData+0x5)($v0)
/* 816AC 800E81FC 1062000C */  beq       $v1, $v0, .L800E8230
/* 816B0 800E8200 00000000 */   nop
/* 816B4 800E8204 82620044 */  lb        $v0, 0x44($s3)
/* 816B8 800E8208 14400009 */  bnez      $v0, .L800E8230
/* 816BC 800E820C 00000000 */   nop
/* 816C0 800E8210 8262003A */  lb        $v0, 0x3a($s3)
/* 816C4 800E8214 10400005 */  beqz      $v0, .L800E822C
/* 816C8 800E8218 24020046 */   addiu    $v0, $zero, 0x46
/* 816CC 800E821C A6620038 */  sh        $v0, 0x38($s3)
/* 816D0 800E8220 A260003A */  sb        $zero, 0x3a($s3)
/* 816D4 800E8224 0803A08C */  j         .L800E8230
/* 816D8 800E8228 A260003B */   sb       $zero, 0x3b($s3)
.L800E822C:
/* 816DC 800E822C A6620038 */  sh        $v0, 0x38($s3)
.L800E8230:
/* 816E0 800E8230 86630048 */  lh        $v1, 0x48($s3)
/* 816E4 800E8234 3C028011 */  lui       $v0, %hi(gPlayerData+0x290)
/* 816E8 800E8238 8442F520 */  lh        $v0, %lo(gPlayerData+0x290)($v0)
/* 816EC 800E823C 1062000C */  beq       $v1, $v0, .L800E8270
/* 816F0 800E8240 00000000 */   nop
/* 816F4 800E8244 82620044 */  lb        $v0, 0x44($s3)
/* 816F8 800E8248 14400009 */  bnez      $v0, .L800E8270
/* 816FC 800E824C 00000000 */   nop
/* 81700 800E8250 8262003A */  lb        $v0, 0x3a($s3)
/* 81704 800E8254 10400005 */  beqz      $v0, .L800E826C
/* 81708 800E8258 24020046 */   addiu    $v0, $zero, 0x46
/* 8170C 800E825C A6620038 */  sh        $v0, 0x38($s3)
/* 81710 800E8260 A260003A */  sb        $zero, 0x3a($s3)
/* 81714 800E8264 0803A09C */  j         .L800E8270
/* 81718 800E8268 A260003B */   sb       $zero, 0x3b($s3)
.L800E826C:
/* 8171C 800E826C A6620038 */  sh        $v0, 0x38($s3)
.L800E8270:
/* 81720 800E8270 8264003D */  lb        $a0, 0x3d($s3)
/* 81724 800E8274 3C038011 */  lui       $v1, %hi(gPlayerData+0x2)
/* 81728 800E8278 8063F292 */  lb        $v1, %lo(gPlayerData+0x2)($v1)
/* 8172C 800E827C 1083002E */  beq       $a0, $v1, .L800E8338
/* 81730 800E8280 00000000 */   nop
/* 81734 800E8284 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 81738 800E8288 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8173C 800E828C 80420070 */  lb        $v0, 0x70($v0)
/* 81740 800E8290 14400005 */  bnez      $v0, .L800E82A8
/* 81744 800E8294 0064102A */   slt      $v0, $v1, $a0
/* 81748 800E8298 10400003 */  beqz      $v0, .L800E82A8
/* 8174C 800E829C 00000000 */   nop
/* 81750 800E82A0 0C03A648 */  jal       status_menu_start_blinking_hp
/* 81754 800E82A4 00000000 */   nop
.L800E82A8:
/* 81758 800E82A8 8262003D */  lb        $v0, 0x3d($s3)
/* 8175C 800E82AC 3C038011 */  lui       $v1, %hi(gPlayerData+0x2)
/* 81760 800E82B0 8063F292 */  lb        $v1, %lo(gPlayerData+0x2)($v1)
/* 81764 800E82B4 0043102A */  slt       $v0, $v0, $v1
/* 81768 800E82B8 10400018 */  beqz      $v0, .L800E831C
/* 8176C 800E82BC 9263003D */   lbu      $v1, 0x3d($s3)
/* 81770 800E82C0 86620036 */  lh        $v0, 0x36($s3)
/* 81774 800E82C4 28420012 */  slti      $v0, $v0, 0x12
/* 81778 800E82C8 1440000C */  bnez      $v0, .L800E82FC
/* 8177C 800E82CC 00000000 */   nop
/* 81780 800E82D0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 81784 800E82D4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 81788 800E82D8 94420134 */  lhu       $v0, 0x134($v0)
/* 8178C 800E82DC 30420003 */  andi      $v0, $v0, 3
/* 81790 800E82E0 14400015 */  bnez      $v0, .L800E8338
/* 81794 800E82E4 24620001 */   addiu    $v0, $v1, 1
/* 81798 800E82E8 A262003D */  sb        $v0, 0x3d($s3)
/* 8179C 800E82EC 0C05272D */  jal       sfx_play_sound
/* 817A0 800E82F0 24040213 */   addiu    $a0, $zero, 0x213
/* 817A4 800E82F4 0803A0CE */  j         .L800E8338
/* 817A8 800E82F8 00000000 */   nop
.L800E82FC:
/* 817AC 800E82FC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 817B0 800E8300 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 817B4 800E8304 94420134 */  lhu       $v0, 0x134($v0)
/* 817B8 800E8308 30420003 */  andi      $v0, $v0, 3
/* 817BC 800E830C 1440000A */  bnez      $v0, .L800E8338
/* 817C0 800E8310 24620001 */   addiu    $v0, $v1, 1
/* 817C4 800E8314 0803A0CE */  j         .L800E8338
/* 817C8 800E8318 A262003D */   sb       $v0, 0x3d($s3)
.L800E831C:
/* 817CC 800E831C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 817D0 800E8320 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 817D4 800E8324 94420134 */  lhu       $v0, 0x134($v0)
/* 817D8 800E8328 30420003 */  andi      $v0, $v0, 3
/* 817DC 800E832C 14400002 */  bnez      $v0, .L800E8338
/* 817E0 800E8330 2462FFFF */   addiu    $v0, $v1, -1
/* 817E4 800E8334 A262003D */  sb        $v0, 0x3d($s3)
.L800E8338:
/* 817E8 800E8338 8264003E */  lb        $a0, 0x3e($s3)
/* 817EC 800E833C 3C038011 */  lui       $v1, %hi(gPlayerData+0x5)
/* 817F0 800E8340 8063F295 */  lb        $v1, %lo(gPlayerData+0x5)($v1)
/* 817F4 800E8344 1083002E */  beq       $a0, $v1, .L800E8400
/* 817F8 800E8348 00000000 */   nop
/* 817FC 800E834C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 81800 800E8350 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 81804 800E8354 80420070 */  lb        $v0, 0x70($v0)
/* 81808 800E8358 14400005 */  bnez      $v0, .L800E8370
/* 8180C 800E835C 0064102A */   slt      $v0, $v1, $a0
/* 81810 800E8360 10400003 */  beqz      $v0, .L800E8370
/* 81814 800E8364 00000000 */   nop
/* 81818 800E8368 0C03A663 */  jal       status_menu_start_blinking_fp
/* 8181C 800E836C 00000000 */   nop
.L800E8370:
/* 81820 800E8370 8262003E */  lb        $v0, 0x3e($s3)
/* 81824 800E8374 3C038011 */  lui       $v1, %hi(gPlayerData+0x5)
/* 81828 800E8378 8063F295 */  lb        $v1, %lo(gPlayerData+0x5)($v1)
/* 8182C 800E837C 0043102A */  slt       $v0, $v0, $v1
/* 81830 800E8380 10400018 */  beqz      $v0, .L800E83E4
/* 81834 800E8384 9263003E */   lbu      $v1, 0x3e($s3)
/* 81838 800E8388 86620036 */  lh        $v0, 0x36($s3)
/* 8183C 800E838C 28420012 */  slti      $v0, $v0, 0x12
/* 81840 800E8390 1440000C */  bnez      $v0, .L800E83C4
/* 81844 800E8394 00000000 */   nop
/* 81848 800E8398 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8184C 800E839C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 81850 800E83A0 94420134 */  lhu       $v0, 0x134($v0)
/* 81854 800E83A4 30420003 */  andi      $v0, $v0, 3
/* 81858 800E83A8 14400015 */  bnez      $v0, .L800E8400
/* 8185C 800E83AC 24620001 */   addiu    $v0, $v1, 1
/* 81860 800E83B0 A262003E */  sb        $v0, 0x3e($s3)
/* 81864 800E83B4 0C05272D */  jal       sfx_play_sound
/* 81868 800E83B8 24040217 */   addiu    $a0, $zero, 0x217
/* 8186C 800E83BC 0803A100 */  j         .L800E8400
/* 81870 800E83C0 00000000 */   nop
.L800E83C4:
/* 81874 800E83C4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 81878 800E83C8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8187C 800E83CC 94420134 */  lhu       $v0, 0x134($v0)
/* 81880 800E83D0 30420003 */  andi      $v0, $v0, 3
/* 81884 800E83D4 1440000A */  bnez      $v0, .L800E8400
/* 81888 800E83D8 24620001 */   addiu    $v0, $v1, 1
/* 8188C 800E83DC 0803A100 */  j         .L800E8400
/* 81890 800E83E0 A262003E */   sb       $v0, 0x3e($s3)
.L800E83E4:
/* 81894 800E83E4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 81898 800E83E8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8189C 800E83EC 94420134 */  lhu       $v0, 0x134($v0)
/* 818A0 800E83F0 30420003 */  andi      $v0, $v0, 3
/* 818A4 800E83F4 14400002 */  bnez      $v0, .L800E8400
/* 818A8 800E83F8 2462FFFF */   addiu    $v0, $v1, -1
/* 818AC 800E83FC A262003E */  sb        $v0, 0x3e($s3)
.L800E8400:
/* 818B0 800E8400 86620048 */  lh        $v0, 0x48($s3)
/* 818B4 800E8404 3C048011 */  lui       $a0, %hi(gPlayerData+0x290)
/* 818B8 800E8408 8484F520 */  lh        $a0, %lo(gPlayerData+0x290)($a0)
/* 818BC 800E840C 96630048 */  lhu       $v1, 0x48($s3)
/* 818C0 800E8410 1044001A */  beq       $v0, $a0, .L800E847C
/* 818C4 800E8414 0044102A */   slt      $v0, $v0, $a0
/* 818C8 800E8418 1040000D */  beqz      $v0, .L800E8450
/* 818CC 800E841C 2462000A */   addiu    $v0, $v1, 0xa
/* 818D0 800E8420 A6620048 */  sh        $v0, 0x48($s3)
/* 818D4 800E8424 00021400 */  sll       $v0, $v0, 0x10
/* 818D8 800E8428 3C038011 */  lui       $v1, %hi(gPlayerData+0x290)
/* 818DC 800E842C 8463F520 */  lh        $v1, %lo(gPlayerData+0x290)($v1)
/* 818E0 800E8430 00021403 */  sra       $v0, $v0, 0x10
/* 818E4 800E8434 0062182A */  slt       $v1, $v1, $v0
/* 818E8 800E8438 3C028011 */  lui       $v0, %hi(gPlayerData+0x290)
/* 818EC 800E843C 9442F520 */  lhu       $v0, %lo(gPlayerData+0x290)($v0)
/* 818F0 800E8440 5460000E */  bnel      $v1, $zero, .L800E847C
/* 818F4 800E8444 A6620048 */   sh       $v0, 0x48($s3)
/* 818F8 800E8448 0803A11F */  j         .L800E847C
/* 818FC 800E844C 00000000 */   nop
.L800E8450:
/* 81900 800E8450 2462FFF6 */  addiu     $v0, $v1, -0xa
/* 81904 800E8454 A6620048 */  sh        $v0, 0x48($s3)
/* 81908 800E8458 00021400 */  sll       $v0, $v0, 0x10
/* 8190C 800E845C 3C038011 */  lui       $v1, %hi(gPlayerData+0x290)
/* 81910 800E8460 8463F520 */  lh        $v1, %lo(gPlayerData+0x290)($v1)
/* 81914 800E8464 00021403 */  sra       $v0, $v0, 0x10
/* 81918 800E8468 0043102A */  slt       $v0, $v0, $v1
/* 8191C 800E846C 3C038011 */  lui       $v1, %hi(gPlayerData+0x290)
/* 81920 800E8470 9463F520 */  lhu       $v1, %lo(gPlayerData+0x290)($v1)
/* 81924 800E8474 54400001 */  bnel      $v0, $zero, .L800E847C
/* 81928 800E8478 A6630048 */   sh       $v1, 0x48($s3)
.L800E847C:
/* 8192C 800E847C 82620047 */  lb        $v0, 0x47($s3)
/* 81930 800E8480 14400389 */  bnez      $v0, .L800E92A8
/* 81934 800E8484 00000000 */   nop
/* 81938 800E8488 82620046 */  lb        $v0, 0x46($s3)
/* 8193C 800E848C 1040000A */  beqz      $v0, .L800E84B8
/* 81940 800E8490 00000000 */   nop
/* 81944 800E8494 8262003A */  lb        $v0, 0x3a($s3)
/* 81948 800E8498 10400007 */  beqz      $v0, .L800E84B8
/* 8194C 800E849C 00000000 */   nop
/* 81950 800E84A0 82220015 */  lb        $v0, 0x15($s1)
/* 81954 800E84A4 14400004 */  bnez      $v0, .L800E84B8
/* 81958 800E84A8 2402002A */   addiu    $v0, $zero, 0x2a
/* 8195C 800E84AC A6620038 */  sh        $v0, 0x38($s3)
/* 81960 800E84B0 A260003A */  sb        $zero, 0x3a($s3)
/* 81964 800E84B4 A260003B */  sb        $zero, 0x3b($s3)
.L800E84B8:
/* 81968 800E84B8 8263003A */  lb        $v1, 0x3a($s3)
/* 8196C 800E84BC 10600005 */  beqz      $v1, .L800E84D4
/* 81970 800E84C0 24020001 */   addiu    $v0, $zero, 1
/* 81974 800E84C4 1062002E */  beq       $v1, $v0, .L800E8580
/* 81978 800E84C8 3C08ED03 */   lui      $t0, 0xed03
/* 8197C 800E84CC 0803A188 */  j         .L800E8620
/* 81980 800E84D0 35080050 */   ori      $t0, $t0, 0x50
.L800E84D4:
/* 81984 800E84D4 96620036 */  lhu       $v0, 0x36($s3)
/* 81988 800E84D8 2442000A */  addiu     $v0, $v0, 0xa
/* 8198C 800E84DC A6620036 */  sh        $v0, 0x36($s3)
/* 81990 800E84E0 00021400 */  sll       $v0, $v0, 0x10
/* 81994 800E84E4 00021403 */  sra       $v0, $v0, 0x10
/* 81998 800E84E8 28420012 */  slti      $v0, $v0, 0x12
/* 8199C 800E84EC 1440004B */  bnez      $v0, .L800E861C
/* 819A0 800E84F0 3C08ED03 */   lui      $t0, 0xed03
/* 819A4 800E84F4 8263003C */  lb        $v1, 0x3c($s3)
/* 819A8 800E84F8 24020012 */  addiu     $v0, $zero, 0x12
/* 819AC 800E84FC 10600007 */  beqz      $v1, .L800E851C
/* 819B0 800E8500 A6620036 */   sh       $v0, 0x36($s3)
/* 819B4 800E8504 8262003B */  lb        $v0, 0x3b($s3)
/* 819B8 800E8508 10400004 */  beqz      $v0, .L800E851C
/* 819BC 800E850C 00000000 */   nop
/* 819C0 800E8510 822200B4 */  lb        $v0, 0xb4($s1)
/* 819C4 800E8514 54400001 */  bnel      $v0, $zero, .L800E851C
/* 819C8 800E8518 A6600038 */   sh       $zero, 0x38($s3)
.L800E851C:
/* 819CC 800E851C 86620038 */  lh        $v0, 0x38($s3)
/* 819D0 800E8520 96630038 */  lhu       $v1, 0x38($s3)
/* 819D4 800E8524 10400003 */  beqz      $v0, .L800E8534
/* 819D8 800E8528 2462FFFF */   addiu    $v0, $v1, -1
/* 819DC 800E852C 0803A186 */  j         .L800E8618
/* 819E0 800E8530 A6620038 */   sh       $v0, 0x38($s3)
.L800E8534:
/* 819E4 800E8534 82620044 */  lb        $v0, 0x44($s3)
/* 819E8 800E8538 14400038 */  bnez      $v0, .L800E861C
/* 819EC 800E853C 3C08ED03 */   lui      $t0, 0xed03
/* 819F0 800E8540 8262003B */  lb        $v0, 0x3b($s3)
/* 819F4 800E8544 10400004 */  beqz      $v0, .L800E8558
/* 819F8 800E8548 00000000 */   nop
/* 819FC 800E854C 822200B4 */  lb        $v0, 0xb4($s1)
/* 81A00 800E8550 10400033 */  beqz      $v0, .L800E8620
/* 81A04 800E8554 35080050 */   ori      $t0, $t0, 0x50
.L800E8558:
/* 81A08 800E8558 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 81A0C 800E855C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 81A10 800E8560 80420070 */  lb        $v0, 0x70($v0)
/* 81A14 800E8564 1440002D */  bnez      $v0, .L800E861C
/* 81A18 800E8568 3C08ED03 */   lui      $t0, 0xed03
/* 81A1C 800E856C 24020001 */  addiu     $v0, $zero, 1
/* 81A20 800E8570 A262003A */  sb        $v0, 0x3a($s3)
/* 81A24 800E8574 A6600038 */  sh        $zero, 0x38($s3)
/* 81A28 800E8578 0803A187 */  j         .L800E861C
/* 81A2C 800E857C A260003C */   sb       $zero, 0x3c($s3)
.L800E8580:
/* 81A30 800E8580 96620036 */  lhu       $v0, 0x36($s3)
/* 81A34 800E8584 2442FFFB */  addiu     $v0, $v0, -5
/* 81A38 800E8588 A6620036 */  sh        $v0, 0x36($s3)
/* 81A3C 800E858C 00021400 */  sll       $v0, $v0, 0x10
/* 81A40 800E8590 00021403 */  sra       $v0, $v0, 0x10
/* 81A44 800E8594 2842FF9C */  slti      $v0, $v0, -0x64
/* 81A48 800E8598 1040001F */  beqz      $v0, .L800E8618
/* 81A4C 800E859C 2402FF9C */   addiu    $v0, $zero, -0x64
/* 81A50 800E85A0 82630044 */  lb        $v1, 0x44($s3)
/* 81A54 800E85A4 1460001C */  bnez      $v1, .L800E8618
/* 81A58 800E85A8 A6620036 */   sh       $v0, 0x36($s3)
/* 81A5C 800E85AC 822200B4 */  lb        $v0, 0xb4($s1)
/* 81A60 800E85B0 5440000A */  bnel      $v0, $zero, .L800E85DC
/* 81A64 800E85B4 A6600038 */   sh       $zero, 0x38($s3)
/* 81A68 800E85B8 8E220000 */  lw        $v0, ($s1)
/* 81A6C 800E85BC 30423000 */  andi      $v0, $v0, 0x3000
/* 81A70 800E85C0 10400003 */  beqz      $v0, .L800E85D0
/* 81A74 800E85C4 00000000 */   nop
/* 81A78 800E85C8 0803A177 */  j         .L800E85DC
/* 81A7C 800E85CC A6600038 */   sh       $zero, 0x38($s3)
.L800E85D0:
/* 81A80 800E85D0 96620038 */  lhu       $v0, 0x38($s3)
/* 81A84 800E85D4 24420001 */  addiu     $v0, $v0, 1
/* 81A88 800E85D8 A6620038 */  sh        $v0, 0x38($s3)
.L800E85DC:
/* 81A8C 800E85DC 86620038 */  lh        $v0, 0x38($s3)
/* 81A90 800E85E0 284200F0 */  slti      $v0, $v0, 0xf0
/* 81A94 800E85E4 1440000D */  bnez      $v0, .L800E861C
/* 81A98 800E85E8 3C08ED03 */   lui      $t0, 0xed03
/* 81A9C 800E85EC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 81AA0 800E85F0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 81AA4 800E85F4 80420070 */  lb        $v0, 0x70($v0)
/* 81AA8 800E85F8 14400009 */  bnez      $v0, .L800E8620
/* 81AAC 800E85FC 35080050 */   ori      $t0, $t0, 0x50
/* 81AB0 800E8600 240200D2 */  addiu     $v0, $zero, 0xd2
/* 81AB4 800E8604 A6620038 */  sh        $v0, 0x38($s3)
/* 81AB8 800E8608 24020001 */  addiu     $v0, $zero, 1
/* 81ABC 800E860C A260003A */  sb        $zero, 0x3a($s3)
/* 81AC0 800E8610 A262003B */  sb        $v0, 0x3b($s3)
/* 81AC4 800E8614 A262003C */  sb        $v0, 0x3c($s3)
.L800E8618:
/* 81AC8 800E8618 3C08ED03 */  lui       $t0, 0xed03
.L800E861C:
/* 81ACC 800E861C 35080050 */  ori       $t0, $t0, 0x50
.L800E8620:
/* 81AD0 800E8620 3C07004D */  lui       $a3, 0x4d
/* 81AD4 800E8624 34E70370 */  ori       $a3, $a3, 0x370
/* 81AD8 800E8628 0000202D */  daddu     $a0, $zero, $zero
/* 81ADC 800E862C 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 81AE0 800E8630 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 81AE4 800E8634 24050005 */  addiu     $a1, $zero, 5
/* 81AE8 800E8638 241200FF */  addiu     $s2, $zero, 0xff
/* 81AEC 800E863C 24110140 */  addiu     $s1, $zero, 0x140
/* 81AF0 800E8640 8CC30000 */  lw        $v1, ($a2)
/* 81AF4 800E8644 241000F0 */  addiu     $s0, $zero, 0xf0
/* 81AF8 800E8648 0060102D */  daddu     $v0, $v1, $zero
/* 81AFC 800E864C 24630008 */  addiu     $v1, $v1, 8
/* 81B00 800E8650 AC480000 */  sw        $t0, ($v0)
/* 81B04 800E8654 AC470004 */  sw        $a3, 4($v0)
/* 81B08 800E8658 867E0034 */  lh        $fp, 0x34($s3)
/* 81B0C 800E865C 86750036 */  lh        $s5, 0x36($s3)
/* 81B10 800E8660 240200AE */  addiu     $v0, $zero, 0xae
/* 81B14 800E8664 ACC30000 */  sw        $v1, ($a2)
/* 81B18 800E8668 AFA20014 */  sw        $v0, 0x14($sp)
/* 81B1C 800E866C 24020023 */  addiu     $v0, $zero, 0x23
/* 81B20 800E8670 AFA00010 */  sw        $zero, 0x10($sp)
/* 81B24 800E8674 AFA20018 */  sw        $v0, 0x18($sp)
/* 81B28 800E8678 AFB2001C */  sw        $s2, 0x1c($sp)
/* 81B2C 800E867C AFA00020 */  sw        $zero, 0x20($sp)
/* 81B30 800E8680 AFA00024 */  sw        $zero, 0x24($sp)
/* 81B34 800E8684 AFA00028 */  sw        $zero, 0x28($sp)
/* 81B38 800E8688 AFA0002C */  sw        $zero, 0x2c($sp)
/* 81B3C 800E868C AFA00030 */  sw        $zero, 0x30($sp)
/* 81B40 800E8690 AFA00034 */  sw        $zero, 0x34($sp)
/* 81B44 800E8694 AFA00038 */  sw        $zero, 0x38($sp)
/* 81B48 800E8698 AFA0003C */  sw        $zero, 0x3c($sp)
/* 81B4C 800E869C AFA00040 */  sw        $zero, 0x40($sp)
/* 81B50 800E86A0 AFB10044 */  sw        $s1, 0x44($sp)
/* 81B54 800E86A4 AFB00048 */  sw        $s0, 0x48($sp)
/* 81B58 800E86A8 AFA0004C */  sw        $zero, 0x4c($sp)
/* 81B5C 800E86AC 03C0302D */  daddu     $a2, $fp, $zero
/* 81B60 800E86B0 0C03D4B8 */  jal       draw_box
/* 81B64 800E86B4 02A0382D */   daddu    $a3, $s5, $zero
/* 81B68 800E86B8 0000202D */  daddu     $a0, $zero, $zero
/* 81B6C 800E86BC 24050006 */  addiu     $a1, $zero, 6
/* 81B70 800E86C0 27C600AE */  addiu     $a2, $fp, 0xae
/* 81B74 800E86C4 02A0382D */  daddu     $a3, $s5, $zero
/* 81B78 800E86C8 2402007A */  addiu     $v0, $zero, 0x7a
/* 81B7C 800E86CC AFA20014 */  sw        $v0, 0x14($sp)
/* 81B80 800E86D0 24020019 */  addiu     $v0, $zero, 0x19
/* 81B84 800E86D4 AFA00010 */  sw        $zero, 0x10($sp)
/* 81B88 800E86D8 AFA20018 */  sw        $v0, 0x18($sp)
/* 81B8C 800E86DC AFB2001C */  sw        $s2, 0x1c($sp)
/* 81B90 800E86E0 AFA00020 */  sw        $zero, 0x20($sp)
/* 81B94 800E86E4 AFA00024 */  sw        $zero, 0x24($sp)
/* 81B98 800E86E8 AFA00028 */  sw        $zero, 0x28($sp)
/* 81B9C 800E86EC AFA0002C */  sw        $zero, 0x2c($sp)
/* 81BA0 800E86F0 AFA00030 */  sw        $zero, 0x30($sp)
/* 81BA4 800E86F4 AFA00034 */  sw        $zero, 0x34($sp)
/* 81BA8 800E86F8 AFA00038 */  sw        $zero, 0x38($sp)
/* 81BAC 800E86FC AFA0003C */  sw        $zero, 0x3c($sp)
/* 81BB0 800E8700 AFA00040 */  sw        $zero, 0x40($sp)
/* 81BB4 800E8704 AFB10044 */  sw        $s1, 0x44($sp)
/* 81BB8 800E8708 AFB00048 */  sw        $s0, 0x48($sp)
/* 81BBC 800E870C 0C03D4B8 */  jal       draw_box
/* 81BC0 800E8710 AFA0004C */   sw       $zero, 0x4c($sp)
/* 81BC4 800E8714 8262004C */  lb        $v0, 0x4c($s3)
/* 81BC8 800E8718 9263004C */  lbu       $v1, 0x4c($s3)
/* 81BCC 800E871C 18400007 */  blez      $v0, .L800E873C
/* 81BD0 800E8720 2462FFFF */   addiu    $v0, $v1, -1
/* 81BD4 800E8724 A262004C */  sb        $v0, 0x4c($s3)
/* 81BD8 800E8728 00021600 */  sll       $v0, $v0, 0x18
/* 81BDC 800E872C 14400003 */  bnez      $v0, .L800E873C
/* 81BE0 800E8730 00000000 */   nop
/* 81BE4 800E8734 0C03A659 */  jal       status_menu_stop_blinking_hp
/* 81BE8 800E8738 00000000 */   nop
.L800E873C:
/* 81BEC 800E873C 8262004A */  lb        $v0, 0x4a($s3)
/* 81BF0 800E8740 1040000C */  beqz      $v0, .L800E8774
/* 81BF4 800E8744 24160001 */   addiu    $s6, $zero, 1
/* 81BF8 800E8748 8263004B */  lb        $v1, 0x4b($s3)
/* 81BFC 800E874C 28620009 */  slti      $v0, $v1, 9
/* 81C00 800E8750 14400005 */  bnez      $v0, .L800E8768
/* 81C04 800E8754 2862000D */   slti     $v0, $v1, 0xd
/* 81C08 800E8758 14400003 */  bnez      $v0, .L800E8768
/* 81C0C 800E875C 0000B02D */   daddu    $s6, $zero, $zero
/* 81C10 800E8760 A260004B */  sb        $zero, 0x4b($s3)
/* 81C14 800E8764 24160001 */  addiu     $s6, $zero, 1
.L800E8768:
/* 81C18 800E8768 9262004B */  lbu       $v0, 0x4b($s3)
/* 81C1C 800E876C 24420001 */  addiu     $v0, $v0, 1
/* 81C20 800E8770 A262004B */  sb        $v0, 0x4b($s3)
.L800E8774:
/* 81C24 800E8774 12C0001D */  beqz      $s6, .L800E87EC
/* 81C28 800E8778 00000000 */   nop
/* 81C2C 800E877C 8E720000 */  lw        $s2, ($s3)
/* 81C30 800E8780 86650034 */  lh        $a1, 0x34($s3)
/* 81C34 800E8784 86660036 */  lh        $a2, 0x36($s3)
/* 81C38 800E8788 0240202D */  daddu     $a0, $s2, $zero
/* 81C3C 800E878C 24A50016 */  addiu     $a1, $a1, 0x16
/* 81C40 800E8790 0C051261 */  jal       set_hud_element_render_pos
/* 81C44 800E8794 24C6000D */   addiu    $a2, $a2, 0xd
/* 81C48 800E8798 0C0511F1 */  jal       draw_hud_element_2
/* 81C4C 800E879C 0240202D */   daddu    $a0, $s2, $zero
/* 81C50 800E87A0 8E720004 */  lw        $s2, 4($s3)
/* 81C54 800E87A4 86650034 */  lh        $a1, 0x34($s3)
/* 81C58 800E87A8 86660036 */  lh        $a2, 0x36($s3)
/* 81C5C 800E87AC 0240202D */  daddu     $a0, $s2, $zero
/* 81C60 800E87B0 24A50025 */  addiu     $a1, $a1, 0x25
/* 81C64 800E87B4 0C051261 */  jal       set_hud_element_render_pos
/* 81C68 800E87B8 24C6000D */   addiu    $a2, $a2, 0xd
/* 81C6C 800E87BC 0C0511F1 */  jal       draw_hud_element_2
/* 81C70 800E87C0 0240202D */   daddu    $a0, $s2, $zero
/* 81C74 800E87C4 8E640020 */  lw        $a0, 0x20($s3)
/* 81C78 800E87C8 86650034 */  lh        $a1, 0x34($s3)
/* 81C7C 800E87CC 86660036 */  lh        $a2, 0x36($s3)
/* 81C80 800E87D0 8267003D */  lb        $a3, 0x3d($s3)
/* 81C84 800E87D4 3C028011 */  lui       $v0, %hi(gPlayerData+0x3)
/* 81C88 800E87D8 8042F293 */  lb        $v0, %lo(gPlayerData+0x3)($v0)
/* 81C8C 800E87DC 24A50030 */  addiu     $a1, $a1, 0x30
/* 81C90 800E87E0 24C60008 */  addiu     $a2, $a2, 8
/* 81C94 800E87E4 0C039F8D */  jal       status_menu_draw_stat
/* 81C98 800E87E8 AFA20010 */   sw       $v0, 0x10($sp)
.L800E87EC:
/* 81C9C 800E87EC 8262004F */  lb        $v0, 0x4f($s3)
/* 81CA0 800E87F0 9263004F */  lbu       $v1, 0x4f($s3)
/* 81CA4 800E87F4 18400007 */  blez      $v0, .L800E8814
/* 81CA8 800E87F8 2462FFFF */   addiu    $v0, $v1, -1
/* 81CAC 800E87FC A262004F */  sb        $v0, 0x4f($s3)
/* 81CB0 800E8800 00021600 */  sll       $v0, $v0, 0x18
/* 81CB4 800E8804 14400003 */  bnez      $v0, .L800E8814
/* 81CB8 800E8808 00000000 */   nop
/* 81CBC 800E880C 0C03A674 */  jal       status_menu_stop_blinking_fp
/* 81CC0 800E8810 00000000 */   nop
.L800E8814:
/* 81CC4 800E8814 8262004D */  lb        $v0, 0x4d($s3)
/* 81CC8 800E8818 1040000C */  beqz      $v0, .L800E884C
/* 81CCC 800E881C 24160001 */   addiu    $s6, $zero, 1
/* 81CD0 800E8820 8263004E */  lb        $v1, 0x4e($s3)
/* 81CD4 800E8824 28620009 */  slti      $v0, $v1, 9
/* 81CD8 800E8828 14400005 */  bnez      $v0, .L800E8840
/* 81CDC 800E882C 2862000D */   slti     $v0, $v1, 0xd
/* 81CE0 800E8830 14400003 */  bnez      $v0, .L800E8840
/* 81CE4 800E8834 0000B02D */   daddu    $s6, $zero, $zero
/* 81CE8 800E8838 A260004E */  sb        $zero, 0x4e($s3)
/* 81CEC 800E883C 24160001 */  addiu     $s6, $zero, 1
.L800E8840:
/* 81CF0 800E8840 9262004E */  lbu       $v0, 0x4e($s3)
/* 81CF4 800E8844 24420001 */  addiu     $v0, $v0, 1
/* 81CF8 800E8848 A262004E */  sb        $v0, 0x4e($s3)
.L800E884C:
/* 81CFC 800E884C 12C0001D */  beqz      $s6, .L800E88C4
/* 81D00 800E8850 00000000 */   nop
/* 81D04 800E8854 8E720008 */  lw        $s2, 8($s3)
/* 81D08 800E8858 86650034 */  lh        $a1, 0x34($s3)
/* 81D0C 800E885C 86660036 */  lh        $a2, 0x36($s3)
/* 81D10 800E8860 0240202D */  daddu     $a0, $s2, $zero
/* 81D14 800E8864 24A5006E */  addiu     $a1, $a1, 0x6e
/* 81D18 800E8868 0C051261 */  jal       set_hud_element_render_pos
/* 81D1C 800E886C 24C6000D */   addiu    $a2, $a2, 0xd
/* 81D20 800E8870 0C0511F1 */  jal       draw_hud_element_2
/* 81D24 800E8874 0240202D */   daddu    $a0, $s2, $zero
/* 81D28 800E8878 8E72000C */  lw        $s2, 0xc($s3)
/* 81D2C 800E887C 86650034 */  lh        $a1, 0x34($s3)
/* 81D30 800E8880 86660036 */  lh        $a2, 0x36($s3)
/* 81D34 800E8884 0240202D */  daddu     $a0, $s2, $zero
/* 81D38 800E8888 24A5007D */  addiu     $a1, $a1, 0x7d
/* 81D3C 800E888C 0C051261 */  jal       set_hud_element_render_pos
/* 81D40 800E8890 24C6000D */   addiu    $a2, $a2, 0xd
/* 81D44 800E8894 0C0511F1 */  jal       draw_hud_element_2
/* 81D48 800E8898 0240202D */   daddu    $a0, $s2, $zero
/* 81D4C 800E889C 8E640024 */  lw        $a0, 0x24($s3)
/* 81D50 800E88A0 86650034 */  lh        $a1, 0x34($s3)
/* 81D54 800E88A4 86660036 */  lh        $a2, 0x36($s3)
/* 81D58 800E88A8 8267003E */  lb        $a3, 0x3e($s3)
/* 81D5C 800E88AC 3C028011 */  lui       $v0, %hi(gPlayerData+0x6)
/* 81D60 800E88B0 8042F296 */  lb        $v0, %lo(gPlayerData+0x6)($v0)
/* 81D64 800E88B4 24A50088 */  addiu     $a1, $a1, 0x88
/* 81D68 800E88B8 24C60008 */  addiu     $a2, $a2, 8
/* 81D6C 800E88BC 0C039F8D */  jal       status_menu_draw_stat
/* 81D70 800E88C0 AFA20010 */   sw       $v0, 0x10($sp)
.L800E88C4:
/* 81D74 800E88C4 3C028011 */  lui       $v0, %hi(gPlayerData+0x9)
/* 81D78 800E88C8 8042F299 */  lb        $v0, %lo(gPlayerData+0x9)($v0)
/* 81D7C 800E88CC 2842001B */  slti      $v0, $v0, 0x1b
/* 81D80 800E88D0 14400003 */  bnez      $v0, .L800E88E0
/* 81D84 800E88D4 00000000 */   nop
/* 81D88 800E88D8 3C018011 */  lui       $at, %hi(gPlayerData+0x10)
/* 81D8C 800E88DC A020F2A0 */  sb        $zero, %lo(gPlayerData+0x10)($at)
.L800E88E0:
/* 81D90 800E88E0 82620052 */  lb        $v0, 0x52($s3)
/* 81D94 800E88E4 1040000B */  beqz      $v0, .L800E8914
/* 81D98 800E88E8 24160001 */   addiu    $s6, $zero, 1
/* 81D9C 800E88EC 82630053 */  lb        $v1, 0x53($s3)
/* 81DA0 800E88F0 28620009 */  slti      $v0, $v1, 9
/* 81DA4 800E88F4 14400004 */  bnez      $v0, .L800E8908
/* 81DA8 800E88F8 2862000D */   slti     $v0, $v1, 0xd
/* 81DAC 800E88FC 50400002 */  beql      $v0, $zero, .L800E8908
/* 81DB0 800E8900 A2600053 */   sb       $zero, 0x53($s3)
/* 81DB4 800E8904 0000B02D */  daddu     $s6, $zero, $zero
.L800E8908:
/* 81DB8 800E8908 92620053 */  lbu       $v0, 0x53($s3)
/* 81DBC 800E890C 24420001 */  addiu     $v0, $v0, 1
/* 81DC0 800E8910 A2620053 */  sb        $v0, 0x53($s3)
.L800E8914:
/* 81DC4 800E8914 12C0001D */  beqz      $s6, .L800E898C
/* 81DC8 800E8918 00000000 */   nop
/* 81DCC 800E891C 8E720018 */  lw        $s2, 0x18($s3)
/* 81DD0 800E8920 86650034 */  lh        $a1, 0x34($s3)
/* 81DD4 800E8924 86660036 */  lh        $a2, 0x36($s3)
/* 81DD8 800E8928 0240202D */  daddu     $a0, $s2, $zero
/* 81DDC 800E892C 24A500C3 */  addiu     $a1, $a1, 0xc3
/* 81DE0 800E8930 0C051261 */  jal       set_hud_element_render_pos
/* 81DE4 800E8934 24C6000E */   addiu    $a2, $a2, 0xe
/* 81DE8 800E8938 0C0511F1 */  jal       draw_hud_element_2
/* 81DEC 800E893C 0240202D */   daddu    $a0, $s2, $zero
/* 81DF0 800E8940 8E72001C */  lw        $s2, 0x1c($s3)
/* 81DF4 800E8944 86650034 */  lh        $a1, 0x34($s3)
/* 81DF8 800E8948 86660036 */  lh        $a2, 0x36($s3)
/* 81DFC 800E894C 0240202D */  daddu     $a0, $s2, $zero
/* 81E00 800E8950 24A500C3 */  addiu     $a1, $a1, 0xc3
/* 81E04 800E8954 0C051261 */  jal       set_hud_element_render_pos
/* 81E08 800E8958 24C60009 */   addiu    $a2, $a2, 9
/* 81E0C 800E895C 0C0511F1 */  jal       draw_hud_element_2
/* 81E10 800E8960 0240202D */   daddu    $a0, $s2, $zero
/* 81E14 800E8964 8E640028 */  lw        $a0, 0x28($s3)
/* 81E18 800E8968 86650034 */  lh        $a1, 0x34($s3)
/* 81E1C 800E896C 24020002 */  addiu     $v0, $zero, 2
/* 81E20 800E8970 AFA20010 */  sw        $v0, 0x10($sp)
/* 81E24 800E8974 86660036 */  lh        $a2, 0x36($s3)
/* 81E28 800E8978 3C078011 */  lui       $a3, %hi(gPlayerData+0x10)
/* 81E2C 800E897C 80E7F2A0 */  lb        $a3, %lo(gPlayerData+0x10)($a3)
/* 81E30 800E8980 24A500C8 */  addiu     $a1, $a1, 0xc8
/* 81E34 800E8984 0C039F29 */  jal       status_menu_draw_number
/* 81E38 800E8988 24C60008 */   addiu    $a2, $a2, 8
.L800E898C:
/* 81E3C 800E898C 82620056 */  lb        $v0, 0x56($s3)
/* 81E40 800E8990 92630056 */  lbu       $v1, 0x56($s3)
/* 81E44 800E8994 18400007 */  blez      $v0, .L800E89B4
/* 81E48 800E8998 2462FFFF */   addiu    $v0, $v1, -1
/* 81E4C 800E899C A2620056 */  sb        $v0, 0x56($s3)
/* 81E50 800E89A0 00021600 */  sll       $v0, $v0, 0x18
/* 81E54 800E89A4 14400003 */  bnez      $v0, .L800E89B4
/* 81E58 800E89A8 00000000 */   nop
/* 81E5C 800E89AC 0C03A68E */  jal       status_menu_stop_blinking_coins
/* 81E60 800E89B0 00000000 */   nop
.L800E89B4:
/* 81E64 800E89B4 82620054 */  lb        $v0, 0x54($s3)
/* 81E68 800E89B8 1040000C */  beqz      $v0, .L800E89EC
/* 81E6C 800E89BC 24160001 */   addiu    $s6, $zero, 1
/* 81E70 800E89C0 82630055 */  lb        $v1, 0x55($s3)
/* 81E74 800E89C4 28620009 */  slti      $v0, $v1, 9
/* 81E78 800E89C8 14400005 */  bnez      $v0, .L800E89E0
/* 81E7C 800E89CC 2862000D */   slti     $v0, $v1, 0xd
/* 81E80 800E89D0 14400003 */  bnez      $v0, .L800E89E0
/* 81E84 800E89D4 0000B02D */   daddu    $s6, $zero, $zero
/* 81E88 800E89D8 A2600055 */  sb        $zero, 0x55($s3)
/* 81E8C 800E89DC 24160001 */  addiu     $s6, $zero, 1
.L800E89E0:
/* 81E90 800E89E0 92620055 */  lbu       $v0, 0x55($s3)
/* 81E94 800E89E4 24420001 */  addiu     $v0, $v0, 1
/* 81E98 800E89E8 A2620055 */  sb        $v0, 0x55($s3)
.L800E89EC:
/* 81E9C 800E89EC 12C0001C */  beqz      $s6, .L800E8A60
/* 81EA0 800E89F0 00000000 */   nop
/* 81EA4 800E89F4 8E720010 */  lw        $s2, 0x10($s3)
/* 81EA8 800E89F8 86650034 */  lh        $a1, 0x34($s3)
/* 81EAC 800E89FC 86660036 */  lh        $a2, 0x36($s3)
/* 81EB0 800E8A00 0240202D */  daddu     $a0, $s2, $zero
/* 81EB4 800E8A04 24A500F4 */  addiu     $a1, $a1, 0xf4
/* 81EB8 800E8A08 0C051261 */  jal       set_hud_element_render_pos
/* 81EBC 800E8A0C 24C6000E */   addiu    $a2, $a2, 0xe
/* 81EC0 800E8A10 0C0511F1 */  jal       draw_hud_element_2
/* 81EC4 800E8A14 0240202D */   daddu    $a0, $s2, $zero
/* 81EC8 800E8A18 8E720014 */  lw        $s2, 0x14($s3)
/* 81ECC 800E8A1C 86650034 */  lh        $a1, 0x34($s3)
/* 81ED0 800E8A20 86660036 */  lh        $a2, 0x36($s3)
/* 81ED4 800E8A24 0240202D */  daddu     $a0, $s2, $zero
/* 81ED8 800E8A28 24A500F4 */  addiu     $a1, $a1, 0xf4
/* 81EDC 800E8A2C 0C051261 */  jal       set_hud_element_render_pos
/* 81EE0 800E8A30 24C6000E */   addiu    $a2, $a2, 0xe
/* 81EE4 800E8A34 0C0511F1 */  jal       draw_hud_element_2
/* 81EE8 800E8A38 0240202D */   daddu    $a0, $s2, $zero
/* 81EEC 800E8A3C 8E64002C */  lw        $a0, 0x2c($s3)
/* 81EF0 800E8A40 86650034 */  lh        $a1, 0x34($s3)
/* 81EF4 800E8A44 24020003 */  addiu     $v0, $zero, 3
/* 81EF8 800E8A48 AFA20010 */  sw        $v0, 0x10($sp)
/* 81EFC 800E8A4C 86660036 */  lh        $a2, 0x36($s3)
/* 81F00 800E8A50 86670040 */  lh        $a3, 0x40($s3)
/* 81F04 800E8A54 24A500F7 */  addiu     $a1, $a1, 0xf7
/* 81F08 800E8A58 0C039F29 */  jal       status_menu_draw_number
/* 81F0C 800E8A5C 24C60008 */   addiu    $a2, $a2, 8
.L800E8A60:
/* 81F10 800E8A60 82620050 */  lb        $v0, 0x50($s3)
/* 81F14 800E8A64 8E720030 */  lw        $s2, 0x30($s3)
/* 81F18 800E8A68 1040000C */  beqz      $v0, .L800E8A9C
/* 81F1C 800E8A6C 24160001 */   addiu    $s6, $zero, 1
/* 81F20 800E8A70 82630051 */  lb        $v1, 0x51($s3)
/* 81F24 800E8A74 28620006 */  slti      $v0, $v1, 6
/* 81F28 800E8A78 14400005 */  bnez      $v0, .L800E8A90
/* 81F2C 800E8A7C 00000000 */   nop
/* 81F30 800E8A80 28620009 */  slti      $v0, $v1, 9
/* 81F34 800E8A84 50400002 */  beql      $v0, $zero, .L800E8A90
/* 81F38 800E8A88 A2600051 */   sb       $zero, 0x51($s3)
/* 81F3C 800E8A8C 0000B02D */  daddu     $s6, $zero, $zero
.L800E8A90:
/* 81F40 800E8A90 92620051 */  lbu       $v0, 0x51($s3)
/* 81F44 800E8A94 24420001 */  addiu     $v0, $v0, 1
/* 81F48 800E8A98 A2620051 */  sb        $v0, 0x51($s3)
.L800E8A9C:
/* 81F4C 800E8A9C 86620034 */  lh        $v0, 0x34($s3)
/* 81F50 800E8AA0 245E0014 */  addiu     $fp, $v0, 0x14
/* 81F54 800E8AA4 86620036 */  lh        $v0, 0x36($s3)
/* 81F58 800E8AA8 86630048 */  lh        $v1, 0x48($s3)
/* 81F5C 800E8AAC 2455001C */  addiu     $s5, $v0, 0x1c
/* 81F60 800E8AB0 04610002 */  bgez      $v1, .L800E8ABC
/* 81F64 800E8AB4 0060102D */   daddu    $v0, $v1, $zero
/* 81F68 800E8AB8 246200FF */  addiu     $v0, $v1, 0xff
.L800E8ABC:
/* 81F6C 800E8ABC 00021203 */  sra       $v0, $v0, 8
/* 81F70 800E8AC0 0040202D */  daddu     $a0, $v0, $zero
/* 81F74 800E8AC4 00041200 */  sll       $v0, $a0, 8
/* 81F78 800E8AC8 00621023 */  subu      $v0, $v1, $v0
/* 81F7C 800E8ACC 00021400 */  sll       $v0, $v0, 0x10
/* 81F80 800E8AD0 0002A403 */  sra       $s4, $v0, 0x10
/* 81F84 800E8AD4 06810002 */  bgez      $s4, .L800E8AE0
/* 81F88 800E8AD8 0280102D */   daddu    $v0, $s4, $zero
/* 81F8C 800E8ADC 2682001F */  addiu     $v0, $s4, 0x1f
.L800E8AE0:
/* 81F90 800E8AE0 0002A143 */  sra       $s4, $v0, 5
/* 81F94 800E8AE4 000410C0 */  sll       $v0, $a0, 3
/* 81F98 800E8AE8 0282A021 */  addu      $s4, $s4, $v0
/* 81F9C 800E8AEC 82630057 */  lb        $v1, 0x57($s3)
/* 81FA0 800E8AF0 24020001 */  addiu     $v0, $zero, 1
/* 81FA4 800E8AF4 1462002B */  bne       $v1, $v0, .L800E8BA4
/* 81FA8 800E8AF8 00000000 */   nop
/* 81FAC 800E8AFC 3C038011 */  lui       $v1, %hi(gPlayerData+0x290)
/* 81FB0 800E8B00 8463F520 */  lh        $v1, %lo(gPlayerData+0x290)($v1)
/* 81FB4 800E8B04 04610002 */  bgez      $v1, .L800E8B10
/* 81FB8 800E8B08 0060102D */   daddu    $v0, $v1, $zero
/* 81FBC 800E8B0C 246200FF */  addiu     $v0, $v1, 0xff
.L800E8B10:
/* 81FC0 800E8B10 00021203 */  sra       $v0, $v0, 8
/* 81FC4 800E8B14 0040202D */  daddu     $a0, $v0, $zero
/* 81FC8 800E8B18 00041200 */  sll       $v0, $a0, 8
/* 81FCC 800E8B1C 00621023 */  subu      $v0, $v1, $v0
/* 81FD0 800E8B20 00021400 */  sll       $v0, $v0, 0x10
/* 81FD4 800E8B24 0002A403 */  sra       $s4, $v0, 0x10
/* 81FD8 800E8B28 06810002 */  bgez      $s4, .L800E8B34
/* 81FDC 800E8B2C 0280102D */   daddu    $v0, $s4, $zero
/* 81FE0 800E8B30 2682001F */  addiu     $v0, $s4, 0x1f
.L800E8B34:
/* 81FE4 800E8B34 0002A143 */  sra       $s4, $v0, 5
/* 81FE8 800E8B38 000410C0 */  sll       $v0, $a0, 3
/* 81FEC 800E8B3C 0282A021 */  addu      $s4, $s4, $v0
/* 81FF0 800E8B40 3C036666 */  lui       $v1, 0x6666
/* 81FF4 800E8B44 34636667 */  ori       $v1, $v1, 0x6667
/* 81FF8 800E8B48 00141040 */  sll       $v0, $s4, 1
/* 81FFC 800E8B4C 00541021 */  addu      $v0, $v0, $s4
/* 82000 800E8B50 000210C0 */  sll       $v0, $v0, 3
/* 82004 800E8B54 00541021 */  addu      $v0, $v0, $s4
/* 82008 800E8B58 00430018 */  mult      $v0, $v1
/* 8200C 800E8B5C 44950000 */  mtc1      $s5, $f0
/* 82010 800E8B60 00000000 */  nop
/* 82014 800E8B64 46800020 */  cvt.s.w   $f0, $f0
/* 82018 800E8B68 000217C3 */  sra       $v0, $v0, 0x1f
/* 8201C 800E8B6C 44060000 */  mfc1      $a2, $f0
/* 82020 800E8B70 3C073F80 */  lui       $a3, 0x3f80
/* 82024 800E8B74 00004810 */  mfhi      $t1
/* 82028 800E8B78 00091883 */  sra       $v1, $t1, 2
/* 8202C 800E8B7C 00621823 */  subu      $v1, $v1, $v0
/* 82030 800E8B80 03C31821 */  addu      $v1, $fp, $v1
/* 82034 800E8B84 44830000 */  mtc1      $v1, $f0
/* 82038 800E8B88 00000000 */  nop
/* 8203C 800E8B8C 46800020 */  cvt.s.w   $f0, $f0
/* 82040 800E8B90 44050000 */  mfc1      $a1, $f0
/* 82044 800E8B94 0C03C32C */  jal       func_800F0CB0
/* 82048 800E8B98 0000202D */   daddu    $a0, $zero, $zero
/* 8204C 800E8B9C 24020002 */  addiu     $v0, $zero, 2
/* 82050 800E8BA0 A2620057 */  sb        $v0, 0x57($s3)
.L800E8BA4:
/* 82054 800E8BA4 82620057 */  lb        $v0, 0x57($s3)
/* 82058 800E8BA8 10400022 */  beqz      $v0, .L800E8C34
/* 8205C 800E8BAC AFA00054 */   sw       $zero, 0x54($sp)
/* 82060 800E8BB0 82620058 */  lb        $v0, 0x58($s3)
/* 82064 800E8BB4 92630058 */  lbu       $v1, 0x58($s3)
/* 82068 800E8BB8 10400003 */  beqz      $v0, .L800E8BC8
/* 8206C 800E8BBC 2462FFFF */   addiu    $v0, $v1, -1
/* 82070 800E8BC0 0803A2F3 */  j         .L800E8BCC
/* 82074 800E8BC4 A2620058 */   sb       $v0, 0x58($s3)
.L800E8BC8:
/* 82078 800E8BC8 A2600057 */  sb        $zero, 0x57($s3)
.L800E8BCC:
/* 8207C 800E8BCC 3C046666 */  lui       $a0, 0x6666
/* 82080 800E8BD0 92630058 */  lbu       $v1, 0x58($s3)
/* 82084 800E8BD4 34846667 */  ori       $a0, $a0, 0x6667
/* 82088 800E8BD8 00031E00 */  sll       $v1, $v1, 0x18
/* 8208C 800E8BDC 00031603 */  sra       $v0, $v1, 0x18
/* 82090 800E8BE0 00440018 */  mult      $v0, $a0
/* 82094 800E8BE4 00031FC3 */  sra       $v1, $v1, 0x1f
/* 82098 800E8BE8 00004810 */  mfhi      $t1
/* 8209C 800E8BEC 00091043 */  sra       $v0, $t1, 1
/* 820A0 800E8BF0 00431023 */  subu      $v0, $v0, $v1
/* 820A4 800E8BF4 30420001 */  andi      $v0, $v0, 1
/* 820A8 800E8BF8 10400002 */  beqz      $v0, .L800E8C04
/* 820AC 800E8BFC 24090001 */   addiu    $t1, $zero, 1
/* 820B0 800E8C00 AFA90054 */  sw        $t1, 0x54($sp)
.L800E8C04:
/* 820B4 800E8C04 82640059 */  lb        $a0, 0x59($s3)
/* 820B8 800E8C08 04810002 */  bgez      $a0, .L800E8C14
/* 820BC 800E8C0C 0080182D */   daddu    $v1, $a0, $zero
/* 820C0 800E8C10 24830007 */  addiu     $v1, $a0, 7
.L800E8C14:
/* 820C4 800E8C14 000318C3 */  sra       $v1, $v1, 3
/* 820C8 800E8C18 000310C0 */  sll       $v0, $v1, 3
/* 820CC 800E8C1C 00821023 */  subu      $v0, $a0, $v0
/* 820D0 800E8C20 00021600 */  sll       $v0, $v0, 0x18
/* 820D4 800E8C24 0002BE03 */  sra       $s7, $v0, 0x18
/* 820D8 800E8C28 000318C0 */  sll       $v1, $v1, 3
/* 820DC 800E8C2C 0803A30E */  j         .L800E8C38
/* 820E0 800E8C30 02E3B821 */   addu     $s7, $s7, $v1
.L800E8C34:
/* 820E4 800E8C34 0280B82D */  daddu     $s7, $s4, $zero
.L800E8C38:
/* 820E8 800E8C38 0000802D */  daddu     $s0, $zero, $zero
/* 820EC 800E8C3C AFA00050 */  sw        $zero, 0x50($sp)
/* 820F0 800E8C40 82620050 */  lb        $v0, 0x50($s3)
/* 820F4 800E8C44 1040002C */  beqz      $v0, .L800E8CF8
/* 820F8 800E8C48 0200882D */   daddu    $s1, $s0, $zero
/* 820FC 800E8C4C 16C0002B */  bnez      $s6, .L800E8CFC
/* 82100 800E8C50 26A9FFFE */   addiu    $t1, $s5, -2
/* 82104 800E8C54 8262005A */  lb        $v0, 0x5a($s3)
/* 82108 800E8C58 000218C0 */  sll       $v1, $v0, 3
/* 8210C 800E8C5C 8FA90050 */  lw        $t1, 0x50($sp)
/* 82110 800E8C60 0123102A */  slt       $v0, $t1, $v1
/* 82114 800E8C64 50400025 */  beql      $v0, $zero, .L800E8CFC
/* 82118 800E8C68 26A9FFFE */   addiu    $t1, $s5, -2
.L800E8C6C:
/* 8211C 800E8C6C 26100001 */  addiu     $s0, $s0, 1
/* 82120 800E8C70 0203102A */  slt       $v0, $s0, $v1
/* 82124 800E8C74 10400020 */  beqz      $v0, .L800E8CF8
/* 82128 800E8C78 26310001 */   addiu    $s1, $s1, 1
/* 8212C 800E8C7C 26100001 */  addiu     $s0, $s0, 1
/* 82130 800E8C80 0203102A */  slt       $v0, $s0, $v1
/* 82134 800E8C84 1040001C */  beqz      $v0, .L800E8CF8
/* 82138 800E8C88 26310001 */   addiu    $s1, $s1, 1
/* 8213C 800E8C8C 26100001 */  addiu     $s0, $s0, 1
/* 82140 800E8C90 0203102A */  slt       $v0, $s0, $v1
/* 82144 800E8C94 10400018 */  beqz      $v0, .L800E8CF8
/* 82148 800E8C98 26310001 */   addiu    $s1, $s1, 1
/* 8214C 800E8C9C 26100001 */  addiu     $s0, $s0, 1
/* 82150 800E8CA0 0203102A */  slt       $v0, $s0, $v1
/* 82154 800E8CA4 10400014 */  beqz      $v0, .L800E8CF8
/* 82158 800E8CA8 26310001 */   addiu    $s1, $s1, 1
/* 8215C 800E8CAC 26100001 */  addiu     $s0, $s0, 1
/* 82160 800E8CB0 0203102A */  slt       $v0, $s0, $v1
/* 82164 800E8CB4 10400010 */  beqz      $v0, .L800E8CF8
/* 82168 800E8CB8 26310001 */   addiu    $s1, $s1, 1
/* 8216C 800E8CBC 26100001 */  addiu     $s0, $s0, 1
/* 82170 800E8CC0 0203102A */  slt       $v0, $s0, $v1
/* 82174 800E8CC4 1040000C */  beqz      $v0, .L800E8CF8
/* 82178 800E8CC8 26310001 */   addiu    $s1, $s1, 1
/* 8217C 800E8CCC 26100001 */  addiu     $s0, $s0, 1
/* 82180 800E8CD0 0203102A */  slt       $v0, $s0, $v1
/* 82184 800E8CD4 10400008 */  beqz      $v0, .L800E8CF8
/* 82188 800E8CD8 26310001 */   addiu    $s1, $s1, 1
/* 8218C 800E8CDC 26100001 */  addiu     $s0, $s0, 1
/* 82190 800E8CE0 0000882D */  daddu     $s1, $zero, $zero
/* 82194 800E8CE4 8FA90050 */  lw        $t1, 0x50($sp)
/* 82198 800E8CE8 0203102A */  slt       $v0, $s0, $v1
/* 8219C 800E8CEC 25290001 */  addiu     $t1, $t1, 1
/* 821A0 800E8CF0 1440FFDE */  bnez      $v0, .L800E8C6C
/* 821A4 800E8CF4 AFA90050 */   sw       $t1, 0x50($sp)
.L800E8CF8:
/* 821A8 800E8CF8 26A9FFFE */  addiu     $t1, $s5, -2
.L800E8CFC:
/* 821AC 800E8CFC AFA9005C */  sw        $t1, 0x5c($sp)
/* 821B0 800E8D00 8FA90050 */  lw        $t1, 0x50($sp)
/* 821B4 800E8D04 00091080 */  sll       $v0, $t1, 2
/* 821B8 800E8D08 00491021 */  addu      $v0, $v0, $t1
/* 821BC 800E8D0C 00021080 */  sll       $v0, $v0, 2
/* 821C0 800E8D10 005EB021 */  addu      $s6, $v0, $fp
/* 821C4 800E8D14 AFA20060 */  sw        $v0, 0x60($sp)
.L800E8D18:
/* 821C8 800E8D18 0214102A */  slt       $v0, $s0, $s4
.L800E8D1C:
/* 821CC 800E8D1C 104000BE */  beqz      $v0, .L800E9018
/* 821D0 800E8D20 0217102A */   slt      $v0, $s0, $s7
/* 821D4 800E8D24 54400005 */  bnel      $v0, $zero, .L800E8D3C
/* 821D8 800E8D28 26100001 */   addiu    $s0, $s0, 1
/* 821DC 800E8D2C 8FA90054 */  lw        $t1, 0x54($sp)
/* 821E0 800E8D30 112000B9 */  beqz      $t1, .L800E9018
/* 821E4 800E8D34 00000000 */   nop
/* 821E8 800E8D38 26100001 */  addiu     $s0, $s0, 1
.L800E8D3C:
/* 821EC 800E8D3C 0240202D */  daddu     $a0, $s2, $zero
/* 821F0 800E8D40 8FA90050 */  lw        $t1, 0x50($sp)
/* 821F4 800E8D44 3C02800F */  lui       $v0, %hi(D_800F7FB0)
/* 821F8 800E8D48 24427FB0 */  addiu     $v0, $v0, %lo(D_800F7FB0)
/* 821FC 800E8D4C 00094880 */  sll       $t1, $t1, 2
/* 82200 800E8D50 01229821 */  addu      $s3, $t1, $v0
/* 82204 800E8D54 AFA90058 */  sw        $t1, 0x58($sp)
/* 82208 800E8D58 8E650000 */  lw        $a1, ($s3)
/* 8220C 800E8D5C 0C0511FF */  jal       set_hud_element_script
/* 82210 800E8D60 26310001 */   addiu    $s1, $s1, 1
/* 82214 800E8D64 0240202D */  daddu     $a0, $s2, $zero
/* 82218 800E8D68 3C05800F */  lui       $a1, %hi(D_800F7FE8)
/* 8221C 800E8D6C 8CA57FE8 */  lw        $a1, %lo(D_800F7FE8)($a1)
/* 82220 800E8D70 8FA6005C */  lw        $a2, 0x5c($sp)
/* 82224 800E8D74 0C051261 */  jal       set_hud_element_render_pos
/* 82228 800E8D78 02C52821 */   addu     $a1, $s6, $a1
/* 8222C 800E8D7C 0C0511F1 */  jal       draw_hud_element_2
/* 82230 800E8D80 0240202D */   daddu    $a0, $s2, $zero
/* 82234 800E8D84 0214102A */  slt       $v0, $s0, $s4
/* 82238 800E8D88 104000A3 */  beqz      $v0, .L800E9018
/* 8223C 800E8D8C 0217102A */   slt      $v0, $s0, $s7
/* 82240 800E8D90 54400005 */  bnel      $v0, $zero, .L800E8DA8
/* 82244 800E8D94 26100001 */   addiu    $s0, $s0, 1
/* 82248 800E8D98 8FA90054 */  lw        $t1, 0x54($sp)
/* 8224C 800E8D9C 1120009E */  beqz      $t1, .L800E9018
/* 82250 800E8DA0 00000000 */   nop
/* 82254 800E8DA4 26100001 */  addiu     $s0, $s0, 1
.L800E8DA8:
/* 82258 800E8DA8 0240202D */  daddu     $a0, $s2, $zero
/* 8225C 800E8DAC 8E650000 */  lw        $a1, ($s3)
/* 82260 800E8DB0 0C0511FF */  jal       set_hud_element_script
/* 82264 800E8DB4 26310001 */   addiu    $s1, $s1, 1
/* 82268 800E8DB8 0240202D */  daddu     $a0, $s2, $zero
/* 8226C 800E8DBC 3C05800F */  lui       $a1, %hi(D_800F7FEC)
/* 82270 800E8DC0 8CA57FEC */  lw        $a1, %lo(D_800F7FEC)($a1)
/* 82274 800E8DC4 8FA6005C */  lw        $a2, 0x5c($sp)
/* 82278 800E8DC8 0C051261 */  jal       set_hud_element_render_pos
/* 8227C 800E8DCC 02C52821 */   addu     $a1, $s6, $a1
/* 82280 800E8DD0 0C0511F1 */  jal       draw_hud_element_2
/* 82284 800E8DD4 0240202D */   daddu    $a0, $s2, $zero
/* 82288 800E8DD8 0214102A */  slt       $v0, $s0, $s4
/* 8228C 800E8DDC 1040008E */  beqz      $v0, .L800E9018
/* 82290 800E8DE0 0217102A */   slt      $v0, $s0, $s7
/* 82294 800E8DE4 54400005 */  bnel      $v0, $zero, .L800E8DFC
/* 82298 800E8DE8 26100001 */   addiu    $s0, $s0, 1
/* 8229C 800E8DEC 8FA90054 */  lw        $t1, 0x54($sp)
/* 822A0 800E8DF0 11200089 */  beqz      $t1, .L800E9018
/* 822A4 800E8DF4 00000000 */   nop
/* 822A8 800E8DF8 26100001 */  addiu     $s0, $s0, 1
.L800E8DFC:
/* 822AC 800E8DFC 0240202D */  daddu     $a0, $s2, $zero
/* 822B0 800E8E00 8E650000 */  lw        $a1, ($s3)
/* 822B4 800E8E04 0C0511FF */  jal       set_hud_element_script
/* 822B8 800E8E08 26310001 */   addiu    $s1, $s1, 1
/* 822BC 800E8E0C 0240202D */  daddu     $a0, $s2, $zero
/* 822C0 800E8E10 3C05800F */  lui       $a1, %hi(D_800F7FF0)
/* 822C4 800E8E14 8CA57FF0 */  lw        $a1, %lo(D_800F7FF0)($a1)
/* 822C8 800E8E18 8FA6005C */  lw        $a2, 0x5c($sp)
/* 822CC 800E8E1C 0C051261 */  jal       set_hud_element_render_pos
/* 822D0 800E8E20 02C52821 */   addu     $a1, $s6, $a1
/* 822D4 800E8E24 0C0511F1 */  jal       draw_hud_element_2
/* 822D8 800E8E28 0240202D */   daddu    $a0, $s2, $zero
/* 822DC 800E8E2C 0214102A */  slt       $v0, $s0, $s4
/* 822E0 800E8E30 10400079 */  beqz      $v0, .L800E9018
/* 822E4 800E8E34 0217102A */   slt      $v0, $s0, $s7
/* 822E8 800E8E38 54400005 */  bnel      $v0, $zero, .L800E8E50
/* 822EC 800E8E3C 26100001 */   addiu    $s0, $s0, 1
/* 822F0 800E8E40 8FA90054 */  lw        $t1, 0x54($sp)
/* 822F4 800E8E44 11200074 */  beqz      $t1, .L800E9018
/* 822F8 800E8E48 00000000 */   nop
/* 822FC 800E8E4C 26100001 */  addiu     $s0, $s0, 1
.L800E8E50:
/* 82300 800E8E50 0240202D */  daddu     $a0, $s2, $zero
/* 82304 800E8E54 8E650000 */  lw        $a1, ($s3)
/* 82308 800E8E58 0C0511FF */  jal       set_hud_element_script
/* 8230C 800E8E5C 26310001 */   addiu    $s1, $s1, 1
/* 82310 800E8E60 0240202D */  daddu     $a0, $s2, $zero
/* 82314 800E8E64 3C05800F */  lui       $a1, %hi(D_800F7FF4)
/* 82318 800E8E68 8CA57FF4 */  lw        $a1, %lo(D_800F7FF4)($a1)
/* 8231C 800E8E6C 8FA6005C */  lw        $a2, 0x5c($sp)
/* 82320 800E8E70 0C051261 */  jal       set_hud_element_render_pos
/* 82324 800E8E74 02C52821 */   addu     $a1, $s6, $a1
/* 82328 800E8E78 0C0511F1 */  jal       draw_hud_element_2
/* 8232C 800E8E7C 0240202D */   daddu    $a0, $s2, $zero
/* 82330 800E8E80 0214102A */  slt       $v0, $s0, $s4
/* 82334 800E8E84 10400064 */  beqz      $v0, .L800E9018
/* 82338 800E8E88 0217102A */   slt      $v0, $s0, $s7
/* 8233C 800E8E8C 54400005 */  bnel      $v0, $zero, .L800E8EA4
/* 82340 800E8E90 26100001 */   addiu    $s0, $s0, 1
/* 82344 800E8E94 8FA90054 */  lw        $t1, 0x54($sp)
/* 82348 800E8E98 1120005F */  beqz      $t1, .L800E9018
/* 8234C 800E8E9C 00000000 */   nop
/* 82350 800E8EA0 26100001 */  addiu     $s0, $s0, 1
.L800E8EA4:
/* 82354 800E8EA4 0240202D */  daddu     $a0, $s2, $zero
/* 82358 800E8EA8 8E650000 */  lw        $a1, ($s3)
/* 8235C 800E8EAC 0C0511FF */  jal       set_hud_element_script
/* 82360 800E8EB0 26310001 */   addiu    $s1, $s1, 1
/* 82364 800E8EB4 0240202D */  daddu     $a0, $s2, $zero
/* 82368 800E8EB8 3C05800F */  lui       $a1, %hi(D_800F7FF8)
/* 8236C 800E8EBC 8CA57FF8 */  lw        $a1, %lo(D_800F7FF8)($a1)
/* 82370 800E8EC0 8FA6005C */  lw        $a2, 0x5c($sp)
/* 82374 800E8EC4 0C051261 */  jal       set_hud_element_render_pos
/* 82378 800E8EC8 02C52821 */   addu     $a1, $s6, $a1
/* 8237C 800E8ECC 0C0511F1 */  jal       draw_hud_element_2
/* 82380 800E8ED0 0240202D */   daddu    $a0, $s2, $zero
/* 82384 800E8ED4 0214102A */  slt       $v0, $s0, $s4
/* 82388 800E8ED8 1040004F */  beqz      $v0, .L800E9018
/* 8238C 800E8EDC 0217102A */   slt      $v0, $s0, $s7
/* 82390 800E8EE0 54400005 */  bnel      $v0, $zero, .L800E8EF8
/* 82394 800E8EE4 26100001 */   addiu    $s0, $s0, 1
/* 82398 800E8EE8 8FA90054 */  lw        $t1, 0x54($sp)
/* 8239C 800E8EEC 1120004A */  beqz      $t1, .L800E9018
/* 823A0 800E8EF0 00000000 */   nop
/* 823A4 800E8EF4 26100001 */  addiu     $s0, $s0, 1
.L800E8EF8:
/* 823A8 800E8EF8 0240202D */  daddu     $a0, $s2, $zero
/* 823AC 800E8EFC 8E650000 */  lw        $a1, ($s3)
/* 823B0 800E8F00 0C0511FF */  jal       set_hud_element_script
/* 823B4 800E8F04 26310001 */   addiu    $s1, $s1, 1
/* 823B8 800E8F08 0240202D */  daddu     $a0, $s2, $zero
/* 823BC 800E8F0C 3C05800F */  lui       $a1, %hi(D_800F7FFC)
/* 823C0 800E8F10 8CA57FFC */  lw        $a1, %lo(D_800F7FFC)($a1)
/* 823C4 800E8F14 8FA6005C */  lw        $a2, 0x5c($sp)
/* 823C8 800E8F18 0C051261 */  jal       set_hud_element_render_pos
/* 823CC 800E8F1C 02C52821 */   addu     $a1, $s6, $a1
/* 823D0 800E8F20 0C0511F1 */  jal       draw_hud_element_2
/* 823D4 800E8F24 0240202D */   daddu    $a0, $s2, $zero
/* 823D8 800E8F28 0214102A */  slt       $v0, $s0, $s4
/* 823DC 800E8F2C 1040003A */  beqz      $v0, .L800E9018
/* 823E0 800E8F30 0217102A */   slt      $v0, $s0, $s7
/* 823E4 800E8F34 54400005 */  bnel      $v0, $zero, .L800E8F4C
/* 823E8 800E8F38 26100001 */   addiu    $s0, $s0, 1
/* 823EC 800E8F3C 8FA90054 */  lw        $t1, 0x54($sp)
/* 823F0 800E8F40 11200035 */  beqz      $t1, .L800E9018
/* 823F4 800E8F44 00000000 */   nop
/* 823F8 800E8F48 26100001 */  addiu     $s0, $s0, 1
.L800E8F4C:
/* 823FC 800E8F4C 0240202D */  daddu     $a0, $s2, $zero
/* 82400 800E8F50 8E650000 */  lw        $a1, ($s3)
/* 82404 800E8F54 0C0511FF */  jal       set_hud_element_script
/* 82408 800E8F58 26310001 */   addiu    $s1, $s1, 1
/* 8240C 800E8F5C 0240202D */  daddu     $a0, $s2, $zero
/* 82410 800E8F60 3C058010 */  lui       $a1, %hi(D_800F8000)
/* 82414 800E8F64 8CA58000 */  lw        $a1, %lo(D_800F8000)($a1)
/* 82418 800E8F68 8FA6005C */  lw        $a2, 0x5c($sp)
/* 8241C 800E8F6C 0C051261 */  jal       set_hud_element_render_pos
/* 82420 800E8F70 02C52821 */   addu     $a1, $s6, $a1
/* 82424 800E8F74 0C0511F1 */  jal       draw_hud_element_2
/* 82428 800E8F78 0240202D */   daddu    $a0, $s2, $zero
/* 8242C 800E8F7C 0214102A */  slt       $v0, $s0, $s4
/* 82430 800E8F80 10400025 */  beqz      $v0, .L800E9018
/* 82434 800E8F84 0217102A */   slt      $v0, $s0, $s7
/* 82438 800E8F88 54400005 */  bnel      $v0, $zero, .L800E8FA0
/* 8243C 800E8F8C 26100001 */   addiu    $s0, $s0, 1
/* 82440 800E8F90 8FA90054 */  lw        $t1, 0x54($sp)
/* 82444 800E8F94 11200020 */  beqz      $t1, .L800E9018
/* 82448 800E8F98 00000000 */   nop
/* 8244C 800E8F9C 26100001 */  addiu     $s0, $s0, 1
.L800E8FA0:
/* 82450 800E8FA0 0240202D */  daddu     $a0, $s2, $zero
/* 82454 800E8FA4 8FA90058 */  lw        $t1, 0x58($sp)
/* 82458 800E8FA8 0000882D */  daddu     $s1, $zero, $zero
/* 8245C 800E8FAC 3C05800F */  lui       $a1, %hi(D_800F7FCC)
/* 82460 800E8FB0 00A92821 */  addu      $a1, $a1, $t1
/* 82464 800E8FB4 8CA57FCC */  lw        $a1, %lo(D_800F7FCC)($a1)
/* 82468 800E8FB8 8FA90050 */  lw        $t1, 0x50($sp)
/* 8246C 800E8FBC 26D60014 */  addiu     $s6, $s6, 0x14
/* 82470 800E8FC0 25290001 */  addiu     $t1, $t1, 1
/* 82474 800E8FC4 0C0511FF */  jal       set_hud_element_script
/* 82478 800E8FC8 AFA90050 */   sw       $t1, 0x50($sp)
/* 8247C 800E8FCC 0240202D */  daddu     $a0, $s2, $zero
/* 82480 800E8FD0 8FA90060 */  lw        $t1, 0x60($sp)
/* 82484 800E8FD4 02A0302D */  daddu     $a2, $s5, $zero
/* 82488 800E8FD8 2525000C */  addiu     $a1, $t1, 0xc
/* 8248C 800E8FDC 0C051261 */  jal       set_hud_element_render_pos
/* 82490 800E8FE0 03C52821 */   addu     $a1, $fp, $a1
/* 82494 800E8FE4 0C0511F1 */  jal       draw_hud_element_2
/* 82498 800E8FE8 0240202D */   daddu    $a0, $s2, $zero
/* 8249C 800E8FEC 8FA90060 */  lw        $t1, 0x60($sp)
/* 824A0 800E8FF0 0214102A */  slt       $v0, $s0, $s4
/* 824A4 800E8FF4 25290014 */  addiu     $t1, $t1, 0x14
/* 824A8 800E8FF8 10400007 */  beqz      $v0, .L800E9018
/* 824AC 800E8FFC AFA90060 */   sw       $t1, 0x60($sp)
/* 824B0 800E9000 0217102A */  slt       $v0, $s0, $s7
/* 824B4 800E9004 1440FF45 */  bnez      $v0, .L800E8D1C
/* 824B8 800E9008 0214102A */   slt      $v0, $s0, $s4
/* 824BC 800E900C 8FA90054 */  lw        $t1, 0x54($sp)
/* 824C0 800E9010 1520FF41 */  bnez      $t1, .L800E8D18
/* 824C4 800E9014 00000000 */   nop
.L800E9018:
/* 824C8 800E9018 3C16800F */  lui       $s6, %hi(D_800F7FE8)
/* 824CC 800E901C 26D67FE8 */  addiu     $s6, $s6, %lo(D_800F7FE8)
/* 824D0 800E9020 8FA90050 */  lw        $t1, 0x50($sp)
/* 824D4 800E9024 3C048011 */  lui       $a0, %hi(gPlayerData+0x28E)
/* 824D8 800E9028 8084F51E */  lb        $a0, %lo(gPlayerData+0x28E)($a0)
/* 824DC 800E902C 00091080 */  sll       $v0, $t1, 2
/* 824E0 800E9030 00491021 */  addu      $v0, $v0, $t1
/* 824E4 800E9034 00021080 */  sll       $v0, $v0, 2
/* 824E8 800E9038 2457000C */  addiu     $s7, $v0, 0xc
/* 824EC 800E903C 005E9821 */  addu      $s3, $v0, $fp
/* 824F0 800E9040 0004A0C0 */  sll       $s4, $a0, 3
.L800E9044:
/* 824F4 800E9044 0214102A */  slt       $v0, $s0, $s4
/* 824F8 800E9048 10400093 */  beqz      $v0, .L800E9298
/* 824FC 800E904C 00000000 */   nop
/* 82500 800E9050 16200012 */  bnez      $s1, .L800E909C
/* 82504 800E9054 24020001 */   addiu    $v0, $zero, 1
/* 82508 800E9058 26100001 */  addiu     $s0, $s0, 1
/* 8250C 800E905C 3C058011 */  lui       $a1, %hi(D_801083B0)
/* 82510 800E9060 24A583B0 */  addiu     $a1, $a1, %lo(D_801083B0)
/* 82514 800E9064 0C0511FF */  jal       set_hud_element_script
/* 82518 800E9068 0240202D */   daddu    $a0, $s2, $zero
/* 8251C 800E906C 0240202D */  daddu     $a0, $s2, $zero
/* 82520 800E9070 3C05800F */  lui       $a1, %hi(D_800F7FE8)
/* 82524 800E9074 8CA57FE8 */  lw        $a1, %lo(D_800F7FE8)($a1)
/* 82528 800E9078 26A6FFFE */  addiu     $a2, $s5, -2
/* 8252C 800E907C 0C051261 */  jal       set_hud_element_render_pos
/* 82530 800E9080 02652821 */   addu     $a1, $s3, $a1
/* 82534 800E9084 0C0511F1 */  jal       draw_hud_element_2
/* 82538 800E9088 0240202D */   daddu    $a0, $s2, $zero
/* 8253C 800E908C 0214102A */  slt       $v0, $s0, $s4
/* 82540 800E9090 10400081 */  beqz      $v0, .L800E9298
/* 82544 800E9094 24110001 */   addiu    $s1, $zero, 1
/* 82548 800E9098 24020001 */  addiu     $v0, $zero, 1
.L800E909C:
/* 8254C 800E909C 56220011 */  bnel      $s1, $v0, .L800E90E4
/* 82550 800E90A0 24020002 */   addiu    $v0, $zero, 2
/* 82554 800E90A4 02028021 */  addu      $s0, $s0, $v0
/* 82558 800E90A8 3C058011 */  lui       $a1, %hi(D_801083B0)
/* 8255C 800E90AC 24A583B0 */  addiu     $a1, $a1, %lo(D_801083B0)
/* 82560 800E90B0 0C0511FF */  jal       set_hud_element_script
/* 82564 800E90B4 0240202D */   daddu    $a0, $s2, $zero
/* 82568 800E90B8 0240202D */  daddu     $a0, $s2, $zero
/* 8256C 800E90BC 8EC50004 */  lw        $a1, 4($s6)
/* 82570 800E90C0 26A6FFFE */  addiu     $a2, $s5, -2
/* 82574 800E90C4 0C051261 */  jal       set_hud_element_render_pos
/* 82578 800E90C8 02652821 */   addu     $a1, $s3, $a1
/* 8257C 800E90CC 0C0511F1 */  jal       draw_hud_element_2
/* 82580 800E90D0 0240202D */   daddu    $a0, $s2, $zero
/* 82584 800E90D4 0214102A */  slt       $v0, $s0, $s4
/* 82588 800E90D8 1040006F */  beqz      $v0, .L800E9298
/* 8258C 800E90DC 24110002 */   addiu    $s1, $zero, 2
/* 82590 800E90E0 24020002 */  addiu     $v0, $zero, 2
.L800E90E4:
/* 82594 800E90E4 16220011 */  bne       $s1, $v0, .L800E912C
/* 82598 800E90E8 24020003 */   addiu    $v0, $zero, 3
/* 8259C 800E90EC 26100001 */  addiu     $s0, $s0, 1
/* 825A0 800E90F0 3C058011 */  lui       $a1, %hi(D_801083B0)
/* 825A4 800E90F4 24A583B0 */  addiu     $a1, $a1, %lo(D_801083B0)
/* 825A8 800E90F8 0C0511FF */  jal       set_hud_element_script
/* 825AC 800E90FC 0240202D */   daddu    $a0, $s2, $zero
/* 825B0 800E9100 0240202D */  daddu     $a0, $s2, $zero
/* 825B4 800E9104 8EC50008 */  lw        $a1, 8($s6)
/* 825B8 800E9108 26A6FFFE */  addiu     $a2, $s5, -2
/* 825BC 800E910C 0C051261 */  jal       set_hud_element_render_pos
/* 825C0 800E9110 02652821 */   addu     $a1, $s3, $a1
/* 825C4 800E9114 0C0511F1 */  jal       draw_hud_element_2
/* 825C8 800E9118 0240202D */   daddu    $a0, $s2, $zero
/* 825CC 800E911C 0214102A */  slt       $v0, $s0, $s4
/* 825D0 800E9120 1040005D */  beqz      $v0, .L800E9298
/* 825D4 800E9124 24110003 */   addiu    $s1, $zero, 3
/* 825D8 800E9128 24020003 */  addiu     $v0, $zero, 3
.L800E912C:
/* 825DC 800E912C 16220011 */  bne       $s1, $v0, .L800E9174
/* 825E0 800E9130 24020004 */   addiu    $v0, $zero, 4
/* 825E4 800E9134 26100001 */  addiu     $s0, $s0, 1
/* 825E8 800E9138 3C058011 */  lui       $a1, %hi(D_801083B0)
/* 825EC 800E913C 24A583B0 */  addiu     $a1, $a1, %lo(D_801083B0)
/* 825F0 800E9140 0C0511FF */  jal       set_hud_element_script
/* 825F4 800E9144 0240202D */   daddu    $a0, $s2, $zero
/* 825F8 800E9148 0240202D */  daddu     $a0, $s2, $zero
/* 825FC 800E914C 8EC5000C */  lw        $a1, 0xc($s6)
/* 82600 800E9150 26A6FFFE */  addiu     $a2, $s5, -2
/* 82604 800E9154 0C051261 */  jal       set_hud_element_render_pos
/* 82608 800E9158 02652821 */   addu     $a1, $s3, $a1
/* 8260C 800E915C 0C0511F1 */  jal       draw_hud_element_2
/* 82610 800E9160 0240202D */   daddu    $a0, $s2, $zero
/* 82614 800E9164 0214102A */  slt       $v0, $s0, $s4
/* 82618 800E9168 1040004B */  beqz      $v0, .L800E9298
/* 8261C 800E916C 24110004 */   addiu    $s1, $zero, 4
/* 82620 800E9170 24020004 */  addiu     $v0, $zero, 4
.L800E9174:
/* 82624 800E9174 16220011 */  bne       $s1, $v0, .L800E91BC
/* 82628 800E9178 24020005 */   addiu    $v0, $zero, 5
/* 8262C 800E917C 26100001 */  addiu     $s0, $s0, 1
/* 82630 800E9180 3C058011 */  lui       $a1, %hi(D_801083B0)
/* 82634 800E9184 24A583B0 */  addiu     $a1, $a1, %lo(D_801083B0)
/* 82638 800E9188 0C0511FF */  jal       set_hud_element_script
/* 8263C 800E918C 0240202D */   daddu    $a0, $s2, $zero
/* 82640 800E9190 0240202D */  daddu     $a0, $s2, $zero
/* 82644 800E9194 8EC50010 */  lw        $a1, 0x10($s6)
/* 82648 800E9198 26A6FFFE */  addiu     $a2, $s5, -2
/* 8264C 800E919C 0C051261 */  jal       set_hud_element_render_pos
/* 82650 800E91A0 02652821 */   addu     $a1, $s3, $a1
/* 82654 800E91A4 0C0511F1 */  jal       draw_hud_element_2
/* 82658 800E91A8 0240202D */   daddu    $a0, $s2, $zero
/* 8265C 800E91AC 0214102A */  slt       $v0, $s0, $s4
/* 82660 800E91B0 10400039 */  beqz      $v0, .L800E9298
/* 82664 800E91B4 24110005 */   addiu    $s1, $zero, 5
/* 82668 800E91B8 24020005 */  addiu     $v0, $zero, 5
.L800E91BC:
/* 8266C 800E91BC 16220011 */  bne       $s1, $v0, .L800E9204
/* 82670 800E91C0 24020006 */   addiu    $v0, $zero, 6
/* 82674 800E91C4 26100001 */  addiu     $s0, $s0, 1
/* 82678 800E91C8 3C058011 */  lui       $a1, %hi(D_801083B0)
/* 8267C 800E91CC 24A583B0 */  addiu     $a1, $a1, %lo(D_801083B0)
/* 82680 800E91D0 0C0511FF */  jal       set_hud_element_script
/* 82684 800E91D4 0240202D */   daddu    $a0, $s2, $zero
/* 82688 800E91D8 0240202D */  daddu     $a0, $s2, $zero
/* 8268C 800E91DC 8EC50014 */  lw        $a1, 0x14($s6)
/* 82690 800E91E0 26A6FFFE */  addiu     $a2, $s5, -2
/* 82694 800E91E4 0C051261 */  jal       set_hud_element_render_pos
/* 82698 800E91E8 02652821 */   addu     $a1, $s3, $a1
/* 8269C 800E91EC 0C0511F1 */  jal       draw_hud_element_2
/* 826A0 800E91F0 0240202D */   daddu    $a0, $s2, $zero
/* 826A4 800E91F4 0214102A */  slt       $v0, $s0, $s4
/* 826A8 800E91F8 10400027 */  beqz      $v0, .L800E9298
/* 826AC 800E91FC 24110006 */   addiu    $s1, $zero, 6
/* 826B0 800E9200 24020006 */  addiu     $v0, $zero, 6
.L800E9204:
/* 826B4 800E9204 16220011 */  bne       $s1, $v0, .L800E924C
/* 826B8 800E9208 24020007 */   addiu    $v0, $zero, 7
/* 826BC 800E920C 26100001 */  addiu     $s0, $s0, 1
/* 826C0 800E9210 3C058011 */  lui       $a1, %hi(D_801083B0)
/* 826C4 800E9214 24A583B0 */  addiu     $a1, $a1, %lo(D_801083B0)
/* 826C8 800E9218 0C0511FF */  jal       set_hud_element_script
/* 826CC 800E921C 0240202D */   daddu    $a0, $s2, $zero
/* 826D0 800E9220 0240202D */  daddu     $a0, $s2, $zero
/* 826D4 800E9224 8EC50018 */  lw        $a1, 0x18($s6)
/* 826D8 800E9228 26A6FFFE */  addiu     $a2, $s5, -2
/* 826DC 800E922C 0C051261 */  jal       set_hud_element_render_pos
/* 826E0 800E9230 02652821 */   addu     $a1, $s3, $a1
/* 826E4 800E9234 0C0511F1 */  jal       draw_hud_element_2
/* 826E8 800E9238 0240202D */   daddu    $a0, $s2, $zero
/* 826EC 800E923C 0214102A */  slt       $v0, $s0, $s4
/* 826F0 800E9240 10400015 */  beqz      $v0, .L800E9298
/* 826F4 800E9244 24110007 */   addiu    $s1, $zero, 7
/* 826F8 800E9248 24020007 */  addiu     $v0, $zero, 7
.L800E924C:
/* 826FC 800E924C 1622000F */  bne       $s1, $v0, .L800E928C
/* 82700 800E9250 0000882D */   daddu    $s1, $zero, $zero
/* 82704 800E9254 26100001 */  addiu     $s0, $s0, 1
/* 82708 800E9258 3C058011 */  lui       $a1, %hi(D_801084F0)
/* 8270C 800E925C 24A584F0 */  addiu     $a1, $a1, %lo(D_801084F0)
/* 82710 800E9260 0C0511FF */  jal       set_hud_element_script
/* 82714 800E9264 0240202D */   daddu    $a0, $s2, $zero
/* 82718 800E9268 0240202D */  daddu     $a0, $s2, $zero
/* 8271C 800E926C 03D72821 */  addu      $a1, $fp, $s7
/* 82720 800E9270 0C051261 */  jal       set_hud_element_render_pos
/* 82724 800E9274 02A0302D */   daddu    $a2, $s5, $zero
/* 82728 800E9278 0C0511F1 */  jal       draw_hud_element_2
/* 8272C 800E927C 0240202D */   daddu    $a0, $s2, $zero
/* 82730 800E9280 0214102A */  slt       $v0, $s0, $s4
/* 82734 800E9284 10400004 */  beqz      $v0, .L800E9298
/* 82738 800E9288 0000882D */   daddu    $s1, $zero, $zero
.L800E928C:
/* 8273C 800E928C 26F70014 */  addiu     $s7, $s7, 0x14
/* 82740 800E9290 0803A411 */  j         .L800E9044
/* 82744 800E9294 26730014 */   addiu    $s3, $s3, 0x14
.L800E9298:
/* 82748 800E9298 0C03C360 */  jal       func_800F0D80
/* 8274C 800E929C 00000000 */   nop
/* 82750 800E92A0 0C03C40B */  jal       func_800F102C
/* 82754 800E92A4 00000000 */   nop
.L800E92A8:
/* 82758 800E92A8 8FBF008C */  lw        $ra, 0x8c($sp)
/* 8275C 800E92AC 8FBE0088 */  lw        $fp, 0x88($sp)
/* 82760 800E92B0 8FB70084 */  lw        $s7, 0x84($sp)
/* 82764 800E92B4 8FB60080 */  lw        $s6, 0x80($sp)
/* 82768 800E92B8 8FB5007C */  lw        $s5, 0x7c($sp)
/* 8276C 800E92BC 8FB40078 */  lw        $s4, 0x78($sp)
/* 82770 800E92C0 8FB30074 */  lw        $s3, 0x74($sp)
/* 82774 800E92C4 8FB20070 */  lw        $s2, 0x70($sp)
/* 82778 800E92C8 8FB1006C */  lw        $s1, 0x6c($sp)
/* 8277C 800E92CC 8FB00068 */  lw        $s0, 0x68($sp)
/* 82780 800E92D0 03E00008 */  jr        $ra
/* 82784 800E92D4 27BD0090 */   addiu    $sp, $sp, 0x90
