.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetEncounterStatusFlags
/* 01F580 80044180 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 01F584 80044184 AFB10014 */  sw    $s1, 0x14($sp)
/* 01F588 80044188 3C11800B */  lui   $s1, 0x800b
/* 01F58C 8004418C 26310F10 */  addiu $s1, $s1, 0xf10
/* 01F590 80044190 AFBF001C */  sw    $ra, 0x1c($sp)
/* 01F594 80044194 AFB20018 */  sw    $s2, 0x18($sp)
/* 01F598 80044198 AFB00010 */  sw    $s0, 0x10($sp)
/* 01F59C 8004419C 8C82000C */  lw    $v0, 0xc($a0)
/* 01F5A0 800441A0 8C450004 */  lw    $a1, 4($v0)
/* 01F5A4 800441A4 8C500000 */  lw    $s0, ($v0)
/* 01F5A8 800441A8 0C0B1EAF */  jal   get_variable
/* 01F5AC 800441AC 0220902D */   daddu $s2, $s1, $zero
/* 01F5B0 800441B0 10400005 */  beqz  $v0, .L800441C8
/* 01F5B4 800441B4 00101827 */   nor   $v1, $zero, $s0
/* 01F5B8 800441B8 8E220000 */  lw    $v0, ($s1)
/* 01F5BC 800441BC 00501025 */  or    $v0, $v0, $s0
/* 01F5C0 800441C0 08011075 */  j     .L800441D4
/* 01F5C4 800441C4 AE220000 */   sw    $v0, ($s1)

.L800441C8:
/* 01F5C8 800441C8 8E420000 */  lw    $v0, ($s2)
/* 01F5CC 800441CC 00431024 */  and   $v0, $v0, $v1
/* 01F5D0 800441D0 AE420000 */  sw    $v0, ($s2)
.L800441D4:
/* 01F5D4 800441D4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 01F5D8 800441D8 8FB20018 */  lw    $s2, 0x18($sp)
/* 01F5DC 800441DC 8FB10014 */  lw    $s1, 0x14($sp)
/* 01F5E0 800441E0 8FB00010 */  lw    $s0, 0x10($sp)
/* 01F5E4 800441E4 24020002 */  addiu $v0, $zero, 2
/* 01F5E8 800441E8 03E00008 */  jr    $ra
/* 01F5EC 800441EC 27BD0020 */   addiu $sp, $sp, 0x20

/* 01F5F0 800441F0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 01F5F4 800441F4 AFB00010 */  sw    $s0, 0x10($sp)
/* 01F5F8 800441F8 0080802D */  daddu $s0, $a0, $zero
/* 01F5FC 800441FC AFBF0018 */  sw    $ra, 0x18($sp)
/* 01F600 80044200 AFB10014 */  sw    $s1, 0x14($sp)
/* 01F604 80044204 8E02000C */  lw    $v0, 0xc($s0)
/* 01F608 80044208 0C011052 */  jal   func_80044148
/* 01F60C 8004420C 8C510000 */   lw    $s1, ($v0)
/* 01F610 80044210 0200202D */  daddu $a0, $s0, $zero
/* 01F614 80044214 0040302D */  daddu $a2, $v0, $zero
/* 01F618 80044218 0C0B2026 */  jal   set_variable
/* 01F61C 8004421C 0220282D */   daddu $a1, $s1, $zero
/* 01F620 80044220 8FBF0018 */  lw    $ra, 0x18($sp)
/* 01F624 80044224 8FB10014 */  lw    $s1, 0x14($sp)
/* 01F628 80044228 8FB00010 */  lw    $s0, 0x10($sp)
/* 01F62C 8004422C 24020002 */  addiu $v0, $zero, 2
/* 01F630 80044230 03E00008 */  jr    $ra
/* 01F634 80044234 27BD0020 */   addiu $sp, $sp, 0x20

/* 01F638 80044238 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01F63C 8004423C AFBF0010 */  sw    $ra, 0x10($sp)
/* 01F640 80044240 8C82000C */  lw    $v0, 0xc($a0)
/* 01F644 80044244 0C0B1EAF */  jal   get_variable
/* 01F648 80044248 8C450000 */   lw    $a1, ($v0)
/* 01F64C 8004424C 0C01CAF3 */  jal   func_80072BCC
/* 01F650 80044250 0040202D */   daddu $a0, $v0, $zero
/* 01F654 80044254 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01F658 80044258 24020002 */  addiu $v0, $zero, 2
/* 01F65C 8004425C 03E00008 */  jr    $ra
/* 01F660 80044260 27BD0018 */   addiu $sp, $sp, 0x18

