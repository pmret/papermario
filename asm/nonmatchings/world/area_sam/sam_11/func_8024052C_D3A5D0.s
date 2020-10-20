.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024052C_D3AAFC
/* D3AAFC 8024052C 24020001 */  addiu     $v0, $zero, 1
/* D3AB00 80240530 3C018015 */  lui       $at, %hi(D_80151310)
/* D3AB04 80240534 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* D3AB08 80240538 03E00008 */  jr        $ra
/* D3AB0C 8024053C 24020002 */   addiu    $v0, $zero, 2
