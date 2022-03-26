.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A928C_4263FC
/* 4263FC 802A928C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 426400 802A9290 AFB10014 */  sw        $s1, 0x14($sp)
/* 426404 802A9294 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 426408 802A9298 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 42640C 802A929C AFBF001C */  sw        $ra, 0x1c($sp)
/* 426410 802A92A0 AFB20018 */  sw        $s2, 0x18($sp)
/* 426414 802A92A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 426418 802A92A8 8623004C */  lh        $v1, 0x4c($s1)
/* 42641C 802A92AC 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 426420 802A92B0 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 426424 802A92B4 2C62000D */  sltiu     $v0, $v1, 0xd
/* 426428 802A92B8 10400102 */  beqz      $v0, L802A96C4_426834
/* 42642C 802A92BC 00031080 */   sll      $v0, $v1, 2
/* 426430 802A92C0 3C01802B */  lui       $at, %hi(jtbl_802A9820_426990)
/* 426434 802A92C4 00220821 */  addu      $at, $at, $v0
/* 426438 802A92C8 8C229820 */  lw        $v0, %lo(jtbl_802A9820_426990)($at)
/* 42643C 802A92CC 00400008 */  jr        $v0
/* 426440 802A92D0 00000000 */   nop
dlabel L802A92D4_426444
/* 426444 802A92D4 0C093EB1 */  jal       btl_set_popup_duration
/* 426448 802A92D8 24040063 */   addiu    $a0, $zero, 0x63
/* 42644C 802A92DC 8E300004 */  lw        $s0, 4($s1)
/* 426450 802A92E0 240500FF */  addiu     $a1, $zero, 0xff
/* 426454 802A92E4 0C0513AC */  jal       hud_element_set_alpha
/* 426458 802A92E8 0200202D */   daddu    $a0, $s0, $zero
/* 42645C 802A92EC 82220061 */  lb        $v0, 0x61($s1)
/* 426460 802A92F0 10400003 */  beqz      $v0, .L802A9300
/* 426464 802A92F4 0200202D */   daddu    $a0, $s0, $zero
/* 426468 802A92F8 0C05128B */  jal       hud_element_clear_flags
/* 42646C 802A92FC 24050002 */   addiu    $a1, $zero, 2
.L802A9300:
/* 426470 802A9300 8E300008 */  lw        $s0, 8($s1)
/* 426474 802A9304 240500FF */  addiu     $a1, $zero, 0xff
/* 426478 802A9308 0C0513AC */  jal       hud_element_set_alpha
/* 42647C 802A930C 0200202D */   daddu    $a0, $s0, $zero
/* 426480 802A9310 82220061 */  lb        $v0, 0x61($s1)
/* 426484 802A9314 10400003 */  beqz      $v0, .L802A9324
/* 426488 802A9318 0200202D */   daddu    $a0, $s0, $zero
/* 42648C 802A931C 0C05128B */  jal       hud_element_clear_flags
/* 426490 802A9320 24050002 */   addiu    $a1, $zero, 2
.L802A9324:
/* 426494 802A9324 24020001 */  addiu     $v0, $zero, 1
/* 426498 802A9328 080AA5B1 */  j         L802A96C4_426834
/* 42649C 802A932C A622004C */   sh       $v0, 0x4c($s1)
dlabel L802A9330_4264A0
/* 4264A0 802A9330 0C093EB1 */  jal       btl_set_popup_duration
/* 4264A4 802A9334 24040063 */   addiu    $a0, $zero, 0x63
/* 4264A8 802A9338 96220056 */  lhu       $v0, 0x56($s1)
/* 4264AC 802A933C 24420014 */  addiu     $v0, $v0, 0x14
/* 4264B0 802A9340 A6220056 */  sh        $v0, 0x56($s1)
/* 4264B4 802A9344 00021400 */  sll       $v0, $v0, 0x10
/* 4264B8 802A9348 00021403 */  sra       $v0, $v0, 0x10
/* 4264BC 802A934C 28420033 */  slti      $v0, $v0, 0x33
/* 4264C0 802A9350 14400002 */  bnez      $v0, .L802A935C
/* 4264C4 802A9354 24020032 */   addiu    $v0, $zero, 0x32
/* 4264C8 802A9358 A6220056 */  sh        $v0, 0x56($s1)
.L802A935C:
/* 4264CC 802A935C 8E240004 */  lw        $a0, 4($s1)
/* 4264D0 802A9360 86250056 */  lh        $a1, 0x56($s1)
/* 4264D4 802A9364 0C051261 */  jal       hud_element_set_render_pos
/* 4264D8 802A9368 86260058 */   lh       $a2, 0x58($s1)
/* 4264DC 802A936C 8E240008 */  lw        $a0, 8($s1)
/* 4264E0 802A9370 86260058 */  lh        $a2, 0x58($s1)
/* 4264E4 802A9374 86250056 */  lh        $a1, 0x56($s1)
/* 4264E8 802A9378 0C051261 */  jal       hud_element_set_render_pos
/* 4264EC 802A937C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 4264F0 802A9380 080AA5B1 */  j         L802A96C4_426834
/* 4264F4 802A9384 00000000 */   nop
dlabel L802A9388_4264F8
/* 4264F8 802A9388 0C093EB1 */  jal       btl_set_popup_duration
/* 4264FC 802A938C 24040063 */   addiu    $a0, $zero, 0x63
/* 426500 802A9390 8622004E */  lh        $v0, 0x4e($s1)
/* 426504 802A9394 9623004E */  lhu       $v1, 0x4e($s1)
/* 426508 802A9398 10400003 */  beqz      $v0, .L802A93A8
/* 42650C 802A939C 2462FFFF */   addiu    $v0, $v1, -1
/* 426510 802A93A0 080AA5B1 */  j         L802A96C4_426834
/* 426514 802A93A4 A622004E */   sh       $v0, 0x4e($s1)
.L802A93A8:
/* 426518 802A93A8 8E240004 */  lw        $a0, 4($s1)
/* 42651C 802A93AC 3C058011 */  lui       $a1, %hi(HudScript_MashAButton)
/* 426520 802A93B0 24A58B80 */  addiu     $a1, $a1, %lo(HudScript_MashAButton)
/* 426524 802A93B4 0C0511FF */  jal       hud_element_set_script
/* 426528 802A93B8 00000000 */   nop
/* 42652C 802A93BC 3C048000 */  lui       $a0, 0x8000
/* 426530 802A93C0 34840041 */  ori       $a0, $a0, 0x41
/* 426534 802A93C4 0000282D */  daddu     $a1, $zero, $zero
/* 426538 802A93C8 00A0302D */  daddu     $a2, $a1, $zero
/* 42653C 802A93CC 96220052 */  lhu       $v0, 0x52($s1)
/* 426540 802A93D0 00A0382D */  daddu     $a3, $a1, $zero
/* 426544 802A93D4 A6200044 */  sh        $zero, 0x44($s1)
/* 426548 802A93D8 0C0526AE */  jal       sfx_play_sound_with_params
/* 42654C 802A93DC A6220054 */   sh       $v0, 0x54($s1)
/* 426550 802A93E0 2402000B */  addiu     $v0, $zero, 0xb
/* 426554 802A93E4 A622004C */  sh        $v0, 0x4c($s1)
dlabel L802A93E8_426558
/* 426558 802A93E8 0C093EB1 */  jal       btl_set_popup_duration
/* 42655C 802A93EC 24040063 */   addiu    $a0, $zero, 0x63
/* 426560 802A93F0 86220068 */  lh        $v0, 0x68($s1)
/* 426564 802A93F4 14400027 */  bnez      $v0, .L802A9494
/* 426568 802A93F8 00000000 */   nop
/* 42656C 802A93FC 86220064 */  lh        $v0, 0x64($s1)
/* 426570 802A9400 1040001E */  beqz      $v0, .L802A947C
/* 426574 802A9404 00000000 */   nop
/* 426578 802A9408 82220080 */  lb        $v0, 0x80($s1)
/* 42657C 802A940C 00021040 */  sll       $v0, $v0, 1
/* 426580 802A9410 02221021 */  addu      $v0, $s1, $v0
/* 426584 802A9414 84430074 */  lh        $v1, 0x74($v0)
/* 426588 802A9418 86220044 */  lh        $v0, 0x44($s1)
/* 42658C 802A941C 14600002 */  bnez      $v1, .L802A9428
/* 426590 802A9420 0043001A */   div      $zero, $v0, $v1
/* 426594 802A9424 0007000D */  break     7
.L802A9428:
/* 426598 802A9428 2401FFFF */   addiu    $at, $zero, -1
/* 42659C 802A942C 14610004 */  bne       $v1, $at, .L802A9440
/* 4265A0 802A9430 3C018000 */   lui      $at, 0x8000
/* 4265A4 802A9434 14410002 */  bne       $v0, $at, .L802A9440
/* 4265A8 802A9438 00000000 */   nop
/* 4265AC 802A943C 0006000D */  break     6
.L802A9440:
/* 4265B0 802A9440 00001012 */   mflo     $v0
/* 4265B4 802A9444 3C036666 */  lui       $v1, 0x6666
/* 4265B8 802A9448 34636667 */  ori       $v1, $v1, 0x6667
/* 4265BC 802A944C 00430018 */  mult      $v0, $v1
/* 4265C0 802A9450 000217C3 */  sra       $v0, $v0, 0x1f
/* 4265C4 802A9454 00001810 */  mfhi      $v1
/* 4265C8 802A9458 000318C3 */  sra       $v1, $v1, 3
/* 4265CC 802A945C 00621823 */  subu      $v1, $v1, $v0
/* 4265D0 802A9460 00031880 */  sll       $v1, $v1, 2
/* 4265D4 802A9464 96220044 */  lhu       $v0, 0x44($s1)
/* 4265D8 802A9468 3C01802B */  lui       $at, %hi(D_802A9802_426972)
/* 4265DC 802A946C 00230821 */  addu      $at, $at, $v1
/* 4265E0 802A9470 94239802 */  lhu       $v1, %lo(D_802A9802_426972)($at)
/* 4265E4 802A9474 080AA521 */  j         .L802A9484
/* 4265E8 802A9478 00431023 */   subu     $v0, $v0, $v1
.L802A947C:
/* 4265EC 802A947C 96220044 */  lhu       $v0, 0x44($s1)
/* 4265F0 802A9480 2442FFF6 */  addiu     $v0, $v0, -0xa
.L802A9484:
/* 4265F4 802A9484 A6220044 */  sh        $v0, 0x44($s1)
/* 4265F8 802A9488 00021400 */  sll       $v0, $v0, 0x10
/* 4265FC 802A948C 04420001 */  bltzl     $v0, .L802A9494
/* 426600 802A9490 A6200044 */   sh       $zero, 0x44($s1)
.L802A9494:
/* 426604 802A9494 8E420214 */  lw        $v0, 0x214($s2)
/* 426608 802A9498 30428000 */  andi      $v0, $v0, 0x8000
/* 42660C 802A949C 10400025 */  beqz      $v0, .L802A9534
/* 426610 802A94A0 00000000 */   nop
/* 426614 802A94A4 86240050 */  lh        $a0, 0x50($s1)
/* 426618 802A94A8 8E420434 */  lw        $v0, 0x434($s2)
/* 42661C 802A94AC 86230064 */  lh        $v1, 0x64($s1)
/* 426620 802A94B0 00042080 */  sll       $a0, $a0, 2
/* 426624 802A94B4 00822021 */  addu      $a0, $a0, $v0
/* 426628 802A94B8 00031040 */  sll       $v0, $v1, 1
/* 42662C 802A94BC 00431021 */  addu      $v0, $v0, $v1
/* 426630 802A94C0 000210C0 */  sll       $v0, $v0, 3
/* 426634 802A94C4 00431021 */  addu      $v0, $v0, $v1
/* 426638 802A94C8 00021900 */  sll       $v1, $v0, 4
/* 42663C 802A94CC 00431021 */  addu      $v0, $v0, $v1
/* 426640 802A94D0 8C830000 */  lw        $v1, ($a0)
/* 426644 802A94D4 00021040 */  sll       $v0, $v0, 1
/* 426648 802A94D8 00620018 */  mult      $v1, $v0
/* 42664C 802A94DC 00001812 */  mflo      $v1
/* 426650 802A94E0 3C0268DB */  lui       $v0, 0x68db
/* 426654 802A94E4 34428BAD */  ori       $v0, $v0, 0x8bad
/* 426658 802A94E8 00620018 */  mult      $v1, $v0
/* 42665C 802A94EC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 426660 802A94F0 00001010 */  mfhi      $v0
/* 426664 802A94F4 00021303 */  sra       $v0, $v0, 0xc
/* 426668 802A94F8 00431823 */  subu      $v1, $v0, $v1
/* 42666C 802A94FC 10600004 */  beqz      $v1, .L802A9510
/* 426670 802A9500 00000000 */   nop
/* 426674 802A9504 96220044 */  lhu       $v0, 0x44($s1)
/* 426678 802A9508 080AA54C */  j         .L802A9530
/* 42667C 802A950C 00431021 */   addu     $v0, $v0, $v1
.L802A9510:
/* 426680 802A9510 96220044 */  lhu       $v0, 0x44($s1)
/* 426684 802A9514 24420064 */  addiu     $v0, $v0, 0x64
/* 426688 802A9518 A6220044 */  sh        $v0, 0x44($s1)
/* 42668C 802A951C 00021400 */  sll       $v0, $v0, 0x10
/* 426690 802A9520 00021403 */  sra       $v0, $v0, 0x10
/* 426694 802A9524 284201F4 */  slti      $v0, $v0, 0x1f4
/* 426698 802A9528 14400002 */  bnez      $v0, .L802A9534
/* 42669C 802A952C 240201F4 */   addiu    $v0, $zero, 0x1f4
.L802A9530:
/* 4266A0 802A9530 A6220044 */  sh        $v0, 0x44($s1)
.L802A9534:
/* 4266A4 802A9534 86220044 */  lh        $v0, 0x44($s1)
/* 4266A8 802A9538 28422710 */  slti      $v0, $v0, 0x2710
/* 4266AC 802A953C 14400010 */  bnez      $v0, .L802A9580
/* 4266B0 802A9540 3C1051EB */   lui      $s0, 0x51eb
/* 4266B4 802A9544 8E30000C */  lw        $s0, 0xc($s1)
/* 4266B8 802A9548 86250056 */  lh        $a1, 0x56($s1)
/* 4266BC 802A954C 86260058 */  lh        $a2, 0x58($s1)
/* 4266C0 802A9550 24022710 */  addiu     $v0, $zero, 0x2710
/* 4266C4 802A9554 A6220044 */  sh        $v0, 0x44($s1)
/* 4266C8 802A9558 24020001 */  addiu     $v0, $zero, 1
/* 4266CC 802A955C A6220068 */  sh        $v0, 0x68($s1)
/* 4266D0 802A9560 0200202D */  daddu     $a0, $s0, $zero
/* 4266D4 802A9564 24A50032 */  addiu     $a1, $a1, 0x32
/* 4266D8 802A9568 0C051261 */  jal       hud_element_set_render_pos
/* 4266DC 802A956C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 4266E0 802A9570 0200202D */  daddu     $a0, $s0, $zero
/* 4266E4 802A9574 0C05128B */  jal       hud_element_clear_flags
/* 4266E8 802A9578 24050002 */   addiu    $a1, $zero, 2
/* 4266EC 802A957C 3C1051EB */  lui       $s0, 0x51eb
.L802A9580:
/* 4266F0 802A9580 3610851F */  ori       $s0, $s0, 0x851f
/* 4266F4 802A9584 96230044 */  lhu       $v1, 0x44($s1)
/* 4266F8 802A9588 3C048000 */  lui       $a0, 0x8000
/* 4266FC 802A958C 00031C00 */  sll       $v1, $v1, 0x10
/* 426700 802A9590 00031403 */  sra       $v0, $v1, 0x10
/* 426704 802A9594 00500018 */  mult      $v0, $s0
/* 426708 802A9598 34840041 */  ori       $a0, $a0, 0x41
/* 42670C 802A959C 0000282D */  daddu     $a1, $zero, $zero
/* 426710 802A95A0 00A0302D */  daddu     $a2, $a1, $zero
/* 426714 802A95A4 00031FC3 */  sra       $v1, $v1, 0x1f
/* 426718 802A95A8 00004810 */  mfhi      $t1
/* 42671C 802A95AC 00094143 */  sra       $t0, $t1, 5
/* 426720 802A95B0 01034023 */  subu      $t0, $t0, $v1
/* 426724 802A95B4 00081600 */  sll       $v0, $t0, 0x18
/* 426728 802A95B8 00021603 */  sra       $v0, $v0, 0x18
/* 42672C 802A95BC 00023840 */  sll       $a3, $v0, 1
/* 426730 802A95C0 00E23821 */  addu      $a3, $a3, $v0
/* 426734 802A95C4 00073880 */  sll       $a3, $a3, 2
/* 426738 802A95C8 0C0526F9 */  jal       sfx_adjust_env_sound_params
/* 42673C 802A95CC A2480084 */   sb       $t0, 0x84($s2)
/* 426740 802A95D0 86220054 */  lh        $v0, 0x54($s1)
/* 426744 802A95D4 96230054 */  lhu       $v1, 0x54($s1)
/* 426748 802A95D8 14400036 */  bnez      $v0, .L802A96B4
/* 42674C 802A95DC 2462FFFF */   addiu    $v0, $v1, -1
/* 426750 802A95E0 86220064 */  lh        $v0, 0x64($s1)
/* 426754 802A95E4 86230044 */  lh        $v1, 0x44($s1)
/* 426758 802A95E8 50400001 */  beql      $v0, $zero, .L802A95F0
/* 42675C 802A95EC 0000182D */   daddu    $v1, $zero, $zero
.L802A95F0:
/* 426760 802A95F0 14600003 */  bnez      $v1, .L802A9600
/* 426764 802A95F4 00700018 */   mult     $v1, $s0
/* 426768 802A95F8 080AA584 */  j         .L802A9610
/* 42676C 802A95FC 2402FFFF */   addiu    $v0, $zero, -1
.L802A9600:
/* 426770 802A9600 00031FC3 */  sra       $v1, $v1, 0x1f
/* 426774 802A9604 00004810 */  mfhi      $t1
/* 426778 802A9608 00091143 */  sra       $v0, $t1, 5
/* 42677C 802A960C 00431023 */  subu      $v0, $v0, $v1
.L802A9610:
/* 426780 802A9610 A2420081 */  sb        $v0, 0x81($s2)
/* 426784 802A9614 82220080 */  lb        $v0, 0x80($s1)
/* 426788 802A9618 2442FFFF */  addiu     $v0, $v0, -1
/* 42678C 802A961C 00021040 */  sll       $v0, $v0, 1
/* 426790 802A9620 02221021 */  addu      $v0, $s1, $v0
/* 426794 802A9624 84430074 */  lh        $v1, 0x74($v0)
/* 426798 802A9628 82420081 */  lb        $v0, 0x81($s2)
/* 42679C 802A962C 0043102A */  slt       $v0, $v0, $v1
/* 4267A0 802A9630 14400002 */  bnez      $v0, .L802A963C
/* 4267A4 802A9634 2402FFFE */   addiu    $v0, $zero, -2
/* 4267A8 802A9638 24020001 */  addiu     $v0, $zero, 1
.L802A963C:
/* 4267AC 802A963C A2420086 */  sb        $v0, 0x86($s2)
/* 4267B0 802A9640 82430081 */  lb        $v1, 0x81($s2)
/* 4267B4 802A9644 24020064 */  addiu     $v0, $zero, 0x64
/* 4267B8 802A9648 14620004 */  bne       $v1, $v0, .L802A965C
/* 4267BC 802A964C 3C048000 */   lui      $a0, 0x8000
/* 4267C0 802A9650 0C09A458 */  jal       func_80269160
/* 4267C4 802A9654 00000000 */   nop
/* 4267C8 802A9658 3C048000 */  lui       $a0, 0x8000
.L802A965C:
/* 4267CC 802A965C 0C05271B */  jal       sfx_stop_sound
/* 4267D0 802A9660 34840041 */   ori      $a0, $a0, 0x41
/* 4267D4 802A9664 0C093EB1 */  jal       btl_set_popup_duration
/* 4267D8 802A9668 0000202D */   daddu    $a0, $zero, $zero
/* 4267DC 802A966C 24020005 */  addiu     $v0, $zero, 5
/* 4267E0 802A9670 A6220054 */  sh        $v0, 0x54($s1)
/* 4267E4 802A9674 2402000C */  addiu     $v0, $zero, 0xc
/* 4267E8 802A9678 080AA5B1 */  j         L802A96C4_426834
/* 4267EC 802A967C A622004C */   sh       $v0, 0x4c($s1)
dlabel L802A9680_4267F0
/* 4267F0 802A9680 86220064 */  lh        $v0, 0x64($s1)
/* 4267F4 802A9684 14400007 */  bnez      $v0, .L802A96A4
/* 4267F8 802A9688 00000000 */   nop
/* 4267FC 802A968C 96220044 */  lhu       $v0, 0x44($s1)
/* 426800 802A9690 2442FF9C */  addiu     $v0, $v0, -0x64
/* 426804 802A9694 A6220044 */  sh        $v0, 0x44($s1)
/* 426808 802A9698 00021400 */  sll       $v0, $v0, 0x10
/* 42680C 802A969C 04420001 */  bltzl     $v0, .L802A96A4
/* 426810 802A96A0 A6200044 */   sh       $zero, 0x44($s1)
.L802A96A4:
/* 426814 802A96A4 86220054 */  lh        $v0, 0x54($s1)
/* 426818 802A96A8 96230054 */  lhu       $v1, 0x54($s1)
/* 42681C 802A96AC 10400003 */  beqz      $v0, .L802A96BC
/* 426820 802A96B0 2462FFFF */   addiu    $v0, $v1, -1
.L802A96B4:
/* 426824 802A96B4 080AA5B1 */  j         L802A96C4_426834
/* 426828 802A96B8 A6220054 */   sh       $v0, 0x54($s1)
.L802A96BC:
/* 42682C 802A96BC 0C09A327 */  jal       func_80268C9C
/* 426830 802A96C0 00000000 */   nop
dlabel L802A96C4_426834
/* 426834 802A96C4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 426838 802A96C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 42683C 802A96CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 426840 802A96D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 426844 802A96D4 03E00008 */  jr        $ra
/* 426848 802A96D8 27BD0020 */   addiu    $sp, $sp, 0x20
