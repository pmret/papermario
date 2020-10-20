.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241478_D51468
/* D51468 80241478 AC800084 */  sw        $zero, 0x84($a0)
/* D5146C 8024147C 3C038011 */  lui       $v1, %hi(gPlayerActionState)
/* D51470 80241480 8063F07C */  lb        $v1, %lo(gPlayerActionState)($v1)
/* D51474 80241484 2402000E */  addiu     $v0, $zero, 0xe
/* D51478 80241488 10620004 */  beq       $v1, $v0, .L8024149C
/* D5147C 8024148C 24020001 */   addiu    $v0, $zero, 1
/* D51480 80241490 24020010 */  addiu     $v0, $zero, 0x10
/* D51484 80241494 14620002 */  bne       $v1, $v0, .L802414A0
/* D51488 80241498 24020001 */   addiu    $v0, $zero, 1
.L8024149C:
/* D5148C 8024149C AC820084 */  sw        $v0, 0x84($a0)
.L802414A0:
/* D51490 802414A0 03E00008 */  jr        $ra
/* D51494 802414A4 24020002 */   addiu    $v0, $zero, 2
