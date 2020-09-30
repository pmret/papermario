.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSpTaskYielded
/* 41070 80065C70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41074 80065C74 AFB00010 */  sw        $s0, 0x10($sp)
/* 41078 80065C78 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4107C 80065C7C 0C01B1B8 */  jal       osSpGetStatus
/* 41080 80065C80 00808021 */   addu     $s0, $a0, $zero
/* 41084 80065C84 00022202 */  srl       $a0, $v0, 8
/* 41088 80065C88 30420080 */  andi      $v0, $v0, 0x80
/* 4108C 80065C8C 10400006 */  beqz      $v0, .L80065CA8
/* 41090 80065C90 30840001 */   andi     $a0, $a0, 1
/* 41094 80065C94 8E020004 */  lw        $v0, 4($s0)
/* 41098 80065C98 2403FFFD */  addiu     $v1, $zero, -3
/* 4109C 80065C9C 00441025 */  or        $v0, $v0, $a0
/* 410A0 80065CA0 00431024 */  and       $v0, $v0, $v1
/* 410A4 80065CA4 AE020004 */  sw        $v0, 4($s0)
.L80065CA8:
/* 410A8 80065CA8 00801021 */  addu      $v0, $a0, $zero
/* 410AC 80065CAC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 410B0 80065CB0 8FB00010 */  lw        $s0, 0x10($sp)
/* 410B4 80065CB4 03E00008 */  jr        $ra
/* 410B8 80065CB8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 410BC 80065CBC 00000000 */  nop       
