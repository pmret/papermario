.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024099C_EDF35C
/* EDF35C 8024099C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EDF360 802409A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* EDF364 802409A4 0080982D */  daddu     $s3, $a0, $zero
/* EDF368 802409A8 AFBF0020 */  sw        $ra, 0x20($sp)
/* EDF36C 802409AC AFB20018 */  sw        $s2, 0x18($sp)
/* EDF370 802409B0 AFB10014 */  sw        $s1, 0x14($sp)
/* EDF374 802409B4 AFB00010 */  sw        $s0, 0x10($sp)
/* EDF378 802409B8 8E720148 */  lw        $s2, 0x148($s3)
/* EDF37C 802409BC 86440008 */  lh        $a0, 8($s2)
/* EDF380 802409C0 0C00F92F */  jal       func_8003E4BC
/* EDF384 802409C4 00A0882D */   daddu    $s1, $a1, $zero
/* EDF388 802409C8 8E240008 */  lw        $a0, 8($s1)
/* EDF38C 802409CC 0040802D */  daddu     $s0, $v0, $zero
/* EDF390 802409D0 00041FC2 */  srl       $v1, $a0, 0x1f
/* EDF394 802409D4 00832021 */  addu      $a0, $a0, $v1
/* EDF398 802409D8 00042043 */  sra       $a0, $a0, 1
/* EDF39C 802409DC 0C00AB3B */  jal       func_8002ACEC
/* EDF3A0 802409E0 24840001 */   addiu    $a0, $a0, 1
/* EDF3A4 802409E4 8E230008 */  lw        $v1, 8($s1)
/* EDF3A8 802409E8 240400B4 */  addiu     $a0, $zero, 0xb4
/* EDF3AC 802409EC 00032FC2 */  srl       $a1, $v1, 0x1f
/* EDF3B0 802409F0 00651821 */  addu      $v1, $v1, $a1
/* EDF3B4 802409F4 00031843 */  sra       $v1, $v1, 1
/* EDF3B8 802409F8 00621821 */  addu      $v1, $v1, $v0
/* EDF3BC 802409FC 0C00AB3B */  jal       func_8002ACEC
/* EDF3C0 80240A00 A603008E */   sh       $v1, 0x8e($s0)
/* EDF3C4 80240A04 C60C000C */  lwc1      $f12, 0xc($s0)
/* EDF3C8 80240A08 44820000 */  mtc1      $v0, $f0
/* EDF3CC 80240A0C 00000000 */  nop
/* EDF3D0 80240A10 46800020 */  cvt.s.w   $f0, $f0
/* EDF3D4 80240A14 46006300 */  add.s     $f12, $f12, $f0
/* EDF3D8 80240A18 3C0142B4 */  lui       $at, 0x42b4
/* EDF3DC 80240A1C 44810000 */  mtc1      $at, $f0
/* EDF3E0 80240A20 0C00AB85 */  jal       func_8002AE14
/* EDF3E4 80240A24 46006301 */   sub.s    $f12, $f12, $f0
/* EDF3E8 80240A28 E600000C */  swc1      $f0, 0xc($s0)
/* EDF3EC 80240A2C 8E4200CC */  lw        $v0, 0xcc($s2)
/* EDF3F0 80240A30 8C420000 */  lw        $v0, ($v0)
/* EDF3F4 80240A34 AE020028 */  sw        $v0, 0x28($s0)
/* EDF3F8 80240A38 24020003 */  addiu     $v0, $zero, 3
/* EDF3FC 80240A3C AE620070 */  sw        $v0, 0x70($s3)
/* EDF400 80240A40 8FBF0020 */  lw        $ra, 0x20($sp)
/* EDF404 80240A44 8FB3001C */  lw        $s3, 0x1c($sp)
/* EDF408 80240A48 8FB20018 */  lw        $s2, 0x18($sp)
/* EDF40C 80240A4C 8FB10014 */  lw        $s1, 0x14($sp)
/* EDF410 80240A50 8FB00010 */  lw        $s0, 0x10($sp)
/* EDF414 80240A54 03E00008 */  jr        $ra
/* EDF418 80240A58 27BD0028 */   addiu    $sp, $sp, 0x28
