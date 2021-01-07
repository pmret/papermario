.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D8BA3C
/* D8BA3C 8024068C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D8BA40 80240690 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D8BA44 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D8BA48 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D8BA4C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D8BA50 802406A0 4480A000 */  mtc1      $zero, $f20
/* D8BA54 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D8BA58 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D8BA5C 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D8BA60 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D8BA64 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D8BA68 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D8BA6C 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D8BA70 802406C0 00031080 */  sll       $v0, $v1, 2
/* D8BA74 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D8BA78 802406C8 00021080 */  sll       $v0, $v0, 2
/* D8BA7C 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D8BA80 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D8BA84 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D8BA88 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D8BA8C 802406DC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D8BA90 802406E0 00220821 */  addu      $at, $at, $v0
/* D8BA94 802406E4 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D8BA98 802406E8 4406A000 */  mfc1      $a2, $f20
/* D8BA9C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D8BAA0 802406F0 4405B000 */  mfc1      $a1, $f22
/* D8BAA4 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D8BAA8 802406F8 0C019EC8 */  jal       guRotateF
/* D8BAAC 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D8BAB0 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D8BAB4 80240704 0C00A6C9 */  jal       clamp_angle
/* D8BAB8 80240708 00000000 */   nop      
/* D8BABC 8024070C 44050000 */  mfc1      $a1, $f0
/* D8BAC0 80240710 4406A000 */  mfc1      $a2, $f20
/* D8BAC4 80240714 4407A000 */  mfc1      $a3, $f20
/* D8BAC8 80240718 3C013F80 */  lui       $at, 0x3f80
/* D8BACC 8024071C 4481C000 */  mtc1      $at, $f24
/* D8BAD0 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D8BAD4 80240724 0C019EC8 */  jal       guRotateF
/* D8BAD8 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D8BADC 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D8BAE0 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D8BAE4 80240734 0C019D80 */  jal       guMtxCatF
/* D8BAE8 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D8BAEC 8024073C 4405B000 */  mfc1      $a1, $f22
/* D8BAF0 80240740 4406A000 */  mfc1      $a2, $f20
/* D8BAF4 80240744 4407C000 */  mfc1      $a3, $f24
/* D8BAF8 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D8BAFC 8024074C 0C019EC8 */  jal       guRotateF
/* D8BB00 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D8BB04 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D8BB08 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D8BB0C 8024075C 0C019D80 */  jal       guMtxCatF
/* D8BB10 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D8BB14 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D8BB18 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D8BB1C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D8BB20 80240770 4407C000 */  mfc1      $a3, $f24
/* D8BB24 80240774 0C019EC8 */  jal       guRotateF
/* D8BB28 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D8BB2C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D8BB30 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D8BB34 80240784 0C019D80 */  jal       guMtxCatF
/* D8BB38 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D8BB3C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D8BB40 80240790 3C013F36 */  lui       $at, 0x3f36
/* D8BB44 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D8BB48 80240798 44810000 */  mtc1      $at, $f0
/* D8BB4C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D8BB50 802407A0 44050000 */  mfc1      $a1, $f0
/* D8BB54 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D8BB58 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D8BB5C 802407AC 0C019DF0 */  jal       guScaleF
/* D8BB60 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D8BB64 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D8BB68 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D8BB6C 802407BC 0C019D80 */  jal       guMtxCatF
/* D8BB70 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D8BB74 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D8BB78 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D8BB7C 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D8BB80 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D8BB84 802407D4 46000007 */  neg.s     $f0, $f0
/* D8BB88 802407D8 44060000 */  mfc1      $a2, $f0
/* D8BB8C 802407DC 0C019E40 */  jal       guTranslateF
/* D8BB90 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D8BB94 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D8BB98 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D8BB9C 802407EC 0C019D80 */  jal       guMtxCatF
/* D8BBA0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D8BBA4 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D8BBA8 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D8BBAC 802407FC 44810000 */  mtc1      $at, $f0
/* D8BBB0 80240800 00000000 */  nop       
/* D8BBB4 80240804 4602003E */  c.le.s    $f0, $f2
/* D8BBB8 80240808 00000000 */  nop       
/* D8BBBC 8024080C 4500000A */  bc1f      .L80240838
/* D8BBC0 80240810 24040001 */   addiu    $a0, $zero, 1
/* D8BBC4 80240814 3C014387 */  lui       $at, 0x4387
/* D8BBC8 80240818 44810000 */  mtc1      $at, $f0
/* D8BBCC 8024081C 00000000 */  nop       
/* D8BBD0 80240820 4600103C */  c.lt.s    $f2, $f0
/* D8BBD4 80240824 00000000 */  nop       
/* D8BBD8 80240828 45000004 */  bc1f      .L8024083C
/* D8BBDC 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D8BBE0 80240830 3C041000 */  lui       $a0, 0x1000
/* D8BBE4 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D8BBE8 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D8BBEC 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D8BBF0 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D8BBF4 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D8BBF8 80240848 0C0B7710 */  jal       render_sprite
/* D8BBFC 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D8BC00 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D8BC04 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D8BC08 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D8BC0C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D8BC10 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D8BC14 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D8BC18 80240868 03E00008 */  jr        $ra
/* D8BC1C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
