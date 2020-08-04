.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80248D54
/* 13C094 80248D54 0C04993B */  jal   draw_string
/* 13C098 80248D58 25460042 */   addiu $a2, $t2, 0x42
.L80248D5C:
/* 13C09C 80248D5C 8FBF00BC */  lw    $ra, 0xbc($sp)
/* 13C0A0 80248D60 8FBE00B8 */  lw    $fp, 0xb8($sp)
/* 13C0A4 80248D64 8FB700B4 */  lw    $s7, 0xb4($sp)
/* 13C0A8 80248D68 8FB600B0 */  lw    $s6, 0xb0($sp)
/* 13C0AC 80248D6C 8FB500AC */  lw    $s5, 0xac($sp)
/* 13C0B0 80248D70 8FB400A8 */  lw    $s4, 0xa8($sp)
/* 13C0B4 80248D74 8FB300A4 */  lw    $s3, 0xa4($sp)
/* 13C0B8 80248D78 8FB200A0 */  lw    $s2, 0xa0($sp)
/* 13C0BC 80248D7C 8FB1009C */  lw    $s1, 0x9c($sp)
/* 13C0C0 80248D80 8FB00098 */  lw    $s0, 0x98($sp)
/* 13C0C4 80248D84 03E00008 */  jr    $ra
/* 13C0C8 80248D88 27BD00C0 */   addiu $sp, $sp, 0xc0

