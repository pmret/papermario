.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003E400
/* 352840 E003E400 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 352844 E003E404 AFBF0010 */  sw        $ra, 0x10($sp)
/* 352848 E003E408 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 35284C E003E40C F7B40018 */  sdc1      $f20, 0x18($sp)
/* 352850 E003E410 8C83000C */  lw        $v1, 0xc($a0)
/* 352854 E003E414 8C62006C */  lw        $v0, 0x6c($v1)
/* 352858 E003E418 2442FFFF */  addiu     $v0, $v0, -1
/* 35285C E003E41C AC62006C */  sw        $v0, 0x6c($v1)
/* 352860 E003E420 8C620070 */  lw        $v0, 0x70($v1)
/* 352864 E003E424 8C65006C */  lw        $a1, 0x6c($v1)
/* 352868 E003E428 24420001 */  addiu     $v0, $v0, 1
/* 35286C E003E42C 04A10005 */  bgez      $a1, .LE003E444
/* 352870 E003E430 AC620070 */   sw       $v0, 0x70($v1)
/* 352874 E003E434 0C080128 */  jal       shim_remove_effect
/* 352878 E003E438 00000000 */   nop
/* 35287C E003E43C 0800F978 */  j         .LE003E5E0
/* 352880 E003E440 00000000 */   nop
.LE003E444:
/* 352884 E003E444 8C820008 */  lw        $v0, 8($a0)
/* 352888 E003E448 18400065 */  blez      $v0, .LE003E5E0
/* 35288C E003E44C 0000302D */   daddu    $a2, $zero, $zero
/* 352890 E003E450 28A80006 */  slti      $t0, $a1, 6
/* 352894 E003E454 240900FF */  addiu     $t1, $zero, 0xff
/* 352898 E003E458 28A70005 */  slti      $a3, $a1, 5
/* 35289C E003E45C 24650064 */  addiu     $a1, $v1, 0x64
/* 3528A0 E003E460 3C01E004 */  lui       $at, %hi(D_E003E878)
/* 3528A4 E003E464 D434E878 */  ldc1      $f20, %lo(D_E003E878)($at)
/* 3528A8 E003E468 3C01E004 */  lui       $at, %hi(D_E003E880)
/* 3528AC E003E46C D42EE880 */  ldc1      $f14, %lo(D_E003E880)($at)
/* 3528B0 E003E470 3C01E004 */  lui       $at, %hi(D_E003E888)
/* 3528B4 E003E474 D432E888 */  ldc1      $f18, %lo(D_E003E888)($at)
/* 3528B8 E003E478 3C01E004 */  lui       $at, %hi(D_E003E890)
/* 3528BC E003E47C D42CE890 */  ldc1      $f12, %lo(D_E003E890)($at)
/* 3528C0 E003E480 3C01E004 */  lui       $at, %hi(D_E003E898)
/* 3528C4 E003E484 D430E898 */  ldc1      $f16, %lo(D_E003E898)($at)
.LE003E488:
/* 3528C8 E003E488 15000020 */  bnez      $t0, .LE003E50C
/* 3528CC E003E48C 00000000 */   nop
/* 3528D0 E003E490 C4A2FFAC */  lwc1      $f2, -0x54($a1)
/* 3528D4 E003E494 460010A1 */  cvt.d.s   $f2, $f2
/* 3528D8 E003E498 462E1082 */  mul.d     $f2, $f2, $f14
/* 3528DC E003E49C 00000000 */  nop
/* 3528E0 E003E4A0 C4A0FFB0 */  lwc1      $f0, -0x50($a1)
/* 3528E4 E003E4A4 46000021 */  cvt.d.s   $f0, $f0
/* 3528E8 E003E4A8 462E0002 */  mul.d     $f0, $f0, $f14
/* 3528EC E003E4AC 00000000 */  nop
/* 3528F0 E003E4B0 C4A4FFB4 */  lwc1      $f4, -0x4c($a1)
/* 3528F4 E003E4B4 46002121 */  cvt.d.s   $f4, $f4
/* 3528F8 E003E4B8 462E2102 */  mul.d     $f4, $f4, $f14
/* 3528FC E003E4BC 00000000 */  nop
/* 352900 E003E4C0 8CA30004 */  lw        $v1, 4($a1)
/* 352904 E003E4C4 01231023 */  subu      $v0, $t1, $v1
/* 352908 E003E4C8 44823000 */  mtc1      $v0, $f6
/* 35290C E003E4CC 00000000 */  nop
/* 352910 E003E4D0 468031A1 */  cvt.d.w   $f6, $f6
/* 352914 E003E4D4 46343182 */  mul.d     $f6, $f6, $f20
/* 352918 E003E4D8 00000000 */  nop
/* 35291C E003E4DC 462010A0 */  cvt.s.d   $f2, $f2
/* 352920 E003E4E0 46200020 */  cvt.s.d   $f0, $f0
/* 352924 E003E4E4 E4A0FFB0 */  swc1      $f0, -0x50($a1)
/* 352928 E003E4E8 44830000 */  mtc1      $v1, $f0
/* 35292C E003E4EC 00000000 */  nop
/* 352930 E003E4F0 46800021 */  cvt.d.w   $f0, $f0
/* 352934 E003E4F4 46202120 */  cvt.s.d   $f4, $f4
/* 352938 E003E4F8 46260000 */  add.d     $f0, $f0, $f6
/* 35293C E003E4FC E4A2FFAC */  swc1      $f2, -0x54($a1)
/* 352940 E003E500 E4A4FFB4 */  swc1      $f4, -0x4c($a1)
/* 352944 E003E504 4620058D */  trunc.w.d $f22, $f0
/* 352948 E003E508 E4B60004 */  swc1      $f22, 4($a1)
.LE003E50C:
/* 35294C E003E50C 10E00019 */  beqz      $a3, .LE003E574
/* 352950 E003E510 00000000 */   nop
/* 352954 E003E514 C4A60004 */  lwc1      $f6, 4($a1)
/* 352958 E003E518 468031A1 */  cvt.d.w   $f6, $f6
/* 35295C E003E51C 46323182 */  mul.d     $f6, $f6, $f18
/* 352960 E003E520 00000000 */  nop
/* 352964 E003E524 C4A4FFAC */  lwc1      $f4, -0x54($a1)
/* 352968 E003E528 46002121 */  cvt.d.s   $f4, $f4
/* 35296C E003E52C 462C2102 */  mul.d     $f4, $f4, $f12
/* 352970 E003E530 00000000 */  nop
/* 352974 E003E534 C4A2FFB0 */  lwc1      $f2, -0x50($a1)
/* 352978 E003E538 460010A1 */  cvt.d.s   $f2, $f2
/* 35297C E003E53C 462C1082 */  mul.d     $f2, $f2, $f12
/* 352980 E003E540 00000000 */  nop
/* 352984 E003E544 C4A0FFB4 */  lwc1      $f0, -0x4c($a1)
/* 352988 E003E548 46000021 */  cvt.d.s   $f0, $f0
/* 35298C E003E54C 462C0002 */  mul.d     $f0, $f0, $f12
/* 352990 E003E550 00000000 */  nop
/* 352994 E003E554 4620358D */  trunc.w.d $f22, $f6
/* 352998 E003E558 E4B60004 */  swc1      $f22, 4($a1)
/* 35299C E003E55C 46202120 */  cvt.s.d   $f4, $f4
/* 3529A0 E003E560 462010A0 */  cvt.s.d   $f2, $f2
/* 3529A4 E003E564 46200020 */  cvt.s.d   $f0, $f0
/* 3529A8 E003E568 E4A4FFAC */  swc1      $f4, -0x54($a1)
/* 3529AC E003E56C E4A2FFB0 */  swc1      $f2, -0x50($a1)
/* 3529B0 E003E570 E4A0FFB4 */  swc1      $f0, -0x4c($a1)
.LE003E574:
/* 3529B4 E003E574 C4A20000 */  lwc1      $f2, ($a1)
/* 3529B8 E003E578 460010A1 */  cvt.d.s   $f2, $f2
/* 3529BC E003E57C 46301082 */  mul.d     $f2, $f2, $f16
/* 3529C0 E003E580 00000000 */  nop
/* 3529C4 E003E584 C4AAFFA0 */  lwc1      $f10, -0x60($a1)
/* 3529C8 E003E588 C4A0FFAC */  lwc1      $f0, -0x54($a1)
/* 3529CC E003E58C C4A8FFA4 */  lwc1      $f8, -0x5c($a1)
/* 3529D0 E003E590 46005280 */  add.s     $f10, $f10, $f0
/* 3529D4 E003E594 C4A0FFB0 */  lwc1      $f0, -0x50($a1)
/* 3529D8 E003E598 C4A4FFA8 */  lwc1      $f4, -0x58($a1)
/* 3529DC E003E59C 46004200 */  add.s     $f8, $f8, $f0
/* 3529E0 E003E5A0 C4A0FFB4 */  lwc1      $f0, -0x4c($a1)
/* 3529E4 E003E5A4 C4A6FFFC */  lwc1      $f6, -4($a1)
/* 3529E8 E003E5A8 46002100 */  add.s     $f4, $f4, $f0
/* 3529EC E003E5AC C4A0FFF8 */  lwc1      $f0, -8($a1)
/* 3529F0 E003E5B0 24C60001 */  addiu     $a2, $a2, 1
/* 3529F4 E003E5B4 E4AAFFA0 */  swc1      $f10, -0x60($a1)
/* 3529F8 E003E5B8 46060000 */  add.s     $f0, $f0, $f6
/* 3529FC E003E5BC E4A8FFA4 */  swc1      $f8, -0x5c($a1)
/* 352A00 E003E5C0 E4A4FFA8 */  swc1      $f4, -0x58($a1)
/* 352A04 E003E5C4 E4A0FFF8 */  swc1      $f0, -8($a1)
/* 352A08 E003E5C8 462010A0 */  cvt.s.d   $f2, $f2
/* 352A0C E003E5CC E4A20000 */  swc1      $f2, ($a1)
/* 352A10 E003E5D0 8C820008 */  lw        $v0, 8($a0)
/* 352A14 E003E5D4 00C2102A */  slt       $v0, $a2, $v0
/* 352A18 E003E5D8 1440FFAB */  bnez      $v0, .LE003E488
/* 352A1C E003E5DC 24A5007C */   addiu    $a1, $a1, 0x7c
.LE003E5E0:
/* 352A20 E003E5E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 352A24 E003E5E4 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 352A28 E003E5E8 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 352A2C E003E5EC 03E00008 */  jr        $ra
/* 352A30 E003E5F0 27BD0028 */   addiu    $sp, $sp, 0x28
