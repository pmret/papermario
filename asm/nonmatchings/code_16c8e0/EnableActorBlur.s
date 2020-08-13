.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel EnableActorBlur
/* 1ABE5C 8027D57C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1ABE60 8027D580 AFB20018 */  sw    $s2, 0x18($sp)
/* 1ABE64 8027D584 0080902D */  daddu $s2, $a0, $zero
/* 1ABE68 8027D588 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1ABE6C 8027D58C AFB10014 */  sw    $s1, 0x14($sp)
/* 1ABE70 8027D590 AFB00010 */  sw    $s0, 0x10($sp)
/* 1ABE74 8027D594 8E50000C */  lw    $s0, 0xc($s2)
/* 1ABE78 8027D598 8E050000 */  lw    $a1, ($s0)
/* 1ABE7C 8027D59C 0C0B1EAF */  jal   get_variable
/* 1ABE80 8027D5A0 26100004 */   addiu $s0, $s0, 4
/* 1ABE84 8027D5A4 0040882D */  daddu $s1, $v0, $zero
/* 1ABE88 8027D5A8 8E050000 */  lw    $a1, ($s0)
/* 1ABE8C 8027D5AC 0C0B1EAF */  jal   get_variable
/* 1ABE90 8027D5B0 0240202D */   daddu $a0, $s2, $zero
/* 1ABE94 8027D5B4 0040802D */  daddu $s0, $v0, $zero
/* 1ABE98 8027D5B8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1ABE9C 8027D5BC 16220002 */  bne   $s1, $v0, .L8027D5C8
/* 1ABEA0 8027D5C0 00000000 */   nop   
/* 1ABEA4 8027D5C4 8E510148 */  lw    $s1, 0x148($s2)
.L8027D5C8:
/* 1ABEA8 8027D5C8 0C09A75B */  jal   get_actor
/* 1ABEAC 8027D5CC 0220202D */   daddu $a0, $s1, $zero
/* 1ABEB0 8027D5D0 16000005 */  bnez  $s0, .L8027D5E8
/* 1ABEB4 8027D5D4 0040202D */   daddu $a0, $v0, $zero
/* 1ABEB8 8027D5D8 0C095157 */  jal   disable_actor_blur
/* 1ABEBC 8027D5DC 00000000 */   nop   
/* 1ABEC0 8027D5E0 0809F583 */  j     .L8027D60C
/* 1ABEC4 8027D5E4 00000000 */   nop   

.L8027D5E8:
/* 1ABEC8 8027D5E8 24020001 */  addiu $v0, $zero, 1
/* 1ABECC 8027D5EC 16020005 */  bne   $s0, $v0, .L8027D604
/* 1ABED0 8027D5F0 00000000 */   nop   
/* 1ABED4 8027D5F4 0C0950B3 */  jal   enable_actor_blur
/* 1ABED8 8027D5F8 00000000 */   nop   
/* 1ABEDC 8027D5FC 0809F583 */  j     .L8027D60C
/* 1ABEE0 8027D600 00000000 */   nop   

.L8027D604:
/* 1ABEE4 8027D604 0C09516B */  jal   func_802545AC
/* 1ABEE8 8027D608 00000000 */   nop   
.L8027D60C:
/* 1ABEEC 8027D60C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1ABEF0 8027D610 8FB20018 */  lw    $s2, 0x18($sp)
/* 1ABEF4 8027D614 8FB10014 */  lw    $s1, 0x14($sp)
/* 1ABEF8 8027D618 8FB00010 */  lw    $s0, 0x10($sp)
/* 1ABEFC 8027D61C 24020002 */  addiu $v0, $zero, 2
/* 1ABF00 8027D620 03E00008 */  jr    $ra
/* 1ABF04 8027D624 27BD0020 */   addiu $sp, $sp, 0x20

/* 1ABF08 8027D628 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1ABF0C 8027D62C AFB00010 */  sw    $s0, 0x10($sp)
/* 1ABF10 8027D630 0080802D */  daddu $s0, $a0, $zero
/* 1ABF14 8027D634 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1ABF18 8027D638 8E02000C */  lw    $v0, 0xc($s0)
/* 1ABF1C 8027D63C 0C0B1EAF */  jal   get_variable
/* 1ABF20 8027D640 8C450000 */   lw    $a1, ($v0)
/* 1ABF24 8027D644 0040202D */  daddu $a0, $v0, $zero
/* 1ABF28 8027D648 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1ABF2C 8027D64C 14820002 */  bne   $a0, $v0, .L8027D658
/* 1ABF30 8027D650 00000000 */   nop   
/* 1ABF34 8027D654 8E040148 */  lw    $a0, 0x148($s0)
.L8027D658:
/* 1ABF38 8027D658 0C09A75B */  jal   get_actor
/* 1ABF3C 8027D65C 00000000 */   nop   
/* 1ABF40 8027D660 0C095184 */  jal   func_80254610
/* 1ABF44 8027D664 0040202D */   daddu $a0, $v0, $zero
/* 1ABF48 8027D668 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1ABF4C 8027D66C 8FB00010 */  lw    $s0, 0x10($sp)
/* 1ABF50 8027D670 24020002 */  addiu $v0, $zero, 2
/* 1ABF54 8027D674 03E00008 */  jr    $ra
/* 1ABF58 8027D678 27BD0018 */   addiu $sp, $sp, 0x18

