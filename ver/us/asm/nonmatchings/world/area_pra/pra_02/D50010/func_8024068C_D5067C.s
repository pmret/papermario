.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D5067C
/* D5067C 8024068C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D50680 80240690 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D50684 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D50688 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D5068C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D50690 802406A0 4480A000 */  mtc1      $zero, $f20
/* D50694 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D50698 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D5069C 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D506A0 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D506A4 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D506A8 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D506AC 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D506B0 802406C0 00031080 */  sll       $v0, $v1, 2
/* D506B4 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D506B8 802406C8 00021080 */  sll       $v0, $v0, 2
/* D506BC 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D506C0 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D506C4 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D506C8 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D506CC 802406DC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D506D0 802406E0 00220821 */  addu      $at, $at, $v0
/* D506D4 802406E4 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D506D8 802406E8 4406A000 */  mfc1      $a2, $f20
/* D506DC 802406EC 4600B587 */  neg.s     $f22, $f22
/* D506E0 802406F0 4405B000 */  mfc1      $a1, $f22
/* D506E4 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D506E8 802406F8 0C019EC8 */  jal       guRotateF
/* D506EC 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D506F0 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D506F4 80240704 0C00A6C9 */  jal       clamp_angle
/* D506F8 80240708 00000000 */   nop
/* D506FC 8024070C 44050000 */  mfc1      $a1, $f0
/* D50700 80240710 4406A000 */  mfc1      $a2, $f20
/* D50704 80240714 4407A000 */  mfc1      $a3, $f20
/* D50708 80240718 3C013F80 */  lui       $at, 0x3f80
/* D5070C 8024071C 4481C000 */  mtc1      $at, $f24
/* D50710 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D50714 80240724 0C019EC8 */  jal       guRotateF
/* D50718 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D5071C 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D50720 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D50724 80240734 0C019D80 */  jal       guMtxCatF
/* D50728 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D5072C 8024073C 4405B000 */  mfc1      $a1, $f22
/* D50730 80240740 4406A000 */  mfc1      $a2, $f20
/* D50734 80240744 4407C000 */  mfc1      $a3, $f24
/* D50738 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D5073C 8024074C 0C019EC8 */  jal       guRotateF
/* D50740 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D50744 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D50748 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D5074C 8024075C 0C019D80 */  jal       guMtxCatF
/* D50750 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D50754 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D50758 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D5075C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D50760 80240770 4407C000 */  mfc1      $a3, $f24
/* D50764 80240774 0C019EC8 */  jal       guRotateF
/* D50768 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D5076C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D50770 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D50774 80240784 0C019D80 */  jal       guMtxCatF
/* D50778 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D5077C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D50780 80240790 3C013F36 */  lui       $at, 0x3f36
/* D50784 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D50788 80240798 44810000 */  mtc1      $at, $f0
/* D5078C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D50790 802407A0 44050000 */  mfc1      $a1, $f0
/* D50794 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D50798 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D5079C 802407AC 0C019DF0 */  jal       guScaleF
/* D507A0 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D507A4 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D507A8 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D507AC 802407BC 0C019D80 */  jal       guMtxCatF
/* D507B0 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D507B4 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D507B8 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D507BC 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D507C0 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D507C4 802407D4 46000007 */  neg.s     $f0, $f0
/* D507C8 802407D8 44060000 */  mfc1      $a2, $f0
/* D507CC 802407DC 0C019E40 */  jal       guTranslateF
/* D507D0 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D507D4 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D507D8 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D507DC 802407EC 0C019D80 */  jal       guMtxCatF
/* D507E0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D507E4 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D507E8 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D507EC 802407FC 44810000 */  mtc1      $at, $f0
/* D507F0 80240800 00000000 */  nop
/* D507F4 80240804 4602003E */  c.le.s    $f0, $f2
/* D507F8 80240808 00000000 */  nop
/* D507FC 8024080C 4500000A */  bc1f      .L80240838
/* D50800 80240810 24040001 */   addiu    $a0, $zero, 1
/* D50804 80240814 3C014387 */  lui       $at, 0x4387
/* D50808 80240818 44810000 */  mtc1      $at, $f0
/* D5080C 8024081C 00000000 */  nop
/* D50810 80240820 4600103C */  c.lt.s    $f2, $f0
/* D50814 80240824 00000000 */  nop
/* D50818 80240828 45000004 */  bc1f      .L8024083C
/* D5081C 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D50820 80240830 3C041000 */  lui       $a0, 0x1000
/* D50824 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D50828 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D5082C 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D50830 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D50834 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D50838 80240848 0C0B7710 */  jal       render_sprite
/* D5083C 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D50840 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D50844 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D50848 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D5084C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D50850 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D50854 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D50858 80240868 03E00008 */  jr        $ra
/* D5085C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
