.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_does_script_exist
/* 0EB428 802C6A78 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EB42C 802C6A7C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EB430 802C6A80 0080882D */  daddu $s1, $a0, $zero
/* 0EB434 802C6A84 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EB438 802C6A88 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EB43C 802C6A8C 8E30000C */  lw    $s0, 0xc($s1)
/* 0EB440 802C6A90 8E050000 */  lw    $a1, ($s0)
/* 0EB444 802C6A94 0C0B1EAF */  jal   get_variable
/* 0EB448 802C6A98 26100004 */   addiu $s0, $s0, 4
/* 0EB44C 802C6A9C 8E100000 */  lw    $s0, ($s0)
/* 0EB450 802C6AA0 0C0B1059 */  jal   does_script_exist
/* 0EB454 802C6AA4 0040202D */   daddu $a0, $v0, $zero
/* 0EB458 802C6AA8 0220202D */  daddu $a0, $s1, $zero
/* 0EB45C 802C6AAC 0040302D */  daddu $a2, $v0, $zero
/* 0EB460 802C6AB0 0C0B2026 */  jal   set_variable
/* 0EB464 802C6AB4 0200282D */   daddu $a1, $s0, $zero
/* 0EB468 802C6AB8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EB46C 802C6ABC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EB470 802C6AC0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EB474 802C6AC4 24020002 */  addiu $v0, $zero, 2
/* 0EB478 802C6AC8 03E00008 */  jr    $ra
/* 0EB47C 802C6ACC 27BD0020 */   addiu $sp, $sp, 0x20

/* 0EB480 802C6AD0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB484 802C6AD4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EB488 802C6AD8 0080802D */  daddu $s0, $a0, $zero
/* 0EB48C 802C6ADC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EB490 802C6AE0 8E020014 */  lw    $v0, 0x14($s0)
/* 0EB494 802C6AE4 1440000F */  bnez  $v0, .L802C6B24
/* 0EB498 802C6AE8 00000000 */   nop   
/* 0EB49C 802C6AEC 8E040010 */  lw    $a0, 0x10($s0)
/* 0EB4A0 802C6AF0 8E050018 */  lw    $a1, 0x18($s0)
/* 0EB4A4 802C6AF4 0C0B0CF8 */  jal   start_script
/* 0EB4A8 802C6AF8 24060020 */   addiu $a2, $zero, 0x20
/* 0EB4AC 802C6AFC AE020014 */  sw    $v0, 0x14($s0)
/* 0EB4B0 802C6B00 8C430144 */  lw    $v1, 0x144($v0)
/* 0EB4B4 802C6B04 8E04001C */  lw    $a0, 0x1c($s0)
/* 0EB4B8 802C6B08 AE030034 */  sw    $v1, 0x34($s0)
/* 0EB4BC 802C6B0C AC440084 */  sw    $a0, 0x84($v0)
/* 0EB4C0 802C6B10 8E030020 */  lw    $v1, 0x20($s0)
/* 0EB4C4 802C6B14 AC430088 */  sw    $v1, 0x88($v0)
/* 0EB4C8 802C6B18 8E030024 */  lw    $v1, 0x24($s0)
/* 0EB4CC 802C6B1C AC50014C */  sw    $s0, 0x14c($v0)
/* 0EB4D0 802C6B20 AC43008C */  sw    $v1, 0x8c($v0)
.L802C6B24:
/* 0EB4D4 802C6B24 0C0B1059 */  jal   does_script_exist
/* 0EB4D8 802C6B28 8E040034 */   lw    $a0, 0x34($s0)
/* 0EB4DC 802C6B2C 14400005 */  bnez  $v0, .L802C6B44
/* 0EB4E0 802C6B30 2403FFFD */   addiu $v1, $zero, -3
/* 0EB4E4 802C6B34 8E020000 */  lw    $v0, ($s0)
/* 0EB4E8 802C6B38 AE000014 */  sw    $zero, 0x14($s0)
/* 0EB4EC 802C6B3C 00431024 */  and   $v0, $v0, $v1
/* 0EB4F0 802C6B40 AE020000 */  sw    $v0, ($s0)
.L802C6B44:
/* 0EB4F4 802C6B44 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EB4F8 802C6B48 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EB4FC 802C6B4C 03E00008 */  jr    $ra
/* 0EB500 802C6B50 27BD0018 */   addiu $sp, $sp, 0x18

