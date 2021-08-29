.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024204C_8028CC
/* 8028CC 8024204C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8028D0 80242050 AFB10024 */  sw        $s1, 0x24($sp)
/* 8028D4 80242054 0080882D */  daddu     $s1, $a0, $zero
/* 8028D8 80242058 3C05F840 */  lui       $a1, 0xf840
/* 8028DC 8024205C AFBF0044 */  sw        $ra, 0x44($sp)
/* 8028E0 80242060 AFBE0040 */  sw        $fp, 0x40($sp)
/* 8028E4 80242064 AFB7003C */  sw        $s7, 0x3c($sp)
/* 8028E8 80242068 AFB60038 */  sw        $s6, 0x38($sp)
/* 8028EC 8024206C AFB50034 */  sw        $s5, 0x34($sp)
/* 8028F0 80242070 AFB40030 */  sw        $s4, 0x30($sp)
/* 8028F4 80242074 AFB3002C */  sw        $s3, 0x2c($sp)
/* 8028F8 80242078 AFB20028 */  sw        $s2, 0x28($sp)
/* 8028FC 8024207C AFB00020 */  sw        $s0, 0x20($sp)
/* 802900 80242080 8E3E0148 */  lw        $fp, 0x148($s1)
/* 802904 80242084 0C0B1EAF */  jal       evt_get_variable
/* 802908 80242088 34A56268 */   ori      $a1, $a1, 0x6268
/* 80290C 8024208C 0040802D */  daddu     $s0, $v0, $zero
/* 802910 80242090 0220202D */  daddu     $a0, $s1, $zero
/* 802914 80242094 3C05F840 */  lui       $a1, 0xf840
/* 802918 80242098 0C0B1EAF */  jal       evt_get_variable
/* 80291C 8024209C 34A56269 */   ori      $a1, $a1, 0x6269
/* 802920 802420A0 0040B82D */  daddu     $s7, $v0, $zero
/* 802924 802420A4 0220202D */  daddu     $a0, $s1, $zero
/* 802928 802420A8 3C05F5DE */  lui       $a1, 0xf5de
/* 80292C 802420AC 0C0B1EAF */  jal       evt_get_variable
/* 802930 802420B0 34A502DE */   ori      $a1, $a1, 0x2de
/* 802934 802420B4 0040B02D */  daddu     $s6, $v0, $zero
/* 802938 802420B8 0220202D */  daddu     $a0, $s1, $zero
/* 80293C 802420BC 3C05F5DE */  lui       $a1, 0xf5de
/* 802940 802420C0 0C0B1EAF */  jal       evt_get_variable
/* 802944 802420C4 34A502DF */   ori      $a1, $a1, 0x2df
/* 802948 802420C8 0040A82D */  daddu     $s5, $v0, $zero
/* 80294C 802420CC 93D3006D */  lbu       $s3, 0x6d($fp)
/* 802950 802420D0 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 802954 802420D4 A7B30010 */  sh        $s3, 0x10($sp)
/* 802958 802420D8 93D2006E */  lbu       $s2, 0x6e($fp)
/* 80295C 802420DC 93C7006F */  lbu       $a3, 0x6f($fp)
/* 802960 802420E0 3274FFFF */  andi      $s4, $s3, 0xffff
/* 802964 802420E4 12820003 */  beq       $s4, $v0, .L802420F4
/* 802968 802420E8 A7A7001E */   sh       $a3, 0x1e($sp)
/* 80296C 802420EC 0000B82D */  daddu     $s7, $zero, $zero
/* 802970 802420F0 02E0802D */  daddu     $s0, $s7, $zero
.L802420F4:
/* 802974 802420F4 3202FFFF */  andi      $v0, $s0, 0xffff
/* 802978 802420F8 14400016 */  bnez      $v0, .L80242154
/* 80297C 802420FC 0220202D */   daddu    $a0, $s1, $zero
/* 802980 80242100 0C00A67F */  jal       rand_int
/* 802984 80242104 24040064 */   addiu    $a0, $zero, 0x64
/* 802988 80242108 2842001E */  slti      $v0, $v0, 0x1e
/* 80298C 8024210C 10400011 */  beqz      $v0, .L80242154
/* 802990 80242110 0220202D */   daddu    $a0, $s1, $zero
/* 802994 80242114 0C00A67F */  jal       rand_int
/* 802998 80242118 2644FFFF */   addiu    $a0, $s2, -1
/* 80299C 8024211C 0040A82D */  daddu     $s5, $v0, $zero
/* 8029A0 80242120 0260B02D */  daddu     $s6, $s3, $zero
/* 8029A4 80242124 0220202D */  daddu     $a0, $s1, $zero
/* 8029A8 80242128 3C05F5DE */  lui       $a1, 0xf5de
/* 8029AC 8024212C 34A502DE */  ori       $a1, $a1, 0x2de
/* 8029B0 80242130 0C0B2026 */  jal       evt_set_variable
/* 8029B4 80242134 0280302D */   daddu    $a2, $s4, $zero
/* 8029B8 80242138 0220202D */  daddu     $a0, $s1, $zero
/* 8029BC 8024213C 3C05F5DE */  lui       $a1, 0xf5de
/* 8029C0 80242140 34A502DF */  ori       $a1, $a1, 0x2df
/* 8029C4 80242144 0C0B2026 */  jal       evt_set_variable
/* 8029C8 80242148 32A6FFFF */   andi     $a2, $s5, 0xffff
/* 8029CC 8024214C 24100001 */  addiu     $s0, $zero, 1
/* 8029D0 80242150 0220202D */  daddu     $a0, $s1, $zero
.L80242154:
/* 8029D4 80242154 3C05F840 */  lui       $a1, 0xf840
/* 8029D8 80242158 34A56268 */  ori       $a1, $a1, 0x6268
/* 8029DC 8024215C 0C0B2026 */  jal       evt_set_variable
/* 8029E0 80242160 3206FFFF */   andi     $a2, $s0, 0xffff
/* 8029E4 80242164 0220202D */  daddu     $a0, $s1, $zero
/* 8029E8 80242168 3C05F840 */  lui       $a1, 0xf840
/* 8029EC 8024216C 34A56269 */  ori       $a1, $a1, 0x6269
/* 8029F0 80242170 0C0B2026 */  jal       evt_set_variable
/* 8029F4 80242174 32E6FFFF */   andi     $a2, $s7, 0xffff
/* 8029F8 80242178 0000202D */  daddu     $a0, $zero, $zero
/* 8029FC 8024217C 3C05F5DE */  lui       $a1, 0xf5de
/* 802A00 80242180 0C0B1EAF */  jal       evt_get_variable
/* 802A04 80242184 34A502E0 */   ori      $a1, $a1, 0x2e0
/* 802A08 80242188 0000202D */  daddu     $a0, $zero, $zero
/* 802A0C 8024218C 3C05F5DE */  lui       $a1, 0xf5de
/* 802A10 80242190 34A50180 */  ori       $a1, $a1, 0x180
/* 802A14 80242194 0C0B1EAF */  jal       evt_get_variable
/* 802A18 80242198 0040802D */   daddu    $s0, $v0, $zero
/* 802A1C 8024219C 0040282D */  daddu     $a1, $v0, $zero
/* 802A20 802421A0 0000182D */  daddu     $v1, $zero, $zero
/* 802A24 802421A4 3C068025 */  lui       $a2, %hi(D_80248CD4_809554)
/* 802A28 802421A8 24C68CD4 */  addiu     $a2, $a2, %lo(D_80248CD4_809554)
/* 802A2C 802421AC 00C0202D */  daddu     $a0, $a2, $zero
.L802421B0:
/* 802A30 802421B0 8C820000 */  lw        $v0, ($a0)
/* 802A34 802421B4 00A2102A */  slt       $v0, $a1, $v0
/* 802A38 802421B8 14400006 */  bnez      $v0, .L802421D4
/* 802A3C 802421BC 000310C0 */   sll      $v0, $v1, 3
/* 802A40 802421C0 24630001 */  addiu     $v1, $v1, 1
/* 802A44 802421C4 28620008 */  slti      $v0, $v1, 8
/* 802A48 802421C8 1440FFF9 */  bnez      $v0, .L802421B0
/* 802A4C 802421CC 24840008 */   addiu    $a0, $a0, 8
/* 802A50 802421D0 000310C0 */  sll       $v0, $v1, 3
.L802421D4:
/* 802A54 802421D4 00461021 */  addu      $v0, $v0, $a2
/* 802A58 802421D8 8C420004 */  lw        $v0, 4($v0)
/* 802A5C 802421DC 97A30010 */  lhu       $v1, 0x10($sp)
/* 802A60 802421E0 0202202A */  slt       $a0, $s0, $v0
/* 802A64 802421E4 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 802A68 802421E8 14620008 */  bne       $v1, $v0, .L8024220C
/* 802A6C 802421EC 32A2FFFF */   andi     $v0, $s5, 0xffff
/* 802A70 802421F0 97A7001E */  lhu       $a3, 0x1e($sp)
/* 802A74 802421F4 14E20005 */  bne       $a3, $v0, .L8024220C
/* 802A78 802421F8 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 802A7C 802421FC 14400003 */  bnez      $v0, .L8024220C
/* 802A80 80242200 00000000 */   nop
/* 802A84 80242204 14800008 */  bnez      $a0, .L80242228
/* 802A88 80242208 24020001 */   addiu    $v0, $zero, 1
.L8024220C:
/* 802A8C 8024220C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 802A90 80242210 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 802A94 80242214 80420075 */  lb        $v0, 0x75($v0)
/* 802A98 80242218 10400005 */  beqz      $v0, .L80242230
/* 802A9C 8024221C 00000000 */   nop
/* 802AA0 80242220 10800003 */  beqz      $a0, .L80242230
/* 802AA4 80242224 24020001 */   addiu    $v0, $zero, 1
.L80242228:
/* 802AA8 80242228 0809088F */  j         .L8024223C
/* 802AAC 8024222C AE220084 */   sw       $v0, 0x84($s1)
.L80242230:
/* 802AB0 80242230 0C00F9EB */  jal       kill_enemy
/* 802AB4 80242234 03C0202D */   daddu    $a0, $fp, $zero
/* 802AB8 80242238 AE200084 */  sw        $zero, 0x84($s1)
.L8024223C:
/* 802ABC 8024223C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 802AC0 80242240 8FBE0040 */  lw        $fp, 0x40($sp)
/* 802AC4 80242244 8FB7003C */  lw        $s7, 0x3c($sp)
/* 802AC8 80242248 8FB60038 */  lw        $s6, 0x38($sp)
/* 802ACC 8024224C 8FB50034 */  lw        $s5, 0x34($sp)
/* 802AD0 80242250 8FB40030 */  lw        $s4, 0x30($sp)
/* 802AD4 80242254 8FB3002C */  lw        $s3, 0x2c($sp)
/* 802AD8 80242258 8FB20028 */  lw        $s2, 0x28($sp)
/* 802ADC 8024225C 8FB10024 */  lw        $s1, 0x24($sp)
/* 802AE0 80242260 8FB00020 */  lw        $s0, 0x20($sp)
/* 802AE4 80242264 24020002 */  addiu     $v0, $zero, 2
/* 802AE8 80242268 03E00008 */  jr        $ra
/* 802AEC 8024226C 27BD0048 */   addiu    $sp, $sp, 0x48
