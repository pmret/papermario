.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D8D8DC
/* D8D8DC 8024068C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D8D8E0 80240690 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D8D8E4 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D8D8E8 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D8D8EC 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D8D8F0 802406A0 4480A000 */  mtc1      $zero, $f20
/* D8D8F4 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D8D8F8 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D8D8FC 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D8D900 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D8D904 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D8D908 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D8D90C 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D8D910 802406C0 00031080 */  sll       $v0, $v1, 2
/* D8D914 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D8D918 802406C8 00021080 */  sll       $v0, $v0, 2
/* D8D91C 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D8D920 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D8D924 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D8D928 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D8D92C 802406DC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D8D930 802406E0 00220821 */  addu      $at, $at, $v0
/* D8D934 802406E4 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D8D938 802406E8 4406A000 */  mfc1      $a2, $f20
/* D8D93C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D8D940 802406F0 4405B000 */  mfc1      $a1, $f22
/* D8D944 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D8D948 802406F8 0C019EC8 */  jal       guRotateF
/* D8D94C 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D8D950 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D8D954 80240704 0C00A6C9 */  jal       clamp_angle
/* D8D958 80240708 00000000 */   nop
/* D8D95C 8024070C 44050000 */  mfc1      $a1, $f0
/* D8D960 80240710 4406A000 */  mfc1      $a2, $f20
/* D8D964 80240714 4407A000 */  mfc1      $a3, $f20
/* D8D968 80240718 3C013F80 */  lui       $at, 0x3f80
/* D8D96C 8024071C 4481C000 */  mtc1      $at, $f24
/* D8D970 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D8D974 80240724 0C019EC8 */  jal       guRotateF
/* D8D978 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D8D97C 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D8D980 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D8D984 80240734 0C019D80 */  jal       guMtxCatF
/* D8D988 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D8D98C 8024073C 4405B000 */  mfc1      $a1, $f22
/* D8D990 80240740 4406A000 */  mfc1      $a2, $f20
/* D8D994 80240744 4407C000 */  mfc1      $a3, $f24
/* D8D998 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D8D99C 8024074C 0C019EC8 */  jal       guRotateF
/* D8D9A0 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D8D9A4 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D8D9A8 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D8D9AC 8024075C 0C019D80 */  jal       guMtxCatF
/* D8D9B0 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D8D9B4 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D8D9B8 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D8D9BC 8024076C 4406A000 */  mfc1      $a2, $f20
/* D8D9C0 80240770 4407C000 */  mfc1      $a3, $f24
/* D8D9C4 80240774 0C019EC8 */  jal       guRotateF
/* D8D9C8 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D8D9CC 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D8D9D0 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D8D9D4 80240784 0C019D80 */  jal       guMtxCatF
/* D8D9D8 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D8D9DC 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D8D9E0 80240790 3C013F36 */  lui       $at, 0x3f36
/* D8D9E4 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D8D9E8 80240798 44810000 */  mtc1      $at, $f0
/* D8D9EC 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D8D9F0 802407A0 44050000 */  mfc1      $a1, $f0
/* D8D9F4 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D8D9F8 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D8D9FC 802407AC 0C019DF0 */  jal       guScaleF
/* D8DA00 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D8DA04 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D8DA08 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D8DA0C 802407BC 0C019D80 */  jal       guMtxCatF
/* D8DA10 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D8DA14 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D8DA18 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D8DA1C 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D8DA20 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D8DA24 802407D4 46000007 */  neg.s     $f0, $f0
/* D8DA28 802407D8 44060000 */  mfc1      $a2, $f0
/* D8DA2C 802407DC 0C019E40 */  jal       guTranslateF
/* D8DA30 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D8DA34 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D8DA38 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D8DA3C 802407EC 0C019D80 */  jal       guMtxCatF
/* D8DA40 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D8DA44 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D8DA48 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D8DA4C 802407FC 44810000 */  mtc1      $at, $f0
/* D8DA50 80240800 00000000 */  nop
/* D8DA54 80240804 4602003E */  c.le.s    $f0, $f2
/* D8DA58 80240808 00000000 */  nop
/* D8DA5C 8024080C 4500000A */  bc1f      .L80240838
/* D8DA60 80240810 24040001 */   addiu    $a0, $zero, 1
/* D8DA64 80240814 3C014387 */  lui       $at, 0x4387
/* D8DA68 80240818 44810000 */  mtc1      $at, $f0
/* D8DA6C 8024081C 00000000 */  nop
/* D8DA70 80240820 4600103C */  c.lt.s    $f2, $f0
/* D8DA74 80240824 00000000 */  nop
/* D8DA78 80240828 45000004 */  bc1f      .L8024083C
/* D8DA7C 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D8DA80 80240830 3C041000 */  lui       $a0, 0x1000
/* D8DA84 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D8DA88 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D8DA8C 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D8DA90 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D8DA94 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D8DA98 80240848 0C0B7710 */  jal       render_sprite
/* D8DA9C 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D8DAA0 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D8DAA4 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D8DAA8 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D8DAAC 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D8DAB0 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D8DAB4 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D8DAB8 80240868 03E00008 */  jr        $ra
/* D8DABC 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
