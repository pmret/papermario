.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1050_77CBD0
/* 77CBD0 802A1050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 77CBD4 802A1054 AFB00010 */  sw        $s0, 0x10($sp)
/* 77CBD8 802A1058 0080802D */  daddu     $s0, $a0, $zero
/* 77CBDC 802A105C 24040016 */  addiu     $a0, $zero, 0x16
/* 77CBE0 802A1060 AFBF0014 */  sw        $ra, 0x14($sp)
/* 77CBE4 802A1064 0C03A752 */  jal       is_ability_active
/* 77CBE8 802A1068 AE000084 */   sw       $zero, 0x84($s0)
/* 77CBEC 802A106C 10400002 */  beqz      $v0, .L802A1078
/* 77CBF0 802A1070 24020001 */   addiu    $v0, $zero, 1
/* 77CBF4 802A1074 AE020084 */  sw        $v0, 0x84($s0)
.L802A1078:
/* 77CBF8 802A1078 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 77CBFC 802A107C 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 77CC00 802A1080 30421000 */  andi      $v0, $v0, 0x1000
/* 77CC04 802A1084 10400002 */  beqz      $v0, .L802A1090
/* 77CC08 802A1088 24020001 */   addiu    $v0, $zero, 1
/* 77CC0C 802A108C AE020084 */  sw        $v0, 0x84($s0)
.L802A1090:
/* 77CC10 802A1090 8FBF0014 */  lw        $ra, 0x14($sp)
/* 77CC14 802A1094 8FB00010 */  lw        $s0, 0x10($sp)
/* 77CC18 802A1098 24020002 */  addiu     $v0, $zero, 2
/* 77CC1C 802A109C 03E00008 */  jr        $ra
