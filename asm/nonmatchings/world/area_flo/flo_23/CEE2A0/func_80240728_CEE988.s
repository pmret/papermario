.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240728_CEE988
/* CEE988 80240728 27BDFF90 */  addiu     $sp, $sp, -0x70
/* CEE98C 8024072C AFB3005C */  sw        $s3, 0x5c($sp)
/* CEE990 80240730 0080982D */  daddu     $s3, $a0, $zero
/* CEE994 80240734 AFBF0068 */  sw        $ra, 0x68($sp)
/* CEE998 80240738 AFB50064 */  sw        $s5, 0x64($sp)
/* CEE99C 8024073C AFB40060 */  sw        $s4, 0x60($sp)
/* CEE9A0 80240740 AFB20058 */  sw        $s2, 0x58($sp)
/* CEE9A4 80240744 AFB10054 */  sw        $s1, 0x54($sp)
/* CEE9A8 80240748 AFB00050 */  sw        $s0, 0x50($sp)
/* CEE9AC 8024074C 8E710148 */  lw        $s1, 0x148($s3)
/* CEE9B0 80240750 86240008 */  lh        $a0, 8($s1)
/* CEE9B4 80240754 0C00EABB */  jal       get_npc_unsafe
/* CEE9B8 80240758 00A0802D */   daddu    $s0, $a1, $zero
/* CEE9BC 8024075C 8E63000C */  lw        $v1, 0xc($s3)
/* CEE9C0 80240760 0260202D */  daddu     $a0, $s3, $zero
/* CEE9C4 80240764 8C650000 */  lw        $a1, ($v1)
/* CEE9C8 80240768 0C0B1EAF */  jal       get_variable
/* CEE9CC 8024076C 0040902D */   daddu    $s2, $v0, $zero
/* CEE9D0 80240770 AFA00028 */  sw        $zero, 0x28($sp)
/* CEE9D4 80240774 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CEE9D8 80240778 8C630030 */  lw        $v1, 0x30($v1)
/* CEE9DC 8024077C AFA3002C */  sw        $v1, 0x2c($sp)
/* CEE9E0 80240780 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CEE9E4 80240784 8C63001C */  lw        $v1, 0x1c($v1)
/* CEE9E8 80240788 AFA30030 */  sw        $v1, 0x30($sp)
/* CEE9EC 8024078C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CEE9F0 80240790 8C630024 */  lw        $v1, 0x24($v1)
/* CEE9F4 80240794 AFA30034 */  sw        $v1, 0x34($sp)
/* CEE9F8 80240798 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CEE9FC 8024079C 8C630028 */  lw        $v1, 0x28($v1)
/* CEEA00 802407A0 27B50028 */  addiu     $s5, $sp, 0x28
/* CEEA04 802407A4 AFA30038 */  sw        $v1, 0x38($sp)
/* CEEA08 802407A8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CEEA0C 802407AC 3C0142C8 */  lui       $at, 0x42c8
/* CEEA10 802407B0 44810000 */  mtc1      $at, $f0
/* CEEA14 802407B4 8C63002C */  lw        $v1, 0x2c($v1)
/* CEEA18 802407B8 0040A02D */  daddu     $s4, $v0, $zero
/* CEEA1C 802407BC E7A00040 */  swc1      $f0, 0x40($sp)
/* CEEA20 802407C0 A7A00044 */  sh        $zero, 0x44($sp)
/* CEEA24 802407C4 12000009 */  beqz      $s0, .L802407EC
/* CEEA28 802407C8 AFA3003C */   sw       $v1, 0x3c($sp)
/* CEEA2C 802407CC 864300A8 */  lh        $v1, 0xa8($s2)
/* CEEA30 802407D0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CEEA34 802407D4 AE20008C */  sw        $zero, 0x8c($s1)
/* CEEA38 802407D8 A22000B5 */  sb        $zero, 0xb5($s1)
/* CEEA3C 802407DC 34420008 */  ori       $v0, $v0, 8
/* CEEA40 802407E0 AE230084 */  sw        $v1, 0x84($s1)
/* CEEA44 802407E4 080901FF */  j         .L802407FC
/* CEEA48 802407E8 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802407EC:
/* CEEA4C 802407EC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CEEA50 802407F0 30420004 */  andi      $v0, $v0, 4
/* CEEA54 802407F4 10400047 */  beqz      $v0, .L80240914
/* CEEA58 802407F8 00000000 */   nop
.L802407FC:
/* CEEA5C 802407FC AE600070 */  sw        $zero, 0x70($s3)
/* CEEA60 80240800 A640008E */  sh        $zero, 0x8e($s2)
/* CEEA64 80240804 8E2300CC */  lw        $v1, 0xcc($s1)
/* CEEA68 80240808 2404F7FF */  addiu     $a0, $zero, -0x801
/* CEEA6C 8024080C A2200007 */  sb        $zero, 7($s1)
/* CEEA70 80240810 8E420000 */  lw        $v0, ($s2)
/* CEEA74 80240814 8C630000 */  lw        $v1, ($v1)
/* CEEA78 80240818 00441024 */  and       $v0, $v0, $a0
/* CEEA7C 8024081C AE420000 */  sw        $v0, ($s2)
/* CEEA80 80240820 AE430028 */  sw        $v1, 0x28($s2)
/* CEEA84 80240824 96220086 */  lhu       $v0, 0x86($s1)
/* CEEA88 80240828 A64200A8 */  sh        $v0, 0xa8($s2)
/* CEEA8C 8024082C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CEEA90 80240830 AE200090 */  sw        $zero, 0x90($s1)
/* CEEA94 80240834 8C420034 */  lw        $v0, 0x34($v0)
/* CEEA98 80240838 14400006 */  bnez      $v0, .L80240854
/* CEEA9C 8024083C 2403FDFF */   addiu    $v1, $zero, -0x201
/* CEEAA0 80240840 8E420000 */  lw        $v0, ($s2)
/* CEEAA4 80240844 2403FFF7 */  addiu     $v1, $zero, -9
/* CEEAA8 80240848 34420200 */  ori       $v0, $v0, 0x200
/* CEEAAC 8024084C 08090218 */  j         .L80240860
/* CEEAB0 80240850 00431024 */   and      $v0, $v0, $v1
.L80240854:
/* CEEAB4 80240854 8E420000 */  lw        $v0, ($s2)
/* CEEAB8 80240858 00431024 */  and       $v0, $v0, $v1
/* CEEABC 8024085C 34420008 */  ori       $v0, $v0, 8
.L80240860:
/* CEEAC0 80240860 AE420000 */  sw        $v0, ($s2)
/* CEEAC4 80240864 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CEEAC8 80240868 30420004 */  andi      $v0, $v0, 4
/* CEEACC 8024086C 1040001E */  beqz      $v0, .L802408E8
/* CEEAD0 80240870 24040002 */   addiu    $a0, $zero, 2
/* CEEAD4 80240874 0240282D */  daddu     $a1, $s2, $zero
/* CEEAD8 80240878 0000302D */  daddu     $a2, $zero, $zero
/* CEEADC 8024087C 24020063 */  addiu     $v0, $zero, 0x63
/* CEEAE0 80240880 AE620070 */  sw        $v0, 0x70($s3)
/* CEEAE4 80240884 AE600074 */  sw        $zero, 0x74($s3)
/* CEEAE8 80240888 864300A8 */  lh        $v1, 0xa8($s2)
/* CEEAEC 8024088C 3C013F80 */  lui       $at, 0x3f80
/* CEEAF0 80240890 44810000 */  mtc1      $at, $f0
/* CEEAF4 80240894 3C014000 */  lui       $at, 0x4000
/* CEEAF8 80240898 44811000 */  mtc1      $at, $f2
/* CEEAFC 8024089C 3C01C1A0 */  lui       $at, 0xc1a0
/* CEEB00 802408A0 44812000 */  mtc1      $at, $f4
/* CEEB04 802408A4 24020028 */  addiu     $v0, $zero, 0x28
/* CEEB08 802408A8 AFA2001C */  sw        $v0, 0x1c($sp)
/* CEEB0C 802408AC 44833000 */  mtc1      $v1, $f6
/* CEEB10 802408B0 00000000 */  nop
/* CEEB14 802408B4 468031A0 */  cvt.s.w   $f6, $f6
/* CEEB18 802408B8 44073000 */  mfc1      $a3, $f6
/* CEEB1C 802408BC 27A20048 */  addiu     $v0, $sp, 0x48
/* CEEB20 802408C0 AFA20020 */  sw        $v0, 0x20($sp)
/* CEEB24 802408C4 E7A00010 */  swc1      $f0, 0x10($sp)
/* CEEB28 802408C8 E7A20014 */  swc1      $f2, 0x14($sp)
/* CEEB2C 802408CC 0C01BFA4 */  jal       fx_emote
/* CEEB30 802408D0 E7A40018 */   swc1     $f4, 0x18($sp)
/* CEEB34 802408D4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CEEB38 802408D8 2403FFFB */  addiu     $v1, $zero, -5
/* CEEB3C 802408DC 00431024 */  and       $v0, $v0, $v1
/* CEEB40 802408E0 08090245 */  j         .L80240914
/* CEEB44 802408E4 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802408E8:
/* CEEB48 802408E8 8E220000 */  lw        $v0, ($s1)
/* CEEB4C 802408EC 3C034000 */  lui       $v1, 0x4000
/* CEEB50 802408F0 00431024 */  and       $v0, $v0, $v1
/* CEEB54 802408F4 10400007 */  beqz      $v0, .L80240914
/* CEEB58 802408F8 3C03BFFF */   lui      $v1, 0xbfff
/* CEEB5C 802408FC 2402000C */  addiu     $v0, $zero, 0xc
/* CEEB60 80240900 AE620070 */  sw        $v0, 0x70($s3)
/* CEEB64 80240904 8E220000 */  lw        $v0, ($s1)
/* CEEB68 80240908 3463FFFF */  ori       $v1, $v1, 0xffff
/* CEEB6C 8024090C 00431024 */  and       $v0, $v0, $v1
/* CEEB70 80240910 AE220000 */  sw        $v0, ($s1)
.L80240914:
/* CEEB74 80240914 8E220090 */  lw        $v0, 0x90($s1)
/* CEEB78 80240918 1840000C */  blez      $v0, .L8024094C
/* CEEB7C 8024091C 2442FFFF */   addiu    $v0, $v0, -1
/* CEEB80 80240920 14400087 */  bnez      $v0, .L80240B40
/* CEEB84 80240924 AE220090 */   sw       $v0, 0x90($s1)
/* CEEB88 80240928 3C03FFAA */  lui       $v1, 0xffaa
/* CEEB8C 8024092C 8E420028 */  lw        $v0, 0x28($s2)
/* CEEB90 80240930 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* CEEB94 80240934 00431021 */  addu      $v0, $v0, $v1
/* CEEB98 80240938 2C420002 */  sltiu     $v0, $v0, 2
/* CEEB9C 8024093C 10400003 */  beqz      $v0, .L8024094C
/* CEEBA0 80240940 3C020055 */   lui      $v0, 0x55
/* CEEBA4 80240944 3442000C */  ori       $v0, $v0, 0xc
/* CEEBA8 80240948 AE420028 */  sw        $v0, 0x28($s2)
.L8024094C:
/* CEEBAC 8024094C 8E630070 */  lw        $v1, 0x70($s3)
/* CEEBB0 80240950 2402000C */  addiu     $v0, $zero, 0xc
/* CEEBB4 80240954 10620048 */  beq       $v1, $v0, .L80240A78
/* CEEBB8 80240958 2862000D */   slti     $v0, $v1, 0xd
/* CEEBBC 8024095C 1040000F */  beqz      $v0, .L8024099C
/* CEEBC0 80240960 24100001 */   addiu    $s0, $zero, 1
/* CEEBC4 80240964 1070001E */  beq       $v1, $s0, .L802409E0
/* CEEBC8 80240968 28620002 */   slti     $v0, $v1, 2
/* CEEBCC 8024096C 10400005 */  beqz      $v0, .L80240984
/* CEEBD0 80240970 24020002 */   addiu    $v0, $zero, 2
/* CEEBD4 80240974 10600015 */  beqz      $v1, .L802409CC
/* CEEBD8 80240978 0260202D */   daddu    $a0, $s3, $zero
/* CEEBDC 8024097C 080902B5 */  j         .L80240AD4
/* CEEBE0 80240980 00000000 */   nop
.L80240984:
/* CEEBE4 80240984 1062001C */  beq       $v1, $v0, .L802409F8
/* CEEBE8 80240988 24020003 */   addiu    $v0, $zero, 3
/* CEEBEC 8024098C 10620035 */  beq       $v1, $v0, .L80240A64
/* CEEBF0 80240990 0260202D */   daddu    $a0, $s3, $zero
/* CEEBF4 80240994 080902B5 */  j         .L80240AD4
/* CEEBF8 80240998 00000000 */   nop
.L8024099C:
/* CEEBFC 8024099C 2402000E */  addiu     $v0, $zero, 0xe
/* CEEC00 802409A0 1062003F */  beq       $v1, $v0, .L80240AA0
/* CEEC04 802409A4 0062102A */   slt      $v0, $v1, $v0
/* CEEC08 802409A8 14400038 */  bnez      $v0, .L80240A8C
/* CEEC0C 802409AC 0260202D */   daddu    $a0, $s3, $zero
/* CEEC10 802409B0 2402000F */  addiu     $v0, $zero, 0xf
/* CEEC14 802409B4 10620040 */  beq       $v1, $v0, .L80240AB8
/* CEEC18 802409B8 24020063 */   addiu    $v0, $zero, 0x63
/* CEEC1C 802409BC 10620043 */  beq       $v1, $v0, .L80240ACC
/* CEEC20 802409C0 00000000 */   nop
/* CEEC24 802409C4 080902B5 */  j         .L80240AD4
/* CEEC28 802409C8 00000000 */   nop
.L802409CC:
/* CEEC2C 802409CC 0280282D */  daddu     $a1, $s4, $zero
/* CEEC30 802409D0 0C012568 */  jal       func_800495A0
/* CEEC34 802409D4 02A0302D */   daddu    $a2, $s5, $zero
/* CEEC38 802409D8 96220086 */  lhu       $v0, 0x86($s1)
/* CEEC3C 802409DC A64200A8 */  sh        $v0, 0xa8($s2)
.L802409E0:
/* CEEC40 802409E0 0260202D */  daddu     $a0, $s3, $zero
/* CEEC44 802409E4 0280282D */  daddu     $a1, $s4, $zero
/* CEEC48 802409E8 0C0125AE */  jal       func_800496B8
/* CEEC4C 802409EC 02A0302D */   daddu    $a2, $s5, $zero
/* CEEC50 802409F0 080902B5 */  j         .L80240AD4
/* CEEC54 802409F4 00000000 */   nop
.L802409F8:
/* CEEC58 802409F8 0260202D */  daddu     $a0, $s3, $zero
/* CEEC5C 802409FC 0280282D */  daddu     $a1, $s4, $zero
/* CEEC60 80240A00 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* CEEC64 80240A04 02A0302D */   daddu    $a2, $s5, $zero
/* CEEC68 80240A08 8E230088 */  lw        $v1, 0x88($s1)
/* CEEC6C 80240A0C 24020006 */  addiu     $v0, $zero, 6
/* CEEC70 80240A10 14620014 */  bne       $v1, $v0, .L80240A64
/* CEEC74 80240A14 0260202D */   daddu    $a0, $s3, $zero
/* CEEC78 80240A18 0C00A67F */  jal       rand_int
/* CEEC7C 80240A1C 24040064 */   addiu    $a0, $zero, 0x64
/* CEEC80 80240A20 28420021 */  slti      $v0, $v0, 0x21
/* CEEC84 80240A24 5040000F */  beql      $v0, $zero, .L80240A64
/* CEEC88 80240A28 0260202D */   daddu    $a0, $s3, $zero
/* CEEC8C 80240A2C 8E22008C */  lw        $v0, 0x8c($s1)
/* CEEC90 80240A30 10400005 */  beqz      $v0, .L80240A48
/* CEEC94 80240A34 3C020055 */   lui      $v0, 0x55
/* CEEC98 80240A38 3442002F */  ori       $v0, $v0, 0x2f
/* CEEC9C 80240A3C AE20008C */  sw        $zero, 0x8c($s1)
/* CEECA0 80240A40 08090295 */  j         .L80240A54
/* CEECA4 80240A44 A22000B5 */   sb       $zero, 0xb5($s1)
.L80240A48:
/* CEECA8 80240A48 3442002E */  ori       $v0, $v0, 0x2e
/* CEECAC 80240A4C AE30008C */  sw        $s0, 0x8c($s1)
/* CEECB0 80240A50 A23000B5 */  sb        $s0, 0xb5($s1)
.L80240A54:
/* CEECB4 80240A54 AE420028 */  sw        $v0, 0x28($s2)
/* CEECB8 80240A58 24020007 */  addiu     $v0, $zero, 7
/* CEECBC 80240A5C 080902D0 */  j         .L80240B40
/* CEECC0 80240A60 AE220090 */   sw       $v0, 0x90($s1)
.L80240A64:
/* CEECC4 80240A64 0280282D */  daddu     $a1, $s4, $zero
/* CEECC8 80240A68 0C012701 */  jal       func_80049C04
/* CEECCC 80240A6C 02A0302D */   daddu    $a2, $s5, $zero
/* CEECD0 80240A70 080902B5 */  j         .L80240AD4
/* CEECD4 80240A74 00000000 */   nop
.L80240A78:
/* CEECD8 80240A78 0260202D */  daddu     $a0, $s3, $zero
/* CEECDC 80240A7C 0280282D */  daddu     $a1, $s4, $zero
/* CEECE0 80240A80 0C0900E5 */  jal       func_80240394_CEE5F4
/* CEECE4 80240A84 02A0302D */   daddu    $a2, $s5, $zero
/* CEECE8 80240A88 0260202D */  daddu     $a0, $s3, $zero
.L80240A8C:
/* CEECEC 80240A8C 0280282D */  daddu     $a1, $s4, $zero
/* CEECF0 80240A90 0C090104 */  jal       func_80240410_CEE670
/* CEECF4 80240A94 02A0302D */   daddu    $a2, $s5, $zero
/* CEECF8 80240A98 080902B5 */  j         .L80240AD4
/* CEECFC 80240A9C 00000000 */   nop
.L80240AA0:
/* CEED00 80240AA0 0260202D */  daddu     $a0, $s3, $zero
/* CEED04 80240AA4 0280282D */  daddu     $a1, $s4, $zero
/* CEED08 80240AA8 0C090151 */  jal       func_80240544_CEE7A4
/* CEED0C 80240AAC 02A0302D */   daddu    $a2, $s5, $zero
/* CEED10 80240AB0 080902B5 */  j         .L80240AD4
/* CEED14 80240AB4 00000000 */   nop
.L80240AB8:
/* CEED18 80240AB8 0280282D */  daddu     $a1, $s4, $zero
/* CEED1C 80240ABC 0C0901AA */  jal       func_802406A8_CEE908
/* CEED20 80240AC0 02A0302D */   daddu    $a2, $s5, $zero
/* CEED24 80240AC4 080902B5 */  j         .L80240AD4
/* CEED28 80240AC8 00000000 */   nop
.L80240ACC:
/* CEED2C 80240ACC 0C0129CF */  jal       func_8004A73C
/* CEED30 80240AD0 0260202D */   daddu    $a0, $s3, $zero
.L80240AD4:
/* CEED34 80240AD4 8E230088 */  lw        $v1, 0x88($s1)
/* CEED38 80240AD8 24020006 */  addiu     $v0, $zero, 6
/* CEED3C 80240ADC 14620019 */  bne       $v1, $v0, .L80240B44
/* CEED40 80240AE0 0000102D */   daddu    $v0, $zero, $zero
/* CEED44 80240AE4 8E22008C */  lw        $v0, 0x8c($s1)
/* CEED48 80240AE8 10400003 */  beqz      $v0, .L80240AF8
/* CEED4C 80240AEC 24020001 */   addiu    $v0, $zero, 1
/* CEED50 80240AF0 080902BF */  j         .L80240AFC
/* CEED54 80240AF4 A22200B5 */   sb       $v0, 0xb5($s1)
.L80240AF8:
/* CEED58 80240AF8 A22000B5 */  sb        $zero, 0xb5($s1)
.L80240AFC:
/* CEED5C 80240AFC 8E22008C */  lw        $v0, 0x8c($s1)
/* CEED60 80240B00 1040000F */  beqz      $v0, .L80240B40
/* CEED64 80240B04 3C03FFAA */   lui      $v1, 0xffaa
/* CEED68 80240B08 8E420028 */  lw        $v0, 0x28($s2)
/* CEED6C 80240B0C 3463FFFC */  ori       $v1, $v1, 0xfffc
/* CEED70 80240B10 00431821 */  addu      $v1, $v0, $v1
/* CEED74 80240B14 2C620015 */  sltiu     $v0, $v1, 0x15
/* CEED78 80240B18 10400009 */  beqz      $v0, .L80240B40
/* CEED7C 80240B1C 00031080 */   sll      $v0, $v1, 2
/* CEED80 80240B20 3C018024 */  lui       $at, %hi(D_80242688)
/* CEED84 80240B24 00220821 */  addu      $at, $at, $v0
/* CEED88 80240B28 8C222688 */  lw        $v0, %lo(D_80242688)($at)
/* CEED8C 80240B2C 00400008 */  jr        $v0
/* CEED90 80240B30 00000000 */   nop
/* CEED94 80240B34 8E420028 */  lw        $v0, 0x28($s2)
/* CEED98 80240B38 24420001 */  addiu     $v0, $v0, 1
/* CEED9C 80240B3C AE420028 */  sw        $v0, 0x28($s2)
.L80240B40:
/* CEEDA0 80240B40 0000102D */  daddu     $v0, $zero, $zero
.L80240B44:
/* CEEDA4 80240B44 8FBF0068 */  lw        $ra, 0x68($sp)
/* CEEDA8 80240B48 8FB50064 */  lw        $s5, 0x64($sp)
/* CEEDAC 80240B4C 8FB40060 */  lw        $s4, 0x60($sp)
/* CEEDB0 80240B50 8FB3005C */  lw        $s3, 0x5c($sp)
/* CEEDB4 80240B54 8FB20058 */  lw        $s2, 0x58($sp)
/* CEEDB8 80240B58 8FB10054 */  lw        $s1, 0x54($sp)
/* CEEDBC 80240B5C 8FB00050 */  lw        $s0, 0x50($sp)
/* CEEDC0 80240B60 03E00008 */  jr        $ra
/* CEEDC4 80240B64 27BD0070 */   addiu    $sp, $sp, 0x70
