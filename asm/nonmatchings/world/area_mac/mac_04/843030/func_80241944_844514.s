.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241944_844514
/* 844514 80241944 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 844518 80241948 AFBF0010 */  sw        $ra, 0x10($sp)
/* 84451C 8024194C 0C03A876 */  jal       set_max_SP
/* 844520 80241950 24040004 */   addiu    $a0, $zero, 4
/* 844524 80241954 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 844528 80241958 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 84452C 8024195C 90430003 */  lbu       $v1, 3($v0)
/* 844530 80241960 90440006 */  lbu       $a0, 6($v0)
/* 844534 80241964 A0430002 */  sb        $v1, 2($v0)
/* 844538 80241968 0C03A6DB */  jal       sync_status_menu
/* 84453C 8024196C A0440005 */   sb       $a0, 5($v0)
/* 844540 80241970 8FBF0010 */  lw        $ra, 0x10($sp)
/* 844544 80241974 24020002 */  addiu     $v0, $zero, 2
/* 844548 80241978 03E00008 */  jr        $ra
/* 84454C 8024197C 27BD0018 */   addiu    $sp, $sp, 0x18
