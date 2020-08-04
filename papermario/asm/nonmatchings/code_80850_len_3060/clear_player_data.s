.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel clear_player_data
/* 080850 800E73A0 0000182D */  daddu $v1, $zero, $zero
/* 080854 800E73A4 3C048011 */  lui   $a0, 0x8011
/* 080858 800E73A8 2484F290 */  addiu $a0, $a0, -0xd70
/* 08085C 800E73AC 0080282D */  daddu $a1, $a0, $zero
/* 080860 800E73B0 2402FFFF */  addiu $v0, $zero, -1
/* 080864 800E73B4 3C018011 */  lui   $at, 0x8011
/* 080868 800E73B8 A420CD10 */  sh    $zero, -0x32f0($at)
/* 08086C 800E73BC 3C018011 */  lui   $at, 0x8011
/* 080870 800E73C0 A420CD12 */  sh    $zero, -0x32ee($at)
/* 080874 800E73C4 A0820001 */  sb    $v0, 1($a0)
/* 080878 800E73C8 2402000A */  addiu $v0, $zero, 0xa
/* 08087C 800E73CC A0820002 */  sb    $v0, 2($a0)
/* 080880 800E73D0 A0820003 */  sb    $v0, 3($a0)
/* 080884 800E73D4 A0820004 */  sb    $v0, 4($a0)
/* 080888 800E73D8 24020005 */  addiu $v0, $zero, 5
/* 08088C 800E73DC A0820005 */  sb    $v0, 5($a0)
/* 080890 800E73E0 A0820006 */  sb    $v0, 6($a0)
/* 080894 800E73E4 A0820007 */  sb    $v0, 7($a0)
/* 080898 800E73E8 24020003 */  addiu $v0, $zero, 3
/* 08089C 800E73EC A0820008 */  sb    $v0, 8($a0)
/* 0808A0 800E73F0 24020001 */  addiu $v0, $zero, 1
/* 0808A4 800E73F4 A0820009 */  sb    $v0, 9($a0)
/* 0808A8 800E73F8 2402FFFF */  addiu $v0, $zero, -1
/* 0808AC 800E73FC A0800000 */  sb    $zero, ($a0)
/* 0808B0 800E7400 A080000A */  sb    $zero, 0xa($a0)
/* 0808B4 800E7404 A480000C */  sh    $zero, 0xc($a0)
/* 0808B8 800E7408 A080000E */  sb    $zero, 0xe($a0)
/* 0808BC 800E740C A080000F */  sb    $zero, 0xf($a0)
/* 0808C0 800E7410 A0800010 */  sb    $zero, 0x10($a0)
/* 0808C4 800E7414 A0800011 */  sb    $zero, 0x11($a0)
/* 0808C8 800E7418 A0800288 */  sb    $zero, 0x288($a0)
/* 0808CC 800E741C A0800289 */  sb    $zero, 0x289($a0)
/* 0808D0 800E7420 A080028A */  sb    $zero, 0x28a($a0)
/* 0808D4 800E7424 A482028C */  sh    $v0, 0x28c($a0)
/* 0808D8 800E7428 A080028E */  sb    $zero, 0x28e($a0)
/* 0808DC 800E742C A4800290 */  sh    $zero, 0x290($a0)
/* 0808E0 800E7430 A0800292 */  sb    $zero, 0x292($a0)
/* 0808E4 800E7434 A0800012 */  sb    $zero, 0x12($a0)
.L800E7438:
/* 0808E8 800E7438 A0A00014 */  sb    $zero, 0x14($a1)
/* 0808EC 800E743C A0A00015 */  sb    $zero, 0x15($a1)
/* 0808F0 800E7440 A4A00016 */  sh    $zero, 0x16($a1)
/* 0808F4 800E7444 A4A00018 */  sh    $zero, 0x18($a1)
/* 0808F8 800E7448 A4A0001A */  sh    $zero, 0x1a($a1)
/* 0808FC 800E744C 24630001 */  addiu $v1, $v1, 1
/* 080900 800E7450 2862000C */  slti  $v0, $v1, 0xc
/* 080904 800E7454 1440FFF8 */  bnez  $v0, .L800E7438
/* 080908 800E7458 24A50008 */   addiu $a1, $a1, 8
/* 08090C 800E745C 2403001F */  addiu $v1, $zero, 0x1f
/* 080910 800E7460 2482003E */  addiu $v0, $a0, 0x3e
.L800E7464:
/* 080914 800E7464 A4400074 */  sh    $zero, 0x74($v0)
/* 080918 800E7468 2463FFFF */  addiu $v1, $v1, -1
/* 08091C 800E746C 0461FFFD */  bgez  $v1, .L800E7464
/* 080920 800E7470 2442FFFE */   addiu $v0, $v0, -2
/* 080924 800E7474 2403007F */  addiu $v1, $zero, 0x7f
/* 080928 800E7478 248200FE */  addiu $v0, $a0, 0xfe
.L800E747C:
/* 08092C 800E747C A44000B4 */  sh    $zero, 0xb4($v0)
/* 080930 800E7480 2463FFFF */  addiu $v1, $v1, -1
/* 080934 800E7484 0461FFFD */  bgez  $v1, .L800E747C
/* 080938 800E7488 2442FFFE */   addiu $v0, $v0, -2
/* 08093C 800E748C 24030009 */  addiu $v1, $zero, 9
/* 080940 800E7490 24820012 */  addiu $v0, $a0, 0x12
.L800E7494:
/* 080944 800E7494 A44001B4 */  sh    $zero, 0x1b4($v0)
/* 080948 800E7498 2463FFFF */  addiu $v1, $v1, -1
/* 08094C 800E749C 0461FFFD */  bgez  $v1, .L800E7494
/* 080950 800E74A0 2442FFFE */   addiu $v0, $v0, -2
/* 080954 800E74A4 2403003F */  addiu $v1, $zero, 0x3f
/* 080958 800E74A8 2482007E */  addiu $v0, $a0, 0x7e
.L800E74AC:
/* 08095C 800E74AC A4400208 */  sh    $zero, 0x208($v0)
/* 080960 800E74B0 2463FFFF */  addiu $v1, $v1, -1
/* 080964 800E74B4 0461FFFD */  bgez  $v1, .L800E74AC
/* 080968 800E74B8 2442FFFE */   addiu $v0, $v0, -2
/* 08096C 800E74BC 2403001F */  addiu $v1, $zero, 0x1f
/* 080970 800E74C0 2482003E */  addiu $v0, $a0, 0x3e
.L800E74C4:
/* 080974 800E74C4 A44001C8 */  sh    $zero, 0x1c8($v0)
/* 080978 800E74C8 2463FFFF */  addiu $v1, $v1, -1
/* 08097C 800E74CC 0461FFFD */  bgez  $v1, .L800E74C4
/* 080980 800E74D0 2442FFFE */   addiu $v0, $v0, -2
/* 080984 800E74D4 0000182D */  daddu $v1, $zero, $zero
/* 080988 800E74D8 0080282D */  daddu $a1, $a0, $zero
/* 08098C 800E74DC A4800294 */  sh    $zero, 0x294($a0)
/* 080990 800E74E0 A4800296 */  sh    $zero, 0x296($a0)
/* 080994 800E74E4 A4800298 */  sh    $zero, 0x298($a0)
/* 080998 800E74E8 A480029A */  sh    $zero, 0x29a($a0)
/* 08099C 800E74EC A480029C */  sh    $zero, 0x29c($a0)
/* 0809A0 800E74F0 A480029E */  sh    $zero, 0x29e($a0)
/* 0809A4 800E74F4 A48002A0 */  sh    $zero, 0x2a0($a0)
/* 0809A8 800E74F8 A48002A2 */  sh    $zero, 0x2a2($a0)
/* 0809AC 800E74FC A48002A4 */  sh    $zero, 0x2a4($a0)
/* 0809B0 800E7500 A48002A6 */  sh    $zero, 0x2a6($a0)
/* 0809B4 800E7504 A48002A8 */  sh    $zero, 0x2a8($a0)
/* 0809B8 800E7508 A48002AA */  sh    $zero, 0x2aa($a0)
/* 0809BC 800E750C AC8002AC */  sw    $zero, 0x2ac($a0)
/* 0809C0 800E7510 AC8002B0 */  sw    $zero, 0x2b0($a0)
/* 0809C4 800E7514 A48002B8 */  sh    $zero, 0x2b8($a0)
/* 0809C8 800E7518 AC8002B4 */  sw    $zero, 0x2b4($a0)
/* 0809CC 800E751C AC8002BC */  sw    $zero, 0x2bc($a0)
/* 0809D0 800E7520 A48002C0 */  sh    $zero, 0x2c0($a0)
/* 0809D4 800E7524 A48002C2 */  sh    $zero, 0x2c2($a0)
.L800E7528:
/* 0809D8 800E7528 ACA002C4 */  sw    $zero, 0x2c4($a1)
/* 0809DC 800E752C ACA002F4 */  sw    $zero, 0x2f4($a1)
/* 0809E0 800E7530 24630001 */  addiu $v1, $v1, 1
/* 0809E4 800E7534 2862000C */  slti  $v0, $v1, 0xc
/* 0809E8 800E7538 1440FFFB */  bnez  $v0, .L800E7528
/* 0809EC 800E753C 24A50004 */   addiu $a1, $a1, 4
/* 0809F0 800E7540 AC800328 */  sw    $zero, 0x328($a0)
/* 0809F4 800E7544 A480032C */  sh    $zero, 0x32c($a0)
/* 0809F8 800E7548 A480032E */  sh    $zero, 0x32e($a0)
/* 0809FC 800E754C AC800330 */  sw    $zero, 0x330($a0)
/* 080A00 800E7550 A4800334 */  sh    $zero, 0x334($a0)
/* 080A04 800E7554 A4800336 */  sh    $zero, 0x336($a0)
/* 080A08 800E7558 AC800338 */  sw    $zero, 0x338($a0)
/* 080A0C 800E755C 03E00008 */  jr    $ra
/* 080A10 800E7560 A480033C */   sh    $zero, 0x33c($a0)

