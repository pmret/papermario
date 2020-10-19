.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E48_BEEC38
/* BEEC38 80241E48 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BEEC3C 80241E4C AFBF0010 */  sw        $ra, 0x10($sp)
/* BEEC40 80241E50 0C03A876 */  jal       set_max_SP
/* BEEC44 80241E54 24040003 */   addiu    $a0, $zero, 3
/* BEEC48 80241E58 3C028011 */  lui       $v0, %hi(gPlayerData)
/* BEEC4C 80241E5C 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* BEEC50 80241E60 90430003 */  lbu       $v1, 3($v0)
/* BEEC54 80241E64 90440006 */  lbu       $a0, 6($v0)
/* BEEC58 80241E68 A0430002 */  sb        $v1, 2($v0)
/* BEEC5C 80241E6C 0C03A6DB */  jal       sync_status_menu
/* BEEC60 80241E70 A0440005 */   sb       $a0, 5($v0)
/* BEEC64 80241E74 8FBF0010 */  lw        $ra, 0x10($sp)
/* BEEC68 80241E78 24020002 */  addiu     $v0, $zero, 2
/* BEEC6C 80241E7C 03E00008 */  jr        $ra
/* BEEC70 80241E80 27BD0018 */   addiu    $sp, $sp, 0x18
/* BEEC74 80241E84 00000000 */  nop       
/* BEEC78 80241E88 00000000 */  nop       
/* BEEC7C 80241E8C 00000000 */  nop       
