.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024C470
.L8024C470:
/* 13F7B0 8024C470 3C018027 */  lui   $at, 0x8027
/* 13F7B4 8024C474 AC2006A4 */  sw    $zero, 0x6a4($at)
.L8024C478:
/* 13F7B8 8024C478 0C039D59 */  jal   get_player_data
/* 13F7BC 8024C47C 00000000 */   nop   
/* 13F7C0 8024C480 3C038027 */  lui   $v1, 0x8027
/* 13F7C4 8024C484 8C6306A0 */  lw    $v1, 0x6a0($v1)
/* 13F7C8 8024C488 00031880 */  sll   $v1, $v1, 2
/* 13F7CC 8024C48C 3C018027 */  lui   $at, 0x8027
/* 13F7D0 8024C490 00230821 */  addu  $at, $at, $v1
/* 13F7D4 8024C494 8C230680 */  lw    $v1, 0x680($at)
/* 13F7D8 8024C498 00031880 */  sll   $v1, $v1, 2
/* 13F7DC 8024C49C 3C018025 */  lui   $at, 0x8025
/* 13F7E0 8024C4A0 00230821 */  addu  $at, $at, $v1
/* 13F7E4 8024C4A4 8C23F6B0 */  lw    $v1, -0x950($at)
/* 13F7E8 8024C4A8 000318C0 */  sll   $v1, $v1, 3
/* 13F7EC 8024C4AC 00431021 */  addu  $v0, $v0, $v1
/* 13F7F0 8024C4B0 80430015 */  lb    $v1, 0x15($v0)
/* 13F7F4 8024C4B4 24020002 */  addiu $v0, $zero, 2
/* 13F7F8 8024C4B8 14620003 */  bne   $v1, $v0, .L8024C4C8
/* 13F7FC 8024C4BC 24020001 */   addiu $v0, $zero, 1
/* 13F800 8024C4C0 08093138 */  j     func_8024C4E0
/* 13F804 8024C4C4 24030004 */   addiu $v1, $zero, 4

.L8024C4C8:
/* 13F808 8024C4C8 14620003 */  bne   $v1, $v0, .L8024C4D8
/* 13F80C 8024C4CC 00000000 */   nop   
/* 13F810 8024C4D0 08093138 */  j     func_8024C4E0
/* 13F814 8024C4D4 24030003 */   addiu $v1, $zero, 3

.L8024C4D8:
/* 13F818 8024C4D8 50600001 */  beql  $v1, $zero, .L8024C4E0
/* 13F81C 8024C4DC 24030002 */   addiu $v1, $zero, 2
