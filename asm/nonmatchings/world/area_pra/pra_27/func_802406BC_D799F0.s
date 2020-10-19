.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_D7A0AC
/* D7A0AC 802406BC 3C03800A */  lui       $v1, 0x800a
/* D7A0B0 802406C0 8463A634 */  lh        $v1, -0x59cc($v1)
/* D7A0B4 802406C4 3C07BF80 */  lui       $a3, 0xbf80
/* D7A0B8 802406C8 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D7A0BC 802406CC F7B40128 */  sdc1      $f20, 0x128($sp)
/* D7A0C0 802406D0 4480A000 */  mtc1      $zero, $f20
/* D7A0C4 802406D4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D7A0C8 802406D8 0080882D */  daddu     $s1, $a0, $zero
/* D7A0CC 802406DC AFB00118 */  sw        $s0, 0x118($sp)
/* D7A0D0 802406E0 27B00098 */  addiu     $s0, $sp, 0x98
/* D7A0D4 802406E4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D7A0D8 802406E8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D7A0DC 802406EC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D7A0E0 802406F0 00031080 */  sll       $v0, $v1, 2
/* D7A0E4 802406F4 00431021 */  addu      $v0, $v0, $v1
/* D7A0E8 802406F8 00021080 */  sll       $v0, $v0, 2
/* D7A0EC 802406FC 00431023 */  subu      $v0, $v0, $v1
/* D7A0F0 80240700 000218C0 */  sll       $v1, $v0, 3
/* D7A0F4 80240704 00431021 */  addu      $v0, $v0, $v1
/* D7A0F8 80240708 000210C0 */  sll       $v0, $v0, 3
/* D7A0FC 8024070C 3C01800B */  lui       $at, 0x800b
/* D7A100 80240710 00220821 */  addu      $at, $at, $v0
/* D7A104 80240714 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D7A108 80240718 4406A000 */  mfc1      $a2, $f20
/* D7A10C 8024071C 4600B587 */  neg.s     $f22, $f22
/* D7A110 80240720 4405B000 */  mfc1      $a1, $f22
/* D7A114 80240724 0200202D */  daddu     $a0, $s0, $zero
/* D7A118 80240728 0C019EC8 */  jal       guRotateF
/* D7A11C 8024072C E7B40010 */   swc1     $f20, 0x10($sp)
/* D7A120 80240730 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D7A124 80240734 0C00A6C9 */  jal       clamp_angle
/* D7A128 80240738 00000000 */   nop      
/* D7A12C 8024073C 44050000 */  mfc1      $a1, $f0
/* D7A130 80240740 4406A000 */  mfc1      $a2, $f20
/* D7A134 80240744 4407A000 */  mfc1      $a3, $f20
/* D7A138 80240748 3C013F80 */  lui       $at, 0x3f80
/* D7A13C 8024074C 4481C000 */  mtc1      $at, $f24
/* D7A140 80240750 27A40018 */  addiu     $a0, $sp, 0x18
/* D7A144 80240754 0C019EC8 */  jal       guRotateF
/* D7A148 80240758 E7B80010 */   swc1     $f24, 0x10($sp)
/* D7A14C 8024075C 0200202D */  daddu     $a0, $s0, $zero
/* D7A150 80240760 27A50018 */  addiu     $a1, $sp, 0x18
/* D7A154 80240764 0C019D80 */  jal       guMtxCatF
/* D7A158 80240768 00A0302D */   daddu    $a2, $a1, $zero
/* D7A15C 8024076C 4405B000 */  mfc1      $a1, $f22
/* D7A160 80240770 4406A000 */  mfc1      $a2, $f20
/* D7A164 80240774 4407C000 */  mfc1      $a3, $f24
/* D7A168 80240778 0200202D */  daddu     $a0, $s0, $zero
/* D7A16C 8024077C 0C019EC8 */  jal       guRotateF
/* D7A170 80240780 E7B40010 */   swc1     $f20, 0x10($sp)
/* D7A174 80240784 27A40018 */  addiu     $a0, $sp, 0x18
/* D7A178 80240788 0200282D */  daddu     $a1, $s0, $zero
/* D7A17C 8024078C 0C019D80 */  jal       guMtxCatF
/* D7A180 80240790 0080302D */   daddu    $a2, $a0, $zero
/* D7A184 80240794 E7B40010 */  swc1      $f20, 0x10($sp)
/* D7A188 80240798 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D7A18C 8024079C 4406A000 */  mfc1      $a2, $f20
/* D7A190 802407A0 4407C000 */  mfc1      $a3, $f24
/* D7A194 802407A4 0C019EC8 */  jal       guRotateF
/* D7A198 802407A8 0200202D */   daddu    $a0, $s0, $zero
/* D7A19C 802407AC 27A40018 */  addiu     $a0, $sp, 0x18
/* D7A1A0 802407B0 0200282D */  daddu     $a1, $s0, $zero
/* D7A1A4 802407B4 0C019D80 */  jal       guMtxCatF
/* D7A1A8 802407B8 0080302D */   daddu    $a2, $a0, $zero
/* D7A1AC 802407BC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D7A1B0 802407C0 3C013F36 */  lui       $at, 0x3f36
/* D7A1B4 802407C4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D7A1B8 802407C8 44810000 */  mtc1      $at, $f0
/* D7A1BC 802407CC 0200202D */  daddu     $a0, $s0, $zero
/* D7A1C0 802407D0 44050000 */  mfc1      $a1, $f0
/* D7A1C4 802407D4 3C06BF36 */  lui       $a2, 0xbf36
/* D7A1C8 802407D8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D7A1CC 802407DC 0C019DF0 */  jal       guScaleF
/* D7A1D0 802407E0 00A0382D */   daddu    $a3, $a1, $zero
/* D7A1D4 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D7A1D8 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D7A1DC 802407EC 0C019D80 */  jal       guMtxCatF
/* D7A1E0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D7A1E4 802407F4 27B00058 */  addiu     $s0, $sp, 0x58
/* D7A1E8 802407F8 8E250028 */  lw        $a1, 0x28($s1)
/* D7A1EC 802407FC C620002C */  lwc1      $f0, 0x2c($s1)
/* D7A1F0 80240800 8E270030 */  lw        $a3, 0x30($s1)
/* D7A1F4 80240804 46000007 */  neg.s     $f0, $f0
/* D7A1F8 80240808 44060000 */  mfc1      $a2, $f0
/* D7A1FC 8024080C 0C019E40 */  jal       guTranslateF
/* D7A200 80240810 0200202D */   daddu    $a0, $s0, $zero
/* D7A204 80240814 27A40018 */  addiu     $a0, $sp, 0x18
/* D7A208 80240818 0200282D */  daddu     $a1, $s0, $zero
/* D7A20C 8024081C 0C019D80 */  jal       guMtxCatF
/* D7A210 80240820 0080302D */   daddu    $a2, $a0, $zero
/* D7A214 80240824 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D7A218 80240828 3C0142B4 */  lui       $at, 0x42b4
/* D7A21C 8024082C 44810000 */  mtc1      $at, $f0
/* D7A220 80240830 00000000 */  nop       
/* D7A224 80240834 4602003E */  c.le.s    $f0, $f2
/* D7A228 80240838 00000000 */  nop       
/* D7A22C 8024083C 4500000A */  bc1f      .L80240868
/* D7A230 80240840 24040001 */   addiu    $a0, $zero, 1
/* D7A234 80240844 3C014387 */  lui       $at, 0x4387
/* D7A238 80240848 44810000 */  mtc1      $at, $f0
/* D7A23C 8024084C 00000000 */  nop       
/* D7A240 80240850 4600103C */  c.lt.s    $f2, $f0
/* D7A244 80240854 00000000 */  nop       
/* D7A248 80240858 45000004 */  bc1f      .L8024086C
/* D7A24C 8024085C 27A20018 */   addiu    $v0, $sp, 0x18
/* D7A250 80240860 3C041000 */  lui       $a0, 0x1000
/* D7A254 80240864 34840001 */  ori       $a0, $a0, 1
.L80240868:
/* D7A258 80240868 27A20018 */  addiu     $v0, $sp, 0x18
.L8024086C:
/* D7A25C 8024086C 0000282D */  daddu     $a1, $zero, $zero
/* D7A260 80240870 00A0302D */  daddu     $a2, $a1, $zero
/* D7A264 80240874 00A0382D */  daddu     $a3, $a1, $zero
/* D7A268 80240878 0C0B7710 */  jal       render_sprite
/* D7A26C 8024087C AFA20010 */   sw       $v0, 0x10($sp)
/* D7A270 80240880 8FBF0120 */  lw        $ra, 0x120($sp)
/* D7A274 80240884 8FB1011C */  lw        $s1, 0x11c($sp)
/* D7A278 80240888 8FB00118 */  lw        $s0, 0x118($sp)
/* D7A27C 8024088C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D7A280 80240890 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D7A284 80240894 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D7A288 80240898 03E00008 */  jr        $ra
/* D7A28C 8024089C 27BD0140 */   addiu    $sp, $sp, 0x140
