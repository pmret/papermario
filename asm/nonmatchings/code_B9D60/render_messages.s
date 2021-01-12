.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_messages
/* BA904 80124204 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BA908 80124208 AFB10024 */  sw        $s1, 0x24($sp)
/* BA90C 8012420C 0000882D */  daddu     $s1, $zero, $zero
/* BA910 80124210 AFB00020 */  sw        $s0, 0x20($sp)
/* BA914 80124214 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* BA918 80124218 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* BA91C 8012421C 3C058015 */  lui       $a1, %hi(D_80154C30)
/* BA920 80124220 24A54C30 */  addiu     $a1, $a1, %lo(D_80154C30)
/* BA924 80124224 44803000 */  mtc1      $zero, $f6
/* BA928 80124228 3C028007 */  lui       $v0, %hi(gCurrentDisplayContextIndex)
/* BA92C 8012422C 8C4241F4 */  lw        $v0, %lo(gCurrentDisplayContextIndex)($v0)
/* BA930 80124230 3C038015 */  lui       $v1, %hi(D_80155CA0)
/* BA934 80124234 24635CA0 */  addiu     $v1, $v1, %lo(D_80155CA0)
/* BA938 80124238 AFBF002C */  sw        $ra, 0x2c($sp)
/* BA93C 8012423C AFB20028 */  sw        $s2, 0x28($sp)
/* BA940 80124240 00021180 */  sll       $v0, $v0, 6
/* BA944 80124244 00432021 */  addu      $a0, $v0, $v1
/* BA948 80124248 3C028000 */  lui       $v0, 0x8000
/* BA94C 8012424C 00829021 */  addu      $s2, $a0, $v0
.L80124250:
/* BA950 80124250 8CA204FC */  lw        $v0, 0x4fc($a1)
/* BA954 80124254 30420002 */  andi      $v0, $v0, 2
/* BA958 80124258 1040003B */  beqz      $v0, .L80124348
/* BA95C 8012425C 3C03DC08 */   lui      $v1, 0xdc08
/* BA960 80124260 34630008 */  ori       $v1, $v1, 8
/* BA964 80124264 8E020000 */  lw        $v0, ($s0)
/* BA968 80124268 3C01C3FA */  lui       $at, 0xc3fa
/* BA96C 8012426C 44810000 */  mtc1      $at, $f0
/* BA970 80124270 3C0143FA */  lui       $at, 0x43fa
/* BA974 80124274 44811000 */  mtc1      $at, $f2
/* BA978 80124278 3C013F80 */  lui       $at, 0x3f80
/* BA97C 8012427C 44812000 */  mtc1      $at, $f4
/* BA980 80124280 44053000 */  mfc1      $a1, $f6
/* BA984 80124284 3C06439F */  lui       $a2, 0x439f
/* BA988 80124288 34C68000 */  ori       $a2, $a2, 0x8000
/* BA98C 8012428C 3C07C370 */  lui       $a3, 0xc370
/* BA990 80124290 0040402D */  daddu     $t0, $v0, $zero
/* BA994 80124294 24420008 */  addiu     $v0, $v0, 8
/* BA998 80124298 AE020000 */  sw        $v0, ($s0)
/* BA99C 8012429C 3C028015 */  lui       $v0, %hi(D_8014C280)
/* BA9A0 801242A0 2442C280 */  addiu     $v0, $v0, %lo(D_8014C280)
/* BA9A4 801242A4 AD030000 */  sw        $v1, ($t0)
/* BA9A8 801242A8 AD020004 */  sw        $v0, 4($t0)
/* BA9AC 801242AC AFA50010 */  sw        $a1, 0x10($sp)
/* BA9B0 801242B0 E7A00014 */  swc1      $f0, 0x14($sp)
/* BA9B4 801242B4 E7A20018 */  swc1      $f2, 0x18($sp)
/* BA9B8 801242B8 0C018E90 */  jal       guOrtho
/* BA9BC 801242BC E7A4001C */   swc1     $f4, 0x1c($sp)
/* BA9C0 801242C0 3C04DA38 */  lui       $a0, 0xda38
/* BA9C4 801242C4 34840007 */  ori       $a0, $a0, 7
/* BA9C8 801242C8 3C05E300 */  lui       $a1, 0xe300
/* BA9CC 801242CC 34A50A01 */  ori       $a1, $a1, 0xa01
/* BA9D0 801242D0 3C06D9C0 */  lui       $a2, 0xd9c0
/* BA9D4 801242D4 34C6F9FB */  ori       $a2, $a2, 0xf9fb
/* BA9D8 801242D8 3C08D9FF */  lui       $t0, 0xd9ff
/* BA9DC 801242DC 3508FFFF */  ori       $t0, $t0, 0xffff
/* BA9E0 801242E0 3C070020 */  lui       $a3, 0x20
/* BA9E4 801242E4 8E030000 */  lw        $v1, ($s0)
/* BA9E8 801242E8 34E70004 */  ori       $a3, $a3, 4
/* BA9EC 801242EC 0060102D */  daddu     $v0, $v1, $zero
/* BA9F0 801242F0 24630008 */  addiu     $v1, $v1, 8
/* BA9F4 801242F4 AE030000 */  sw        $v1, ($s0)
/* BA9F8 801242F8 AC440000 */  sw        $a0, ($v0)
/* BA9FC 801242FC AC520004 */  sw        $s2, 4($v0)
/* BAA00 80124300 24620008 */  addiu     $v0, $v1, 8
/* BAA04 80124304 AE020000 */  sw        $v0, ($s0)
/* BAA08 80124308 3C02E700 */  lui       $v0, 0xe700
/* BAA0C 8012430C AC620000 */  sw        $v0, ($v1)
/* BAA10 80124310 24620010 */  addiu     $v0, $v1, 0x10
/* BAA14 80124314 AC600004 */  sw        $zero, 4($v1)
/* BAA18 80124318 AE020000 */  sw        $v0, ($s0)
/* BAA1C 8012431C 24620018 */  addiu     $v0, $v1, 0x18
/* BAA20 80124320 AC650008 */  sw        $a1, 8($v1)
/* BAA24 80124324 AC60000C */  sw        $zero, 0xc($v1)
/* BAA28 80124328 AE020000 */  sw        $v0, ($s0)
/* BAA2C 8012432C 24620020 */  addiu     $v0, $v1, 0x20
/* BAA30 80124330 AC660010 */  sw        $a2, 0x10($v1)
/* BAA34 80124334 AC600014 */  sw        $zero, 0x14($v1)
/* BAA38 80124338 AE020000 */  sw        $v0, ($s0)
/* BAA3C 8012433C AC680018 */  sw        $t0, 0x18($v1)
/* BAA40 80124340 080490D6 */  j         .L80124358
/* BAA44 80124344 AC67001C */   sw       $a3, 0x1c($v1)
.L80124348:
/* BAA48 80124348 26310001 */  addiu     $s1, $s1, 1
/* BAA4C 8012434C 2A220003 */  slti      $v0, $s1, 3
/* BAA50 80124350 1440FFBF */  bnez      $v0, .L80124250
/* BAA54 80124354 24A50558 */   addiu    $a1, $a1, 0x558
.L80124358:
/* BAA58 80124358 0000882D */  daddu     $s1, $zero, $zero
/* BAA5C 8012435C 24120005 */  addiu     $s2, $zero, 5
/* BAA60 80124360 3C108015 */  lui       $s0, %hi(D_80154C30)
/* BAA64 80124364 26104C30 */  addiu     $s0, $s0, %lo(D_80154C30)
.L80124368:
/* BAA68 80124368 8E0204FC */  lw        $v0, 0x4fc($s0)
/* BAA6C 8012436C 30420002 */  andi      $v0, $v0, 2
/* BAA70 80124370 50400026 */  beql      $v0, $zero, .L8012440C
/* BAA74 80124374 26100558 */   addiu    $s0, $s0, 0x558
/* BAA78 80124378 0C049EE9 */  jal       func_80127BA4
/* BAA7C 8012437C 0200202D */   daddu    $a0, $s0, $zero
/* BAA80 80124380 920404F8 */  lbu       $a0, 0x4f8($s0)
/* BAA84 80124384 308300FF */  andi      $v1, $a0, 0xff
/* BAA88 80124388 1472000C */  bne       $v1, $s2, .L801243BC
/* BAA8C 8012438C 2402000C */   addiu    $v0, $zero, 0xc
/* BAA90 80124390 8E0304FC */  lw        $v1, 0x4fc($s0)
/* BAA94 80124394 30628000 */  andi      $v0, $v1, 0x8000
/* BAA98 80124398 5440001C */  bnel      $v0, $zero, .L8012440C
/* BAA9C 8012439C 26100558 */   addiu    $s0, $s0, 0x558
/* BAAA0 801243A0 30620040 */  andi      $v0, $v1, 0x40
/* BAAA4 801243A4 54400019 */  bnel      $v0, $zero, .L8012440C
/* BAAA8 801243A8 26100558 */   addiu    $s0, $s0, 0x558
/* BAAAC 801243AC 0C0499E4 */  jal       func_80126790
/* BAAB0 801243B0 0220202D */   daddu    $a0, $s1, $zero
/* BAAB4 801243B4 08049103 */  j         .L8012440C
/* BAAB8 801243B8 26100558 */   addiu    $s0, $s0, 0x558
.L801243BC:
/* BAABC 801243BC 14620005 */  bne       $v1, $v0, .L801243D4
/* BAAC0 801243C0 2482FFF9 */   addiu    $v0, $a0, -7
/* BAAC4 801243C4 0C049BAB */  jal       func_80126EAC
/* BAAC8 801243C8 0220202D */   daddu    $a0, $s1, $zero
/* BAACC 801243CC 08049103 */  j         .L8012440C
/* BAAD0 801243D0 26100558 */   addiu    $s0, $s0, 0x558
.L801243D4:
/* BAAD4 801243D4 304200FF */  andi      $v0, $v0, 0xff
/* BAAD8 801243D8 2C420002 */  sltiu     $v0, $v0, 2
/* BAADC 801243DC 14400008 */  bnez      $v0, .L80124400
/* BAAE0 801243E0 3C020001 */   lui      $v0, 1
/* BAAE4 801243E4 8E0304FC */  lw        $v1, 0x4fc($s0)
/* BAAE8 801243E8 00621024 */  and       $v0, $v1, $v0
/* BAAEC 801243EC 14400004 */  bnez      $v0, .L80124400
/* BAAF0 801243F0 3C020002 */   lui      $v0, 2
/* BAAF4 801243F4 00621024 */  and       $v0, $v1, $v0
/* BAAF8 801243F8 50400004 */  beql      $v0, $zero, .L8012440C
/* BAAFC 801243FC 26100558 */   addiu    $s0, $s0, 0x558
.L80124400:
/* BAB00 80124400 0C049BDE */  jal       func_80126F78
/* BAB04 80124404 0200202D */   daddu    $a0, $s0, $zero
/* BAB08 80124408 26100558 */  addiu     $s0, $s0, 0x558
.L8012440C:
/* BAB0C 8012440C 26310001 */  addiu     $s1, $s1, 1
/* BAB10 80124410 2A220003 */  slti      $v0, $s1, 3
/* BAB14 80124414 1440FFD4 */  bnez      $v0, .L80124368
/* BAB18 80124418 00000000 */   nop
/* BAB1C 8012441C 8FBF002C */  lw        $ra, 0x2c($sp)
/* BAB20 80124420 8FB20028 */  lw        $s2, 0x28($sp)
/* BAB24 80124424 8FB10024 */  lw        $s1, 0x24($sp)
/* BAB28 80124428 8FB00020 */  lw        $s0, 0x20($sp)
/* BAB2C 8012442C 03E00008 */  jr        $ra
/* BAB30 80124430 27BD0030 */   addiu    $sp, $sp, 0x30
