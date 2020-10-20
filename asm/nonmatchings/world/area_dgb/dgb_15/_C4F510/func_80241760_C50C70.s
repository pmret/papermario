.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241760_C50C70
/* C50C70 80241760 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C50C74 80241764 AFBF0010 */  sw        $ra, 0x10($sp)
/* C50C78 80241768 0C03A6D5 */  jal       increment_status_menu_disabled
/* C50C7C 8024176C 00000000 */   nop      
/* C50C80 80241770 3C05437F */  lui       $a1, 0x437f
/* C50C84 80241774 0C04DF69 */  jal       func_80137DA4
/* C50C88 80241778 0000202D */   daddu    $a0, $zero, $zero
/* C50C8C 8024177C 8FBF0010 */  lw        $ra, 0x10($sp)
/* C50C90 80241780 24020002 */  addiu     $v0, $zero, 2
/* C50C94 80241784 03E00008 */  jr        $ra
/* C50C98 80241788 27BD0018 */   addiu    $sp, $sp, 0x18
/* C50C9C 8024178C 00000000 */  nop       
