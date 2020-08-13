.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel RestartNpcAux
/* 020338 80044F38 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 02033C 80044F3C AFBF001C */  sw    $ra, 0x1c($sp)
/* 020340 80044F40 AFB20018 */  sw    $s2, 0x18($sp)
/* 020344 80044F44 AFB10014 */  sw    $s1, 0x14($sp)
/* 020348 80044F48 AFB00010 */  sw    $s0, 0x10($sp)
/* 02034C 80044F4C 8C82000C */  lw    $v0, 0xc($a0)
/* 020350 80044F50 8C450000 */  lw    $a1, ($v0)
/* 020354 80044F54 0C0B1EAF */  jal   get_variable
/* 020358 80044F58 8C900148 */   lw    $s0, 0x148($a0)
/* 02035C 80044F5C 0040882D */  daddu $s1, $v0, $zero
/* 020360 80044F60 2402FFFF */  addiu $v0, $zero, -1
/* 020364 80044F64 16220002 */  bne   $s1, $v0, .L80044F70
/* 020368 80044F68 00000000 */   nop   
/* 02036C 80044F6C 86110008 */  lh    $s1, 8($s0)
.L80044F70:
/* 020370 80044F70 0C00FB3A */  jal   get_enemy
/* 020374 80044F74 0220202D */   daddu $a0, $s1, $zero
/* 020378 80044F78 0040802D */  daddu $s0, $v0, $zero
/* 02037C 80044F7C 8E020000 */  lw    $v0, ($s0)
/* 020380 80044F80 30420001 */  andi  $v0, $v0, 1
/* 020384 80044F84 10400002 */  beqz  $v0, .L80044F90
/* 020388 80044F88 2412000B */   addiu $s2, $zero, 0xb
/* 02038C 80044F8C 2412000A */  addiu $s2, $zero, 0xa
.L80044F90:
/* 020390 80044F90 8E020044 */  lw    $v0, 0x44($s0)
/* 020394 80044F94 10400005 */  beqz  $v0, .L80044FAC
/* 020398 80044F98 2405000A */   addiu $a1, $zero, 0xa
/* 02039C 80044F9C 8E04005C */  lw    $a0, 0x5c($s0)
/* 0203A0 80044FA0 0C0B102B */  jal   kill_script_by_ID
/* 0203A4 80044FA4 00000000 */   nop   
/* 0203A8 80044FA8 2405000A */  addiu $a1, $zero, 0xa
.L80044FAC:
/* 0203AC 80044FAC 8E04002C */  lw    $a0, 0x2c($s0)
/* 0203B0 80044FB0 0C0B0CF8 */  jal   start_script
/* 0203B4 80044FB4 0000302D */   daddu $a2, $zero, $zero
/* 0203B8 80044FB8 0040182D */  daddu $v1, $v0, $zero
/* 0203BC 80044FBC AE030044 */  sw    $v1, 0x44($s0)
/* 0203C0 80044FC0 8C640144 */  lw    $a0, 0x144($v1)
/* 0203C4 80044FC4 AE04005C */  sw    $a0, 0x5c($s0)
/* 0203C8 80044FC8 AC700148 */  sw    $s0, 0x148($v1)
/* 0203CC 80044FCC AC71014C */  sw    $s1, 0x14c($v1)
/* 0203D0 80044FD0 A0720004 */  sb    $s2, 4($v1)
/* 0203D4 80044FD4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0203D8 80044FD8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0203DC 80044FDC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0203E0 80044FE0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0203E4 80044FE4 24020002 */  addiu $v0, $zero, 2
/* 0203E8 80044FE8 03E00008 */  jr    $ra
/* 0203EC 80044FEC 27BD0020 */   addiu $sp, $sp, 0x20

