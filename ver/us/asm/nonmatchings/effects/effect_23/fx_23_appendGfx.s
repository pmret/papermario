.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_23_appendGfx
/* 341D48 E002E368 27BDFEF8 */  addiu     $sp, $sp, -0x108
/* 341D4C E002E36C AFBE0100 */  sw        $fp, 0x100($sp)
/* 341D50 E002E370 0080F02D */  daddu     $fp, $a0, $zero
/* 341D54 E002E374 AFBF0104 */  sw        $ra, 0x104($sp)
/* 341D58 E002E378 AFB700FC */  sw        $s7, 0xfc($sp)
/* 341D5C E002E37C AFB600F8 */  sw        $s6, 0xf8($sp)
/* 341D60 E002E380 AFB500F4 */  sw        $s5, 0xf4($sp)
/* 341D64 E002E384 AFB400F0 */  sw        $s4, 0xf0($sp)
/* 341D68 E002E388 AFB300EC */  sw        $s3, 0xec($sp)
/* 341D6C E002E38C AFB200E8 */  sw        $s2, 0xe8($sp)
/* 341D70 E002E390 AFB100E4 */  sw        $s1, 0xe4($sp)
/* 341D74 E002E394 AFB000E0 */  sw        $s0, 0xe0($sp)
/* 341D78 E002E398 8FD4000C */  lw        $s4, 0xc($fp)
/* 341D7C E002E39C 8E820040 */  lw        $v0, 0x40($s4)
/* 341D80 E002E3A0 3C170900 */  lui       $s7, 0x900
/* 341D84 E002E3A4 26F72B40 */  addiu     $s7, $s7, 0x2b40
/* 341D88 E002E3A8 30550007 */  andi      $s5, $v0, 7
/* 341D8C E002E3AC 30430038 */  andi      $v1, $v0, 0x38
/* 341D90 E002E3B0 0003B080 */  sll       $s6, $v1, 2
/* 341D94 E002E3B4 96830000 */  lhu       $v1, ($s4)
/* 341D98 E002E3B8 30420040 */  andi      $v0, $v0, 0x40
/* 341D9C E002E3BC 10600003 */  beqz      $v1, .LE002E3CC
/* 341DA0 E002E3C0 AFA200D8 */   sw       $v0, 0xd8($sp)
/* 341DA4 E002E3C4 3C170900 */  lui       $s7, 0x900
/* 341DA8 E002E3C8 26F72B60 */  addiu     $s7, $s7, 0x2b60
.LE002E3CC:
/* 341DAC E002E3CC 3C06DB06 */  lui       $a2, 0xdb06
/* 341DB0 E002E3D0 34C60024 */  ori       $a2, $a2, 0x24
/* 341DB4 E002E3D4 27A40018 */  addiu     $a0, $sp, 0x18
/* 341DB8 E002E3D8 3C120001 */  lui       $s2, 1
/* 341DBC E002E3DC 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 341DC0 E002E3E0 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 341DC4 E002E3E4 36521630 */  ori       $s2, $s2, 0x1630
/* 341DC8 E002E3E8 8E630000 */  lw        $v1, ($s3)
/* 341DCC E002E3EC 3C02E700 */  lui       $v0, 0xe700
/* 341DD0 E002E3F0 0060282D */  daddu     $a1, $v1, $zero
/* 341DD4 E002E3F4 24630008 */  addiu     $v1, $v1, 8
/* 341DD8 E002E3F8 AE630000 */  sw        $v1, ($s3)
/* 341DDC E002E3FC ACA20000 */  sw        $v0, ($a1)
/* 341DE0 E002E400 ACA00004 */  sw        $zero, 4($a1)
/* 341DE4 E002E404 AC660000 */  sw        $a2, ($v1)
/* 341DE8 E002E408 8FC50010 */  lw        $a1, 0x10($fp)
/* 341DEC E002E40C 24620008 */  addiu     $v0, $v1, 8
/* 341DF0 E002E410 AE620000 */  sw        $v0, ($s3)
/* 341DF4 E002E414 8CA5001C */  lw        $a1, 0x1c($a1)
/* 341DF8 E002E418 3C02DE00 */  lui       $v0, 0xde00
/* 341DFC E002E41C AC620008 */  sw        $v0, 8($v1)
/* 341E00 E002E420 3C020900 */  lui       $v0, 0x900
/* 341E04 E002E424 24422950 */  addiu     $v0, $v0, 0x2950
/* 341E08 E002E428 AC62000C */  sw        $v0, 0xc($v1)
/* 341E0C E002E42C 3C028000 */  lui       $v0, 0x8000
/* 341E10 E002E430 00A22821 */  addu      $a1, $a1, $v0
/* 341E14 E002E434 AC650004 */  sw        $a1, 4($v1)
/* 341E18 E002E438 8E850004 */  lw        $a1, 4($s4)
/* 341E1C E002E43C 8E860008 */  lw        $a2, 8($s4)
/* 341E20 E002E440 8E87000C */  lw        $a3, 0xc($s4)
/* 341E24 E002E444 24630010 */  addiu     $v1, $v1, 0x10
/* 341E28 E002E448 0C080108 */  jal       shim_guTranslateF
/* 341E2C E002E44C AE630000 */   sw       $v1, ($s3)
/* 341E30 E002E450 27B00058 */  addiu     $s0, $sp, 0x58
/* 341E34 E002E454 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 341E38 E002E458 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 341E3C E002E45C 44800000 */  mtc1      $zero, $f0
/* 341E40 E002E460 00031080 */  sll       $v0, $v1, 2
/* 341E44 E002E464 00431021 */  addu      $v0, $v0, $v1
/* 341E48 E002E468 00021080 */  sll       $v0, $v0, 2
/* 341E4C E002E46C 00431023 */  subu      $v0, $v0, $v1
/* 341E50 E002E470 000218C0 */  sll       $v1, $v0, 3
/* 341E54 E002E474 00431021 */  addu      $v0, $v0, $v1
/* 341E58 E002E478 000210C0 */  sll       $v0, $v0, 3
/* 341E5C E002E47C 44060000 */  mfc1      $a2, $f0
/* 341E60 E002E480 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 341E64 E002E484 00220821 */  addu      $at, $at, $v0
/* 341E68 E002E488 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 341E6C E002E48C 3C073F80 */  lui       $a3, 0x3f80
/* 341E70 E002E490 46000007 */  neg.s     $f0, $f0
/* 341E74 E002E494 44050000 */  mfc1      $a1, $f0
/* 341E78 E002E498 0200202D */  daddu     $a0, $s0, $zero
/* 341E7C E002E49C 0C080104 */  jal       shim_guRotateF
/* 341E80 E002E4A0 AFA60010 */   sw       $a2, 0x10($sp)
/* 341E84 E002E4A4 0200202D */  daddu     $a0, $s0, $zero
/* 341E88 E002E4A8 27A50018 */  addiu     $a1, $sp, 0x18
/* 341E8C E002E4AC 27B00098 */  addiu     $s0, $sp, 0x98
/* 341E90 E002E4B0 0C080114 */  jal       shim_guMtxCatF
/* 341E94 E002E4B4 0200302D */   daddu    $a2, $s0, $zero
/* 341E98 E002E4B8 0200202D */  daddu     $a0, $s0, $zero
/* 341E9C E002E4BC 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 341EA0 E002E4C0 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 341EA4 E002E4C4 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 341EA8 E002E4C8 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 341EAC E002E4CC 96050000 */  lhu       $a1, ($s0)
/* 341EB0 E002E4D0 8E220000 */  lw        $v0, ($s1)
/* 341EB4 E002E4D4 00052980 */  sll       $a1, $a1, 6
/* 341EB8 E002E4D8 00B22821 */  addu      $a1, $a1, $s2
/* 341EBC E002E4DC 0C080118 */  jal       shim_guMtxF2L
/* 341EC0 E002E4E0 00452821 */   addu     $a1, $v0, $a1
/* 341EC4 E002E4E4 3C05EEDC */  lui       $a1, 0xeedc
/* 341EC8 E002E4E8 8E660000 */  lw        $a2, ($s3)
/* 341ECC E002E4EC 34A5D7A0 */  ori       $a1, $a1, 0xd7a0
/* 341ED0 E002E4F0 00C0202D */  daddu     $a0, $a2, $zero
/* 341ED4 E002E4F4 24C60008 */  addiu     $a2, $a2, 8
/* 341ED8 E002E4F8 AE660000 */  sw        $a2, ($s3)
/* 341EDC E002E4FC 96020000 */  lhu       $v0, ($s0)
/* 341EE0 E002E500 3C03DA38 */  lui       $v1, 0xda38
/* 341EE4 E002E504 AC830000 */  sw        $v1, ($a0)
/* 341EE8 E002E508 24430001 */  addiu     $v1, $v0, 1
/* 341EEC E002E50C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 341EF0 E002E510 00021180 */  sll       $v0, $v0, 6
/* 341EF4 E002E514 A6030000 */  sh        $v1, ($s0)
/* 341EF8 E002E518 8E230000 */  lw        $v1, ($s1)
/* 341EFC E002E51C 00521021 */  addu      $v0, $v0, $s2
/* 341F00 E002E520 00621821 */  addu      $v1, $v1, $v0
/* 341F04 E002E524 24C20008 */  addiu     $v0, $a2, 8
/* 341F08 E002E528 AC830004 */  sw        $v1, 4($a0)
/* 341F0C E002E52C AE620000 */  sw        $v0, ($s3)
/* 341F10 E002E530 3C02FA00 */  lui       $v0, 0xfa00
/* 341F14 E002E534 ACC20000 */  sw        $v0, ($a2)
/* 341F18 E002E538 24C20010 */  addiu     $v0, $a2, 0x10
/* 341F1C E002E53C ACC50004 */  sw        $a1, 4($a2)
/* 341F20 E002E540 AE620000 */  sw        $v0, ($s3)
/* 341F24 E002E544 3C02FB00 */  lui       $v0, 0xfb00
/* 341F28 E002E548 ACC20008 */  sw        $v0, 8($a2)
/* 341F2C E002E54C 24C20018 */  addiu     $v0, $a2, 0x18
/* 341F30 E002E550 ACD6000C */  sw        $s6, 0xc($a2)
/* 341F34 E002E554 AE620000 */  sw        $v0, ($s3)
/* 341F38 E002E558 001514C0 */  sll       $v0, $s5, 0x13
/* 341F3C E002E55C 3C04F200 */  lui       $a0, 0xf200
/* 341F40 E002E560 00441025 */  or        $v0, $v0, $a0
/* 341F44 E002E564 00152940 */  sll       $a1, $s5, 5
/* 341F48 E002E568 ACC20010 */  sw        $v0, 0x10($a2)
/* 341F4C E002E56C 24A2001F */  addiu     $v0, $a1, 0x1f
/* 341F50 E002E570 00021380 */  sll       $v0, $v0, 0xe
/* 341F54 E002E574 3442007C */  ori       $v0, $v0, 0x7c
/* 341F58 E002E578 ACC20014 */  sw        $v0, 0x14($a2)
/* 341F5C E002E57C 8FA800D8 */  lw        $t0, 0xd8($sp)
/* 341F60 E002E580 1100000E */  beqz      $t0, .LE002E5BC
/* 341F64 E002E584 24A70020 */   addiu    $a3, $a1, 0x20
/* 341F68 E002E588 0080182D */  daddu     $v1, $a0, $zero
/* 341F6C E002E58C 34630080 */  ori       $v1, $v1, 0x80
/* 341F70 E002E590 3C040100 */  lui       $a0, 0x100
/* 341F74 E002E594 348400FC */  ori       $a0, $a0, 0xfc
/* 341F78 E002E598 24C20020 */  addiu     $v0, $a2, 0x20
/* 341F7C E002E59C AE620000 */  sw        $v0, ($s3)
/* 341F80 E002E5A0 00071380 */  sll       $v0, $a3, 0xe
/* 341F84 E002E5A4 00431025 */  or        $v0, $v0, $v1
/* 341F88 E002E5A8 ACC20018 */  sw        $v0, 0x18($a2)
/* 341F8C E002E5AC 24A2003F */  addiu     $v0, $a1, 0x3f
/* 341F90 E002E5B0 00021380 */  sll       $v0, $v0, 0xe
/* 341F94 E002E5B4 0800B979 */  j         .LE002E5E4
/* 341F98 E002E5B8 00441025 */   or       $v0, $v0, $a0
.LE002E5BC:
/* 341F9C E002E5BC 3C030100 */  lui       $v1, 0x100
/* 341FA0 E002E5C0 3463007C */  ori       $v1, $v1, 0x7c
/* 341FA4 E002E5C4 24C20020 */  addiu     $v0, $a2, 0x20
/* 341FA8 E002E5C8 AE620000 */  sw        $v0, ($s3)
/* 341FAC E002E5CC 00071380 */  sll       $v0, $a3, 0xe
/* 341FB0 E002E5D0 00441025 */  or        $v0, $v0, $a0
/* 341FB4 E002E5D4 ACC20018 */  sw        $v0, 0x18($a2)
/* 341FB8 E002E5D8 24A2003F */  addiu     $v0, $a1, 0x3f
/* 341FBC E002E5DC 00021380 */  sll       $v0, $v0, 0xe
/* 341FC0 E002E5E0 00431025 */  or        $v0, $v0, $v1
.LE002E5E4:
/* 341FC4 E002E5E4 ACC2001C */  sw        $v0, 0x1c($a2)
/* 341FC8 E002E5E8 8FC20008 */  lw        $v0, 8($fp)
/* 341FCC E002E5EC 24110001 */  addiu     $s1, $zero, 1
/* 341FD0 E002E5F0 0222102A */  slt       $v0, $s1, $v0
/* 341FD4 E002E5F4 10400036 */  beqz      $v0, .LE002E6D0
/* 341FD8 E002E5F8 26940044 */   addiu    $s4, $s4, 0x44
/* 341FDC E002E5FC 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 341FE0 E002E600 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 341FE4 E002E604 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 341FE8 E002E608 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 341FEC E002E60C 3C130001 */  lui       $s3, 1
/* 341FF0 E002E610 36731630 */  ori       $s3, $s3, 0x1630
/* 341FF4 E002E614 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 341FF8 E002E618 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 341FFC E002E61C 2690000C */  addiu     $s0, $s4, 0xc
.LE002E620:
/* 342000 E002E620 27A40018 */  addiu     $a0, $sp, 0x18
/* 342004 E002E624 26310001 */  addiu     $s1, $s1, 1
/* 342008 E002E628 8E05FFF8 */  lw        $a1, -8($s0)
/* 34200C E002E62C 8E06FFFC */  lw        $a2, -4($s0)
/* 342010 E002E630 8E070000 */  lw        $a3, ($s0)
/* 342014 E002E634 0C080108 */  jal       shim_guTranslateF
/* 342018 E002E638 26100044 */   addiu    $s0, $s0, 0x44
/* 34201C E002E63C 27A40018 */  addiu     $a0, $sp, 0x18
/* 342020 E002E640 96A50000 */  lhu       $a1, ($s5)
/* 342024 E002E644 8EC20000 */  lw        $v0, ($s6)
/* 342028 E002E648 00052980 */  sll       $a1, $a1, 6
/* 34202C E002E64C 00B32821 */  addu      $a1, $a1, $s3
/* 342030 E002E650 0C080118 */  jal       shim_guMtxF2L
/* 342034 E002E654 00452821 */   addu     $a1, $v0, $a1
/* 342038 E002E658 3C06D838 */  lui       $a2, 0xd838
/* 34203C E002E65C 8E440000 */  lw        $a0, ($s2)
/* 342040 E002E660 34C60002 */  ori       $a2, $a2, 2
/* 342044 E002E664 0080282D */  daddu     $a1, $a0, $zero
/* 342048 E002E668 24840008 */  addiu     $a0, $a0, 8
/* 34204C E002E66C AE440000 */  sw        $a0, ($s2)
/* 342050 E002E670 96A20000 */  lhu       $v0, ($s5)
/* 342054 E002E674 3C03DA38 */  lui       $v1, 0xda38
/* 342058 E002E678 ACA30000 */  sw        $v1, ($a1)
/* 34205C E002E67C 24430001 */  addiu     $v1, $v0, 1
/* 342060 E002E680 3042FFFF */  andi      $v0, $v0, 0xffff
/* 342064 E002E684 00021180 */  sll       $v0, $v0, 6
/* 342068 E002E688 A6A30000 */  sh        $v1, ($s5)
/* 34206C E002E68C 8EC30000 */  lw        $v1, ($s6)
/* 342070 E002E690 00531021 */  addu      $v0, $v0, $s3
/* 342074 E002E694 00621821 */  addu      $v1, $v1, $v0
/* 342078 E002E698 24820008 */  addiu     $v0, $a0, 8
/* 34207C E002E69C ACA30004 */  sw        $v1, 4($a1)
/* 342080 E002E6A0 AE420000 */  sw        $v0, ($s2)
/* 342084 E002E6A4 3C02DE00 */  lui       $v0, 0xde00
/* 342088 E002E6A8 AC820000 */  sw        $v0, ($a0)
/* 34208C E002E6AC 24020040 */  addiu     $v0, $zero, 0x40
/* 342090 E002E6B0 AC970004 */  sw        $s7, 4($a0)
/* 342094 E002E6B4 AC860008 */  sw        $a2, 8($a0)
/* 342098 E002E6B8 AC82000C */  sw        $v0, 0xc($a0)
/* 34209C E002E6BC 8FC20008 */  lw        $v0, 8($fp)
/* 3420A0 E002E6C0 24840010 */  addiu     $a0, $a0, 0x10
/* 3420A4 E002E6C4 0222102A */  slt       $v0, $s1, $v0
/* 3420A8 E002E6C8 1440FFD5 */  bnez      $v0, .LE002E620
/* 3420AC E002E6CC AE440000 */   sw       $a0, ($s2)
.LE002E6D0:
/* 3420B0 E002E6D0 3C03D838 */  lui       $v1, 0xd838
/* 3420B4 E002E6D4 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3420B8 E002E6D8 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3420BC E002E6DC 8C820000 */  lw        $v0, ($a0)
/* 3420C0 E002E6E0 34630002 */  ori       $v1, $v1, 2
/* 3420C4 E002E6E4 0040282D */  daddu     $a1, $v0, $zero
/* 3420C8 E002E6E8 24420008 */  addiu     $v0, $v0, 8
/* 3420CC E002E6EC AC820000 */  sw        $v0, ($a0)
/* 3420D0 E002E6F0 ACA30000 */  sw        $v1, ($a1)
/* 3420D4 E002E6F4 24030040 */  addiu     $v1, $zero, 0x40
/* 3420D8 E002E6F8 ACA30004 */  sw        $v1, 4($a1)
/* 3420DC E002E6FC 24430008 */  addiu     $v1, $v0, 8
/* 3420E0 E002E700 AC830000 */  sw        $v1, ($a0)
/* 3420E4 E002E704 3C03E700 */  lui       $v1, 0xe700
/* 3420E8 E002E708 AC430000 */  sw        $v1, ($v0)
/* 3420EC E002E70C AC400004 */  sw        $zero, 4($v0)
/* 3420F0 E002E710 8FBF0104 */  lw        $ra, 0x104($sp)
/* 3420F4 E002E714 8FBE0100 */  lw        $fp, 0x100($sp)
/* 3420F8 E002E718 8FB700FC */  lw        $s7, 0xfc($sp)
/* 3420FC E002E71C 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 342100 E002E720 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 342104 E002E724 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 342108 E002E728 8FB300EC */  lw        $s3, 0xec($sp)
/* 34210C E002E72C 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 342110 E002E730 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 342114 E002E734 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 342118 E002E738 03E00008 */  jr        $ra
/* 34211C E002E73C 27BD0108 */   addiu    $sp, $sp, 0x108
