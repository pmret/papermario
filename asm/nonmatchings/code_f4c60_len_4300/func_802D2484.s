.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2484
/* F6E34 802D2484 3C028016 */  lui       $v0, 0x8016
/* F6E38 802D2488 8442A552 */  lh        $v0, -0x5aae($v0)
/* F6E3C 802D248C 00021027 */  nor       $v0, $zero, $v0
/* F6E40 802D2490 000217C3 */  sra       $v0, $v0, 0x1f
/* F6E44 802D2494 03E00008 */  jr        $ra
/* F6E48 802D2498 30420002 */   andi     $v0, $v0, 2
