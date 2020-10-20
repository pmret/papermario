.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406D4_B73784
/* B73784 802406D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B73788 802406D8 AFB10014 */  sw        $s1, 0x14($sp)
/* B7378C 802406DC 0080882D */  daddu     $s1, $a0, $zero
/* B73790 802406E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* B73794 802406E4 AFB00010 */  sw        $s0, 0x10($sp)
/* B73798 802406E8 8E300148 */  lw        $s0, 0x148($s1)
/* B7379C 802406EC 0C00EABB */  jal       get_npc_unsafe
/* B737A0 802406F0 86040008 */   lh       $a0, 8($s0)
/* B737A4 802406F4 24030001 */  addiu     $v1, $zero, 1
/* B737A8 802406F8 0040202D */  daddu     $a0, $v0, $zero
/* B737AC 802406FC AE03006C */  sw        $v1, 0x6c($s0)
/* B737B0 80240700 8482008C */  lh        $v0, 0x8c($a0)
/* B737B4 80240704 14400009 */  bnez      $v0, .L8024072C
/* B737B8 80240708 24020002 */   addiu    $v0, $zero, 2
/* B737BC 8024070C 96030072 */  lhu       $v1, 0x72($s0)
/* B737C0 80240710 AE02006C */  sw        $v0, 0x6c($s0)
/* B737C4 80240714 A483008E */  sh        $v1, 0x8e($a0)
/* B737C8 80240718 8E0200CC */  lw        $v0, 0xcc($s0)
/* B737CC 8024071C 8C420020 */  lw        $v0, 0x20($v0)
/* B737D0 80240720 AC820028 */  sw        $v0, 0x28($a0)
/* B737D4 80240724 2402001F */  addiu     $v0, $zero, 0x1f
/* B737D8 80240728 AE220070 */  sw        $v0, 0x70($s1)
.L8024072C:
/* B737DC 8024072C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B737E0 80240730 8FB10014 */  lw        $s1, 0x14($sp)
/* B737E4 80240734 8FB00010 */  lw        $s0, 0x10($sp)
/* B737E8 80240738 03E00008 */  jr        $ra
/* B737EC 8024073C 27BD0020 */   addiu    $sp, $sp, 0x20
