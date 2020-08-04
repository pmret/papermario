.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RestartNpcAI
/* 02002C 80044C2C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 020030 80044C30 AFB10014 */  sw    $s1, 0x14($sp)
/* 020034 80044C34 0080882D */  daddu $s1, $a0, $zero
/* 020038 80044C38 AFBF001C */  sw    $ra, 0x1c($sp)
/* 02003C 80044C3C AFB20018 */  sw    $s2, 0x18($sp)
/* 020040 80044C40 AFB00010 */  sw    $s0, 0x10($sp)
/* 020044 80044C44 8E22000C */  lw    $v0, 0xc($s1)
/* 020048 80044C48 8C450000 */  lw    $a1, ($v0)
/* 02004C 80044C4C 0C0B1EAF */  jal   get_variable
/* 020050 80044C50 8E300148 */   lw    $s0, 0x148($s1)
/* 020054 80044C54 0040202D */  daddu $a0, $v0, $zero
/* 020058 80044C58 2402FFFF */  addiu $v0, $zero, -1
/* 02005C 80044C5C 14820002 */  bne   $a0, $v0, .L80044C68
/* 020060 80044C60 00000000 */   nop   
/* 020064 80044C64 86040008 */  lh    $a0, 8($s0)
.L80044C68:
/* 020068 80044C68 0C00FB3A */  jal   get_enemy
/* 02006C 80044C6C 2412000B */   addiu $s2, $zero, 0xb
/* 020070 80044C70 0040802D */  daddu $s0, $v0, $zero
/* 020074 80044C74 8E020000 */  lw    $v0, ($s0)
/* 020078 80044C78 30420001 */  andi  $v0, $v0, 1
/* 02007C 80044C7C 54400001 */  bnel  $v0, $zero, .L80044C84
/* 020080 80044C80 2412000A */   addiu $s2, $zero, 0xa
.L80044C84:
/* 020084 80044C84 8E02003C */  lw    $v0, 0x3c($s0)
/* 020088 80044C88 10400005 */  beqz  $v0, .L80044CA0
/* 02008C 80044C8C 2405000A */   addiu $a1, $zero, 0xa
/* 020090 80044C90 8E040054 */  lw    $a0, 0x54($s0)
/* 020094 80044C94 0C0B102B */  jal   kill_script_by_ID
/* 020098 80044C98 00000000 */   nop   
/* 02009C 80044C9C 2405000A */  addiu $a1, $zero, 0xa
.L80044CA0:
/* 0200A0 80044CA0 24020064 */  addiu $v0, $zero, 0x64
/* 0200A4 80044CA4 8E040024 */  lw    $a0, 0x24($s0)
/* 0200A8 80044CA8 0000302D */  daddu $a2, $zero, $zero
/* 0200AC 80044CAC 0C0B0CF8 */  jal   start_script
/* 0200B0 80044CB0 AE0200C8 */   sw    $v0, 0xc8($s0)
/* 0200B4 80044CB4 0040182D */  daddu $v1, $v0, $zero
/* 0200B8 80044CB8 AE03003C */  sw    $v1, 0x3c($s0)
/* 0200BC 80044CBC 8C620144 */  lw    $v0, 0x144($v1)
/* 0200C0 80044CC0 AE020054 */  sw    $v0, 0x54($s0)
/* 0200C4 80044CC4 AC700148 */  sw    $s0, 0x148($v1)
/* 0200C8 80044CC8 8E24014C */  lw    $a0, 0x14c($s1)
/* 0200CC 80044CCC A0720004 */  sb    $s2, 4($v1)
/* 0200D0 80044CD0 AC64014C */  sw    $a0, 0x14c($v1)
/* 0200D4 80044CD4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0200D8 80044CD8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0200DC 80044CDC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0200E0 80044CE0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0200E4 80044CE4 24020002 */  addiu $v0, $zero, 2
/* 0200E8 80044CE8 03E00008 */  jr    $ra
/* 0200EC 80044CEC 27BD0020 */   addiu $sp, $sp, 0x20

