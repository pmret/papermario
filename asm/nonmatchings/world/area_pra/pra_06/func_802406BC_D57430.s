.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_D57AEC
/* D57AEC 802406BC 3C03800A */  lui       $v1, 0x800a
/* D57AF0 802406C0 8463A634 */  lh        $v1, -0x59cc($v1)
/* D57AF4 802406C4 3C07BF80 */  lui       $a3, 0xbf80
/* D57AF8 802406C8 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D57AFC 802406CC F7B40128 */  sdc1      $f20, 0x128($sp)
/* D57B00 802406D0 4480A000 */  mtc1      $zero, $f20
/* D57B04 802406D4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D57B08 802406D8 0080882D */  daddu     $s1, $a0, $zero
/* D57B0C 802406DC AFB00118 */  sw        $s0, 0x118($sp)
/* D57B10 802406E0 27B00098 */  addiu     $s0, $sp, 0x98
/* D57B14 802406E4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D57B18 802406E8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D57B1C 802406EC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D57B20 802406F0 00031080 */  sll       $v0, $v1, 2
/* D57B24 802406F4 00431021 */  addu      $v0, $v0, $v1
/* D57B28 802406F8 00021080 */  sll       $v0, $v0, 2
/* D57B2C 802406FC 00431023 */  subu      $v0, $v0, $v1
/* D57B30 80240700 000218C0 */  sll       $v1, $v0, 3
/* D57B34 80240704 00431021 */  addu      $v0, $v0, $v1
/* D57B38 80240708 000210C0 */  sll       $v0, $v0, 3
/* D57B3C 8024070C 3C01800B */  lui       $at, 0x800b
/* D57B40 80240710 00220821 */  addu      $at, $at, $v0
/* D57B44 80240714 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D57B48 80240718 4406A000 */  mfc1      $a2, $f20
/* D57B4C 8024071C 4600B587 */  neg.s     $f22, $f22
/* D57B50 80240720 4405B000 */  mfc1      $a1, $f22
/* D57B54 80240724 0200202D */  daddu     $a0, $s0, $zero
/* D57B58 80240728 0C019EC8 */  jal       guRotateF
/* D57B5C 8024072C E7B40010 */   swc1     $f20, 0x10($sp)
/* D57B60 80240730 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D57B64 80240734 0C00A6C9 */  jal       clamp_angle
/* D57B68 80240738 00000000 */   nop      
/* D57B6C 8024073C 44050000 */  mfc1      $a1, $f0
/* D57B70 80240740 4406A000 */  mfc1      $a2, $f20
/* D57B74 80240744 4407A000 */  mfc1      $a3, $f20
/* D57B78 80240748 3C013F80 */  lui       $at, 0x3f80
/* D57B7C 8024074C 4481C000 */  mtc1      $at, $f24
/* D57B80 80240750 27A40018 */  addiu     $a0, $sp, 0x18
/* D57B84 80240754 0C019EC8 */  jal       guRotateF
/* D57B88 80240758 E7B80010 */   swc1     $f24, 0x10($sp)
/* D57B8C 8024075C 0200202D */  daddu     $a0, $s0, $zero
/* D57B90 80240760 27A50018 */  addiu     $a1, $sp, 0x18
/* D57B94 80240764 0C019D80 */  jal       guMtxCatF
/* D57B98 80240768 00A0302D */   daddu    $a2, $a1, $zero
/* D57B9C 8024076C 4405B000 */  mfc1      $a1, $f22
/* D57BA0 80240770 4406A000 */  mfc1      $a2, $f20
/* D57BA4 80240774 4407C000 */  mfc1      $a3, $f24
/* D57BA8 80240778 0200202D */  daddu     $a0, $s0, $zero
/* D57BAC 8024077C 0C019EC8 */  jal       guRotateF
/* D57BB0 80240780 E7B40010 */   swc1     $f20, 0x10($sp)
/* D57BB4 80240784 27A40018 */  addiu     $a0, $sp, 0x18
/* D57BB8 80240788 0200282D */  daddu     $a1, $s0, $zero
/* D57BBC 8024078C 0C019D80 */  jal       guMtxCatF
/* D57BC0 80240790 0080302D */   daddu    $a2, $a0, $zero
/* D57BC4 80240794 E7B40010 */  swc1      $f20, 0x10($sp)
/* D57BC8 80240798 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D57BCC 8024079C 4406A000 */  mfc1      $a2, $f20
/* D57BD0 802407A0 4407C000 */  mfc1      $a3, $f24
/* D57BD4 802407A4 0C019EC8 */  jal       guRotateF
/* D57BD8 802407A8 0200202D */   daddu    $a0, $s0, $zero
/* D57BDC 802407AC 27A40018 */  addiu     $a0, $sp, 0x18
/* D57BE0 802407B0 0200282D */  daddu     $a1, $s0, $zero
/* D57BE4 802407B4 0C019D80 */  jal       guMtxCatF
/* D57BE8 802407B8 0080302D */   daddu    $a2, $a0, $zero
/* D57BEC 802407BC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D57BF0 802407C0 3C013F36 */  lui       $at, 0x3f36
/* D57BF4 802407C4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D57BF8 802407C8 44810000 */  mtc1      $at, $f0
/* D57BFC 802407CC 0200202D */  daddu     $a0, $s0, $zero
/* D57C00 802407D0 44050000 */  mfc1      $a1, $f0
/* D57C04 802407D4 3C06BF36 */  lui       $a2, 0xbf36
/* D57C08 802407D8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D57C0C 802407DC 0C019DF0 */  jal       guScaleF
/* D57C10 802407E0 00A0382D */   daddu    $a3, $a1, $zero
/* D57C14 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D57C18 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D57C1C 802407EC 0C019D80 */  jal       guMtxCatF
/* D57C20 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D57C24 802407F4 27B00058 */  addiu     $s0, $sp, 0x58
/* D57C28 802407F8 8E250028 */  lw        $a1, 0x28($s1)
/* D57C2C 802407FC C620002C */  lwc1      $f0, 0x2c($s1)
/* D57C30 80240800 8E270030 */  lw        $a3, 0x30($s1)
/* D57C34 80240804 46000007 */  neg.s     $f0, $f0
/* D57C38 80240808 44060000 */  mfc1      $a2, $f0
/* D57C3C 8024080C 0C019E40 */  jal       guTranslateF
/* D57C40 80240810 0200202D */   daddu    $a0, $s0, $zero
/* D57C44 80240814 27A40018 */  addiu     $a0, $sp, 0x18
/* D57C48 80240818 0200282D */  daddu     $a1, $s0, $zero
/* D57C4C 8024081C 0C019D80 */  jal       guMtxCatF
/* D57C50 80240820 0080302D */   daddu    $a2, $a0, $zero
/* D57C54 80240824 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D57C58 80240828 3C0142B4 */  lui       $at, 0x42b4
/* D57C5C 8024082C 44810000 */  mtc1      $at, $f0
/* D57C60 80240830 00000000 */  nop       
/* D57C64 80240834 4602003E */  c.le.s    $f0, $f2
/* D57C68 80240838 00000000 */  nop       
/* D57C6C 8024083C 4500000A */  bc1f      .L80240868
/* D57C70 80240840 24040001 */   addiu    $a0, $zero, 1
/* D57C74 80240844 3C014387 */  lui       $at, 0x4387
/* D57C78 80240848 44810000 */  mtc1      $at, $f0
/* D57C7C 8024084C 00000000 */  nop       
/* D57C80 80240850 4600103C */  c.lt.s    $f2, $f0
/* D57C84 80240854 00000000 */  nop       
/* D57C88 80240858 45000004 */  bc1f      .L8024086C
/* D57C8C 8024085C 27A20018 */   addiu    $v0, $sp, 0x18
/* D57C90 80240860 3C041000 */  lui       $a0, 0x1000
/* D57C94 80240864 34840001 */  ori       $a0, $a0, 1
.L80240868:
/* D57C98 80240868 27A20018 */  addiu     $v0, $sp, 0x18
.L8024086C:
/* D57C9C 8024086C 0000282D */  daddu     $a1, $zero, $zero
/* D57CA0 80240870 00A0302D */  daddu     $a2, $a1, $zero
/* D57CA4 80240874 00A0382D */  daddu     $a3, $a1, $zero
/* D57CA8 80240878 0C0B7710 */  jal       render_sprite
/* D57CAC 8024087C AFA20010 */   sw       $v0, 0x10($sp)
/* D57CB0 80240880 8FBF0120 */  lw        $ra, 0x120($sp)
/* D57CB4 80240884 8FB1011C */  lw        $s1, 0x11c($sp)
/* D57CB8 80240888 8FB00118 */  lw        $s0, 0x118($sp)
/* D57CBC 8024088C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D57CC0 80240890 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D57CC4 80240894 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D57CC8 80240898 03E00008 */  jr        $ra
/* D57CCC 8024089C 27BD0140 */   addiu    $sp, $sp, 0x140
