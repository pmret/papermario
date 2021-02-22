.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D64C6C
/* D64C6C 8024068C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D64C70 80240690 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D64C74 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D64C78 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D64C7C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D64C80 802406A0 4480A000 */  mtc1      $zero, $f20
/* D64C84 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D64C88 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D64C8C 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D64C90 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D64C94 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D64C98 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D64C9C 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D64CA0 802406C0 00031080 */  sll       $v0, $v1, 2
/* D64CA4 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D64CA8 802406C8 00021080 */  sll       $v0, $v0, 2
/* D64CAC 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D64CB0 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D64CB4 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D64CB8 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D64CBC 802406DC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D64CC0 802406E0 00220821 */  addu      $at, $at, $v0
/* D64CC4 802406E4 C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* D64CC8 802406E8 4406A000 */  mfc1      $a2, $f20
/* D64CCC 802406EC 4600B587 */  neg.s     $f22, $f22
/* D64CD0 802406F0 4405B000 */  mfc1      $a1, $f22
/* D64CD4 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D64CD8 802406F8 0C019EC8 */  jal       guRotateF
/* D64CDC 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D64CE0 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D64CE4 80240704 0C00A6C9 */  jal       clamp_angle
/* D64CE8 80240708 00000000 */   nop
/* D64CEC 8024070C 44050000 */  mfc1      $a1, $f0
/* D64CF0 80240710 4406A000 */  mfc1      $a2, $f20
/* D64CF4 80240714 4407A000 */  mfc1      $a3, $f20
/* D64CF8 80240718 3C013F80 */  lui       $at, 0x3f80
/* D64CFC 8024071C 4481C000 */  mtc1      $at, $f24
/* D64D00 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D64D04 80240724 0C019EC8 */  jal       guRotateF
/* D64D08 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D64D0C 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D64D10 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D64D14 80240734 0C019D80 */  jal       guMtxCatF
/* D64D18 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D64D1C 8024073C 4405B000 */  mfc1      $a1, $f22
/* D64D20 80240740 4406A000 */  mfc1      $a2, $f20
/* D64D24 80240744 4407C000 */  mfc1      $a3, $f24
/* D64D28 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D64D2C 8024074C 0C019EC8 */  jal       guRotateF
/* D64D30 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D64D34 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D64D38 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D64D3C 8024075C 0C019D80 */  jal       guMtxCatF
/* D64D40 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D64D44 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D64D48 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D64D4C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D64D50 80240770 4407C000 */  mfc1      $a3, $f24
/* D64D54 80240774 0C019EC8 */  jal       guRotateF
/* D64D58 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D64D5C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D64D60 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D64D64 80240784 0C019D80 */  jal       guMtxCatF
/* D64D68 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D64D6C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D64D70 80240790 3C013F36 */  lui       $at, 0x3f36
/* D64D74 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D64D78 80240798 44810000 */  mtc1      $at, $f0
/* D64D7C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D64D80 802407A0 44050000 */  mfc1      $a1, $f0
/* D64D84 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D64D88 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D64D8C 802407AC 0C019DF0 */  jal       guScaleF
/* D64D90 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D64D94 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D64D98 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D64D9C 802407BC 0C019D80 */  jal       guMtxCatF
/* D64DA0 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D64DA4 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D64DA8 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D64DAC 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D64DB0 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D64DB4 802407D4 46000007 */  neg.s     $f0, $f0
/* D64DB8 802407D8 44060000 */  mfc1      $a2, $f0
/* D64DBC 802407DC 0C019E40 */  jal       guTranslateF
/* D64DC0 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D64DC4 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D64DC8 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D64DCC 802407EC 0C019D80 */  jal       guMtxCatF
/* D64DD0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D64DD4 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D64DD8 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D64DDC 802407FC 44810000 */  mtc1      $at, $f0
/* D64DE0 80240800 00000000 */  nop
/* D64DE4 80240804 4602003E */  c.le.s    $f0, $f2
/* D64DE8 80240808 00000000 */  nop
/* D64DEC 8024080C 4500000A */  bc1f      .L80240838
/* D64DF0 80240810 24040001 */   addiu    $a0, $zero, 1
/* D64DF4 80240814 3C014387 */  lui       $at, 0x4387
/* D64DF8 80240818 44810000 */  mtc1      $at, $f0
/* D64DFC 8024081C 00000000 */  nop
/* D64E00 80240820 4600103C */  c.lt.s    $f2, $f0
/* D64E04 80240824 00000000 */  nop
/* D64E08 80240828 45000004 */  bc1f      .L8024083C
/* D64E0C 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D64E10 80240830 3C041000 */  lui       $a0, 0x1000
/* D64E14 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D64E18 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D64E1C 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D64E20 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D64E24 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D64E28 80240848 0C0B7710 */  jal       render_sprite
/* D64E2C 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D64E30 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D64E34 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D64E38 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D64E3C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D64E40 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D64E44 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D64E48 80240868 03E00008 */  jr        $ra
/* D64E4C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
