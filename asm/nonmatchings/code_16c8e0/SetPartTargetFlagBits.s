.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartTargetFlagBits
/* 19BA38 8026D158 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19BA3C 8026D15C AFB10014 */  sw        $s1, 0x14($sp)
/* 19BA40 8026D160 0080882D */  daddu     $s1, $a0, $zero
/* 19BA44 8026D164 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19BA48 8026D168 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19BA4C 8026D16C AFB20018 */  sw        $s2, 0x18($sp)
/* 19BA50 8026D170 AFB00010 */  sw        $s0, 0x10($sp)
/* 19BA54 8026D174 8E30000C */  lw        $s0, 0xc($s1)
/* 19BA58 8026D178 8E050000 */  lw        $a1, ($s0)
/* 19BA5C 8026D17C 0C0B1EAF */  jal       get_variable
/* 19BA60 8026D180 26100004 */   addiu    $s0, $s0, 4
/* 19BA64 8026D184 0040902D */  daddu     $s2, $v0, $zero
/* 19BA68 8026D188 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19BA6C 8026D18C 16420002 */  bne       $s2, $v0, .L8026D198
/* 19BA70 8026D190 00000000 */   nop      
/* 19BA74 8026D194 8E320148 */  lw        $s2, 0x148($s1)
.L8026D198:
/* 19BA78 8026D198 8E050000 */  lw        $a1, ($s0)
/* 19BA7C 8026D19C 26100004 */  addiu     $s0, $s0, 4
/* 19BA80 8026D1A0 0C0B1EAF */  jal       get_variable
/* 19BA84 8026D1A4 0220202D */   daddu    $a0, $s1, $zero
/* 19BA88 8026D1A8 0220202D */  daddu     $a0, $s1, $zero
/* 19BA8C 8026D1AC 8E050004 */  lw        $a1, 4($s0)
/* 19BA90 8026D1B0 8E130000 */  lw        $s3, ($s0)
/* 19BA94 8026D1B4 0C0B1EAF */  jal       get_variable
/* 19BA98 8026D1B8 0040882D */   daddu    $s1, $v0, $zero
/* 19BA9C 8026D1BC 0240202D */  daddu     $a0, $s2, $zero
/* 19BAA0 8026D1C0 0C09A75B */  jal       get_actor
/* 19BAA4 8026D1C4 0040802D */   daddu    $s0, $v0, $zero
/* 19BAA8 8026D1C8 0040202D */  daddu     $a0, $v0, $zero
/* 19BAAC 8026D1CC 0C099117 */  jal       get_actor_part
/* 19BAB0 8026D1D0 0220282D */   daddu    $a1, $s1, $zero
/* 19BAB4 8026D1D4 12000004 */  beqz      $s0, .L8026D1E8
/* 19BAB8 8026D1D8 0040202D */   daddu    $a0, $v0, $zero
/* 19BABC 8026D1DC 8C820004 */  lw        $v0, 4($a0)
/* 19BAC0 8026D1E0 0809B47D */  j         .L8026D1F4
/* 19BAC4 8026D1E4 00531025 */   or       $v0, $v0, $s3
.L8026D1E8:
/* 19BAC8 8026D1E8 8C820004 */  lw        $v0, 4($a0)
/* 19BACC 8026D1EC 00131827 */  nor       $v1, $zero, $s3
/* 19BAD0 8026D1F0 00431024 */  and       $v0, $v0, $v1
.L8026D1F4:
/* 19BAD4 8026D1F4 AC820004 */  sw        $v0, 4($a0)
/* 19BAD8 8026D1F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19BADC 8026D1FC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19BAE0 8026D200 8FB20018 */  lw        $s2, 0x18($sp)
/* 19BAE4 8026D204 8FB10014 */  lw        $s1, 0x14($sp)
/* 19BAE8 8026D208 8FB00010 */  lw        $s0, 0x10($sp)
/* 19BAEC 8026D20C 24020002 */  addiu     $v0, $zero, 2
/* 19BAF0 8026D210 03E00008 */  jr        $ra
/* 19BAF4 8026D214 27BD0028 */   addiu    $sp, $sp, 0x28
