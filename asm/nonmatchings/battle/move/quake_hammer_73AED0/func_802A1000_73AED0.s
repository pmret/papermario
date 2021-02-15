.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_73AED0
/* 73AED0 802A1000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 73AED4 802A1004 AFB00010 */  sw        $s0, 0x10($sp)
/* 73AED8 802A1008 0080802D */  daddu     $s0, $a0, $zero
/* 73AEDC 802A100C 2402000F */  addiu     $v0, $zero, 0xf
/* 73AEE0 802A1010 3C03800E */  lui       $v1, %hi(gBattleStatus+0x83)
/* 73AEE4 802A1014 8063C0F3 */  lb        $v1, %lo(gBattleStatus+0x83)($v1)
/* 73AEE8 802A1018 24040015 */  addiu     $a0, $zero, 0x15
/* 73AEEC 802A101C AFBF0014 */  sw        $ra, 0x14($sp)
/* 73AEF0 802A1020 AE020088 */  sw        $v0, 0x88($s0)
/* 73AEF4 802A1024 0C03A752 */  jal       is_ability_active
/* 73AEF8 802A1028 AE030084 */   sw       $v1, 0x84($s0)
/* 73AEFC 802A102C 10400003 */  beqz      $v0, .L802A103C
/* 73AF00 802A1030 24020028 */   addiu    $v0, $zero, 0x28
/* 73AF04 802A1034 AE000084 */  sw        $zero, 0x84($s0)
/* 73AF08 802A1038 AE020088 */  sw        $v0, 0x88($s0)
.L802A103C:
/* 73AF0C 802A103C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 73AF10 802A1040 8FB00010 */  lw        $s0, 0x10($sp)
/* 73AF14 802A1044 24020002 */  addiu     $v0, $zero, 2
/* 73AF18 802A1048 03E00008 */  jr        $ra
/* 73AF1C 802A104C 27BD0018 */   addiu    $sp, $sp, 0x18
