.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D77F20
/* D77F20 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D77F24 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D77F28 80240008 24020001 */  addiu     $v0, $zero, 1
/* D77F2C 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* D77F30 80240010 03E00008 */  jr        $ra
/* D77F34 80240014 0000102D */   daddu    $v0, $zero, $zero
/* D77F38 80240018 00000000 */  nop       
/* D77F3C 8024001C 00000000 */  nop       
