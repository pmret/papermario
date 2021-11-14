.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_8014FE60
.word L8011EC3C_B533C, L8011EC5C_B535C, L8011F034_B5734, L8011EC7C_B537C, L8011F034_B5734, L8011ED48_B5448, L8011EE10_B5510, L8011F034_B5734, L8011EEF0_B55F0, L8011F034_B5734, L8011EC8C_B538C, L8011F034_B5734, L8011F034_B5734, L8011F034_B5734, L8011EC9C_B539C, L8011ECB8_B53B8, L8011ECEC_B53EC, L8011EF6C_B566C, L8011EC44_B5344, L8011ED2C_B542C

dlabel D_8014FEB0
.double 180.0

dlabel D_8014FEB8
.double 32767.0

dlabel D_8014FEC0
.double 180.0

dlabel D_8014FEC8
.double 32767.0

dlabel D_8014FED0
.double 180.0

dlabel D_8014FED8
.double 32767.0

.section .text

glabel step_model_animator
/* B52F0 8011EBF0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B52F4 8011EBF4 AFB10014 */  sw        $s1, 0x14($sp)
/* B52F8 8011EBF8 0080882D */  daddu     $s1, $a0, $zero
/* B52FC 8011EBFC AFBF0018 */  sw        $ra, 0x18($sp)
/* B5300 8011EC00 AFB00010 */  sw        $s0, 0x10($sp)
/* B5304 8011EC04 F7B80030 */  sdc1      $f24, 0x30($sp)
/* B5308 8011EC08 F7B60028 */  sdc1      $f22, 0x28($sp)
/* B530C 8011EC0C F7B40020 */  sdc1      $f20, 0x20($sp)
/* B5310 8011EC10 8E300008 */  lw        $s0, 8($s1)
/* B5314 8011EC14 86030000 */  lh        $v1, ($s0)
/* B5318 8011EC18 2C620014 */  sltiu     $v0, $v1, 0x14
/* B531C 8011EC1C 10400105 */  beqz      $v0, L8011F034_B5734
/* B5320 8011EC20 26100002 */   addiu    $s0, $s0, 2
/* B5324 8011EC24 00031080 */  sll       $v0, $v1, 2
/* B5328 8011EC28 3C018015 */  lui       $at, %hi(jtbl_8014FE60)
/* B532C 8011EC2C 00220821 */  addu      $at, $at, $v0
/* B5330 8011EC30 8C22FE60 */  lw        $v0, %lo(jtbl_8014FE60)($at)
/* B5334 8011EC34 00400008 */  jr        $v0
/* B5338 8011EC38 00000000 */   nop
dlabel L8011EC3C_B533C
/* B533C 8011EC3C 08047C0E */  j         .L8011F038
/* B5340 8011EC40 2402FFFF */   addiu    $v0, $zero, -1
dlabel L8011EC44_B5344
/* B5344 8011EC44 92030001 */  lbu       $v1, 1($s0)
/* B5348 8011EC48 26100002 */  addiu     $s0, $s0, 2
/* B534C 8011EC4C 24020001 */  addiu     $v0, $zero, 1
/* B5350 8011EC50 AE300008 */  sw        $s0, 8($s1)
/* B5354 8011EC54 08047C0E */  j         .L8011F038
/* B5358 8011EC58 A2230004 */   sb       $v1, 4($s1)
dlabel L8011EC5C_B535C
/* B535C 8011EC5C 86020000 */  lh        $v0, ($s0)
/* B5360 8011EC60 26100002 */  addiu     $s0, $s0, 2
/* B5364 8011EC64 AE300008 */  sw        $s0, 8($s1)
/* B5368 8011EC68 44820000 */  mtc1      $v0, $f0
/* B536C 8011EC6C 00000000 */  nop
/* B5370 8011EC70 46800020 */  cvt.s.w   $f0, $f0
/* B5374 8011EC74 08047C0D */  j         L8011F034_B5734
/* B5378 8011EC78 E6200090 */   swc1     $f0, 0x90($s1)
dlabel L8011EC7C_B537C
/* B537C 8011EC7C 8E23000C */  lw        $v1, 0xc($s1)
/* B5380 8011EC80 24020001 */  addiu     $v0, $zero, 1
/* B5384 8011EC84 08047C0E */  j         .L8011F038
/* B5388 8011EC88 AE230008 */   sw       $v1, 8($s1)
dlabel L8011EC8C_B538C
/* B538C 8011EC8C 24020001 */  addiu     $v0, $zero, 1
/* B5390 8011EC90 AE30000C */  sw        $s0, 0xc($s1)
/* B5394 8011EC94 08047C0E */  j         .L8011F038
/* B5398 8011EC98 AE300008 */   sw       $s0, 8($s1)
dlabel L8011EC9C_B539C
/* B539C 8011EC9C 86040000 */  lh        $a0, ($s0)
/* B53A0 8011ECA0 26100002 */  addiu     $s0, $s0, 2
/* B53A4 8011ECA4 8E230000 */  lw        $v1, ($s1)
/* B53A8 8011ECA8 24020001 */  addiu     $v0, $zero, 1
/* B53AC 8011ECAC AE300008 */  sw        $s0, 8($s1)
/* B53B0 8011ECB0 08047B4F */  j         .L8011ED3C
/* B53B4 8011ECB4 3084FFFF */   andi     $a0, $a0, 0xffff
dlabel L8011ECB8_B53B8
/* B53B8 8011ECB8 86020000 */  lh        $v0, ($s0)
/* B53BC 8011ECBC 8E240010 */  lw        $a0, 0x10($s1)
/* B53C0 8011ECC0 00511021 */  addu      $v0, $v0, $s1
/* B53C4 8011ECC4 90450014 */  lbu       $a1, 0x14($v0)
/* B53C8 8011ECC8 0C047837 */  jal       get_animator_child_with_id
/* B53CC 8011ECCC 26100002 */   addiu    $s0, $s0, 2
/* B53D0 8011ECD0 0040282D */  daddu     $a1, $v0, $zero
/* B53D4 8011ECD4 86040000 */  lh        $a0, ($s0)
/* B53D8 8011ECD8 26100002 */  addiu     $s0, $s0, 2
/* B53DC 8011ECDC 94A300F4 */  lhu       $v1, 0xf4($a1)
/* B53E0 8011ECE0 24020001 */  addiu     $v0, $zero, 1
/* B53E4 8011ECE4 08047B48 */  j         .L8011ED20
/* B53E8 8011ECE8 00641825 */   or       $v1, $v1, $a0
dlabel L8011ECEC_B53EC
/* B53EC 8011ECEC 86020000 */  lh        $v0, ($s0)
/* B53F0 8011ECF0 8E240010 */  lw        $a0, 0x10($s1)
/* B53F4 8011ECF4 00511021 */  addu      $v0, $v0, $s1
/* B53F8 8011ECF8 90450014 */  lbu       $a1, 0x14($v0)
/* B53FC 8011ECFC 0C047837 */  jal       get_animator_child_with_id
/* B5400 8011ED00 26100002 */   addiu    $s0, $s0, 2
/* B5404 8011ED04 0040282D */  daddu     $a1, $v0, $zero
/* B5408 8011ED08 86040000 */  lh        $a0, ($s0)
/* B540C 8011ED0C 26100002 */  addiu     $s0, $s0, 2
/* B5410 8011ED10 24020001 */  addiu     $v0, $zero, 1
/* B5414 8011ED14 94A300F4 */  lhu       $v1, 0xf4($a1)
/* B5418 8011ED18 00042027 */  nor       $a0, $zero, $a0
/* B541C 8011ED1C 00641824 */  and       $v1, $v1, $a0
.L8011ED20:
/* B5420 8011ED20 A4A300F4 */  sh        $v1, 0xf4($a1)
/* B5424 8011ED24 08047C0E */  j         .L8011F038
/* B5428 8011ED28 AE300008 */   sw       $s0, 8($s1)
dlabel L8011ED2C_B542C
/* B542C 8011ED2C 24020001 */  addiu     $v0, $zero, 1
/* B5430 8011ED30 8E230000 */  lw        $v1, ($s1)
/* B5434 8011ED34 3C040002 */  lui       $a0, 2
/* B5438 8011ED38 AE300008 */  sw        $s0, 8($s1)
.L8011ED3C:
/* B543C 8011ED3C 00641825 */  or        $v1, $v1, $a0
/* B5440 8011ED40 08047C0E */  j         .L8011F038
/* B5444 8011ED44 AE230000 */   sw       $v1, ($s1)
dlabel L8011ED48_B5448
/* B5448 8011ED48 86030000 */  lh        $v1, ($s0)
/* B544C 8011ED4C 26100002 */  addiu     $s0, $s0, 2
/* B5450 8011ED50 86020000 */  lh        $v0, ($s0)
/* B5454 8011ED54 3C018015 */  lui       $at, %hi(D_8014FEB0)
/* B5458 8011ED58 D424FEB0 */  ldc1      $f4, %lo(D_8014FEB0)($at)
/* B545C 8011ED5C 44823000 */  mtc1      $v0, $f6
/* B5460 8011ED60 00000000 */  nop
/* B5464 8011ED64 468031A0 */  cvt.s.w   $f6, $f6
/* B5468 8011ED68 460031A1 */  cvt.d.s   $f6, $f6
/* B546C 8011ED6C 46243182 */  mul.d     $f6, $f6, $f4
/* B5470 8011ED70 00000000 */  nop
/* B5474 8011ED74 26100002 */  addiu     $s0, $s0, 2
/* B5478 8011ED78 86020000 */  lh        $v0, ($s0)
/* B547C 8011ED7C 44821000 */  mtc1      $v0, $f2
/* B5480 8011ED80 00000000 */  nop
/* B5484 8011ED84 468010A0 */  cvt.s.w   $f2, $f2
/* B5488 8011ED88 460010A1 */  cvt.d.s   $f2, $f2
/* B548C 8011ED8C 46241082 */  mul.d     $f2, $f2, $f4
/* B5490 8011ED90 00000000 */  nop
/* B5494 8011ED94 8E240010 */  lw        $a0, 0x10($s1)
/* B5498 8011ED98 26100002 */  addiu     $s0, $s0, 2
/* B549C 8011ED9C 00711821 */  addu      $v1, $v1, $s1
/* B54A0 8011EDA0 86020000 */  lh        $v0, ($s0)
/* B54A4 8011EDA4 90650014 */  lbu       $a1, 0x14($v1)
/* B54A8 8011EDA8 44820000 */  mtc1      $v0, $f0
/* B54AC 8011EDAC 00000000 */  nop
/* B54B0 8011EDB0 46800020 */  cvt.s.w   $f0, $f0
/* B54B4 8011EDB4 46000021 */  cvt.d.s   $f0, $f0
/* B54B8 8011EDB8 46240002 */  mul.d     $f0, $f0, $f4
/* B54BC 8011EDBC 00000000 */  nop
/* B54C0 8011EDC0 3C018015 */  lui       $at, %hi(D_8014FEB8)
/* B54C4 8011EDC4 D424FEB8 */  ldc1      $f4, %lo(D_8014FEB8)($at)
/* B54C8 8011EDC8 26100002 */  addiu     $s0, $s0, 2
/* B54CC 8011EDCC AE300008 */  sw        $s0, 8($s1)
/* B54D0 8011EDD0 46243183 */  div.d     $f6, $f6, $f4
/* B54D4 8011EDD4 46203620 */  cvt.s.d   $f24, $f6
/* B54D8 8011EDD8 46241083 */  div.d     $f2, $f2, $f4
/* B54DC 8011EDDC 462015A0 */  cvt.s.d   $f22, $f2
/* B54E0 8011EDE0 46240003 */  div.d     $f0, $f0, $f4
/* B54E4 8011EDE4 0C047837 */  jal       get_animator_child_with_id
/* B54E8 8011EDE8 46200520 */   cvt.s.d  $f20, $f0
/* B54EC 8011EDEC 0040282D */  daddu     $a1, $v0, $zero
/* B54F0 8011EDF0 14A00003 */  bnez      $a1, .L8011EE00
/* B54F4 8011EDF4 24020001 */   addiu    $v0, $zero, 1
.L8011EDF8:
/* B54F8 8011EDF8 08047B7E */  j         .L8011EDF8
/* B54FC 8011EDFC 00000000 */   nop
.L8011EE00:
/* B5500 8011EE00 E4B8009C */  swc1      $f24, 0x9c($a1)
/* B5504 8011EE04 E4B600A0 */  swc1      $f22, 0xa0($a1)
/* B5508 8011EE08 08047C0E */  j         .L8011F038
/* B550C 8011EE0C E4B400A4 */   swc1     $f20, 0xa4($a1)
dlabel L8011EE10_B5510
/* B5510 8011EE10 86030000 */  lh        $v1, ($s0)
/* B5514 8011EE14 26100002 */  addiu     $s0, $s0, 2
/* B5518 8011EE18 86020000 */  lh        $v0, ($s0)
/* B551C 8011EE1C 3C018015 */  lui       $at, %hi(D_8014FEC0)
/* B5520 8011EE20 D424FEC0 */  ldc1      $f4, %lo(D_8014FEC0)($at)
/* B5524 8011EE24 44823000 */  mtc1      $v0, $f6
/* B5528 8011EE28 00000000 */  nop
/* B552C 8011EE2C 468031A0 */  cvt.s.w   $f6, $f6
/* B5530 8011EE30 460031A1 */  cvt.d.s   $f6, $f6
/* B5534 8011EE34 46243182 */  mul.d     $f6, $f6, $f4
/* B5538 8011EE38 00000000 */  nop
/* B553C 8011EE3C 26100002 */  addiu     $s0, $s0, 2
/* B5540 8011EE40 86020000 */  lh        $v0, ($s0)
/* B5544 8011EE44 44821000 */  mtc1      $v0, $f2
/* B5548 8011EE48 00000000 */  nop
/* B554C 8011EE4C 468010A0 */  cvt.s.w   $f2, $f2
/* B5550 8011EE50 460010A1 */  cvt.d.s   $f2, $f2
/* B5554 8011EE54 46241082 */  mul.d     $f2, $f2, $f4
/* B5558 8011EE58 00000000 */  nop
/* B555C 8011EE5C 8E240010 */  lw        $a0, 0x10($s1)
/* B5560 8011EE60 26100002 */  addiu     $s0, $s0, 2
/* B5564 8011EE64 00711821 */  addu      $v1, $v1, $s1
/* B5568 8011EE68 86020000 */  lh        $v0, ($s0)
/* B556C 8011EE6C 90650014 */  lbu       $a1, 0x14($v1)
/* B5570 8011EE70 44820000 */  mtc1      $v0, $f0
/* B5574 8011EE74 00000000 */  nop
/* B5578 8011EE78 46800020 */  cvt.s.w   $f0, $f0
/* B557C 8011EE7C 46000021 */  cvt.d.s   $f0, $f0
/* B5580 8011EE80 46240002 */  mul.d     $f0, $f0, $f4
/* B5584 8011EE84 00000000 */  nop
/* B5588 8011EE88 3C018015 */  lui       $at, %hi(D_8014FEC8)
/* B558C 8011EE8C D424FEC8 */  ldc1      $f4, %lo(D_8014FEC8)($at)
/* B5590 8011EE90 26100002 */  addiu     $s0, $s0, 2
/* B5594 8011EE94 AE300008 */  sw        $s0, 8($s1)
/* B5598 8011EE98 46243183 */  div.d     $f6, $f6, $f4
/* B559C 8011EE9C 46203620 */  cvt.s.d   $f24, $f6
/* B55A0 8011EEA0 46241083 */  div.d     $f2, $f2, $f4
/* B55A4 8011EEA4 462015A0 */  cvt.s.d   $f22, $f2
/* B55A8 8011EEA8 46240003 */  div.d     $f0, $f0, $f4
/* B55AC 8011EEAC 0C047837 */  jal       get_animator_child_with_id
/* B55B0 8011EEB0 46200520 */   cvt.s.d  $f20, $f0
/* B55B4 8011EEB4 0040282D */  daddu     $a1, $v0, $zero
/* B55B8 8011EEB8 14A00003 */  bnez      $a1, .L8011EEC8
/* B55BC 8011EEBC 24020001 */   addiu    $v0, $zero, 1
.L8011EEC0:
/* B55C0 8011EEC0 08047BB0 */  j         .L8011EEC0
/* B55C4 8011EEC4 00000000 */   nop
.L8011EEC8:
/* B55C8 8011EEC8 C4A4009C */  lwc1      $f4, 0x9c($a1)
/* B55CC 8011EECC 46182100 */  add.s     $f4, $f4, $f24
/* B55D0 8011EED0 C4A200A0 */  lwc1      $f2, 0xa0($a1)
/* B55D4 8011EED4 46161080 */  add.s     $f2, $f2, $f22
/* B55D8 8011EED8 C4A000A4 */  lwc1      $f0, 0xa4($a1)
/* B55DC 8011EEDC 46140000 */  add.s     $f0, $f0, $f20
/* B55E0 8011EEE0 E4A4009C */  swc1      $f4, 0x9c($a1)
/* B55E4 8011EEE4 E4A200A0 */  swc1      $f2, 0xa0($a1)
/* B55E8 8011EEE8 08047C0E */  j         .L8011F038
/* B55EC 8011EEEC E4A000A4 */   swc1     $f0, 0xa4($a1)
dlabel L8011EEF0_B55F0
/* B55F0 8011EEF0 86020000 */  lh        $v0, ($s0)
/* B55F4 8011EEF4 26100002 */  addiu     $s0, $s0, 2
/* B55F8 8011EEF8 86050000 */  lh        $a1, ($s0)
/* B55FC 8011EEFC 26100002 */  addiu     $s0, $s0, 2
/* B5600 8011EF00 86030000 */  lh        $v1, ($s0)
/* B5604 8011EF04 26100002 */  addiu     $s0, $s0, 2
/* B5608 8011EF08 86060000 */  lh        $a2, ($s0)
/* B560C 8011EF0C 26100002 */  addiu     $s0, $s0, 2
/* B5610 8011EF10 8E240010 */  lw        $a0, 0x10($s1)
/* B5614 8011EF14 4485C000 */  mtc1      $a1, $f24
/* B5618 8011EF18 00000000 */  nop
/* B561C 8011EF1C 4680C620 */  cvt.s.w   $f24, $f24
/* B5620 8011EF20 4483B000 */  mtc1      $v1, $f22
/* B5624 8011EF24 00000000 */  nop
/* B5628 8011EF28 4680B5A0 */  cvt.s.w   $f22, $f22
/* B562C 8011EF2C 00511021 */  addu      $v0, $v0, $s1
/* B5630 8011EF30 90450014 */  lbu       $a1, 0x14($v0)
/* B5634 8011EF34 4486A000 */  mtc1      $a2, $f20
/* B5638 8011EF38 00000000 */  nop
/* B563C 8011EF3C 4680A520 */  cvt.s.w   $f20, $f20
/* B5640 8011EF40 0C047837 */  jal       get_animator_child_with_id
/* B5644 8011EF44 AE300008 */   sw       $s0, 8($s1)
/* B5648 8011EF48 0040282D */  daddu     $a1, $v0, $zero
/* B564C 8011EF4C 14A00003 */  bnez      $a1, .L8011EF5C
/* B5650 8011EF50 24020001 */   addiu    $v0, $zero, 1
.L8011EF54:
/* B5654 8011EF54 08047BD5 */  j         .L8011EF54
/* B5658 8011EF58 00000000 */   nop
.L8011EF5C:
/* B565C 8011EF5C E4B80090 */  swc1      $f24, 0x90($a1)
/* B5660 8011EF60 E4B60094 */  swc1      $f22, 0x94($a1)
/* B5664 8011EF64 08047C0E */  j         .L8011F038
/* B5668 8011EF68 E4B40098 */   swc1     $f20, 0x98($a1)
dlabel L8011EF6C_B566C
/* B566C 8011EF6C 86030000 */  lh        $v1, ($s0)
/* B5670 8011EF70 26100002 */  addiu     $s0, $s0, 2
/* B5674 8011EF74 86020000 */  lh        $v0, ($s0)
/* B5678 8011EF78 3C018015 */  lui       $at, %hi(D_8014FED0)
/* B567C 8011EF7C D424FED0 */  ldc1      $f4, %lo(D_8014FED0)($at)
/* B5680 8011EF80 44823000 */  mtc1      $v0, $f6
/* B5684 8011EF84 00000000 */  nop
/* B5688 8011EF88 468031A0 */  cvt.s.w   $f6, $f6
/* B568C 8011EF8C 460031A1 */  cvt.d.s   $f6, $f6
/* B5690 8011EF90 46243182 */  mul.d     $f6, $f6, $f4
/* B5694 8011EF94 00000000 */  nop
/* B5698 8011EF98 26100002 */  addiu     $s0, $s0, 2
/* B569C 8011EF9C 86020000 */  lh        $v0, ($s0)
/* B56A0 8011EFA0 44821000 */  mtc1      $v0, $f2
/* B56A4 8011EFA4 00000000 */  nop
/* B56A8 8011EFA8 468010A0 */  cvt.s.w   $f2, $f2
/* B56AC 8011EFAC 460010A1 */  cvt.d.s   $f2, $f2
/* B56B0 8011EFB0 46241082 */  mul.d     $f2, $f2, $f4
/* B56B4 8011EFB4 00000000 */  nop
/* B56B8 8011EFB8 8E240010 */  lw        $a0, 0x10($s1)
/* B56BC 8011EFBC 26100002 */  addiu     $s0, $s0, 2
/* B56C0 8011EFC0 00711821 */  addu      $v1, $v1, $s1
/* B56C4 8011EFC4 86020000 */  lh        $v0, ($s0)
/* B56C8 8011EFC8 90650014 */  lbu       $a1, 0x14($v1)
/* B56CC 8011EFCC 44820000 */  mtc1      $v0, $f0
/* B56D0 8011EFD0 00000000 */  nop
/* B56D4 8011EFD4 46800020 */  cvt.s.w   $f0, $f0
/* B56D8 8011EFD8 46000021 */  cvt.d.s   $f0, $f0
/* B56DC 8011EFDC 46240002 */  mul.d     $f0, $f0, $f4
/* B56E0 8011EFE0 00000000 */  nop
/* B56E4 8011EFE4 3C018015 */  lui       $at, %hi(D_8014FED8)
/* B56E8 8011EFE8 D424FED8 */  ldc1      $f4, %lo(D_8014FED8)($at)
/* B56EC 8011EFEC 26100002 */  addiu     $s0, $s0, 2
/* B56F0 8011EFF0 AE300008 */  sw        $s0, 8($s1)
/* B56F4 8011EFF4 46243183 */  div.d     $f6, $f6, $f4
/* B56F8 8011EFF8 46203620 */  cvt.s.d   $f24, $f6
/* B56FC 8011EFFC 46241083 */  div.d     $f2, $f2, $f4
/* B5700 8011F000 462015A0 */  cvt.s.d   $f22, $f2
/* B5704 8011F004 46240003 */  div.d     $f0, $f0, $f4
/* B5708 8011F008 0C047837 */  jal       get_animator_child_with_id
/* B570C 8011F00C 46200520 */   cvt.s.d  $f20, $f0
/* B5710 8011F010 0040282D */  daddu     $a1, $v0, $zero
/* B5714 8011F014 14A00003 */  bnez      $a1, .L8011F024
/* B5718 8011F018 24020001 */   addiu    $v0, $zero, 1
.L8011F01C:
/* B571C 8011F01C 08047C07 */  j         .L8011F01C
/* B5720 8011F020 00000000 */   nop
.L8011F024:
/* B5724 8011F024 E4B800A8 */  swc1      $f24, 0xa8($a1)
/* B5728 8011F028 E4B600AC */  swc1      $f22, 0xac($a1)
/* B572C 8011F02C 08047C0E */  j         .L8011F038
/* B5730 8011F030 E4B400B0 */   swc1     $f20, 0xb0($a1)
dlabel L8011F034_B5734
/* B5734 8011F034 0000102D */  daddu     $v0, $zero, $zero
.L8011F038:
/* B5738 8011F038 8FBF0018 */  lw        $ra, 0x18($sp)
/* B573C 8011F03C 8FB10014 */  lw        $s1, 0x14($sp)
/* B5740 8011F040 8FB00010 */  lw        $s0, 0x10($sp)
/* B5744 8011F044 D7B80030 */  ldc1      $f24, 0x30($sp)
/* B5748 8011F048 D7B60028 */  ldc1      $f22, 0x28($sp)
/* B574C 8011F04C D7B40020 */  ldc1      $f20, 0x20($sp)
/* B5750 8011F050 03E00008 */  jr        $ra
/* B5754 8011F054 27BD0038 */   addiu    $sp, $sp, 0x38
