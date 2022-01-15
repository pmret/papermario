.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024024C_95420C
/* 95420C 8024024C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 954210 80240250 AFB5002C */  sw        $s5, 0x2c($sp)
/* 954214 80240254 0080A82D */  daddu     $s5, $a0, $zero
/* 954218 80240258 AFBE0038 */  sw        $fp, 0x38($sp)
/* 95421C 8024025C 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* 954220 80240260 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* 954224 80240264 AFBF003C */  sw        $ra, 0x3c($sp)
/* 954228 80240268 AFB70034 */  sw        $s7, 0x34($sp)
/* 95422C 8024026C AFB60030 */  sw        $s6, 0x30($sp)
/* 954230 80240270 AFB40028 */  sw        $s4, 0x28($sp)
/* 954234 80240274 AFB30024 */  sw        $s3, 0x24($sp)
/* 954238 80240278 AFB20020 */  sw        $s2, 0x20($sp)
/* 95423C 8024027C AFB1001C */  sw        $s1, 0x1c($sp)
/* 954240 80240280 10A0004F */  beqz      $a1, .L802403C0
/* 954244 80240284 AFB00018 */   sw       $s0, 0x18($sp)
/* 954248 80240288 0C00AB39 */  jal       heap_malloc
/* 95424C 8024028C 24040330 */   addiu    $a0, $zero, 0x330
/* 954250 80240290 0040982D */  daddu     $s3, $v0, $zero
/* 954254 80240294 0000B02D */  daddu     $s6, $zero, $zero
/* 954258 80240298 02C0902D */  daddu     $s2, $s6, $zero
/* 95425C 8024029C 3C148024 */  lui       $s4, %hi(D_80241438_9553F8)
/* 954260 802402A0 26941438 */  addiu     $s4, $s4, %lo(D_80241438_9553F8)
/* 954264 802402A4 0260882D */  daddu     $s1, $s3, $zero
/* 954268 802402A8 8EA200B4 */  lw        $v0, 0xb4($s5)
/* 95426C 802402AC 3C038024 */  lui       $v1, %hi(D_80241430_9553F0)
/* 954270 802402B0 24631430 */  addiu     $v1, $v1, %lo(D_80241430_9553F0)
/* 954274 802402B4 AEB30078 */  sw        $s3, 0x78($s5)
/* 954278 802402B8 00021027 */  nor       $v0, $zero, $v0
/* 95427C 802402BC 0002BFC2 */  srl       $s7, $v0, 0x1f
/* 954280 802402C0 00171080 */  sll       $v0, $s7, 2
/* 954284 802402C4 00431021 */  addu      $v0, $v0, $v1
/* 954288 802402C8 AFA20010 */  sw        $v0, 0x10($sp)
.L802402CC:
/* 95428C 802402CC 86900000 */  lh        $s0, ($s4)
/* 954290 802402D0 001010C0 */  sll       $v0, $s0, 3
/* 954294 802402D4 03C21021 */  addu      $v0, $fp, $v0
/* 954298 802402D8 90420014 */  lbu       $v0, 0x14($v0)
/* 95429C 802402DC 5040002E */  beql      $v0, $zero, .L80240398
/* 9542A0 802402E0 26520001 */   addiu    $s2, $s2, 1
/* 9542A4 802402E4 00101100 */  sll       $v0, $s0, 4
/* 9542A8 802402E8 3C068009 */  lui       $a2, %hi(gPartnerPopupProperties)
/* 9542AC 802402EC 24C6EF20 */  addiu     $a2, $a2, %lo(gPartnerPopupProperties)
/* 9542B0 802402F0 00461021 */  addu      $v0, $v0, $a2
/* 9542B4 802402F4 0200202D */  daddu     $a0, $s0, $zero
/* 9542B8 802402F8 AE300108 */  sw        $s0, 0x108($s1)
/* 9542BC 802402FC 8C420000 */  lw        $v0, ($v0)
/* 9542C0 80240300 02E0282D */  daddu     $a1, $s7, $zero
/* 9542C4 80240304 0C090055 */  jal       sbk_56_UnkFunc37
/* 9542C8 80240308 AE220084 */   sw       $v0, 0x84($s1)
/* 9542CC 8024030C 0040202D */  daddu     $a0, $v0, $zero
/* 9542D0 80240310 04800011 */  bltz      $a0, .L80240358
/* 9542D4 80240314 00101080 */   sll      $v0, $s0, 2
/* 9542D8 80240318 3C06800F */  lui       $a2, %hi(wPartnerHudScripts)
/* 9542DC 8024031C 24C67F00 */  addiu     $a2, $a2, %lo(wPartnerHudScripts)
/* 9542E0 80240320 00461021 */  addu      $v0, $v0, $a2
/* 9542E4 80240324 8C430000 */  lw        $v1, ($v0)
/* 9542E8 80240328 24020001 */  addiu     $v0, $zero, 1
/* 9542EC 8024032C AE22018C */  sw        $v0, 0x18c($s1)
/* 9542F0 80240330 00041080 */  sll       $v0, $a0, 2
/* 9542F4 80240334 3C068024 */  lui       $a2, %hi(D_80241448_955408)
/* 9542F8 80240338 24C61448 */  addiu     $a2, $a2, %lo(D_80241448_955408)
/* 9542FC 8024033C AE230000 */  sw        $v1, ($s1)
/* 954300 80240340 001218C0 */  sll       $v1, $s2, 3
/* 954304 80240344 00431021 */  addu      $v0, $v0, $v1
/* 954308 80240348 00461021 */  addu      $v0, $v0, $a2
/* 95430C 8024034C 8C420000 */  lw        $v0, ($v0)
/* 954310 80240350 080900DF */  j         .L8024037C
/* 954314 80240354 AE220294 */   sw       $v0, 0x294($s1)
.L80240358:
/* 954318 80240358 3C06800F */  lui       $a2, %hi(wDisabledPartnerHudScripts)
/* 95431C 8024035C 24C67F40 */  addiu     $a2, $a2, %lo(wDisabledPartnerHudScripts)
/* 954320 80240360 00461021 */  addu      $v0, $v0, $a2
/* 954324 80240364 8C420000 */  lw        $v0, ($v0)
/* 954328 80240368 AE20018C */  sw        $zero, 0x18c($s1)
/* 95432C 8024036C AE220000 */  sw        $v0, ($s1)
/* 954330 80240370 8FA60010 */  lw        $a2, 0x10($sp)
/* 954334 80240374 8CC20000 */  lw        $v0, ($a2)
/* 954338 80240378 AE220294 */  sw        $v0, 0x294($s1)
.L8024037C:
/* 95433C 8024037C 001010C0 */  sll       $v0, $s0, 3
/* 954340 80240380 03C21021 */  addu      $v0, $fp, $v0
/* 954344 80240384 80420015 */  lb        $v0, 0x15($v0)
/* 954348 80240388 26D60001 */  addiu     $s6, $s6, 1
/* 95434C 8024038C AE220210 */  sw        $v0, 0x210($s1)
/* 954350 80240390 26310004 */  addiu     $s1, $s1, 4
/* 954354 80240394 26520001 */  addiu     $s2, $s2, 1
.L80240398:
/* 954358 80240398 2A420008 */  slti      $v0, $s2, 8
/* 95435C 8024039C 1440FFCB */  bnez      $v0, .L802402CC
/* 954360 802403A0 26940002 */   addiu    $s4, $s4, 2
/* 954364 802403A4 0260202D */  daddu     $a0, $s3, $zero
/* 954368 802403A8 24020004 */  addiu     $v0, $zero, 4
/* 95436C 802403AC AC820318 */  sw        $v0, 0x318($a0)
/* 954370 802403B0 AC960324 */  sw        $s6, 0x324($a0)
/* 954374 802403B4 0C03D390 */  jal       create_popup_menu
/* 954378 802403B8 AC800328 */   sw       $zero, 0x328($a0)
/* 95437C 802403BC AEA00070 */  sw        $zero, 0x70($s5)
.L802403C0:
/* 954380 802403C0 8EA20070 */  lw        $v0, 0x70($s5)
/* 954384 802403C4 8EB30078 */  lw        $s3, 0x78($s5)
/* 954388 802403C8 14400008 */  bnez      $v0, .L802403EC
/* 95438C 802403CC 24420001 */   addiu    $v0, $v0, 1
/* 954390 802403D0 8662032C */  lh        $v0, 0x32c($s3)
/* 954394 802403D4 10400009 */  beqz      $v0, .L802403FC
/* 954398 802403D8 AEA20074 */   sw       $v0, 0x74($s5)
/* 95439C 802403DC 0C03C4EC */  jal       hide_popup_menu
/* 9543A0 802403E0 00000000 */   nop
/* 9543A4 802403E4 8EA20070 */  lw        $v0, 0x70($s5)
/* 9543A8 802403E8 24420001 */  addiu     $v0, $v0, 1
.L802403EC:
/* 9543AC 802403EC AEA20070 */  sw        $v0, 0x70($s5)
/* 9543B0 802403F0 2842000F */  slti      $v0, $v0, 0xf
/* 9543B4 802403F4 10400003 */  beqz      $v0, .L80240404
/* 9543B8 802403F8 00000000 */   nop
.L802403FC:
/* 9543BC 802403FC 0809011B */  j         .L8024046C
/* 9543C0 80240400 0000102D */   daddu    $v0, $zero, $zero
.L80240404:
/* 9543C4 80240404 0C03C54E */  jal       destroy_popup_menu
/* 9543C8 80240408 00000000 */   nop
/* 9543CC 8024040C 8EA30074 */  lw        $v1, 0x74($s5)
/* 9543D0 80240410 240200FF */  addiu     $v0, $zero, 0xff
/* 9543D4 80240414 10620010 */  beq       $v1, $v0, .L80240458
/* 9543D8 80240418 2462FFFF */   addiu    $v0, $v1, -1
/* 9543DC 8024041C 00021080 */  sll       $v0, $v0, 2
/* 9543E0 80240420 02621021 */  addu      $v0, $s3, $v0
/* 9543E4 80240424 8C420108 */  lw        $v0, 0x108($v0)
/* 9543E8 80240428 00021100 */  sll       $v0, $v0, 4
/* 9543EC 8024042C 3C038009 */  lui       $v1, %hi(gPartnerPopupProperties)
/* 9543F0 80240430 00621821 */  addu      $v1, $v1, $v0
/* 9543F4 80240434 8C63EF20 */  lw        $v1, %lo(gPartnerPopupProperties)($v1)
/* 9543F8 80240438 8EA20074 */  lw        $v0, 0x74($s5)
/* 9543FC 8024043C 2442FFFF */  addiu     $v0, $v0, -1
/* 954400 80240440 00021080 */  sll       $v0, $v0, 2
/* 954404 80240444 02621021 */  addu      $v0, $s3, $v0
/* 954408 80240448 AEA30084 */  sw        $v1, 0x84($s5)
/* 95440C 8024044C 8C420108 */  lw        $v0, 0x108($v0)
/* 954410 80240450 08090118 */  j         .L80240460
/* 954414 80240454 AEA20088 */   sw       $v0, 0x88($s5)
.L80240458:
/* 954418 80240458 2402FFFF */  addiu     $v0, $zero, -1
/* 95441C 8024045C AEA20084 */  sw        $v0, 0x84($s5)
.L80240460:
/* 954420 80240460 0C00AB4B */  jal       heap_free
/* 954424 80240464 8EA40078 */   lw       $a0, 0x78($s5)
/* 954428 80240468 24020002 */  addiu     $v0, $zero, 2
.L8024046C:
/* 95442C 8024046C 8FBF003C */  lw        $ra, 0x3c($sp)
/* 954430 80240470 8FBE0038 */  lw        $fp, 0x38($sp)
/* 954434 80240474 8FB70034 */  lw        $s7, 0x34($sp)
/* 954438 80240478 8FB60030 */  lw        $s6, 0x30($sp)
/* 95443C 8024047C 8FB5002C */  lw        $s5, 0x2c($sp)
/* 954440 80240480 8FB40028 */  lw        $s4, 0x28($sp)
/* 954444 80240484 8FB30024 */  lw        $s3, 0x24($sp)
/* 954448 80240488 8FB20020 */  lw        $s2, 0x20($sp)
/* 95444C 8024048C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 954450 80240490 8FB00018 */  lw        $s0, 0x18($sp)
/* 954454 80240494 03E00008 */  jr        $ra
/* 954458 80240498 27BD0040 */   addiu    $sp, $sp, 0x40
