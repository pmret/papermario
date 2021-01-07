.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240078_DCCD48
/* DCCD48 80240078 27BDFF90 */  addiu     $sp, $sp, -0x70
/* DCCD4C 8024007C AFB00048 */  sw        $s0, 0x48($sp)
/* DCCD50 80240080 0080802D */  daddu     $s0, $a0, $zero
/* DCCD54 80240084 2404FFFC */  addiu     $a0, $zero, -4
/* DCCD58 80240088 AFBF006C */  sw        $ra, 0x6c($sp)
/* DCCD5C 8024008C AFBE0068 */  sw        $fp, 0x68($sp)
/* DCCD60 80240090 AFB70064 */  sw        $s7, 0x64($sp)
/* DCCD64 80240094 AFB60060 */  sw        $s6, 0x60($sp)
/* DCCD68 80240098 AFB5005C */  sw        $s5, 0x5c($sp)
/* DCCD6C 8024009C AFB40058 */  sw        $s4, 0x58($sp)
/* DCCD70 802400A0 AFB30054 */  sw        $s3, 0x54($sp)
/* DCCD74 802400A4 AFB20050 */  sw        $s2, 0x50($sp)
/* DCCD78 802400A8 0C00EABB */  jal       get_npc_unsafe
/* DCCD7C 802400AC AFB1004C */   sw       $s1, 0x4c($sp)
/* DCCD80 802400B0 3C158011 */  lui       $s5, %hi(gPlayerStatus)
/* DCCD84 802400B4 26B5EFC8 */  addiu     $s5, $s5, %lo(gPlayerStatus)
/* DCCD88 802400B8 0040982D */  daddu     $s3, $v0, $zero
/* DCCD8C 802400BC 3C148011 */  lui       $s4, %hi(D_8010EBB0)
/* DCCD90 802400C0 2694EBB0 */  addiu     $s4, $s4, %lo(D_8010EBB0)
/* DCCD94 802400C4 0C090000 */  jal       func_80240000_DCCCD0
/* DCCD98 802400C8 AE000084 */   sw       $zero, 0x84($s0)
/* DCCD9C 802400CC 14400073 */  bnez      $v0, .L8024029C
/* DCCDA0 802400D0 24020002 */   addiu    $v0, $zero, 2
/* DCCDA4 802400D4 82830003 */  lb        $v1, 3($s4)
/* DCCDA8 802400D8 24020009 */  addiu     $v0, $zero, 9
/* DCCDAC 802400DC 14620039 */  bne       $v1, $v0, .L802401C4
/* DCCDB0 802400E0 24020008 */   addiu    $v0, $zero, 8
/* DCCDB4 802400E4 82820000 */  lb        $v0, ($s4)
/* DCCDB8 802400E8 10400035 */  beqz      $v0, .L802401C0
/* DCCDBC 802400EC 24020080 */   addiu    $v0, $zero, 0x80
/* DCCDC0 802400F0 92A3000E */  lbu       $v1, 0xe($s5)
/* DCCDC4 802400F4 14620031 */  bne       $v1, $v0, .L802401BC
/* DCCDC8 802400F8 02A0202D */   daddu    $a0, $s5, $zero
/* DCCDCC 802400FC 27A20034 */  addiu     $v0, $sp, 0x34
/* DCCDD0 80240100 27A50028 */  addiu     $a1, $sp, 0x28
/* DCCDD4 80240104 27A6002C */  addiu     $a2, $sp, 0x2c
/* DCCDD8 80240108 C6A00028 */  lwc1      $f0, 0x28($s5)
/* DCCDDC 8024010C C6A2002C */  lwc1      $f2, 0x2c($s5)
/* DCCDE0 80240110 C6A40030 */  lwc1      $f4, 0x30($s5)
/* DCCDE4 80240114 3C01447A */  lui       $at, 0x447a
/* DCCDE8 80240118 44813000 */  mtc1      $at, $f6
/* DCCDEC 8024011C 27A70030 */  addiu     $a3, $sp, 0x30
/* DCCDF0 80240120 E7A00028 */  swc1      $f0, 0x28($sp)
/* DCCDF4 80240124 E7A2002C */  swc1      $f2, 0x2c($sp)
/* DCCDF8 80240128 E7A40030 */  swc1      $f4, 0x30($sp)
/* DCCDFC 8024012C E7A60034 */  swc1      $f6, 0x34($sp)
/* DCCE00 80240130 AFA20010 */  sw        $v0, 0x10($sp)
/* DCCE04 80240134 27A20038 */  addiu     $v0, $sp, 0x38
/* DCCE08 80240138 AFA20014 */  sw        $v0, 0x14($sp)
/* DCCE0C 8024013C 27A2003C */  addiu     $v0, $sp, 0x3c
/* DCCE10 80240140 AFA20018 */  sw        $v0, 0x18($sp)
/* DCCE14 80240144 27A20040 */  addiu     $v0, $sp, 0x40
/* DCCE18 80240148 AFA2001C */  sw        $v0, 0x1c($sp)
/* DCCE1C 8024014C 27A20044 */  addiu     $v0, $sp, 0x44
/* DCCE20 80240150 0C03791B */  jal       func_800DE46C
/* DCCE24 80240154 AFA20020 */   sw       $v0, 0x20($sp)
/* DCCE28 80240158 0040402D */  daddu     $t0, $v0, $zero
/* DCCE2C 8024015C 0000302D */  daddu     $a2, $zero, $zero
/* DCCE30 80240160 24050004 */  addiu     $a1, $zero, 4
/* DCCE34 80240164 3C078024 */  lui       $a3, %hi(D_80243A90)
/* DCCE38 80240168 24E73A90 */  addiu     $a3, $a3, %lo(D_80243A90)
/* DCCE3C 8024016C 00E0202D */  daddu     $a0, $a3, $zero
/* DCCE40 80240170 3C038024 */  lui       $v1, %hi(D_80243A80)
/* DCCE44 80240174 24633A80 */  addiu     $v1, $v1, %lo(D_80243A80)
.L80240178:
/* DCCE48 80240178 8C620000 */  lw        $v0, ($v1)
/* DCCE4C 8024017C 55020007 */  bnel      $t0, $v0, .L8024019C
/* DCCE50 80240180 24A50008 */   addiu    $a1, $a1, 8
/* DCCE54 80240184 C4800000 */  lwc1      $f0, ($a0)
/* DCCE58 80240188 00A71021 */  addu      $v0, $a1, $a3
/* DCCE5C 8024018C E6A0001C */  swc1      $f0, 0x1c($s5)
/* DCCE60 80240190 C4400000 */  lwc1      $f0, ($v0)
/* DCCE64 80240194 E6A00024 */  swc1      $f0, 0x24($s5)
/* DCCE68 80240198 24A50008 */  addiu     $a1, $a1, 8
.L8024019C:
/* DCCE6C 8024019C 24840008 */  addiu     $a0, $a0, 8
/* DCCE70 802401A0 24C60001 */  addiu     $a2, $a2, 1
/* DCCE74 802401A4 2CC20004 */  sltiu     $v0, $a2, 4
/* DCCE78 802401A8 1440FFF3 */  bnez      $v0, .L80240178
/* DCCE7C 802401AC 24630004 */   addiu    $v1, $v1, 4
/* DCCE80 802401B0 24020001 */  addiu     $v0, $zero, 1
/* DCCE84 802401B4 080900A6 */  j         .L80240298
/* DCCE88 802401B8 AE020084 */   sw       $v0, 0x84($s0)
.L802401BC:
/* DCCE8C 802401BC 82830003 */  lb        $v1, 3($s4)
.L802401C0:
/* DCCE90 802401C0 24020008 */  addiu     $v0, $zero, 8
.L802401C4:
/* DCCE94 802401C4 14620004 */  bne       $v1, $v0, .L802401D8
/* DCCE98 802401C8 00000000 */   nop      
/* DCCE9C 802401CC 82820000 */  lb        $v0, ($s4)
/* DCCEA0 802401D0 14400032 */  bnez      $v0, .L8024029C
/* DCCEA4 802401D4 24020002 */   addiu    $v0, $zero, 2
.L802401D8:
/* DCCEA8 802401D8 3C178016 */  lui       $s7, %hi(gCollisionStatus)
/* DCCEAC 802401DC 26F7A550 */  addiu     $s7, $s7, %lo(gCollisionStatus)
/* DCCEB0 802401E0 24120004 */  addiu     $s2, $zero, 4
/* DCCEB4 802401E4 3C168024 */  lui       $s6, %hi(D_80243A90)
/* DCCEB8 802401E8 26D63A90 */  addiu     $s6, $s6, %lo(D_80243A90)
/* DCCEBC 802401EC 02C0802D */  daddu     $s0, $s6, $zero
/* DCCEC0 802401F0 3C118024 */  lui       $s1, %hi(D_80243A80)
/* DCCEC4 802401F4 26313A80 */  addiu     $s1, $s1, %lo(D_80243A80)
/* DCCEC8 802401F8 261E0020 */  addiu     $fp, $s0, 0x20
.L802401FC:
/* DCCECC 802401FC 86E20002 */  lh        $v0, 2($s7)
/* DCCED0 80240200 8E230000 */  lw        $v1, ($s1)
/* DCCED4 80240204 10430004 */  beq       $v0, $v1, .L80240218
/* DCCED8 80240208 00000000 */   nop      
/* DCCEDC 8024020C 86E20004 */  lh        $v0, 4($s7)
/* DCCEE0 80240210 14430006 */  bne       $v0, $v1, .L8024022C
/* DCCEE4 80240214 00000000 */   nop      
.L80240218:
/* DCCEE8 80240218 C6000000 */  lwc1      $f0, ($s0)
/* DCCEEC 8024021C 02561021 */  addu      $v0, $s2, $s6
/* DCCEF0 80240220 E6A0001C */  swc1      $f0, 0x1c($s5)
/* DCCEF4 80240224 C4400000 */  lwc1      $f0, ($v0)
/* DCCEF8 80240228 E6A00024 */  swc1      $f0, 0x24($s5)
.L8024022C:
/* DCCEFC 8024022C 86630084 */  lh        $v1, 0x84($s3)
/* DCCF00 80240230 8E220000 */  lw        $v0, ($s1)
/* DCCF04 80240234 54620014 */  bnel      $v1, $v0, .L80240288
/* DCCF08 80240238 26520008 */   addiu    $s2, $s2, 8
/* DCCF0C 8024023C 82830003 */  lb        $v1, 3($s4)
/* DCCF10 80240240 24020002 */  addiu     $v0, $zero, 2
/* DCCF14 80240244 14620004 */  bne       $v1, $v0, .L80240258
/* DCCF18 80240248 00000000 */   nop      
/* DCCF1C 8024024C 82820000 */  lb        $v0, ($s4)
/* DCCF20 80240250 5440000D */  bnel      $v0, $zero, .L80240288
/* DCCF24 80240254 26520008 */   addiu    $s2, $s2, 8
.L80240258:
/* DCCF28 80240258 C6600038 */  lwc1      $f0, 0x38($s3)
/* DCCF2C 8024025C C6020000 */  lwc1      $f2, ($s0)
/* DCCF30 80240260 46020000 */  add.s     $f0, $f0, $f2
/* DCCF34 80240264 C6620040 */  lwc1      $f2, 0x40($s3)
/* DCCF38 80240268 02561021 */  addu      $v0, $s2, $s6
/* DCCF3C 8024026C E6600038 */  swc1      $f0, 0x38($s3)
/* DCCF40 80240270 C4400000 */  lwc1      $f0, ($v0)
/* DCCF44 80240274 46001080 */  add.s     $f2, $f2, $f0
/* DCCF48 80240278 0260202D */  daddu     $a0, $s3, $zero
/* DCCF4C 8024027C 0C03BD17 */  jal       clear_partner_move_history
/* DCCF50 80240280 E6620040 */   swc1     $f2, 0x40($s3)
/* DCCF54 80240284 26520008 */  addiu     $s2, $s2, 8
.L80240288:
/* DCCF58 80240288 26100008 */  addiu     $s0, $s0, 8
/* DCCF5C 8024028C 021E102B */  sltu      $v0, $s0, $fp
/* DCCF60 80240290 1440FFDA */  bnez      $v0, .L802401FC
/* DCCF64 80240294 26310004 */   addiu    $s1, $s1, 4
.L80240298:
/* DCCF68 80240298 24020002 */  addiu     $v0, $zero, 2
.L8024029C:
/* DCCF6C 8024029C 8FBF006C */  lw        $ra, 0x6c($sp)
/* DCCF70 802402A0 8FBE0068 */  lw        $fp, 0x68($sp)
/* DCCF74 802402A4 8FB70064 */  lw        $s7, 0x64($sp)
/* DCCF78 802402A8 8FB60060 */  lw        $s6, 0x60($sp)
/* DCCF7C 802402AC 8FB5005C */  lw        $s5, 0x5c($sp)
/* DCCF80 802402B0 8FB40058 */  lw        $s4, 0x58($sp)
/* DCCF84 802402B4 8FB30054 */  lw        $s3, 0x54($sp)
/* DCCF88 802402B8 8FB20050 */  lw        $s2, 0x50($sp)
/* DCCF8C 802402BC 8FB1004C */  lw        $s1, 0x4c($sp)
/* DCCF90 802402C0 8FB00048 */  lw        $s0, 0x48($sp)
/* DCCF94 802402C4 03E00008 */  jr        $ra
/* DCCF98 802402C8 27BD0070 */   addiu    $sp, $sp, 0x70
/* DCCF9C 802402CC 00000000 */  nop       
