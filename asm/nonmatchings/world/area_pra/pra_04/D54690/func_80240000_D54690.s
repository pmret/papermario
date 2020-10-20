.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D54690
/* D54690 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D54694 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D54698 80240008 24020001 */  addiu     $v0, $zero, 1
/* D5469C 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* D546A0 80240010 03E00008 */  jr        $ra
/* D546A4 80240014 0000102D */   daddu    $v0, $zero, $zero
/* D546A8 80240018 00000000 */  nop       
/* D546AC 8024001C 00000000 */  nop       
