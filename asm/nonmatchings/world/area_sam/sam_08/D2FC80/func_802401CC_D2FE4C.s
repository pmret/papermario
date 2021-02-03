.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401CC_D2FE4C
/* D2FE4C 802401CC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D2FE50 802401D0 AFB5002C */  sw        $s5, 0x2c($sp)
/* D2FE54 802401D4 0080A82D */  daddu     $s5, $a0, $zero
/* D2FE58 802401D8 AFBE0038 */  sw        $fp, 0x38($sp)
/* D2FE5C 802401DC 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* D2FE60 802401E0 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* D2FE64 802401E4 AFBF003C */  sw        $ra, 0x3c($sp)
/* D2FE68 802401E8 AFB70034 */  sw        $s7, 0x34($sp)
/* D2FE6C 802401EC AFB60030 */  sw        $s6, 0x30($sp)
/* D2FE70 802401F0 AFB40028 */  sw        $s4, 0x28($sp)
/* D2FE74 802401F4 AFB30024 */  sw        $s3, 0x24($sp)
/* D2FE78 802401F8 AFB20020 */  sw        $s2, 0x20($sp)
/* D2FE7C 802401FC AFB1001C */  sw        $s1, 0x1c($sp)
/* D2FE80 80240200 10A0004F */  beqz      $a1, .L80240340
/* D2FE84 80240204 AFB00018 */   sw       $s0, 0x18($sp)
/* D2FE88 80240208 0C00AB39 */  jal       heap_malloc
/* D2FE8C 8024020C 24040330 */   addiu    $a0, $zero, 0x330
/* D2FE90 80240210 0040982D */  daddu     $s3, $v0, $zero
/* D2FE94 80240214 0000B02D */  daddu     $s6, $zero, $zero
/* D2FE98 80240218 02C0902D */  daddu     $s2, $s6, $zero
/* D2FE9C 8024021C 3C148024 */  lui       $s4, %hi(D_80241AE8_D31768)
/* D2FEA0 80240220 26941AE8 */  addiu     $s4, $s4, %lo(D_80241AE8_D31768)
/* D2FEA4 80240224 0260882D */  daddu     $s1, $s3, $zero
/* D2FEA8 80240228 8EA200B4 */  lw        $v0, 0xb4($s5)
/* D2FEAC 8024022C 3C038024 */  lui       $v1, %hi(D_80241AE0_D31760)
/* D2FEB0 80240230 24631AE0 */  addiu     $v1, $v1, %lo(D_80241AE0_D31760)
/* D2FEB4 80240234 AEB30078 */  sw        $s3, 0x78($s5)
/* D2FEB8 80240238 00021027 */  nor       $v0, $zero, $v0
/* D2FEBC 8024023C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* D2FEC0 80240240 00171080 */  sll       $v0, $s7, 2
/* D2FEC4 80240244 00431021 */  addu      $v0, $v0, $v1
/* D2FEC8 80240248 AFA20010 */  sw        $v0, 0x10($sp)
.L8024024C:
/* D2FECC 8024024C 86900000 */  lh        $s0, ($s4)
/* D2FED0 80240250 001010C0 */  sll       $v0, $s0, 3
/* D2FED4 80240254 03C21021 */  addu      $v0, $fp, $v0
/* D2FED8 80240258 90420014 */  lbu       $v0, 0x14($v0)
/* D2FEDC 8024025C 5040002E */  beql      $v0, $zero, .L80240318
/* D2FEE0 80240260 26520001 */   addiu    $s2, $s2, 1
/* D2FEE4 80240264 00101100 */  sll       $v0, $s0, 4
/* D2FEE8 80240268 3C068009 */  lui       $a2, %hi(D_8008EF20)
/* D2FEEC 8024026C 24C6EF20 */  addiu     $a2, $a2, %lo(D_8008EF20)
/* D2FEF0 80240270 00461021 */  addu      $v0, $v0, $a2
/* D2FEF4 80240274 0200202D */  daddu     $a0, $s0, $zero
/* D2FEF8 80240278 AE300108 */  sw        $s0, 0x108($s1)
/* D2FEFC 8024027C 8C420000 */  lw        $v0, ($v0)
/* D2FF00 80240280 02E0282D */  daddu     $a1, $s7, $zero
/* D2FF04 80240284 0C090035 */  jal       func_802400D4_D2FD54
/* D2FF08 80240288 AE220084 */   sw       $v0, 0x84($s1)
/* D2FF0C 8024028C 0040202D */  daddu     $a0, $v0, $zero
/* D2FF10 80240290 04800011 */  bltz      $a0, .L802402D8
/* D2FF14 80240294 00101080 */   sll      $v0, $s0, 2
/* D2FF18 80240298 3C06800F */  lui       $a2, %hi(D_800F7F00)
/* D2FF1C 8024029C 24C67F00 */  addiu     $a2, $a2, %lo(D_800F7F00)
/* D2FF20 802402A0 00461021 */  addu      $v0, $v0, $a2
/* D2FF24 802402A4 8C430000 */  lw        $v1, ($v0)
/* D2FF28 802402A8 24020001 */  addiu     $v0, $zero, 1
/* D2FF2C 802402AC AE22018C */  sw        $v0, 0x18c($s1)
/* D2FF30 802402B0 00041080 */  sll       $v0, $a0, 2
/* D2FF34 802402B4 3C068024 */  lui       $a2, %hi(D_80241AF8_D31778)
/* D2FF38 802402B8 24C61AF8 */  addiu     $a2, $a2, %lo(D_80241AF8_D31778)
/* D2FF3C 802402BC AE230000 */  sw        $v1, ($s1)
/* D2FF40 802402C0 001218C0 */  sll       $v1, $s2, 3
/* D2FF44 802402C4 00431021 */  addu      $v0, $v0, $v1
/* D2FF48 802402C8 00461021 */  addu      $v0, $v0, $a2
/* D2FF4C 802402CC 8C420000 */  lw        $v0, ($v0)
/* D2FF50 802402D0 080900BF */  j         .L802402FC
/* D2FF54 802402D4 AE220294 */   sw       $v0, 0x294($s1)
.L802402D8:
/* D2FF58 802402D8 3C06800F */  lui       $a2, %hi(D_800F7F40)
/* D2FF5C 802402DC 24C67F40 */  addiu     $a2, $a2, %lo(D_800F7F40)
/* D2FF60 802402E0 00461021 */  addu      $v0, $v0, $a2
/* D2FF64 802402E4 8C420000 */  lw        $v0, ($v0)
/* D2FF68 802402E8 AE20018C */  sw        $zero, 0x18c($s1)
/* D2FF6C 802402EC AE220000 */  sw        $v0, ($s1)
/* D2FF70 802402F0 8FA60010 */  lw        $a2, 0x10($sp)
/* D2FF74 802402F4 8CC20000 */  lw        $v0, ($a2)
/* D2FF78 802402F8 AE220294 */  sw        $v0, 0x294($s1)
.L802402FC:
/* D2FF7C 802402FC 001010C0 */  sll       $v0, $s0, 3
/* D2FF80 80240300 03C21021 */  addu      $v0, $fp, $v0
/* D2FF84 80240304 80420015 */  lb        $v0, 0x15($v0)
/* D2FF88 80240308 26D60001 */  addiu     $s6, $s6, 1
/* D2FF8C 8024030C AE220210 */  sw        $v0, 0x210($s1)
/* D2FF90 80240310 26310004 */  addiu     $s1, $s1, 4
/* D2FF94 80240314 26520001 */  addiu     $s2, $s2, 1
.L80240318:
/* D2FF98 80240318 2A420008 */  slti      $v0, $s2, 8
/* D2FF9C 8024031C 1440FFCB */  bnez      $v0, .L8024024C
/* D2FFA0 80240320 26940002 */   addiu    $s4, $s4, 2
/* D2FFA4 80240324 0260202D */  daddu     $a0, $s3, $zero
/* D2FFA8 80240328 24020004 */  addiu     $v0, $zero, 4
/* D2FFAC 8024032C AC820318 */  sw        $v0, 0x318($a0)
/* D2FFB0 80240330 AC960324 */  sw        $s6, 0x324($a0)
/* D2FFB4 80240334 0C03D390 */  jal       func_800F4E40
/* D2FFB8 80240338 AC800328 */   sw       $zero, 0x328($a0)
/* D2FFBC 8024033C AEA00070 */  sw        $zero, 0x70($s5)
.L80240340:
/* D2FFC0 80240340 8EA20070 */  lw        $v0, 0x70($s5)
/* D2FFC4 80240344 8EB30078 */  lw        $s3, 0x78($s5)
/* D2FFC8 80240348 14400008 */  bnez      $v0, .L8024036C
/* D2FFCC 8024034C 24420001 */   addiu    $v0, $v0, 1
/* D2FFD0 80240350 8662032C */  lh        $v0, 0x32c($s3)
/* D2FFD4 80240354 10400009 */  beqz      $v0, .L8024037C
/* D2FFD8 80240358 AEA20074 */   sw       $v0, 0x74($s5)
/* D2FFDC 8024035C 0C03C4EC */  jal       func_800F13B0
/* D2FFE0 80240360 00000000 */   nop
/* D2FFE4 80240364 8EA20070 */  lw        $v0, 0x70($s5)
/* D2FFE8 80240368 24420001 */  addiu     $v0, $v0, 1
.L8024036C:
/* D2FFEC 8024036C AEA20070 */  sw        $v0, 0x70($s5)
/* D2FFF0 80240370 2842000F */  slti      $v0, $v0, 0xf
/* D2FFF4 80240374 10400003 */  beqz      $v0, .L80240384
/* D2FFF8 80240378 00000000 */   nop
.L8024037C:
/* D2FFFC 8024037C 080900FB */  j         .L802403EC
/* D30000 80240380 0000102D */   daddu    $v0, $zero, $zero
.L80240384:
/* D30004 80240384 0C03C54E */  jal       func_800F1538
/* D30008 80240388 00000000 */   nop
/* D3000C 8024038C 8EA30074 */  lw        $v1, 0x74($s5)
/* D30010 80240390 240200FF */  addiu     $v0, $zero, 0xff
/* D30014 80240394 10620010 */  beq       $v1, $v0, .L802403D8
/* D30018 80240398 2462FFFF */   addiu    $v0, $v1, -1
/* D3001C 8024039C 00021080 */  sll       $v0, $v0, 2
/* D30020 802403A0 02621021 */  addu      $v0, $s3, $v0
/* D30024 802403A4 8C420108 */  lw        $v0, 0x108($v0)
/* D30028 802403A8 00021100 */  sll       $v0, $v0, 4
/* D3002C 802403AC 3C038009 */  lui       $v1, %hi(D_8008EF20)
/* D30030 802403B0 00621821 */  addu      $v1, $v1, $v0
/* D30034 802403B4 8C63EF20 */  lw        $v1, %lo(D_8008EF20)($v1)
/* D30038 802403B8 8EA20074 */  lw        $v0, 0x74($s5)
/* D3003C 802403BC 2442FFFF */  addiu     $v0, $v0, -1
/* D30040 802403C0 00021080 */  sll       $v0, $v0, 2
/* D30044 802403C4 02621021 */  addu      $v0, $s3, $v0
/* D30048 802403C8 AEA30084 */  sw        $v1, 0x84($s5)
/* D3004C 802403CC 8C420108 */  lw        $v0, 0x108($v0)
/* D30050 802403D0 080900F8 */  j         .L802403E0
/* D30054 802403D4 AEA20088 */   sw       $v0, 0x88($s5)
.L802403D8:
/* D30058 802403D8 2402FFFF */  addiu     $v0, $zero, -1
/* D3005C 802403DC AEA20084 */  sw        $v0, 0x84($s5)
.L802403E0:
/* D30060 802403E0 0C00AB4B */  jal       heap_free
/* D30064 802403E4 8EA40078 */   lw       $a0, 0x78($s5)
/* D30068 802403E8 24020002 */  addiu     $v0, $zero, 2
.L802403EC:
/* D3006C 802403EC 8FBF003C */  lw        $ra, 0x3c($sp)
/* D30070 802403F0 8FBE0038 */  lw        $fp, 0x38($sp)
/* D30074 802403F4 8FB70034 */  lw        $s7, 0x34($sp)
/* D30078 802403F8 8FB60030 */  lw        $s6, 0x30($sp)
/* D3007C 802403FC 8FB5002C */  lw        $s5, 0x2c($sp)
/* D30080 80240400 8FB40028 */  lw        $s4, 0x28($sp)
/* D30084 80240404 8FB30024 */  lw        $s3, 0x24($sp)
/* D30088 80240408 8FB20020 */  lw        $s2, 0x20($sp)
/* D3008C 8024040C 8FB1001C */  lw        $s1, 0x1c($sp)
/* D30090 80240410 8FB00018 */  lw        $s0, 0x18($sp)
/* D30094 80240414 03E00008 */  jr        $ra
/* D30098 80240418 27BD0040 */   addiu    $sp, $sp, 0x40
