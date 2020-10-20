.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B5C
/* 92AE0C 80240B5C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 92AE10 80240B60 AFBF0010 */  sw        $ra, 0x10($sp)
/* 92AE14 80240B64 0C03A876 */  jal       set_max_SP
/* 92AE18 80240B68 24040002 */   addiu    $a0, $zero, 2
/* 92AE1C 80240B6C 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 92AE20 80240B70 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 92AE24 80240B74 90430003 */  lbu       $v1, 3($v0)
/* 92AE28 80240B78 90440006 */  lbu       $a0, 6($v0)
/* 92AE2C 80240B7C A0430002 */  sb        $v1, 2($v0)
/* 92AE30 80240B80 0C03A6DB */  jal       sync_status_menu
/* 92AE34 80240B84 A0440005 */   sb       $a0, 5($v0)
/* 92AE38 80240B88 8FBF0010 */  lw        $ra, 0x10($sp)
/* 92AE3C 80240B8C 24020002 */  addiu     $v0, $zero, 2
/* 92AE40 80240B90 03E00008 */  jr        $ra
/* 92AE44 80240B94 27BD0018 */   addiu    $sp, $sp, 0x18
