.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetBattleState
/* 19CA20 8026E140 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19CA24 8026E144 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19CA28 8026E148 8C82000C */  lw    $v0, 0xc($a0)
/* 19CA2C 8026E14C 3C06800E */  lui   $a2, 0x800e
/* 19CA30 8026E150 8CC6C068 */  lw    $a2, -0x3f98($a2)
/* 19CA34 8026E154 0C0B2026 */  jal   set_variable
/* 19CA38 8026E158 8C450000 */   lw    $a1, ($v0)
/* 19CA3C 8026E15C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19CA40 8026E160 24020002 */  addiu $v0, $zero, 2
/* 19CA44 8026E164 03E00008 */  jr    $ra
/* 19CA48 8026E168 27BD0018 */   addiu $sp, $sp, 0x18

/* 19CA4C 8026E16C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19CA50 8026E170 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19CA54 8026E174 8C82000C */  lw    $v0, 0xc($a0)
/* 19CA58 8026E178 0C0B1EAF */  jal   get_variable
/* 19CA5C 8026E17C 8C450000 */   lw    $a1, ($v0)
/* 19CA60 8026E180 0C090464 */  jal   func_80241190
/* 19CA64 8026E184 0040202D */   daddu $a0, $v0, $zero
/* 19CA68 8026E188 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19CA6C 8026E18C 24020002 */  addiu $v0, $zero, 2
/* 19CA70 8026E190 03E00008 */  jr    $ra
/* 19CA74 8026E194 27BD0018 */   addiu $sp, $sp, 0x18

/* 19CA78 8026E198 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19CA7C 8026E19C AFB00010 */  sw    $s0, 0x10($sp)
/* 19CA80 8026E1A0 3C10800E */  lui   $s0, 0x800e
/* 19CA84 8026E1A4 2610C070 */  addiu $s0, $s0, -0x3f90
/* 19CA88 8026E1A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 19CA8C 8026E1AC 10A00008 */  beqz  $a1, .L8026E1D0
/* 19CA90 8026E1B0 8C82000C */   lw    $v0, 0xc($a0)
/* 19CA94 8026E1B4 0C0B1EAF */  jal   get_variable
/* 19CA98 8026E1B8 8C450000 */   lw    $a1, ($v0)
/* 19CA9C 8026E1BC 0040182D */  daddu $v1, $v0, $zero
/* 19CAA0 8026E1C0 54600003 */  bnezl $v1, .L8026E1D0
/* 19CAA4 8026E1C4 A2030095 */   sb    $v1, 0x95($s0)
/* 19CAA8 8026E1C8 0809B87D */  j     .L8026E1F4
/* 19CAAC 8026E1CC A2000095 */   sb    $zero, 0x95($s0)

.L8026E1D0:
/* 19CAB0 8026E1D0 82030095 */  lb    $v1, 0x95($s0)
/* 19CAB4 8026E1D4 50600008 */  beql  $v1, $zero, .L8026E1F8
/* 19CAB8 8026E1D8 24020002 */   addiu $v0, $zero, 2
/* 19CABC 8026E1DC 3C02800E */  lui   $v0, 0x800e
/* 19CAC0 8026E1E0 8C42C068 */  lw    $v0, -0x3f98($v0)
/* 19CAC4 8026E1E4 00431026 */  xor   $v0, $v0, $v1
/* 19CAC8 8026E1E8 2C420001 */  sltiu $v0, $v0, 1
/* 19CACC 8026E1EC 0809B87E */  j     .L8026E1F8
/* 19CAD0 8026E1F0 00021040 */   sll   $v0, $v0, 1

.L8026E1F4:
/* 19CAD4 8026E1F4 24020002 */  addiu $v0, $zero, 2
.L8026E1F8:
.L8026E1F8:
/* 19CAD8 8026E1F8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19CADC 8026E1FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 19CAE0 8026E200 03E00008 */  jr    $ra
/* 19CAE4 8026E204 27BD0018 */   addiu $sp, $sp, 0x18

