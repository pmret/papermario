.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_entity_fog_color
/* B9728 80123028 3C018015 */  lui       $at, 0x8015
/* B972C 8012302C AC24437C */  sw        $a0, 0x437c($at)
/* B9730 80123030 3C018015 */  lui       $at, 0x8015
/* B9734 80123034 AC254380 */  sw        $a1, 0x4380($at)
/* B9738 80123038 3C018015 */  lui       $at, 0x8015
/* B973C 8012303C AC264384 */  sw        $a2, 0x4384($at)
/* B9740 80123040 3C018015 */  lui       $at, 0x8015
/* B9744 80123044 AC274388 */  sw        $a3, 0x4388($at)
/* B9748 80123048 03E00008 */  jr        $ra
/* B974C 8012304C 00000000 */   nop      
