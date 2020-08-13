.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osViSwapBuffer
/* 042420 80067020 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 042424 80067024 AFB00010 */  sw    $s0, 0x10($sp)
/* 042428 80067028 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04242C 8006702C 0C01ACD8 */  jal   __osDisableInt
/* 042430 80067030 00808021 */   addu  $s0, $a0, $zero
/* 042434 80067034 3C048009 */  lui   $a0, 0x8009
/* 042438 80067038 8C8459D4 */  lw    $a0, 0x59d4($a0)
/* 04243C 8006703C 94830000 */  lhu   $v1, ($a0)
/* 042440 80067040 AC900004 */  sw    $s0, 4($a0)
/* 042444 80067044 34630010 */  ori   $v1, $v1, 0x10
/* 042448 80067048 A4830000 */  sh    $v1, ($a0)
/* 04244C 8006704C 0C01ACF4 */  jal   __osRestoreInt
/* 042450 80067050 00402021 */   addu  $a0, $v0, $zero
/* 042454 80067054 8FBF0014 */  lw    $ra, 0x14($sp)
/* 042458 80067058 8FB00010 */  lw    $s0, 0x10($sp)
/* 04245C 8006705C 03E00008 */  jr    $ra
/* 042460 80067060 27BD0018 */   addiu $sp, $sp, 0x18

/* 042464 80067064 00000000 */  nop   
/* 042468 80067068 00000000 */  nop   
/* 04246C 8006706C 00000000 */  nop   


