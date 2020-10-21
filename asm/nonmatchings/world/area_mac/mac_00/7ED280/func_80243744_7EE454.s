.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243744_7EE454
/* 7EE454 80243744 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EE458 80243748 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EE45C 8024374C 10A00003 */  beqz      $a1, .L8024375C
/* 7EE460 80243750 8C86000C */   lw       $a2, 0xc($a0)
/* 7EE464 80243754 3C018025 */  lui       $at, 0x8025
/* 7EE468 80243758 AC20ED4C */  sw        $zero, -0x12b4($at)
.L8024375C:
/* 7EE46C 8024375C 3C038025 */  lui       $v1, 0x8025
/* 7EE470 80243760 2463ED4C */  addiu     $v1, $v1, -0x12b4
/* 7EE474 80243764 8C620000 */  lw        $v0, ($v1)
/* 7EE478 80243768 54400003 */  bnel      $v0, $zero, .L80243778
/* 7EE47C 8024376C AC600000 */   sw       $zero, ($v1)
/* 7EE480 80243770 08090DE3 */  j         .L8024378C
/* 7EE484 80243774 0000102D */   daddu    $v0, $zero, $zero
.L80243778:
/* 7EE488 80243778 8CC50000 */  lw        $a1, ($a2)
/* 7EE48C 8024377C 3C068025 */  lui       $a2, 0x8025
/* 7EE490 80243780 0C0B2026 */  jal       set_variable
/* 7EE494 80243784 8CC6ED50 */   lw       $a2, -0x12b0($a2)
/* 7EE498 80243788 24020002 */  addiu     $v0, $zero, 2
.L8024378C:
/* 7EE49C 8024378C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EE4A0 80243790 03E00008 */  jr        $ra
/* 7EE4A4 80243794 27BD0018 */   addiu    $sp, $sp, 0x18
