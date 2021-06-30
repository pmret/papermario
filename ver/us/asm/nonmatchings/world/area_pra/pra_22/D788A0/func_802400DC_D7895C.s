.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400DC_D7895C
/* D7895C 802400DC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D78960 802400E0 AFB10034 */  sw        $s1, 0x34($sp)
/* D78964 802400E4 0080882D */  daddu     $s1, $a0, $zero
/* D78968 802400E8 AFB00030 */  sw        $s0, 0x30($sp)
/* D7896C 802400EC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D78970 802400F0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D78974 802400F4 AFBF0038 */  sw        $ra, 0x38($sp)
/* D78978 802400F8 C6200084 */  lwc1      $f0, 0x84($s1)
/* D7897C 802400FC 46800020 */  cvt.s.w   $f0, $f0
/* D78980 80240100 27A2002C */  addiu     $v0, $sp, 0x2c
/* D78984 80240104 0000202D */  daddu     $a0, $zero, $zero
/* D78988 80240108 27A50020 */  addiu     $a1, $sp, 0x20
/* D7898C 8024010C 27A60024 */  addiu     $a2, $sp, 0x24
/* D78990 80240110 E6000028 */  swc1      $f0, 0x28($s0)
/* D78994 80240114 E7A00020 */  swc1      $f0, 0x20($sp)
/* D78998 80240118 C600002C */  lwc1      $f0, 0x2c($s0)
/* D7899C 8024011C 3C014120 */  lui       $at, 0x4120
/* D789A0 80240120 44811000 */  mtc1      $at, $f2
/* D789A4 80240124 C6040030 */  lwc1      $f4, 0x30($s0)
/* D789A8 80240128 3C014396 */  lui       $at, 0x4396
/* D789AC 8024012C 44813000 */  mtc1      $at, $f6
/* D789B0 80240130 46020000 */  add.s     $f0, $f0, $f2
/* D789B4 80240134 E7A40028 */  swc1      $f4, 0x28($sp)
/* D789B8 80240138 E7A6002C */  swc1      $f6, 0x2c($sp)
/* D789BC 8024013C E7A00024 */  swc1      $f0, 0x24($sp)
/* D789C0 80240140 3C014387 */  lui       $at, 0x4387
/* D789C4 80240144 44810000 */  mtc1      $at, $f0
/* D789C8 80240148 860300B2 */  lh        $v1, 0xb2($s0)
/* D789CC 8024014C 27A70028 */  addiu     $a3, $sp, 0x28
/* D789D0 80240150 AFA20010 */  sw        $v0, 0x10($sp)
/* D789D4 80240154 E7A00014 */  swc1      $f0, 0x14($sp)
/* D789D8 80240158 44830000 */  mtc1      $v1, $f0
/* D789DC 8024015C 00000000 */  nop
/* D789E0 80240160 46800020 */  cvt.s.w   $f0, $f0
/* D789E4 80240164 0C0371DE */  jal       npc_raycast_down_ahead
/* D789E8 80240168 E7A00018 */   swc1     $f0, 0x18($sp)
/* D789EC 8024016C C7A00020 */  lwc1      $f0, 0x20($sp)
/* D789F0 80240170 C7A20028 */  lwc1      $f2, 0x28($sp)
/* D789F4 80240174 E6000028 */  swc1      $f0, 0x28($s0)
/* D789F8 80240178 E6020030 */  swc1      $f2, 0x30($s0)
/* D789FC 8024017C AE2000AC */  sw        $zero, 0xac($s1)
/* D78A00 80240180 C602002C */  lwc1      $f2, 0x2c($s0)
/* D78A04 80240184 C7A00024 */  lwc1      $f0, 0x24($sp)
/* D78A08 80240188 46001032 */  c.eq.s    $f2, $f0
/* D78A0C 8024018C 00000000 */  nop
/* D78A10 80240190 45010009 */  bc1t      .L802401B8
/* D78A14 80240194 00000000 */   nop
/* D78A18 80240198 AE00002C */  sw        $zero, 0x2c($s0)
/* D78A1C 8024019C 8E220090 */  lw        $v0, 0x90($s1)
/* D78A20 802401A0 24420001 */  addiu     $v0, $v0, 1
/* D78A24 802401A4 AE220090 */  sw        $v0, 0x90($s1)
/* D78A28 802401A8 2842001E */  slti      $v0, $v0, 0x1e
/* D78A2C 802401AC 14400002 */  bnez      $v0, .L802401B8
/* D78A30 802401B0 24020001 */   addiu    $v0, $zero, 1
/* D78A34 802401B4 AE2200AC */  sw        $v0, 0xac($s1)
.L802401B8:
/* D78A38 802401B8 8FBF0038 */  lw        $ra, 0x38($sp)
/* D78A3C 802401BC 8FB10034 */  lw        $s1, 0x34($sp)
/* D78A40 802401C0 8FB00030 */  lw        $s0, 0x30($sp)
/* D78A44 802401C4 24020002 */  addiu     $v0, $zero, 2
/* D78A48 802401C8 03E00008 */  jr        $ra
/* D78A4C 802401CC 27BD0040 */   addiu    $sp, $sp, 0x40
