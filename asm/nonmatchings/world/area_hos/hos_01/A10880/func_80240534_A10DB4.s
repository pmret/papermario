.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240534_A10DB4
/* A10DB4 80240534 27BDFF90 */  addiu     $sp, $sp, -0x70
/* A10DB8 80240538 AFB10034 */  sw        $s1, 0x34($sp)
/* A10DBC 8024053C 0080882D */  daddu     $s1, $a0, $zero
/* A10DC0 80240540 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* A10DC4 80240544 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* A10DC8 80240548 3C014334 */  lui       $at, 0x4334
/* A10DCC 8024054C 44811000 */  mtc1      $at, $f2
/* A10DD0 80240550 3C014049 */  lui       $at, 0x4049
/* A10DD4 80240554 34210FD8 */  ori       $at, $at, 0xfd8
/* A10DD8 80240558 44812000 */  mtc1      $at, $f4
/* A10DDC 8024055C 24040096 */  addiu     $a0, $zero, 0x96
/* A10DE0 80240560 AFBF0038 */  sw        $ra, 0x38($sp)
/* A10DE4 80240564 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* A10DE8 80240568 46020003 */  div.s     $f0, $f0, $f2
/* A10DEC 8024056C 46040782 */  mul.s     $f30, $f0, $f4
/* A10DF0 80240570 00000000 */  nop
/* A10DF4 80240574 AFB00030 */  sw        $s0, 0x30($sp)
/* A10DF8 80240578 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* A10DFC 8024057C F7BA0058 */  sdc1      $f26, 0x58($sp)
/* A10E00 80240580 3C018024 */  lui       $at, %hi(pause_stats_draw_contents)
/* A10E04 80240584 D4225980 */  ldc1      $f2, %lo(pause_stats_draw_contents)($at)
/* A10E08 80240588 4600F021 */  cvt.d.s   $f0, $f30
/* A10E0C 8024058C 46220100 */  add.d     $f4, $f0, $f2
/* A10E10 80240590 F7B80050 */  sdc1      $f24, 0x50($sp)
/* A10E14 80240594 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A10E18 80240598 46220001 */  sub.d     $f0, $f0, $f2
/* A10E1C 8024059C F7B40040 */  sdc1      $f20, 0x40($sp)
/* A10E20 802405A0 46202120 */  cvt.s.d   $f4, $f4
/* A10E24 802405A4 46200020 */  cvt.s.d   $f0, $f0
/* A10E28 802405A8 E7A40020 */  swc1      $f4, 0x20($sp)
/* A10E2C 802405AC 0C00A67F */  jal       rand_int
/* A10E30 802405B0 E7A00024 */   swc1     $f0, 0x24($sp)
/* A10E34 802405B4 24040096 */  addiu     $a0, $zero, 0x96
/* A10E38 802405B8 44823000 */  mtc1      $v0, $f6
/* A10E3C 802405BC 00000000 */  nop
/* A10E40 802405C0 468031A0 */  cvt.s.w   $f6, $f6
/* A10E44 802405C4 0C00A67F */  jal       rand_int
/* A10E48 802405C8 E7A60028 */   swc1     $f6, 0x28($sp)
/* A10E4C 802405CC 24040064 */  addiu     $a0, $zero, 0x64
/* A10E50 802405D0 44823000 */  mtc1      $v0, $f6
/* A10E54 802405D4 00000000 */  nop
/* A10E58 802405D8 468031A0 */  cvt.s.w   $f6, $f6
/* A10E5C 802405DC 0C00A67F */  jal       rand_int
/* A10E60 802405E0 E7A6002C */   swc1     $f6, 0x2c($sp)
/* A10E64 802405E4 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A10E68 802405E8 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A10E6C 802405EC 2442FFCE */  addiu     $v0, $v0, -0x32
/* A10E70 802405F0 C6000030 */  lwc1      $f0, 0x30($s0)
/* A10E74 802405F4 3C014348 */  lui       $at, 0x4348
/* A10E78 802405F8 4481B000 */  mtc1      $at, $f22
/* A10E7C 802405FC 4482A000 */  mtc1      $v0, $f20
/* A10E80 80240600 00000000 */  nop
/* A10E84 80240604 4680A520 */  cvt.s.w   $f20, $f20
/* A10E88 80240608 4616003C */  c.lt.s    $f0, $f22
/* A10E8C 8024060C 00000000 */  nop
/* A10E90 80240610 4501004A */  bc1t      .L8024073C
/* A10E94 80240614 24020002 */   addiu    $v0, $zero, 2
/* A10E98 80240618 0C00A85B */  jal       sin_rad
/* A10E9C 8024061C 4600F306 */   mov.s    $f12, $f30
/* A10EA0 80240620 4600A002 */  mul.s     $f0, $f20, $f0
/* A10EA4 80240624 00000000 */  nop
/* A10EA8 80240628 C61A0028 */  lwc1      $f26, 0x28($s0)
/* A10EAC 8024062C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* A10EB0 80240630 0C00A85B */  jal       sin_rad
/* A10EB4 80240634 4600D681 */   sub.s    $f26, $f26, $f0
/* A10EB8 80240638 C7A60028 */  lwc1      $f6, 0x28($sp)
/* A10EBC 8024063C 46003002 */  mul.s     $f0, $f6, $f0
/* A10EC0 80240640 00000000 */  nop
/* A10EC4 80240644 C61C002C */  lwc1      $f28, 0x2c($s0)
/* A10EC8 80240648 4616E700 */  add.s     $f28, $f28, $f22
/* A10ECC 8024064C 4600D680 */  add.s     $f26, $f26, $f0
/* A10ED0 80240650 0C00A874 */  jal       cos_rad
/* A10ED4 80240654 4600F306 */   mov.s    $f12, $f30
/* A10ED8 80240658 4600A002 */  mul.s     $f0, $f20, $f0
/* A10EDC 8024065C 00000000 */  nop
/* A10EE0 80240660 C6180030 */  lwc1      $f24, 0x30($s0)
/* A10EE4 80240664 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* A10EE8 80240668 0C00A874 */  jal       cos_rad
/* A10EEC 8024066C 4600C600 */   add.s    $f24, $f24, $f0
/* A10EF0 80240670 C7A60028 */  lwc1      $f6, 0x28($sp)
/* A10EF4 80240674 46003002 */  mul.s     $f0, $f6, $f0
/* A10EF8 80240678 00000000 */  nop
/* A10EFC 8024067C 4600C601 */  sub.s     $f24, $f24, $f0
/* A10F00 80240680 4600D18D */  trunc.w.s $f6, $f26
/* A10F04 80240684 E6260088 */  swc1      $f6, 0x88($s1)
/* A10F08 80240688 4600E18D */  trunc.w.s $f6, $f28
/* A10F0C 8024068C E626008C */  swc1      $f6, 0x8c($s1)
/* A10F10 80240690 4600C18D */  trunc.w.s $f6, $f24
/* A10F14 80240694 E6260090 */  swc1      $f6, 0x90($s1)
/* A10F18 80240698 0C00A85B */  jal       sin_rad
/* A10F1C 8024069C 4600F306 */   mov.s    $f12, $f30
/* A10F20 802406A0 4600A002 */  mul.s     $f0, $f20, $f0
/* A10F24 802406A4 00000000 */  nop
/* A10F28 802406A8 C6160028 */  lwc1      $f22, 0x28($s0)
/* A10F2C 802406AC C7AC0024 */  lwc1      $f12, 0x24($sp)
/* A10F30 802406B0 0C00A85B */  jal       sin_rad
/* A10F34 802406B4 4600B581 */   sub.s    $f22, $f22, $f0
/* A10F38 802406B8 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* A10F3C 802406BC 46003002 */  mul.s     $f0, $f6, $f0
/* A10F40 802406C0 00000000 */  nop
/* A10F44 802406C4 4600F306 */  mov.s     $f12, $f30
/* A10F48 802406C8 C61E002C */  lwc1      $f30, 0x2c($s0)
/* A10F4C 802406CC 0C00A874 */  jal       cos_rad
/* A10F50 802406D0 4600B580 */   add.s    $f22, $f22, $f0
/* A10F54 802406D4 4600A002 */  mul.s     $f0, $f20, $f0
/* A10F58 802406D8 00000000 */  nop
/* A10F5C 802406DC C6140030 */  lwc1      $f20, 0x30($s0)
/* A10F60 802406E0 C7AC0024 */  lwc1      $f12, 0x24($sp)
/* A10F64 802406E4 0C00A874 */  jal       cos_rad
/* A10F68 802406E8 4600A500 */   add.s    $f20, $f20, $f0
/* A10F6C 802406EC C7A6002C */  lwc1      $f6, 0x2c($sp)
/* A10F70 802406F0 46003002 */  mul.s     $f0, $f6, $f0
/* A10F74 802406F4 00000000 */  nop
/* A10F78 802406F8 24040004 */  addiu     $a0, $zero, 4
/* A10F7C 802406FC 0C00A67F */  jal       rand_int
/* A10F80 80240700 4600A501 */   sub.s    $f20, $f20, $f0
/* A10F84 80240704 24040002 */  addiu     $a0, $zero, 2
/* A10F88 80240708 2442000A */  addiu     $v0, $v0, 0xa
/* A10F8C 8024070C 4405D000 */  mfc1      $a1, $f26
/* A10F90 80240710 4406E000 */  mfc1      $a2, $f28
/* A10F94 80240714 4407C000 */  mfc1      $a3, $f24
/* A10F98 80240718 44820000 */  mtc1      $v0, $f0
/* A10F9C 8024071C 00000000 */  nop
/* A10FA0 80240720 46800020 */  cvt.s.w   $f0, $f0
/* A10FA4 80240724 E7B60010 */  swc1      $f22, 0x10($sp)
/* A10FA8 80240728 E7BE0014 */  swc1      $f30, 0x14($sp)
/* A10FAC 8024072C E7A0001C */  swc1      $f0, 0x1c($sp)
/* A10FB0 80240730 0C01BF8C */  jal       func_8006FE30
/* A10FB4 80240734 E7B40018 */   swc1     $f20, 0x18($sp)
/* A10FB8 80240738 24020002 */  addiu     $v0, $zero, 2
.L8024073C:
/* A10FBC 8024073C 8FBF0038 */  lw        $ra, 0x38($sp)
/* A10FC0 80240740 8FB10034 */  lw        $s1, 0x34($sp)
/* A10FC4 80240744 8FB00030 */  lw        $s0, 0x30($sp)
/* A10FC8 80240748 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* A10FCC 8024074C D7BC0060 */  ldc1      $f28, 0x60($sp)
/* A10FD0 80240750 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* A10FD4 80240754 D7B80050 */  ldc1      $f24, 0x50($sp)
/* A10FD8 80240758 D7B60048 */  ldc1      $f22, 0x48($sp)
/* A10FDC 8024075C D7B40040 */  ldc1      $f20, 0x40($sp)
/* A10FE0 80240760 03E00008 */  jr        $ra
/* A10FE4 80240764 27BD0070 */   addiu    $sp, $sp, 0x70
