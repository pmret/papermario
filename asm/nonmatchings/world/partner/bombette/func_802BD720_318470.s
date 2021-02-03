.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD720_318470
/* 318470 802BD720 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 318474 802BD724 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* 318478 802BD728 10400005 */  beqz      $v0, .L802BD740
/* 31847C 802BD72C 24020001 */   addiu    $v0, $zero, 1
/* 318480 802BD730 3C01802C */  lui       $at, %hi(D_802BE934)
/* 318484 802BD734 AC22E934 */  sw        $v0, %lo(D_802BE934)($at)
/* 318488 802BD738 03E00008 */  jr        $ra
/* 31848C 802BD73C 0000102D */   daddu    $v0, $zero, $zero
.L802BD740:
/* 318490 802BD740 03E00008 */  jr        $ra
/* 318494 802BD744 00000000 */   nop
