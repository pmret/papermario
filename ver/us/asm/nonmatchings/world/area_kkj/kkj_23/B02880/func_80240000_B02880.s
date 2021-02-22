.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B02880
/* B02880 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* B02884 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* B02888 80240008 24020002 */  addiu     $v0, $zero, 2
/* B0288C 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* B02890 80240010 03E00008 */  jr        $ra
/* B02894 80240014 0000102D */   daddu    $v0, $zero, $zero
/* B02898 80240018 00000000 */  nop
/* B0289C 8024001C 00000000 */  nop
