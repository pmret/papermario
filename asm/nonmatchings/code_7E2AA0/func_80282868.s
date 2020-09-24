.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282868
/* 7E36E8 80282868 8C820074 */  lw        $v0, 0x74($a0)
/* 7E36EC 8028286C AC820088 */  sw        $v0, 0x88($a0)
/* 7E36F0 80282870 03E00008 */  jr        $ra
/* 7E36F4 80282874 24020002 */   addiu    $v0, $zero, 2
/* 7E36F8 80282878 00000000 */  nop       
/* 7E36FC 8028287C 00000000 */  nop       
