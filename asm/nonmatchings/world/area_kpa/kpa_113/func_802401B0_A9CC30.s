.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401B0_A9CDE0
/* A9CDE0 802401B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A9CDE4 802401B4 AFB20018 */  sw        $s2, 0x18($sp)
/* A9CDE8 802401B8 0080902D */  daddu     $s2, $a0, $zero
/* A9CDEC 802401BC AFBF001C */  sw        $ra, 0x1c($sp)
/* A9CDF0 802401C0 AFB10014 */  sw        $s1, 0x14($sp)
/* A9CDF4 802401C4 AFB00010 */  sw        $s0, 0x10($sp)
/* A9CDF8 802401C8 8E510148 */  lw        $s1, 0x148($s2)
/* A9CDFC 802401CC 0C00EABB */  jal       get_npc_unsafe
/* A9CE00 802401D0 86240008 */   lh       $a0, 8($s1)
/* A9CE04 802401D4 0040802D */  daddu     $s0, $v0, $zero
/* A9CE08 802401D8 8E2300CC */  lw        $v1, 0xcc($s1)
/* A9CE0C 802401DC C60C0038 */  lwc1      $f12, 0x38($s0)
/* A9CE10 802401E0 8C630020 */  lw        $v1, 0x20($v1)
/* A9CE14 802401E4 AE030028 */  sw        $v1, 0x28($s0)
/* A9CE18 802401E8 96220076 */  lhu       $v0, 0x76($s1)
/* A9CE1C 802401EC A602008E */  sh        $v0, 0x8e($s0)
/* A9CE20 802401F0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A9CE24 802401F4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A9CE28 802401F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A9CE2C 802401FC 8C460028 */  lw        $a2, 0x28($v0)
/* A9CE30 80240200 0C00A720 */  jal       atan2
/* A9CE34 80240204 8C470030 */   lw       $a3, 0x30($v0)
/* A9CE38 80240208 2402000D */  addiu     $v0, $zero, 0xd
/* A9CE3C 8024020C E600000C */  swc1      $f0, 0xc($s0)
/* A9CE40 80240210 AE420070 */  sw        $v0, 0x70($s2)
/* A9CE44 80240214 8FBF001C */  lw        $ra, 0x1c($sp)
/* A9CE48 80240218 8FB20018 */  lw        $s2, 0x18($sp)
/* A9CE4C 8024021C 8FB10014 */  lw        $s1, 0x14($sp)
/* A9CE50 80240220 8FB00010 */  lw        $s0, 0x10($sp)
/* A9CE54 80240224 03E00008 */  jr        $ra
/* A9CE58 80240228 27BD0020 */   addiu    $sp, $sp, 0x20
