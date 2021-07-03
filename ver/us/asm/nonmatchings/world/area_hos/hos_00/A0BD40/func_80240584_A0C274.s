.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244B50_A10840
.double 1.570796

.section .text

glabel func_80240584_A0C274
/* A0C274 80240584 27BDFF90 */  addiu     $sp, $sp, -0x70
/* A0C278 80240588 AFB10034 */  sw        $s1, 0x34($sp)
/* A0C27C 8024058C 0080882D */  daddu     $s1, $a0, $zero
/* A0C280 80240590 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* A0C284 80240594 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* A0C288 80240598 3C014334 */  lui       $at, 0x4334
/* A0C28C 8024059C 44811000 */  mtc1      $at, $f2
/* A0C290 802405A0 3C014049 */  lui       $at, 0x4049
/* A0C294 802405A4 34210FD8 */  ori       $at, $at, 0xfd8
/* A0C298 802405A8 44812000 */  mtc1      $at, $f4
/* A0C29C 802405AC 24040096 */  addiu     $a0, $zero, 0x96
/* A0C2A0 802405B0 AFBF0038 */  sw        $ra, 0x38($sp)
/* A0C2A4 802405B4 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* A0C2A8 802405B8 46020003 */  div.s     $f0, $f0, $f2
/* A0C2AC 802405BC 46040782 */  mul.s     $f30, $f0, $f4
/* A0C2B0 802405C0 00000000 */  nop
/* A0C2B4 802405C4 AFB00030 */  sw        $s0, 0x30($sp)
/* A0C2B8 802405C8 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* A0C2BC 802405CC F7BA0058 */  sdc1      $f26, 0x58($sp)
/* A0C2C0 802405D0 3C018024 */  lui       $at, %hi(D_80244B50_A10840)
/* A0C2C4 802405D4 D4224B50 */  ldc1      $f2, %lo(D_80244B50_A10840)($at)
/* A0C2C8 802405D8 4600F021 */  cvt.d.s   $f0, $f30
/* A0C2CC 802405DC 46220100 */  add.d     $f4, $f0, $f2
/* A0C2D0 802405E0 F7B80050 */  sdc1      $f24, 0x50($sp)
/* A0C2D4 802405E4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A0C2D8 802405E8 46220001 */  sub.d     $f0, $f0, $f2
/* A0C2DC 802405EC F7B40040 */  sdc1      $f20, 0x40($sp)
/* A0C2E0 802405F0 46202120 */  cvt.s.d   $f4, $f4
/* A0C2E4 802405F4 46200020 */  cvt.s.d   $f0, $f0
/* A0C2E8 802405F8 E7A40020 */  swc1      $f4, 0x20($sp)
/* A0C2EC 802405FC 0C00A67F */  jal       rand_int
/* A0C2F0 80240600 E7A00024 */   swc1     $f0, 0x24($sp)
/* A0C2F4 80240604 24040096 */  addiu     $a0, $zero, 0x96
/* A0C2F8 80240608 44823000 */  mtc1      $v0, $f6
/* A0C2FC 8024060C 00000000 */  nop
/* A0C300 80240610 468031A0 */  cvt.s.w   $f6, $f6
/* A0C304 80240614 0C00A67F */  jal       rand_int
/* A0C308 80240618 E7A60028 */   swc1     $f6, 0x28($sp)
/* A0C30C 8024061C 24040064 */  addiu     $a0, $zero, 0x64
/* A0C310 80240620 44823000 */  mtc1      $v0, $f6
/* A0C314 80240624 00000000 */  nop
/* A0C318 80240628 468031A0 */  cvt.s.w   $f6, $f6
/* A0C31C 8024062C 0C00A67F */  jal       rand_int
/* A0C320 80240630 E7A6002C */   swc1     $f6, 0x2c($sp)
/* A0C324 80240634 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A0C328 80240638 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A0C32C 8024063C 2442FFCE */  addiu     $v0, $v0, -0x32
/* A0C330 80240640 C6000030 */  lwc1      $f0, 0x30($s0)
/* A0C334 80240644 3C014348 */  lui       $at, 0x4348
/* A0C338 80240648 4481B000 */  mtc1      $at, $f22
/* A0C33C 8024064C 4482A000 */  mtc1      $v0, $f20
/* A0C340 80240650 00000000 */  nop
/* A0C344 80240654 4680A520 */  cvt.s.w   $f20, $f20
/* A0C348 80240658 4616003C */  c.lt.s    $f0, $f22
/* A0C34C 8024065C 00000000 */  nop
/* A0C350 80240660 4501004A */  bc1t      .L8024078C
/* A0C354 80240664 24020002 */   addiu    $v0, $zero, 2
/* A0C358 80240668 0C00A85B */  jal       sin_rad
/* A0C35C 8024066C 4600F306 */   mov.s    $f12, $f30
/* A0C360 80240670 4600A002 */  mul.s     $f0, $f20, $f0
/* A0C364 80240674 00000000 */  nop
/* A0C368 80240678 C61A0028 */  lwc1      $f26, 0x28($s0)
/* A0C36C 8024067C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* A0C370 80240680 0C00A85B */  jal       sin_rad
/* A0C374 80240684 4600D681 */   sub.s    $f26, $f26, $f0
/* A0C378 80240688 C7A60028 */  lwc1      $f6, 0x28($sp)
/* A0C37C 8024068C 46003002 */  mul.s     $f0, $f6, $f0
/* A0C380 80240690 00000000 */  nop
/* A0C384 80240694 C61C002C */  lwc1      $f28, 0x2c($s0)
/* A0C388 80240698 4616E700 */  add.s     $f28, $f28, $f22
/* A0C38C 8024069C 4600D680 */  add.s     $f26, $f26, $f0
/* A0C390 802406A0 0C00A874 */  jal       cos_rad
/* A0C394 802406A4 4600F306 */   mov.s    $f12, $f30
/* A0C398 802406A8 4600A002 */  mul.s     $f0, $f20, $f0
/* A0C39C 802406AC 00000000 */  nop
/* A0C3A0 802406B0 C6180030 */  lwc1      $f24, 0x30($s0)
/* A0C3A4 802406B4 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* A0C3A8 802406B8 0C00A874 */  jal       cos_rad
/* A0C3AC 802406BC 4600C600 */   add.s    $f24, $f24, $f0
/* A0C3B0 802406C0 C7A60028 */  lwc1      $f6, 0x28($sp)
/* A0C3B4 802406C4 46003002 */  mul.s     $f0, $f6, $f0
/* A0C3B8 802406C8 00000000 */  nop
/* A0C3BC 802406CC 4600C601 */  sub.s     $f24, $f24, $f0
/* A0C3C0 802406D0 4600D18D */  trunc.w.s $f6, $f26
/* A0C3C4 802406D4 E6260088 */  swc1      $f6, 0x88($s1)
/* A0C3C8 802406D8 4600E18D */  trunc.w.s $f6, $f28
/* A0C3CC 802406DC E626008C */  swc1      $f6, 0x8c($s1)
/* A0C3D0 802406E0 4600C18D */  trunc.w.s $f6, $f24
/* A0C3D4 802406E4 E6260090 */  swc1      $f6, 0x90($s1)
/* A0C3D8 802406E8 0C00A85B */  jal       sin_rad
/* A0C3DC 802406EC 4600F306 */   mov.s    $f12, $f30
/* A0C3E0 802406F0 4600A002 */  mul.s     $f0, $f20, $f0
/* A0C3E4 802406F4 00000000 */  nop
/* A0C3E8 802406F8 C6160028 */  lwc1      $f22, 0x28($s0)
/* A0C3EC 802406FC C7AC0024 */  lwc1      $f12, 0x24($sp)
/* A0C3F0 80240700 0C00A85B */  jal       sin_rad
/* A0C3F4 80240704 4600B581 */   sub.s    $f22, $f22, $f0
/* A0C3F8 80240708 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* A0C3FC 8024070C 46003002 */  mul.s     $f0, $f6, $f0
/* A0C400 80240710 00000000 */  nop
/* A0C404 80240714 4600F306 */  mov.s     $f12, $f30
/* A0C408 80240718 C61E002C */  lwc1      $f30, 0x2c($s0)
/* A0C40C 8024071C 0C00A874 */  jal       cos_rad
/* A0C410 80240720 4600B580 */   add.s    $f22, $f22, $f0
/* A0C414 80240724 4600A002 */  mul.s     $f0, $f20, $f0
/* A0C418 80240728 00000000 */  nop
/* A0C41C 8024072C C6140030 */  lwc1      $f20, 0x30($s0)
/* A0C420 80240730 C7AC0024 */  lwc1      $f12, 0x24($sp)
/* A0C424 80240734 0C00A874 */  jal       cos_rad
/* A0C428 80240738 4600A500 */   add.s    $f20, $f20, $f0
/* A0C42C 8024073C C7A6002C */  lwc1      $f6, 0x2c($sp)
/* A0C430 80240740 46003002 */  mul.s     $f0, $f6, $f0
/* A0C434 80240744 00000000 */  nop
/* A0C438 80240748 24040004 */  addiu     $a0, $zero, 4
/* A0C43C 8024074C 0C00A67F */  jal       rand_int
/* A0C440 80240750 4600A501 */   sub.s    $f20, $f20, $f0
/* A0C444 80240754 24040002 */  addiu     $a0, $zero, 2
/* A0C448 80240758 2442000A */  addiu     $v0, $v0, 0xa
/* A0C44C 8024075C 4405D000 */  mfc1      $a1, $f26
/* A0C450 80240760 4406E000 */  mfc1      $a2, $f28
/* A0C454 80240764 4407C000 */  mfc1      $a3, $f24
/* A0C458 80240768 44820000 */  mtc1      $v0, $f0
/* A0C45C 8024076C 00000000 */  nop
/* A0C460 80240770 46800020 */  cvt.s.w   $f0, $f0
/* A0C464 80240774 E7B60010 */  swc1      $f22, 0x10($sp)
/* A0C468 80240778 E7BE0014 */  swc1      $f30, 0x14($sp)
/* A0C46C 8024077C E7A0001C */  swc1      $f0, 0x1c($sp)
/* A0C470 80240780 0C01BF8C */  jal       playFX_0F
/* A0C474 80240784 E7B40018 */   swc1     $f20, 0x18($sp)
/* A0C478 80240788 24020002 */  addiu     $v0, $zero, 2
.L8024078C:
/* A0C47C 8024078C 8FBF0038 */  lw        $ra, 0x38($sp)
/* A0C480 80240790 8FB10034 */  lw        $s1, 0x34($sp)
/* A0C484 80240794 8FB00030 */  lw        $s0, 0x30($sp)
/* A0C488 80240798 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* A0C48C 8024079C D7BC0060 */  ldc1      $f28, 0x60($sp)
/* A0C490 802407A0 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* A0C494 802407A4 D7B80050 */  ldc1      $f24, 0x50($sp)
/* A0C498 802407A8 D7B60048 */  ldc1      $f22, 0x48($sp)
/* A0C49C 802407AC D7B40040 */  ldc1      $f20, 0x40($sp)
/* A0C4A0 802407B0 03E00008 */  jr        $ra
/* A0C4A4 802407B4 27BD0070 */   addiu    $sp, $sp, 0x70
/* A0C4A8 802407B8 00000000 */  nop
/* A0C4AC 802407BC 00000000 */  nop
