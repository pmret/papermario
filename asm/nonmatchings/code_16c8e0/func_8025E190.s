.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025E190
/* 18CA70 8025E190 3C03800E */  lui       $v1, 0x800e
/* 18CA74 8025E194 8C63C4DC */  lw        $v1, -0x3b24($v1)
/* 18CA78 8025E198 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 18CA7C 8025E19C AFBE0060 */  sw        $fp, 0x60($sp)
/* 18CA80 8025E1A0 3C1E800E */  lui       $fp, 0x800e
/* 18CA84 8025E1A4 27DEC070 */  addiu     $fp, $fp, -0x3f90
/* 18CA88 8025E1A8 AFB50054 */  sw        $s5, 0x54($sp)
/* 18CA8C 8025E1AC 3C158011 */  lui       $s5, 0x8011
/* 18CA90 8025E1B0 26B5F290 */  addiu     $s5, $s5, -0xd70
/* 18CA94 8025E1B4 AFBF0064 */  sw        $ra, 0x64($sp)
/* 18CA98 8025E1B8 AFB7005C */  sw        $s7, 0x5c($sp)
/* 18CA9C 8025E1BC AFB60058 */  sw        $s6, 0x58($sp)
/* 18CAA0 8025E1C0 AFB40050 */  sw        $s4, 0x50($sp)
/* 18CAA4 8025E1C4 AFB3004C */  sw        $s3, 0x4c($sp)
/* 18CAA8 8025E1C8 AFB20048 */  sw        $s2, 0x48($sp)
/* 18CAAC 8025E1CC AFB10044 */  sw        $s1, 0x44($sp)
/* 18CAB0 8025E1D0 AFB00040 */  sw        $s0, 0x40($sp)
/* 18CAB4 8025E1D4 8FD100D8 */  lw        $s1, 0xd8($fp)
/* 18CAB8 8025E1D8 8FD200DC */  lw        $s2, 0xdc($fp)
/* 18CABC 8025E1DC 2C620017 */  sltiu     $v0, $v1, 0x17
/* 18CAC0 8025E1E0 10400759 */  beqz      $v0, .L8025FF48
/* 18CAC4 8025E1E4 00031080 */   sll      $v0, $v1, 2
/* 18CAC8 8025E1E8 3C01802A */  lui       $at, 0x802a
/* 18CACC 8025E1EC 00220821 */  addu      $at, $at, $v0
/* 18CAD0 8025E1F0 8C22D4F0 */  lw        $v0, -0x2b10($at)
/* 18CAD4 8025E1F4 00400008 */  jr        $v0
/* 18CAD8 8025E1F8 00000000 */   nop      
/* 18CADC 8025E1FC 83C20079 */  lb        $v0, 0x79($fp)
/* 18CAE0 8025E200 1C400751 */  bgtz      $v0, .L8025FF48
/* 18CAE4 8025E204 3C03F7FF */   lui      $v1, 0xf7ff
/* 18CAE8 8025E208 8E220000 */  lw        $v0, ($s1)
/* 18CAEC 8025E20C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 18CAF0 8025E210 00431024 */  and       $v0, $v0, $v1
/* 18CAF4 8025E214 AE220000 */  sw        $v0, ($s1)
/* 18CAF8 8025E218 83C30078 */  lb        $v1, 0x78($fp)
/* 18CAFC 8025E21C 3C01802A */  lui       $at, 0x802a
/* 18CB00 8025E220 AC20FB74 */  sw        $zero, -0x48c($at)
/* 18CB04 8025E224 3C01802A */  lui       $at, 0x802a
/* 18CB08 8025E228 AC20FB50 */  sw        $zero, -0x4b0($at)
/* 18CB0C 8025E22C 3C018028 */  lui       $at, 0x8028
/* 18CB10 8025E230 AC204150 */  sw        $zero, 0x4150($at)
/* 18CB14 8025E234 3C01802A */  lui       $at, 0x802a
/* 18CB18 8025E238 AC20FB88 */  sw        $zero, -0x478($at)
/* 18CB1C 8025E23C 3C01802A */  lui       $at, 0x802a
/* 18CB20 8025E240 AC20FB8C */  sw        $zero, -0x474($at)
/* 18CB24 8025E244 00031040 */  sll       $v0, $v1, 1
/* 18CB28 8025E248 00431021 */  addu      $v0, $v0, $v1
/* 18CB2C 8025E24C 000210C0 */  sll       $v0, $v0, 3
/* 18CB30 8025E250 00431021 */  addu      $v0, $v0, $v1
/* 18CB34 8025E254 00021080 */  sll       $v0, $v0, 2
/* 18CB38 8025E258 3C01802A */  lui       $at, 0x802a
/* 18CB3C 8025E25C AC22FB6C */  sw        $v0, -0x494($at)
/* 18CB40 8025E260 0C05272D */  jal       play_sound
/* 18CB44 8025E264 240400D4 */   addiu    $a0, $zero, 0xd4
/* 18CB48 8025E268 82A30010 */  lb        $v1, 0x10($s5)
/* 18CB4C 8025E26C 83C20078 */  lb        $v0, 0x78($fp)
/* 18CB50 8025E270 00622821 */  addu      $a1, $v1, $v0
/* 18CB54 8025E274 28A20064 */  slti      $v0, $a1, 0x64
/* 18CB58 8025E278 14400005 */  bnez      $v0, .L8025E290
/* 18CB5C 8025E27C 24020008 */   addiu    $v0, $zero, 8
/* 18CB60 8025E280 AFA20010 */  sw        $v0, 0x10($sp)
/* 18CB64 8025E284 0000202D */  daddu     $a0, $zero, $zero
/* 18CB68 8025E288 080978A7 */  j         .L8025E29C
/* 18CB6C 8025E28C 2405008E */   addiu    $a1, $zero, 0x8e
.L8025E290:
/* 18CB70 8025E290 AFA20010 */  sw        $v0, 0x10($sp)
/* 18CB74 8025E294 0000202D */  daddu     $a0, $zero, $zero
/* 18CB78 8025E298 2405008B */  addiu     $a1, $zero, 0x8b
.L8025E29C:
/* 18CB7C 8025E29C 0080302D */  daddu     $a2, $a0, $zero
/* 18CB80 8025E2A0 0C052A46 */  jal       set_music_track
/* 18CB84 8025E2A4 240700FA */   addiu    $a3, $zero, 0xfa
/* 18CB88 8025E2A8 3C01802A */  lui       $at, 0x802a
/* 18CB8C 8025E2AC AC20FB84 */  sw        $zero, -0x47c($at)
/* 18CB90 8025E2B0 0C093903 */  jal       func_8024E40C
/* 18CB94 8025E2B4 24040017 */   addiu    $a0, $zero, 0x17
/* 18CB98 8025E2B8 3C02800E */  lui       $v0, 0x800e
/* 18CB9C 8025E2BC 2442C070 */  addiu     $v0, $v0, -0x3f90
/* 18CBA0 8025E2C0 8C430004 */  lw        $v1, 4($v0)
/* 18CBA4 8025E2C4 24040001 */  addiu     $a0, $zero, 1
/* 18CBA8 8025E2C8 3C01802A */  lui       $at, 0x802a
/* 18CBAC 8025E2CC AC20FB54 */  sw        $zero, -0x4ac($at)
/* 18CBB0 8025E2D0 3C01802A */  lui       $at, 0x802a
/* 18CBB4 8025E2D4 AC24FB4C */  sw        $a0, -0x4b4($at)
/* 18CBB8 8025E2D8 3C01800E */  lui       $at, 0x800e
/* 18CBBC 8025E2DC AC24C4DC */  sw        $a0, -0x3b24($at)
/* 18CBC0 8025E2E0 00641825 */  or        $v1, $v1, $a0
/* 18CBC4 8025E2E4 08097FD2 */  j         .L8025FF48
/* 18CBC8 8025E2E8 AC430004 */   sw       $v1, 4($v0)
/* 18CBCC 8025E2EC 3C10802A */  lui       $s0, 0x802a
/* 18CBD0 8025E2F0 2610FB4C */  addiu     $s0, $s0, -0x4b4
/* 18CBD4 8025E2F4 8E020000 */  lw        $v0, ($s0)
/* 18CBD8 8025E2F8 10400003 */  beqz      $v0, .L8025E308
/* 18CBDC 8025E2FC 2442FFFF */   addiu    $v0, $v0, -1
/* 18CBE0 8025E300 08097FD2 */  j         .L8025FF48
/* 18CBE4 8025E304 AE020000 */   sw       $v0, ($s0)
.L8025E308:
/* 18CBE8 8025E308 0C093961 */  jal       func_8024E584
/* 18CBEC 8025E30C 00000000 */   nop      
/* 18CBF0 8025E310 1040070D */  beqz      $v0, .L8025FF48
/* 18CBF4 8025E314 00000000 */   nop      
/* 18CBF8 8025E318 3C04007B */  lui       $a0, 0x7b
/* 18CBFC 8025E31C 248489A0 */  addiu     $a0, $a0, -0x7660
/* 18CC00 8025E320 3C05007B */  lui       $a1, 0x7b
/* 18CC04 8025E324 24A55960 */  addiu     $a1, $a1, 0x5960
/* 18CC08 8025E328 3C06802A */  lui       $a2, 0x802a
/* 18CC0C 8025E32C 24C61000 */  addiu     $a2, $a2, 0x1000
/* 18CC10 8025E330 0C00A5CF */  jal       dma_copy
/* 18CC14 8025E334 00000000 */   nop      
/* 18CC18 8025E338 3C048028 */  lui       $a0, 0x8028
/* 18CC1C 8025E33C 248442B0 */  addiu     $a0, $a0, 0x42b0
/* 18CC20 8025E340 2405000A */  addiu     $a1, $zero, 0xa
/* 18CC24 8025E344 0C0B0CF8 */  jal       start_script
/* 18CC28 8025E348 0000302D */   daddu    $a2, $zero, $zero
/* 18CC2C 8025E34C 3C04802A */  lui       $a0, 0x802a
/* 18CC30 8025E350 8C84FB6C */  lw        $a0, -0x494($a0)
/* 18CC34 8025E354 24030014 */  addiu     $v1, $zero, 0x14
/* 18CC38 8025E358 14600002 */  bnez      $v1, .L8025E364
/* 18CC3C 8025E35C 0083001A */   div      $zero, $a0, $v1
/* 18CC40 8025E360 0007000D */  break     7
.L8025E364:
/* 18CC44 8025E364 2401FFFF */   addiu    $at, $zero, -1
/* 18CC48 8025E368 14610004 */  bne       $v1, $at, .L8025E37C
/* 18CC4C 8025E36C 3C018000 */   lui      $at, 0x8000
/* 18CC50 8025E370 14810002 */  bne       $a0, $at, .L8025E37C
/* 18CC54 8025E374 00000000 */   nop      
/* 18CC58 8025E378 0006000D */  break     6
.L8025E37C:
/* 18CC5C 8025E37C 00002012 */   mflo     $a0
/* 18CC60 8025E380 3C01802A */  lui       $at, 0x802a
/* 18CC64 8025E384 AC20FB78 */  sw        $zero, -0x488($at)
/* 18CC68 8025E388 3C01802A */  lui       $at, 0x802a
/* 18CC6C 8025E38C AC23FB54 */  sw        $v1, -0x4ac($at)
/* 18CC70 8025E390 0040282D */  daddu     $a1, $v0, $zero
/* 18CC74 8025E394 24020001 */  addiu     $v0, $zero, 1
/* 18CC78 8025E398 AE2501D4 */  sw        $a1, 0x1d4($s1)
/* 18CC7C 8025E39C AE020000 */  sw        $v0, ($s0)
/* 18CC80 8025E3A0 8CA30144 */  lw        $v1, 0x144($a1)
/* 18CC84 8025E3A4 24020002 */  addiu     $v0, $zero, 2
/* 18CC88 8025E3A8 3C01800E */  lui       $at, 0x800e
/* 18CC8C 8025E3AC AC22C4DC */  sw        $v0, -0x3b24($at)
/* 18CC90 8025E3B0 AE2301E4 */  sw        $v1, 0x1e4($s1)
/* 18CC94 8025E3B4 ACA00148 */  sw        $zero, 0x148($a1)
/* 18CC98 8025E3B8 3C01802A */  lui       $at, 0x802a
/* 18CC9C 8025E3BC AC24FB70 */  sw        $a0, -0x490($at)
/* 18CCA0 8025E3C0 08097FD2 */  j         .L8025FF48
/* 18CCA4 8025E3C4 00000000 */   nop      
/* 18CCA8 8025E3C8 3C03802A */  lui       $v1, 0x802a
/* 18CCAC 8025E3CC 2463FB4C */  addiu     $v1, $v1, -0x4b4
/* 18CCB0 8025E3D0 8C620000 */  lw        $v0, ($v1)
/* 18CCB4 8025E3D4 14400662 */  bnez      $v0, .L8025FD60
/* 18CCB8 8025E3D8 2442FFFF */   addiu    $v0, $v0, -1
/* 18CCBC 8025E3DC 83C20078 */  lb        $v0, 0x78($fp)
/* 18CCC0 8025E3E0 10400028 */  beqz      $v0, .L8025E484
/* 18CCC4 8025E3E4 3C0551EB */   lui      $a1, 0x51eb
/* 18CCC8 8025E3E8 3C04802A */  lui       $a0, 0x802a
/* 18CCCC 8025E3EC 2484FB6C */  addiu     $a0, $a0, -0x494
/* 18CCD0 8025E3F0 8C830000 */  lw        $v1, ($a0)
/* 18CCD4 8025E3F4 3C02802A */  lui       $v0, 0x802a
/* 18CCD8 8025E3F8 8C42FB70 */  lw        $v0, -0x490($v0)
/* 18CCDC 8025E3FC 34A5851F */  ori       $a1, $a1, 0x851f
/* 18CCE0 8025E400 00621823 */  subu      $v1, $v1, $v0
/* 18CCE4 8025E404 00650018 */  mult      $v1, $a1
/* 18CCE8 8025E408 83C50078 */  lb        $a1, 0x78($fp)
/* 18CCEC 8025E40C AC830000 */  sw        $v1, ($a0)
/* 18CCF0 8025E410 00031FC3 */  sra       $v1, $v1, 0x1f
/* 18CCF4 8025E414 00004810 */  mfhi      $t1
/* 18CCF8 8025E418 00091143 */  sra       $v0, $t1, 5
/* 18CCFC 8025E41C 00431023 */  subu      $v0, $v0, $v1
/* 18CD00 8025E420 A3C20078 */  sb        $v0, 0x78($fp)
/* 18CD04 8025E424 00021600 */  sll       $v0, $v0, 0x18
/* 18CD08 8025E428 00021603 */  sra       $v0, $v0, 0x18
/* 18CD0C 8025E42C 00A28023 */  subu      $s0, $a1, $v0
/* 18CD10 8025E430 1A000003 */  blez      $s0, .L8025E440
/* 18CD14 8025E434 00000000 */   nop      
/* 18CD18 8025E438 0C05272D */  jal       play_sound
/* 18CD1C 8025E43C 24040215 */   addiu    $a0, $zero, 0x215
.L8025E440:
/* 18CD20 8025E440 92A20010 */  lbu       $v0, 0x10($s5)
/* 18CD24 8025E444 3C038028 */  lui       $v1, 0x8028
/* 18CD28 8025E448 24634150 */  addiu     $v1, $v1, 0x4150
/* 18CD2C 8025E44C 00501021 */  addu      $v0, $v0, $s0
/* 18CD30 8025E450 A2A20010 */  sb        $v0, 0x10($s5)
/* 18CD34 8025E454 8C620000 */  lw        $v0, ($v1)
/* 18CD38 8025E458 3C04802A */  lui       $a0, 0x802a
/* 18CD3C 8025E45C 8C84FB54 */  lw        $a0, -0x4ac($a0)
/* 18CD40 8025E460 24420001 */  addiu     $v0, $v0, 1
/* 18CD44 8025E464 14800007 */  bnez      $a0, .L8025E484
/* 18CD48 8025E468 AC620000 */   sw       $v0, ($v1)
/* 18CD4C 8025E46C 83C20078 */  lb        $v0, 0x78($fp)
/* 18CD50 8025E470 10400004 */  beqz      $v0, .L8025E484
/* 18CD54 8025E474 00000000 */   nop      
/* 18CD58 8025E478 92A20010 */  lbu       $v0, 0x10($s5)
/* 18CD5C 8025E47C 24420001 */  addiu     $v0, $v0, 1
/* 18CD60 8025E480 A2A20010 */  sb        $v0, 0x10($s5)
.L8025E484:
/* 18CD64 8025E484 82A20009 */  lb        $v0, 9($s5)
/* 18CD68 8025E488 2842001B */  slti      $v0, $v0, 0x1b
/* 18CD6C 8025E48C 50400001 */  beql      $v0, $zero, .L8025E494
/* 18CD70 8025E490 A2A00010 */   sb       $zero, 0x10($s5)
.L8025E494:
/* 18CD74 8025E494 82A20010 */  lb        $v0, 0x10($s5)
/* 18CD78 8025E498 28420064 */  slti      $v0, $v0, 0x64
/* 18CD7C 8025E49C 14400006 */  bnez      $v0, .L8025E4B8
/* 18CD80 8025E4A0 24030001 */   addiu    $v1, $zero, 1
/* 18CD84 8025E4A4 92A20010 */  lbu       $v0, 0x10($s5)
/* 18CD88 8025E4A8 3C01802A */  lui       $at, 0x802a
/* 18CD8C 8025E4AC AC23FB74 */  sw        $v1, -0x48c($at)
/* 18CD90 8025E4B0 2442FF9C */  addiu     $v0, $v0, -0x64
/* 18CD94 8025E4B4 A2A20010 */  sb        $v0, 0x10($s5)
.L8025E4B8:
/* 18CD98 8025E4B8 82A20009 */  lb        $v0, 9($s5)
/* 18CD9C 8025E4BC 3C03802A */  lui       $v1, 0x802a
/* 18CDA0 8025E4C0 8C63FB74 */  lw        $v1, -0x48c($v1)
/* 18CDA4 8025E4C4 00431021 */  addu      $v0, $v0, $v1
/* 18CDA8 8025E4C8 2403001B */  addiu     $v1, $zero, 0x1b
/* 18CDAC 8025E4CC 50430001 */  beql      $v0, $v1, .L8025E4D4
/* 18CDB0 8025E4D0 A2A00010 */   sb       $zero, 0x10($s5)
.L8025E4D4:
/* 18CDB4 8025E4D4 83C20078 */  lb        $v0, 0x78($fp)
/* 18CDB8 8025E4D8 1440069B */  bnez      $v0, .L8025FF48
/* 18CDBC 8025E4DC 00000000 */   nop      
/* 18CDC0 8025E4E0 3C03802A */  lui       $v1, 0x802a
/* 18CDC4 8025E4E4 2463FB54 */  addiu     $v1, $v1, -0x4ac
/* 18CDC8 8025E4E8 8C620000 */  lw        $v0, ($v1)
/* 18CDCC 8025E4EC 1440061C */  bnez      $v0, .L8025FD60
/* 18CDD0 8025E4F0 2442FFFF */   addiu    $v0, $v0, -1
/* 18CDD4 8025E4F4 3C04F3FF */  lui       $a0, 0xf3ff
/* 18CDD8 8025E4F8 3484FFFF */  ori       $a0, $a0, 0xffff
/* 18CDDC 8025E4FC 8E220000 */  lw        $v0, ($s1)
/* 18CDE0 8025E500 24030001 */  addiu     $v1, $zero, 1
/* 18CDE4 8025E504 3C01802A */  lui       $at, 0x802a
/* 18CDE8 8025E508 AC23FB78 */  sw        $v1, -0x488($at)
/* 18CDEC 8025E50C 00441024 */  and       $v0, $v0, $a0
/* 18CDF0 8025E510 12400004 */  beqz      $s2, .L8025E524
/* 18CDF4 8025E514 AE220000 */   sw       $v0, ($s1)
/* 18CDF8 8025E518 8E420000 */  lw        $v0, ($s2)
/* 18CDFC 8025E51C 00441024 */  and       $v0, $v0, $a0
/* 18CE00 8025E520 AE420000 */  sw        $v0, ($s2)
.L8025E524:
/* 18CE04 8025E524 3C048028 */  lui       $a0, 0x8028
/* 18CE08 8025E528 24844EBC */  addiu     $a0, $a0, 0x4ebc
/* 18CE0C 8025E52C 2405000A */  addiu     $a1, $zero, 0xa
/* 18CE10 8025E530 0000302D */  daddu     $a2, $zero, $zero
/* 18CE14 8025E534 24020005 */  addiu     $v0, $zero, 5
/* 18CE18 8025E538 0C0B0CF8 */  jal       start_script
/* 18CE1C 8025E53C A3C201A7 */   sb       $v0, 0x1a7($fp)
/* 18CE20 8025E540 0040282D */  daddu     $a1, $v0, $zero
/* 18CE24 8025E544 AE2501D4 */  sw        $a1, 0x1d4($s1)
/* 18CE28 8025E548 8CA20144 */  lw        $v0, 0x144($a1)
/* 18CE2C 8025E54C AE2201E4 */  sw        $v0, 0x1e4($s1)
/* 18CE30 8025E550 1240000B */  beqz      $s2, .L8025E580
/* 18CE34 8025E554 ACA00148 */   sw       $zero, 0x148($a1)
/* 18CE38 8025E558 2405000A */  addiu     $a1, $zero, 0xa
/* 18CE3C 8025E55C 8E4401C4 */  lw        $a0, 0x1c4($s2)
/* 18CE40 8025E560 0C0B0CF8 */  jal       start_script
/* 18CE44 8025E564 0000302D */   daddu    $a2, $zero, $zero
/* 18CE48 8025E568 0040282D */  daddu     $a1, $v0, $zero
/* 18CE4C 8025E56C AE4501D4 */  sw        $a1, 0x1d4($s2)
/* 18CE50 8025E570 8CA20144 */  lw        $v0, 0x144($a1)
/* 18CE54 8025E574 AE4201E4 */  sw        $v0, 0x1e4($s2)
/* 18CE58 8025E578 24020100 */  addiu     $v0, $zero, 0x100
/* 18CE5C 8025E57C ACA20148 */  sw        $v0, 0x148($a1)
.L8025E580:
/* 18CE60 8025E580 24020028 */  addiu     $v0, $zero, 0x28
/* 18CE64 8025E584 3C01802A */  lui       $at, 0x802a
/* 18CE68 8025E588 AC22FB4C */  sw        $v0, -0x4b4($at)
/* 18CE6C 8025E58C 08097FD0 */  j         .L8025FF40
/* 18CE70 8025E590 24020003 */   addiu    $v0, $zero, 3
/* 18CE74 8025E594 3C03802A */  lui       $v1, 0x802a
/* 18CE78 8025E598 2463FB4C */  addiu     $v1, $v1, -0x4b4
/* 18CE7C 8025E59C 8C620000 */  lw        $v0, ($v1)
/* 18CE80 8025E5A0 144005EF */  bnez      $v0, .L8025FD60
/* 18CE84 8025E5A4 2442FFFF */   addiu    $v0, $v0, -1
/* 18CE88 8025E5A8 3C02802A */  lui       $v0, 0x802a
/* 18CE8C 8025E5AC 8C42FB74 */  lw        $v0, -0x48c($v0)
/* 18CE90 8025E5B0 14400663 */  bnez      $v0, .L8025FF40
/* 18CE94 8025E5B4 24020004 */   addiu    $v0, $zero, 4
/* 18CE98 8025E5B8 08097FD0 */  j         .L8025FF40
/* 18CE9C 8025E5BC 24020014 */   addiu    $v0, $zero, 0x14
/* 18CEA0 8025E5C0 3C10802A */  lui       $s0, 0x802a
/* 18CEA4 8025E5C4 2610FB84 */  addiu     $s0, $s0, -0x47c
/* 18CEA8 8025E5C8 8E020000 */  lw        $v0, ($s0)
/* 18CEAC 8025E5CC 28420063 */  slti      $v0, $v0, 0x63
/* 18CEB0 8025E5D0 1440065D */  bnez      $v0, .L8025FF48
/* 18CEB4 8025E5D4 00000000 */   nop      
/* 18CEB8 8025E5D8 92A20009 */  lbu       $v0, 9($s5)
/* 18CEBC 8025E5DC 24040002 */  addiu     $a0, $zero, 2
/* 18CEC0 8025E5E0 24420001 */  addiu     $v0, $v0, 1
/* 18CEC4 8025E5E4 0C093903 */  jal       func_8024E40C
/* 18CEC8 8025E5E8 A2A20009 */   sb       $v0, 9($s5)
/* 18CECC 8025E5EC 0C093936 */  jal       move_cam_over
/* 18CED0 8025E5F0 24040005 */   addiu    $a0, $zero, 5
/* 18CED4 8025E5F4 3C04007A */  lui       $a0, 0x7a
/* 18CED8 8025E5F8 2484EF40 */  addiu     $a0, $a0, -0x10c0
/* 18CEDC 8025E5FC 3C05007B */  lui       $a1, 0x7b
/* 18CEE0 8025E600 24A589A0 */  addiu     $a1, $a1, -0x7660
/* 18CEE4 8025E604 3C06802A */  lui       $a2, 0x802a
/* 18CEE8 8025E608 24C61000 */  addiu     $a2, $a2, 0x1000
/* 18CEEC 8025E60C 0C00A5CF */  jal       dma_copy
/* 18CEF0 8025E610 00000000 */   nop      
/* 18CEF4 8025E614 3C048000 */  lui       $a0, 0x8000
/* 18CEF8 8025E618 0C05272D */  jal       play_sound
/* 18CEFC 8025E61C 34840008 */   ori      $a0, $a0, 8
/* 18CF00 8025E620 24020005 */  addiu     $v0, $zero, 5
/* 18CF04 8025E624 08097FD0 */  j         .L8025FF40
/* 18CF08 8025E628 AE000000 */   sw       $zero, ($s0)
/* 18CF0C 8025E62C 3C048028 */  lui       $a0, 0x8028
/* 18CF10 8025E630 24844880 */  addiu     $a0, $a0, 0x4880
/* 18CF14 8025E634 2405000A */  addiu     $a1, $zero, 0xa
/* 18CF18 8025E638 0C0B0CF8 */  jal       start_script
/* 18CF1C 8025E63C 0000302D */   daddu    $a2, $zero, $zero
/* 18CF20 8025E640 24030019 */  addiu     $v1, $zero, 0x19
/* 18CF24 8025E644 3C01802A */  lui       $at, 0x802a
/* 18CF28 8025E648 AC23FB4C */  sw        $v1, -0x4b4($at)
/* 18CF2C 8025E64C 8C430144 */  lw        $v1, 0x144($v0)
/* 18CF30 8025E650 3C01802A */  lui       $at, 0x802a
/* 18CF34 8025E654 AC22FB7C */  sw        $v0, -0x484($at)
/* 18CF38 8025E658 24020006 */  addiu     $v0, $zero, 6
/* 18CF3C 8025E65C 3C01800E */  lui       $at, 0x800e
/* 18CF40 8025E660 AC22C4DC */  sw        $v0, -0x3b24($at)
/* 18CF44 8025E664 3C01802A */  lui       $at, 0x802a
/* 18CF48 8025E668 AC23FB80 */  sw        $v1, -0x480($at)
/* 18CF4C 8025E66C 0C04760B */  jal       func_8011D82C
/* 18CF50 8025E670 24040001 */   addiu    $a0, $zero, 1
/* 18CF54 8025E674 0000202D */  daddu     $a0, $zero, $zero
/* 18CF58 8025E678 0080282D */  daddu     $a1, $a0, $zero
/* 18CF5C 8025E67C 0080302D */  daddu     $a2, $a0, $zero
/* 18CF60 8025E680 0080382D */  daddu     $a3, $a0, $zero
/* 18CF64 8025E684 3C038015 */  lui       $v1, 0x8015
/* 18CF68 8025E688 8C6312F0 */  lw        $v1, 0x12f0($v1)
/* 18CF6C 8025E68C 24020001 */  addiu     $v0, $zero, 1
/* 18CF70 8025E690 0C046F97 */  jal       set_background_color_blend
/* 18CF74 8025E694 A0620000 */   sb       $v0, ($v1)
/* 18CF78 8025E698 08097FD2 */  j         .L8025FF48
/* 18CF7C 8025E69C 00000000 */   nop      
/* 18CF80 8025E6A0 3C10802A */  lui       $s0, 0x802a
/* 18CF84 8025E6A4 2610FB4C */  addiu     $s0, $s0, -0x4b4
/* 18CF88 8025E6A8 8E030000 */  lw        $v1, ($s0)
/* 18CF8C 8025E6AC 24020012 */  addiu     $v0, $zero, 0x12
/* 18CF90 8025E6B0 1462004E */  bne       $v1, $v0, .L8025E7EC
/* 18CF94 8025E6B4 0000202D */   daddu    $a0, $zero, $zero
/* 18CF98 8025E6B8 92A20003 */  lbu       $v0, 3($s5)
/* 18CF9C 8025E6BC 92A30006 */  lbu       $v1, 6($s5)
/* 18CFA0 8025E6C0 44801000 */  mtc1      $zero, $f2
/* 18CFA4 8025E6C4 A2A20002 */  sb        $v0, 2($s5)
/* 18CFA8 8025E6C8 A2A30005 */  sb        $v1, 5($s5)
/* 18CFAC 8025E6CC C6240144 */  lwc1      $f4, 0x144($s1)
/* 18CFB0 8025E6D0 C620014C */  lwc1      $f0, 0x14c($s1)
/* 18CFB4 8025E6D4 82A80002 */  lb        $t0, 2($s5)
/* 18CFB8 8025E6D8 4600018D */  trunc.w.s $f6, $f0
/* 18CFBC 8025E6DC 44073000 */  mfc1      $a3, $f6
/* 18CFC0 8025E6E0 00000000 */  nop       
/* 18CFC4 8025E6E4 44873000 */  mtc1      $a3, $f6
/* 18CFC8 8025E6E8 00000000 */  nop       
/* 18CFCC 8025E6EC 468031A0 */  cvt.s.w   $f6, $f6
/* 18CFD0 8025E6F0 46022100 */  add.s     $f4, $f4, $f2
/* 18CFD4 8025E6F4 C6200148 */  lwc1      $f0, 0x148($s1)
/* 18CFD8 8025E6F8 3C01420C */  lui       $at, 0x420c
/* 18CFDC 8025E6FC 44811000 */  mtc1      $at, $f2
/* 18CFE0 8025E700 44073000 */  mfc1      $a3, $f6
/* 18CFE4 8025E704 46020000 */  add.s     $f0, $f0, $f2
/* 18CFE8 8025E708 4600218D */  trunc.w.s $f6, $f4
/* 18CFEC 8025E70C 44033000 */  mfc1      $v1, $f6
/* 18CFF0 8025E710 00000000 */  nop       
/* 18CFF4 8025E714 44833000 */  mtc1      $v1, $f6
/* 18CFF8 8025E718 00000000 */  nop       
/* 18CFFC 8025E71C 468031A0 */  cvt.s.w   $f6, $f6
/* 18D000 8025E720 44053000 */  mfc1      $a1, $f6
/* 18D004 8025E724 4600018D */  trunc.w.s $f6, $f0
/* 18D008 8025E728 44023000 */  mfc1      $v0, $f6
/* 18D00C 8025E72C 00000000 */  nop       
/* 18D010 8025E730 44823000 */  mtc1      $v0, $f6
/* 18D014 8025E734 00000000 */  nop       
/* 18D018 8025E738 468031A0 */  cvt.s.w   $f6, $f6
/* 18D01C 8025E73C 44063000 */  mfc1      $a2, $f6
/* 18D020 8025E740 AFA30028 */  sw        $v1, 0x28($sp)
/* 18D024 8025E744 AFA2002C */  sw        $v0, 0x2c($sp)
/* 18D028 8025E748 0C01C424 */  jal       func_80071090
/* 18D02C 8025E74C AFA80010 */   sw       $t0, 0x10($sp)
/* 18D030 8025E750 C6240144 */  lwc1      $f4, 0x144($s1)
/* 18D034 8025E754 C620014C */  lwc1      $f0, 0x14c($s1)
/* 18D038 8025E758 3C0141A0 */  lui       $at, 0x41a0
/* 18D03C 8025E75C 44811000 */  mtc1      $at, $f2
/* 18D040 8025E760 82A80005 */  lb        $t0, 5($s5)
/* 18D044 8025E764 4600018D */  trunc.w.s $f6, $f0
/* 18D048 8025E768 44073000 */  mfc1      $a3, $f6
/* 18D04C 8025E76C 00000000 */  nop       
/* 18D050 8025E770 44873000 */  mtc1      $a3, $f6
/* 18D054 8025E774 00000000 */  nop       
/* 18D058 8025E778 468031A0 */  cvt.s.w   $f6, $f6
/* 18D05C 8025E77C 46022100 */  add.s     $f4, $f4, $f2
/* 18D060 8025E780 C6200148 */  lwc1      $f0, 0x148($s1)
/* 18D064 8025E784 3C0141C8 */  lui       $at, 0x41c8
/* 18D068 8025E788 44811000 */  mtc1      $at, $f2
/* 18D06C 8025E78C 44073000 */  mfc1      $a3, $f6
/* 18D070 8025E790 46020000 */  add.s     $f0, $f0, $f2
/* 18D074 8025E794 4600218D */  trunc.w.s $f6, $f4
/* 18D078 8025E798 44033000 */  mfc1      $v1, $f6
/* 18D07C 8025E79C 00000000 */  nop       
/* 18D080 8025E7A0 44833000 */  mtc1      $v1, $f6
/* 18D084 8025E7A4 00000000 */  nop       
/* 18D088 8025E7A8 468031A0 */  cvt.s.w   $f6, $f6
/* 18D08C 8025E7AC 44053000 */  mfc1      $a1, $f6
/* 18D090 8025E7B0 4600018D */  trunc.w.s $f6, $f0
/* 18D094 8025E7B4 44023000 */  mfc1      $v0, $f6
/* 18D098 8025E7B8 00000000 */  nop       
/* 18D09C 8025E7BC 44823000 */  mtc1      $v0, $f6
/* 18D0A0 8025E7C0 00000000 */  nop       
/* 18D0A4 8025E7C4 468031A0 */  cvt.s.w   $f6, $f6
/* 18D0A8 8025E7C8 44063000 */  mfc1      $a2, $f6
/* 18D0AC 8025E7CC 24040001 */  addiu     $a0, $zero, 1
/* 18D0B0 8025E7D0 AFA30028 */  sw        $v1, 0x28($sp)
/* 18D0B4 8025E7D4 AFA2002C */  sw        $v0, 0x2c($sp)
/* 18D0B8 8025E7D8 0C01C424 */  jal       func_80071090
/* 18D0BC 8025E7DC AFA80010 */   sw       $t0, 0x10($sp)
/* 18D0C0 8025E7E0 82A2028E */  lb        $v0, 0x28e($s5)
/* 18D0C4 8025E7E4 00021200 */  sll       $v0, $v0, 8
/* 18D0C8 8025E7E8 A6A20290 */  sh        $v0, 0x290($s5)
.L8025E7EC:
/* 18D0CC 8025E7EC 8E020000 */  lw        $v0, ($s0)
/* 18D0D0 8025E7F0 1040000E */  beqz      $v0, .L8025E82C
/* 18D0D4 8025E7F4 2443FFFF */   addiu    $v1, $v0, -1
/* 18D0D8 8025E7F8 2862000A */  slti      $v0, $v1, 0xa
/* 18D0DC 8025E7FC 104005D2 */  beqz      $v0, .L8025FF48
/* 18D0E0 8025E800 AE030000 */   sw       $v1, ($s0)
/* 18D0E4 8025E804 0000202D */  daddu     $a0, $zero, $zero
/* 18D0E8 8025E808 0080282D */  daddu     $a1, $a0, $zero
/* 18D0EC 8025E80C 0080302D */  daddu     $a2, $a0, $zero
/* 18D0F0 8025E810 2407000A */  addiu     $a3, $zero, 0xa
/* 18D0F4 8025E814 00E33823 */  subu      $a3, $a3, $v1
/* 18D0F8 8025E818 00073900 */  sll       $a3, $a3, 4
/* 18D0FC 8025E81C 0C046F97 */  jal       set_background_color_blend
/* 18D100 8025E820 30E700F0 */   andi     $a3, $a3, 0xf0
/* 18D104 8025E824 08097FD2 */  j         .L8025FF48
/* 18D108 8025E828 00000000 */   nop      
.L8025E82C:
/* 18D10C 8025E82C 3C04802B */  lui       $a0, 0x802b
/* 18D110 8025E830 24849F0C */  addiu     $a0, $a0, -0x60f4
/* 18D114 8025E834 0C050529 */  jal       create_icon
/* 18D118 8025E838 24130001 */   addiu    $s3, $zero, 1
/* 18D11C 8025E83C 0040A02D */  daddu     $s4, $v0, $zero
/* 18D120 8025E840 0280202D */  daddu     $a0, $s4, $zero
/* 18D124 8025E844 24050136 */  addiu     $a1, $zero, 0x136
/* 18D128 8025E848 2406008C */  addiu     $a2, $zero, 0x8c
/* 18D12C 8025E84C 3C10802A */  lui       $s0, 0x802a
/* 18D130 8025E850 2610FA80 */  addiu     $s0, $s0, -0x580
/* 18D134 8025E854 0C051261 */  jal       set_icon_render_pos
/* 18D138 8025E858 AE140000 */   sw       $s4, ($s0)
/* 18D13C 8025E85C 0280202D */  daddu     $a0, $s4, $zero
/* 18D140 8025E860 0C051280 */  jal       set_icon_flags
/* 18D144 8025E864 24050080 */   addiu    $a1, $zero, 0x80
/* 18D148 8025E868 3C04802B */  lui       $a0, 0x802b
/* 18D14C 8025E86C 24849F5C */  addiu     $a0, $a0, -0x60a4
/* 18D150 8025E870 0C050529 */  jal       create_icon
/* 18D154 8025E874 00000000 */   nop      
/* 18D158 8025E878 0040A02D */  daddu     $s4, $v0, $zero
/* 18D15C 8025E87C 0280202D */  daddu     $a0, $s4, $zero
/* 18D160 8025E880 2405009E */  addiu     $a1, $zero, 0x9e
/* 18D164 8025E884 24060154 */  addiu     $a2, $zero, 0x154
/* 18D168 8025E888 0C051261 */  jal       set_icon_render_pos
/* 18D16C 8025E88C AE140004 */   sw       $s4, 4($s0)
/* 18D170 8025E890 0280202D */  daddu     $a0, $s4, $zero
/* 18D174 8025E894 0C051280 */  jal       set_icon_flags
/* 18D178 8025E898 24050080 */   addiu    $a1, $zero, 0x80
/* 18D17C 8025E89C 3C04802B */  lui       $a0, 0x802b
/* 18D180 8025E8A0 24849F84 */  addiu     $a0, $a0, -0x607c
/* 18D184 8025E8A4 0C050529 */  jal       create_icon
/* 18D188 8025E8A8 00000000 */   nop      
/* 18D18C 8025E8AC 0040A02D */  daddu     $s4, $v0, $zero
/* 18D190 8025E8B0 0280202D */  daddu     $a0, $s4, $zero
/* 18D194 8025E8B4 2405009E */  addiu     $a1, $zero, 0x9e
/* 18D198 8025E8B8 24060154 */  addiu     $a2, $zero, 0x154
/* 18D19C 8025E8BC 0C051261 */  jal       set_icon_render_pos
/* 18D1A0 8025E8C0 AE14000C */   sw       $s4, 0xc($s0)
/* 18D1A4 8025E8C4 0280202D */  daddu     $a0, $s4, $zero
/* 18D1A8 8025E8C8 0C051280 */  jal       set_icon_flags
/* 18D1AC 8025E8CC 24050080 */   addiu    $a1, $zero, 0x80
/* 18D1B0 8025E8D0 3C04802B */  lui       $a0, 0x802b
/* 18D1B4 8025E8D4 24849FAC */  addiu     $a0, $a0, -0x6054
/* 18D1B8 8025E8D8 0C050529 */  jal       create_icon
/* 18D1BC 8025E8DC 00000000 */   nop      
/* 18D1C0 8025E8E0 0040A02D */  daddu     $s4, $v0, $zero
/* 18D1C4 8025E8E4 0280202D */  daddu     $a0, $s4, $zero
/* 18D1C8 8025E8E8 24050006 */  addiu     $a1, $zero, 6
/* 18D1CC 8025E8EC 2406008C */  addiu     $a2, $zero, 0x8c
/* 18D1D0 8025E8F0 0C051261 */  jal       set_icon_render_pos
/* 18D1D4 8025E8F4 AE140008 */   sw       $s4, 8($s0)
/* 18D1D8 8025E8F8 0280202D */  daddu     $a0, $s4, $zero
/* 18D1DC 8025E8FC 0C051280 */  jal       set_icon_flags
/* 18D1E0 8025E900 24050080 */   addiu    $a1, $zero, 0x80
/* 18D1E4 8025E904 3C10802A */  lui       $s0, 0x802a
/* 18D1E8 8025E908 2610FA90 */  addiu     $s0, $s0, -0x570
/* 18D1EC 8025E90C 3C048028 */  lui       $a0, 0x8028
/* 18D1F0 8025E910 8C8441B4 */  lw        $a0, 0x41b4($a0)
/* 18D1F4 8025E914 0C050529 */  jal       create_icon
/* 18D1F8 8025E918 26110004 */   addiu    $s1, $s0, 4
/* 18D1FC 8025E91C 0040A02D */  daddu     $s4, $v0, $zero
/* 18D200 8025E920 0280202D */  daddu     $a0, $s4, $zero
/* 18D204 8025E924 240500A0 */  addiu     $a1, $zero, 0xa0
/* 18D208 8025E928 2406013D */  addiu     $a2, $zero, 0x13d
/* 18D20C 8025E92C 0C051261 */  jal       set_icon_render_pos
/* 18D210 8025E930 AE140000 */   sw       $s4, ($s0)
/* 18D214 8025E934 0280202D */  daddu     $a0, $s4, $zero
/* 18D218 8025E938 0C051280 */  jal       set_icon_flags
/* 18D21C 8025E93C 24050080 */   addiu    $a1, $zero, 0x80
.L8025E940:
/* 18D220 8025E940 3C048028 */  lui       $a0, 0x8028
/* 18D224 8025E944 8C8441C0 */  lw        $a0, 0x41c0($a0)
/* 18D228 8025E948 0C050529 */  jal       create_icon
/* 18D22C 8025E94C 26730001 */   addiu    $s3, $s3, 1
/* 18D230 8025E950 0040A02D */  daddu     $s4, $v0, $zero
/* 18D234 8025E954 0280202D */  daddu     $a0, $s4, $zero
/* 18D238 8025E958 240500A0 */  addiu     $a1, $zero, 0xa0
/* 18D23C 8025E95C 2406013D */  addiu     $a2, $zero, 0x13d
/* 18D240 8025E960 0C051261 */  jal       set_icon_render_pos
/* 18D244 8025E964 AE340000 */   sw       $s4, ($s1)
/* 18D248 8025E968 0280202D */  daddu     $a0, $s4, $zero
/* 18D24C 8025E96C 0C051280 */  jal       set_icon_flags
/* 18D250 8025E970 24050082 */   addiu    $a1, $zero, 0x82
/* 18D254 8025E974 2A620007 */  slti      $v0, $s3, 7
/* 18D258 8025E978 1440FFF1 */  bnez      $v0, .L8025E940
/* 18D25C 8025E97C 26310004 */   addiu    $s1, $s1, 4
/* 18D260 8025E980 24130001 */  addiu     $s3, $zero, 1
/* 18D264 8025E984 3C128028 */  lui       $s2, 0x8028
/* 18D268 8025E988 265241C0 */  addiu     $s2, $s2, 0x41c0
/* 18D26C 8025E98C 3C10802A */  lui       $s0, 0x802a
/* 18D270 8025E990 2610FA90 */  addiu     $s0, $s0, -0x570
/* 18D274 8025E994 3C048028 */  lui       $a0, 0x8028
/* 18D278 8025E998 8C8441B8 */  lw        $a0, 0x41b8($a0)
/* 18D27C 8025E99C 0C050529 */  jal       create_icon
/* 18D280 8025E9A0 26110004 */   addiu    $s1, $s0, 4
/* 18D284 8025E9A4 0040A02D */  daddu     $s4, $v0, $zero
/* 18D288 8025E9A8 0280202D */  daddu     $a0, $s4, $zero
/* 18D28C 8025E9AC 24050138 */  addiu     $a1, $zero, 0x138
/* 18D290 8025E9B0 24060075 */  addiu     $a2, $zero, 0x75
/* 18D294 8025E9B4 0C051261 */  jal       set_icon_render_pos
/* 18D298 8025E9B8 AE14001C */   sw       $s4, 0x1c($s0)
/* 18D29C 8025E9BC 0280202D */  daddu     $a0, $s4, $zero
/* 18D2A0 8025E9C0 0C051280 */  jal       set_icon_flags
/* 18D2A4 8025E9C4 24050080 */   addiu    $a1, $zero, 0x80
.L8025E9C8:
/* 18D2A8 8025E9C8 8E440028 */  lw        $a0, 0x28($s2)
/* 18D2AC 8025E9CC 0C050529 */  jal       create_icon
/* 18D2B0 8025E9D0 26730001 */   addiu    $s3, $s3, 1
/* 18D2B4 8025E9D4 0040A02D */  daddu     $s4, $v0, $zero
/* 18D2B8 8025E9D8 0280202D */  daddu     $a0, $s4, $zero
/* 18D2BC 8025E9DC 24050138 */  addiu     $a1, $zero, 0x138
/* 18D2C0 8025E9E0 24060075 */  addiu     $a2, $zero, 0x75
/* 18D2C4 8025E9E4 0C051261 */  jal       set_icon_render_pos
/* 18D2C8 8025E9E8 AE34001C */   sw       $s4, 0x1c($s1)
/* 18D2CC 8025E9EC 0280202D */  daddu     $a0, $s4, $zero
/* 18D2D0 8025E9F0 0C051280 */  jal       set_icon_flags
/* 18D2D4 8025E9F4 24050082 */   addiu    $a1, $zero, 0x82
/* 18D2D8 8025E9F8 2A620007 */  slti      $v0, $s3, 7
/* 18D2DC 8025E9FC 1440FFF2 */  bnez      $v0, .L8025E9C8
/* 18D2E0 8025EA00 26310004 */   addiu    $s1, $s1, 4
/* 18D2E4 8025EA04 24130001 */  addiu     $s3, $zero, 1
/* 18D2E8 8025EA08 3C128028 */  lui       $s2, 0x8028
/* 18D2EC 8025EA0C 265241C0 */  addiu     $s2, $s2, 0x41c0
/* 18D2F0 8025EA10 3C10802A */  lui       $s0, 0x802a
/* 18D2F4 8025EA14 2610FA90 */  addiu     $s0, $s0, -0x570
/* 18D2F8 8025EA18 3C048028 */  lui       $a0, 0x8028
/* 18D2FC 8025EA1C 8C8441BC */  lw        $a0, 0x41bc($a0)
/* 18D300 8025EA20 0C050529 */  jal       create_icon
/* 18D304 8025EA24 26110004 */   addiu    $s1, $s0, 4
/* 18D308 8025EA28 0040A02D */  daddu     $s4, $v0, $zero
/* 18D30C 8025EA2C 0280202D */  daddu     $a0, $s4, $zero
/* 18D310 8025EA30 24050008 */  addiu     $a1, $zero, 8
/* 18D314 8025EA34 24060075 */  addiu     $a2, $zero, 0x75
/* 18D318 8025EA38 0C051261 */  jal       set_icon_render_pos
/* 18D31C 8025EA3C AE140038 */   sw       $s4, 0x38($s0)
/* 18D320 8025EA40 0280202D */  daddu     $a0, $s4, $zero
/* 18D324 8025EA44 0C051280 */  jal       set_icon_flags
/* 18D328 8025EA48 24050080 */   addiu    $a1, $zero, 0x80
.L8025EA4C:
/* 18D32C 8025EA4C 8E440050 */  lw        $a0, 0x50($s2)
/* 18D330 8025EA50 0C050529 */  jal       create_icon
/* 18D334 8025EA54 26730001 */   addiu    $s3, $s3, 1
/* 18D338 8025EA58 0040A02D */  daddu     $s4, $v0, $zero
/* 18D33C 8025EA5C 0280202D */  daddu     $a0, $s4, $zero
/* 18D340 8025EA60 24050008 */  addiu     $a1, $zero, 8
/* 18D344 8025EA64 24060075 */  addiu     $a2, $zero, 0x75
/* 18D348 8025EA68 0C051261 */  jal       set_icon_render_pos
/* 18D34C 8025EA6C AE340038 */   sw       $s4, 0x38($s1)
/* 18D350 8025EA70 0280202D */  daddu     $a0, $s4, $zero
/* 18D354 8025EA74 0C051280 */  jal       set_icon_flags
/* 18D358 8025EA78 24050082 */   addiu    $a1, $zero, 0x82
/* 18D35C 8025EA7C 2A620007 */  slti      $v0, $s3, 7
/* 18D360 8025EA80 1440FFF2 */  bnez      $v0, .L8025EA4C
/* 18D364 8025EA84 26310004 */   addiu    $s1, $s1, 4
/* 18D368 8025EA88 3C16802A */  lui       $s6, 0x802a
/* 18D36C 8025EA8C 26D6FB60 */  addiu     $s6, $s6, -0x4a0
/* 18D370 8025EA90 AEC00000 */  sw        $zero, ($s6)
/* 18D374 8025EA94 AEC00004 */  sw        $zero, 4($s6)
/* 18D378 8025EA98 AEC00008 */  sw        $zero, 8($s6)
/* 18D37C 8025EA9C 82A30007 */  lb        $v1, 7($s5)
/* 18D380 8025EAA0 24020032 */  addiu     $v0, $zero, 0x32
/* 18D384 8025EAA4 1062008C */  beq       $v1, $v0, .L8025ECD8
/* 18D388 8025EAA8 3C096666 */   lui      $t1, 0x6666
/* 18D38C 8025EAAC 35296667 */  ori       $t1, $t1, 0x6667
/* 18D390 8025EAB0 3C17802A */  lui       $s7, 0x802a
/* 18D394 8025EAB4 26F7FA90 */  addiu     $s7, $s7, -0x570
/* 18D398 8025EAB8 92A20006 */  lbu       $v0, 6($s5)
/* 18D39C 8025EABC 00021600 */  sll       $v0, $v0, 0x18
/* 18D3A0 8025EAC0 00022E03 */  sra       $a1, $v0, 0x18
/* 18D3A4 8025EAC4 00A90018 */  mult      $a1, $t1
/* 18D3A8 8025EAC8 3C118028 */  lui       $s1, 0x8028
/* 18D3AC 8025EACC 26314238 */  addiu     $s1, $s1, 0x4238
/* 18D3B0 8025EAD0 AFA90030 */  sw        $t1, 0x30($sp)
/* 18D3B4 8025EAD4 8EF40004 */  lw        $s4, 4($s7)
/* 18D3B8 8025EAD8 000217C3 */  sra       $v0, $v0, 0x1f
/* 18D3BC 8025EADC 00004810 */  mfhi      $t1
/* 18D3C0 8025EAE0 00091883 */  sra       $v1, $t1, 2
/* 18D3C4 8025EAE4 00621823 */  subu      $v1, $v1, $v0
/* 18D3C8 8025EAE8 00031600 */  sll       $v0, $v1, 0x18
/* 18D3CC 8025EAEC 00028603 */  sra       $s0, $v0, 0x18
/* 18D3D0 8025EAF0 00031080 */  sll       $v0, $v1, 2
/* 18D3D4 8025EAF4 00431021 */  addu      $v0, $v0, $v1
/* 18D3D8 8025EAF8 00021040 */  sll       $v0, $v0, 1
/* 18D3DC 8025EAFC 00A22823 */  subu      $a1, $a1, $v0
/* 18D3E0 8025EB00 00052E00 */  sll       $a1, $a1, 0x18
/* 18D3E4 8025EB04 00059603 */  sra       $s2, $a1, 0x18
/* 18D3E8 8025EB08 00101080 */  sll       $v0, $s0, 2
/* 18D3EC 8025EB0C 3C058028 */  lui       $a1, 0x8028
/* 18D3F0 8025EB10 00A22821 */  addu      $a1, $a1, $v0
/* 18D3F4 8025EB14 8CA54238 */  lw        $a1, 0x4238($a1)
/* 18D3F8 8025EB18 0C0511FF */  jal       set_menu_icon_script
/* 18D3FC 8025EB1C 0280202D */   daddu    $a0, $s4, $zero
/* 18D400 8025EB20 12000004 */  beqz      $s0, .L8025EB34
/* 18D404 8025EB24 0280202D */   daddu    $a0, $s4, $zero
/* 18D408 8025EB28 0C05128B */  jal       clear_icon_flags
/* 18D40C 8025EB2C 24050002 */   addiu    $a1, $zero, 2
/* 18D410 8025EB30 0280202D */  daddu     $a0, $s4, $zero
.L8025EB34:
/* 18D414 8025EB34 27B60028 */  addiu     $s6, $sp, 0x28
/* 18D418 8025EB38 02C0282D */  daddu     $a1, $s6, $zero
/* 18D41C 8025EB3C 27B3002C */  addiu     $s3, $sp, 0x2c
/* 18D420 8025EB40 0C05126B */  jal       get_icon_render_pos
/* 18D424 8025EB44 0260302D */   daddu    $a2, $s3, $zero
/* 18D428 8025EB48 0280202D */  daddu     $a0, $s4, $zero
/* 18D42C 8025EB4C 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D430 8025EB50 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D434 8025EB54 24A5FFF2 */  addiu     $a1, $a1, -0xe
/* 18D438 8025EB58 0C051261 */  jal       set_icon_render_pos
/* 18D43C 8025EB5C 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D440 8025EB60 00121080 */  sll       $v0, $s2, 2
/* 18D444 8025EB64 00511021 */  addu      $v0, $v0, $s1
/* 18D448 8025EB68 8EF40008 */  lw        $s4, 8($s7)
/* 18D44C 8025EB6C 8C450000 */  lw        $a1, ($v0)
/* 18D450 8025EB70 0C0511FF */  jal       set_menu_icon_script
/* 18D454 8025EB74 0280202D */   daddu    $a0, $s4, $zero
/* 18D458 8025EB78 0280202D */  daddu     $a0, $s4, $zero
/* 18D45C 8025EB7C 0C05128B */  jal       clear_icon_flags
/* 18D460 8025EB80 24050002 */   addiu    $a1, $zero, 2
/* 18D464 8025EB84 0280202D */  daddu     $a0, $s4, $zero
/* 18D468 8025EB88 02C0282D */  daddu     $a1, $s6, $zero
/* 18D46C 8025EB8C 0C05126B */  jal       get_icon_render_pos
/* 18D470 8025EB90 0260302D */   daddu    $a2, $s3, $zero
/* 18D474 8025EB94 0280202D */  daddu     $a0, $s4, $zero
/* 18D478 8025EB98 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D47C 8025EB9C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D480 8025EBA0 24A5FFF8 */  addiu     $a1, $a1, -8
/* 18D484 8025EBA4 0C051261 */  jal       set_icon_render_pos
/* 18D488 8025EBA8 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D48C 8025EBAC 8EF4000C */  lw        $s4, 0xc($s7)
/* 18D490 8025EBB0 3C05802B */  lui       $a1, 0x802b
/* 18D494 8025EBB4 24A5A320 */  addiu     $a1, $a1, -0x5ce0
/* 18D498 8025EBB8 0C0511FF */  jal       set_menu_icon_script
/* 18D49C 8025EBBC 0280202D */   daddu    $a0, $s4, $zero
/* 18D4A0 8025EBC0 0280202D */  daddu     $a0, $s4, $zero
/* 18D4A4 8025EBC4 0C05128B */  jal       clear_icon_flags
/* 18D4A8 8025EBC8 24050002 */   addiu    $a1, $zero, 2
/* 18D4AC 8025EBCC 0280202D */  daddu     $a0, $s4, $zero
/* 18D4B0 8025EBD0 02C0282D */  daddu     $a1, $s6, $zero
/* 18D4B4 8025EBD4 0C05126B */  jal       get_icon_render_pos
/* 18D4B8 8025EBD8 0260302D */   daddu    $a2, $s3, $zero
/* 18D4BC 8025EBDC 0280202D */  daddu     $a0, $s4, $zero
/* 18D4C0 8025EBE0 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D4C4 8025EBE4 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D4C8 8025EBE8 24A5FFFD */  addiu     $a1, $a1, -3
/* 18D4CC 8025EBEC 0C051261 */  jal       set_icon_render_pos
/* 18D4D0 8025EBF0 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D4D4 8025EBF4 82A30006 */  lb        $v1, 6($s5)
/* 18D4D8 8025EBF8 8FA90030 */  lw        $t1, 0x30($sp)
/* 18D4DC 8025EBFC 24630005 */  addiu     $v1, $v1, 5
/* 18D4E0 8025EC00 00690018 */  mult      $v1, $t1
/* 18D4E4 8025EC04 3C118028 */  lui       $s1, 0x8028
/* 18D4E8 8025EC08 263141C0 */  addiu     $s1, $s1, 0x41c0
/* 18D4EC 8025EC0C 8EF40010 */  lw        $s4, 0x10($s7)
/* 18D4F0 8025EC10 000317C3 */  sra       $v0, $v1, 0x1f
/* 18D4F4 8025EC14 00004810 */  mfhi      $t1
/* 18D4F8 8025EC18 00092883 */  sra       $a1, $t1, 2
/* 18D4FC 8025EC1C 00A29023 */  subu      $s2, $a1, $v0
/* 18D500 8025EC20 0240802D */  daddu     $s0, $s2, $zero
/* 18D504 8025EC24 00101080 */  sll       $v0, $s0, 2
/* 18D508 8025EC28 00501021 */  addu      $v0, $v0, $s0
/* 18D50C 8025EC2C 00021040 */  sll       $v0, $v0, 1
/* 18D510 8025EC30 00629023 */  subu      $s2, $v1, $v0
/* 18D514 8025EC34 00101080 */  sll       $v0, $s0, 2
/* 18D518 8025EC38 3C058028 */  lui       $a1, 0x8028
/* 18D51C 8025EC3C 00A22821 */  addu      $a1, $a1, $v0
/* 18D520 8025EC40 8CA541C0 */  lw        $a1, 0x41c0($a1)
/* 18D524 8025EC44 0C0511FF */  jal       set_menu_icon_script
/* 18D528 8025EC48 0280202D */   daddu    $a0, $s4, $zero
/* 18D52C 8025EC4C 12000003 */  beqz      $s0, .L8025EC5C
/* 18D530 8025EC50 0280202D */   daddu    $a0, $s4, $zero
/* 18D534 8025EC54 0C05128B */  jal       clear_icon_flags
/* 18D538 8025EC58 24050002 */   addiu    $a1, $zero, 2
.L8025EC5C:
/* 18D53C 8025EC5C 0280202D */  daddu     $a0, $s4, $zero
/* 18D540 8025EC60 02C0282D */  daddu     $a1, $s6, $zero
/* 18D544 8025EC64 0C05126B */  jal       get_icon_render_pos
/* 18D548 8025EC68 0260302D */   daddu    $a2, $s3, $zero
/* 18D54C 8025EC6C 0280202D */  daddu     $a0, $s4, $zero
/* 18D550 8025EC70 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D554 8025EC74 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D558 8025EC78 24A50003 */  addiu     $a1, $a1, 3
/* 18D55C 8025EC7C 0C051261 */  jal       set_icon_render_pos
/* 18D560 8025EC80 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D564 8025EC84 00121080 */  sll       $v0, $s2, 2
/* 18D568 8025EC88 00511021 */  addu      $v0, $v0, $s1
/* 18D56C 8025EC8C 8EF40014 */  lw        $s4, 0x14($s7)
/* 18D570 8025EC90 8C450000 */  lw        $a1, ($v0)
/* 18D574 8025EC94 0C0511FF */  jal       set_menu_icon_script
/* 18D578 8025EC98 0280202D */   daddu    $a0, $s4, $zero
/* 18D57C 8025EC9C 0280202D */  daddu     $a0, $s4, $zero
/* 18D580 8025ECA0 0C05128B */  jal       clear_icon_flags
/* 18D584 8025ECA4 24050002 */   addiu    $a1, $zero, 2
/* 18D588 8025ECA8 0280202D */  daddu     $a0, $s4, $zero
/* 18D58C 8025ECAC 02C0282D */  daddu     $a1, $s6, $zero
/* 18D590 8025ECB0 0C05126B */  jal       get_icon_render_pos
/* 18D594 8025ECB4 0260302D */   daddu    $a2, $s3, $zero
/* 18D598 8025ECB8 0280202D */  daddu     $a0, $s4, $zero
/* 18D59C 8025ECBC 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D5A0 8025ECC0 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D5A4 8025ECC4 24A5000A */  addiu     $a1, $a1, 0xa
/* 18D5A8 8025ECC8 0C051261 */  jal       set_icon_render_pos
/* 18D5AC 8025ECCC 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D5B0 8025ECD0 08097B78 */  j         .L8025EDE0
/* 18D5B4 8025ECD4 00000000 */   nop      
.L8025ECD8:
/* 18D5B8 8025ECD8 3C036666 */  lui       $v1, 0x6666
/* 18D5BC 8025ECDC 34636667 */  ori       $v1, $v1, 0x6667
/* 18D5C0 8025ECE0 92A20006 */  lbu       $v0, 6($s5)
/* 18D5C4 8025ECE4 3C17802A */  lui       $s7, 0x802a
/* 18D5C8 8025ECE8 26F7FA90 */  addiu     $s7, $s7, -0x570
/* 18D5CC 8025ECEC 00021600 */  sll       $v0, $v0, 0x18
/* 18D5D0 8025ECF0 00022E03 */  sra       $a1, $v0, 0x18
/* 18D5D4 8025ECF4 00A30018 */  mult      $a1, $v1
/* 18D5D8 8025ECF8 3C138028 */  lui       $s3, 0x8028
/* 18D5DC 8025ECFC 267341C0 */  addiu     $s3, $s3, 0x41c0
/* 18D5E0 8025ED00 8EF40010 */  lw        $s4, 0x10($s7)
/* 18D5E4 8025ED04 000217C3 */  sra       $v0, $v0, 0x1f
/* 18D5E8 8025ED08 00004810 */  mfhi      $t1
/* 18D5EC 8025ED0C 00091883 */  sra       $v1, $t1, 2
/* 18D5F0 8025ED10 00621823 */  subu      $v1, $v1, $v0
/* 18D5F4 8025ED14 00031600 */  sll       $v0, $v1, 0x18
/* 18D5F8 8025ED18 00028603 */  sra       $s0, $v0, 0x18
/* 18D5FC 8025ED1C 00031080 */  sll       $v0, $v1, 2
/* 18D600 8025ED20 00431021 */  addu      $v0, $v0, $v1
/* 18D604 8025ED24 00021040 */  sll       $v0, $v0, 1
/* 18D608 8025ED28 00A22823 */  subu      $a1, $a1, $v0
/* 18D60C 8025ED2C 00052E00 */  sll       $a1, $a1, 0x18
/* 18D610 8025ED30 00059603 */  sra       $s2, $a1, 0x18
/* 18D614 8025ED34 00101080 */  sll       $v0, $s0, 2
/* 18D618 8025ED38 3C058028 */  lui       $a1, 0x8028
/* 18D61C 8025ED3C 00A22821 */  addu      $a1, $a1, $v0
/* 18D620 8025ED40 8CA541C0 */  lw        $a1, 0x41c0($a1)
/* 18D624 8025ED44 0C0511FF */  jal       set_menu_icon_script
/* 18D628 8025ED48 0280202D */   daddu    $a0, $s4, $zero
/* 18D62C 8025ED4C 12000004 */  beqz      $s0, .L8025ED60
/* 18D630 8025ED50 0280202D */   daddu    $a0, $s4, $zero
/* 18D634 8025ED54 0C05128B */  jal       clear_icon_flags
/* 18D638 8025ED58 24050002 */   addiu    $a1, $zero, 2
/* 18D63C 8025ED5C 0280202D */  daddu     $a0, $s4, $zero
.L8025ED60:
/* 18D640 8025ED60 27B10028 */  addiu     $s1, $sp, 0x28
/* 18D644 8025ED64 0220282D */  daddu     $a1, $s1, $zero
/* 18D648 8025ED68 27B0002C */  addiu     $s0, $sp, 0x2c
/* 18D64C 8025ED6C 0C05126B */  jal       get_icon_render_pos
/* 18D650 8025ED70 0200302D */   daddu    $a2, $s0, $zero
/* 18D654 8025ED74 0280202D */  daddu     $a0, $s4, $zero
/* 18D658 8025ED78 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D65C 8025ED7C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D660 8025ED80 24A5FFFA */  addiu     $a1, $a1, -6
/* 18D664 8025ED84 0C051261 */  jal       set_icon_render_pos
/* 18D668 8025ED88 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D66C 8025ED8C 00121080 */  sll       $v0, $s2, 2
/* 18D670 8025ED90 00531021 */  addu      $v0, $v0, $s3
/* 18D674 8025ED94 8EF40014 */  lw        $s4, 0x14($s7)
/* 18D678 8025ED98 8C450000 */  lw        $a1, ($v0)
/* 18D67C 8025ED9C 0C0511FF */  jal       set_menu_icon_script
/* 18D680 8025EDA0 0280202D */   daddu    $a0, $s4, $zero
/* 18D684 8025EDA4 0280202D */  daddu     $a0, $s4, $zero
/* 18D688 8025EDA8 0C05128B */  jal       clear_icon_flags
/* 18D68C 8025EDAC 24050002 */   addiu    $a1, $zero, 2
/* 18D690 8025EDB0 0280202D */  daddu     $a0, $s4, $zero
/* 18D694 8025EDB4 0220282D */  daddu     $a1, $s1, $zero
/* 18D698 8025EDB8 0C05126B */  jal       get_icon_render_pos
/* 18D69C 8025EDBC 0200302D */   daddu    $a2, $s0, $zero
/* 18D6A0 8025EDC0 0280202D */  daddu     $a0, $s4, $zero
/* 18D6A4 8025EDC4 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D6A8 8025EDC8 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D6AC 8025EDCC 24A50002 */  addiu     $a1, $a1, 2
/* 18D6B0 8025EDD0 0C051261 */  jal       set_icon_render_pos
/* 18D6B4 8025EDD4 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D6B8 8025EDD8 24020001 */  addiu     $v0, $zero, 1
/* 18D6BC 8025EDDC AEC20004 */  sw        $v0, 4($s6)
.L8025EDE0:
/* 18D6C0 8025EDE0 0C03A752 */  jal       is_ability_active
/* 18D6C4 8025EDE4 2404000C */   addiu    $a0, $zero, 0xc
/* 18D6C8 8025EDE8 1040001B */  beqz      $v0, .L8025EE58
/* 18D6CC 8025EDEC 00000000 */   nop      
/* 18D6D0 8025EDF0 3C028009 */  lui       $v0, 0x8009
/* 18D6D4 8025EDF4 844297E4 */  lh        $v0, -0x681c($v0)
/* 18D6D8 8025EDF8 3C14802A */  lui       $s4, 0x802a
/* 18D6DC 8025EDFC 8E94FAA8 */  lw        $s4, -0x558($s4)
/* 18D6E0 8025EE00 000210C0 */  sll       $v0, $v0, 3
/* 18D6E4 8025EE04 3C058009 */  lui       $a1, 0x8009
/* 18D6E8 8025EE08 00A22821 */  addu      $a1, $a1, $v0
/* 18D6EC 8025EE0C 8CA5A680 */  lw        $a1, -0x5980($a1)
/* 18D6F0 8025EE10 0C0511FF */  jal       set_menu_icon_script
/* 18D6F4 8025EE14 0280202D */   daddu    $a0, $s4, $zero
/* 18D6F8 8025EE18 0280202D */  daddu     $a0, $s4, $zero
/* 18D6FC 8025EE1C 0C05128B */  jal       clear_icon_flags
/* 18D700 8025EE20 24050002 */   addiu    $a1, $zero, 2
/* 18D704 8025EE24 3C053F00 */  lui       $a1, 0x3f00
/* 18D708 8025EE28 0C051308 */  jal       func_80144C20
/* 18D70C 8025EE2C 0280202D */   daddu    $a0, $s4, $zero
/* 18D710 8025EE30 0280202D */  daddu     $a0, $s4, $zero
/* 18D714 8025EE34 27A50028 */  addiu     $a1, $sp, 0x28
/* 18D718 8025EE38 0C05126B */  jal       get_icon_render_pos
/* 18D71C 8025EE3C 27A6002C */   addiu    $a2, $sp, 0x2c
/* 18D720 8025EE40 0280202D */  daddu     $a0, $s4, $zero
/* 18D724 8025EE44 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D728 8025EE48 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D72C 8025EE4C 24A50011 */  addiu     $a1, $a1, 0x11
/* 18D730 8025EE50 0C051261 */  jal       set_icon_render_pos
/* 18D734 8025EE54 24C6002E */   addiu    $a2, $a2, 0x2e
.L8025EE58:
/* 18D738 8025EE58 82A30004 */  lb        $v1, 4($s5)
/* 18D73C 8025EE5C 24020032 */  addiu     $v0, $zero, 0x32
/* 18D740 8025EE60 1062008C */  beq       $v1, $v0, .L8025F094
/* 18D744 8025EE64 3C096666 */   lui      $t1, 0x6666
/* 18D748 8025EE68 35296667 */  ori       $t1, $t1, 0x6667
/* 18D74C 8025EE6C 3C17802A */  lui       $s7, 0x802a
/* 18D750 8025EE70 26F7FA90 */  addiu     $s7, $s7, -0x570
/* 18D754 8025EE74 92A20003 */  lbu       $v0, 3($s5)
/* 18D758 8025EE78 00021600 */  sll       $v0, $v0, 0x18
/* 18D75C 8025EE7C 00022E03 */  sra       $a1, $v0, 0x18
/* 18D760 8025EE80 00A90018 */  mult      $a1, $t1
/* 18D764 8025EE84 3C118028 */  lui       $s1, 0x8028
/* 18D768 8025EE88 26314238 */  addiu     $s1, $s1, 0x4238
/* 18D76C 8025EE8C AFA90034 */  sw        $t1, 0x34($sp)
/* 18D770 8025EE90 8EF40020 */  lw        $s4, 0x20($s7)
/* 18D774 8025EE94 000217C3 */  sra       $v0, $v0, 0x1f
/* 18D778 8025EE98 00004810 */  mfhi      $t1
/* 18D77C 8025EE9C 00091883 */  sra       $v1, $t1, 2
/* 18D780 8025EEA0 00621823 */  subu      $v1, $v1, $v0
/* 18D784 8025EEA4 00031600 */  sll       $v0, $v1, 0x18
/* 18D788 8025EEA8 00028603 */  sra       $s0, $v0, 0x18
/* 18D78C 8025EEAC 00031080 */  sll       $v0, $v1, 2
/* 18D790 8025EEB0 00431021 */  addu      $v0, $v0, $v1
/* 18D794 8025EEB4 00021040 */  sll       $v0, $v0, 1
/* 18D798 8025EEB8 00A22823 */  subu      $a1, $a1, $v0
/* 18D79C 8025EEBC 00052E00 */  sll       $a1, $a1, 0x18
/* 18D7A0 8025EEC0 00059603 */  sra       $s2, $a1, 0x18
/* 18D7A4 8025EEC4 00101080 */  sll       $v0, $s0, 2
/* 18D7A8 8025EEC8 3C058028 */  lui       $a1, 0x8028
/* 18D7AC 8025EECC 00A22821 */  addu      $a1, $a1, $v0
/* 18D7B0 8025EED0 8CA54260 */  lw        $a1, 0x4260($a1)
/* 18D7B4 8025EED4 0C0511FF */  jal       set_menu_icon_script
/* 18D7B8 8025EED8 0280202D */   daddu    $a0, $s4, $zero
/* 18D7BC 8025EEDC 12000004 */  beqz      $s0, .L8025EEF0
/* 18D7C0 8025EEE0 0280202D */   daddu    $a0, $s4, $zero
/* 18D7C4 8025EEE4 0C05128B */  jal       clear_icon_flags
/* 18D7C8 8025EEE8 24050002 */   addiu    $a1, $zero, 2
/* 18D7CC 8025EEEC 0280202D */  daddu     $a0, $s4, $zero
.L8025EEF0:
/* 18D7D0 8025EEF0 27B60028 */  addiu     $s6, $sp, 0x28
/* 18D7D4 8025EEF4 02C0282D */  daddu     $a1, $s6, $zero
/* 18D7D8 8025EEF8 27B3002C */  addiu     $s3, $sp, 0x2c
/* 18D7DC 8025EEFC 0C05126B */  jal       get_icon_render_pos
/* 18D7E0 8025EF00 0260302D */   daddu    $a2, $s3, $zero
/* 18D7E4 8025EF04 0280202D */  daddu     $a0, $s4, $zero
/* 18D7E8 8025EF08 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D7EC 8025EF0C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D7F0 8025EF10 24A5FFF2 */  addiu     $a1, $a1, -0xe
/* 18D7F4 8025EF14 0C051261 */  jal       set_icon_render_pos
/* 18D7F8 8025EF18 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D7FC 8025EF1C 00121080 */  sll       $v0, $s2, 2
/* 18D800 8025EF20 00511021 */  addu      $v0, $v0, $s1
/* 18D804 8025EF24 8EF40024 */  lw        $s4, 0x24($s7)
/* 18D808 8025EF28 8C450028 */  lw        $a1, 0x28($v0)
/* 18D80C 8025EF2C 0C0511FF */  jal       set_menu_icon_script
/* 18D810 8025EF30 0280202D */   daddu    $a0, $s4, $zero
/* 18D814 8025EF34 0280202D */  daddu     $a0, $s4, $zero
/* 18D818 8025EF38 0C05128B */  jal       clear_icon_flags
/* 18D81C 8025EF3C 24050002 */   addiu    $a1, $zero, 2
/* 18D820 8025EF40 0280202D */  daddu     $a0, $s4, $zero
/* 18D824 8025EF44 02C0282D */  daddu     $a1, $s6, $zero
/* 18D828 8025EF48 0C05126B */  jal       get_icon_render_pos
/* 18D82C 8025EF4C 0260302D */   daddu    $a2, $s3, $zero
/* 18D830 8025EF50 0280202D */  daddu     $a0, $s4, $zero
/* 18D834 8025EF54 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D838 8025EF58 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D83C 8025EF5C 24A5FFF8 */  addiu     $a1, $a1, -8
/* 18D840 8025EF60 0C051261 */  jal       set_icon_render_pos
/* 18D844 8025EF64 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D848 8025EF68 8EF40028 */  lw        $s4, 0x28($s7)
/* 18D84C 8025EF6C 3C05802B */  lui       $a1, 0x802b
/* 18D850 8025EF70 24A5A694 */  addiu     $a1, $a1, -0x596c
/* 18D854 8025EF74 0C0511FF */  jal       set_menu_icon_script
/* 18D858 8025EF78 0280202D */   daddu    $a0, $s4, $zero
/* 18D85C 8025EF7C 0280202D */  daddu     $a0, $s4, $zero
/* 18D860 8025EF80 0C05128B */  jal       clear_icon_flags
/* 18D864 8025EF84 24050002 */   addiu    $a1, $zero, 2
/* 18D868 8025EF88 0280202D */  daddu     $a0, $s4, $zero
/* 18D86C 8025EF8C 02C0282D */  daddu     $a1, $s6, $zero
/* 18D870 8025EF90 0C05126B */  jal       get_icon_render_pos
/* 18D874 8025EF94 0260302D */   daddu    $a2, $s3, $zero
/* 18D878 8025EF98 0280202D */  daddu     $a0, $s4, $zero
/* 18D87C 8025EF9C 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D880 8025EFA0 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D884 8025EFA4 24A5FFFD */  addiu     $a1, $a1, -3
/* 18D888 8025EFA8 0C051261 */  jal       set_icon_render_pos
/* 18D88C 8025EFAC 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D890 8025EFB0 82A30003 */  lb        $v1, 3($s5)
/* 18D894 8025EFB4 8FA90034 */  lw        $t1, 0x34($sp)
/* 18D898 8025EFB8 24630005 */  addiu     $v1, $v1, 5
/* 18D89C 8025EFBC 00690018 */  mult      $v1, $t1
/* 18D8A0 8025EFC0 3C118028 */  lui       $s1, 0x8028
/* 18D8A4 8025EFC4 263141C0 */  addiu     $s1, $s1, 0x41c0
/* 18D8A8 8025EFC8 8EF4002C */  lw        $s4, 0x2c($s7)
/* 18D8AC 8025EFCC 000317C3 */  sra       $v0, $v1, 0x1f
/* 18D8B0 8025EFD0 00004810 */  mfhi      $t1
/* 18D8B4 8025EFD4 00092883 */  sra       $a1, $t1, 2
/* 18D8B8 8025EFD8 00A29023 */  subu      $s2, $a1, $v0
/* 18D8BC 8025EFDC 0240802D */  daddu     $s0, $s2, $zero
/* 18D8C0 8025EFE0 00101080 */  sll       $v0, $s0, 2
/* 18D8C4 8025EFE4 00501021 */  addu      $v0, $v0, $s0
/* 18D8C8 8025EFE8 00021040 */  sll       $v0, $v0, 1
/* 18D8CC 8025EFEC 00629023 */  subu      $s2, $v1, $v0
/* 18D8D0 8025EFF0 00101080 */  sll       $v0, $s0, 2
/* 18D8D4 8025EFF4 3C058028 */  lui       $a1, 0x8028
/* 18D8D8 8025EFF8 00A22821 */  addu      $a1, $a1, $v0
/* 18D8DC 8025EFFC 8CA541E8 */  lw        $a1, 0x41e8($a1)
/* 18D8E0 8025F000 0C0511FF */  jal       set_menu_icon_script
/* 18D8E4 8025F004 0280202D */   daddu    $a0, $s4, $zero
/* 18D8E8 8025F008 12000003 */  beqz      $s0, .L8025F018
/* 18D8EC 8025F00C 0280202D */   daddu    $a0, $s4, $zero
/* 18D8F0 8025F010 0C05128B */  jal       clear_icon_flags
/* 18D8F4 8025F014 24050002 */   addiu    $a1, $zero, 2
.L8025F018:
/* 18D8F8 8025F018 0280202D */  daddu     $a0, $s4, $zero
/* 18D8FC 8025F01C 02C0282D */  daddu     $a1, $s6, $zero
/* 18D900 8025F020 0C05126B */  jal       get_icon_render_pos
/* 18D904 8025F024 0260302D */   daddu    $a2, $s3, $zero
/* 18D908 8025F028 0280202D */  daddu     $a0, $s4, $zero
/* 18D90C 8025F02C 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D910 8025F030 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D914 8025F034 24A50003 */  addiu     $a1, $a1, 3
/* 18D918 8025F038 0C051261 */  jal       set_icon_render_pos
/* 18D91C 8025F03C 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D920 8025F040 00121080 */  sll       $v0, $s2, 2
/* 18D924 8025F044 00511021 */  addu      $v0, $v0, $s1
/* 18D928 8025F048 8EF40030 */  lw        $s4, 0x30($s7)
/* 18D92C 8025F04C 8C450028 */  lw        $a1, 0x28($v0)
/* 18D930 8025F050 0C0511FF */  jal       set_menu_icon_script
/* 18D934 8025F054 0280202D */   daddu    $a0, $s4, $zero
/* 18D938 8025F058 0280202D */  daddu     $a0, $s4, $zero
/* 18D93C 8025F05C 0C05128B */  jal       clear_icon_flags
/* 18D940 8025F060 24050002 */   addiu    $a1, $zero, 2
/* 18D944 8025F064 0280202D */  daddu     $a0, $s4, $zero
/* 18D948 8025F068 02C0282D */  daddu     $a1, $s6, $zero
/* 18D94C 8025F06C 0C05126B */  jal       get_icon_render_pos
/* 18D950 8025F070 0260302D */   daddu    $a2, $s3, $zero
/* 18D954 8025F074 0280202D */  daddu     $a0, $s4, $zero
/* 18D958 8025F078 8FA50028 */  lw        $a1, 0x28($sp)
/* 18D95C 8025F07C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18D960 8025F080 24A5000A */  addiu     $a1, $a1, 0xa
/* 18D964 8025F084 0C051261 */  jal       set_icon_render_pos
/* 18D968 8025F088 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18D96C 8025F08C 08097C68 */  j         .L8025F1A0
/* 18D970 8025F090 00000000 */   nop      
.L8025F094:
/* 18D974 8025F094 3C036666 */  lui       $v1, 0x6666
/* 18D978 8025F098 34636667 */  ori       $v1, $v1, 0x6667
/* 18D97C 8025F09C 92A20003 */  lbu       $v0, 3($s5)
/* 18D980 8025F0A0 3C16802A */  lui       $s6, 0x802a
/* 18D984 8025F0A4 26D6FA90 */  addiu     $s6, $s6, -0x570
/* 18D988 8025F0A8 00021600 */  sll       $v0, $v0, 0x18
/* 18D98C 8025F0AC 00022E03 */  sra       $a1, $v0, 0x18
/* 18D990 8025F0B0 00A30018 */  mult      $a1, $v1
/* 18D994 8025F0B4 3C138028 */  lui       $s3, 0x8028
/* 18D998 8025F0B8 267341C0 */  addiu     $s3, $s3, 0x41c0
/* 18D99C 8025F0BC 8ED4002C */  lw        $s4, 0x2c($s6)
/* 18D9A0 8025F0C0 000217C3 */  sra       $v0, $v0, 0x1f
/* 18D9A4 8025F0C4 00004810 */  mfhi      $t1
/* 18D9A8 8025F0C8 00091883 */  sra       $v1, $t1, 2
/* 18D9AC 8025F0CC 00621823 */  subu      $v1, $v1, $v0
/* 18D9B0 8025F0D0 00031600 */  sll       $v0, $v1, 0x18
/* 18D9B4 8025F0D4 00028603 */  sra       $s0, $v0, 0x18
/* 18D9B8 8025F0D8 00031080 */  sll       $v0, $v1, 2
/* 18D9BC 8025F0DC 00431021 */  addu      $v0, $v0, $v1
/* 18D9C0 8025F0E0 00021040 */  sll       $v0, $v0, 1
/* 18D9C4 8025F0E4 00A22823 */  subu      $a1, $a1, $v0
/* 18D9C8 8025F0E8 00052E00 */  sll       $a1, $a1, 0x18
/* 18D9CC 8025F0EC 00059603 */  sra       $s2, $a1, 0x18
/* 18D9D0 8025F0F0 00101080 */  sll       $v0, $s0, 2
/* 18D9D4 8025F0F4 3C058028 */  lui       $a1, 0x8028
/* 18D9D8 8025F0F8 00A22821 */  addu      $a1, $a1, $v0
/* 18D9DC 8025F0FC 8CA541E8 */  lw        $a1, 0x41e8($a1)
/* 18D9E0 8025F100 0C0511FF */  jal       set_menu_icon_script
/* 18D9E4 8025F104 0280202D */   daddu    $a0, $s4, $zero
/* 18D9E8 8025F108 12000004 */  beqz      $s0, .L8025F11C
/* 18D9EC 8025F10C 0280202D */   daddu    $a0, $s4, $zero
/* 18D9F0 8025F110 0C05128B */  jal       clear_icon_flags
/* 18D9F4 8025F114 24050002 */   addiu    $a1, $zero, 2
/* 18D9F8 8025F118 0280202D */  daddu     $a0, $s4, $zero
.L8025F11C:
/* 18D9FC 8025F11C 27B10028 */  addiu     $s1, $sp, 0x28
/* 18DA00 8025F120 0220282D */  daddu     $a1, $s1, $zero
/* 18DA04 8025F124 27B0002C */  addiu     $s0, $sp, 0x2c
/* 18DA08 8025F128 0C05126B */  jal       get_icon_render_pos
/* 18DA0C 8025F12C 0200302D */   daddu    $a2, $s0, $zero
/* 18DA10 8025F130 0280202D */  daddu     $a0, $s4, $zero
/* 18DA14 8025F134 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DA18 8025F138 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DA1C 8025F13C 24A5FFFA */  addiu     $a1, $a1, -6
/* 18DA20 8025F140 0C051261 */  jal       set_icon_render_pos
/* 18DA24 8025F144 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18DA28 8025F148 00121080 */  sll       $v0, $s2, 2
/* 18DA2C 8025F14C 00531021 */  addu      $v0, $v0, $s3
/* 18DA30 8025F150 8ED40030 */  lw        $s4, 0x30($s6)
/* 18DA34 8025F154 8C450028 */  lw        $a1, 0x28($v0)
/* 18DA38 8025F158 0C0511FF */  jal       set_menu_icon_script
/* 18DA3C 8025F15C 0280202D */   daddu    $a0, $s4, $zero
/* 18DA40 8025F160 0280202D */  daddu     $a0, $s4, $zero
/* 18DA44 8025F164 0C05128B */  jal       clear_icon_flags
/* 18DA48 8025F168 24050002 */   addiu    $a1, $zero, 2
/* 18DA4C 8025F16C 0280202D */  daddu     $a0, $s4, $zero
/* 18DA50 8025F170 0220282D */  daddu     $a1, $s1, $zero
/* 18DA54 8025F174 0C05126B */  jal       get_icon_render_pos
/* 18DA58 8025F178 0200302D */   daddu    $a2, $s0, $zero
/* 18DA5C 8025F17C 0280202D */  daddu     $a0, $s4, $zero
/* 18DA60 8025F180 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DA64 8025F184 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DA68 8025F188 24A50002 */  addiu     $a1, $a1, 2
/* 18DA6C 8025F18C 0C051261 */  jal       set_icon_render_pos
/* 18DA70 8025F190 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18DA74 8025F194 24020001 */  addiu     $v0, $zero, 1
/* 18DA78 8025F198 3C01802A */  lui       $at, 0x802a
/* 18DA7C 8025F19C AC22FB60 */  sw        $v0, -0x4a0($at)
.L8025F1A0:
/* 18DA80 8025F1A0 0C03A752 */  jal       is_ability_active
/* 18DA84 8025F1A4 24040004 */   addiu    $a0, $zero, 4
/* 18DA88 8025F1A8 1040001B */  beqz      $v0, .L8025F218
/* 18DA8C 8025F1AC 00000000 */   nop      
/* 18DA90 8025F1B0 3C028009 */  lui       $v0, 0x8009
/* 18DA94 8025F1B4 844295C4 */  lh        $v0, -0x6a3c($v0)
/* 18DA98 8025F1B8 3C14802A */  lui       $s4, 0x802a
/* 18DA9C 8025F1BC 8E94FAC4 */  lw        $s4, -0x53c($s4)
/* 18DAA0 8025F1C0 000210C0 */  sll       $v0, $v0, 3
/* 18DAA4 8025F1C4 3C058009 */  lui       $a1, 0x8009
/* 18DAA8 8025F1C8 00A22821 */  addu      $a1, $a1, $v0
/* 18DAAC 8025F1CC 8CA5A680 */  lw        $a1, -0x5980($a1)
/* 18DAB0 8025F1D0 0C0511FF */  jal       set_menu_icon_script
/* 18DAB4 8025F1D4 0280202D */   daddu    $a0, $s4, $zero
/* 18DAB8 8025F1D8 0280202D */  daddu     $a0, $s4, $zero
/* 18DABC 8025F1DC 0C05128B */  jal       clear_icon_flags
/* 18DAC0 8025F1E0 24050002 */   addiu    $a1, $zero, 2
/* 18DAC4 8025F1E4 3C053F00 */  lui       $a1, 0x3f00
/* 18DAC8 8025F1E8 0C051308 */  jal       func_80144C20
/* 18DACC 8025F1EC 0280202D */   daddu    $a0, $s4, $zero
/* 18DAD0 8025F1F0 0280202D */  daddu     $a0, $s4, $zero
/* 18DAD4 8025F1F4 27A50028 */  addiu     $a1, $sp, 0x28
/* 18DAD8 8025F1F8 0C05126B */  jal       get_icon_render_pos
/* 18DADC 8025F1FC 27A6002C */   addiu    $a2, $sp, 0x2c
/* 18DAE0 8025F200 0280202D */  daddu     $a0, $s4, $zero
/* 18DAE4 8025F204 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DAE8 8025F208 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DAEC 8025F20C 24A50011 */  addiu     $a1, $a1, 0x11
/* 18DAF0 8025F210 0C051261 */  jal       set_icon_render_pos
/* 18DAF4 8025F214 24C6002E */   addiu    $a2, $a2, 0x2e
.L8025F218:
/* 18DAF8 8025F218 92A20008 */  lbu       $v0, 8($s5)
/* 18DAFC 8025F21C 00023600 */  sll       $a2, $v0, 0x18
/* 18DB00 8025F220 00062E03 */  sra       $a1, $a2, 0x18
/* 18DB04 8025F224 2402001E */  addiu     $v0, $zero, 0x1e
/* 18DB08 8025F228 10A20089 */  beq       $a1, $v0, .L8025F450
/* 18DB0C 8025F22C 3C096666 */   lui      $t1, 0x6666
/* 18DB10 8025F230 35296667 */  ori       $t1, $t1, 0x6667
/* 18DB14 8025F234 3C17802A */  lui       $s7, 0x802a
/* 18DB18 8025F238 26F7FA90 */  addiu     $s7, $s7, -0x570
/* 18DB1C 8025F23C 00A90018 */  mult      $a1, $t1
/* 18DB20 8025F240 000617C3 */  sra       $v0, $a2, 0x1f
/* 18DB24 8025F244 3C118028 */  lui       $s1, 0x8028
/* 18DB28 8025F248 26314238 */  addiu     $s1, $s1, 0x4238
/* 18DB2C 8025F24C AFA90038 */  sw        $t1, 0x38($sp)
/* 18DB30 8025F250 8EF4003C */  lw        $s4, 0x3c($s7)
/* 18DB34 8025F254 00004810 */  mfhi      $t1
/* 18DB38 8025F258 00091883 */  sra       $v1, $t1, 2
/* 18DB3C 8025F25C 00621823 */  subu      $v1, $v1, $v0
/* 18DB40 8025F260 00031600 */  sll       $v0, $v1, 0x18
/* 18DB44 8025F264 00028603 */  sra       $s0, $v0, 0x18
/* 18DB48 8025F268 00031080 */  sll       $v0, $v1, 2
/* 18DB4C 8025F26C 00431021 */  addu      $v0, $v0, $v1
/* 18DB50 8025F270 00021040 */  sll       $v0, $v0, 1
/* 18DB54 8025F274 00A21023 */  subu      $v0, $a1, $v0
/* 18DB58 8025F278 00021600 */  sll       $v0, $v0, 0x18
/* 18DB5C 8025F27C 00029603 */  sra       $s2, $v0, 0x18
/* 18DB60 8025F280 00101080 */  sll       $v0, $s0, 2
/* 18DB64 8025F284 3C058028 */  lui       $a1, 0x8028
/* 18DB68 8025F288 00A22821 */  addu      $a1, $a1, $v0
/* 18DB6C 8025F28C 8CA54288 */  lw        $a1, 0x4288($a1)
/* 18DB70 8025F290 0C0511FF */  jal       set_menu_icon_script
/* 18DB74 8025F294 0280202D */   daddu    $a0, $s4, $zero
/* 18DB78 8025F298 12000004 */  beqz      $s0, .L8025F2AC
/* 18DB7C 8025F29C 0280202D */   daddu    $a0, $s4, $zero
/* 18DB80 8025F2A0 0C05128B */  jal       clear_icon_flags
/* 18DB84 8025F2A4 24050002 */   addiu    $a1, $zero, 2
/* 18DB88 8025F2A8 0280202D */  daddu     $a0, $s4, $zero
.L8025F2AC:
/* 18DB8C 8025F2AC 27B60028 */  addiu     $s6, $sp, 0x28
/* 18DB90 8025F2B0 02C0282D */  daddu     $a1, $s6, $zero
/* 18DB94 8025F2B4 27B3002C */  addiu     $s3, $sp, 0x2c
/* 18DB98 8025F2B8 0C05126B */  jal       get_icon_render_pos
/* 18DB9C 8025F2BC 0260302D */   daddu    $a2, $s3, $zero
/* 18DBA0 8025F2C0 0280202D */  daddu     $a0, $s4, $zero
/* 18DBA4 8025F2C4 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DBA8 8025F2C8 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DBAC 8025F2CC 24A5FFF2 */  addiu     $a1, $a1, -0xe
/* 18DBB0 8025F2D0 0C051261 */  jal       set_icon_render_pos
/* 18DBB4 8025F2D4 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18DBB8 8025F2D8 00121080 */  sll       $v0, $s2, 2
/* 18DBBC 8025F2DC 00511021 */  addu      $v0, $v0, $s1
/* 18DBC0 8025F2E0 8EF40040 */  lw        $s4, 0x40($s7)
/* 18DBC4 8025F2E4 8C450050 */  lw        $a1, 0x50($v0)
/* 18DBC8 8025F2E8 0C0511FF */  jal       set_menu_icon_script
/* 18DBCC 8025F2EC 0280202D */   daddu    $a0, $s4, $zero
/* 18DBD0 8025F2F0 0280202D */  daddu     $a0, $s4, $zero
/* 18DBD4 8025F2F4 0C05128B */  jal       clear_icon_flags
/* 18DBD8 8025F2F8 24050002 */   addiu    $a1, $zero, 2
/* 18DBDC 8025F2FC 0280202D */  daddu     $a0, $s4, $zero
/* 18DBE0 8025F300 02C0282D */  daddu     $a1, $s6, $zero
/* 18DBE4 8025F304 0C05126B */  jal       get_icon_render_pos
/* 18DBE8 8025F308 0260302D */   daddu    $a2, $s3, $zero
/* 18DBEC 8025F30C 0280202D */  daddu     $a0, $s4, $zero
/* 18DBF0 8025F310 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DBF4 8025F314 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DBF8 8025F318 24A5FFF8 */  addiu     $a1, $a1, -8
/* 18DBFC 8025F31C 0C051261 */  jal       set_icon_render_pos
/* 18DC00 8025F320 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18DC04 8025F324 8EF40044 */  lw        $s4, 0x44($s7)
/* 18DC08 8025F328 3C05802B */  lui       $a1, 0x802b
/* 18DC0C 8025F32C 24A5AA08 */  addiu     $a1, $a1, -0x55f8
/* 18DC10 8025F330 0C0511FF */  jal       set_menu_icon_script
/* 18DC14 8025F334 0280202D */   daddu    $a0, $s4, $zero
/* 18DC18 8025F338 0280202D */  daddu     $a0, $s4, $zero
/* 18DC1C 8025F33C 0C05128B */  jal       clear_icon_flags
/* 18DC20 8025F340 24050002 */   addiu    $a1, $zero, 2
/* 18DC24 8025F344 0280202D */  daddu     $a0, $s4, $zero
/* 18DC28 8025F348 02C0282D */  daddu     $a1, $s6, $zero
/* 18DC2C 8025F34C 0C05126B */  jal       get_icon_render_pos
/* 18DC30 8025F350 0260302D */   daddu    $a2, $s3, $zero
/* 18DC34 8025F354 0280202D */  daddu     $a0, $s4, $zero
/* 18DC38 8025F358 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DC3C 8025F35C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DC40 8025F360 24A5FFFD */  addiu     $a1, $a1, -3
/* 18DC44 8025F364 0C051261 */  jal       set_icon_render_pos
/* 18DC48 8025F368 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18DC4C 8025F36C 82A30008 */  lb        $v1, 8($s5)
/* 18DC50 8025F370 8FA90038 */  lw        $t1, 0x38($sp)
/* 18DC54 8025F374 24630003 */  addiu     $v1, $v1, 3
/* 18DC58 8025F378 00690018 */  mult      $v1, $t1
/* 18DC5C 8025F37C 3C118028 */  lui       $s1, 0x8028
/* 18DC60 8025F380 263141C0 */  addiu     $s1, $s1, 0x41c0
/* 18DC64 8025F384 8EF40048 */  lw        $s4, 0x48($s7)
/* 18DC68 8025F388 000317C3 */  sra       $v0, $v1, 0x1f
/* 18DC6C 8025F38C 00004810 */  mfhi      $t1
/* 18DC70 8025F390 00092883 */  sra       $a1, $t1, 2
/* 18DC74 8025F394 00A29023 */  subu      $s2, $a1, $v0
/* 18DC78 8025F398 0240802D */  daddu     $s0, $s2, $zero
/* 18DC7C 8025F39C 00101080 */  sll       $v0, $s0, 2
/* 18DC80 8025F3A0 00501021 */  addu      $v0, $v0, $s0
/* 18DC84 8025F3A4 00021040 */  sll       $v0, $v0, 1
/* 18DC88 8025F3A8 00629023 */  subu      $s2, $v1, $v0
/* 18DC8C 8025F3AC 00101080 */  sll       $v0, $s0, 2
/* 18DC90 8025F3B0 3C058028 */  lui       $a1, 0x8028
/* 18DC94 8025F3B4 00A22821 */  addu      $a1, $a1, $v0
/* 18DC98 8025F3B8 8CA54210 */  lw        $a1, 0x4210($a1)
/* 18DC9C 8025F3BC 0C0511FF */  jal       set_menu_icon_script
/* 18DCA0 8025F3C0 0280202D */   daddu    $a0, $s4, $zero
/* 18DCA4 8025F3C4 12000004 */  beqz      $s0, .L8025F3D8
/* 18DCA8 8025F3C8 0280202D */   daddu    $a0, $s4, $zero
/* 18DCAC 8025F3CC 0C05128B */  jal       clear_icon_flags
/* 18DCB0 8025F3D0 24050002 */   addiu    $a1, $zero, 2
/* 18DCB4 8025F3D4 0280202D */  daddu     $a0, $s4, $zero
.L8025F3D8:
/* 18DCB8 8025F3D8 02C0282D */  daddu     $a1, $s6, $zero
/* 18DCBC 8025F3DC 0C05126B */  jal       get_icon_render_pos
/* 18DCC0 8025F3E0 0260302D */   daddu    $a2, $s3, $zero
/* 18DCC4 8025F3E4 0280202D */  daddu     $a0, $s4, $zero
/* 18DCC8 8025F3E8 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DCCC 8025F3EC 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DCD0 8025F3F0 24A50003 */  addiu     $a1, $a1, 3
/* 18DCD4 8025F3F4 0C051261 */  jal       set_icon_render_pos
/* 18DCD8 8025F3F8 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18DCDC 8025F3FC 00121080 */  sll       $v0, $s2, 2
/* 18DCE0 8025F400 00511021 */  addu      $v0, $v0, $s1
/* 18DCE4 8025F404 8EF4004C */  lw        $s4, 0x4c($s7)
/* 18DCE8 8025F408 8C450050 */  lw        $a1, 0x50($v0)
/* 18DCEC 8025F40C 0C0511FF */  jal       set_menu_icon_script
/* 18DCF0 8025F410 0280202D */   daddu    $a0, $s4, $zero
/* 18DCF4 8025F414 0280202D */  daddu     $a0, $s4, $zero
/* 18DCF8 8025F418 0C05128B */  jal       clear_icon_flags
/* 18DCFC 8025F41C 24050002 */   addiu    $a1, $zero, 2
/* 18DD00 8025F420 0280202D */  daddu     $a0, $s4, $zero
/* 18DD04 8025F424 02C0282D */  daddu     $a1, $s6, $zero
/* 18DD08 8025F428 0C05126B */  jal       get_icon_render_pos
/* 18DD0C 8025F42C 0260302D */   daddu    $a2, $s3, $zero
/* 18DD10 8025F430 0280202D */  daddu     $a0, $s4, $zero
/* 18DD14 8025F434 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DD18 8025F438 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DD1C 8025F43C 24A5000A */  addiu     $a1, $a1, 0xa
/* 18DD20 8025F440 0C051261 */  jal       set_icon_render_pos
/* 18DD24 8025F444 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18DD28 8025F448 08097D3F */  j         .L8025F4FC
/* 18DD2C 8025F44C 00000000 */   nop      
.L8025F450:
/* 18DD30 8025F450 3C13802A */  lui       $s3, 0x802a
/* 18DD34 8025F454 2673FA90 */  addiu     $s3, $s3, -0x570
/* 18DD38 8025F458 3C128028 */  lui       $s2, 0x8028
/* 18DD3C 8025F45C 265241C0 */  addiu     $s2, $s2, 0x41c0
/* 18DD40 8025F460 8E740048 */  lw        $s4, 0x48($s3)
/* 18DD44 8025F464 8E45005C */  lw        $a1, 0x5c($s2)
/* 18DD48 8025F468 0C0511FF */  jal       set_menu_icon_script
/* 18DD4C 8025F46C 0280202D */   daddu    $a0, $s4, $zero
/* 18DD50 8025F470 0280202D */  daddu     $a0, $s4, $zero
/* 18DD54 8025F474 0C05128B */  jal       clear_icon_flags
/* 18DD58 8025F478 24050002 */   addiu    $a1, $zero, 2
/* 18DD5C 8025F47C 0280202D */  daddu     $a0, $s4, $zero
/* 18DD60 8025F480 27B10028 */  addiu     $s1, $sp, 0x28
/* 18DD64 8025F484 0220282D */  daddu     $a1, $s1, $zero
/* 18DD68 8025F488 27B0002C */  addiu     $s0, $sp, 0x2c
/* 18DD6C 8025F48C 0C05126B */  jal       get_icon_render_pos
/* 18DD70 8025F490 0200302D */   daddu    $a2, $s0, $zero
/* 18DD74 8025F494 0280202D */  daddu     $a0, $s4, $zero
/* 18DD78 8025F498 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DD7C 8025F49C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DD80 8025F4A0 24A5FFFA */  addiu     $a1, $a1, -6
/* 18DD84 8025F4A4 0C051261 */  jal       set_icon_render_pos
/* 18DD88 8025F4A8 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18DD8C 8025F4AC 8E74004C */  lw        $s4, 0x4c($s3)
/* 18DD90 8025F4B0 8E450050 */  lw        $a1, 0x50($s2)
/* 18DD94 8025F4B4 0C0511FF */  jal       set_menu_icon_script
/* 18DD98 8025F4B8 0280202D */   daddu    $a0, $s4, $zero
/* 18DD9C 8025F4BC 0280202D */  daddu     $a0, $s4, $zero
/* 18DDA0 8025F4C0 0C05128B */  jal       clear_icon_flags
/* 18DDA4 8025F4C4 24050002 */   addiu    $a1, $zero, 2
/* 18DDA8 8025F4C8 0280202D */  daddu     $a0, $s4, $zero
/* 18DDAC 8025F4CC 0220282D */  daddu     $a1, $s1, $zero
/* 18DDB0 8025F4D0 0C05126B */  jal       get_icon_render_pos
/* 18DDB4 8025F4D4 0200302D */   daddu    $a2, $s0, $zero
/* 18DDB8 8025F4D8 0280202D */  daddu     $a0, $s4, $zero
/* 18DDBC 8025F4DC 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DDC0 8025F4E0 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DDC4 8025F4E4 24A50002 */  addiu     $a1, $a1, 2
/* 18DDC8 8025F4E8 0C051261 */  jal       set_icon_render_pos
/* 18DDCC 8025F4EC 24C6002E */   addiu    $a2, $a2, 0x2e
/* 18DDD0 8025F4F0 24020001 */  addiu     $v0, $zero, 1
/* 18DDD4 8025F4F4 3C01802A */  lui       $at, 0x802a
/* 18DDD8 8025F4F8 AC22FB68 */  sw        $v0, -0x498($at)
.L8025F4FC:
/* 18DDDC 8025F4FC 3C048029 */  lui       $a0, 0x8029
/* 18DDE0 8025F500 24842C28 */  addiu     $a0, $a0, 0x2c28
/* 18DDE4 8025F504 0C050529 */  jal       create_icon
/* 18DDE8 8025F508 00000000 */   nop      
/* 18DDEC 8025F50C 0040A02D */  daddu     $s4, $v0, $zero
/* 18DDF0 8025F510 3C01802A */  lui       $at, 0x802a
/* 18DDF4 8025F514 AC34FAE8 */  sw        $s4, -0x518($at)
/* 18DDF8 8025F518 0C0513F6 */  jal       func_80144FD8
/* 18DDFC 8025F51C 0280202D */   daddu    $a0, $s4, $zero
/* 18DE00 8025F520 0280202D */  daddu     $a0, $s4, $zero
/* 18DE04 8025F524 2405009C */  addiu     $a1, $zero, 0x9c
/* 18DE08 8025F528 0C051261 */  jal       set_icon_render_pos
/* 18DE0C 8025F52C 2406000D */   addiu    $a2, $zero, 0xd
/* 18DE10 8025F530 0280202D */  daddu     $a0, $s4, $zero
/* 18DE14 8025F534 240500FF */  addiu     $a1, $zero, 0xff
/* 18DE18 8025F538 00A0302D */  daddu     $a2, $a1, $zero
/* 18DE1C 8025F53C 0C0513BF */  jal       icon_set_tint
/* 18DE20 8025F540 00A0382D */   daddu    $a3, $a1, $zero
/* 18DE24 8025F544 0280202D */  daddu     $a0, $s4, $zero
/* 18DE28 8025F548 0000282D */  daddu     $a1, $zero, $zero
/* 18DE2C 8025F54C 0C05149D */  jal       func_80145274
/* 18DE30 8025F550 2406FFDD */   addiu    $a2, $zero, -0x23
/* 18DE34 8025F554 44800000 */  mtc1      $zero, $f0
/* 18DE38 8025F558 0280202D */  daddu     $a0, $s4, $zero
/* 18DE3C 8025F55C 44050000 */  mfc1      $a1, $f0
/* 18DE40 8025F560 3C074334 */  lui       $a3, 0x4334
/* 18DE44 8025F564 0C051489 */  jal       func_80145224
/* 18DE48 8025F568 00A0302D */   daddu    $a2, $a1, $zero
/* 18DE4C 8025F56C 3C013F80 */  lui       $at, 0x3f80
/* 18DE50 8025F570 44810000 */  mtc1      $at, $f0
/* 18DE54 8025F574 0280202D */  daddu     $a0, $s4, $zero
/* 18DE58 8025F578 44050000 */  mfc1      $a1, $f0
/* 18DE5C 8025F57C 3C063FC0 */  lui       $a2, 0x3fc0
/* 18DE60 8025F580 0C051475 */  jal       func_801451D4
/* 18DE64 8025F584 00A0382D */   daddu    $a3, $a1, $zero
/* 18DE68 8025F588 0280202D */  daddu     $a0, $s4, $zero
/* 18DE6C 8025F58C 0C0513AC */  jal       icon_set_opacity
/* 18DE70 8025F590 240500C8 */   addiu    $a1, $zero, 0xc8
/* 18DE74 8025F594 0280202D */  daddu     $a0, $s4, $zero
/* 18DE78 8025F598 0C051280 */  jal       set_icon_flags
/* 18DE7C 8025F59C 34058080 */   ori      $a1, $zero, 0x8080
/* 18DE80 8025F5A0 3C04802B */  lui       $a0, 0x802b
/* 18DE84 8025F5A4 2484AA30 */  addiu     $a0, $a0, -0x55d0
/* 18DE88 8025F5A8 0C050529 */  jal       create_icon
/* 18DE8C 8025F5AC 00000000 */   nop      
/* 18DE90 8025F5B0 0040A02D */  daddu     $s4, $v0, $zero
/* 18DE94 8025F5B4 0280202D */  daddu     $a0, $s4, $zero
/* 18DE98 8025F5B8 0000282D */  daddu     $a1, $zero, $zero
/* 18DE9C 8025F5BC 3C01802A */  lui       $at, 0x802a
/* 18DEA0 8025F5C0 AC34FB48 */  sw        $s4, -0x4b8($at)
/* 18DEA4 8025F5C4 0C051261 */  jal       set_icon_render_pos
/* 18DEA8 8025F5C8 00A0302D */   daddu    $a2, $a1, $zero
/* 18DEAC 8025F5CC 0280202D */  daddu     $a0, $s4, $zero
/* 18DEB0 8025F5D0 0C051280 */  jal       set_icon_flags
/* 18DEB4 8025F5D4 24050080 */   addiu    $a1, $zero, 0x80
/* 18DEB8 8025F5D8 24020001 */  addiu     $v0, $zero, 1
/* 18DEBC 8025F5DC A3C20048 */  sb        $v0, 0x48($fp)
/* 18DEC0 8025F5E0 2402000A */  addiu     $v0, $zero, 0xa
/* 18DEC4 8025F5E4 3C01802A */  lui       $at, 0x802a
/* 18DEC8 8025F5E8 AC22FB4C */  sw        $v0, -0x4b4($at)
/* 18DECC 8025F5EC 08097FD0 */  j         .L8025FF40
/* 18DED0 8025F5F0 24020007 */   addiu    $v0, $zero, 7
/* 18DED4 8025F5F4 27A50028 */  addiu     $a1, $sp, 0x28
/* 18DED8 8025F5F8 27A6002C */  addiu     $a2, $sp, 0x2c
/* 18DEDC 8025F5FC 0000982D */  daddu     $s3, $zero, $zero
/* 18DEE0 8025F600 3C14802A */  lui       $s4, 0x802a
/* 18DEE4 8025F604 8E94FA80 */  lw        $s4, -0x580($s4)
/* 18DEE8 8025F608 3C10802A */  lui       $s0, 0x802a
/* 18DEEC 8025F60C 2610FA90 */  addiu     $s0, $s0, -0x570
/* 18DEF0 8025F610 0C05126B */  jal       get_icon_render_pos
/* 18DEF4 8025F614 0280202D */   daddu    $a0, $s4, $zero
/* 18DEF8 8025F618 0280202D */  daddu     $a0, $s4, $zero
/* 18DEFC 8025F61C 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DF00 8025F620 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DF04 8025F624 24A5FFEC */  addiu     $a1, $a1, -0x14
/* 18DF08 8025F628 0C051261 */  jal       set_icon_render_pos
/* 18DF0C 8025F62C AFA50028 */   sw       $a1, 0x28($sp)
/* 18DF10 8025F630 27A50028 */  addiu     $a1, $sp, 0x28
.L8025F634:
/* 18DF14 8025F634 27A6002C */  addiu     $a2, $sp, 0x2c
/* 18DF18 8025F638 8E14001C */  lw        $s4, 0x1c($s0)
/* 18DF1C 8025F63C 26100004 */  addiu     $s0, $s0, 4
/* 18DF20 8025F640 26730001 */  addiu     $s3, $s3, 1
/* 18DF24 8025F644 0C05126B */  jal       get_icon_render_pos
/* 18DF28 8025F648 0280202D */   daddu    $a0, $s4, $zero
/* 18DF2C 8025F64C 0280202D */  daddu     $a0, $s4, $zero
/* 18DF30 8025F650 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DF34 8025F654 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DF38 8025F658 24A5FFEC */  addiu     $a1, $a1, -0x14
/* 18DF3C 8025F65C 0C051261 */  jal       set_icon_render_pos
/* 18DF40 8025F660 AFA50028 */   sw       $a1, 0x28($sp)
/* 18DF44 8025F664 2A620007 */  slti      $v0, $s3, 7
/* 18DF48 8025F668 1440FFF2 */  bnez      $v0, .L8025F634
/* 18DF4C 8025F66C 27A50028 */   addiu    $a1, $sp, 0x28
/* 18DF50 8025F670 27B10028 */  addiu     $s1, $sp, 0x28
/* 18DF54 8025F674 0220282D */  daddu     $a1, $s1, $zero
/* 18DF58 8025F678 27B2002C */  addiu     $s2, $sp, 0x2c
/* 18DF5C 8025F67C 0240302D */  daddu     $a2, $s2, $zero
/* 18DF60 8025F680 0000982D */  daddu     $s3, $zero, $zero
/* 18DF64 8025F684 3C10802A */  lui       $s0, 0x802a
/* 18DF68 8025F688 2610FA80 */  addiu     $s0, $s0, -0x580
/* 18DF6C 8025F68C 8E140004 */  lw        $s4, 4($s0)
/* 18DF70 8025F690 3C15802A */  lui       $s5, 0x802a
/* 18DF74 8025F694 26B5FA90 */  addiu     $s5, $s5, -0x570
/* 18DF78 8025F698 0C05126B */  jal       get_icon_render_pos
/* 18DF7C 8025F69C 0280202D */   daddu    $a0, $s4, $zero
/* 18DF80 8025F6A0 0280202D */  daddu     $a0, $s4, $zero
/* 18DF84 8025F6A4 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DF88 8025F6A8 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DF8C 8025F6AC 24C6FFEC */  addiu     $a2, $a2, -0x14
/* 18DF90 8025F6B0 0C051261 */  jal       set_icon_render_pos
/* 18DF94 8025F6B4 AFA6002C */   sw       $a2, 0x2c($sp)
/* 18DF98 8025F6B8 0220282D */  daddu     $a1, $s1, $zero
/* 18DF9C 8025F6BC 8E14000C */  lw        $s4, 0xc($s0)
/* 18DFA0 8025F6C0 0240302D */  daddu     $a2, $s2, $zero
/* 18DFA4 8025F6C4 0C05126B */  jal       get_icon_render_pos
/* 18DFA8 8025F6C8 0280202D */   daddu    $a0, $s4, $zero
/* 18DFAC 8025F6CC 0280202D */  daddu     $a0, $s4, $zero
/* 18DFB0 8025F6D0 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DFB4 8025F6D4 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DFB8 8025F6D8 24C6FFEC */  addiu     $a2, $a2, -0x14
/* 18DFBC 8025F6DC 0C051261 */  jal       set_icon_render_pos
/* 18DFC0 8025F6E0 AFA6002C */   sw       $a2, 0x2c($sp)
/* 18DFC4 8025F6E4 27A50028 */  addiu     $a1, $sp, 0x28
.L8025F6E8:
/* 18DFC8 8025F6E8 27A6002C */  addiu     $a2, $sp, 0x2c
/* 18DFCC 8025F6EC 8EB40000 */  lw        $s4, ($s5)
/* 18DFD0 8025F6F0 26B50004 */  addiu     $s5, $s5, 4
/* 18DFD4 8025F6F4 26730001 */  addiu     $s3, $s3, 1
/* 18DFD8 8025F6F8 0C05126B */  jal       get_icon_render_pos
/* 18DFDC 8025F6FC 0280202D */   daddu    $a0, $s4, $zero
/* 18DFE0 8025F700 0280202D */  daddu     $a0, $s4, $zero
/* 18DFE4 8025F704 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18DFE8 8025F708 8FA50028 */  lw        $a1, 0x28($sp)
/* 18DFEC 8025F70C 24C6FFEC */  addiu     $a2, $a2, -0x14
/* 18DFF0 8025F710 0C051261 */  jal       set_icon_render_pos
/* 18DFF4 8025F714 AFA6002C */   sw       $a2, 0x2c($sp)
/* 18DFF8 8025F718 2A620007 */  slti      $v0, $s3, 7
/* 18DFFC 8025F71C 1440FFF2 */  bnez      $v0, .L8025F6E8
/* 18E000 8025F720 27A50028 */   addiu    $a1, $sp, 0x28
/* 18E004 8025F724 27A6002C */  addiu     $a2, $sp, 0x2c
/* 18E008 8025F728 0000982D */  daddu     $s3, $zero, $zero
/* 18E00C 8025F72C 3C14802A */  lui       $s4, 0x802a
/* 18E010 8025F730 8E94FA88 */  lw        $s4, -0x578($s4)
/* 18E014 8025F734 3C10802A */  lui       $s0, 0x802a
/* 18E018 8025F738 2610FA90 */  addiu     $s0, $s0, -0x570
/* 18E01C 8025F73C 0C05126B */  jal       get_icon_render_pos
/* 18E020 8025F740 0280202D */   daddu    $a0, $s4, $zero
/* 18E024 8025F744 0280202D */  daddu     $a0, $s4, $zero
/* 18E028 8025F748 8FA50028 */  lw        $a1, 0x28($sp)
/* 18E02C 8025F74C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18E030 8025F750 24A50014 */  addiu     $a1, $a1, 0x14
/* 18E034 8025F754 0C051261 */  jal       set_icon_render_pos
/* 18E038 8025F758 AFA50028 */   sw       $a1, 0x28($sp)
/* 18E03C 8025F75C 27A50028 */  addiu     $a1, $sp, 0x28
.L8025F760:
/* 18E040 8025F760 27A6002C */  addiu     $a2, $sp, 0x2c
/* 18E044 8025F764 8E140038 */  lw        $s4, 0x38($s0)
/* 18E048 8025F768 26100004 */  addiu     $s0, $s0, 4
/* 18E04C 8025F76C 26730001 */  addiu     $s3, $s3, 1
/* 18E050 8025F770 0C05126B */  jal       get_icon_render_pos
/* 18E054 8025F774 0280202D */   daddu    $a0, $s4, $zero
/* 18E058 8025F778 0280202D */  daddu     $a0, $s4, $zero
/* 18E05C 8025F77C 8FA50028 */  lw        $a1, 0x28($sp)
/* 18E060 8025F780 8FA6002C */  lw        $a2, 0x2c($sp)
/* 18E064 8025F784 24A50014 */  addiu     $a1, $a1, 0x14
/* 18E068 8025F788 0C051261 */  jal       set_icon_render_pos
/* 18E06C 8025F78C AFA50028 */   sw       $a1, 0x28($sp)
/* 18E070 8025F790 2A620007 */  slti      $v0, $s3, 7
/* 18E074 8025F794 1440FFF2 */  bnez      $v0, .L8025F760
/* 18E078 8025F798 27A50028 */   addiu    $a1, $sp, 0x28
/* 18E07C 8025F79C 3C03802A */  lui       $v1, 0x802a
/* 18E080 8025F7A0 2463FB4C */  addiu     $v1, $v1, -0x4b4
/* 18E084 8025F7A4 8C620000 */  lw        $v0, ($v1)
/* 18E088 8025F7A8 2442FFFF */  addiu     $v0, $v0, -1
/* 18E08C 8025F7AC 144001E6 */  bnez      $v0, .L8025FF48
/* 18E090 8025F7B0 AC620000 */   sw       $v0, ($v1)
/* 18E094 8025F7B4 0280202D */  daddu     $a0, $s4, $zero
/* 18E098 8025F7B8 24050080 */  addiu     $a1, $zero, 0x80
/* 18E09C 8025F7BC 00A0302D */  daddu     $a2, $a1, $zero
/* 18E0A0 8025F7C0 0C0513BF */  jal       icon_set_tint
/* 18E0A4 8025F7C4 00A0382D */   daddu    $a3, $a1, $zero
/* 18E0A8 8025F7C8 24040008 */  addiu     $a0, $zero, 8
/* 18E0AC 8025F7CC 24050014 */  addiu     $a1, $zero, 0x14
/* 18E0B0 8025F7D0 240600BA */  addiu     $a2, $zero, 0xba
/* 18E0B4 8025F7D4 24070118 */  addiu     $a3, $zero, 0x118
/* 18E0B8 8025F7D8 00A0182D */  daddu     $v1, $a1, $zero
/* 18E0BC 8025F7DC 00C0102D */  daddu     $v0, $a2, $zero
/* 18E0C0 8025F7E0 AFA2002C */  sw        $v0, 0x2c($sp)
/* 18E0C4 8025F7E4 24020020 */  addiu     $v0, $zero, 0x20
/* 18E0C8 8025F7E8 AFA30028 */  sw        $v1, 0x28($sp)
/* 18E0CC 8025F7EC AFA20010 */  sw        $v0, 0x10($sp)
/* 18E0D0 8025F7F0 3C028026 */  lui       $v0, 0x8026
/* 18E0D4 8025F7F4 24420948 */  addiu     $v0, $v0, 0x948
/* 18E0D8 8025F7F8 AFA20018 */  sw        $v0, 0x18($sp)
/* 18E0DC 8025F7FC 2402FFFF */  addiu     $v0, $zero, -1
/* 18E0E0 8025F800 AFA30014 */  sw        $v1, 0x14($sp)
/* 18E0E4 8025F804 AFA0001C */  sw        $zero, 0x1c($sp)
/* 18E0E8 8025F808 0C051F32 */  jal       set_ui_panel_properties
/* 18E0EC 8025F80C AFA20020 */   sw       $v0, 0x20($sp)
/* 18E0F0 8025F810 24040008 */  addiu     $a0, $zero, 8
/* 18E0F4 8025F814 0C051F9F */  jal       func_80147E7C
/* 18E0F8 8025F818 24050001 */   addiu    $a1, $zero, 1
/* 18E0FC 8025F81C 08097FD0 */  j         .L8025FF40
/* 18E100 8025F820 24020008 */   addiu    $v0, $zero, 8
/* 18E104 8025F824 8FC20214 */  lw        $v0, 0x214($fp)
/* 18E108 8025F828 30428000 */  andi      $v0, $v0, 0x8000
/* 18E10C 8025F82C 10400012 */  beqz      $v0, .L8025F878
/* 18E110 8025F830 00000000 */   nop      
/* 18E114 8025F834 83C20048 */  lb        $v0, 0x48($fp)
/* 18E118 8025F838 00021080 */  sll       $v0, $v0, 2
/* 18E11C 8025F83C 3C01802A */  lui       $at, 0x802a
/* 18E120 8025F840 00220821 */  addu      $at, $at, $v0
/* 18E124 8025F844 8C22FB60 */  lw        $v0, -0x4a0($at)
/* 18E128 8025F848 14400007 */  bnez      $v0, .L8025F868
/* 18E12C 8025F84C 00000000 */   nop      
/* 18E130 8025F850 0C05272D */  jal       play_sound
/* 18E134 8025F854 240400C9 */   addiu    $a0, $zero, 0xc9
/* 18E138 8025F858 0C05272D */  jal       play_sound
/* 18E13C 8025F85C 24040749 */   addiu    $a0, $zero, 0x749
/* 18E140 8025F860 08097FD0 */  j         .L8025FF40
/* 18E144 8025F864 24020009 */   addiu    $v0, $zero, 9
.L8025F868:
/* 18E148 8025F868 0C05272D */  jal       play_sound
/* 18E14C 8025F86C 2404021D */   addiu    $a0, $zero, 0x21d
/* 18E150 8025F870 08097FD0 */  j         .L8025FF40
/* 18E154 8025F874 2402000F */   addiu    $v0, $zero, 0xf
.L8025F878:
/* 18E158 8025F878 93C20048 */  lbu       $v0, 0x48($fp)
/* 18E15C 8025F87C 8FC30218 */  lw        $v1, 0x218($fp)
/* 18E160 8025F880 00022600 */  sll       $a0, $v0, 0x18
/* 18E164 8025F884 3C020004 */  lui       $v0, 4
/* 18E168 8025F888 00621024 */  and       $v0, $v1, $v0
/* 18E16C 8025F88C 10400002 */  beqz      $v0, .L8025F898
/* 18E170 8025F890 00048603 */   sra      $s0, $a0, 0x18
/* 18E174 8025F894 2610FFFF */  addiu     $s0, $s0, -1
.L8025F898:
/* 18E178 8025F898 3C020008 */  lui       $v0, 8
/* 18E17C 8025F89C 00621024 */  and       $v0, $v1, $v0
/* 18E180 8025F8A0 54400001 */  bnel      $v0, $zero, .L8025F8A8
/* 18E184 8025F8A4 26100001 */   addiu    $s0, $s0, 1
.L8025F8A8:
/* 18E188 8025F8A8 06020001 */  bltzl     $s0, .L8025F8B0
/* 18E18C 8025F8AC 0000802D */   daddu    $s0, $zero, $zero
.L8025F8B0:
/* 18E190 8025F8B0 2A020003 */  slti      $v0, $s0, 3
/* 18E194 8025F8B4 50400001 */  beql      $v0, $zero, .L8025F8BC
/* 18E198 8025F8B8 24100002 */   addiu    $s0, $zero, 2
.L8025F8BC:
/* 18E19C 8025F8BC 00041603 */  sra       $v0, $a0, 0x18
/* 18E1A0 8025F8C0 12020004 */  beq       $s0, $v0, .L8025F8D4
/* 18E1A4 8025F8C4 00000000 */   nop      
/* 18E1A8 8025F8C8 0C05272D */  jal       play_sound
/* 18E1AC 8025F8CC 240400C7 */   addiu    $a0, $zero, 0xc7
/* 18E1B0 8025F8D0 A3D00048 */  sb        $s0, 0x48($fp)
.L8025F8D4:
/* 18E1B4 8025F8D4 3C10802A */  lui       $s0, 0x802a
/* 18E1B8 8025F8D8 2610FB84 */  addiu     $s0, $s0, -0x47c
/* 18E1BC 8025F8DC 8E020000 */  lw        $v0, ($s0)
/* 18E1C0 8025F8E0 24420001 */  addiu     $v0, $v0, 1
/* 18E1C4 8025F8E4 AE020000 */  sw        $v0, ($s0)
/* 18E1C8 8025F8E8 28420065 */  slti      $v0, $v0, 0x65
/* 18E1CC 8025F8EC 14400196 */  bnez      $v0, .L8025FF48
/* 18E1D0 8025F8F0 24020078 */   addiu    $v0, $zero, 0x78
/* 18E1D4 8025F8F4 24040003 */  addiu     $a0, $zero, 3
/* 18E1D8 8025F8F8 44800000 */  mtc1      $zero, $f0
/* 18E1DC 8025F8FC 3C0642C8 */  lui       $a2, 0x42c8
/* 18E1E0 8025F900 AFA20014 */  sw        $v0, 0x14($sp)
/* 18E1E4 8025F904 44050000 */  mfc1      $a1, $f0
/* 18E1E8 8025F908 3C013F80 */  lui       $at, 0x3f80
/* 18E1EC 8025F90C 44810000 */  mtc1      $at, $f0
/* 18E1F0 8025F910 00A0382D */  daddu     $a3, $a1, $zero
/* 18E1F4 8025F914 0C01C484 */  jal       func_80071210
/* 18E1F8 8025F918 E7A00010 */   swc1     $f0, 0x10($sp)
/* 18E1FC 8025F91C 08097FD2 */  j         .L8025FF48
/* 18E200 8025F920 AE000000 */   sw       $zero, ($s0)
/* 18E204 8025F924 3C04802A */  lui       $a0, 0x802a
/* 18E208 8025F928 8C84FAE8 */  lw        $a0, -0x518($a0)
/* 18E20C 8025F92C 0C05123D */  jal       free_icon
/* 18E210 8025F930 00000000 */   nop      
/* 18E214 8025F934 24040008 */  addiu     $a0, $zero, 8
/* 18E218 8025F938 0C051F9F */  jal       func_80147E7C
/* 18E21C 8025F93C 24050002 */   addiu    $a1, $zero, 2
/* 18E220 8025F940 83C30048 */  lb        $v1, 0x48($fp)
/* 18E224 8025F944 24020001 */  addiu     $v0, $zero, 1
/* 18E228 8025F948 10620024 */  beq       $v1, $v0, .L8025F9DC
/* 18E22C 8025F94C 28620002 */   slti     $v0, $v1, 2
/* 18E230 8025F950 10400005 */  beqz      $v0, .L8025F968
/* 18E234 8025F954 24020002 */   addiu    $v0, $zero, 2
/* 18E238 8025F958 10600007 */  beqz      $v1, .L8025F978
/* 18E23C 8025F95C 0000202D */   daddu    $a0, $zero, $zero
/* 18E240 8025F960 08097E99 */  j         .L8025FA64
/* 18E244 8025F964 0080282D */   daddu    $a1, $a0, $zero
.L8025F968:
/* 18E248 8025F968 10620032 */  beq       $v1, $v0, .L8025FA34
/* 18E24C 8025F96C 0000202D */   daddu    $a0, $zero, $zero
/* 18E250 8025F970 08097E99 */  j         .L8025FA64
/* 18E254 8025F974 0080282D */   daddu    $a1, $a0, $zero
.L8025F978:
/* 18E258 8025F978 92A20004 */  lbu       $v0, 4($s5)
/* 18E25C 8025F97C 92A30003 */  lbu       $v1, 3($s5)
/* 18E260 8025F980 24420005 */  addiu     $v0, $v0, 5
/* 18E264 8025F984 A2A20004 */  sb        $v0, 4($s5)
/* 18E268 8025F988 92A20002 */  lbu       $v0, 2($s5)
/* 18E26C 8025F98C 24630005 */  addiu     $v1, $v1, 5
/* 18E270 8025F990 A2A30003 */  sb        $v1, 3($s5)
/* 18E274 8025F994 82A30003 */  lb        $v1, 3($s5)
/* 18E278 8025F998 24420005 */  addiu     $v0, $v0, 5
/* 18E27C 8025F99C 2863004C */  slti      $v1, $v1, 0x4c
/* 18E280 8025F9A0 14600003 */  bnez      $v1, .L8025F9B0
/* 18E284 8025F9A4 A2A20002 */   sb       $v0, 2($s5)
/* 18E288 8025F9A8 2402004B */  addiu     $v0, $zero, 0x4b
/* 18E28C 8025F9AC A2A20003 */  sb        $v0, 3($s5)
.L8025F9B0:
/* 18E290 8025F9B0 82A30002 */  lb        $v1, 2($s5)
/* 18E294 8025F9B4 82A20003 */  lb        $v0, 3($s5)
/* 18E298 8025F9B8 0043102A */  slt       $v0, $v0, $v1
/* 18E29C 8025F9BC 92A30003 */  lbu       $v1, 3($s5)
/* 18E2A0 8025F9C0 54400001 */  bnel      $v0, $zero, .L8025F9C8
/* 18E2A4 8025F9C4 A2A30002 */   sb       $v1, 2($s5)
.L8025F9C8:
/* 18E2A8 8025F9C8 92A20003 */  lbu       $v0, 3($s5)
/* 18E2AC 8025F9CC A22201B9 */  sb        $v0, 0x1b9($s1)
/* 18E2B0 8025F9D0 92A20002 */  lbu       $v0, 2($s5)
/* 18E2B4 8025F9D4 08097E97 */  j         .L8025FA5C
/* 18E2B8 8025F9D8 A22201B8 */   sb       $v0, 0x1b8($s1)
.L8025F9DC:
/* 18E2BC 8025F9DC 92A20007 */  lbu       $v0, 7($s5)
/* 18E2C0 8025F9E0 92A30006 */  lbu       $v1, 6($s5)
/* 18E2C4 8025F9E4 24420005 */  addiu     $v0, $v0, 5
/* 18E2C8 8025F9E8 A2A20007 */  sb        $v0, 7($s5)
/* 18E2CC 8025F9EC 92A20005 */  lbu       $v0, 5($s5)
/* 18E2D0 8025F9F0 24630005 */  addiu     $v1, $v1, 5
/* 18E2D4 8025F9F4 A2A30006 */  sb        $v1, 6($s5)
/* 18E2D8 8025F9F8 82A30006 */  lb        $v1, 6($s5)
/* 18E2DC 8025F9FC 24420005 */  addiu     $v0, $v0, 5
/* 18E2E0 8025FA00 2863004C */  slti      $v1, $v1, 0x4c
/* 18E2E4 8025FA04 14600003 */  bnez      $v1, .L8025FA14
/* 18E2E8 8025FA08 A2A20005 */   sb       $v0, 5($s5)
/* 18E2EC 8025FA0C 2402004B */  addiu     $v0, $zero, 0x4b
/* 18E2F0 8025FA10 A2A20006 */  sb        $v0, 6($s5)
.L8025FA14:
/* 18E2F4 8025FA14 82A30005 */  lb        $v1, 5($s5)
/* 18E2F8 8025FA18 82A20006 */  lb        $v0, 6($s5)
/* 18E2FC 8025FA1C 0043102A */  slt       $v0, $v0, $v1
/* 18E300 8025FA20 92A30006 */  lbu       $v1, 6($s5)
/* 18E304 8025FA24 5440000D */  bnel      $v0, $zero, .L8025FA5C
/* 18E308 8025FA28 A2A30005 */   sb       $v1, 5($s5)
/* 18E30C 8025FA2C 08097E98 */  j         .L8025FA60
/* 18E310 8025FA30 0000202D */   daddu    $a0, $zero, $zero
.L8025FA34:
/* 18E314 8025FA34 92A20008 */  lbu       $v0, 8($s5)
/* 18E318 8025FA38 24420003 */  addiu     $v0, $v0, 3
/* 18E31C 8025FA3C A2A20008 */  sb        $v0, 8($s5)
/* 18E320 8025FA40 00021600 */  sll       $v0, $v0, 0x18
/* 18E324 8025FA44 00021603 */  sra       $v0, $v0, 0x18
/* 18E328 8025FA48 2842001F */  slti      $v0, $v0, 0x1f
/* 18E32C 8025FA4C 14400005 */  bnez      $v0, .L8025FA64
/* 18E330 8025FA50 0080282D */   daddu    $a1, $a0, $zero
/* 18E334 8025FA54 2402001E */  addiu     $v0, $zero, 0x1e
/* 18E338 8025FA58 A2A20008 */  sb        $v0, 8($s5)
.L8025FA5C:
/* 18E33C 8025FA5C 0000202D */  daddu     $a0, $zero, $zero
.L8025FA60:
/* 18E340 8025FA60 0080282D */  daddu     $a1, $a0, $zero
.L8025FA64:
/* 18E344 8025FA64 3C060003 */  lui       $a2, 3
/* 18E348 8025FA68 0C098F3F */  jal       set_animation
/* 18E34C 8025FA6C 34C60009 */   ori      $a2, $a2, 9
/* 18E350 8025FA70 1240000A */  beqz      $s2, .L8025FA9C
/* 18E354 8025FA74 2405000A */   addiu    $a1, $zero, 0xa
/* 18E358 8025FA78 8E4401C4 */  lw        $a0, 0x1c4($s2)
/* 18E35C 8025FA7C 0C0B0CF8 */  jal       start_script
/* 18E360 8025FA80 0000302D */   daddu    $a2, $zero, $zero
/* 18E364 8025FA84 0040282D */  daddu     $a1, $v0, $zero
/* 18E368 8025FA88 AE4501D4 */  sw        $a1, 0x1d4($s2)
/* 18E36C 8025FA8C 8CA20144 */  lw        $v0, 0x144($a1)
/* 18E370 8025FA90 AE4201E4 */  sw        $v0, 0x1e4($s2)
/* 18E374 8025FA94 24020100 */  addiu     $v0, $zero, 0x100
/* 18E378 8025FA98 ACA20148 */  sw        $v0, 0x148($a1)
.L8025FA9C:
/* 18E37C 8025FA9C 3C02800E */  lui       $v0, 0x800e
/* 18E380 8025FAA0 8C42C074 */  lw        $v0, -0x3f8c($v0)
/* 18E384 8025FAA4 3C030200 */  lui       $v1, 0x200
/* 18E388 8025FAA8 00431024 */  and       $v0, $v0, $v1
/* 18E38C 8025FAAC 14400007 */  bnez      $v0, .L8025FACC
/* 18E390 8025FAB0 24020008 */   addiu    $v0, $zero, 8
/* 18E394 8025FAB4 AFA20010 */  sw        $v0, 0x10($sp)
/* 18E398 8025FAB8 0000202D */  daddu     $a0, $zero, $zero
/* 18E39C 8025FABC 2405FFFF */  addiu     $a1, $zero, -1
/* 18E3A0 8025FAC0 0080302D */  daddu     $a2, $a0, $zero
/* 18E3A4 8025FAC4 0C052A46 */  jal       set_music_track
/* 18E3A8 8025FAC8 240707D0 */   addiu    $a3, $zero, 0x7d0
.L8025FACC:
/* 18E3AC 8025FACC 3C018028 */  lui       $at, 0x8028
/* 18E3B0 8025FAD0 AC204150 */  sw        $zero, 0x4150($at)
/* 18E3B4 8025FAD4 08097FD0 */  j         .L8025FF40
/* 18E3B8 8025FAD8 2402000A */   addiu    $v0, $zero, 0xa
/* 18E3BC 8025FADC 3C028007 */  lui       $v0, 0x8007
/* 18E3C0 8025FAE0 8C42419C */  lw        $v0, 0x419c($v0)
/* 18E3C4 8025FAE4 94420134 */  lhu       $v0, 0x134($v0)
/* 18E3C8 8025FAE8 30420001 */  andi      $v0, $v0, 1
/* 18E3CC 8025FAEC 10400020 */  beqz      $v0, .L8025FB70
/* 18E3D0 8025FAF0 24020001 */   addiu    $v0, $zero, 1
/* 18E3D4 8025FAF4 83C30048 */  lb        $v1, 0x48($fp)
/* 18E3D8 8025FAF8 1062000F */  beq       $v1, $v0, .L8025FB38
/* 18E3DC 8025FAFC 28620002 */   slti     $v0, $v1, 2
/* 18E3E0 8025FB00 10400005 */  beqz      $v0, .L8025FB18
/* 18E3E4 8025FB04 24020002 */   addiu    $v0, $zero, 2
/* 18E3E8 8025FB08 10600007 */  beqz      $v1, .L8025FB28
/* 18E3EC 8025FB0C 00000000 */   nop      
/* 18E3F0 8025FB10 08097EF9 */  j         .L8025FBE4
/* 18E3F4 8025FB14 00000000 */   nop      
.L8025FB18:
/* 18E3F8 8025FB18 1062000F */  beq       $v1, $v0, .L8025FB58
/* 18E3FC 8025FB1C 00000000 */   nop      
/* 18E400 8025FB20 08097EF9 */  j         .L8025FBE4
/* 18E404 8025FB24 00000000 */   nop      
.L8025FB28:
/* 18E408 8025FB28 3C04802A */  lui       $a0, 0x802a
/* 18E40C 8025FB2C 8C84FA80 */  lw        $a0, -0x580($a0)
/* 18E410 8025FB30 08097ED8 */  j         .L8025FB60
/* 18E414 8025FB34 00000000 */   nop      
.L8025FB38:
/* 18E418 8025FB38 3C10802A */  lui       $s0, 0x802a
/* 18E41C 8025FB3C 2610FA80 */  addiu     $s0, $s0, -0x580
/* 18E420 8025FB40 8E040004 */  lw        $a0, 4($s0)
/* 18E424 8025FB44 0C051280 */  jal       set_icon_flags
/* 18E428 8025FB48 24050002 */   addiu    $a1, $zero, 2
/* 18E42C 8025FB4C 8E04000C */  lw        $a0, 0xc($s0)
/* 18E430 8025FB50 08097ED8 */  j         .L8025FB60
/* 18E434 8025FB54 00000000 */   nop      
.L8025FB58:
/* 18E438 8025FB58 3C04802A */  lui       $a0, 0x802a
/* 18E43C 8025FB5C 8C84FA88 */  lw        $a0, -0x578($a0)
.L8025FB60:
/* 18E440 8025FB60 0C051280 */  jal       set_icon_flags
/* 18E444 8025FB64 24050002 */   addiu    $a1, $zero, 2
/* 18E448 8025FB68 08097EF9 */  j         .L8025FBE4
/* 18E44C 8025FB6C 00000000 */   nop      
.L8025FB70:
/* 18E450 8025FB70 83C30048 */  lb        $v1, 0x48($fp)
/* 18E454 8025FB74 1062000F */  beq       $v1, $v0, .L8025FBB4
/* 18E458 8025FB78 28620002 */   slti     $v0, $v1, 2
/* 18E45C 8025FB7C 10400005 */  beqz      $v0, .L8025FB94
/* 18E460 8025FB80 24020002 */   addiu    $v0, $zero, 2
/* 18E464 8025FB84 10600007 */  beqz      $v1, .L8025FBA4
/* 18E468 8025FB88 00000000 */   nop      
/* 18E46C 8025FB8C 08097EF9 */  j         .L8025FBE4
/* 18E470 8025FB90 00000000 */   nop      
.L8025FB94:
/* 18E474 8025FB94 1062000F */  beq       $v1, $v0, .L8025FBD4
/* 18E478 8025FB98 00000000 */   nop      
/* 18E47C 8025FB9C 08097EF9 */  j         .L8025FBE4
/* 18E480 8025FBA0 00000000 */   nop      
.L8025FBA4:
/* 18E484 8025FBA4 3C04802A */  lui       $a0, 0x802a
/* 18E488 8025FBA8 8C84FA80 */  lw        $a0, -0x580($a0)
/* 18E48C 8025FBAC 08097EF7 */  j         .L8025FBDC
/* 18E490 8025FBB0 00000000 */   nop      
.L8025FBB4:
/* 18E494 8025FBB4 3C10802A */  lui       $s0, 0x802a
/* 18E498 8025FBB8 2610FA80 */  addiu     $s0, $s0, -0x580
/* 18E49C 8025FBBC 8E040004 */  lw        $a0, 4($s0)
/* 18E4A0 8025FBC0 0C05128B */  jal       clear_icon_flags
/* 18E4A4 8025FBC4 24050002 */   addiu    $a1, $zero, 2
/* 18E4A8 8025FBC8 8E04000C */  lw        $a0, 0xc($s0)
/* 18E4AC 8025FBCC 08097EF7 */  j         .L8025FBDC
/* 18E4B0 8025FBD0 00000000 */   nop      
.L8025FBD4:
/* 18E4B4 8025FBD4 3C04802A */  lui       $a0, 0x802a
/* 18E4B8 8025FBD8 8C84FA88 */  lw        $a0, -0x578($a0)
.L8025FBDC:
/* 18E4BC 8025FBDC 0C05128B */  jal       clear_icon_flags
/* 18E4C0 8025FBE0 24050002 */   addiu    $a1, $zero, 2
.L8025FBE4:
/* 18E4C4 8025FBE4 3C038028 */  lui       $v1, 0x8028
/* 18E4C8 8025FBE8 24634150 */  addiu     $v1, $v1, 0x4150
/* 18E4CC 8025FBEC 8C620000 */  lw        $v0, ($v1)
/* 18E4D0 8025FBF0 240400FF */  addiu     $a0, $zero, 0xff
/* 18E4D4 8025FBF4 144400BB */  bne       $v0, $a0, .L8025FEE4
/* 18E4D8 8025FBF8 2442000A */   addiu    $v0, $v0, 0xa
/* 18E4DC 8025FBFC 08097FD0 */  j         .L8025FF40
/* 18E4E0 8025FC00 2402000B */   addiu    $v0, $zero, 0xb
/* 18E4E4 8025FC04 3C10802A */  lui       $s0, 0x802a
/* 18E4E8 8025FC08 2610FA80 */  addiu     $s0, $s0, -0x580
/* 18E4EC 8025FC0C 8E040000 */  lw        $a0, ($s0)
/* 18E4F0 8025FC10 0C05123D */  jal       free_icon
/* 18E4F4 8025FC14 0000982D */   daddu    $s3, $zero, $zero
/* 18E4F8 8025FC18 8E040004 */  lw        $a0, 4($s0)
/* 18E4FC 8025FC1C 0C05123D */  jal       free_icon
/* 18E500 8025FC20 0260902D */   daddu    $s2, $s3, $zero
/* 18E504 8025FC24 8E04000C */  lw        $a0, 0xc($s0)
/* 18E508 8025FC28 3C14802A */  lui       $s4, 0x802a
/* 18E50C 8025FC2C 2694FA90 */  addiu     $s4, $s4, -0x570
/* 18E510 8025FC30 0C05123D */  jal       free_icon
/* 18E514 8025FC34 00000000 */   nop      
/* 18E518 8025FC38 0C05123D */  jal       free_icon
/* 18E51C 8025FC3C 8E040008 */   lw       $a0, 8($s0)
.L8025FC40:
/* 18E520 8025FC40 0000882D */  daddu     $s1, $zero, $zero
/* 18E524 8025FC44 0240802D */  daddu     $s0, $s2, $zero
/* 18E528 8025FC48 02141021 */  addu      $v0, $s0, $s4
.L8025FC4C:
/* 18E52C 8025FC4C 8C440000 */  lw        $a0, ($v0)
/* 18E530 8025FC50 26100004 */  addiu     $s0, $s0, 4
/* 18E534 8025FC54 0C05123D */  jal       free_icon
/* 18E538 8025FC58 26310001 */   addiu    $s1, $s1, 1
/* 18E53C 8025FC5C 2A220007 */  slti      $v0, $s1, 7
/* 18E540 8025FC60 1440FFFA */  bnez      $v0, .L8025FC4C
/* 18E544 8025FC64 02141021 */   addu     $v0, $s0, $s4
/* 18E548 8025FC68 26730001 */  addiu     $s3, $s3, 1
/* 18E54C 8025FC6C 2A620003 */  slti      $v0, $s3, 3
/* 18E550 8025FC70 1440FFF3 */  bnez      $v0, .L8025FC40
/* 18E554 8025FC74 2652001C */   addiu    $s2, $s2, 0x1c
/* 18E558 8025FC78 3C04802A */  lui       $a0, 0x802a
/* 18E55C 8025FC7C 8C84FB48 */  lw        $a0, -0x4b8($a0)
/* 18E560 8025FC80 0C05123D */  jal       free_icon
/* 18E564 8025FC84 00000000 */   nop      
/* 18E568 8025FC88 0000202D */  daddu     $a0, $zero, $zero
/* 18E56C 8025FC8C 0080282D */  daddu     $a1, $a0, $zero
/* 18E570 8025FC90 0080302D */  daddu     $a2, $a0, $zero
/* 18E574 8025FC94 0C046F97 */  jal       set_background_color_blend
/* 18E578 8025FC98 0080382D */   daddu    $a3, $a0, $zero
/* 18E57C 8025FC9C 08097FCD */  j         .L8025FF34
/* 18E580 8025FCA0 00000000 */   nop      
/* 18E584 8025FCA4 3C04001D */  lui       $a0, 0x1d
/* 18E588 8025FCA8 348400AB */  ori       $a0, $a0, 0xab
/* 18E58C 8025FCAC 0C04991D */  jal       get_string_width
/* 18E590 8025FCB0 0000282D */   daddu    $a1, $zero, $zero
/* 18E594 8025FCB4 24040009 */  addiu     $a0, $zero, 9
/* 18E598 8025FCB8 2447001F */  addiu     $a3, $v0, 0x1f
/* 18E59C 8025FCBC 000717C2 */  srl       $v0, $a3, 0x1f
/* 18E5A0 8025FCC0 00E21021 */  addu      $v0, $a3, $v0
/* 18E5A4 8025FCC4 00021043 */  sra       $v0, $v0, 1
/* 18E5A8 8025FCC8 240500A0 */  addiu     $a1, $zero, 0xa0
/* 18E5AC 8025FCCC 00A22823 */  subu      $a1, $a1, $v0
/* 18E5B0 8025FCD0 24060050 */  addiu     $a2, $zero, 0x50
/* 18E5B4 8025FCD4 00C0102D */  daddu     $v0, $a2, $zero
/* 18E5B8 8025FCD8 AFA2002C */  sw        $v0, 0x2c($sp)
/* 18E5BC 8025FCDC 2402001C */  addiu     $v0, $zero, 0x1c
/* 18E5C0 8025FCE0 AFA50028 */  sw        $a1, 0x28($sp)
/* 18E5C4 8025FCE4 AFA20010 */  sw        $v0, 0x10($sp)
/* 18E5C8 8025FCE8 2402000A */  addiu     $v0, $zero, 0xa
/* 18E5CC 8025FCEC AFA20014 */  sw        $v0, 0x14($sp)
/* 18E5D0 8025FCF0 3C028026 */  lui       $v0, 0x8026
/* 18E5D4 8025FCF4 24420A20 */  addiu     $v0, $v0, 0xa20
/* 18E5D8 8025FCF8 AFA20018 */  sw        $v0, 0x18($sp)
/* 18E5DC 8025FCFC 2402FFFF */  addiu     $v0, $zero, -1
/* 18E5E0 8025FD00 AFA0001C */  sw        $zero, 0x1c($sp)
/* 18E5E4 8025FD04 0C051F32 */  jal       set_ui_panel_properties
/* 18E5E8 8025FD08 AFA20020 */   sw       $v0, 0x20($sp)
/* 18E5EC 8025FD0C 24040009 */  addiu     $a0, $zero, 9
/* 18E5F0 8025FD10 0C051F9F */  jal       func_80147E7C
/* 18E5F4 8025FD14 24050001 */   addiu    $a1, $zero, 1
/* 18E5F8 8025FD18 2402003C */  addiu     $v0, $zero, 0x3c
/* 18E5FC 8025FD1C 3C01802A */  lui       $at, 0x802a
/* 18E600 8025FD20 AC22FB4C */  sw        $v0, -0x4b4($at)
/* 18E604 8025FD24 08097FD0 */  j         .L8025FF40
/* 18E608 8025FD28 24020010 */   addiu    $v0, $zero, 0x10
/* 18E60C 8025FD2C 3C028007 */  lui       $v0, 0x8007
/* 18E610 8025FD30 8C42419C */  lw        $v0, 0x419c($v0)
/* 18E614 8025FD34 8C420010 */  lw        $v0, 0x10($v0)
/* 18E618 8025FD38 3042C000 */  andi      $v0, $v0, 0xc000
/* 18E61C 8025FD3C 10400003 */  beqz      $v0, .L8025FD4C
/* 18E620 8025FD40 00000000 */   nop      
/* 18E624 8025FD44 3C01802A */  lui       $at, 0x802a
/* 18E628 8025FD48 AC20FB4C */  sw        $zero, -0x4b4($at)
.L8025FD4C:
/* 18E62C 8025FD4C 3C03802A */  lui       $v1, 0x802a
/* 18E630 8025FD50 2463FB4C */  addiu     $v1, $v1, -0x4b4
/* 18E634 8025FD54 8C620000 */  lw        $v0, ($v1)
/* 18E638 8025FD58 10400003 */  beqz      $v0, .L8025FD68
/* 18E63C 8025FD5C 2442FFFF */   addiu    $v0, $v0, -1
.L8025FD60:
/* 18E640 8025FD60 08097FD2 */  j         .L8025FF48
/* 18E644 8025FD64 AC620000 */   sw       $v0, ($v1)
.L8025FD68:
/* 18E648 8025FD68 24040009 */  addiu     $a0, $zero, 9
/* 18E64C 8025FD6C 0C051F9F */  jal       func_80147E7C
/* 18E650 8025FD70 24050002 */   addiu    $a1, $zero, 2
/* 18E654 8025FD74 08097FD0 */  j         .L8025FF40
/* 18E658 8025FD78 24020008 */   addiu    $v0, $zero, 8
/* 18E65C 8025FD7C 8FC20214 */  lw        $v0, 0x214($fp)
/* 18E660 8025FD80 3042C000 */  andi      $v0, $v0, 0xc000
/* 18E664 8025FD84 10400003 */  beqz      $v0, .L8025FD94
/* 18E668 8025FD88 24020063 */   addiu    $v0, $zero, 0x63
/* 18E66C 8025FD8C 3C01802A */  lui       $at, 0x802a
/* 18E670 8025FD90 AC22FB84 */  sw        $v0, -0x47c($at)
.L8025FD94:
/* 18E674 8025FD94 3C02802A */  lui       $v0, 0x802a
/* 18E678 8025FD98 8C42FB84 */  lw        $v0, -0x47c($v0)
/* 18E67C 8025FD9C 28420063 */  slti      $v0, $v0, 0x63
/* 18E680 8025FDA0 14400069 */  bnez      $v0, .L8025FF48
/* 18E684 8025FDA4 3C030200 */   lui      $v1, 0x200
/* 18E688 8025FDA8 3C02800E */  lui       $v0, 0x800e
/* 18E68C 8025FDAC 8C42C074 */  lw        $v0, -0x3f8c($v0)
/* 18E690 8025FDB0 00431024 */  and       $v0, $v0, $v1
/* 18E694 8025FDB4 14400009 */  bnez      $v0, .L8025FDDC
/* 18E698 8025FDB8 24040001 */   addiu    $a0, $zero, 1
/* 18E69C 8025FDBC 24020008 */  addiu     $v0, $zero, 8
/* 18E6A0 8025FDC0 AFA20010 */  sw        $v0, 0x10($sp)
/* 18E6A4 8025FDC4 0000202D */  daddu     $a0, $zero, $zero
/* 18E6A8 8025FDC8 2405FFFF */  addiu     $a1, $zero, -1
/* 18E6AC 8025FDCC 0080302D */  daddu     $a2, $a0, $zero
/* 18E6B0 8025FDD0 0C052A46 */  jal       set_music_track
/* 18E6B4 8025FDD4 240705DC */   addiu    $a3, $zero, 0x5dc
/* 18E6B8 8025FDD8 24040001 */  addiu     $a0, $zero, 1
.L8025FDDC:
/* 18E6BC 8025FDDC 2405010E */  addiu     $a1, $zero, 0x10e
/* 18E6C0 8025FDE0 24060064 */  addiu     $a2, $zero, 0x64
/* 18E6C4 8025FDE4 24070008 */  addiu     $a3, $zero, 8
/* 18E6C8 8025FDE8 24022400 */  addiu     $v0, $zero, 0x2400
/* 18E6CC 8025FDEC AFA20014 */  sw        $v0, 0x14($sp)
/* 18E6D0 8025FDF0 00C0102D */  daddu     $v0, $a2, $zero
/* 18E6D4 8025FDF4 3C018028 */  lui       $at, 0x8028
/* 18E6D8 8025FDF8 AC204150 */  sw        $zero, 0x4150($at)
/* 18E6DC 8025FDFC AFA00010 */  sw        $zero, 0x10($sp)
/* 18E6E0 8025FE00 AFA00018 */  sw        $zero, 0x18($sp)
/* 18E6E4 8025FE04 0C093921 */  jal       func_8024E484
/* 18E6E8 8025FE08 AFA2001C */   sw       $v0, 0x1c($sp)
/* 18E6EC 8025FE0C 0000202D */  daddu     $a0, $zero, $zero
/* 18E6F0 8025FE10 0080282D */  daddu     $a1, $a0, $zero
/* 18E6F4 8025FE14 3C060003 */  lui       $a2, 3
/* 18E6F8 8025FE18 0C098F3F */  jal       set_animation
/* 18E6FC 8025FE1C 34C60009 */   ori      $a2, $a2, 9
/* 18E700 8025FE20 12400008 */  beqz      $s2, .L8025FE44
/* 18E704 8025FE24 24040100 */   addiu    $a0, $zero, 0x100
/* 18E708 8025FE28 82A20012 */  lb        $v0, 0x12($s5)
/* 18E70C 8025FE2C 00021080 */  sll       $v0, $v0, 2
/* 18E710 8025FE30 3C068028 */  lui       $a2, 0x8028
/* 18E714 8025FE34 00C23021 */  addu      $a2, $a2, $v0
/* 18E718 8025FE38 8CC64154 */  lw        $a2, 0x4154($a2)
/* 18E71C 8025FE3C 0C098F3F */  jal       set_animation
/* 18E720 8025FE40 0000282D */   daddu    $a1, $zero, $zero
.L8025FE44:
/* 18E724 8025FE44 24020006 */  addiu     $v0, $zero, 6
/* 18E728 8025FE48 3C01802A */  lui       $at, 0x802a
/* 18E72C 8025FE4C AC22FB4C */  sw        $v0, -0x4b4($at)
/* 18E730 8025FE50 08097FD0 */  j         .L8025FF40
/* 18E734 8025FE54 24020015 */   addiu    $v0, $zero, 0x15
/* 18E738 8025FE58 3C03802A */  lui       $v1, 0x802a
/* 18E73C 8025FE5C 2463FB4C */  addiu     $v1, $v1, -0x4b4
/* 18E740 8025FE60 8C620000 */  lw        $v0, ($v1)
/* 18E744 8025FE64 1040000A */  beqz      $v0, .L8025FE90
/* 18E748 8025FE68 2442FFFF */   addiu    $v0, $v0, -1
/* 18E74C 8025FE6C 14400015 */  bnez      $v0, .L8025FEC4
/* 18E750 8025FE70 AC620000 */   sw       $v0, ($v1)
/* 18E754 8025FE74 0000202D */  daddu     $a0, $zero, $zero
/* 18E758 8025FE78 0080282D */  daddu     $a1, $a0, $zero
/* 18E75C 8025FE7C 3C060001 */  lui       $a2, 1
/* 18E760 8025FE80 0C098F3F */  jal       set_animation
/* 18E764 8025FE84 34C60004 */   ori      $a2, $a2, 4
/* 18E768 8025FE88 08097FB1 */  j         .L8025FEC4
/* 18E76C 8025FE8C 00000000 */   nop      
.L8025FE90:
/* 18E770 8025FE90 12400002 */  beqz      $s2, .L8025FE9C
/* 18E774 8025FE94 AE20018C */   sw       $zero, 0x18c($s1)
/* 18E778 8025FE98 AE40018C */  sw        $zero, 0x18c($s2)
.L8025FE9C:
/* 18E77C 8025FE9C C6200144 */  lwc1      $f0, 0x144($s1)
/* 18E780 8025FEA0 3C014080 */  lui       $at, 0x4080
/* 18E784 8025FEA4 44811000 */  mtc1      $at, $f2
/* 18E788 8025FEA8 00000000 */  nop       
/* 18E78C 8025FEAC 46020000 */  add.s     $f0, $f0, $f2
/* 18E790 8025FEB0 12400004 */  beqz      $s2, .L8025FEC4
/* 18E794 8025FEB4 E6200144 */   swc1     $f0, 0x144($s1)
/* 18E798 8025FEB8 C6400144 */  lwc1      $f0, 0x144($s2)
/* 18E79C 8025FEBC 46020000 */  add.s     $f0, $f0, $f2
/* 18E7A0 8025FEC0 E6400144 */  swc1      $f0, 0x144($s2)
.L8025FEC4:
/* 18E7A4 8025FEC4 3C038028 */  lui       $v1, 0x8028
/* 18E7A8 8025FEC8 24634150 */  addiu     $v1, $v1, 0x4150
/* 18E7AC 8025FECC 8C620000 */  lw        $v0, ($v1)
/* 18E7B0 8025FED0 240400FF */  addiu     $a0, $zero, 0xff
/* 18E7B4 8025FED4 14440003 */  bne       $v0, $a0, .L8025FEE4
/* 18E7B8 8025FED8 24420014 */   addiu    $v0, $v0, 0x14
/* 18E7BC 8025FEDC 08097FD0 */  j         .L8025FF40
/* 18E7C0 8025FEE0 24020016 */   addiu    $v0, $zero, 0x16
.L8025FEE4:
/* 18E7C4 8025FEE4 AC620000 */  sw        $v0, ($v1)
/* 18E7C8 8025FEE8 28420100 */  slti      $v0, $v0, 0x100
/* 18E7CC 8025FEEC 50400016 */  beql      $v0, $zero, .L8025FF48
/* 18E7D0 8025FEF0 AC640000 */   sw       $a0, ($v1)
/* 18E7D4 8025FEF4 08097FD2 */  j         .L8025FF48
/* 18E7D8 8025FEF8 00000000 */   nop      
/* 18E7DC 8025FEFC 0C0B1059 */  jal       does_script_exist
/* 18E7E0 8025FF00 8E2401E4 */   lw       $a0, 0x1e4($s1)
/* 18E7E4 8025FF04 10400003 */  beqz      $v0, .L8025FF14
/* 18E7E8 8025FF08 00000000 */   nop      
/* 18E7EC 8025FF0C 0C0B102B */  jal       kill_script_by_ID
/* 18E7F0 8025FF10 8E2401E4 */   lw       $a0, 0x1e4($s1)
.L8025FF14:
/* 18E7F4 8025FF14 12400007 */  beqz      $s2, .L8025FF34
/* 18E7F8 8025FF18 00000000 */   nop      
/* 18E7FC 8025FF1C 0C0B1059 */  jal       does_script_exist
/* 18E800 8025FF20 8E4401E4 */   lw       $a0, 0x1e4($s2)
/* 18E804 8025FF24 10400003 */  beqz      $v0, .L8025FF34
/* 18E808 8025FF28 00000000 */   nop      
/* 18E80C 8025FF2C 0C0B102B */  jal       kill_script_by_ID
/* 18E810 8025FF30 8E4401E4 */   lw       $a0, 0x1e4($s2)
.L8025FF34:
/* 18E814 8025FF34 0C090464 */  jal       func_80241190
/* 18E818 8025FF38 24040020 */   addiu    $a0, $zero, 0x20
/* 18E81C 8025FF3C 24020002 */  addiu     $v0, $zero, 2
.L8025FF40:
/* 18E820 8025FF40 3C01800E */  lui       $at, 0x800e
/* 18E824 8025FF44 AC22C4DC */  sw        $v0, -0x3b24($at)
.L8025FF48:
/* 18E828 8025FF48 3C03802A */  lui       $v1, 0x802a
/* 18E82C 8025FF4C 2463FB84 */  addiu     $v1, $v1, -0x47c
/* 18E830 8025FF50 8C620000 */  lw        $v0, ($v1)
/* 18E834 8025FF54 24420001 */  addiu     $v0, $v0, 1
/* 18E838 8025FF58 AC620000 */  sw        $v0, ($v1)
/* 18E83C 8025FF5C 8FBF0064 */  lw        $ra, 0x64($sp)
/* 18E840 8025FF60 8FBE0060 */  lw        $fp, 0x60($sp)
/* 18E844 8025FF64 8FB7005C */  lw        $s7, 0x5c($sp)
/* 18E848 8025FF68 8FB60058 */  lw        $s6, 0x58($sp)
/* 18E84C 8025FF6C 8FB50054 */  lw        $s5, 0x54($sp)
/* 18E850 8025FF70 8FB40050 */  lw        $s4, 0x50($sp)
/* 18E854 8025FF74 8FB3004C */  lw        $s3, 0x4c($sp)
/* 18E858 8025FF78 8FB20048 */  lw        $s2, 0x48($sp)
/* 18E85C 8025FF7C 8FB10044 */  lw        $s1, 0x44($sp)
/* 18E860 8025FF80 8FB00040 */  lw        $s0, 0x40($sp)
/* 18E864 8025FF84 03E00008 */  jr        $ra
/* 18E868 8025FF88 27BD0068 */   addiu    $sp, $sp, 0x68
