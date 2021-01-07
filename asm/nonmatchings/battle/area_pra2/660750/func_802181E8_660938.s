.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181E8_660938
/* 660938 802181E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 66093C 802181EC AFB20018 */  sw        $s2, 0x18($sp)
/* 660940 802181F0 0080902D */  daddu     $s2, $a0, $zero
/* 660944 802181F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 660948 802181F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 66094C 802181FC AFB10014 */  sw        $s1, 0x14($sp)
/* 660950 80218200 AFB00010 */  sw        $s0, 0x10($sp)
/* 660954 80218204 8E50000C */  lw        $s0, 0xc($s2)
/* 660958 80218208 8E050000 */  lw        $a1, ($s0)
/* 66095C 8021820C 0C0B1EAF */  jal       get_variable
/* 660960 80218210 26100004 */   addiu    $s0, $s0, 4
/* 660964 80218214 0040882D */  daddu     $s1, $v0, $zero
/* 660968 80218218 8E050000 */  lw        $a1, ($s0)
/* 66096C 8021821C 26100004 */  addiu     $s0, $s0, 4
/* 660970 80218220 0C0B1EAF */  jal       get_variable
/* 660974 80218224 0240202D */   daddu    $a0, $s2, $zero
/* 660978 80218228 0040982D */  daddu     $s3, $v0, $zero
/* 66097C 8021822C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 660980 80218230 16220002 */  bne       $s1, $v0, .L8021823C
/* 660984 80218234 00000000 */   nop      
/* 660988 80218238 8E510148 */  lw        $s1, 0x148($s2)
.L8021823C:
/* 66098C 8021823C 0C09A75B */  jal       get_actor
/* 660990 80218240 0220202D */   daddu    $a0, $s1, $zero
/* 660994 80218244 0040202D */  daddu     $a0, $v0, $zero
/* 660998 80218248 0C099117 */  jal       get_actor_part
/* 66099C 8021824C 0260282D */   daddu    $a1, $s3, $zero
/* 6609A0 80218250 8E050000 */  lw        $a1, ($s0)
/* 6609A4 80218254 84460098 */  lh        $a2, 0x98($v0)
/* 6609A8 80218258 0C0B2026 */  jal       set_variable
/* 6609AC 8021825C 0240202D */   daddu    $a0, $s2, $zero
/* 6609B0 80218260 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6609B4 80218264 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6609B8 80218268 8FB20018 */  lw        $s2, 0x18($sp)
/* 6609BC 8021826C 8FB10014 */  lw        $s1, 0x14($sp)
/* 6609C0 80218270 8FB00010 */  lw        $s0, 0x10($sp)
/* 6609C4 80218274 24020002 */  addiu     $v0, $zero, 2
/* 6609C8 80218278 03E00008 */  jr        $ra
/* 6609CC 8021827C 27BD0028 */   addiu    $sp, $sp, 0x28
