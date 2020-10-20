.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B90_DF0A30
/* DF0A30 80241B90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DF0A34 80241B94 AFB20018 */  sw        $s2, 0x18($sp)
/* DF0A38 80241B98 0080902D */  daddu     $s2, $a0, $zero
/* DF0A3C 80241B9C AFBF001C */  sw        $ra, 0x1c($sp)
/* DF0A40 80241BA0 AFB10014 */  sw        $s1, 0x14($sp)
/* DF0A44 80241BA4 AFB00010 */  sw        $s0, 0x10($sp)
/* DF0A48 80241BA8 8E510148 */  lw        $s1, 0x148($s2)
/* DF0A4C 80241BAC 0C00EABB */  jal       get_npc_unsafe
/* DF0A50 80241BB0 86240008 */   lh       $a0, 8($s1)
/* DF0A54 80241BB4 0040802D */  daddu     $s0, $v0, $zero
/* DF0A58 80241BB8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DF0A5C 80241BBC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DF0A60 80241BC0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DF0A64 80241BC4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DF0A68 80241BC8 A600008E */  sh        $zero, 0x8e($s0)
/* DF0A6C 80241BCC 8C460028 */  lw        $a2, 0x28($v0)
/* DF0A70 80241BD0 0C00A720 */  jal       atan2
/* DF0A74 80241BD4 8C470030 */   lw       $a3, 0x30($v0)
/* DF0A78 80241BD8 E600000C */  swc1      $f0, 0xc($s0)
/* DF0A7C 80241BDC 8E2200CC */  lw        $v0, 0xcc($s1)
/* DF0A80 80241BE0 8C420020 */  lw        $v0, 0x20($v0)
/* DF0A84 80241BE4 AE020028 */  sw        $v0, 0x28($s0)
/* DF0A88 80241BE8 2402000B */  addiu     $v0, $zero, 0xb
/* DF0A8C 80241BEC AE420070 */  sw        $v0, 0x70($s2)
/* DF0A90 80241BF0 8FBF001C */  lw        $ra, 0x1c($sp)
/* DF0A94 80241BF4 8FB20018 */  lw        $s2, 0x18($sp)
/* DF0A98 80241BF8 8FB10014 */  lw        $s1, 0x14($sp)
/* DF0A9C 80241BFC 8FB00010 */  lw        $s0, 0x10($sp)
/* DF0AA0 80241C00 03E00008 */  jr        $ra
/* DF0AA4 80241C04 27BD0020 */   addiu    $sp, $sp, 0x20
