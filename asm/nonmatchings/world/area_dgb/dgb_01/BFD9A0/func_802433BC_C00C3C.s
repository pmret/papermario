.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802433BC_C00C3C
/* C00C3C 802433BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C00C40 802433C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* C00C44 802433C4 0C03A6D5 */  jal       increment_status_menu_disabled
/* C00C48 802433C8 00000000 */   nop      
/* C00C4C 802433CC 3C05437F */  lui       $a1, 0x437f
/* C00C50 802433D0 0C04DF69 */  jal       func_80137DA4
/* C00C54 802433D4 0000202D */   daddu    $a0, $zero, $zero
/* C00C58 802433D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* C00C5C 802433DC 24020002 */  addiu     $v0, $zero, 2
/* C00C60 802433E0 03E00008 */  jr        $ra
/* C00C64 802433E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* C00C68 802433E8 00000000 */  nop       
/* C00C6C 802433EC 00000000 */  nop       
