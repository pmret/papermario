.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033560
/* E960 80033560 24020005 */  addiu     $v0, $zero, 5
/* E964 80033564 3C01800A */  lui       $at, %hi(D_8009E710)
/* E968 80033568 A022E710 */  sb        $v0, %lo(D_8009E710)($at)
/* E96C 8003356C 03E00008 */  jr        $ra
/* E970 80033570 00000000 */   nop
