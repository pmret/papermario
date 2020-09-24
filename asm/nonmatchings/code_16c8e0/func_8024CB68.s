.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024CB68
/* 17B448 8024CB68 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 17B44C 8024CB6C AFB00030 */  sw        $s0, 0x30($sp)
/* 17B450 8024CB70 3C10800B */  lui       $s0, 0x800b
/* 17B454 8024CB74 261022D8 */  addiu     $s0, $s0, 0x22d8
/* 17B458 8024CB78 3C02802A */  lui       $v0, 0x802a
/* 17B45C 8024CB7C 9442F27C */  lhu       $v0, -0xd84($v0)
/* 17B460 8024CB80 3C04800E */  lui       $a0, 0x800e
/* 17B464 8024CB84 2484C070 */  addiu     $a0, $a0, -0x3f90
/* 17B468 8024CB88 AFBF0034 */  sw        $ra, 0x34($sp)
/* 17B46C 8024CB8C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 17B470 8024CB90 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 17B474 8024CB94 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 17B478 8024CB98 30430700 */  andi      $v1, $v0, 0x700
/* 17B47C 8024CB9C 304600FF */  andi      $a2, $v0, 0xff
/* 17B480 8024CBA0 24020100 */  addiu     $v0, $zero, 0x100
/* 17B484 8024CBA4 10620018 */  beq       $v1, $v0, .L8024CC08
/* 17B488 8024CBA8 28620101 */   slti     $v0, $v1, 0x101
/* 17B48C 8024CBAC 10400019 */  beqz      $v0, .L8024CC14
/* 17B490 8024CBB0 00061080 */   sll      $v0, $a2, 2
/* 17B494 8024CBB4 14600018 */  bnez      $v1, .L8024CC18
/* 17B498 8024CBB8 00821021 */   addu     $v0, $a0, $v0
/* 17B49C 8024CBBC 8C8400D8 */  lw        $a0, 0xd8($a0)
/* 17B4A0 8024CBC0 108000AF */  beqz      $a0, .L8024CE80
/* 17B4A4 8024CBC4 0000102D */   daddu    $v0, $zero, $zero
/* 17B4A8 8024CBC8 3C028011 */  lui       $v0, 0x8011
/* 17B4AC 8024CBCC 2442EFC8 */  addiu     $v0, $v0, -0x1038
/* 17B4B0 8024CBD0 C4940144 */  lwc1      $f20, 0x144($a0)
/* 17B4B4 8024CBD4 944200B0 */  lhu       $v0, 0xb0($v0)
/* 17B4B8 8024CBD8 C498014C */  lwc1      $f24, 0x14c($a0)
/* 17B4BC 8024CBDC C4820148 */  lwc1      $f2, 0x148($a0)
/* 17B4C0 8024CBE0 00021400 */  sll       $v0, $v0, 0x10
/* 17B4C4 8024CBE4 00021C03 */  sra       $v1, $v0, 0x10
/* 17B4C8 8024CBE8 000217C2 */  srl       $v0, $v0, 0x1f
/* 17B4CC 8024CBEC 00621821 */  addu      $v1, $v1, $v0
/* 17B4D0 8024CBF0 00031843 */  sra       $v1, $v1, 1
/* 17B4D4 8024CBF4 44830000 */  mtc1      $v1, $f0
/* 17B4D8 8024CBF8 00000000 */  nop       
/* 17B4DC 8024CBFC 46800020 */  cvt.s.w   $f0, $f0
/* 17B4E0 8024CC00 0809330C */  j         .L8024CC30
/* 17B4E4 8024CC04 46001580 */   add.s    $f22, $f2, $f0
.L8024CC08:
/* 17B4E8 8024CC08 8C8200DC */  lw        $v0, 0xdc($a0)
/* 17B4EC 8024CC0C 08093307 */  j         .L8024CC1C
/* 17B4F0 8024CC10 00000000 */   nop      
.L8024CC14:
/* 17B4F4 8024CC14 00821021 */  addu      $v0, $a0, $v0
.L8024CC18:
/* 17B4F8 8024CC18 8C4200E0 */  lw        $v0, 0xe0($v0)
.L8024CC1C:
/* 17B4FC 8024CC1C 50400098 */  beql      $v0, $zero, .L8024CE80
/* 17B500 8024CC20 0000102D */   daddu    $v0, $zero, $zero
/* 17B504 8024CC24 C4540144 */  lwc1      $f20, 0x144($v0)
/* 17B508 8024CC28 C4560148 */  lwc1      $f22, 0x148($v0)
/* 17B50C 8024CC2C C458014C */  lwc1      $f24, 0x14c($v0)
.L8024CC30:
/* 17B510 8024CC30 10A0001D */  beqz      $a1, .L8024CCA8
/* 17B514 8024CC34 27A20020 */   addiu    $v0, $sp, 0x20
/* 17B518 8024CC38 C6000054 */  lwc1      $f0, 0x54($s0)
/* 17B51C 8024CC3C C6020058 */  lwc1      $f2, 0x58($s0)
/* 17B520 8024CC40 C604005C */  lwc1      $f4, 0x5c($s0)
/* 17B524 8024CC44 8602001E */  lh        $v0, 0x1e($s0)
/* 17B528 8024CC48 86030022 */  lh        $v1, 0x22($s0)
/* 17B52C 8024CC4C 3C01802A */  lui       $at, 0x802a
/* 17B530 8024CC50 E420F270 */  swc1      $f0, -0xd90($at)
/* 17B534 8024CC54 44820000 */  mtc1      $v0, $f0
/* 17B538 8024CC58 00000000 */  nop       
/* 17B53C 8024CC5C 46800020 */  cvt.s.w   $f0, $f0
/* 17B540 8024CC60 86020024 */  lh        $v0, 0x24($s0)
/* 17B544 8024CC64 3C01802A */  lui       $at, 0x802a
/* 17B548 8024CC68 E422F274 */  swc1      $f2, -0xd8c($at)
/* 17B54C 8024CC6C 3C01802A */  lui       $at, 0x802a
/* 17B550 8024CC70 E424F278 */  swc1      $f4, -0xd88($at)
/* 17B554 8024CC74 3C01802A */  lui       $at, 0x802a
/* 17B558 8024CC78 E420F288 */  swc1      $f0, -0xd78($at)
/* 17B55C 8024CC7C 44820000 */  mtc1      $v0, $f0
/* 17B560 8024CC80 00000000 */  nop       
/* 17B564 8024CC84 46800020 */  cvt.s.w   $f0, $f0
/* 17B568 8024CC88 3C01802A */  lui       $at, 0x802a
/* 17B56C 8024CC8C E420F290 */  swc1      $f0, -0xd70($at)
/* 17B570 8024CC90 44830000 */  mtc1      $v1, $f0
/* 17B574 8024CC94 00000000 */  nop       
/* 17B578 8024CC98 46800020 */  cvt.s.w   $f0, $f0
/* 17B57C 8024CC9C 3C01802A */  lui       $at, 0x802a
/* 17B580 8024CCA0 E420F294 */  swc1      $f0, -0xd6c($at)
/* 17B584 8024CCA4 27A20020 */  addiu     $v0, $sp, 0x20
.L8024CCA8:
/* 17B588 8024CCA8 AFA20010 */  sw        $v0, 0x10($sp)
/* 17B58C 8024CCAC 27A20024 */  addiu     $v0, $sp, 0x24
/* 17B590 8024CCB0 AFA20014 */  sw        $v0, 0x14($sp)
/* 17B594 8024CCB4 27A20028 */  addiu     $v0, $sp, 0x28
/* 17B598 8024CCB8 4405A000 */  mfc1      $a1, $f20
/* 17B59C 8024CCBC 4406B000 */  mfc1      $a2, $f22
/* 17B5A0 8024CCC0 4407C000 */  mfc1      $a3, $f24
/* 17B5A4 8024CCC4 24040001 */  addiu     $a0, $zero, 1
/* 17B5A8 8024CCC8 0C00B94E */  jal       get_screen_coords
/* 17B5AC 8024CCCC AFA20018 */   sw       $v0, 0x18($sp)
/* 17B5B0 8024CCD0 8FA20024 */  lw        $v0, 0x24($sp)
/* 17B5B4 8024CCD4 28420064 */  slti      $v0, $v0, 0x64
/* 17B5B8 8024CCD8 10400005 */  beqz      $v0, .L8024CCF0
/* 17B5BC 8024CCDC 00000000 */   nop      
/* 17B5C0 8024CCE0 3C0141C8 */  lui       $at, 0x41c8
/* 17B5C4 8024CCE4 44810000 */  mtc1      $at, $f0
/* 17B5C8 8024CCE8 00000000 */  nop       
/* 17B5CC 8024CCEC 4600B580 */  add.s     $f22, $f22, $f0
.L8024CCF0:
/* 17B5D0 8024CCF0 3C01802A */  lui       $at, 0x802a
/* 17B5D4 8024CCF4 C420F274 */  lwc1      $f0, -0xd8c($at)
/* 17B5D8 8024CCF8 4600B03C */  c.lt.s    $f22, $f0
/* 17B5DC 8024CCFC 00000000 */  nop       
/* 17B5E0 8024CD00 45030001 */  bc1tl     .L8024CD08
/* 17B5E4 8024CD04 46000586 */   mov.s    $f22, $f0
.L8024CD08:
/* 17B5E8 8024CD08 8FA30020 */  lw        $v1, 0x20($sp)
/* 17B5EC 8024CD0C 28620064 */  slti      $v0, $v1, 0x64
/* 17B5F0 8024CD10 10400005 */  beqz      $v0, .L8024CD28
/* 17B5F4 8024CD14 00000000 */   nop      
/* 17B5F8 8024CD18 3C0141C8 */  lui       $at, 0x41c8
/* 17B5FC 8024CD1C 44810000 */  mtc1      $at, $f0
/* 17B600 8024CD20 00000000 */  nop       
/* 17B604 8024CD24 4600A501 */  sub.s     $f20, $f20, $f0
.L8024CD28:
/* 17B608 8024CD28 3C01802A */  lui       $at, 0x802a
/* 17B60C 8024CD2C C420F270 */  lwc1      $f0, -0xd90($at)
/* 17B610 8024CD30 4600A03C */  c.lt.s    $f20, $f0
/* 17B614 8024CD34 00000000 */  nop       
/* 17B618 8024CD38 45030001 */  bc1tl     .L8024CD40
/* 17B61C 8024CD3C 46000506 */   mov.s    $f20, $f0
.L8024CD40:
/* 17B620 8024CD40 286200DD */  slti      $v0, $v1, 0xdd
/* 17B624 8024CD44 14400005 */  bnez      $v0, .L8024CD5C
/* 17B628 8024CD48 00000000 */   nop      
/* 17B62C 8024CD4C 3C0141C8 */  lui       $at, 0x41c8
/* 17B630 8024CD50 44810000 */  mtc1      $at, $f0
/* 17B634 8024CD54 00000000 */  nop       
/* 17B638 8024CD58 4600A500 */  add.s     $f20, $f20, $f0
.L8024CD5C:
/* 17B63C 8024CD5C C6060054 */  lwc1      $f6, 0x54($s0)
/* 17B640 8024CD60 4606A101 */  sub.s     $f4, $f20, $f6
/* 17B644 8024CD64 3C01802A */  lui       $at, 0x802a
/* 17B648 8024CD68 D422CC30 */  ldc1      $f2, -0x33d0($at)
/* 17B64C 8024CD6C 46002005 */  abs.s     $f0, $f4
/* 17B650 8024CD70 46000021 */  cvt.d.s   $f0, $f0
/* 17B654 8024CD74 4622003C */  c.lt.d    $f0, $f2
/* 17B658 8024CD78 00000000 */  nop       
/* 17B65C 8024CD7C 45000009 */  bc1f      .L8024CDA4
/* 17B660 8024CD80 00000000 */   nop      
/* 17B664 8024CD84 44800000 */  mtc1      $zero, $f0
/* 17B668 8024CD88 00000000 */  nop       
/* 17B66C 8024CD8C 46002032 */  c.eq.s    $f4, $f0
/* 17B670 8024CD90 00000000 */  nop       
/* 17B674 8024CD94 45020009 */  bc1fl     .L8024CDBC
/* 17B678 8024CD98 E6140054 */   swc1     $f20, 0x54($s0)
/* 17B67C 8024CD9C 0809336F */  j         .L8024CDBC
/* 17B680 8024CDA0 00000000 */   nop      
.L8024CDA4:
/* 17B684 8024CDA4 3C0140A0 */  lui       $at, 0x40a0
/* 17B688 8024CDA8 44810000 */  mtc1      $at, $f0
/* 17B68C 8024CDAC 00000000 */  nop       
/* 17B690 8024CDB0 46002003 */  div.s     $f0, $f4, $f0
/* 17B694 8024CDB4 46003000 */  add.s     $f0, $f6, $f0
/* 17B698 8024CDB8 E6000054 */  swc1      $f0, 0x54($s0)
.L8024CDBC:
/* 17B69C 8024CDBC C6060058 */  lwc1      $f6, 0x58($s0)
/* 17B6A0 8024CDC0 4606B101 */  sub.s     $f4, $f22, $f6
/* 17B6A4 8024CDC4 3C01802A */  lui       $at, 0x802a
/* 17B6A8 8024CDC8 D422CC38 */  ldc1      $f2, -0x33c8($at)
/* 17B6AC 8024CDCC 46002005 */  abs.s     $f0, $f4
/* 17B6B0 8024CDD0 46000021 */  cvt.d.s   $f0, $f0
/* 17B6B4 8024CDD4 4622003C */  c.lt.d    $f0, $f2
/* 17B6B8 8024CDD8 00000000 */  nop       
/* 17B6BC 8024CDDC 45000009 */  bc1f      .L8024CE04
/* 17B6C0 8024CDE0 00000000 */   nop      
/* 17B6C4 8024CDE4 44800000 */  mtc1      $zero, $f0
/* 17B6C8 8024CDE8 00000000 */  nop       
/* 17B6CC 8024CDEC 46002032 */  c.eq.s    $f4, $f0
/* 17B6D0 8024CDF0 00000000 */  nop       
/* 17B6D4 8024CDF4 45020009 */  bc1fl     .L8024CE1C
/* 17B6D8 8024CDF8 E6160058 */   swc1     $f22, 0x58($s0)
/* 17B6DC 8024CDFC 08093387 */  j         .L8024CE1C
/* 17B6E0 8024CE00 00000000 */   nop      
.L8024CE04:
/* 17B6E4 8024CE04 3C0140A0 */  lui       $at, 0x40a0
/* 17B6E8 8024CE08 44810000 */  mtc1      $at, $f0
/* 17B6EC 8024CE0C 00000000 */  nop       
/* 17B6F0 8024CE10 46002003 */  div.s     $f0, $f4, $f0
/* 17B6F4 8024CE14 46003000 */  add.s     $f0, $f6, $f0
/* 17B6F8 8024CE18 E6000058 */  swc1      $f0, 0x58($s0)
.L8024CE1C:
/* 17B6FC 8024CE1C C606005C */  lwc1      $f6, 0x5c($s0)
/* 17B700 8024CE20 4606C101 */  sub.s     $f4, $f24, $f6
/* 17B704 8024CE24 3C01802A */  lui       $at, 0x802a
/* 17B708 8024CE28 D422CC40 */  ldc1      $f2, -0x33c0($at)
/* 17B70C 8024CE2C 46002005 */  abs.s     $f0, $f4
/* 17B710 8024CE30 46000021 */  cvt.d.s   $f0, $f0
/* 17B714 8024CE34 4622003C */  c.lt.d    $f0, $f2
/* 17B718 8024CE38 00000000 */  nop       
/* 17B71C 8024CE3C 45000009 */  bc1f      .L8024CE64
/* 17B720 8024CE40 00000000 */   nop      
/* 17B724 8024CE44 44800000 */  mtc1      $zero, $f0
/* 17B728 8024CE48 00000000 */  nop       
/* 17B72C 8024CE4C 46002032 */  c.eq.s    $f4, $f0
/* 17B730 8024CE50 00000000 */  nop       
/* 17B734 8024CE54 45020009 */  bc1fl     .L8024CE7C
/* 17B738 8024CE58 E618005C */   swc1     $f24, 0x5c($s0)
/* 17B73C 8024CE5C 080933A0 */  j         .L8024CE80
/* 17B740 8024CE60 0000102D */   daddu    $v0, $zero, $zero
.L8024CE64:
/* 17B744 8024CE64 3C0140A0 */  lui       $at, 0x40a0
/* 17B748 8024CE68 44810000 */  mtc1      $at, $f0
/* 17B74C 8024CE6C 00000000 */  nop       
/* 17B750 8024CE70 46002003 */  div.s     $f0, $f4, $f0
/* 17B754 8024CE74 46003000 */  add.s     $f0, $f6, $f0
/* 17B758 8024CE78 E600005C */  swc1      $f0, 0x5c($s0)
.L8024CE7C:
/* 17B75C 8024CE7C 0000102D */  daddu     $v0, $zero, $zero
.L8024CE80:
/* 17B760 8024CE80 8FBF0034 */  lw        $ra, 0x34($sp)
/* 17B764 8024CE84 8FB00030 */  lw        $s0, 0x30($sp)
/* 17B768 8024CE88 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 17B76C 8024CE8C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 17B770 8024CE90 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 17B774 8024CE94 03E00008 */  jr        $ra
/* 17B778 8024CE98 27BD0050 */   addiu    $sp, $sp, 0x50
