.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel EnemyFollowupAfflictTarget
/* 1AB7B4 8027CED4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1AB7B8 8027CED8 AFB20018 */  sw    $s2, 0x18($sp)
/* 1AB7BC 8027CEDC 0080902D */  daddu $s2, $a0, $zero
/* 1AB7C0 8027CEE0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 1AB7C4 8027CEE4 AFB3001C */  sw    $s3, 0x1c($sp)
/* 1AB7C8 8027CEE8 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AB7CC 8027CEEC AFB00010 */  sw    $s0, 0x10($sp)
/* 1AB7D0 8027CEF0 8E50000C */  lw    $s0, 0xc($s2)
/* 1AB7D4 8027CEF4 8E050000 */  lw    $a1, ($s0)
/* 1AB7D8 8027CEF8 0C0B1EAF */  jal   get_variable
/* 1AB7DC 8027CEFC 26100004 */   addiu $s0, $s0, 4
/* 1AB7E0 8027CF00 0040202D */  daddu $a0, $v0, $zero
/* 1AB7E4 8027CF04 3C11800E */  lui   $s1, 0x800e
/* 1AB7E8 8027CF08 2631C070 */  addiu $s1, $s1, -0x3f90
/* 1AB7EC 8027CF0C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AB7F0 8027CF10 14820002 */  bne   $a0, $v0, .L8027CF1C
/* 1AB7F4 8027CF14 0220982D */   daddu $s3, $s1, $zero
/* 1AB7F8 8027CF18 8E440148 */  lw    $a0, 0x148($s2)
.L8027CF1C:
/* 1AB7FC 8027CF1C 0C09A75B */  jal   get_actor
/* 1AB800 8027CF20 00000000 */   nop   
/* 1AB804 8027CF24 0040202D */  daddu $a0, $v0, $zero
/* 1AB808 8027CF28 94820428 */  lhu   $v0, 0x428($a0)
/* 1AB80C 8027CF2C 8E100000 */  lw    $s0, ($s0)
/* 1AB810 8027CF30 92230193 */  lbu   $v1, 0x193($s1)
/* 1AB814 8027CF34 A62201A0 */  sh    $v0, 0x1a0($s1)
/* 1AB818 8027CF38 90820426 */  lbu   $v0, 0x426($a0)
/* 1AB81C 8027CF3C A2230194 */  sb    $v1, 0x194($s1)
/* 1AB820 8027CF40 306300FF */  andi  $v1, $v1, 0xff
/* 1AB824 8027CF44 A22201A2 */  sb    $v0, 0x1a2($s1)
/* 1AB828 8027CF48 240200FF */  addiu $v0, $zero, 0xff
/* 1AB82C 8027CF4C 50620001 */  beql  $v1, $v0, .L8027CF54
/* 1AB830 8027CF50 A2200194 */   sb    $zero, 0x194($s1)
.L8027CF54:
/* 1AB834 8027CF54 8E620190 */  lw    $v0, 0x190($s3)
/* 1AB838 8027CF58 30420F00 */  andi  $v0, $v0, 0xf00
/* 1AB83C 8027CF5C 00021203 */  sra   $v0, $v0, 8
/* 1AB840 8027CF60 0C09DD0B */  jal   calc_enemy_damage_target
/* 1AB844 8027CF64 A2620195 */   sb    $v0, 0x195($s3)
/* 1AB848 8027CF68 0440000B */  bltz  $v0, .L8027CF98
/* 1AB84C 8027CF6C 0240202D */   daddu $a0, $s2, $zero
/* 1AB850 8027CF70 0200282D */  daddu $a1, $s0, $zero
/* 1AB854 8027CF74 0C0B2026 */  jal   set_variable
/* 1AB858 8027CF78 0040302D */   daddu $a2, $v0, $zero
/* 1AB85C 8027CF7C 0C0B1069 */  jal   does_script_exist_by_ref
/* 1AB860 8027CF80 0240202D */   daddu $a0, $s2, $zero
/* 1AB864 8027CF84 0040182D */  daddu $v1, $v0, $zero
/* 1AB868 8027CF88 10600004 */  beqz  $v1, .L8027CF9C
/* 1AB86C 8027CF8C 240200FF */   addiu $v0, $zero, 0xff
/* 1AB870 8027CF90 0809F3E7 */  j     .L8027CF9C
/* 1AB874 8027CF94 24020002 */   addiu $v0, $zero, 2

.L8027CF98:
/* 1AB878 8027CF98 240200FF */  addiu $v0, $zero, 0xff
.L8027CF9C:
.L8027CF9C:
/* 1AB87C 8027CF9C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 1AB880 8027CFA0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1AB884 8027CFA4 8FB20018 */  lw    $s2, 0x18($sp)
/* 1AB888 8027CFA8 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AB88C 8027CFAC 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AB890 8027CFB0 03E00008 */  jr    $ra
/* 1AB894 8027CFB4 27BD0028 */   addiu $sp, $sp, 0x28

