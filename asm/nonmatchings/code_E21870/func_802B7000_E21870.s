.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B7000_E21870
/* E21870 802B7000 3C048011 */  lui       $a0, %hi(D_8010EBB0)
/* E21874 802B7004 2484EBB0 */  addiu     $a0, $a0, %lo(D_8010EBB0)
/* E21878 802B7008 3C038011 */  lui       $v1, %hi(gPlayerActionState)
/* E2187C 802B700C 8063F07C */  lb        $v1, %lo(gPlayerActionState)($v1)
/* E21880 802B7010 2402001F */  addiu     $v0, $zero, 0x1f
/* E21884 802B7014 1062000B */  beq       $v1, $v0, .L802B7044
/* E21888 802B7018 24020001 */   addiu    $v0, $zero, 1
/* E2188C 802B701C 80830000 */  lb        $v1, ($a0)
/* E21890 802B7020 14620006 */  bne       $v1, $v0, .L802B703C
/* E21894 802B7024 24020009 */   addiu    $v0, $zero, 9
/* E21898 802B7028 80830003 */  lb        $v1, 3($a0)
/* E2189C 802B702C 10620005 */  beq       $v1, $v0, .L802B7044
/* E218A0 802B7030 24020004 */   addiu    $v0, $zero, 4
/* E218A4 802B7034 10620003 */  beq       $v1, $v0, .L802B7044
/* E218A8 802B7038 00000000 */   nop      
.L802B703C:
/* E218AC 802B703C 03E00008 */  jr        $ra
/* E218B0 802B7040 0000102D */   daddu    $v0, $zero, $zero
.L802B7044:
/* E218B4 802B7044 03E00008 */  jr        $ra
/* E218B8 802B7048 24020001 */   addiu    $v0, $zero, 1
