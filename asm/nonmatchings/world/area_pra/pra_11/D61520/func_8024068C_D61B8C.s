.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D61B8C
/* D61B8C 8024068C 3C03800A */  lui       $v1, 0x800a
/* D61B90 80240690 8463A634 */  lh        $v1, -0x59cc($v1)
/* D61B94 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D61B98 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D61B9C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D61BA0 802406A0 4480A000 */  mtc1      $zero, $f20
/* D61BA4 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D61BA8 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D61BAC 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D61BB0 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D61BB4 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D61BB8 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D61BBC 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D61BC0 802406C0 00031080 */  sll       $v0, $v1, 2
/* D61BC4 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D61BC8 802406C8 00021080 */  sll       $v0, $v0, 2
/* D61BCC 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D61BD0 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D61BD4 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D61BD8 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D61BDC 802406DC 3C01800B */  lui       $at, 0x800b
/* D61BE0 802406E0 00220821 */  addu      $at, $at, $v0
/* D61BE4 802406E4 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D61BE8 802406E8 4406A000 */  mfc1      $a2, $f20
/* D61BEC 802406EC 4600B587 */  neg.s     $f22, $f22
/* D61BF0 802406F0 4405B000 */  mfc1      $a1, $f22
/* D61BF4 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D61BF8 802406F8 0C019EC8 */  jal       guRotateF
/* D61BFC 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D61C00 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D61C04 80240704 0C00A6C9 */  jal       clamp_angle
/* D61C08 80240708 00000000 */   nop      
/* D61C0C 8024070C 44050000 */  mfc1      $a1, $f0
/* D61C10 80240710 4406A000 */  mfc1      $a2, $f20
/* D61C14 80240714 4407A000 */  mfc1      $a3, $f20
/* D61C18 80240718 3C013F80 */  lui       $at, 0x3f80
/* D61C1C 8024071C 4481C000 */  mtc1      $at, $f24
/* D61C20 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D61C24 80240724 0C019EC8 */  jal       guRotateF
/* D61C28 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D61C2C 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D61C30 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D61C34 80240734 0C019D80 */  jal       guMtxCatF
/* D61C38 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D61C3C 8024073C 4405B000 */  mfc1      $a1, $f22
/* D61C40 80240740 4406A000 */  mfc1      $a2, $f20
/* D61C44 80240744 4407C000 */  mfc1      $a3, $f24
/* D61C48 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D61C4C 8024074C 0C019EC8 */  jal       guRotateF
/* D61C50 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D61C54 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D61C58 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D61C5C 8024075C 0C019D80 */  jal       guMtxCatF
/* D61C60 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D61C64 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D61C68 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D61C6C 8024076C 4406A000 */  mfc1      $a2, $f20
/* D61C70 80240770 4407C000 */  mfc1      $a3, $f24
/* D61C74 80240774 0C019EC8 */  jal       guRotateF
/* D61C78 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D61C7C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D61C80 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D61C84 80240784 0C019D80 */  jal       guMtxCatF
/* D61C88 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D61C8C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D61C90 80240790 3C013F36 */  lui       $at, 0x3f36
/* D61C94 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D61C98 80240798 44810000 */  mtc1      $at, $f0
/* D61C9C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D61CA0 802407A0 44050000 */  mfc1      $a1, $f0
/* D61CA4 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D61CA8 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D61CAC 802407AC 0C019DF0 */  jal       guScaleF
/* D61CB0 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D61CB4 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D61CB8 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D61CBC 802407BC 0C019D80 */  jal       guMtxCatF
/* D61CC0 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D61CC4 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D61CC8 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D61CCC 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D61CD0 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D61CD4 802407D4 46000007 */  neg.s     $f0, $f0
/* D61CD8 802407D8 44060000 */  mfc1      $a2, $f0
/* D61CDC 802407DC 0C019E40 */  jal       guTranslateF
/* D61CE0 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D61CE4 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D61CE8 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D61CEC 802407EC 0C019D80 */  jal       guMtxCatF
/* D61CF0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D61CF4 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D61CF8 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D61CFC 802407FC 44810000 */  mtc1      $at, $f0
/* D61D00 80240800 00000000 */  nop       
/* D61D04 80240804 4602003E */  c.le.s    $f0, $f2
/* D61D08 80240808 00000000 */  nop       
/* D61D0C 8024080C 4500000A */  bc1f      .L80240838
/* D61D10 80240810 24040001 */   addiu    $a0, $zero, 1
/* D61D14 80240814 3C014387 */  lui       $at, 0x4387
/* D61D18 80240818 44810000 */  mtc1      $at, $f0
/* D61D1C 8024081C 00000000 */  nop       
/* D61D20 80240820 4600103C */  c.lt.s    $f2, $f0
/* D61D24 80240824 00000000 */  nop       
/* D61D28 80240828 45000004 */  bc1f      .L8024083C
/* D61D2C 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D61D30 80240830 3C041000 */  lui       $a0, 0x1000
/* D61D34 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D61D38 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D61D3C 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D61D40 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D61D44 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D61D48 80240848 0C0B7710 */  jal       render_sprite
/* D61D4C 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D61D50 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D61D54 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D61D58 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D61D5C 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D61D60 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D61D64 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D61D68 80240868 03E00008 */  jr        $ra
/* D61D6C 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
