.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80120420
/* B6B20 80120420 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B6B24 80120424 10800010 */  beqz      $a0, .L80120468
/* B6B28 80120428 AFBF0010 */   sw       $ra, 0x10($sp)
/* B6B2C 8012042C 8C83001C */  lw        $v1, 0x1c($a0)
/* B6B30 80120430 10600008 */  beqz      $v1, .L80120454
/* B6B34 80120434 00061080 */   sll      $v0, $a2, 2
/* B6B38 80120438 14C00007 */  bnez      $a2, .L80120458
/* B6B3C 8012043C 00451021 */   addu     $v0, $v0, $a1
/* B6B40 80120440 0060202D */  daddu     $a0, $v1, $zero
/* B6B44 80120444 0C048108 */  jal       func_80120420
/* B6B48 80120448 0000302D */   daddu    $a2, $zero, $zero
/* B6B4C 8012044C 0804811A */  j         .L80120468
/* B6B50 80120450 00000000 */   nop
.L80120454:
/* B6B54 80120454 00451021 */  addu      $v0, $v0, $a1
.L80120458:
/* B6B58 80120458 AC4400E0 */  sw        $a0, 0xe0($v0)
/* B6B5C 8012045C 8C840018 */  lw        $a0, 0x18($a0)
/* B6B60 80120460 1480FFFD */  bnez      $a0, .L80120458
/* B6B64 80120464 24420004 */   addiu    $v0, $v0, 4
.L80120468:
/* B6B68 80120468 8FBF0010 */  lw        $ra, 0x10($sp)
/* B6B6C 8012046C 03E00008 */  jr        $ra
/* B6B70 80120470 27BD0018 */   addiu    $sp, $sp, 0x18
