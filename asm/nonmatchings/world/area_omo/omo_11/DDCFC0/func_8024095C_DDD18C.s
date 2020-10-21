.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024095C_DDD18C
/* DDD18C 8024095C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* DDD190 80240960 AFB5002C */  sw        $s5, 0x2c($sp)
/* DDD194 80240964 0080A82D */  daddu     $s5, $a0, $zero
/* DDD198 80240968 AFBE0038 */  sw        $fp, 0x38($sp)
/* DDD19C 8024096C 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* DDD1A0 80240970 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* DDD1A4 80240974 AFBF003C */  sw        $ra, 0x3c($sp)
/* DDD1A8 80240978 AFB70034 */  sw        $s7, 0x34($sp)
/* DDD1AC 8024097C AFB60030 */  sw        $s6, 0x30($sp)
/* DDD1B0 80240980 AFB40028 */  sw        $s4, 0x28($sp)
/* DDD1B4 80240984 AFB30024 */  sw        $s3, 0x24($sp)
/* DDD1B8 80240988 AFB20020 */  sw        $s2, 0x20($sp)
/* DDD1BC 8024098C AFB1001C */  sw        $s1, 0x1c($sp)
/* DDD1C0 80240990 10A0004F */  beqz      $a1, .L80240AD0
/* DDD1C4 80240994 AFB00018 */   sw       $s0, 0x18($sp)
/* DDD1C8 80240998 0C00AB39 */  jal       heap_malloc
/* DDD1CC 8024099C 24040330 */   addiu    $a0, $zero, 0x330
/* DDD1D0 802409A0 0040982D */  daddu     $s3, $v0, $zero
/* DDD1D4 802409A4 0000B02D */  daddu     $s6, $zero, $zero
/* DDD1D8 802409A8 02C0902D */  daddu     $s2, $s6, $zero
/* DDD1DC 802409AC 3C148024 */  lui       $s4, 0x8024
/* DDD1E0 802409B0 26941E48 */  addiu     $s4, $s4, 0x1e48
/* DDD1E4 802409B4 0260882D */  daddu     $s1, $s3, $zero
/* DDD1E8 802409B8 8EA200B4 */  lw        $v0, 0xb4($s5)
/* DDD1EC 802409BC 3C038024 */  lui       $v1, 0x8024
/* DDD1F0 802409C0 24631E40 */  addiu     $v1, $v1, 0x1e40
/* DDD1F4 802409C4 AEB30078 */  sw        $s3, 0x78($s5)
/* DDD1F8 802409C8 00021027 */  nor       $v0, $zero, $v0
/* DDD1FC 802409CC 0002BFC2 */  srl       $s7, $v0, 0x1f
/* DDD200 802409D0 00171080 */  sll       $v0, $s7, 2
/* DDD204 802409D4 00431021 */  addu      $v0, $v0, $v1
/* DDD208 802409D8 AFA20010 */  sw        $v0, 0x10($sp)
.L802409DC:
/* DDD20C 802409DC 86900000 */  lh        $s0, ($s4)
/* DDD210 802409E0 001010C0 */  sll       $v0, $s0, 3
/* DDD214 802409E4 03C21021 */  addu      $v0, $fp, $v0
/* DDD218 802409E8 90420014 */  lbu       $v0, 0x14($v0)
/* DDD21C 802409EC 5040002E */  beql      $v0, $zero, .L80240AA8
/* DDD220 802409F0 26520001 */   addiu    $s2, $s2, 1
/* DDD224 802409F4 00101100 */  sll       $v0, $s0, 4
/* DDD228 802409F8 3C068009 */  lui       $a2, 0x8009
/* DDD22C 802409FC 24C6EF20 */  addiu     $a2, $a2, -0x10e0
/* DDD230 80240A00 00461021 */  addu      $v0, $v0, $a2
/* DDD234 80240A04 0200202D */  daddu     $a0, $s0, $zero
/* DDD238 80240A08 AE300108 */  sw        $s0, 0x108($s1)
/* DDD23C 80240A0C 8C420000 */  lw        $v0, ($v0)
/* DDD240 80240A10 02E0282D */  daddu     $a1, $s7, $zero
/* DDD244 80240A14 0C090219 */  jal       func_80240864_DDD094
/* DDD248 80240A18 AE220084 */   sw       $v0, 0x84($s1)
/* DDD24C 80240A1C 0040202D */  daddu     $a0, $v0, $zero
/* DDD250 80240A20 04800011 */  bltz      $a0, .L80240A68
/* DDD254 80240A24 00101080 */   sll      $v0, $s0, 2
/* DDD258 80240A28 3C06800F */  lui       $a2, 0x800f
/* DDD25C 80240A2C 24C67F00 */  addiu     $a2, $a2, 0x7f00
/* DDD260 80240A30 00461021 */  addu      $v0, $v0, $a2
/* DDD264 80240A34 8C430000 */  lw        $v1, ($v0)
/* DDD268 80240A38 24020001 */  addiu     $v0, $zero, 1
/* DDD26C 80240A3C AE22018C */  sw        $v0, 0x18c($s1)
/* DDD270 80240A40 00041080 */  sll       $v0, $a0, 2
/* DDD274 80240A44 3C068024 */  lui       $a2, 0x8024
/* DDD278 80240A48 24C61E58 */  addiu     $a2, $a2, 0x1e58
/* DDD27C 80240A4C AE230000 */  sw        $v1, ($s1)
/* DDD280 80240A50 001218C0 */  sll       $v1, $s2, 3
/* DDD284 80240A54 00431021 */  addu      $v0, $v0, $v1
/* DDD288 80240A58 00461021 */  addu      $v0, $v0, $a2
/* DDD28C 80240A5C 8C420000 */  lw        $v0, ($v0)
/* DDD290 80240A60 080902A3 */  j         .L80240A8C
/* DDD294 80240A64 AE220294 */   sw       $v0, 0x294($s1)
.L80240A68:
/* DDD298 80240A68 3C06800F */  lui       $a2, 0x800f
/* DDD29C 80240A6C 24C67F40 */  addiu     $a2, $a2, 0x7f40
/* DDD2A0 80240A70 00461021 */  addu      $v0, $v0, $a2
/* DDD2A4 80240A74 8C420000 */  lw        $v0, ($v0)
/* DDD2A8 80240A78 AE20018C */  sw        $zero, 0x18c($s1)
/* DDD2AC 80240A7C AE220000 */  sw        $v0, ($s1)
/* DDD2B0 80240A80 8FA60010 */  lw        $a2, 0x10($sp)
/* DDD2B4 80240A84 8CC20000 */  lw        $v0, ($a2)
/* DDD2B8 80240A88 AE220294 */  sw        $v0, 0x294($s1)
.L80240A8C:
/* DDD2BC 80240A8C 001010C0 */  sll       $v0, $s0, 3
/* DDD2C0 80240A90 03C21021 */  addu      $v0, $fp, $v0
/* DDD2C4 80240A94 80420015 */  lb        $v0, 0x15($v0)
/* DDD2C8 80240A98 26D60001 */  addiu     $s6, $s6, 1
/* DDD2CC 80240A9C AE220210 */  sw        $v0, 0x210($s1)
/* DDD2D0 80240AA0 26310004 */  addiu     $s1, $s1, 4
/* DDD2D4 80240AA4 26520001 */  addiu     $s2, $s2, 1
.L80240AA8:
/* DDD2D8 80240AA8 2A420008 */  slti      $v0, $s2, 8
/* DDD2DC 80240AAC 1440FFCB */  bnez      $v0, .L802409DC
/* DDD2E0 80240AB0 26940002 */   addiu    $s4, $s4, 2
/* DDD2E4 80240AB4 0260202D */  daddu     $a0, $s3, $zero
/* DDD2E8 80240AB8 24020004 */  addiu     $v0, $zero, 4
/* DDD2EC 80240ABC AC820318 */  sw        $v0, 0x318($a0)
/* DDD2F0 80240AC0 AC960324 */  sw        $s6, 0x324($a0)
/* DDD2F4 80240AC4 0C03D390 */  jal       func_800F4E40
/* DDD2F8 80240AC8 AC800328 */   sw       $zero, 0x328($a0)
/* DDD2FC 80240ACC AEA00070 */  sw        $zero, 0x70($s5)
.L80240AD0:
/* DDD300 80240AD0 8EA20070 */  lw        $v0, 0x70($s5)
/* DDD304 80240AD4 8EB30078 */  lw        $s3, 0x78($s5)
/* DDD308 80240AD8 14400008 */  bnez      $v0, .L80240AFC
/* DDD30C 80240ADC 24420001 */   addiu    $v0, $v0, 1
/* DDD310 80240AE0 8662032C */  lh        $v0, 0x32c($s3)
/* DDD314 80240AE4 10400009 */  beqz      $v0, .L80240B0C
/* DDD318 80240AE8 AEA20074 */   sw       $v0, 0x74($s5)
/* DDD31C 80240AEC 0C03C4EC */  jal       func_800F13B0
/* DDD320 80240AF0 00000000 */   nop      
/* DDD324 80240AF4 8EA20070 */  lw        $v0, 0x70($s5)
/* DDD328 80240AF8 24420001 */  addiu     $v0, $v0, 1
.L80240AFC:
/* DDD32C 80240AFC AEA20070 */  sw        $v0, 0x70($s5)
/* DDD330 80240B00 2842000F */  slti      $v0, $v0, 0xf
/* DDD334 80240B04 10400003 */  beqz      $v0, .L80240B14
/* DDD338 80240B08 00000000 */   nop      
.L80240B0C:
/* DDD33C 80240B0C 080902DF */  j         .L80240B7C
/* DDD340 80240B10 0000102D */   daddu    $v0, $zero, $zero
.L80240B14:
/* DDD344 80240B14 0C03C54E */  jal       func_800F1538
/* DDD348 80240B18 00000000 */   nop      
/* DDD34C 80240B1C 8EA30074 */  lw        $v1, 0x74($s5)
/* DDD350 80240B20 240200FF */  addiu     $v0, $zero, 0xff
/* DDD354 80240B24 10620010 */  beq       $v1, $v0, .L80240B68
/* DDD358 80240B28 2462FFFF */   addiu    $v0, $v1, -1
/* DDD35C 80240B2C 00021080 */  sll       $v0, $v0, 2
/* DDD360 80240B30 02621021 */  addu      $v0, $s3, $v0
/* DDD364 80240B34 8C420108 */  lw        $v0, 0x108($v0)
/* DDD368 80240B38 00021100 */  sll       $v0, $v0, 4
/* DDD36C 80240B3C 3C038009 */  lui       $v1, 0x8009
/* DDD370 80240B40 00621821 */  addu      $v1, $v1, $v0
/* DDD374 80240B44 8C63EF20 */  lw        $v1, -0x10e0($v1)
/* DDD378 80240B48 8EA20074 */  lw        $v0, 0x74($s5)
/* DDD37C 80240B4C 2442FFFF */  addiu     $v0, $v0, -1
/* DDD380 80240B50 00021080 */  sll       $v0, $v0, 2
/* DDD384 80240B54 02621021 */  addu      $v0, $s3, $v0
/* DDD388 80240B58 AEA30084 */  sw        $v1, 0x84($s5)
/* DDD38C 80240B5C 8C420108 */  lw        $v0, 0x108($v0)
/* DDD390 80240B60 080902DC */  j         .L80240B70
/* DDD394 80240B64 AEA20088 */   sw       $v0, 0x88($s5)
.L80240B68:
/* DDD398 80240B68 2402FFFF */  addiu     $v0, $zero, -1
/* DDD39C 80240B6C AEA20084 */  sw        $v0, 0x84($s5)
.L80240B70:
/* DDD3A0 80240B70 0C00AB4B */  jal       heap_free
/* DDD3A4 80240B74 8EA40078 */   lw       $a0, 0x78($s5)
/* DDD3A8 80240B78 24020002 */  addiu     $v0, $zero, 2
.L80240B7C:
/* DDD3AC 80240B7C 8FBF003C */  lw        $ra, 0x3c($sp)
/* DDD3B0 80240B80 8FBE0038 */  lw        $fp, 0x38($sp)
/* DDD3B4 80240B84 8FB70034 */  lw        $s7, 0x34($sp)
/* DDD3B8 80240B88 8FB60030 */  lw        $s6, 0x30($sp)
/* DDD3BC 80240B8C 8FB5002C */  lw        $s5, 0x2c($sp)
/* DDD3C0 80240B90 8FB40028 */  lw        $s4, 0x28($sp)
/* DDD3C4 80240B94 8FB30024 */  lw        $s3, 0x24($sp)
/* DDD3C8 80240B98 8FB20020 */  lw        $s2, 0x20($sp)
/* DDD3CC 80240B9C 8FB1001C */  lw        $s1, 0x1c($sp)
/* DDD3D0 80240BA0 8FB00018 */  lw        $s0, 0x18($sp)
/* DDD3D4 80240BA4 03E00008 */  jr        $ra
/* DDD3D8 80240BA8 27BD0040 */   addiu    $sp, $sp, 0x40
