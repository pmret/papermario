.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D4FFF0
/* D4FFF0 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D4FFF4 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D4FFF8 80240008 24020001 */  addiu     $v0, $zero, 1
/* D4FFFC 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* D50000 80240010 03E00008 */  jr        $ra
/* D50004 80240014 0000102D */   daddu    $v0, $zero, $zero
/* D50008 80240018 00000000 */  nop       
/* D5000C 8024001C 00000000 */  nop       
