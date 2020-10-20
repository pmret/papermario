.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024159C_95C79C
/* 95C79C 8024159C 3C018015 */  lui       $at, %hi(D_80151310)
/* 95C7A0 802415A0 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 95C7A4 802415A4 03E00008 */  jr        $ra
/* 95C7A8 802415A8 24020002 */   addiu    $v0, $zero, 2
