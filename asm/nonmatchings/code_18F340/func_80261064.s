.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80261064
/* 18F944 80261064 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18F948 80261068 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 18F94C 8026106C 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 18F950 80261070 AFBF0014 */  sw        $ra, 0x14($sp)
/* 18F954 80261074 AFB00010 */  sw        $s0, 0x10($sp)
/* 18F958 80261078 8462017A */  lh        $v0, 0x17a($v1)
/* 18F95C 8026107C 8C6400D8 */  lw        $a0, 0xd8($v1)
/* 18F960 80261080 00021140 */  sll       $v0, $v0, 5
/* 18F964 80261084 3C108008 */  lui       $s0, %hi(gItemTable+0xC)
/* 18F968 80261088 02028021 */  addu      $s0, $s0, $v0
/* 18F96C 8026108C 861078EC */  lh        $s0, %lo(gItemTable+0xC)($s0)
/* 18F970 80261090 0C099CAB */  jal       heroes_is_ability_active
/* 18F974 80261094 2405001D */   addiu    $a1, $zero, 0x1d
/* 18F978 80261098 10400007 */  beqz      $v0, .L802610B8
/* 18F97C 8026109C 00000000 */   nop      
/* 18F980 802610A0 1A000005 */  blez      $s0, .L802610B8
/* 18F984 802610A4 00000000 */   nop      
/* 18F988 802610A8 3C04802A */  lui       $a0, %hi(D_8029FBA0)
/* 18F98C 802610AC 8C84FBA0 */  lw        $a0, %lo(D_8029FBA0)($a0)
/* 18F990 802610B0 0C05123D */  jal       free_icon
/* 18F994 802610B4 00000000 */   nop      
.L802610B8:
/* 18F998 802610B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 18F99C 802610BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 18F9A0 802610C0 24020002 */  addiu     $v0, $zero, 2
/* 18F9A4 802610C4 03E00008 */  jr        $ra
/* 18F9A8 802610C8 27BD0018 */   addiu    $sp, $sp, 0x18
