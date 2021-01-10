.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_752450
/* 752450 802A1000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 752454 802A1004 AFB00010 */  sw        $s0, 0x10($sp)
/* 752458 802A1008 0080802D */  daddu     $s0, $a0, $zero
/* 75245C 802A100C 2402000F */  addiu     $v0, $zero, 0xf
/* 752460 802A1010 3C03800E */  lui       $v1, %hi(gBattleStatus+0x83)
/* 752464 802A1014 8063C0F3 */  lb        $v1, %lo(gBattleStatus+0x83)($v1)
/* 752468 802A1018 24040015 */  addiu     $a0, $zero, 0x15
/* 75246C 802A101C AFBF0014 */  sw        $ra, 0x14($sp)
/* 752470 802A1020 AE020088 */  sw        $v0, 0x88($s0)
/* 752474 802A1024 0C03A752 */  jal       is_ability_active
/* 752478 802A1028 AE030084 */   sw       $v1, 0x84($s0)
/* 75247C 802A102C 10400003 */  beqz      $v0, .L802A103C
/* 752480 802A1030 24020028 */   addiu    $v0, $zero, 0x28
/* 752484 802A1034 AE000084 */  sw        $zero, 0x84($s0)
/* 752488 802A1038 AE020088 */  sw        $v0, 0x88($s0)
.L802A103C:
/* 75248C 802A103C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 752490 802A1040 8FB00010 */  lw        $s0, 0x10($sp)
/* 752494 802A1044 24020002 */  addiu     $v0, $zero, 2
/* 752498 802A1048 03E00008 */  jr        $ra
/* 75249C 802A104C 27BD0018 */   addiu    $sp, $sp, 0x18
