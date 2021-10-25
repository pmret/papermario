.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_54_update
/* 36E470 E006C2A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 36E474 E006C2A4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 36E478 E006C2A8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 36E47C E006C2AC AFB20018 */  sw        $s2, 0x18($sp)
/* 36E480 E006C2B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 36E484 E006C2B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 36E488 E006C2B8 8C830000 */  lw        $v1, ($a0)
/* 36E48C E006C2BC 8C90000C */  lw        $s0, 0xc($a0)
/* 36E490 E006C2C0 30620010 */  andi      $v0, $v1, 0x10
/* 36E494 E006C2C4 10400004 */  beqz      $v0, .LE006C2D8
/* 36E498 E006C2C8 2402FFEF */   addiu    $v0, $zero, -0x11
/* 36E49C E006C2CC 00621024 */  and       $v0, $v1, $v0
/* 36E4A0 E006C2D0 AC820000 */  sw        $v0, ($a0)
/* 36E4A4 E006C2D4 AE000014 */  sw        $zero, 0x14($s0)
.LE006C2D8:
/* 36E4A8 E006C2D8 8E030014 */  lw        $v1, 0x14($s0)
/* 36E4AC E006C2DC 8E120000 */  lw        $s2, ($s0)
/* 36E4B0 E006C2E0 28620064 */  slti      $v0, $v1, 0x64
/* 36E4B4 E006C2E4 10400002 */  beqz      $v0, .LE006C2F0
/* 36E4B8 E006C2E8 2462FFFF */   addiu    $v0, $v1, -1
/* 36E4BC E006C2EC AE020014 */  sw        $v0, 0x14($s0)
.LE006C2F0:
/* 36E4C0 E006C2F0 8E020018 */  lw        $v0, 0x18($s0)
/* 36E4C4 E006C2F4 8E050014 */  lw        $a1, 0x14($s0)
/* 36E4C8 E006C2F8 24420001 */  addiu     $v0, $v0, 1
/* 36E4CC E006C2FC 04A10010 */  bgez      $a1, .LE006C340
/* 36E4D0 E006C300 AE020018 */   sw       $v0, 0x18($s0)
/* 36E4D4 E006C304 0C080128 */  jal       shim_remove_effect
/* 36E4D8 E006C308 00000000 */   nop
/* 36E4DC E006C30C 8E040048 */  lw        $a0, 0x48($s0)
/* 36E4E0 E006C310 10800004 */  beqz      $a0, .LE006C324
/* 36E4E4 E006C314 00000000 */   nop
/* 36E4E8 E006C318 0C080128 */  jal       shim_remove_effect
/* 36E4EC E006C31C 00000000 */   nop
/* 36E4F0 E006C320 AE000048 */  sw        $zero, 0x48($s0)
.LE006C324:
/* 36E4F4 E006C324 8E040044 */  lw        $a0, 0x44($s0)
/* 36E4F8 E006C328 10800096 */  beqz      $a0, .LE006C584
/* 36E4FC E006C32C 00000000 */   nop
/* 36E500 E006C330 0C080128 */  jal       shim_remove_effect
/* 36E504 E006C334 00000000 */   nop
/* 36E508 E006C338 0801B161 */  j         .LE006C584
/* 36E50C E006C33C AE000044 */   sw       $zero, 0x44($s0)
.LE006C340:
/* 36E510 E006C340 00A0982D */  daddu     $s3, $a1, $zero
/* 36E514 E006C344 8E040044 */  lw        $a0, 0x44($s0)
/* 36E518 E006C348 10800007 */  beqz      $a0, .LE006C368
/* 36E51C E006C34C 0040882D */   daddu    $s1, $v0, $zero
/* 36E520 E006C350 2A220012 */  slti      $v0, $s1, 0x12
/* 36E524 E006C354 14400005 */  bnez      $v0, .LE006C36C
/* 36E528 E006C358 2A420003 */   slti     $v0, $s2, 3
/* 36E52C E006C35C 0C080128 */  jal       shim_remove_effect
/* 36E530 E006C360 00000000 */   nop
/* 36E534 E006C364 AE000044 */  sw        $zero, 0x44($s0)
.LE006C368:
/* 36E538 E006C368 2A420003 */  slti      $v0, $s2, 3
.LE006C36C:
/* 36E53C E006C36C 14400003 */  bnez      $v0, .LE006C37C
/* 36E540 E006C370 2A220007 */   slti     $v0, $s1, 7
/* 36E544 E006C374 10400074 */  beqz      $v0, .LE006C548
/* 36E548 E006C378 2A420003 */   slti     $v0, $s2, 3
.LE006C37C:
/* 36E54C E006C37C C600001C */  lwc1      $f0, 0x1c($s0)
/* 36E550 E006C380 C602002C */  lwc1      $f2, 0x2c($s0)
/* 36E554 E006C384 46020080 */  add.s     $f2, $f0, $f2
/* 36E558 E006C388 44800000 */  mtc1      $zero, $f0
/* 36E55C E006C38C 00000000 */  nop
/* 36E560 E006C390 4600103C */  c.lt.s    $f2, $f0
/* 36E564 E006C394 00000000 */  nop
/* 36E568 E006C398 45000005 */  bc1f      .LE006C3B0
/* 36E56C E006C39C E602001C */   swc1     $f2, 0x1c($s0)
/* 36E570 E006C3A0 3C014380 */  lui       $at, 0x4380
/* 36E574 E006C3A4 44810000 */  mtc1      $at, $f0
/* 36E578 E006C3A8 0801B0F4 */  j         .LE006C3D0
/* 36E57C E006C3AC 46001000 */   add.s    $f0, $f2, $f0
.LE006C3B0:
/* 36E580 E006C3B0 3C014380 */  lui       $at, 0x4380
/* 36E584 E006C3B4 44810000 */  mtc1      $at, $f0
/* 36E588 E006C3B8 00000000 */  nop
/* 36E58C E006C3BC 4602003C */  c.lt.s    $f0, $f2
/* 36E590 E006C3C0 00000000 */  nop
/* 36E594 E006C3C4 45000003 */  bc1f      .LE006C3D4
/* 36E598 E006C3C8 00000000 */   nop
/* 36E59C E006C3CC 46001001 */  sub.s     $f0, $f2, $f0
.LE006C3D0:
/* 36E5A0 E006C3D0 E600001C */  swc1      $f0, 0x1c($s0)
.LE006C3D4:
/* 36E5A4 E006C3D4 8E02003C */  lw        $v0, 0x3c($s0)
/* 36E5A8 E006C3D8 14400002 */  bnez      $v0, .LE006C3E4
/* 36E5AC E006C3DC 0222001A */   div      $zero, $s1, $v0
/* 36E5B0 E006C3E0 0007000D */  break     7
.LE006C3E4:
/* 36E5B4 E006C3E4 2401FFFF */   addiu    $at, $zero, -1
/* 36E5B8 E006C3E8 14410004 */  bne       $v0, $at, .LE006C3FC
/* 36E5BC E006C3EC 3C018000 */   lui      $at, 0x8000
/* 36E5C0 E006C3F0 16210002 */  bne       $s1, $at, .LE006C3FC
/* 36E5C4 E006C3F4 00000000 */   nop
/* 36E5C8 E006C3F8 0006000D */  break     6
.LE006C3FC:
/* 36E5CC E006C3FC 00001810 */   mfhi     $v1
/* 36E5D0 E006C400 14600017 */  bnez      $v1, .LE006C460
/* 36E5D4 E006C404 00000000 */   nop
/* 36E5D8 E006C408 C6000020 */  lwc1      $f0, 0x20($s0)
/* 36E5DC E006C40C C6020030 */  lwc1      $f2, 0x30($s0)
/* 36E5E0 E006C410 46020080 */  add.s     $f2, $f0, $f2
/* 36E5E4 E006C414 44800000 */  mtc1      $zero, $f0
/* 36E5E8 E006C418 00000000 */  nop
/* 36E5EC E006C41C 4600103C */  c.lt.s    $f2, $f0
/* 36E5F0 E006C420 00000000 */  nop
/* 36E5F4 E006C424 45000005 */  bc1f      .LE006C43C
/* 36E5F8 E006C428 E6020020 */   swc1     $f2, 0x20($s0)
/* 36E5FC E006C42C 3C014280 */  lui       $at, 0x4280
/* 36E600 E006C430 44810000 */  mtc1      $at, $f0
/* 36E604 E006C434 0801B117 */  j         .LE006C45C
/* 36E608 E006C438 46001000 */   add.s    $f0, $f2, $f0
.LE006C43C:
/* 36E60C E006C43C 3C014280 */  lui       $at, 0x4280
/* 36E610 E006C440 44810000 */  mtc1      $at, $f0
/* 36E614 E006C444 00000000 */  nop
/* 36E618 E006C448 4602003C */  c.lt.s    $f0, $f2
/* 36E61C E006C44C 00000000 */  nop
/* 36E620 E006C450 45000003 */  bc1f      .LE006C460
/* 36E624 E006C454 00000000 */   nop
/* 36E628 E006C458 46001001 */  sub.s     $f0, $f2, $f0
.LE006C45C:
/* 36E62C E006C45C E6000020 */  swc1      $f0, 0x20($s0)
.LE006C460:
/* 36E630 E006C460 8E020040 */  lw        $v0, 0x40($s0)
/* 36E634 E006C464 14400002 */  bnez      $v0, .LE006C470
/* 36E638 E006C468 0222001A */   div      $zero, $s1, $v0
/* 36E63C E006C46C 0007000D */  break     7
.LE006C470:
/* 36E640 E006C470 2401FFFF */   addiu    $at, $zero, -1
/* 36E644 E006C474 14410004 */  bne       $v0, $at, .LE006C488
/* 36E648 E006C478 3C018000 */   lui      $at, 0x8000
/* 36E64C E006C47C 16210002 */  bne       $s1, $at, .LE006C488
/* 36E650 E006C480 00000000 */   nop
/* 36E654 E006C484 0006000D */  break     6
.LE006C488:
/* 36E658 E006C488 00001810 */   mfhi     $v1
/* 36E65C E006C48C 14600017 */  bnez      $v1, .LE006C4EC
/* 36E660 E006C490 00000000 */   nop
/* 36E664 E006C494 C6000024 */  lwc1      $f0, 0x24($s0)
/* 36E668 E006C498 C6020034 */  lwc1      $f2, 0x34($s0)
/* 36E66C E006C49C 46020080 */  add.s     $f2, $f0, $f2
/* 36E670 E006C4A0 44800000 */  mtc1      $zero, $f0
/* 36E674 E006C4A4 00000000 */  nop
/* 36E678 E006C4A8 4600103C */  c.lt.s    $f2, $f0
/* 36E67C E006C4AC 00000000 */  nop
/* 36E680 E006C4B0 45000005 */  bc1f      .LE006C4C8
/* 36E684 E006C4B4 E6020024 */   swc1     $f2, 0x24($s0)
/* 36E688 E006C4B8 3C014380 */  lui       $at, 0x4380
/* 36E68C E006C4BC 44810000 */  mtc1      $at, $f0
/* 36E690 E006C4C0 0801B13A */  j         .LE006C4E8
/* 36E694 E006C4C4 46001000 */   add.s    $f0, $f2, $f0
.LE006C4C8:
/* 36E698 E006C4C8 3C014380 */  lui       $at, 0x4380
/* 36E69C E006C4CC 44810000 */  mtc1      $at, $f0
/* 36E6A0 E006C4D0 00000000 */  nop
/* 36E6A4 E006C4D4 4602003C */  c.lt.s    $f0, $f2
/* 36E6A8 E006C4D8 00000000 */  nop
/* 36E6AC E006C4DC 45000003 */  bc1f      .LE006C4EC
/* 36E6B0 E006C4E0 00000000 */   nop
/* 36E6B4 E006C4E4 46001001 */  sub.s     $f0, $f2, $f0
.LE006C4E8:
/* 36E6B8 E006C4E8 E6000024 */  swc1      $f0, 0x24($s0)
.LE006C4EC:
/* 36E6BC E006C4EC C6000028 */  lwc1      $f0, 0x28($s0)
/* 36E6C0 E006C4F0 C6020038 */  lwc1      $f2, 0x38($s0)
/* 36E6C4 E006C4F4 46020080 */  add.s     $f2, $f0, $f2
/* 36E6C8 E006C4F8 44800000 */  mtc1      $zero, $f0
/* 36E6CC E006C4FC 00000000 */  nop
/* 36E6D0 E006C500 4600103C */  c.lt.s    $f2, $f0
/* 36E6D4 E006C504 00000000 */  nop
/* 36E6D8 E006C508 45000005 */  bc1f      .LE006C520
/* 36E6DC E006C50C E6020028 */   swc1     $f2, 0x28($s0)
/* 36E6E0 E006C510 3C014280 */  lui       $at, 0x4280
/* 36E6E4 E006C514 44810000 */  mtc1      $at, $f0
/* 36E6E8 E006C518 0801B150 */  j         .LE006C540
/* 36E6EC E006C51C 46001000 */   add.s    $f0, $f2, $f0
.LE006C520:
/* 36E6F0 E006C520 3C014280 */  lui       $at, 0x4280
/* 36E6F4 E006C524 44810000 */  mtc1      $at, $f0
/* 36E6F8 E006C528 00000000 */  nop
/* 36E6FC E006C52C 4602003C */  c.lt.s    $f0, $f2
/* 36E700 E006C530 00000000 */  nop
/* 36E704 E006C534 45000004 */  bc1f      .LE006C548
/* 36E708 E006C538 2A420003 */   slti     $v0, $s2, 3
/* 36E70C E006C53C 46001001 */  sub.s     $f0, $f2, $f0
.LE006C540:
/* 36E710 E006C540 E6000028 */  swc1      $f0, 0x28($s0)
/* 36E714 E006C544 2A420003 */  slti      $v0, $s2, 3
.LE006C548:
/* 36E718 E006C548 14400007 */  bnez      $v0, .LE006C568
/* 36E71C E006C54C 2A62000A */   slti     $v0, $s3, 0xa
/* 36E720 E006C550 2A220007 */  slti      $v0, $s1, 7
/* 36E724 E006C554 1440000B */  bnez      $v0, .LE006C584
/* 36E728 E006C558 00000000 */   nop
/* 36E72C E006C55C 8E020010 */  lw        $v0, 0x10($s0)
/* 36E730 E006C560 0801B15E */  j         .LE006C578
/* 36E734 E006C564 2442FFF3 */   addiu    $v0, $v0, -0xd
.LE006C568:
/* 36E738 E006C568 10400006 */  beqz      $v0, .LE006C584
/* 36E73C E006C56C 00000000 */   nop
/* 36E740 E006C570 8E020010 */  lw        $v0, 0x10($s0)
/* 36E744 E006C574 2442FFE7 */  addiu     $v0, $v0, -0x19
.LE006C578:
/* 36E748 E006C578 04410002 */  bgez      $v0, .LE006C584
/* 36E74C E006C57C AE020010 */   sw       $v0, 0x10($s0)
/* 36E750 E006C580 AE000010 */  sw        $zero, 0x10($s0)
.LE006C584:
/* 36E754 E006C584 8FBF0020 */  lw        $ra, 0x20($sp)
/* 36E758 E006C588 8FB3001C */  lw        $s3, 0x1c($sp)
/* 36E75C E006C58C 8FB20018 */  lw        $s2, 0x18($sp)
/* 36E760 E006C590 8FB10014 */  lw        $s1, 0x14($sp)
/* 36E764 E006C594 8FB00010 */  lw        $s0, 0x10($sp)
/* 36E768 E006C598 03E00008 */  jr        $ra
/* 36E76C E006C59C 27BD0028 */   addiu    $sp, $sp, 0x28
