.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_case_greater
/* 0E9C18 802C5268 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9C1C 802C526C AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9C20 802C5270 0080882D */  daddu $s1, $a0, $zero
/* 0E9C24 802C5274 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E9C28 802C5278 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9C2C 802C527C 82300007 */  lb    $s0, 7($s1)
/* 0E9C30 802C5280 06010003 */  bgez  $s0, .L802C5290
/* 0E9C34 802C5284 8E25000C */   lw    $a1, 0xc($s1)
.L802C5288:
/* 0E9C38 802C5288 080B14A2 */  j     .L802C5288
/* 0E9C3C 802C528C 00000000 */   nop   

.L802C5290:
/* 0E9C40 802C5290 8CA50000 */  lw    $a1, ($a1)
/* 0E9C44 802C5294 0C0B1EAF */  jal   get_variable
/* 0E9C48 802C5298 0220202D */   daddu $a0, $s1, $zero
/* 0E9C4C 802C529C 0040282D */  daddu $a1, $v0, $zero
/* 0E9C50 802C52A0 00101080 */  sll   $v0, $s0, 2
/* 0E9C54 802C52A4 02221021 */  addu  $v0, $s1, $v0
/* 0E9C58 802C52A8 02302021 */  addu  $a0, $s1, $s0
/* 0E9C5C 802C52AC 80830110 */  lb    $v1, 0x110($a0)
/* 0E9C60 802C52B0 8C420118 */  lw    $v0, 0x118($v0)
/* 0E9C64 802C52B4 1C600005 */  bgtz  $v1, .L802C52CC
/* 0E9C68 802C52B8 00A2102A */   slt   $v0, $a1, $v0
/* 0E9C6C 802C52BC 0C0B2279 */  jal   si_goto_end_case
/* 0E9C70 802C52C0 0220202D */   daddu $a0, $s1, $zero
/* 0E9C74 802C52C4 080B14B8 */  j     .L802C52E0
/* 0E9C78 802C52C8 AE220008 */   sw    $v0, 8($s1)

.L802C52CC:
/* 0E9C7C 802C52CC 54400004 */  bnel  $v0, $zero, .L802C52E0
/* 0E9C80 802C52D0 A0800110 */   sb    $zero, 0x110($a0)
/* 0E9C84 802C52D4 0C0B2298 */  jal   si_goto_next_case
/* 0E9C88 802C52D8 0220202D */   daddu $a0, $s1, $zero
/* 0E9C8C 802C52DC AE220008 */  sw    $v0, 8($s1)
.L802C52E0:
/* 0E9C90 802C52E0 24020002 */  addiu $v0, $zero, 2
/* 0E9C94 802C52E4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9C98 802C52E8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9C9C 802C52EC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9CA0 802C52F0 03E00008 */  jr    $ra
/* 0E9CA4 802C52F4 27BD0020 */   addiu $sp, $sp, 0x20

