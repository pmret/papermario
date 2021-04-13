.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057A78
/* 32E78 80057A78 28820002 */  slti      $v0, $a0, 2
/* 32E7C 80057A7C 10400005 */  beqz      $v0, .L80057A94
/* 32E80 80057A80 00000000 */   nop
/* 32E84 80057A84 3C01800A */  lui       $at, %hi(D_800A1E00)
/* 32E88 80057A88 AC201E00 */  sw        $zero, %lo(D_800A1E00)($at)
/* 32E8C 80057A8C 3C01800A */  lui       $at, %hi(D_800A1DFE)
/* 32E90 80057A90 A4201DFE */  sh        $zero, %lo(D_800A1DFE)($at)
.L80057A94:
/* 32E94 80057A94 3C03800A */  lui       $v1, %hi(D_800A1E00)
/* 32E98 80057A98 24631E00 */  addiu     $v1, $v1, %lo(D_800A1E00)
/* 32E9C 80057A9C 28820005 */  slti      $v0, $a0, 5
/* 32EA0 80057AA0 14400003 */  bnez      $v0, .L80057AB0
/* 32EA4 80057AA4 AC640000 */   sw       $a0, ($v1)
/* 32EA8 80057AA8 24020004 */  addiu     $v0, $zero, 4
/* 32EAC 80057AAC AC620000 */  sw        $v0, ($v1)
.L80057AB0:
/* 32EB0 80057AB0 03E00008 */  jr        $ra
/* 32EB4 80057AB4 00000000 */   nop
