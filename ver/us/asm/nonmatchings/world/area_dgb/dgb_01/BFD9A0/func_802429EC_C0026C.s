.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429EC_C0026C
/* C0026C 802429EC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C00270 802429F0 AFB40040 */  sw        $s4, 0x40($sp)
/* C00274 802429F4 0080A02D */  daddu     $s4, $a0, $zero
/* C00278 802429F8 AFBF0044 */  sw        $ra, 0x44($sp)
/* C0027C 802429FC AFB3003C */  sw        $s3, 0x3c($sp)
/* C00280 80242A00 AFB20038 */  sw        $s2, 0x38($sp)
/* C00284 80242A04 AFB10034 */  sw        $s1, 0x34($sp)
/* C00288 80242A08 AFB00030 */  sw        $s0, 0x30($sp)
/* C0028C 80242A0C 8E910148 */  lw        $s1, 0x148($s4)
/* C00290 80242A10 00A0902D */  daddu     $s2, $a1, $zero
/* C00294 80242A14 86240008 */  lh        $a0, 8($s1)
/* C00298 80242A18 0C00EABB */  jal       get_npc_unsafe
/* C0029C 80242A1C 00C0982D */   daddu    $s3, $a2, $zero
/* C002A0 80242A20 8E430014 */  lw        $v1, 0x14($s2)
/* C002A4 80242A24 04600031 */  bltz      $v1, .L80242AEC
/* C002A8 80242A28 0040802D */   daddu    $s0, $v0, $zero
/* C002AC 80242A2C 0260202D */  daddu     $a0, $s3, $zero
/* C002B0 80242A30 AFA00010 */  sw        $zero, 0x10($sp)
/* C002B4 80242A34 8E460024 */  lw        $a2, 0x24($s2)
/* C002B8 80242A38 8E470028 */  lw        $a3, 0x28($s2)
/* C002BC 80242A3C 0C01242D */  jal       func_800490B4
/* C002C0 80242A40 0220282D */   daddu    $a1, $s1, $zero
/* C002C4 80242A44 10400029 */  beqz      $v0, .L80242AEC
/* C002C8 80242A48 0000202D */   daddu    $a0, $zero, $zero
/* C002CC 80242A4C 0200282D */  daddu     $a1, $s0, $zero
/* C002D0 80242A50 0000302D */  daddu     $a2, $zero, $zero
/* C002D4 80242A54 860300A8 */  lh        $v1, 0xa8($s0)
/* C002D8 80242A58 3C013F80 */  lui       $at, 0x3f80
/* C002DC 80242A5C 44810000 */  mtc1      $at, $f0
/* C002E0 80242A60 3C014000 */  lui       $at, 0x4000
/* C002E4 80242A64 44811000 */  mtc1      $at, $f2
/* C002E8 80242A68 3C01C1A0 */  lui       $at, 0xc1a0
/* C002EC 80242A6C 44812000 */  mtc1      $at, $f4
/* C002F0 80242A70 2402000F */  addiu     $v0, $zero, 0xf
/* C002F4 80242A74 AFA2001C */  sw        $v0, 0x1c($sp)
/* C002F8 80242A78 44833000 */  mtc1      $v1, $f6
/* C002FC 80242A7C 00000000 */  nop
/* C00300 80242A80 468031A0 */  cvt.s.w   $f6, $f6
/* C00304 80242A84 44073000 */  mfc1      $a3, $f6
/* C00308 80242A88 27A20028 */  addiu     $v0, $sp, 0x28
/* C0030C 80242A8C AFA20020 */  sw        $v0, 0x20($sp)
/* C00310 80242A90 E7A00010 */  swc1      $f0, 0x10($sp)
/* C00314 80242A94 E7A20014 */  swc1      $f2, 0x14($sp)
/* C00318 80242A98 0C01BFA4 */  jal       fx_emote
/* C0031C 80242A9C E7A40018 */   swc1     $f4, 0x18($sp)
/* C00320 80242AA0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C00324 80242AA4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C00328 80242AA8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C0032C 80242AAC C60E0040 */  lwc1      $f14, 0x40($s0)
/* C00330 80242AB0 8C460028 */  lw        $a2, 0x28($v0)
/* C00334 80242AB4 0C00A720 */  jal       atan2
/* C00338 80242AB8 8C470030 */   lw       $a3, 0x30($v0)
/* C0033C 80242ABC 0200202D */  daddu     $a0, $s0, $zero
/* C00340 80242AC0 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C00344 80242AC4 3C060020 */  lui       $a2, 0x20
/* C00348 80242AC8 0C012530 */  jal       func_800494C0
/* C0034C 80242ACC E480000C */   swc1     $f0, 0xc($a0)
/* C00350 80242AD0 8E220018 */  lw        $v0, 0x18($s1)
/* C00354 80242AD4 9442002A */  lhu       $v0, 0x2a($v0)
/* C00358 80242AD8 30420001 */  andi      $v0, $v0, 1
/* C0035C 80242ADC 14400029 */  bnez      $v0, .L80242B84
/* C00360 80242AE0 2402000A */   addiu    $v0, $zero, 0xa
/* C00364 80242AE4 08090AE1 */  j         .L80242B84
/* C00368 80242AE8 2402000C */   addiu    $v0, $zero, 0xc
.L80242AEC:
/* C0036C 80242AEC 8602008C */  lh        $v0, 0x8c($s0)
/* C00370 80242AF0 14400025 */  bnez      $v0, .L80242B88
/* C00374 80242AF4 00000000 */   nop
/* C00378 80242AF8 9602008E */  lhu       $v0, 0x8e($s0)
/* C0037C 80242AFC 2442FFFF */  addiu     $v0, $v0, -1
/* C00380 80242B00 A602008E */  sh        $v0, 0x8e($s0)
/* C00384 80242B04 00021400 */  sll       $v0, $v0, 0x10
/* C00388 80242B08 1440001F */  bnez      $v0, .L80242B88
/* C0038C 80242B0C 00000000 */   nop
/* C00390 80242B10 8E820074 */  lw        $v0, 0x74($s4)
/* C00394 80242B14 2442FFFF */  addiu     $v0, $v0, -1
/* C00398 80242B18 10400019 */  beqz      $v0, .L80242B80
/* C0039C 80242B1C AE820074 */   sw       $v0, 0x74($s4)
/* C003A0 80242B20 8E220018 */  lw        $v0, 0x18($s1)
/* C003A4 80242B24 9442002A */  lhu       $v0, 0x2a($v0)
/* C003A8 80242B28 30420010 */  andi      $v0, $v0, 0x10
/* C003AC 80242B2C 14400007 */  bnez      $v0, .L80242B4C
/* C003B0 80242B30 00000000 */   nop
/* C003B4 80242B34 C600000C */  lwc1      $f0, 0xc($s0)
/* C003B8 80242B38 3C014334 */  lui       $at, 0x4334
/* C003BC 80242B3C 44816000 */  mtc1      $at, $f12
/* C003C0 80242B40 0C00A6C9 */  jal       clamp_angle
/* C003C4 80242B44 460C0300 */   add.s    $f12, $f0, $f12
/* C003C8 80242B48 E600000C */  swc1      $f0, 0xc($s0)
.L80242B4C:
/* C003CC 80242B4C 8E440008 */  lw        $a0, 8($s2)
/* C003D0 80242B50 000417C2 */  srl       $v0, $a0, 0x1f
/* C003D4 80242B54 00822021 */  addu      $a0, $a0, $v0
/* C003D8 80242B58 00042043 */  sra       $a0, $a0, 1
/* C003DC 80242B5C 0C00A67F */  jal       rand_int
/* C003E0 80242B60 24840001 */   addiu    $a0, $a0, 1
/* C003E4 80242B64 8E430008 */  lw        $v1, 8($s2)
/* C003E8 80242B68 000327C2 */  srl       $a0, $v1, 0x1f
/* C003EC 80242B6C 00641821 */  addu      $v1, $v1, $a0
/* C003F0 80242B70 00031843 */  sra       $v1, $v1, 1
/* C003F4 80242B74 00621821 */  addu      $v1, $v1, $v0
/* C003F8 80242B78 08090AE2 */  j         .L80242B88
/* C003FC 80242B7C A603008E */   sh       $v1, 0x8e($s0)
.L80242B80:
/* C00400 80242B80 24020004 */  addiu     $v0, $zero, 4
.L80242B84:
/* C00404 80242B84 AE820070 */  sw        $v0, 0x70($s4)
.L80242B88:
/* C00408 80242B88 8FBF0044 */  lw        $ra, 0x44($sp)
/* C0040C 80242B8C 8FB40040 */  lw        $s4, 0x40($sp)
/* C00410 80242B90 8FB3003C */  lw        $s3, 0x3c($sp)
/* C00414 80242B94 8FB20038 */  lw        $s2, 0x38($sp)
/* C00418 80242B98 8FB10034 */  lw        $s1, 0x34($sp)
/* C0041C 80242B9C 8FB00030 */  lw        $s0, 0x30($sp)
/* C00420 80242BA0 03E00008 */  jr        $ra
/* C00424 80242BA4 27BD0048 */   addiu    $sp, $sp, 0x48
