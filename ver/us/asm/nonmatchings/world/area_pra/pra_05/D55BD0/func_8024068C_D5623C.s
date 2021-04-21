.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D5623C
/* D5623C 8024068C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D56240 80240690 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D56244 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D56248 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D5624C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D56250 802406A0 4480A000 */  mtc1      $zero, $f20
/* D56254 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D56258 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D5625C 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D56260 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D56264 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D56268 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D5626C 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D56270 802406C0 00031080 */  sll       $v0, $v1, 2
/* D56274 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D56278 802406C8 00021080 */  sll       $v0, $v0, 2
/* D5627C 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D56280 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D56284 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D56288 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D5628C 802406DC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D56290 802406E0 00220821 */  addu      $at, $at, $v0
/* D56294 802406E4 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D56298 802406E8 4406A000 */  mfc1      $a2, $f20
/* D5629C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D562A0 802406F0 4405B000 */  mfc1      $a1, $f22
/* D562A4 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D562A8 802406F8 0C019EC8 */  jal       guRotateF
/* D562AC 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D562B0 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D562B4 80240704 0C00A6C9 */  jal       clamp_angle
/* D562B8 80240708 00000000 */   nop
/* D562BC 8024070C 44050000 */  mfc1      $a1, $f0
/* D562C0 80240710 4406A000 */  mfc1      $a2, $f20
/* D562C4 80240714 4407A000 */  mfc1      $a3, $f20
/* D562C8 80240718 3C013F80 */  lui       $at, 0x3f80
/* D562CC 8024071C 4481C000 */  mtc1      $at, $f24
/* D562D0 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D562D4 80240724 0C019EC8 */  jal       guRotateF
/* D562D8 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D562DC 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D562E0 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D562E4 80240734 0C019D80 */  jal       guMtxCatF
/* D562E8 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D562EC 8024073C 4405B000 */  mfc1      $a1, $f22
/* D562F0 80240740 4406A000 */  mfc1      $a2, $f20
/* D562F4 80240744 4407C000 */  mfc1      $a3, $f24
/* D562F8 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D562FC 8024074C 0C019EC8 */  jal       guRotateF
/* D56300 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D56304 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D56308 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D5630C 8024075C 0C019D80 */  jal       guMtxCatF
/* D56310 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D56314 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D56318 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D5631C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D56320 80240770 4407C000 */  mfc1      $a3, $f24
/* D56324 80240774 0C019EC8 */  jal       guRotateF
/* D56328 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D5632C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D56330 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D56334 80240784 0C019D80 */  jal       guMtxCatF
/* D56338 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D5633C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D56340 80240790 3C013F36 */  lui       $at, 0x3f36
/* D56344 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D56348 80240798 44810000 */  mtc1      $at, $f0
/* D5634C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D56350 802407A0 44050000 */  mfc1      $a1, $f0
/* D56354 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D56358 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D5635C 802407AC 0C019DF0 */  jal       guScaleF
/* D56360 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D56364 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D56368 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D5636C 802407BC 0C019D80 */  jal       guMtxCatF
/* D56370 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D56374 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D56378 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D5637C 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D56380 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D56384 802407D4 46000007 */  neg.s     $f0, $f0
/* D56388 802407D8 44060000 */  mfc1      $a2, $f0
/* D5638C 802407DC 0C019E40 */  jal       guTranslateF
/* D56390 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D56394 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D56398 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D5639C 802407EC 0C019D80 */  jal       guMtxCatF
/* D563A0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D563A4 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D563A8 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D563AC 802407FC 44810000 */  mtc1      $at, $f0
/* D563B0 80240800 00000000 */  nop
/* D563B4 80240804 4602003E */  c.le.s    $f0, $f2
/* D563B8 80240808 00000000 */  nop
/* D563BC 8024080C 4500000A */  bc1f      .L80240838
/* D563C0 80240810 24040001 */   addiu    $a0, $zero, 1
/* D563C4 80240814 3C014387 */  lui       $at, 0x4387
/* D563C8 80240818 44810000 */  mtc1      $at, $f0
/* D563CC 8024081C 00000000 */  nop
/* D563D0 80240820 4600103C */  c.lt.s    $f2, $f0
/* D563D4 80240824 00000000 */  nop
/* D563D8 80240828 45000004 */  bc1f      .L8024083C
/* D563DC 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D563E0 80240830 3C041000 */  lui       $a0, 0x1000
/* D563E4 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D563E8 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D563EC 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D563F0 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D563F4 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D563F8 80240848 0C0B7710 */  jal       render_sprite
/* D563FC 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D56400 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D56404 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D56408 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D5640C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D56410 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D56414 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D56418 80240868 03E00008 */  jr        $ra
/* D5641C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
