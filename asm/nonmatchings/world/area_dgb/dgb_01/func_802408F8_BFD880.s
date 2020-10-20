.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408F8_BFE178
/* BFE178 802408F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BFE17C 802408FC AFB3001C */  sw        $s3, 0x1c($sp)
/* BFE180 80240900 0080982D */  daddu     $s3, $a0, $zero
/* BFE184 80240904 AFBF0020 */  sw        $ra, 0x20($sp)
/* BFE188 80240908 AFB20018 */  sw        $s2, 0x18($sp)
/* BFE18C 8024090C AFB10014 */  sw        $s1, 0x14($sp)
/* BFE190 80240910 AFB00010 */  sw        $s0, 0x10($sp)
/* BFE194 80240914 8E720148 */  lw        $s2, 0x148($s3)
/* BFE198 80240918 86440008 */  lh        $a0, 8($s2)
/* BFE19C 8024091C 0C00EABB */  jal       get_npc_unsafe
/* BFE1A0 80240920 00A0882D */   daddu    $s1, $a1, $zero
/* BFE1A4 80240924 8E240008 */  lw        $a0, 8($s1)
/* BFE1A8 80240928 0040802D */  daddu     $s0, $v0, $zero
/* BFE1AC 8024092C 00041FC2 */  srl       $v1, $a0, 0x1f
/* BFE1B0 80240930 00832021 */  addu      $a0, $a0, $v1
/* BFE1B4 80240934 00042043 */  sra       $a0, $a0, 1
/* BFE1B8 80240938 0C00A67F */  jal       rand_int
/* BFE1BC 8024093C 24840001 */   addiu    $a0, $a0, 1
/* BFE1C0 80240940 8E230008 */  lw        $v1, 8($s1)
/* BFE1C4 80240944 240400B4 */  addiu     $a0, $zero, 0xb4
/* BFE1C8 80240948 00032FC2 */  srl       $a1, $v1, 0x1f
/* BFE1CC 8024094C 00651821 */  addu      $v1, $v1, $a1
/* BFE1D0 80240950 00031843 */  sra       $v1, $v1, 1
/* BFE1D4 80240954 00621821 */  addu      $v1, $v1, $v0
/* BFE1D8 80240958 0C00A67F */  jal       rand_int
/* BFE1DC 8024095C A603008E */   sh       $v1, 0x8e($s0)
/* BFE1E0 80240960 C60C000C */  lwc1      $f12, 0xc($s0)
/* BFE1E4 80240964 44820000 */  mtc1      $v0, $f0
/* BFE1E8 80240968 00000000 */  nop       
/* BFE1EC 8024096C 46800020 */  cvt.s.w   $f0, $f0
/* BFE1F0 80240970 46006300 */  add.s     $f12, $f12, $f0
/* BFE1F4 80240974 3C0142B4 */  lui       $at, 0x42b4
/* BFE1F8 80240978 44810000 */  mtc1      $at, $f0
/* BFE1FC 8024097C 0C00A6C9 */  jal       clamp_angle
/* BFE200 80240980 46006301 */   sub.s    $f12, $f12, $f0
/* BFE204 80240984 E600000C */  swc1      $f0, 0xc($s0)
/* BFE208 80240988 8E4200CC */  lw        $v0, 0xcc($s2)
/* BFE20C 8024098C 8C420000 */  lw        $v0, ($v0)
/* BFE210 80240990 AE020028 */  sw        $v0, 0x28($s0)
/* BFE214 80240994 24020003 */  addiu     $v0, $zero, 3
/* BFE218 80240998 AE620070 */  sw        $v0, 0x70($s3)
/* BFE21C 8024099C 8FBF0020 */  lw        $ra, 0x20($sp)
/* BFE220 802409A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* BFE224 802409A4 8FB20018 */  lw        $s2, 0x18($sp)
/* BFE228 802409A8 8FB10014 */  lw        $s1, 0x14($sp)
/* BFE22C 802409AC 8FB00010 */  lw        $s0, 0x10($sp)
/* BFE230 802409B0 03E00008 */  jr        $ra
/* BFE234 802409B4 27BD0028 */   addiu    $sp, $sp, 0x28
