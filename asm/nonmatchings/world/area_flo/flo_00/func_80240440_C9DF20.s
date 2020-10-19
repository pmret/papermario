.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240440_C9E360
/* C9E360 80240440 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C9E364 80240444 AFB3001C */  sw        $s3, 0x1c($sp)
/* C9E368 80240448 0080982D */  daddu     $s3, $a0, $zero
/* C9E36C 8024044C AFBF0020 */  sw        $ra, 0x20($sp)
/* C9E370 80240450 AFB20018 */  sw        $s2, 0x18($sp)
/* C9E374 80240454 AFB10014 */  sw        $s1, 0x14($sp)
/* C9E378 80240458 AFB00010 */  sw        $s0, 0x10($sp)
/* C9E37C 8024045C 8E720148 */  lw        $s2, 0x148($s3)
/* C9E380 80240460 86440008 */  lh        $a0, 8($s2)
/* C9E384 80240464 0C00EABB */  jal       get_npc_unsafe
/* C9E388 80240468 00A0882D */   daddu    $s1, $a1, $zero
/* C9E38C 8024046C 8E240008 */  lw        $a0, 8($s1)
/* C9E390 80240470 0040802D */  daddu     $s0, $v0, $zero
/* C9E394 80240474 00041FC2 */  srl       $v1, $a0, 0x1f
/* C9E398 80240478 00832021 */  addu      $a0, $a0, $v1
/* C9E39C 8024047C 00042043 */  sra       $a0, $a0, 1
/* C9E3A0 80240480 0C00A67F */  jal       rand_int
/* C9E3A4 80240484 24840001 */   addiu    $a0, $a0, 1
/* C9E3A8 80240488 8E230008 */  lw        $v1, 8($s1)
/* C9E3AC 8024048C 240400B4 */  addiu     $a0, $zero, 0xb4
/* C9E3B0 80240490 00032FC2 */  srl       $a1, $v1, 0x1f
/* C9E3B4 80240494 00651821 */  addu      $v1, $v1, $a1
/* C9E3B8 80240498 00031843 */  sra       $v1, $v1, 1
/* C9E3BC 8024049C 00621821 */  addu      $v1, $v1, $v0
/* C9E3C0 802404A0 0C00A67F */  jal       rand_int
/* C9E3C4 802404A4 A603008E */   sh       $v1, 0x8e($s0)
/* C9E3C8 802404A8 C60C000C */  lwc1      $f12, 0xc($s0)
/* C9E3CC 802404AC 44820000 */  mtc1      $v0, $f0
/* C9E3D0 802404B0 00000000 */  nop       
/* C9E3D4 802404B4 46800020 */  cvt.s.w   $f0, $f0
/* C9E3D8 802404B8 46006300 */  add.s     $f12, $f12, $f0
/* C9E3DC 802404BC 3C0142B4 */  lui       $at, 0x42b4
/* C9E3E0 802404C0 44810000 */  mtc1      $at, $f0
/* C9E3E4 802404C4 0C00A6C9 */  jal       clamp_angle
/* C9E3E8 802404C8 46006301 */   sub.s    $f12, $f12, $f0
/* C9E3EC 802404CC E600000C */  swc1      $f0, 0xc($s0)
/* C9E3F0 802404D0 8E4200CC */  lw        $v0, 0xcc($s2)
/* C9E3F4 802404D4 8C420000 */  lw        $v0, ($v0)
/* C9E3F8 802404D8 AE020028 */  sw        $v0, 0x28($s0)
/* C9E3FC 802404DC 24020003 */  addiu     $v0, $zero, 3
/* C9E400 802404E0 AE620070 */  sw        $v0, 0x70($s3)
/* C9E404 802404E4 8FBF0020 */  lw        $ra, 0x20($sp)
/* C9E408 802404E8 8FB3001C */  lw        $s3, 0x1c($sp)
/* C9E40C 802404EC 8FB20018 */  lw        $s2, 0x18($sp)
/* C9E410 802404F0 8FB10014 */  lw        $s1, 0x14($sp)
/* C9E414 802404F4 8FB00010 */  lw        $s0, 0x10($sp)
/* C9E418 802404F8 03E00008 */  jr        $ra
/* C9E41C 802404FC 27BD0028 */   addiu    $sp, $sp, 0x28
