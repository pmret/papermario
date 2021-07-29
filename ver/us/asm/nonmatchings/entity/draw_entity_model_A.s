.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_entity_model_A
/* B83E8 80121CE8 27BDFF60 */  addiu     $sp, $sp, -0xa0
/* B83EC 80121CEC 0080302D */  daddu     $a2, $a0, $zero
/* B83F0 80121CF0 AFB1008C */  sw        $s1, 0x8c($sp)
/* B83F4 80121CF4 27B10028 */  addiu     $s1, $sp, 0x28
/* B83F8 80121CF8 3C07800A */  lui       $a3, %hi(gCurrentCamID)
/* B83FC 80121CFC 84E7A634 */  lh        $a3, %lo(gCurrentCamID)($a3)
/* B8400 80121D00 3C04800B */  lui       $a0, %hi(gCameras)
/* B8404 80121D04 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* B8408 80121D08 AFBF0094 */  sw        $ra, 0x94($sp)
/* B840C 80121D0C AFB20090 */  sw        $s2, 0x90($sp)
/* B8410 80121D10 AFB00088 */  sw        $s0, 0x88($sp)
/* B8414 80121D14 F7B40098 */  sdc1      $f20, 0x98($sp)
/* B8418 80121D18 00071080 */  sll       $v0, $a3, 2
/* B841C 80121D1C 00471021 */  addu      $v0, $v0, $a3
/* B8420 80121D20 00021080 */  sll       $v0, $v0, 2
/* B8424 80121D24 00471023 */  subu      $v0, $v0, $a3
/* B8428 80121D28 000218C0 */  sll       $v1, $v0, 3
/* B842C 80121D2C 00431021 */  addu      $v0, $v0, $v1
/* B8430 80121D30 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* B8434 80121D34 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* B8438 80121D38 000210C0 */  sll       $v0, $v0, 3
/* B843C 80121D3C 80630070 */  lb        $v1, 0x70($v1)
/* B8440 80121D40 10600004 */  beqz      $v1, .L80121D54
/* B8444 80121D44 00449021 */   addu     $s2, $v0, $a0
/* B8448 80121D48 30C20800 */  andi      $v0, $a2, 0x800
/* B844C 80121D4C 10400053 */  beqz      $v0, .L80121E9C
/* B8450 80121D50 00000000 */   nop
.L80121D54:
/* B8454 80121D54 2402F7FF */  addiu     $v0, $zero, -0x801
/* B8458 80121D58 00C23024 */  and       $a2, $a2, $v0
/* B845C 80121D5C 3C038015 */  lui       $v1, %hi(gCurrentEntityModelList)
/* B8460 80121D60 8C634370 */  lw        $v1, %lo(gCurrentEntityModelList)($v1)
/* B8464 80121D64 00061080 */  sll       $v0, $a2, 2
/* B8468 80121D68 00431021 */  addu      $v0, $v0, $v1
/* B846C 80121D6C 8C500000 */  lw        $s0, ($v0)
/* B8470 80121D70 1200004A */  beqz      $s0, .L80121E9C
/* B8474 80121D74 00000000 */   nop
/* B8478 80121D78 8E030000 */  lw        $v1, ($s0)
/* B847C 80121D7C 10600047 */  beqz      $v1, .L80121E9C
/* B8480 80121D80 30620100 */   andi     $v0, $v1, 0x100
/* B8484 80121D84 14400045 */  bnez      $v0, .L80121E9C
/* B8488 80121D88 30620020 */   andi     $v0, $v1, 0x20
/* B848C 80121D8C 14400043 */  bnez      $v0, .L80121E9C
/* B8490 80121D90 30620040 */   andi     $v0, $v1, 0x40
/* B8494 80121D94 14400041 */  bnez      $v0, .L80121E9C
/* B8498 80121D98 24020001 */   addiu    $v0, $zero, 1
/* B849C 80121D9C 00E21004 */  sllv      $v0, $v0, $a3
/* B84A0 80121DA0 00621024 */  and       $v0, $v1, $v0
/* B84A4 80121DA4 1040003D */  beqz      $v0, .L80121E9C
/* B84A8 80121DA8 26030018 */   addiu    $v1, $s0, 0x18
/* B84AC 80121DAC 00A0102D */  daddu     $v0, $a1, $zero
/* B84B0 80121DB0 24A40040 */  addiu     $a0, $a1, 0x40
.L80121DB4:
/* B84B4 80121DB4 8C480000 */  lw        $t0, ($v0)
/* B84B8 80121DB8 8C490004 */  lw        $t1, 4($v0)
/* B84BC 80121DBC 8C4A0008 */  lw        $t2, 8($v0)
/* B84C0 80121DC0 8C4B000C */  lw        $t3, 0xc($v0)
/* B84C4 80121DC4 AC680000 */  sw        $t0, ($v1)
/* B84C8 80121DC8 AC690004 */  sw        $t1, 4($v1)
/* B84CC 80121DCC AC6A0008 */  sw        $t2, 8($v1)
/* B84D0 80121DD0 AC6B000C */  sw        $t3, 0xc($v1)
/* B84D4 80121DD4 24420010 */  addiu     $v0, $v0, 0x10
/* B84D8 80121DD8 1444FFF6 */  bne       $v0, $a0, .L80121DB4
/* B84DC 80121DDC 24630010 */   addiu    $v1, $v1, 0x10
/* B84E0 80121DE0 27A40038 */  addiu     $a0, $sp, 0x38
/* B84E4 80121DE4 0C019D60 */  jal       guMtxL2F
/* B84E8 80121DE8 AE00005C */   sw       $zero, 0x5c($s0)
/* B84EC 80121DEC 264400D4 */  addiu     $a0, $s2, 0xd4
/* B84F0 80121DF0 C7A00068 */  lwc1      $f0, 0x68($sp)
/* B84F4 80121DF4 C7A2006C */  lwc1      $f2, 0x6c($sp)
/* B84F8 80121DF8 C7B40070 */  lwc1      $f20, 0x70($sp)
/* B84FC 80121DFC 27A20078 */  addiu     $v0, $sp, 0x78
/* B8500 80121E00 AFA20014 */  sw        $v0, 0x14($sp)
/* B8504 80121E04 27A2007C */  addiu     $v0, $sp, 0x7c
/* B8508 80121E08 AFA20018 */  sw        $v0, 0x18($sp)
/* B850C 80121E0C 27A20080 */  addiu     $v0, $sp, 0x80
/* B8510 80121E10 AFA2001C */  sw        $v0, 0x1c($sp)
/* B8514 80121E14 44050000 */  mfc1      $a1, $f0
/* B8518 80121E18 3C013F80 */  lui       $at, 0x3f80
/* B851C 80121E1C 44810000 */  mtc1      $at, $f0
/* B8520 80121E20 44061000 */  mfc1      $a2, $f2
/* B8524 80121E24 4407A000 */  mfc1      $a3, $f20
/* B8528 80121E28 27A20084 */  addiu     $v0, $sp, 0x84
/* B852C 80121E2C AFA20020 */  sw        $v0, 0x20($sp)
/* B8530 80121E30 0C00A588 */  jal       transform_point
/* B8534 80121E34 E7A00010 */   swc1     $f0, 0x10($sp)
/* B8538 80121E38 82030004 */  lb        $v1, 4($s0)
/* B853C 80121E3C 3C028012 */  lui       $v0, %hi(appendGfx_entity_model)
/* B8540 80121E40 24421184 */  addiu     $v0, $v0, %lo(appendGfx_entity_model)
/* B8544 80121E44 AE300008 */  sw        $s0, 8($s1)
/* B8548 80121E48 AE22000C */  sw        $v0, 0xc($s1)
/* B854C 80121E4C AE230000 */  sw        $v1, ($s1)
/* B8550 80121E50 8E020000 */  lw        $v0, ($s0)
/* B8554 80121E54 3042F000 */  andi      $v0, $v0, 0xf000
/* B8558 80121E58 00021202 */  srl       $v0, $v0, 8
/* B855C 80121E5C 44821000 */  mtc1      $v0, $f2
/* B8560 80121E60 00000000 */  nop
/* B8564 80121E64 468010A1 */  cvt.d.w   $f2, $f2
/* B8568 80121E68 04430007 */  bgezl     $v0, .L80121E88
/* B856C 80121E6C 46201020 */   cvt.s.d  $f0, $f2
/* B8570 80121E70 3C0141F0 */  lui       $at, 0x41f0
/* B8574 80121E74 44810800 */  mtc1      $at, $f1
/* B8578 80121E78 44800000 */  mtc1      $zero, $f0
/* B857C 80121E7C 00000000 */  nop
/* B8580 80121E80 46201080 */  add.d     $f2, $f2, $f0
/* B8584 80121E84 46201020 */  cvt.s.d   $f0, $f2
.L80121E88:
/* B8588 80121E88 46140000 */  add.s     $f0, $f0, $f20
/* B858C 80121E8C 0220202D */  daddu     $a0, $s1, $zero
/* B8590 80121E90 4600010D */  trunc.w.s $f4, $f0
/* B8594 80121E94 0C047644 */  jal       queue_render_task
/* B8598 80121E98 E4840004 */   swc1     $f4, 4($a0)
.L80121E9C:
/* B859C 80121E9C 8FBF0094 */  lw        $ra, 0x94($sp)
/* B85A0 80121EA0 8FB20090 */  lw        $s2, 0x90($sp)
/* B85A4 80121EA4 8FB1008C */  lw        $s1, 0x8c($sp)
/* B85A8 80121EA8 8FB00088 */  lw        $s0, 0x88($sp)
/* B85AC 80121EAC D7B40098 */  ldc1      $f20, 0x98($sp)
/* B85B0 80121EB0 03E00008 */  jr        $ra
/* B85B4 80121EB4 27BD00A0 */   addiu    $sp, $sp, 0xa0
