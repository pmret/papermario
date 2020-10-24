.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417C8_A179E8
/* A179E8 802417C8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A179EC 802417CC AFB3001C */  sw        $s3, 0x1c($sp)
/* A179F0 802417D0 0080982D */  daddu     $s3, $a0, $zero
/* A179F4 802417D4 AFBF0020 */  sw        $ra, 0x20($sp)
/* A179F8 802417D8 AFB20018 */  sw        $s2, 0x18($sp)
/* A179FC 802417DC AFB10014 */  sw        $s1, 0x14($sp)
/* A17A00 802417E0 AFB00010 */  sw        $s0, 0x10($sp)
/* A17A04 802417E4 8E720148 */  lw        $s2, 0x148($s3)
/* A17A08 802417E8 86440008 */  lh        $a0, 8($s2)
/* A17A0C 802417EC 0C00EABB */  jal       get_npc_unsafe
/* A17A10 802417F0 00A0882D */   daddu    $s1, $a1, $zero
/* A17A14 802417F4 8E240008 */  lw        $a0, 8($s1)
/* A17A18 802417F8 0040802D */  daddu     $s0, $v0, $zero
/* A17A1C 802417FC 00041FC2 */  srl       $v1, $a0, 0x1f
/* A17A20 80241800 00832021 */  addu      $a0, $a0, $v1
/* A17A24 80241804 00042043 */  sra       $a0, $a0, 1
/* A17A28 80241808 0C00A67F */  jal       rand_int
/* A17A2C 8024180C 24840001 */   addiu    $a0, $a0, 1
/* A17A30 80241810 8E230008 */  lw        $v1, 8($s1)
/* A17A34 80241814 240400B4 */  addiu     $a0, $zero, 0xb4
/* A17A38 80241818 00032FC2 */  srl       $a1, $v1, 0x1f
/* A17A3C 8024181C 00651821 */  addu      $v1, $v1, $a1
/* A17A40 80241820 00031843 */  sra       $v1, $v1, 1
/* A17A44 80241824 00621821 */  addu      $v1, $v1, $v0
/* A17A48 80241828 0C00A67F */  jal       rand_int
/* A17A4C 8024182C A603008E */   sh       $v1, 0x8e($s0)
/* A17A50 80241830 C60C000C */  lwc1      $f12, 0xc($s0)
/* A17A54 80241834 44820000 */  mtc1      $v0, $f0
/* A17A58 80241838 00000000 */  nop       
/* A17A5C 8024183C 46800020 */  cvt.s.w   $f0, $f0
/* A17A60 80241840 46006300 */  add.s     $f12, $f12, $f0
/* A17A64 80241844 3C0142B4 */  lui       $at, 0x42b4
/* A17A68 80241848 44810000 */  mtc1      $at, $f0
/* A17A6C 8024184C 0C00A6C9 */  jal       clamp_angle
/* A17A70 80241850 46006301 */   sub.s    $f12, $f12, $f0
/* A17A74 80241854 E600000C */  swc1      $f0, 0xc($s0)
/* A17A78 80241858 8E4200CC */  lw        $v0, 0xcc($s2)
/* A17A7C 8024185C 8C420000 */  lw        $v0, ($v0)
/* A17A80 80241860 AE020028 */  sw        $v0, 0x28($s0)
/* A17A84 80241864 24020003 */  addiu     $v0, $zero, 3
/* A17A88 80241868 AE620070 */  sw        $v0, 0x70($s3)
/* A17A8C 8024186C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A17A90 80241870 8FB3001C */  lw        $s3, 0x1c($sp)
/* A17A94 80241874 8FB20018 */  lw        $s2, 0x18($sp)
/* A17A98 80241878 8FB10014 */  lw        $s1, 0x14($sp)
/* A17A9C 8024187C 8FB00010 */  lw        $s0, 0x10($sp)
/* A17AA0 80241880 03E00008 */  jr        $ra
/* A17AA4 80241884 27BD0028 */   addiu    $sp, $sp, 0x28
