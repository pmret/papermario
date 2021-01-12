.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_767C90
/* 767C90 802A1000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 767C94 802A1004 AFB00010 */  sw        $s0, 0x10($sp)
/* 767C98 802A1008 0080802D */  daddu     $s0, $a0, $zero
/* 767C9C 802A100C 2402000F */  addiu     $v0, $zero, 0xf
/* 767CA0 802A1010 3C03800E */  lui       $v1, %hi(gBattleStatus+0x83)
/* 767CA4 802A1014 8063C0F3 */  lb        $v1, %lo(gBattleStatus+0x83)($v1)
/* 767CA8 802A1018 24040015 */  addiu     $a0, $zero, 0x15
/* 767CAC 802A101C AFBF0014 */  sw        $ra, 0x14($sp)
/* 767CB0 802A1020 AE020088 */  sw        $v0, 0x88($s0)
/* 767CB4 802A1024 0C03A752 */  jal       is_ability_active
/* 767CB8 802A1028 AE030084 */   sw       $v1, 0x84($s0)
/* 767CBC 802A102C 10400003 */  beqz      $v0, .L802A103C
/* 767CC0 802A1030 24020028 */   addiu    $v0, $zero, 0x28
/* 767CC4 802A1034 AE000084 */  sw        $zero, 0x84($s0)
/* 767CC8 802A1038 AE020088 */  sw        $v0, 0x88($s0)
.L802A103C:
/* 767CCC 802A103C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 767CD0 802A1040 8FB00010 */  lw        $s0, 0x10($sp)
/* 767CD4 802A1044 24020002 */  addiu     $v0, $zero, 2
/* 767CD8 802A1048 03E00008 */  jr        $ra
/* 767CDC 802A104C 27BD0018 */   addiu    $sp, $sp, 0x18
