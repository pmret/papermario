.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402C0_BCEEB0
/* BCEEB0 802402C0 AC800074 */  sw        $zero, 0x74($a0)
/* BCEEB4 802402C4 03E00008 */  jr        $ra
/* BCEEB8 802402C8 24020002 */   addiu    $v0, $zero, 2
