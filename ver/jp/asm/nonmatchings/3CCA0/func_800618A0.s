.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800618A0
/* 3CCA0 800618A0 3C088000 */  lui       $t0, 0x8000
/* 3CCA4 800618A4 240A2000 */  addiu     $t2, $zero, 0x2000
/* 3CCA8 800618A8 010A4821 */  addu      $t1, $t0, $t2
/* 3CCAC 800618AC 2529FFF0 */  addiu     $t1, $t1, -0x10
.L800618B0:
/* 3CCB0 800618B0 BD010000 */  cache     1, ($t0)
/* 3CCB4 800618B4 0109082B */  sltu      $at, $t0, $t1
/* 3CCB8 800618B8 1420FFFD */  bnez      $at, .L800618B0
/* 3CCBC 800618BC 25080010 */   addiu    $t0, $t0, 0x10
/* 3CCC0 800618C0 03E00008 */  jr        $ra
/* 3CCC4 800618C4 00000000 */   nop
/* 3CCC8 800618C8 00000000 */  nop
/* 3CCCC 800618CC 00000000 */  nop
