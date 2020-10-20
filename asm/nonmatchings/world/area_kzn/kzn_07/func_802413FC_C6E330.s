.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413FC_C6F72C
/* C6F72C 802413FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C6F730 80241400 AFB20018 */  sw        $s2, 0x18($sp)
/* C6F734 80241404 0080902D */  daddu     $s2, $a0, $zero
/* C6F738 80241408 AFBF001C */  sw        $ra, 0x1c($sp)
/* C6F73C 8024140C AFB10014 */  sw        $s1, 0x14($sp)
/* C6F740 80241410 AFB00010 */  sw        $s0, 0x10($sp)
/* C6F744 80241414 8E510148 */  lw        $s1, 0x148($s2)
/* C6F748 80241418 0C00EABB */  jal       get_npc_unsafe
/* C6F74C 8024141C 86240008 */   lh       $a0, 8($s1)
/* C6F750 80241420 0040802D */  daddu     $s0, $v0, $zero
/* C6F754 80241424 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C6F758 80241428 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C6F75C 8024142C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C6F760 80241430 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C6F764 80241434 A600008E */  sh        $zero, 0x8e($s0)
/* C6F768 80241438 8C460028 */  lw        $a2, 0x28($v0)
/* C6F76C 8024143C 0C00A720 */  jal       atan2
/* C6F770 80241440 8C470030 */   lw       $a3, 0x30($v0)
/* C6F774 80241444 E600000C */  swc1      $f0, 0xc($s0)
/* C6F778 80241448 8E2200CC */  lw        $v0, 0xcc($s1)
/* C6F77C 8024144C 8C420020 */  lw        $v0, 0x20($v0)
/* C6F780 80241450 AE020028 */  sw        $v0, 0x28($s0)
/* C6F784 80241454 2402000B */  addiu     $v0, $zero, 0xb
/* C6F788 80241458 AE420070 */  sw        $v0, 0x70($s2)
/* C6F78C 8024145C 8FBF001C */  lw        $ra, 0x1c($sp)
/* C6F790 80241460 8FB20018 */  lw        $s2, 0x18($sp)
/* C6F794 80241464 8FB10014 */  lw        $s1, 0x14($sp)
/* C6F798 80241468 8FB00010 */  lw        $s0, 0x10($sp)
/* C6F79C 8024146C 03E00008 */  jr        $ra
/* C6F7A0 80241470 27BD0020 */   addiu    $sp, $sp, 0x20
