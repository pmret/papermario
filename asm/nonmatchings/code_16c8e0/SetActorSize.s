.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetActorSize
/* 1AC0F0 8027D810 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1AC0F4 8027D814 AFB20018 */  sw    $s2, 0x18($sp)
/* 1AC0F8 8027D818 0080902D */  daddu $s2, $a0, $zero
/* 1AC0FC 8027D81C AFBF0020 */  sw    $ra, 0x20($sp)
/* 1AC100 8027D820 AFB3001C */  sw    $s3, 0x1c($sp)
/* 1AC104 8027D824 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AC108 8027D828 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AC10C 8027D82C 8E50000C */  lw    $s0, 0xc($s2)
/* 1AC110 8027D830 8E050000 */  lw    $a1, ($s0)
/* 1AC114 8027D834 0C0B1EAF */  jal   get_variable
/* 1AC118 8027D838 26100004 */   addiu $s0, $s0, 4
/* 1AC11C 8027D83C 0040882D */  daddu $s1, $v0, $zero
/* 1AC120 8027D840 8E050000 */  lw    $a1, ($s0)
/* 1AC124 8027D844 26100004 */  addiu $s0, $s0, 4
/* 1AC128 8027D848 0C0B1EAF */  jal   get_variable
/* 1AC12C 8027D84C 0240202D */   daddu $a0, $s2, $zero
/* 1AC130 8027D850 0240202D */  daddu $a0, $s2, $zero
/* 1AC134 8027D854 8E050000 */  lw    $a1, ($s0)
/* 1AC138 8027D858 0C0B1EAF */  jal   get_variable
/* 1AC13C 8027D85C 0040802D */   daddu $s0, $v0, $zero
/* 1AC140 8027D860 0040982D */  daddu $s3, $v0, $zero
/* 1AC144 8027D864 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AC148 8027D868 16220002 */  bne   $s1, $v0, .L8027D874
/* 1AC14C 8027D86C 00000000 */   nop   
/* 1AC150 8027D870 8E510148 */  lw    $s1, 0x148($s2)
.L8027D874:
/* 1AC154 8027D874 0C09A75B */  jal   get_actor
/* 1AC158 8027D878 0220202D */   daddu $a0, $s1, $zero
/* 1AC15C 8027D87C 3C03F119 */  lui   $v1, 0xf119
/* 1AC160 8027D880 34634D80 */  ori   $v1, $v1, 0x4d80
/* 1AC164 8027D884 12030002 */  beq   $s0, $v1, .L8027D890
/* 1AC168 8027D888 0040202D */   daddu $a0, $v0, $zero
/* 1AC16C 8027D88C A0900191 */  sb    $s0, 0x191($a0)
.L8027D890:
/* 1AC170 8027D890 56630001 */  bnel  $s3, $v1, .L8027D898
/* 1AC174 8027D894 A0930190 */   sb    $s3, 0x190($a0)
.L8027D898:
/* 1AC178 8027D898 90830190 */  lbu   $v1, 0x190($a0)
/* 1AC17C 8027D89C 3C014038 */  lui   $at, 0x4038
/* 1AC180 8027D8A0 44811800 */  mtc1  $at, $f3
/* 1AC184 8027D8A4 44801000 */  mtc1  $zero, $f2
/* 1AC188 8027D8A8 44830000 */  mtc1  $v1, $f0
/* 1AC18C 8027D8AC 00000000 */  nop   
/* 1AC190 8027D8B0 46800021 */  cvt.d.w $f0, $f0
/* 1AC194 8027D8B4 46220003 */  div.d $f0, $f0, $f2
/* 1AC198 8027D8B8 46200020 */  cvt.s.d $f0, $f0
/* 1AC19C 8027D8BC E4800430 */  swc1  $f0, 0x430($a0)
/* 1AC1A0 8027D8C0 8FBF0020 */  lw    $ra, 0x20($sp)
/* 1AC1A4 8027D8C4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1AC1A8 8027D8C8 8FB20018 */  lw    $s2, 0x18($sp)
/* 1AC1AC 8027D8CC 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AC1B0 8027D8D0 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AC1B4 8027D8D4 24020002 */  addiu $v0, $zero, 2
/* 1AC1B8 8027D8D8 03E00008 */  jr    $ra
/* 1AC1BC 8027D8DC 27BD0028 */   addiu $sp, $sp, 0x28

