.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B50_EAA630
/* EAA630 80241B50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EAA634 80241B54 AFB00010 */  sw        $s0, 0x10($sp)
/* EAA638 80241B58 0080802D */  daddu     $s0, $a0, $zero
/* EAA63C 80241B5C AFBF0014 */  sw        $ra, 0x14($sp)
/* EAA640 80241B60 0C00F92F */  jal       func_8003E4BC
/* EAA644 80241B64 8E04008C */   lw       $a0, 0x8c($s0)
/* EAA648 80241B68 0040282D */  daddu     $a1, $v0, $zero
/* EAA64C 80241B6C 8E040094 */  lw        $a0, 0x94($s0)
/* EAA650 80241B70 8CA30028 */  lw        $v1, 0x28($a1)
/* EAA654 80241B74 ACA40028 */  sw        $a0, 0x28($a1)
/* EAA658 80241B78 8FBF0014 */  lw        $ra, 0x14($sp)
/* EAA65C 80241B7C 8FB00010 */  lw        $s0, 0x10($sp)
/* EAA660 80241B80 24020002 */  addiu     $v0, $zero, 2
/* EAA664 80241B84 3C018025 */  lui       $at, %hi(D_8024854C)
/* EAA668 80241B88 AC23854C */  sw        $v1, %lo(D_8024854C)($at)
/* EAA66C 80241B8C 03E00008 */  jr        $ra
/* EAA670 80241B90 27BD0018 */   addiu    $sp, $sp, 0x18
