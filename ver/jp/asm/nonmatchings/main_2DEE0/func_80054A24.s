.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054A24
/* 2FE24 80054A24 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2FE28 80054A28 30840010 */  andi      $a0, $a0, 0x10
/* 2FE2C 80054A2C 14800003 */  bnez      $a0, .L80054A3C
/* 2FE30 80054A30 AFBF0010 */   sw       $ra, 0x10($sp)
/* 2FE34 80054A34 08015293 */  j         .L80054A4C
/* 2FE38 80054A38 0000102D */   daddu    $v0, $zero, $zero
.L80054A3C:
/* 2FE3C 80054A3C 3C04800A */  lui       $a0, %hi(D_8009A620)
/* 2FE40 80054A40 8C84A620 */  lw        $a0, %lo(D_8009A620)($a0)
/* 2FE44 80054A44 0C012DA5 */  jal       func_8004B694
/* 2FE48 80054A48 00000000 */   nop
.L80054A4C:
/* 2FE4C 80054A4C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2FE50 80054A50 03E00008 */  jr        $ra
/* 2FE54 80054A54 27BD0018 */   addiu    $sp, $sp, 0x18
