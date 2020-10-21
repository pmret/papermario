.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024124C_A61C1C
/* A61C1C 8024124C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A61C20 80241250 AFB20018 */  sw        $s2, 0x18($sp)
/* A61C24 80241254 0080902D */  daddu     $s2, $a0, $zero
/* A61C28 80241258 AFBF001C */  sw        $ra, 0x1c($sp)
/* A61C2C 8024125C AFB10014 */  sw        $s1, 0x14($sp)
/* A61C30 80241260 AFB00010 */  sw        $s0, 0x10($sp)
/* A61C34 80241264 8E510148 */  lw        $s1, 0x148($s2)
/* A61C38 80241268 0C00EABB */  jal       get_npc_unsafe
/* A61C3C 8024126C 86240008 */   lh       $a0, 8($s1)
/* A61C40 80241270 0040802D */  daddu     $s0, $v0, $zero
/* A61C44 80241274 8E2300CC */  lw        $v1, 0xcc($s1)
/* A61C48 80241278 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A61C4C 8024127C 8C630020 */  lw        $v1, 0x20($v1)
/* A61C50 80241280 AE030028 */  sw        $v1, 0x28($s0)
/* A61C54 80241284 96220076 */  lhu       $v0, 0x76($s1)
/* A61C58 80241288 A602008E */  sh        $v0, 0x8e($s0)
/* A61C5C 8024128C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A61C60 80241290 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A61C64 80241294 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A61C68 80241298 8C460028 */  lw        $a2, 0x28($v0)
/* A61C6C 8024129C 0C00A720 */  jal       atan2
/* A61C70 802412A0 8C470030 */   lw       $a3, 0x30($v0)
/* A61C74 802412A4 2402000D */  addiu     $v0, $zero, 0xd
/* A61C78 802412A8 E600000C */  swc1      $f0, 0xc($s0)
/* A61C7C 802412AC AE420070 */  sw        $v0, 0x70($s2)
/* A61C80 802412B0 8FBF001C */  lw        $ra, 0x1c($sp)
/* A61C84 802412B4 8FB20018 */  lw        $s2, 0x18($sp)
/* A61C88 802412B8 8FB10014 */  lw        $s1, 0x14($sp)
/* A61C8C 802412BC 8FB00010 */  lw        $s0, 0x10($sp)
/* A61C90 802412C0 03E00008 */  jr        $ra
/* A61C94 802412C4 27BD0020 */   addiu    $sp, $sp, 0x20
