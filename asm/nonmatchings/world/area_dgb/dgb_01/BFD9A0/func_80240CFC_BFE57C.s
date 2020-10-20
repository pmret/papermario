.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CFC_BFE57C
/* BFE57C 80240CFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BFE580 80240D00 AFB20018 */  sw        $s2, 0x18($sp)
/* BFE584 80240D04 0080902D */  daddu     $s2, $a0, $zero
/* BFE588 80240D08 AFBF001C */  sw        $ra, 0x1c($sp)
/* BFE58C 80240D0C AFB10014 */  sw        $s1, 0x14($sp)
/* BFE590 80240D10 AFB00010 */  sw        $s0, 0x10($sp)
/* BFE594 80240D14 8E510148 */  lw        $s1, 0x148($s2)
/* BFE598 80240D18 0C00EABB */  jal       get_npc_unsafe
/* BFE59C 80240D1C 86240008 */   lh       $a0, 8($s1)
/* BFE5A0 80240D20 0040802D */  daddu     $s0, $v0, $zero
/* BFE5A4 80240D24 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BFE5A8 80240D28 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BFE5AC 80240D2C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BFE5B0 80240D30 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BFE5B4 80240D34 A600008E */  sh        $zero, 0x8e($s0)
/* BFE5B8 80240D38 8C460028 */  lw        $a2, 0x28($v0)
/* BFE5BC 80240D3C 0C00A720 */  jal       atan2
/* BFE5C0 80240D40 8C470030 */   lw       $a3, 0x30($v0)
/* BFE5C4 80240D44 E600000C */  swc1      $f0, 0xc($s0)
/* BFE5C8 80240D48 8E2200CC */  lw        $v0, 0xcc($s1)
/* BFE5CC 80240D4C 8C420020 */  lw        $v0, 0x20($v0)
/* BFE5D0 80240D50 AE020028 */  sw        $v0, 0x28($s0)
/* BFE5D4 80240D54 2402000B */  addiu     $v0, $zero, 0xb
/* BFE5D8 80240D58 AE420070 */  sw        $v0, 0x70($s2)
/* BFE5DC 80240D5C 8FBF001C */  lw        $ra, 0x1c($sp)
/* BFE5E0 80240D60 8FB20018 */  lw        $s2, 0x18($sp)
/* BFE5E4 80240D64 8FB10014 */  lw        $s1, 0x14($sp)
/* BFE5E8 80240D68 8FB00010 */  lw        $s0, 0x10($sp)
/* BFE5EC 80240D6C 03E00008 */  jr        $ra
/* BFE5F0 80240D70 27BD0020 */   addiu    $sp, $sp, 0x20
