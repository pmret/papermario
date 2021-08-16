.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0012564
/* 32E274 E0012564 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 32E278 E0012568 0080602D */  daddu     $t4, $a0, $zero
/* 32E27C E001256C 3C05DB06 */  lui       $a1, 0xdb06
/* 32E280 E0012570 34A50024 */  ori       $a1, $a1, 0x24
/* 32E284 E0012574 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 32E288 E0012578 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 32E28C E001257C 3C02E700 */  lui       $v0, 0xe700
/* 32E290 E0012580 AFB7001C */  sw        $s7, 0x1c($sp)
/* 32E294 E0012584 AFB60018 */  sw        $s6, 0x18($sp)
/* 32E298 E0012588 AFB50014 */  sw        $s5, 0x14($sp)
/* 32E29C E001258C AFB40010 */  sw        $s4, 0x10($sp)
/* 32E2A0 E0012590 AFB3000C */  sw        $s3, 0xc($sp)
/* 32E2A4 E0012594 AFB20008 */  sw        $s2, 8($sp)
/* 32E2A8 E0012598 AFB10004 */  sw        $s1, 4($sp)
/* 32E2AC E001259C AFB00000 */  sw        $s0, ($sp)
/* 32E2B0 E00125A0 8CC40000 */  lw        $a0, ($a2)
/* 32E2B4 E00125A4 8D87000C */  lw        $a3, 0xc($t4)
/* 32E2B8 E00125A8 0080182D */  daddu     $v1, $a0, $zero
/* 32E2BC E00125AC 24840008 */  addiu     $a0, $a0, 8
/* 32E2C0 E00125B0 AC620000 */  sw        $v0, ($v1)
/* 32E2C4 E00125B4 AC600004 */  sw        $zero, 4($v1)
/* 32E2C8 E00125B8 AC850000 */  sw        $a1, ($a0)
/* 32E2CC E00125BC 8D820010 */  lw        $v0, 0x10($t4)
/* 32E2D0 E00125C0 0000482D */  daddu     $t1, $zero, $zero
/* 32E2D4 E00125C4 ACC40000 */  sw        $a0, ($a2)
/* 32E2D8 E00125C8 8C42001C */  lw        $v0, 0x1c($v0)
/* 32E2DC E00125CC 3C038000 */  lui       $v1, 0x8000
/* 32E2E0 E00125D0 00431021 */  addu      $v0, $v0, $v1
/* 32E2E4 E00125D4 AC820004 */  sw        $v0, 4($a0)
/* 32E2E8 E00125D8 8D820008 */  lw        $v0, 8($t4)
/* 32E2EC E00125DC 24840008 */  addiu     $a0, $a0, 8
/* 32E2F0 E00125E0 18400053 */  blez      $v0, .LE0012730
/* 32E2F4 E00125E4 ACC40000 */   sw       $a0, ($a2)
/* 32E2F8 E00125E8 3C0E800A */  lui       $t6, %hi(gDisplayContext)
/* 32E2FC E00125EC 25CEA674 */  addiu     $t6, $t6, %lo(gDisplayContext)
/* 32E300 E00125F0 3C0D8007 */  lui       $t5, %hi(gMatrixListPos)
/* 32E304 E00125F4 25AD41F0 */  addiu     $t5, $t5, %lo(gMatrixListPos)
/* 32E308 E00125F8 3C0B0001 */  lui       $t3, 1
/* 32E30C E00125FC 356B1630 */  ori       $t3, $t3, 0x1630
/* 32E310 E0012600 00C0502D */  daddu     $t2, $a2, $zero
/* 32E314 E0012604 3C13E700 */  lui       $s3, 0xe700
/* 32E318 E0012608 3C12FA00 */  lui       $s2, 0xfa00
/* 32E31C E001260C 3C187060 */  lui       $t8, 0x7060
/* 32E320 E0012610 37181800 */  ori       $t8, $t8, 0x1800
/* 32E324 E0012614 3C11DA38 */  lui       $s1, 0xda38
/* 32E328 E0012618 3C10DE00 */  lui       $s0, 0xde00
/* 32E32C E001261C 3C0FD838 */  lui       $t7, 0xd838
/* 32E330 E0012620 35EF0002 */  ori       $t7, $t7, 2
/* 32E334 E0012624 24190040 */  addiu     $t9, $zero, 0x40
/* 32E338 E0012628 24E60008 */  addiu     $a2, $a3, 8
.LE001262C:
/* 32E33C E001262C 8CE20000 */  lw        $v0, ($a3)
/* 32E340 E0012630 5040003A */  beql      $v0, $zero, .LE001271C
/* 32E344 E0012634 25290001 */   addiu    $t1, $t1, 1
/* 32E348 E0012638 80C20001 */  lb        $v0, 1($a2)
/* 32E34C E001263C 3C080900 */  lui       $t0, 0x900
/* 32E350 E0012640 25080E38 */  addiu     $t0, $t0, 0xe38
/* 32E354 E0012644 10400003 */  beqz      $v0, .LE0012654
/* 32E358 E0012648 24E40030 */   addiu    $a0, $a3, 0x30
/* 32E35C E001264C 3C080900 */  lui       $t0, 0x900
/* 32E360 E0012650 25080E20 */  addiu     $t0, $t0, 0xe20
.LE0012654:
/* 32E364 E0012654 24E50070 */  addiu     $a1, $a3, 0x70
/* 32E368 E0012658 95A20000 */  lhu       $v0, ($t5)
/* 32E36C E001265C 8DC30000 */  lw        $v1, ($t6)
/* 32E370 E0012660 00021180 */  sll       $v0, $v0, 6
/* 32E374 E0012664 00621821 */  addu      $v1, $v1, $v0
/* 32E378 E0012668 006B1821 */  addu      $v1, $v1, $t3
.LE001266C:
/* 32E37C E001266C 8C940000 */  lw        $s4, ($a0)
/* 32E380 E0012670 8C950004 */  lw        $s5, 4($a0)
/* 32E384 E0012674 8C960008 */  lw        $s6, 8($a0)
/* 32E388 E0012678 8C97000C */  lw        $s7, 0xc($a0)
/* 32E38C E001267C AC740000 */  sw        $s4, ($v1)
/* 32E390 E0012680 AC750004 */  sw        $s5, 4($v1)
/* 32E394 E0012684 AC760008 */  sw        $s6, 8($v1)
/* 32E398 E0012688 AC77000C */  sw        $s7, 0xc($v1)
/* 32E39C E001268C 24840010 */  addiu     $a0, $a0, 0x10
/* 32E3A0 E0012690 1485FFF6 */  bne       $a0, $a1, .LE001266C
/* 32E3A4 E0012694 24630010 */   addiu    $v1, $v1, 0x10
/* 32E3A8 E0012698 8D440000 */  lw        $a0, ($t2)
/* 32E3AC E001269C 0080102D */  daddu     $v0, $a0, $zero
/* 32E3B0 E00126A0 24840008 */  addiu     $a0, $a0, 8
/* 32E3B4 E00126A4 AD440000 */  sw        $a0, ($t2)
/* 32E3B8 E00126A8 AC530000 */  sw        $s3, ($v0)
/* 32E3BC E00126AC AC400004 */  sw        $zero, 4($v0)
/* 32E3C0 E00126B0 24820008 */  addiu     $v0, $a0, 8
/* 32E3C4 E00126B4 AD420000 */  sw        $v0, ($t2)
/* 32E3C8 E00126B8 AC920000 */  sw        $s2, ($a0)
/* 32E3CC E00126BC 90C50000 */  lbu       $a1, ($a2)
/* 32E3D0 E00126C0 95A30000 */  lhu       $v1, ($t5)
/* 32E3D4 E00126C4 24820010 */  addiu     $v0, $a0, 0x10
/* 32E3D8 E00126C8 AD420000 */  sw        $v0, ($t2)
/* 32E3DC E00126CC AC910008 */  sw        $s1, 8($a0)
/* 32E3E0 E00126D0 24620001 */  addiu     $v0, $v1, 1
/* 32E3E4 E00126D4 3063FFFF */  andi      $v1, $v1, 0xffff
/* 32E3E8 E00126D8 00031980 */  sll       $v1, $v1, 6
/* 32E3EC E00126DC 006B1821 */  addu      $v1, $v1, $t3
/* 32E3F0 E00126E0 A5A20000 */  sh        $v0, ($t5)
/* 32E3F4 E00126E4 8DC20000 */  lw        $v0, ($t6)
/* 32E3F8 E00126E8 00B82825 */  or        $a1, $a1, $t8
/* 32E3FC E00126EC 00431021 */  addu      $v0, $v0, $v1
/* 32E400 E00126F0 AC82000C */  sw        $v0, 0xc($a0)
/* 32E404 E00126F4 24820018 */  addiu     $v0, $a0, 0x18
/* 32E408 E00126F8 AD420000 */  sw        $v0, ($t2)
/* 32E40C E00126FC 24820020 */  addiu     $v0, $a0, 0x20
/* 32E410 E0012700 AC900010 */  sw        $s0, 0x10($a0)
/* 32E414 E0012704 AC880014 */  sw        $t0, 0x14($a0)
/* 32E418 E0012708 AD420000 */  sw        $v0, ($t2)
/* 32E41C E001270C AC8F0018 */  sw        $t7, 0x18($a0)
/* 32E420 E0012710 AC99001C */  sw        $t9, 0x1c($a0)
/* 32E424 E0012714 AC850004 */  sw        $a1, 4($a0)
/* 32E428 E0012718 25290001 */  addiu     $t1, $t1, 1
.LE001271C:
/* 32E42C E001271C 24C60098 */  addiu     $a2, $a2, 0x98
/* 32E430 E0012720 8D820008 */  lw        $v0, 8($t4)
/* 32E434 E0012724 0122102A */  slt       $v0, $t1, $v0
/* 32E438 E0012728 1440FFC0 */  bnez      $v0, .LE001262C
/* 32E43C E001272C 24E70098 */   addiu    $a3, $a3, 0x98
.LE0012730:
/* 32E440 E0012730 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 32E444 E0012734 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 32E448 E0012738 8C620000 */  lw        $v0, ($v1)
/* 32E44C E001273C 0040202D */  daddu     $a0, $v0, $zero
/* 32E450 E0012740 24420008 */  addiu     $v0, $v0, 8
/* 32E454 E0012744 AC620000 */  sw        $v0, ($v1)
/* 32E458 E0012748 3C02E700 */  lui       $v0, 0xe700
/* 32E45C E001274C AC820000 */  sw        $v0, ($a0)
/* 32E460 E0012750 AC800004 */  sw        $zero, 4($a0)
/* 32E464 E0012754 8FB7001C */  lw        $s7, 0x1c($sp)
/* 32E468 E0012758 8FB60018 */  lw        $s6, 0x18($sp)
/* 32E46C E001275C 8FB50014 */  lw        $s5, 0x14($sp)
/* 32E470 E0012760 8FB40010 */  lw        $s4, 0x10($sp)
/* 32E474 E0012764 8FB3000C */  lw        $s3, 0xc($sp)
/* 32E478 E0012768 8FB20008 */  lw        $s2, 8($sp)
/* 32E47C E001276C 8FB10004 */  lw        $s1, 4($sp)
/* 32E480 E0012770 8FB00000 */  lw        $s0, ($sp)
/* 32E484 E0012774 03E00008 */  jr        $ra
/* 32E488 E0012778 27BD0020 */   addiu    $sp, $sp, 0x20
/* 32E48C E001277C 00000000 */  nop
