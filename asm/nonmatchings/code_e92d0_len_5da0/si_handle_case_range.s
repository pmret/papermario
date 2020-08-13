.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_case_range
/* 0E9D38 802C5388 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9D3C 802C538C AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9D40 802C5390 0080882D */  daddu $s1, $a0, $zero
/* 0E9D44 802C5394 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E9D48 802C5398 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E9D4C 802C539C AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9D50 802C53A0 82320007 */  lb    $s2, 7($s1)
/* 0E9D54 802C53A4 06410003 */  bgez  $s2, .L802C53B4
/* 0E9D58 802C53A8 8E30000C */   lw    $s0, 0xc($s1)
.L802C53AC:
/* 0E9D5C 802C53AC 080B14EB */  j     .L802C53AC
/* 0E9D60 802C53B0 00000000 */   nop   

.L802C53B4:
/* 0E9D64 802C53B4 8E050000 */  lw    $a1, ($s0)
/* 0E9D68 802C53B8 26100004 */  addiu $s0, $s0, 4
/* 0E9D6C 802C53BC 0C0B1EAF */  jal   get_variable
/* 0E9D70 802C53C0 0220202D */   daddu $a0, $s1, $zero
/* 0E9D74 802C53C4 0220202D */  daddu $a0, $s1, $zero
/* 0E9D78 802C53C8 8E050000 */  lw    $a1, ($s0)
/* 0E9D7C 802C53CC 0C0B1EAF */  jal   get_variable
/* 0E9D80 802C53D0 0040802D */   daddu $s0, $v0, $zero
/* 0E9D84 802C53D4 0040302D */  daddu $a2, $v0, $zero
/* 0E9D88 802C53D8 00121080 */  sll   $v0, $s2, 2
/* 0E9D8C 802C53DC 02221021 */  addu  $v0, $s1, $v0
/* 0E9D90 802C53E0 02322821 */  addu  $a1, $s1, $s2
/* 0E9D94 802C53E4 80A30110 */  lb    $v1, 0x110($a1)
/* 0E9D98 802C53E8 8C440118 */  lw    $a0, 0x118($v0)
/* 0E9D9C 802C53EC 1C600005 */  bgtz  $v1, .L802C5404
/* 0E9DA0 802C53F0 0090102A */   slt   $v0, $a0, $s0
/* 0E9DA4 802C53F4 0C0B2279 */  jal   si_goto_end_case
/* 0E9DA8 802C53F8 0220202D */   daddu $a0, $s1, $zero
/* 0E9DAC 802C53FC 080B150A */  j     .L802C5428
/* 0E9DB0 802C5400 AE220008 */   sw    $v0, 8($s1)

.L802C5404:
/* 0E9DB4 802C5404 14400005 */  bnez  $v0, .L802C541C
/* 0E9DB8 802C5408 00C4102A */   slt   $v0, $a2, $a0
/* 0E9DBC 802C540C 14400003 */  bnez  $v0, .L802C541C
/* 0E9DC0 802C5410 00000000 */   nop   
/* 0E9DC4 802C5414 080B150A */  j     .L802C5428
/* 0E9DC8 802C5418 A0A00110 */   sb    $zero, 0x110($a1)

.L802C541C:
/* 0E9DCC 802C541C 0C0B2298 */  jal   si_goto_next_case
/* 0E9DD0 802C5420 0220202D */   daddu $a0, $s1, $zero
/* 0E9DD4 802C5424 AE220008 */  sw    $v0, 8($s1)
.L802C5428:
/* 0E9DD8 802C5428 24020002 */  addiu $v0, $zero, 2
/* 0E9DDC 802C542C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E9DE0 802C5430 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E9DE4 802C5434 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9DE8 802C5438 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9DEC 802C543C 03E00008 */  jr    $ra
/* 0E9DF0 802C5440 27BD0020 */   addiu $sp, $sp, 0x20

