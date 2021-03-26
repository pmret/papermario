.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9298_4302B8
/* 4302B8 802A9298 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4302BC 802A929C AFB10014 */  sw        $s1, 0x14($sp)
/* 4302C0 802A92A0 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 4302C4 802A92A4 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 4302C8 802A92A8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 4302CC 802A92AC AFB20018 */  sw        $s2, 0x18($sp)
/* 4302D0 802A92B0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4302D4 802A92B4 8623004C */  lh        $v1, 0x4c($s1)
/* 4302D8 802A92B8 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 4302DC 802A92BC 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 4302E0 802A92C0 2C62000D */  sltiu     $v0, $v1, 0xd
/* 4302E4 802A92C4 10400147 */  beqz      $v0, L802A97E4_430804
/* 4302E8 802A92C8 00031080 */   sll      $v0, $v1, 2
/* 4302EC 802A92CC 3C01802B */  lui       $at, %hi(jtbl_802A9940_430960)
/* 4302F0 802A92D0 00220821 */  addu      $at, $at, $v0
/* 4302F4 802A92D4 8C229940 */  lw        $v0, %lo(jtbl_802A9940_430960)($at)
/* 4302F8 802A92D8 00400008 */  jr        $v0
/* 4302FC 802A92DC 00000000 */   nop
glabel L802A92E0_430300
/* 430300 802A92E0 0C093EB1 */  jal       set_popup_duration
/* 430304 802A92E4 24040063 */   addiu    $a0, $zero, 0x63
/* 430308 802A92E8 8E300004 */  lw        $s0, 4($s1)
/* 43030C 802A92EC 240500FF */  addiu     $a1, $zero, 0xff
/* 430310 802A92F0 0C0513AC */  jal       icon_set_opacity
/* 430314 802A92F4 0200202D */   daddu    $a0, $s0, $zero
/* 430318 802A92F8 82220061 */  lb        $v0, 0x61($s1)
/* 43031C 802A92FC 10400003 */  beqz      $v0, .L802A930C
/* 430320 802A9300 0200202D */   daddu    $a0, $s0, $zero
/* 430324 802A9304 0C05128B */  jal       clear_icon_flags
/* 430328 802A9308 24050002 */   addiu    $a1, $zero, 2
.L802A930C:
/* 43032C 802A930C 8E300008 */  lw        $s0, 8($s1)
/* 430330 802A9310 240500FF */  addiu     $a1, $zero, 0xff
/* 430334 802A9314 0C0513AC */  jal       icon_set_opacity
/* 430338 802A9318 0200202D */   daddu    $a0, $s0, $zero
/* 43033C 802A931C 82220061 */  lb        $v0, 0x61($s1)
/* 430340 802A9320 10400003 */  beqz      $v0, .L802A9330
/* 430344 802A9324 0200202D */   daddu    $a0, $s0, $zero
/* 430348 802A9328 0C05128B */  jal       clear_icon_flags
/* 43034C 802A932C 24050002 */   addiu    $a1, $zero, 2
.L802A9330:
/* 430350 802A9330 24020001 */  addiu     $v0, $zero, 1
/* 430354 802A9334 080AA5F9 */  j         L802A97E4_430804
/* 430358 802A9338 A622004C */   sh       $v0, 0x4c($s1)
glabel L802A933C_43035C
/* 43035C 802A933C 0C093EB1 */  jal       set_popup_duration
/* 430360 802A9340 24040063 */   addiu    $a0, $zero, 0x63
/* 430364 802A9344 96220056 */  lhu       $v0, 0x56($s1)
/* 430368 802A9348 24420014 */  addiu     $v0, $v0, 0x14
/* 43036C 802A934C A6220056 */  sh        $v0, 0x56($s1)
/* 430370 802A9350 00021400 */  sll       $v0, $v0, 0x10
/* 430374 802A9354 00021403 */  sra       $v0, $v0, 0x10
/* 430378 802A9358 28420033 */  slti      $v0, $v0, 0x33
/* 43037C 802A935C 14400002 */  bnez      $v0, .L802A9368
/* 430380 802A9360 24020032 */   addiu    $v0, $zero, 0x32
/* 430384 802A9364 A6220056 */  sh        $v0, 0x56($s1)
.L802A9368:
/* 430388 802A9368 8E240004 */  lw        $a0, 4($s1)
/* 43038C 802A936C 86250056 */  lh        $a1, 0x56($s1)
/* 430390 802A9370 0C051261 */  jal       set_icon_render_pos
/* 430394 802A9374 86260058 */   lh       $a2, 0x58($s1)
/* 430398 802A9378 8E240008 */  lw        $a0, 8($s1)
/* 43039C 802A937C 86260058 */  lh        $a2, 0x58($s1)
/* 4303A0 802A9380 86250056 */  lh        $a1, 0x56($s1)
/* 4303A4 802A9384 0C051261 */  jal       set_icon_render_pos
/* 4303A8 802A9388 24C6001C */   addiu    $a2, $a2, 0x1c
/* 4303AC 802A938C 080AA5F9 */  j         L802A97E4_430804
/* 4303B0 802A9390 00000000 */   nop
glabel L802A9394_4303B4
/* 4303B4 802A9394 0C093EB1 */  jal       set_popup_duration
/* 4303B8 802A9398 24040063 */   addiu    $a0, $zero, 0x63
/* 4303BC 802A939C 8622004E */  lh        $v0, 0x4e($s1)
/* 4303C0 802A93A0 9623004E */  lhu       $v1, 0x4e($s1)
/* 4303C4 802A93A4 10400003 */  beqz      $v0, .L802A93B4
/* 4303C8 802A93A8 2462FFFF */   addiu    $v0, $v1, -1
/* 4303CC 802A93AC 080AA5F9 */  j         L802A97E4_430804
/* 4303D0 802A93B0 A622004E */   sh       $v0, 0x4e($s1)
.L802A93B4:
/* 4303D4 802A93B4 8E240004 */  lw        $a0, 4($s1)
/* 4303D8 802A93B8 3C058011 */  lui       $a1, %hi(D_80108F30)
/* 4303DC 802A93BC 24A58F30 */  addiu     $a1, $a1, %lo(D_80108F30)
/* 4303E0 802A93C0 0C0511FF */  jal       set_menu_icon_script
/* 4303E4 802A93C4 00000000 */   nop
/* 4303E8 802A93C8 3C048000 */  lui       $a0, 0x8000
/* 4303EC 802A93CC 34840041 */  ori       $a0, $a0, 0x41
/* 4303F0 802A93D0 0000282D */  daddu     $a1, $zero, $zero
/* 4303F4 802A93D4 00A0302D */  daddu     $a2, $a1, $zero
/* 4303F8 802A93D8 96220052 */  lhu       $v0, 0x52($s1)
/* 4303FC 802A93DC 00A0382D */  daddu     $a3, $a1, $zero
/* 430400 802A93E0 A6200044 */  sh        $zero, 0x44($s1)
/* 430404 802A93E4 A2400084 */  sb        $zero, 0x84($s2)
/* 430408 802A93E8 A220005C */  sb        $zero, 0x5c($s1)
/* 43040C 802A93EC 0C0526AE */  jal       sfx_play_sound_with_params
/* 430410 802A93F0 A6220054 */   sh       $v0, 0x54($s1)
/* 430414 802A93F4 2402000B */  addiu     $v0, $zero, 0xb
/* 430418 802A93F8 A622004C */  sh        $v0, 0x4c($s1)
glabel L802A93FC_43041C
/* 43041C 802A93FC 0C093EB1 */  jal       set_popup_duration
/* 430420 802A9400 24040063 */   addiu    $a0, $zero, 0x63
/* 430424 802A9404 86220068 */  lh        $v0, 0x68($s1)
/* 430428 802A9408 1440008F */  bnez      $v0, .L802A9648
/* 43042C 802A940C 00000000 */   nop
/* 430430 802A9410 86220064 */  lh        $v0, 0x64($s1)
/* 430434 802A9414 1040001E */  beqz      $v0, .L802A9490
/* 430438 802A9418 00000000 */   nop
/* 43043C 802A941C 82220080 */  lb        $v0, 0x80($s1)
/* 430440 802A9420 00021040 */  sll       $v0, $v0, 1
/* 430444 802A9424 02221021 */  addu      $v0, $s1, $v0
/* 430448 802A9428 84430074 */  lh        $v1, 0x74($v0)
/* 43044C 802A942C 86220044 */  lh        $v0, 0x44($s1)
/* 430450 802A9430 14600002 */  bnez      $v1, .L802A943C
/* 430454 802A9434 0043001A */   div      $zero, $v0, $v1
/* 430458 802A9438 0007000D */  break     7
.L802A943C:
/* 43045C 802A943C 2401FFFF */   addiu    $at, $zero, -1
/* 430460 802A9440 14610004 */  bne       $v1, $at, .L802A9454
/* 430464 802A9444 3C018000 */   lui      $at, 0x8000
/* 430468 802A9448 14410002 */  bne       $v0, $at, .L802A9454
/* 43046C 802A944C 00000000 */   nop
/* 430470 802A9450 0006000D */  break     6
.L802A9454:
/* 430474 802A9454 00001012 */   mflo     $v0
/* 430478 802A9458 3C036666 */  lui       $v1, 0x6666
/* 43047C 802A945C 34636667 */  ori       $v1, $v1, 0x6667
/* 430480 802A9460 00430018 */  mult      $v0, $v1
/* 430484 802A9464 000217C3 */  sra       $v0, $v0, 0x1f
/* 430488 802A9468 00001810 */  mfhi      $v1
/* 43048C 802A946C 000318C3 */  sra       $v1, $v1, 3
/* 430490 802A9470 00621823 */  subu      $v1, $v1, $v0
/* 430494 802A9474 00031880 */  sll       $v1, $v1, 2
/* 430498 802A9478 96220044 */  lhu       $v0, 0x44($s1)
/* 43049C 802A947C 3C01802B */  lui       $at, %hi(D_802A9922_430942)
/* 4304A0 802A9480 00230821 */  addu      $at, $at, $v1
/* 4304A4 802A9484 94239922 */  lhu       $v1, %lo(D_802A9922_430942)($at)
/* 4304A8 802A9488 080AA526 */  j         .L802A9498
/* 4304AC 802A948C 00431023 */   subu     $v0, $v0, $v1
.L802A9490:
/* 4304B0 802A9490 96220044 */  lhu       $v0, 0x44($s1)
/* 4304B4 802A9494 2442FFF6 */  addiu     $v0, $v0, -0xa
.L802A9498:
/* 4304B8 802A9498 A6220044 */  sh        $v0, 0x44($s1)
/* 4304BC 802A949C 00021400 */  sll       $v0, $v0, 0x10
/* 4304C0 802A94A0 04420001 */  bltzl     $v0, .L802A94A8
/* 4304C4 802A94A4 A6200044 */   sh       $zero, 0x44($s1)
.L802A94A8:
/* 4304C8 802A94A8 86220068 */  lh        $v0, 0x68($s1)
/* 4304CC 802A94AC 14400066 */  bnez      $v0, .L802A9648
/* 4304D0 802A94B0 00000000 */   nop
/* 4304D4 802A94B4 86220064 */  lh        $v0, 0x64($s1)
/* 4304D8 802A94B8 10400044 */  beqz      $v0, .L802A95CC
/* 4304DC 802A94BC 3C040004 */   lui      $a0, 4
/* 4304E0 802A94C0 8E420210 */  lw        $v0, 0x210($s2)
/* 4304E4 802A94C4 00441024 */  and       $v0, $v0, $a0
/* 4304E8 802A94C8 10400005 */  beqz      $v0, .L802A94E0
/* 4304EC 802A94CC 24030001 */   addiu    $v1, $zero, 1
/* 4304F0 802A94D0 8E420210 */  lw        $v0, 0x210($s2)
/* 4304F4 802A94D4 00441024 */  and       $v0, $v0, $a0
/* 4304F8 802A94D8 1440001E */  bnez      $v0, .L802A9554
/* 4304FC 802A94DC A223005C */   sb       $v1, 0x5c($s1)
.L802A94E0:
/* 430500 802A94E0 8222005C */  lb        $v0, 0x5c($s1)
/* 430504 802A94E4 1040001B */  beqz      $v0, .L802A9554
/* 430508 802A94E8 00000000 */   nop
/* 43050C 802A94EC 86240050 */  lh        $a0, 0x50($s1)
/* 430510 802A94F0 8E420434 */  lw        $v0, 0x434($s2)
/* 430514 802A94F4 86230064 */  lh        $v1, 0x64($s1)
/* 430518 802A94F8 00042080 */  sll       $a0, $a0, 2
/* 43051C 802A94FC 00822021 */  addu      $a0, $a0, $v0
/* 430520 802A9500 00031040 */  sll       $v0, $v1, 1
/* 430524 802A9504 00431021 */  addu      $v0, $v0, $v1
/* 430528 802A9508 000210C0 */  sll       $v0, $v0, 3
/* 43052C 802A950C 00431021 */  addu      $v0, $v0, $v1
/* 430530 802A9510 00021900 */  sll       $v1, $v0, 4
/* 430534 802A9514 00431021 */  addu      $v0, $v0, $v1
/* 430538 802A9518 8C840000 */  lw        $a0, ($a0)
/* 43053C 802A951C 00021040 */  sll       $v0, $v0, 1
/* 430540 802A9520 00820018 */  mult      $a0, $v0
/* 430544 802A9524 00002012 */  mflo      $a0
/* 430548 802A9528 3C0268DB */  lui       $v0, 0x68db
/* 43054C 802A952C 34428BAD */  ori       $v0, $v0, 0x8bad
/* 430550 802A9530 00820018 */  mult      $a0, $v0
/* 430554 802A9534 A220005C */  sb        $zero, 0x5c($s1)
/* 430558 802A9538 000427C3 */  sra       $a0, $a0, 0x1f
/* 43055C 802A953C 00001010 */  mfhi      $v0
/* 430560 802A9540 00021B03 */  sra       $v1, $v0, 0xc
/* 430564 802A9544 96220044 */  lhu       $v0, 0x44($s1)
/* 430568 802A9548 00641823 */  subu      $v1, $v1, $a0
/* 43056C 802A954C 00431021 */  addu      $v0, $v0, $v1
/* 430570 802A9550 A6220044 */  sh        $v0, 0x44($s1)
.L802A9554:
/* 430574 802A9554 8E420214 */  lw        $v0, 0x214($s2)
/* 430578 802A9558 3C030008 */  lui       $v1, 8
/* 43057C 802A955C 00431024 */  and       $v0, $v0, $v1
/* 430580 802A9560 10400039 */  beqz      $v0, .L802A9648
/* 430584 802A9564 00000000 */   nop
/* 430588 802A9568 86240050 */  lh        $a0, 0x50($s1)
/* 43058C 802A956C 8E420434 */  lw        $v0, 0x434($s2)
/* 430590 802A9570 86230064 */  lh        $v1, 0x64($s1)
/* 430594 802A9574 00042080 */  sll       $a0, $a0, 2
/* 430598 802A9578 00822021 */  addu      $a0, $a0, $v0
/* 43059C 802A957C 00031040 */  sll       $v0, $v1, 1
/* 4305A0 802A9580 00431021 */  addu      $v0, $v0, $v1
/* 4305A4 802A9584 000210C0 */  sll       $v0, $v0, 3
/* 4305A8 802A9588 00431021 */  addu      $v0, $v0, $v1
/* 4305AC 802A958C 00021900 */  sll       $v1, $v0, 4
/* 4305B0 802A9590 00431021 */  addu      $v0, $v0, $v1
/* 4305B4 802A9594 8C840000 */  lw        $a0, ($a0)
/* 4305B8 802A9598 00021040 */  sll       $v0, $v0, 1
/* 4305BC 802A959C 00820018 */  mult      $a0, $v0
/* 4305C0 802A95A0 00002012 */  mflo      $a0
/* 4305C4 802A95A4 3C0268DB */  lui       $v0, 0x68db
/* 4305C8 802A95A8 34428BAD */  ori       $v0, $v0, 0x8bad
/* 4305CC 802A95AC 00820018 */  mult      $a0, $v0
/* 4305D0 802A95B0 000427C3 */  sra       $a0, $a0, 0x1f
/* 4305D4 802A95B4 00001010 */  mfhi      $v0
/* 4305D8 802A95B8 00021B03 */  sra       $v1, $v0, 0xc
/* 4305DC 802A95BC 96220044 */  lhu       $v0, 0x44($s1)
/* 4305E0 802A95C0 00641823 */  subu      $v1, $v1, $a0
/* 4305E4 802A95C4 080AA591 */  j         .L802A9644
/* 4305E8 802A95C8 00431023 */   subu     $v0, $v0, $v1
.L802A95CC:
/* 4305EC 802A95CC 8E420210 */  lw        $v0, 0x210($s2)
/* 4305F0 802A95D0 00441024 */  and       $v0, $v0, $a0
/* 4305F4 802A95D4 10400006 */  beqz      $v0, .L802A95F0
/* 4305F8 802A95D8 00000000 */   nop
/* 4305FC 802A95DC 8E420210 */  lw        $v0, 0x210($s2)
/* 430600 802A95E0 24030001 */  addiu     $v1, $zero, 1
/* 430604 802A95E4 00441024 */  and       $v0, $v0, $a0
/* 430608 802A95E8 1440000F */  bnez      $v0, .L802A9628
/* 43060C 802A95EC A223005C */   sb       $v1, 0x5c($s1)
.L802A95F0:
/* 430610 802A95F0 8222005C */  lb        $v0, 0x5c($s1)
/* 430614 802A95F4 1040000C */  beqz      $v0, .L802A9628
/* 430618 802A95F8 00000000 */   nop
/* 43061C 802A95FC 96220044 */  lhu       $v0, 0x44($s1)
/* 430620 802A9600 24420064 */  addiu     $v0, $v0, 0x64
/* 430624 802A9604 A6220044 */  sh        $v0, 0x44($s1)
/* 430628 802A9608 00021400 */  sll       $v0, $v0, 0x10
/* 43062C 802A960C 00021403 */  sra       $v0, $v0, 0x10
/* 430630 802A9610 284201F4 */  slti      $v0, $v0, 0x1f4
/* 430634 802A9614 54400004 */  bnel      $v0, $zero, .L802A9628
/* 430638 802A9618 A220005C */   sb       $zero, 0x5c($s1)
/* 43063C 802A961C 240201F4 */  addiu     $v0, $zero, 0x1f4
/* 430640 802A9620 A6220044 */  sh        $v0, 0x44($s1)
/* 430644 802A9624 A220005C */  sb        $zero, 0x5c($s1)
.L802A9628:
/* 430648 802A9628 8E420214 */  lw        $v0, 0x214($s2)
/* 43064C 802A962C 3C030008 */  lui       $v1, 8
/* 430650 802A9630 00431024 */  and       $v0, $v0, $v1
/* 430654 802A9634 10400004 */  beqz      $v0, .L802A9648
/* 430658 802A9638 00000000 */   nop
/* 43065C 802A963C 96220044 */  lhu       $v0, 0x44($s1)
/* 430660 802A9640 2442FF9C */  addiu     $v0, $v0, -0x64
.L802A9644:
/* 430664 802A9644 A6220044 */  sh        $v0, 0x44($s1)
.L802A9648:
/* 430668 802A9648 86220044 */  lh        $v0, 0x44($s1)
/* 43066C 802A964C 04420001 */  bltzl     $v0, .L802A9654
/* 430670 802A9650 A6200044 */   sh       $zero, 0x44($s1)
.L802A9654:
/* 430674 802A9654 86220044 */  lh        $v0, 0x44($s1)
/* 430678 802A9658 28422711 */  slti      $v0, $v0, 0x2711
/* 43067C 802A965C 14400010 */  bnez      $v0, .L802A96A0
/* 430680 802A9660 3C1051EB */   lui      $s0, 0x51eb
/* 430684 802A9664 8E30000C */  lw        $s0, 0xc($s1)
/* 430688 802A9668 86250056 */  lh        $a1, 0x56($s1)
/* 43068C 802A966C 86260058 */  lh        $a2, 0x58($s1)
/* 430690 802A9670 24022710 */  addiu     $v0, $zero, 0x2710
/* 430694 802A9674 A6220044 */  sh        $v0, 0x44($s1)
/* 430698 802A9678 24020001 */  addiu     $v0, $zero, 1
/* 43069C 802A967C A6220068 */  sh        $v0, 0x68($s1)
/* 4306A0 802A9680 0200202D */  daddu     $a0, $s0, $zero
/* 4306A4 802A9684 24A50032 */  addiu     $a1, $a1, 0x32
/* 4306A8 802A9688 0C051261 */  jal       set_icon_render_pos
/* 4306AC 802A968C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 4306B0 802A9690 0200202D */  daddu     $a0, $s0, $zero
/* 4306B4 802A9694 0C05128B */  jal       clear_icon_flags
/* 4306B8 802A9698 24050002 */   addiu    $a1, $zero, 2
/* 4306BC 802A969C 3C1051EB */  lui       $s0, 0x51eb
.L802A96A0:
/* 4306C0 802A96A0 3610851F */  ori       $s0, $s0, 0x851f
/* 4306C4 802A96A4 96230044 */  lhu       $v1, 0x44($s1)
/* 4306C8 802A96A8 3C048000 */  lui       $a0, 0x8000
/* 4306CC 802A96AC 00031C00 */  sll       $v1, $v1, 0x10
/* 4306D0 802A96B0 00031403 */  sra       $v0, $v1, 0x10
/* 4306D4 802A96B4 00500018 */  mult      $v0, $s0
/* 4306D8 802A96B8 34840041 */  ori       $a0, $a0, 0x41
/* 4306DC 802A96BC 0000282D */  daddu     $a1, $zero, $zero
/* 4306E0 802A96C0 00A0302D */  daddu     $a2, $a1, $zero
/* 4306E4 802A96C4 00031FC3 */  sra       $v1, $v1, 0x1f
/* 4306E8 802A96C8 00004810 */  mfhi      $t1
/* 4306EC 802A96CC 00094143 */  sra       $t0, $t1, 5
/* 4306F0 802A96D0 01034023 */  subu      $t0, $t0, $v1
/* 4306F4 802A96D4 00081600 */  sll       $v0, $t0, 0x18
/* 4306F8 802A96D8 00021603 */  sra       $v0, $v0, 0x18
/* 4306FC 802A96DC 00023840 */  sll       $a3, $v0, 1
/* 430700 802A96E0 00E23821 */  addu      $a3, $a3, $v0
/* 430704 802A96E4 00073880 */  sll       $a3, $a3, 2
/* 430708 802A96E8 0C0526F9 */  jal       sfx_adjust_env_sound_params
/* 43070C 802A96EC A2480084 */   sb       $t0, 0x84($s2)
/* 430710 802A96F0 86220054 */  lh        $v0, 0x54($s1)
/* 430714 802A96F4 96230054 */  lhu       $v1, 0x54($s1)
/* 430718 802A96F8 14400036 */  bnez      $v0, .L802A97D4
/* 43071C 802A96FC 2462FFFF */   addiu    $v0, $v1, -1
/* 430720 802A9700 86220064 */  lh        $v0, 0x64($s1)
/* 430724 802A9704 86230044 */  lh        $v1, 0x44($s1)
/* 430728 802A9708 50400001 */  beql      $v0, $zero, .L802A9710
/* 43072C 802A970C 0000182D */   daddu    $v1, $zero, $zero
.L802A9710:
/* 430730 802A9710 14600003 */  bnez      $v1, .L802A9720
/* 430734 802A9714 00700018 */   mult     $v1, $s0
/* 430738 802A9718 080AA5CC */  j         .L802A9730
/* 43073C 802A971C 2402FFFF */   addiu    $v0, $zero, -1
.L802A9720:
/* 430740 802A9720 00031FC3 */  sra       $v1, $v1, 0x1f
/* 430744 802A9724 00004810 */  mfhi      $t1
/* 430748 802A9728 00091143 */  sra       $v0, $t1, 5
/* 43074C 802A972C 00431023 */  subu      $v0, $v0, $v1
.L802A9730:
/* 430750 802A9730 A2420081 */  sb        $v0, 0x81($s2)
/* 430754 802A9734 82220080 */  lb        $v0, 0x80($s1)
/* 430758 802A9738 2442FFFF */  addiu     $v0, $v0, -1
/* 43075C 802A973C 00021040 */  sll       $v0, $v0, 1
/* 430760 802A9740 02221021 */  addu      $v0, $s1, $v0
/* 430764 802A9744 84430074 */  lh        $v1, 0x74($v0)
/* 430768 802A9748 82420081 */  lb        $v0, 0x81($s2)
/* 43076C 802A974C 0062102A */  slt       $v0, $v1, $v0
/* 430770 802A9750 14400002 */  bnez      $v0, .L802A975C
/* 430774 802A9754 24020001 */   addiu    $v0, $zero, 1
/* 430778 802A9758 2402FFFE */  addiu     $v0, $zero, -2
.L802A975C:
/* 43077C 802A975C A2420086 */  sb        $v0, 0x86($s2)
/* 430780 802A9760 82430081 */  lb        $v1, 0x81($s2)
/* 430784 802A9764 24020064 */  addiu     $v0, $zero, 0x64
/* 430788 802A9768 14620003 */  bne       $v1, $v0, .L802A9778
/* 43078C 802A976C 00000000 */   nop
/* 430790 802A9770 0C09A458 */  jal       func_80269160
/* 430794 802A9774 00000000 */   nop
.L802A9778:
/* 430798 802A9778 0C093EB1 */  jal       set_popup_duration
/* 43079C 802A977C 0000202D */   daddu    $a0, $zero, $zero
/* 4307A0 802A9780 3C048000 */  lui       $a0, 0x8000
/* 4307A4 802A9784 0C05271B */  jal       sfx_stop_sound
/* 4307A8 802A9788 34840041 */   ori      $a0, $a0, 0x41
/* 4307AC 802A978C 24020005 */  addiu     $v0, $zero, 5
/* 4307B0 802A9790 A6220054 */  sh        $v0, 0x54($s1)
/* 4307B4 802A9794 2402000C */  addiu     $v0, $zero, 0xc
/* 4307B8 802A9798 080AA5F9 */  j         L802A97E4_430804
/* 4307BC 802A979C A622004C */   sh       $v0, 0x4c($s1)
glabel L802A97A0_4307C0
/* 4307C0 802A97A0 86220064 */  lh        $v0, 0x64($s1)
/* 4307C4 802A97A4 14400007 */  bnez      $v0, .L802A97C4
/* 4307C8 802A97A8 00000000 */   nop
/* 4307CC 802A97AC 96220044 */  lhu       $v0, 0x44($s1)
/* 4307D0 802A97B0 2442FF9C */  addiu     $v0, $v0, -0x64
/* 4307D4 802A97B4 A6220044 */  sh        $v0, 0x44($s1)
/* 4307D8 802A97B8 00021400 */  sll       $v0, $v0, 0x10
/* 4307DC 802A97BC 04420001 */  bltzl     $v0, .L802A97C4
/* 4307E0 802A97C0 A6200044 */   sh       $zero, 0x44($s1)
.L802A97C4:
/* 4307E4 802A97C4 86220054 */  lh        $v0, 0x54($s1)
/* 4307E8 802A97C8 96230054 */  lhu       $v1, 0x54($s1)
/* 4307EC 802A97CC 10400003 */  beqz      $v0, .L802A97DC
/* 4307F0 802A97D0 2462FFFF */   addiu    $v0, $v1, -1
.L802A97D4:
/* 4307F4 802A97D4 080AA5F9 */  j         L802A97E4_430804
/* 4307F8 802A97D8 A6220054 */   sh       $v0, 0x54($s1)
.L802A97DC:
/* 4307FC 802A97DC 0C09A327 */  jal       func_80268C9C
/* 430800 802A97E0 00000000 */   nop
glabel L802A97E4_430804
/* 430804 802A97E4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 430808 802A97E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 43080C 802A97EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 430810 802A97F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 430814 802A97F4 03E00008 */  jr        $ra
/* 430818 802A97F8 27BD0020 */   addiu    $sp, $sp, 0x20
