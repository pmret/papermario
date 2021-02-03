.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_7345A0
/* 7345A0 802A1000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7345A4 802A1004 AFB00010 */  sw        $s0, 0x10($sp)
/* 7345A8 802A1008 0080802D */  daddu     $s0, $a0, $zero
/* 7345AC 802A100C 2402000F */  addiu     $v0, $zero, 0xf
/* 7345B0 802A1010 3C03800E */  lui       $v1, %hi(gBattleStatus+0x83)
/* 7345B4 802A1014 8063C0F3 */  lb        $v1, %lo(gBattleStatus+0x83)($v1)
/* 7345B8 802A1018 24040015 */  addiu     $a0, $zero, 0x15
/* 7345BC 802A101C AFBF0014 */  sw        $ra, 0x14($sp)
/* 7345C0 802A1020 AE020088 */  sw        $v0, 0x88($s0)
/* 7345C4 802A1024 0C03A752 */  jal       is_ability_active
/* 7345C8 802A1028 AE030084 */   sw       $v1, 0x84($s0)
/* 7345CC 802A102C 10400003 */  beqz      $v0, .L802A103C
/* 7345D0 802A1030 24020028 */   addiu    $v0, $zero, 0x28
/* 7345D4 802A1034 AE000084 */  sw        $zero, 0x84($s0)
/* 7345D8 802A1038 AE020088 */  sw        $v0, 0x88($s0)
.L802A103C:
/* 7345DC 802A103C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7345E0 802A1040 8FB00010 */  lw        $s0, 0x10($sp)
/* 7345E4 802A1044 24020002 */  addiu     $v0, $zero, 2
/* 7345E8 802A1048 03E00008 */  jr        $ra
/* 7345EC 802A104C 27BD0018 */   addiu    $sp, $sp, 0x18
