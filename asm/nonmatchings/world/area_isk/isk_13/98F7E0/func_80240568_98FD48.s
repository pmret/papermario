.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240568_98FD48
/* 98FD48 80240568 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 98FD4C 8024056C AFB3001C */  sw        $s3, 0x1c($sp)
/* 98FD50 80240570 0080982D */  daddu     $s3, $a0, $zero
/* 98FD54 80240574 AFBF0020 */  sw        $ra, 0x20($sp)
/* 98FD58 80240578 AFB20018 */  sw        $s2, 0x18($sp)
/* 98FD5C 8024057C AFB10014 */  sw        $s1, 0x14($sp)
/* 98FD60 80240580 AFB00010 */  sw        $s0, 0x10($sp)
/* 98FD64 80240584 8E720148 */  lw        $s2, 0x148($s3)
/* 98FD68 80240588 86440008 */  lh        $a0, 8($s2)
/* 98FD6C 8024058C 0C00EABB */  jal       get_npc_unsafe
/* 98FD70 80240590 00A0882D */   daddu    $s1, $a1, $zero
/* 98FD74 80240594 8E240008 */  lw        $a0, 8($s1)
/* 98FD78 80240598 0040802D */  daddu     $s0, $v0, $zero
/* 98FD7C 8024059C 00041FC2 */  srl       $v1, $a0, 0x1f
/* 98FD80 802405A0 00832021 */  addu      $a0, $a0, $v1
/* 98FD84 802405A4 00042043 */  sra       $a0, $a0, 1
/* 98FD88 802405A8 0C00A67F */  jal       rand_int
/* 98FD8C 802405AC 24840001 */   addiu    $a0, $a0, 1
/* 98FD90 802405B0 8E230008 */  lw        $v1, 8($s1)
/* 98FD94 802405B4 240400B4 */  addiu     $a0, $zero, 0xb4
/* 98FD98 802405B8 00032FC2 */  srl       $a1, $v1, 0x1f
/* 98FD9C 802405BC 00651821 */  addu      $v1, $v1, $a1
/* 98FDA0 802405C0 00031843 */  sra       $v1, $v1, 1
/* 98FDA4 802405C4 00621821 */  addu      $v1, $v1, $v0
/* 98FDA8 802405C8 0C00A67F */  jal       rand_int
/* 98FDAC 802405CC A603008E */   sh       $v1, 0x8e($s0)
/* 98FDB0 802405D0 C60C000C */  lwc1      $f12, 0xc($s0)
/* 98FDB4 802405D4 44820000 */  mtc1      $v0, $f0
/* 98FDB8 802405D8 00000000 */  nop       
/* 98FDBC 802405DC 46800020 */  cvt.s.w   $f0, $f0
/* 98FDC0 802405E0 46006300 */  add.s     $f12, $f12, $f0
/* 98FDC4 802405E4 3C0142B4 */  lui       $at, 0x42b4
/* 98FDC8 802405E8 44810000 */  mtc1      $at, $f0
/* 98FDCC 802405EC 0C00A6C9 */  jal       clamp_angle
/* 98FDD0 802405F0 46006301 */   sub.s    $f12, $f12, $f0
/* 98FDD4 802405F4 E600000C */  swc1      $f0, 0xc($s0)
/* 98FDD8 802405F8 8E4200CC */  lw        $v0, 0xcc($s2)
/* 98FDDC 802405FC 8C420000 */  lw        $v0, ($v0)
/* 98FDE0 80240600 AE020028 */  sw        $v0, 0x28($s0)
/* 98FDE4 80240604 24020003 */  addiu     $v0, $zero, 3
/* 98FDE8 80240608 AE620070 */  sw        $v0, 0x70($s3)
/* 98FDEC 8024060C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 98FDF0 80240610 8FB3001C */  lw        $s3, 0x1c($sp)
/* 98FDF4 80240614 8FB20018 */  lw        $s2, 0x18($sp)
/* 98FDF8 80240618 8FB10014 */  lw        $s1, 0x14($sp)
/* 98FDFC 8024061C 8FB00010 */  lw        $s0, 0x10($sp)
/* 98FE00 80240620 03E00008 */  jr        $ra
/* 98FE04 80240624 27BD0028 */   addiu    $sp, $sp, 0x28
