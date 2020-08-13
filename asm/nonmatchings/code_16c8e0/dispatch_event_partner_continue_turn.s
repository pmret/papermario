.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel dispatch_event_partner_continue_turn
/* 1AC7EC 8027DF0C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1AC7F0 8027DF10 2405000A */  addiu $a1, $zero, 0xa
/* 1AC7F4 8027DF14 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AC7F8 8027DF18 3C10800E */  lui   $s0, 0x800e
/* 1AC7FC 8027DF1C 8E10C14C */  lw    $s0, -0x3eb4($s0)
/* 1AC800 8027DF20 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1AC804 8027DF24 AFB20018 */  sw    $s2, 0x18($sp)
/* 1AC808 8027DF28 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AC80C 8027DF2C A20401F0 */  sb    $a0, 0x1f0($s0)
/* 1AC810 8027DF30 8E0401C8 */  lw    $a0, 0x1c8($s0)
/* 1AC814 8027DF34 8E1101D8 */  lw    $s1, 0x1d8($s0)
/* 1AC818 8027DF38 8E1201E8 */  lw    $s2, 0x1e8($s0)
/* 1AC81C 8027DF3C 0C0B0CF8 */  jal   start_script
/* 1AC820 8027DF40 24060020 */   addiu $a2, $zero, 0x20
/* 1AC824 8027DF44 AE0201D8 */  sw    $v0, 0x1d8($s0)
/* 1AC828 8027DF48 8C430144 */  lw    $v1, 0x144($v0)
/* 1AC82C 8027DF4C AE0301E8 */  sw    $v1, 0x1e8($s0)
/* 1AC830 8027DF50 24030100 */  addiu $v1, $zero, 0x100
/* 1AC834 8027DF54 12200003 */  beqz  $s1, .L8027DF64
/* 1AC838 8027DF58 AC430148 */   sw    $v1, 0x148($v0)
/* 1AC83C 8027DF5C 0C0B102B */  jal   kill_script_by_ID
/* 1AC840 8027DF60 0240202D */   daddu $a0, $s2, $zero
.L8027DF64:
/* 1AC844 8027DF64 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1AC848 8027DF68 8FB20018 */  lw    $s2, 0x18($sp)
/* 1AC84C 8027DF6C 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AC850 8027DF70 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AC854 8027DF74 03E00008 */  jr    $ra
/* 1AC858 8027DF78 27BD0020 */   addiu $sp, $sp, 0x20

