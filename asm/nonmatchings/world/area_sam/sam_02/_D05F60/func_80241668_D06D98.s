.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241668_D06D98
/* D06D98 80241668 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D06D9C 8024166C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D06DA0 80241670 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D06DA4 80241674 3C05FE36 */  lui       $a1, 0xfe36
/* D06DA8 80241678 AFBF0010 */  sw        $ra, 0x10($sp)
/* D06DAC 8024167C 80460075 */  lb        $a2, 0x75($v0)
/* D06DB0 80241680 0C0B2026 */  jal       set_variable
/* D06DB4 80241684 34A53C80 */   ori      $a1, $a1, 0x3c80
/* D06DB8 80241688 8FBF0010 */  lw        $ra, 0x10($sp)
/* D06DBC 8024168C 24020002 */  addiu     $v0, $zero, 2
/* D06DC0 80241690 03E00008 */  jr        $ra
/* D06DC4 80241694 27BD0018 */   addiu    $sp, $sp, 0x18
