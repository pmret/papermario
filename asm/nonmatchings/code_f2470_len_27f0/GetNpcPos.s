.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetNpcPos
/* 0F3AA4 802CF0F4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F3AA8 802CF0F8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F3AAC 802CF0FC 0080882D */  daddu $s1, $a0, $zero
/* 0F3AB0 802CF100 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F3AB4 802CF104 AFB40020 */  sw    $s4, 0x20($sp)
/* 0F3AB8 802CF108 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F3ABC 802CF10C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F3AC0 802CF110 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F3AC4 802CF114 8E30000C */  lw    $s0, 0xc($s1)
/* 0F3AC8 802CF118 8E050000 */  lw    $a1, ($s0)
/* 0F3ACC 802CF11C 0C0B1EAF */  jal   get_variable
/* 0F3AD0 802CF120 26100004 */   addiu $s0, $s0, 4
/* 0F3AD4 802CF124 8E120000 */  lw    $s2, ($s0)
/* 0F3AD8 802CF128 26100004 */  addiu $s0, $s0, 4
/* 0F3ADC 802CF12C 0220202D */  daddu $a0, $s1, $zero
/* 0F3AE0 802CF130 8E130000 */  lw    $s3, ($s0)
/* 0F3AE4 802CF134 8E140004 */  lw    $s4, 4($s0)
/* 0F3AE8 802CF138 0C0B36B0 */  jal   resolve_npc
/* 0F3AEC 802CF13C 0040282D */   daddu $a1, $v0, $zero
/* 0F3AF0 802CF140 0040802D */  daddu $s0, $v0, $zero
/* 0F3AF4 802CF144 12000012 */  beqz  $s0, .L802CF190
/* 0F3AF8 802CF148 0220202D */   daddu $a0, $s1, $zero
/* 0F3AFC 802CF14C C6000038 */  lwc1  $f0, 0x38($s0)
/* 0F3B00 802CF150 4600008D */  trunc.w.s $f2, $f0
/* 0F3B04 802CF154 44061000 */  mfc1  $a2, $f2
/* 0F3B08 802CF158 0C0B2026 */  jal   set_variable
/* 0F3B0C 802CF15C 0240282D */   daddu $a1, $s2, $zero
/* 0F3B10 802CF160 0220202D */  daddu $a0, $s1, $zero
/* 0F3B14 802CF164 C600003C */  lwc1  $f0, 0x3c($s0)
/* 0F3B18 802CF168 4600008D */  trunc.w.s $f2, $f0
/* 0F3B1C 802CF16C 44061000 */  mfc1  $a2, $f2
/* 0F3B20 802CF170 0C0B2026 */  jal   set_variable
/* 0F3B24 802CF174 0260282D */   daddu $a1, $s3, $zero
/* 0F3B28 802CF178 0220202D */  daddu $a0, $s1, $zero
/* 0F3B2C 802CF17C C6000040 */  lwc1  $f0, 0x40($s0)
/* 0F3B30 802CF180 4600008D */  trunc.w.s $f2, $f0
/* 0F3B34 802CF184 44061000 */  mfc1  $a2, $f2
/* 0F3B38 802CF188 0C0B2026 */  jal   set_variable
/* 0F3B3C 802CF18C 0280282D */   daddu $a1, $s4, $zero
.L802CF190:
/* 0F3B40 802CF190 24020002 */  addiu $v0, $zero, 2
/* 0F3B44 802CF194 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F3B48 802CF198 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F3B4C 802CF19C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F3B50 802CF1A0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F3B54 802CF1A4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F3B58 802CF1A8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F3B5C 802CF1AC 03E00008 */  jr    $ra
/* 0F3B60 802CF1B0 27BD0028 */   addiu $sp, $sp, 0x28

/* 0F3B64 802CF1B4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F3B68 802CF1B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F3B6C 802CF1BC 0080802D */  daddu $s0, $a0, $zero
/* 0F3B70 802CF1C0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F3B74 802CF1C4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F3B78 802CF1C8 8E11000C */  lw    $s1, 0xc($s0)
/* 0F3B7C 802CF1CC 8E250000 */  lw    $a1, ($s1)
/* 0F3B80 802CF1D0 0C0B1EAF */  jal   get_variable
/* 0F3B84 802CF1D4 26310004 */   addiu $s1, $s1, 4
/* 0F3B88 802CF1D8 0200202D */  daddu $a0, $s0, $zero
/* 0F3B8C 802CF1DC 8E310000 */  lw    $s1, ($s1)
/* 0F3B90 802CF1E0 0C0B36B0 */  jal   resolve_npc
/* 0F3B94 802CF1E4 0040282D */   daddu $a1, $v0, $zero
/* 0F3B98 802CF1E8 54400001 */  bnel  $v0, $zero, .L802CF1F0
/* 0F3B9C 802CF1EC AC510080 */   sw    $s1, 0x80($v0)
.L802CF1F0:
/* 0F3BA0 802CF1F0 24020002 */  addiu $v0, $zero, 2
/* 0F3BA4 802CF1F4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F3BA8 802CF1F8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F3BAC 802CF1FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F3BB0 802CF200 03E00008 */  jr    $ra
/* 0F3BB4 802CF204 27BD0020 */   addiu $sp, $sp, 0x20

/* 0F3BB8 802CF208 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F3BBC 802CF20C AFB00010 */  sw    $s0, 0x10($sp)
/* 0F3BC0 802CF210 0080802D */  daddu $s0, $a0, $zero
/* 0F3BC4 802CF214 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F3BC8 802CF218 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F3BCC 802CF21C 8E11000C */  lw    $s1, 0xc($s0)
/* 0F3BD0 802CF220 8E250000 */  lw    $a1, ($s1)
/* 0F3BD4 802CF224 0C0B1EAF */  jal   get_variable
/* 0F3BD8 802CF228 26310004 */   addiu $s1, $s1, 4
/* 0F3BDC 802CF22C 0200202D */  daddu $a0, $s0, $zero
/* 0F3BE0 802CF230 8E310000 */  lw    $s1, ($s1)
/* 0F3BE4 802CF234 0C0B36B0 */  jal   resolve_npc
/* 0F3BE8 802CF238 0040282D */   daddu $a1, $v0, $zero
/* 0F3BEC 802CF23C 10400004 */  beqz  $v0, .L802CF250
/* 0F3BF0 802CF240 0040202D */   daddu $a0, $v0, $zero
/* 0F3BF4 802CF244 0220282D */  daddu $a1, $s1, $zero
/* 0F3BF8 802CF248 0C00EB17 */  jal   func_8003AC5C
/* 0F3BFC 802CF24C 0000302D */   daddu $a2, $zero, $zero
.L802CF250:
/* 0F3C00 802CF250 24020002 */  addiu $v0, $zero, 2
/* 0F3C04 802CF254 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F3C08 802CF258 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F3C0C 802CF25C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F3C10 802CF260 03E00008 */  jr    $ra
/* 0F3C14 802CF264 27BD0020 */   addiu $sp, $sp, 0x20

