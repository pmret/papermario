.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuScEventBroadcast
/* 03A4C0 8005F0C0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03A4C4 8005F0C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 03A4C8 8005F0C8 3C10800E */  lui   $s0, 0x800e
/* 03A4CC 8005F0CC 8E10AAA8 */  lw    $s0, -0x5558($s0)
/* 03A4D0 8005F0D0 AFB10014 */  sw    $s1, 0x14($sp)
/* 03A4D4 8005F0D4 0080882D */  daddu $s1, $a0, $zero
/* 03A4D8 8005F0D8 1200000C */  beqz  $s0, .L8005F10C
/* 03A4DC 8005F0DC AFBF0018 */   sw    $ra, 0x18($sp)
.L8005F0E0:
/* 03A4E0 8005F0E0 96020008 */  lhu   $v0, 8($s0)
/* 03A4E4 8005F0E4 96230000 */  lhu   $v1, ($s1)
/* 03A4E8 8005F0E8 00431024 */  and   $v0, $v0, $v1
/* 03A4EC 8005F0EC 10400004 */  beqz  $v0, .L8005F100
/* 03A4F0 8005F0F0 0220282D */   daddu $a1, $s1, $zero
/* 03A4F4 8005F0F4 8E040004 */  lw    $a0, 4($s0)
/* 03A4F8 8005F0F8 0C019608 */  jal   osSendMesg
/* 03A4FC 8005F0FC 0000302D */   daddu $a2, $zero, $zero
.L8005F100:
/* 03A500 8005F100 8E100000 */  lw    $s0, ($s0)
/* 03A504 8005F104 1600FFF6 */  bnez  $s0, .L8005F0E0
/* 03A508 8005F108 00000000 */   nop   
.L8005F10C:
/* 03A50C 8005F10C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 03A510 8005F110 8FB10014 */  lw    $s1, 0x14($sp)
/* 03A514 8005F114 8FB00010 */  lw    $s0, 0x10($sp)
/* 03A518 8005F118 03E00008 */  jr    $ra
/* 03A51C 8005F11C 27BD0020 */   addiu $sp, $sp, 0x20

