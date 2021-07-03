.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80243BF8_A78468
.word L80240AB0_A75320, L80240ABC_A7532C, L80240ABC_A7532C, L80240ABC_A7532C, L80240ABC_A7532C, L80240ABC_A7532C, L80240ABC_A7532C, L80240ABC_A7532C, L80240AB0_A75320, L80240ABC_A7532C, L80240AB0_A75320, L80240ABC_A7532C, L80240AB0_A75320, L80240ABC_A7532C, L80240AB0_A75320, L80240ABC_A7532C, L80240ABC_A7532C, L80240ABC_A7532C, L80240AB0_A75320, L80240ABC_A7532C, L80240AB0_A75320, 0

.section .text

glabel func_802406A4_A74F14
/* A74F14 802406A4 27BDFF90 */  addiu     $sp, $sp, -0x70
/* A74F18 802406A8 AFB3005C */  sw        $s3, 0x5c($sp)
/* A74F1C 802406AC 0080982D */  daddu     $s3, $a0, $zero
/* A74F20 802406B0 AFBF0068 */  sw        $ra, 0x68($sp)
/* A74F24 802406B4 AFB50064 */  sw        $s5, 0x64($sp)
/* A74F28 802406B8 AFB40060 */  sw        $s4, 0x60($sp)
/* A74F2C 802406BC AFB20058 */  sw        $s2, 0x58($sp)
/* A74F30 802406C0 AFB10054 */  sw        $s1, 0x54($sp)
/* A74F34 802406C4 AFB00050 */  sw        $s0, 0x50($sp)
/* A74F38 802406C8 8E710148 */  lw        $s1, 0x148($s3)
/* A74F3C 802406CC 86240008 */  lh        $a0, 8($s1)
/* A74F40 802406D0 0C00EABB */  jal       get_npc_unsafe
/* A74F44 802406D4 00A0802D */   daddu    $s0, $a1, $zero
/* A74F48 802406D8 8E63000C */  lw        $v1, 0xc($s3)
/* A74F4C 802406DC 0260202D */  daddu     $a0, $s3, $zero
/* A74F50 802406E0 8C650000 */  lw        $a1, ($v1)
/* A74F54 802406E4 0C0B1EAF */  jal       get_variable
/* A74F58 802406E8 0040902D */   daddu    $s2, $v0, $zero
/* A74F5C 802406EC AFA00028 */  sw        $zero, 0x28($sp)
/* A74F60 802406F0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A74F64 802406F4 8C630030 */  lw        $v1, 0x30($v1)
/* A74F68 802406F8 AFA3002C */  sw        $v1, 0x2c($sp)
/* A74F6C 802406FC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A74F70 80240700 8C63001C */  lw        $v1, 0x1c($v1)
/* A74F74 80240704 AFA30030 */  sw        $v1, 0x30($sp)
/* A74F78 80240708 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A74F7C 8024070C 8C630024 */  lw        $v1, 0x24($v1)
/* A74F80 80240710 AFA30034 */  sw        $v1, 0x34($sp)
/* A74F84 80240714 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A74F88 80240718 8C630028 */  lw        $v1, 0x28($v1)
/* A74F8C 8024071C 27B50028 */  addiu     $s5, $sp, 0x28
/* A74F90 80240720 AFA30038 */  sw        $v1, 0x38($sp)
/* A74F94 80240724 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A74F98 80240728 3C0142C8 */  lui       $at, 0x42c8
/* A74F9C 8024072C 44810000 */  mtc1      $at, $f0
/* A74FA0 80240730 8C63002C */  lw        $v1, 0x2c($v1)
/* A74FA4 80240734 0040A02D */  daddu     $s4, $v0, $zero
/* A74FA8 80240738 E7A00040 */  swc1      $f0, 0x40($sp)
/* A74FAC 8024073C A7A00044 */  sh        $zero, 0x44($sp)
/* A74FB0 80240740 12000009 */  beqz      $s0, .L80240768
/* A74FB4 80240744 AFA3003C */   sw       $v1, 0x3c($sp)
/* A74FB8 80240748 864300A8 */  lh        $v1, 0xa8($s2)
/* A74FBC 8024074C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A74FC0 80240750 AE20008C */  sw        $zero, 0x8c($s1)
/* A74FC4 80240754 A22000B5 */  sb        $zero, 0xb5($s1)
/* A74FC8 80240758 34420008 */  ori       $v0, $v0, 8
/* A74FCC 8024075C AE230084 */  sw        $v1, 0x84($s1)
/* A74FD0 80240760 080901DE */  j         .L80240778
/* A74FD4 80240764 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240768:
/* A74FD8 80240768 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A74FDC 8024076C 30420004 */  andi      $v0, $v0, 4
/* A74FE0 80240770 10400047 */  beqz      $v0, .L80240890
/* A74FE4 80240774 00000000 */   nop
.L80240778:
/* A74FE8 80240778 AE600070 */  sw        $zero, 0x70($s3)
/* A74FEC 8024077C A640008E */  sh        $zero, 0x8e($s2)
/* A74FF0 80240780 8E2300CC */  lw        $v1, 0xcc($s1)
/* A74FF4 80240784 2404F7FF */  addiu     $a0, $zero, -0x801
/* A74FF8 80240788 A2200007 */  sb        $zero, 7($s1)
/* A74FFC 8024078C 8E420000 */  lw        $v0, ($s2)
/* A75000 80240790 8C630000 */  lw        $v1, ($v1)
/* A75004 80240794 00441024 */  and       $v0, $v0, $a0
/* A75008 80240798 AE420000 */  sw        $v0, ($s2)
/* A7500C 8024079C AE430028 */  sw        $v1, 0x28($s2)
/* A75010 802407A0 96220086 */  lhu       $v0, 0x86($s1)
/* A75014 802407A4 A64200A8 */  sh        $v0, 0xa8($s2)
/* A75018 802407A8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A7501C 802407AC AE200090 */  sw        $zero, 0x90($s1)
/* A75020 802407B0 8C420034 */  lw        $v0, 0x34($v0)
/* A75024 802407B4 14400006 */  bnez      $v0, .L802407D0
/* A75028 802407B8 2403FDFF */   addiu    $v1, $zero, -0x201
/* A7502C 802407BC 8E420000 */  lw        $v0, ($s2)
/* A75030 802407C0 2403FFF7 */  addiu     $v1, $zero, -9
/* A75034 802407C4 34420200 */  ori       $v0, $v0, 0x200
/* A75038 802407C8 080901F7 */  j         .L802407DC
/* A7503C 802407CC 00431024 */   and      $v0, $v0, $v1
.L802407D0:
/* A75040 802407D0 8E420000 */  lw        $v0, ($s2)
/* A75044 802407D4 00431024 */  and       $v0, $v0, $v1
/* A75048 802407D8 34420008 */  ori       $v0, $v0, 8
.L802407DC:
/* A7504C 802407DC AE420000 */  sw        $v0, ($s2)
/* A75050 802407E0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A75054 802407E4 30420004 */  andi      $v0, $v0, 4
/* A75058 802407E8 1040001E */  beqz      $v0, .L80240864
/* A7505C 802407EC 24040002 */   addiu    $a0, $zero, 2
/* A75060 802407F0 0240282D */  daddu     $a1, $s2, $zero
/* A75064 802407F4 0000302D */  daddu     $a2, $zero, $zero
/* A75068 802407F8 24020063 */  addiu     $v0, $zero, 0x63
/* A7506C 802407FC AE620070 */  sw        $v0, 0x70($s3)
/* A75070 80240800 AE600074 */  sw        $zero, 0x74($s3)
/* A75074 80240804 864300A8 */  lh        $v1, 0xa8($s2)
/* A75078 80240808 3C013F80 */  lui       $at, 0x3f80
/* A7507C 8024080C 44810000 */  mtc1      $at, $f0
/* A75080 80240810 3C014000 */  lui       $at, 0x4000
/* A75084 80240814 44811000 */  mtc1      $at, $f2
/* A75088 80240818 3C01C1A0 */  lui       $at, 0xc1a0
/* A7508C 8024081C 44812000 */  mtc1      $at, $f4
/* A75090 80240820 24020028 */  addiu     $v0, $zero, 0x28
/* A75094 80240824 AFA2001C */  sw        $v0, 0x1c($sp)
/* A75098 80240828 44833000 */  mtc1      $v1, $f6
/* A7509C 8024082C 00000000 */  nop
/* A750A0 80240830 468031A0 */  cvt.s.w   $f6, $f6
/* A750A4 80240834 44073000 */  mfc1      $a3, $f6
/* A750A8 80240838 27A20048 */  addiu     $v0, $sp, 0x48
/* A750AC 8024083C AFA20020 */  sw        $v0, 0x20($sp)
/* A750B0 80240840 E7A00010 */  swc1      $f0, 0x10($sp)
/* A750B4 80240844 E7A20014 */  swc1      $f2, 0x14($sp)
/* A750B8 80240848 0C01BFA4 */  jal       fx_emote
/* A750BC 8024084C E7A40018 */   swc1     $f4, 0x18($sp)
/* A750C0 80240850 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A750C4 80240854 2403FFFB */  addiu     $v1, $zero, -5
/* A750C8 80240858 00431024 */  and       $v0, $v0, $v1
/* A750CC 8024085C 08090224 */  j         .L80240890
/* A750D0 80240860 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240864:
/* A750D4 80240864 8E220000 */  lw        $v0, ($s1)
/* A750D8 80240868 3C034000 */  lui       $v1, 0x4000
/* A750DC 8024086C 00431024 */  and       $v0, $v0, $v1
/* A750E0 80240870 10400007 */  beqz      $v0, .L80240890
/* A750E4 80240874 3C03BFFF */   lui      $v1, 0xbfff
/* A750E8 80240878 2402000C */  addiu     $v0, $zero, 0xc
/* A750EC 8024087C AE620070 */  sw        $v0, 0x70($s3)
/* A750F0 80240880 8E220000 */  lw        $v0, ($s1)
/* A750F4 80240884 3463FFFF */  ori       $v1, $v1, 0xffff
/* A750F8 80240888 00431024 */  and       $v0, $v0, $v1
/* A750FC 8024088C AE220000 */  sw        $v0, ($s1)
.L80240890:
/* A75100 80240890 8E220090 */  lw        $v0, 0x90($s1)
/* A75104 80240894 1840000C */  blez      $v0, .L802408C8
/* A75108 80240898 2442FFFF */   addiu    $v0, $v0, -1
/* A7510C 8024089C 14400087 */  bnez      $v0, L80240ABC_A7532C
/* A75110 802408A0 AE220090 */   sw       $v0, 0x90($s1)
/* A75114 802408A4 3C03FFAA */  lui       $v1, 0xffaa
/* A75118 802408A8 8E420028 */  lw        $v0, 0x28($s2)
/* A7511C 802408AC 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* A75120 802408B0 00431021 */  addu      $v0, $v0, $v1
/* A75124 802408B4 2C420002 */  sltiu     $v0, $v0, 2
/* A75128 802408B8 10400003 */  beqz      $v0, .L802408C8
/* A7512C 802408BC 3C020055 */   lui      $v0, 0x55
/* A75130 802408C0 3442000C */  ori       $v0, $v0, 0xc
/* A75134 802408C4 AE420028 */  sw        $v0, 0x28($s2)
.L802408C8:
/* A75138 802408C8 8E630070 */  lw        $v1, 0x70($s3)
/* A7513C 802408CC 2402000C */  addiu     $v0, $zero, 0xc
/* A75140 802408D0 10620048 */  beq       $v1, $v0, .L802409F4
/* A75144 802408D4 2862000D */   slti     $v0, $v1, 0xd
/* A75148 802408D8 1040000F */  beqz      $v0, .L80240918
/* A7514C 802408DC 24100001 */   addiu    $s0, $zero, 1
/* A75150 802408E0 1070001E */  beq       $v1, $s0, .L8024095C
/* A75154 802408E4 28620002 */   slti     $v0, $v1, 2
/* A75158 802408E8 10400005 */  beqz      $v0, .L80240900
/* A7515C 802408EC 24020002 */   addiu    $v0, $zero, 2
/* A75160 802408F0 10600015 */  beqz      $v1, .L80240948
/* A75164 802408F4 0260202D */   daddu    $a0, $s3, $zero
/* A75168 802408F8 08090294 */  j         .L80240A50
/* A7516C 802408FC 00000000 */   nop
.L80240900:
/* A75170 80240900 1062001C */  beq       $v1, $v0, .L80240974
/* A75174 80240904 24020003 */   addiu    $v0, $zero, 3
/* A75178 80240908 10620035 */  beq       $v1, $v0, .L802409E0
/* A7517C 8024090C 0260202D */   daddu    $a0, $s3, $zero
/* A75180 80240910 08090294 */  j         .L80240A50
/* A75184 80240914 00000000 */   nop
.L80240918:
/* A75188 80240918 2402000E */  addiu     $v0, $zero, 0xe
/* A7518C 8024091C 1062003F */  beq       $v1, $v0, .L80240A1C
/* A75190 80240920 0062102A */   slt      $v0, $v1, $v0
/* A75194 80240924 14400038 */  bnez      $v0, .L80240A08
/* A75198 80240928 0260202D */   daddu    $a0, $s3, $zero
/* A7519C 8024092C 2402000F */  addiu     $v0, $zero, 0xf
/* A751A0 80240930 10620040 */  beq       $v1, $v0, .L80240A34
/* A751A4 80240934 24020063 */   addiu    $v0, $zero, 0x63
/* A751A8 80240938 10620043 */  beq       $v1, $v0, .L80240A48
/* A751AC 8024093C 00000000 */   nop
/* A751B0 80240940 08090294 */  j         .L80240A50
/* A751B4 80240944 00000000 */   nop
.L80240948:
/* A751B8 80240948 0280282D */  daddu     $a1, $s4, $zero
/* A751BC 8024094C 0C012568 */  jal       func_800495A0
/* A751C0 80240950 02A0302D */   daddu    $a2, $s5, $zero
/* A751C4 80240954 96220086 */  lhu       $v0, 0x86($s1)
/* A751C8 80240958 A64200A8 */  sh        $v0, 0xa8($s2)
.L8024095C:
/* A751CC 8024095C 0260202D */  daddu     $a0, $s3, $zero
/* A751D0 80240960 0280282D */  daddu     $a1, $s4, $zero
/* A751D4 80240964 0C0125AE */  jal       func_800496B8
/* A751D8 80240968 02A0302D */   daddu    $a2, $s5, $zero
/* A751DC 8024096C 08090294 */  j         .L80240A50
/* A751E0 80240970 00000000 */   nop
.L80240974:
/* A751E4 80240974 0260202D */  daddu     $a0, $s3, $zero
/* A751E8 80240978 0280282D */  daddu     $a1, $s4, $zero
/* A751EC 8024097C 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* A751F0 80240980 02A0302D */   daddu    $a2, $s5, $zero
/* A751F4 80240984 8E230088 */  lw        $v1, 0x88($s1)
/* A751F8 80240988 24020006 */  addiu     $v0, $zero, 6
/* A751FC 8024098C 14620014 */  bne       $v1, $v0, .L802409E0
/* A75200 80240990 0260202D */   daddu    $a0, $s3, $zero
/* A75204 80240994 0C00A67F */  jal       rand_int
/* A75208 80240998 24040064 */   addiu    $a0, $zero, 0x64
/* A7520C 8024099C 28420021 */  slti      $v0, $v0, 0x21
/* A75210 802409A0 5040000F */  beql      $v0, $zero, .L802409E0
/* A75214 802409A4 0260202D */   daddu    $a0, $s3, $zero
/* A75218 802409A8 8E22008C */  lw        $v0, 0x8c($s1)
/* A7521C 802409AC 10400005 */  beqz      $v0, .L802409C4
/* A75220 802409B0 3C020055 */   lui      $v0, 0x55
/* A75224 802409B4 3442002F */  ori       $v0, $v0, 0x2f
/* A75228 802409B8 AE20008C */  sw        $zero, 0x8c($s1)
/* A7522C 802409BC 08090274 */  j         .L802409D0
/* A75230 802409C0 A22000B5 */   sb       $zero, 0xb5($s1)
.L802409C4:
/* A75234 802409C4 3442002E */  ori       $v0, $v0, 0x2e
/* A75238 802409C8 AE30008C */  sw        $s0, 0x8c($s1)
/* A7523C 802409CC A23000B5 */  sb        $s0, 0xb5($s1)
.L802409D0:
/* A75240 802409D0 AE420028 */  sw        $v0, 0x28($s2)
/* A75244 802409D4 24020007 */  addiu     $v0, $zero, 7
/* A75248 802409D8 080902AF */  j         L80240ABC_A7532C
/* A7524C 802409DC AE220090 */   sw       $v0, 0x90($s1)
.L802409E0:
/* A75250 802409E0 0280282D */  daddu     $a1, $s4, $zero
/* A75254 802409E4 0C012701 */  jal       func_80049C04
/* A75258 802409E8 02A0302D */   daddu    $a2, $s5, $zero
/* A7525C 802409EC 08090294 */  j         .L80240A50
/* A75260 802409F0 00000000 */   nop
.L802409F4:
/* A75264 802409F4 0260202D */  daddu     $a0, $s3, $zero
/* A75268 802409F8 0280282D */  daddu     $a1, $s4, $zero
/* A7526C 802409FC 0C0900C4 */  jal       kpa_70_set_script_owner_npc_anim
/* A75270 80240A00 02A0302D */   daddu    $a2, $s5, $zero
/* A75274 80240A04 0260202D */  daddu     $a0, $s3, $zero
.L80240A08:
/* A75278 80240A08 0280282D */  daddu     $a1, $s4, $zero
/* A7527C 80240A0C 0C0900E3 */  jal       kpa_70_UnkDistFunc
/* A75280 80240A10 02A0302D */   daddu    $a2, $s5, $zero
/* A75284 80240A14 08090294 */  j         .L80240A50
/* A75288 80240A18 00000000 */   nop
.L80240A1C:
/* A7528C 80240A1C 0260202D */  daddu     $a0, $s3, $zero
/* A75290 80240A20 0280282D */  daddu     $a1, $s4, $zero
/* A75294 80240A24 0C090130 */  jal       kpa_70_UnkNpcAIFunc12
/* A75298 80240A28 02A0302D */   daddu    $a2, $s5, $zero
/* A7529C 80240A2C 08090294 */  j         .L80240A50
/* A752A0 80240A30 00000000 */   nop
.L80240A34:
/* A752A4 80240A34 0280282D */  daddu     $a1, $s4, $zero
/* A752A8 80240A38 0C090189 */  jal       kpa_70_set_script_owner_npc_col_height
/* A752AC 80240A3C 02A0302D */   daddu    $a2, $s5, $zero
/* A752B0 80240A40 08090294 */  j         .L80240A50
/* A752B4 80240A44 00000000 */   nop
.L80240A48:
/* A752B8 80240A48 0C0129CF */  jal       func_8004A73C
/* A752BC 80240A4C 0260202D */   daddu    $a0, $s3, $zero
.L80240A50:
/* A752C0 80240A50 8E230088 */  lw        $v1, 0x88($s1)
/* A752C4 80240A54 24020006 */  addiu     $v0, $zero, 6
/* A752C8 80240A58 14620019 */  bne       $v1, $v0, .L80240AC0
/* A752CC 80240A5C 0000102D */   daddu    $v0, $zero, $zero
/* A752D0 80240A60 8E22008C */  lw        $v0, 0x8c($s1)
/* A752D4 80240A64 10400003 */  beqz      $v0, .L80240A74
/* A752D8 80240A68 24020001 */   addiu    $v0, $zero, 1
/* A752DC 80240A6C 0809029E */  j         .L80240A78
/* A752E0 80240A70 A22200B5 */   sb       $v0, 0xb5($s1)
.L80240A74:
/* A752E4 80240A74 A22000B5 */  sb        $zero, 0xb5($s1)
.L80240A78:
/* A752E8 80240A78 8E22008C */  lw        $v0, 0x8c($s1)
/* A752EC 80240A7C 1040000F */  beqz      $v0, L80240ABC_A7532C
/* A752F0 80240A80 3C03FFAA */   lui      $v1, 0xffaa
/* A752F4 80240A84 8E420028 */  lw        $v0, 0x28($s2)
/* A752F8 80240A88 3463FFFC */  ori       $v1, $v1, 0xfffc
/* A752FC 80240A8C 00431821 */  addu      $v1, $v0, $v1
/* A75300 80240A90 2C620015 */  sltiu     $v0, $v1, 0x15
/* A75304 80240A94 10400009 */  beqz      $v0, L80240ABC_A7532C
/* A75308 80240A98 00031080 */   sll      $v0, $v1, 2
/* A7530C 80240A9C 3C018024 */  lui       $at, %hi(jtbl_80243BF8_A78468)
/* A75310 80240AA0 00220821 */  addu      $at, $at, $v0
/* A75314 80240AA4 8C223BF8 */  lw        $v0, %lo(jtbl_80243BF8_A78468)($at)
/* A75318 80240AA8 00400008 */  jr        $v0
/* A7531C 80240AAC 00000000 */   nop
glabel L80240AB0_A75320
/* A75320 80240AB0 8E420028 */  lw        $v0, 0x28($s2)
/* A75324 80240AB4 24420001 */  addiu     $v0, $v0, 1
/* A75328 80240AB8 AE420028 */  sw        $v0, 0x28($s2)
glabel L80240ABC_A7532C
/* A7532C 80240ABC 0000102D */  daddu     $v0, $zero, $zero
.L80240AC0:
/* A75330 80240AC0 8FBF0068 */  lw        $ra, 0x68($sp)
/* A75334 80240AC4 8FB50064 */  lw        $s5, 0x64($sp)
/* A75338 80240AC8 8FB40060 */  lw        $s4, 0x60($sp)
/* A7533C 80240ACC 8FB3005C */  lw        $s3, 0x5c($sp)
/* A75340 80240AD0 8FB20058 */  lw        $s2, 0x58($sp)
/* A75344 80240AD4 8FB10054 */  lw        $s1, 0x54($sp)
/* A75348 80240AD8 8FB00050 */  lw        $s0, 0x50($sp)
/* A7534C 80240ADC 03E00008 */  jr        $ra
/* A75350 80240AE0 27BD0070 */   addiu    $sp, $sp, 0x70
/* A75354 80240AE4 00000000 */  nop
/* A75358 80240AE8 00000000 */  nop
/* A7535C 80240AEC 00000000 */  nop
