.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240814_D87214
/* D87214 80240814 3C02800A */  lui       $v0, %hi(D_8009A650)
/* D87218 80240818 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* D8721C 8024081C 8C430000 */  lw        $v1, ($v0)
/* D87220 80240820 2404FF7F */  addiu     $a0, $zero, -0x81
/* D87224 80240824 00641824 */  and       $v1, $v1, $a0
/* D87228 80240828 AC430000 */  sw        $v1, ($v0)
/* D8722C 8024082C 03E00008 */  jr        $ra
/* D87230 80240830 24020002 */   addiu    $v0, $zero, 2
/* D87234 80240834 00000000 */  nop
/* D87238 80240838 00000000 */  nop
/* D8723C 8024083C 00000000 */  nop
