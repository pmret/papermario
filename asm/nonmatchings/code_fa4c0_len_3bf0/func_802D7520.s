.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D7520
/* FBED0 802D7520 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* FBED4 802D7524 AFB1001C */  sw        $s1, 0x1c($sp)
/* FBED8 802D7528 0080882D */  daddu     $s1, $a0, $zero
/* FBEDC 802D752C AFBF0020 */  sw        $ra, 0x20($sp)
/* FBEE0 802D7530 AFB00018 */  sw        $s0, 0x18($sp)
/* FBEE4 802D7534 F7B80038 */  sdc1      $f24, 0x38($sp)
/* FBEE8 802D7538 F7B60030 */  sdc1      $f22, 0x30($sp)
/* FBEEC 802D753C F7B40028 */  sdc1      $f20, 0x28($sp)
/* FBEF0 802D7540 8E30000C */  lw        $s0, 0xc($s1)
/* FBEF4 802D7544 8E050000 */  lw        $a1, ($s0)
/* FBEF8 802D7548 0C0B210B */  jal       get_float_variable
/* FBEFC 802D754C 26100004 */   addiu    $s0, $s0, 4
/* FBF00 802D7550 8E050000 */  lw        $a1, ($s0)
/* FBF04 802D7554 26100004 */  addiu     $s0, $s0, 4
/* FBF08 802D7558 0220202D */  daddu     $a0, $s1, $zero
/* FBF0C 802D755C 0C0B210B */  jal       get_float_variable
/* FBF10 802D7560 46000606 */   mov.s    $f24, $f0
/* FBF14 802D7564 8E050000 */  lw        $a1, ($s0)
/* FBF18 802D7568 26100004 */  addiu     $s0, $s0, 4
/* FBF1C 802D756C 0220202D */  daddu     $a0, $s1, $zero
/* FBF20 802D7570 0C0B210B */  jal       get_float_variable
/* FBF24 802D7574 46000586 */   mov.s    $f22, $f0
/* FBF28 802D7578 0220202D */  daddu     $a0, $s1, $zero
/* FBF2C 802D757C 8E050000 */  lw        $a1, ($s0)
/* FBF30 802D7580 0C0B1EAF */  jal       get_variable
/* FBF34 802D7584 46000506 */   mov.s    $f20, $f0
/* FBF38 802D7588 0040382D */  daddu     $a3, $v0, $zero
/* FBF3C 802D758C 4600C306 */  mov.s     $f12, $f24
/* FBF40 802D7590 4406A000 */  mfc1      $a2, $f20
/* FBF44 802D7594 0C0B5D18 */  jal       func_802D7460
/* FBF48 802D7598 4600B386 */   mov.s    $f14, $f22
/* FBF4C 802D759C 24042055 */  addiu     $a0, $zero, 0x2055
/* FBF50 802D75A0 4406C000 */  mfc1      $a2, $f24
/* FBF54 802D75A4 4407B000 */  mfc1      $a3, $f22
/* FBF58 802D75A8 0000282D */  daddu     $a1, $zero, $zero
/* FBF5C 802D75AC 0C052757 */  jal       play_sound_at_position
/* FBF60 802D75B0 E7B40010 */   swc1     $f20, 0x10($sp)
/* FBF64 802D75B4 8FBF0020 */  lw        $ra, 0x20($sp)
/* FBF68 802D75B8 8FB1001C */  lw        $s1, 0x1c($sp)
/* FBF6C 802D75BC 8FB00018 */  lw        $s0, 0x18($sp)
/* FBF70 802D75C0 D7B80038 */  ldc1      $f24, 0x38($sp)
/* FBF74 802D75C4 D7B60030 */  ldc1      $f22, 0x30($sp)
/* FBF78 802D75C8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* FBF7C 802D75CC 24020002 */  addiu     $v0, $zero, 2
/* FBF80 802D75D0 03E00008 */  jr        $ra
/* FBF84 802D75D4 27BD0040 */   addiu    $sp, $sp, 0x40
