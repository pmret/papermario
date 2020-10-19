.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AB6290
/* AB6290 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AB6294 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AB6298 80240008 24020002 */  addiu     $v0, $zero, 2
/* AB629C 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* AB62A0 80240010 03E00008 */  jr        $ra
/* AB62A4 80240014 0000102D */   daddu    $v0, $zero, $zero
/* AB62A8 80240018 00000000 */  nop       
/* AB62AC 8024001C 00000000 */  nop       
