.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802454A8_EF25A8
.double 0.06

.section .text

glabel func_802424A4_EEF5A4
/* EEF5A4 802424A4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* EEF5A8 802424A8 AFB3004C */  sw        $s3, 0x4c($sp)
/* EEF5AC 802424AC 0080982D */  daddu     $s3, $a0, $zero
/* EEF5B0 802424B0 AFBF0050 */  sw        $ra, 0x50($sp)
/* EEF5B4 802424B4 AFB20048 */  sw        $s2, 0x48($sp)
/* EEF5B8 802424B8 AFB10044 */  sw        $s1, 0x44($sp)
/* EEF5BC 802424BC AFB00040 */  sw        $s0, 0x40($sp)
/* EEF5C0 802424C0 8E720148 */  lw        $s2, 0x148($s3)
/* EEF5C4 802424C4 00A0882D */  daddu     $s1, $a1, $zero
/* EEF5C8 802424C8 86440008 */  lh        $a0, 8($s2)
/* EEF5CC 802424CC 0C00F92F */  jal       dead_get_npc_unsafe
/* EEF5D0 802424D0 00C0802D */   daddu    $s0, $a2, $zero
/* EEF5D4 802424D4 0200202D */  daddu     $a0, $s0, $zero
/* EEF5D8 802424D8 0240282D */  daddu     $a1, $s2, $zero
/* EEF5DC 802424DC 24030001 */  addiu     $v1, $zero, 1
/* EEF5E0 802424E0 AFA30010 */  sw        $v1, 0x10($sp)
/* EEF5E4 802424E4 8E260024 */  lw        $a2, 0x24($s1)
/* EEF5E8 802424E8 8E270028 */  lw        $a3, 0x28($s1)
/* EEF5EC 802424EC 0C013469 */  jal       func_8004D1A4
/* EEF5F0 802424F0 0040802D */   daddu    $s0, $v0, $zero
/* EEF5F4 802424F4 14400020 */  bnez      $v0, .L80242578
/* EEF5F8 802424F8 24040002 */   addiu    $a0, $zero, 2
/* EEF5FC 802424FC 0200282D */  daddu     $a1, $s0, $zero
/* EEF600 80242500 0000302D */  daddu     $a2, $zero, $zero
/* EEF604 80242504 860300A8 */  lh        $v1, 0xa8($s0)
/* EEF608 80242508 3C013F80 */  lui       $at, 0x3f80
/* EEF60C 8024250C 44810000 */  mtc1      $at, $f0
/* EEF610 80242510 3C014000 */  lui       $at, 0x4000
/* EEF614 80242514 44811000 */  mtc1      $at, $f2
/* EEF618 80242518 3C01C1A0 */  lui       $at, 0xc1a0
/* EEF61C 8024251C 44812000 */  mtc1      $at, $f4
/* EEF620 80242520 2402000F */  addiu     $v0, $zero, 0xf
/* EEF624 80242524 AFA2001C */  sw        $v0, 0x1c($sp)
/* EEF628 80242528 44834000 */  mtc1      $v1, $f8
/* EEF62C 8024252C 00000000 */  nop
/* EEF630 80242530 46804220 */  cvt.s.w   $f8, $f8
/* EEF634 80242534 44074000 */  mfc1      $a3, $f8
/* EEF638 80242538 27A20028 */  addiu     $v0, $sp, 0x28
/* EEF63C 8024253C AFA20020 */  sw        $v0, 0x20($sp)
/* EEF640 80242540 E7A00010 */  swc1      $f0, 0x10($sp)
/* EEF644 80242544 E7A20014 */  swc1      $f2, 0x14($sp)
/* EEF648 80242548 0C01D444 */  jal       func_80075110
/* EEF64C 8024254C E7A40018 */   swc1     $f4, 0x18($sp)
/* EEF650 80242550 8E4200CC */  lw        $v0, 0xcc($s2)
/* EEF654 80242554 8C430000 */  lw        $v1, ($v0)
/* EEF658 80242558 2402001E */  addiu     $v0, $zero, 0x1e
/* EEF65C 8024255C A602008E */  sh        $v0, 0x8e($s0)
/* EEF660 80242560 24020014 */  addiu     $v0, $zero, 0x14
/* EEF664 80242564 AE030028 */  sw        $v1, 0x28($s0)
/* EEF668 80242568 AE620070 */  sw        $v0, 0x70($s3)
/* EEF66C 8024256C 2402001E */  addiu     $v0, $zero, 0x1e
/* EEF670 80242570 080909C2 */  j         .L80242708
/* EEF674 80242574 AE420090 */   sw       $v0, 0x90($s2)
.L80242578:
/* EEF678 80242578 8E050018 */  lw        $a1, 0x18($s0)
/* EEF67C 8024257C 8E06000C */  lw        $a2, 0xc($s0)
/* EEF680 80242580 0C00F909 */  jal       func_8003E424
/* EEF684 80242584 0200202D */   daddu    $a0, $s0, $zero
/* EEF688 80242588 8E020000 */  lw        $v0, ($s0)
/* EEF68C 8024258C 30420008 */  andi      $v0, $v0, 8
/* EEF690 80242590 14400028 */  bnez      $v0, .L80242634
/* EEF694 80242594 0000882D */   daddu    $s1, $zero, $zero
/* EEF698 80242598 27A5002C */  addiu     $a1, $sp, 0x2c
/* EEF69C 8024259C 27A60030 */  addiu     $a2, $sp, 0x30
/* EEF6A0 802425A0 860200A8 */  lh        $v0, 0xa8($s0)
/* EEF6A4 802425A4 C6000038 */  lwc1      $f0, 0x38($s0)
/* EEF6A8 802425A8 44821000 */  mtc1      $v0, $f2
/* EEF6AC 802425AC 00000000 */  nop
/* EEF6B0 802425B0 468010A0 */  cvt.s.w   $f2, $f2
/* EEF6B4 802425B4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* EEF6B8 802425B8 860200A8 */  lh        $v0, 0xa8($s0)
/* EEF6BC 802425BC C604003C */  lwc1      $f4, 0x3c($s0)
/* EEF6C0 802425C0 C6060040 */  lwc1      $f6, 0x40($s0)
/* EEF6C4 802425C4 44820000 */  mtc1      $v0, $f0
/* EEF6C8 802425C8 00000000 */  nop
/* EEF6CC 802425CC 46800021 */  cvt.d.w   $f0, $f0
/* EEF6D0 802425D0 46022100 */  add.s     $f4, $f4, $f2
/* EEF6D4 802425D4 3C014008 */  lui       $at, 0x4008
/* EEF6D8 802425D8 44811800 */  mtc1      $at, $f3
/* EEF6DC 802425DC 44801000 */  mtc1      $zero, $f2
/* EEF6E0 802425E0 27A20038 */  addiu     $v0, $sp, 0x38
/* EEF6E4 802425E4 46220000 */  add.d     $f0, $f0, $f2
/* EEF6E8 802425E8 E7A60034 */  swc1      $f6, 0x34($sp)
/* EEF6EC 802425EC E7A40030 */  swc1      $f4, 0x30($sp)
/* EEF6F0 802425F0 46200020 */  cvt.s.d   $f0, $f0
/* EEF6F4 802425F4 E7A00038 */  swc1      $f0, 0x38($sp)
/* EEF6F8 802425F8 AFA20010 */  sw        $v0, 0x10($sp)
/* EEF6FC 802425FC 8E040080 */  lw        $a0, 0x80($s0)
/* EEF700 80242600 0C03908F */  jal       func_800E423C
/* EEF704 80242604 27A70034 */   addiu    $a3, $sp, 0x34
/* EEF708 80242608 1040000A */  beqz      $v0, .L80242634
/* EEF70C 8024260C 00000000 */   nop
/* EEF710 80242610 860200A8 */  lh        $v0, 0xa8($s0)
/* EEF714 80242614 C7A20038 */  lwc1      $f2, 0x38($sp)
/* EEF718 80242618 44820000 */  mtc1      $v0, $f0
/* EEF71C 8024261C 00000000 */  nop
/* EEF720 80242620 46800020 */  cvt.s.w   $f0, $f0
/* EEF724 80242624 4600103C */  c.lt.s    $f2, $f0
/* EEF728 80242628 00000000 */  nop
/* EEF72C 8024262C 45030001 */  bc1tl     .L80242634
/* EEF730 80242630 24110001 */   addiu    $s1, $zero, 1
.L80242634:
/* EEF734 80242634 12200008 */  beqz      $s1, .L80242658
/* EEF738 80242638 00000000 */   nop
/* EEF73C 8024263C C7A00030 */  lwc1      $f0, 0x30($sp)
/* EEF740 80242640 3C013FF0 */  lui       $at, 0x3ff0
/* EEF744 80242644 44811800 */  mtc1      $at, $f3
/* EEF748 80242648 44801000 */  mtc1      $zero, $f2
/* EEF74C 8024264C 46000021 */  cvt.d.s   $f0, $f0
/* EEF750 80242650 080909B8 */  j         .L802426E0
/* EEF754 80242654 46220000 */   add.d    $f0, $f0, $f2
.L80242658:
/* EEF758 80242658 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EEF75C 8024265C 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EEF760 80242660 3C014018 */  lui       $at, 0x4018
/* EEF764 80242664 44811800 */  mtc1      $at, $f3
/* EEF768 80242668 44801000 */  mtc1      $zero, $f2
/* EEF76C 8024266C C440002C */  lwc1      $f0, 0x2c($v0)
/* EEF770 80242670 C604003C */  lwc1      $f4, 0x3c($s0)
/* EEF774 80242674 46000021 */  cvt.d.s   $f0, $f0
/* EEF778 80242678 46220000 */  add.d     $f0, $f0, $f2
/* EEF77C 8024267C 46002121 */  cvt.d.s   $f4, $f4
/* EEF780 80242680 46202001 */  sub.d     $f0, $f4, $f0
/* EEF784 80242684 462001A0 */  cvt.s.d   $f6, $f0
/* EEF788 80242688 44800000 */  mtc1      $zero, $f0
/* EEF78C 8024268C 44800800 */  mtc1      $zero, $f1
/* EEF790 80242690 460030A1 */  cvt.d.s   $f2, $f6
/* EEF794 80242694 4620103C */  c.lt.d    $f2, $f0
/* EEF798 80242698 00000000 */  nop
/* EEF79C 8024269C 45010009 */  bc1t      .L802426C4
/* EEF7A0 802426A0 00000000 */   nop
/* EEF7A4 802426A4 3C014010 */  lui       $at, 0x4010
/* EEF7A8 802426A8 44810800 */  mtc1      $at, $f1
/* EEF7AC 802426AC 44800000 */  mtc1      $zero, $f0
/* EEF7B0 802426B0 00000000 */  nop
/* EEF7B4 802426B4 4622003C */  c.lt.d    $f0, $f2
/* EEF7B8 802426B8 00000000 */  nop
/* EEF7BC 802426BC 4500000A */  bc1f      .L802426E8
/* EEF7C0 802426C0 00000000 */   nop
.L802426C4:
/* EEF7C4 802426C4 3C018024 */  lui       $at, %hi(D_802454A8_EF25A8)
/* EEF7C8 802426C8 D42254A8 */  ldc1      $f2, %lo(D_802454A8_EF25A8)($at)
/* EEF7CC 802426CC 46003187 */  neg.s     $f6, $f6
/* EEF7D0 802426D0 46003021 */  cvt.d.s   $f0, $f6
/* EEF7D4 802426D4 46220002 */  mul.d     $f0, $f0, $f2
/* EEF7D8 802426D8 00000000 */  nop
/* EEF7DC 802426DC 46202000 */  add.d     $f0, $f4, $f0
.L802426E0:
/* EEF7E0 802426E0 46200020 */  cvt.s.d   $f0, $f0
/* EEF7E4 802426E4 E600003C */  swc1      $f0, 0x3c($s0)
.L802426E8:
/* EEF7E8 802426E8 8602008E */  lh        $v0, 0x8e($s0)
/* EEF7EC 802426EC 9603008E */  lhu       $v1, 0x8e($s0)
/* EEF7F0 802426F0 18400003 */  blez      $v0, .L80242700
/* EEF7F4 802426F4 2462FFFF */   addiu    $v0, $v1, -1
/* EEF7F8 802426F8 080909C2 */  j         .L80242708
/* EEF7FC 802426FC A602008E */   sh       $v0, 0x8e($s0)
.L80242700:
/* EEF800 80242700 2402000C */  addiu     $v0, $zero, 0xc
/* EEF804 80242704 AE620070 */  sw        $v0, 0x70($s3)
.L80242708:
/* EEF808 80242708 8FBF0050 */  lw        $ra, 0x50($sp)
/* EEF80C 8024270C 8FB3004C */  lw        $s3, 0x4c($sp)
/* EEF810 80242710 8FB20048 */  lw        $s2, 0x48($sp)
/* EEF814 80242714 8FB10044 */  lw        $s1, 0x44($sp)
/* EEF818 80242718 8FB00040 */  lw        $s0, 0x40($sp)
/* EEF81C 8024271C 03E00008 */  jr        $ra
/* EEF820 80242720 27BD0058 */   addiu    $sp, $sp, 0x58
