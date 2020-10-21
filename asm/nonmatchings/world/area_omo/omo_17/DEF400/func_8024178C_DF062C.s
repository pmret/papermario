.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024178C_DF062C
/* DF062C 8024178C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DF0630 80241790 AFB3001C */  sw        $s3, 0x1c($sp)
/* DF0634 80241794 0080982D */  daddu     $s3, $a0, $zero
/* DF0638 80241798 AFBF0020 */  sw        $ra, 0x20($sp)
/* DF063C 8024179C AFB20018 */  sw        $s2, 0x18($sp)
/* DF0640 802417A0 AFB10014 */  sw        $s1, 0x14($sp)
/* DF0644 802417A4 AFB00010 */  sw        $s0, 0x10($sp)
/* DF0648 802417A8 8E720148 */  lw        $s2, 0x148($s3)
/* DF064C 802417AC 86440008 */  lh        $a0, 8($s2)
/* DF0650 802417B0 0C00EABB */  jal       get_npc_unsafe
/* DF0654 802417B4 00A0882D */   daddu    $s1, $a1, $zero
/* DF0658 802417B8 8E240008 */  lw        $a0, 8($s1)
/* DF065C 802417BC 0040802D */  daddu     $s0, $v0, $zero
/* DF0660 802417C0 00041FC2 */  srl       $v1, $a0, 0x1f
/* DF0664 802417C4 00832021 */  addu      $a0, $a0, $v1
/* DF0668 802417C8 00042043 */  sra       $a0, $a0, 1
/* DF066C 802417CC 0C00A67F */  jal       rand_int
/* DF0670 802417D0 24840001 */   addiu    $a0, $a0, 1
/* DF0674 802417D4 8E230008 */  lw        $v1, 8($s1)
/* DF0678 802417D8 240400B4 */  addiu     $a0, $zero, 0xb4
/* DF067C 802417DC 00032FC2 */  srl       $a1, $v1, 0x1f
/* DF0680 802417E0 00651821 */  addu      $v1, $v1, $a1
/* DF0684 802417E4 00031843 */  sra       $v1, $v1, 1
/* DF0688 802417E8 00621821 */  addu      $v1, $v1, $v0
/* DF068C 802417EC 0C00A67F */  jal       rand_int
/* DF0690 802417F0 A603008E */   sh       $v1, 0x8e($s0)
/* DF0694 802417F4 C60C000C */  lwc1      $f12, 0xc($s0)
/* DF0698 802417F8 44820000 */  mtc1      $v0, $f0
/* DF069C 802417FC 00000000 */  nop       
/* DF06A0 80241800 46800020 */  cvt.s.w   $f0, $f0
/* DF06A4 80241804 46006300 */  add.s     $f12, $f12, $f0
/* DF06A8 80241808 3C0142B4 */  lui       $at, 0x42b4
/* DF06AC 8024180C 44810000 */  mtc1      $at, $f0
/* DF06B0 80241810 0C00A6C9 */  jal       clamp_angle
/* DF06B4 80241814 46006301 */   sub.s    $f12, $f12, $f0
/* DF06B8 80241818 E600000C */  swc1      $f0, 0xc($s0)
/* DF06BC 8024181C 8E4200CC */  lw        $v0, 0xcc($s2)
/* DF06C0 80241820 8C420000 */  lw        $v0, ($v0)
/* DF06C4 80241824 AE020028 */  sw        $v0, 0x28($s0)
/* DF06C8 80241828 24020003 */  addiu     $v0, $zero, 3
/* DF06CC 8024182C AE620070 */  sw        $v0, 0x70($s3)
/* DF06D0 80241830 8FBF0020 */  lw        $ra, 0x20($sp)
/* DF06D4 80241834 8FB3001C */  lw        $s3, 0x1c($sp)
/* DF06D8 80241838 8FB20018 */  lw        $s2, 0x18($sp)
/* DF06DC 8024183C 8FB10014 */  lw        $s1, 0x14($sp)
/* DF06E0 80241840 8FB00010 */  lw        $s0, 0x10($sp)
/* DF06E4 80241844 03E00008 */  jr        $ra
/* DF06E8 80241848 27BD0028 */   addiu    $sp, $sp, 0x28
