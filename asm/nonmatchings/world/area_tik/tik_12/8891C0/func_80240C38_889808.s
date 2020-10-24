.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C38_889808
/* 889808 80240C38 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 88980C 80240C3C 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 889810 80240C40 8C430000 */  lw        $v1, ($v0)
/* 889814 80240C44 2404FFBF */  addiu     $a0, $zero, -0x41
/* 889818 80240C48 00641824 */  and       $v1, $v1, $a0
/* 88981C 80240C4C AC430000 */  sw        $v1, ($v0)
/* 889820 80240C50 03E00008 */  jr        $ra
/* 889824 80240C54 24020002 */   addiu    $v0, $zero, 2
