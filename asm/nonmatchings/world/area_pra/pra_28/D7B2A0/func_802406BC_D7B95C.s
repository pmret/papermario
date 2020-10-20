.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_D7B95C
/* D7B95C 802406BC 3C03800A */  lui       $v1, 0x800a
/* D7B960 802406C0 8463A634 */  lh        $v1, -0x59cc($v1)
/* D7B964 802406C4 3C07BF80 */  lui       $a3, 0xbf80
/* D7B968 802406C8 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D7B96C 802406CC F7B40128 */  sdc1      $f20, 0x128($sp)
/* D7B970 802406D0 4480A000 */  mtc1      $zero, $f20
/* D7B974 802406D4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D7B978 802406D8 0080882D */  daddu     $s1, $a0, $zero
/* D7B97C 802406DC AFB00118 */  sw        $s0, 0x118($sp)
/* D7B980 802406E0 27B00098 */  addiu     $s0, $sp, 0x98
/* D7B984 802406E4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D7B988 802406E8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D7B98C 802406EC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D7B990 802406F0 00031080 */  sll       $v0, $v1, 2
/* D7B994 802406F4 00431021 */  addu      $v0, $v0, $v1
/* D7B998 802406F8 00021080 */  sll       $v0, $v0, 2
/* D7B99C 802406FC 00431023 */  subu      $v0, $v0, $v1
/* D7B9A0 80240700 000218C0 */  sll       $v1, $v0, 3
/* D7B9A4 80240704 00431021 */  addu      $v0, $v0, $v1
/* D7B9A8 80240708 000210C0 */  sll       $v0, $v0, 3
/* D7B9AC 8024070C 3C01800B */  lui       $at, 0x800b
/* D7B9B0 80240710 00220821 */  addu      $at, $at, $v0
/* D7B9B4 80240714 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D7B9B8 80240718 4406A000 */  mfc1      $a2, $f20
/* D7B9BC 8024071C 4600B587 */  neg.s     $f22, $f22
/* D7B9C0 80240720 4405B000 */  mfc1      $a1, $f22
/* D7B9C4 80240724 0200202D */  daddu     $a0, $s0, $zero
/* D7B9C8 80240728 0C019EC8 */  jal       guRotateF
/* D7B9CC 8024072C E7B40010 */   swc1     $f20, 0x10($sp)
/* D7B9D0 80240730 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D7B9D4 80240734 0C00A6C9 */  jal       clamp_angle
/* D7B9D8 80240738 00000000 */   nop      
/* D7B9DC 8024073C 44050000 */  mfc1      $a1, $f0
/* D7B9E0 80240740 4406A000 */  mfc1      $a2, $f20
/* D7B9E4 80240744 4407A000 */  mfc1      $a3, $f20
/* D7B9E8 80240748 3C013F80 */  lui       $at, 0x3f80
/* D7B9EC 8024074C 4481C000 */  mtc1      $at, $f24
/* D7B9F0 80240750 27A40018 */  addiu     $a0, $sp, 0x18
/* D7B9F4 80240754 0C019EC8 */  jal       guRotateF
/* D7B9F8 80240758 E7B80010 */   swc1     $f24, 0x10($sp)
/* D7B9FC 8024075C 0200202D */  daddu     $a0, $s0, $zero
/* D7BA00 80240760 27A50018 */  addiu     $a1, $sp, 0x18
/* D7BA04 80240764 0C019D80 */  jal       guMtxCatF
/* D7BA08 80240768 00A0302D */   daddu    $a2, $a1, $zero
/* D7BA0C 8024076C 4405B000 */  mfc1      $a1, $f22
/* D7BA10 80240770 4406A000 */  mfc1      $a2, $f20
/* D7BA14 80240774 4407C000 */  mfc1      $a3, $f24
/* D7BA18 80240778 0200202D */  daddu     $a0, $s0, $zero
/* D7BA1C 8024077C 0C019EC8 */  jal       guRotateF
/* D7BA20 80240780 E7B40010 */   swc1     $f20, 0x10($sp)
/* D7BA24 80240784 27A40018 */  addiu     $a0, $sp, 0x18
/* D7BA28 80240788 0200282D */  daddu     $a1, $s0, $zero
/* D7BA2C 8024078C 0C019D80 */  jal       guMtxCatF
/* D7BA30 80240790 0080302D */   daddu    $a2, $a0, $zero
/* D7BA34 80240794 E7B40010 */  swc1      $f20, 0x10($sp)
/* D7BA38 80240798 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D7BA3C 8024079C 4406A000 */  mfc1      $a2, $f20
/* D7BA40 802407A0 4407C000 */  mfc1      $a3, $f24
/* D7BA44 802407A4 0C019EC8 */  jal       guRotateF
/* D7BA48 802407A8 0200202D */   daddu    $a0, $s0, $zero
/* D7BA4C 802407AC 27A40018 */  addiu     $a0, $sp, 0x18
/* D7BA50 802407B0 0200282D */  daddu     $a1, $s0, $zero
/* D7BA54 802407B4 0C019D80 */  jal       guMtxCatF
/* D7BA58 802407B8 0080302D */   daddu    $a2, $a0, $zero
/* D7BA5C 802407BC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D7BA60 802407C0 3C013F36 */  lui       $at, 0x3f36
/* D7BA64 802407C4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D7BA68 802407C8 44810000 */  mtc1      $at, $f0
/* D7BA6C 802407CC 0200202D */  daddu     $a0, $s0, $zero
/* D7BA70 802407D0 44050000 */  mfc1      $a1, $f0
/* D7BA74 802407D4 3C06BF36 */  lui       $a2, 0xbf36
/* D7BA78 802407D8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D7BA7C 802407DC 0C019DF0 */  jal       guScaleF
/* D7BA80 802407E0 00A0382D */   daddu    $a3, $a1, $zero
/* D7BA84 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D7BA88 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D7BA8C 802407EC 0C019D80 */  jal       guMtxCatF
/* D7BA90 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D7BA94 802407F4 27B00058 */  addiu     $s0, $sp, 0x58
/* D7BA98 802407F8 8E250028 */  lw        $a1, 0x28($s1)
/* D7BA9C 802407FC C620002C */  lwc1      $f0, 0x2c($s1)
/* D7BAA0 80240800 8E270030 */  lw        $a3, 0x30($s1)
/* D7BAA4 80240804 46000007 */  neg.s     $f0, $f0
/* D7BAA8 80240808 44060000 */  mfc1      $a2, $f0
/* D7BAAC 8024080C 0C019E40 */  jal       guTranslateF
/* D7BAB0 80240810 0200202D */   daddu    $a0, $s0, $zero
/* D7BAB4 80240814 27A40018 */  addiu     $a0, $sp, 0x18
/* D7BAB8 80240818 0200282D */  daddu     $a1, $s0, $zero
/* D7BABC 8024081C 0C019D80 */  jal       guMtxCatF
/* D7BAC0 80240820 0080302D */   daddu    $a2, $a0, $zero
/* D7BAC4 80240824 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D7BAC8 80240828 3C0142B4 */  lui       $at, 0x42b4
/* D7BACC 8024082C 44810000 */  mtc1      $at, $f0
/* D7BAD0 80240830 00000000 */  nop       
/* D7BAD4 80240834 4602003E */  c.le.s    $f0, $f2
/* D7BAD8 80240838 00000000 */  nop       
/* D7BADC 8024083C 4500000A */  bc1f      .L80240868
/* D7BAE0 80240840 24040001 */   addiu    $a0, $zero, 1
/* D7BAE4 80240844 3C014387 */  lui       $at, 0x4387
/* D7BAE8 80240848 44810000 */  mtc1      $at, $f0
/* D7BAEC 8024084C 00000000 */  nop       
/* D7BAF0 80240850 4600103C */  c.lt.s    $f2, $f0
/* D7BAF4 80240854 00000000 */  nop       
/* D7BAF8 80240858 45000004 */  bc1f      .L8024086C
/* D7BAFC 8024085C 27A20018 */   addiu    $v0, $sp, 0x18
/* D7BB00 80240860 3C041000 */  lui       $a0, 0x1000
/* D7BB04 80240864 34840001 */  ori       $a0, $a0, 1
.L80240868:
/* D7BB08 80240868 27A20018 */  addiu     $v0, $sp, 0x18
.L8024086C:
/* D7BB0C 8024086C 0000282D */  daddu     $a1, $zero, $zero
/* D7BB10 80240870 00A0302D */  daddu     $a2, $a1, $zero
/* D7BB14 80240874 00A0382D */  daddu     $a3, $a1, $zero
/* D7BB18 80240878 0C0B7710 */  jal       render_sprite
/* D7BB1C 8024087C AFA20010 */   sw       $v0, 0x10($sp)
/* D7BB20 80240880 8FBF0120 */  lw        $ra, 0x120($sp)
/* D7BB24 80240884 8FB1011C */  lw        $s1, 0x11c($sp)
/* D7BB28 80240888 8FB00118 */  lw        $s0, 0x118($sp)
/* D7BB2C 8024088C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D7BB30 80240890 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D7BB34 80240894 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D7BB38 80240898 03E00008 */  jr        $ra
/* D7BB3C 8024089C 27BD0140 */   addiu    $sp, $sp, 0x140
