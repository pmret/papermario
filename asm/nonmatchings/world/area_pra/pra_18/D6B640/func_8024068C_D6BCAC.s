.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D6BCAC
/* D6BCAC 8024068C 3C03800A */  lui       $v1, 0x800a
/* D6BCB0 80240690 8463A634 */  lh        $v1, -0x59cc($v1)
/* D6BCB4 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D6BCB8 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D6BCBC 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D6BCC0 802406A0 4480A000 */  mtc1      $zero, $f20
/* D6BCC4 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D6BCC8 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D6BCCC 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D6BCD0 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D6BCD4 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D6BCD8 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D6BCDC 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D6BCE0 802406C0 00031080 */  sll       $v0, $v1, 2
/* D6BCE4 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D6BCE8 802406C8 00021080 */  sll       $v0, $v0, 2
/* D6BCEC 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D6BCF0 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D6BCF4 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D6BCF8 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D6BCFC 802406DC 3C01800B */  lui       $at, 0x800b
/* D6BD00 802406E0 00220821 */  addu      $at, $at, $v0
/* D6BD04 802406E4 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D6BD08 802406E8 4406A000 */  mfc1      $a2, $f20
/* D6BD0C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D6BD10 802406F0 4405B000 */  mfc1      $a1, $f22
/* D6BD14 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D6BD18 802406F8 0C019EC8 */  jal       guRotateF
/* D6BD1C 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D6BD20 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D6BD24 80240704 0C00A6C9 */  jal       clamp_angle
/* D6BD28 80240708 00000000 */   nop      
/* D6BD2C 8024070C 44050000 */  mfc1      $a1, $f0
/* D6BD30 80240710 4406A000 */  mfc1      $a2, $f20
/* D6BD34 80240714 4407A000 */  mfc1      $a3, $f20
/* D6BD38 80240718 3C013F80 */  lui       $at, 0x3f80
/* D6BD3C 8024071C 4481C000 */  mtc1      $at, $f24
/* D6BD40 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D6BD44 80240724 0C019EC8 */  jal       guRotateF
/* D6BD48 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D6BD4C 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D6BD50 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D6BD54 80240734 0C019D80 */  jal       guMtxCatF
/* D6BD58 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D6BD5C 8024073C 4405B000 */  mfc1      $a1, $f22
/* D6BD60 80240740 4406A000 */  mfc1      $a2, $f20
/* D6BD64 80240744 4407C000 */  mfc1      $a3, $f24
/* D6BD68 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D6BD6C 8024074C 0C019EC8 */  jal       guRotateF
/* D6BD70 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D6BD74 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D6BD78 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D6BD7C 8024075C 0C019D80 */  jal       guMtxCatF
/* D6BD80 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D6BD84 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D6BD88 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D6BD8C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D6BD90 80240770 4407C000 */  mfc1      $a3, $f24
/* D6BD94 80240774 0C019EC8 */  jal       guRotateF
/* D6BD98 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D6BD9C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D6BDA0 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D6BDA4 80240784 0C019D80 */  jal       guMtxCatF
/* D6BDA8 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D6BDAC 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D6BDB0 80240790 3C013F36 */  lui       $at, 0x3f36
/* D6BDB4 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D6BDB8 80240798 44810000 */  mtc1      $at, $f0
/* D6BDBC 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D6BDC0 802407A0 44050000 */  mfc1      $a1, $f0
/* D6BDC4 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D6BDC8 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D6BDCC 802407AC 0C019DF0 */  jal       guScaleF
/* D6BDD0 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D6BDD4 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D6BDD8 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D6BDDC 802407BC 0C019D80 */  jal       guMtxCatF
/* D6BDE0 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D6BDE4 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D6BDE8 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D6BDEC 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D6BDF0 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D6BDF4 802407D4 46000007 */  neg.s     $f0, $f0
/* D6BDF8 802407D8 44060000 */  mfc1      $a2, $f0
/* D6BDFC 802407DC 0C019E40 */  jal       guTranslateF
/* D6BE00 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D6BE04 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D6BE08 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D6BE0C 802407EC 0C019D80 */  jal       guMtxCatF
/* D6BE10 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D6BE14 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D6BE18 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D6BE1C 802407FC 44810000 */  mtc1      $at, $f0
/* D6BE20 80240800 00000000 */  nop       
/* D6BE24 80240804 4602003E */  c.le.s    $f0, $f2
/* D6BE28 80240808 00000000 */  nop       
/* D6BE2C 8024080C 4500000A */  bc1f      .L80240838
/* D6BE30 80240810 24040001 */   addiu    $a0, $zero, 1
/* D6BE34 80240814 3C014387 */  lui       $at, 0x4387
/* D6BE38 80240818 44810000 */  mtc1      $at, $f0
/* D6BE3C 8024081C 00000000 */  nop       
/* D6BE40 80240820 4600103C */  c.lt.s    $f2, $f0
/* D6BE44 80240824 00000000 */  nop       
/* D6BE48 80240828 45000004 */  bc1f      .L8024083C
/* D6BE4C 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D6BE50 80240830 3C041000 */  lui       $a0, 0x1000
/* D6BE54 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D6BE58 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D6BE5C 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D6BE60 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D6BE64 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D6BE68 80240848 0C0B7710 */  jal       render_sprite
/* D6BE6C 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D6BE70 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D6BE74 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D6BE78 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D6BE7C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D6BE80 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D6BE84 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D6BE88 80240868 03E00008 */  jr        $ra
/* D6BE8C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
