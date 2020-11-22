.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* B5F984 802416D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5F988 802416D8 AFB10014 */  sw        $s1, 0x14($sp)
/* B5F98C 802416DC 0080882D */  daddu     $s1, $a0, $zero
/* B5F990 802416E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* B5F994 802416E4 AFB00010 */  sw        $s0, 0x10($sp)
/* B5F998 802416E8 8E300148 */  lw        $s0, 0x148($s1)
/* B5F99C 802416EC 0C00EABB */  jal       get_npc_unsafe
/* B5F9A0 802416F0 86040008 */   lh       $a0, 8($s0)
/* B5F9A4 802416F4 0040202D */  daddu     $a0, $v0, $zero
/* B5F9A8 802416F8 9482008E */  lhu       $v0, 0x8e($a0)
/* B5F9AC 802416FC 2442FFFF */  addiu     $v0, $v0, -1
/* B5F9B0 80241700 A482008E */  sh        $v0, 0x8e($a0)
/* B5F9B4 80241704 00021400 */  sll       $v0, $v0, 0x10
/* B5F9B8 80241708 1C400009 */  bgtz      $v0, .L80241730
/* B5F9BC 8024170C 24020003 */   addiu    $v0, $zero, 3
/* B5F9C0 80241710 96030076 */  lhu       $v1, 0x76($s0)
/* B5F9C4 80241714 AE02006C */  sw        $v0, 0x6c($s0)
/* B5F9C8 80241718 A483008E */  sh        $v1, 0x8e($a0)
/* B5F9CC 8024171C 8E0200CC */  lw        $v0, 0xcc($s0)
/* B5F9D0 80241720 8C420024 */  lw        $v0, 0x24($v0)
/* B5F9D4 80241724 AC820028 */  sw        $v0, 0x28($a0)
/* B5F9D8 80241728 24020020 */  addiu     $v0, $zero, 0x20
/* B5F9DC 8024172C AE220070 */  sw        $v0, 0x70($s1)
.L80241730:
/* B5F9E0 80241730 8FBF0018 */  lw        $ra, 0x18($sp)
/* B5F9E4 80241734 8FB10014 */  lw        $s1, 0x14($sp)
/* B5F9E8 80241738 8FB00010 */  lw        $s0, 0x10($sp)
/* B5F9EC 8024173C 03E00008 */  jr        $ra
/* B5F9F0 80241740 27BD0020 */   addiu    $sp, $sp, 0x20
