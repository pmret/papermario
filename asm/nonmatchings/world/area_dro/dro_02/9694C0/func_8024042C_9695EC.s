.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024042C_9695EC
/* 9695EC 8024042C 3C018015 */  lui       $at, %hi(D_80151310)
/* 9695F0 80240430 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 9695F4 80240434 03E00008 */  jr        $ra
/* 9695F8 80240438 24020002 */   addiu    $v0, $zero, 2
