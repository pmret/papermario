.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ED0_C9EDF0
/* C9EDF0 80240ED0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9EDF4 80240ED4 AFBF0010 */  sw        $ra, 0x10($sp)
/* C9EDF8 80240ED8 0C03A876 */  jal       set_max_SP
/* C9EDFC 80240EDC 24040006 */   addiu    $a0, $zero, 6
/* C9EE00 80240EE0 3C028011 */  lui       $v0, %hi(gPlayerData)
/* C9EE04 80240EE4 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* C9EE08 80240EE8 90430003 */  lbu       $v1, 3($v0)
/* C9EE0C 80240EEC 90440006 */  lbu       $a0, 6($v0)
/* C9EE10 80240EF0 A0430002 */  sb        $v1, 2($v0)
/* C9EE14 80240EF4 0C03A6DB */  jal       sync_status_menu
/* C9EE18 80240EF8 A0440005 */   sb       $a0, 5($v0)
/* C9EE1C 80240EFC 8FBF0010 */  lw        $ra, 0x10($sp)
/* C9EE20 80240F00 24020002 */  addiu     $v0, $zero, 2
/* C9EE24 80240F04 03E00008 */  jr        $ra
/* C9EE28 80240F08 27BD0018 */   addiu    $sp, $sp, 0x18
/* C9EE2C 80240F0C 00000000 */  nop       
