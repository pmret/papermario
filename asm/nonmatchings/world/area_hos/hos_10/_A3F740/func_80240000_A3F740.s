.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A3F740
/* A3F740 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* A3F744 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* A3F748 80240008 24020002 */  addiu     $v0, $zero, 2
/* A3F74C 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* A3F750 80240010 03E00008 */  jr        $ra
/* A3F754 80240014 0000102D */   daddu    $v0, $zero, $zero
/* A3F758 80240018 00000000 */  nop       
/* A3F75C 8024001C 00000000 */  nop       
