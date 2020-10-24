.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024157C_BD016C
/* BD016C 8024157C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD0170 80241580 AFB00010 */  sw        $s0, 0x10($sp)
/* BD0174 80241584 AFBF0014 */  sw        $ra, 0x14($sp)
/* BD0178 80241588 0C090150 */  jal       func_80240540_BCF130
/* BD017C 8024158C 0080802D */   daddu    $s0, $a0, $zero
/* BD0180 80241590 3C05FE36 */  lui       $a1, 0xfe36
/* BD0184 80241594 34A53C80 */  ori       $a1, $a1, 0x3c80
/* BD0188 80241598 8C4601D0 */  lw        $a2, 0x1d0($v0)
/* BD018C 8024159C 0C0B2190 */  jal       set_float_variable
/* BD0190 802415A0 0200202D */   daddu    $a0, $s0, $zero
/* BD0194 802415A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD0198 802415A8 8FB00010 */  lw        $s0, 0x10($sp)
/* BD019C 802415AC 24020002 */  addiu     $v0, $zero, 2
/* BD01A0 802415B0 03E00008 */  jr        $ra
/* BD01A4 802415B4 27BD0018 */   addiu    $sp, $sp, 0x18
