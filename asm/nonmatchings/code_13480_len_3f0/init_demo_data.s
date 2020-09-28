.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel init_demo_data
/* 13480 80038080 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13484 80038084 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 13488 80038088 2484419C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* 1348C 8003808C AFBF0010 */  sw        $ra, 0x10($sp)
/* 13490 80038090 8C830000 */  lw        $v1, ($a0)
/* 13494 80038094 80620071 */  lb        $v0, 0x71($v1)
/* 13498 80038098 14400004 */  bnez      $v0, .L800380AC
/* 1349C 8003809C 24020001 */   addiu    $v0, $zero, 1
/* 134A0 800380A0 A0600072 */  sb        $zero, 0x72($v1)
/* 134A4 800380A4 8C830000 */  lw        $v1, ($a0)
/* 134A8 800380A8 A0620071 */  sb        $v0, 0x71($v1)
.L800380AC:
/* 134AC 800380AC 8C820000 */  lw        $v0, ($a0)
/* 134B0 800380B0 A040006A */  sb        $zero, 0x6a($v0)
/* 134B4 800380B4 8C830000 */  lw        $v1, ($a0)
/* 134B8 800380B8 A4400068 */  sh        $zero, 0x68($v0)
/* 134BC 800380BC 0C01588A */  jal       func_80056228
/* 134C0 800380C0 A060006B */   sb       $zero, 0x6b($v1)
/* 134C4 800380C4 0C04E0A8 */  jal       set_map_transition_effect
/* 134C8 800380C8 24040002 */   addiu    $a0, $zero, 2
/* 134CC 800380CC 3C05437F */  lui       $a1, 0x437f
/* 134D0 800380D0 0C04DF62 */  jal       func_80137D88
/* 134D4 800380D4 0000202D */   daddu    $a0, $zero, $zero
/* 134D8 800380D8 0C0514C8 */  jal       clear_saved_variables
/* 134DC 800380DC 00000000 */   nop      
/* 134E0 800380E0 0C0B0C77 */  jal       clear_script_list
/* 134E4 800380E4 00000000 */   nop      
/* 134E8 800380E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 134EC 800380EC 03E00008 */  jr        $ra
/* 134F0 800380F0 27BD0018 */   addiu    $sp, $sp, 0x18
