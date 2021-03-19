.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C_C76CFC
/* C76CFC 8024001C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* C76D00 80240020 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* C76D04 80240024 8C430000 */  lw        $v1, ($v0)
/* C76D08 80240028 2404FFBF */  addiu     $a0, $zero, -0x41
/* C76D0C 8024002C 00641824 */  and       $v1, $v1, $a0
/* C76D10 80240030 AC430000 */  sw        $v1, ($v0)
/* C76D14 80240034 03E00008 */  jr        $ra
/* C76D18 80240038 24020002 */   addiu    $v0, $zero, 2
