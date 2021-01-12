.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC0F0_E2EA20
/* E2EA20 802BC0F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2EA24 802BC0F4 AFB10014 */  sw        $s1, 0x14($sp)
/* E2EA28 802BC0F8 0080882D */  daddu     $s1, $a0, $zero
/* E2EA2C 802BC0FC AFB00010 */  sw        $s0, 0x10($sp)
/* E2EA30 802BC100 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E2EA34 802BC104 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E2EA38 802BC108 AFBF001C */  sw        $ra, 0x1c($sp)
/* E2EA3C 802BC10C AFB20018 */  sw        $s2, 0x18($sp)
/* E2EA40 802BC110 C62C0048 */  lwc1      $f12, 0x48($s1)
/* E2EA44 802BC114 C62E0050 */  lwc1      $f14, 0x50($s1)
/* E2EA48 802BC118 8E060028 */  lw        $a2, 0x28($s0)
/* E2EA4C 802BC11C 8E070030 */  lw        $a3, 0x30($s0)
/* E2EA50 802BC120 0C00A7B5 */  jal       dist2D
/* E2EA54 802BC124 8E320040 */   lw       $s2, 0x40($s1)
/* E2EA58 802BC128 3C013FD0 */  lui       $at, 0x3fd0
/* E2EA5C 802BC12C 44811800 */  mtc1      $at, $f3
/* E2EA60 802BC130 44801000 */  mtc1      $zero, $f2
/* E2EA64 802BC134 46000021 */  cvt.d.s   $f0, $f0
/* E2EA68 802BC138 46220002 */  mul.d     $f0, $f0, $f2
/* E2EA6C 802BC13C 00000000 */  nop       
/* E2EA70 802BC140 46200005 */  abs.d     $f0, $f0
/* E2EA74 802BC144 46200020 */  cvt.s.d   $f0, $f0
/* E2EA78 802BC148 E6400018 */  swc1      $f0, 0x18($s2)
/* E2EA7C 802BC14C C60C0028 */  lwc1      $f12, 0x28($s0)
/* E2EA80 802BC150 C60E0030 */  lwc1      $f14, 0x30($s0)
/* E2EA84 802BC154 8E260048 */  lw        $a2, 0x48($s1)
/* E2EA88 802BC158 0C00A720 */  jal       atan2
/* E2EA8C 802BC15C 8E270050 */   lw       $a3, 0x50($s1)
/* E2EA90 802BC160 E6400014 */  swc1      $f0, 0x14($s2)
/* E2EA94 802BC164 8FBF001C */  lw        $ra, 0x1c($sp)
/* E2EA98 802BC168 8FB20018 */  lw        $s2, 0x18($sp)
/* E2EA9C 802BC16C 8FB10014 */  lw        $s1, 0x14($sp)
/* E2EAA0 802BC170 8FB00010 */  lw        $s0, 0x10($sp)
/* E2EAA4 802BC174 03E00008 */  jr        $ra
/* E2EAA8 802BC178 27BD0020 */   addiu    $sp, $sp, 0x20
