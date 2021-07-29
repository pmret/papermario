.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel osRestoreInt
/* 467D0 8006B3D0 40086000 */  mfc0      $t0, $12
/* 467D4 8006B3D4 01044025 */  or        $t0, $t0, $a0
/* 467D8 8006B3D8 40886000 */  mtc0      $t0, $12
/* 467DC 8006B3DC 00000000 */  nop
/* 467E0 8006B3E0 00000000 */  nop
/* 467E4 8006B3E4 03E00008 */  jr        $ra
/* 467E8 8006B3E8 00000000 */   nop
/* 467EC 8006B3EC 00000000 */  nop
