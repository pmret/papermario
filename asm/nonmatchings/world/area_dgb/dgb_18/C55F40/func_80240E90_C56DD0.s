.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E90_C56DD0
/* C56DD0 80240E90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C56DD4 80240E94 AFBF0010 */  sw        $ra, 0x10($sp)
/* C56DD8 80240E98 0C03A6D5 */  jal       increment_status_menu_disabled
/* C56DDC 80240E9C 00000000 */   nop      
/* C56DE0 80240EA0 3C05437F */  lui       $a1, 0x437f
/* C56DE4 80240EA4 0C04DF69 */  jal       func_80137DA4
/* C56DE8 80240EA8 0000202D */   daddu    $a0, $zero, $zero
/* C56DEC 80240EAC 8FBF0010 */  lw        $ra, 0x10($sp)
/* C56DF0 80240EB0 24020002 */  addiu     $v0, $zero, 2
/* C56DF4 80240EB4 03E00008 */  jr        $ra
/* C56DF8 80240EB8 27BD0018 */   addiu    $sp, $sp, 0x18
