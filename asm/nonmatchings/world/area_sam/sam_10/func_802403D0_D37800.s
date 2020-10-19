.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403D0_D37BD0
/* D37BD0 802403D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D37BD4 802403D4 AFB10014 */  sw        $s1, 0x14($sp)
/* D37BD8 802403D8 0080882D */  daddu     $s1, $a0, $zero
/* D37BDC 802403DC AFBF0018 */  sw        $ra, 0x18($sp)
/* D37BE0 802403E0 AFB00010 */  sw        $s0, 0x10($sp)
/* D37BE4 802403E4 8E300148 */  lw        $s0, 0x148($s1)
/* D37BE8 802403E8 0C00EABB */  jal       get_npc_unsafe
/* D37BEC 802403EC 86040008 */   lh       $a0, 8($s0)
/* D37BF0 802403F0 24030001 */  addiu     $v1, $zero, 1
/* D37BF4 802403F4 0040202D */  daddu     $a0, $v0, $zero
/* D37BF8 802403F8 AE03006C */  sw        $v1, 0x6c($s0)
/* D37BFC 802403FC 8482008C */  lh        $v0, 0x8c($a0)
/* D37C00 80240400 14400009 */  bnez      $v0, .L80240428
/* D37C04 80240404 24020002 */   addiu    $v0, $zero, 2
/* D37C08 80240408 96030072 */  lhu       $v1, 0x72($s0)
/* D37C0C 8024040C AE02006C */  sw        $v0, 0x6c($s0)
/* D37C10 80240410 A483008E */  sh        $v1, 0x8e($a0)
/* D37C14 80240414 8E0200CC */  lw        $v0, 0xcc($s0)
/* D37C18 80240418 8C420020 */  lw        $v0, 0x20($v0)
/* D37C1C 8024041C AC820028 */  sw        $v0, 0x28($a0)
/* D37C20 80240420 2402001F */  addiu     $v0, $zero, 0x1f
/* D37C24 80240424 AE220070 */  sw        $v0, 0x70($s1)
.L80240428:
/* D37C28 80240428 8FBF0018 */  lw        $ra, 0x18($sp)
/* D37C2C 8024042C 8FB10014 */  lw        $s1, 0x14($sp)
/* D37C30 80240430 8FB00010 */  lw        $s0, 0x10($sp)
/* D37C34 80240434 03E00008 */  jr        $ra
/* D37C38 80240438 27BD0020 */   addiu    $sp, $sp, 0x20
