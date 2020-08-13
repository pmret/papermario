.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel resume_all_script
/* 0E8E3C 802C448C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E8E40 802C4490 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E8E44 802C4494 0080882D */  daddu $s1, $a0, $zero
/* 0E8E48 802C4498 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8E4C 802C449C 0000802D */  daddu $s0, $zero, $zero
/* 0E8E50 802C44A0 AFBF0018 */  sw    $ra, 0x18($sp)
.L802C44A4:
/* 0E8E54 802C44A4 3C03802E */  lui   $v1, 0x802e
/* 0E8E58 802C44A8 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8E5C 802C44AC 00101080 */  sll   $v0, $s0, 2
/* 0E8E60 802C44B0 00431021 */  addu  $v0, $v0, $v1
/* 0E8E64 802C44B4 8C440000 */  lw    $a0, ($v0)
/* 0E8E68 802C44B8 50800007 */  beql  $a0, $zero, .L802C44D8
/* 0E8E6C 802C44BC 26100001 */   addiu $s0, $s0, 1
/* 0E8E70 802C44C0 8C820144 */  lw    $v0, 0x144($a0)
/* 0E8E74 802C44C4 54510004 */  bnel  $v0, $s1, .L802C44D8
/* 0E8E78 802C44C8 26100001 */   addiu $s0, $s0, 1
/* 0E8E7C 802C44CC 0C0B10DF */  jal   resume_group_script
/* 0E8E80 802C44D0 240500EF */   addiu $a1, $zero, 0xef
/* 0E8E84 802C44D4 26100001 */  addiu $s0, $s0, 1
.L802C44D8:
/* 0E8E88 802C44D8 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8E8C 802C44DC 1440FFF1 */  bnez  $v0, .L802C44A4
/* 0E8E90 802C44E0 00000000 */   nop   
/* 0E8E94 802C44E4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E8E98 802C44E8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E8E9C 802C44EC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8EA0 802C44F0 03E00008 */  jr    $ra
/* 0E8EA4 802C44F4 27BD0020 */   addiu $sp, $sp, 0x20