/* 19CAE8 8026E208 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19CAEC 8026E20C AFBF0014 */  sw    $ra, 0x14($sp)
/* 19CAF0 8026E210 AFB00010 */  sw    $s0, 0x10($sp)
/* 19CAF4 8026E214 8C82000C */  lw    $v0, 0xc($a0)
/* 19CAF8 8026E218 0C0B1EAF */  jal   get_variable
/* 19CAFC 8026E21C 8C450000 */   lw    $a1, ($v0)
/* 19CB00 8026E220 3C10800E */  lui   $s0, 0x800e
/* 19CB04 8026E224 2610C070 */  addiu $s0, $s0, -0x3f90
/* 19CB08 8026E228 0040182D */  daddu $v1, $v0, $zero
/* 19CB0C 8026E22C 10600005 */  beqz  $v1, .L8026E244
/* 19CB10 8026E230 24020001 */   addiu $v0, $zero, 1
/* 19CB14 8026E234 10620004 */  beq   $v1, $v0, .L8026E248
/* 19CB18 8026E238 2402FFFF */   addiu $v0, $zero, -1
/* 19CB1C 8026E23C 0809B893 */  j     .L8026E24C
/* 19CB20 8026E240 00000000 */   nop   

.L8026E244:
/* 19CB24 8026E244 24020001 */  addiu $v0, $zero, 1
.L8026E248:
/* 19CB28 8026E248 A2020094 */  sb    $v0, 0x94($s0)
.L8026E24C:
/* 19CB2C 8026E24C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19CB30 8026E250 8FB00010 */  lw    $s0, 0x10($sp)
/* 19CB34 8026E254 24020002 */  addiu $v0, $zero, 2
/* 19CB38 8026E258 03E00008 */  jr    $ra
/* 19CB3C 8026E25C 27BD0018 */   addiu $sp, $sp, 0x18

/* 19CB40 8026E260 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19CB44 8026E264 AFB20018 */  sw    $s2, 0x18($sp)
/* 19CB48 8026E268 0080902D */  daddu $s2, $a0, $zero
/* 19CB4C 8026E26C AFBF001C */  sw    $ra, 0x1c($sp)
/* 19CB50 8026E270 AFB10014 */  sw    $s1, 0x14($sp)
/* 19CB54 8026E274 AFB00010 */  sw    $s0, 0x10($sp)
/* 19CB58 8026E278 8E50000C */  lw    $s0, 0xc($s2)
/* 19CB5C 8026E27C 8E050000 */  lw    $a1, ($s0)
/* 19CB60 8026E280 0C0B1EAF */  jal   get_variable
/* 19CB64 8026E284 26100004 */   addiu $s0, $s0, 4
/* 19CB68 8026E288 0040882D */  daddu $s1, $v0, $zero
/* 19CB6C 8026E28C 8E050000 */  lw    $a1, ($s0)
/* 19CB70 8026E290 0C0B1EAF */  jal   get_variable
/* 19CB74 8026E294 0240202D */   daddu $a0, $s2, $zero
/* 19CB78 8026E298 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19CB7C 8026E29C 16220002 */  bne   $s1, $v0, .L8026E2A8
/* 19CB80 8026E2A0 00000000 */   nop   
/* 19CB84 8026E2A4 8E510148 */  lw    $s1, 0x148($s2)
.L8026E2A8:
/* 19CB88 8026E2A8 0C09A75B */  jal   get_actor
/* 19CB8C 8026E2AC 0220202D */   daddu $a0, $s1, $zero
/* 19CB90 8026E2B0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19CB94 8026E2B4 8FB20018 */  lw    $s2, 0x18($sp)
/* 19CB98 8026E2B8 8FB10014 */  lw    $s1, 0x14($sp)
/* 19CB9C 8026E2BC 8FB00010 */  lw    $s0, 0x10($sp)
/* 19CBA0 8026E2C0 24020002 */  addiu $v0, $zero, 2
/* 19CBA4 8026E2C4 03E00008 */  jr    $ra
/* 19CBA8 8026E2C8 27BD0020 */   addiu $sp, $sp, 0x20

