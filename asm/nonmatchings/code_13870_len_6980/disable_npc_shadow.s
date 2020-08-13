.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel disable_npc_shadow
/* 015FFC 8003ABFC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 016000 8003AC00 AFB00010 */  sw    $s0, 0x10($sp)
/* 016004 8003AC04 0080802D */  daddu $s0, $a0, $zero
/* 016008 8003AC08 AFBF0014 */  sw    $ra, 0x14($sp)
/* 01600C 8003AC0C 8E020000 */  lw    $v0, ($s0)
/* 016010 8003AC10 30420010 */  andi  $v0, $v0, 0x10
/* 016014 8003AC14 1040000D */  beqz  $v0, .L8003AC4C
/* 016018 8003AC18 00000000 */   nop   
/* 01601C 8003AC1C 0C044181 */  jal   get_shadow_by_index
/* 016020 8003AC20 8E040078 */   lw    $a0, 0x78($s0)
/* 016024 8003AC24 3C04FFFE */  lui   $a0, 0xfffe
/* 016028 8003AC28 8C430000 */  lw    $v1, ($v0)
/* 01602C 8003AC2C 3484FFFF */  ori   $a0, $a0, 0xffff
/* 016030 8003AC30 34630001 */  ori   $v1, $v1, 1
/* 016034 8003AC34 AC430000 */  sw    $v1, ($v0)
/* 016038 8003AC38 8E020000 */  lw    $v0, ($s0)
/* 01603C 8003AC3C 2403FFEF */  addiu $v1, $zero, -0x11
/* 016040 8003AC40 00431024 */  and   $v0, $v0, $v1
/* 016044 8003AC44 00441024 */  and   $v0, $v0, $a0
/* 016048 8003AC48 AE020000 */  sw    $v0, ($s0)
.L8003AC4C:
/* 01604C 8003AC4C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 016050 8003AC50 8FB00010 */  lw    $s0, 0x10($sp)
/* 016054 8003AC54 03E00008 */  jr    $ra
/* 016058 8003AC58 27BD0018 */   addiu $sp, $sp, 0x18

