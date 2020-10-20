.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241978_DBEC28
/* DBEC28 80241978 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DBEC2C 8024197C AFB3002C */  sw        $s3, 0x2c($sp)
/* DBEC30 80241980 0080982D */  daddu     $s3, $a0, $zero
/* DBEC34 80241984 AFBF0030 */  sw        $ra, 0x30($sp)
/* DBEC38 80241988 AFB20028 */  sw        $s2, 0x28($sp)
/* DBEC3C 8024198C AFB10024 */  sw        $s1, 0x24($sp)
/* DBEC40 80241990 AFB00020 */  sw        $s0, 0x20($sp)
/* DBEC44 80241994 8E710148 */  lw        $s1, 0x148($s3)
/* DBEC48 80241998 86240008 */  lh        $a0, 8($s1)
/* DBEC4C 8024199C 0C00EABB */  jal       get_npc_unsafe
/* DBEC50 802419A0 00A0902D */   daddu    $s2, $a1, $zero
/* DBEC54 802419A4 8E440004 */  lw        $a0, 4($s2)
/* DBEC58 802419A8 0040802D */  daddu     $s0, $v0, $zero
/* DBEC5C 802419AC 00041FC2 */  srl       $v1, $a0, 0x1f
/* DBEC60 802419B0 00832021 */  addu      $a0, $a0, $v1
/* DBEC64 802419B4 00042043 */  sra       $a0, $a0, 1
/* DBEC68 802419B8 0C00A67F */  jal       rand_int
/* DBEC6C 802419BC 24840001 */   addiu    $a0, $a0, 1
/* DBEC70 802419C0 8E430004 */  lw        $v1, 4($s2)
/* DBEC74 802419C4 000327C2 */  srl       $a0, $v1, 0x1f
/* DBEC78 802419C8 00641821 */  addu      $v1, $v1, $a0
/* DBEC7C 802419CC 00031843 */  sra       $v1, $v1, 1
/* DBEC80 802419D0 00621821 */  addu      $v1, $v1, $v0
/* DBEC84 802419D4 A603008E */  sh        $v1, 0x8e($s0)
/* DBEC88 802419D8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBEC8C 802419DC C6000040 */  lwc1      $f0, 0x40($s0)
/* DBEC90 802419E0 C4640000 */  lwc1      $f4, ($v1)
/* DBEC94 802419E4 46802120 */  cvt.s.w   $f4, $f4
/* DBEC98 802419E8 C4620008 */  lwc1      $f2, 8($v1)
/* DBEC9C 802419EC 468010A0 */  cvt.s.w   $f2, $f2
/* DBECA0 802419F0 E7A00010 */  swc1      $f0, 0x10($sp)
/* DBECA4 802419F4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBECA8 802419F8 44061000 */  mfc1      $a2, $f2
/* DBECAC 802419FC C440000C */  lwc1      $f0, 0xc($v0)
/* DBECB0 80241A00 46800020 */  cvt.s.w   $f0, $f0
/* DBECB4 80241A04 E7A00014 */  swc1      $f0, 0x14($sp)
/* DBECB8 80241A08 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBECBC 80241A0C 44052000 */  mfc1      $a1, $f4
/* DBECC0 80241A10 C4400010 */  lwc1      $f0, 0x10($v0)
/* DBECC4 80241A14 46800020 */  cvt.s.w   $f0, $f0
/* DBECC8 80241A18 E7A00018 */  swc1      $f0, 0x18($sp)
/* DBECCC 80241A1C 8C640018 */  lw        $a0, 0x18($v1)
/* DBECD0 80241A20 0C0123F5 */  jal       is_point_within_region
/* DBECD4 80241A24 8E070038 */   lw       $a3, 0x38($s0)
/* DBECD8 80241A28 1040000E */  beqz      $v0, .L80241A64
/* DBECDC 80241A2C 00000000 */   nop      
/* DBECE0 80241A30 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBECE4 80241A34 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DBECE8 80241A38 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DBECEC 80241A3C C4460000 */  lwc1      $f6, ($v0)
/* DBECF0 80241A40 468031A0 */  cvt.s.w   $f6, $f6
/* DBECF4 80241A44 44063000 */  mfc1      $a2, $f6
/* DBECF8 80241A48 C4460008 */  lwc1      $f6, 8($v0)
/* DBECFC 80241A4C 468031A0 */  cvt.s.w   $f6, $f6
/* DBED00 80241A50 44073000 */  mfc1      $a3, $f6
/* DBED04 80241A54 0C00A720 */  jal       atan2
/* DBED08 80241A58 00000000 */   nop      
/* DBED0C 80241A5C 080906A5 */  j         .L80241A94
/* DBED10 80241A60 E600000C */   swc1     $f0, 0xc($s0)
.L80241A64:
/* DBED14 80241A64 0C00A67F */  jal       rand_int
/* DBED18 80241A68 2404003C */   addiu    $a0, $zero, 0x3c
/* DBED1C 80241A6C C60C000C */  lwc1      $f12, 0xc($s0)
/* DBED20 80241A70 44820000 */  mtc1      $v0, $f0
/* DBED24 80241A74 00000000 */  nop       
/* DBED28 80241A78 46800020 */  cvt.s.w   $f0, $f0
/* DBED2C 80241A7C 46006300 */  add.s     $f12, $f12, $f0
/* DBED30 80241A80 3C0141F0 */  lui       $at, 0x41f0
/* DBED34 80241A84 44810000 */  mtc1      $at, $f0
/* DBED38 80241A88 0C00A6C9 */  jal       clamp_angle
/* DBED3C 80241A8C 46006301 */   sub.s    $f12, $f12, $f0
/* DBED40 80241A90 E600000C */  swc1      $f0, 0xc($s0)
.L80241A94:
/* DBED44 80241A94 8E2200CC */  lw        $v0, 0xcc($s1)
/* DBED48 80241A98 8C420004 */  lw        $v0, 4($v0)
/* DBED4C 80241A9C AE020028 */  sw        $v0, 0x28($s0)
/* DBED50 80241AA0 AE600074 */  sw        $zero, 0x74($s3)
/* DBED54 80241AA4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBED58 80241AA8 8C420014 */  lw        $v0, 0x14($v0)
/* DBED5C 80241AAC 04410004 */  bgez      $v0, .L80241AC0
/* DBED60 80241AB0 00000000 */   nop      
/* DBED64 80241AB4 C6400000 */  lwc1      $f0, ($s2)
/* DBED68 80241AB8 080906B8 */  j         .L80241AE0
/* DBED6C 80241ABC E6000018 */   swc1     $f0, 0x18($s0)
.L80241AC0:
/* DBED70 80241AC0 3C018024 */  lui       $at, 0x8024
/* DBED74 80241AC4 D42270B0 */  ldc1      $f2, 0x70b0($at)
/* DBED78 80241AC8 44820000 */  mtc1      $v0, $f0
/* DBED7C 80241ACC 00000000 */  nop       
/* DBED80 80241AD0 46800021 */  cvt.d.w   $f0, $f0
/* DBED84 80241AD4 46220003 */  div.d     $f0, $f0, $f2
/* DBED88 80241AD8 46200020 */  cvt.s.d   $f0, $f0
/* DBED8C 80241ADC E6000018 */  swc1      $f0, 0x18($s0)
.L80241AE0:
/* DBED90 80241AE0 C600003C */  lwc1      $f0, 0x3c($s0)
/* DBED94 80241AE4 3C014059 */  lui       $at, 0x4059
/* DBED98 80241AE8 44811800 */  mtc1      $at, $f3
/* DBED9C 80241AEC 44801000 */  mtc1      $zero, $f2
/* DBEDA0 80241AF0 46000021 */  cvt.d.s   $f0, $f0
/* DBEDA4 80241AF4 46220002 */  mul.d     $f0, $f0, $f2
/* DBEDA8 80241AF8 00000000 */  nop       
/* DBEDAC 80241AFC 24020001 */  addiu     $v0, $zero, 1
/* DBEDB0 80241B00 4620018D */  trunc.w.d $f6, $f0
/* DBEDB4 80241B04 E626007C */  swc1      $f6, 0x7c($s1)
/* DBEDB8 80241B08 AE620070 */  sw        $v0, 0x70($s3)
/* DBEDBC 80241B0C 8FBF0030 */  lw        $ra, 0x30($sp)
/* DBEDC0 80241B10 8FB3002C */  lw        $s3, 0x2c($sp)
/* DBEDC4 80241B14 8FB20028 */  lw        $s2, 0x28($sp)
/* DBEDC8 80241B18 8FB10024 */  lw        $s1, 0x24($sp)
/* DBEDCC 80241B1C 8FB00020 */  lw        $s0, 0x20($sp)
/* DBEDD0 80241B20 03E00008 */  jr        $ra
/* DBEDD4 80241B24 27BD0038 */   addiu    $sp, $sp, 0x38
