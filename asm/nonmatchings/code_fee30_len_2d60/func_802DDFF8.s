.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DDFF8
/* 1010E8 802DDFF8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1010EC 802DDFFC 00A0402D */  daddu $t0, $a1, $zero
/* 1010F0 802DE000 00C0482D */  daddu $t1, $a2, $zero
/* 1010F4 802DE004 2405FFFF */  addiu $a1, $zero, -1
/* 1010F8 802DE008 8FA20038 */  lw    $v0, 0x38($sp)
/* 1010FC 802DE00C 8FA3003C */  lw    $v1, 0x3c($sp)
/* 101100 802DE010 8FA40040 */  lw    $a0, 0x40($sp)
/* 101104 802DE014 0100302D */  daddu $a2, $t0, $zero
/* 101108 802DE018 AFA70010 */  sw    $a3, 0x10($sp)
/* 10110C 802DE01C 0120382D */  daddu $a3, $t1, $zero
/* 101110 802DE020 AFBF0020 */  sw    $ra, 0x20($sp)
/* 101114 802DE024 AFA4001C */  sw    $a0, 0x1c($sp)
/* 101118 802DE028 0000202D */  daddu $a0, $zero, $zero
/* 10111C 802DE02C AFA20014 */  sw    $v0, 0x14($sp)
/* 101120 802DE030 0C0B77B9 */  jal   func_802DDEE4
/* 101124 802DE034 AFA30018 */   sw    $v1, 0x18($sp)
/* 101128 802DE038 8FBF0020 */  lw    $ra, 0x20($sp)
/* 10112C 802DE03C 03E00008 */  jr    $ra
/* 101130 802DE040 27BD0028 */   addiu $sp, $sp, 0x28

/* 101134 802DE044 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 101138 802DE048 AFB00010 */  sw    $s0, 0x10($sp)
/* 10113C 802DE04C 0080802D */  daddu $s0, $a0, $zero
/* 101140 802DE050 24A5FFFF */  addiu $a1, $a1, -1
/* 101144 802DE054 00051080 */  sll   $v0, $a1, 2
/* 101148 802DE058 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10114C 802DE05C 3C04802E */  lui   $a0, 0x802e
/* 101150 802DE060 00822021 */  addu  $a0, $a0, $v0
/* 101154 802DE064 8C84F548 */  lw    $a0, -0xab8($a0)
/* 101158 802DE068 10800011 */  beqz  $a0, .L802DE0B0
/* 10115C 802DE06C 00061080 */   sll   $v0, $a2, 2
/* 101160 802DE070 8C830000 */  lw    $v1, ($a0)
/* 101164 802DE074 00431021 */  addu  $v0, $v0, $v1
/* 101168 802DE078 8C430000 */  lw    $v1, ($v0)
/* 10116C 802DE07C 8C840004 */  lw    $a0, 4($a0)
/* 101170 802DE080 90620004 */  lbu   $v0, 4($v1)
/* 101174 802DE084 AE020008 */  sw    $v0, 8($s0)
/* 101178 802DE088 90620005 */  lbu   $v0, 5($v1)
/* 10117C 802DE08C AE02000C */  sw    $v0, 0xc($s0)
/* 101180 802DE090 80620006 */  lb    $v0, 6($v1)
/* 101184 802DE094 00021080 */  sll   $v0, $v0, 2
/* 101188 802DE098 00441021 */  addu  $v0, $v0, $a0
/* 10118C 802DE09C 8C420000 */  lw    $v0, ($v0)
/* 101190 802DE0A0 00C0202D */  daddu $a0, $a2, $zero
/* 101194 802DE0A4 0C0B7BA8 */  jal   func_802DEEA0
/* 101198 802DE0A8 AE020004 */   sw    $v0, 4($s0)
/* 10119C 802DE0AC AE020000 */  sw    $v0, ($s0)
.L802DE0B0:
/* 1011A0 802DE0B0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1011A4 802DE0B4 8FB00010 */  lw    $s0, 0x10($sp)
/* 1011A8 802DE0B8 03E00008 */  jr    $ra
/* 1011AC 802DE0BC 27BD0018 */   addiu $sp, $sp, 0x18

