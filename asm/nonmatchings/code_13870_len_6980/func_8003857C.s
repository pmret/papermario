.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003857C
/* 1397C 8003857C 0000182D */  daddu     $v1, $zero, $zero
/* 13980 80038580 24630001 */  addiu     $v1, $v1, 1
.L80038584:
/* 13984 80038584 28620040 */  slti      $v0, $v1, 0x40
/* 13988 80038588 1440FFFE */  bnez      $v0, .L80038584
/* 1398C 8003858C 24630001 */   addiu    $v1, $v1, 1
/* 13990 80038590 03E00008 */  jr        $ra
/* 13994 80038594 00000000 */   nop
