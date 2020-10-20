.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024123C
/* CF8DAC 8024123C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF8DB0 80241240 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* CF8DB4 80241244 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* CF8DB8 80241248 3C05FE36 */  lui       $a1, 0xfe36
/* CF8DBC 8024124C AFBF0010 */  sw        $ra, 0x10($sp)
/* CF8DC0 80241250 80460075 */  lb        $a2, 0x75($v0)
/* CF8DC4 80241254 0C0B2026 */  jal       set_variable
/* CF8DC8 80241258 34A53C80 */   ori      $a1, $a1, 0x3c80
/* CF8DCC 8024125C 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF8DD0 80241260 24020002 */  addiu     $v0, $zero, 2
/* CF8DD4 80241264 03E00008 */  jr        $ra
/* CF8DD8 80241268 27BD0018 */   addiu    $sp, $sp, 0x18
