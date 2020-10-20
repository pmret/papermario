.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A28_B7AA78
/* B7AA78 80240A28 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B7AA7C 80240A2C AFB3001C */  sw        $s3, 0x1c($sp)
/* B7AA80 80240A30 0080982D */  daddu     $s3, $a0, $zero
/* B7AA84 80240A34 AFBF0020 */  sw        $ra, 0x20($sp)
/* B7AA88 80240A38 AFB20018 */  sw        $s2, 0x18($sp)
/* B7AA8C 80240A3C AFB10014 */  sw        $s1, 0x14($sp)
/* B7AA90 80240A40 AFB00010 */  sw        $s0, 0x10($sp)
/* B7AA94 80240A44 8E720148 */  lw        $s2, 0x148($s3)
/* B7AA98 80240A48 86440008 */  lh        $a0, 8($s2)
/* B7AA9C 80240A4C 0C00EABB */  jal       get_npc_unsafe
/* B7AAA0 80240A50 00A0882D */   daddu    $s1, $a1, $zero
/* B7AAA4 80240A54 8E240008 */  lw        $a0, 8($s1)
/* B7AAA8 80240A58 0040802D */  daddu     $s0, $v0, $zero
/* B7AAAC 80240A5C 00041FC2 */  srl       $v1, $a0, 0x1f
/* B7AAB0 80240A60 00832021 */  addu      $a0, $a0, $v1
/* B7AAB4 80240A64 00042043 */  sra       $a0, $a0, 1
/* B7AAB8 80240A68 0C00A67F */  jal       rand_int
/* B7AABC 80240A6C 24840001 */   addiu    $a0, $a0, 1
/* B7AAC0 80240A70 8E230008 */  lw        $v1, 8($s1)
/* B7AAC4 80240A74 240400B4 */  addiu     $a0, $zero, 0xb4
/* B7AAC8 80240A78 00032FC2 */  srl       $a1, $v1, 0x1f
/* B7AACC 80240A7C 00651821 */  addu      $v1, $v1, $a1
/* B7AAD0 80240A80 00031843 */  sra       $v1, $v1, 1
/* B7AAD4 80240A84 00621821 */  addu      $v1, $v1, $v0
/* B7AAD8 80240A88 0C00A67F */  jal       rand_int
/* B7AADC 80240A8C A603008E */   sh       $v1, 0x8e($s0)
/* B7AAE0 80240A90 C60C000C */  lwc1      $f12, 0xc($s0)
/* B7AAE4 80240A94 44820000 */  mtc1      $v0, $f0
/* B7AAE8 80240A98 00000000 */  nop       
/* B7AAEC 80240A9C 46800020 */  cvt.s.w   $f0, $f0
/* B7AAF0 80240AA0 46006300 */  add.s     $f12, $f12, $f0
/* B7AAF4 80240AA4 3C0142B4 */  lui       $at, 0x42b4
/* B7AAF8 80240AA8 44810000 */  mtc1      $at, $f0
/* B7AAFC 80240AAC 0C00A6C9 */  jal       clamp_angle
/* B7AB00 80240AB0 46006301 */   sub.s    $f12, $f12, $f0
/* B7AB04 80240AB4 E600000C */  swc1      $f0, 0xc($s0)
/* B7AB08 80240AB8 8E4200CC */  lw        $v0, 0xcc($s2)
/* B7AB0C 80240ABC 8C420000 */  lw        $v0, ($v0)
/* B7AB10 80240AC0 AE020028 */  sw        $v0, 0x28($s0)
/* B7AB14 80240AC4 24020003 */  addiu     $v0, $zero, 3
/* B7AB18 80240AC8 AE620070 */  sw        $v0, 0x70($s3)
/* B7AB1C 80240ACC 8FBF0020 */  lw        $ra, 0x20($sp)
/* B7AB20 80240AD0 8FB3001C */  lw        $s3, 0x1c($sp)
/* B7AB24 80240AD4 8FB20018 */  lw        $s2, 0x18($sp)
/* B7AB28 80240AD8 8FB10014 */  lw        $s1, 0x14($sp)
/* B7AB2C 80240ADC 8FB00010 */  lw        $s0, 0x10($sp)
/* B7AB30 80240AE0 03E00008 */  jr        $ra
/* B7AB34 80240AE4 27BD0028 */   addiu    $sp, $sp, 0x28
