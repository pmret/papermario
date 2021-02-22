.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F6C_BE671C
/* BE671C 80242F6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE6720 80242F70 AFB10014 */  sw        $s1, 0x14($sp)
/* BE6724 80242F74 0080882D */  daddu     $s1, $a0, $zero
/* BE6728 80242F78 AFBF0018 */  sw        $ra, 0x18($sp)
/* BE672C 80242F7C AFB00010 */  sw        $s0, 0x10($sp)
/* BE6730 80242F80 8E300148 */  lw        $s0, 0x148($s1)
/* BE6734 80242F84 0C00EABB */  jal       get_npc_unsafe
/* BE6738 80242F88 86040008 */   lh       $a0, 8($s0)
/* BE673C 80242F8C 0040182D */  daddu     $v1, $v0, $zero
/* BE6740 80242F90 9462008E */  lhu       $v0, 0x8e($v1)
/* BE6744 80242F94 2442FFFF */  addiu     $v0, $v0, -1
/* BE6748 80242F98 A462008E */  sh        $v0, 0x8e($v1)
/* BE674C 80242F9C 00021400 */  sll       $v0, $v0, 0x10
/* BE6750 80242FA0 1C400007 */  bgtz      $v0, .L80242FC0
/* BE6754 80242FA4 24020008 */   addiu    $v0, $zero, 8
/* BE6758 80242FA8 A462008E */  sh        $v0, 0x8e($v1)
/* BE675C 80242FAC 8E0200CC */  lw        $v0, 0xcc($s0)
/* BE6760 80242FB0 8C420038 */  lw        $v0, 0x38($v0)
/* BE6764 80242FB4 AC620028 */  sw        $v0, 0x28($v1)
/* BE6768 80242FB8 24020034 */  addiu     $v0, $zero, 0x34
/* BE676C 80242FBC AE220070 */  sw        $v0, 0x70($s1)
.L80242FC0:
/* BE6770 80242FC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE6774 80242FC4 8FB10014 */  lw        $s1, 0x14($sp)
/* BE6778 80242FC8 8FB00010 */  lw        $s0, 0x10($sp)
/* BE677C 80242FCC 03E00008 */  jr        $ra
/* BE6780 80242FD0 27BD0020 */   addiu    $sp, $sp, 0x20
