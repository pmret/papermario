.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80247878_DA4D48
.double 0.6

.section .text

glabel func_802409E0_D9DEB0
/* D9DEB0 802409E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D9DEB4 802409E4 AFB20028 */  sw        $s2, 0x28($sp)
/* D9DEB8 802409E8 0080902D */  daddu     $s2, $a0, $zero
/* D9DEBC 802409EC AFBF002C */  sw        $ra, 0x2c($sp)
/* D9DEC0 802409F0 AFB10024 */  sw        $s1, 0x24($sp)
/* D9DEC4 802409F4 AFB00020 */  sw        $s0, 0x20($sp)
/* D9DEC8 802409F8 8E510148 */  lw        $s1, 0x148($s2)
/* D9DECC 802409FC 0C00EABB */  jal       get_npc_unsafe
/* D9DED0 80240A00 86240008 */   lh       $a0, 8($s1)
/* D9DED4 80240A04 0040802D */  daddu     $s0, $v0, $zero
/* D9DED8 80240A08 0200202D */  daddu     $a0, $s0, $zero
/* D9DEDC 80240A0C C600000C */  lwc1      $f0, 0xc($s0)
/* D9DEE0 80240A10 27A60018 */  addiu     $a2, $sp, 0x18
/* D9DEE4 80240A14 E7A00018 */  swc1      $f0, 0x18($sp)
/* D9DEE8 80240A18 AFA00010 */  sw        $zero, 0x10($sp)
/* D9DEEC 80240A1C AFA00014 */  sw        $zero, 0x14($sp)
/* D9DEF0 80240A20 8E050018 */  lw        $a1, 0x18($s0)
/* D9DEF4 80240A24 0C0129E1 */  jal       func_8004A784
/* D9DEF8 80240A28 0000382D */   daddu    $a3, $zero, $zero
/* D9DEFC 80240A2C 14400005 */  bnez      $v0, .L80240A44
/* D9DF00 80240A30 00000000 */   nop
/* D9DF04 80240A34 8E050018 */  lw        $a1, 0x18($s0)
/* D9DF08 80240A38 8E06000C */  lw        $a2, 0xc($s0)
/* D9DF0C 80240A3C 0C00EA95 */  jal       npc_move_heading
/* D9DF10 80240A40 0200202D */   daddu    $a0, $s0, $zero
.L80240A44:
/* D9DF14 80240A44 9602008E */  lhu       $v0, 0x8e($s0)
/* D9DF18 80240A48 2442FFFF */  addiu     $v0, $v0, -1
/* D9DF1C 80240A4C A602008E */  sh        $v0, 0x8e($s0)
/* D9DF20 80240A50 00021400 */  sll       $v0, $v0, 0x10
/* D9DF24 80240A54 14400010 */  bnez      $v0, .L80240A98
/* D9DF28 80240A58 00000000 */   nop
/* D9DF2C 80240A5C C6000018 */  lwc1      $f0, 0x18($s0)
/* D9DF30 80240A60 3C018024 */  lui       $at, %hi(D_80247878_DA4D48)
/* D9DF34 80240A64 D4227878 */  ldc1      $f2, %lo(D_80247878_DA4D48)($at)
/* D9DF38 80240A68 46000021 */  cvt.d.s   $f0, $f0
/* D9DF3C 80240A6C 46220002 */  mul.d     $f0, $f0, $f2
/* D9DF40 80240A70 00000000 */  nop
/* D9DF44 80240A74 46200020 */  cvt.s.d   $f0, $f0
/* D9DF48 80240A78 E6000018 */  swc1      $f0, 0x18($s0)
/* D9DF4C 80240A7C 8E2200CC */  lw        $v0, 0xcc($s1)
/* D9DF50 80240A80 8C43002C */  lw        $v1, 0x2c($v0)
/* D9DF54 80240A84 2402000A */  addiu     $v0, $zero, 0xa
/* D9DF58 80240A88 A602008E */  sh        $v0, 0x8e($s0)
/* D9DF5C 80240A8C 24020010 */  addiu     $v0, $zero, 0x10
/* D9DF60 80240A90 AE030028 */  sw        $v1, 0x28($s0)
/* D9DF64 80240A94 AE420070 */  sw        $v0, 0x70($s2)
.L80240A98:
/* D9DF68 80240A98 8FBF002C */  lw        $ra, 0x2c($sp)
/* D9DF6C 80240A9C 8FB20028 */  lw        $s2, 0x28($sp)
/* D9DF70 80240AA0 8FB10024 */  lw        $s1, 0x24($sp)
/* D9DF74 80240AA4 8FB00020 */  lw        $s0, 0x20($sp)
/* D9DF78 80240AA8 03E00008 */  jr        $ra
/* D9DF7C 80240AAC 27BD0030 */   addiu    $sp, $sp, 0x30
