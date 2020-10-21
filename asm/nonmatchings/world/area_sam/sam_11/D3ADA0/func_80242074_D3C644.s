.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242074_D3C644
/* D3C644 80242074 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D3C648 80242078 AFB20038 */  sw        $s2, 0x38($sp)
/* D3C64C 8024207C 0080902D */  daddu     $s2, $a0, $zero
/* D3C650 80242080 AFBF003C */  sw        $ra, 0x3c($sp)
/* D3C654 80242084 AFB10034 */  sw        $s1, 0x34($sp)
/* D3C658 80242088 AFB00030 */  sw        $s0, 0x30($sp)
/* D3C65C 8024208C F7B40040 */  sdc1      $f20, 0x40($sp)
/* D3C660 80242090 8E51000C */  lw        $s1, 0xc($s2)
/* D3C664 80242094 0C00EAD2 */  jal       get_npc_safe
/* D3C668 80242098 2404FFFC */   addiu    $a0, $zero, -4
/* D3C66C 8024209C 2410FFFF */  addiu     $s0, $zero, -1
/* D3C670 802420A0 3C038016 */  lui       $v1, 0x8016
/* D3C674 802420A4 8463A568 */  lh        $v1, -0x5a98($v1)
/* D3C678 802420A8 04600025 */  bltz      $v1, .L80242140
/* D3C67C 802420AC 0040202D */   daddu    $a0, $v0, $zero
/* D3C680 802420B0 3C014130 */  lui       $at, 0x4130
/* D3C684 802420B4 44812000 */  mtc1      $at, $f4
/* D3C688 802420B8 C4800038 */  lwc1      $f0, 0x38($a0)
/* D3C68C 802420BC 3C014140 */  lui       $at, 0x4140
/* D3C690 802420C0 4481A000 */  mtc1      $at, $f20
/* D3C694 802420C4 27A2002C */  addiu     $v0, $sp, 0x2c
/* D3C698 802420C8 E7A4002C */  swc1      $f4, 0x2c($sp)
/* D3C69C 802420CC E7A00020 */  swc1      $f0, 0x20($sp)
/* D3C6A0 802420D0 C480003C */  lwc1      $f0, 0x3c($a0)
/* D3C6A4 802420D4 C4820040 */  lwc1      $f2, 0x40($a0)
/* D3C6A8 802420D8 46040000 */  add.s     $f0, $f0, $f4
/* D3C6AC 802420DC E7B4002C */  swc1      $f20, 0x2c($sp)
/* D3C6B0 802420E0 E7A20028 */  swc1      $f2, 0x28($sp)
/* D3C6B4 802420E4 E7A00024 */  swc1      $f0, 0x24($sp)
/* D3C6B8 802420E8 AFA20010 */  sw        $v0, 0x10($sp)
/* D3C6BC 802420EC C480000C */  lwc1      $f0, 0xc($a0)
/* D3C6C0 802420F0 27A50020 */  addiu     $a1, $sp, 0x20
/* D3C6C4 802420F4 E7A00014 */  swc1      $f0, 0x14($sp)
/* D3C6C8 802420F8 848200A6 */  lh        $v0, 0xa6($a0)
/* D3C6CC 802420FC 27A60024 */  addiu     $a2, $sp, 0x24
/* D3C6D0 80242100 44820000 */  mtc1      $v0, $f0
/* D3C6D4 80242104 00000000 */  nop       
/* D3C6D8 80242108 46800020 */  cvt.s.w   $f0, $f0
/* D3C6DC 8024210C E7A00018 */  swc1      $f0, 0x18($sp)
/* D3C6E0 80242110 8C840080 */  lw        $a0, 0x80($a0)
/* D3C6E4 80242114 0C0371DE */  jal       func_800DC778
/* D3C6E8 80242118 27A70028 */   addiu    $a3, $sp, 0x28
/* D3C6EC 8024211C 10400009 */  beqz      $v0, .L80242144
/* D3C6F0 80242120 0240202D */   daddu    $a0, $s2, $zero
/* D3C6F4 80242124 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* D3C6F8 80242128 4614003E */  c.le.s    $f0, $f20
/* D3C6FC 8024212C 00000000 */  nop       
/* D3C700 80242130 45000004 */  bc1f      .L80242144
/* D3C704 80242134 00000000 */   nop      
/* D3C708 80242138 3C108011 */  lui       $s0, 0x8011
/* D3C70C 8024213C 8E10C978 */  lw        $s0, -0x3688($s0)
.L80242140:
/* D3C710 80242140 0240202D */  daddu     $a0, $s2, $zero
.L80242144:
/* D3C714 80242144 8E250000 */  lw        $a1, ($s1)
/* D3C718 80242148 0C0B2026 */  jal       set_variable
/* D3C71C 8024214C 0200302D */   daddu    $a2, $s0, $zero
/* D3C720 80242150 8FBF003C */  lw        $ra, 0x3c($sp)
/* D3C724 80242154 8FB20038 */  lw        $s2, 0x38($sp)
/* D3C728 80242158 8FB10034 */  lw        $s1, 0x34($sp)
/* D3C72C 8024215C 8FB00030 */  lw        $s0, 0x30($sp)
/* D3C730 80242160 D7B40040 */  ldc1      $f20, 0x40($sp)
/* D3C734 80242164 24020002 */  addiu     $v0, $zero, 2
/* D3C738 80242168 03E00008 */  jr        $ra
/* D3C73C 8024216C 27BD0048 */   addiu    $sp, $sp, 0x48
