.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetNpcPos
/* F3AA4 802CF0F4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* F3AA8 802CF0F8 AFB10014 */  sw        $s1, 0x14($sp)
/* F3AAC 802CF0FC 0080882D */  daddu     $s1, $a0, $zero
/* F3AB0 802CF100 AFBF0024 */  sw        $ra, 0x24($sp)
/* F3AB4 802CF104 AFB40020 */  sw        $s4, 0x20($sp)
/* F3AB8 802CF108 AFB3001C */  sw        $s3, 0x1c($sp)
/* F3ABC 802CF10C AFB20018 */  sw        $s2, 0x18($sp)
/* F3AC0 802CF110 AFB00010 */  sw        $s0, 0x10($sp)
/* F3AC4 802CF114 8E30000C */  lw        $s0, 0xc($s1)
/* F3AC8 802CF118 8E050000 */  lw        $a1, ($s0)
/* F3ACC 802CF11C 0C0B1EAF */  jal       get_variable
/* F3AD0 802CF120 26100004 */   addiu    $s0, $s0, 4
/* F3AD4 802CF124 8E120000 */  lw        $s2, ($s0)
/* F3AD8 802CF128 26100004 */  addiu     $s0, $s0, 4
/* F3ADC 802CF12C 0220202D */  daddu     $a0, $s1, $zero
/* F3AE0 802CF130 8E130000 */  lw        $s3, ($s0)
/* F3AE4 802CF134 8E140004 */  lw        $s4, 4($s0)
/* F3AE8 802CF138 0C0B36B0 */  jal       resolve_npc
/* F3AEC 802CF13C 0040282D */   daddu    $a1, $v0, $zero
/* F3AF0 802CF140 0040802D */  daddu     $s0, $v0, $zero
/* F3AF4 802CF144 12000012 */  beqz      $s0, .L802CF190
/* F3AF8 802CF148 0220202D */   daddu    $a0, $s1, $zero
/* F3AFC 802CF14C C6000038 */  lwc1      $f0, 0x38($s0)
/* F3B00 802CF150 4600008D */  trunc.w.s $f2, $f0
/* F3B04 802CF154 44061000 */  mfc1      $a2, $f2
/* F3B08 802CF158 0C0B2026 */  jal       set_variable
/* F3B0C 802CF15C 0240282D */   daddu    $a1, $s2, $zero
/* F3B10 802CF160 0220202D */  daddu     $a0, $s1, $zero
/* F3B14 802CF164 C600003C */  lwc1      $f0, 0x3c($s0)
/* F3B18 802CF168 4600008D */  trunc.w.s $f2, $f0
/* F3B1C 802CF16C 44061000 */  mfc1      $a2, $f2
/* F3B20 802CF170 0C0B2026 */  jal       set_variable
/* F3B24 802CF174 0260282D */   daddu    $a1, $s3, $zero
/* F3B28 802CF178 0220202D */  daddu     $a0, $s1, $zero
/* F3B2C 802CF17C C6000040 */  lwc1      $f0, 0x40($s0)
/* F3B30 802CF180 4600008D */  trunc.w.s $f2, $f0
/* F3B34 802CF184 44061000 */  mfc1      $a2, $f2
/* F3B38 802CF188 0C0B2026 */  jal       set_variable
/* F3B3C 802CF18C 0280282D */   daddu    $a1, $s4, $zero
.L802CF190:
/* F3B40 802CF190 24020002 */  addiu     $v0, $zero, 2
/* F3B44 802CF194 8FBF0024 */  lw        $ra, 0x24($sp)
/* F3B48 802CF198 8FB40020 */  lw        $s4, 0x20($sp)
/* F3B4C 802CF19C 8FB3001C */  lw        $s3, 0x1c($sp)
/* F3B50 802CF1A0 8FB20018 */  lw        $s2, 0x18($sp)
/* F3B54 802CF1A4 8FB10014 */  lw        $s1, 0x14($sp)
/* F3B58 802CF1A8 8FB00010 */  lw        $s0, 0x10($sp)
/* F3B5C 802CF1AC 03E00008 */  jr        $ra
/* F3B60 802CF1B0 27BD0028 */   addiu    $sp, $sp, 0x28
