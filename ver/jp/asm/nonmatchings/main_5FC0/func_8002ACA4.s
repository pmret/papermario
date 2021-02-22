.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002ACA4
/* 60A4 8002ACA4 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 60A8 8002ACA8 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 60AC 8002ACAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 60B0 8002ACB0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 60B4 8002ACB4 80420070 */  lb        $v0, 0x70($v0)
/* 60B8 8002ACB8 10400007 */  beqz      $v0, .L8002ACD8
/* 60BC 8002ACBC 0080282D */   daddu    $a1, $a0, $zero
/* 60C0 8002ACC0 3C04803E */  lui       $a0, %hi(D_803DA800)
/* 60C4 8002ACC4 2484A800 */  addiu     $a0, $a0, %lo(D_803DA800)
/* 60C8 8002ACC8 0C00A40B */  jal       func_8002902C
/* 60CC 8002ACCC 00000000 */   nop
/* 60D0 8002ACD0 0800AB38 */  j         .L8002ACE0
/* 60D4 8002ACD4 00000000 */   nop
.L8002ACD8:
/* 60D8 8002ACD8 0C00AAFA */  jal       func_8002ABE8
/* 60DC 8002ACDC 00A0202D */   daddu    $a0, $a1, $zero
.L8002ACE0:
/* 60E0 8002ACE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 60E4 8002ACE4 03E00008 */  jr        $ra
/* 60E8 8002ACE8 27BD0018 */   addiu    $sp, $sp, 0x18
