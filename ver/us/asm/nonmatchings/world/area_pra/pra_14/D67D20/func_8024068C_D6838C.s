.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D6838C
/* D6838C 8024068C 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D68390 80240690 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D68394 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D68398 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D6839C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D683A0 802406A0 4480A000 */  mtc1      $zero, $f20
/* D683A4 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D683A8 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D683AC 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D683B0 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D683B4 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D683B8 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D683BC 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D683C0 802406C0 00031080 */  sll       $v0, $v1, 2
/* D683C4 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D683C8 802406C8 00021080 */  sll       $v0, $v0, 2
/* D683CC 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D683D0 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D683D4 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D683D8 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D683DC 802406DC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D683E0 802406E0 00220821 */  addu      $at, $at, $v0
/* D683E4 802406E4 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D683E8 802406E8 4406A000 */  mfc1      $a2, $f20
/* D683EC 802406EC 4600B587 */  neg.s     $f22, $f22
/* D683F0 802406F0 4405B000 */  mfc1      $a1, $f22
/* D683F4 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D683F8 802406F8 0C019EC8 */  jal       guRotateF
/* D683FC 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D68400 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D68404 80240704 0C00A6C9 */  jal       clamp_angle
/* D68408 80240708 00000000 */   nop
/* D6840C 8024070C 44050000 */  mfc1      $a1, $f0
/* D68410 80240710 4406A000 */  mfc1      $a2, $f20
/* D68414 80240714 4407A000 */  mfc1      $a3, $f20
/* D68418 80240718 3C013F80 */  lui       $at, 0x3f80
/* D6841C 8024071C 4481C000 */  mtc1      $at, $f24
/* D68420 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D68424 80240724 0C019EC8 */  jal       guRotateF
/* D68428 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D6842C 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D68430 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D68434 80240734 0C019D80 */  jal       guMtxCatF
/* D68438 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D6843C 8024073C 4405B000 */  mfc1      $a1, $f22
/* D68440 80240740 4406A000 */  mfc1      $a2, $f20
/* D68444 80240744 4407C000 */  mfc1      $a3, $f24
/* D68448 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D6844C 8024074C 0C019EC8 */  jal       guRotateF
/* D68450 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D68454 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D68458 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D6845C 8024075C 0C019D80 */  jal       guMtxCatF
/* D68460 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D68464 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D68468 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D6846C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D68470 80240770 4407C000 */  mfc1      $a3, $f24
/* D68474 80240774 0C019EC8 */  jal       guRotateF
/* D68478 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D6847C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D68480 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D68484 80240784 0C019D80 */  jal       guMtxCatF
/* D68488 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D6848C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D68490 80240790 3C013F36 */  lui       $at, 0x3f36
/* D68494 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D68498 80240798 44810000 */  mtc1      $at, $f0
/* D6849C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D684A0 802407A0 44050000 */  mfc1      $a1, $f0
/* D684A4 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D684A8 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D684AC 802407AC 0C019DF0 */  jal       guScaleF
/* D684B0 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D684B4 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D684B8 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D684BC 802407BC 0C019D80 */  jal       guMtxCatF
/* D684C0 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D684C4 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D684C8 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D684CC 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D684D0 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D684D4 802407D4 46000007 */  neg.s     $f0, $f0
/* D684D8 802407D8 44060000 */  mfc1      $a2, $f0
/* D684DC 802407DC 0C019E40 */  jal       guTranslateF
/* D684E0 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D684E4 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D684E8 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D684EC 802407EC 0C019D80 */  jal       guMtxCatF
/* D684F0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D684F4 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D684F8 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D684FC 802407FC 44810000 */  mtc1      $at, $f0
/* D68500 80240800 00000000 */  nop
/* D68504 80240804 4602003E */  c.le.s    $f0, $f2
/* D68508 80240808 00000000 */  nop
/* D6850C 8024080C 4500000A */  bc1f      .L80240838
/* D68510 80240810 24040001 */   addiu    $a0, $zero, 1
/* D68514 80240814 3C014387 */  lui       $at, 0x4387
/* D68518 80240818 44810000 */  mtc1      $at, $f0
/* D6851C 8024081C 00000000 */  nop
/* D68520 80240820 4600103C */  c.lt.s    $f2, $f0
/* D68524 80240824 00000000 */  nop
/* D68528 80240828 45000004 */  bc1f      .L8024083C
/* D6852C 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D68530 80240830 3C041000 */  lui       $a0, 0x1000
/* D68534 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D68538 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D6853C 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D68540 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D68544 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D68548 80240848 0C0B7710 */  jal       render_sprite
/* D6854C 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D68550 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D68554 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D68558 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D6855C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D68560 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D68564 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D68568 80240868 03E00008 */  jr        $ra
/* D6856C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
