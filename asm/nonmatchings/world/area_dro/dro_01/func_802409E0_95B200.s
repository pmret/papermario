.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409E0_95BBE0
/* 95BBE0 802409E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 95BBE4 802409E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 95BBE8 802409E8 0080982D */  daddu     $s3, $a0, $zero
/* 95BBEC 802409EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 95BBF0 802409F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 95BBF4 802409F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 95BBF8 802409F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 95BBFC 802409FC 8E720148 */  lw        $s2, 0x148($s3)
/* 95BC00 80240A00 86440008 */  lh        $a0, 8($s2)
/* 95BC04 80240A04 0C00EABB */  jal       get_npc_unsafe
/* 95BC08 80240A08 00A0882D */   daddu    $s1, $a1, $zero
/* 95BC0C 80240A0C 8E240008 */  lw        $a0, 8($s1)
/* 95BC10 80240A10 0040802D */  daddu     $s0, $v0, $zero
/* 95BC14 80240A14 00041FC2 */  srl       $v1, $a0, 0x1f
/* 95BC18 80240A18 00832021 */  addu      $a0, $a0, $v1
/* 95BC1C 80240A1C 00042043 */  sra       $a0, $a0, 1
/* 95BC20 80240A20 0C00A67F */  jal       rand_int
/* 95BC24 80240A24 24840001 */   addiu    $a0, $a0, 1
/* 95BC28 80240A28 8E230008 */  lw        $v1, 8($s1)
/* 95BC2C 80240A2C 240400B4 */  addiu     $a0, $zero, 0xb4
/* 95BC30 80240A30 00032FC2 */  srl       $a1, $v1, 0x1f
/* 95BC34 80240A34 00651821 */  addu      $v1, $v1, $a1
/* 95BC38 80240A38 00031843 */  sra       $v1, $v1, 1
/* 95BC3C 80240A3C 00621821 */  addu      $v1, $v1, $v0
/* 95BC40 80240A40 0C00A67F */  jal       rand_int
/* 95BC44 80240A44 A603008E */   sh       $v1, 0x8e($s0)
/* 95BC48 80240A48 C60C000C */  lwc1      $f12, 0xc($s0)
/* 95BC4C 80240A4C 44820000 */  mtc1      $v0, $f0
/* 95BC50 80240A50 00000000 */  nop       
/* 95BC54 80240A54 46800020 */  cvt.s.w   $f0, $f0
/* 95BC58 80240A58 46006300 */  add.s     $f12, $f12, $f0
/* 95BC5C 80240A5C 3C0142B4 */  lui       $at, 0x42b4
/* 95BC60 80240A60 44810000 */  mtc1      $at, $f0
/* 95BC64 80240A64 0C00A6C9 */  jal       clamp_angle
/* 95BC68 80240A68 46006301 */   sub.s    $f12, $f12, $f0
/* 95BC6C 80240A6C E600000C */  swc1      $f0, 0xc($s0)
/* 95BC70 80240A70 8E4200CC */  lw        $v0, 0xcc($s2)
/* 95BC74 80240A74 8C420000 */  lw        $v0, ($v0)
/* 95BC78 80240A78 AE020028 */  sw        $v0, 0x28($s0)
/* 95BC7C 80240A7C 24020003 */  addiu     $v0, $zero, 3
/* 95BC80 80240A80 AE620070 */  sw        $v0, 0x70($s3)
/* 95BC84 80240A84 8FBF0020 */  lw        $ra, 0x20($sp)
/* 95BC88 80240A88 8FB3001C */  lw        $s3, 0x1c($sp)
/* 95BC8C 80240A8C 8FB20018 */  lw        $s2, 0x18($sp)
/* 95BC90 80240A90 8FB10014 */  lw        $s1, 0x14($sp)
/* 95BC94 80240A94 8FB00010 */  lw        $s0, 0x10($sp)
/* 95BC98 80240A98 03E00008 */  jr        $ra
/* 95BC9C 80240A9C 27BD0028 */   addiu    $sp, $sp, 0x28
