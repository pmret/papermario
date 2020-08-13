.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel init_demo_data
/* 013480 80038080 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 013484 80038084 3C048007 */  lui   $a0, 0x8007
/* 013488 80038088 2484419C */  addiu $a0, $a0, 0x419c
/* 01348C 8003808C AFBF0010 */  sw    $ra, 0x10($sp)
/* 013490 80038090 8C830000 */  lw    $v1, ($a0)
/* 013494 80038094 80620071 */  lb    $v0, 0x71($v1)
/* 013498 80038098 14400004 */  bnez  $v0, .L800380AC
/* 01349C 8003809C 24020001 */   addiu $v0, $zero, 1
/* 0134A0 800380A0 A0600072 */  sb    $zero, 0x72($v1)
/* 0134A4 800380A4 8C830000 */  lw    $v1, ($a0)
/* 0134A8 800380A8 A0620071 */  sb    $v0, 0x71($v1)
.L800380AC:
/* 0134AC 800380AC 8C820000 */  lw    $v0, ($a0)
/* 0134B0 800380B0 A040006A */  sb    $zero, 0x6a($v0)
/* 0134B4 800380B4 8C830000 */  lw    $v1, ($a0)
/* 0134B8 800380B8 A4400068 */  sh    $zero, 0x68($v0)
/* 0134BC 800380BC 0C01588A */  jal   func_80056228
/* 0134C0 800380C0 A060006B */   sb    $zero, 0x6b($v1)
/* 0134C4 800380C4 0C04E0A8 */  jal   set_map_transition_effect
/* 0134C8 800380C8 24040002 */   addiu $a0, $zero, 2
/* 0134CC 800380CC 3C05437F */  lui   $a1, 0x437f
/* 0134D0 800380D0 0C04DF62 */  jal   func_80137D88
/* 0134D4 800380D4 0000202D */   daddu $a0, $zero, $zero
/* 0134D8 800380D8 0C0514C8 */  jal   clear_saved_variables
/* 0134DC 800380DC 00000000 */   nop   
/* 0134E0 800380E0 0C0B0C77 */  jal   clear_script_list
/* 0134E4 800380E4 00000000 */   nop   
/* 0134E8 800380E8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0134EC 800380EC 03E00008 */  jr    $ra
/* 0134F0 800380F0 27BD0018 */   addiu $sp, $sp, 0x18

