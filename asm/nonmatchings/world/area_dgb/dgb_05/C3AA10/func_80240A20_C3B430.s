.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A20_C3B430
/* C3B430 80240A20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3B434 80240A24 AFB10014 */  sw        $s1, 0x14($sp)
/* C3B438 80240A28 0080882D */  daddu     $s1, $a0, $zero
/* C3B43C 80240A2C AFBF001C */  sw        $ra, 0x1c($sp)
/* C3B440 80240A30 AFB20018 */  sw        $s2, 0x18($sp)
/* C3B444 80240A34 AFB00010 */  sw        $s0, 0x10($sp)
/* C3B448 80240A38 8E320148 */  lw        $s2, 0x148($s1)
/* C3B44C 80240A3C 0C00EABB */  jal       get_npc_unsafe
/* C3B450 80240A40 86440008 */   lh       $a0, 8($s2)
/* C3B454 80240A44 240400B4 */  addiu     $a0, $zero, 0xb4
/* C3B458 80240A48 0C00A67F */  jal       rand_int
/* C3B45C 80240A4C 0040802D */   daddu    $s0, $v0, $zero
/* C3B460 80240A50 C60C000C */  lwc1      $f12, 0xc($s0)
/* C3B464 80240A54 44820000 */  mtc1      $v0, $f0
/* C3B468 80240A58 00000000 */  nop
/* C3B46C 80240A5C 46800020 */  cvt.s.w   $f0, $f0
/* C3B470 80240A60 46006300 */  add.s     $f12, $f12, $f0
/* C3B474 80240A64 3C0142B4 */  lui       $at, 0x42b4
/* C3B478 80240A68 44810000 */  mtc1      $at, $f0
/* C3B47C 80240A6C 0C00A6C9 */  jal       clamp_angle
/* C3B480 80240A70 46006301 */   sub.s    $f12, $f12, $f0
/* C3B484 80240A74 E600000C */  swc1      $f0, 0xc($s0)
/* C3B488 80240A78 8E4200CC */  lw        $v0, 0xcc($s2)
/* C3B48C 80240A7C 8C420000 */  lw        $v0, ($v0)
/* C3B490 80240A80 240403E8 */  addiu     $a0, $zero, 0x3e8
/* C3B494 80240A84 0C00A67F */  jal       rand_int
/* C3B498 80240A88 AE020028 */   sw       $v0, 0x28($s0)
/* C3B49C 80240A8C 00021FC2 */  srl       $v1, $v0, 0x1f
/* C3B4A0 80240A90 00431821 */  addu      $v1, $v0, $v1
/* C3B4A4 80240A94 00031843 */  sra       $v1, $v1, 1
/* C3B4A8 80240A98 00031840 */  sll       $v1, $v1, 1
/* C3B4AC 80240A9C 00431023 */  subu      $v0, $v0, $v1
/* C3B4B0 80240AA0 24420002 */  addiu     $v0, $v0, 2
/* C3B4B4 80240AA4 AE220074 */  sw        $v0, 0x74($s1)
/* C3B4B8 80240AA8 24020004 */  addiu     $v0, $zero, 4
/* C3B4BC 80240AAC AE220070 */  sw        $v0, 0x70($s1)
/* C3B4C0 80240AB0 8FBF001C */  lw        $ra, 0x1c($sp)
/* C3B4C4 80240AB4 8FB20018 */  lw        $s2, 0x18($sp)
/* C3B4C8 80240AB8 8FB10014 */  lw        $s1, 0x14($sp)
/* C3B4CC 80240ABC 8FB00010 */  lw        $s0, 0x10($sp)
/* C3B4D0 80240AC0 03E00008 */  jr        $ra
/* C3B4D4 80240AC4 27BD0020 */   addiu    $sp, $sp, 0x20
