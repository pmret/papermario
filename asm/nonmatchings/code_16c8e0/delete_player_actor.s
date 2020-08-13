.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel delete_player_actor
/* 16F648 80240D68 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 16F64C 80240D6C AFB10014 */  sw    $s1, 0x14($sp)
/* 16F650 80240D70 0080882D */  daddu $s1, $a0, $zero
/* 16F654 80240D74 AFB00010 */  sw    $s0, 0x10($sp)
/* 16F658 80240D78 0000802D */  daddu $s0, $zero, $zero
/* 16F65C 80240D7C AFBF0020 */  sw    $ra, 0x20($sp)
/* 16F660 80240D80 AFB3001C */  sw    $s3, 0x1c($sp)
/* 16F664 80240D84 AFB20018 */  sw    $s2, 0x18($sp)
/* 16F668 80240D88 0220202D */  daddu $a0, $s1, $zero
.L80240D8C:
/* 16F66C 80240D8C 0C099C8D */  jal   remove_actor_decoration
/* 16F670 80240D90 0200282D */   daddu $a1, $s0, $zero
/* 16F674 80240D94 26100001 */  addiu $s0, $s0, 1
/* 16F678 80240D98 2A020002 */  slti  $v0, $s0, 2
/* 16F67C 80240D9C 1440FFFB */  bnez  $v0, .L80240D8C
/* 16F680 80240DA0 0220202D */   daddu $a0, $s1, $zero
/* 16F684 80240DA4 8E2201D0 */  lw    $v0, 0x1d0($s1)
/* 16F688 80240DA8 10400003 */  beqz  $v0, .L80240DB8
/* 16F68C 80240DAC 00000000 */   nop   
/* 16F690 80240DB0 0C0B102B */  jal   kill_script_by_ID
/* 16F694 80240DB4 8E2401E0 */   lw    $a0, 0x1e0($s1)
.L80240DB8:
/* 16F698 80240DB8 8E2201D8 */  lw    $v0, 0x1d8($s1)
/* 16F69C 80240DBC 10400003 */  beqz  $v0, .L80240DCC
/* 16F6A0 80240DC0 00000000 */   nop   
/* 16F6A4 80240DC4 0C0B102B */  jal   kill_script_by_ID
/* 16F6A8 80240DC8 8E2401E8 */   lw    $a0, 0x1e8($s1)
.L80240DCC:
/* 16F6AC 80240DCC 8E2201D4 */  lw    $v0, 0x1d4($s1)
/* 16F6B0 80240DD0 10400003 */  beqz  $v0, .L80240DE0
/* 16F6B4 80240DD4 00000000 */   nop   
/* 16F6B8 80240DD8 0C0B102B */  jal   kill_script_by_ID
/* 16F6BC 80240DDC 8E2401E4 */   lw    $a0, 0x1e4($s1)
.L80240DE0:
/* 16F6C0 80240DE0 8E3001F4 */  lw    $s0, 0x1f4($s1)
/* 16F6C4 80240DE4 8E24042C */  lw    $a0, 0x42c($s1)
/* 16F6C8 80240DE8 8E1300C0 */  lw    $s3, 0xc0($s0)
/* 16F6CC 80240DEC 0C0448CA */  jal   func_80112328
/* 16F6D0 80240DF0 8E120010 */   lw    $s2, 0x10($s0)
/* 16F6D4 80240DF4 0C011DBD */  jal   func_800476F4
/* 16F6D8 80240DF8 86240436 */   lh    $a0, 0x436($s1)
/* 16F6DC 80240DFC 0C016914 */  jal   remove_effect
/* 16F6E0 80240E00 8E240440 */   lw    $a0, 0x440($s1)
/* 16F6E4 80240E04 8E220200 */  lw    $v0, 0x200($s1)
/* 16F6E8 80240E08 10400003 */  beqz  $v0, .L80240E18
/* 16F6EC 80240E0C 00000000 */   nop   
/* 16F6F0 80240E10 8C42000C */  lw    $v0, 0xc($v0)
/* 16F6F4 80240E14 AC400024 */  sw    $zero, 0x24($v0)
.L80240E18:
/* 16F6F8 80240E18 0C00AB4B */  jal   heap_free
/* 16F6FC 80240E1C 0240202D */   daddu $a0, $s2, $zero
/* 16F700 80240E20 0C00AB4B */  jal   heap_free
/* 16F704 80240E24 0260202D */   daddu $a0, $s3, $zero
/* 16F708 80240E28 0C00AB4B */  jal   heap_free
/* 16F70C 80240E2C 0200202D */   daddu $a0, $s0, $zero
/* 16F710 80240E30 0C00AB4B */  jal   heap_free
/* 16F714 80240E34 0220202D */   daddu $a0, $s1, $zero
/* 16F718 80240E38 8FBF0020 */  lw    $ra, 0x20($sp)
/* 16F71C 80240E3C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 16F720 80240E40 8FB20018 */  lw    $s2, 0x18($sp)
/* 16F724 80240E44 8FB10014 */  lw    $s1, 0x14($sp)
/* 16F728 80240E48 8FB00010 */  lw    $s0, 0x10($sp)
/* 16F72C 80240E4C 03E00008 */  jr    $ra
/* 16F730 80240E50 27BD0028 */   addiu $sp, $sp, 0x28

/* 16F734 80240E54 00000000 */  nop   
/* 16F738 80240E58 00000000 */  nop   
/* 16F73C 80240E5C 00000000 */  nop   
