.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DD0_B94210
/* B94210 80240DD0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B94214 80240DD4 AFB10014 */  sw        $s1, 0x14($sp)
/* B94218 80240DD8 0080882D */  daddu     $s1, $a0, $zero
/* B9421C 80240DDC AFBF0018 */  sw        $ra, 0x18($sp)
/* B94220 80240DE0 AFB00010 */  sw        $s0, 0x10($sp)
/* B94224 80240DE4 8E300148 */  lw        $s0, 0x148($s1)
/* B94228 80240DE8 0C00EABB */  jal       get_npc_unsafe
/* B9422C 80240DEC 86040008 */   lh       $a0, 8($s0)
/* B94230 80240DF0 0040202D */  daddu     $a0, $v0, $zero
/* B94234 80240DF4 8482008E */  lh        $v0, 0x8e($a0)
/* B94238 80240DF8 9483008E */  lhu       $v1, 0x8e($a0)
/* B9423C 80240DFC 18400003 */  blez      $v0, .L80240E0C
/* B94240 80240E00 2462FFFF */   addiu    $v0, $v1, -1
/* B94244 80240E04 0809038A */  j         .L80240E28
/* B94248 80240E08 A482008E */   sh       $v0, 0x8e($a0)
.L80240E0C:
/* B9424C 80240E0C 8E0200CC */  lw        $v0, 0xcc($s0)
/* B94250 80240E10 AE00006C */  sw        $zero, 0x6c($s0)
/* B94254 80240E14 8C420000 */  lw        $v0, ($v0)
/* B94258 80240E18 AC820028 */  sw        $v0, 0x28($a0)
/* B9425C 80240E1C 24020001 */  addiu     $v0, $zero, 1
/* B94260 80240E20 AE200074 */  sw        $zero, 0x74($s1)
/* B94264 80240E24 AE220070 */  sw        $v0, 0x70($s1)
.L80240E28:
/* B94268 80240E28 8FBF0018 */  lw        $ra, 0x18($sp)
/* B9426C 80240E2C 8FB10014 */  lw        $s1, 0x14($sp)
/* B94270 80240E30 8FB00010 */  lw        $s0, 0x10($sp)
/* B94274 80240E34 03E00008 */  jr        $ra
/* B94278 80240E38 27BD0020 */   addiu    $sp, $sp, 0x20
