.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ShowBattleChoice
/* 181E18 80253538 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 181E1C 8025353C AFB00010 */  sw    $s0, 0x10($sp)
/* 181E20 80253540 0080802D */  daddu $s0, $a0, $zero
/* 181E24 80253544 AFBF0014 */  sw    $ra, 0x14($sp)
/* 181E28 80253548 10A00009 */  beqz  $a1, .L80253570
/* 181E2C 8025354C 8E02000C */   lw    $v0, 0xc($s0)
/* 181E30 80253550 0C0B1EAF */  jal   get_variable
/* 181E34 80253554 8C450000 */   lw    $a1, ($v0)
/* 181E38 80253558 0040202D */  daddu $a0, $v0, $zero
/* 181E3C 8025355C 26050074 */  addiu $a1, $s0, 0x74
/* 181E40 80253560 0C049640 */  jal   load_string
/* 181E44 80253564 AE000074 */   sw    $zero, 0x74($s0)
/* 181E48 80253568 3C01802A */  lui   $at, 0x802a
/* 181E4C 8025356C AC22FA64 */  sw    $v0, -0x59c($at)
.L80253570:
/* 181E50 80253570 8E030074 */  lw    $v1, 0x74($s0)
/* 181E54 80253574 24020001 */  addiu $v0, $zero, 1
/* 181E58 80253578 1462000A */  bne   $v1, $v0, .L802535A4
/* 181E5C 8025357C 0000102D */   daddu $v0, $zero, $zero
/* 181E60 80253580 3C02802A */  lui   $v0, 0x802a
/* 181E64 80253584 8C42FA64 */  lw    $v0, -0x59c($v0)
/* 181E68 80253588 3C04802A */  lui   $a0, 0x802a
/* 181E6C 8025358C 8C84FA60 */  lw    $a0, -0x5a0($a0)
/* 181E70 80253590 904304E8 */  lbu   $v1, 0x4e8($v0)
/* 181E74 80253594 24020001 */  addiu $v0, $zero, 1
/* 181E78 80253598 A08304E8 */  sb    $v1, 0x4e8($a0)
/* 181E7C 8025359C 306300FF */  andi  $v1, $v1, 0xff
/* 181E80 802535A0 AE030084 */  sw    $v1, 0x84($s0)
.L802535A4:
/* 181E84 802535A4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 181E88 802535A8 8FB00010 */  lw    $s0, 0x10($sp)
/* 181E8C 802535AC 03E00008 */  jr    $ra
/* 181E90 802535B0 27BD0018 */   addiu $sp, $sp, 0x18

/* 181E94 802535B4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 181E98 802535B8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 181E9C 802535BC 8C82000C */  lw    $v0, 0xc($a0)
/* 181EA0 802535C0 0C0B1EAF */  jal   get_variable
/* 181EA4 802535C4 8C450000 */   lw    $a1, ($v0)
/* 181EA8 802535C8 10400005 */  beqz  $v0, .L802535E0
/* 181EAC 802535CC 00000000 */   nop   
/* 181EB0 802535D0 0C03A6CC */  jal   decrement_status_menu_disabled
/* 181EB4 802535D4 00000000 */   nop   
/* 181EB8 802535D8 08094D7A */  j     .L802535E8
/* 181EBC 802535DC 00000000 */   nop   

.L802535E0:
/* 181EC0 802535E0 0C03A6D5 */  jal   increment_status_menu_disabled
/* 181EC4 802535E4 00000000 */   nop   
.L802535E8:
/* 181EC8 802535E8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 181ECC 802535EC 24020002 */  addiu $v0, $zero, 2
/* 181ED0 802535F0 03E00008 */  jr    $ra
/* 181ED4 802535F4 27BD0018 */   addiu $sp, $sp, 0x18

