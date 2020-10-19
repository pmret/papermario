.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240818_CF8388
/* CF8388 80240818 24020001 */  addiu     $v0, $zero, 1
/* CF838C 8024081C 3C018015 */  lui       $at, %hi(D_80151310)
/* CF8390 80240820 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* CF8394 80240824 03E00008 */  jr        $ra
/* CF8398 80240828 24020002 */   addiu    $v0, $zero, 2
