.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel resume_all_group
/* 0E8FF8 802C4648 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E8FFC 802C464C AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9000 802C4650 0080882D */  daddu $s1, $a0, $zero
/* 0E9004 802C4654 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9008 802C4658 0000802D */  daddu $s0, $zero, $zero
/* 0E900C 802C465C AFBF0018 */  sw    $ra, 0x18($sp)
.L802C4660:
/* 0E9010 802C4660 3C03802E */  lui   $v1, 0x802e
/* 0E9014 802C4664 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E9018 802C4668 00101080 */  sll   $v0, $s0, 2
/* 0E901C 802C466C 00431021 */  addu  $v0, $v0, $v1
/* 0E9020 802C4670 8C440000 */  lw    $a0, ($v0)
/* 0E9024 802C4674 50800004 */  beql  $a0, $zero, .L802C4688
/* 0E9028 802C4678 26100001 */   addiu $s0, $s0, 1
/* 0E902C 802C467C 0C0B10DF */  jal   resume_group_script
/* 0E9030 802C4680 0220282D */   daddu $a1, $s1, $zero
/* 0E9034 802C4684 26100001 */  addiu $s0, $s0, 1
.L802C4688:
/* 0E9038 802C4688 2A020080 */  slti  $v0, $s0, 0x80
/* 0E903C 802C468C 1440FFF4 */  bnez  $v0, .L802C4660
/* 0E9040 802C4690 00000000 */   nop   
/* 0E9044 802C4694 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E9048 802C4698 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E904C 802C469C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9050 802C46A0 03E00008 */  jr    $ra
/* 0E9054 802C46A4 27BD0020 */   addiu $sp, $sp, 0x20

