.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E5530
/* 7E9E0 800E5530 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E9E4 800E5534 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E9E8 800E5538 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E9EC 800E553C 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 7E9F0 800E5540 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 7E9F4 800E5544 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 7E9F8 800E5548 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 7E9FC 800E554C 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 7EA00 800E5550 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 7EA04 800E5554 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EA08 800E5558 84640086 */  lh        $a0, 0x86($v1)
/* 7EA0C 800E555C 2402000B */  addiu     $v0, $zero, 0xb
/* 7EA10 800E5560 10820008 */  beq       $a0, $v0, .L800E5584
/* 7EA14 800E5564 24100001 */   addiu    $s0, $zero, 1
/* 7EA18 800E5568 2402000D */  addiu     $v0, $zero, 0xd
/* 7EA1C 800E556C 148200B5 */  bne       $a0, $v0, .L800E5844
/* 7EA20 800E5570 24020001 */   addiu    $v0, $zero, 1
/* 7EA24 800E5574 8462008C */  lh        $v0, 0x8c($v1)
/* 7EA28 800E5578 38420004 */  xori      $v0, $v0, 4
/* 7EA2C 800E557C 08039610 */  j         L800E5840_7ECF0
/* 7EA30 800E5580 0002802B */   sltu     $s0, $zero, $v0
.L800E5584:
/* 7EA34 800E5584 8463008C */  lh        $v1, 0x8c($v1)
/* 7EA38 800E5588 2C62000C */  sltiu     $v0, $v1, 0xc
/* 7EA3C 800E558C 104000AC */  beqz      $v0, L800E5840_7ECF0
/* 7EA40 800E5590 00031080 */   sll      $v0, $v1, 2
/* 7EA44 800E5594 3C018011 */  lui       $at, %hi(jtbl_8010BF00)
/* 7EA48 800E5598 00220821 */  addu      $at, $at, $v0
/* 7EA4C 800E559C 8C22BF00 */  lw        $v0, %lo(jtbl_8010BF00)($at)
/* 7EA50 800E55A0 00400008 */  jr        $v0
/* 7EA54 800E55A4 00000000 */   nop
glabel L800E55A8_7EA58
/* 7EA58 800E55A8 3C038011 */  lui       $v1, %hi(D_8010C9B0)
/* 7EA5C 800E55AC 2463C9B0 */  addiu     $v1, $v1, %lo(D_8010C9B0)
/* 7EA60 800E55B0 84620000 */  lh        $v0, ($v1)
/* 7EA64 800E55B4 1440000A */  bnez      $v0, .L800E55E0
/* 7EA68 800E55B8 00000000 */   nop
/* 7EA6C 800E55BC C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EA70 800E55C0 44800000 */  mtc1      $zero, $f0
/* 7EA74 800E55C4 00000000 */  nop
/* 7EA78 800E55C8 4600103E */  c.le.s    $f2, $f0
/* 7EA7C 800E55CC 00000000 */  nop
/* 7EA80 800E55D0 4500009A */  bc1f      L800E583C_7ECEC
/* 7EA84 800E55D4 24020001 */   addiu    $v0, $zero, 1
/* 7EA88 800E55D8 0803960F */  j         L800E583C_7ECEC
/* 7EA8C 800E55DC A4620000 */   sh       $v0, ($v1)
.L800E55E0:
/* 7EA90 800E55E0 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EA94 800E55E4 44800000 */  mtc1      $zero, $f0
/* 7EA98 800E55E8 080395E6 */  j         .L800E5798
/* 7EA9C 800E55EC 00000000 */   nop
glabel L800E55F0_7EAA0
/* 7EAA0 800E55F0 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EAA4 800E55F4 3C0141C8 */  lui       $at, 0x41c8
/* 7EAA8 800E55F8 44810000 */  mtc1      $at, $f0
/* 7EAAC 800E55FC 080395E6 */  j         .L800E5798
/* 7EAB0 800E5600 00000000 */   nop
glabel L800E5604_7EAB4
/* 7EAB4 800E5604 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EAB8 800E5608 3C014248 */  lui       $at, 0x4248
/* 7EABC 800E560C 44810000 */  mtc1      $at, $f0
/* 7EAC0 800E5610 080395E6 */  j         .L800E5798
/* 7EAC4 800E5614 00000000 */   nop
glabel L800E5618_7EAC8
/* 7EAC8 800E5618 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EACC 800E561C 3C01C3C3 */  lui       $at, 0xc3c3
/* 7EAD0 800E5620 44810000 */  mtc1      $at, $f0
/* 7EAD4 800E5624 00000000 */  nop
/* 7EAD8 800E5628 4602003C */  c.lt.s    $f0, $f2
/* 7EADC 800E562C 00000000 */  nop
/* 7EAE0 800E5630 45030083 */  bc1tl     L800E5840_7ECF0
/* 7EAE4 800E5634 0000802D */   daddu    $s0, $zero, $zero
/* 7EAE8 800E5638 3C01C3F7 */  lui       $at, 0xc3f7
/* 7EAEC 800E563C 34218000 */  ori       $at, $at, 0x8000
/* 7EAF0 800E5640 44810000 */  mtc1      $at, $f0
/* 7EAF4 800E5644 00000000 */  nop
/* 7EAF8 800E5648 4600103C */  c.lt.s    $f2, $f0
/* 7EAFC 800E564C 080395E8 */  j         .L800E57A0
/* 7EB00 800E5650 00000000 */   nop
glabel L800E5654_7EB04
/* 7EB04 800E5654 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EB08 800E5658 3C01C2B4 */  lui       $at, 0xc2b4
/* 7EB0C 800E565C 44810000 */  mtc1      $at, $f0
/* 7EB10 800E5660 00000000 */  nop
/* 7EB14 800E5664 4602003C */  c.lt.s    $f0, $f2
/* 7EB18 800E5668 00000000 */  nop
/* 7EB1C 800E566C 45030074 */  bc1tl     L800E5840_7ECF0
/* 7EB20 800E5670 0000802D */   daddu    $s0, $zero, $zero
/* 7EB24 800E5674 3C01C3B9 */  lui       $at, 0xc3b9
/* 7EB28 800E5678 44810000 */  mtc1      $at, $f0
/* 7EB2C 800E567C 00000000 */  nop
/* 7EB30 800E5680 4600103C */  c.lt.s    $f2, $f0
/* 7EB34 800E5684 080395E8 */  j         .L800E57A0
/* 7EB38 800E5688 00000000 */   nop
glabel L800E568C_7EB3C
/* 7EB3C 800E568C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7EB40 800E5690 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7EB44 800E5694 8442008E */  lh        $v0, 0x8e($v0)
/* 7EB48 800E5698 54400069 */  bnel      $v0, $zero, L800E5840_7ECF0
/* 7EB4C 800E569C 24100002 */   addiu    $s0, $zero, 2
/* 7EB50 800E56A0 3C038011 */  lui       $v1, %hi(D_8010C9B0)
/* 7EB54 800E56A4 2463C9B0 */  addiu     $v1, $v1, %lo(D_8010C9B0)
/* 7EB58 800E56A8 84620000 */  lh        $v0, ($v1)
/* 7EB5C 800E56AC 1440000A */  bnez      $v0, .L800E56D8
/* 7EB60 800E56B0 00000000 */   nop
/* 7EB64 800E56B4 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EB68 800E56B8 44800000 */  mtc1      $zero, $f0
/* 7EB6C 800E56BC 00000000 */  nop
/* 7EB70 800E56C0 4602003C */  c.lt.s    $f0, $f2
/* 7EB74 800E56C4 00000000 */  nop
/* 7EB78 800E56C8 4503005D */  bc1tl     L800E5840_7ECF0
/* 7EB7C 800E56CC 24100002 */   addiu    $s0, $zero, 2
/* 7EB80 800E56D0 24020001 */  addiu     $v0, $zero, 1
/* 7EB84 800E56D4 A4620000 */  sh        $v0, ($v1)
.L800E56D8:
/* 7EB88 800E56D8 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EB8C 800E56DC 44800000 */  mtc1      $zero, $f0
/* 7EB90 800E56E0 080395E6 */  j         .L800E5798
/* 7EB94 800E56E4 00000000 */   nop
glabel L800E56E8_7EB98
/* 7EB98 800E56E8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7EB9C 800E56EC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7EBA0 800E56F0 8442008E */  lh        $v0, 0x8e($v0)
/* 7EBA4 800E56F4 54400052 */  bnel      $v0, $zero, L800E5840_7ECF0
/* 7EBA8 800E56F8 24100002 */   addiu    $s0, $zero, 2
/* 7EBAC 800E56FC 3C038011 */  lui       $v1, %hi(D_8010C9B0)
/* 7EBB0 800E5700 2463C9B0 */  addiu     $v1, $v1, %lo(D_8010C9B0)
/* 7EBB4 800E5704 84620000 */  lh        $v0, ($v1)
/* 7EBB8 800E5708 1440000B */  bnez      $v0, .L800E5738
/* 7EBBC 800E570C 00000000 */   nop
/* 7EBC0 800E5710 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EBC4 800E5714 3C01C302 */  lui       $at, 0xc302
/* 7EBC8 800E5718 44810000 */  mtc1      $at, $f0
/* 7EBCC 800E571C 00000000 */  nop
/* 7EBD0 800E5720 4602003C */  c.lt.s    $f0, $f2
/* 7EBD4 800E5724 00000000 */  nop
/* 7EBD8 800E5728 45030045 */  bc1tl     L800E5840_7ECF0
/* 7EBDC 800E572C 24100002 */   addiu    $s0, $zero, 2
/* 7EBE0 800E5730 24020001 */  addiu     $v0, $zero, 1
/* 7EBE4 800E5734 A4620000 */  sh        $v0, ($v1)
.L800E5738:
/* 7EBE8 800E5738 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EBEC 800E573C 3C01C302 */  lui       $at, 0xc302
/* 7EBF0 800E5740 44810000 */  mtc1      $at, $f0
/* 7EBF4 800E5744 080395E6 */  j         .L800E5798
/* 7EBF8 800E5748 00000000 */   nop
glabel L800E574C_7EBFC
/* 7EBFC 800E574C 3C038011 */  lui       $v1, %hi(D_8010C9B0)
/* 7EC00 800E5750 2463C9B0 */  addiu     $v1, $v1, %lo(D_8010C9B0)
/* 7EC04 800E5754 84620000 */  lh        $v0, ($v1)
/* 7EC08 800E5758 1440000B */  bnez      $v0, .L800E5788
/* 7EC0C 800E575C 00000000 */   nop
/* 7EC10 800E5760 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EC14 800E5764 3C01C402 */  lui       $at, 0xc402
/* 7EC18 800E5768 44810000 */  mtc1      $at, $f0
/* 7EC1C 800E576C 00000000 */  nop
/* 7EC20 800E5770 4602003C */  c.lt.s    $f0, $f2
/* 7EC24 800E5774 00000000 */  nop
/* 7EC28 800E5778 45030031 */  bc1tl     L800E5840_7ECF0
/* 7EC2C 800E577C 24100002 */   addiu    $s0, $zero, 2
/* 7EC30 800E5780 24020001 */  addiu     $v0, $zero, 1
/* 7EC34 800E5784 A4620000 */  sh        $v0, ($v1)
.L800E5788:
/* 7EC38 800E5788 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EC3C 800E578C 3C01C402 */  lui       $at, 0xc402
/* 7EC40 800E5790 44810000 */  mtc1      $at, $f0
/* 7EC44 800E5794 00000000 */  nop
.L800E5798:
/* 7EC48 800E5798 4602003C */  c.lt.s    $f0, $f2
/* 7EC4C 800E579C 00000000 */  nop
.L800E57A0:
/* 7EC50 800E57A0 45000028 */  bc1f      .L800E5844
/* 7EC54 800E57A4 24020001 */   addiu    $v0, $zero, 1
/* 7EC58 800E57A8 08039611 */  j         .L800E5844
/* 7EC5C 800E57AC 0000802D */   daddu    $s0, $zero, $zero
glabel L800E57B0_7EC60
/* 7EC60 800E57B0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7EC64 800E57B4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7EC68 800E57B8 8442008E */  lh        $v0, 0x8e($v0)
/* 7EC6C 800E57BC 14400019 */  bnez      $v0, .L800E5824
/* 7EC70 800E57C0 0000202D */   daddu    $a0, $zero, $zero
/* 7EC74 800E57C4 3C038011 */  lui       $v1, %hi(D_8010C9B0)
/* 7EC78 800E57C8 2463C9B0 */  addiu     $v1, $v1, %lo(D_8010C9B0)
/* 7EC7C 800E57CC 84620000 */  lh        $v0, ($v1)
/* 7EC80 800E57D0 1440000B */  bnez      $v0, .L800E5800
/* 7EC84 800E57D4 00000000 */   nop
/* 7EC88 800E57D8 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7EC8C 800E57DC 3C01C402 */  lui       $at, 0xc402
/* 7EC90 800E57E0 44810000 */  mtc1      $at, $f0
/* 7EC94 800E57E4 00000000 */  nop
/* 7EC98 800E57E8 4602003C */  c.lt.s    $f0, $f2
/* 7EC9C 800E57EC 00000000 */  nop
/* 7ECA0 800E57F0 45030013 */  bc1tl     L800E5840_7ECF0
/* 7ECA4 800E57F4 24100002 */   addiu    $s0, $zero, 2
/* 7ECA8 800E57F8 24020001 */  addiu     $v0, $zero, 1
/* 7ECAC 800E57FC A4620000 */  sh        $v0, ($v1)
.L800E5800:
/* 7ECB0 800E5800 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 7ECB4 800E5804 3C01C402 */  lui       $at, 0xc402
/* 7ECB8 800E5808 44810000 */  mtc1      $at, $f0
/* 7ECBC 800E580C 00000000 */  nop
/* 7ECC0 800E5810 4602003C */  c.lt.s    $f0, $f2
/* 7ECC4 800E5814 00000000 */  nop
/* 7ECC8 800E5818 45030001 */  bc1tl     .L800E5820
/* 7ECCC 800E581C 0000802D */   daddu    $s0, $zero, $zero
.L800E5820:
/* 7ECD0 800E5820 0000202D */  daddu     $a0, $zero, $zero
.L800E5824:
/* 7ECD4 800E5824 3C05F5DE */  lui       $a1, 0xf5de
/* 7ECD8 800E5828 0C0B1EAF */  jal       get_variable
/* 7ECDC 800E582C 34A50180 */   ori      $a1, $a1, 0x180
/* 7ECE0 800E5830 2842FFC6 */  slti      $v0, $v0, -0x3a
/* 7ECE4 800E5834 14400003 */  bnez      $v0, .L800E5844
/* 7ECE8 800E5838 24020001 */   addiu    $v0, $zero, 1
glabel L800E583C_7ECEC
/* 7ECEC 800E583C 24100002 */  addiu     $s0, $zero, 2
glabel L800E5840_7ECF0
/* 7ECF0 800E5840 24020001 */  addiu     $v0, $zero, 1
.L800E5844:
/* 7ECF4 800E5844 16020014 */  bne       $s0, $v0, .L800E5898
/* 7ECF8 800E5848 00000000 */   nop
/* 7ECFC 800E584C 3C048016 */  lui       $a0, %hi(gCollisionStatus+0x2)
/* 7ED00 800E5850 8484A552 */  lh        $a0, %lo(gCollisionStatus+0x2)($a0)
/* 7ED04 800E5854 0C016F6A */  jal       get_collider_type_by_id
/* 7ED08 800E5858 00000000 */   nop
/* 7ED0C 800E585C 304200FF */  andi      $v0, $v0, 0xff
/* 7ED10 800E5860 24030003 */  addiu     $v1, $zero, 3
/* 7ED14 800E5864 14430007 */  bne       $v0, $v1, .L800E5884
/* 7ED18 800E5868 00000000 */   nop
/* 7ED1C 800E586C 3C03800B */  lui       $v1, %hi(gCameras)
/* 7ED20 800E5870 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 7ED24 800E5874 94620002 */  lhu       $v0, 2($v1)
/* 7ED28 800E5878 0000802D */  daddu     $s0, $zero, $zero
/* 7ED2C 800E587C 08039635 */  j         .L800E58D4
/* 7ED30 800E5880 34420001 */   ori      $v0, $v0, 1
.L800E5884:
/* 7ED34 800E5884 3C03800B */  lui       $v1, %hi(gCameras)
/* 7ED38 800E5888 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 7ED3C 800E588C 94620002 */  lhu       $v0, 2($v1)
/* 7ED40 800E5890 08039635 */  j         .L800E58D4
/* 7ED44 800E5894 3042FFFE */   andi     $v0, $v0, 0xfffe
.L800E5898:
/* 7ED48 800E5898 82220000 */  lb        $v0, ($s1)
/* 7ED4C 800E589C 10400009 */  beqz      $v0, .L800E58C4
/* 7ED50 800E58A0 24020004 */   addiu    $v0, $zero, 4
/* 7ED54 800E58A4 82230003 */  lb        $v1, 3($s1)
/* 7ED58 800E58A8 14620006 */  bne       $v1, $v0, .L800E58C4
/* 7ED5C 800E58AC 00000000 */   nop
/* 7ED60 800E58B0 3C03800B */  lui       $v1, %hi(gCameras)
/* 7ED64 800E58B4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 7ED68 800E58B8 94620002 */  lhu       $v0, 2($v1)
/* 7ED6C 800E58BC 08039635 */  j         .L800E58D4
/* 7ED70 800E58C0 34420002 */   ori      $v0, $v0, 2
.L800E58C4:
/* 7ED74 800E58C4 3C03800B */  lui       $v1, %hi(gCameras)
/* 7ED78 800E58C8 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 7ED7C 800E58CC 94620002 */  lhu       $v0, 2($v1)
/* 7ED80 800E58D0 3042FFFD */  andi      $v0, $v0, 0xfffd
.L800E58D4:
/* 7ED84 800E58D4 A4620002 */  sh        $v0, 2($v1)
/* 7ED88 800E58D8 0200102D */  daddu     $v0, $s0, $zero
/* 7ED8C 800E58DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7ED90 800E58E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ED94 800E58E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ED98 800E58E8 03E00008 */  jr        $ra
/* 7ED9C 800E58EC 27BD0020 */   addiu    $sp, $sp, 0x20
