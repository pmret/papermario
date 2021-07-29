.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C_EC9D1C
/* EC9D1C 8024001C 3C02800A */  lui       $v0, %hi(D_800A15A8)
/* EC9D20 80240020 244215A8 */  addiu     $v0, $v0, %lo(D_800A15A8)
/* EC9D24 80240024 8C430000 */  lw        $v1, ($v0)
/* EC9D28 80240028 2404FFBF */  addiu     $a0, $zero, -0x41
/* EC9D2C 8024002C 00641824 */  and       $v1, $v1, $a0
/* EC9D30 80240030 AC430000 */  sw        $v1, ($v0)
/* EC9D34 80240034 03E00008 */  jr        $ra
/* EC9D38 80240038 24020002 */   addiu    $v0, $zero, 2
