.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402AC_EED3AC
/* EED3AC 802402AC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* EED3B0 802402B0 AFB5002C */  sw        $s5, 0x2c($sp)
/* EED3B4 802402B4 0080A82D */  daddu     $s5, $a0, $zero
/* EED3B8 802402B8 AFBE0038 */  sw        $fp, 0x38($sp)
/* EED3BC 802402BC 3C1E8011 */  lui       $fp, %hi(D_80117840)
/* EED3C0 802402C0 27DE7840 */  addiu     $fp, $fp, %lo(D_80117840)
/* EED3C4 802402C4 AFBF003C */  sw        $ra, 0x3c($sp)
/* EED3C8 802402C8 AFB70034 */  sw        $s7, 0x34($sp)
/* EED3CC 802402CC AFB60030 */  sw        $s6, 0x30($sp)
/* EED3D0 802402D0 AFB40028 */  sw        $s4, 0x28($sp)
/* EED3D4 802402D4 AFB30024 */  sw        $s3, 0x24($sp)
/* EED3D8 802402D8 AFB20020 */  sw        $s2, 0x20($sp)
/* EED3DC 802402DC AFB1001C */  sw        $s1, 0x1c($sp)
/* EED3E0 802402E0 10A0004F */  beqz      $a1, .L80240420
/* EED3E4 802402E4 AFB00018 */   sw       $s0, 0x18($sp)
/* EED3E8 802402E8 0C00AFF5 */  jal       func_8002BFD4
/* EED3EC 802402EC 24040330 */   addiu    $a0, $zero, 0x330
/* EED3F0 802402F0 0040982D */  daddu     $s3, $v0, $zero
/* EED3F4 802402F4 0000B02D */  daddu     $s6, $zero, $zero
/* EED3F8 802402F8 02C0902D */  daddu     $s2, $s6, $zero
/* EED3FC 802402FC 3C148024 */  lui       $s4, %hi(D_80243768_EF0868)
/* EED400 80240300 26943768 */  addiu     $s4, $s4, %lo(D_80243768_EF0868)
/* EED404 80240304 0260882D */  daddu     $s1, $s3, $zero
/* EED408 80240308 8EA200B4 */  lw        $v0, 0xb4($s5)
/* EED40C 8024030C 3C038024 */  lui       $v1, %hi(D_80243760_EF0860)
/* EED410 80240310 24633760 */  addiu     $v1, $v1, %lo(D_80243760_EF0860)
/* EED414 80240314 AEB30078 */  sw        $s3, 0x78($s5)
/* EED418 80240318 00021027 */  nor       $v0, $zero, $v0
/* EED41C 8024031C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* EED420 80240320 00171080 */  sll       $v0, $s7, 2
/* EED424 80240324 00431021 */  addu      $v0, $v0, $v1
/* EED428 80240328 AFA20010 */  sw        $v0, 0x10($sp)
.L8024032C:
/* EED42C 8024032C 86900000 */  lh        $s0, ($s4)
/* EED430 80240330 001010C0 */  sll       $v0, $s0, 3
/* EED434 80240334 03C21021 */  addu      $v0, $fp, $v0
/* EED438 80240338 90420014 */  lbu       $v0, 0x14($v0)
/* EED43C 8024033C 5040002E */  beql      $v0, $zero, .L802403F8
/* EED440 80240340 26520001 */   addiu    $s2, $s2, 1
/* EED444 80240344 00101100 */  sll       $v0, $s0, 4
/* EED448 80240348 3C068009 */  lui       $a2, %hi(D_80094900)
/* EED44C 8024034C 24C64900 */  addiu     $a2, $a2, %lo(D_80094900)
/* EED450 80240350 00461021 */  addu      $v0, $v0, $a2
/* EED454 80240354 0200202D */  daddu     $a0, $s0, $zero
/* EED458 80240358 AE300108 */  sw        $s0, 0x108($s1)
/* EED45C 8024035C 8C420000 */  lw        $v0, ($v0)
/* EED460 80240360 02E0282D */  daddu     $a1, $s7, $zero
/* EED464 80240364 0C09006D */  jal       func_802401B4_EED2B4
/* EED468 80240368 AE220084 */   sw       $v0, 0x84($s1)
/* EED46C 8024036C 0040202D */  daddu     $a0, $v0, $zero
/* EED470 80240370 04800011 */  bltz      $a0, .L802403B8
/* EED474 80240374 00101080 */   sll      $v0, $s0, 2
/* EED478 80240378 3C068010 */  lui       $a2, %hi(D_80100060)
/* EED47C 8024037C 24C60060 */  addiu     $a2, $a2, %lo(D_80100060)
/* EED480 80240380 00461021 */  addu      $v0, $v0, $a2
/* EED484 80240384 8C430000 */  lw        $v1, ($v0)
/* EED488 80240388 24020001 */  addiu     $v0, $zero, 1
/* EED48C 8024038C AE22018C */  sw        $v0, 0x18c($s1)
/* EED490 80240390 00041080 */  sll       $v0, $a0, 2
/* EED494 80240394 3C068024 */  lui       $a2, %hi(D_80243778_EF0878)
/* EED498 80240398 24C63778 */  addiu     $a2, $a2, %lo(D_80243778_EF0878)
/* EED49C 8024039C AE230000 */  sw        $v1, ($s1)
/* EED4A0 802403A0 001218C0 */  sll       $v1, $s2, 3
/* EED4A4 802403A4 00431021 */  addu      $v0, $v0, $v1
/* EED4A8 802403A8 00461021 */  addu      $v0, $v0, $a2
/* EED4AC 802403AC 8C420000 */  lw        $v0, ($v0)
/* EED4B0 802403B0 080900F7 */  j         .L802403DC
/* EED4B4 802403B4 AE220294 */   sw       $v0, 0x294($s1)
.L802403B8:
/* EED4B8 802403B8 3C068010 */  lui       $a2, %hi(D_801000A0)
/* EED4BC 802403BC 24C600A0 */  addiu     $a2, $a2, %lo(D_801000A0)
/* EED4C0 802403C0 00461021 */  addu      $v0, $v0, $a2
/* EED4C4 802403C4 8C420000 */  lw        $v0, ($v0)
/* EED4C8 802403C8 AE20018C */  sw        $zero, 0x18c($s1)
/* EED4CC 802403CC AE220000 */  sw        $v0, ($s1)
/* EED4D0 802403D0 8FA60010 */  lw        $a2, 0x10($sp)
/* EED4D4 802403D4 8CC20000 */  lw        $v0, ($a2)
/* EED4D8 802403D8 AE220294 */  sw        $v0, 0x294($s1)
.L802403DC:
/* EED4DC 802403DC 001010C0 */  sll       $v0, $s0, 3
/* EED4E0 802403E0 03C21021 */  addu      $v0, $fp, $v0
/* EED4E4 802403E4 80420015 */  lb        $v0, 0x15($v0)
/* EED4E8 802403E8 26D60001 */  addiu     $s6, $s6, 1
/* EED4EC 802403EC AE220210 */  sw        $v0, 0x210($s1)
/* EED4F0 802403F0 26310004 */  addiu     $s1, $s1, 4
/* EED4F4 802403F4 26520001 */  addiu     $s2, $s2, 1
.L802403F8:
/* EED4F8 802403F8 2A420008 */  slti      $v0, $s2, 8
/* EED4FC 802403FC 1440FFCB */  bnez      $v0, .L8024032C
/* EED500 80240400 26940002 */   addiu    $s4, $s4, 2
/* EED504 80240404 0260202D */  daddu     $a0, $s3, $zero
/* EED508 80240408 24020004 */  addiu     $v0, $zero, 4
/* EED50C 8024040C AC820318 */  sw        $v0, 0x318($a0)
/* EED510 80240410 AC960324 */  sw        $s6, 0x324($a0)
/* EED514 80240414 0C03F343 */  jal       func_800FCD0C
/* EED518 80240418 AC800328 */   sw       $zero, 0x328($a0)
/* EED51C 8024041C AEA00070 */  sw        $zero, 0x70($s5)
.L80240420:
/* EED520 80240420 8EA20070 */  lw        $v0, 0x70($s5)
/* EED524 80240424 8EB30078 */  lw        $s3, 0x78($s5)
/* EED528 80240428 14400008 */  bnez      $v0, .L8024044C
/* EED52C 8024042C 24420001 */   addiu    $v0, $v0, 1
/* EED530 80240430 8662032C */  lh        $v0, 0x32c($s3)
/* EED534 80240434 10400009 */  beqz      $v0, .L8024045C
/* EED538 80240438 AEA20074 */   sw       $v0, 0x74($s5)
/* EED53C 8024043C 0C03E498 */  jal       func_800F9260
/* EED540 80240440 00000000 */   nop
/* EED544 80240444 8EA20070 */  lw        $v0, 0x70($s5)
/* EED548 80240448 24420001 */  addiu     $v0, $v0, 1
.L8024044C:
/* EED54C 8024044C AEA20070 */  sw        $v0, 0x70($s5)
/* EED550 80240450 2842000F */  slti      $v0, $v0, 0xf
/* EED554 80240454 10400003 */  beqz      $v0, .L80240464
/* EED558 80240458 00000000 */   nop
.L8024045C:
/* EED55C 8024045C 08090133 */  j         .L802404CC
/* EED560 80240460 0000102D */   daddu    $v0, $zero, $zero
.L80240464:
/* EED564 80240464 0C03E4FA */  jal       func_800F93E8
/* EED568 80240468 00000000 */   nop
/* EED56C 8024046C 8EA30074 */  lw        $v1, 0x74($s5)
/* EED570 80240470 240200FF */  addiu     $v0, $zero, 0xff
/* EED574 80240474 10620010 */  beq       $v1, $v0, .L802404B8
/* EED578 80240478 2462FFFF */   addiu    $v0, $v1, -1
/* EED57C 8024047C 00021080 */  sll       $v0, $v0, 2
/* EED580 80240480 02621021 */  addu      $v0, $s3, $v0
/* EED584 80240484 8C420108 */  lw        $v0, 0x108($v0)
/* EED588 80240488 00021100 */  sll       $v0, $v0, 4
/* EED58C 8024048C 3C038009 */  lui       $v1, %hi(D_80094900)
/* EED590 80240490 00621821 */  addu      $v1, $v1, $v0
/* EED594 80240494 8C634900 */  lw        $v1, %lo(D_80094900)($v1)
/* EED598 80240498 8EA20074 */  lw        $v0, 0x74($s5)
/* EED59C 8024049C 2442FFFF */  addiu     $v0, $v0, -1
/* EED5A0 802404A0 00021080 */  sll       $v0, $v0, 2
/* EED5A4 802404A4 02621021 */  addu      $v0, $s3, $v0
/* EED5A8 802404A8 AEA30084 */  sw        $v1, 0x84($s5)
/* EED5AC 802404AC 8C420108 */  lw        $v0, 0x108($v0)
/* EED5B0 802404B0 08090130 */  j         .L802404C0
/* EED5B4 802404B4 AEA20088 */   sw       $v0, 0x88($s5)
.L802404B8:
/* EED5B8 802404B8 2402FFFF */  addiu     $v0, $zero, -1
/* EED5BC 802404BC AEA20084 */  sw        $v0, 0x84($s5)
.L802404C0:
/* EED5C0 802404C0 0C00B007 */  jal       func_8002C01C
/* EED5C4 802404C4 8EA40078 */   lw       $a0, 0x78($s5)
/* EED5C8 802404C8 24020002 */  addiu     $v0, $zero, 2
.L802404CC:
/* EED5CC 802404CC 8FBF003C */  lw        $ra, 0x3c($sp)
/* EED5D0 802404D0 8FBE0038 */  lw        $fp, 0x38($sp)
/* EED5D4 802404D4 8FB70034 */  lw        $s7, 0x34($sp)
/* EED5D8 802404D8 8FB60030 */  lw        $s6, 0x30($sp)
/* EED5DC 802404DC 8FB5002C */  lw        $s5, 0x2c($sp)
/* EED5E0 802404E0 8FB40028 */  lw        $s4, 0x28($sp)
/* EED5E4 802404E4 8FB30024 */  lw        $s3, 0x24($sp)
/* EED5E8 802404E8 8FB20020 */  lw        $s2, 0x20($sp)
/* EED5EC 802404EC 8FB1001C */  lw        $s1, 0x1c($sp)
/* EED5F0 802404F0 8FB00018 */  lw        $s0, 0x18($sp)
/* EED5F4 802404F4 03E00008 */  jr        $ra
/* EED5F8 802404F8 27BD0040 */   addiu    $sp, $sp, 0x40
