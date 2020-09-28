.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80028F8C
/* 438C 80028F8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4390 80028F90 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 4394 80028F94 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 4398 80028F98 3C048007 */  lui       $a0, 0x8007
/* 439C 80028F9C 24844264 */  addiu     $a0, $a0, 0x4264
/* 43A0 80028FA0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 43A4 80028FA4 8C830000 */  lw        $v1, ($a0)
/* 43A8 80028FA8 8C420000 */  lw        $v0, ($v0)
/* 43AC 80028FAC 10620003 */  beq       $v1, $v0, .L80028FBC
/* 43B0 80028FB0 00000000 */   nop      
/* 43B4 80028FB4 0C00A3F8 */  jal       func_80028FE0
/* 43B8 80028FB8 AC820000 */   sw       $v0, ($a0)
.L80028FBC:
/* 43BC 80028FBC 3C038007 */  lui       $v1, 0x8007
/* 43C0 80028FC0 24634260 */  addiu     $v1, $v1, 0x4260
/* 43C4 80028FC4 94620000 */  lhu       $v0, ($v1)
/* 43C8 80028FC8 10400002 */  beqz      $v0, .L80028FD4
/* 43CC 80028FCC 2442FFFF */   addiu    $v0, $v0, -1
/* 43D0 80028FD0 A4620000 */  sh        $v0, ($v1)
.L80028FD4:
/* 43D4 80028FD4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 43D8 80028FD8 03E00008 */  jr        $ra
/* 43DC 80028FDC 27BD0018 */   addiu    $sp, $sp, 0x18
