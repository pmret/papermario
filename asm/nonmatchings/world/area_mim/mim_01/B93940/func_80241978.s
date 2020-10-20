.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241978
/* B94DB8 80241978 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B94DBC 8024197C AFB10014 */  sw        $s1, 0x14($sp)
/* B94DC0 80241980 0080882D */  daddu     $s1, $a0, $zero
/* B94DC4 80241984 AFBF0018 */  sw        $ra, 0x18($sp)
/* B94DC8 80241988 AFB00010 */  sw        $s0, 0x10($sp)
/* B94DCC 8024198C 8E300148 */  lw        $s0, 0x148($s1)
/* B94DD0 80241990 0C00EABB */  jal       get_npc_unsafe
/* B94DD4 80241994 86040008 */   lh       $a0, 8($s0)
/* B94DD8 80241998 0040202D */  daddu     $a0, $v0, $zero
/* B94DDC 8024199C 9482008E */  lhu       $v0, 0x8e($a0)
/* B94DE0 802419A0 2442FFFF */  addiu     $v0, $v0, -1
/* B94DE4 802419A4 A482008E */  sh        $v0, 0x8e($a0)
/* B94DE8 802419A8 00021400 */  sll       $v0, $v0, 0x10
/* B94DEC 802419AC 8E030098 */  lw        $v1, 0x98($s0)
/* B94DF0 802419B0 00021403 */  sra       $v0, $v0, 0x10
/* B94DF4 802419B4 0062182A */  slt       $v1, $v1, $v0
/* B94DF8 802419B8 14600005 */  bnez      $v1, .L802419D0
/* B94DFC 802419BC 3C03E0EF */   lui      $v1, 0xe0ef
/* B94E00 802419C0 8E020000 */  lw        $v0, ($s0)
/* B94E04 802419C4 3463FFFF */  ori       $v1, $v1, 0xffff
/* B94E08 802419C8 00431024 */  and       $v0, $v0, $v1
/* B94E0C 802419CC AE020000 */  sw        $v0, ($s0)
.L802419D0:
/* B94E10 802419D0 8482008E */  lh        $v0, 0x8e($a0)
/* B94E14 802419D4 14400007 */  bnez      $v0, .L802419F4
/* B94E18 802419D8 00000000 */   nop      
/* B94E1C 802419DC 8E0200CC */  lw        $v0, 0xcc($s0)
/* B94E20 802419E0 8C420028 */  lw        $v0, 0x28($v0)
/* B94E24 802419E4 A480008E */  sh        $zero, 0x8e($a0)
/* B94E28 802419E8 AC820028 */  sw        $v0, 0x28($a0)
/* B94E2C 802419EC 2402000C */  addiu     $v0, $zero, 0xc
/* B94E30 802419F0 AE220070 */  sw        $v0, 0x70($s1)
.L802419F4:
/* B94E34 802419F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* B94E38 802419F8 8FB10014 */  lw        $s1, 0x14($sp)
/* B94E3C 802419FC 8FB00010 */  lw        $s0, 0x10($sp)
/* B94E40 80241A00 03E00008 */  jr        $ra
/* B94E44 80241A04 27BD0020 */   addiu    $sp, $sp, 0x20
