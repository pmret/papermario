.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006B530
/* 46930 8006B530 3C038009 */  lui       $v1, %hi(D_80093D30)
/* 46934 8006B534 8C633D30 */  lw        $v1, %lo(D_80093D30)($v1)
/* 46938 8006B538 10600003 */  beqz      $v1, .L8006B548
/* 4693C 8006B53C 00001021 */   addu     $v0, $zero, $zero
/* 46940 8006B540 3C028009 */  lui       $v0, %hi(D_80093D38)
/* 46944 8006B544 8C423D38 */  lw        $v0, %lo(D_80093D38)($v0)
.L8006B548:
/* 46948 8006B548 03E00008 */  jr        $ra
/* 4694C 8006B54C 00000000 */   nop
