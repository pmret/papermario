.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_entity_model_B
/* B85B8 80121EB8 27BDFF60 */  addiu     $sp, $sp, -0xa0
/* B85BC 80121EBC 0080402D */  daddu     $t0, $a0, $zero
/* B85C0 80121EC0 AFB1008C */  sw        $s1, 0x8c($sp)
/* B85C4 80121EC4 27B10028 */  addiu     $s1, $sp, 0x28
/* B85C8 80121EC8 3C09800A */  lui       $t1, %hi(gCurrentCamID)
/* B85CC 80121ECC 8529A634 */  lh        $t1, %lo(gCurrentCamID)($t1)
/* B85D0 80121ED0 3C04800B */  lui       $a0, %hi(gCameras)
/* B85D4 80121ED4 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* B85D8 80121ED8 AFBF0094 */  sw        $ra, 0x94($sp)
/* B85DC 80121EDC AFB20090 */  sw        $s2, 0x90($sp)
/* B85E0 80121EE0 AFB00088 */  sw        $s0, 0x88($sp)
/* B85E4 80121EE4 F7B40098 */  sdc1      $f20, 0x98($sp)
/* B85E8 80121EE8 00091080 */  sll       $v0, $t1, 2
/* B85EC 80121EEC 00491021 */  addu      $v0, $v0, $t1
/* B85F0 80121EF0 00021080 */  sll       $v0, $v0, 2
/* B85F4 80121EF4 00491023 */  subu      $v0, $v0, $t1
/* B85F8 80121EF8 000218C0 */  sll       $v1, $v0, 3
/* B85FC 80121EFC 00431021 */  addu      $v0, $v0, $v1
/* B8600 80121F00 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* B8604 80121F04 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* B8608 80121F08 000210C0 */  sll       $v0, $v0, 3
/* B860C 80121F0C 80630070 */  lb        $v1, 0x70($v1)
/* B8610 80121F10 10600004 */  beqz      $v1, .L80121F24
/* B8614 80121F14 00449021 */   addu     $s2, $v0, $a0
/* B8618 80121F18 31020800 */  andi      $v0, $t0, 0x800
/* B861C 80121F1C 10400053 */  beqz      $v0, .L8012206C
/* B8620 80121F20 00000000 */   nop
.L80121F24:
/* B8624 80121F24 2402F7FF */  addiu     $v0, $zero, -0x801
/* B8628 80121F28 01024024 */  and       $t0, $t0, $v0
/* B862C 80121F2C 3C038015 */  lui       $v1, %hi(gCurrentEntityModelList)
/* B8630 80121F30 8C634370 */  lw        $v1, %lo(gCurrentEntityModelList)($v1)
/* B8634 80121F34 00081080 */  sll       $v0, $t0, 2
/* B8638 80121F38 00431021 */  addu      $v0, $v0, $v1
/* B863C 80121F3C 8C500000 */  lw        $s0, ($v0)
/* B8640 80121F40 1200004A */  beqz      $s0, .L8012206C
/* B8644 80121F44 00000000 */   nop
/* B8648 80121F48 8E030000 */  lw        $v1, ($s0)
/* B864C 80121F4C 10600047 */  beqz      $v1, .L8012206C
/* B8650 80121F50 30620100 */   andi     $v0, $v1, 0x100
/* B8654 80121F54 14400045 */  bnez      $v0, .L8012206C
/* B8658 80121F58 30620020 */   andi     $v0, $v1, 0x20
/* B865C 80121F5C 14400043 */  bnez      $v0, .L8012206C
/* B8660 80121F60 24020001 */   addiu    $v0, $zero, 1
/* B8664 80121F64 01221004 */  sllv      $v0, $v0, $t1
/* B8668 80121F68 00621024 */  and       $v0, $v1, $v0
/* B866C 80121F6C 1040003F */  beqz      $v0, .L8012206C
/* B8670 80121F70 26030018 */   addiu    $v1, $s0, 0x18
/* B8674 80121F74 00A0102D */  daddu     $v0, $a1, $zero
/* B8678 80121F78 24A40040 */  addiu     $a0, $a1, 0x40
.L80121F7C:
/* B867C 80121F7C 8C4A0000 */  lw        $t2, ($v0)
/* B8680 80121F80 8C4B0004 */  lw        $t3, 4($v0)
/* B8684 80121F84 8C4C0008 */  lw        $t4, 8($v0)
/* B8688 80121F88 8C4D000C */  lw        $t5, 0xc($v0)
/* B868C 80121F8C AC6A0000 */  sw        $t2, ($v1)
/* B8690 80121F90 AC6B0004 */  sw        $t3, 4($v1)
/* B8694 80121F94 AC6C0008 */  sw        $t4, 8($v1)
/* B8698 80121F98 AC6D000C */  sw        $t5, 0xc($v1)
/* B869C 80121F9C 24420010 */  addiu     $v0, $v0, 0x10
/* B86A0 80121FA0 1444FFF6 */  bne       $v0, $a0, .L80121F7C
/* B86A4 80121FA4 24630010 */   addiu    $v1, $v1, 0x10
/* B86A8 80121FA8 27A40038 */  addiu     $a0, $sp, 0x38
/* B86AC 80121FAC 3C018015 */  lui       $at, %hi(D_80154374)
/* B86B0 80121FB0 AC264374 */  sw        $a2, %lo(D_80154374)($at)
/* B86B4 80121FB4 0C019D60 */  jal       guMtxL2F
/* B86B8 80121FB8 AE07005C */   sw       $a3, 0x5c($s0)
/* B86BC 80121FBC 264400D4 */  addiu     $a0, $s2, 0xd4
/* B86C0 80121FC0 C7A00068 */  lwc1      $f0, 0x68($sp)
/* B86C4 80121FC4 C7A2006C */  lwc1      $f2, 0x6c($sp)
/* B86C8 80121FC8 C7B40070 */  lwc1      $f20, 0x70($sp)
/* B86CC 80121FCC 27A20078 */  addiu     $v0, $sp, 0x78
/* B86D0 80121FD0 AFA20014 */  sw        $v0, 0x14($sp)
/* B86D4 80121FD4 27A2007C */  addiu     $v0, $sp, 0x7c
/* B86D8 80121FD8 AFA20018 */  sw        $v0, 0x18($sp)
/* B86DC 80121FDC 27A20080 */  addiu     $v0, $sp, 0x80
/* B86E0 80121FE0 AFA2001C */  sw        $v0, 0x1c($sp)
/* B86E4 80121FE4 44050000 */  mfc1      $a1, $f0
/* B86E8 80121FE8 3C013F80 */  lui       $at, 0x3f80
/* B86EC 80121FEC 44810000 */  mtc1      $at, $f0
/* B86F0 80121FF0 44061000 */  mfc1      $a2, $f2
/* B86F4 80121FF4 4407A000 */  mfc1      $a3, $f20
/* B86F8 80121FF8 27A20084 */  addiu     $v0, $sp, 0x84
/* B86FC 80121FFC AFA20020 */  sw        $v0, 0x20($sp)
/* B8700 80122000 0C00A588 */  jal       transform_point
/* B8704 80122004 E7A00010 */   swc1     $f0, 0x10($sp)
/* B8708 80122008 82030004 */  lb        $v1, 4($s0)
/* B870C 8012200C 3C028012 */  lui       $v0, %hi(appendGfx_entity_model)
/* B8710 80122010 24421184 */  addiu     $v0, $v0, %lo(appendGfx_entity_model)
/* B8714 80122014 AE300008 */  sw        $s0, 8($s1)
/* B8718 80122018 AE22000C */  sw        $v0, 0xc($s1)
/* B871C 8012201C AE230000 */  sw        $v1, ($s1)
/* B8720 80122020 8E020000 */  lw        $v0, ($s0)
/* B8724 80122024 3042F000 */  andi      $v0, $v0, 0xf000
/* B8728 80122028 00021202 */  srl       $v0, $v0, 8
/* B872C 8012202C 44821000 */  mtc1      $v0, $f2
/* B8730 80122030 00000000 */  nop
/* B8734 80122034 468010A1 */  cvt.d.w   $f2, $f2
/* B8738 80122038 04430007 */  bgezl     $v0, .L80122058
/* B873C 8012203C 46201020 */   cvt.s.d  $f0, $f2
/* B8740 80122040 3C0141F0 */  lui       $at, 0x41f0
/* B8744 80122044 44810800 */  mtc1      $at, $f1
/* B8748 80122048 44800000 */  mtc1      $zero, $f0
/* B874C 8012204C 00000000 */  nop
/* B8750 80122050 46201080 */  add.d     $f2, $f2, $f0
/* B8754 80122054 46201020 */  cvt.s.d   $f0, $f2
.L80122058:
/* B8758 80122058 46140000 */  add.s     $f0, $f0, $f20
/* B875C 8012205C 0220202D */  daddu     $a0, $s1, $zero
/* B8760 80122060 4600010D */  trunc.w.s $f4, $f0
/* B8764 80122064 0C047644 */  jal       queue_render_task
/* B8768 80122068 E4840004 */   swc1     $f4, 4($a0)
.L8012206C:
/* B876C 8012206C 8FBF0094 */  lw        $ra, 0x94($sp)
/* B8770 80122070 8FB20090 */  lw        $s2, 0x90($sp)
/* B8774 80122074 8FB1008C */  lw        $s1, 0x8c($sp)
/* B8778 80122078 8FB00088 */  lw        $s0, 0x88($sp)
/* B877C 8012207C D7B40098 */  ldc1      $f20, 0x98($sp)
/* B8780 80122080 03E00008 */  jr        $ra
/* B8784 80122084 27BD00A0 */   addiu    $sp, $sp, 0xa0
