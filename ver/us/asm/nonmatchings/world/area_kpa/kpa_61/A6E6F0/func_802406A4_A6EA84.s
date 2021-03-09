.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A4_A6EA84
/* A6EA84 802406A4 27BDFF90 */  addiu     $sp, $sp, -0x70
/* A6EA88 802406A8 AFB3005C */  sw        $s3, 0x5c($sp)
/* A6EA8C 802406AC 0080982D */  daddu     $s3, $a0, $zero
/* A6EA90 802406B0 AFBF0068 */  sw        $ra, 0x68($sp)
/* A6EA94 802406B4 AFB50064 */  sw        $s5, 0x64($sp)
/* A6EA98 802406B8 AFB40060 */  sw        $s4, 0x60($sp)
/* A6EA9C 802406BC AFB20058 */  sw        $s2, 0x58($sp)
/* A6EAA0 802406C0 AFB10054 */  sw        $s1, 0x54($sp)
/* A6EAA4 802406C4 AFB00050 */  sw        $s0, 0x50($sp)
/* A6EAA8 802406C8 8E710148 */  lw        $s1, 0x148($s3)
/* A6EAAC 802406CC 86240008 */  lh        $a0, 8($s1)
/* A6EAB0 802406D0 0C00EABB */  jal       get_npc_unsafe
/* A6EAB4 802406D4 00A0802D */   daddu    $s0, $a1, $zero
/* A6EAB8 802406D8 8E63000C */  lw        $v1, 0xc($s3)
/* A6EABC 802406DC 0260202D */  daddu     $a0, $s3, $zero
/* A6EAC0 802406E0 8C650000 */  lw        $a1, ($v1)
/* A6EAC4 802406E4 0C0B1EAF */  jal       get_variable
/* A6EAC8 802406E8 0040902D */   daddu    $s2, $v0, $zero
/* A6EACC 802406EC AFA00028 */  sw        $zero, 0x28($sp)
/* A6EAD0 802406F0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A6EAD4 802406F4 8C630030 */  lw        $v1, 0x30($v1)
/* A6EAD8 802406F8 AFA3002C */  sw        $v1, 0x2c($sp)
/* A6EADC 802406FC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A6EAE0 80240700 8C63001C */  lw        $v1, 0x1c($v1)
/* A6EAE4 80240704 AFA30030 */  sw        $v1, 0x30($sp)
/* A6EAE8 80240708 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A6EAEC 8024070C 8C630024 */  lw        $v1, 0x24($v1)
/* A6EAF0 80240710 AFA30034 */  sw        $v1, 0x34($sp)
/* A6EAF4 80240714 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A6EAF8 80240718 8C630028 */  lw        $v1, 0x28($v1)
/* A6EAFC 8024071C 27B50028 */  addiu     $s5, $sp, 0x28
/* A6EB00 80240720 AFA30038 */  sw        $v1, 0x38($sp)
/* A6EB04 80240724 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A6EB08 80240728 3C0142C8 */  lui       $at, 0x42c8
/* A6EB0C 8024072C 44810000 */  mtc1      $at, $f0
/* A6EB10 80240730 8C63002C */  lw        $v1, 0x2c($v1)
/* A6EB14 80240734 0040A02D */  daddu     $s4, $v0, $zero
/* A6EB18 80240738 E7A00040 */  swc1      $f0, 0x40($sp)
/* A6EB1C 8024073C A7A00044 */  sh        $zero, 0x44($sp)
/* A6EB20 80240740 12000009 */  beqz      $s0, .L80240768
/* A6EB24 80240744 AFA3003C */   sw       $v1, 0x3c($sp)
/* A6EB28 80240748 864300A8 */  lh        $v1, 0xa8($s2)
/* A6EB2C 8024074C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A6EB30 80240750 AE20008C */  sw        $zero, 0x8c($s1)
/* A6EB34 80240754 A22000B5 */  sb        $zero, 0xb5($s1)
/* A6EB38 80240758 34420008 */  ori       $v0, $v0, 8
/* A6EB3C 8024075C AE230084 */  sw        $v1, 0x84($s1)
/* A6EB40 80240760 080901DE */  j         .L80240778
/* A6EB44 80240764 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240768:
/* A6EB48 80240768 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A6EB4C 8024076C 30420004 */  andi      $v0, $v0, 4
/* A6EB50 80240770 10400047 */  beqz      $v0, .L80240890
/* A6EB54 80240774 00000000 */   nop
.L80240778:
/* A6EB58 80240778 AE600070 */  sw        $zero, 0x70($s3)
/* A6EB5C 8024077C A640008E */  sh        $zero, 0x8e($s2)
/* A6EB60 80240780 8E2300CC */  lw        $v1, 0xcc($s1)
/* A6EB64 80240784 2404F7FF */  addiu     $a0, $zero, -0x801
/* A6EB68 80240788 A2200007 */  sb        $zero, 7($s1)
/* A6EB6C 8024078C 8E420000 */  lw        $v0, ($s2)
/* A6EB70 80240790 8C630000 */  lw        $v1, ($v1)
/* A6EB74 80240794 00441024 */  and       $v0, $v0, $a0
/* A6EB78 80240798 AE420000 */  sw        $v0, ($s2)
/* A6EB7C 8024079C AE430028 */  sw        $v1, 0x28($s2)
/* A6EB80 802407A0 96220086 */  lhu       $v0, 0x86($s1)
/* A6EB84 802407A4 A64200A8 */  sh        $v0, 0xa8($s2)
/* A6EB88 802407A8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A6EB8C 802407AC AE200090 */  sw        $zero, 0x90($s1)
/* A6EB90 802407B0 8C420034 */  lw        $v0, 0x34($v0)
/* A6EB94 802407B4 14400006 */  bnez      $v0, .L802407D0
/* A6EB98 802407B8 2403FDFF */   addiu    $v1, $zero, -0x201
/* A6EB9C 802407BC 8E420000 */  lw        $v0, ($s2)
/* A6EBA0 802407C0 2403FFF7 */  addiu     $v1, $zero, -9
/* A6EBA4 802407C4 34420200 */  ori       $v0, $v0, 0x200
/* A6EBA8 802407C8 080901F7 */  j         .L802407DC
/* A6EBAC 802407CC 00431024 */   and      $v0, $v0, $v1
.L802407D0:
/* A6EBB0 802407D0 8E420000 */  lw        $v0, ($s2)
/* A6EBB4 802407D4 00431024 */  and       $v0, $v0, $v1
/* A6EBB8 802407D8 34420008 */  ori       $v0, $v0, 8
.L802407DC:
/* A6EBBC 802407DC AE420000 */  sw        $v0, ($s2)
/* A6EBC0 802407E0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A6EBC4 802407E4 30420004 */  andi      $v0, $v0, 4
/* A6EBC8 802407E8 1040001E */  beqz      $v0, .L80240864
/* A6EBCC 802407EC 24040002 */   addiu    $a0, $zero, 2
/* A6EBD0 802407F0 0240282D */  daddu     $a1, $s2, $zero
/* A6EBD4 802407F4 0000302D */  daddu     $a2, $zero, $zero
/* A6EBD8 802407F8 24020063 */  addiu     $v0, $zero, 0x63
/* A6EBDC 802407FC AE620070 */  sw        $v0, 0x70($s3)
/* A6EBE0 80240800 AE600074 */  sw        $zero, 0x74($s3)
/* A6EBE4 80240804 864300A8 */  lh        $v1, 0xa8($s2)
/* A6EBE8 80240808 3C013F80 */  lui       $at, 0x3f80
/* A6EBEC 8024080C 44810000 */  mtc1      $at, $f0
/* A6EBF0 80240810 3C014000 */  lui       $at, 0x4000
/* A6EBF4 80240814 44811000 */  mtc1      $at, $f2
/* A6EBF8 80240818 3C01C1A0 */  lui       $at, 0xc1a0
/* A6EBFC 8024081C 44812000 */  mtc1      $at, $f4
/* A6EC00 80240820 24020028 */  addiu     $v0, $zero, 0x28
/* A6EC04 80240824 AFA2001C */  sw        $v0, 0x1c($sp)
/* A6EC08 80240828 44833000 */  mtc1      $v1, $f6
/* A6EC0C 8024082C 00000000 */  nop
/* A6EC10 80240830 468031A0 */  cvt.s.w   $f6, $f6
/* A6EC14 80240834 44073000 */  mfc1      $a3, $f6
/* A6EC18 80240838 27A20048 */  addiu     $v0, $sp, 0x48
/* A6EC1C 8024083C AFA20020 */  sw        $v0, 0x20($sp)
/* A6EC20 80240840 E7A00010 */  swc1      $f0, 0x10($sp)
/* A6EC24 80240844 E7A20014 */  swc1      $f2, 0x14($sp)
/* A6EC28 80240848 0C01BFA4 */  jal       fx_emote
/* A6EC2C 8024084C E7A40018 */   swc1     $f4, 0x18($sp)
/* A6EC30 80240850 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A6EC34 80240854 2403FFFB */  addiu     $v1, $zero, -5
/* A6EC38 80240858 00431024 */  and       $v0, $v0, $v1
/* A6EC3C 8024085C 08090224 */  j         .L80240890
/* A6EC40 80240860 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240864:
/* A6EC44 80240864 8E220000 */  lw        $v0, ($s1)
/* A6EC48 80240868 3C034000 */  lui       $v1, 0x4000
/* A6EC4C 8024086C 00431024 */  and       $v0, $v0, $v1
/* A6EC50 80240870 10400007 */  beqz      $v0, .L80240890
/* A6EC54 80240874 3C03BFFF */   lui      $v1, 0xbfff
/* A6EC58 80240878 2402000C */  addiu     $v0, $zero, 0xc
/* A6EC5C 8024087C AE620070 */  sw        $v0, 0x70($s3)
/* A6EC60 80240880 8E220000 */  lw        $v0, ($s1)
/* A6EC64 80240884 3463FFFF */  ori       $v1, $v1, 0xffff
/* A6EC68 80240888 00431024 */  and       $v0, $v0, $v1
/* A6EC6C 8024088C AE220000 */  sw        $v0, ($s1)
.L80240890:
/* A6EC70 80240890 8E220090 */  lw        $v0, 0x90($s1)
/* A6EC74 80240894 1840000C */  blez      $v0, .L802408C8
/* A6EC78 80240898 2442FFFF */   addiu    $v0, $v0, -1
/* A6EC7C 8024089C 14400087 */  bnez      $v0, L80240ABC_A6EE9C
/* A6EC80 802408A0 AE220090 */   sw       $v0, 0x90($s1)
/* A6EC84 802408A4 3C03FFAA */  lui       $v1, 0xffaa
/* A6EC88 802408A8 8E420028 */  lw        $v0, 0x28($s2)
/* A6EC8C 802408AC 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* A6EC90 802408B0 00431021 */  addu      $v0, $v0, $v1
/* A6EC94 802408B4 2C420002 */  sltiu     $v0, $v0, 2
/* A6EC98 802408B8 10400003 */  beqz      $v0, .L802408C8
/* A6EC9C 802408BC 3C020055 */   lui      $v0, 0x55
/* A6ECA0 802408C0 3442000C */  ori       $v0, $v0, 0xc
/* A6ECA4 802408C4 AE420028 */  sw        $v0, 0x28($s2)
.L802408C8:
/* A6ECA8 802408C8 8E630070 */  lw        $v1, 0x70($s3)
/* A6ECAC 802408CC 2402000C */  addiu     $v0, $zero, 0xc
/* A6ECB0 802408D0 10620048 */  beq       $v1, $v0, .L802409F4
/* A6ECB4 802408D4 2862000D */   slti     $v0, $v1, 0xd
/* A6ECB8 802408D8 1040000F */  beqz      $v0, .L80240918
/* A6ECBC 802408DC 24100001 */   addiu    $s0, $zero, 1
/* A6ECC0 802408E0 1070001E */  beq       $v1, $s0, .L8024095C
/* A6ECC4 802408E4 28620002 */   slti     $v0, $v1, 2
/* A6ECC8 802408E8 10400005 */  beqz      $v0, .L80240900
/* A6ECCC 802408EC 24020002 */   addiu    $v0, $zero, 2
/* A6ECD0 802408F0 10600015 */  beqz      $v1, .L80240948
/* A6ECD4 802408F4 0260202D */   daddu    $a0, $s3, $zero
/* A6ECD8 802408F8 08090294 */  j         .L80240A50
/* A6ECDC 802408FC 00000000 */   nop
.L80240900:
/* A6ECE0 80240900 1062001C */  beq       $v1, $v0, .L80240974
/* A6ECE4 80240904 24020003 */   addiu    $v0, $zero, 3
/* A6ECE8 80240908 10620035 */  beq       $v1, $v0, .L802409E0
/* A6ECEC 8024090C 0260202D */   daddu    $a0, $s3, $zero
/* A6ECF0 80240910 08090294 */  j         .L80240A50
/* A6ECF4 80240914 00000000 */   nop
.L80240918:
/* A6ECF8 80240918 2402000E */  addiu     $v0, $zero, 0xe
/* A6ECFC 8024091C 1062003F */  beq       $v1, $v0, .L80240A1C
/* A6ED00 80240920 0062102A */   slt      $v0, $v1, $v0
/* A6ED04 80240924 14400038 */  bnez      $v0, .L80240A08
/* A6ED08 80240928 0260202D */   daddu    $a0, $s3, $zero
/* A6ED0C 8024092C 2402000F */  addiu     $v0, $zero, 0xf
/* A6ED10 80240930 10620040 */  beq       $v1, $v0, .L80240A34
/* A6ED14 80240934 24020063 */   addiu    $v0, $zero, 0x63
/* A6ED18 80240938 10620043 */  beq       $v1, $v0, .L80240A48
/* A6ED1C 8024093C 00000000 */   nop
/* A6ED20 80240940 08090294 */  j         .L80240A50
/* A6ED24 80240944 00000000 */   nop
.L80240948:
/* A6ED28 80240948 0280282D */  daddu     $a1, $s4, $zero
/* A6ED2C 8024094C 0C012568 */  jal       func_800495A0
/* A6ED30 80240950 02A0302D */   daddu    $a2, $s5, $zero
/* A6ED34 80240954 96220086 */  lhu       $v0, 0x86($s1)
/* A6ED38 80240958 A64200A8 */  sh        $v0, 0xa8($s2)
.L8024095C:
/* A6ED3C 8024095C 0260202D */  daddu     $a0, $s3, $zero
/* A6ED40 80240960 0280282D */  daddu     $a1, $s4, $zero
/* A6ED44 80240964 0C0125AE */  jal       func_800496B8
/* A6ED48 80240968 02A0302D */   daddu    $a2, $s5, $zero
/* A6ED4C 8024096C 08090294 */  j         .L80240A50
/* A6ED50 80240970 00000000 */   nop
.L80240974:
/* A6ED54 80240974 0260202D */  daddu     $a0, $s3, $zero
/* A6ED58 80240978 0280282D */  daddu     $a1, $s4, $zero
/* A6ED5C 8024097C 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* A6ED60 80240980 02A0302D */   daddu    $a2, $s5, $zero
/* A6ED64 80240984 8E230088 */  lw        $v1, 0x88($s1)
/* A6ED68 80240988 24020006 */  addiu     $v0, $zero, 6
/* A6ED6C 8024098C 14620014 */  bne       $v1, $v0, .L802409E0
/* A6ED70 80240990 0260202D */   daddu    $a0, $s3, $zero
/* A6ED74 80240994 0C00A67F */  jal       rand_int
/* A6ED78 80240998 24040064 */   addiu    $a0, $zero, 0x64
/* A6ED7C 8024099C 28420021 */  slti      $v0, $v0, 0x21
/* A6ED80 802409A0 5040000F */  beql      $v0, $zero, .L802409E0
/* A6ED84 802409A4 0260202D */   daddu    $a0, $s3, $zero
/* A6ED88 802409A8 8E22008C */  lw        $v0, 0x8c($s1)
/* A6ED8C 802409AC 10400005 */  beqz      $v0, .L802409C4
/* A6ED90 802409B0 3C020055 */   lui      $v0, 0x55
/* A6ED94 802409B4 3442002F */  ori       $v0, $v0, 0x2f
/* A6ED98 802409B8 AE20008C */  sw        $zero, 0x8c($s1)
/* A6ED9C 802409BC 08090274 */  j         .L802409D0
/* A6EDA0 802409C0 A22000B5 */   sb       $zero, 0xb5($s1)
.L802409C4:
/* A6EDA4 802409C4 3442002E */  ori       $v0, $v0, 0x2e
/* A6EDA8 802409C8 AE30008C */  sw        $s0, 0x8c($s1)
/* A6EDAC 802409CC A23000B5 */  sb        $s0, 0xb5($s1)
.L802409D0:
/* A6EDB0 802409D0 AE420028 */  sw        $v0, 0x28($s2)
/* A6EDB4 802409D4 24020007 */  addiu     $v0, $zero, 7
/* A6EDB8 802409D8 080902AF */  j         L80240ABC_A6EE9C
/* A6EDBC 802409DC AE220090 */   sw       $v0, 0x90($s1)
.L802409E0:
/* A6EDC0 802409E0 0280282D */  daddu     $a1, $s4, $zero
/* A6EDC4 802409E4 0C012701 */  jal       func_80049C04
/* A6EDC8 802409E8 02A0302D */   daddu    $a2, $s5, $zero
/* A6EDCC 802409EC 08090294 */  j         .L80240A50
/* A6EDD0 802409F0 00000000 */   nop
.L802409F4:
/* A6EDD4 802409F4 0260202D */  daddu     $a0, $s3, $zero
/* A6EDD8 802409F8 0280282D */  daddu     $a1, $s4, $zero
/* A6EDDC 802409FC 0C0900C4 */  jal       kpa_61_set_script_owner_npc_anim
/* A6EDE0 80240A00 02A0302D */   daddu    $a2, $s5, $zero
/* A6EDE4 80240A04 0260202D */  daddu     $a0, $s3, $zero
.L80240A08:
/* A6EDE8 80240A08 0280282D */  daddu     $a1, $s4, $zero
/* A6EDEC 80240A0C 0C0900E3 */  jal       func_8024038C_A6E76C
/* A6EDF0 80240A10 02A0302D */   daddu    $a2, $s5, $zero
/* A6EDF4 80240A14 08090294 */  j         .L80240A50
/* A6EDF8 80240A18 00000000 */   nop
.L80240A1C:
/* A6EDFC 80240A1C 0260202D */  daddu     $a0, $s3, $zero
/* A6EE00 80240A20 0280282D */  daddu     $a1, $s4, $zero
/* A6EE04 80240A24 0C090130 */  jal       kpa_61_UnkNpcAIFunc12
/* A6EE08 80240A28 02A0302D */   daddu    $a2, $s5, $zero
/* A6EE0C 80240A2C 08090294 */  j         .L80240A50
/* A6EE10 80240A30 00000000 */   nop
.L80240A34:
/* A6EE14 80240A34 0280282D */  daddu     $a1, $s4, $zero
/* A6EE18 80240A38 0C090189 */  jal       kpa_61_set_script_owner_npc_col_height
/* A6EE1C 80240A3C 02A0302D */   daddu    $a2, $s5, $zero
/* A6EE20 80240A40 08090294 */  j         .L80240A50
/* A6EE24 80240A44 00000000 */   nop
.L80240A48:
/* A6EE28 80240A48 0C0129CF */  jal       func_8004A73C
/* A6EE2C 80240A4C 0260202D */   daddu    $a0, $s3, $zero
.L80240A50:
/* A6EE30 80240A50 8E230088 */  lw        $v1, 0x88($s1)
/* A6EE34 80240A54 24020006 */  addiu     $v0, $zero, 6
/* A6EE38 80240A58 14620019 */  bne       $v1, $v0, .L80240AC0
/* A6EE3C 80240A5C 0000102D */   daddu    $v0, $zero, $zero
/* A6EE40 80240A60 8E22008C */  lw        $v0, 0x8c($s1)
/* A6EE44 80240A64 10400003 */  beqz      $v0, .L80240A74
/* A6EE48 80240A68 24020001 */   addiu    $v0, $zero, 1
/* A6EE4C 80240A6C 0809029E */  j         .L80240A78
/* A6EE50 80240A70 A22200B5 */   sb       $v0, 0xb5($s1)
.L80240A74:
/* A6EE54 80240A74 A22000B5 */  sb        $zero, 0xb5($s1)
.L80240A78:
/* A6EE58 80240A78 8E22008C */  lw        $v0, 0x8c($s1)
/* A6EE5C 80240A7C 1040000F */  beqz      $v0, L80240ABC_A6EE9C
/* A6EE60 80240A80 3C03FFAA */   lui      $v1, 0xffaa
/* A6EE64 80240A84 8E420028 */  lw        $v0, 0x28($s2)
/* A6EE68 80240A88 3463FFFC */  ori       $v1, $v1, 0xfffc
/* A6EE6C 80240A8C 00431821 */  addu      $v1, $v0, $v1
/* A6EE70 80240A90 2C620015 */  sltiu     $v0, $v1, 0x15
/* A6EE74 80240A94 10400009 */  beqz      $v0, L80240ABC_A6EE9C
/* A6EE78 80240A98 00031080 */   sll      $v0, $v1, 2
/* A6EE7C 80240A9C 3C018024 */  lui       $at, %hi(jtbl_80243CD8_A720B8)
/* A6EE80 80240AA0 00220821 */  addu      $at, $at, $v0
/* A6EE84 80240AA4 8C223CD8 */  lw        $v0, %lo(jtbl_80243CD8_A720B8)($at)
/* A6EE88 80240AA8 00400008 */  jr        $v0
/* A6EE8C 80240AAC 00000000 */   nop
glabel L80240AB0_A6EE90
/* A6EE90 80240AB0 8E420028 */  lw        $v0, 0x28($s2)
/* A6EE94 80240AB4 24420001 */  addiu     $v0, $v0, 1
/* A6EE98 80240AB8 AE420028 */  sw        $v0, 0x28($s2)
glabel L80240ABC_A6EE9C
/* A6EE9C 80240ABC 0000102D */  daddu     $v0, $zero, $zero
.L80240AC0:
/* A6EEA0 80240AC0 8FBF0068 */  lw        $ra, 0x68($sp)
/* A6EEA4 80240AC4 8FB50064 */  lw        $s5, 0x64($sp)
/* A6EEA8 80240AC8 8FB40060 */  lw        $s4, 0x60($sp)
/* A6EEAC 80240ACC 8FB3005C */  lw        $s3, 0x5c($sp)
/* A6EEB0 80240AD0 8FB20058 */  lw        $s2, 0x58($sp)
/* A6EEB4 80240AD4 8FB10054 */  lw        $s1, 0x54($sp)
/* A6EEB8 80240AD8 8FB00050 */  lw        $s0, 0x50($sp)
/* A6EEBC 80240ADC 03E00008 */  jr        $ra
/* A6EEC0 80240AE0 27BD0070 */   addiu    $sp, $sp, 0x70
