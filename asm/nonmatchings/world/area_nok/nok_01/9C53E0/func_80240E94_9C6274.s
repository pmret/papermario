.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E94_9C6274
/* 9C6274 80240E94 3C018015 */  lui       $at, %hi(D_80151310)
/* 9C6278 80240E98 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* 9C627C 80240E9C 03E00008 */  jr        $ra
/* 9C6280 80240EA0 24020002 */   addiu    $v0, $zero, 2
