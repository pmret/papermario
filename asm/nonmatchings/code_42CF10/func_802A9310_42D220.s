.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9310_42D220
/* 42D220 802A9310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42D224 802A9314 AFB10014 */  sw        $s1, 0x14($sp)
/* 42D228 802A9318 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42D22C 802A931C 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42D230 802A9320 AFBF001C */  sw        $ra, 0x1c($sp)
/* 42D234 802A9324 AFB20018 */  sw        $s2, 0x18($sp)
/* 42D238 802A9328 AFB00010 */  sw        $s0, 0x10($sp)
/* 42D23C 802A932C 8623004C */  lh        $v1, 0x4c($s1)
/* 42D240 802A9330 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 42D244 802A9334 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 42D248 802A9338 2C62000D */  sltiu     $v0, $v1, 0xd
/* 42D24C 802A933C 1040013F */  beqz      $v0, .L802A983C
/* 42D250 802A9340 00031080 */   sll      $v0, $v1, 2
/* 42D254 802A9344 3C01802B */  lui       $at, %hi(jtbl_802A9AC0_42D9D0)
/* 42D258 802A9348 00220821 */  addu      $at, $at, $v0
/* 42D25C 802A934C 8C229AC0 */  lw        $v0, %lo(jtbl_802A9AC0_42D9D0)($at)
/* 42D260 802A9350 00400008 */  jr        $v0
/* 42D264 802A9354 00000000 */   nop
glabel L802A9358_42D268
/* 42D268 802A9358 0C093EB1 */  jal       set_popup_duration
/* 42D26C 802A935C 24040063 */   addiu    $a0, $zero, 0x63
/* 42D270 802A9360 82220061 */  lb        $v0, 0x61($s1)
/* 42D274 802A9364 8E300004 */  lw        $s0, 4($s1)
/* 42D278 802A9368 10400004 */  beqz      $v0, .L802A937C
/* 42D27C 802A936C 0200202D */   daddu    $a0, $s0, $zero
/* 42D280 802A9370 0C05128B */  jal       clear_icon_flags
/* 42D284 802A9374 24050002 */   addiu    $a1, $zero, 2
/* 42D288 802A9378 0200202D */  daddu     $a0, $s0, $zero
.L802A937C:
/* 42D28C 802A937C 0C0513AC */  jal       icon_set_opacity
/* 42D290 802A9380 240500FF */   addiu    $a1, $zero, 0xff
/* 42D294 802A9384 8E300008 */  lw        $s0, 8($s1)
/* 42D298 802A9388 240500FF */  addiu     $a1, $zero, 0xff
/* 42D29C 802A938C 0C0513AC */  jal       icon_set_opacity
/* 42D2A0 802A9390 0200202D */   daddu    $a0, $s0, $zero
/* 42D2A4 802A9394 82220061 */  lb        $v0, 0x61($s1)
/* 42D2A8 802A9398 10400003 */  beqz      $v0, .L802A93A8
/* 42D2AC 802A939C 0200202D */   daddu    $a0, $s0, $zero
/* 42D2B0 802A93A0 0C05128B */  jal       clear_icon_flags
/* 42D2B4 802A93A4 24050002 */   addiu    $a1, $zero, 2
.L802A93A8:
/* 42D2B8 802A93A8 8E300014 */  lw        $s0, 0x14($s1)
/* 42D2BC 802A93AC 240500FF */  addiu     $a1, $zero, 0xff
/* 42D2C0 802A93B0 0C0513AC */  jal       icon_set_opacity
/* 42D2C4 802A93B4 0200202D */   daddu    $a0, $s0, $zero
/* 42D2C8 802A93B8 82220061 */  lb        $v0, 0x61($s1)
/* 42D2CC 802A93BC 10400003 */  beqz      $v0, .L802A93CC
/* 42D2D0 802A93C0 0200202D */   daddu    $a0, $s0, $zero
/* 42D2D4 802A93C4 0C05128B */  jal       clear_icon_flags
/* 42D2D8 802A93C8 24050002 */   addiu    $a1, $zero, 2
.L802A93CC:
/* 42D2DC 802A93CC 24020001 */  addiu     $v0, $zero, 1
/* 42D2E0 802A93D0 080AA60E */  j         .L802A9838
/* 42D2E4 802A93D4 A622004C */   sh       $v0, 0x4c($s1)
glabel L802A93D8_42D2E8
/* 42D2E8 802A93D8 0C093EB1 */  jal       set_popup_duration
/* 42D2EC 802A93DC 24040063 */   addiu    $a0, $zero, 0x63
/* 42D2F0 802A93E0 8622006C */  lh        $v0, 0x6c($s1)
/* 42D2F4 802A93E4 9623006C */  lhu       $v1, 0x6c($s1)
/* 42D2F8 802A93E8 10400003 */  beqz      $v0, .L802A93F8
/* 42D2FC 802A93EC 2462FFFF */   addiu    $v0, $v1, -1
/* 42D300 802A93F0 080AA60E */  j         .L802A9838
/* 42D304 802A93F4 A622006C */   sh       $v0, 0x6c($s1)
.L802A93F8:
/* 42D308 802A93F8 96220056 */  lhu       $v0, 0x56($s1)
/* 42D30C 802A93FC 24420014 */  addiu     $v0, $v0, 0x14
/* 42D310 802A9400 A6220056 */  sh        $v0, 0x56($s1)
/* 42D314 802A9404 00021400 */  sll       $v0, $v0, 0x10
/* 42D318 802A9408 00021403 */  sra       $v0, $v0, 0x10
/* 42D31C 802A940C 28420033 */  slti      $v0, $v0, 0x33
/* 42D320 802A9410 14400002 */  bnez      $v0, .L802A941C
/* 42D324 802A9414 24020032 */   addiu    $v0, $zero, 0x32
/* 42D328 802A9418 A6220056 */  sh        $v0, 0x56($s1)
.L802A941C:
/* 42D32C 802A941C 8E240004 */  lw        $a0, 4($s1)
/* 42D330 802A9420 86250056 */  lh        $a1, 0x56($s1)
/* 42D334 802A9424 0C051261 */  jal       set_icon_render_pos
/* 42D338 802A9428 86260058 */   lh       $a2, 0x58($s1)
/* 42D33C 802A942C 8E240008 */  lw        $a0, 8($s1)
/* 42D340 802A9430 86260058 */  lh        $a2, 0x58($s1)
/* 42D344 802A9434 86250056 */  lh        $a1, 0x56($s1)
/* 42D348 802A9438 0C051261 */  jal       set_icon_render_pos
/* 42D34C 802A943C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42D350 802A9440 3C0451EB */  lui       $a0, 0x51eb
/* 42D354 802A9444 3484851F */  ori       $a0, $a0, 0x851f
/* 42D358 802A9448 24020064 */  addiu     $v0, $zero, 0x64
/* 42D35C 802A944C 86230046 */  lh        $v1, 0x46($s1)
/* 42D360 802A9450 86260058 */  lh        $a2, 0x58($s1)
/* 42D364 802A9454 00432823 */  subu      $a1, $v0, $v1
/* 42D368 802A9458 00051100 */  sll       $v0, $a1, 4
/* 42D36C 802A945C 00451023 */  subu      $v0, $v0, $a1
/* 42D370 802A9460 00021080 */  sll       $v0, $v0, 2
/* 42D374 802A9464 00440018 */  mult      $v0, $a0
/* 42D378 802A9468 24C60011 */  addiu     $a2, $a2, 0x11
/* 42D37C 802A946C 000217C3 */  sra       $v0, $v0, 0x1f
/* 42D380 802A9470 2405001D */  addiu     $a1, $zero, 0x1d
/* 42D384 802A9474 8E240014 */  lw        $a0, 0x14($s1)
/* 42D388 802A9478 00004810 */  mfhi      $t1
/* 42D38C 802A947C 00091943 */  sra       $v1, $t1, 5
/* 42D390 802A9480 00621823 */  subu      $v1, $v1, $v0
/* 42D394 802A9484 86220056 */  lh        $v0, 0x56($s1)
/* 42D398 802A9488 00A32823 */  subu      $a1, $a1, $v1
/* 42D39C 802A948C 0C051261 */  jal       set_icon_render_pos
/* 42D3A0 802A9490 00452823 */   subu     $a1, $v0, $a1
/* 42D3A4 802A9494 080AA60E */  j         .L802A9838
/* 42D3A8 802A9498 00000000 */   nop
glabel L802A949C_42D3AC
/* 42D3AC 802A949C 0C093EB1 */  jal       set_popup_duration
/* 42D3B0 802A94A0 24040063 */   addiu    $a0, $zero, 0x63
/* 42D3B4 802A94A4 8622004E */  lh        $v0, 0x4e($s1)
/* 42D3B8 802A94A8 9623004E */  lhu       $v1, 0x4e($s1)
/* 42D3BC 802A94AC 10400003 */  beqz      $v0, .L802A94BC
/* 42D3C0 802A94B0 2462FFFF */   addiu    $v0, $v1, -1
/* 42D3C4 802A94B4 080AA60E */  j         .L802A9838
/* 42D3C8 802A94B8 A622004E */   sh       $v0, 0x4e($s1)
.L802A94BC:
/* 42D3CC 802A94BC 8E240004 */  lw        $a0, 4($s1)
/* 42D3D0 802A94C0 3C058011 */  lui       $a1, %hi(D_80108B80)
/* 42D3D4 802A94C4 24A58B80 */  addiu     $a1, $a1, %lo(D_80108B80)
/* 42D3D8 802A94C8 0C0511FF */  jal       set_menu_icon_script
/* 42D3DC 802A94CC 00000000 */   nop
/* 42D3E0 802A94D0 3C048000 */  lui       $a0, 0x8000
/* 42D3E4 802A94D4 34840041 */  ori       $a0, $a0, 0x41
/* 42D3E8 802A94D8 0000282D */  daddu     $a1, $zero, $zero
/* 42D3EC 802A94DC 00A0302D */  daddu     $a2, $a1, $zero
/* 42D3F0 802A94E0 00A0382D */  daddu     $a3, $a1, $zero
/* 42D3F4 802A94E4 96220052 */  lhu       $v0, 0x52($s1)
/* 42D3F8 802A94E8 24030001 */  addiu     $v1, $zero, 1
/* 42D3FC 802A94EC A6200044 */  sh        $zero, 0x44($s1)
/* 42D400 802A94F0 A220005C */  sb        $zero, 0x5c($s1)
/* 42D404 802A94F4 3C01802B */  lui       $at, %hi(D_802A9B00)
/* 42D408 802A94F8 AC239B00 */  sw        $v1, %lo(D_802A9B00)($at)
/* 42D40C 802A94FC 0C0526AE */  jal       _play_sound
/* 42D410 802A9500 A6220054 */   sh       $v0, 0x54($s1)
/* 42D414 802A9504 2402000B */  addiu     $v0, $zero, 0xb
/* 42D418 802A9508 A622004C */  sh        $v0, 0x4c($s1)
glabel L802A950C_42D41C
/* 42D41C 802A950C 0C093EB1 */  jal       set_popup_duration
/* 42D420 802A9510 24040063 */   addiu    $a0, $zero, 0x63
/* 42D424 802A9514 86220068 */  lh        $v0, 0x68($s1)
/* 42D428 802A9518 14400027 */  bnez      $v0, .L802A95B8
/* 42D42C 802A951C 00000000 */   nop
/* 42D430 802A9520 86220064 */  lh        $v0, 0x64($s1)
/* 42D434 802A9524 1040001E */  beqz      $v0, .L802A95A0
/* 42D438 802A9528 00000000 */   nop
/* 42D43C 802A952C 82220080 */  lb        $v0, 0x80($s1)
/* 42D440 802A9530 00021040 */  sll       $v0, $v0, 1
/* 42D444 802A9534 02221021 */  addu      $v0, $s1, $v0
/* 42D448 802A9538 84430074 */  lh        $v1, 0x74($v0)
/* 42D44C 802A953C 86220044 */  lh        $v0, 0x44($s1)
/* 42D450 802A9540 14600002 */  bnez      $v1, .L802A954C
/* 42D454 802A9544 0043001A */   div      $zero, $v0, $v1
/* 42D458 802A9548 0007000D */  break     7
.L802A954C:
/* 42D45C 802A954C 2401FFFF */   addiu    $at, $zero, -1
/* 42D460 802A9550 14610004 */  bne       $v1, $at, .L802A9564
/* 42D464 802A9554 3C018000 */   lui      $at, 0x8000
/* 42D468 802A9558 14410002 */  bne       $v0, $at, .L802A9564
/* 42D46C 802A955C 00000000 */   nop
/* 42D470 802A9560 0006000D */  break     6
.L802A9564:
/* 42D474 802A9564 00001012 */   mflo     $v0
/* 42D478 802A9568 3C036666 */  lui       $v1, 0x6666
/* 42D47C 802A956C 34636667 */  ori       $v1, $v1, 0x6667
/* 42D480 802A9570 00430018 */  mult      $v0, $v1
/* 42D484 802A9574 000217C3 */  sra       $v0, $v0, 0x1f
/* 42D488 802A9578 00001810 */  mfhi      $v1
/* 42D48C 802A957C 000318C3 */  sra       $v1, $v1, 3
/* 42D490 802A9580 00621823 */  subu      $v1, $v1, $v0
/* 42D494 802A9584 00031880 */  sll       $v1, $v1, 2
/* 42D498 802A9588 96220044 */  lhu       $v0, 0x44($s1)
/* 42D49C 802A958C 3C01802B */  lui       $at, %hi(D_802A9AA2)
/* 42D4A0 802A9590 00230821 */  addu      $at, $at, $v1
/* 42D4A4 802A9594 94239AA2 */  lhu       $v1, %lo(D_802A9AA2)($at)
/* 42D4A8 802A9598 080AA56A */  j         .L802A95A8
/* 42D4AC 802A959C 00431023 */   subu     $v0, $v0, $v1
.L802A95A0:
/* 42D4B0 802A95A0 96220044 */  lhu       $v0, 0x44($s1)
/* 42D4B4 802A95A4 2442FFF6 */  addiu     $v0, $v0, -0xa
.L802A95A8:
/* 42D4B8 802A95A8 A6220044 */  sh        $v0, 0x44($s1)
/* 42D4BC 802A95AC 00021400 */  sll       $v0, $v0, 0x10
/* 42D4C0 802A95B0 04420001 */  bltzl     $v0, .L802A95B8
/* 42D4C4 802A95B4 A6200044 */   sh       $zero, 0x44($s1)
.L802A95B8:
/* 42D4C8 802A95B8 8E420214 */  lw        $v0, 0x214($s2)
/* 42D4CC 802A95BC 30428000 */  andi      $v0, $v0, 0x8000
/* 42D4D0 802A95C0 1040002B */  beqz      $v0, .L802A9670
/* 42D4D4 802A95C4 00000000 */   nop
/* 42D4D8 802A95C8 86250064 */  lh        $a1, 0x64($s1)
/* 42D4DC 802A95CC 10A0001F */  beqz      $a1, .L802A964C
/* 42D4E0 802A95D0 3C0451EB */   lui      $a0, 0x51eb
/* 42D4E4 802A95D4 86220050 */  lh        $v0, 0x50($s1)
/* 42D4E8 802A95D8 8E430434 */  lw        $v1, 0x434($s2)
/* 42D4EC 802A95DC 00021080 */  sll       $v0, $v0, 2
/* 42D4F0 802A95E0 00431021 */  addu      $v0, $v0, $v1
/* 42D4F4 802A95E4 8C430000 */  lw        $v1, ($v0)
/* 42D4F8 802A95E8 3484851F */  ori       $a0, $a0, 0x851f
/* 42D4FC 802A95EC 00031040 */  sll       $v0, $v1, 1
/* 42D500 802A95F0 00431021 */  addu      $v0, $v0, $v1
/* 42D504 802A95F4 000210C0 */  sll       $v0, $v0, 3
/* 42D508 802A95F8 00431021 */  addu      $v0, $v0, $v1
/* 42D50C 802A95FC 00021900 */  sll       $v1, $v0, 4
/* 42D510 802A9600 00431021 */  addu      $v0, $v0, $v1
/* 42D514 802A9604 00021040 */  sll       $v0, $v0, 1
/* 42D518 802A9608 00440018 */  mult      $v0, $a0
/* 42D51C 802A960C 000217C3 */  sra       $v0, $v0, 0x1f
/* 42D520 802A9610 00001810 */  mfhi      $v1
/* 42D524 802A9614 00031943 */  sra       $v1, $v1, 5
/* 42D528 802A9618 00621823 */  subu      $v1, $v1, $v0
/* 42D52C 802A961C 00650018 */  mult      $v1, $a1
/* 42D530 802A9620 00001812 */  mflo      $v1
/* 42D534 802A9624 00000000 */  nop
/* 42D538 802A9628 00000000 */  nop
/* 42D53C 802A962C 00640018 */  mult      $v1, $a0
/* 42D540 802A9630 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42D544 802A9634 00001010 */  mfhi      $v0
/* 42D548 802A9638 00022143 */  sra       $a0, $v0, 5
/* 42D54C 802A963C 96220044 */  lhu       $v0, 0x44($s1)
/* 42D550 802A9640 00832823 */  subu      $a1, $a0, $v1
/* 42D554 802A9644 080AA59B */  j         .L802A966C
/* 42D558 802A9648 00451021 */   addu     $v0, $v0, $a1
.L802A964C:
/* 42D55C 802A964C 96220044 */  lhu       $v0, 0x44($s1)
/* 42D560 802A9650 24420064 */  addiu     $v0, $v0, 0x64
/* 42D564 802A9654 A6220044 */  sh        $v0, 0x44($s1)
/* 42D568 802A9658 00021400 */  sll       $v0, $v0, 0x10
/* 42D56C 802A965C 00021403 */  sra       $v0, $v0, 0x10
/* 42D570 802A9660 284201F4 */  slti      $v0, $v0, 0x1f4
/* 42D574 802A9664 14400002 */  bnez      $v0, .L802A9670
/* 42D578 802A9668 240201F4 */   addiu    $v0, $zero, 0x1f4
.L802A966C:
/* 42D57C 802A966C A6220044 */  sh        $v0, 0x44($s1)
.L802A9670:
/* 42D580 802A9670 86220044 */  lh        $v0, 0x44($s1)
/* 42D584 802A9674 28422711 */  slti      $v0, $v0, 0x2711
/* 42D588 802A9678 14400010 */  bnez      $v0, .L802A96BC
/* 42D58C 802A967C 3C1051EB */   lui      $s0, 0x51eb
/* 42D590 802A9680 8E300010 */  lw        $s0, 0x10($s1)
/* 42D594 802A9684 86250056 */  lh        $a1, 0x56($s1)
/* 42D598 802A9688 86260058 */  lh        $a2, 0x58($s1)
/* 42D59C 802A968C 24022710 */  addiu     $v0, $zero, 0x2710
/* 42D5A0 802A9690 A6220044 */  sh        $v0, 0x44($s1)
/* 42D5A4 802A9694 24020001 */  addiu     $v0, $zero, 1
/* 42D5A8 802A9698 A6220068 */  sh        $v0, 0x68($s1)
/* 42D5AC 802A969C 0200202D */  daddu     $a0, $s0, $zero
/* 42D5B0 802A96A0 24A50032 */  addiu     $a1, $a1, 0x32
/* 42D5B4 802A96A4 0C051261 */  jal       set_icon_render_pos
/* 42D5B8 802A96A8 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42D5BC 802A96AC 0200202D */  daddu     $a0, $s0, $zero
/* 42D5C0 802A96B0 0C05128B */  jal       clear_icon_flags
/* 42D5C4 802A96B4 24050002 */   addiu    $a1, $zero, 2
/* 42D5C8 802A96B8 3C1051EB */  lui       $s0, 0x51eb
.L802A96BC:
/* 42D5CC 802A96BC 3610851F */  ori       $s0, $s0, 0x851f
/* 42D5D0 802A96C0 96230044 */  lhu       $v1, 0x44($s1)
/* 42D5D4 802A96C4 3C048000 */  lui       $a0, 0x8000
/* 42D5D8 802A96C8 00031C00 */  sll       $v1, $v1, 0x10
/* 42D5DC 802A96CC 00031403 */  sra       $v0, $v1, 0x10
/* 42D5E0 802A96D0 00500018 */  mult      $v0, $s0
/* 42D5E4 802A96D4 34840041 */  ori       $a0, $a0, 0x41
/* 42D5E8 802A96D8 0000282D */  daddu     $a1, $zero, $zero
/* 42D5EC 802A96DC 00A0302D */  daddu     $a2, $a1, $zero
/* 42D5F0 802A96E0 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42D5F4 802A96E4 00004810 */  mfhi      $t1
/* 42D5F8 802A96E8 00094143 */  sra       $t0, $t1, 5
/* 42D5FC 802A96EC 01034023 */  subu      $t0, $t0, $v1
/* 42D600 802A96F0 00081600 */  sll       $v0, $t0, 0x18
/* 42D604 802A96F4 00021603 */  sra       $v0, $v0, 0x18
/* 42D608 802A96F8 00023840 */  sll       $a3, $v0, 1
/* 42D60C 802A96FC 00E23821 */  addu      $a3, $a3, $v0
/* 42D610 802A9700 00073880 */  sll       $a3, $a3, 2
/* 42D614 802A9704 0C0526F9 */  jal       func_80149BE4
/* 42D618 802A9708 A2480084 */   sb       $t0, 0x84($s2)
/* 42D61C 802A970C 86220054 */  lh        $v0, 0x54($s1)
/* 42D620 802A9710 96230054 */  lhu       $v1, 0x54($s1)
/* 42D624 802A9714 14400044 */  bnez      $v0, .L802A9828
/* 42D628 802A9718 2462FFFF */   addiu    $v0, $v1, -1
/* 42D62C 802A971C 86220064 */  lh        $v0, 0x64($s1)
/* 42D630 802A9720 86250044 */  lh        $a1, 0x44($s1)
/* 42D634 802A9724 50400001 */  beql      $v0, $zero, .L802A972C
/* 42D638 802A9728 0000282D */   daddu    $a1, $zero, $zero
.L802A972C:
/* 42D63C 802A972C 00B00018 */  mult      $a1, $s0
/* 42D640 802A9730 000517C3 */  sra       $v0, $a1, 0x1f
/* 42D644 802A9734 00004810 */  mfhi      $t1
/* 42D648 802A9738 00091943 */  sra       $v1, $t1, 5
/* 42D64C 802A973C 00621023 */  subu      $v0, $v1, $v0
/* 42D650 802A9740 14A00004 */  bnez      $a1, .L802A9754
/* 42D654 802A9744 A2420084 */   sb       $v0, 0x84($s2)
/* 42D658 802A9748 2402FFFF */  addiu     $v0, $zero, -1
/* 42D65C 802A974C 080AA5DD */  j         .L802A9774
/* 42D660 802A9750 A2420081 */   sb       $v0, 0x81($s2)
.L802A9754:
/* 42D664 802A9754 00021600 */  sll       $v0, $v0, 0x18
/* 42D668 802A9758 86230046 */  lh        $v1, 0x46($s1)
/* 42D66C 802A975C 00021603 */  sra       $v0, $v0, 0x18
/* 42D670 802A9760 0043102A */  slt       $v0, $v0, $v1
/* 42D674 802A9764 54400003 */  bnel      $v0, $zero, .L802A9774
/* 42D678 802A9768 A2400081 */   sb       $zero, 0x81($s2)
/* 42D67C 802A976C 24020001 */  addiu     $v0, $zero, 1
/* 42D680 802A9770 A2420081 */  sb        $v0, 0x81($s2)
.L802A9774:
/* 42D684 802A9774 82220080 */  lb        $v0, 0x80($s1)
/* 42D688 802A9778 2442FFFF */  addiu     $v0, $v0, -1
/* 42D68C 802A977C 00021040 */  sll       $v0, $v0, 1
/* 42D690 802A9780 02221021 */  addu      $v0, $s1, $v0
/* 42D694 802A9784 94420074 */  lhu       $v0, 0x74($v0)
/* 42D698 802A9788 00021400 */  sll       $v0, $v0, 0x10
/* 42D69C 802A978C 00021C03 */  sra       $v1, $v0, 0x10
/* 42D6A0 802A9790 000217C2 */  srl       $v0, $v0, 0x1f
/* 42D6A4 802A9794 00621021 */  addu      $v0, $v1, $v0
/* 42D6A8 802A9798 82430084 */  lb        $v1, 0x84($s2)
/* 42D6AC 802A979C 00021043 */  sra       $v0, $v0, 1
/* 42D6B0 802A97A0 0043102A */  slt       $v0, $v0, $v1
/* 42D6B4 802A97A4 14400002 */  bnez      $v0, .L802A97B0
/* 42D6B8 802A97A8 24020001 */   addiu    $v0, $zero, 1
/* 42D6BC 802A97AC 2402FFFC */  addiu     $v0, $zero, -4
.L802A97B0:
/* 42D6C0 802A97B0 A2420086 */  sb        $v0, 0x86($s2)
/* 42D6C4 802A97B4 82430081 */  lb        $v1, 0x81($s2)
/* 42D6C8 802A97B8 24020001 */  addiu     $v0, $zero, 1
/* 42D6CC 802A97BC 14620004 */  bne       $v1, $v0, .L802A97D0
/* 42D6D0 802A97C0 3C048000 */   lui      $a0, 0x8000
/* 42D6D4 802A97C4 0C09A458 */  jal       func_80269160
/* 42D6D8 802A97C8 00000000 */   nop
/* 42D6DC 802A97CC 3C048000 */  lui       $a0, 0x8000
.L802A97D0:
/* 42D6E0 802A97D0 0C05271B */  jal       stop_sound
/* 42D6E4 802A97D4 34840041 */   ori      $a0, $a0, 0x41
/* 42D6E8 802A97D8 0C093EB1 */  jal       set_popup_duration
/* 42D6EC 802A97DC 0000202D */   daddu    $a0, $zero, $zero
/* 42D6F0 802A97E0 24020005 */  addiu     $v0, $zero, 5
/* 42D6F4 802A97E4 A6220054 */  sh        $v0, 0x54($s1)
/* 42D6F8 802A97E8 2402000C */  addiu     $v0, $zero, 0xc
/* 42D6FC 802A97EC 080AA60E */  j         .L802A9838
/* 42D700 802A97F0 A622004C */   sh       $v0, 0x4c($s1)
glabel L802A97F4_42D704
/* 42D704 802A97F4 86220064 */  lh        $v0, 0x64($s1)
/* 42D708 802A97F8 14400007 */  bnez      $v0, .L802A9818
/* 42D70C 802A97FC 00000000 */   nop
/* 42D710 802A9800 96220044 */  lhu       $v0, 0x44($s1)
/* 42D714 802A9804 2442FF9C */  addiu     $v0, $v0, -0x64
/* 42D718 802A9808 A6220044 */  sh        $v0, 0x44($s1)
/* 42D71C 802A980C 00021400 */  sll       $v0, $v0, 0x10
/* 42D720 802A9810 04420001 */  bltzl     $v0, .L802A9818
/* 42D724 802A9814 A6200044 */   sh       $zero, 0x44($s1)
.L802A9818:
/* 42D728 802A9818 86220054 */  lh        $v0, 0x54($s1)
/* 42D72C 802A981C 96230054 */  lhu       $v1, 0x54($s1)
/* 42D730 802A9820 10400003 */  beqz      $v0, .L802A9830
/* 42D734 802A9824 2462FFFF */   addiu    $v0, $v1, -1
.L802A9828:
/* 42D738 802A9828 080AA60E */  j         .L802A9838
/* 42D73C 802A982C A6220054 */   sh       $v0, 0x54($s1)
.L802A9830:
/* 42D740 802A9830 0C09A327 */  jal       func_80268C9C
/* 42D744 802A9834 00000000 */   nop
.L802A9838:
glabel L802A9838_42D748
/* 42D748 802A9838 8623004C */  lh        $v1, 0x4c($s1)
.L802A983C:
/* 42D74C 802A983C 24040001 */  addiu     $a0, $zero, 1
/* 42D750 802A9840 10640007 */  beq       $v1, $a0, .L802A9860
/* 42D754 802A9844 00000000 */   nop
/* 42D758 802A9848 1860001B */  blez      $v1, .L802A98B8
/* 42D75C 802A984C 2862000C */   slti     $v0, $v1, 0xc
/* 42D760 802A9850 10400019 */  beqz      $v0, .L802A98B8
/* 42D764 802A9854 2862000A */   slti     $v0, $v1, 0xa
/* 42D768 802A9858 14400017 */  bnez      $v0, .L802A98B8
/* 42D76C 802A985C 00000000 */   nop
.L802A9860:
/* 42D770 802A9860 86220066 */  lh        $v0, 0x66($s1)
/* 42D774 802A9864 1440000C */  bnez      $v0, .L802A9898
/* 42D778 802A9868 00000000 */   nop
/* 42D77C 802A986C 96220046 */  lhu       $v0, 0x46($s1)
/* 42D780 802A9870 24420007 */  addiu     $v0, $v0, 7
/* 42D784 802A9874 A6220046 */  sh        $v0, 0x46($s1)
/* 42D788 802A9878 00021400 */  sll       $v0, $v0, 0x10
/* 42D78C 802A987C 00021403 */  sra       $v0, $v0, 0x10
/* 42D790 802A9880 28420064 */  slti      $v0, $v0, 0x64
/* 42D794 802A9884 1440000C */  bnez      $v0, .L802A98B8
/* 42D798 802A9888 24020064 */   addiu    $v0, $zero, 0x64
/* 42D79C 802A988C A6220046 */  sh        $v0, 0x46($s1)
/* 42D7A0 802A9890 080AA62E */  j         .L802A98B8
/* 42D7A4 802A9894 A6240066 */   sh       $a0, 0x66($s1)
.L802A9898:
/* 42D7A8 802A9898 96220046 */  lhu       $v0, 0x46($s1)
/* 42D7AC 802A989C 2442FFF9 */  addiu     $v0, $v0, -7
/* 42D7B0 802A98A0 A6220046 */  sh        $v0, 0x46($s1)
/* 42D7B4 802A98A4 00021400 */  sll       $v0, $v0, 0x10
/* 42D7B8 802A98A8 1C400003 */  bgtz      $v0, .L802A98B8
/* 42D7BC 802A98AC 00000000 */   nop
/* 42D7C0 802A98B0 A6200046 */  sh        $zero, 0x46($s1)
/* 42D7C4 802A98B4 A6200066 */  sh        $zero, 0x66($s1)
.L802A98B8:
/* 42D7C8 802A98B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 42D7CC 802A98BC 8FB20018 */  lw        $s2, 0x18($sp)
/* 42D7D0 802A98C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 42D7D4 802A98C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 42D7D8 802A98C8 03E00008 */  jr        $ra
/* 42D7DC 802A98CC 27BD0020 */   addiu    $sp, $sp, 0x20
