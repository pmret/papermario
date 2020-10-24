.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241938_B4C3A8
/* B4C3A8 80241938 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B4C3AC 8024193C AFB10014 */  sw        $s1, 0x14($sp)
/* B4C3B0 80241940 0080882D */  daddu     $s1, $a0, $zero
/* B4C3B4 80241944 AFBF0018 */  sw        $ra, 0x18($sp)
/* B4C3B8 80241948 AFB00010 */  sw        $s0, 0x10($sp)
/* B4C3BC 8024194C 8E300148 */  lw        $s0, 0x148($s1)
/* B4C3C0 80241950 0C00EABB */  jal       get_npc_unsafe
/* B4C3C4 80241954 86040008 */   lh       $a0, 8($s0)
/* B4C3C8 80241958 0040202D */  daddu     $a0, $v0, $zero
/* B4C3CC 8024195C 9482008E */  lhu       $v0, 0x8e($a0)
/* B4C3D0 80241960 2442FFFF */  addiu     $v0, $v0, -1
/* B4C3D4 80241964 A482008E */  sh        $v0, 0x8e($a0)
/* B4C3D8 80241968 00021400 */  sll       $v0, $v0, 0x10
/* B4C3DC 8024196C 1C400009 */  bgtz      $v0, .L80241994
/* B4C3E0 80241970 24020003 */   addiu    $v0, $zero, 3
/* B4C3E4 80241974 96030076 */  lhu       $v1, 0x76($s0)
/* B4C3E8 80241978 AE02006C */  sw        $v0, 0x6c($s0)
/* B4C3EC 8024197C A483008E */  sh        $v1, 0x8e($a0)
/* B4C3F0 80241980 8E0200CC */  lw        $v0, 0xcc($s0)
/* B4C3F4 80241984 8C420024 */  lw        $v0, 0x24($v0)
/* B4C3F8 80241988 AC820028 */  sw        $v0, 0x28($a0)
/* B4C3FC 8024198C 24020020 */  addiu     $v0, $zero, 0x20
/* B4C400 80241990 AE220070 */  sw        $v0, 0x70($s1)
.L80241994:
/* B4C404 80241994 8FBF0018 */  lw        $ra, 0x18($sp)
/* B4C408 80241998 8FB10014 */  lw        $s1, 0x14($sp)
/* B4C40C 8024199C 8FB00010 */  lw        $s0, 0x10($sp)
/* B4C410 802419A0 03E00008 */  jr        $ra
/* B4C414 802419A4 27BD0020 */   addiu    $sp, $sp, 0x20
