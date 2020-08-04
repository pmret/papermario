.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel try_inflict_status
/* 195458 80266B78 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 19545C 80266B7C AFB20018 */  sw    $s2, 0x18($sp)
/* 195460 80266B80 0080902D */  daddu $s2, $a0, $zero
/* 195464 80266B84 AFB40020 */  sw    $s4, 0x20($sp)
/* 195468 80266B88 00A0A02D */  daddu $s4, $a1, $zero
/* 19546C 80266B8C AFB50024 */  sw    $s5, 0x24($sp)
/* 195470 80266B90 AFB3001C */  sw    $s3, 0x1c($sp)
/* 195474 80266B94 3C13800E */  lui   $s3, 0x800e
/* 195478 80266B98 2673C070 */  addiu $s3, $s3, -0x3f90
/* 19547C 80266B9C AFBF0028 */  sw    $ra, 0x28($sp)
/* 195480 80266BA0 AFB10014 */  sw    $s1, 0x14($sp)
/* 195484 80266BA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 195488 80266BA8 92630194 */  lbu   $v1, 0x194($s3)
/* 19548C 80266BAC 240200FE */  addiu $v0, $zero, 0xfe
/* 195490 80266BB0 1462000C */  bne   $v1, $v0, .L80266BE4
/* 195494 80266BB4 00C0A82D */   daddu $s5, $a2, $zero
/* 195498 80266BB8 8E44020C */  lw    $a0, 0x20c($s2)
/* 19549C 80266BBC 82710195 */  lb    $s1, 0x195($s3)
/* 1954A0 80266BC0 0C0997BB */  jal   lookup_status_duration_mod
/* 1954A4 80266BC4 02A0282D */   daddu $a1, $s5, $zero
/* 1954A8 80266BC8 0240202D */  daddu $a0, $s2, $zero
/* 1954AC 80266BCC 0280282D */  daddu $a1, $s4, $zero
/* 1954B0 80266BD0 02A0302D */  daddu $a2, $s5, $zero
/* 1954B4 80266BD4 0C099B3C */  jal   inflict_status_set_duration
/* 1954B8 80266BD8 02223821 */   addu  $a3, $s1, $v0
/* 1954BC 80266BDC 08099B33 */  j     .L80266CCC
/* 1954C0 80266BE0 00000000 */   nop   

.L80266BE4:
/* 1954C4 80266BE4 8E44020C */  lw    $a0, 0x20c($s2)
/* 1954C8 80266BE8 10800026 */  beqz  $a0, .L80266C84
/* 1954CC 80266BEC 0000882D */   daddu $s1, $zero, $zero
/* 1954D0 80266BF0 8E620190 */  lw    $v0, 0x190($s3)
/* 1954D4 80266BF4 3C034000 */  lui   $v1, 0x4000
/* 1954D8 80266BF8 00431024 */  and   $v0, $v0, $v1
/* 1954DC 80266BFC 14400005 */  bnez  $v0, .L80266C14
/* 1954E0 80266C00 00000000 */   nop   
/* 1954E4 80266C04 0C0997A6 */  jal   lookup_status_chance
/* 1954E8 80266C08 0280282D */   daddu $a1, $s4, $zero
/* 1954EC 80266C0C 08099B09 */  j     .L80266C24
/* 1954F0 80266C10 0040802D */   daddu $s0, $v0, $zero

