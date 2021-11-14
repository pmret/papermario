.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A92A0_42F980
/* 42F980 802A92A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42F984 802A92A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 42F988 802A92A8 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 42F98C 802A92AC 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 42F990 802A92B0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 42F994 802A92B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 42F998 802A92B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 42F99C 802A92BC 8623004C */  lh        $v1, 0x4c($s1)
/* 42F9A0 802A92C0 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 42F9A4 802A92C4 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 42F9A8 802A92C8 2C62000D */  sltiu     $v0, $v1, 0xd
/* 42F9AC 802A92CC 10400131 */  beqz      $v0, L802A9794_42FE74
/* 42F9B0 802A92D0 00031080 */   sll      $v0, $v1, 2
/* 42F9B4 802A92D4 3C01802B */  lui       $at, %hi(jtbl_802A9900_42FFE0)
/* 42F9B8 802A92D8 00220821 */  addu      $at, $at, $v0
/* 42F9BC 802A92DC 8C229900 */  lw        $v0, %lo(jtbl_802A9900_42FFE0)($at)
/* 42F9C0 802A92E0 00400008 */  jr        $v0
/* 42F9C4 802A92E4 00000000 */   nop
dlabel L802A92E8_42F9C8
/* 42F9C8 802A92E8 0C093EB1 */  jal       btl_set_popup_duration
/* 42F9CC 802A92EC 24040063 */   addiu    $a0, $zero, 0x63
/* 42F9D0 802A92F0 82220061 */  lb        $v0, 0x61($s1)
/* 42F9D4 802A92F4 8E300004 */  lw        $s0, 4($s1)
/* 42F9D8 802A92F8 10400003 */  beqz      $v0, .L802A9308
/* 42F9DC 802A92FC 0200202D */   daddu    $a0, $s0, $zero
/* 42F9E0 802A9300 0C05128B */  jal       clear_hud_element_flags
/* 42F9E4 802A9304 24050002 */   addiu    $a1, $zero, 2
.L802A9308:
/* 42F9E8 802A9308 0200202D */  daddu     $a0, $s0, $zero
/* 42F9EC 802A930C 0C0513AC */  jal       set_hud_element_alpha
/* 42F9F0 802A9310 240500FF */   addiu    $a1, $zero, 0xff
/* 42F9F4 802A9314 82220061 */  lb        $v0, 0x61($s1)
/* 42F9F8 802A9318 8E30000C */  lw        $s0, 0xc($s1)
/* 42F9FC 802A931C 10400004 */  beqz      $v0, .L802A9330
/* 42FA00 802A9320 0200202D */   daddu    $a0, $s0, $zero
/* 42FA04 802A9324 0C05128B */  jal       clear_hud_element_flags
/* 42FA08 802A9328 24050002 */   addiu    $a1, $zero, 2
/* 42FA0C 802A932C 0200202D */  daddu     $a0, $s0, $zero
.L802A9330:
/* 42FA10 802A9330 0C0513AC */  jal       set_hud_element_alpha
/* 42FA14 802A9334 240500FF */   addiu    $a1, $zero, 0xff
/* 42FA18 802A9338 8E300008 */  lw        $s0, 8($s1)
/* 42FA1C 802A933C 240500FF */  addiu     $a1, $zero, 0xff
/* 42FA20 802A9340 0C0513AC */  jal       set_hud_element_alpha
/* 42FA24 802A9344 0200202D */   daddu    $a0, $s0, $zero
/* 42FA28 802A9348 82220061 */  lb        $v0, 0x61($s1)
/* 42FA2C 802A934C 10400003 */  beqz      $v0, .L802A935C
/* 42FA30 802A9350 0200202D */   daddu    $a0, $s0, $zero
/* 42FA34 802A9354 0C05128B */  jal       clear_hud_element_flags
/* 42FA38 802A9358 24050002 */   addiu    $a1, $zero, 2
.L802A935C:
/* 42FA3C 802A935C 24020001 */  addiu     $v0, $zero, 1
/* 42FA40 802A9360 080AA5E5 */  j         L802A9794_42FE74
/* 42FA44 802A9364 A622004C */   sh       $v0, 0x4c($s1)
dlabel L802A9368_42FA48
/* 42FA48 802A9368 0C093EB1 */  jal       btl_set_popup_duration
/* 42FA4C 802A936C 24040063 */   addiu    $a0, $zero, 0x63
/* 42FA50 802A9370 8622006C */  lh        $v0, 0x6c($s1)
/* 42FA54 802A9374 9623006C */  lhu       $v1, 0x6c($s1)
/* 42FA58 802A9378 10400003 */  beqz      $v0, .L802A9388
/* 42FA5C 802A937C 2462FFFF */   addiu    $v0, $v1, -1
/* 42FA60 802A9380 080AA5E5 */  j         L802A9794_42FE74
/* 42FA64 802A9384 A622006C */   sh       $v0, 0x6c($s1)
.L802A9388:
/* 42FA68 802A9388 96220056 */  lhu       $v0, 0x56($s1)
/* 42FA6C 802A938C 24420014 */  addiu     $v0, $v0, 0x14
/* 42FA70 802A9390 A6220056 */  sh        $v0, 0x56($s1)
/* 42FA74 802A9394 00021400 */  sll       $v0, $v0, 0x10
/* 42FA78 802A9398 00021403 */  sra       $v0, $v0, 0x10
/* 42FA7C 802A939C 28420033 */  slti      $v0, $v0, 0x33
/* 42FA80 802A93A0 14400002 */  bnez      $v0, .L802A93AC
/* 42FA84 802A93A4 24020032 */   addiu    $v0, $zero, 0x32
/* 42FA88 802A93A8 A6220056 */  sh        $v0, 0x56($s1)
.L802A93AC:
/* 42FA8C 802A93AC 8E240004 */  lw        $a0, 4($s1)
/* 42FA90 802A93B0 86250056 */  lh        $a1, 0x56($s1)
/* 42FA94 802A93B4 86260058 */  lh        $a2, 0x58($s1)
/* 42FA98 802A93B8 0C051261 */  jal       set_hud_element_render_pos
/* 42FA9C 802A93BC 24A5FFEF */   addiu    $a1, $a1, -0x11
/* 42FAA0 802A93C0 8E24000C */  lw        $a0, 0xc($s1)
/* 42FAA4 802A93C4 86250056 */  lh        $a1, 0x56($s1)
/* 42FAA8 802A93C8 86260058 */  lh        $a2, 0x58($s1)
/* 42FAAC 802A93CC 0C051261 */  jal       set_hud_element_render_pos
/* 42FAB0 802A93D0 24A50017 */   addiu    $a1, $a1, 0x17
/* 42FAB4 802A93D4 8E240008 */  lw        $a0, 8($s1)
/* 42FAB8 802A93D8 86260058 */  lh        $a2, 0x58($s1)
/* 42FABC 802A93DC 86250056 */  lh        $a1, 0x56($s1)
/* 42FAC0 802A93E0 0C051261 */  jal       set_hud_element_render_pos
/* 42FAC4 802A93E4 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42FAC8 802A93E8 080AA5E5 */  j         L802A9794_42FE74
/* 42FACC 802A93EC 00000000 */   nop
dlabel L802A93F0_42FAD0
/* 42FAD0 802A93F0 0C093EB1 */  jal       btl_set_popup_duration
/* 42FAD4 802A93F4 24040063 */   addiu    $a0, $zero, 0x63
/* 42FAD8 802A93F8 8622004E */  lh        $v0, 0x4e($s1)
/* 42FADC 802A93FC 9623004E */  lhu       $v1, 0x4e($s1)
/* 42FAE0 802A9400 10400003 */  beqz      $v0, .L802A9410
/* 42FAE4 802A9404 2462FFFF */   addiu    $v0, $v1, -1
/* 42FAE8 802A9408 080AA5E5 */  j         L802A9794_42FE74
/* 42FAEC 802A940C A622004E */   sh       $v0, 0x4e($s1)
.L802A9410:
/* 42FAF0 802A9410 8E240004 */  lw        $a0, 4($s1)
/* 42FAF4 802A9414 3C058011 */  lui       $a1, %hi(D_80108B80)
/* 42FAF8 802A9418 24A58B80 */  addiu     $a1, $a1, %lo(D_80108B80)
/* 42FAFC 802A941C 0C0511FF */  jal       set_hud_element_anim
/* 42FB00 802A9420 00000000 */   nop
/* 42FB04 802A9424 8E24000C */  lw        $a0, 0xc($s1)
/* 42FB08 802A9428 3C058029 */  lui       $a1, %hi(D_80292374)
/* 42FB0C 802A942C 24A52374 */  addiu     $a1, $a1, %lo(D_80292374)
/* 42FB10 802A9430 0C0511FF */  jal       set_hud_element_anim
/* 42FB14 802A9434 00000000 */   nop
/* 42FB18 802A9438 96230052 */  lhu       $v1, 0x52($s1)
/* 42FB1C 802A943C 2402000B */  addiu     $v0, $zero, 0xb
/* 42FB20 802A9440 A6200044 */  sh        $zero, 0x44($s1)
/* 42FB24 802A9444 A220005C */  sb        $zero, 0x5c($s1)
/* 42FB28 802A9448 A622004C */  sh        $v0, 0x4c($s1)
/* 42FB2C 802A944C A6230054 */  sh        $v1, 0x54($s1)
dlabel L802A9450_42FB30
/* 42FB30 802A9450 0C093EB1 */  jal       btl_set_popup_duration
/* 42FB34 802A9454 24040063 */   addiu    $a0, $zero, 0x63
/* 42FB38 802A9458 86220068 */  lh        $v0, 0x68($s1)
/* 42FB3C 802A945C 14400027 */  bnez      $v0, .L802A94FC
/* 42FB40 802A9460 00000000 */   nop
/* 42FB44 802A9464 86220064 */  lh        $v0, 0x64($s1)
/* 42FB48 802A9468 1040001E */  beqz      $v0, .L802A94E4
/* 42FB4C 802A946C 00000000 */   nop
/* 42FB50 802A9470 82220080 */  lb        $v0, 0x80($s1)
/* 42FB54 802A9474 00021040 */  sll       $v0, $v0, 1
/* 42FB58 802A9478 02221021 */  addu      $v0, $s1, $v0
/* 42FB5C 802A947C 84430074 */  lh        $v1, 0x74($v0)
/* 42FB60 802A9480 86220044 */  lh        $v0, 0x44($s1)
/* 42FB64 802A9484 14600002 */  bnez      $v1, .L802A9490
/* 42FB68 802A9488 0043001A */   div      $zero, $v0, $v1
/* 42FB6C 802A948C 0007000D */  break     7
.L802A9490:
/* 42FB70 802A9490 2401FFFF */   addiu    $at, $zero, -1
/* 42FB74 802A9494 14610004 */  bne       $v1, $at, .L802A94A8
/* 42FB78 802A9498 3C018000 */   lui      $at, 0x8000
/* 42FB7C 802A949C 14410002 */  bne       $v0, $at, .L802A94A8
/* 42FB80 802A94A0 00000000 */   nop
/* 42FB84 802A94A4 0006000D */  break     6
.L802A94A8:
/* 42FB88 802A94A8 00001012 */   mflo     $v0
/* 42FB8C 802A94AC 3C036666 */  lui       $v1, 0x6666
/* 42FB90 802A94B0 34636667 */  ori       $v1, $v1, 0x6667
/* 42FB94 802A94B4 00430018 */  mult      $v0, $v1
/* 42FB98 802A94B8 000217C3 */  sra       $v0, $v0, 0x1f
/* 42FB9C 802A94BC 00001810 */  mfhi      $v1
/* 42FBA0 802A94C0 000318C3 */  sra       $v1, $v1, 3
/* 42FBA4 802A94C4 00621823 */  subu      $v1, $v1, $v0
/* 42FBA8 802A94C8 00031880 */  sll       $v1, $v1, 2
/* 42FBAC 802A94CC 96220044 */  lhu       $v0, 0x44($s1)
/* 42FBB0 802A94D0 3C01802B */  lui       $at, %hi(D_802A98E2_42FFC2)
/* 42FBB4 802A94D4 00230821 */  addu      $at, $at, $v1
/* 42FBB8 802A94D8 942398E2 */  lhu       $v1, %lo(D_802A98E2_42FFC2)($at)
/* 42FBBC 802A94DC 080AA53B */  j         .L802A94EC
/* 42FBC0 802A94E0 00431023 */   subu     $v0, $v0, $v1
.L802A94E4:
/* 42FBC4 802A94E4 96220044 */  lhu       $v0, 0x44($s1)
/* 42FBC8 802A94E8 2442FFF6 */  addiu     $v0, $v0, -0xa
.L802A94EC:
/* 42FBCC 802A94EC A6220044 */  sh        $v0, 0x44($s1)
/* 42FBD0 802A94F0 00021400 */  sll       $v0, $v0, 0x10
/* 42FBD4 802A94F4 04420001 */  bltzl     $v0, .L802A94FC
/* 42FBD8 802A94F8 A6200044 */   sh       $zero, 0x44($s1)
.L802A94FC:
/* 42FBDC 802A94FC 82430431 */  lb        $v1, 0x431($s2)
/* 42FBE0 802A9500 2463FFFE */  addiu     $v1, $v1, -2
/* 42FBE4 802A9504 04620001 */  bltzl     $v1, .L802A950C
/* 42FBE8 802A9508 24630040 */   addiu    $v1, $v1, 0x40
.L802A950C:
/* 42FBEC 802A950C 0000282D */  daddu     $a1, $zero, $zero
/* 42FBF0 802A9510 24040001 */  addiu     $a0, $zero, 1
.L802A9514:
/* 42FBF4 802A9514 28620040 */  slti      $v0, $v1, 0x40
/* 42FBF8 802A9518 50400001 */  beql      $v0, $zero, .L802A9520
/* 42FBFC 802A951C 2463FFC0 */   addiu    $v1, $v1, -0x40
.L802A9520:
/* 42FC00 802A9520 00031080 */  sll       $v0, $v1, 2
/* 42FC04 802A9524 24630001 */  addiu     $v1, $v1, 1
/* 42FC08 802A9528 02421021 */  addu      $v0, $s2, $v0
/* 42FC0C 802A952C 8C420330 */  lw        $v0, 0x330($v0)
/* 42FC10 802A9530 2484FFFF */  addiu     $a0, $a0, -1
/* 42FC14 802A9534 0481FFF7 */  bgez      $a0, .L802A9514
/* 42FC18 802A9538 00A22825 */   or       $a1, $a1, $v0
/* 42FC1C 802A953C 3403C000 */  ori       $v1, $zero, 0xc000
/* 42FC20 802A9540 00A31024 */  and       $v0, $a1, $v1
/* 42FC24 802A9544 14430037 */  bne       $v0, $v1, .L802A9624
/* 42FC28 802A9548 00000000 */   nop
/* 42FC2C 802A954C 86220064 */  lh        $v0, 0x64($s1)
/* 42FC30 802A9550 1040001D */  beqz      $v0, .L802A95C8
/* 42FC34 802A9554 3C0651EB */   lui      $a2, 0x51eb
/* 42FC38 802A9558 34C6851F */  ori       $a2, $a2, 0x851f
/* 42FC3C 802A955C 00021880 */  sll       $v1, $v0, 2
/* 42FC40 802A9560 00621821 */  addu      $v1, $v1, $v0
/* 42FC44 802A9564 00031180 */  sll       $v0, $v1, 6
/* 42FC48 802A9568 00621821 */  addu      $v1, $v1, $v0
/* 42FC4C 802A956C 00031840 */  sll       $v1, $v1, 1
/* 42FC50 802A9570 00660018 */  mult      $v1, $a2
/* 42FC54 802A9574 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42FC58 802A9578 00001010 */  mfhi      $v0
/* 42FC5C 802A957C 00022143 */  sra       $a0, $v0, 5
/* 42FC60 802A9580 86220050 */  lh        $v0, 0x50($s1)
/* 42FC64 802A9584 8E450434 */  lw        $a1, 0x434($s2)
/* 42FC68 802A9588 00021080 */  sll       $v0, $v0, 2
/* 42FC6C 802A958C 00451021 */  addu      $v0, $v0, $a1
/* 42FC70 802A9590 8C420000 */  lw        $v0, ($v0)
/* 42FC74 802A9594 00832023 */  subu      $a0, $a0, $v1
/* 42FC78 802A9598 00820018 */  mult      $a0, $v0
/* 42FC7C 802A959C 00002012 */  mflo      $a0
/* 42FC80 802A95A0 00000000 */  nop
/* 42FC84 802A95A4 00000000 */  nop
/* 42FC88 802A95A8 00860018 */  mult      $a0, $a2
/* 42FC8C 802A95AC 000427C3 */  sra       $a0, $a0, 0x1f
/* 42FC90 802A95B0 00001010 */  mfhi      $v0
/* 42FC94 802A95B4 00021943 */  sra       $v1, $v0, 5
/* 42FC98 802A95B8 96220044 */  lhu       $v0, 0x44($s1)
/* 42FC9C 802A95BC 00642823 */  subu      $a1, $v1, $a0
/* 42FCA0 802A95C0 080AA57A */  j         .L802A95E8
/* 42FCA4 802A95C4 00451021 */   addu     $v0, $v0, $a1
.L802A95C8:
/* 42FCA8 802A95C8 96220044 */  lhu       $v0, 0x44($s1)
/* 42FCAC 802A95CC 24420064 */  addiu     $v0, $v0, 0x64
/* 42FCB0 802A95D0 A6220044 */  sh        $v0, 0x44($s1)
/* 42FCB4 802A95D4 00021400 */  sll       $v0, $v0, 0x10
/* 42FCB8 802A95D8 00021403 */  sra       $v0, $v0, 0x10
/* 42FCBC 802A95DC 284201F4 */  slti      $v0, $v0, 0x1f4
/* 42FCC0 802A95E0 14400002 */  bnez      $v0, .L802A95EC
/* 42FCC4 802A95E4 240201F4 */   addiu    $v0, $zero, 0x1f4
.L802A95E8:
/* 42FCC8 802A95E8 A6220044 */  sh        $v0, 0x44($s1)
.L802A95EC:
/* 42FCCC 802A95EC 82430431 */  lb        $v1, 0x431($s2)
/* 42FCD0 802A95F0 2463FFFE */  addiu     $v1, $v1, -2
/* 42FCD4 802A95F4 04620001 */  bltzl     $v1, .L802A95FC
/* 42FCD8 802A95F8 24630040 */   addiu    $v1, $v1, 0x40
.L802A95FC:
/* 42FCDC 802A95FC 24040001 */  addiu     $a0, $zero, 1
.L802A9600:
/* 42FCE0 802A9600 28620040 */  slti      $v0, $v1, 0x40
/* 42FCE4 802A9604 50400001 */  beql      $v0, $zero, .L802A960C
/* 42FCE8 802A9608 2463FFC0 */   addiu    $v1, $v1, -0x40
.L802A960C:
/* 42FCEC 802A960C 00031080 */  sll       $v0, $v1, 2
/* 42FCF0 802A9610 02421021 */  addu      $v0, $s2, $v0
/* 42FCF4 802A9614 AC400330 */  sw        $zero, 0x330($v0)
/* 42FCF8 802A9618 2484FFFF */  addiu     $a0, $a0, -1
/* 42FCFC 802A961C 0481FFF8 */  bgez      $a0, .L802A9600
/* 42FD00 802A9620 24630001 */   addiu    $v1, $v1, 1
.L802A9624:
/* 42FD04 802A9624 86220044 */  lh        $v0, 0x44($s1)
/* 42FD08 802A9628 28422711 */  slti      $v0, $v0, 0x2711
/* 42FD0C 802A962C 14400010 */  bnez      $v0, .L802A9670
/* 42FD10 802A9630 3C0451EB */   lui      $a0, 0x51eb
/* 42FD14 802A9634 8E300014 */  lw        $s0, 0x14($s1)
/* 42FD18 802A9638 86250056 */  lh        $a1, 0x56($s1)
/* 42FD1C 802A963C 86260058 */  lh        $a2, 0x58($s1)
/* 42FD20 802A9640 24022710 */  addiu     $v0, $zero, 0x2710
/* 42FD24 802A9644 A6220044 */  sh        $v0, 0x44($s1)
/* 42FD28 802A9648 24020001 */  addiu     $v0, $zero, 1
/* 42FD2C 802A964C A6220068 */  sh        $v0, 0x68($s1)
/* 42FD30 802A9650 0200202D */  daddu     $a0, $s0, $zero
/* 42FD34 802A9654 24A50032 */  addiu     $a1, $a1, 0x32
/* 42FD38 802A9658 0C051261 */  jal       set_hud_element_render_pos
/* 42FD3C 802A965C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42FD40 802A9660 0200202D */  daddu     $a0, $s0, $zero
/* 42FD44 802A9664 0C05128B */  jal       clear_hud_element_flags
/* 42FD48 802A9668 24050002 */   addiu    $a1, $zero, 2
/* 42FD4C 802A966C 3C0451EB */  lui       $a0, 0x51eb
.L802A9670:
/* 42FD50 802A9670 96230044 */  lhu       $v1, 0x44($s1)
/* 42FD54 802A9674 3484851F */  ori       $a0, $a0, 0x851f
/* 42FD58 802A9678 00031C00 */  sll       $v1, $v1, 0x10
/* 42FD5C 802A967C 00031403 */  sra       $v0, $v1, 0x10
/* 42FD60 802A9680 00440018 */  mult      $v0, $a0
/* 42FD64 802A9684 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42FD68 802A9688 00003810 */  mfhi      $a3
/* 42FD6C 802A968C 00071143 */  sra       $v0, $a3, 5
/* 42FD70 802A9690 00431023 */  subu      $v0, $v0, $v1
/* 42FD74 802A9694 A2420084 */  sb        $v0, 0x84($s2)
/* 42FD78 802A9698 86220054 */  lh        $v0, 0x54($s1)
/* 42FD7C 802A969C 96230054 */  lhu       $v1, 0x54($s1)
/* 42FD80 802A96A0 14400038 */  bnez      $v0, .L802A9784
/* 42FD84 802A96A4 2462FFFF */   addiu    $v0, $v1, -1
/* 42FD88 802A96A8 86220064 */  lh        $v0, 0x64($s1)
/* 42FD8C 802A96AC 86250044 */  lh        $a1, 0x44($s1)
/* 42FD90 802A96B0 50400001 */  beql      $v0, $zero, .L802A96B8
/* 42FD94 802A96B4 0000282D */   daddu    $a1, $zero, $zero
.L802A96B8:
/* 42FD98 802A96B8 14A00003 */  bnez      $a1, .L802A96C8
/* 42FD9C 802A96BC 00A40018 */   mult     $a1, $a0
/* 42FDA0 802A96C0 080AA5B6 */  j         .L802A96D8
/* 42FDA4 802A96C4 2402FFFF */   addiu    $v0, $zero, -1
.L802A96C8:
/* 42FDA8 802A96C8 00051FC3 */  sra       $v1, $a1, 0x1f
/* 42FDAC 802A96CC 00003810 */  mfhi      $a3
/* 42FDB0 802A96D0 00071143 */  sra       $v0, $a3, 5
/* 42FDB4 802A96D4 00431023 */  subu      $v0, $v0, $v1
.L802A96D8:
/* 42FDB8 802A96D8 A2420081 */  sb        $v0, 0x81($s2)
/* 42FDBC 802A96DC 82220080 */  lb        $v0, 0x80($s1)
/* 42FDC0 802A96E0 2442FFFF */  addiu     $v0, $v0, -1
/* 42FDC4 802A96E4 00021040 */  sll       $v0, $v0, 1
/* 42FDC8 802A96E8 02221021 */  addu      $v0, $s1, $v0
/* 42FDCC 802A96EC 94420074 */  lhu       $v0, 0x74($v0)
/* 42FDD0 802A96F0 00021400 */  sll       $v0, $v0, 0x10
/* 42FDD4 802A96F4 00021C03 */  sra       $v1, $v0, 0x10
/* 42FDD8 802A96F8 000217C2 */  srl       $v0, $v0, 0x1f
/* 42FDDC 802A96FC 00621021 */  addu      $v0, $v1, $v0
/* 42FDE0 802A9700 82430084 */  lb        $v1, 0x84($s2)
/* 42FDE4 802A9704 00021043 */  sra       $v0, $v0, 1
/* 42FDE8 802A9708 0043102A */  slt       $v0, $v0, $v1
/* 42FDEC 802A970C 14400002 */  bnez      $v0, .L802A9718
/* 42FDF0 802A9710 24020001 */   addiu    $v0, $zero, 1
/* 42FDF4 802A9714 2402FFFC */  addiu     $v0, $zero, -4
.L802A9718:
/* 42FDF8 802A9718 A2420086 */  sb        $v0, 0x86($s2)
/* 42FDFC 802A971C 82430081 */  lb        $v1, 0x81($s2)
/* 42FE00 802A9720 24020064 */  addiu     $v0, $zero, 0x64
/* 42FE04 802A9724 14620003 */  bne       $v1, $v0, .L802A9734
/* 42FE08 802A9728 00000000 */   nop
/* 42FE0C 802A972C 0C09A458 */  jal       func_80269160
/* 42FE10 802A9730 00000000 */   nop
.L802A9734:
/* 42FE14 802A9734 0C093EB1 */  jal       btl_set_popup_duration
/* 42FE18 802A9738 0000202D */   daddu    $a0, $zero, $zero
/* 42FE1C 802A973C 24020005 */  addiu     $v0, $zero, 5
/* 42FE20 802A9740 A6220054 */  sh        $v0, 0x54($s1)
/* 42FE24 802A9744 2402000C */  addiu     $v0, $zero, 0xc
/* 42FE28 802A9748 080AA5E5 */  j         L802A9794_42FE74
/* 42FE2C 802A974C A622004C */   sh       $v0, 0x4c($s1)
dlabel L802A9750_42FE30
/* 42FE30 802A9750 86220064 */  lh        $v0, 0x64($s1)
/* 42FE34 802A9754 14400007 */  bnez      $v0, .L802A9774
/* 42FE38 802A9758 00000000 */   nop
/* 42FE3C 802A975C 96220044 */  lhu       $v0, 0x44($s1)
/* 42FE40 802A9760 2442FF9C */  addiu     $v0, $v0, -0x64
/* 42FE44 802A9764 A6220044 */  sh        $v0, 0x44($s1)
/* 42FE48 802A9768 00021400 */  sll       $v0, $v0, 0x10
/* 42FE4C 802A976C 04420001 */  bltzl     $v0, .L802A9774
/* 42FE50 802A9770 A6200044 */   sh       $zero, 0x44($s1)
.L802A9774:
/* 42FE54 802A9774 86220054 */  lh        $v0, 0x54($s1)
/* 42FE58 802A9778 96230054 */  lhu       $v1, 0x54($s1)
/* 42FE5C 802A977C 10400003 */  beqz      $v0, .L802A978C
/* 42FE60 802A9780 2462FFFF */   addiu    $v0, $v1, -1
.L802A9784:
/* 42FE64 802A9784 080AA5E5 */  j         L802A9794_42FE74
/* 42FE68 802A9788 A6220054 */   sh       $v0, 0x54($s1)
.L802A978C:
/* 42FE6C 802A978C 0C09A327 */  jal       func_80268C9C
/* 42FE70 802A9790 00000000 */   nop
dlabel L802A9794_42FE74
/* 42FE74 802A9794 8FBF001C */  lw        $ra, 0x1c($sp)
/* 42FE78 802A9798 8FB20018 */  lw        $s2, 0x18($sp)
/* 42FE7C 802A979C 8FB10014 */  lw        $s1, 0x14($sp)
/* 42FE80 802A97A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 42FE84 802A97A4 03E00008 */  jr        $ra
/* 42FE88 802A97A8 27BD0020 */   addiu    $sp, $sp, 0x20
