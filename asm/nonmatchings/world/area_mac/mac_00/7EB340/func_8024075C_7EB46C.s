.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024075C_7EB46C
/* 7EB46C 8024075C 3C018015 */  lui       $at, %hi(D_80151310)
/* 7EB470 80240760 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 7EB474 80240764 03E00008 */  jr        $ra
/* 7EB478 80240768 24020002 */   addiu    $v0, $zero, 2
