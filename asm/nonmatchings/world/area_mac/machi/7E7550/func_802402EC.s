.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402EC
/* 7E768C 802402EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E7690 802402F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E7694 802402F4 8C820148 */  lw        $v0, 0x148($a0)
/* 7E7698 802402F8 0C00EABB */  jal       get_npc_unsafe
/* 7E769C 802402FC 84440008 */   lh       $a0, 8($v0)
/* 7E76A0 80240300 0C0177F5 */  jal       func_8005DFD4
/* 7E76A4 80240304 0040202D */   daddu    $a0, $v0, $zero
/* 7E76A8 80240308 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E76AC 8024030C 24020002 */  addiu     $v0, $zero, 2
/* 7E76B0 80240310 03E00008 */  jr        $ra
/* 7E76B4 80240314 27BD0018 */   addiu    $sp, $sp, 0x18
