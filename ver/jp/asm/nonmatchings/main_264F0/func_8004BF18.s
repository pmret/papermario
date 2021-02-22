.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004BF18
/* 27318 8004BF18 30A20C00 */  andi      $v0, $a1, 0xc00
/* 2731C 8004BF1C 00024282 */  srl       $t0, $v0, 0xa
/* 27320 8004BF20 0000382D */  daddu     $a3, $zero, $zero
/* 27324 8004BF24 30A523FF */  andi      $a1, $a1, 0x23ff
/* 27328 8004BF28 2406016C */  addiu     $a2, $zero, 0x16c
.L8004BF2C:
/* 2732C 8004BF2C 00861821 */  addu      $v1, $a0, $a2
/* 27330 8004BF30 94620096 */  lhu       $v0, 0x96($v1)
/* 27334 8004BF34 50450001 */  beql      $v0, $a1, .L8004BF3C
/* 27338 8004BF38 A0680085 */   sb       $t0, 0x85($v1)
.L8004BF3C:
/* 2733C 8004BF3C 24E70001 */  addiu     $a3, $a3, 1
/* 27340 8004BF40 28E20008 */  slti      $v0, $a3, 8
/* 27344 8004BF44 1440FFF9 */  bnez      $v0, .L8004BF2C
/* 27348 8004BF48 24C600AC */   addiu    $a2, $a2, 0xac
/* 2734C 8004BF4C 03E00008 */  jr        $ra
/* 27350 8004BF50 00000000 */   nop
