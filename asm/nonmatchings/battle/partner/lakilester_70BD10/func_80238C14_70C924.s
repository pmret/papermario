.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238C14_70C924
/* 70C924 80238C14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 70C928 80238C18 AFB00010 */  sw        $s0, 0x10($sp)
/* 70C92C 80238C1C 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 70C930 80238C20 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 70C934 80238C24 AFBF0014 */  sw        $ra, 0x14($sp)
/* 70C938 80238C28 8E0400A8 */  lw        $a0, 0xa8($s0)
/* 70C93C 80238C2C 10800006 */  beqz      $a0, .L80238C48
/* 70C940 80238C30 24020002 */   addiu    $v0, $zero, 2
/* 70C944 80238C34 0C016914 */  jal       remove_effect
/* 70C948 80238C38 00000000 */   nop
/* 70C94C 80238C3C 24020002 */  addiu     $v0, $zero, 2
/* 70C950 80238C40 AE0000A8 */  sw        $zero, 0xa8($s0)
/* 70C954 80238C44 A20000A4 */  sb        $zero, 0xa4($s0)
.L80238C48:
/* 70C958 80238C48 8FBF0014 */  lw        $ra, 0x14($sp)
/* 70C95C 80238C4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 70C960 80238C50 03E00008 */  jr        $ra
/* 70C964 80238C54 27BD0018 */   addiu    $sp, $sp, 0x18
