.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D4D6CC
/* D4D6CC 8024068C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D4D6D0 80240690 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D4D6D4 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D4D6D8 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D4D6DC 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D4D6E0 802406A0 4480A000 */  mtc1      $zero, $f20
/* D4D6E4 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D4D6E8 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D4D6EC 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D4D6F0 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D4D6F4 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D4D6F8 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D4D6FC 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D4D700 802406C0 00031080 */  sll       $v0, $v1, 2
/* D4D704 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D4D708 802406C8 00021080 */  sll       $v0, $v0, 2
/* D4D70C 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D4D710 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D4D714 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D4D718 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D4D71C 802406DC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D4D720 802406E0 00220821 */  addu      $at, $at, $v0
/* D4D724 802406E4 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D4D728 802406E8 4406A000 */  mfc1      $a2, $f20
/* D4D72C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D4D730 802406F0 4405B000 */  mfc1      $a1, $f22
/* D4D734 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D4D738 802406F8 0C019EC8 */  jal       guRotateF
/* D4D73C 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D4D740 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D4D744 80240704 0C00A6C9 */  jal       clamp_angle
/* D4D748 80240708 00000000 */   nop      
/* D4D74C 8024070C 44050000 */  mfc1      $a1, $f0
/* D4D750 80240710 4406A000 */  mfc1      $a2, $f20
/* D4D754 80240714 4407A000 */  mfc1      $a3, $f20
/* D4D758 80240718 3C013F80 */  lui       $at, 0x3f80
/* D4D75C 8024071C 4481C000 */  mtc1      $at, $f24
/* D4D760 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D764 80240724 0C019EC8 */  jal       guRotateF
/* D4D768 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D4D76C 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D4D770 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D4D774 80240734 0C019D80 */  jal       guMtxCatF
/* D4D778 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D4D77C 8024073C 4405B000 */  mfc1      $a1, $f22
/* D4D780 80240740 4406A000 */  mfc1      $a2, $f20
/* D4D784 80240744 4407C000 */  mfc1      $a3, $f24
/* D4D788 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D4D78C 8024074C 0C019EC8 */  jal       guRotateF
/* D4D790 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D4D794 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D798 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D4D79C 8024075C 0C019D80 */  jal       guMtxCatF
/* D4D7A0 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D4D7A4 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D4D7A8 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D4D7AC 8024076C 4406A000 */  mfc1      $a2, $f20
/* D4D7B0 80240770 4407C000 */  mfc1      $a3, $f24
/* D4D7B4 80240774 0C019EC8 */  jal       guRotateF
/* D4D7B8 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D4D7BC 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D7C0 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D4D7C4 80240784 0C019D80 */  jal       guMtxCatF
/* D4D7C8 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D4D7CC 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D4D7D0 80240790 3C013F36 */  lui       $at, 0x3f36
/* D4D7D4 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D4D7D8 80240798 44810000 */  mtc1      $at, $f0
/* D4D7DC 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D4D7E0 802407A0 44050000 */  mfc1      $a1, $f0
/* D4D7E4 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D4D7E8 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D4D7EC 802407AC 0C019DF0 */  jal       guScaleF
/* D4D7F0 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D4D7F4 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D7F8 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D4D7FC 802407BC 0C019D80 */  jal       guMtxCatF
/* D4D800 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D4D804 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D4D808 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D4D80C 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D4D810 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D4D814 802407D4 46000007 */  neg.s     $f0, $f0
/* D4D818 802407D8 44060000 */  mfc1      $a2, $f0
/* D4D81C 802407DC 0C019E40 */  jal       guTranslateF
/* D4D820 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D4D824 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D4D828 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D4D82C 802407EC 0C019D80 */  jal       guMtxCatF
/* D4D830 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D4D834 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D4D838 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D4D83C 802407FC 44810000 */  mtc1      $at, $f0
/* D4D840 80240800 00000000 */  nop       
/* D4D844 80240804 4602003E */  c.le.s    $f0, $f2
/* D4D848 80240808 00000000 */  nop       
/* D4D84C 8024080C 4500000A */  bc1f      .L80240838
/* D4D850 80240810 24040001 */   addiu    $a0, $zero, 1
/* D4D854 80240814 3C014387 */  lui       $at, 0x4387
/* D4D858 80240818 44810000 */  mtc1      $at, $f0
/* D4D85C 8024081C 00000000 */  nop       
/* D4D860 80240820 4600103C */  c.lt.s    $f2, $f0
/* D4D864 80240824 00000000 */  nop       
/* D4D868 80240828 45000004 */  bc1f      .L8024083C
/* D4D86C 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D4D870 80240830 3C041000 */  lui       $a0, 0x1000
/* D4D874 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D4D878 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D4D87C 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D4D880 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D4D884 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D4D888 80240848 0C0B7710 */  jal       render_sprite
/* D4D88C 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D4D890 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D4D894 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D4D898 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D4D89C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D4D8A0 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D4D8A4 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D4D8A8 80240868 03E00008 */  jr        $ra
/* D4D8AC 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
