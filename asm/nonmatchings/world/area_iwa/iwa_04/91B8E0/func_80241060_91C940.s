.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241060_91C940
/* 91C940 80241060 3C013F80 */  lui       $at, 0x3f80
/* 91C944 80241064 44810000 */  mtc1      $at, $f0
/* 91C948 80241068 00000000 */  nop
/* 91C94C 8024106C 3C01800B */  lui       $at, %hi(D_800B2218)
/* 91C950 80241070 E4202218 */  swc1      $f0, %lo(D_800B2218)($at)
/* 91C954 80241074 03E00008 */  jr        $ra
/* 91C958 80241078 0000102D */   daddu    $v0, $zero, $zero
