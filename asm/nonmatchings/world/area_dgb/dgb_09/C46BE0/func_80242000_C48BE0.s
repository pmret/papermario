.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242000_C48BE0
/* C48BE0 80242000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C48BE4 80242004 AFB20018 */  sw        $s2, 0x18($sp)
/* C48BE8 80242008 0080902D */  daddu     $s2, $a0, $zero
/* C48BEC 8024200C AFBF001C */  sw        $ra, 0x1c($sp)
/* C48BF0 80242010 AFB10014 */  sw        $s1, 0x14($sp)
/* C48BF4 80242014 AFB00010 */  sw        $s0, 0x10($sp)
/* C48BF8 80242018 8E510148 */  lw        $s1, 0x148($s2)
/* C48BFC 8024201C 0C00EABB */  jal       get_npc_unsafe
/* C48C00 80242020 86240008 */   lh       $a0, 8($s1)
/* C48C04 80242024 0040802D */  daddu     $s0, $v0, $zero
/* C48C08 80242028 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C48C0C 8024202C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C48C10 80242030 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C48C14 80242034 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C48C18 80242038 A600008E */  sh        $zero, 0x8e($s0)
/* C48C1C 8024203C 8C460028 */  lw        $a2, 0x28($v0)
/* C48C20 80242040 0C00A720 */  jal       atan2
/* C48C24 80242044 8C470030 */   lw       $a3, 0x30($v0)
/* C48C28 80242048 E600000C */  swc1      $f0, 0xc($s0)
/* C48C2C 8024204C 8E2200CC */  lw        $v0, 0xcc($s1)
/* C48C30 80242050 8C420020 */  lw        $v0, 0x20($v0)
/* C48C34 80242054 AE020028 */  sw        $v0, 0x28($s0)
/* C48C38 80242058 2402000B */  addiu     $v0, $zero, 0xb
/* C48C3C 8024205C AE420070 */  sw        $v0, 0x70($s2)
/* C48C40 80242060 8FBF001C */  lw        $ra, 0x1c($sp)
/* C48C44 80242064 8FB20018 */  lw        $s2, 0x18($sp)
/* C48C48 80242068 8FB10014 */  lw        $s1, 0x14($sp)
/* C48C4C 8024206C 8FB00010 */  lw        $s0, 0x10($sp)
/* C48C50 80242070 03E00008 */  jr        $ra
/* C48C54 80242074 27BD0020 */   addiu    $sp, $sp, 0x20
