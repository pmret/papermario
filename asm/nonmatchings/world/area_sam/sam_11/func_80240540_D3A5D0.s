.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240540_D3AB10
/* D3AB10 80240540 24020002 */  addiu     $v0, $zero, 2
/* D3AB14 80240544 3C018015 */  lui       $at, %hi(D_80151310)
/* D3AB18 80240548 AC221310 */  sw        $v0, %lo(D_80151310)($at)
/* D3AB1C 8024054C 03E00008 */  jr        $ra
/* D3AB20 80240550 00000000 */   nop      
