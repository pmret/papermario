.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024128C_A0818C
/* A0818C 8024128C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A08190 80241290 AFB3001C */  sw        $s3, 0x1c($sp)
/* A08194 80241294 0080982D */  daddu     $s3, $a0, $zero
/* A08198 80241298 AFBF0020 */  sw        $ra, 0x20($sp)
/* A0819C 8024129C AFB20018 */  sw        $s2, 0x18($sp)
/* A081A0 802412A0 AFB10014 */  sw        $s1, 0x14($sp)
/* A081A4 802412A4 AFB00010 */  sw        $s0, 0x10($sp)
/* A081A8 802412A8 8E720148 */  lw        $s2, 0x148($s3)
/* A081AC 802412AC 86440008 */  lh        $a0, 8($s2)
/* A081B0 802412B0 0C00EABB */  jal       get_npc_unsafe
/* A081B4 802412B4 00A0882D */   daddu    $s1, $a1, $zero
/* A081B8 802412B8 8E240008 */  lw        $a0, 8($s1)
/* A081BC 802412BC 0040802D */  daddu     $s0, $v0, $zero
/* A081C0 802412C0 00041FC2 */  srl       $v1, $a0, 0x1f
/* A081C4 802412C4 00832021 */  addu      $a0, $a0, $v1
/* A081C8 802412C8 00042043 */  sra       $a0, $a0, 1
/* A081CC 802412CC 0C00A67F */  jal       rand_int
/* A081D0 802412D0 24840001 */   addiu    $a0, $a0, 1
/* A081D4 802412D4 8E230008 */  lw        $v1, 8($s1)
/* A081D8 802412D8 240400B4 */  addiu     $a0, $zero, 0xb4
/* A081DC 802412DC 00032FC2 */  srl       $a1, $v1, 0x1f
/* A081E0 802412E0 00651821 */  addu      $v1, $v1, $a1
/* A081E4 802412E4 00031843 */  sra       $v1, $v1, 1
/* A081E8 802412E8 00621821 */  addu      $v1, $v1, $v0
/* A081EC 802412EC 0C00A67F */  jal       rand_int
/* A081F0 802412F0 A603008E */   sh       $v1, 0x8e($s0)
/* A081F4 802412F4 C60C000C */  lwc1      $f12, 0xc($s0)
/* A081F8 802412F8 44820000 */  mtc1      $v0, $f0
/* A081FC 802412FC 00000000 */  nop       
/* A08200 80241300 46800020 */  cvt.s.w   $f0, $f0
/* A08204 80241304 46006300 */  add.s     $f12, $f12, $f0
/* A08208 80241308 3C0142B4 */  lui       $at, 0x42b4
/* A0820C 8024130C 44810000 */  mtc1      $at, $f0
/* A08210 80241310 0C00A6C9 */  jal       clamp_angle
/* A08214 80241314 46006301 */   sub.s    $f12, $f12, $f0
/* A08218 80241318 E600000C */  swc1      $f0, 0xc($s0)
/* A0821C 8024131C 8E4200CC */  lw        $v0, 0xcc($s2)
/* A08220 80241320 8C420000 */  lw        $v0, ($v0)
/* A08224 80241324 AE020028 */  sw        $v0, 0x28($s0)
/* A08228 80241328 24020003 */  addiu     $v0, $zero, 3
/* A0822C 8024132C AE620070 */  sw        $v0, 0x70($s3)
/* A08230 80241330 8FBF0020 */  lw        $ra, 0x20($sp)
/* A08234 80241334 8FB3001C */  lw        $s3, 0x1c($sp)
/* A08238 80241338 8FB20018 */  lw        $s2, 0x18($sp)
/* A0823C 8024133C 8FB10014 */  lw        $s1, 0x14($sp)
/* A08240 80241340 8FB00010 */  lw        $s0, 0x10($sp)
/* A08244 80241344 03E00008 */  jr        $ra
/* A08248 80241348 27BD0028 */   addiu    $sp, $sp, 0x28
