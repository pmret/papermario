.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401C0_A02A00
/* A02A00 802401C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A02A04 802401C4 AFB20018 */  sw        $s2, 0x18($sp)
/* A02A08 802401C8 0080902D */  daddu     $s2, $a0, $zero
/* A02A0C 802401CC AFBF001C */  sw        $ra, 0x1c($sp)
/* A02A10 802401D0 AFB10014 */  sw        $s1, 0x14($sp)
/* A02A14 802401D4 AFB00010 */  sw        $s0, 0x10($sp)
/* A02A18 802401D8 8E510148 */  lw        $s1, 0x148($s2)
/* A02A1C 802401DC 0C00EABB */  jal       get_npc_unsafe
/* A02A20 802401E0 86240008 */   lh       $a0, 8($s1)
/* A02A24 802401E4 0040802D */  daddu     $s0, $v0, $zero
/* A02A28 802401E8 8E2300CC */  lw        $v1, 0xcc($s1)
/* A02A2C 802401EC C60C0038 */  lwc1      $f12, 0x38($s0)
/* A02A30 802401F0 8C630020 */  lw        $v1, 0x20($v1)
/* A02A34 802401F4 AE030028 */  sw        $v1, 0x28($s0)
/* A02A38 802401F8 96220076 */  lhu       $v0, 0x76($s1)
/* A02A3C 802401FC A602008E */  sh        $v0, 0x8e($s0)
/* A02A40 80240200 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A02A44 80240204 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A02A48 80240208 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A02A4C 8024020C 8C460028 */  lw        $a2, 0x28($v0)
/* A02A50 80240210 0C00A720 */  jal       atan2
/* A02A54 80240214 8C470030 */   lw       $a3, 0x30($v0)
/* A02A58 80240218 2402000D */  addiu     $v0, $zero, 0xd
/* A02A5C 8024021C E600000C */  swc1      $f0, 0xc($s0)
/* A02A60 80240220 AE420070 */  sw        $v0, 0x70($s2)
/* A02A64 80240224 8FBF001C */  lw        $ra, 0x1c($sp)
/* A02A68 80240228 8FB20018 */  lw        $s2, 0x18($sp)
/* A02A6C 8024022C 8FB10014 */  lw        $s1, 0x14($sp)
/* A02A70 80240230 8FB00010 */  lw        $s0, 0x10($sp)
/* A02A74 80240234 03E00008 */  jr        $ra
/* A02A78 80240238 27BD0020 */   addiu    $sp, $sp, 0x20
