.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80054C4C
/* 03004C 80054C4C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 030050 80054C50 00051080 */  sll   $v0, $a1, 2
/* 030054 80054C54 3C03800A */  lui   $v1, 0x800a
/* 030058 80054C58 8C63A5C0 */  lw    $v1, -0x5a40($v1)
/* 03005C 80054C5C 00A0302D */  daddu $a2, $a1, $zero
/* 030060 80054C60 AFBF0010 */  sw    $ra, 0x10($sp)
/* 030064 80054C64 00621821 */  addu  $v1, $v1, $v0
/* 030068 80054C68 8C651310 */  lw    $a1, 0x1310($v1)
/* 03006C 80054C6C 0C0151F2 */  jal   al_LoadBank
/* 030070 80054C70 24070001 */   addiu $a3, $zero, 1
/* 030074 80054C74 8FBF0010 */  lw    $ra, 0x10($sp)
/* 030078 80054C78 0000102D */  daddu $v0, $zero, $zero
/* 03007C 80054C7C 03E00008 */  jr    $ra
/* 030080 80054C80 27BD0018 */   addiu $sp, $sp, 0x18

/* 030084 80054C84 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 030088 80054C88 0080182D */  daddu $v1, $a0, $zero
/* 03008C 80054C8C 00A0202D */  daddu $a0, $a1, $zero
/* 030090 80054C90 3C02800A */  lui   $v0, 0x800a
/* 030094 80054C94 8C42A5C0 */  lw    $v0, -0x5a40($v0)
/* 030098 80054C98 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03009C 80054C9C AFB00010 */  sw    $s0, 0x10($sp)
/* 0300A0 80054CA0 8C500004 */  lw    $s0, 4($v0)
/* 0300A4 80054CA4 0C0151D1 */  jal   func_80054744
/* 0300A8 80054CA8 0060282D */   daddu $a1, $v1, $zero
/* 0300AC 80054CAC 0040182D */  daddu $v1, $v0, $zero
/* 0300B0 80054CB0 10600007 */  beqz  $v1, .L80054CD0
/* 0300B4 80054CB4 00000000 */   nop   
/* 0300B8 80054CB8 0000202D */  daddu $a0, $zero, $zero
.L80054CBC:
/* 0300BC 80054CBC AC700000 */  sw    $s0, ($v1)
/* 0300C0 80054CC0 24840001 */  addiu $a0, $a0, 1
/* 0300C4 80054CC4 2C820010 */  sltiu $v0, $a0, 0x10
/* 0300C8 80054CC8 1440FFFC */  bnez  $v0, .L80054CBC
/* 0300CC 80054CCC 24630004 */   addiu $v1, $v1, 4
.L80054CD0:
/* 0300D0 80054CD0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0300D4 80054CD4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0300D8 80054CD8 03E00008 */  jr    $ra
/* 0300DC 80054CDC 27BD0018 */   addiu $sp, $sp, 0x18

