.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AD5ED0
/* AD5ED0 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AD5ED4 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AD5ED8 80240008 24020002 */  addiu     $v0, $zero, 2
/* AD5EDC 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* AD5EE0 80240010 03E00008 */  jr        $ra
/* AD5EE4 80240014 0000102D */   daddu    $v0, $zero, $zero
/* AD5EE8 80240018 00000000 */  nop       
/* AD5EEC 8024001C 00000000 */  nop       
