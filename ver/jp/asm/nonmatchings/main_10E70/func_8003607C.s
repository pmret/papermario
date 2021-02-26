.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003607C
/* 1147C 8003607C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 11480 80036080 3C03800A */  lui       $v1, %hi(D_8009E754)
/* 11484 80036084 8463E754 */  lh        $v1, %lo(D_8009E754)($v1)
/* 11488 80036088 24020004 */  addiu     $v0, $zero, 4
/* 1148C 8003608C 10620003 */  beq       $v1, $v0, .L8003609C
/* 11490 80036090 AFBF0010 */   sw       $ra, 0x10($sp)
/* 11494 80036094 14600003 */  bnez      $v1, .L800360A4
/* 11498 80036098 00000000 */   nop
.L8003609C:
/* 1149C 8003609C 0C03A5B7 */  jal       func_800E96DC
/* 114A0 800360A0 00000000 */   nop
.L800360A4:
/* 114A4 800360A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 114A8 800360A8 03E00008 */  jr        $ra
/* 114AC 800360AC 27BD0018 */   addiu    $sp, $sp, 0x18
