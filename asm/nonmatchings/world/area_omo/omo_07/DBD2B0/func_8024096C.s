.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024096C
/* DBDC1C 8024096C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DBDC20 80240970 AFB3001C */  sw        $s3, 0x1c($sp)
/* DBDC24 80240974 0080982D */  daddu     $s3, $a0, $zero
/* DBDC28 80240978 AFBF0020 */  sw        $ra, 0x20($sp)
/* DBDC2C 8024097C AFB20018 */  sw        $s2, 0x18($sp)
/* DBDC30 80240980 AFB10014 */  sw        $s1, 0x14($sp)
/* DBDC34 80240984 AFB00010 */  sw        $s0, 0x10($sp)
/* DBDC38 80240988 8E720148 */  lw        $s2, 0x148($s3)
/* DBDC3C 8024098C 86440008 */  lh        $a0, 8($s2)
/* DBDC40 80240990 0C00EABB */  jal       get_npc_unsafe
/* DBDC44 80240994 00A0882D */   daddu    $s1, $a1, $zero
/* DBDC48 80240998 8E240008 */  lw        $a0, 8($s1)
/* DBDC4C 8024099C 0040802D */  daddu     $s0, $v0, $zero
/* DBDC50 802409A0 00041FC2 */  srl       $v1, $a0, 0x1f
/* DBDC54 802409A4 00832021 */  addu      $a0, $a0, $v1
/* DBDC58 802409A8 00042043 */  sra       $a0, $a0, 1
/* DBDC5C 802409AC 0C00A67F */  jal       rand_int
/* DBDC60 802409B0 24840001 */   addiu    $a0, $a0, 1
/* DBDC64 802409B4 8E230008 */  lw        $v1, 8($s1)
/* DBDC68 802409B8 240400B4 */  addiu     $a0, $zero, 0xb4
/* DBDC6C 802409BC 00032FC2 */  srl       $a1, $v1, 0x1f
/* DBDC70 802409C0 00651821 */  addu      $v1, $v1, $a1
/* DBDC74 802409C4 00031843 */  sra       $v1, $v1, 1
/* DBDC78 802409C8 00621821 */  addu      $v1, $v1, $v0
/* DBDC7C 802409CC 0C00A67F */  jal       rand_int
/* DBDC80 802409D0 A603008E */   sh       $v1, 0x8e($s0)
/* DBDC84 802409D4 C60C000C */  lwc1      $f12, 0xc($s0)
/* DBDC88 802409D8 44820000 */  mtc1      $v0, $f0
/* DBDC8C 802409DC 00000000 */  nop       
/* DBDC90 802409E0 46800020 */  cvt.s.w   $f0, $f0
/* DBDC94 802409E4 46006300 */  add.s     $f12, $f12, $f0
/* DBDC98 802409E8 3C0142B4 */  lui       $at, 0x42b4
/* DBDC9C 802409EC 44810000 */  mtc1      $at, $f0
/* DBDCA0 802409F0 0C00A6C9 */  jal       clamp_angle
/* DBDCA4 802409F4 46006301 */   sub.s    $f12, $f12, $f0
/* DBDCA8 802409F8 E600000C */  swc1      $f0, 0xc($s0)
/* DBDCAC 802409FC 8E4200CC */  lw        $v0, 0xcc($s2)
/* DBDCB0 80240A00 8C420000 */  lw        $v0, ($v0)
/* DBDCB4 80240A04 AE020028 */  sw        $v0, 0x28($s0)
/* DBDCB8 80240A08 24020003 */  addiu     $v0, $zero, 3
/* DBDCBC 80240A0C AE620070 */  sw        $v0, 0x70($s3)
/* DBDCC0 80240A10 8FBF0020 */  lw        $ra, 0x20($sp)
/* DBDCC4 80240A14 8FB3001C */  lw        $s3, 0x1c($sp)
/* DBDCC8 80240A18 8FB20018 */  lw        $s2, 0x18($sp)
/* DBDCCC 80240A1C 8FB10014 */  lw        $s1, 0x14($sp)
/* DBDCD0 80240A20 8FB00010 */  lw        $s0, 0x10($sp)
/* DBDCD4 80240A24 03E00008 */  jr        $ra
/* DBDCD8 80240A28 27BD0028 */   addiu    $sp, $sp, 0x28
