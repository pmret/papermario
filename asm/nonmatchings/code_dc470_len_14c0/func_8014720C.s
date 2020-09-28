.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014720C
/* DD90C 8014720C 24020001 */  addiu     $v0, $zero, 1
/* DD910 80147210 3C018015 */  lui       $at, 0x8015
/* DD914 80147214 03E00008 */  jr        $ra
/* DD918 80147218 A022F12F */   sb       $v0, -0xed1($at)
