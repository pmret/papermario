.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D6F03C
/* D6F03C 8024068C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D6F040 80240690 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D6F044 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D6F048 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D6F04C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D6F050 802406A0 4480A000 */  mtc1      $zero, $f20
/* D6F054 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D6F058 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D6F05C 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D6F060 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D6F064 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D6F068 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D6F06C 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D6F070 802406C0 00031080 */  sll       $v0, $v1, 2
/* D6F074 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D6F078 802406C8 00021080 */  sll       $v0, $v0, 2
/* D6F07C 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D6F080 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D6F084 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D6F088 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D6F08C 802406DC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D6F090 802406E0 00220821 */  addu      $at, $at, $v0
/* D6F094 802406E4 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D6F098 802406E8 4406A000 */  mfc1      $a2, $f20
/* D6F09C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D6F0A0 802406F0 4405B000 */  mfc1      $a1, $f22
/* D6F0A4 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D6F0A8 802406F8 0C019EC8 */  jal       guRotateF
/* D6F0AC 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D6F0B0 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D6F0B4 80240704 0C00A6C9 */  jal       clamp_angle
/* D6F0B8 80240708 00000000 */   nop
/* D6F0BC 8024070C 44050000 */  mfc1      $a1, $f0
/* D6F0C0 80240710 4406A000 */  mfc1      $a2, $f20
/* D6F0C4 80240714 4407A000 */  mfc1      $a3, $f20
/* D6F0C8 80240718 3C013F80 */  lui       $at, 0x3f80
/* D6F0CC 8024071C 4481C000 */  mtc1      $at, $f24
/* D6F0D0 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D6F0D4 80240724 0C019EC8 */  jal       guRotateF
/* D6F0D8 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D6F0DC 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D6F0E0 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D6F0E4 80240734 0C019D80 */  jal       guMtxCatF
/* D6F0E8 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D6F0EC 8024073C 4405B000 */  mfc1      $a1, $f22
/* D6F0F0 80240740 4406A000 */  mfc1      $a2, $f20
/* D6F0F4 80240744 4407C000 */  mfc1      $a3, $f24
/* D6F0F8 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D6F0FC 8024074C 0C019EC8 */  jal       guRotateF
/* D6F100 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D6F104 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D6F108 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D6F10C 8024075C 0C019D80 */  jal       guMtxCatF
/* D6F110 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D6F114 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D6F118 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D6F11C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D6F120 80240770 4407C000 */  mfc1      $a3, $f24
/* D6F124 80240774 0C019EC8 */  jal       guRotateF
/* D6F128 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D6F12C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D6F130 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D6F134 80240784 0C019D80 */  jal       guMtxCatF
/* D6F138 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D6F13C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D6F140 80240790 3C013F36 */  lui       $at, 0x3f36
/* D6F144 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D6F148 80240798 44810000 */  mtc1      $at, $f0
/* D6F14C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D6F150 802407A0 44050000 */  mfc1      $a1, $f0
/* D6F154 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D6F158 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D6F15C 802407AC 0C019DF0 */  jal       guScaleF
/* D6F160 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D6F164 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D6F168 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D6F16C 802407BC 0C019D80 */  jal       guMtxCatF
/* D6F170 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D6F174 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D6F178 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D6F17C 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D6F180 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D6F184 802407D4 46000007 */  neg.s     $f0, $f0
/* D6F188 802407D8 44060000 */  mfc1      $a2, $f0
/* D6F18C 802407DC 0C019E40 */  jal       guTranslateF
/* D6F190 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D6F194 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D6F198 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D6F19C 802407EC 0C019D80 */  jal       guMtxCatF
/* D6F1A0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D6F1A4 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D6F1A8 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D6F1AC 802407FC 44810000 */  mtc1      $at, $f0
/* D6F1B0 80240800 00000000 */  nop
/* D6F1B4 80240804 4602003E */  c.le.s    $f0, $f2
/* D6F1B8 80240808 00000000 */  nop
/* D6F1BC 8024080C 4500000A */  bc1f      .L80240838
/* D6F1C0 80240810 24040001 */   addiu    $a0, $zero, 1
/* D6F1C4 80240814 3C014387 */  lui       $at, 0x4387
/* D6F1C8 80240818 44810000 */  mtc1      $at, $f0
/* D6F1CC 8024081C 00000000 */  nop
/* D6F1D0 80240820 4600103C */  c.lt.s    $f2, $f0
/* D6F1D4 80240824 00000000 */  nop
/* D6F1D8 80240828 45000004 */  bc1f      .L8024083C
/* D6F1DC 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D6F1E0 80240830 3C041000 */  lui       $a0, 0x1000
/* D6F1E4 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D6F1E8 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D6F1EC 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D6F1F0 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D6F1F4 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D6F1F8 80240848 0C0B7710 */  jal       render_sprite
/* D6F1FC 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D6F200 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D6F204 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D6F208 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D6F20C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D6F210 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D6F214 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D6F218 80240868 03E00008 */  jr        $ra
/* D6F21C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
