.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407D8_8CE848
/* 8CE848 802407D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8CE84C 802407DC AFB3001C */  sw        $s3, 0x1c($sp)
/* 8CE850 802407E0 0080982D */  daddu     $s3, $a0, $zero
/* 8CE854 802407E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8CE858 802407E8 AFB20018 */  sw        $s2, 0x18($sp)
/* 8CE85C 802407EC AFB10014 */  sw        $s1, 0x14($sp)
/* 8CE860 802407F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 8CE864 802407F4 8E720148 */  lw        $s2, 0x148($s3)
/* 8CE868 802407F8 86440008 */  lh        $a0, 8($s2)
/* 8CE86C 802407FC 0C00EABB */  jal       get_npc_unsafe
/* 8CE870 80240800 00A0882D */   daddu    $s1, $a1, $zero
/* 8CE874 80240804 8E240008 */  lw        $a0, 8($s1)
/* 8CE878 80240808 0040802D */  daddu     $s0, $v0, $zero
/* 8CE87C 8024080C 00041FC2 */  srl       $v1, $a0, 0x1f
/* 8CE880 80240810 00832021 */  addu      $a0, $a0, $v1
/* 8CE884 80240814 00042043 */  sra       $a0, $a0, 1
/* 8CE888 80240818 0C00A67F */  jal       rand_int
/* 8CE88C 8024081C 24840001 */   addiu    $a0, $a0, 1
/* 8CE890 80240820 8E230008 */  lw        $v1, 8($s1)
/* 8CE894 80240824 240400B4 */  addiu     $a0, $zero, 0xb4
/* 8CE898 80240828 00032FC2 */  srl       $a1, $v1, 0x1f
/* 8CE89C 8024082C 00651821 */  addu      $v1, $v1, $a1
/* 8CE8A0 80240830 00031843 */  sra       $v1, $v1, 1
/* 8CE8A4 80240834 00621821 */  addu      $v1, $v1, $v0
/* 8CE8A8 80240838 0C00A67F */  jal       rand_int
/* 8CE8AC 8024083C A603008E */   sh       $v1, 0x8e($s0)
/* 8CE8B0 80240840 C60C000C */  lwc1      $f12, 0xc($s0)
/* 8CE8B4 80240844 44820000 */  mtc1      $v0, $f0
/* 8CE8B8 80240848 00000000 */  nop       
/* 8CE8BC 8024084C 46800020 */  cvt.s.w   $f0, $f0
/* 8CE8C0 80240850 46006300 */  add.s     $f12, $f12, $f0
/* 8CE8C4 80240854 3C0142B4 */  lui       $at, 0x42b4
/* 8CE8C8 80240858 44810000 */  mtc1      $at, $f0
/* 8CE8CC 8024085C 0C00A6C9 */  jal       clamp_angle
/* 8CE8D0 80240860 46006301 */   sub.s    $f12, $f12, $f0
/* 8CE8D4 80240864 E600000C */  swc1      $f0, 0xc($s0)
/* 8CE8D8 80240868 8E4200CC */  lw        $v0, 0xcc($s2)
/* 8CE8DC 8024086C 8C420000 */  lw        $v0, ($v0)
/* 8CE8E0 80240870 AE020028 */  sw        $v0, 0x28($s0)
/* 8CE8E4 80240874 24020003 */  addiu     $v0, $zero, 3
/* 8CE8E8 80240878 AE620070 */  sw        $v0, 0x70($s3)
/* 8CE8EC 8024087C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8CE8F0 80240880 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8CE8F4 80240884 8FB20018 */  lw        $s2, 0x18($sp)
/* 8CE8F8 80240888 8FB10014 */  lw        $s1, 0x14($sp)
/* 8CE8FC 8024088C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8CE900 80240890 03E00008 */  jr        $ra
/* 8CE904 80240894 27BD0028 */   addiu    $sp, $sp, 0x28
