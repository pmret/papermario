.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_D91DBC
/* D91DBC 802406BC 3C03800A */  lui       $v1, 0x800a
/* D91DC0 802406C0 8463A634 */  lh        $v1, -0x59cc($v1)
/* D91DC4 802406C4 3C07BF80 */  lui       $a3, 0xbf80
/* D91DC8 802406C8 27BDFEC0 */  addiu     $sp, $sp, -0x140
/* D91DCC 802406CC F7B40128 */  sdc1      $f20, 0x128($sp)
/* D91DD0 802406D0 4480A000 */  mtc1      $zero, $f20
/* D91DD4 802406D4 AFB1011C */  sw        $s1, 0x11c($sp)
/* D91DD8 802406D8 0080882D */  daddu     $s1, $a0, $zero
/* D91DDC 802406DC AFB00118 */  sw        $s0, 0x118($sp)
/* D91DE0 802406E0 27B00098 */  addiu     $s0, $sp, 0x98
/* D91DE4 802406E4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D91DE8 802406E8 F7B80138 */  sdc1      $f24, 0x138($sp)
/* D91DEC 802406EC F7B60130 */  sdc1      $f22, 0x130($sp)
/* D91DF0 802406F0 00031080 */  sll       $v0, $v1, 2
/* D91DF4 802406F4 00431021 */  addu      $v0, $v0, $v1
/* D91DF8 802406F8 00021080 */  sll       $v0, $v0, 2
/* D91DFC 802406FC 00431023 */  subu      $v0, $v0, $v1
/* D91E00 80240700 000218C0 */  sll       $v1, $v0, 3
/* D91E04 80240704 00431021 */  addu      $v0, $v0, $v1
/* D91E08 80240708 000210C0 */  sll       $v0, $v0, 3
/* D91E0C 8024070C 3C01800B */  lui       $at, 0x800b
/* D91E10 80240710 00220821 */  addu      $at, $at, $v0
/* D91E14 80240714 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D91E18 80240718 4406A000 */  mfc1      $a2, $f20
/* D91E1C 8024071C 4600B587 */  neg.s     $f22, $f22
/* D91E20 80240720 4405B000 */  mfc1      $a1, $f22
/* D91E24 80240724 0200202D */  daddu     $a0, $s0, $zero
/* D91E28 80240728 0C019EC8 */  jal       guRotateF
/* D91E2C 8024072C E7B40010 */   swc1     $f20, 0x10($sp)
/* D91E30 80240730 C62C008C */  lwc1      $f12, 0x8c($s1)
/* D91E34 80240734 0C00A6C9 */  jal       clamp_angle
/* D91E38 80240738 00000000 */   nop      
/* D91E3C 8024073C 44050000 */  mfc1      $a1, $f0
/* D91E40 80240740 4406A000 */  mfc1      $a2, $f20
/* D91E44 80240744 4407A000 */  mfc1      $a3, $f20
/* D91E48 80240748 3C013F80 */  lui       $at, 0x3f80
/* D91E4C 8024074C 4481C000 */  mtc1      $at, $f24
/* D91E50 80240750 27A40018 */  addiu     $a0, $sp, 0x18
/* D91E54 80240754 0C019EC8 */  jal       guRotateF
/* D91E58 80240758 E7B80010 */   swc1     $f24, 0x10($sp)
/* D91E5C 8024075C 0200202D */  daddu     $a0, $s0, $zero
/* D91E60 80240760 27A50018 */  addiu     $a1, $sp, 0x18
/* D91E64 80240764 0C019D80 */  jal       guMtxCatF
/* D91E68 80240768 00A0302D */   daddu    $a2, $a1, $zero
/* D91E6C 8024076C 4405B000 */  mfc1      $a1, $f22
/* D91E70 80240770 4406A000 */  mfc1      $a2, $f20
/* D91E74 80240774 4407C000 */  mfc1      $a3, $f24
/* D91E78 80240778 0200202D */  daddu     $a0, $s0, $zero
/* D91E7C 8024077C 0C019EC8 */  jal       guRotateF
/* D91E80 80240780 E7B40010 */   swc1     $f20, 0x10($sp)
/* D91E84 80240784 27A40018 */  addiu     $a0, $sp, 0x18
/* D91E88 80240788 0200282D */  daddu     $a1, $s0, $zero
/* D91E8C 8024078C 0C019D80 */  jal       guMtxCatF
/* D91E90 80240790 0080302D */   daddu    $a2, $a0, $zero
/* D91E94 80240794 E7B40010 */  swc1      $f20, 0x10($sp)
/* D91E98 80240798 8E2500A8 */  lw        $a1, 0xa8($s1)
/* D91E9C 8024079C 4406A000 */  mfc1      $a2, $f20
/* D91EA0 802407A0 4407C000 */  mfc1      $a3, $f24
/* D91EA4 802407A4 0C019EC8 */  jal       guRotateF
/* D91EA8 802407A8 0200202D */   daddu    $a0, $s0, $zero
/* D91EAC 802407AC 27A40018 */  addiu     $a0, $sp, 0x18
/* D91EB0 802407B0 0200282D */  daddu     $a1, $s0, $zero
/* D91EB4 802407B4 0C019D80 */  jal       guMtxCatF
/* D91EB8 802407B8 0080302D */   daddu    $a2, $a0, $zero
/* D91EBC 802407BC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D91EC0 802407C0 3C013F36 */  lui       $at, 0x3f36
/* D91EC4 802407C4 3421DB6E */  ori       $at, $at, 0xdb6e
/* D91EC8 802407C8 44810000 */  mtc1      $at, $f0
/* D91ECC 802407CC 0200202D */  daddu     $a0, $s0, $zero
/* D91ED0 802407D0 44050000 */  mfc1      $a1, $f0
/* D91ED4 802407D4 3C06BF36 */  lui       $a2, 0xbf36
/* D91ED8 802407D8 34C6DB6E */  ori       $a2, $a2, 0xdb6e
/* D91EDC 802407DC 0C019DF0 */  jal       guScaleF
/* D91EE0 802407E0 00A0382D */   daddu    $a3, $a1, $zero
/* D91EE4 802407E4 27A40018 */  addiu     $a0, $sp, 0x18
/* D91EE8 802407E8 0200282D */  daddu     $a1, $s0, $zero
/* D91EEC 802407EC 0C019D80 */  jal       guMtxCatF
/* D91EF0 802407F0 0080302D */   daddu    $a2, $a0, $zero
/* D91EF4 802407F4 27B00058 */  addiu     $s0, $sp, 0x58
/* D91EF8 802407F8 8E250028 */  lw        $a1, 0x28($s1)
/* D91EFC 802407FC C620002C */  lwc1      $f0, 0x2c($s1)
/* D91F00 80240800 8E270030 */  lw        $a3, 0x30($s1)
/* D91F04 80240804 46000007 */  neg.s     $f0, $f0
/* D91F08 80240808 44060000 */  mfc1      $a2, $f0
/* D91F0C 8024080C 0C019E40 */  jal       guTranslateF
/* D91F10 80240810 0200202D */   daddu    $a0, $s0, $zero
/* D91F14 80240814 27A40018 */  addiu     $a0, $sp, 0x18
/* D91F18 80240818 0200282D */  daddu     $a1, $s0, $zero
/* D91F1C 8024081C 0C019D80 */  jal       guMtxCatF
/* D91F20 80240820 0080302D */   daddu    $a2, $a0, $zero
/* D91F24 80240824 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* D91F28 80240828 3C0142B4 */  lui       $at, 0x42b4
/* D91F2C 8024082C 44810000 */  mtc1      $at, $f0
/* D91F30 80240830 00000000 */  nop       
/* D91F34 80240834 4602003E */  c.le.s    $f0, $f2
/* D91F38 80240838 00000000 */  nop       
/* D91F3C 8024083C 4500000A */  bc1f      .L80240868
/* D91F40 80240840 24040001 */   addiu    $a0, $zero, 1
/* D91F44 80240844 3C014387 */  lui       $at, 0x4387
/* D91F48 80240848 44810000 */  mtc1      $at, $f0
/* D91F4C 8024084C 00000000 */  nop       
/* D91F50 80240850 4600103C */  c.lt.s    $f2, $f0
/* D91F54 80240854 00000000 */  nop       
/* D91F58 80240858 45000004 */  bc1f      .L8024086C
/* D91F5C 8024085C 27A20018 */   addiu    $v0, $sp, 0x18
/* D91F60 80240860 3C041000 */  lui       $a0, 0x1000
/* D91F64 80240864 34840001 */  ori       $a0, $a0, 1
.L80240868:
/* D91F68 80240868 27A20018 */  addiu     $v0, $sp, 0x18
.L8024086C:
/* D91F6C 8024086C 0000282D */  daddu     $a1, $zero, $zero
/* D91F70 80240870 00A0302D */  daddu     $a2, $a1, $zero
/* D91F74 80240874 00A0382D */  daddu     $a3, $a1, $zero
/* D91F78 80240878 0C0B7710 */  jal       render_sprite
/* D91F7C 8024087C AFA20010 */   sw       $v0, 0x10($sp)
/* D91F80 80240880 8FBF0120 */  lw        $ra, 0x120($sp)
/* D91F84 80240884 8FB1011C */  lw        $s1, 0x11c($sp)
/* D91F88 80240888 8FB00118 */  lw        $s0, 0x118($sp)
/* D91F8C 8024088C D7B80138 */  ldc1      $f24, 0x138($sp)
/* D91F90 80240890 D7B60130 */  ldc1      $f22, 0x130($sp)
/* D91F94 80240894 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D91F98 80240898 03E00008 */  jr        $ra
/* D91F9C 8024089C 27BD0140 */   addiu    $sp, $sp, 0x140
