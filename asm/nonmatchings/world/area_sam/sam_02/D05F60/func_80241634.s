.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241634
/* D06D64 80241634 3C028025 */  lui       $v0, 0x8025
/* D06D68 80241638 8C42B9B8 */  lw        $v0, -0x4648($v0)
/* D06D6C 8024163C 8C43000C */  lw        $v1, 0xc($v0)
/* D06D70 80241640 24020001 */  addiu     $v0, $zero, 1
/* D06D74 80241644 AC62001C */  sw        $v0, 0x1c($v1)
/* D06D78 80241648 03E00008 */  jr        $ra
/* D06D7C 8024164C 24020002 */   addiu    $v0, $zero, 2
