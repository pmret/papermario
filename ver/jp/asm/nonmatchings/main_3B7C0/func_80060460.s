.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060460
/* 3B860 80060460 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3B864 80060464 AFB10014 */  sw        $s1, 0x14($sp)
/* 3B868 80060468 3C118009 */  lui       $s1, %hi(D_80093CF0)
/* 3B86C 8006046C 26313CF0 */  addiu     $s1, $s1, %lo(D_80093CF0)
/* 3B870 80060470 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3B874 80060474 AFB00010 */  sw        $s0, 0x10($sp)
/* 3B878 80060478 8E220000 */  lw        $v0, ($s1)
/* 3B87C 8006047C 10400011 */  beqz      $v0, .L800604C4
/* 3B880 80060480 00000000 */   nop
.L80060484:
/* 3B884 80060484 8E220000 */  lw        $v0, ($s1)
/* 3B888 80060488 8C500000 */  lw        $s0, ($v0)
/* 3B88C 8006048C 1604000B */  bne       $s0, $a0, .L800604BC
/* 3B890 80060490 00000000 */   nop
/* 3B894 80060494 0C018244 */  jal       func_80060910
/* 3B898 80060498 24040001 */   addiu    $a0, $zero, 1
/* 3B89C 8006049C 8E250000 */  lw        $a1, ($s1)
/* 3B8A0 800604A0 8E030000 */  lw        $v1, ($s0)
/* 3B8A4 800604A4 0040202D */  daddu     $a0, $v0, $zero
/* 3B8A8 800604A8 ACA30000 */  sw        $v1, ($a1)
/* 3B8AC 800604AC 0C018244 */  jal       func_80060910
/* 3B8B0 800604B0 AE000000 */   sw       $zero, ($s0)
/* 3B8B4 800604B4 08018131 */  j         .L800604C4
/* 3B8B8 800604B8 00000000 */   nop
.L800604BC:
/* 3B8BC 800604BC 1600FFF1 */  bnez      $s0, .L80060484
/* 3B8C0 800604C0 0040882D */   daddu    $s1, $v0, $zero
.L800604C4:
/* 3B8C4 800604C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3B8C8 800604C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 3B8CC 800604CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3B8D0 800604D0 03E00008 */  jr        $ra
/* 3B8D4 800604D4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3B8D8 800604D8 00000000 */  nop
/* 3B8DC 800604DC 00000000 */  nop
