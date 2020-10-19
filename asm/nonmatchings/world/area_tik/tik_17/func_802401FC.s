.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401FC
/* 892C1C 802401FC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 892C20 80240200 AFB5002C */  sw        $s5, 0x2c($sp)
/* 892C24 80240204 0080A82D */  daddu     $s5, $a0, $zero
/* 892C28 80240208 AFBE0038 */  sw        $fp, 0x38($sp)
/* 892C2C 8024020C 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* 892C30 80240210 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* 892C34 80240214 AFBF003C */  sw        $ra, 0x3c($sp)
/* 892C38 80240218 AFB70034 */  sw        $s7, 0x34($sp)
/* 892C3C 8024021C AFB60030 */  sw        $s6, 0x30($sp)
/* 892C40 80240220 AFB40028 */  sw        $s4, 0x28($sp)
/* 892C44 80240224 AFB30024 */  sw        $s3, 0x24($sp)
/* 892C48 80240228 AFB20020 */  sw        $s2, 0x20($sp)
/* 892C4C 8024022C AFB1001C */  sw        $s1, 0x1c($sp)
/* 892C50 80240230 10A0004F */  beqz      $a1, .L80240370
/* 892C54 80240234 AFB00018 */   sw       $s0, 0x18($sp)
/* 892C58 80240238 0C00AB39 */  jal       heap_malloc
/* 892C5C 8024023C 24040330 */   addiu    $a0, $zero, 0x330
/* 892C60 80240240 0040982D */  daddu     $s3, $v0, $zero
/* 892C64 80240244 0000B02D */  daddu     $s6, $zero, $zero
/* 892C68 80240248 02C0902D */  daddu     $s2, $s6, $zero
/* 892C6C 8024024C 3C148024 */  lui       $s4, 0x8024
/* 892C70 80240250 26941428 */  addiu     $s4, $s4, 0x1428
/* 892C74 80240254 0260882D */  daddu     $s1, $s3, $zero
/* 892C78 80240258 8EA200B4 */  lw        $v0, 0xb4($s5)
/* 892C7C 8024025C 3C038024 */  lui       $v1, 0x8024
/* 892C80 80240260 24631420 */  addiu     $v1, $v1, 0x1420
/* 892C84 80240264 AEB30078 */  sw        $s3, 0x78($s5)
/* 892C88 80240268 00021027 */  nor       $v0, $zero, $v0
/* 892C8C 8024026C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* 892C90 80240270 00171080 */  sll       $v0, $s7, 2
/* 892C94 80240274 00431021 */  addu      $v0, $v0, $v1
/* 892C98 80240278 AFA20010 */  sw        $v0, 0x10($sp)
.L8024027C:
/* 892C9C 8024027C 86900000 */  lh        $s0, ($s4)
/* 892CA0 80240280 001010C0 */  sll       $v0, $s0, 3
/* 892CA4 80240284 03C21021 */  addu      $v0, $fp, $v0
/* 892CA8 80240288 90420014 */  lbu       $v0, 0x14($v0)
/* 892CAC 8024028C 5040002E */  beql      $v0, $zero, .L80240348
/* 892CB0 80240290 26520001 */   addiu    $s2, $s2, 1
/* 892CB4 80240294 00101100 */  sll       $v0, $s0, 4
/* 892CB8 80240298 3C068009 */  lui       $a2, 0x8009
/* 892CBC 8024029C 24C6EF20 */  addiu     $a2, $a2, -0x10e0
/* 892CC0 802402A0 00461021 */  addu      $v0, $v0, $a2
/* 892CC4 802402A4 0200202D */  daddu     $a0, $s0, $zero
/* 892CC8 802402A8 AE300108 */  sw        $s0, 0x108($s1)
/* 892CCC 802402AC 8C420000 */  lw        $v0, ($v0)
/* 892CD0 802402B0 02E0282D */  daddu     $a1, $s7, $zero
/* 892CD4 802402B4 0C090041 */  jal       func_80240104
/* 892CD8 802402B8 AE220084 */   sw       $v0, 0x84($s1)
/* 892CDC 802402BC 0040202D */  daddu     $a0, $v0, $zero
/* 892CE0 802402C0 04800011 */  bltz      $a0, .L80240308
/* 892CE4 802402C4 00101080 */   sll      $v0, $s0, 2
/* 892CE8 802402C8 3C06800F */  lui       $a2, 0x800f
/* 892CEC 802402CC 24C67F00 */  addiu     $a2, $a2, 0x7f00
/* 892CF0 802402D0 00461021 */  addu      $v0, $v0, $a2
/* 892CF4 802402D4 8C430000 */  lw        $v1, ($v0)
/* 892CF8 802402D8 24020001 */  addiu     $v0, $zero, 1
/* 892CFC 802402DC AE22018C */  sw        $v0, 0x18c($s1)
/* 892D00 802402E0 00041080 */  sll       $v0, $a0, 2
/* 892D04 802402E4 3C068024 */  lui       $a2, 0x8024
/* 892D08 802402E8 24C61438 */  addiu     $a2, $a2, 0x1438
/* 892D0C 802402EC AE230000 */  sw        $v1, ($s1)
/* 892D10 802402F0 001218C0 */  sll       $v1, $s2, 3
/* 892D14 802402F4 00431021 */  addu      $v0, $v0, $v1
/* 892D18 802402F8 00461021 */  addu      $v0, $v0, $a2
/* 892D1C 802402FC 8C420000 */  lw        $v0, ($v0)
/* 892D20 80240300 080900CB */  j         .L8024032C
/* 892D24 80240304 AE220294 */   sw       $v0, 0x294($s1)
.L80240308:
/* 892D28 80240308 3C06800F */  lui       $a2, 0x800f
/* 892D2C 8024030C 24C67F40 */  addiu     $a2, $a2, 0x7f40
/* 892D30 80240310 00461021 */  addu      $v0, $v0, $a2
/* 892D34 80240314 8C420000 */  lw        $v0, ($v0)
/* 892D38 80240318 AE20018C */  sw        $zero, 0x18c($s1)
/* 892D3C 8024031C AE220000 */  sw        $v0, ($s1)
/* 892D40 80240320 8FA60010 */  lw        $a2, 0x10($sp)
/* 892D44 80240324 8CC20000 */  lw        $v0, ($a2)
/* 892D48 80240328 AE220294 */  sw        $v0, 0x294($s1)
.L8024032C:
/* 892D4C 8024032C 001010C0 */  sll       $v0, $s0, 3
/* 892D50 80240330 03C21021 */  addu      $v0, $fp, $v0
/* 892D54 80240334 80420015 */  lb        $v0, 0x15($v0)
/* 892D58 80240338 26D60001 */  addiu     $s6, $s6, 1
/* 892D5C 8024033C AE220210 */  sw        $v0, 0x210($s1)
/* 892D60 80240340 26310004 */  addiu     $s1, $s1, 4
/* 892D64 80240344 26520001 */  addiu     $s2, $s2, 1
.L80240348:
/* 892D68 80240348 2A420008 */  slti      $v0, $s2, 8
/* 892D6C 8024034C 1440FFCB */  bnez      $v0, .L8024027C
/* 892D70 80240350 26940002 */   addiu    $s4, $s4, 2
/* 892D74 80240354 0260202D */  daddu     $a0, $s3, $zero
/* 892D78 80240358 24020004 */  addiu     $v0, $zero, 4
/* 892D7C 8024035C AC820318 */  sw        $v0, 0x318($a0)
/* 892D80 80240360 AC960324 */  sw        $s6, 0x324($a0)
/* 892D84 80240364 0C03D390 */  jal       func_800F4E40
/* 892D88 80240368 AC800328 */   sw       $zero, 0x328($a0)
/* 892D8C 8024036C AEA00070 */  sw        $zero, 0x70($s5)
.L80240370:
/* 892D90 80240370 8EA20070 */  lw        $v0, 0x70($s5)
/* 892D94 80240374 8EB30078 */  lw        $s3, 0x78($s5)
/* 892D98 80240378 14400008 */  bnez      $v0, .L8024039C
/* 892D9C 8024037C 24420001 */   addiu    $v0, $v0, 1
/* 892DA0 80240380 8662032C */  lh        $v0, 0x32c($s3)
/* 892DA4 80240384 10400009 */  beqz      $v0, .L802403AC
/* 892DA8 80240388 AEA20074 */   sw       $v0, 0x74($s5)
/* 892DAC 8024038C 0C03C4EC */  jal       func_800F13B0
/* 892DB0 80240390 00000000 */   nop      
/* 892DB4 80240394 8EA20070 */  lw        $v0, 0x70($s5)
/* 892DB8 80240398 24420001 */  addiu     $v0, $v0, 1
.L8024039C:
/* 892DBC 8024039C AEA20070 */  sw        $v0, 0x70($s5)
/* 892DC0 802403A0 2842000F */  slti      $v0, $v0, 0xf
/* 892DC4 802403A4 10400003 */  beqz      $v0, .L802403B4
/* 892DC8 802403A8 00000000 */   nop      
.L802403AC:
/* 892DCC 802403AC 08090107 */  j         .L8024041C
/* 892DD0 802403B0 0000102D */   daddu    $v0, $zero, $zero
.L802403B4:
/* 892DD4 802403B4 0C03C54E */  jal       func_800F1538
/* 892DD8 802403B8 00000000 */   nop      
/* 892DDC 802403BC 8EA30074 */  lw        $v1, 0x74($s5)
/* 892DE0 802403C0 240200FF */  addiu     $v0, $zero, 0xff
/* 892DE4 802403C4 10620010 */  beq       $v1, $v0, .L80240408
/* 892DE8 802403C8 2462FFFF */   addiu    $v0, $v1, -1
/* 892DEC 802403CC 00021080 */  sll       $v0, $v0, 2
/* 892DF0 802403D0 02621021 */  addu      $v0, $s3, $v0
/* 892DF4 802403D4 8C420108 */  lw        $v0, 0x108($v0)
/* 892DF8 802403D8 00021100 */  sll       $v0, $v0, 4
/* 892DFC 802403DC 3C038009 */  lui       $v1, 0x8009
/* 892E00 802403E0 00621821 */  addu      $v1, $v1, $v0
/* 892E04 802403E4 8C63EF20 */  lw        $v1, -0x10e0($v1)
/* 892E08 802403E8 8EA20074 */  lw        $v0, 0x74($s5)
/* 892E0C 802403EC 2442FFFF */  addiu     $v0, $v0, -1
/* 892E10 802403F0 00021080 */  sll       $v0, $v0, 2
/* 892E14 802403F4 02621021 */  addu      $v0, $s3, $v0
/* 892E18 802403F8 AEA30084 */  sw        $v1, 0x84($s5)
/* 892E1C 802403FC 8C420108 */  lw        $v0, 0x108($v0)
/* 892E20 80240400 08090104 */  j         .L80240410
/* 892E24 80240404 AEA20088 */   sw       $v0, 0x88($s5)
.L80240408:
/* 892E28 80240408 2402FFFF */  addiu     $v0, $zero, -1
/* 892E2C 8024040C AEA20084 */  sw        $v0, 0x84($s5)
.L80240410:
/* 892E30 80240410 0C00AB4B */  jal       heap_free
/* 892E34 80240414 8EA40078 */   lw       $a0, 0x78($s5)
/* 892E38 80240418 24020002 */  addiu     $v0, $zero, 2
.L8024041C:
/* 892E3C 8024041C 8FBF003C */  lw        $ra, 0x3c($sp)
/* 892E40 80240420 8FBE0038 */  lw        $fp, 0x38($sp)
/* 892E44 80240424 8FB70034 */  lw        $s7, 0x34($sp)
/* 892E48 80240428 8FB60030 */  lw        $s6, 0x30($sp)
/* 892E4C 8024042C 8FB5002C */  lw        $s5, 0x2c($sp)
/* 892E50 80240430 8FB40028 */  lw        $s4, 0x28($sp)
/* 892E54 80240434 8FB30024 */  lw        $s3, 0x24($sp)
/* 892E58 80240438 8FB20020 */  lw        $s2, 0x20($sp)
/* 892E5C 8024043C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 892E60 80240440 8FB00018 */  lw        $s0, 0x18($sp)
/* 892E64 80240444 03E00008 */  jr        $ra
/* 892E68 80240448 27BD0040 */   addiu    $sp, $sp, 0x40
