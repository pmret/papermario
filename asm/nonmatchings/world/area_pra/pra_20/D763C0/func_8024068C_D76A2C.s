.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D76A2C
/* D76A2C 8024068C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D76A30 80240690 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D76A34 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D76A38 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D76A3C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D76A40 802406A0 4480A000 */  mtc1      $zero, $f20
/* D76A44 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D76A48 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D76A4C 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D76A50 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D76A54 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D76A58 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D76A5C 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D76A60 802406C0 00031080 */  sll       $v0, $v1, 2
/* D76A64 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D76A68 802406C8 00021080 */  sll       $v0, $v0, 2
/* D76A6C 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D76A70 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D76A74 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D76A78 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D76A7C 802406DC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D76A80 802406E0 00220821 */  addu      $at, $at, $v0
/* D76A84 802406E4 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D76A88 802406E8 4406A000 */  mfc1      $a2, $f20
/* D76A8C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D76A90 802406F0 4405B000 */  mfc1      $a1, $f22
/* D76A94 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D76A98 802406F8 0C019EC8 */  jal       guRotateF
/* D76A9C 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D76AA0 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D76AA4 80240704 0C00A6C9 */  jal       clamp_angle
/* D76AA8 80240708 00000000 */   nop
/* D76AAC 8024070C 44050000 */  mfc1      $a1, $f0
/* D76AB0 80240710 4406A000 */  mfc1      $a2, $f20
/* D76AB4 80240714 4407A000 */  mfc1      $a3, $f20
/* D76AB8 80240718 3C013F80 */  lui       $at, 0x3f80
/* D76ABC 8024071C 4481C000 */  mtc1      $at, $f24
/* D76AC0 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D76AC4 80240724 0C019EC8 */  jal       guRotateF
/* D76AC8 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D76ACC 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D76AD0 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D76AD4 80240734 0C019D80 */  jal       guMtxCatF
/* D76AD8 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D76ADC 8024073C 4405B000 */  mfc1      $a1, $f22
/* D76AE0 80240740 4406A000 */  mfc1      $a2, $f20
/* D76AE4 80240744 4407C000 */  mfc1      $a3, $f24
/* D76AE8 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D76AEC 8024074C 0C019EC8 */  jal       guRotateF
/* D76AF0 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D76AF4 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D76AF8 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D76AFC 8024075C 0C019D80 */  jal       guMtxCatF
/* D76B00 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D76B04 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D76B08 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D76B0C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D76B10 80240770 4407C000 */  mfc1      $a3, $f24
/* D76B14 80240774 0C019EC8 */  jal       guRotateF
/* D76B18 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D76B1C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D76B20 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D76B24 80240784 0C019D80 */  jal       guMtxCatF
/* D76B28 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D76B2C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D76B30 80240790 3C013F36 */  lui       $at, 0x3f36
/* D76B34 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D76B38 80240798 44810000 */  mtc1      $at, $f0
/* D76B3C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D76B40 802407A0 44050000 */  mfc1      $a1, $f0
/* D76B44 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D76B48 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D76B4C 802407AC 0C019DF0 */  jal       guScaleF
/* D76B50 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D76B54 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D76B58 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D76B5C 802407BC 0C019D80 */  jal       guMtxCatF
/* D76B60 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D76B64 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D76B68 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D76B6C 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D76B70 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D76B74 802407D4 46000007 */  neg.s     $f0, $f0
/* D76B78 802407D8 44060000 */  mfc1      $a2, $f0
/* D76B7C 802407DC 0C019E40 */  jal       guTranslateF
/* D76B80 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D76B84 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D76B88 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D76B8C 802407EC 0C019D80 */  jal       guMtxCatF
/* D76B90 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D76B94 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D76B98 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D76B9C 802407FC 44810000 */  mtc1      $at, $f0
/* D76BA0 80240800 00000000 */  nop
/* D76BA4 80240804 4602003E */  c.le.s    $f0, $f2
/* D76BA8 80240808 00000000 */  nop
/* D76BAC 8024080C 4500000A */  bc1f      .L80240838
/* D76BB0 80240810 24040001 */   addiu    $a0, $zero, 1
/* D76BB4 80240814 3C014387 */  lui       $at, 0x4387
/* D76BB8 80240818 44810000 */  mtc1      $at, $f0
/* D76BBC 8024081C 00000000 */  nop
/* D76BC0 80240820 4600103C */  c.lt.s    $f2, $f0
/* D76BC4 80240824 00000000 */  nop
/* D76BC8 80240828 45000004 */  bc1f      .L8024083C
/* D76BCC 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D76BD0 80240830 3C041000 */  lui       $a0, 0x1000
/* D76BD4 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D76BD8 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D76BDC 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D76BE0 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D76BE4 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D76BE8 80240848 0C0B7710 */  jal       render_sprite
/* D76BEC 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D76BF0 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D76BF4 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D76BF8 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D76BFC 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D76C00 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D76C04 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D76C08 80240868 03E00008 */  jr        $ra
/* D76C0C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
