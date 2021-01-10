.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1050_759600
/* 759600 802A1050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 759604 802A1054 AFB00010 */  sw        $s0, 0x10($sp)
/* 759608 802A1058 0080802D */  daddu     $s0, $a0, $zero
/* 75960C 802A105C 24040016 */  addiu     $a0, $zero, 0x16
/* 759610 802A1060 AFBF0014 */  sw        $ra, 0x14($sp)
/* 759614 802A1064 0C03A752 */  jal       is_ability_active
/* 759618 802A1068 AE000084 */   sw       $zero, 0x84($s0)
/* 75961C 802A106C 10400002 */  beqz      $v0, .L802A1078
/* 759620 802A1070 24020001 */   addiu    $v0, $zero, 1
/* 759624 802A1074 AE020084 */  sw        $v0, 0x84($s0)
.L802A1078:
/* 759628 802A1078 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 75962C 802A107C 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 759630 802A1080 30421000 */  andi      $v0, $v0, 0x1000
/* 759634 802A1084 10400002 */  beqz      $v0, .L802A1090
/* 759638 802A1088 24020001 */   addiu    $v0, $zero, 1
/* 75963C 802A108C AE020084 */  sw        $v0, 0x84($s0)
.L802A1090:
/* 759640 802A1090 8FBF0014 */  lw        $ra, 0x14($sp)
/* 759644 802A1094 8FB00010 */  lw        $s0, 0x10($sp)
/* 759648 802A1098 24020002 */  addiu     $v0, $zero, 2
/* 75964C 802A109C 03E00008 */  jr        $ra
/* 759650 802A10A0 27BD0018 */   addiu    $sp, $sp, 0x18
