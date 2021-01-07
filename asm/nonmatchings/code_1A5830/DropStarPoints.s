.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel DropStarPoints
/* 1AB184 8027C8A4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 1AB188 8027C8A8 AFB00020 */  sw        $s0, 0x20($sp)
/* 1AB18C 8027C8AC 0080802D */  daddu     $s0, $a0, $zero
/* 1AB190 8027C8B0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 1AB194 8027C8B4 AFB40030 */  sw        $s4, 0x30($sp)
/* 1AB198 8027C8B8 AFB3002C */  sw        $s3, 0x2c($sp)
/* 1AB19C 8027C8BC AFB20028 */  sw        $s2, 0x28($sp)
/* 1AB1A0 8027C8C0 AFB10024 */  sw        $s1, 0x24($sp)
/* 1AB1A4 8027C8C4 8E02000C */  lw        $v0, 0xc($s0)
/* 1AB1A8 8027C8C8 0C0B1EAF */  jal       get_variable
/* 1AB1AC 8027C8CC 8C450000 */   lw       $a1, ($v0)
/* 1AB1B0 8027C8D0 0040202D */  daddu     $a0, $v0, $zero
/* 1AB1B4 8027C8D4 3C14800E */  lui       $s4, %hi(gBattleStatus)
/* 1AB1B8 8027C8D8 2694C070 */  addiu     $s4, $s4, %lo(gBattleStatus)
/* 1AB1BC 8027C8DC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AB1C0 8027C8E0 14820002 */  bne       $a0, $v0, .L8027C8EC
/* 1AB1C4 8027C8E4 00000000 */   nop      
/* 1AB1C8 8027C8E8 8E040148 */  lw        $a0, 0x148($s0)
.L8027C8EC:
/* 1AB1CC 8027C8EC 0C09A75B */  jal       get_actor
/* 1AB1D0 8027C8F0 00000000 */   nop      
/* 1AB1D4 8027C8F4 0040882D */  daddu     $s1, $v0, $zero
/* 1AB1D8 8027C8F8 8E220008 */  lw        $v0, 8($s1)
/* 1AB1DC 8027C8FC 90420006 */  lbu       $v0, 6($v0)
/* 1AB1E0 8027C900 44800000 */  mtc1      $zero, $f0
/* 1AB1E4 8027C904 44823000 */  mtc1      $v0, $f6
/* 1AB1E8 8027C908 00000000 */  nop       
/* 1AB1EC 8027C90C 468031A0 */  cvt.s.w   $f6, $f6
/* 1AB1F0 8027C910 46003032 */  c.eq.s    $f6, $f0
/* 1AB1F4 8027C914 00000000 */  nop       
/* 1AB1F8 8027C918 45000003 */  bc1f      .L8027C928
/* 1AB1FC 8027C91C 00000000 */   nop      
/* 1AB200 8027C920 3C013F80 */  lui       $at, 0x3f80
/* 1AB204 8027C924 44813000 */  mtc1      $at, $f6
.L8027C928:
/* 1AB208 8027C928 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 1AB20C 8027C92C 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 1AB210 8027C930 80430009 */  lb        $v1, 9($v0)
/* 1AB214 8027C934 44832000 */  mtc1      $v1, $f4
/* 1AB218 8027C938 00000000 */  nop       
/* 1AB21C 8027C93C 46802120 */  cvt.s.w   $f4, $f4
/* 1AB220 8027C940 46002032 */  c.eq.s    $f4, $f0
/* 1AB224 8027C944 00000000 */  nop       
/* 1AB228 8027C948 45000004 */  bc1f      .L8027C95C
/* 1AB22C 8027C94C 00000000 */   nop      
/* 1AB230 8027C950 3C013F80 */  lui       $at, 0x3f80
/* 1AB234 8027C954 44812000 */  mtc1      $at, $f4
/* 1AB238 8027C958 00000000 */  nop       
.L8027C95C:
/* 1AB23C 8027C95C 4604303C */  c.lt.s    $f6, $f4
/* 1AB240 8027C960 00000000 */  nop       
/* 1AB244 8027C964 45010017 */  bc1t      .L8027C9C4
/* 1AB248 8027C968 46000086 */   mov.s    $f2, $f0
/* 1AB24C 8027C96C 46043081 */  sub.s     $f2, $f6, $f4
/* 1AB250 8027C970 3C013F00 */  lui       $at, 0x3f00
/* 1AB254 8027C974 44810000 */  mtc1      $at, $f0
/* 1AB258 8027C978 00000000 */  nop       
/* 1AB25C 8027C97C 46001082 */  mul.s     $f2, $f2, $f0
/* 1AB260 8027C980 00000000 */  nop       
/* 1AB264 8027C984 8282008E */  lb        $v0, 0x8e($s4)
/* 1AB268 8027C988 00021080 */  sll       $v0, $v0, 2
/* 1AB26C 8027C98C 3C018029 */  lui       $at, %hi(D_802946E0)
/* 1AB270 8027C990 00220821 */  addu      $at, $at, $v0
/* 1AB274 8027C994 C42046E0 */  lwc1      $f0, %lo(D_802946E0)($at)
/* 1AB278 8027C998 46800020 */  cvt.s.w   $f0, $f0
/* 1AB27C 8027C99C 46001082 */  mul.s     $f2, $f2, $f0
/* 1AB280 8027C9A0 00000000 */  nop       
/* 1AB284 8027C9A4 3C014248 */  lui       $at, 0x4248
/* 1AB288 8027C9A8 44810000 */  mtc1      $at, $f0
/* 1AB28C 8027C9AC 00000000 */  nop       
/* 1AB290 8027C9B0 46001000 */  add.s     $f0, $f2, $f0
/* 1AB294 8027C9B4 3C0142C8 */  lui       $at, 0x42c8
/* 1AB298 8027C9B8 44811000 */  mtc1      $at, $f2
/* 1AB29C 8027C9BC 00000000 */  nop       
/* 1AB2A0 8027C9C0 46020083 */  div.s     $f2, $f0, $f2
.L8027C9C4:
/* 1AB2A4 8027C9C4 4600120D */  trunc.w.s $f8, $f2
/* 1AB2A8 8027C9C8 44134000 */  mfc1      $s3, $f8
/* 1AB2AC 8027C9CC 2862001B */  slti      $v0, $v1, 0x1b
/* 1AB2B0 8027C9D0 10400019 */  beqz      $v0, .L8027CA38
/* 1AB2B4 8027C9D4 00000000 */   nop      
/* 1AB2B8 8027C9D8 8E220000 */  lw        $v0, ($s1)
/* 1AB2BC 8027C9DC 30420800 */  andi      $v0, $v0, 0x800
/* 1AB2C0 8027C9E0 10400002 */  beqz      $v0, .L8027C9EC
/* 1AB2C4 8027C9E4 24120017 */   addiu    $s2, $zero, 0x17
/* 1AB2C8 8027C9E8 24120019 */  addiu     $s2, $zero, 0x19
.L8027C9EC:
/* 1AB2CC 8027C9EC 1A60000D */  blez      $s3, .L8027CA24
/* 1AB2D0 8027C9F0 0000802D */   daddu    $s0, $zero, $zero
/* 1AB2D4 8027C9F4 24040159 */  addiu     $a0, $zero, 0x159
.L8027C9F8:
/* 1AB2D8 8027C9F8 AFB20010 */  sw        $s2, 0x10($sp)
/* 1AB2DC 8027C9FC AFB00014 */  sw        $s0, 0x14($sp)
/* 1AB2E0 8027CA00 AFA00018 */  sw        $zero, 0x18($sp)
/* 1AB2E4 8027CA04 8E250144 */  lw        $a1, 0x144($s1)
/* 1AB2E8 8027CA08 8E260148 */  lw        $a2, 0x148($s1)
/* 1AB2EC 8027CA0C 8E27014C */  lw        $a3, 0x14c($s1)
/* 1AB2F0 8027CA10 0C04C6B2 */  jal       make_item_entity_delayed
/* 1AB2F4 8027CA14 26100001 */   addiu    $s0, $s0, 1
/* 1AB2F8 8027CA18 0213102A */  slt       $v0, $s0, $s3
/* 1AB2FC 8027CA1C 1440FFF6 */  bnez      $v0, .L8027C9F8
/* 1AB300 8027CA20 24040159 */   addiu    $a0, $zero, 0x159
.L8027CA24:
/* 1AB304 8027CA24 92820079 */  lbu       $v0, 0x79($s4)
/* 1AB308 8027CA28 24030028 */  addiu     $v1, $zero, 0x28
/* 1AB30C 8027CA2C A283007A */  sb        $v1, 0x7a($s4)
/* 1AB310 8027CA30 00531021 */  addu      $v0, $v0, $s3
/* 1AB314 8027CA34 A2820079 */  sb        $v0, 0x79($s4)
.L8027CA38:
/* 1AB318 8027CA38 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AB31C 8027CA3C 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AB320 8027CA40 8C640000 */  lw        $a0, ($v1)
/* 1AB324 8027CA44 3C050100 */  lui       $a1, 0x100
/* 1AB328 8027CA48 00852025 */  or        $a0, $a0, $a1
/* 1AB32C 8027CA4C AC640000 */  sw        $a0, ($v1)
/* 1AB330 8027CA50 8FBF0034 */  lw        $ra, 0x34($sp)
/* 1AB334 8027CA54 8FB40030 */  lw        $s4, 0x30($sp)
/* 1AB338 8027CA58 8FB3002C */  lw        $s3, 0x2c($sp)
/* 1AB33C 8027CA5C 8FB20028 */  lw        $s2, 0x28($sp)
/* 1AB340 8027CA60 8FB10024 */  lw        $s1, 0x24($sp)
/* 1AB344 8027CA64 8FB00020 */  lw        $s0, 0x20($sp)
/* 1AB348 8027CA68 24020002 */  addiu     $v0, $zero, 2
/* 1AB34C 8027CA6C 03E00008 */  jr        $ra
/* 1AB350 8027CA70 27BD0038 */   addiu    $sp, $sp, 0x38
