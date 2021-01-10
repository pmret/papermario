.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9228_42C918
/* 42C918 802A9228 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 42C91C 802A922C AFB10014 */  sw        $s1, 0x14($sp)
/* 42C920 802A9230 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42C924 802A9234 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42C928 802A9238 AFBF0034 */  sw        $ra, 0x34($sp)
/* 42C92C 802A923C AFBE0030 */  sw        $fp, 0x30($sp)
/* 42C930 802A9240 AFB7002C */  sw        $s7, 0x2c($sp)
/* 42C934 802A9244 AFB60028 */  sw        $s6, 0x28($sp)
/* 42C938 802A9248 AFB50024 */  sw        $s5, 0x24($sp)
/* 42C93C 802A924C AFB40020 */  sw        $s4, 0x20($sp)
/* 42C940 802A9250 AFB3001C */  sw        $s3, 0x1c($sp)
/* 42C944 802A9254 AFB20018 */  sw        $s2, 0x18($sp)
/* 42C948 802A9258 AFB00010 */  sw        $s0, 0x10($sp)
/* 42C94C 802A925C 8623004C */  lh        $v1, 0x4c($s1)
/* 42C950 802A9260 3C17800E */  lui       $s7, %hi(gBattleStatus)
/* 42C954 802A9264 26F7C070 */  addiu     $s7, $s7, %lo(gBattleStatus)
/* 42C958 802A9268 2C62000F */  sltiu     $v0, $v1, 0xf
/* 42C95C 802A926C 1040011E */  beqz      $v0, .L802A96E8
/* 42C960 802A9270 00031080 */   sll      $v0, $v1, 2
/* 42C964 802A9274 3C01802B */  lui       $at, %hi(D_802A97E0)
/* 42C968 802A9278 00220821 */  addu      $at, $at, $v0
/* 42C96C 802A927C 8C2297E0 */  lw        $v0, %lo(D_802A97E0)($at)
/* 42C970 802A9280 00400008 */  jr        $v0
/* 42C974 802A9284 00000000 */   nop      
/* 42C978 802A9288 0C093EB1 */  jal       set_popup_duration
/* 42C97C 802A928C 24040063 */   addiu    $a0, $zero, 0x63
/* 42C980 802A9290 82220061 */  lb        $v0, 0x61($s1)
/* 42C984 802A9294 8E300004 */  lw        $s0, 4($s1)
/* 42C988 802A9298 10400003 */  beqz      $v0, .L802A92A8
/* 42C98C 802A929C 0200202D */   daddu    $a0, $s0, $zero
/* 42C990 802A92A0 0C05128B */  jal       clear_icon_flags
/* 42C994 802A92A4 24050002 */   addiu    $a1, $zero, 2
.L802A92A8:
/* 42C998 802A92A8 0200202D */  daddu     $a0, $s0, $zero
/* 42C99C 802A92AC 0C0513AC */  jal       icon_set_opacity
/* 42C9A0 802A92B0 240500FF */   addiu    $a1, $zero, 0xff
/* 42C9A4 802A92B4 24020001 */  addiu     $v0, $zero, 1
/* 42C9A8 802A92B8 080AA5BA */  j         .L802A96E8
/* 42C9AC 802A92BC A622004C */   sh       $v0, 0x4c($s1)
/* 42C9B0 802A92C0 0C093EB1 */  jal       set_popup_duration
/* 42C9B4 802A92C4 24040063 */   addiu    $a0, $zero, 0x63
/* 42C9B8 802A92C8 96220056 */  lhu       $v0, 0x56($s1)
/* 42C9BC 802A92CC 24420014 */  addiu     $v0, $v0, 0x14
/* 42C9C0 802A92D0 A6220056 */  sh        $v0, 0x56($s1)
/* 42C9C4 802A92D4 00021400 */  sll       $v0, $v0, 0x10
/* 42C9C8 802A92D8 00021403 */  sra       $v0, $v0, 0x10
/* 42C9CC 802A92DC 28420033 */  slti      $v0, $v0, 0x33
/* 42C9D0 802A92E0 14400002 */  bnez      $v0, .L802A92EC
/* 42C9D4 802A92E4 24020032 */   addiu    $v0, $zero, 0x32
/* 42C9D8 802A92E8 A6220056 */  sh        $v0, 0x56($s1)
.L802A92EC:
/* 42C9DC 802A92EC 8E240004 */  lw        $a0, 4($s1)
/* 42C9E0 802A92F0 86250056 */  lh        $a1, 0x56($s1)
/* 42C9E4 802A92F4 86260058 */  lh        $a2, 0x58($s1)
/* 42C9E8 802A92F8 24A50015 */  addiu     $a1, $a1, 0x15
/* 42C9EC 802A92FC 0C051261 */  jal       set_icon_render_pos
/* 42C9F0 802A9300 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42C9F4 802A9304 080AA5BA */  j         .L802A96E8
/* 42C9F8 802A9308 00000000 */   nop      
/* 42C9FC 802A930C 0C093EB1 */  jal       set_popup_duration
/* 42CA00 802A9310 24040063 */   addiu    $a0, $zero, 0x63
/* 42CA04 802A9314 8622004E */  lh        $v0, 0x4e($s1)
/* 42CA08 802A9318 9623004E */  lhu       $v1, 0x4e($s1)
/* 42CA0C 802A931C 10400003 */  beqz      $v0, .L802A932C
/* 42CA10 802A9320 2462FFFF */   addiu    $v0, $v1, -1
/* 42CA14 802A9324 080AA5BA */  j         .L802A96E8
/* 42CA18 802A9328 A622004E */   sh       $v0, 0x4e($s1)
.L802A932C:
/* 42CA1C 802A932C 24040002 */  addiu     $a0, $zero, 2
/* 42CA20 802A9330 96220052 */  lhu       $v0, 0x52($s1)
/* 42CA24 802A9334 24030001 */  addiu     $v1, $zero, 1
/* 42CA28 802A9338 A223005D */  sb        $v1, 0x5d($s1)
/* 42CA2C 802A933C 0C00A67F */  jal       rand_int
/* 42CA30 802A9340 A6220054 */   sh       $v0, 0x54($s1)
/* 42CA34 802A9344 A222005C */  sb        $v0, 0x5c($s1)
/* 42CA38 802A9348 2402000B */  addiu     $v0, $zero, 0xb
/* 42CA3C 802A934C A622004C */  sh        $v0, 0x4c($s1)
/* 42CA40 802A9350 A6200072 */  sh        $zero, 0x72($s1)
/* 42CA44 802A9354 0C093EB1 */  jal       set_popup_duration
/* 42CA48 802A9358 24040063 */   addiu    $a0, $zero, 0x63
/* 42CA4C 802A935C 8230005C */  lb        $s0, 0x5c($s1)
.L802A9360:
/* 42CA50 802A9360 0C00A67F */  jal       rand_int
/* 42CA54 802A9364 24040002 */   addiu    $a0, $zero, 2
/* 42CA58 802A9368 A222005C */  sb        $v0, 0x5c($s1)
/* 42CA5C 802A936C 00021600 */  sll       $v0, $v0, 0x18
/* 42CA60 802A9370 00021E03 */  sra       $v1, $v0, 0x18
/* 42CA64 802A9374 1203FFFA */  beq       $s0, $v1, .L802A9360
/* 42CA68 802A9378 00000000 */   nop      
/* 42CA6C 802A937C 8222005D */  lb        $v0, 0x5d($s1)
/* 42CA70 802A9380 00021080 */  sll       $v0, $v0, 2
/* 42CA74 802A9384 02221021 */  addu      $v0, $s1, $v0
/* 42CA78 802A9388 8C500004 */  lw        $s0, 4($v0)
/* 42CA7C 802A938C 00031080 */  sll       $v0, $v1, 2
/* 42CA80 802A9390 3C05802B */  lui       $a1, %hi(D_802A97C0)
/* 42CA84 802A9394 00A22821 */  addu      $a1, $a1, $v0
/* 42CA88 802A9398 8CA597C0 */  lw        $a1, %lo(D_802A97C0)($a1)
/* 42CA8C 802A939C 0C0511FF */  jal       set_menu_icon_script
/* 42CA90 802A93A0 0200202D */   daddu    $a0, $s0, $zero
/* 42CA94 802A93A4 0200202D */  daddu     $a0, $s0, $zero
/* 42CA98 802A93A8 8223005D */  lb        $v1, 0x5d($s1)
/* 42CA9C 802A93AC 86260058 */  lh        $a2, 0x58($s1)
/* 42CAA0 802A93B0 86250056 */  lh        $a1, 0x56($s1)
/* 42CAA4 802A93B4 2463FFFF */  addiu     $v1, $v1, -1
/* 42CAA8 802A93B8 00031080 */  sll       $v0, $v1, 2
/* 42CAAC 802A93BC 00431021 */  addu      $v0, $v0, $v1
/* 42CAB0 802A93C0 00021080 */  sll       $v0, $v0, 2
/* 42CAB4 802A93C4 00A22821 */  addu      $a1, $a1, $v0
/* 42CAB8 802A93C8 0C051261 */  jal       set_icon_render_pos
/* 42CABC 802A93CC 24A50010 */   addiu    $a1, $a1, 0x10
/* 42CAC0 802A93D0 0200202D */  daddu     $a0, $s0, $zero
/* 42CAC4 802A93D4 0C05128B */  jal       clear_icon_flags
/* 42CAC8 802A93D8 24050002 */   addiu    $a1, $zero, 2
/* 42CACC 802A93DC 0C05272D */  jal       play_sound
/* 42CAD0 802A93E0 24040233 */   addiu    $a0, $zero, 0x233
/* 42CAD4 802A93E4 24020001 */  addiu     $v0, $zero, 1
/* 42CAD8 802A93E8 A6220070 */  sh        $v0, 0x70($s1)
/* 42CADC 802A93EC 2402000C */  addiu     $v0, $zero, 0xc
/* 42CAE0 802A93F0 A622004C */  sh        $v0, 0x4c($s1)
/* 42CAE4 802A93F4 0C093EB1 */  jal       set_popup_duration
/* 42CAE8 802A93F8 24040063 */   addiu    $a0, $zero, 0x63
/* 42CAEC 802A93FC 96220054 */  lhu       $v0, 0x54($s1)
/* 42CAF0 802A9400 2442FFFF */  addiu     $v0, $v0, -1
/* 42CAF4 802A9404 A6220054 */  sh        $v0, 0x54($s1)
/* 42CAF8 802A9408 00021400 */  sll       $v0, $v0, 0x10
/* 42CAFC 802A940C 14400004 */  bnez      $v0, .L802A9420
/* 42CB00 802A9410 2402000F */   addiu    $v0, $zero, 0xf
/* 42CB04 802A9414 2402000D */  addiu     $v0, $zero, 0xd
/* 42CB08 802A9418 080AA5BA */  j         .L802A96E8
/* 42CB0C 802A941C A622004C */   sh       $v0, 0x4c($s1)
.L802A9420:
/* 42CB10 802A9420 8223005D */  lb        $v1, 0x5d($s1)
/* 42CB14 802A9424 106200B0 */  beq       $v1, $v0, .L802A96E8
/* 42CB18 802A9428 00000000 */   nop      
/* 42CB1C 802A942C 96220070 */  lhu       $v0, 0x70($s1)
/* 42CB20 802A9430 2442FFFF */  addiu     $v0, $v0, -1
/* 42CB24 802A9434 A6220070 */  sh        $v0, 0x70($s1)
/* 42CB28 802A9438 96220072 */  lhu       $v0, 0x72($s1)
/* 42CB2C 802A943C 86230070 */  lh        $v1, 0x70($s1)
/* 42CB30 802A9440 2442FFFF */  addiu     $v0, $v0, -1
/* 42CB34 802A9444 1C6000A8 */  bgtz      $v1, .L802A96E8
/* 42CB38 802A9448 A6220072 */   sh       $v0, 0x72($s1)
/* 42CB3C 802A944C 04610002 */  bgez      $v1, .L802A9458
/* 42CB40 802A9450 0060A82D */   daddu    $s5, $v1, $zero
/* 42CB44 802A9454 0015A823 */  negu      $s5, $s5
.L802A9458:
/* 42CB48 802A9458 2AA20015 */  slti      $v0, $s5, 0x15
/* 42CB4C 802A945C 50400001 */  beql      $v0, $zero, .L802A9464
/* 42CB50 802A9460 24150014 */   addiu    $s5, $zero, 0x14
.L802A9464:
/* 42CB54 802A9464 82E20431 */  lb        $v0, 0x431($s7)
/* 42CB58 802A9468 00559823 */  subu      $s3, $v0, $s5
/* 42CB5C 802A946C 06620001 */  bltzl     $s3, .L802A9474
/* 42CB60 802A9470 26730040 */   addiu    $s3, $s3, 0x40
.L802A9474:
/* 42CB64 802A9474 52A00001 */  beql      $s5, $zero, .L802A947C
/* 42CB68 802A9478 24150001 */   addiu    $s5, $zero, 1
.L802A947C:
/* 42CB6C 802A947C 1AA0009A */  blez      $s5, .L802A96E8
/* 42CB70 802A9480 0000A02D */   daddu    $s4, $zero, $zero
/* 42CB74 802A9484 24160001 */  addiu     $s6, $zero, 1
/* 42CB78 802A9488 3C1E802B */  lui       $fp, %hi(func_802A97CC_42823C)
/* 42CB7C 802A948C 27DE97CC */  addiu     $fp, $fp, %lo(func_802A97CC_42823C)
/* 42CB80 802A9490 00131080 */  sll       $v0, $s3, 2
/* 42CB84 802A9494 00579021 */  addu      $s2, $v0, $s7
.L802A9498:
/* 42CB88 802A9498 2A620040 */  slti      $v0, $s3, 0x40
/* 42CB8C 802A949C 14400003 */  bnez      $v0, .L802A94AC
/* 42CB90 802A94A0 00000000 */   nop      
/* 42CB94 802A94A4 2652FF00 */  addiu     $s2, $s2, -0x100
/* 42CB98 802A94A8 2673FFC0 */  addiu     $s3, $s3, -0x40
.L802A94AC:
/* 42CB9C 802A94AC 86220072 */  lh        $v0, 0x72($s1)
/* 42CBA0 802A94B0 1C40008D */  bgtz      $v0, .L802A96E8
/* 42CBA4 802A94B4 0000802D */   daddu    $s0, $zero, $zero
/* 42CBA8 802A94B8 8223005C */  lb        $v1, 0x5c($s1)
/* 42CBAC 802A94BC 10760018 */  beq       $v1, $s6, .L802A9520
/* 42CBB0 802A94C0 A2200060 */   sb       $zero, 0x60($s1)
/* 42CBB4 802A94C4 28620002 */  slti      $v0, $v1, 2
/* 42CBB8 802A94C8 10400005 */  beqz      $v0, .L802A94E0
/* 42CBBC 802A94CC 24020002 */   addiu    $v0, $zero, 2
/* 42CBC0 802A94D0 10600007 */  beqz      $v1, .L802A94F0
/* 42CBC4 802A94D4 00000000 */   nop      
/* 42CBC8 802A94D8 080AA55A */  j         .L802A9568
/* 42CBCC 802A94DC 00000000 */   nop      
.L802A94E0:
/* 42CBD0 802A94E0 10620017 */  beq       $v1, $v0, .L802A9540
/* 42CBD4 802A94E4 00000000 */   nop      
/* 42CBD8 802A94E8 080AA55A */  j         .L802A9568
/* 42CBDC 802A94EC 00000000 */   nop      
.L802A94F0:
/* 42CBE0 802A94F0 8222005E */  lb        $v0, 0x5e($s1)
/* 42CBE4 802A94F4 5440001C */  bnel      $v0, $zero, .L802A9568
/* 42CBE8 802A94F8 24100001 */   addiu    $s0, $zero, 1
/* 42CBEC 802A94FC 8E430330 */  lw        $v1, 0x330($s2)
/* 42CBF0 802A9500 10600019 */  beqz      $v1, .L802A9568
/* 42CBF4 802A9504 3C02FFFF */   lui      $v0, 0xffff
/* 42CBF8 802A9508 34427FFF */  ori       $v0, $v0, 0x7fff
/* 42CBFC 802A950C 00621024 */  and       $v0, $v1, $v0
.L802A9510:
/* 42CC00 802A9510 54400015 */  bnel      $v0, $zero, .L802A9568
/* 42CC04 802A9514 A2360060 */   sb       $s6, 0x60($s1)
/* 42CC08 802A9518 080AA55A */  j         .L802A9568
/* 42CC0C 802A951C 24100001 */   addiu    $s0, $zero, 1
.L802A9520:
/* 42CC10 802A9520 8222005E */  lb        $v0, 0x5e($s1)
/* 42CC14 802A9524 54400010 */  bnel      $v0, $zero, .L802A9568
/* 42CC18 802A9528 24100001 */   addiu    $s0, $zero, 1
/* 42CC1C 802A952C 8E430330 */  lw        $v1, 0x330($s2)
/* 42CC20 802A9530 1060000D */  beqz      $v1, .L802A9568
/* 42CC24 802A9534 2402BFFF */   addiu    $v0, $zero, -0x4001
/* 42CC28 802A9538 080AA544 */  j         .L802A9510
/* 42CC2C 802A953C 00621024 */   and      $v0, $v1, $v0
.L802A9540:
/* 42CC30 802A9540 8222005E */  lb        $v0, 0x5e($s1)
/* 42CC34 802A9544 54400008 */  bnel      $v0, $zero, .L802A9568
/* 42CC38 802A9548 24100001 */   addiu    $s0, $zero, 1
/* 42CC3C 802A954C 8E430330 */  lw        $v1, 0x330($s2)
/* 42CC40 802A9550 10600005 */  beqz      $v1, .L802A9568
/* 42CC44 802A9554 2402FFFB */   addiu    $v0, $zero, -5
/* 42CC48 802A9558 00621024 */  and       $v0, $v1, $v0
/* 42CC4C 802A955C 50400002 */  beql      $v0, $zero, .L802A9568
/* 42CC50 802A9560 24100001 */   addiu    $s0, $zero, 1
/* 42CC54 802A9564 A2360060 */  sb        $s6, 0x60($s1)
.L802A9568:
/* 42CC58 802A9568 82220060 */  lb        $v0, 0x60($s1)
/* 42CC5C 802A956C 10400005 */  beqz      $v0, .L802A9584
/* 42CC60 802A9570 2404021D */   addiu    $a0, $zero, 0x21d
/* 42CC64 802A9574 2402000A */  addiu     $v0, $zero, 0xa
/* 42CC68 802A9578 0C05272D */  jal       play_sound
/* 42CC6C 802A957C A6220072 */   sh       $v0, 0x72($s1)
/* 42CC70 802A9580 A6200070 */  sh        $zero, 0x70($s1)
.L802A9584:
/* 42CC74 802A9584 12000036 */  beqz      $s0, .L802A9660
/* 42CC78 802A9588 26520004 */   addiu    $s2, $s2, 4
/* 42CC7C 802A958C 8222005D */  lb        $v0, 0x5d($s1)
/* 42CC80 802A9590 8223005C */  lb        $v1, 0x5c($s1)
/* 42CC84 802A9594 00021080 */  sll       $v0, $v0, 2
/* 42CC88 802A9598 02221021 */  addu      $v0, $s1, $v0
/* 42CC8C 802A959C 00031880 */  sll       $v1, $v1, 2
/* 42CC90 802A95A0 007E1821 */  addu      $v1, $v1, $fp
/* 42CC94 802A95A4 8C500004 */  lw        $s0, 4($v0)
/* 42CC98 802A95A8 8C650000 */  lw        $a1, ($v1)
/* 42CC9C 802A95AC 0C0511FF */  jal       set_menu_icon_script
/* 42CCA0 802A95B0 0200202D */   daddu    $a0, $s0, $zero
/* 42CCA4 802A95B4 3C053F00 */  lui       $a1, 0x3f00
/* 42CCA8 802A95B8 0C051308 */  jal       func_80144C20
/* 42CCAC 802A95BC 0200202D */   daddu    $a0, $s0, $zero
/* 42CCB0 802A95C0 0200202D */  daddu     $a0, $s0, $zero
/* 42CCB4 802A95C4 8222005D */  lb        $v0, 0x5d($s1)
/* 42CCB8 802A95C8 86260058 */  lh        $a2, 0x58($s1)
/* 42CCBC 802A95CC 2442FFFF */  addiu     $v0, $v0, -1
/* 42CCC0 802A95D0 00022880 */  sll       $a1, $v0, 2
/* 42CCC4 802A95D4 00A22821 */  addu      $a1, $a1, $v0
/* 42CCC8 802A95D8 00052880 */  sll       $a1, $a1, 2
/* 42CCCC 802A95DC 86220056 */  lh        $v0, 0x56($s1)
/* 42CCD0 802A95E0 24C60007 */  addiu     $a2, $a2, 7
/* 42CCD4 802A95E4 0C051261 */  jal       set_icon_render_pos
/* 42CCD8 802A95E8 00452821 */   addu     $a1, $v0, $a1
/* 42CCDC 802A95EC 9222005D */  lbu       $v0, 0x5d($s1)
/* 42CCE0 802A95F0 24420001 */  addiu     $v0, $v0, 1
/* 42CCE4 802A95F4 A222005D */  sb        $v0, 0x5d($s1)
/* 42CCE8 802A95F8 86220050 */  lh        $v0, 0x50($s1)
/* 42CCEC 802A95FC 8EE30434 */  lw        $v1, 0x434($s7)
/* 42CCF0 802A9600 00021080 */  sll       $v0, $v0, 2
/* 42CCF4 802A9604 00431021 */  addu      $v0, $v0, $v1
/* 42CCF8 802A9608 8C420000 */  lw        $v0, ($v0)
/* 42CCFC 802A960C 000218C0 */  sll       $v1, $v0, 3
/* 42CD00 802A9610 00621821 */  addu      $v1, $v1, $v0
/* 42CD04 802A9614 96220044 */  lhu       $v0, 0x44($s1)
/* 42CD08 802A9618 00031840 */  sll       $v1, $v1, 1
/* 42CD0C 802A961C 00431021 */  addu      $v0, $v0, $v1
/* 42CD10 802A9620 A6220044 */  sh        $v0, 0x44($s1)
/* 42CD14 802A9624 00021400 */  sll       $v0, $v0, 0x10
/* 42CD18 802A9628 00021403 */  sra       $v0, $v0, 0x10
/* 42CD1C 802A962C 28422711 */  slti      $v0, $v0, 0x2711
/* 42CD20 802A9630 14400003 */  bnez      $v0, .L802A9640
/* 42CD24 802A9634 2404021C */   addiu    $a0, $zero, 0x21c
/* 42CD28 802A9638 24022710 */  addiu     $v0, $zero, 0x2710
/* 42CD2C 802A963C A6220044 */  sh        $v0, 0x44($s1)
.L802A9640:
/* 42CD30 802A9640 92E30084 */  lbu       $v1, 0x84($s7)
/* 42CD34 802A9644 2402000B */  addiu     $v0, $zero, 0xb
/* 42CD38 802A9648 A622004C */  sh        $v0, 0x4c($s1)
/* 42CD3C 802A964C 24630001 */  addiu     $v1, $v1, 1
/* 42CD40 802A9650 0C05272D */  jal       play_sound
/* 42CD44 802A9654 A2E30084 */   sb       $v1, 0x84($s7)
/* 42CD48 802A9658 080AA5BA */  j         .L802A96E8
/* 42CD4C 802A965C 00000000 */   nop      
.L802A9660:
/* 42CD50 802A9660 26940001 */  addiu     $s4, $s4, 1
/* 42CD54 802A9664 0295102A */  slt       $v0, $s4, $s5
/* 42CD58 802A9668 1440FF8B */  bnez      $v0, .L802A9498
/* 42CD5C 802A966C 26730001 */   addiu    $s3, $s3, 1
/* 42CD60 802A9670 080AA5BA */  j         .L802A96E8
/* 42CD64 802A9674 00000000 */   nop      
/* 42CD68 802A9678 82E20084 */  lb        $v0, 0x84($s7)
/* 42CD6C 802A967C 92E30084 */  lbu       $v1, 0x84($s7)
/* 42CD70 802A9680 54400003 */  bnel      $v0, $zero, .L802A9690
/* 42CD74 802A9684 A2E30081 */   sb       $v1, 0x81($s7)
/* 42CD78 802A9688 2402FFFF */  addiu     $v0, $zero, -1
/* 42CD7C 802A968C A2E20081 */  sb        $v0, 0x81($s7)
.L802A9690:
/* 42CD80 802A9690 82E20081 */  lb        $v0, 0x81($s7)
/* 42CD84 802A9694 24030001 */  addiu     $v1, $zero, 1
/* 42CD88 802A9698 2842000A */  slti      $v0, $v0, 0xa
/* 42CD8C 802A969C 14400003 */  bnez      $v0, .L802A96AC
/* 42CD90 802A96A0 A2E30086 */   sb       $v1, 0x86($s7)
/* 42CD94 802A96A4 0C09A458 */  jal       func_80269160
/* 42CD98 802A96A8 00000000 */   nop      
.L802A96AC:
/* 42CD9C 802A96AC 0C093EB1 */  jal       set_popup_duration
/* 42CDA0 802A96B0 0000202D */   daddu    $a0, $zero, $zero
/* 42CDA4 802A96B4 24020005 */  addiu     $v0, $zero, 5
/* 42CDA8 802A96B8 A6220054 */  sh        $v0, 0x54($s1)
/* 42CDAC 802A96BC 2402000E */  addiu     $v0, $zero, 0xe
/* 42CDB0 802A96C0 080AA5BA */  j         .L802A96E8
/* 42CDB4 802A96C4 A622004C */   sh       $v0, 0x4c($s1)
/* 42CDB8 802A96C8 86220054 */  lh        $v0, 0x54($s1)
/* 42CDBC 802A96CC 96230054 */  lhu       $v1, 0x54($s1)
/* 42CDC0 802A96D0 10400003 */  beqz      $v0, .L802A96E0
/* 42CDC4 802A96D4 2462FFFF */   addiu    $v0, $v1, -1
/* 42CDC8 802A96D8 080AA5BA */  j         .L802A96E8
/* 42CDCC 802A96DC A6220054 */   sh       $v0, 0x54($s1)
.L802A96E0:
/* 42CDD0 802A96E0 0C09A327 */  jal       func_80268C9C
/* 42CDD4 802A96E4 00000000 */   nop      
.L802A96E8:
/* 42CDD8 802A96E8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 42CDDC 802A96EC 8FBE0030 */  lw        $fp, 0x30($sp)
/* 42CDE0 802A96F0 8FB7002C */  lw        $s7, 0x2c($sp)
/* 42CDE4 802A96F4 8FB60028 */  lw        $s6, 0x28($sp)
/* 42CDE8 802A96F8 8FB50024 */  lw        $s5, 0x24($sp)
/* 42CDEC 802A96FC 8FB40020 */  lw        $s4, 0x20($sp)
/* 42CDF0 802A9700 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42CDF4 802A9704 8FB20018 */  lw        $s2, 0x18($sp)
/* 42CDF8 802A9708 8FB10014 */  lw        $s1, 0x14($sp)
/* 42CDFC 802A970C 8FB00010 */  lw        $s0, 0x10($sp)
/* 42CE00 802A9710 03E00008 */  jr        $ra
/* 42CE04 802A9714 27BD0038 */   addiu    $sp, $sp, 0x38
