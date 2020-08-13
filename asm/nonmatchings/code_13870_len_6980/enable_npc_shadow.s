.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel enable_npc_shadow
/* 015FA0 8003ABA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 015FA4 8003ABA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 015FA8 8003ABA8 0080802D */  daddu $s0, $a0, $zero
/* 015FAC 8003ABAC AFBF0014 */  sw    $ra, 0x14($sp)
/* 015FB0 8003ABB0 8E020000 */  lw    $v0, ($s0)
/* 015FB4 8003ABB4 30420010 */  andi  $v0, $v0, 0x10
/* 015FB8 8003ABB8 1440000C */  bnez  $v0, .L8003ABEC
/* 015FBC 8003ABBC 00000000 */   nop   
/* 015FC0 8003ABC0 0C044181 */  jal   get_shadow_by_index
/* 015FC4 8003ABC4 8E040078 */   lw    $a0, 0x78($s0)
/* 015FC8 8003ABC8 3C050001 */  lui   $a1, 1
/* 015FCC 8003ABCC 8C430000 */  lw    $v1, ($v0)
/* 015FD0 8003ABD0 2404FFFE */  addiu $a0, $zero, -2
/* 015FD4 8003ABD4 00641824 */  and   $v1, $v1, $a0
/* 015FD8 8003ABD8 AC430000 */  sw    $v1, ($v0)
/* 015FDC 8003ABDC 8E020000 */  lw    $v0, ($s0)
/* 015FE0 8003ABE0 34A50010 */  ori   $a1, $a1, 0x10
/* 015FE4 8003ABE4 00451025 */  or    $v0, $v0, $a1
/* 015FE8 8003ABE8 AE020000 */  sw    $v0, ($s0)
.L8003ABEC:
/* 015FEC 8003ABEC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 015FF0 8003ABF0 8FB00010 */  lw    $s0, 0x10($sp)
/* 015FF4 8003ABF4 03E00008 */  jr    $ra
/* 015FF8 8003ABF8 27BD0018 */   addiu $sp, $sp, 0x18

