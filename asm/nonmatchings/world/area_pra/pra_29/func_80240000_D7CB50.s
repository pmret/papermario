.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D7CB50
/* D7CB50 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D7CB54 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D7CB58 80240008 24020001 */  addiu     $v0, $zero, 1
/* D7CB5C 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* D7CB60 80240010 03E00008 */  jr        $ra
/* D7CB64 80240014 0000102D */   daddu    $v0, $zero, $zero
/* D7CB68 80240018 00000000 */  nop       
/* D7CB6C 8024001C 00000000 */  nop       
