.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D5F93C
/* D5F93C 8024068C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D5F940 80240690 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D5F944 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D5F948 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D5F94C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D5F950 802406A0 4480A000 */  mtc1      $zero, $f20
/* D5F954 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D5F958 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D5F95C 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D5F960 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D5F964 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D5F968 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D5F96C 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D5F970 802406C0 00031080 */  sll       $v0, $v1, 2
/* D5F974 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D5F978 802406C8 00021080 */  sll       $v0, $v0, 2
/* D5F97C 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D5F980 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D5F984 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D5F988 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D5F98C 802406DC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D5F990 802406E0 00220821 */  addu      $at, $at, $v0
/* D5F994 802406E4 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D5F998 802406E8 4406A000 */  mfc1      $a2, $f20
/* D5F99C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D5F9A0 802406F0 4405B000 */  mfc1      $a1, $f22
/* D5F9A4 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D5F9A8 802406F8 0C019EC8 */  jal       guRotateF
/* D5F9AC 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D5F9B0 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D5F9B4 80240704 0C00A6C9 */  jal       clamp_angle
/* D5F9B8 80240708 00000000 */   nop
/* D5F9BC 8024070C 44050000 */  mfc1      $a1, $f0
/* D5F9C0 80240710 4406A000 */  mfc1      $a2, $f20
/* D5F9C4 80240714 4407A000 */  mfc1      $a3, $f20
/* D5F9C8 80240718 3C013F80 */  lui       $at, 0x3f80
/* D5F9CC 8024071C 4481C000 */  mtc1      $at, $f24
/* D5F9D0 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D5F9D4 80240724 0C019EC8 */  jal       guRotateF
/* D5F9D8 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D5F9DC 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D5F9E0 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D5F9E4 80240734 0C019D80 */  jal       guMtxCatF
/* D5F9E8 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D5F9EC 8024073C 4405B000 */  mfc1      $a1, $f22
/* D5F9F0 80240740 4406A000 */  mfc1      $a2, $f20
/* D5F9F4 80240744 4407C000 */  mfc1      $a3, $f24
/* D5F9F8 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D5F9FC 8024074C 0C019EC8 */  jal       guRotateF
/* D5FA00 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D5FA04 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D5FA08 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D5FA0C 8024075C 0C019D80 */  jal       guMtxCatF
/* D5FA10 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D5FA14 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D5FA18 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D5FA1C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D5FA20 80240770 4407C000 */  mfc1      $a3, $f24
/* D5FA24 80240774 0C019EC8 */  jal       guRotateF
/* D5FA28 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D5FA2C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D5FA30 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D5FA34 80240784 0C019D80 */  jal       guMtxCatF
/* D5FA38 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D5FA3C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D5FA40 80240790 3C013F36 */  lui       $at, 0x3f36
/* D5FA44 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D5FA48 80240798 44810000 */  mtc1      $at, $f0
/* D5FA4C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D5FA50 802407A0 44050000 */  mfc1      $a1, $f0
/* D5FA54 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D5FA58 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D5FA5C 802407AC 0C019DF0 */  jal       guScaleF
/* D5FA60 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D5FA64 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D5FA68 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D5FA6C 802407BC 0C019D80 */  jal       guMtxCatF
/* D5FA70 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D5FA74 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D5FA78 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D5FA7C 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D5FA80 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D5FA84 802407D4 46000007 */  neg.s     $f0, $f0
/* D5FA88 802407D8 44060000 */  mfc1      $a2, $f0
/* D5FA8C 802407DC 0C019E40 */  jal       guTranslateF
/* D5FA90 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D5FA94 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D5FA98 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D5FA9C 802407EC 0C019D80 */  jal       guMtxCatF
/* D5FAA0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D5FAA4 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D5FAA8 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D5FAAC 802407FC 44810000 */  mtc1      $at, $f0
/* D5FAB0 80240800 00000000 */  nop
/* D5FAB4 80240804 4602003E */  c.le.s    $f0, $f2
/* D5FAB8 80240808 00000000 */  nop
/* D5FABC 8024080C 4500000A */  bc1f      .L80240838
/* D5FAC0 80240810 24040001 */   addiu    $a0, $zero, 1
/* D5FAC4 80240814 3C014387 */  lui       $at, 0x4387
/* D5FAC8 80240818 44810000 */  mtc1      $at, $f0
/* D5FACC 8024081C 00000000 */  nop
/* D5FAD0 80240820 4600103C */  c.lt.s    $f2, $f0
/* D5FAD4 80240824 00000000 */  nop
/* D5FAD8 80240828 45000004 */  bc1f      .L8024083C
/* D5FADC 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D5FAE0 80240830 3C041000 */  lui       $a0, 0x1000
/* D5FAE4 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D5FAE8 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D5FAEC 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D5FAF0 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D5FAF4 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D5FAF8 80240848 0C0B7710 */  jal       render_sprite
/* D5FAFC 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D5FB00 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D5FB04 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D5FB08 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D5FB0C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D5FB10 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D5FB14 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D5FB18 80240868 03E00008 */  jr        $ra
/* D5FB1C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
