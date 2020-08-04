.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_case_greater_equal
/* 0E9CA8 802C52F8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9CAC 802C52FC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9CB0 802C5300 0080882D */  daddu $s1, $a0, $zero
/* 0E9CB4 802C5304 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E9CB8 802C5308 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9CBC 802C530C 82300007 */  lb    $s0, 7($s1)
/* 0E9CC0 802C5310 06010003 */  bgez  $s0, .L802C5320
/* 0E9CC4 802C5314 8E25000C */   lw    $a1, 0xc($s1)
.L802C5318:
/* 0E9CC8 802C5318 080B14C6 */  j     .L802C5318
/* 0E9CCC 802C531C 00000000 */   nop   

.L802C5320:
/* 0E9CD0 802C5320 8CA50000 */  lw    $a1, ($a1)
/* 0E9CD4 802C5324 0C0B1EAF */  jal   get_variable
/* 0E9CD8 802C5328 0220202D */   daddu $a0, $s1, $zero
/* 0E9CDC 802C532C 0040282D */  daddu $a1, $v0, $zero
/* 0E9CE0 802C5330 00101080 */  sll   $v0, $s0, 2
/* 0E9CE4 802C5334 02221021 */  addu  $v0, $s1, $v0
/* 0E9CE8 802C5338 02302021 */  addu  $a0, $s1, $s0
/* 0E9CEC 802C533C 80830110 */  lb    $v1, 0x110($a0)
/* 0E9CF0 802C5340 8C420118 */  lw    $v0, 0x118($v0)
/* 0E9CF4 802C5344 1C600005 */  bgtz  $v1, .L802C535C
/* 0E9CF8 802C5348 0045102A */   slt   $v0, $v0, $a1
/* 0E9CFC 802C534C 0C0B2279 */  jal   si_goto_end_case
/* 0E9D00 802C5350 0220202D */   daddu $a0, $s1, $zero
/* 0E9D04 802C5354 080B14DC */  j     .L802C5370
/* 0E9D08 802C5358 AE220008 */   sw    $v0, 8($s1)

.L802C535C:
/* 0E9D0C 802C535C 50400004 */  beql  $v0, $zero, .L802C5370
/* 0E9D10 802C5360 A0800110 */   sb    $zero, 0x110($a0)
/* 0E9D14 802C5364 0C0B2298 */  jal   si_goto_next_case
/* 0E9D18 802C5368 0220202D */   daddu $a0, $s1, $zero
/* 0E9D1C 802C536C AE220008 */  sw    $v0, 8($s1)
.L802C5370:
/* 0E9D20 802C5370 24020002 */  addiu $v0, $zero, 2
/* 0E9D24 802C5374 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9D28 802C5378 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9D2C 802C537C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9D30 802C5380 03E00008 */  jr    $ra
/* 0E9D34 802C5384 27BD0020 */   addiu $sp, $sp, 0x20

