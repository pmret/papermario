.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024068C_D58F1C
/* D58F1C 8024068C 3C03800A */  lui       $v1, 0x800a
/* D58F20 80240690 8463A634 */  lh        $v1, -0x59cc($v1)
/* D58F24 80240694 3C07BF80 */  lui       $a3, 0xbf80
/* D58F28 80240698 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D58F2C 8024069C F7B40128 */  sdc1      $f20, 0x128($sp)
/* D58F30 802406A0 4480A000 */  mtc1      $zero, $f20
/* D58F34 802406A4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D58F38 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* D58F3C 802406AC AFB00118 */  sw        $s0, 0x118($sp)
/* D58F40 802406B0 27B00098 */  addiu     $s0, $sp, 0x98
/* D58F44 802406B4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D58F48 802406B8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D58F4C 802406BC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D58F50 802406C0 00031080 */  sll       $v0, $v1, 2
/* D58F54 802406C4 00431021 */  addu      $v0, $v0, $v1
/* D58F58 802406C8 00021080 */  sll       $v0, $v0, 2
/* D58F5C 802406CC 00431023 */  subu      $v0, $v0, $v1
/* D58F60 802406D0 000218C0 */  sll       $v1, $v0, 3
/* D58F64 802406D4 00431021 */  addu      $v0, $v0, $v1
/* D58F68 802406D8 000210C0 */  sll       $v0, $v0, 3
/* D58F6C 802406DC 3C01800B */  lui       $at, 0x800b
/* D58F70 802406E0 00220821 */  addu      $at, $at, $v0
/* D58F74 802406E4 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D58F78 802406E8 4406A000 */  mfc1      $a2, $f20
/* D58F7C 802406EC 4600B587 */  neg.s     $f22, $f22
/* D58F80 802406F0 4405B000 */  mfc1      $a1, $f22
/* D58F84 802406F4 0200202D */  daddu     $a0, $s0, $zero
/* D58F88 802406F8 0C019EC8 */  jal       guRotateF
/* D58F8C 802406FC E7B40010 */   swc1     $f20, 0x10($sp)
/* D58F90 80240700 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D58F94 80240704 0C00A6C9 */  jal       clamp_angle
/* D58F98 80240708 00000000 */   nop      
/* D58F9C 8024070C 44050000 */  mfc1      $a1, $f0
/* D58FA0 80240710 4406A000 */  mfc1      $a2, $f20
/* D58FA4 80240714 4407A000 */  mfc1      $a3, $f20
/* D58FA8 80240718 3C013F80 */  lui       $at, 0x3f80
/* D58FAC 8024071C 4481C000 */  mtc1      $at, $f24
/* D58FB0 80240720 27A40018 */  addiu     $a0, $sp, 0x18
/* D58FB4 80240724 0C019EC8 */  jal       guRotateF
/* D58FB8 80240728 E7B80010 */   swc1     $f24, 0x10($sp)
/* D58FBC 8024072C 0200202D */  daddu     $a0, $s0, $zero
/* D58FC0 80240730 27A50018 */  addiu     $a1, $sp, 0x18
/* D58FC4 80240734 0C019D80 */  jal       guMtxCatF
/* D58FC8 80240738 00A0302D */   daddu    $a2, $a1, $zero
/* D58FCC 8024073C 4405B000 */  mfc1      $a1, $f22
/* D58FD0 80240740 4406A000 */  mfc1      $a2, $f20
/* D58FD4 80240744 4407C000 */  mfc1      $a3, $f24
/* D58FD8 80240748 0200202D */  daddu     $a0, $s0, $zero
/* D58FDC 8024074C 0C019EC8 */  jal       guRotateF
/* D58FE0 80240750 E7B40010 */   swc1     $f20, 0x10($sp)
/* D58FE4 80240754 27A40018 */  addiu     $a0, $sp, 0x18
/* D58FE8 80240758 0200282D */  daddu     $a1, $s0, $zero
/* D58FEC 8024075C 0C019D80 */  jal       guMtxCatF
/* D58FF0 80240760 0080302D */   daddu    $a2, $a0, $zero
/* D58FF4 80240764 E7B40010 */  swc1      $f20, 0x10($sp)
/* D58FF8 80240768 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D58FFC 8024076C 4406A000 */  mfc1      $a2, $f20
/* D59000 80240770 4407C000 */  mfc1      $a3, $f24
/* D59004 80240774 0C019EC8 */  jal       guRotateF
/* D59008 80240778 0200202D */   daddu    $a0, $s0, $zero
/* D5900C 8024077C 27A40018 */  addiu     $a0, $sp, 0x18
/* D59010 80240780 0200282D */  daddu     $a1, $s0, $zero
/* D59014 80240784 0C019D80 */  jal       guMtxCatF
/* D59018 80240788 0080302D */   daddu    $a2, $a0, $zero
/* D5901C 8024078C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D59020 80240790 3C013F36 */  lui       $at, 0x3f36
/* D59024 80240794 3421DB6E */  ori       $at, $at, 0xdb6e
/* D59028 80240798 44810000 */  mtc1      $at, $f0
/* D5902C 8024079C 0200202D */  daddu     $a0, $s0, $zero
/* D59030 802407A0 44050000 */  mfc1      $a1, $f0
/* D59034 802407A4 3C06BF36 */  lui       $a2, 0xbf36
/* D59038 802407A8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D5903C 802407AC 0C019DF0 */  jal       guScaleF
/* D59040 802407B0 00A0382D */   daddu    $a3, $a1, $zero
/* D59044 802407B4 27A40018 */  addiu     $a0, $sp, 0x18
/* D59048 802407B8 0200282D */  daddu     $a1, $s0, $zero
/* D5904C 802407BC 0C019D80 */  jal       guMtxCatF
/* D59050 802407C0 0080302D */   daddu    $a2, $a0, $zero
/* D59054 802407C4 27B00058 */  addiu     $s0, $sp, 0x58
/* D59058 802407C8 8E250028 */  lw        $a1, 0x28($s1)
/* D5905C 802407CC C620002C */  lwc1      $f0, 0x2c($s1)
/* D59060 802407D0 8E270030 */  lw        $a3, 0x30($s1)
/* D59064 802407D4 46000007 */  neg.s     $f0, $f0
/* D59068 802407D8 44060000 */  mfc1      $a2, $f0
/* D5906C 802407DC 0C019E40 */  jal       guTranslateF
/* D59070 802407E0 0200202D */   daddu    $a0, $s0, $zero
/* D59074 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D59078 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D5907C 802407EC 0C019D80 */  jal       guMtxCatF
/* D59080 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D59084 802407F4 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D59088 802407F8 3C0142B4 */  lui       $at, 0x42b4
/* D5908C 802407FC 44810000 */  mtc1      $at, $f0
/* D59090 80240800 00000000 */  nop       
/* D59094 80240804 4602003E */  c.le.s    $f0, $f2
/* D59098 80240808 00000000 */  nop       
/* D5909C 8024080C 4500000A */  bc1f      .L80240838
/* D590A0 80240810 24040001 */   addiu    $a0, $zero, 1
/* D590A4 80240814 3C014387 */  lui       $at, 0x4387
/* D590A8 80240818 44810000 */  mtc1      $at, $f0
/* D590AC 8024081C 00000000 */  nop       
/* D590B0 80240820 4600103C */  c.lt.s    $f2, $f0
/* D590B4 80240824 00000000 */  nop       
/* D590B8 80240828 45000004 */  bc1f      .L8024083C
/* D590BC 8024082C 27A20018 */   addiu    $v0, $sp, 0x18
/* D590C0 80240830 3C041000 */  lui       $a0, 0x1000
/* D590C4 80240834 34840001 */  ori       $a0, $a0, 1
.L80240838:
/* D590C8 80240838 27A20018 */  addiu     $v0, $sp, 0x18
.L8024083C:
/* D590CC 8024083C 0000282D */  daddu     $a1, $zero, $zero
/* D590D0 80240840 00A0302D */  daddu     $a2, $a1, $zero
/* D590D4 80240844 00A0382D */  daddu     $a3, $a1, $zero
/* D590D8 80240848 0C0B7710 */  jal       render_sprite
/* D590DC 8024084C AFA20010 */   sw       $v0, 0x10($sp)
/* D590E0 80240850 8FBF0120 */  lw        $ra, 0x120($sp)
/* D590E4 80240854 8FB1011C */  lw        $s1, 0x11c($sp)
/* D590E8 80240858 8FB00118 */  lw        $s0, 0x118($sp)
/* D590EC 8024085C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D590F0 80240860 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D590F4 80240864 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D590F8 80240868 03E00008 */  jr        $ra
/* D590FC 8024086C 27BD0140 */   addiu    $sp, $sp, 0x140
