.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_entity_fog_color
/* B9728 80123028 3C018015 */  lui       $at, %hi(D_8015437C)
/* B972C 8012302C AC24437C */  sw        $a0, %lo(D_8015437C)($at)
/* B9730 80123030 3C018015 */  lui       $at, %hi(D_80154380)
/* B9734 80123034 AC254380 */  sw        $a1, %lo(D_80154380)($at)
/* B9738 80123038 3C018015 */  lui       $at, %hi(D_80154384)
/* B973C 8012303C AC264384 */  sw        $a2, %lo(D_80154384)($at)
/* B9740 80123040 3C018015 */  lui       $at, %hi(D_80154388)
/* B9744 80123044 AC274388 */  sw        $a3, %lo(D_80154388)($at)
/* B9748 80123048 03E00008 */  jr        $ra
/* B974C 8012304C 00000000 */   nop      
