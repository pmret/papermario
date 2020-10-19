.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F60_D4DFA0
/* D4DFA0 80240F60 3C02800A */  lui       $v0, %hi(D_8009A650)
/* D4DFA4 80240F64 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* D4DFA8 80240F68 8C430000 */  lw        $v1, ($v0)
/* D4DFAC 80240F6C 2404FF7F */  addiu     $a0, $zero, -0x81
/* D4DFB0 80240F70 00641824 */  and       $v1, $v1, $a0
/* D4DFB4 80240F74 AC430000 */  sw        $v1, ($v0)
/* D4DFB8 80240F78 03E00008 */  jr        $ra
/* D4DFBC 80240F7C 24020002 */   addiu    $v0, $zero, 2
