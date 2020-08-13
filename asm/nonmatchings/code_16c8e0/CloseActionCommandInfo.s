.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CloseActionCommandInfo
/* 197CF0 80269410 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197CF4 80269414 10A0000D */  beqz  $a1, .L8026944C
/* 197CF8 80269418 AFBF0010 */   sw    $ra, 0x10($sp)
/* 197CFC 8026941C 3C02802A */  lui   $v0, 0x802a
/* 197D00 80269420 2442FBE0 */  addiu $v0, $v0, -0x420
/* 197D04 80269424 8443004A */  lh    $v1, 0x4a($v0)
/* 197D08 80269428 28620007 */  slti  $v0, $v1, 7
/* 197D0C 8026942C 10400003 */  beqz  $v0, .L8026943C
/* 197D10 80269430 28620005 */   slti  $v0, $v1, 5
/* 197D14 80269434 1040000B */  beqz  $v0, .L80269464
/* 197D18 80269438 24020002 */   addiu $v0, $zero, 2
.L8026943C:
/* 197D1C 8026943C 0C09A327 */  jal   func_80268C9C
/* 197D20 80269440 00000000 */   nop   
/* 197D24 80269444 0809A519 */  j     .L80269464
/* 197D28 80269448 0000102D */   daddu $v0, $zero, $zero

.L8026944C:
/* 197D2C 8026944C 3C048000 */  lui   $a0, 0x8000
/* 197D30 80269450 0C05271B */  jal   stop_sound
/* 197D34 80269454 34840041 */   ori   $a0, $a0, 0x41
/* 197D38 80269458 0C093EC3 */  jal   close_action_command_instruction_popup
/* 197D3C 8026945C 00000000 */   nop   
/* 197D40 80269460 24020002 */  addiu $v0, $zero, 2
.L80269464:
.L80269464:
/* 197D44 80269464 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197D48 80269468 03E00008 */  jr    $ra
/* 197D4C 8026946C 27BD0018 */   addiu $sp, $sp, 0x18

/* 197D50 80269470 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 197D54 80269474 14A00005 */  bnez  $a1, .L8026948C
/* 197D58 80269478 AFBF0010 */   sw    $ra, 0x10($sp)
/* 197D5C 8026947C 0C093EC3 */  jal   close_action_command_instruction_popup
/* 197D60 80269480 00000000 */   nop   
/* 197D64 80269484 0809A526 */  j     .L80269498
/* 197D68 80269488 24020002 */   addiu $v0, $zero, 2

.L8026948C:
/* 197D6C 8026948C 0C09A327 */  jal   func_80268C9C
/* 197D70 80269490 00000000 */   nop   
/* 197D74 80269494 0000102D */  daddu $v0, $zero, $zero
.L80269498:
/* 197D78 80269498 8FBF0010 */  lw    $ra, 0x10($sp)
/* 197D7C 8026949C 03E00008 */  jr    $ra
/* 197D80 802694A0 27BD0018 */   addiu $sp, $sp, 0x18

/* 197D84 802694A4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 197D88 802694A8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 197D8C 802694AC AFB10014 */  sw    $s1, 0x14($sp)
/* 197D90 802694B0 AFB00010 */  sw    $s0, 0x10($sp)
/* 197D94 802694B4 8C82000C */  lw    $v0, 0xc($a0)
/* 197D98 802694B8 3C10802A */  lui   $s0, 0x802a
/* 197D9C 802694BC 2610FBE0 */  addiu $s0, $s0, -0x420
/* 197DA0 802694C0 8C450000 */  lw    $a1, ($v0)
/* 197DA4 802694C4 0C0B1EAF */  jal   get_variable
/* 197DA8 802694C8 0200882D */   daddu $s1, $s0, $zero
/* 197DAC 802694CC 14400003 */  bnez  $v0, .L802694DC
/* 197DB0 802694D0 24020001 */   addiu $v0, $zero, 1
/* 197DB4 802694D4 0809A538 */  j     .L802694E0
/* 197DB8 802694D8 A2000061 */   sb    $zero, 0x61($s0)

.L802694DC:
/* 197DBC 802694DC A2220061 */  sb    $v0, 0x61($s1)
.L802694E0:
/* 197DC0 802694E0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 197DC4 802694E4 8FB10014 */  lw    $s1, 0x14($sp)
/* 197DC8 802694E8 8FB00010 */  lw    $s0, 0x10($sp)
/* 197DCC 802694EC 24020002 */  addiu $v0, $zero, 2
/* 197DD0 802694F0 03E00008 */  jr    $ra
/* 197DD4 802694F4 27BD0020 */   addiu $sp, $sp, 0x20

