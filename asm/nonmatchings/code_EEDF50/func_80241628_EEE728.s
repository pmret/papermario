.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241628_EEE728
/* EEE728 80241628 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EEE72C 8024162C AFB3001C */  sw        $s3, 0x1c($sp)
/* EEE730 80241630 0080982D */  daddu     $s3, $a0, $zero
/* EEE734 80241634 AFBF0020 */  sw        $ra, 0x20($sp)
/* EEE738 80241638 AFB20018 */  sw        $s2, 0x18($sp)
/* EEE73C 8024163C AFB10014 */  sw        $s1, 0x14($sp)
/* EEE740 80241640 AFB00010 */  sw        $s0, 0x10($sp)
/* EEE744 80241644 8E720148 */  lw        $s2, 0x148($s3)
/* EEE748 80241648 86440008 */  lh        $a0, 8($s2)
/* EEE74C 8024164C 0C00F92F */  jal       func_8003E4BC
/* EEE750 80241650 00A0882D */   daddu    $s1, $a1, $zero
/* EEE754 80241654 8E240008 */  lw        $a0, 8($s1)
/* EEE758 80241658 0040802D */  daddu     $s0, $v0, $zero
/* EEE75C 8024165C 00041FC2 */  srl       $v1, $a0, 0x1f
/* EEE760 80241660 00832021 */  addu      $a0, $a0, $v1
/* EEE764 80241664 00042043 */  sra       $a0, $a0, 1
/* EEE768 80241668 0C00AB3B */  jal       func_8002ACEC
/* EEE76C 8024166C 24840001 */   addiu    $a0, $a0, 1
/* EEE770 80241670 8E230008 */  lw        $v1, 8($s1)
/* EEE774 80241674 240400B4 */  addiu     $a0, $zero, 0xb4
/* EEE778 80241678 00032FC2 */  srl       $a1, $v1, 0x1f
/* EEE77C 8024167C 00651821 */  addu      $v1, $v1, $a1
/* EEE780 80241680 00031843 */  sra       $v1, $v1, 1
/* EEE784 80241684 00621821 */  addu      $v1, $v1, $v0
/* EEE788 80241688 0C00AB3B */  jal       func_8002ACEC
/* EEE78C 8024168C A603008E */   sh       $v1, 0x8e($s0)
/* EEE790 80241690 C60C000C */  lwc1      $f12, 0xc($s0)
/* EEE794 80241694 44820000 */  mtc1      $v0, $f0
/* EEE798 80241698 00000000 */  nop
/* EEE79C 8024169C 46800020 */  cvt.s.w   $f0, $f0
/* EEE7A0 802416A0 46006300 */  add.s     $f12, $f12, $f0
/* EEE7A4 802416A4 3C0142B4 */  lui       $at, 0x42b4
/* EEE7A8 802416A8 44810000 */  mtc1      $at, $f0
/* EEE7AC 802416AC 0C00AB85 */  jal       func_8002AE14
/* EEE7B0 802416B0 46006301 */   sub.s    $f12, $f12, $f0
/* EEE7B4 802416B4 E600000C */  swc1      $f0, 0xc($s0)
/* EEE7B8 802416B8 8E4200CC */  lw        $v0, 0xcc($s2)
/* EEE7BC 802416BC 8C420000 */  lw        $v0, ($v0)
/* EEE7C0 802416C0 AE020028 */  sw        $v0, 0x28($s0)
/* EEE7C4 802416C4 24020003 */  addiu     $v0, $zero, 3
/* EEE7C8 802416C8 AE620070 */  sw        $v0, 0x70($s3)
/* EEE7CC 802416CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* EEE7D0 802416D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* EEE7D4 802416D4 8FB20018 */  lw        $s2, 0x18($sp)
/* EEE7D8 802416D8 8FB10014 */  lw        $s1, 0x14($sp)
/* EEE7DC 802416DC 8FB00010 */  lw        $s0, 0x10($sp)
/* EEE7E0 802416E0 03E00008 */  jr        $ra
/* EEE7E4 802416E4 27BD0028 */   addiu    $sp, $sp, 0x28
