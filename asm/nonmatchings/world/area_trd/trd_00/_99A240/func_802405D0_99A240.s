.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405D0_99A240
/* 99A240 802405D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 99A244 802405D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 99A248 802405D8 0C03A876 */  jal       set_max_SP
/* 99A24C 802405DC 24040001 */   addiu    $a0, $zero, 1
/* 99A250 802405E0 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 99A254 802405E4 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 99A258 802405E8 90430003 */  lbu       $v1, 3($v0)
/* 99A25C 802405EC 90440006 */  lbu       $a0, 6($v0)
/* 99A260 802405F0 A0430002 */  sb        $v1, 2($v0)
/* 99A264 802405F4 0C03A6DB */  jal       sync_status_menu
/* 99A268 802405F8 A0440005 */   sb       $a0, 5($v0)
/* 99A26C 802405FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 99A270 80240600 24020002 */  addiu     $v0, $zero, 2
/* 99A274 80240604 03E00008 */  jr        $ra
/* 99A278 80240608 27BD0018 */   addiu    $sp, $sp, 0x18
