.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240554_D3AB24
/* D3AB24 80240554 3C018015 */  lui       $at, %hi(D_80151310)
/* D3AB28 80240558 AC201310 */  sw        $zero, %lo(D_80151310)($at)
/* D3AB2C 8024055C 03E00008 */  jr        $ra
/* D3AB30 80240560 24020002 */   addiu    $v0, $zero, 2
