.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EFC
/* B36ACC 80241EFC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36AD0 80241F00 AFBF0014 */  sw        $ra, 0x14($sp)
/* B36AD4 80241F04 AFB00010 */  sw        $s0, 0x10($sp)
/* B36AD8 80241F08 0C00EABB */  jal       get_npc_unsafe
/* B36ADC 80241F0C 8C84014C */   lw       $a0, 0x14c($a0)
/* B36AE0 80241F10 24040008 */  addiu     $a0, $zero, 8
/* B36AE4 80241F14 0040802D */  daddu     $s0, $v0, $zero
/* B36AE8 80241F18 3C028024 */  lui       $v0, 0x8024
/* B36AEC 80241F1C 24421F68 */  addiu     $v0, $v0, 0x1f68
/* B36AF0 80241F20 0C00AB39 */  jal       heap_malloc
/* B36AF4 80241F24 AE020008 */   sw       $v0, 8($s0)
/* B36AF8 80241F28 0040182D */  daddu     $v1, $v0, $zero
/* B36AFC 80241F2C AE030020 */  sw        $v1, 0x20($s0)
/* B36B00 80241F30 AC600000 */  sw        $zero, ($v1)
/* B36B04 80241F34 8FBF0014 */  lw        $ra, 0x14($sp)
/* B36B08 80241F38 8FB00010 */  lw        $s0, 0x10($sp)
/* B36B0C 80241F3C 24020001 */  addiu     $v0, $zero, 1
/* B36B10 80241F40 03E00008 */  jr        $ra
/* B36B14 80241F44 27BD0018 */   addiu    $sp, $sp, 0x18
