.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242358_DF8D58
/* DF8D58 80242358 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* DF8D5C 8024235C AFB20030 */  sw        $s2, 0x30($sp)
/* DF8D60 80242360 0080902D */  daddu     $s2, $a0, $zero
/* DF8D64 80242364 0000182D */  daddu     $v1, $zero, $zero
/* DF8D68 80242368 3C068025 */  lui       $a2, 0x8025
/* DF8D6C 8024236C 8CC6F7E4 */  lw        $a2, -0x81c($a2)
/* DF8D70 80242370 24040020 */  addiu     $a0, $zero, 0x20
/* DF8D74 80242374 AFBF0038 */  sw        $ra, 0x38($sp)
/* DF8D78 80242378 AFB30034 */  sw        $s3, 0x34($sp)
/* DF8D7C 8024237C AFB1002C */  sw        $s1, 0x2c($sp)
/* DF8D80 80242380 AFB00028 */  sw        $s0, 0x28($sp)
/* DF8D84 80242384 00C0282D */  daddu     $a1, $a2, $zero
.L80242388:
/* DF8D88 80242388 94A20074 */  lhu       $v0, 0x74($a1)
/* DF8D8C 8024238C 30420001 */  andi      $v0, $v0, 1
/* DF8D90 80242390 10400006 */  beqz      $v0, .L802423AC
/* DF8D94 80242394 000310C0 */   sll      $v0, $v1, 3
/* DF8D98 80242398 24630001 */  addiu     $v1, $v1, 1
/* DF8D9C 8024239C 10640051 */  beq       $v1, $a0, .L802424E4
/* DF8DA0 802423A0 24A50074 */   addiu    $a1, $a1, 0x74
/* DF8DA4 802423A4 080908E2 */  j         .L80242388
/* DF8DA8 802423A8 00000000 */   nop      
.L802423AC:
/* DF8DAC 802423AC 00431023 */  subu      $v0, $v0, $v1
/* DF8DB0 802423B0 00021080 */  sll       $v0, $v0, 2
/* DF8DB4 802423B4 00431021 */  addu      $v0, $v0, $v1
/* DF8DB8 802423B8 00021080 */  sll       $v0, $v0, 2
/* DF8DBC 802423BC 24420004 */  addiu     $v0, $v0, 4
/* DF8DC0 802423C0 8E440000 */  lw        $a0, ($s2)
/* DF8DC4 802423C4 10800047 */  beqz      $a0, .L802424E4
/* DF8DC8 802423C8 00C28821 */   addu     $s1, $a2, $v0
/* DF8DCC 802423CC 04820014 */  bltzl     $a0, .L80242420
/* DF8DD0 802423D0 AE240000 */   sw       $a0, ($s1)
/* DF8DD4 802423D4 3C138024 */  lui       $s3, 0x8024
/* DF8DD8 802423D8 26732D70 */  addiu     $s3, $s3, 0x2d70
/* DF8DDC 802423DC 8E650000 */  lw        $a1, ($s3)
/* DF8DE0 802423E0 3C108025 */  lui       $s0, 0x8025
/* DF8DE4 802423E4 2610F7F0 */  addiu     $s0, $s0, -0x810
/* DF8DE8 802423E8 00052A00 */  sll       $a1, $a1, 8
/* DF8DEC 802423EC 0C049601 */  jal       dma_load_string
/* DF8DF0 802423F0 00B02821 */   addu     $a1, $a1, $s0
/* DF8DF4 802423F4 8E630000 */  lw        $v1, ($s3)
/* DF8DF8 802423F8 00031200 */  sll       $v0, $v1, 8
/* DF8DFC 802423FC 00501021 */  addu      $v0, $v0, $s0
/* DF8E00 80242400 24630001 */  addiu     $v1, $v1, 1
/* DF8E04 80242404 AE220000 */  sw        $v0, ($s1)
/* DF8E08 80242408 AE630000 */  sw        $v1, ($s3)
/* DF8E0C 8024240C 28630017 */  slti      $v1, $v1, 0x17
/* DF8E10 80242410 50600003 */  beql      $v1, $zero, .L80242420
/* DF8E14 80242414 AE600000 */   sw       $zero, ($s3)
/* DF8E18 80242418 08090909 */  j         .L80242424
/* DF8E1C 8024241C 0000282D */   daddu    $a1, $zero, $zero
.L80242420:
/* DF8E20 80242420 0000282D */  daddu     $a1, $zero, $zero
.L80242424:
/* DF8E24 80242424 27A20024 */  addiu     $v0, $sp, 0x24
/* DF8E28 80242428 00A0302D */  daddu     $a2, $a1, $zero
/* DF8E2C 8024242C AFA00010 */  sw        $zero, 0x10($sp)
/* DF8E30 80242430 AFA00014 */  sw        $zero, 0x14($sp)
/* DF8E34 80242434 AFA20018 */  sw        $v0, 0x18($sp)
/* DF8E38 80242438 AFA0001C */  sw        $zero, 0x1c($sp)
/* DF8E3C 8024243C 8E240000 */  lw        $a0, ($s1)
/* DF8E40 80242440 0C0497DA */  jal       get_string_properties
/* DF8E44 80242444 27A70020 */   addiu    $a3, $sp, 0x20
/* DF8E48 80242448 8E420004 */  lw        $v0, 4($s2)
/* DF8E4C 8024244C AE220068 */  sw        $v0, 0x68($s1)
/* DF8E50 80242450 8E420008 */  lw        $v0, 8($s2)
/* DF8E54 80242454 AE22006C */  sw        $v0, 0x6c($s1)
/* DF8E58 80242458 8E42000C */  lw        $v0, 0xc($s2)
/* DF8E5C 8024245C AE220010 */  sw        $v0, 0x10($s1)
/* DF8E60 80242460 8E420010 */  lw        $v0, 0x10($s2)
/* DF8E64 80242464 AE220018 */  sw        $v0, 0x18($s1)
/* DF8E68 80242468 8E420014 */  lw        $v0, 0x14($s2)
/* DF8E6C 8024246C AE22001C */  sw        $v0, 0x1c($s1)
/* DF8E70 80242470 8E42001C */  lw        $v0, 0x1c($s2)
/* DF8E74 80242474 AE220034 */  sw        $v0, 0x34($s1)
/* DF8E78 80242478 8E420020 */  lw        $v0, 0x20($s2)
/* DF8E7C 8024247C AE220038 */  sw        $v0, 0x38($s1)
/* DF8E80 80242480 8E440018 */  lw        $a0, 0x18($s2)
/* DF8E84 80242484 1080000C */  beqz      $a0, .L802424B8
/* DF8E88 80242488 00000000 */   nop      
/* DF8E8C 8024248C 8FA20024 */  lw        $v0, 0x24($sp)
/* DF8E90 80242490 8FA30020 */  lw        $v1, 0x20($sp)
/* DF8E94 80242494 24420001 */  addiu     $v0, $v0, 1
/* DF8E98 80242498 00621823 */  subu      $v1, $v1, $v0
/* DF8E9C 8024249C 00640018 */  mult      $v1, $a0
/* DF8EA0 802424A0 8E420020 */  lw        $v0, 0x20($s2)
/* DF8EA4 802424A4 00004012 */  mflo      $t0
/* DF8EA8 802424A8 00481023 */  subu      $v0, $v0, $t0
/* DF8EAC 802424AC 04410002 */  bgez      $v0, .L802424B8
/* DF8EB0 802424B0 AE220038 */   sw       $v0, 0x38($s1)
/* DF8EB4 802424B4 AE200038 */  sw        $zero, 0x38($s1)
.L802424B8:
/* DF8EB8 802424B8 8E420024 */  lw        $v0, 0x24($s2)
/* DF8EBC 802424BC AE22004C */  sw        $v0, 0x4c($s1)
/* DF8EC0 802424C0 8E420028 */  lw        $v0, 0x28($s2)
/* DF8EC4 802424C4 AE220050 */  sw        $v0, 0x50($s1)
/* DF8EC8 802424C8 8E420018 */  lw        $v0, 0x18($s2)
/* DF8ECC 802424CC AE220020 */  sw        $v0, 0x20($s1)
/* DF8ED0 802424D0 8E42002C */  lw        $v0, 0x2c($s2)
/* DF8ED4 802424D4 AE220054 */  sw        $v0, 0x54($s1)
/* DF8ED8 802424D8 96420034 */  lhu       $v0, 0x34($s2)
/* DF8EDC 802424DC 34420003 */  ori       $v0, $v0, 3
/* DF8EE0 802424E0 A6220070 */  sh        $v0, 0x70($s1)
.L802424E4:
/* DF8EE4 802424E4 8FBF0038 */  lw        $ra, 0x38($sp)
/* DF8EE8 802424E8 8FB30034 */  lw        $s3, 0x34($sp)
/* DF8EEC 802424EC 8FB20030 */  lw        $s2, 0x30($sp)
/* DF8EF0 802424F0 8FB1002C */  lw        $s1, 0x2c($sp)
/* DF8EF4 802424F4 8FB00028 */  lw        $s0, 0x28($sp)
/* DF8EF8 802424F8 03E00008 */  jr        $ra
/* DF8EFC 802424FC 27BD0040 */   addiu    $sp, $sp, 0x40
