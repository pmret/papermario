.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024D570
.L8024D570:
/* 1408B0 8024D570 3C028027 */  lui   $v0, 0x8027
/* 1408B4 8024D574 8C4200C0 */  lw    $v0, 0xc0($v0)
/* 1408B8 8024D578 3C030001 */  lui   $v1, 1
/* 1408BC 8024D57C 00431024 */  and   $v0, $v0, $v1
/* 1408C0 8024D580 10400029 */  beqz  $v0, .L8024D628
/* 1408C4 8024D584 24020002 */   addiu $v0, $zero, 2
/* 1408C8 8024D588 92030003 */  lbu   $v1, 3($s0)
/* 1408CC 8024D58C 14620005 */  bne   $v1, $v0, .L8024D5A4
/* 1408D0 8024D590 24020005 */   addiu $v0, $zero, 5
/* 1408D4 8024D594 0809356B */  j     func_8024D5AC
/* 1408D8 8024D598 24020003 */   addiu $v0, $zero, 3

.L8024D59C:
/* 1408DC 8024D59C 0809355C */  j     func_8024D570
/* 1408E0 8024D5A0 A2020001 */   sb    $v0, 1($s0)

.L8024D5A4:
/* 1408E4 8024D5A4 14620004 */  bne   $v1, $v0, .L8024D5B8
/* 1408E8 8024D5A8 24020001 */   addiu $v0, $zero, 1
