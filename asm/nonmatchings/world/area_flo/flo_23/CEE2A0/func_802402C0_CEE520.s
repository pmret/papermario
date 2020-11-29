.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402C0_CEE520
/* CEE520 802402C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CEE524 802402C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* CEE528 802402C8 8C82000C */  lw        $v0, 0xc($a0)
/* CEE52C 802402CC 0C0B1EAF */  jal       get_variable
/* CEE530 802402D0 8C450000 */   lw       $a1, ($v0)
/* CEE534 802402D4 3C018024 */  lui       $at, %hi(D_80241310)
/* CEE538 802402D8 AC221310 */  sw        $v0, %lo(D_80241310)($at)
/* CEE53C 802402DC 24020002 */  addiu     $v0, $zero, 2
/* CEE540 802402E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* CEE544 802402E4 24030001 */  addiu     $v1, $zero, 1
/* CEE548 802402E8 3C018024 */  lui       $at, %hi(D_8024130C)
/* CEE54C 802402EC AC23130C */  sw        $v1, %lo(D_8024130C)($at)
/* CEE550 802402F0 03E00008 */  jr        $ra
/* CEE554 802402F4 27BD0018 */   addiu    $sp, $sp, 0x18
