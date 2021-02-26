.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80028F4C
/* 434C 80028F4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4350 80028F50 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 4354 80028F54 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 4358 80028F58 3C048007 */  lui       $a0, %hi(D_80074244)
/* 435C 80028F5C 24844244 */  addiu     $a0, $a0, %lo(D_80074244)
/* 4360 80028F60 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4364 80028F64 8C830000 */  lw        $v1, ($a0)
/* 4368 80028F68 8C420000 */  lw        $v0, ($v0)
/* 436C 80028F6C 10620003 */  beq       $v1, $v0, .L80028F7C
/* 4370 80028F70 00000000 */   nop
/* 4374 80028F74 0C00A3E8 */  jal       func_80028FA0
/* 4378 80028F78 AC820000 */   sw       $v0, ($a0)
.L80028F7C:
/* 437C 80028F7C 3C038007 */  lui       $v1, %hi(D_80074240)
/* 4380 80028F80 24634240 */  addiu     $v1, $v1, %lo(D_80074240)
/* 4384 80028F84 94620000 */  lhu       $v0, ($v1)
/* 4388 80028F88 10400002 */  beqz      $v0, .L80028F94
/* 438C 80028F8C 2442FFFF */   addiu    $v0, $v0, -1
/* 4390 80028F90 A4620000 */  sh        $v0, ($v1)
.L80028F94:
/* 4394 80028F94 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4398 80028F98 03E00008 */  jr        $ra
/* 439C 80028F9C 27BD0018 */   addiu    $sp, $sp, 0x18
