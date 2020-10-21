.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024161C_D06D4C
/* D06D4C 8024161C 3C028025 */  lui       $v0, 0x8025
/* D06D50 80241620 8C42B9B8 */  lw        $v0, -0x4648($v0)
/* D06D54 80241624 8C42000C */  lw        $v0, 0xc($v0)
/* D06D58 80241628 AC40001C */  sw        $zero, 0x1c($v0)
/* D06D5C 8024162C 03E00008 */  jr        $ra
/* D06D60 80241630 24020002 */   addiu    $v0, $zero, 2
