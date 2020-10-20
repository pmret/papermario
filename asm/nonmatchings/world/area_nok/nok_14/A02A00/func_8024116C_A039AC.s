.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024116C_A039AC
/* A039AC 8024116C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A039B0 80241170 AFB3001C */  sw        $s3, 0x1c($sp)
/* A039B4 80241174 0080982D */  daddu     $s3, $a0, $zero
/* A039B8 80241178 AFBF0020 */  sw        $ra, 0x20($sp)
/* A039BC 8024117C AFB20018 */  sw        $s2, 0x18($sp)
/* A039C0 80241180 AFB10014 */  sw        $s1, 0x14($sp)
/* A039C4 80241184 AFB00010 */  sw        $s0, 0x10($sp)
/* A039C8 80241188 8E720148 */  lw        $s2, 0x148($s3)
/* A039CC 8024118C 86440008 */  lh        $a0, 8($s2)
/* A039D0 80241190 0C00EABB */  jal       get_npc_unsafe
/* A039D4 80241194 00A0882D */   daddu    $s1, $a1, $zero
/* A039D8 80241198 8E240008 */  lw        $a0, 8($s1)
/* A039DC 8024119C 0040802D */  daddu     $s0, $v0, $zero
/* A039E0 802411A0 00041FC2 */  srl       $v1, $a0, 0x1f
/* A039E4 802411A4 00832021 */  addu      $a0, $a0, $v1
/* A039E8 802411A8 00042043 */  sra       $a0, $a0, 1
/* A039EC 802411AC 0C00A67F */  jal       rand_int
/* A039F0 802411B0 24840001 */   addiu    $a0, $a0, 1
/* A039F4 802411B4 8E230008 */  lw        $v1, 8($s1)
/* A039F8 802411B8 240400B4 */  addiu     $a0, $zero, 0xb4
/* A039FC 802411BC 00032FC2 */  srl       $a1, $v1, 0x1f
/* A03A00 802411C0 00651821 */  addu      $v1, $v1, $a1
/* A03A04 802411C4 00031843 */  sra       $v1, $v1, 1
/* A03A08 802411C8 00621821 */  addu      $v1, $v1, $v0
/* A03A0C 802411CC 0C00A67F */  jal       rand_int
/* A03A10 802411D0 A603008E */   sh       $v1, 0x8e($s0)
/* A03A14 802411D4 C60C000C */  lwc1      $f12, 0xc($s0)
/* A03A18 802411D8 44820000 */  mtc1      $v0, $f0
/* A03A1C 802411DC 00000000 */  nop       
/* A03A20 802411E0 46800020 */  cvt.s.w   $f0, $f0
/* A03A24 802411E4 46006300 */  add.s     $f12, $f12, $f0
/* A03A28 802411E8 3C0142B4 */  lui       $at, 0x42b4
/* A03A2C 802411EC 44810000 */  mtc1      $at, $f0
/* A03A30 802411F0 0C00A6C9 */  jal       clamp_angle
/* A03A34 802411F4 46006301 */   sub.s    $f12, $f12, $f0
/* A03A38 802411F8 E600000C */  swc1      $f0, 0xc($s0)
/* A03A3C 802411FC 8E4200CC */  lw        $v0, 0xcc($s2)
/* A03A40 80241200 8C420000 */  lw        $v0, ($v0)
/* A03A44 80241204 AE020028 */  sw        $v0, 0x28($s0)
/* A03A48 80241208 24020003 */  addiu     $v0, $zero, 3
/* A03A4C 8024120C AE620070 */  sw        $v0, 0x70($s3)
/* A03A50 80241210 8FBF0020 */  lw        $ra, 0x20($sp)
/* A03A54 80241214 8FB3001C */  lw        $s3, 0x1c($sp)
/* A03A58 80241218 8FB20018 */  lw        $s2, 0x18($sp)
/* A03A5C 8024121C 8FB10014 */  lw        $s1, 0x14($sp)
/* A03A60 80241220 8FB00010 */  lw        $s0, 0x10($sp)
/* A03A64 80241224 03E00008 */  jr        $ra
/* A03A68 80241228 27BD0028 */   addiu    $sp, $sp, 0x28
