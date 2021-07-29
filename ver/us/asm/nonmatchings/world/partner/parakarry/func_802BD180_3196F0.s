.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802BEB10_31B080
.double 0.8

.section .text

glabel func_802BD180_3196F0
/* 3196F0 802BD180 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3196F4 802BD184 AFB00018 */  sw        $s0, 0x18($sp)
/* 3196F8 802BD188 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 3196FC 802BD18C 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 319700 802BD190 AFBF0028 */  sw        $ra, 0x28($sp)
/* 319704 802BD194 AFB30024 */  sw        $s3, 0x24($sp)
/* 319708 802BD198 AFB20020 */  sw        $s2, 0x20($sp)
/* 31970C 802BD19C AFB1001C */  sw        $s1, 0x1c($sp)
/* 319710 802BD1A0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 319714 802BD1A4 8C91014C */  lw        $s1, 0x14c($a0)
/* 319718 802BD1A8 10A00009 */  beqz      $a1, .L802BD1D0
/* 31971C 802BD1AC 0220202D */   daddu    $a0, $s1, $zero
/* 319720 802BD1B0 0C03B4C4 */  jal       partner_flying_enable
/* 319724 802BD1B4 24050001 */   addiu    $a1, $zero, 1
/* 319728 802BD1B8 3C04802C */  lui       $a0, %hi(D_802BEAAC_31B01C)
/* 31972C 802BD1BC 8C84EAAC */  lw        $a0, %lo(D_802BEAAC_31B01C)($a0)
/* 319730 802BD1C0 0C00A580 */  jal       mem_clear
/* 319734 802BD1C4 2405001C */   addiu    $a1, $zero, 0x1c
/* 319738 802BD1C8 3C018011 */  lui       $at, %hi(D_8010C954)
/* 31973C 802BD1CC AC20C954 */  sw        $zero, %lo(D_8010C954)($at)
.L802BD1D0:
/* 319740 802BD1D0 3C138011 */  lui       $s3, %hi(D_8010C954)
/* 319744 802BD1D4 2673C954 */  addiu     $s3, $s3, %lo(D_8010C954)
/* 319748 802BD1D8 8E020304 */  lw        $v0, 0x304($s0)
/* 31974C 802BD1DC 8E720000 */  lw        $s2, ($s3)
/* 319750 802BD1E0 24420001 */  addiu     $v0, $v0, 1
/* 319754 802BD1E4 16400007 */  bnez      $s2, .L802BD204
/* 319758 802BD1E8 AE020304 */   sw       $v0, 0x304($s0)
/* 31975C 802BD1EC 0C03B52E */  jal       partner_flying_update_player_tracking
/* 319760 802BD1F0 0220202D */   daddu    $a0, $s1, $zero
/* 319764 802BD1F4 0C03B574 */  jal       partner_flying_update_motion
/* 319768 802BD1F8 0220202D */   daddu    $a0, $s1, $zero
/* 31976C 802BD1FC 080AF53D */  j         .L802BD4F4
/* 319770 802BD200 0000102D */   daddu    $v0, $zero, $zero
.L802BD204:
/* 319774 802BD204 3C10802C */  lui       $s0, %hi(D_802BEAAC_31B01C)
/* 319778 802BD208 2610EAAC */  addiu     $s0, $s0, %lo(D_802BEAAC_31B01C)
/* 31977C 802BD20C 8E040000 */  lw        $a0, ($s0)
/* 319780 802BD210 8C830004 */  lw        $v1, 4($a0)
/* 319784 802BD214 24050001 */  addiu     $a1, $zero, 1
/* 319788 802BD218 10650030 */  beq       $v1, $a1, .L802BD2DC
/* 31978C 802BD21C 28620002 */   slti     $v0, $v1, 2
/* 319790 802BD220 10400005 */  beqz      $v0, .L802BD238
/* 319794 802BD224 24020002 */   addiu    $v0, $zero, 2
/* 319798 802BD228 10600009 */  beqz      $v1, .L802BD250
/* 31979C 802BD22C 0000102D */   daddu    $v0, $zero, $zero
/* 3197A0 802BD230 080AF53D */  j         .L802BD4F4
/* 3197A4 802BD234 00000000 */   nop
.L802BD238:
/* 3197A8 802BD238 1062009A */  beq       $v1, $v0, .L802BD4A4
/* 3197AC 802BD23C 24020003 */   addiu    $v0, $zero, 3
/* 3197B0 802BD240 106200A0 */  beq       $v1, $v0, .L802BD4C4
/* 3197B4 802BD244 0000102D */   daddu    $v0, $zero, $zero
/* 3197B8 802BD248 080AF53D */  j         .L802BD4F4
/* 3197BC 802BD24C 00000000 */   nop
.L802BD250:
/* 3197C0 802BD250 AC850004 */  sw        $a1, 4($a0)
/* 3197C4 802BD254 8E220000 */  lw        $v0, ($s1)
/* 3197C8 802BD258 AC820008 */  sw        $v0, 8($a0)
/* 3197CC 802BD25C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 3197D0 802BD260 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 3197D4 802BD264 8E460048 */  lw        $a2, 0x48($s2)
/* 3197D8 802BD268 0C00A7B5 */  jal       dist2D
/* 3197DC 802BD26C 8E470050 */   lw       $a3, 0x50($s2)
/* 3197E0 802BD270 8E020000 */  lw        $v0, ($s0)
/* 3197E4 802BD274 46000005 */  abs.s     $f0, $f0
/* 3197E8 802BD278 E440000C */  swc1      $f0, 0xc($v0)
/* 3197EC 802BD27C C64C0048 */  lwc1      $f12, 0x48($s2)
/* 3197F0 802BD280 C64E0050 */  lwc1      $f14, 0x50($s2)
/* 3197F4 802BD284 8E260038 */  lw        $a2, 0x38($s1)
/* 3197F8 802BD288 0C00A720 */  jal       atan2
/* 3197FC 802BD28C 8E270040 */   lw       $a3, 0x40($s1)
/* 319800 802BD290 3C040004 */  lui       $a0, 4
/* 319804 802BD294 24020078 */  addiu     $v0, $zero, 0x78
/* 319808 802BD298 8E030000 */  lw        $v1, ($s0)
/* 31980C 802BD29C 3C0140C0 */  lui       $at, 0x40c0
/* 319810 802BD2A0 44811000 */  mtc1      $at, $f2
/* 319814 802BD2A4 3C014248 */  lui       $at, 0x4248
/* 319818 802BD2A8 44812000 */  mtc1      $at, $f4
/* 31981C 802BD2AC 34840148 */  ori       $a0, $a0, 0x148
/* 319820 802BD2B0 E4600010 */  swc1      $f0, 0x10($v1)
/* 319824 802BD2B4 E4620014 */  swc1      $f2, 0x14($v1)
/* 319828 802BD2B8 E4640018 */  swc1      $f4, 0x18($v1)
/* 31982C 802BD2BC AC620000 */  sw        $v0, ($v1)
/* 319830 802BD2C0 8E220000 */  lw        $v0, ($s1)
/* 319834 802BD2C4 2403FDFF */  addiu     $v1, $zero, -0x201
/* 319838 802BD2C8 00441025 */  or        $v0, $v0, $a0
/* 31983C 802BD2CC 00431024 */  and       $v0, $v0, $v1
/* 319840 802BD2D0 AE220000 */  sw        $v0, ($s1)
/* 319844 802BD2D4 3C10802C */  lui       $s0, %hi(D_802BEAAC_31B01C)
/* 319848 802BD2D8 2610EAAC */  addiu     $s0, $s0, %lo(D_802BEAAC_31B01C)
.L802BD2DC:
/* 31984C 802BD2DC 8E020000 */  lw        $v0, ($s0)
/* 319850 802BD2E0 3C0140C9 */  lui       $at, 0x40c9
/* 319854 802BD2E4 34210FD0 */  ori       $at, $at, 0xfd0
/* 319858 802BD2E8 44810000 */  mtc1      $at, $f0
/* 31985C 802BD2EC C44C0010 */  lwc1      $f12, 0x10($v0)
/* 319860 802BD2F0 46006302 */  mul.s     $f12, $f12, $f0
/* 319864 802BD2F4 00000000 */  nop
/* 319868 802BD2F8 27A50010 */  addiu     $a1, $sp, 0x10
/* 31986C 802BD2FC 3C0143B4 */  lui       $at, 0x43b4
/* 319870 802BD300 44810000 */  mtc1      $at, $f0
/* 319874 802BD304 27A60014 */  addiu     $a2, $sp, 0x14
/* 319878 802BD308 0C00A82D */  jal       sin_cos_rad
/* 31987C 802BD30C 46006303 */   div.s    $f12, $f12, $f0
/* 319880 802BD310 8E020000 */  lw        $v0, ($s0)
/* 319884 802BD314 C7A20010 */  lwc1      $f2, 0x10($sp)
/* 319888 802BD318 C440000C */  lwc1      $f0, 0xc($v0)
/* 31988C 802BD31C 46001082 */  mul.s     $f2, $f2, $f0
/* 319890 802BD320 00000000 */  nop
/* 319894 802BD324 C6400048 */  lwc1      $f0, 0x48($s2)
/* 319898 802BD328 46020000 */  add.s     $f0, $f0, $f2
/* 31989C 802BD32C E6200038 */  swc1      $f0, 0x38($s1)
/* 3198A0 802BD330 C7A20014 */  lwc1      $f2, 0x14($sp)
/* 3198A4 802BD334 C440000C */  lwc1      $f0, 0xc($v0)
/* 3198A8 802BD338 46001082 */  mul.s     $f2, $f2, $f0
/* 3198AC 802BD33C 00000000 */  nop
/* 3198B0 802BD340 C6400050 */  lwc1      $f0, 0x50($s2)
/* 3198B4 802BD344 46020001 */  sub.s     $f0, $f0, $f2
/* 3198B8 802BD348 E6200040 */  swc1      $f0, 0x40($s1)
/* 3198BC 802BD34C C4400010 */  lwc1      $f0, 0x10($v0)
/* 3198C0 802BD350 C44C0014 */  lwc1      $f12, 0x14($v0)
/* 3198C4 802BD354 0C00A6C9 */  jal       clamp_angle
/* 3198C8 802BD358 460C0301 */   sub.s    $f12, $f0, $f12
/* 3198CC 802BD35C 8E100000 */  lw        $s0, ($s0)
/* 3198D0 802BD360 3C0141A0 */  lui       $at, 0x41a0
/* 3198D4 802BD364 44811000 */  mtc1      $at, $f2
/* 3198D8 802BD368 C604000C */  lwc1      $f4, 0xc($s0)
/* 3198DC 802BD36C 4604103C */  c.lt.s    $f2, $f4
/* 3198E0 802BD370 00000000 */  nop
/* 3198E4 802BD374 45000005 */  bc1f      .L802BD38C
/* 3198E8 802BD378 E6000010 */   swc1     $f0, 0x10($s0)
/* 3198EC 802BD37C 3C013F80 */  lui       $at, 0x3f80
/* 3198F0 802BD380 44810000 */  mtc1      $at, $f0
/* 3198F4 802BD384 080AF4EE */  j         .L802BD3B8
/* 3198F8 802BD388 46002001 */   sub.s    $f0, $f4, $f0
.L802BD38C:
/* 3198FC 802BD38C 3C014198 */  lui       $at, 0x4198
/* 319900 802BD390 44810000 */  mtc1      $at, $f0
/* 319904 802BD394 00000000 */  nop
/* 319908 802BD398 4600203C */  c.lt.s    $f4, $f0
/* 31990C 802BD39C 00000000 */  nop
/* 319910 802BD3A0 45000006 */  bc1f      .L802BD3BC
/* 319914 802BD3A4 00000000 */   nop
/* 319918 802BD3A8 3C013F80 */  lui       $at, 0x3f80
/* 31991C 802BD3AC 44810000 */  mtc1      $at, $f0
/* 319920 802BD3B0 00000000 */  nop
/* 319924 802BD3B4 46002000 */  add.s     $f0, $f4, $f0
.L802BD3B8:
/* 319928 802BD3B8 E600000C */  swc1      $f0, 0xc($s0)
.L802BD3BC:
/* 31992C 802BD3BC 3C10802C */  lui       $s0, %hi(D_802BEAAC_31B01C)
/* 319930 802BD3C0 2610EAAC */  addiu     $s0, $s0, %lo(D_802BEAAC_31B01C)
/* 319934 802BD3C4 8E020000 */  lw        $v0, ($s0)
/* 319938 802BD3C8 3C0140C9 */  lui       $at, 0x40c9
/* 31993C 802BD3CC 34210FD0 */  ori       $at, $at, 0xfd0
/* 319940 802BD3D0 44810000 */  mtc1      $at, $f0
/* 319944 802BD3D4 C44C0018 */  lwc1      $f12, 0x18($v0)
/* 319948 802BD3D8 46006302 */  mul.s     $f12, $f12, $f0
/* 31994C 802BD3DC 00000000 */  nop
/* 319950 802BD3E0 3C0143B4 */  lui       $at, 0x43b4
/* 319954 802BD3E4 4481A000 */  mtc1      $at, $f20
/* 319958 802BD3E8 0C00A85B */  jal       sin_rad
/* 31995C 802BD3EC 46146303 */   div.s    $f12, $f12, $f20
/* 319960 802BD3F0 8E020000 */  lw        $v0, ($s0)
/* 319964 802BD3F4 3C014040 */  lui       $at, 0x4040
/* 319968 802BD3F8 44812000 */  mtc1      $at, $f4
/* 31996C 802BD3FC C4420018 */  lwc1      $f2, 0x18($v0)
/* 319970 802BD400 46041080 */  add.s     $f2, $f2, $f4
/* 319974 802BD404 3C014316 */  lui       $at, 0x4316
/* 319978 802BD408 44813000 */  mtc1      $at, $f6
/* 31997C 802BD40C 00000000 */  nop
/* 319980 802BD410 4602303C */  c.lt.s    $f6, $f2
/* 319984 802BD414 E4420018 */  swc1      $f2, 0x18($v0)
/* 319988 802BD418 46040082 */  mul.s     $f2, $f0, $f4
/* 31998C 802BD41C 00000000 */  nop
/* 319990 802BD420 45030001 */  bc1tl     .L802BD428
/* 319994 802BD424 E4460018 */   swc1     $f6, 0x18($v0)
.L802BD428:
/* 319998 802BD428 C620003C */  lwc1      $f0, 0x3c($s1)
/* 31999C 802BD42C 46020000 */  add.s     $f0, $f0, $f2
/* 3199A0 802BD430 8E020000 */  lw        $v0, ($s0)
/* 3199A4 802BD434 E620003C */  swc1      $f0, 0x3c($s1)
/* 3199A8 802BD438 C44C0010 */  lwc1      $f12, 0x10($v0)
/* 3199AC 802BD43C 0C00A6C9 */  jal       clamp_angle
/* 3199B0 802BD440 460CA301 */   sub.s    $f12, $f20, $f12
/* 3199B4 802BD444 8E020000 */  lw        $v0, ($s0)
/* 3199B8 802BD448 E6200034 */  swc1      $f0, 0x34($s1)
/* 3199BC 802BD44C C4400014 */  lwc1      $f0, 0x14($v0)
/* 3199C0 802BD450 3C01802C */  lui       $at, %hi(D_802BEB10_31B080)
/* 3199C4 802BD454 D422EB10 */  ldc1      $f2, %lo(D_802BEB10_31B080)($at)
/* 3199C8 802BD458 46000021 */  cvt.d.s   $f0, $f0
/* 3199CC 802BD45C 46220000 */  add.d     $f0, $f0, $f2
/* 3199D0 802BD460 3C014220 */  lui       $at, 0x4220
/* 3199D4 802BD464 44811000 */  mtc1      $at, $f2
/* 3199D8 802BD468 46200020 */  cvt.s.d   $f0, $f0
/* 3199DC 802BD46C 4600103C */  c.lt.s    $f2, $f0
/* 3199E0 802BD470 00000000 */  nop
/* 3199E4 802BD474 45000002 */  bc1f      .L802BD480
/* 3199E8 802BD478 E4400014 */   swc1     $f0, 0x14($v0)
/* 3199EC 802BD47C E4420014 */  swc1      $f2, 0x14($v0)
.L802BD480:
/* 3199F0 802BD480 8E030000 */  lw        $v1, ($s0)
/* 3199F4 802BD484 8C620000 */  lw        $v0, ($v1)
/* 3199F8 802BD488 2442FFFF */  addiu     $v0, $v0, -1
/* 3199FC 802BD48C 14400018 */  bnez      $v0, .L802BD4F0
/* 319A00 802BD490 AC620000 */   sw       $v0, ($v1)
/* 319A04 802BD494 8C620004 */  lw        $v0, 4($v1)
/* 319A08 802BD498 24420001 */  addiu     $v0, $v0, 1
/* 319A0C 802BD49C 080AF53C */  j         .L802BD4F0
/* 319A10 802BD4A0 AC620004 */   sw       $v0, 4($v1)
.L802BD4A4:
/* 319A14 802BD4A4 8C820008 */  lw        $v0, 8($a0)
/* 319A18 802BD4A8 AE220000 */  sw        $v0, ($s1)
/* 319A1C 802BD4AC 8C820004 */  lw        $v0, 4($a0)
/* 319A20 802BD4B0 2403001E */  addiu     $v1, $zero, 0x1e
/* 319A24 802BD4B4 AC830000 */  sw        $v1, ($a0)
/* 319A28 802BD4B8 24420001 */  addiu     $v0, $v0, 1
/* 319A2C 802BD4BC 080AF53C */  j         .L802BD4F0
/* 319A30 802BD4C0 AC820004 */   sw       $v0, 4($a0)
.L802BD4C4:
/* 319A34 802BD4C4 0C03B52E */  jal       partner_flying_update_player_tracking
/* 319A38 802BD4C8 0220202D */   daddu    $a0, $s1, $zero
/* 319A3C 802BD4CC 0C03B574 */  jal       partner_flying_update_motion
/* 319A40 802BD4D0 0220202D */   daddu    $a0, $s1, $zero
/* 319A44 802BD4D4 8E030000 */  lw        $v1, ($s0)
/* 319A48 802BD4D8 8C620000 */  lw        $v0, ($v1)
/* 319A4C 802BD4DC 2442FFFF */  addiu     $v0, $v0, -1
/* 319A50 802BD4E0 14400003 */  bnez      $v0, .L802BD4F0
/* 319A54 802BD4E4 AC620000 */   sw       $v0, ($v1)
/* 319A58 802BD4E8 AC600004 */  sw        $zero, 4($v1)
/* 319A5C 802BD4EC AE600000 */  sw        $zero, ($s3)
.L802BD4F0:
/* 319A60 802BD4F0 0000102D */  daddu     $v0, $zero, $zero
.L802BD4F4:
/* 319A64 802BD4F4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 319A68 802BD4F8 8FB30024 */  lw        $s3, 0x24($sp)
/* 319A6C 802BD4FC 8FB20020 */  lw        $s2, 0x20($sp)
/* 319A70 802BD500 8FB1001C */  lw        $s1, 0x1c($sp)
/* 319A74 802BD504 8FB00018 */  lw        $s0, 0x18($sp)
/* 319A78 802BD508 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 319A7C 802BD50C 03E00008 */  jr        $ra
/* 319A80 802BD510 27BD0038 */   addiu    $sp, $sp, 0x38
