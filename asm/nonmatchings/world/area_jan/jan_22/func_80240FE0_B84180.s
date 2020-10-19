.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE0_B85160
/* B85160 80240FE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B85164 80240FE4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B85168 80240FE8 0C03A876 */  jal       set_max_SP
/* B8516C 80240FEC 24040005 */   addiu    $a0, $zero, 5
/* B85170 80240FF0 3C028011 */  lui       $v0, %hi(gPlayerData)
/* B85174 80240FF4 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* B85178 80240FF8 90430003 */  lbu       $v1, 3($v0)
/* B8517C 80240FFC 90440006 */  lbu       $a0, 6($v0)
/* B85180 80241000 A0430002 */  sb        $v1, 2($v0)
/* B85184 80241004 0C03A6DB */  jal       sync_status_menu
/* B85188 80241008 A0440005 */   sb       $a0, 5($v0)
/* B8518C 8024100C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B85190 80241010 24020002 */  addiu     $v0, $zero, 2
/* B85194 80241014 03E00008 */  jr        $ra
/* B85198 80241018 27BD0018 */   addiu    $sp, $sp, 0x18
/* B8519C 8024101C 00000000 */  nop       
