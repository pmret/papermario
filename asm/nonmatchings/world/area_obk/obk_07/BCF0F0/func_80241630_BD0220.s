.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241630_BD0220
/* BD0220 80241630 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD0224 80241634 AFB00010 */  sw        $s0, 0x10($sp)
/* BD0228 80241638 0080802D */  daddu     $s0, $a0, $zero
/* BD022C 8024163C 3C05FE36 */  lui       $a1, 0xfe36
/* BD0230 80241640 AFBF0014 */  sw        $ra, 0x14($sp)
/* BD0234 80241644 0C0B210B */  jal       get_float_variable
/* BD0238 80241648 34A53C80 */   ori      $a1, $a1, 0x3c80
/* BD023C 8024164C 0200202D */  daddu     $a0, $s0, $zero
/* BD0240 80241650 3C05FE36 */  lui       $a1, 0xfe36
/* BD0244 80241654 44060000 */  mfc1      $a2, $f0
/* BD0248 80241658 0C0B2190 */  jal       set_float_variable
/* BD024C 8024165C 34A53C81 */   ori      $a1, $a1, 0x3c81
/* BD0250 80241660 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD0254 80241664 8FB00010 */  lw        $s0, 0x10($sp)
/* BD0258 80241668 24020002 */  addiu     $v0, $zero, 2
/* BD025C 8024166C 03E00008 */  jr        $ra
/* BD0260 80241670 27BD0018 */   addiu    $sp, $sp, 0x18
