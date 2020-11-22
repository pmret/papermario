.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* C4F57C 8024006C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C4F580 80240070 AFB10014 */  sw        $s1, 0x14($sp)
/* C4F584 80240074 0080882D */  daddu     $s1, $a0, $zero
/* C4F588 80240078 AFBF0018 */  sw        $ra, 0x18($sp)
/* C4F58C 8024007C AFB00010 */  sw        $s0, 0x10($sp)
/* C4F590 80240080 8E300148 */  lw        $s0, 0x148($s1)
/* C4F594 80240084 0C00EABB */  jal       get_npc_unsafe
/* C4F598 80240088 86040008 */   lh       $a0, 8($s0)
/* C4F59C 8024008C 0040202D */  daddu     $a0, $v0, $zero
/* C4F5A0 80240090 9482008E */  lhu       $v0, 0x8e($a0)
/* C4F5A4 80240094 2442FFFF */  addiu     $v0, $v0, -1
/* C4F5A8 80240098 A482008E */  sh        $v0, 0x8e($a0)
/* C4F5AC 8024009C 00021400 */  sll       $v0, $v0, 0x10
/* C4F5B0 802400A0 1C400009 */  bgtz      $v0, .L802400C8
/* C4F5B4 802400A4 24020003 */   addiu    $v0, $zero, 3
/* C4F5B8 802400A8 96030076 */  lhu       $v1, 0x76($s0)
/* C4F5BC 802400AC AE02006C */  sw        $v0, 0x6c($s0)
/* C4F5C0 802400B0 A483008E */  sh        $v1, 0x8e($a0)
/* C4F5C4 802400B4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C4F5C8 802400B8 8C420024 */  lw        $v0, 0x24($v0)
/* C4F5CC 802400BC AC820028 */  sw        $v0, 0x28($a0)
/* C4F5D0 802400C0 24020020 */  addiu     $v0, $zero, 0x20
/* C4F5D4 802400C4 AE220070 */  sw        $v0, 0x70($s1)
.L802400C8:
/* C4F5D8 802400C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C4F5DC 802400CC 8FB10014 */  lw        $s1, 0x14($sp)
/* C4F5E0 802400D0 8FB00010 */  lw        $s0, 0x10($sp)
/* C4F5E4 802400D4 03E00008 */  jr        $ra
/* C4F5E8 802400D8 27BD0020 */   addiu    $sp, $sp, 0x20
