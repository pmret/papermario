.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_B06A50
/* B06A50 80240050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B06A54 80240054 AFBF0010 */  sw        $ra, 0x10($sp)
/* B06A58 80240058 0C03A6D5 */  jal       increment_status_menu_disabled
/* B06A5C 8024005C 00000000 */   nop      
/* B06A60 80240060 3C05437F */  lui       $a1, 0x437f
/* B06A64 80240064 0C04DF69 */  jal       func_80137DA4
/* B06A68 80240068 0000202D */   daddu    $a0, $zero, $zero
/* B06A6C 8024006C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B06A70 80240070 24020002 */  addiu     $v0, $zero, 2
/* B06A74 80240074 03E00008 */  jr        $ra
/* B06A78 80240078 27BD0018 */   addiu    $sp, $sp, 0x18
/* B06A7C 8024007C 00000000 */  nop       
