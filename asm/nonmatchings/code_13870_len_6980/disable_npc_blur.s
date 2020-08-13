.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel disable_npc_blur
/* 0161AC 8003ADAC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0161B0 8003ADB0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0161B4 8003ADB4 0080802D */  daddu $s0, $a0, $zero
/* 0161B8 8003ADB8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0161BC 8003ADBC 8E030000 */  lw    $v1, ($s0)
/* 0161C0 8003ADC0 3C020010 */  lui   $v0, 0x10
/* 0161C4 8003ADC4 00621024 */  and   $v0, $v1, $v0
/* 0161C8 8003ADC8 10400007 */  beqz  $v0, .L8003ADE8
/* 0161CC 8003ADCC 3C02FFEF */   lui   $v0, 0xffef
/* 0161D0 8003ADD0 3442FFFF */  ori   $v0, $v0, 0xffff
/* 0161D4 8003ADD4 8E040020 */  lw    $a0, 0x20($s0)
/* 0161D8 8003ADD8 00621024 */  and   $v0, $v1, $v0
/* 0161DC 8003ADDC 0C00AB4B */  jal   heap_free
/* 0161E0 8003ADE0 AE020000 */   sw    $v0, ($s0)
/* 0161E4 8003ADE4 AE000020 */  sw    $zero, 0x20($s0)
.L8003ADE8:
/* 0161E8 8003ADE8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0161EC 8003ADEC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0161F0 8003ADF0 03E00008 */  jr    $ra
/* 0161F4 8003ADF4 27BD0018 */   addiu $sp, $sp, 0x18

