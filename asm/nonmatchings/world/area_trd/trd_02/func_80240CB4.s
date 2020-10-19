.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CB4
/* 9A1C94 80240CB4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9A1C98 80240CB8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9A1C9C 80240CBC 0080982D */  daddu     $s3, $a0, $zero
/* 9A1CA0 80240CC0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9A1CA4 80240CC4 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A1CA8 80240CC8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A1CAC 80240CCC AFB00010 */  sw        $s0, 0x10($sp)
/* 9A1CB0 80240CD0 8E720148 */  lw        $s2, 0x148($s3)
/* 9A1CB4 80240CD4 86440008 */  lh        $a0, 8($s2)
/* 9A1CB8 80240CD8 0C00EABB */  jal       get_npc_unsafe
/* 9A1CBC 80240CDC 00A0882D */   daddu    $s1, $a1, $zero
/* 9A1CC0 80240CE0 8E240008 */  lw        $a0, 8($s1)
/* 9A1CC4 80240CE4 0040802D */  daddu     $s0, $v0, $zero
/* 9A1CC8 80240CE8 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9A1CCC 80240CEC 00832021 */  addu      $a0, $a0, $v1
/* 9A1CD0 80240CF0 00042043 */  sra       $a0, $a0, 1
/* 9A1CD4 80240CF4 0C00A67F */  jal       rand_int
/* 9A1CD8 80240CF8 24840001 */   addiu    $a0, $a0, 1
/* 9A1CDC 80240CFC 8E230008 */  lw        $v1, 8($s1)
/* 9A1CE0 80240D00 240400B4 */  addiu     $a0, $zero, 0xb4
/* 9A1CE4 80240D04 00032FC2 */  srl       $a1, $v1, 0x1f
/* 9A1CE8 80240D08 00651821 */  addu      $v1, $v1, $a1
/* 9A1CEC 80240D0C 00031843 */  sra       $v1, $v1, 1
/* 9A1CF0 80240D10 00621821 */  addu      $v1, $v1, $v0
/* 9A1CF4 80240D14 0C00A67F */  jal       rand_int
/* 9A1CF8 80240D18 A603008E */   sh       $v1, 0x8e($s0)
/* 9A1CFC 80240D1C C60C000C */  lwc1      $f12, 0xc($s0)
/* 9A1D00 80240D20 44820000 */  mtc1      $v0, $f0
/* 9A1D04 80240D24 00000000 */  nop       
/* 9A1D08 80240D28 46800020 */  cvt.s.w   $f0, $f0
/* 9A1D0C 80240D2C 46006300 */  add.s     $f12, $f12, $f0
/* 9A1D10 80240D30 3C0142B4 */  lui       $at, 0x42b4
/* 9A1D14 80240D34 44810000 */  mtc1      $at, $f0
/* 9A1D18 80240D38 0C00A6C9 */  jal       clamp_angle
/* 9A1D1C 80240D3C 46006301 */   sub.s    $f12, $f12, $f0
/* 9A1D20 80240D40 E600000C */  swc1      $f0, 0xc($s0)
/* 9A1D24 80240D44 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9A1D28 80240D48 8C420000 */  lw        $v0, ($v0)
/* 9A1D2C 80240D4C AE020028 */  sw        $v0, 0x28($s0)
/* 9A1D30 80240D50 24020003 */  addiu     $v0, $zero, 3
/* 9A1D34 80240D54 AE620070 */  sw        $v0, 0x70($s3)
/* 9A1D38 80240D58 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9A1D3C 80240D5C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9A1D40 80240D60 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A1D44 80240D64 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A1D48 80240D68 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A1D4C 80240D6C 03E00008 */  jr        $ra
/* 9A1D50 80240D70 27BD0028 */   addiu    $sp, $sp, 0x28
