.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240568_97E038
/* 97E038 80240568 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 97E03C 8024056C AFB3001C */  sw        $s3, 0x1c($sp)
/* 97E040 80240570 0080982D */  daddu     $s3, $a0, $zero
/* 97E044 80240574 AFBF0020 */  sw        $ra, 0x20($sp)
/* 97E048 80240578 AFB20018 */  sw        $s2, 0x18($sp)
/* 97E04C 8024057C AFB10014 */  sw        $s1, 0x14($sp)
/* 97E050 80240580 AFB00010 */  sw        $s0, 0x10($sp)
/* 97E054 80240584 8E720148 */  lw        $s2, 0x148($s3)
/* 97E058 80240588 86440008 */  lh        $a0, 8($s2)
/* 97E05C 8024058C 0C00EABB */  jal       get_npc_unsafe
/* 97E060 80240590 00A0882D */   daddu    $s1, $a1, $zero
/* 97E064 80240594 8E240008 */  lw        $a0, 8($s1)
/* 97E068 80240598 0040802D */  daddu     $s0, $v0, $zero
/* 97E06C 8024059C 00041FC2 */  srl       $v1, $a0, 0x1f
/* 97E070 802405A0 00832021 */  addu      $a0, $a0, $v1
/* 97E074 802405A4 00042043 */  sra       $a0, $a0, 1
/* 97E078 802405A8 0C00A67F */  jal       rand_int
/* 97E07C 802405AC 24840001 */   addiu    $a0, $a0, 1
/* 97E080 802405B0 8E230008 */  lw        $v1, 8($s1)
/* 97E084 802405B4 240400B4 */  addiu     $a0, $zero, 0xb4
/* 97E088 802405B8 00032FC2 */  srl       $a1, $v1, 0x1f
/* 97E08C 802405BC 00651821 */  addu      $v1, $v1, $a1
/* 97E090 802405C0 00031843 */  sra       $v1, $v1, 1
/* 97E094 802405C4 00621821 */  addu      $v1, $v1, $v0
/* 97E098 802405C8 0C00A67F */  jal       rand_int
/* 97E09C 802405CC A603008E */   sh       $v1, 0x8e($s0)
/* 97E0A0 802405D0 C60C000C */  lwc1      $f12, 0xc($s0)
/* 97E0A4 802405D4 44820000 */  mtc1      $v0, $f0
/* 97E0A8 802405D8 00000000 */  nop       
/* 97E0AC 802405DC 46800020 */  cvt.s.w   $f0, $f0
/* 97E0B0 802405E0 46006300 */  add.s     $f12, $f12, $f0
/* 97E0B4 802405E4 3C0142B4 */  lui       $at, 0x42b4
/* 97E0B8 802405E8 44810000 */  mtc1      $at, $f0
/* 97E0BC 802405EC 0C00A6C9 */  jal       clamp_angle
/* 97E0C0 802405F0 46006301 */   sub.s    $f12, $f12, $f0
/* 97E0C4 802405F4 E600000C */  swc1      $f0, 0xc($s0)
/* 97E0C8 802405F8 8E4200CC */  lw        $v0, 0xcc($s2)
/* 97E0CC 802405FC 8C420000 */  lw        $v0, ($v0)
/* 97E0D0 80240600 AE020028 */  sw        $v0, 0x28($s0)
/* 97E0D4 80240604 24020003 */  addiu     $v0, $zero, 3
/* 97E0D8 80240608 AE620070 */  sw        $v0, 0x70($s3)
/* 97E0DC 8024060C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 97E0E0 80240610 8FB3001C */  lw        $s3, 0x1c($sp)
/* 97E0E4 80240614 8FB20018 */  lw        $s2, 0x18($sp)
/* 97E0E8 80240618 8FB10014 */  lw        $s1, 0x14($sp)
/* 97E0EC 8024061C 8FB00010 */  lw        $s0, 0x10($sp)
/* 97E0F0 80240620 03E00008 */  jr        $ra
/* 97E0F4 80240624 27BD0028 */   addiu    $sp, $sp, 0x28