.L80266C14:
/* 1954F4 80266C14 0C0997A6 */  jal   lookup_status_chance
/* 1954F8 80266C18 0280282D */   daddu $a1, $s4, $zero
/* 1954FC 80266C1C 1040001A */  beqz  $v0, .L80266C88
/* 195500 80266C20 24100064 */   addiu $s0, $zero, 0x64
.L80266C24:
/* 195504 80266C24 1A000018 */  blez  $s0, .L80266C88
/* 195508 80266C28 3C0351EB */   lui   $v1, 0x51eb
/* 19550C 80266C2C 92620194 */  lbu   $v0, 0x194($s3)
/* 195510 80266C30 02020018 */  mult  $s0, $v0
/* 195514 80266C34 00001012 */  mflo  $v0
/* 195518 80266C38 3463851F */  ori   $v1, $v1, 0x851f
/* 19551C 80266C3C 00000000 */  nop   
/* 195520 80266C40 00430018 */  mult  $v0, $v1
/* 195524 80266C44 000217C3 */  sra   $v0, $v0, 0x1f
/* 195528 80266C48 00001810 */  mfhi  $v1
/* 19552C 80266C4C 00031943 */  sra   $v1, $v1, 5
/* 195530 80266C50 00628023 */  subu  $s0, $v1, $v0
/* 195534 80266C54 1A00000C */  blez  $s0, .L80266C88
/* 195538 80266C58 00000000 */   nop   
/* 19553C 80266C5C 0C00A67F */  jal   rand_int
/* 195540 80266C60 24040064 */   addiu $a0, $zero, 0x64
/* 195544 80266C64 0202102A */  slt   $v0, $s0, $v0
/* 195548 80266C68 14400007 */  bnez  $v0, .L80266C88
/* 19554C 80266C6C 00000000 */   nop   
/* 195550 80266C70 8E44020C */  lw    $a0, 0x20c($s2)
/* 195554 80266C74 0C0997BB */  jal   lookup_status_duration_mod
/* 195558 80266C78 02A0282D */   daddu $a1, $s5, $zero
/* 19555C 80266C7C 08099B22 */  j     .L80266C88
/* 195560 80266C80 24510003 */   addiu $s1, $v0, 3

.L80266C84:
/* 195564 80266C84 24110003 */  addiu $s1, $zero, 3
.L80266C88:
.L80266C88:
/* 195568 80266C88 5A20000F */  blezl $s1, .L80266CC8
/* 19556C 80266C8C 0000882D */   daddu $s1, $zero, $zero
/* 195570 80266C90 8E620190 */  lw    $v0, 0x190($s3)
/* 195574 80266C94 04410007 */  bgez  $v0, .L80266CB4
/* 195578 80266C98 0240202D */   daddu $a0, $s2, $zero
/* 19557C 80266C9C 8E44020C */  lw    $a0, 0x20c($s2)
/* 195580 80266CA0 82710195 */  lb    $s1, 0x195($s3)
/* 195584 80266CA4 0C0997BB */  jal   lookup_status_duration_mod
/* 195588 80266CA8 02A0282D */   daddu $a1, $s5, $zero
/* 19558C 80266CAC 02228821 */  addu  $s1, $s1, $v0
/* 195590 80266CB0 0240202D */  daddu $a0, $s2, $zero
.L80266CB4:
/* 195594 80266CB4 0280282D */  daddu $a1, $s4, $zero
/* 195598 80266CB8 0C0997D0 */  jal   inflict_status
/* 19559C 80266CBC 0220302D */   daddu $a2, $s1, $zero
/* 1955A0 80266CC0 08099B33 */  j     .L80266CCC
/* 1955A4 80266CC4 0220102D */   daddu $v0, $s1, $zero

.L80266CC8:
/* 1955A8 80266CC8 0220102D */  daddu $v0, $s1, $zero
.L80266CCC:
/* 1955AC 80266CCC 8FBF0028 */  lw    $ra, 0x28($sp)
/* 1955B0 80266CD0 8FB50024 */  lw    $s5, 0x24($sp)
/* 1955B4 80266CD4 8FB40020 */  lw    $s4, 0x20($sp)
/* 1955B8 80266CD8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1955BC 80266CDC 8FB20018 */  lw    $s2, 0x18($sp)
/* 1955C0 80266CE0 8FB10014 */  lw    $s1, 0x14($sp)
/* 1955C4 80266CE4 8FB00010 */  lw    $s0, 0x10($sp)
/* 1955C8 80266CE8 03E00008 */  jr    $ra
/* 1955CC 80266CEC 27BD0030 */   addiu $sp, $sp, 0x30

