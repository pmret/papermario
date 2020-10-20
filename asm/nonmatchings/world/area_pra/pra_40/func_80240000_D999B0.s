.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D999B0
/* D999B0 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D999B4 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D999B8 80240008 24020001 */  addiu     $v0, $zero, 1
/* D999BC 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* D999C0 80240010 03E00008 */  jr        $ra
/* D999C4 80240014 0000102D */   daddu    $v0, $zero, $zero
/* D999C8 80240018 00000000 */  nop       
/* D999CC 8024001C 00000000 */  nop       
