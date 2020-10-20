.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FD0_D7FD30
/* D7FD30 80240FD0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* D7FD34 80240FD4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* D7FD38 80240FD8 8C430004 */  lw        $v1, 4($v0)
/* D7FD3C 80240FDC 3C040080 */  lui       $a0, 0x80
/* D7FD40 80240FE0 00641825 */  or        $v1, $v1, $a0
/* D7FD44 80240FE4 AC430004 */  sw        $v1, 4($v0)
/* D7FD48 80240FE8 03E00008 */  jr        $ra
/* D7FD4C 80240FEC 24020002 */   addiu    $v0, $zero, 2
