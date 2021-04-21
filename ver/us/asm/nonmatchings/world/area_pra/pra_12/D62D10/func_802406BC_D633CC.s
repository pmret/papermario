.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_D633CC
/* D633CC 802406BC 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D633D0 802406C0 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D633D4 802406C4 3C07BF80 */  lui       $a3, 0xbf80
/* D633D8 802406C8 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D633DC 802406CC F7B40128 */  sdc1      $f20, 0x128($sp)
/* D633E0 802406D0 4480A000 */  mtc1      $zero, $f20
/* D633E4 802406D4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D633E8 802406D8 0080882D */  daddu     $s1, $a0, $zero
/* D633EC 802406DC AFB00118 */  sw        $s0, 0x118($sp)
/* D633F0 802406E0 27B00098 */  addiu     $s0, $sp, 0x98
/* D633F4 802406E4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D633F8 802406E8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D633FC 802406EC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D63400 802406F0 00031080 */  sll       $v0, $v1, 2
/* D63404 802406F4 00431021 */  addu      $v0, $v0, $v1
/* D63408 802406F8 00021080 */  sll       $v0, $v0, 2
/* D6340C 802406FC 00431023 */  subu      $v0, $v0, $v1
/* D63410 80240700 000218C0 */  sll       $v1, $v0, 3
/* D63414 80240704 00431021 */  addu      $v0, $v0, $v1
/* D63418 80240708 000210C0 */  sll       $v0, $v0, 3
/* D6341C 8024070C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D63420 80240710 00220821 */  addu      $at, $at, $v0
/* D63424 80240714 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D63428 80240718 4406A000 */  mfc1      $a2, $f20
/* D6342C 8024071C 4600B587 */  neg.s     $f22, $f22
/* D63430 80240720 4405B000 */  mfc1      $a1, $f22
/* D63434 80240724 0200202D */  daddu     $a0, $s0, $zero
/* D63438 80240728 0C019EC8 */  jal       guRotateF
/* D6343C 8024072C E7B40010 */   swc1     $f20, 0x10($sp)
/* D63440 80240730 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D63444 80240734 0C00A6C9 */  jal       clamp_angle
/* D63448 80240738 00000000 */   nop
/* D6344C 8024073C 44050000 */  mfc1      $a1, $f0
/* D63450 80240740 4406A000 */  mfc1      $a2, $f20
/* D63454 80240744 4407A000 */  mfc1      $a3, $f20
/* D63458 80240748 3C013F80 */  lui       $at, 0x3f80
/* D6345C 8024074C 4481C000 */  mtc1      $at, $f24
/* D63460 80240750 27A40018 */  addiu     $a0, $sp, 0x18
/* D63464 80240754 0C019EC8 */  jal       guRotateF
/* D63468 80240758 E7B80010 */   swc1     $f24, 0x10($sp)
/* D6346C 8024075C 0200202D */  daddu     $a0, $s0, $zero
/* D63470 80240760 27A50018 */  addiu     $a1, $sp, 0x18
/* D63474 80240764 0C019D80 */  jal       guMtxCatF
/* D63478 80240768 00A0302D */   daddu    $a2, $a1, $zero
/* D6347C 8024076C 4405B000 */  mfc1      $a1, $f22
/* D63480 80240770 4406A000 */  mfc1      $a2, $f20
/* D63484 80240774 4407C000 */  mfc1      $a3, $f24
/* D63488 80240778 0200202D */  daddu     $a0, $s0, $zero
/* D6348C 8024077C 0C019EC8 */  jal       guRotateF
/* D63490 80240780 E7B40010 */   swc1     $f20, 0x10($sp)
/* D63494 80240784 27A40018 */  addiu     $a0, $sp, 0x18
/* D63498 80240788 0200282D */  daddu     $a1, $s0, $zero
/* D6349C 8024078C 0C019D80 */  jal       guMtxCatF
/* D634A0 80240790 0080302D */   daddu    $a2, $a0, $zero
/* D634A4 80240794 E7B40010 */  swc1      $f20, 0x10($sp)
/* D634A8 80240798 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D634AC 8024079C 4406A000 */  mfc1      $a2, $f20
/* D634B0 802407A0 4407C000 */  mfc1      $a3, $f24
/* D634B4 802407A4 0C019EC8 */  jal       guRotateF
/* D634B8 802407A8 0200202D */   daddu    $a0, $s0, $zero
/* D634BC 802407AC 27A40018 */  addiu     $a0, $sp, 0x18
/* D634C0 802407B0 0200282D */  daddu     $a1, $s0, $zero
/* D634C4 802407B4 0C019D80 */  jal       guMtxCatF
/* D634C8 802407B8 0080302D */   daddu    $a2, $a0, $zero
/* D634CC 802407BC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D634D0 802407C0 3C013F36 */  lui       $at, 0x3f36
/* D634D4 802407C4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D634D8 802407C8 44810000 */  mtc1      $at, $f0
/* D634DC 802407CC 0200202D */  daddu     $a0, $s0, $zero
/* D634E0 802407D0 44050000 */  mfc1      $a1, $f0
/* D634E4 802407D4 3C06BF36 */  lui       $a2, 0xbf36
/* D634E8 802407D8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D634EC 802407DC 0C019DF0 */  jal       guScaleF
/* D634F0 802407E0 00A0382D */   daddu    $a3, $a1, $zero
/* D634F4 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D634F8 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D634FC 802407EC 0C019D80 */  jal       guMtxCatF
/* D63500 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D63504 802407F4 27B00058 */  addiu     $s0, $sp, 0x58
/* D63508 802407F8 8E250028 */  lw        $a1, 0x28($s1)
/* D6350C 802407FC C620002C */  lwc1      $f0, 0x2c($s1)
/* D63510 80240800 8E270030 */  lw        $a3, 0x30($s1)
/* D63514 80240804 46000007 */  neg.s     $f0, $f0
/* D63518 80240808 44060000 */  mfc1      $a2, $f0
/* D6351C 8024080C 0C019E40 */  jal       guTranslateF
/* D63520 80240810 0200202D */   daddu    $a0, $s0, $zero
/* D63524 80240814 27A40018 */  addiu     $a0, $sp, 0x18
/* D63528 80240818 0200282D */  daddu     $a1, $s0, $zero
/* D6352C 8024081C 0C019D80 */  jal       guMtxCatF
/* D63530 80240820 0080302D */   daddu    $a2, $a0, $zero
/* D63534 80240824 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D63538 80240828 3C0142B4 */  lui       $at, 0x42b4
/* D6353C 8024082C 44810000 */  mtc1      $at, $f0
/* D63540 80240830 00000000 */  nop
/* D63544 80240834 4602003E */  c.le.s    $f0, $f2
/* D63548 80240838 00000000 */  nop
/* D6354C 8024083C 4500000A */  bc1f      .L80240868
/* D63550 80240840 24040001 */   addiu    $a0, $zero, 1
/* D63554 80240844 3C014387 */  lui       $at, 0x4387
/* D63558 80240848 44810000 */  mtc1      $at, $f0
/* D6355C 8024084C 00000000 */  nop
/* D63560 80240850 4600103C */  c.lt.s    $f2, $f0
/* D63564 80240854 00000000 */  nop
/* D63568 80240858 45000004 */  bc1f      .L8024086C
/* D6356C 8024085C 27A20018 */   addiu    $v0, $sp, 0x18
/* D63570 80240860 3C041000 */  lui       $a0, 0x1000
/* D63574 80240864 34840001 */  ori       $a0, $a0, 1
.L80240868:
/* D63578 80240868 27A20018 */  addiu     $v0, $sp, 0x18
.L8024086C:
/* D6357C 8024086C 0000282D */  daddu     $a1, $zero, $zero
/* D63580 80240870 00A0302D */  daddu     $a2, $a1, $zero
/* D63584 80240874 00A0382D */  daddu     $a3, $a1, $zero
/* D63588 80240878 0C0B7710 */  jal       render_sprite
/* D6358C 8024087C AFA20010 */   sw       $v0, 0x10($sp)
/* D63590 80240880 8FBF0120 */  lw        $ra, 0x120($sp)
/* D63594 80240884 8FB1011C */  lw        $s1, 0x11c($sp)
/* D63598 80240888 8FB00118 */  lw        $s0, 0x118($sp)
/* D6359C 8024088C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D635A0 80240890 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D635A4 80240894 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D635A8 80240898 03E00008 */  jr        $ra
/* D635AC 8024089C 27BD0140 */   addiu    $sp, $sp, 0x140
