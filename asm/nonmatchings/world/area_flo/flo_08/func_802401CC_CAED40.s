.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401CC_CAEF0C
/* CAEF0C 802401CC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* CAEF10 802401D0 AFB5002C */  sw        $s5, 0x2c($sp)
/* CAEF14 802401D4 0080A82D */  daddu     $s5, $a0, $zero
/* CAEF18 802401D8 AFBE0038 */  sw        $fp, 0x38($sp)
/* CAEF1C 802401DC 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* CAEF20 802401E0 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* CAEF24 802401E4 AFBF003C */  sw        $ra, 0x3c($sp)
/* CAEF28 802401E8 AFB70034 */  sw        $s7, 0x34($sp)
/* CAEF2C 802401EC AFB60030 */  sw        $s6, 0x30($sp)
/* CAEF30 802401F0 AFB40028 */  sw        $s4, 0x28($sp)
/* CAEF34 802401F4 AFB30024 */  sw        $s3, 0x24($sp)
/* CAEF38 802401F8 AFB20020 */  sw        $s2, 0x20($sp)
/* CAEF3C 802401FC AFB1001C */  sw        $s1, 0x1c($sp)
/* CAEF40 80240200 10A0004F */  beqz      $a1, .L80240340
/* CAEF44 80240204 AFB00018 */   sw       $s0, 0x18($sp)
/* CAEF48 80240208 0C00AB39 */  jal       heap_malloc
/* CAEF4C 8024020C 24040330 */   addiu    $a0, $zero, 0x330
/* CAEF50 80240210 0040982D */  daddu     $s3, $v0, $zero
/* CAEF54 80240214 0000B02D */  daddu     $s6, $zero, $zero
/* CAEF58 80240218 02C0902D */  daddu     $s2, $s6, $zero
/* CAEF5C 8024021C 3C148024 */  lui       $s4, 0x8024
/* CAEF60 80240220 26941FB8 */  addiu     $s4, $s4, 0x1fb8
/* CAEF64 80240224 0260882D */  daddu     $s1, $s3, $zero
/* CAEF68 80240228 8EA200B4 */  lw        $v0, 0xb4($s5)
/* CAEF6C 8024022C 3C038024 */  lui       $v1, 0x8024
/* CAEF70 80240230 24631FB0 */  addiu     $v1, $v1, 0x1fb0
/* CAEF74 80240234 AEB30078 */  sw        $s3, 0x78($s5)
/* CAEF78 80240238 00021027 */  nor       $v0, $zero, $v0
/* CAEF7C 8024023C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* CAEF80 80240240 00171080 */  sll       $v0, $s7, 2
/* CAEF84 80240244 00431021 */  addu      $v0, $v0, $v1
/* CAEF88 80240248 AFA20010 */  sw        $v0, 0x10($sp)
.L8024024C:
/* CAEF8C 8024024C 86900000 */  lh        $s0, ($s4)
/* CAEF90 80240250 001010C0 */  sll       $v0, $s0, 3
/* CAEF94 80240254 03C21021 */  addu      $v0, $fp, $v0
/* CAEF98 80240258 90420014 */  lbu       $v0, 0x14($v0)
/* CAEF9C 8024025C 5040002E */  beql      $v0, $zero, .L80240318
/* CAEFA0 80240260 26520001 */   addiu    $s2, $s2, 1
/* CAEFA4 80240264 00101100 */  sll       $v0, $s0, 4
/* CAEFA8 80240268 3C068009 */  lui       $a2, 0x8009
/* CAEFAC 8024026C 24C6EF20 */  addiu     $a2, $a2, -0x10e0
/* CAEFB0 80240270 00461021 */  addu      $v0, $v0, $a2
/* CAEFB4 80240274 0200202D */  daddu     $a0, $s0, $zero
/* CAEFB8 80240278 AE300108 */  sw        $s0, 0x108($s1)
/* CAEFBC 8024027C 8C420000 */  lw        $v0, ($v0)
/* CAEFC0 80240280 02E0282D */  daddu     $a1, $s7, $zero
/* CAEFC4 80240284 0C090035 */  jal       func_802400D4
/* CAEFC8 80240288 AE220084 */   sw       $v0, 0x84($s1)
/* CAEFCC 8024028C 0040202D */  daddu     $a0, $v0, $zero
/* CAEFD0 80240290 04800011 */  bltz      $a0, .L802402D8
/* CAEFD4 80240294 00101080 */   sll      $v0, $s0, 2
/* CAEFD8 80240298 3C06800F */  lui       $a2, 0x800f
/* CAEFDC 8024029C 24C67F00 */  addiu     $a2, $a2, 0x7f00
/* CAEFE0 802402A0 00461021 */  addu      $v0, $v0, $a2
/* CAEFE4 802402A4 8C430000 */  lw        $v1, ($v0)
/* CAEFE8 802402A8 24020001 */  addiu     $v0, $zero, 1
/* CAEFEC 802402AC AE22018C */  sw        $v0, 0x18c($s1)
/* CAEFF0 802402B0 00041080 */  sll       $v0, $a0, 2
/* CAEFF4 802402B4 3C068024 */  lui       $a2, 0x8024
/* CAEFF8 802402B8 24C61FC8 */  addiu     $a2, $a2, 0x1fc8
/* CAEFFC 802402BC AE230000 */  sw        $v1, ($s1)
/* CAF000 802402C0 001218C0 */  sll       $v1, $s2, 3
/* CAF004 802402C4 00431021 */  addu      $v0, $v0, $v1
/* CAF008 802402C8 00461021 */  addu      $v0, $v0, $a2
/* CAF00C 802402CC 8C420000 */  lw        $v0, ($v0)
/* CAF010 802402D0 080900BF */  j         .L802402FC
/* CAF014 802402D4 AE220294 */   sw       $v0, 0x294($s1)
.L802402D8:
/* CAF018 802402D8 3C06800F */  lui       $a2, 0x800f
/* CAF01C 802402DC 24C67F40 */  addiu     $a2, $a2, 0x7f40
/* CAF020 802402E0 00461021 */  addu      $v0, $v0, $a2
/* CAF024 802402E4 8C420000 */  lw        $v0, ($v0)
/* CAF028 802402E8 AE20018C */  sw        $zero, 0x18c($s1)
/* CAF02C 802402EC AE220000 */  sw        $v0, ($s1)
/* CAF030 802402F0 8FA60010 */  lw        $a2, 0x10($sp)
/* CAF034 802402F4 8CC20000 */  lw        $v0, ($a2)
/* CAF038 802402F8 AE220294 */  sw        $v0, 0x294($s1)
.L802402FC:
/* CAF03C 802402FC 001010C0 */  sll       $v0, $s0, 3
/* CAF040 80240300 03C21021 */  addu      $v0, $fp, $v0
/* CAF044 80240304 80420015 */  lb        $v0, 0x15($v0)
/* CAF048 80240308 26D60001 */  addiu     $s6, $s6, 1
/* CAF04C 8024030C AE220210 */  sw        $v0, 0x210($s1)
/* CAF050 80240310 26310004 */  addiu     $s1, $s1, 4
/* CAF054 80240314 26520001 */  addiu     $s2, $s2, 1
.L80240318:
/* CAF058 80240318 2A420008 */  slti      $v0, $s2, 8
/* CAF05C 8024031C 1440FFCB */  bnez      $v0, .L8024024C
/* CAF060 80240320 26940002 */   addiu    $s4, $s4, 2
/* CAF064 80240324 0260202D */  daddu     $a0, $s3, $zero
/* CAF068 80240328 24020004 */  addiu     $v0, $zero, 4
/* CAF06C 8024032C AC820318 */  sw        $v0, 0x318($a0)
/* CAF070 80240330 AC960324 */  sw        $s6, 0x324($a0)
/* CAF074 80240334 0C03D390 */  jal       func_800F4E40
/* CAF078 80240338 AC800328 */   sw       $zero, 0x328($a0)
/* CAF07C 8024033C AEA00070 */  sw        $zero, 0x70($s5)
.L80240340:
/* CAF080 80240340 8EA20070 */  lw        $v0, 0x70($s5)
/* CAF084 80240344 8EB30078 */  lw        $s3, 0x78($s5)
/* CAF088 80240348 14400008 */  bnez      $v0, .L8024036C
/* CAF08C 8024034C 24420001 */   addiu    $v0, $v0, 1
/* CAF090 80240350 8662032C */  lh        $v0, 0x32c($s3)
/* CAF094 80240354 10400009 */  beqz      $v0, .L8024037C
/* CAF098 80240358 AEA20074 */   sw       $v0, 0x74($s5)
/* CAF09C 8024035C 0C03C4EC */  jal       func_800F13B0
/* CAF0A0 80240360 00000000 */   nop      
/* CAF0A4 80240364 8EA20070 */  lw        $v0, 0x70($s5)
/* CAF0A8 80240368 24420001 */  addiu     $v0, $v0, 1
.L8024036C:
/* CAF0AC 8024036C AEA20070 */  sw        $v0, 0x70($s5)
/* CAF0B0 80240370 2842000F */  slti      $v0, $v0, 0xf
/* CAF0B4 80240374 10400003 */  beqz      $v0, .L80240384
/* CAF0B8 80240378 00000000 */   nop      
.L8024037C:
/* CAF0BC 8024037C 080900FB */  j         .L802403EC
/* CAF0C0 80240380 0000102D */   daddu    $v0, $zero, $zero
.L80240384:
/* CAF0C4 80240384 0C03C54E */  jal       func_800F1538
/* CAF0C8 80240388 00000000 */   nop      
/* CAF0CC 8024038C 8EA30074 */  lw        $v1, 0x74($s5)
/* CAF0D0 80240390 240200FF */  addiu     $v0, $zero, 0xff
/* CAF0D4 80240394 10620010 */  beq       $v1, $v0, .L802403D8
/* CAF0D8 80240398 2462FFFF */   addiu    $v0, $v1, -1
/* CAF0DC 8024039C 00021080 */  sll       $v0, $v0, 2
/* CAF0E0 802403A0 02621021 */  addu      $v0, $s3, $v0
/* CAF0E4 802403A4 8C420108 */  lw        $v0, 0x108($v0)
/* CAF0E8 802403A8 00021100 */  sll       $v0, $v0, 4
/* CAF0EC 802403AC 3C038009 */  lui       $v1, 0x8009
/* CAF0F0 802403B0 00621821 */  addu      $v1, $v1, $v0
/* CAF0F4 802403B4 8C63EF20 */  lw        $v1, -0x10e0($v1)
/* CAF0F8 802403B8 8EA20074 */  lw        $v0, 0x74($s5)
/* CAF0FC 802403BC 2442FFFF */  addiu     $v0, $v0, -1
/* CAF100 802403C0 00021080 */  sll       $v0, $v0, 2
/* CAF104 802403C4 02621021 */  addu      $v0, $s3, $v0
/* CAF108 802403C8 AEA30084 */  sw        $v1, 0x84($s5)
/* CAF10C 802403CC 8C420108 */  lw        $v0, 0x108($v0)
/* CAF110 802403D0 080900F8 */  j         .L802403E0
/* CAF114 802403D4 AEA20088 */   sw       $v0, 0x88($s5)
.L802403D8:
/* CAF118 802403D8 2402FFFF */  addiu     $v0, $zero, -1
/* CAF11C 802403DC AEA20084 */  sw        $v0, 0x84($s5)
.L802403E0:
/* CAF120 802403E0 0C00AB4B */  jal       heap_free
/* CAF124 802403E4 8EA40078 */   lw       $a0, 0x78($s5)
/* CAF128 802403E8 24020002 */  addiu     $v0, $zero, 2
.L802403EC:
/* CAF12C 802403EC 8FBF003C */  lw        $ra, 0x3c($sp)
/* CAF130 802403F0 8FBE0038 */  lw        $fp, 0x38($sp)
/* CAF134 802403F4 8FB70034 */  lw        $s7, 0x34($sp)
/* CAF138 802403F8 8FB60030 */  lw        $s6, 0x30($sp)
/* CAF13C 802403FC 8FB5002C */  lw        $s5, 0x2c($sp)
/* CAF140 80240400 8FB40028 */  lw        $s4, 0x28($sp)
/* CAF144 80240404 8FB30024 */  lw        $s3, 0x24($sp)
/* CAF148 80240408 8FB20020 */  lw        $s2, 0x20($sp)
/* CAF14C 8024040C 8FB1001C */  lw        $s1, 0x1c($sp)
/* CAF150 80240410 8FB00018 */  lw        $s0, 0x18($sp)
/* CAF154 80240414 03E00008 */  jr        $ra
/* CAF158 80240418 27BD0040 */   addiu    $sp, $sp, 0x40
