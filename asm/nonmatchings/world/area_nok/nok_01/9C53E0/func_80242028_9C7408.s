.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242028_9C7408
/* 9C7408 80242028 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C740C 8024202C AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7410 80242030 10A00003 */  beqz      $a1, .L80242040
/* 9C7414 80242034 8C86000C */   lw       $a2, 0xc($a0)
/* 9C7418 80242038 3C018025 */  lui       $at, %hi(D_8024856C)
/* 9C741C 8024203C AC20856C */  sw        $zero, %lo(D_8024856C)($at)
.L80242040:
/* 9C7420 80242040 3C038025 */  lui       $v1, %hi(D_8024856C)
/* 9C7424 80242044 2463856C */  addiu     $v1, $v1, %lo(D_8024856C)
/* 9C7428 80242048 8C620000 */  lw        $v0, ($v1)
/* 9C742C 8024204C 54400003 */  bnel      $v0, $zero, .L8024205C
/* 9C7430 80242050 AC600000 */   sw       $zero, ($v1)
/* 9C7434 80242054 0809081C */  j         .L80242070
/* 9C7438 80242058 0000102D */   daddu    $v0, $zero, $zero
.L8024205C:
/* 9C743C 8024205C 8CC50000 */  lw        $a1, ($a2)
/* 9C7440 80242060 3C068025 */  lui       $a2, %hi(D_80248570)
/* 9C7444 80242064 0C0B2026 */  jal       set_variable
/* 9C7448 80242068 8CC68570 */   lw       $a2, %lo(D_80248570)($a2)
/* 9C744C 8024206C 24020002 */  addiu     $v0, $zero, 2
.L80242070:
/* 9C7450 80242070 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7454 80242074 03E00008 */  jr        $ra
/* 9C7458 80242078 27BD0018 */   addiu    $sp, $sp, 0x18
