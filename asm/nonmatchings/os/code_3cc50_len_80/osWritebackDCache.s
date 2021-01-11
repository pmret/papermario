.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osWritebackDCache
/* 3CC50 80061850 18A00011 */  blez      $a1, .L80061898
/* 3CC54 80061854 00000000 */   nop
/* 3CC58 80061858 240B2000 */  addiu     $t3, $zero, 0x2000
/* 3CC5C 8006185C 00AB082B */  sltu      $at, $a1, $t3
/* 3CC60 80061860 1020000F */  beqz      $at, .L800618A0
/* 3CC64 80061864 00000000 */   nop
/* 3CC68 80061868 00804021 */  addu      $t0, $a0, $zero
/* 3CC6C 8006186C 00854821 */  addu      $t1, $a0, $a1
/* 3CC70 80061870 0109082B */  sltu      $at, $t0, $t1
/* 3CC74 80061874 10200008 */  beqz      $at, .L80061898
/* 3CC78 80061878 00000000 */   nop
/* 3CC7C 8006187C 2529FFF0 */  addiu     $t1, $t1, -0x10
/* 3CC80 80061880 310A000F */  andi      $t2, $t0, 0xf
/* 3CC84 80061884 010A4023 */  subu      $t0, $t0, $t2
.L80061888:
/* 3CC88 80061888 BD190000 */  cache     0x19, ($t0)
/* 3CC8C 8006188C 0109082B */  sltu      $at, $t0, $t1
/* 3CC90 80061890 1420FFFD */  bnez      $at, .L80061888
/* 3CC94 80061894 25080010 */   addiu    $t0, $t0, 0x10
.L80061898:
/* 3CC98 80061898 03E00008 */  jr        $ra
/* 3CC9C 8006189C 00000000 */   nop
.L800618A0:
/* 3CCA0 800618A0 3C088000 */  lui       $t0, 0x8000
/* 3CCA4 800618A4 010B4821 */  addu      $t1, $t0, $t3
/* 3CCA8 800618A8 2529FFF0 */  addiu     $t1, $t1, -0x10
.L800618AC:
/* 3CCAC 800618AC BD010000 */  cache     1, ($t0)
/* 3CCB0 800618B0 0109082B */  sltu      $at, $t0, $t1
/* 3CCB4 800618B4 1420FFFD */  bnez      $at, .L800618AC
/* 3CCB8 800618B8 25080010 */   addiu    $t0, $t0, 0x10
/* 3CCBC 800618BC 03E00008 */  jr        $ra
/* 3CCC0 800618C0 00000000 */   nop
/* 3CCC4 800618C4 00000000 */  nop
/* 3CCC8 800618C8 00000000 */  nop
/* 3CCCC 800618CC 00000000 */  nop
