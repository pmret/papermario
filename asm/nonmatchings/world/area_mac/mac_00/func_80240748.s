.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240748
/* 7EB458 80240748 24020001 */  addiu     $v0, $zero, 1
/* 7EB45C 8024074C 3C018015 */  lui       $at, %hi(D_80151310)
/* 7EB460 80240750 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* 7EB464 80240754 03E00008 */  jr        $ra
/* 7EB468 80240758 24020002 */   addiu    $v0, $zero, 2
