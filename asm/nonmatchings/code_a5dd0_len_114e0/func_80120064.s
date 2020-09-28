.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80120064
/* B6764 80120064 3C018015 */  lui       $at, 0x8015
/* B6768 80120068 AC243A48 */  sw        $a0, 0x3a48($at)
/* B676C 8012006C 3C018015 */  lui       $at, 0x8015
/* B6770 80120070 AC253A4C */  sw        $a1, 0x3a4c($at)
/* B6774 80120074 3C018015 */  lui       $at, 0x8015
/* B6778 80120078 AC263A50 */  sw        $a2, 0x3a50($at)
/* B677C 8012007C 3C018015 */  lui       $at, 0x8015
/* B6780 80120080 AC273A54 */  sw        $a3, 0x3a54($at)
/* B6784 80120084 03E00008 */  jr        $ra
/* B6788 80120088 00000000 */   nop      
