.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E0C_B4B87C
/* B4B87C 80240E0C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B4B880 80240E10 AFB3001C */  sw        $s3, 0x1c($sp)
/* B4B884 80240E14 0080982D */  daddu     $s3, $a0, $zero
/* B4B888 80240E18 AFBF0020 */  sw        $ra, 0x20($sp)
/* B4B88C 80240E1C AFB20018 */  sw        $s2, 0x18($sp)
/* B4B890 80240E20 AFB10014 */  sw        $s1, 0x14($sp)
/* B4B894 80240E24 AFB00010 */  sw        $s0, 0x10($sp)
/* B4B898 80240E28 8E720148 */  lw        $s2, 0x148($s3)
/* B4B89C 80240E2C 86440008 */  lh        $a0, 8($s2)
/* B4B8A0 80240E30 0C00EABB */  jal       get_npc_unsafe
/* B4B8A4 80240E34 00A0882D */   daddu    $s1, $a1, $zero
/* B4B8A8 80240E38 8E240008 */  lw        $a0, 8($s1)
/* B4B8AC 80240E3C 0040802D */  daddu     $s0, $v0, $zero
/* B4B8B0 80240E40 00041FC2 */  srl       $v1, $a0, 0x1f
/* B4B8B4 80240E44 00832021 */  addu      $a0, $a0, $v1
/* B4B8B8 80240E48 00042043 */  sra       $a0, $a0, 1
/* B4B8BC 80240E4C 0C00A67F */  jal       rand_int
/* B4B8C0 80240E50 24840001 */   addiu    $a0, $a0, 1
/* B4B8C4 80240E54 8E230008 */  lw        $v1, 8($s1)
/* B4B8C8 80240E58 240400B4 */  addiu     $a0, $zero, 0xb4
/* B4B8CC 80240E5C 00032FC2 */  srl       $a1, $v1, 0x1f
/* B4B8D0 80240E60 00651821 */  addu      $v1, $v1, $a1
/* B4B8D4 80240E64 00031843 */  sra       $v1, $v1, 1
/* B4B8D8 80240E68 00621821 */  addu      $v1, $v1, $v0
/* B4B8DC 80240E6C 0C00A67F */  jal       rand_int
/* B4B8E0 80240E70 A603008E */   sh       $v1, 0x8e($s0)
/* B4B8E4 80240E74 C60C000C */  lwc1      $f12, 0xc($s0)
/* B4B8E8 80240E78 44820000 */  mtc1      $v0, $f0
/* B4B8EC 80240E7C 00000000 */  nop       
/* B4B8F0 80240E80 46800020 */  cvt.s.w   $f0, $f0
/* B4B8F4 80240E84 46006300 */  add.s     $f12, $f12, $f0
/* B4B8F8 80240E88 3C0142B4 */  lui       $at, 0x42b4
/* B4B8FC 80240E8C 44810000 */  mtc1      $at, $f0
/* B4B900 80240E90 0C00A6C9 */  jal       clamp_angle
/* B4B904 80240E94 46006301 */   sub.s    $f12, $f12, $f0
/* B4B908 80240E98 E600000C */  swc1      $f0, 0xc($s0)
/* B4B90C 80240E9C 8E4200CC */  lw        $v0, 0xcc($s2)
/* B4B910 80240EA0 8C420000 */  lw        $v0, ($v0)
/* B4B914 80240EA4 AE020028 */  sw        $v0, 0x28($s0)
/* B4B918 80240EA8 24020003 */  addiu     $v0, $zero, 3
/* B4B91C 80240EAC AE620070 */  sw        $v0, 0x70($s3)
/* B4B920 80240EB0 8FBF0020 */  lw        $ra, 0x20($sp)
/* B4B924 80240EB4 8FB3001C */  lw        $s3, 0x1c($sp)
/* B4B928 80240EB8 8FB20018 */  lw        $s2, 0x18($sp)
/* B4B92C 80240EBC 8FB10014 */  lw        $s1, 0x14($sp)
/* B4B930 80240EC0 8FB00010 */  lw        $s0, 0x10($sp)
/* B4B934 80240EC4 03E00008 */  jr        $ra
/* B4B938 80240EC8 27BD0028 */   addiu    $sp, $sp, 0x28
