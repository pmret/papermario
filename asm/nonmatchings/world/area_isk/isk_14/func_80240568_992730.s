.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240568_992C98
/* 992C98 80240568 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 992C9C 8024056C AFB3001C */  sw        $s3, 0x1c($sp)
/* 992CA0 80240570 0080982D */  daddu     $s3, $a0, $zero
/* 992CA4 80240574 AFBF0020 */  sw        $ra, 0x20($sp)
/* 992CA8 80240578 AFB20018 */  sw        $s2, 0x18($sp)
/* 992CAC 8024057C AFB10014 */  sw        $s1, 0x14($sp)
/* 992CB0 80240580 AFB00010 */  sw        $s0, 0x10($sp)
/* 992CB4 80240584 8E720148 */  lw        $s2, 0x148($s3)
/* 992CB8 80240588 86440008 */  lh        $a0, 8($s2)
/* 992CBC 8024058C 0C00EABB */  jal       get_npc_unsafe
/* 992CC0 80240590 00A0882D */   daddu    $s1, $a1, $zero
/* 992CC4 80240594 8E240008 */  lw        $a0, 8($s1)
/* 992CC8 80240598 0040802D */  daddu     $s0, $v0, $zero
/* 992CCC 8024059C 00041FC2 */  srl       $v1, $a0, 0x1f
/* 992CD0 802405A0 00832021 */  addu      $a0, $a0, $v1
/* 992CD4 802405A4 00042043 */  sra       $a0, $a0, 1
/* 992CD8 802405A8 0C00A67F */  jal       rand_int
/* 992CDC 802405AC 24840001 */   addiu    $a0, $a0, 1
/* 992CE0 802405B0 8E230008 */  lw        $v1, 8($s1)
/* 992CE4 802405B4 240400B4 */  addiu     $a0, $zero, 0xb4
/* 992CE8 802405B8 00032FC2 */  srl       $a1, $v1, 0x1f
/* 992CEC 802405BC 00651821 */  addu      $v1, $v1, $a1
/* 992CF0 802405C0 00031843 */  sra       $v1, $v1, 1
/* 992CF4 802405C4 00621821 */  addu      $v1, $v1, $v0
/* 992CF8 802405C8 0C00A67F */  jal       rand_int
/* 992CFC 802405CC A603008E */   sh       $v1, 0x8e($s0)
/* 992D00 802405D0 C60C000C */  lwc1      $f12, 0xc($s0)
/* 992D04 802405D4 44820000 */  mtc1      $v0, $f0
/* 992D08 802405D8 00000000 */  nop       
/* 992D0C 802405DC 46800020 */  cvt.s.w   $f0, $f0
/* 992D10 802405E0 46006300 */  add.s     $f12, $f12, $f0
/* 992D14 802405E4 3C0142B4 */  lui       $at, 0x42b4
/* 992D18 802405E8 44810000 */  mtc1      $at, $f0
/* 992D1C 802405EC 0C00A6C9 */  jal       clamp_angle
/* 992D20 802405F0 46006301 */   sub.s    $f12, $f12, $f0
/* 992D24 802405F4 E600000C */  swc1      $f0, 0xc($s0)
/* 992D28 802405F8 8E4200CC */  lw        $v0, 0xcc($s2)
/* 992D2C 802405FC 8C420000 */  lw        $v0, ($v0)
/* 992D30 80240600 AE020028 */  sw        $v0, 0x28($s0)
/* 992D34 80240604 24020003 */  addiu     $v0, $zero, 3
/* 992D38 80240608 AE620070 */  sw        $v0, 0x70($s3)
/* 992D3C 8024060C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 992D40 80240610 8FB3001C */  lw        $s3, 0x1c($sp)
/* 992D44 80240614 8FB20018 */  lw        $s2, 0x18($sp)
/* 992D48 80240618 8FB10014 */  lw        $s1, 0x14($sp)
/* 992D4C 8024061C 8FB00010 */  lw        $s0, 0x10($sp)
/* 992D50 80240620 03E00008 */  jr        $ra
/* 992D54 80240624 27BD0028 */   addiu    $sp, $sp, 0x28
