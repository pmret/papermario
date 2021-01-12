.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_D97F4C
/* D97F4C 802406BC 3C03800A */  lui       $v1, %hi(D_8009A634)
/* D97F50 802406C0 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* D97F54 802406C4 3C07BF80 */  lui       $a3, 0xbf80
/* D97F58 802406C8 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D97F5C 802406CC F7B40128 */  sdc1      $f20, 0x128($sp)
/* D97F60 802406D0 4480A000 */  mtc1      $zero, $f20
/* D97F64 802406D4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D97F68 802406D8 0080882D */  daddu     $s1, $a0, $zero
/* D97F6C 802406DC AFB00118 */  sw        $s0, 0x118($sp)
/* D97F70 802406E0 27B00098 */  addiu     $s0, $sp, 0x98
/* D97F74 802406E4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D97F78 802406E8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D97F7C 802406EC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D97F80 802406F0 00031080 */  sll       $v0, $v1, 2
/* D97F84 802406F4 00431021 */  addu      $v0, $v0, $v1
/* D97F88 802406F8 00021080 */  sll       $v0, $v0, 2
/* D97F8C 802406FC 00431023 */  subu      $v0, $v0, $v1
/* D97F90 80240700 000218C0 */  sll       $v1, $v0, 3
/* D97F94 80240704 00431021 */  addu      $v0, $v0, $v1
/* D97F98 80240708 000210C0 */  sll       $v0, $v0, 3
/* D97F9C 8024070C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* D97FA0 80240710 00220821 */  addu      $at, $at, $v0
/* D97FA4 80240714 C4361DEC */  lwc1      $f22, %lo(D_800B1DEC)($at)
/* D97FA8 80240718 4406A000 */  mfc1      $a2, $f20
/* D97FAC 8024071C 4600B587 */  neg.s     $f22, $f22
/* D97FB0 80240720 4405B000 */  mfc1      $a1, $f22
/* D97FB4 80240724 0200202D */  daddu     $a0, $s0, $zero
/* D97FB8 80240728 0C019EC8 */  jal       guRotateF
/* D97FBC 8024072C E7B40010 */   swc1     $f20, 0x10($sp)
/* D97FC0 80240730 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D97FC4 80240734 0C00A6C9 */  jal       clamp_angle
/* D97FC8 80240738 00000000 */   nop
/* D97FCC 8024073C 44050000 */  mfc1      $a1, $f0
/* D97FD0 80240740 4406A000 */  mfc1      $a2, $f20
/* D97FD4 80240744 4407A000 */  mfc1      $a3, $f20
/* D97FD8 80240748 3C013F80 */  lui       $at, 0x3f80
/* D97FDC 8024074C 4481C000 */  mtc1      $at, $f24
/* D97FE0 80240750 27A40018 */  addiu     $a0, $sp, 0x18
/* D97FE4 80240754 0C019EC8 */  jal       guRotateF
/* D97FE8 80240758 E7B80010 */   swc1     $f24, 0x10($sp)
/* D97FEC 8024075C 0200202D */  daddu     $a0, $s0, $zero
/* D97FF0 80240760 27A50018 */  addiu     $a1, $sp, 0x18
/* D97FF4 80240764 0C019D80 */  jal       guMtxCatF
/* D97FF8 80240768 00A0302D */   daddu    $a2, $a1, $zero
/* D97FFC 8024076C 4405B000 */  mfc1      $a1, $f22
/* D98000 80240770 4406A000 */  mfc1      $a2, $f20
/* D98004 80240774 4407C000 */  mfc1      $a3, $f24
/* D98008 80240778 0200202D */  daddu     $a0, $s0, $zero
/* D9800C 8024077C 0C019EC8 */  jal       guRotateF
/* D98010 80240780 E7B40010 */   swc1     $f20, 0x10($sp)
/* D98014 80240784 27A40018 */  addiu     $a0, $sp, 0x18
/* D98018 80240788 0200282D */  daddu     $a1, $s0, $zero
/* D9801C 8024078C 0C019D80 */  jal       guMtxCatF
/* D98020 80240790 0080302D */   daddu    $a2, $a0, $zero
/* D98024 80240794 E7B40010 */  swc1      $f20, 0x10($sp)
/* D98028 80240798 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D9802C 8024079C 4406A000 */  mfc1      $a2, $f20
/* D98030 802407A0 4407C000 */  mfc1      $a3, $f24
/* D98034 802407A4 0C019EC8 */  jal       guRotateF
/* D98038 802407A8 0200202D */   daddu    $a0, $s0, $zero
/* D9803C 802407AC 27A40018 */  addiu     $a0, $sp, 0x18
/* D98040 802407B0 0200282D */  daddu     $a1, $s0, $zero
/* D98044 802407B4 0C019D80 */  jal       guMtxCatF
/* D98048 802407B8 0080302D */   daddu    $a2, $a0, $zero
/* D9804C 802407BC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D98050 802407C0 3C013F36 */  lui       $at, 0x3f36
/* D98054 802407C4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D98058 802407C8 44810000 */  mtc1      $at, $f0
/* D9805C 802407CC 0200202D */  daddu     $a0, $s0, $zero
/* D98060 802407D0 44050000 */  mfc1      $a1, $f0
/* D98064 802407D4 3C06BF36 */  lui       $a2, 0xbf36
/* D98068 802407D8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D9806C 802407DC 0C019DF0 */  jal       guScaleF
/* D98070 802407E0 00A0382D */   daddu    $a3, $a1, $zero
/* D98074 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D98078 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D9807C 802407EC 0C019D80 */  jal       guMtxCatF
/* D98080 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D98084 802407F4 27B00058 */  addiu     $s0, $sp, 0x58
/* D98088 802407F8 8E250028 */  lw        $a1, 0x28($s1)
/* D9808C 802407FC C620002C */  lwc1      $f0, 0x2c($s1)
/* D98090 80240800 8E270030 */  lw        $a3, 0x30($s1)
/* D98094 80240804 46000007 */  neg.s     $f0, $f0
/* D98098 80240808 44060000 */  mfc1      $a2, $f0
/* D9809C 8024080C 0C019E40 */  jal       guTranslateF
/* D980A0 80240810 0200202D */   daddu    $a0, $s0, $zero
/* D980A4 80240814 27A40018 */  addiu     $a0, $sp, 0x18
/* D980A8 80240818 0200282D */  daddu     $a1, $s0, $zero
/* D980AC 8024081C 0C019D80 */  jal       guMtxCatF
/* D980B0 80240820 0080302D */   daddu    $a2, $a0, $zero
/* D980B4 80240824 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D980B8 80240828 3C0142B4 */  lui       $at, 0x42b4
/* D980BC 8024082C 44810000 */  mtc1      $at, $f0
/* D980C0 80240830 00000000 */  nop
/* D980C4 80240834 4602003E */  c.le.s    $f0, $f2
/* D980C8 80240838 00000000 */  nop
/* D980CC 8024083C 4500000A */  bc1f      .L80240868
/* D980D0 80240840 24040001 */   addiu    $a0, $zero, 1
/* D980D4 80240844 3C014387 */  lui       $at, 0x4387
/* D980D8 80240848 44810000 */  mtc1      $at, $f0
/* D980DC 8024084C 00000000 */  nop
/* D980E0 80240850 4600103C */  c.lt.s    $f2, $f0
/* D980E4 80240854 00000000 */  nop
/* D980E8 80240858 45000004 */  bc1f      .L8024086C
/* D980EC 8024085C 27A20018 */   addiu    $v0, $sp, 0x18
/* D980F0 80240860 3C041000 */  lui       $a0, 0x1000
/* D980F4 80240864 34840001 */  ori       $a0, $a0, 1
.L80240868:
/* D980F8 80240868 27A20018 */  addiu     $v0, $sp, 0x18
.L8024086C:
/* D980FC 8024086C 0000282D */  daddu     $a1, $zero, $zero
/* D98100 80240870 00A0302D */  daddu     $a2, $a1, $zero
/* D98104 80240874 00A0382D */  daddu     $a3, $a1, $zero
/* D98108 80240878 0C0B7710 */  jal       render_sprite
/* D9810C 8024087C AFA20010 */   sw       $v0, 0x10($sp)
/* D98110 80240880 8FBF0120 */  lw        $ra, 0x120($sp)
/* D98114 80240884 8FB1011C */  lw        $s1, 0x11c($sp)
/* D98118 80240888 8FB00118 */  lw        $s0, 0x118($sp)
/* D9811C 8024088C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D98120 80240890 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D98124 80240894 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D98128 80240898 03E00008 */  jr        $ra
/* D9812C 8024089C 27BD0140 */   addiu    $sp, $sp, 0x140
