.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065C40
/* 41040 80065C40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41044 80065C44 AFB00010 */  sw        $s0, 0x10($sp)
/* 41048 80065C48 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4104C 80065C4C 0C01B1B0 */  jal       func_8006C6C0
/* 41050 80065C50 00808021 */   addu     $s0, $a0, $zero
/* 41054 80065C54 00022202 */  srl       $a0, $v0, 8
/* 41058 80065C58 30420080 */  andi      $v0, $v0, 0x80
/* 4105C 80065C5C 10400006 */  beqz      $v0, .L80065C78
/* 41060 80065C60 30840001 */   andi     $a0, $a0, 1
/* 41064 80065C64 8E020004 */  lw        $v0, 4($s0)
/* 41068 80065C68 2403FFFD */  addiu     $v1, $zero, -3
/* 4106C 80065C6C 00441025 */  or        $v0, $v0, $a0
/* 41070 80065C70 00431024 */  and       $v0, $v0, $v1
/* 41074 80065C74 AE020004 */  sw        $v0, 4($s0)
.L80065C78:
/* 41078 80065C78 00801021 */  addu      $v0, $a0, $zero
/* 4107C 80065C7C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 41080 80065C80 8FB00010 */  lw        $s0, 0x10($sp)
/* 41084 80065C84 03E00008 */  jr        $ra
/* 41088 80065C88 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4108C 80065C8C 00000000 */  nop
