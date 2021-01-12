.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240440_EB9290
/* EB9290 80240440 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EB9294 80240444 AFB3001C */  sw        $s3, 0x1c($sp)
/* EB9298 80240448 0080982D */  daddu     $s3, $a0, $zero
/* EB929C 8024044C AFBF0020 */  sw        $ra, 0x20($sp)
/* EB92A0 80240450 AFB20018 */  sw        $s2, 0x18($sp)
/* EB92A4 80240454 AFB10014 */  sw        $s1, 0x14($sp)
/* EB92A8 80240458 AFB00010 */  sw        $s0, 0x10($sp)
/* EB92AC 8024045C 8E720148 */  lw        $s2, 0x148($s3)
/* EB92B0 80240460 86440008 */  lh        $a0, 8($s2)
/* EB92B4 80240464 0C00F92F */  jal       func_8003E4BC
/* EB92B8 80240468 00A0882D */   daddu    $s1, $a1, $zero
/* EB92BC 8024046C 8E240008 */  lw        $a0, 8($s1)
/* EB92C0 80240470 0040802D */  daddu     $s0, $v0, $zero
/* EB92C4 80240474 00041FC2 */  srl       $v1, $a0, 0x1f
/* EB92C8 80240478 00832021 */  addu      $a0, $a0, $v1
/* EB92CC 8024047C 00042043 */  sra       $a0, $a0, 1
/* EB92D0 80240480 0C00AB3B */  jal       func_8002ACEC
/* EB92D4 80240484 24840001 */   addiu    $a0, $a0, 1
/* EB92D8 80240488 8E230008 */  lw        $v1, 8($s1)
/* EB92DC 8024048C 240400B4 */  addiu     $a0, $zero, 0xb4
/* EB92E0 80240490 00032FC2 */  srl       $a1, $v1, 0x1f
/* EB92E4 80240494 00651821 */  addu      $v1, $v1, $a1
/* EB92E8 80240498 00031843 */  sra       $v1, $v1, 1
/* EB92EC 8024049C 00621821 */  addu      $v1, $v1, $v0
/* EB92F0 802404A0 0C00AB3B */  jal       func_8002ACEC
/* EB92F4 802404A4 A603008E */   sh       $v1, 0x8e($s0)
/* EB92F8 802404A8 C60C000C */  lwc1      $f12, 0xc($s0)
/* EB92FC 802404AC 44820000 */  mtc1      $v0, $f0
/* EB9300 802404B0 00000000 */  nop       
/* EB9304 802404B4 46800020 */  cvt.s.w   $f0, $f0
/* EB9308 802404B8 46006300 */  add.s     $f12, $f12, $f0
/* EB930C 802404BC 3C0142B4 */  lui       $at, 0x42b4
/* EB9310 802404C0 44810000 */  mtc1      $at, $f0
/* EB9314 802404C4 0C00AB85 */  jal       func_8002AE14
/* EB9318 802404C8 46006301 */   sub.s    $f12, $f12, $f0
/* EB931C 802404CC E600000C */  swc1      $f0, 0xc($s0)
/* EB9320 802404D0 8E4200CC */  lw        $v0, 0xcc($s2)
/* EB9324 802404D4 8C420000 */  lw        $v0, ($v0)
/* EB9328 802404D8 AE020028 */  sw        $v0, 0x28($s0)
/* EB932C 802404DC 24020003 */  addiu     $v0, $zero, 3
/* EB9330 802404E0 AE620070 */  sw        $v0, 0x70($s3)
/* EB9334 802404E4 8FBF0020 */  lw        $ra, 0x20($sp)
/* EB9338 802404E8 8FB3001C */  lw        $s3, 0x1c($sp)
/* EB933C 802404EC 8FB20018 */  lw        $s2, 0x18($sp)
/* EB9340 802404F0 8FB10014 */  lw        $s1, 0x14($sp)
/* EB9344 802404F4 8FB00010 */  lw        $s0, 0x10($sp)
/* EB9348 802404F8 03E00008 */  jr        $ra
/* EB934C 802404FC 27BD0028 */   addiu    $sp, $sp, 0x28
