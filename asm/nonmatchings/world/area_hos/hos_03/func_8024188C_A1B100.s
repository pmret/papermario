.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024188C_A1C98C
/* A1C98C 8024188C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1C990 80241890 AFB20018 */  sw        $s2, 0x18($sp)
/* A1C994 80241894 0080902D */  daddu     $s2, $a0, $zero
/* A1C998 80241898 AFBF001C */  sw        $ra, 0x1c($sp)
/* A1C99C 8024189C AFB10014 */  sw        $s1, 0x14($sp)
/* A1C9A0 802418A0 AFB00010 */  sw        $s0, 0x10($sp)
/* A1C9A4 802418A4 8E510148 */  lw        $s1, 0x148($s2)
/* A1C9A8 802418A8 0C00EABB */  jal       get_npc_unsafe
/* A1C9AC 802418AC 86240008 */   lh       $a0, 8($s1)
/* A1C9B0 802418B0 0040802D */  daddu     $s0, $v0, $zero
/* A1C9B4 802418B4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A1C9B8 802418B8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A1C9BC 802418BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* A1C9C0 802418C0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A1C9C4 802418C4 A600008E */  sh        $zero, 0x8e($s0)
/* A1C9C8 802418C8 8C460028 */  lw        $a2, 0x28($v0)
/* A1C9CC 802418CC 0C00A720 */  jal       atan2
/* A1C9D0 802418D0 8C470030 */   lw       $a3, 0x30($v0)
/* A1C9D4 802418D4 E600000C */  swc1      $f0, 0xc($s0)
/* A1C9D8 802418D8 8E2200CC */  lw        $v0, 0xcc($s1)
/* A1C9DC 802418DC 8C420020 */  lw        $v0, 0x20($v0)
/* A1C9E0 802418E0 AE020028 */  sw        $v0, 0x28($s0)
/* A1C9E4 802418E4 2402000B */  addiu     $v0, $zero, 0xb
/* A1C9E8 802418E8 AE420070 */  sw        $v0, 0x70($s2)
/* A1C9EC 802418EC 8FBF001C */  lw        $ra, 0x1c($sp)
/* A1C9F0 802418F0 8FB20018 */  lw        $s2, 0x18($sp)
/* A1C9F4 802418F4 8FB10014 */  lw        $s1, 0x14($sp)
/* A1C9F8 802418F8 8FB00010 */  lw        $s0, 0x10($sp)
/* A1C9FC 802418FC 03E00008 */  jr        $ra
/* A1CA00 80241900 27BD0020 */   addiu    $sp, $sp, 0x20
