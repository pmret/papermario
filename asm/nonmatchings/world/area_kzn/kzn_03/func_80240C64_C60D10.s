.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C64_C61974
/* C61974 80240C64 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C61978 80240C68 AFB10014 */  sw        $s1, 0x14($sp)
/* C6197C 80240C6C 0080882D */  daddu     $s1, $a0, $zero
/* C61980 80240C70 AFBF0018 */  sw        $ra, 0x18($sp)
/* C61984 80240C74 AFB00010 */  sw        $s0, 0x10($sp)
/* C61988 80240C78 8E300148 */  lw        $s0, 0x148($s1)
/* C6198C 80240C7C 0C00EABB */  jal       get_npc_unsafe
/* C61990 80240C80 86040008 */   lh       $a0, 8($s0)
/* C61994 80240C84 0040202D */  daddu     $a0, $v0, $zero
/* C61998 80240C88 9482008E */  lhu       $v0, 0x8e($a0)
/* C6199C 80240C8C 2442FFFF */  addiu     $v0, $v0, -1
/* C619A0 80240C90 A482008E */  sh        $v0, 0x8e($a0)
/* C619A4 80240C94 00021400 */  sll       $v0, $v0, 0x10
/* C619A8 80240C98 1C400009 */  bgtz      $v0, .L80240CC0
/* C619AC 80240C9C 24020003 */   addiu    $v0, $zero, 3
/* C619B0 80240CA0 96030076 */  lhu       $v1, 0x76($s0)
/* C619B4 80240CA4 AE02006C */  sw        $v0, 0x6c($s0)
/* C619B8 80240CA8 A483008E */  sh        $v1, 0x8e($a0)
/* C619BC 80240CAC 8E0200CC */  lw        $v0, 0xcc($s0)
/* C619C0 80240CB0 8C420024 */  lw        $v0, 0x24($v0)
/* C619C4 80240CB4 AC820028 */  sw        $v0, 0x28($a0)
/* C619C8 80240CB8 24020020 */  addiu     $v0, $zero, 0x20
/* C619CC 80240CBC AE220070 */  sw        $v0, 0x70($s1)
.L80240CC0:
/* C619D0 80240CC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C619D4 80240CC4 8FB10014 */  lw        $s1, 0x14($sp)
/* C619D8 80240CC8 8FB00010 */  lw        $s0, 0x10($sp)
/* C619DC 80240CCC 03E00008 */  jr        $ra
/* C619E0 80240CD0 27BD0020 */   addiu    $sp, $sp, 0x20
