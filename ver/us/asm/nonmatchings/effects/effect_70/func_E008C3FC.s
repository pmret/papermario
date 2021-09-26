.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008C3FC
/* 38E1FC E008C3FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 38E200 E008C400 AFBF0010 */  sw        $ra, 0x10($sp)
/* 38E204 E008C404 8C85000C */  lw        $a1, 0xc($a0)
/* 38E208 E008C408 8CA20024 */  lw        $v0, 0x24($a1)
/* 38E20C E008C40C 2442FFFF */  addiu     $v0, $v0, -1
/* 38E210 E008C410 ACA20024 */  sw        $v0, 0x24($a1)
/* 38E214 E008C414 8CA20028 */  lw        $v0, 0x28($a1)
/* 38E218 E008C418 8CA30024 */  lw        $v1, 0x24($a1)
/* 38E21C E008C41C 24420001 */  addiu     $v0, $v0, 1
/* 38E220 E008C420 04610005 */  bgez      $v1, .LE008C438
/* 38E224 E008C424 ACA20028 */   sw       $v0, 0x28($a1)
/* 38E228 E008C428 0C080128 */  jal       shim_remove_effect
/* 38E22C E008C42C 00000000 */   nop
/* 38E230 E008C430 080231AB */  j         .LE008C6AC
/* 38E234 E008C434 00000000 */   nop
.LE008C438:
/* 38E238 E008C438 8CA80000 */  lw        $t0, ($a1)
/* 38E23C E008C43C 24020008 */  addiu     $v0, $zero, 8
/* 38E240 E008C440 15020025 */  bne       $t0, $v0, .LE008C4D8
/* 38E244 E008C444 0060382D */   daddu    $a3, $v1, $zero
/* 38E248 E008C448 28E20006 */  slti      $v0, $a3, 6
/* 38E24C E008C44C 14400010 */  bnez      $v0, .LE008C490
/* 38E250 E008C450 240200FF */   addiu    $v0, $zero, 0xff
/* 38E254 E008C454 8CA3001C */  lw        $v1, 0x1c($a1)
/* 38E258 E008C458 3C01E009 */  lui       $at, %hi(D_E008CB60)
/* 38E25C E008C45C D420CB60 */  ldc1      $f0, %lo(D_E008CB60)($at)
/* 38E260 E008C460 00431023 */  subu      $v0, $v0, $v1
/* 38E264 E008C464 44821000 */  mtc1      $v0, $f2
/* 38E268 E008C468 00000000 */  nop
/* 38E26C E008C46C 468010A1 */  cvt.d.w   $f2, $f2
/* 38E270 E008C470 46201082 */  mul.d     $f2, $f2, $f0
/* 38E274 E008C474 00000000 */  nop
/* 38E278 E008C478 44830000 */  mtc1      $v1, $f0
/* 38E27C E008C47C 00000000 */  nop
/* 38E280 E008C480 46800021 */  cvt.d.w   $f0, $f0
/* 38E284 E008C484 46220000 */  add.d     $f0, $f0, $f2
/* 38E288 E008C488 4620040D */  trunc.w.d $f16, $f0
/* 38E28C E008C48C E4B0001C */  swc1      $f16, 0x1c($a1)
.LE008C490:
/* 38E290 E008C490 C4A00018 */  lwc1      $f0, 0x18($a1)
/* 38E294 E008C494 44871000 */  mtc1      $a3, $f2
/* 38E298 E008C498 00000000 */  nop
/* 38E29C E008C49C 468010A0 */  cvt.s.w   $f2, $f2
/* 38E2A0 E008C4A0 46020002 */  mul.s     $f0, $f0, $f2
/* 38E2A4 E008C4A4 00000000 */  nop
/* 38E2A8 E008C4A8 28E2000A */  slti      $v0, $a3, 0xa
/* 38E2AC E008C4AC C4A20020 */  lwc1      $f2, 0x20($a1)
/* 38E2B0 E008C4B0 468010A0 */  cvt.s.w   $f2, $f2
/* 38E2B4 E008C4B4 46020003 */  div.s     $f0, $f0, $f2
/* 38E2B8 E008C4B8 10400032 */  beqz      $v0, .LE008C584
/* 38E2BC E008C4BC E4A00014 */   swc1     $f0, 0x14($a1)
/* 38E2C0 E008C4C0 00071040 */  sll       $v0, $a3, 1
/* 38E2C4 E008C4C4 00471021 */  addu      $v0, $v0, $a3
/* 38E2C8 E008C4C8 000210C0 */  sll       $v0, $v0, 3
/* 38E2CC E008C4CC 00471021 */  addu      $v0, $v0, $a3
/* 38E2D0 E008C4D0 08023161 */  j         .LE008C584
/* 38E2D4 E008C4D4 ACA2001C */   sw       $v0, 0x1c($a1)
.LE008C4D8:
/* 38E2D8 E008C4D8 28E20006 */  slti      $v0, $a3, 6
/* 38E2DC E008C4DC 14400012 */  bnez      $v0, .LE008C528
/* 38E2E0 E008C4E0 28E2000A */   slti     $v0, $a3, 0xa
/* 38E2E4 E008C4E4 24020064 */  addiu     $v0, $zero, 0x64
/* 38E2E8 E008C4E8 8CA3001C */  lw        $v1, 0x1c($a1)
/* 38E2EC E008C4EC 3C01E009 */  lui       $at, %hi(D_E008CB68)
/* 38E2F0 E008C4F0 D420CB68 */  ldc1      $f0, %lo(D_E008CB68)($at)
/* 38E2F4 E008C4F4 00431023 */  subu      $v0, $v0, $v1
/* 38E2F8 E008C4F8 44821000 */  mtc1      $v0, $f2
/* 38E2FC E008C4FC 00000000 */  nop
/* 38E300 E008C500 468010A1 */  cvt.d.w   $f2, $f2
/* 38E304 E008C504 46201082 */  mul.d     $f2, $f2, $f0
/* 38E308 E008C508 00000000 */  nop
/* 38E30C E008C50C 44830000 */  mtc1      $v1, $f0
/* 38E310 E008C510 00000000 */  nop
/* 38E314 E008C514 46800021 */  cvt.d.w   $f0, $f0
/* 38E318 E008C518 46220000 */  add.d     $f0, $f0, $f2
/* 38E31C E008C51C 4620040D */  trunc.w.d $f16, $f0
/* 38E320 E008C520 E4B0001C */  swc1      $f16, 0x1c($a1)
/* 38E324 E008C524 28E2000A */  slti      $v0, $a3, 0xa
.LE008C528:
/* 38E328 E008C528 10400016 */  beqz      $v0, .LE008C584
/* 38E32C E008C52C 00000000 */   nop
/* 38E330 E008C530 3C01E009 */  lui       $at, %hi(D_E008CB70)
/* 38E334 E008C534 D420CB70 */  ldc1      $f0, %lo(D_E008CB70)($at)
/* 38E338 E008C538 C4A6001C */  lwc1      $f6, 0x1c($a1)
/* 38E33C E008C53C 468031A1 */  cvt.d.w   $f6, $f6
/* 38E340 E008C540 46203182 */  mul.d     $f6, $f6, $f0
/* 38E344 E008C544 00000000 */  nop
/* 38E348 E008C548 C4A00018 */  lwc1      $f0, 0x18($a1)
/* 38E34C E008C54C 46000000 */  add.s     $f0, $f0, $f0
/* 38E350 E008C550 C4A20014 */  lwc1      $f2, 0x14($a1)
/* 38E354 E008C554 46020001 */  sub.s     $f0, $f0, $f2
/* 38E358 E008C558 3C01E009 */  lui       $at, %hi(D_E008CB78)
/* 38E35C E008C55C D424CB78 */  ldc1      $f4, %lo(D_E008CB78)($at)
/* 38E360 E008C560 46000021 */  cvt.d.s   $f0, $f0
/* 38E364 E008C564 46240002 */  mul.d     $f0, $f0, $f4
/* 38E368 E008C568 00000000 */  nop
/* 38E36C E008C56C 460010A1 */  cvt.d.s   $f2, $f2
/* 38E370 E008C570 46201080 */  add.d     $f2, $f2, $f0
/* 38E374 E008C574 4620340D */  trunc.w.d $f16, $f6
/* 38E378 E008C578 E4B0001C */  swc1      $f16, 0x1c($a1)
/* 38E37C E008C57C 462010A0 */  cvt.s.d   $f2, $f2
/* 38E380 E008C580 E4A20014 */  swc1      $f2, 0x14($a1)
.LE008C584:
/* 38E384 E008C584 8CA20004 */  lw        $v0, 4($a1)
/* 38E388 E008C588 C4400028 */  lwc1      $f0, 0x28($v0)
/* 38E38C E008C58C E4A00008 */  swc1      $f0, 8($a1)
/* 38E390 E008C590 C440002C */  lwc1      $f0, 0x2c($v0)
/* 38E394 E008C594 E4A0000C */  swc1      $f0, 0xc($a1)
/* 38E398 E008C598 C4400030 */  lwc1      $f0, 0x30($v0)
/* 38E39C E008C59C 24060001 */  addiu     $a2, $zero, 1
/* 38E3A0 E008C5A0 E4A00010 */  swc1      $f0, 0x10($a1)
/* 38E3A4 E008C5A4 8C820008 */  lw        $v0, 8($a0)
/* 38E3A8 E008C5A8 00C2102A */  slt       $v0, $a2, $v0
/* 38E3AC E008C5AC 1040003F */  beqz      $v0, .LE008C6AC
/* 38E3B0 E008C5B0 24A50048 */   addiu    $a1, $a1, 0x48
/* 38E3B4 E008C5B4 240A0008 */  addiu     $t2, $zero, 8
/* 38E3B8 E008C5B8 28E9000A */  slti      $t1, $a3, 0xa
/* 38E3BC E008C5BC 24A30030 */  addiu     $v1, $a1, 0x30
/* 38E3C0 E008C5C0 3C014220 */  lui       $at, 0x4220
/* 38E3C4 E008C5C4 44817000 */  mtc1      $at, $f14
/* 38E3C8 E008C5C8 3C01E009 */  lui       $at, %hi(D_E008CB80)
/* 38E3CC E008C5CC D428CB80 */  ldc1      $f8, %lo(D_E008CB80)($at)
/* 38E3D0 E008C5D0 3C01C220 */  lui       $at, 0xc220
/* 38E3D4 E008C5D4 44816000 */  mtc1      $at, $f12
/* 38E3D8 E008C5D8 3C014120 */  lui       $at, 0x4120
/* 38E3DC E008C5DC 44815000 */  mtc1      $at, $f10
.LE008C5E0:
/* 38E3E0 E008C5E0 150A001C */  bne       $t0, $t2, .LE008C654
/* 38E3E4 E008C5E4 30C20001 */   andi     $v0, $a2, 1
/* 38E3E8 E008C5E8 10400004 */  beqz      $v0, .LE008C5FC
/* 38E3EC E008C5EC 00000000 */   nop
/* 38E3F0 E008C5F0 C460000C */  lwc1      $f0, 0xc($v1)
/* 38E3F4 E008C5F4 08023181 */  j         .LE008C604
/* 38E3F8 E008C5F8 46007081 */   sub.s    $f2, $f14, $f0
.LE008C5FC:
/* 38E3FC E008C5FC C460000C */  lwc1      $f0, 0xc($v1)
/* 38E400 E008C600 46006081 */  sub.s     $f2, $f12, $f0
.LE008C604:
/* 38E404 E008C604 460010A1 */  cvt.d.s   $f2, $f2
/* 38E408 E008C608 46281082 */  mul.d     $f2, $f2, $f8
/* 38E40C E008C60C 00000000 */  nop
/* 38E410 E008C610 46000021 */  cvt.d.s   $f0, $f0
/* 38E414 E008C614 46220000 */  add.d     $f0, $f0, $f2
/* 38E418 E008C618 46200020 */  cvt.s.d   $f0, $f0
/* 38E41C E008C61C E460000C */  swc1      $f0, 0xc($v1)
/* 38E420 E008C620 C466FFFC */  lwc1      $f6, -4($v1)
/* 38E424 E008C624 C4600008 */  lwc1      $f0, 8($v1)
/* 38E428 E008C628 C4640000 */  lwc1      $f4, ($v1)
/* 38E42C E008C62C 46003180 */  add.s     $f6, $f6, $f0
/* 38E430 E008C630 C460000C */  lwc1      $f0, 0xc($v1)
/* 38E434 E008C634 C4620004 */  lwc1      $f2, 4($v1)
/* 38E438 E008C638 46002100 */  add.s     $f4, $f4, $f0
/* 38E43C E008C63C C4600010 */  lwc1      $f0, 0x10($v1)
/* 38E440 E008C640 46001080 */  add.s     $f2, $f2, $f0
/* 38E444 E008C644 E466FFFC */  swc1      $f6, -4($v1)
/* 38E448 E008C648 E4640000 */  swc1      $f4, ($v1)
/* 38E44C E008C64C 080231A6 */  j         .LE008C698
/* 38E450 E008C650 E4620004 */   swc1     $f2, 4($v1)
.LE008C654:
/* 38E454 E008C654 1120000C */  beqz      $t1, .LE008C688
/* 38E458 E008C658 00000000 */   nop
/* 38E45C E008C65C C460000C */  lwc1      $f0, 0xc($v1)
/* 38E460 E008C660 44871000 */  mtc1      $a3, $f2
/* 38E464 E008C664 00000000 */  nop
/* 38E468 E008C668 468010A0 */  cvt.s.w   $f2, $f2
/* 38E46C E008C66C 46020002 */  mul.s     $f0, $f0, $f2
/* 38E470 E008C670 00000000 */  nop
/* 38E474 E008C674 C4620000 */  lwc1      $f2, ($v1)
/* 38E478 E008C678 460A0003 */  div.s     $f0, $f0, $f10
/* 38E47C E008C67C 46001080 */  add.s     $f2, $f2, $f0
/* 38E480 E008C680 080231A6 */  j         .LE008C698
/* 38E484 E008C684 E4620000 */   swc1     $f2, ($v1)
.LE008C688:
/* 38E488 E008C688 C4600000 */  lwc1      $f0, ($v1)
/* 38E48C E008C68C C462000C */  lwc1      $f2, 0xc($v1)
/* 38E490 E008C690 46020000 */  add.s     $f0, $f0, $f2
/* 38E494 E008C694 E4600000 */  swc1      $f0, ($v1)
.LE008C698:
/* 38E498 E008C698 24C60001 */  addiu     $a2, $a2, 1
/* 38E49C E008C69C 8C820008 */  lw        $v0, 8($a0)
/* 38E4A0 E008C6A0 00C2102A */  slt       $v0, $a2, $v0
/* 38E4A4 E008C6A4 1440FFCE */  bnez      $v0, .LE008C5E0
/* 38E4A8 E008C6A8 24630048 */   addiu    $v1, $v1, 0x48
.LE008C6AC:
/* 38E4AC E008C6AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 38E4B0 E008C6B0 03E00008 */  jr        $ra
/* 38E4B4 E008C6B4 27BD0018 */   addiu    $sp, $sp, 0x18
