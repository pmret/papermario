.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024099C
/* CC41AC 8024099C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CC41B0 802409A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* CC41B4 802409A4 0080982D */  daddu     $s3, $a0, $zero
/* CC41B8 802409A8 AFBF0020 */  sw        $ra, 0x20($sp)
/* CC41BC 802409AC AFB20018 */  sw        $s2, 0x18($sp)
/* CC41C0 802409B0 AFB10014 */  sw        $s1, 0x14($sp)
/* CC41C4 802409B4 AFB00010 */  sw        $s0, 0x10($sp)
/* CC41C8 802409B8 8E720148 */  lw        $s2, 0x148($s3)
/* CC41CC 802409BC 86440008 */  lh        $a0, 8($s2)
/* CC41D0 802409C0 0C00EABB */  jal       get_npc_unsafe
/* CC41D4 802409C4 00A0882D */   daddu    $s1, $a1, $zero
/* CC41D8 802409C8 8E240008 */  lw        $a0, 8($s1)
/* CC41DC 802409CC 0040802D */  daddu     $s0, $v0, $zero
/* CC41E0 802409D0 00041FC2 */  srl       $v1, $a0, 0x1f
/* CC41E4 802409D4 00832021 */  addu      $a0, $a0, $v1
/* CC41E8 802409D8 00042043 */  sra       $a0, $a0, 1
/* CC41EC 802409DC 0C00A67F */  jal       rand_int
/* CC41F0 802409E0 24840001 */   addiu    $a0, $a0, 1
/* CC41F4 802409E4 8E230008 */  lw        $v1, 8($s1)
/* CC41F8 802409E8 240400B4 */  addiu     $a0, $zero, 0xb4
/* CC41FC 802409EC 00032FC2 */  srl       $a1, $v1, 0x1f
/* CC4200 802409F0 00651821 */  addu      $v1, $v1, $a1
/* CC4204 802409F4 00031843 */  sra       $v1, $v1, 1
/* CC4208 802409F8 00621821 */  addu      $v1, $v1, $v0
/* CC420C 802409FC 0C00A67F */  jal       rand_int
/* CC4210 80240A00 A603008E */   sh       $v1, 0x8e($s0)
/* CC4214 80240A04 C60C000C */  lwc1      $f12, 0xc($s0)
/* CC4218 80240A08 44820000 */  mtc1      $v0, $f0
/* CC421C 80240A0C 00000000 */  nop       
/* CC4220 80240A10 46800020 */  cvt.s.w   $f0, $f0
/* CC4224 80240A14 46006300 */  add.s     $f12, $f12, $f0
/* CC4228 80240A18 3C0142B4 */  lui       $at, 0x42b4
/* CC422C 80240A1C 44810000 */  mtc1      $at, $f0
/* CC4230 80240A20 0C00A6C9 */  jal       clamp_angle
/* CC4234 80240A24 46006301 */   sub.s    $f12, $f12, $f0
/* CC4238 80240A28 E600000C */  swc1      $f0, 0xc($s0)
/* CC423C 80240A2C 8E4200CC */  lw        $v0, 0xcc($s2)
/* CC4240 80240A30 8C420000 */  lw        $v0, ($v0)
/* CC4244 80240A34 AE020028 */  sw        $v0, 0x28($s0)
/* CC4248 80240A38 24020003 */  addiu     $v0, $zero, 3
/* CC424C 80240A3C AE620070 */  sw        $v0, 0x70($s3)
/* CC4250 80240A40 8FBF0020 */  lw        $ra, 0x20($sp)
/* CC4254 80240A44 8FB3001C */  lw        $s3, 0x1c($sp)
/* CC4258 80240A48 8FB20018 */  lw        $s2, 0x18($sp)
/* CC425C 80240A4C 8FB10014 */  lw        $s1, 0x14($sp)
/* CC4260 80240A50 8FB00010 */  lw        $s0, 0x10($sp)
/* CC4264 80240A54 03E00008 */  jr        $ra
/* CC4268 80240A58 27BD0028 */   addiu    $sp, $sp, 0x28
