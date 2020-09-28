.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004DAA8
/* 28EA8 8004DAA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 28EAC 8004DAAC AFBF0010 */  sw        $ra, 0x10($sp)
/* 28EB0 8004DAB0 90820221 */  lbu       $v0, 0x221($a0)
/* 28EB4 8004DAB4 10400007 */  beqz      $v0, .L8004DAD4
/* 28EB8 8004DAB8 24020004 */   addiu    $v0, $zero, 4
/* 28EBC 8004DABC A0820221 */  sb        $v0, 0x221($a0)
/* 28EC0 8004DAC0 24020001 */  addiu     $v0, $zero, 1
/* 28EC4 8004DAC4 AC820010 */  sw        $v0, 0x10($a0)
/* 28EC8 8004DAC8 AC820008 */  sw        $v0, 8($a0)
/* 28ECC 8004DACC 0C014E86 */  jal       func_80053A18
/* 28ED0 8004DAD0 2484002C */   addiu    $a0, $a0, 0x2c
.L8004DAD4:
/* 28ED4 8004DAD4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 28ED8 8004DAD8 03E00008 */  jr        $ra
/* 28EDC 8004DADC 27BD0018 */   addiu    $sp, $sp, 0x18
