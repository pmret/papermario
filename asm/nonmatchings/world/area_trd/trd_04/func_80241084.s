.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241084
/* 9A9474 80241084 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9A9478 80241088 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9A947C 8024108C 0080982D */  daddu     $s3, $a0, $zero
/* 9A9480 80241090 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9A9484 80241094 AFB20018 */  sw        $s2, 0x18($sp)
/* 9A9488 80241098 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A948C 8024109C AFB00010 */  sw        $s0, 0x10($sp)
/* 9A9490 802410A0 8E720148 */  lw        $s2, 0x148($s3)
/* 9A9494 802410A4 86440008 */  lh        $a0, 8($s2)
/* 9A9498 802410A8 0C00EABB */  jal       get_npc_unsafe
/* 9A949C 802410AC 00A0882D */   daddu    $s1, $a1, $zero
/* 9A94A0 802410B0 8E240008 */  lw        $a0, 8($s1)
/* 9A94A4 802410B4 0040802D */  daddu     $s0, $v0, $zero
/* 9A94A8 802410B8 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9A94AC 802410BC 00832021 */  addu      $a0, $a0, $v1
/* 9A94B0 802410C0 00042043 */  sra       $a0, $a0, 1
/* 9A94B4 802410C4 0C00A67F */  jal       rand_int
/* 9A94B8 802410C8 24840001 */   addiu    $a0, $a0, 1
/* 9A94BC 802410CC 8E230008 */  lw        $v1, 8($s1)
/* 9A94C0 802410D0 240400B4 */  addiu     $a0, $zero, 0xb4
/* 9A94C4 802410D4 00032FC2 */  srl       $a1, $v1, 0x1f
/* 9A94C8 802410D8 00651821 */  addu      $v1, $v1, $a1
/* 9A94CC 802410DC 00031843 */  sra       $v1, $v1, 1
/* 9A94D0 802410E0 00621821 */  addu      $v1, $v1, $v0
/* 9A94D4 802410E4 0C00A67F */  jal       rand_int
/* 9A94D8 802410E8 A603008E */   sh       $v1, 0x8e($s0)
/* 9A94DC 802410EC C60C000C */  lwc1      $f12, 0xc($s0)
/* 9A94E0 802410F0 44820000 */  mtc1      $v0, $f0
/* 9A94E4 802410F4 00000000 */  nop       
/* 9A94E8 802410F8 46800020 */  cvt.s.w   $f0, $f0
/* 9A94EC 802410FC 46006300 */  add.s     $f12, $f12, $f0
/* 9A94F0 80241100 3C0142B4 */  lui       $at, 0x42b4
/* 9A94F4 80241104 44810000 */  mtc1      $at, $f0
/* 9A94F8 80241108 0C00A6C9 */  jal       clamp_angle
/* 9A94FC 8024110C 46006301 */   sub.s    $f12, $f12, $f0
/* 9A9500 80241110 E600000C */  swc1      $f0, 0xc($s0)
/* 9A9504 80241114 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9A9508 80241118 8C420000 */  lw        $v0, ($v0)
/* 9A950C 8024111C AE020028 */  sw        $v0, 0x28($s0)
/* 9A9510 80241120 24020003 */  addiu     $v0, $zero, 3
/* 9A9514 80241124 AE620070 */  sw        $v0, 0x70($s3)
/* 9A9518 80241128 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9A951C 8024112C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9A9520 80241130 8FB20018 */  lw        $s2, 0x18($sp)
/* 9A9524 80241134 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A9528 80241138 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A952C 8024113C 03E00008 */  jr        $ra
/* 9A9530 80241140 27BD0028 */   addiu    $sp, $sp, 0x28
