.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00183D8
/* 32F958 E00183D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 32F95C E00183DC 0080602D */  daddu     $t4, $a0, $zero
/* 32F960 E00183E0 3C05DB06 */  lui       $a1, 0xdb06
/* 32F964 E00183E4 34A50024 */  ori       $a1, $a1, 0x24
/* 32F968 E00183E8 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 32F96C E00183EC 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 32F970 E00183F0 3C02E700 */  lui       $v0, 0xe700
/* 32F974 E00183F4 AFB7001C */  sw        $s7, 0x1c($sp)
/* 32F978 E00183F8 AFB60018 */  sw        $s6, 0x18($sp)
/* 32F97C E00183FC AFB50014 */  sw        $s5, 0x14($sp)
/* 32F980 E0018400 AFB40010 */  sw        $s4, 0x10($sp)
/* 32F984 E0018404 AFB3000C */  sw        $s3, 0xc($sp)
/* 32F988 E0018408 AFB20008 */  sw        $s2, 8($sp)
/* 32F98C E001840C AFB10004 */  sw        $s1, 4($sp)
/* 32F990 E0018410 AFB00000 */  sw        $s0, ($sp)
/* 32F994 E0018414 8CC40000 */  lw        $a0, ($a2)
/* 32F998 E0018418 8D88000C */  lw        $t0, 0xc($t4)
/* 32F99C E001841C 0080182D */  daddu     $v1, $a0, $zero
/* 32F9A0 E0018420 24840008 */  addiu     $a0, $a0, 8
/* 32F9A4 E0018424 AC620000 */  sw        $v0, ($v1)
/* 32F9A8 E0018428 AC600004 */  sw        $zero, 4($v1)
/* 32F9AC E001842C AC850000 */  sw        $a1, ($a0)
/* 32F9B0 E0018430 8D820010 */  lw        $v0, 0x10($t4)
/* 32F9B4 E0018434 0000482D */  daddu     $t1, $zero, $zero
/* 32F9B8 E0018438 ACC40000 */  sw        $a0, ($a2)
/* 32F9BC E001843C 8C42001C */  lw        $v0, 0x1c($v0)
/* 32F9C0 E0018440 3C038000 */  lui       $v1, 0x8000
/* 32F9C4 E0018444 00431021 */  addu      $v0, $v0, $v1
/* 32F9C8 E0018448 AC820004 */  sw        $v0, 4($a0)
/* 32F9CC E001844C 8D820008 */  lw        $v0, 8($t4)
/* 32F9D0 E0018450 24840008 */  addiu     $a0, $a0, 8
/* 32F9D4 E0018454 1840004A */  blez      $v0, .LE0018580
/* 32F9D8 E0018458 ACC40000 */   sw       $a0, ($a2)
/* 32F9DC E001845C 3C0F800A */  lui       $t7, %hi(gDisplayContext)
/* 32F9E0 E0018460 25EFA674 */  addiu     $t7, $t7, %lo(gDisplayContext)
/* 32F9E4 E0018464 3C0D8007 */  lui       $t5, %hi(gMatrixListPos)
/* 32F9E8 E0018468 25AD41F0 */  addiu     $t5, $t5, %lo(gMatrixListPos)
/* 32F9EC E001846C 3C0B0001 */  lui       $t3, 1
/* 32F9F0 E0018470 356B1630 */  ori       $t3, $t3, 0x1630
/* 32F9F4 E0018474 00C0502D */  daddu     $t2, $a2, $zero
/* 32F9F8 E0018478 3C13FA00 */  lui       $s3, 0xfa00
/* 32F9FC E001847C 3C197060 */  lui       $t9, 0x7060
/* 32FA00 E0018480 37391800 */  ori       $t9, $t9, 0x1800
/* 32FA04 E0018484 3C12DA38 */  lui       $s2, 0xda38
/* 32FA08 E0018488 3C11DE00 */  lui       $s1, 0xde00
/* 32FA0C E001848C 3C18D838 */  lui       $t8, 0xd838
/* 32FA10 E0018490 37180002 */  ori       $t8, $t8, 2
/* 32FA14 E0018494 24100040 */  addiu     $s0, $zero, 0x40
/* 32FA18 E0018498 25070070 */  addiu     $a3, $t0, 0x70
.LE001849C:
/* 32FA1C E001849C 8D020000 */  lw        $v0, ($t0)
/* 32FA20 E00184A0 50400032 */  beql      $v0, $zero, .LE001856C
/* 32FA24 E00184A4 25290001 */   addiu    $t1, $t1, 1
/* 32FA28 E00184A8 3C0E0900 */  lui       $t6, 0x900
/* 32FA2C E00184AC 25CE0240 */  addiu     $t6, $t6, 0x240
/* 32FA30 E00184B0 25040030 */  addiu     $a0, $t0, 0x30
/* 32FA34 E00184B4 00E0282D */  daddu     $a1, $a3, $zero
/* 32FA38 E00184B8 95A20000 */  lhu       $v0, ($t5)
/* 32FA3C E00184BC 8DE30000 */  lw        $v1, ($t7)
/* 32FA40 E00184C0 00021180 */  sll       $v0, $v0, 6
/* 32FA44 E00184C4 00621821 */  addu      $v1, $v1, $v0
/* 32FA48 E00184C8 006B1821 */  addu      $v1, $v1, $t3
.LE00184CC:
/* 32FA4C E00184CC 8C940000 */  lw        $s4, ($a0)
/* 32FA50 E00184D0 8C950004 */  lw        $s5, 4($a0)
/* 32FA54 E00184D4 8C960008 */  lw        $s6, 8($a0)
/* 32FA58 E00184D8 8C97000C */  lw        $s7, 0xc($a0)
/* 32FA5C E00184DC AC740000 */  sw        $s4, ($v1)
/* 32FA60 E00184E0 AC750004 */  sw        $s5, 4($v1)
/* 32FA64 E00184E4 AC760008 */  sw        $s6, 8($v1)
/* 32FA68 E00184E8 AC77000C */  sw        $s7, 0xc($v1)
/* 32FA6C E00184EC 24840010 */  addiu     $a0, $a0, 0x10
/* 32FA70 E00184F0 1485FFF6 */  bne       $a0, $a1, .LE00184CC
/* 32FA74 E00184F4 24630010 */   addiu    $v1, $v1, 0x10
/* 32FA78 E00184F8 8D440000 */  lw        $a0, ($t2)
/* 32FA7C E00184FC 0080302D */  daddu     $a2, $a0, $zero
/* 32FA80 E0018500 24840008 */  addiu     $a0, $a0, 8
/* 32FA84 E0018504 AD440000 */  sw        $a0, ($t2)
/* 32FA88 E0018508 ACD30000 */  sw        $s3, ($a2)
/* 32FA8C E001850C 90E5FF98 */  lbu       $a1, -0x68($a3)
/* 32FA90 E0018510 95A30000 */  lhu       $v1, ($t5)
/* 32FA94 E0018514 24820008 */  addiu     $v0, $a0, 8
/* 32FA98 E0018518 AD420000 */  sw        $v0, ($t2)
/* 32FA9C E001851C 24620001 */  addiu     $v0, $v1, 1
/* 32FAA0 E0018520 A5A20000 */  sh        $v0, ($t5)
/* 32FAA4 E0018524 24820010 */  addiu     $v0, $a0, 0x10
/* 32FAA8 E0018528 AD420000 */  sw        $v0, ($t2)
/* 32FAAC E001852C 24820018 */  addiu     $v0, $a0, 0x18
/* 32FAB0 E0018530 00B92825 */  or        $a1, $a1, $t9
/* 32FAB4 E0018534 3063FFFF */  andi      $v1, $v1, 0xffff
/* 32FAB8 E0018538 00031980 */  sll       $v1, $v1, 6
/* 32FABC E001853C AD420000 */  sw        $v0, ($t2)
/* 32FAC0 E0018540 ACC50004 */  sw        $a1, 4($a2)
/* 32FAC4 E0018544 AC920000 */  sw        $s2, ($a0)
/* 32FAC8 E0018548 8DE20000 */  lw        $v0, ($t7)
/* 32FACC E001854C 006B1821 */  addu      $v1, $v1, $t3
/* 32FAD0 E0018550 AC910008 */  sw        $s1, 8($a0)
/* 32FAD4 E0018554 AC8E000C */  sw        $t6, 0xc($a0)
/* 32FAD8 E0018558 AC980010 */  sw        $t8, 0x10($a0)
/* 32FADC E001855C AC900014 */  sw        $s0, 0x14($a0)
/* 32FAE0 E0018560 00431021 */  addu      $v0, $v0, $v1
/* 32FAE4 E0018564 AC820004 */  sw        $v0, 4($a0)
/* 32FAE8 E0018568 25290001 */  addiu     $t1, $t1, 1
.LE001856C:
/* 32FAEC E001856C 24E70098 */  addiu     $a3, $a3, 0x98
/* 32FAF0 E0018570 8D820008 */  lw        $v0, 8($t4)
/* 32FAF4 E0018574 0122102A */  slt       $v0, $t1, $v0
/* 32FAF8 E0018578 1440FFC8 */  bnez      $v0, .LE001849C
/* 32FAFC E001857C 25080098 */   addiu    $t0, $t0, 0x98
.LE0018580:
/* 32FB00 E0018580 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 32FB04 E0018584 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 32FB08 E0018588 8C620000 */  lw        $v0, ($v1)
/* 32FB0C E001858C 0040202D */  daddu     $a0, $v0, $zero
/* 32FB10 E0018590 24420008 */  addiu     $v0, $v0, 8
/* 32FB14 E0018594 AC620000 */  sw        $v0, ($v1)
/* 32FB18 E0018598 3C02E700 */  lui       $v0, 0xe700
/* 32FB1C E001859C AC820000 */  sw        $v0, ($a0)
/* 32FB20 E00185A0 AC800004 */  sw        $zero, 4($a0)
/* 32FB24 E00185A4 8FB7001C */  lw        $s7, 0x1c($sp)
/* 32FB28 E00185A8 8FB60018 */  lw        $s6, 0x18($sp)
/* 32FB2C E00185AC 8FB50014 */  lw        $s5, 0x14($sp)
/* 32FB30 E00185B0 8FB40010 */  lw        $s4, 0x10($sp)
/* 32FB34 E00185B4 8FB3000C */  lw        $s3, 0xc($sp)
/* 32FB38 E00185B8 8FB20008 */  lw        $s2, 8($sp)
/* 32FB3C E00185BC 8FB10004 */  lw        $s1, 4($sp)
/* 32FB40 E00185C0 8FB00000 */  lw        $s0, ($sp)
/* 32FB44 E00185C4 03E00008 */  jr        $ra
/* 32FB48 E00185C8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 32FB4C E00185CC 00000000 */  nop       
