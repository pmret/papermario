.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241788_C87238
/* C87238 80241788 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C8723C 8024178C AFB10014 */  sw        $s1, 0x14($sp)
/* C87240 80241790 0080882D */  daddu     $s1, $a0, $zero
/* C87244 80241794 AFBF0018 */  sw        $ra, 0x18($sp)
/* C87248 80241798 AFB00010 */  sw        $s0, 0x10($sp)
/* C8724C 8024179C 8E300148 */  lw        $s0, 0x148($s1)
/* C87250 802417A0 0C00EABB */  jal       get_npc_unsafe
/* C87254 802417A4 86040008 */   lh       $a0, 8($s0)
/* C87258 802417A8 0040202D */  daddu     $a0, $v0, $zero
/* C8725C 802417AC 9482008E */  lhu       $v0, 0x8e($a0)
/* C87260 802417B0 2442FFFF */  addiu     $v0, $v0, -1
/* C87264 802417B4 A482008E */  sh        $v0, 0x8e($a0)
/* C87268 802417B8 00021400 */  sll       $v0, $v0, 0x10
/* C8726C 802417BC 8E030098 */  lw        $v1, 0x98($s0)
/* C87270 802417C0 00021403 */  sra       $v0, $v0, 0x10
/* C87274 802417C4 0062182A */  slt       $v1, $v1, $v0
/* C87278 802417C8 14600005 */  bnez      $v1, .L802417E0
/* C8727C 802417CC 3C03E0EF */   lui      $v1, 0xe0ef
/* C87280 802417D0 8E020000 */  lw        $v0, ($s0)
/* C87284 802417D4 3463FFFF */  ori       $v1, $v1, 0xffff
/* C87288 802417D8 00431024 */  and       $v0, $v0, $v1
/* C8728C 802417DC AE020000 */  sw        $v0, ($s0)
.L802417E0:
/* C87290 802417E0 8482008E */  lh        $v0, 0x8e($a0)
/* C87294 802417E4 14400007 */  bnez      $v0, .L80241804
/* C87298 802417E8 00000000 */   nop      
/* C8729C 802417EC 8E0200CC */  lw        $v0, 0xcc($s0)
/* C872A0 802417F0 8C420028 */  lw        $v0, 0x28($v0)
/* C872A4 802417F4 A480008E */  sh        $zero, 0x8e($a0)
/* C872A8 802417F8 AC820028 */  sw        $v0, 0x28($a0)
/* C872AC 802417FC 2402000C */  addiu     $v0, $zero, 0xc
/* C872B0 80241800 AE220070 */  sw        $v0, 0x70($s1)
.L80241804:
/* C872B4 80241804 8FBF0018 */  lw        $ra, 0x18($sp)
/* C872B8 80241808 8FB10014 */  lw        $s1, 0x14($sp)
/* C872BC 8024180C 8FB00010 */  lw        $s0, 0x10($sp)
/* C872C0 80241810 03E00008 */  jr        $ra
/* C872C4 80241814 27BD0020 */   addiu    $sp, $sp, 0x20
