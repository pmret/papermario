.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00BE3A4
/* 3BC304 E00BE3A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3BC308 E00BE3A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BC30C E00BE3AC F7B40018 */  sdc1      $f20, 0x18($sp)
/* 3BC310 E00BE3B0 8C850000 */  lw        $a1, ($a0)
/* 3BC314 E00BE3B4 8C83000C */  lw        $v1, 0xc($a0)
/* 3BC318 E00BE3B8 30A20010 */  andi      $v0, $a1, 0x10
/* 3BC31C E00BE3BC 8C660000 */  lw        $a2, ($v1)
/* 3BC320 E00BE3C0 10400005 */  beqz      $v0, .LE00BE3D8
/* 3BC324 E00BE3C4 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3BC328 E00BE3C8 00A21024 */  and       $v0, $a1, $v0
/* 3BC32C E00BE3CC AC820000 */  sw        $v0, ($a0)
/* 3BC330 E00BE3D0 24020010 */  addiu     $v0, $zero, 0x10
/* 3BC334 E00BE3D4 AC62001C */  sw        $v0, 0x1c($v1)
.LE00BE3D8:
/* 3BC338 E00BE3D8 8C65001C */  lw        $a1, 0x1c($v1)
/* 3BC33C E00BE3DC 28A203E8 */  slti      $v0, $a1, 0x3e8
/* 3BC340 E00BE3E0 10400002 */  beqz      $v0, .LE00BE3EC
/* 3BC344 E00BE3E4 24A2FFFF */   addiu    $v0, $a1, -1
/* 3BC348 E00BE3E8 AC62001C */  sw        $v0, 0x1c($v1)
.LE00BE3EC:
/* 3BC34C E00BE3EC 8C620020 */  lw        $v0, 0x20($v1)
/* 3BC350 E00BE3F0 8C65001C */  lw        $a1, 0x1c($v1)
/* 3BC354 E00BE3F4 24420001 */  addiu     $v0, $v0, 1
/* 3BC358 E00BE3F8 04A10005 */  bgez      $a1, .LE00BE410
/* 3BC35C E00BE3FC AC620020 */   sw       $v0, 0x20($v1)
/* 3BC360 E00BE400 0C080128 */  jal       func_E02004A0
/* 3BC364 E00BE404 00000000 */   nop      
/* 3BC368 E00BE408 0802F95A */  j         .LE00BE568
/* 3BC36C E00BE40C 00000000 */   nop      
.LE00BE410:
/* 3BC370 E00BE410 28A20004 */  slti      $v0, $a1, 4
/* 3BC374 E00BE414 10400002 */  beqz      $v0, .LE00BE420
/* 3BC378 E00BE418 00051180 */   sll      $v0, $a1, 6
/* 3BC37C E00BE41C AC620030 */  sw        $v0, 0x30($v1)
.LE00BE420:
/* 3BC380 E00BE420 8C820008 */  lw        $v0, 8($a0)
/* 3BC384 E00BE424 24050001 */  addiu     $a1, $zero, 1
/* 3BC388 E00BE428 00A2102A */  slt       $v0, $a1, $v0
/* 3BC38C E00BE42C 1040004E */  beqz      $v0, .LE00BE568
/* 3BC390 E00BE430 24630038 */   addiu    $v1, $v1, 0x38
/* 3BC394 E00BE434 24080002 */  addiu     $t0, $zero, 2
/* 3BC398 E00BE438 24070003 */  addiu     $a3, $zero, 3
/* 3BC39C E00BE43C 24630034 */  addiu     $v1, $v1, 0x34
/* 3BC3A0 E00BE440 3C01E00C */  lui       $at, %hi(D_E00BEB00)
/* 3BC3A4 E00BE444 D42AEB00 */  ldc1      $f10, %lo(D_E00BEB00)($at)
/* 3BC3A8 E00BE448 3C01E00C */  lui       $at, %hi(D_E00BEB08)
/* 3BC3AC E00BE44C D432EB08 */  ldc1      $f18, %lo(D_E00BEB08)($at)
/* 3BC3B0 E00BE450 3C01E00C */  lui       $at, %hi(D_E00BEB10)
/* 3BC3B4 E00BE454 D430EB10 */  ldc1      $f16, %lo(D_E00BEB10)($at)
/* 3BC3B8 E00BE458 3C01E00C */  lui       $at, %hi(D_E00BEB18)
/* 3BC3BC E00BE45C D42EEB18 */  ldc1      $f14, %lo(D_E00BEB18)($at)
/* 3BC3C0 E00BE460 3C01E00C */  lui       $at, %hi(D_E00BEB20)
/* 3BC3C4 E00BE464 D42CEB20 */  ldc1      $f12, %lo(D_E00BEB20)($at)
.LE00BE468:
/* 3BC3C8 E00BE468 C464FFFC */  lwc1      $f4, -4($v1)
/* 3BC3CC E00BE46C 46802121 */  cvt.d.w   $f4, $f4
/* 3BC3D0 E00BE470 462A2102 */  mul.d     $f4, $f4, $f10
/* 3BC3D4 E00BE474 00000000 */  nop       
/* 3BC3D8 E00BE478 C468FFD0 */  lwc1      $f8, -0x30($v1)
/* 3BC3DC E00BE47C C460FFDC */  lwc1      $f0, -0x24($v1)
/* 3BC3E0 E00BE480 C466FFD4 */  lwc1      $f6, -0x2c($v1)
/* 3BC3E4 E00BE484 46004200 */  add.s     $f8, $f8, $f0
/* 3BC3E8 E00BE488 C460FFE0 */  lwc1      $f0, -0x20($v1)
/* 3BC3EC E00BE48C C462FFD8 */  lwc1      $f2, -0x28($v1)
/* 3BC3F0 E00BE490 46003180 */  add.s     $f6, $f6, $f0
/* 3BC3F4 E00BE494 C460FFE4 */  lwc1      $f0, -0x1c($v1)
/* 3BC3F8 E00BE498 46001080 */  add.s     $f2, $f2, $f0
/* 3BC3FC E00BE49C E468FFD0 */  swc1      $f8, -0x30($v1)
/* 3BC400 E00BE4A0 E466FFD4 */  swc1      $f6, -0x2c($v1)
/* 3BC404 E00BE4A4 E462FFD8 */  swc1      $f2, -0x28($v1)
/* 3BC408 E00BE4A8 4620250D */  trunc.w.d $f20, $f4
/* 3BC40C E00BE4AC 14C80006 */  bne       $a2, $t0, .LE00BE4C8
/* 3BC410 E00BE4B0 E474FFFC */   swc1     $f20, -4($v1)
/* 3BC414 E00BE4B4 C460FFE0 */  lwc1      $f0, -0x20($v1)
/* 3BC418 E00BE4B8 46000021 */  cvt.d.s   $f0, $f0
/* 3BC41C E00BE4BC 46320000 */  add.d     $f0, $f0, $f18
/* 3BC420 E00BE4C0 46200020 */  cvt.s.d   $f0, $f0
/* 3BC424 E00BE4C4 E460FFE0 */  swc1      $f0, -0x20($v1)
.LE00BE4C8:
/* 3BC428 E00BE4C8 C464FFDC */  lwc1      $f4, -0x24($v1)
/* 3BC42C E00BE4CC 46002121 */  cvt.d.s   $f4, $f4
/* 3BC430 E00BE4D0 462A2102 */  mul.d     $f4, $f4, $f10
/* 3BC434 E00BE4D4 00000000 */  nop       
/* 3BC438 E00BE4D8 C462FFE4 */  lwc1      $f2, -0x1c($v1)
/* 3BC43C E00BE4DC 460010A1 */  cvt.d.s   $f2, $f2
/* 3BC440 E00BE4E0 462A1082 */  mul.d     $f2, $f2, $f10
/* 3BC444 E00BE4E4 00000000 */  nop       
/* 3BC448 E00BE4E8 C460FFE0 */  lwc1      $f0, -0x20($v1)
/* 3BC44C E00BE4EC 46000021 */  cvt.d.s   $f0, $f0
/* 3BC450 E00BE4F0 46300000 */  add.d     $f0, $f0, $f16
/* 3BC454 E00BE4F4 46200020 */  cvt.s.d   $f0, $f0
/* 3BC458 E00BE4F8 E460FFE0 */  swc1      $f0, -0x20($v1)
/* 3BC45C E00BE4FC 46000021 */  cvt.d.s   $f0, $f0
/* 3BC460 E00BE500 462A0002 */  mul.d     $f0, $f0, $f10
/* 3BC464 E00BE504 00000000 */  nop       
/* 3BC468 E00BE508 46202120 */  cvt.s.d   $f4, $f4
/* 3BC46C E00BE50C 462010A0 */  cvt.s.d   $f2, $f2
/* 3BC470 E00BE510 E464FFDC */  swc1      $f4, -0x24($v1)
/* 3BC474 E00BE514 E462FFE4 */  swc1      $f2, -0x1c($v1)
/* 3BC478 E00BE518 46200020 */  cvt.s.d   $f0, $f0
/* 3BC47C E00BE51C 14C70007 */  bne       $a2, $a3, .LE00BE53C
/* 3BC480 E00BE520 E460FFE0 */   swc1     $f0, -0x20($v1)
/* 3BC484 E00BE524 C4600000 */  lwc1      $f0, ($v1)
/* 3BC488 E00BE528 46000021 */  cvt.d.s   $f0, $f0
/* 3BC48C E00BE52C 462E0002 */  mul.d     $f0, $f0, $f14
/* 3BC490 E00BE530 00000000 */  nop       
/* 3BC494 E00BE534 0802F954 */  j         .LE00BE550
/* 3BC498 E00BE538 46200020 */   cvt.s.d  $f0, $f0
.LE00BE53C:
/* 3BC49C E00BE53C C4600000 */  lwc1      $f0, ($v1)
/* 3BC4A0 E00BE540 46000021 */  cvt.d.s   $f0, $f0
/* 3BC4A4 E00BE544 462C0002 */  mul.d     $f0, $f0, $f12
/* 3BC4A8 E00BE548 00000000 */  nop       
/* 3BC4AC E00BE54C 46200020 */  cvt.s.d   $f0, $f0
.LE00BE550:
/* 3BC4B0 E00BE550 E4600000 */  swc1      $f0, ($v1)
/* 3BC4B4 E00BE554 24A50001 */  addiu     $a1, $a1, 1
/* 3BC4B8 E00BE558 8C820008 */  lw        $v0, 8($a0)
/* 3BC4BC E00BE55C 00A2102A */  slt       $v0, $a1, $v0
/* 3BC4C0 E00BE560 1440FFC1 */  bnez      $v0, .LE00BE468
/* 3BC4C4 E00BE564 24630038 */   addiu    $v1, $v1, 0x38
.LE00BE568:
/* 3BC4C8 E00BE568 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BC4CC E00BE56C D7B40018 */  ldc1      $f20, 0x18($sp)
/* 3BC4D0 E00BE570 03E00008 */  jr        $ra
/* 3BC4D4 E00BE574 27BD0020 */   addiu    $sp, $sp, 0x20
