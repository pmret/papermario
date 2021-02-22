.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241000_C77CE0
/* C77CE0 80241000 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C77CE4 80241004 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C77CE8 80241008 8C420010 */  lw        $v0, 0x10($v0)
/* C77CEC 8024100C 30428000 */  andi      $v0, $v0, 0x8000
/* C77CF0 80241010 AC8200A4 */  sw        $v0, 0xa4($a0)
/* C77CF4 80241014 03E00008 */  jr        $ra
/* C77CF8 80241018 24020002 */   addiu    $v0, $zero, 2
/* C77CFC 8024101C 00000000 */  nop
