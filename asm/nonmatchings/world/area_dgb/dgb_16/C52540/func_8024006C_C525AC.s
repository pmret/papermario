.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* C525AC 8024006C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C525B0 80240070 AFB10014 */  sw        $s1, 0x14($sp)
/* C525B4 80240074 0080882D */  daddu     $s1, $a0, $zero
/* C525B8 80240078 AFBF0018 */  sw        $ra, 0x18($sp)
/* C525BC 8024007C AFB00010 */  sw        $s0, 0x10($sp)
/* C525C0 80240080 8E300148 */  lw        $s0, 0x148($s1)
/* C525C4 80240084 0C00EABB */  jal       get_npc_unsafe
/* C525C8 80240088 86040008 */   lh       $a0, 8($s0)
/* C525CC 8024008C 0040202D */  daddu     $a0, $v0, $zero
/* C525D0 80240090 9482008E */  lhu       $v0, 0x8e($a0)
/* C525D4 80240094 2442FFFF */  addiu     $v0, $v0, -1
/* C525D8 80240098 A482008E */  sh        $v0, 0x8e($a0)
/* C525DC 8024009C 00021400 */  sll       $v0, $v0, 0x10
/* C525E0 802400A0 1C400009 */  bgtz      $v0, .L802400C8
/* C525E4 802400A4 24020003 */   addiu    $v0, $zero, 3
/* C525E8 802400A8 96030076 */  lhu       $v1, 0x76($s0)
/* C525EC 802400AC AE02006C */  sw        $v0, 0x6c($s0)
/* C525F0 802400B0 A483008E */  sh        $v1, 0x8e($a0)
/* C525F4 802400B4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C525F8 802400B8 8C420024 */  lw        $v0, 0x24($v0)
/* C525FC 802400BC AC820028 */  sw        $v0, 0x28($a0)
/* C52600 802400C0 24020020 */  addiu     $v0, $zero, 0x20
/* C52604 802400C4 AE220070 */  sw        $v0, 0x70($s1)
.L802400C8:
/* C52608 802400C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C5260C 802400CC 8FB10014 */  lw        $s1, 0x14($sp)
/* C52610 802400D0 8FB00010 */  lw        $s0, 0x10($sp)
/* C52614 802400D4 03E00008 */  jr        $ra
/* C52618 802400D8 27BD0020 */   addiu    $sp, $sp, 0x20
