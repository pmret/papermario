.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D4D040
/* D4D040 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D4D044 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D4D048 80240008 24020001 */  addiu     $v0, $zero, 1
/* D4D04C 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* D4D050 80240010 03E00008 */  jr        $ra
/* D4D054 80240014 0000102D */   daddu    $v0, $zero, $zero
/* D4D058 80240018 00000000 */  nop       
/* D4D05C 8024001C 00000000 */  nop       
