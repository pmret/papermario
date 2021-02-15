.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D7D1DC
/* D7D1DC 8024068C 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D7D1E0 80240690 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D7D1E4 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D7D1E8 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D7D1EC 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D7D1F0 802406A0 4480A000 */  mtc1      $zero, $f20
/* D7D1F4 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D7D1F8 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D7D1FC 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D7D200 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D7D204 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D7D208 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D7D20C 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D7D210 802406C0 00031080 */  sll       $v0, $v1, 2
/* D7D214 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D7D218 802406C8 00021080 */  sll       $v0, $v0, 2
/* D7D21C 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D7D220 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D7D224 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D7D228 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D7D22C 802406DC 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D7D230 802406E0 00220821 */  addu      $at, $at, $v0
/* D7D234 802406E4 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D7D238 802406E8 4406A000 */  mfc1      $a2, $f20
/* D7D23C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D7D240 802406F0 4405B000 */  mfc1      $a1, $f22
/* D7D244 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D7D248 802406F8 0C019EC8 */  jal       guRotateF
/* D7D24C 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D7D250 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D7D254 80240704 0C00A6C9 */  jal       clamp_angle
/* D7D258 80240708 00000000 */   nop
/* D7D25C 8024070C 44050000 */  mfc1      $a1, $f0
/* D7D260 80240710 4406A000 */  mfc1      $a2, $f20
/* D7D264 80240714 4407A000 */  mfc1      $a3, $f20
/* D7D268 80240718 3C013F80 */  lui       $at, 0x3f80
/* D7D26C 8024071C 4481C000 */  mtc1      $at, $f24
/* D7D270 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D7D274 80240724 0C019EC8 */  jal       guRotateF
/* D7D278 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D7D27C 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D7D280 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D7D284 80240734 0C019D80 */  jal       guMtxCatF
/* D7D288 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D7D28C 8024073C 4405B000 */  mfc1      $a1, $f22
/* D7D290 80240740 4406A000 */  mfc1      $a2, $f20
/* D7D294 80240744 4407C000 */  mfc1      $a3, $f24
/* D7D298 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D7D29C 8024074C 0C019EC8 */  jal       guRotateF
/* D7D2A0 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D7D2A4 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D7D2A8 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D7D2AC 8024075C 0C019D80 */  jal       guMtxCatF
/* D7D2B0 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D7D2B4 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D7D2B8 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D7D2BC 8024076C 4406A000 */  mfc1      $a2, $f20
/* D7D2C0 80240770 4407C000 */  mfc1      $a3, $f24
/* D7D2C4 80240774 0C019EC8 */  jal       guRotateF
/* D7D2C8 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D7D2CC 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D7D2D0 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D7D2D4 80240784 0C019D80 */  jal       guMtxCatF
/* D7D2D8 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D7D2DC 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D7D2E0 80240790 3C013F36 */  lui       $at, 0x3f36
/* D7D2E4 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D7D2E8 80240798 44810000 */  mtc1      $at, $f0
/* D7D2EC 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D7D2F0 802407A0 44050000 */  mfc1      $a1, $f0
/* D7D2F4 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D7D2F8 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D7D2FC 802407AC 0C019DF0 */  jal       guScaleF
/* D7D300 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D7D304 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D7D308 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D7D30C 802407BC 0C019D80 */  jal       guMtxCatF
/* D7D310 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D7D314 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D7D318 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D7D31C 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D7D320 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D7D324 802407D4 46000007 */  neg.s     $f0, $f0
/* D7D328 802407D8 44060000 */  mfc1      $a2, $f0
/* D7D32C 802407DC 0C019E40 */  jal       guTranslateF
/* D7D330 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D7D334 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D7D338 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D7D33C 802407EC 0C019D80 */  jal       guMtxCatF
/* D7D340 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D7D344 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D7D348 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D7D34C 802407FC 44810000 */  mtc1      $at, $f0
/* D7D350 80240800 00000000 */  nop
/* D7D354 80240804 4602003E */  c.le.s    $f0, $f2
/* D7D358 80240808 00000000 */  nop
/* D7D35C 8024080C 4500000A */  bc1f      .L80240838
/* D7D360 80240810 24040001 */   addiu    $a0, $zero, 1
/* D7D364 80240814 3C014387 */  lui       $at, 0x4387
/* D7D368 80240818 44810000 */  mtc1      $at, $f0
/* D7D36C 8024081C 00000000 */  nop
/* D7D370 80240820 4600103C */  c.lt.s    $f2, $f0
/* D7D374 80240824 00000000 */  nop
/* D7D378 80240828 45000004 */  bc1f      .L8024083C
/* D7D37C 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D7D380 80240830 3C041000 */  lui       $a0, 0x1000
/* D7D384 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D7D388 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D7D38C 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D7D390 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D7D394 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D7D398 80240848 0C0B7710 */  jal       render_sprite
/* D7D39C 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D7D3A0 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D7D3A4 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D7D3A8 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D7D3AC 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D7D3B0 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D7D3B4 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D7D3B8 80240868 03E00008 */  jr        $ra
/* D7D3BC 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
