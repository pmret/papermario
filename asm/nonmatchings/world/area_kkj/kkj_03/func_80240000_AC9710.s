.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AC9710
/* AC9710 80240000 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AC9714 80240004 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AC9718 80240008 24020002 */  addiu     $v0, $zero, 2
/* AC971C 8024000C A0620084 */  sb        $v0, 0x84($v1)
/* AC9720 80240010 03E00008 */  jr        $ra
/* AC9724 80240014 0000102D */   daddu    $v0, $zero, $zero
/* AC9728 80240018 00000000 */  nop       
/* AC972C 8024001C 00000000 */  nop       
