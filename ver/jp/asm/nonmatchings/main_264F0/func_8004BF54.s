.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004BF54
/* 27354 8004BF54 0000382D */  daddu     $a3, $zero, $zero
/* 27358 8004BF58 30A523FF */  andi      $a1, $a1, 0x23ff
/* 2735C 8004BF5C 3C0A8008 */  lui       $t2, %hi(D_80078434)
/* 27360 8004BF60 254A8434 */  addiu     $t2, $t2, %lo(D_80078434)
/* 27364 8004BF64 24090001 */  addiu     $t1, $zero, 1
/* 27368 8004BF68 24080001 */  addiu     $t0, $zero, 1
/* 2736C 8004BF6C 2406016C */  addiu     $a2, $zero, 0x16c
.L8004BF70:
/* 27370 8004BF70 00861821 */  addu      $v1, $a0, $a2
/* 27374 8004BF74 94620096 */  lhu       $v0, 0x96($v1)
/* 27378 8004BF78 14450008 */  bne       $v0, $a1, .L8004BF9C
/* 2737C 8004BF7C 24E70001 */   addiu    $a3, $a3, 1
/* 27380 8004BF80 AC6A0000 */  sw        $t2, ($v1)
/* 27384 8004BF84 AC600080 */  sw        $zero, 0x80($v1)
/* 27388 8004BF88 A069009A */  sb        $t1, 0x9a($v1)
/* 2738C 8004BF8C A06000A9 */  sb        $zero, 0xa9($v1)
/* 27390 8004BF90 A468008E */  sh        $t0, 0x8e($v1)
/* 27394 8004BF94 A0600098 */  sb        $zero, 0x98($v1)
/* 27398 8004BF98 A0600099 */  sb        $zero, 0x99($v1)
.L8004BF9C:
/* 2739C 8004BF9C 28E20008 */  slti      $v0, $a3, 8
/* 273A0 8004BFA0 1440FFF3 */  bnez      $v0, .L8004BF70
/* 273A4 8004BFA4 24C600AC */   addiu    $a2, $a2, 0xac
/* 273A8 8004BFA8 03E00008 */  jr        $ra
/* 273AC 8004BFAC 00000000 */   nop
