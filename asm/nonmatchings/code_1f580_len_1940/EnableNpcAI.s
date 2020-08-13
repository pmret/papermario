.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel EnableNpcAI
/* 0200F0 80044CF0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0200F4 80044CF4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0200F8 80044CF8 0080882D */  daddu $s1, $a0, $zero
/* 0200FC 80044CFC AFBF0020 */  sw    $ra, 0x20($sp)
/* 020100 80044D00 AFB3001C */  sw    $s3, 0x1c($sp)
/* 020104 80044D04 AFB20018 */  sw    $s2, 0x18($sp)
/* 020108 80044D08 AFB00010 */  sw    $s0, 0x10($sp)
/* 02010C 80044D0C 8E30000C */  lw    $s0, 0xc($s1)
/* 020110 80044D10 8E330148 */  lw    $s3, 0x148($s1)
/* 020114 80044D14 8E050000 */  lw    $a1, ($s0)
/* 020118 80044D18 0C0B1EAF */  jal   get_variable
/* 02011C 80044D1C 26100004 */   addiu $s0, $s0, 4
/* 020120 80044D20 0040902D */  daddu $s2, $v0, $zero
/* 020124 80044D24 8E050000 */  lw    $a1, ($s0)
/* 020128 80044D28 0C0B1EAF */  jal   get_variable
/* 02012C 80044D2C 0220202D */   daddu $a0, $s1, $zero
/* 020130 80044D30 0040802D */  daddu $s0, $v0, $zero
/* 020134 80044D34 2402FFFF */  addiu $v0, $zero, -1
/* 020138 80044D38 16420002 */  bne   $s2, $v0, .L80044D44
/* 02013C 80044D3C 00000000 */   nop   
/* 020140 80044D40 86720008 */  lh    $s2, 8($s3)
.L80044D44:
/* 020144 80044D44 0C00FB3A */  jal   get_enemy
/* 020148 80044D48 0240202D */   daddu $a0, $s2, $zero
/* 02014C 80044D4C 12000008 */  beqz  $s0, .L80044D70
/* 020150 80044D50 0040982D */   daddu $s3, $v0, $zero
/* 020154 80044D54 8E62003C */  lw    $v0, 0x3c($s3)
/* 020158 80044D58 1040000A */  beqz  $v0, .L80044D84
/* 02015C 80044D5C 00000000 */   nop   
/* 020160 80044D60 0C0B1123 */  jal   resume_all_script
/* 020164 80044D64 8E640054 */   lw    $a0, 0x54($s3)
/* 020168 80044D68 08011361 */  j     .L80044D84
/* 02016C 80044D6C 00000000 */   nop   

.L80044D70:
/* 020170 80044D70 8E62003C */  lw    $v0, 0x3c($s3)
/* 020174 80044D74 10400003 */  beqz  $v0, .L80044D84
/* 020178 80044D78 00000000 */   nop   
/* 02017C 80044D7C 0C0B1108 */  jal   suspend_all_script
/* 020180 80044D80 8E640054 */   lw    $a0, 0x54($s3)
.L80044D84:
/* 020184 80044D84 8FBF0020 */  lw    $ra, 0x20($sp)
/* 020188 80044D88 8FB3001C */  lw    $s3, 0x1c($sp)
/* 02018C 80044D8C 8FB20018 */  lw    $s2, 0x18($sp)
/* 020190 80044D90 8FB10014 */  lw    $s1, 0x14($sp)
/* 020194 80044D94 8FB00010 */  lw    $s0, 0x10($sp)
/* 020198 80044D98 24020002 */  addiu $v0, $zero, 2
/* 02019C 80044D9C 03E00008 */  jr    $ra
/* 0201A0 80044DA0 27BD0028 */   addiu $sp, $sp, 0x28

