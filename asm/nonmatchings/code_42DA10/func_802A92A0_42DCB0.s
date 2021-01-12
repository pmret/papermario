.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A92A0_42DCB0
/* 42DCB0 802A92A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42DCB4 802A92A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 42DCB8 802A92A8 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42DCBC 802A92AC 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42DCC0 802A92B0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 42DCC4 802A92B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 42DCC8 802A92B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 42DCCC 802A92BC 8623004C */  lh        $v1, 0x4c($s1)
/* 42DCD0 802A92C0 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 42DCD4 802A92C4 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 42DCD8 802A92C8 2C62000D */  sltiu     $v0, $v1, 0xd
/* 42DCDC 802A92CC 10400144 */  beqz      $v0, .L802A97E0
/* 42DCE0 802A92D0 00031080 */   sll      $v0, $v1, 2
/* 42DCE4 802A92D4 3C01802B */  lui       $at, %hi(D_802A9950)
/* 42DCE8 802A92D8 00220821 */  addu      $at, $at, $v0
/* 42DCEC 802A92DC 8C229950 */  lw        $v0, %lo(D_802A9950)($at)
/* 42DCF0 802A92E0 00400008 */  jr        $v0
/* 42DCF4 802A92E4 00000000 */   nop      
/* 42DCF8 802A92E8 0C093EB1 */  jal       set_popup_duration
/* 42DCFC 802A92EC 24040063 */   addiu    $a0, $zero, 0x63
/* 42DD00 802A92F0 82220061 */  lb        $v0, 0x61($s1)
/* 42DD04 802A92F4 8E300004 */  lw        $s0, 4($s1)
/* 42DD08 802A92F8 10400003 */  beqz      $v0, .L802A9308
/* 42DD0C 802A92FC 0200202D */   daddu    $a0, $s0, $zero
/* 42DD10 802A9300 0C05128B */  jal       clear_icon_flags
/* 42DD14 802A9304 24050002 */   addiu    $a1, $zero, 2
.L802A9308:
/* 42DD18 802A9308 0200202D */  daddu     $a0, $s0, $zero
/* 42DD1C 802A930C 0C0513AC */  jal       icon_set_opacity
/* 42DD20 802A9310 240500FF */   addiu    $a1, $zero, 0xff
/* 42DD24 802A9314 82220061 */  lb        $v0, 0x61($s1)
/* 42DD28 802A9318 8E30000C */  lw        $s0, 0xc($s1)
/* 42DD2C 802A931C 10400004 */  beqz      $v0, .L802A9330
/* 42DD30 802A9320 0200202D */   daddu    $a0, $s0, $zero
/* 42DD34 802A9324 0C05128B */  jal       clear_icon_flags
/* 42DD38 802A9328 24050002 */   addiu    $a1, $zero, 2
/* 42DD3C 802A932C 0200202D */  daddu     $a0, $s0, $zero
.L802A9330:
/* 42DD40 802A9330 0C0513AC */  jal       icon_set_opacity
/* 42DD44 802A9334 240500FF */   addiu    $a1, $zero, 0xff
/* 42DD48 802A9338 8E300008 */  lw        $s0, 8($s1)
/* 42DD4C 802A933C 240500FF */  addiu     $a1, $zero, 0xff
/* 42DD50 802A9340 0C0513AC */  jal       icon_set_opacity
/* 42DD54 802A9344 0200202D */   daddu    $a0, $s0, $zero
/* 42DD58 802A9348 82220061 */  lb        $v0, 0x61($s1)
/* 42DD5C 802A934C 10400003 */  beqz      $v0, .L802A935C
/* 42DD60 802A9350 0200202D */   daddu    $a0, $s0, $zero
/* 42DD64 802A9354 0C05128B */  jal       clear_icon_flags
/* 42DD68 802A9358 24050002 */   addiu    $a1, $zero, 2
.L802A935C:
/* 42DD6C 802A935C 24020001 */  addiu     $v0, $zero, 1
/* 42DD70 802A9360 080AA5F8 */  j         .L802A97E0
/* 42DD74 802A9364 A622004C */   sh       $v0, 0x4c($s1)
/* 42DD78 802A9368 0C093EB1 */  jal       set_popup_duration
/* 42DD7C 802A936C 24040063 */   addiu    $a0, $zero, 0x63
/* 42DD80 802A9370 8622006C */  lh        $v0, 0x6c($s1)
/* 42DD84 802A9374 9623006C */  lhu       $v1, 0x6c($s1)
/* 42DD88 802A9378 10400003 */  beqz      $v0, .L802A9388
/* 42DD8C 802A937C 2462FFFF */   addiu    $v0, $v1, -1
/* 42DD90 802A9380 080AA5F8 */  j         .L802A97E0
/* 42DD94 802A9384 A622006C */   sh       $v0, 0x6c($s1)
.L802A9388:
/* 42DD98 802A9388 96220056 */  lhu       $v0, 0x56($s1)
/* 42DD9C 802A938C 24420014 */  addiu     $v0, $v0, 0x14
/* 42DDA0 802A9390 A6220056 */  sh        $v0, 0x56($s1)
/* 42DDA4 802A9394 00021400 */  sll       $v0, $v0, 0x10
/* 42DDA8 802A9398 00021403 */  sra       $v0, $v0, 0x10
/* 42DDAC 802A939C 28420033 */  slti      $v0, $v0, 0x33
/* 42DDB0 802A93A0 14400002 */  bnez      $v0, .L802A93AC
/* 42DDB4 802A93A4 24020032 */   addiu    $v0, $zero, 0x32
/* 42DDB8 802A93A8 A6220056 */  sh        $v0, 0x56($s1)
.L802A93AC:
/* 42DDBC 802A93AC 8E240004 */  lw        $a0, 4($s1)
/* 42DDC0 802A93B0 86250056 */  lh        $a1, 0x56($s1)
/* 42DDC4 802A93B4 86260058 */  lh        $a2, 0x58($s1)
/* 42DDC8 802A93B8 0C051261 */  jal       set_icon_render_pos
/* 42DDCC 802A93BC 24A5FFEF */   addiu    $a1, $a1, -0x11
/* 42DDD0 802A93C0 8E24000C */  lw        $a0, 0xc($s1)
/* 42DDD4 802A93C4 86250056 */  lh        $a1, 0x56($s1)
/* 42DDD8 802A93C8 86260058 */  lh        $a2, 0x58($s1)
/* 42DDDC 802A93CC 0C051261 */  jal       set_icon_render_pos
/* 42DDE0 802A93D0 24A50017 */   addiu    $a1, $a1, 0x17
/* 42DDE4 802A93D4 8E240008 */  lw        $a0, 8($s1)
/* 42DDE8 802A93D8 86260058 */  lh        $a2, 0x58($s1)
/* 42DDEC 802A93DC 86250056 */  lh        $a1, 0x56($s1)
/* 42DDF0 802A93E0 0C051261 */  jal       set_icon_render_pos
/* 42DDF4 802A93E4 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42DDF8 802A93E8 080AA5F8 */  j         .L802A97E0
/* 42DDFC 802A93EC 00000000 */   nop      
/* 42DE00 802A93F0 0C093EB1 */  jal       set_popup_duration
/* 42DE04 802A93F4 24040063 */   addiu    $a0, $zero, 0x63
/* 42DE08 802A93F8 8622004E */  lh        $v0, 0x4e($s1)
/* 42DE0C 802A93FC 9623004E */  lhu       $v1, 0x4e($s1)
/* 42DE10 802A9400 10400003 */  beqz      $v0, .L802A9410
/* 42DE14 802A9404 2462FFFF */   addiu    $v0, $v1, -1
/* 42DE18 802A9408 080AA5F8 */  j         .L802A97E0
/* 42DE1C 802A940C A622004E */   sh       $v0, 0x4e($s1)
.L802A9410:
/* 42DE20 802A9410 8E240004 */  lw        $a0, 4($s1)
/* 42DE24 802A9414 3C058011 */  lui       $a1, %hi(D_80108B80)
/* 42DE28 802A9418 24A58B80 */  addiu     $a1, $a1, %lo(D_80108B80)
/* 42DE2C 802A941C 0C0511FF */  jal       set_menu_icon_script
/* 42DE30 802A9420 00000000 */   nop      
/* 42DE34 802A9424 8E24000C */  lw        $a0, 0xc($s1)
/* 42DE38 802A9428 3C058029 */  lui       $a1, %hi(D_80292374)
/* 42DE3C 802A942C 24A52374 */  addiu     $a1, $a1, %lo(D_80292374)
/* 42DE40 802A9430 0C0511FF */  jal       set_menu_icon_script
/* 42DE44 802A9434 00000000 */   nop      
/* 42DE48 802A9438 3C048000 */  lui       $a0, 0x8000
/* 42DE4C 802A943C 34840041 */  ori       $a0, $a0, 0x41
/* 42DE50 802A9440 0000282D */  daddu     $a1, $zero, $zero
/* 42DE54 802A9444 00A0302D */  daddu     $a2, $a1, $zero
/* 42DE58 802A9448 96220052 */  lhu       $v0, 0x52($s1)
/* 42DE5C 802A944C 00A0382D */  daddu     $a3, $a1, $zero
/* 42DE60 802A9450 A6200044 */  sh        $zero, 0x44($s1)
/* 42DE64 802A9454 A220005C */  sb        $zero, 0x5c($s1)
/* 42DE68 802A9458 0C0526AE */  jal       _play_sound
/* 42DE6C 802A945C A6220054 */   sh       $v0, 0x54($s1)
/* 42DE70 802A9460 2402000B */  addiu     $v0, $zero, 0xb
/* 42DE74 802A9464 A622004C */  sh        $v0, 0x4c($s1)
/* 42DE78 802A9468 0C093EB1 */  jal       set_popup_duration
/* 42DE7C 802A946C 24040063 */   addiu    $a0, $zero, 0x63
/* 42DE80 802A9470 86220068 */  lh        $v0, 0x68($s1)
/* 42DE84 802A9474 14400027 */  bnez      $v0, .L802A9514
/* 42DE88 802A9478 00000000 */   nop      
/* 42DE8C 802A947C 86220064 */  lh        $v0, 0x64($s1)
/* 42DE90 802A9480 1040001E */  beqz      $v0, .L802A94FC
/* 42DE94 802A9484 00000000 */   nop      
/* 42DE98 802A9488 82220080 */  lb        $v0, 0x80($s1)
/* 42DE9C 802A948C 00021040 */  sll       $v0, $v0, 1
/* 42DEA0 802A9490 02221021 */  addu      $v0, $s1, $v0
/* 42DEA4 802A9494 84430074 */  lh        $v1, 0x74($v0)
/* 42DEA8 802A9498 86220044 */  lh        $v0, 0x44($s1)
/* 42DEAC 802A949C 14600002 */  bnez      $v1, .L802A94A8
/* 42DEB0 802A94A0 0043001A */   div      $zero, $v0, $v1
/* 42DEB4 802A94A4 0007000D */  break     7
.L802A94A8:
/* 42DEB8 802A94A8 2401FFFF */   addiu    $at, $zero, -1
/* 42DEBC 802A94AC 14610004 */  bne       $v1, $at, .L802A94C0
/* 42DEC0 802A94B0 3C018000 */   lui      $at, 0x8000
/* 42DEC4 802A94B4 14410002 */  bne       $v0, $at, .L802A94C0
/* 42DEC8 802A94B8 00000000 */   nop      
/* 42DECC 802A94BC 0006000D */  break     6
.L802A94C0:
/* 42DED0 802A94C0 00001012 */   mflo     $v0
/* 42DED4 802A94C4 3C036666 */  lui       $v1, 0x6666
/* 42DED8 802A94C8 34636667 */  ori       $v1, $v1, 0x6667
/* 42DEDC 802A94CC 00430018 */  mult      $v0, $v1
/* 42DEE0 802A94D0 000217C3 */  sra       $v0, $v0, 0x1f
/* 42DEE4 802A94D4 00001810 */  mfhi      $v1
/* 42DEE8 802A94D8 000318C3 */  sra       $v1, $v1, 3
/* 42DEEC 802A94DC 00621823 */  subu      $v1, $v1, $v0
/* 42DEF0 802A94E0 00031880 */  sll       $v1, $v1, 2
/* 42DEF4 802A94E4 96220044 */  lhu       $v0, 0x44($s1)
/* 42DEF8 802A94E8 3C01802B */  lui       $at, %hi(D_802A9932)
/* 42DEFC 802A94EC 00230821 */  addu      $at, $at, $v1
/* 42DF00 802A94F0 94239932 */  lhu       $v1, %lo(D_802A9932)($at)
/* 42DF04 802A94F4 080AA541 */  j         .L802A9504
/* 42DF08 802A94F8 00431023 */   subu     $v0, $v0, $v1
.L802A94FC:
/* 42DF0C 802A94FC 96220044 */  lhu       $v0, 0x44($s1)
/* 42DF10 802A9500 2442FFF6 */  addiu     $v0, $v0, -0xa
.L802A9504:
/* 42DF14 802A9504 A6220044 */  sh        $v0, 0x44($s1)
/* 42DF18 802A9508 00021400 */  sll       $v0, $v0, 0x10
/* 42DF1C 802A950C 04420001 */  bltzl     $v0, .L802A9514
/* 42DF20 802A9510 A6200044 */   sh       $zero, 0x44($s1)
.L802A9514:
/* 42DF24 802A9514 82430431 */  lb        $v1, 0x431($s2)
/* 42DF28 802A9518 2463FFFE */  addiu     $v1, $v1, -2
/* 42DF2C 802A951C 04620001 */  bltzl     $v1, .L802A9524
/* 42DF30 802A9520 24630040 */   addiu    $v1, $v1, 0x40
.L802A9524:
/* 42DF34 802A9524 0000282D */  daddu     $a1, $zero, $zero
/* 42DF38 802A9528 24040001 */  addiu     $a0, $zero, 1
.L802A952C:
/* 42DF3C 802A952C 28620040 */  slti      $v0, $v1, 0x40
/* 42DF40 802A9530 50400001 */  beql      $v0, $zero, .L802A9538
/* 42DF44 802A9534 2463FFC0 */   addiu    $v1, $v1, -0x40
.L802A9538:
/* 42DF48 802A9538 00031080 */  sll       $v0, $v1, 2
/* 42DF4C 802A953C 24630001 */  addiu     $v1, $v1, 1
/* 42DF50 802A9540 02421021 */  addu      $v0, $s2, $v0
/* 42DF54 802A9544 8C420330 */  lw        $v0, 0x330($v0)
/* 42DF58 802A9548 2484FFFF */  addiu     $a0, $a0, -1
/* 42DF5C 802A954C 0481FFF7 */  bgez      $a0, .L802A952C
/* 42DF60 802A9550 00A22825 */   or       $a1, $a1, $v0
/* 42DF64 802A9554 3403C000 */  ori       $v1, $zero, 0xc000
/* 42DF68 802A9558 00A31024 */  and       $v0, $a1, $v1
/* 42DF6C 802A955C 14430037 */  bne       $v0, $v1, .L802A963C
/* 42DF70 802A9560 00000000 */   nop      
/* 42DF74 802A9564 86220064 */  lh        $v0, 0x64($s1)
/* 42DF78 802A9568 1040001D */  beqz      $v0, .L802A95E0
/* 42DF7C 802A956C 3C0651EB */   lui      $a2, 0x51eb
/* 42DF80 802A9570 34C6851F */  ori       $a2, $a2, 0x851f
/* 42DF84 802A9574 00021840 */  sll       $v1, $v0, 1
/* 42DF88 802A9578 00621821 */  addu      $v1, $v1, $v0
/* 42DF8C 802A957C 00031180 */  sll       $v0, $v1, 6
/* 42DF90 802A9580 00621821 */  addu      $v1, $v1, $v0
/* 42DF94 802A9584 00031880 */  sll       $v1, $v1, 2
/* 42DF98 802A9588 00660018 */  mult      $v1, $a2
/* 42DF9C 802A958C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42DFA0 802A9590 00001010 */  mfhi      $v0
/* 42DFA4 802A9594 00022143 */  sra       $a0, $v0, 5
/* 42DFA8 802A9598 86220050 */  lh        $v0, 0x50($s1)
/* 42DFAC 802A959C 8E450434 */  lw        $a1, 0x434($s2)
/* 42DFB0 802A95A0 00021080 */  sll       $v0, $v0, 2
/* 42DFB4 802A95A4 00451021 */  addu      $v0, $v0, $a1
/* 42DFB8 802A95A8 8C420000 */  lw        $v0, ($v0)
/* 42DFBC 802A95AC 00832023 */  subu      $a0, $a0, $v1
/* 42DFC0 802A95B0 00820018 */  mult      $a0, $v0
/* 42DFC4 802A95B4 00002012 */  mflo      $a0
/* 42DFC8 802A95B8 00000000 */  nop       
/* 42DFCC 802A95BC 00000000 */  nop       
/* 42DFD0 802A95C0 00860018 */  mult      $a0, $a2
/* 42DFD4 802A95C4 000427C3 */  sra       $a0, $a0, 0x1f
/* 42DFD8 802A95C8 00001010 */  mfhi      $v0
/* 42DFDC 802A95CC 00021943 */  sra       $v1, $v0, 5
/* 42DFE0 802A95D0 96220044 */  lhu       $v0, 0x44($s1)
/* 42DFE4 802A95D4 00642823 */  subu      $a1, $v1, $a0
/* 42DFE8 802A95D8 080AA580 */  j         .L802A9600
/* 42DFEC 802A95DC 00451021 */   addu     $v0, $v0, $a1
.L802A95E0:
/* 42DFF0 802A95E0 96220044 */  lhu       $v0, 0x44($s1)
/* 42DFF4 802A95E4 24420064 */  addiu     $v0, $v0, 0x64
/* 42DFF8 802A95E8 A6220044 */  sh        $v0, 0x44($s1)
/* 42DFFC 802A95EC 00021400 */  sll       $v0, $v0, 0x10
/* 42E000 802A95F0 00021403 */  sra       $v0, $v0, 0x10
/* 42E004 802A95F4 284201F4 */  slti      $v0, $v0, 0x1f4
/* 42E008 802A95F8 14400002 */  bnez      $v0, .L802A9604
/* 42E00C 802A95FC 240201F4 */   addiu    $v0, $zero, 0x1f4
.L802A9600:
/* 42E010 802A9600 A6220044 */  sh        $v0, 0x44($s1)
.L802A9604:
/* 42E014 802A9604 82430431 */  lb        $v1, 0x431($s2)
/* 42E018 802A9608 2463FFFE */  addiu     $v1, $v1, -2
/* 42E01C 802A960C 04620001 */  bltzl     $v1, .L802A9614
/* 42E020 802A9610 24630040 */   addiu    $v1, $v1, 0x40
.L802A9614:
/* 42E024 802A9614 24040001 */  addiu     $a0, $zero, 1
.L802A9618:
/* 42E028 802A9618 28620040 */  slti      $v0, $v1, 0x40
/* 42E02C 802A961C 50400001 */  beql      $v0, $zero, .L802A9624
/* 42E030 802A9620 2463FFC0 */   addiu    $v1, $v1, -0x40
.L802A9624:
/* 42E034 802A9624 00031080 */  sll       $v0, $v1, 2
/* 42E038 802A9628 02421021 */  addu      $v0, $s2, $v0
/* 42E03C 802A962C AC400330 */  sw        $zero, 0x330($v0)
/* 42E040 802A9630 2484FFFF */  addiu     $a0, $a0, -1
/* 42E044 802A9634 0481FFF8 */  bgez      $a0, .L802A9618
/* 42E048 802A9638 24630001 */   addiu    $v1, $v1, 1
.L802A963C:
/* 42E04C 802A963C 86220044 */  lh        $v0, 0x44($s1)
/* 42E050 802A9640 28422711 */  slti      $v0, $v0, 0x2711
/* 42E054 802A9644 14400010 */  bnez      $v0, .L802A9688
/* 42E058 802A9648 3C1051EB */   lui      $s0, 0x51eb
/* 42E05C 802A964C 8E300014 */  lw        $s0, 0x14($s1)
/* 42E060 802A9650 86250056 */  lh        $a1, 0x56($s1)
/* 42E064 802A9654 86260058 */  lh        $a2, 0x58($s1)
/* 42E068 802A9658 24022710 */  addiu     $v0, $zero, 0x2710
/* 42E06C 802A965C A6220044 */  sh        $v0, 0x44($s1)
/* 42E070 802A9660 24020001 */  addiu     $v0, $zero, 1
/* 42E074 802A9664 A6220068 */  sh        $v0, 0x68($s1)
/* 42E078 802A9668 0200202D */  daddu     $a0, $s0, $zero
/* 42E07C 802A966C 24A50032 */  addiu     $a1, $a1, 0x32
/* 42E080 802A9670 0C051261 */  jal       set_icon_render_pos
/* 42E084 802A9674 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42E088 802A9678 0200202D */  daddu     $a0, $s0, $zero
/* 42E08C 802A967C 0C05128B */  jal       clear_icon_flags
/* 42E090 802A9680 24050002 */   addiu    $a1, $zero, 2
/* 42E094 802A9684 3C1051EB */  lui       $s0, 0x51eb
.L802A9688:
/* 42E098 802A9688 3610851F */  ori       $s0, $s0, 0x851f
/* 42E09C 802A968C 96230044 */  lhu       $v1, 0x44($s1)
/* 42E0A0 802A9690 3C048000 */  lui       $a0, 0x8000
/* 42E0A4 802A9694 00031C00 */  sll       $v1, $v1, 0x10
/* 42E0A8 802A9698 00031403 */  sra       $v0, $v1, 0x10
/* 42E0AC 802A969C 00500018 */  mult      $v0, $s0
/* 42E0B0 802A96A0 34840041 */  ori       $a0, $a0, 0x41
/* 42E0B4 802A96A4 0000282D */  daddu     $a1, $zero, $zero
/* 42E0B8 802A96A8 00A0302D */  daddu     $a2, $a1, $zero
/* 42E0BC 802A96AC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42E0C0 802A96B0 00004810 */  mfhi      $t1
/* 42E0C4 802A96B4 00094143 */  sra       $t0, $t1, 5
/* 42E0C8 802A96B8 01034023 */  subu      $t0, $t0, $v1
/* 42E0CC 802A96BC 00081600 */  sll       $v0, $t0, 0x18
/* 42E0D0 802A96C0 00021603 */  sra       $v0, $v0, 0x18
/* 42E0D4 802A96C4 00023840 */  sll       $a3, $v0, 1
/* 42E0D8 802A96C8 00E23821 */  addu      $a3, $a3, $v0
/* 42E0DC 802A96CC 00073880 */  sll       $a3, $a3, 2
/* 42E0E0 802A96D0 0C0526F9 */  jal       func_80149BE4
/* 42E0E4 802A96D4 A2480084 */   sb       $t0, 0x84($s2)
/* 42E0E8 802A96D8 86220054 */  lh        $v0, 0x54($s1)
/* 42E0EC 802A96DC 96230054 */  lhu       $v1, 0x54($s1)
/* 42E0F0 802A96E0 1440003B */  bnez      $v0, .L802A97D0
/* 42E0F4 802A96E4 2462FFFF */   addiu    $v0, $v1, -1
/* 42E0F8 802A96E8 86220064 */  lh        $v0, 0x64($s1)
/* 42E0FC 802A96EC 86250044 */  lh        $a1, 0x44($s1)
/* 42E100 802A96F0 50400001 */  beql      $v0, $zero, .L802A96F8
/* 42E104 802A96F4 0000282D */   daddu    $a1, $zero, $zero
.L802A96F8:
/* 42E108 802A96F8 14A00003 */  bnez      $a1, .L802A9708
/* 42E10C 802A96FC 00B00018 */   mult     $a1, $s0
/* 42E110 802A9700 080AA5C6 */  j         .L802A9718
/* 42E114 802A9704 2402FFFF */   addiu    $v0, $zero, -1
.L802A9708:
/* 42E118 802A9708 00051FC3 */  sra       $v1, $a1, 0x1f
/* 42E11C 802A970C 00004810 */  mfhi      $t1
/* 42E120 802A9710 00091143 */  sra       $v0, $t1, 5
/* 42E124 802A9714 00431023 */  subu      $v0, $v0, $v1
.L802A9718:
/* 42E128 802A9718 A2420081 */  sb        $v0, 0x81($s2)
/* 42E12C 802A971C 82220080 */  lb        $v0, 0x80($s1)
/* 42E130 802A9720 2442FFFF */  addiu     $v0, $v0, -1
/* 42E134 802A9724 00021040 */  sll       $v0, $v0, 1
/* 42E138 802A9728 02221021 */  addu      $v0, $s1, $v0
/* 42E13C 802A972C 94420074 */  lhu       $v0, 0x74($v0)
/* 42E140 802A9730 00021400 */  sll       $v0, $v0, 0x10
/* 42E144 802A9734 00021C03 */  sra       $v1, $v0, 0x10
/* 42E148 802A9738 000217C2 */  srl       $v0, $v0, 0x1f
/* 42E14C 802A973C 00621021 */  addu      $v0, $v1, $v0
/* 42E150 802A9740 82430084 */  lb        $v1, 0x84($s2)
/* 42E154 802A9744 00021043 */  sra       $v0, $v0, 1
/* 42E158 802A9748 0043102A */  slt       $v0, $v0, $v1
/* 42E15C 802A974C 14400002 */  bnez      $v0, .L802A9758
/* 42E160 802A9750 24020001 */   addiu    $v0, $zero, 1
/* 42E164 802A9754 2402FFFC */  addiu     $v0, $zero, -4
.L802A9758:
/* 42E168 802A9758 A2420086 */  sb        $v0, 0x86($s2)
/* 42E16C 802A975C 82430081 */  lb        $v1, 0x81($s2)
/* 42E170 802A9760 24020064 */  addiu     $v0, $zero, 0x64
/* 42E174 802A9764 14620004 */  bne       $v1, $v0, .L802A9778
/* 42E178 802A9768 3C048000 */   lui      $a0, 0x8000
/* 42E17C 802A976C 0C09A458 */  jal       func_80269160
/* 42E180 802A9770 00000000 */   nop      
/* 42E184 802A9774 3C048000 */  lui       $a0, 0x8000
.L802A9778:
/* 42E188 802A9778 0C05271B */  jal       stop_sound
/* 42E18C 802A977C 34840041 */   ori      $a0, $a0, 0x41
/* 42E190 802A9780 0C093EB1 */  jal       set_popup_duration
/* 42E194 802A9784 0000202D */   daddu    $a0, $zero, $zero
/* 42E198 802A9788 24020005 */  addiu     $v0, $zero, 5
/* 42E19C 802A978C A6220054 */  sh        $v0, 0x54($s1)
/* 42E1A0 802A9790 2402000C */  addiu     $v0, $zero, 0xc
/* 42E1A4 802A9794 080AA5F8 */  j         .L802A97E0
/* 42E1A8 802A9798 A622004C */   sh       $v0, 0x4c($s1)
/* 42E1AC 802A979C 86220064 */  lh        $v0, 0x64($s1)
/* 42E1B0 802A97A0 14400007 */  bnez      $v0, .L802A97C0
/* 42E1B4 802A97A4 00000000 */   nop      
/* 42E1B8 802A97A8 96220044 */  lhu       $v0, 0x44($s1)
/* 42E1BC 802A97AC 2442FF9C */  addiu     $v0, $v0, -0x64
/* 42E1C0 802A97B0 A6220044 */  sh        $v0, 0x44($s1)
/* 42E1C4 802A97B4 00021400 */  sll       $v0, $v0, 0x10
/* 42E1C8 802A97B8 04420001 */  bltzl     $v0, .L802A97C0
/* 42E1CC 802A97BC A6200044 */   sh       $zero, 0x44($s1)
.L802A97C0:
/* 42E1D0 802A97C0 86220054 */  lh        $v0, 0x54($s1)
/* 42E1D4 802A97C4 96230054 */  lhu       $v1, 0x54($s1)
/* 42E1D8 802A97C8 10400003 */  beqz      $v0, .L802A97D8
/* 42E1DC 802A97CC 2462FFFF */   addiu    $v0, $v1, -1
.L802A97D0:
/* 42E1E0 802A97D0 080AA5F8 */  j         .L802A97E0
/* 42E1E4 802A97D4 A6220054 */   sh       $v0, 0x54($s1)
.L802A97D8:
/* 42E1E8 802A97D8 0C09A327 */  jal       func_80268C9C
/* 42E1EC 802A97DC 00000000 */   nop      
.L802A97E0:
/* 42E1F0 802A97E0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 42E1F4 802A97E4 8FB20018 */  lw        $s2, 0x18($sp)
/* 42E1F8 802A97E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 42E1FC 802A97EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 42E200 802A97F0 03E00008 */  jr        $ra
/* 42E204 802A97F4 27BD0020 */   addiu    $sp, $sp, 0x20
