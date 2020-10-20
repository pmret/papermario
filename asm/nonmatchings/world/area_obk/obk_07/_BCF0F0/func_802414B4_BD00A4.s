.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414B4_BD00A4
/* BD00A4 802414B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD00A8 802414B8 AFB00010 */  sw        $s0, 0x10($sp)
/* BD00AC 802414BC 0080802D */  daddu     $s0, $a0, $zero
/* BD00B0 802414C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* BD00B4 802414C4 0C090150 */  jal       func_80240540
/* BD00B8 802414C8 AFB10014 */   sw       $s1, 0x14($sp)
/* BD00BC 802414CC 0200202D */  daddu     $a0, $s0, $zero
/* BD00C0 802414D0 3C05FE36 */  lui       $a1, 0xfe36
/* BD00C4 802414D4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* BD00C8 802414D8 0C0B210B */  jal       get_float_variable
/* BD00CC 802414DC 0040882D */   daddu    $s1, $v0, $zero
/* BD00D0 802414E0 0C00A6C9 */  jal       clamp_angle
/* BD00D4 802414E4 46000306 */   mov.s    $f12, $f0
/* BD00D8 802414E8 0200202D */  daddu     $a0, $s0, $zero
/* BD00DC 802414EC 3C05FE36 */  lui       $a1, 0xfe36
/* BD00E0 802414F0 44060000 */  mfc1      $a2, $f0
/* BD00E4 802414F4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* BD00E8 802414F8 0C0B2190 */  jal       set_float_variable
/* BD00EC 802414FC AE2601C8 */   sw       $a2, 0x1c8($s1)
/* BD00F0 80241500 8FBF0018 */  lw        $ra, 0x18($sp)
/* BD00F4 80241504 8FB10014 */  lw        $s1, 0x14($sp)
/* BD00F8 80241508 8FB00010 */  lw        $s0, 0x10($sp)
/* BD00FC 8024150C 24020002 */  addiu     $v0, $zero, 2
/* BD0100 80241510 03E00008 */  jr        $ra
/* BD0104 80241514 27BD0020 */   addiu    $sp, $sp, 0x20
