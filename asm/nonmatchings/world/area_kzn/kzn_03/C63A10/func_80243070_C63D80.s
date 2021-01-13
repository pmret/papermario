.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243070_C63D80
/* C63D80 80243070 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C63D84 80243074 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C63D88 80243078 8C420010 */  lw        $v0, 0x10($v0)
/* C63D8C 8024307C 30428000 */  andi      $v0, $v0, 0x8000
/* C63D90 80243080 AC8200A4 */  sw        $v0, 0xa4($a0)
/* C63D94 80243084 03E00008 */  jr        $ra
/* C63D98 80243088 24020002 */   addiu    $v0, $zero, 2
/* C63D9C 8024308C 00000000 */  nop
