.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_08_UnkFunc17
/* D2FC9C 8024001C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* D2FCA0 80240020 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* D2FCA4 80240024 8C430000 */  lw        $v1, ($v0)
/* D2FCA8 80240028 2404FFBF */  addiu     $a0, $zero, -0x41
/* D2FCAC 8024002C 00641824 */  and       $v1, $v1, $a0
/* D2FCB0 80240030 AC430000 */  sw        $v1, ($v0)
/* D2FCB4 80240034 03E00008 */  jr        $ra
/* D2FCB8 80240038 24020002 */   addiu    $v0, $zero, 2
