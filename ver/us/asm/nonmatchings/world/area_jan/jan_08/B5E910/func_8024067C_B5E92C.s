.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024067C_B5E92C
/* B5E92C 8024067C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* B5E930 80240680 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* B5E934 80240684 8C430000 */  lw        $v1, ($v0)
/* B5E938 80240688 2404FFBF */  addiu     $a0, $zero, -0x41
/* B5E93C 8024068C 00641824 */  and       $v1, $v1, $a0
/* B5E940 80240690 AC430000 */  sw        $v1, ($v0)
/* B5E944 80240694 03E00008 */  jr        $ra
/* B5E948 80240698 24020002 */   addiu    $v0, $zero, 2
