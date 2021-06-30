.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024228C_A3B76C
/* A3B76C 8024228C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A3B770 80242290 AFB3001C */  sw        $s3, 0x1c($sp)
/* A3B774 80242294 0080982D */  daddu     $s3, $a0, $zero
/* A3B778 80242298 AFBF0034 */  sw        $ra, 0x34($sp)
/* A3B77C 8024229C AFBE0030 */  sw        $fp, 0x30($sp)
/* A3B780 802422A0 AFB7002C */  sw        $s7, 0x2c($sp)
/* A3B784 802422A4 AFB60028 */  sw        $s6, 0x28($sp)
/* A3B788 802422A8 AFB50024 */  sw        $s5, 0x24($sp)
/* A3B78C 802422AC AFB40020 */  sw        $s4, 0x20($sp)
/* A3B790 802422B0 AFB20018 */  sw        $s2, 0x18($sp)
/* A3B794 802422B4 AFB10014 */  sw        $s1, 0x14($sp)
/* A3B798 802422B8 10A0004B */  beqz      $a1, .L802423E8
/* A3B79C 802422BC AFB00010 */   sw       $s0, 0x10($sp)
/* A3B7A0 802422C0 0C00AB39 */  jal       heap_malloc
/* A3B7A4 802422C4 24040330 */   addiu    $a0, $zero, 0x330
/* A3B7A8 802422C8 8E630084 */  lw        $v1, 0x84($s3)
/* A3B7AC 802422CC 0040A82D */  daddu     $s5, $v0, $zero
/* A3B7B0 802422D0 AE750078 */  sw        $s5, 0x78($s3)
/* A3B7B4 802422D4 14600008 */  bnez      $v1, .L802422F8
/* A3B7B8 802422D8 AE6300AC */   sw       $v1, 0xac($s3)
/* A3B7BC 802422DC 3C03F840 */  lui       $v1, 0xf840
/* A3B7C0 802422E0 34635D64 */  ori       $v1, $v1, 0x5d64
/* A3B7C4 802422E4 3C02F840 */  lui       $v0, 0xf840
/* A3B7C8 802422E8 34425D69 */  ori       $v0, $v0, 0x5d69
/* A3B7CC 802422EC AE62008C */  sw        $v0, 0x8c($s3)
/* A3B7D0 802422F0 080908C4 */  j         .L80242310
/* A3B7D4 802422F4 2402000C */   addiu    $v0, $zero, 0xc
.L802422F8:
/* A3B7D8 802422F8 3C03F840 */  lui       $v1, 0xf840
/* A3B7DC 802422FC 34635D69 */  ori       $v1, $v1, 0x5d69
/* A3B7E0 80242300 3C02F840 */  lui       $v0, 0xf840
/* A3B7E4 80242304 34425D6E */  ori       $v0, $v0, 0x5d6e
/* A3B7E8 80242308 AE62008C */  sw        $v0, 0x8c($s3)
/* A3B7EC 8024230C 24020009 */  addiu     $v0, $zero, 9
.L80242310:
/* A3B7F0 80242310 AE630088 */  sw        $v1, 0x88($s3)
/* A3B7F4 80242314 AEA20318 */  sw        $v0, 0x318($s5)
/* A3B7F8 80242318 0000B02D */  daddu     $s6, $zero, $zero
/* A3B7FC 8024231C 02C0902D */  daddu     $s2, $s6, $zero
/* A3B800 80242320 3C1E8009 */  lui       $fp, %hi(D_8008A680)
/* A3B804 80242324 27DEA680 */  addiu     $fp, $fp, %lo(D_8008A680)
/* A3B808 80242328 24170001 */  addiu     $s7, $zero, 1
/* A3B80C 8024232C 3C148024 */  lui       $s4, %hi(D_80245EEC_A3F3CC)
/* A3B810 80242330 26945EEC */  addiu     $s4, $s4, %lo(D_80245EEC_A3F3CC)
/* A3B814 80242334 02A0882D */  daddu     $s1, $s5, $zero
.L80242338:
/* A3B818 80242338 8E650088 */  lw        $a1, 0x88($s3)
/* A3B81C 8024233C 0000202D */  daddu     $a0, $zero, $zero
/* A3B820 80242340 0C0B1EAF */  jal       get_variable
/* A3B824 80242344 00B22821 */   addu     $a1, $a1, $s2
/* A3B828 80242348 0000202D */  daddu     $a0, $zero, $zero
/* A3B82C 8024234C 8E65008C */  lw        $a1, 0x8c($s3)
/* A3B830 80242350 0040802D */  daddu     $s0, $v0, $zero
/* A3B834 80242354 0C0B1EAF */  jal       get_variable
/* A3B838 80242358 00B22821 */   addu     $a1, $a1, $s2
/* A3B83C 8024235C 52000016 */  beql      $s0, $zero, .L802423B8
/* A3B840 80242360 26520001 */   addiu    $s2, $s2, 1
/* A3B844 80242364 54400014 */  bnel      $v0, $zero, .L802423B8
/* A3B848 80242368 26520001 */   addiu    $s2, $s2, 1
/* A3B84C 8024236C 8E830000 */  lw        $v1, ($s4)
/* A3B850 80242370 3C078008 */  lui       $a3, %hi(gItemTable)
/* A3B854 80242374 24E778E0 */  addiu     $a3, $a3, %lo(gItemTable)
/* A3B858 80242378 00031940 */  sll       $v1, $v1, 5
/* A3B85C 8024237C 00671821 */  addu      $v1, $v1, $a3
/* A3B860 80242380 84620004 */  lh        $v0, 4($v1)
/* A3B864 80242384 000210C0 */  sll       $v0, $v0, 3
/* A3B868 80242388 005E1021 */  addu      $v0, $v0, $fp
/* A3B86C 8024238C 8C420000 */  lw        $v0, ($v0)
/* A3B870 80242390 AE320108 */  sw        $s2, 0x108($s1)
/* A3B874 80242394 AE37018C */  sw        $s7, 0x18c($s1)
/* A3B878 80242398 AE220000 */  sw        $v0, ($s1)
/* A3B87C 8024239C 8C620000 */  lw        $v0, ($v1)
/* A3B880 802423A0 AE220084 */  sw        $v0, 0x84($s1)
/* A3B884 802423A4 8C620014 */  lw        $v0, 0x14($v1)
/* A3B888 802423A8 26D60001 */  addiu     $s6, $s6, 1
/* A3B88C 802423AC AE220294 */  sw        $v0, 0x294($s1)
/* A3B890 802423B0 26310004 */  addiu     $s1, $s1, 4
/* A3B894 802423B4 26520001 */  addiu     $s2, $s2, 1
.L802423B8:
/* A3B898 802423B8 2A420005 */  slti      $v0, $s2, 5
/* A3B89C 802423BC 1440FFDE */  bnez      $v0, .L80242338
/* A3B8A0 802423C0 26940004 */   addiu    $s4, $s4, 4
/* A3B8A4 802423C4 16C00004 */  bnez      $s6, .L802423D8
/* A3B8A8 802423C8 02A0202D */   daddu    $a0, $s5, $zero
/* A3B8AC 802423CC AE600084 */  sw        $zero, 0x84($s3)
/* A3B8B0 802423D0 08090927 */  j         .L8024249C
/* A3B8B4 802423D4 24020001 */   addiu    $v0, $zero, 1
.L802423D8:
/* A3B8B8 802423D8 AC960324 */  sw        $s6, 0x324($a0)
/* A3B8BC 802423DC 0C03D390 */  jal       btl_create_popup_menu
/* A3B8C0 802423E0 AC800328 */   sw       $zero, 0x328($a0)
/* A3B8C4 802423E4 AE600070 */  sw        $zero, 0x70($s3)
.L802423E8:
/* A3B8C8 802423E8 8E620070 */  lw        $v0, 0x70($s3)
/* A3B8CC 802423EC 8E750078 */  lw        $s5, 0x78($s3)
/* A3B8D0 802423F0 14400008 */  bnez      $v0, .L80242414
/* A3B8D4 802423F4 24420001 */   addiu    $v0, $v0, 1
/* A3B8D8 802423F8 86A2032C */  lh        $v0, 0x32c($s5)
/* A3B8DC 802423FC 10400009 */  beqz      $v0, .L80242424
/* A3B8E0 80242400 AE620074 */   sw       $v0, 0x74($s3)
/* A3B8E4 80242404 0C03C4EC */  jal       hide_popup_menu
/* A3B8E8 80242408 00000000 */   nop
/* A3B8EC 8024240C 8E620070 */  lw        $v0, 0x70($s3)
/* A3B8F0 80242410 24420001 */  addiu     $v0, $v0, 1
.L80242414:
/* A3B8F4 80242414 AE620070 */  sw        $v0, 0x70($s3)
/* A3B8F8 80242418 2842000F */  slti      $v0, $v0, 0xf
/* A3B8FC 8024241C 10400003 */  beqz      $v0, .L8024242C
/* A3B900 80242420 00000000 */   nop
.L80242424:
/* A3B904 80242424 08090927 */  j         .L8024249C
/* A3B908 80242428 0000102D */   daddu    $v0, $zero, $zero
.L8024242C:
/* A3B90C 8024242C 0C03C54E */  jal       destroy_popup_menu
/* A3B910 80242430 00000000 */   nop
/* A3B914 80242434 8E630074 */  lw        $v1, 0x74($s3)
/* A3B918 80242438 240200FF */  addiu     $v0, $zero, 0xff
/* A3B91C 8024243C 14620004 */  bne       $v1, $v0, .L80242450
/* A3B920 80242440 2462FFFF */   addiu    $v0, $v1, -1
/* A3B924 80242444 2402FFFF */  addiu     $v0, $zero, -1
/* A3B928 80242448 08090926 */  j         .L80242498
/* A3B92C 8024244C AE620084 */   sw       $v0, 0x84($s3)
.L80242450:
/* A3B930 80242450 00021080 */  sll       $v0, $v0, 2
/* A3B934 80242454 02A21021 */  addu      $v0, $s5, $v0
/* A3B938 80242458 8C460108 */  lw        $a2, 0x108($v0)
/* A3B93C 8024245C 8E6300AC */  lw        $v1, 0xac($s3)
/* A3B940 80242460 00061080 */  sll       $v0, $a2, 2
/* A3B944 80242464 3C018024 */  lui       $at, %hi(D_80245EEC_A3F3CC)
/* A3B948 80242468 00220821 */  addu      $at, $at, $v0
/* A3B94C 8024246C 8C225EEC */  lw        $v0, %lo(D_80245EEC_A3F3CC)($at)
/* A3B950 80242470 14600006 */  bnez      $v1, .L8024248C
/* A3B954 80242474 AE620084 */   sw       $v0, 0x84($s3)
/* A3B958 80242478 8E65008C */  lw        $a1, 0x8c($s3)
/* A3B95C 8024247C 0000202D */  daddu     $a0, $zero, $zero
/* A3B960 80242480 00A62821 */  addu      $a1, $a1, $a2
/* A3B964 80242484 0C0B2026 */  jal       set_variable
/* A3B968 80242488 24060001 */   addiu    $a2, $zero, 1
.L8024248C:
/* A3B96C 8024248C 8E640078 */  lw        $a0, 0x78($s3)
/* A3B970 80242490 0C00AB4B */  jal       heap_free
/* A3B974 80242494 00000000 */   nop
.L80242498:
/* A3B978 80242498 24020002 */  addiu     $v0, $zero, 2
.L8024249C:
/* A3B97C 8024249C 8FBF0034 */  lw        $ra, 0x34($sp)
/* A3B980 802424A0 8FBE0030 */  lw        $fp, 0x30($sp)
/* A3B984 802424A4 8FB7002C */  lw        $s7, 0x2c($sp)
/* A3B988 802424A8 8FB60028 */  lw        $s6, 0x28($sp)
/* A3B98C 802424AC 8FB50024 */  lw        $s5, 0x24($sp)
/* A3B990 802424B0 8FB40020 */  lw        $s4, 0x20($sp)
/* A3B994 802424B4 8FB3001C */  lw        $s3, 0x1c($sp)
/* A3B998 802424B8 8FB20018 */  lw        $s2, 0x18($sp)
/* A3B99C 802424BC 8FB10014 */  lw        $s1, 0x14($sp)
/* A3B9A0 802424C0 8FB00010 */  lw        $s0, 0x10($sp)
/* A3B9A4 802424C4 03E00008 */  jr        $ra
/* A3B9A8 802424C8 27BD0038 */   addiu    $sp, $sp, 0x38
