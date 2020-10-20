.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C
/* 988B7C 8024001C 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 988B80 80240020 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 988B84 80240024 8C430000 */  lw        $v1, ($v0)
/* 988B88 80240028 2404FFBF */  addiu     $a0, $zero, -0x41
/* 988B8C 8024002C 00641824 */  and       $v1, $v1, $a0
/* 988B90 80240030 AC430000 */  sw        $v1, ($v0)
/* 988B94 80240034 03E00008 */  jr        $ra
/* 988B98 80240038 24020002 */   addiu    $v0, $zero, 2
