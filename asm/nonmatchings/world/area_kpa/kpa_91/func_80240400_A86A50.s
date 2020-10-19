.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240400_A86E50
/* A86E50 80240400 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A86E54 80240404 AFB3001C */  sw        $s3, 0x1c($sp)
/* A86E58 80240408 0080982D */  daddu     $s3, $a0, $zero
/* A86E5C 8024040C AFBF0020 */  sw        $ra, 0x20($sp)
/* A86E60 80240410 AFB20018 */  sw        $s2, 0x18($sp)
/* A86E64 80240414 AFB10014 */  sw        $s1, 0x14($sp)
/* A86E68 80240418 AFB00010 */  sw        $s0, 0x10($sp)
/* A86E6C 8024041C 8E720148 */  lw        $s2, 0x148($s3)
/* A86E70 80240420 86440008 */  lh        $a0, 8($s2)
/* A86E74 80240424 0C00EABB */  jal       get_npc_unsafe
/* A86E78 80240428 00A0882D */   daddu    $s1, $a1, $zero
/* A86E7C 8024042C 8E240008 */  lw        $a0, 8($s1)
/* A86E80 80240430 0040802D */  daddu     $s0, $v0, $zero
/* A86E84 80240434 00041FC2 */  srl       $v1, $a0, 0x1f
/* A86E88 80240438 00832021 */  addu      $a0, $a0, $v1
/* A86E8C 8024043C 00042043 */  sra       $a0, $a0, 1
/* A86E90 80240440 0C00A67F */  jal       rand_int
/* A86E94 80240444 24840001 */   addiu    $a0, $a0, 1
/* A86E98 80240448 8E230008 */  lw        $v1, 8($s1)
/* A86E9C 8024044C 240400B4 */  addiu     $a0, $zero, 0xb4
/* A86EA0 80240450 00032FC2 */  srl       $a1, $v1, 0x1f
/* A86EA4 80240454 00651821 */  addu      $v1, $v1, $a1
/* A86EA8 80240458 00031843 */  sra       $v1, $v1, 1
/* A86EAC 8024045C 00621821 */  addu      $v1, $v1, $v0
/* A86EB0 80240460 0C00A67F */  jal       rand_int
/* A86EB4 80240464 A603008E */   sh       $v1, 0x8e($s0)
/* A86EB8 80240468 C60C000C */  lwc1      $f12, 0xc($s0)
/* A86EBC 8024046C 44820000 */  mtc1      $v0, $f0
/* A86EC0 80240470 00000000 */  nop       
/* A86EC4 80240474 46800020 */  cvt.s.w   $f0, $f0
/* A86EC8 80240478 46006300 */  add.s     $f12, $f12, $f0
/* A86ECC 8024047C 3C0142B4 */  lui       $at, 0x42b4
/* A86ED0 80240480 44810000 */  mtc1      $at, $f0
/* A86ED4 80240484 0C00A6C9 */  jal       clamp_angle
/* A86ED8 80240488 46006301 */   sub.s    $f12, $f12, $f0
/* A86EDC 8024048C E600000C */  swc1      $f0, 0xc($s0)
/* A86EE0 80240490 8E4200CC */  lw        $v0, 0xcc($s2)
/* A86EE4 80240494 8C420000 */  lw        $v0, ($v0)
/* A86EE8 80240498 AE020028 */  sw        $v0, 0x28($s0)
/* A86EEC 8024049C 24020003 */  addiu     $v0, $zero, 3
/* A86EF0 802404A0 AE620070 */  sw        $v0, 0x70($s3)
/* A86EF4 802404A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* A86EF8 802404A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* A86EFC 802404AC 8FB20018 */  lw        $s2, 0x18($sp)
/* A86F00 802404B0 8FB10014 */  lw        $s1, 0x14($sp)
/* A86F04 802404B4 8FB00010 */  lw        $s0, 0x10($sp)
/* A86F08 802404B8 03E00008 */  jr        $ra
/* A86F0C 802404BC 27BD0028 */   addiu    $sp, $sp, 0x28
