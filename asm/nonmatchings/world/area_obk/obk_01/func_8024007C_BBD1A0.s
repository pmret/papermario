.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024007C_BBD21C
/* BBD21C 8024007C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* BBD220 80240080 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* BBD224 80240084 90420012 */  lbu       $v0, 0x12($v0)
/* BBD228 80240088 000211C2 */  srl       $v0, $v0, 7
/* BBD22C 8024008C AC82009C */  sw        $v0, 0x9c($a0)
/* BBD230 80240090 03E00008 */  jr        $ra
/* BBD234 80240094 24020002 */   addiu    $v0, $zero, 2
