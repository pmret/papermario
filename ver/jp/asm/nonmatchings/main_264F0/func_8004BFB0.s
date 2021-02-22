.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004BFB0
/* 273B0 8004BFB0 0000382D */  daddu     $a3, $zero, $zero
/* 273B4 8004BFB4 3C0A8008 */  lui       $t2, %hi(D_80078434)
/* 273B8 8004BFB8 254A8434 */  addiu     $t2, $t2, %lo(D_80078434)
/* 273BC 8004BFBC 24090001 */  addiu     $t1, $zero, 1
/* 273C0 8004BFC0 24080001 */  addiu     $t0, $zero, 1
/* 273C4 8004BFC4 2406016C */  addiu     $a2, $zero, 0x16c
.L8004BFC8:
/* 273C8 8004BFC8 00861821 */  addu      $v1, $a0, $a2
/* 273CC 8004BFCC 90620099 */  lbu       $v0, 0x99($v1)
/* 273D0 8004BFD0 14A20008 */  bne       $a1, $v0, .L8004BFF4
/* 273D4 8004BFD4 24E70001 */   addiu    $a3, $a3, 1
/* 273D8 8004BFD8 AC6A0000 */  sw        $t2, ($v1)
/* 273DC 8004BFDC AC600080 */  sw        $zero, 0x80($v1)
/* 273E0 8004BFE0 A069009A */  sb        $t1, 0x9a($v1)
/* 273E4 8004BFE4 A06000A9 */  sb        $zero, 0xa9($v1)
/* 273E8 8004BFE8 A468008E */  sh        $t0, 0x8e($v1)
/* 273EC 8004BFEC A0600098 */  sb        $zero, 0x98($v1)
/* 273F0 8004BFF0 A0600099 */  sb        $zero, 0x99($v1)
.L8004BFF4:
/* 273F4 8004BFF4 28E20008 */  slti      $v0, $a3, 8
/* 273F8 8004BFF8 1440FFF3 */  bnez      $v0, .L8004BFC8
/* 273FC 8004BFFC 24C600AC */   addiu    $a2, $a2, 0xac
/* 27400 8004C000 03E00008 */  jr        $ra
/* 27404 8004C004 00000000 */   nop
