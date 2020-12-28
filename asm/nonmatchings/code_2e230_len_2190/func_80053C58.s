.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053C58
/* 2F058 80053C58 3C03800A */  lui       $v1, %hi(D_8009A5C0)
/* 2F05C 80053C5C 8C63A5C0 */  lw        $v1, %lo(D_8009A5C0)($v1)
/* 2F060 80053C60 24020001 */  addiu     $v0, $zero, 1
/* 2F064 80053C64 1082000B */  beq       $a0, $v0, .L80053C94
/* 2F068 80053C68 00000000 */   nop      
/* 2F06C 80053C6C 10800003 */  beqz      $a0, .L80053C7C
/* 2F070 80053C70 24020002 */   addiu    $v0, $zero, 2
/* 2F074 80053C74 5482000D */  bnel      $a0, $v0, .L80053CAC
/* 2F078 80053C78 ACA00000 */   sw       $zero, ($a1)
.L80053C7C:
/* 2F07C 80053C7C 8C62005C */  lw        $v0, 0x5c($v1)
/* 2F080 80053C80 ACA20000 */  sw        $v0, ($a1)
/* 2F084 80053C84 3C02800A */  lui       $v0, %hi(D_8009A664)
/* 2F088 80053C88 8C42A664 */  lw        $v0, %lo(D_8009A664)($v0)
/* 2F08C 80053C8C 03E00008 */  jr        $ra
/* 2F090 80053C90 ACC20000 */   sw       $v0, ($a2)
.L80053C94:
/* 2F094 80053C94 8C620060 */  lw        $v0, 0x60($v1)
/* 2F098 80053C98 ACA20000 */  sw        $v0, ($a1)
/* 2F09C 80053C9C 3C02800A */  lui       $v0, %hi(D_8009A5FC)
/* 2F0A0 80053CA0 8C42A5FC */  lw        $v0, %lo(D_8009A5FC)($v0)
/* 2F0A4 80053CA4 03E00008 */  jr        $ra
/* 2F0A8 80053CA8 ACC20000 */   sw       $v0, ($a2)
.L80053CAC:
/* 2F0AC 80053CAC 03E00008 */  jr        $ra
/* 2F0B0 80053CB0 ACC00000 */   sw       $zero, ($a2)
