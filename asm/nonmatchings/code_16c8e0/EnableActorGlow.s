.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel EnableActorGlow
/* 1AC484 8027DBA4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1AC488 8027DBA8 AFB20028 */  sw    $s2, 0x28($sp)
/* 1AC48C 8027DBAC 0080902D */  daddu $s2, $a0, $zero
/* 1AC490 8027DBB0 AFBF002C */  sw    $ra, 0x2c($sp)
/* 1AC494 8027DBB4 AFB10024 */  sw    $s1, 0x24($sp)
/* 1AC498 8027DBB8 AFB00020 */  sw    $s0, 0x20($sp)
/* 1AC49C 8027DBBC 8E51000C */  lw    $s1, 0xc($s2)
/* 1AC4A0 8027DBC0 8E250000 */  lw    $a1, ($s1)
/* 1AC4A4 8027DBC4 0C0B1EAF */  jal   get_variable
/* 1AC4A8 8027DBC8 26310004 */   addiu $s1, $s1, 4
/* 1AC4AC 8027DBCC 0040802D */  daddu $s0, $v0, $zero
/* 1AC4B0 8027DBD0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AC4B4 8027DBD4 16020002 */  bne   $s0, $v0, .L8027DBE0
/* 1AC4B8 8027DBD8 00000000 */   nop   
/* 1AC4BC 8027DBDC 8E500148 */  lw    $s0, 0x148($s2)
.L8027DBE0:
/* 1AC4C0 8027DBE0 8E250000 */  lw    $a1, ($s1)
/* 1AC4C4 8027DBE4 0C0B1EAF */  jal   get_variable
/* 1AC4C8 8027DBE8 0240202D */   daddu $a0, $s2, $zero
/* 1AC4CC 8027DBEC 0200202D */  daddu $a0, $s0, $zero
/* 1AC4D0 8027DBF0 0C09A75B */  jal   get_actor
/* 1AC4D4 8027DBF4 0040802D */   daddu $s0, $v0, $zero
/* 1AC4D8 8027DBF8 0040882D */  daddu $s1, $v0, $zero
/* 1AC4DC 8027DBFC 16000013 */  bnez  $s0, .L8027DC4C
/* 1AC4E0 8027DC00 A2300220 */   sb    $s0, 0x220($s1)
/* 1AC4E4 8027DC04 8E3001F4 */  lw    $s0, 0x1f4($s1)
/* 1AC4E8 8027DC08 1200000E */  beqz  $s0, .L8027DC44
/* 1AC4EC 8027DC0C 0220202D */   daddu $a0, $s1, $zero
.L8027DC10:
/* 1AC4F0 8027DC10 8E020094 */  lw    $v0, 0x94($s0)
/* 1AC4F4 8027DC14 10400008 */  beqz  $v0, .L8027DC38
/* 1AC4F8 8027DC18 0000282D */   daddu $a1, $zero, $zero
/* 1AC4FC 8027DC1C 00A0302D */  daddu $a2, $a1, $zero
/* 1AC500 8027DC20 AFA00010 */  sw    $zero, 0x10($sp)
/* 1AC504 8027DC24 AFA00014 */  sw    $zero, 0x14($sp)
/* 1AC508 8027DC28 AFA00018 */  sw    $zero, 0x18($sp)
/* 1AC50C 8027DC2C 8E040084 */  lw    $a0, 0x84($s0)
/* 1AC510 8027DC30 0C0B7A25 */  jal   func_802DE894
/* 1AC514 8027DC34 00A0382D */   daddu $a3, $a1, $zero
.L8027DC38:
/* 1AC518 8027DC38 8E10000C */  lw    $s0, 0xc($s0)
/* 1AC51C 8027DC3C 1600FFF4 */  bnez  $s0, .L8027DC10
/* 1AC520 8027DC40 0220202D */   daddu $a0, $s1, $zero
.L8027DC44:
/* 1AC524 8027DC44 0C099BBA */  jal   func_80266EE8
/* 1AC528 8027DC48 0000282D */   daddu $a1, $zero, $zero
.L8027DC4C:
/* 1AC52C 8027DC4C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 1AC530 8027DC50 8FB20028 */  lw    $s2, 0x28($sp)
/* 1AC534 8027DC54 8FB10024 */  lw    $s1, 0x24($sp)
/* 1AC538 8027DC58 8FB00020 */  lw    $s0, 0x20($sp)
/* 1AC53C 8027DC5C 24020002 */  addiu $v0, $zero, 2
/* 1AC540 8027DC60 03E00008 */  jr    $ra
/* 1AC544 8027DC64 27BD0030 */   addiu $sp, $sp, 0x30

