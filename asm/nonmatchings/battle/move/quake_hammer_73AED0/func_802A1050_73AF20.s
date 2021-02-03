.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1050_73AF20
/* 73AF20 802A1050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 73AF24 802A1054 AFB00010 */  sw        $s0, 0x10($sp)
/* 73AF28 802A1058 0080802D */  daddu     $s0, $a0, $zero
/* 73AF2C 802A105C 24040016 */  addiu     $a0, $zero, 0x16
/* 73AF30 802A1060 AFBF0014 */  sw        $ra, 0x14($sp)
/* 73AF34 802A1064 0C03A752 */  jal       is_ability_active
/* 73AF38 802A1068 AE000084 */   sw       $zero, 0x84($s0)
/* 73AF3C 802A106C 10400002 */  beqz      $v0, .L802A1078
/* 73AF40 802A1070 24020001 */   addiu    $v0, $zero, 1
/* 73AF44 802A1074 AE020084 */  sw        $v0, 0x84($s0)
.L802A1078:
/* 73AF48 802A1078 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 73AF4C 802A107C 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 73AF50 802A1080 30421000 */  andi      $v0, $v0, 0x1000
/* 73AF54 802A1084 10400002 */  beqz      $v0, .L802A1090
/* 73AF58 802A1088 24020001 */   addiu    $v0, $zero, 1
/* 73AF5C 802A108C AE020084 */  sw        $v0, 0x84($s0)
.L802A1090:
/* 73AF60 802A1090 8FBF0014 */  lw        $ra, 0x14($sp)
/* 73AF64 802A1094 8FB00010 */  lw        $s0, 0x10($sp)
/* 73AF68 802A1098 24020002 */  addiu     $v0, $zero, 2
/* 73AF6C 802A109C 03E00008 */  jr        $ra
