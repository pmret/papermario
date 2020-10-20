.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413B0
/* 9F5DF0 802413B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9F5DF4 802413B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 9F5DF8 802413B8 0080902D */  daddu     $s2, $a0, $zero
/* 9F5DFC 802413BC AFBF001C */  sw        $ra, 0x1c($sp)
/* 9F5E00 802413C0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9F5E04 802413C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9F5E08 802413C8 8E510148 */  lw        $s1, 0x148($s2)
/* 9F5E0C 802413CC 0C00EABB */  jal       get_npc_unsafe
/* 9F5E10 802413D0 86240008 */   lh       $a0, 8($s1)
/* 9F5E14 802413D4 0040802D */  daddu     $s0, $v0, $zero
/* 9F5E18 802413D8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9F5E1C 802413DC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9F5E20 802413E0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9F5E24 802413E4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9F5E28 802413E8 A600008E */  sh        $zero, 0x8e($s0)
/* 9F5E2C 802413EC 8C460028 */  lw        $a2, 0x28($v0)
/* 9F5E30 802413F0 0C00A720 */  jal       atan2
/* 9F5E34 802413F4 8C470030 */   lw       $a3, 0x30($v0)
/* 9F5E38 802413F8 E600000C */  swc1      $f0, 0xc($s0)
/* 9F5E3C 802413FC 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9F5E40 80241400 8C420020 */  lw        $v0, 0x20($v0)
/* 9F5E44 80241404 AE020028 */  sw        $v0, 0x28($s0)
/* 9F5E48 80241408 2402000B */  addiu     $v0, $zero, 0xb
/* 9F5E4C 8024140C AE420070 */  sw        $v0, 0x70($s2)
/* 9F5E50 80241410 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9F5E54 80241414 8FB20018 */  lw        $s2, 0x18($sp)
/* 9F5E58 80241418 8FB10014 */  lw        $s1, 0x14($sp)
/* 9F5E5C 8024141C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9F5E60 80241420 03E00008 */  jr        $ra
/* 9F5E64 80241424 27BD0020 */   addiu    $sp, $sp, 0x20
