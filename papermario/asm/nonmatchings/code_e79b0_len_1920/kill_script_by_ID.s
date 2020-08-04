.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel kill_script_by_ID
/* 0E8A5C 802C40AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E8A60 802C40B0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E8A64 802C40B4 0080882D */  daddu $s1, $a0, $zero
/* 0E8A68 802C40B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8A6C 802C40BC 0000802D */  daddu $s0, $zero, $zero
/* 0E8A70 802C40C0 AFBF0018 */  sw    $ra, 0x18($sp)
.L802C40C4:
/* 0E8A74 802C40C4 3C03802E */  lui   $v1, 0x802e
/* 0E8A78 802C40C8 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8A7C 802C40CC 00101080 */  sll   $v0, $s0, 2
/* 0E8A80 802C40D0 00431021 */  addu  $v0, $v0, $v1
/* 0E8A84 802C40D4 8C440000 */  lw    $a0, ($v0)
/* 0E8A88 802C40D8 10800006 */  beqz  $a0, .L802C40F4
/* 0E8A8C 802C40DC 26100001 */   addiu $s0, $s0, 1
/* 0E8A90 802C40E0 8C820144 */  lw    $v0, 0x144($a0)
/* 0E8A94 802C40E4 14510003 */  bne   $v0, $s1, .L802C40F4
/* 0E8A98 802C40E8 00000000 */   nop   
/* 0E8A9C 802C40EC 0C0B0FCF */  jal   kill_script
/* 0E8AA0 802C40F0 00000000 */   nop   
.L802C40F4:
/* 0E8AA4 802C40F4 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8AA8 802C40F8 1440FFF2 */  bnez  $v0, .L802C40C4
/* 0E8AAC 802C40FC 00000000 */   nop   
/* 0E8AB0 802C4100 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E8AB4 802C4104 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E8AB8 802C4108 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8ABC 802C410C 03E00008 */  jr    $ra
/* 0E8AC0 802C4110 27BD0020 */   addiu $sp, $sp, 0x20

