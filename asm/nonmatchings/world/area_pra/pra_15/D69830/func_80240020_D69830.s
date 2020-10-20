.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_D69830
/* D69830 80240020 3C02800A */  lui       $v0, %hi(D_8009A650)
/* D69834 80240024 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* D69838 80240028 8C430000 */  lw        $v1, ($v0)
/* D6983C 8024002C 2404FF7F */  addiu     $a0, $zero, -0x81
/* D69840 80240030 00641824 */  and       $v1, $v1, $a0
/* D69844 80240034 AC430000 */  sw        $v1, ($v0)
/* D69848 80240038 03E00008 */  jr        $ra
/* D6984C 8024003C 24020002 */   addiu    $v0, $zero, 2
