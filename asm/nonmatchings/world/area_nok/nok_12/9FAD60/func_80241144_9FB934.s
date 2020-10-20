.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241144_9FB934
/* 9FB934 80241144 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9FB938 80241148 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9FB93C 8024114C 0080982D */  daddu     $s3, $a0, $zero
/* 9FB940 80241150 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9FB944 80241154 AFB20018 */  sw        $s2, 0x18($sp)
/* 9FB948 80241158 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FB94C 8024115C AFB00010 */  sw        $s0, 0x10($sp)
/* 9FB950 80241160 8E720148 */  lw        $s2, 0x148($s3)
/* 9FB954 80241164 86440008 */  lh        $a0, 8($s2)
/* 9FB958 80241168 0C00EABB */  jal       get_npc_unsafe
/* 9FB95C 8024116C 00A0882D */   daddu    $s1, $a1, $zero
/* 9FB960 80241170 8E240008 */  lw        $a0, 8($s1)
/* 9FB964 80241174 0040802D */  daddu     $s0, $v0, $zero
/* 9FB968 80241178 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9FB96C 8024117C 00832021 */  addu      $a0, $a0, $v1
/* 9FB970 80241180 00042043 */  sra       $a0, $a0, 1
/* 9FB974 80241184 0C00A67F */  jal       rand_int
/* 9FB978 80241188 24840001 */   addiu    $a0, $a0, 1
/* 9FB97C 8024118C 8E230008 */  lw        $v1, 8($s1)
/* 9FB980 80241190 240400B4 */  addiu     $a0, $zero, 0xb4
/* 9FB984 80241194 00032FC2 */  srl       $a1, $v1, 0x1f
/* 9FB988 80241198 00651821 */  addu      $v1, $v1, $a1
/* 9FB98C 8024119C 00031843 */  sra       $v1, $v1, 1
/* 9FB990 802411A0 00621821 */  addu      $v1, $v1, $v0
/* 9FB994 802411A4 0C00A67F */  jal       rand_int
/* 9FB998 802411A8 A603008E */   sh       $v1, 0x8e($s0)
/* 9FB99C 802411AC C60C000C */  lwc1      $f12, 0xc($s0)
/* 9FB9A0 802411B0 44820000 */  mtc1      $v0, $f0
/* 9FB9A4 802411B4 00000000 */  nop       
/* 9FB9A8 802411B8 46800020 */  cvt.s.w   $f0, $f0
/* 9FB9AC 802411BC 46006300 */  add.s     $f12, $f12, $f0
/* 9FB9B0 802411C0 3C0142B4 */  lui       $at, 0x42b4
/* 9FB9B4 802411C4 44810000 */  mtc1      $at, $f0
/* 9FB9B8 802411C8 0C00A6C9 */  jal       clamp_angle
/* 9FB9BC 802411CC 46006301 */   sub.s    $f12, $f12, $f0
/* 9FB9C0 802411D0 E600000C */  swc1      $f0, 0xc($s0)
/* 9FB9C4 802411D4 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9FB9C8 802411D8 8C420000 */  lw        $v0, ($v0)
/* 9FB9CC 802411DC AE020028 */  sw        $v0, 0x28($s0)
/* 9FB9D0 802411E0 24020003 */  addiu     $v0, $zero, 3
/* 9FB9D4 802411E4 AE620070 */  sw        $v0, 0x70($s3)
/* 9FB9D8 802411E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9FB9DC 802411EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9FB9E0 802411F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9FB9E4 802411F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FB9E8 802411F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FB9EC 802411FC 03E00008 */  jr        $ra
/* 9FB9F0 80241200 27BD0028 */   addiu    $sp, $sp, 0x28
