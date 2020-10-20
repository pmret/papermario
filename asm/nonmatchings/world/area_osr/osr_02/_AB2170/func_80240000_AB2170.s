.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AB2170
/* AB2170 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AB2174 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AB2178 80240008 24020002 */  addiu     $v0, $zero, 2
/* AB217C 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* AB2180 80240010 03E00008 */  jr        $ra
/* AB2184 80240014 0000102D */   daddu    $v0, $zero, $zero
/* AB2188 80240018 00000000 */  nop       
/* AB218C 8024001C 00000000 */  nop       
