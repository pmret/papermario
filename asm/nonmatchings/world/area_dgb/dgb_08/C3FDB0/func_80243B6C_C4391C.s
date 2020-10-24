.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243B6C_C4391C
/* C4391C 80243B6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C43920 80243B70 AFBF0010 */  sw        $ra, 0x10($sp)
/* C43924 80243B74 0C03A6D5 */  jal       increment_status_menu_disabled
/* C43928 80243B78 00000000 */   nop      
/* C4392C 80243B7C 3C05437F */  lui       $a1, 0x437f
/* C43930 80243B80 0C04DF69 */  jal       func_80137DA4
/* C43934 80243B84 0000202D */   daddu    $a0, $zero, $zero
/* C43938 80243B88 8FBF0010 */  lw        $ra, 0x10($sp)
/* C4393C 80243B8C 24020002 */  addiu     $v0, $zero, 2
/* C43940 80243B90 03E00008 */  jr        $ra
/* C43944 80243B94 27BD0018 */   addiu    $sp, $sp, 0x18
