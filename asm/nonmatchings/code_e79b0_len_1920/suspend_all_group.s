.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel suspend_all_group
/* 0E8F98 802C45E8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E8F9C 802C45EC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E8FA0 802C45F0 0080882D */  daddu $s1, $a0, $zero
/* 0E8FA4 802C45F4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8FA8 802C45F8 0000802D */  daddu $s0, $zero, $zero
/* 0E8FAC 802C45FC AFBF0018 */  sw    $ra, 0x18($sp)
.L802C4600:
/* 0E8FB0 802C4600 3C03802E */  lui   $v1, 0x802e
/* 0E8FB4 802C4604 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8FB8 802C4608 00101080 */  sll   $v0, $s0, 2
/* 0E8FBC 802C460C 00431021 */  addu  $v0, $v0, $v1
/* 0E8FC0 802C4610 8C440000 */  lw    $a0, ($v0)
/* 0E8FC4 802C4614 50800004 */  beql  $a0, $zero, .L802C4628
/* 0E8FC8 802C4618 26100001 */   addiu $s0, $s0, 1
/* 0E8FCC 802C461C 0C0B10B6 */  jal   suspend_group_script
/* 0E8FD0 802C4620 0220282D */   daddu $a1, $s1, $zero
/* 0E8FD4 802C4624 26100001 */  addiu $s0, $s0, 1
.L802C4628:
/* 0E8FD8 802C4628 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8FDC 802C462C 1440FFF4 */  bnez  $v0, .L802C4600
/* 0E8FE0 802C4630 00000000 */   nop   
/* 0E8FE4 802C4634 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E8FE8 802C4638 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E8FEC 802C463C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8FF0 802C4640 03E00008 */  jr    $ra
/* 0E8FF4 802C4644 27BD0020 */   addiu $sp, $sp, 0x20

