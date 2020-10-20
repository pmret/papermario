.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241320_D8E570
/* D8E570 80241320 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D8E574 80241324 AFB3001C */  sw        $s3, 0x1c($sp)
/* D8E578 80241328 0080982D */  daddu     $s3, $a0, $zero
/* D8E57C 8024132C AFBF0020 */  sw        $ra, 0x20($sp)
/* D8E580 80241330 AFB20018 */  sw        $s2, 0x18($sp)
/* D8E584 80241334 AFB10014 */  sw        $s1, 0x14($sp)
/* D8E588 80241338 AFB00010 */  sw        $s0, 0x10($sp)
/* D8E58C 8024133C 8E720148 */  lw        $s2, 0x148($s3)
/* D8E590 80241340 86440008 */  lh        $a0, 8($s2)
/* D8E594 80241344 0C00EABB */  jal       get_npc_unsafe
/* D8E598 80241348 00A0882D */   daddu    $s1, $a1, $zero
/* D8E59C 8024134C 8E240008 */  lw        $a0, 8($s1)
/* D8E5A0 80241350 0040802D */  daddu     $s0, $v0, $zero
/* D8E5A4 80241354 00041FC2 */  srl       $v1, $a0, 0x1f
/* D8E5A8 80241358 00832021 */  addu      $a0, $a0, $v1
/* D8E5AC 8024135C 00042043 */  sra       $a0, $a0, 1
/* D8E5B0 80241360 0C00A67F */  jal       rand_int
/* D8E5B4 80241364 24840001 */   addiu    $a0, $a0, 1
/* D8E5B8 80241368 8E230008 */  lw        $v1, 8($s1)
/* D8E5BC 8024136C 240400B4 */  addiu     $a0, $zero, 0xb4
/* D8E5C0 80241370 00032FC2 */  srl       $a1, $v1, 0x1f
/* D8E5C4 80241374 00651821 */  addu      $v1, $v1, $a1
/* D8E5C8 80241378 00031843 */  sra       $v1, $v1, 1
/* D8E5CC 8024137C 00621821 */  addu      $v1, $v1, $v0
/* D8E5D0 80241380 0C00A67F */  jal       rand_int
/* D8E5D4 80241384 A603008E */   sh       $v1, 0x8e($s0)
/* D8E5D8 80241388 C60C000C */  lwc1      $f12, 0xc($s0)
/* D8E5DC 8024138C 44820000 */  mtc1      $v0, $f0
/* D8E5E0 80241390 00000000 */  nop       
/* D8E5E4 80241394 46800020 */  cvt.s.w   $f0, $f0
/* D8E5E8 80241398 46006300 */  add.s     $f12, $f12, $f0
/* D8E5EC 8024139C 3C0142B4 */  lui       $at, 0x42b4
/* D8E5F0 802413A0 44810000 */  mtc1      $at, $f0
/* D8E5F4 802413A4 0C00A6C9 */  jal       clamp_angle
/* D8E5F8 802413A8 46006301 */   sub.s    $f12, $f12, $f0
/* D8E5FC 802413AC E600000C */  swc1      $f0, 0xc($s0)
/* D8E600 802413B0 8E4200CC */  lw        $v0, 0xcc($s2)
/* D8E604 802413B4 8C420000 */  lw        $v0, ($v0)
/* D8E608 802413B8 AE020028 */  sw        $v0, 0x28($s0)
/* D8E60C 802413BC 24020003 */  addiu     $v0, $zero, 3
/* D8E610 802413C0 AE620070 */  sw        $v0, 0x70($s3)
/* D8E614 802413C4 8FBF0020 */  lw        $ra, 0x20($sp)
/* D8E618 802413C8 8FB3001C */  lw        $s3, 0x1c($sp)
/* D8E61C 802413CC 8FB20018 */  lw        $s2, 0x18($sp)
/* D8E620 802413D0 8FB10014 */  lw        $s1, 0x14($sp)
/* D8E624 802413D4 8FB00010 */  lw        $s0, 0x10($sp)
/* D8E628 802413D8 03E00008 */  jr        $ra
/* D8E62C 802413DC 27BD0028 */   addiu    $sp, $sp, 0x28
