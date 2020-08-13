.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetActorPos
/* 199720 8026AE40 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 199724 8026AE44 AFB20018 */  sw    $s2, 0x18($sp)
/* 199728 8026AE48 0080902D */  daddu $s2, $a0, $zero
/* 19972C 8026AE4C AFBF001C */  sw    $ra, 0x1c($sp)
/* 199730 8026AE50 AFB10014 */  sw    $s1, 0x14($sp)
/* 199734 8026AE54 AFB00010 */  sw    $s0, 0x10($sp)
/* 199738 8026AE58 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 19973C 8026AE5C F7B60028 */  sdc1  $f22, 0x28($sp)
/* 199740 8026AE60 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 199744 8026AE64 8E50000C */  lw    $s0, 0xc($s2)
/* 199748 8026AE68 8E050000 */  lw    $a1, ($s0)
/* 19974C 8026AE6C 0C0B1EAF */  jal   get_variable
/* 199750 8026AE70 26100004 */   addiu $s0, $s0, 4
/* 199754 8026AE74 0040882D */  daddu $s1, $v0, $zero
/* 199758 8026AE78 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19975C 8026AE7C 16220002 */  bne   $s1, $v0, .L8026AE88
/* 199760 8026AE80 00000000 */   nop   
/* 199764 8026AE84 8E510148 */  lw    $s1, 0x148($s2)
.L8026AE88:
/* 199768 8026AE88 8E050000 */  lw    $a1, ($s0)
/* 19976C 8026AE8C 26100004 */  addiu $s0, $s0, 4
/* 199770 8026AE90 0C0B1EAF */  jal   get_variable
/* 199774 8026AE94 0240202D */   daddu $a0, $s2, $zero
/* 199778 8026AE98 8E050000 */  lw    $a1, ($s0)
/* 19977C 8026AE9C 26100004 */  addiu $s0, $s0, 4
/* 199780 8026AEA0 4482C000 */  mtc1  $v0, $f24
/* 199784 8026AEA4 00000000 */  nop   
/* 199788 8026AEA8 4680C620 */  cvt.s.w $f24, $f24
/* 19978C 8026AEAC 0C0B1EAF */  jal   get_variable
/* 199790 8026AEB0 0240202D */   daddu $a0, $s2, $zero
/* 199794 8026AEB4 8E050000 */  lw    $a1, ($s0)
/* 199798 8026AEB8 4482B000 */  mtc1  $v0, $f22
/* 19979C 8026AEBC 00000000 */  nop   
/* 1997A0 8026AEC0 4680B5A0 */  cvt.s.w $f22, $f22
/* 1997A4 8026AEC4 0C0B1EAF */  jal   get_variable
/* 1997A8 8026AEC8 0240202D */   daddu $a0, $s2, $zero
/* 1997AC 8026AECC 4482A000 */  mtc1  $v0, $f20
/* 1997B0 8026AED0 00000000 */  nop   
/* 1997B4 8026AED4 4680A520 */  cvt.s.w $f20, $f20
/* 1997B8 8026AED8 0C09A75B */  jal   get_actor
/* 1997BC 8026AEDC 0220202D */   daddu $a0, $s1, $zero
/* 1997C0 8026AEE0 0040182D */  daddu $v1, $v0, $zero
/* 1997C4 8026AEE4 E4780144 */  swc1  $f24, 0x144($v1)
/* 1997C8 8026AEE8 E4760148 */  swc1  $f22, 0x148($v1)
/* 1997CC 8026AEEC E474014C */  swc1  $f20, 0x14c($v1)
/* 1997D0 8026AEF0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1997D4 8026AEF4 8FB20018 */  lw    $s2, 0x18($sp)
/* 1997D8 8026AEF8 8FB10014 */  lw    $s1, 0x14($sp)
/* 1997DC 8026AEFC 8FB00010 */  lw    $s0, 0x10($sp)
/* 1997E0 8026AF00 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 1997E4 8026AF04 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 1997E8 8026AF08 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 1997EC 8026AF0C 24020002 */  addiu $v0, $zero, 2
/* 1997F0 8026AF10 03E00008 */  jr    $ra
/* 1997F4 8026AF14 27BD0038 */   addiu $sp, $sp, 0x38

