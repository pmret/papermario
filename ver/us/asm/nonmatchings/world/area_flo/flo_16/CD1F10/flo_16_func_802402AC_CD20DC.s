.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402AC_CD20DC
/* CD20DC 802402AC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* CD20E0 802402B0 AFB5002C */  sw        $s5, 0x2c($sp)
/* CD20E4 802402B4 0080A82D */  daddu     $s5, $a0, $zero
/* CD20E8 802402B8 AFBE0038 */  sw        $fp, 0x38($sp)
/* CD20EC 802402BC 3C1E8011 */  lui       $fp, %hi(gPlayerData)
/* CD20F0 802402C0 27DEF290 */  addiu     $fp, $fp, %lo(gPlayerData)
/* CD20F4 802402C4 AFBF003C */  sw        $ra, 0x3c($sp)
/* CD20F8 802402C8 AFB70034 */  sw        $s7, 0x34($sp)
/* CD20FC 802402CC AFB60030 */  sw        $s6, 0x30($sp)
/* CD2100 802402D0 AFB40028 */  sw        $s4, 0x28($sp)
/* CD2104 802402D4 AFB30024 */  sw        $s3, 0x24($sp)
/* CD2108 802402D8 AFB20020 */  sw        $s2, 0x20($sp)
/* CD210C 802402DC AFB1001C */  sw        $s1, 0x1c($sp)
/* CD2110 802402E0 10A0004F */  beqz      $a1, .L80240420
/* CD2114 802402E4 AFB00018 */   sw       $s0, 0x18($sp)
/* CD2118 802402E8 0C00AB39 */  jal       heap_malloc
/* CD211C 802402EC 24040330 */   addiu    $a0, $zero, 0x330
/* CD2120 802402F0 0040982D */  daddu     $s3, $v0, $zero
/* CD2124 802402F4 0000B02D */  daddu     $s6, $zero, $zero
/* CD2128 802402F8 02C0902D */  daddu     $s2, $s6, $zero
/* CD212C 802402FC 3C148024 */  lui       $s4, %hi(flo_16_D_80243708_CD5538)
/* CD2130 80240300 26943708 */  addiu     $s4, $s4, %lo(flo_16_D_80243708_CD5538)
/* CD2134 80240304 0260882D */  daddu     $s1, $s3, $zero
/* CD2138 80240308 8EA200B4 */  lw        $v0, 0xb4($s5)
/* CD213C 8024030C 3C038024 */  lui       $v1, %hi(flo_16_D_80243700_CD5530)
/* CD2140 80240310 24633700 */  addiu     $v1, $v1, %lo(flo_16_D_80243700_CD5530)
/* CD2144 80240314 AEB30078 */  sw        $s3, 0x78($s5)
/* CD2148 80240318 00021027 */  nor       $v0, $zero, $v0
/* CD214C 8024031C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* CD2150 80240320 00171080 */  sll       $v0, $s7, 2
/* CD2154 80240324 00431021 */  addu      $v0, $v0, $v1
/* CD2158 80240328 AFA20010 */  sw        $v0, 0x10($sp)
.L8024032C:
/* CD215C 8024032C 86900000 */  lh        $s0, ($s4)
/* CD2160 80240330 001010C0 */  sll       $v0, $s0, 3
/* CD2164 80240334 03C21021 */  addu      $v0, $fp, $v0
/* CD2168 80240338 90420014 */  lbu       $v0, 0x14($v0)
/* CD216C 8024033C 5040002E */  beql      $v0, $zero, .L802403F8
/* CD2170 80240340 26520001 */   addiu    $s2, $s2, 1
/* CD2174 80240344 00101100 */  sll       $v0, $s0, 4
/* CD2178 80240348 3C068009 */  lui       $a2, %hi(D_8008EF20)
/* CD217C 8024034C 24C6EF20 */  addiu     $a2, $a2, %lo(D_8008EF20)
/* CD2180 80240350 00461021 */  addu      $v0, $v0, $a2
/* CD2184 80240354 0200202D */  daddu     $a0, $s0, $zero
/* CD2188 80240358 AE300108 */  sw        $s0, 0x108($s1)
/* CD218C 8024035C 8C420000 */  lw        $v0, ($v0)
/* CD2190 80240360 02E0282D */  daddu     $a1, $s7, $zero
/* CD2194 80240364 0C09006D */  jal       flo_16_UnkFunc37
/* CD2198 80240368 AE220084 */   sw       $v0, 0x84($s1)
/* CD219C 8024036C 0040202D */  daddu     $a0, $v0, $zero
/* CD21A0 80240370 04800011 */  bltz      $a0, .L802403B8
/* CD21A4 80240374 00101080 */   sll      $v0, $s0, 2
/* CD21A8 80240378 3C06800F */  lui       $a2, %hi(D_800F7F00)
/* CD21AC 8024037C 24C67F00 */  addiu     $a2, $a2, %lo(D_800F7F00)
/* CD21B0 80240380 00461021 */  addu      $v0, $v0, $a2
/* CD21B4 80240384 8C430000 */  lw        $v1, ($v0)
/* CD21B8 80240388 24020001 */  addiu     $v0, $zero, 1
/* CD21BC 8024038C AE22018C */  sw        $v0, 0x18c($s1)
/* CD21C0 80240390 00041080 */  sll       $v0, $a0, 2
/* CD21C4 80240394 3C068024 */  lui       $a2, %hi(flo_16_D_80243718_CD5548)
/* CD21C8 80240398 24C63718 */  addiu     $a2, $a2, %lo(flo_16_D_80243718_CD5548)
/* CD21CC 8024039C AE230000 */  sw        $v1, ($s1)
/* CD21D0 802403A0 001218C0 */  sll       $v1, $s2, 3
/* CD21D4 802403A4 00431021 */  addu      $v0, $v0, $v1
/* CD21D8 802403A8 00461021 */  addu      $v0, $v0, $a2
/* CD21DC 802403AC 8C420000 */  lw        $v0, ($v0)
/* CD21E0 802403B0 080900F7 */  j         .L802403DC
/* CD21E4 802403B4 AE220294 */   sw       $v0, 0x294($s1)
.L802403B8:
/* CD21E8 802403B8 3C06800F */  lui       $a2, %hi(D_800F7F40)
/* CD21EC 802403BC 24C67F40 */  addiu     $a2, $a2, %lo(D_800F7F40)
/* CD21F0 802403C0 00461021 */  addu      $v0, $v0, $a2
/* CD21F4 802403C4 8C420000 */  lw        $v0, ($v0)
/* CD21F8 802403C8 AE20018C */  sw        $zero, 0x18c($s1)
/* CD21FC 802403CC AE220000 */  sw        $v0, ($s1)
/* CD2200 802403D0 8FA60010 */  lw        $a2, 0x10($sp)
/* CD2204 802403D4 8CC20000 */  lw        $v0, ($a2)
/* CD2208 802403D8 AE220294 */  sw        $v0, 0x294($s1)
.L802403DC:
/* CD220C 802403DC 001010C0 */  sll       $v0, $s0, 3
/* CD2210 802403E0 03C21021 */  addu      $v0, $fp, $v0
/* CD2214 802403E4 80420015 */  lb        $v0, 0x15($v0)
/* CD2218 802403E8 26D60001 */  addiu     $s6, $s6, 1
/* CD221C 802403EC AE220210 */  sw        $v0, 0x210($s1)
/* CD2220 802403F0 26310004 */  addiu     $s1, $s1, 4
/* CD2224 802403F4 26520001 */  addiu     $s2, $s2, 1
.L802403F8:
/* CD2228 802403F8 2A420008 */  slti      $v0, $s2, 8
/* CD222C 802403FC 1440FFCB */  bnez      $v0, .L8024032C
/* CD2230 80240400 26940002 */   addiu    $s4, $s4, 2
/* CD2234 80240404 0260202D */  daddu     $a0, $s3, $zero
/* CD2238 80240408 24020004 */  addiu     $v0, $zero, 4
/* CD223C 8024040C AC820318 */  sw        $v0, 0x318($a0)
/* CD2240 80240410 AC960324 */  sw        $s6, 0x324($a0)
/* CD2244 80240414 0C03D390 */  jal       create_popup_menu
/* CD2248 80240418 AC800328 */   sw       $zero, 0x328($a0)
/* CD224C 8024041C AEA00070 */  sw        $zero, 0x70($s5)
.L80240420:
/* CD2250 80240420 8EA20070 */  lw        $v0, 0x70($s5)
/* CD2254 80240424 8EB30078 */  lw        $s3, 0x78($s5)
/* CD2258 80240428 14400008 */  bnez      $v0, .L8024044C
/* CD225C 8024042C 24420001 */   addiu    $v0, $v0, 1
/* CD2260 80240430 8662032C */  lh        $v0, 0x32c($s3)
/* CD2264 80240434 10400009 */  beqz      $v0, .L8024045C
/* CD2268 80240438 AEA20074 */   sw       $v0, 0x74($s5)
/* CD226C 8024043C 0C03C4EC */  jal       hide_popup_menu
/* CD2270 80240440 00000000 */   nop
/* CD2274 80240444 8EA20070 */  lw        $v0, 0x70($s5)
/* CD2278 80240448 24420001 */  addiu     $v0, $v0, 1
.L8024044C:
/* CD227C 8024044C AEA20070 */  sw        $v0, 0x70($s5)
/* CD2280 80240450 2842000F */  slti      $v0, $v0, 0xf
/* CD2284 80240454 10400003 */  beqz      $v0, .L80240464
/* CD2288 80240458 00000000 */   nop
.L8024045C:
/* CD228C 8024045C 08090133 */  j         .L802404CC
/* CD2290 80240460 0000102D */   daddu    $v0, $zero, $zero
.L80240464:
/* CD2294 80240464 0C03C54E */  jal       destroy_popup_menu
/* CD2298 80240468 00000000 */   nop
/* CD229C 8024046C 8EA30074 */  lw        $v1, 0x74($s5)
/* CD22A0 80240470 240200FF */  addiu     $v0, $zero, 0xff
/* CD22A4 80240474 10620010 */  beq       $v1, $v0, .L802404B8
/* CD22A8 80240478 2462FFFF */   addiu    $v0, $v1, -1
/* CD22AC 8024047C 00021080 */  sll       $v0, $v0, 2
/* CD22B0 80240480 02621021 */  addu      $v0, $s3, $v0
/* CD22B4 80240484 8C420108 */  lw        $v0, 0x108($v0)
/* CD22B8 80240488 00021100 */  sll       $v0, $v0, 4
/* CD22BC 8024048C 3C038009 */  lui       $v1, %hi(D_8008EF20)
/* CD22C0 80240490 00621821 */  addu      $v1, $v1, $v0
/* CD22C4 80240494 8C63EF20 */  lw        $v1, %lo(D_8008EF20)($v1)
/* CD22C8 80240498 8EA20074 */  lw        $v0, 0x74($s5)
/* CD22CC 8024049C 2442FFFF */  addiu     $v0, $v0, -1
/* CD22D0 802404A0 00021080 */  sll       $v0, $v0, 2
/* CD22D4 802404A4 02621021 */  addu      $v0, $s3, $v0
/* CD22D8 802404A8 AEA30084 */  sw        $v1, 0x84($s5)
/* CD22DC 802404AC 8C420108 */  lw        $v0, 0x108($v0)
/* CD22E0 802404B0 08090130 */  j         .L802404C0
/* CD22E4 802404B4 AEA20088 */   sw       $v0, 0x88($s5)
.L802404B8:
/* CD22E8 802404B8 2402FFFF */  addiu     $v0, $zero, -1
/* CD22EC 802404BC AEA20084 */  sw        $v0, 0x84($s5)
.L802404C0:
/* CD22F0 802404C0 0C00AB4B */  jal       heap_free
/* CD22F4 802404C4 8EA40078 */   lw       $a0, 0x78($s5)
/* CD22F8 802404C8 24020002 */  addiu     $v0, $zero, 2
.L802404CC:
/* CD22FC 802404CC 8FBF003C */  lw        $ra, 0x3c($sp)
/* CD2300 802404D0 8FBE0038 */  lw        $fp, 0x38($sp)
/* CD2304 802404D4 8FB70034 */  lw        $s7, 0x34($sp)
/* CD2308 802404D8 8FB60030 */  lw        $s6, 0x30($sp)
/* CD230C 802404DC 8FB5002C */  lw        $s5, 0x2c($sp)
/* CD2310 802404E0 8FB40028 */  lw        $s4, 0x28($sp)
/* CD2314 802404E4 8FB30024 */  lw        $s3, 0x24($sp)
/* CD2318 802404E8 8FB20020 */  lw        $s2, 0x20($sp)
/* CD231C 802404EC 8FB1001C */  lw        $s1, 0x1c($sp)
/* CD2320 802404F0 8FB00018 */  lw        $s0, 0x18($sp)
/* CD2324 802404F4 03E00008 */  jr        $ra
/* CD2328 802404F8 27BD0040 */   addiu    $sp, $sp, 0x40
