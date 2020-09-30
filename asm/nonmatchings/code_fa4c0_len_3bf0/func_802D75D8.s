.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D75D8
/* FBF88 802D75D8 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* FBF8C 802D75DC AFB1001C */  sw        $s1, 0x1c($sp)
/* FBF90 802D75E0 0080882D */  daddu     $s1, $a0, $zero
/* FBF94 802D75E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* FBF98 802D75E8 AFB00018 */  sw        $s0, 0x18($sp)
/* FBF9C 802D75EC F7B80038 */  sdc1      $f24, 0x38($sp)
/* FBFA0 802D75F0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* FBFA4 802D75F4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* FBFA8 802D75F8 8E30000C */  lw        $s0, 0xc($s1)
/* FBFAC 802D75FC 8E050000 */  lw        $a1, ($s0)
/* FBFB0 802D7600 0C0B210B */  jal       get_float_variable
/* FBFB4 802D7604 26100004 */   addiu    $s0, $s0, 4
/* FBFB8 802D7608 8E050000 */  lw        $a1, ($s0)
/* FBFBC 802D760C 26100004 */  addiu     $s0, $s0, 4
/* FBFC0 802D7610 0220202D */  daddu     $a0, $s1, $zero
/* FBFC4 802D7614 0C0B210B */  jal       get_float_variable
/* FBFC8 802D7618 46000606 */   mov.s    $f24, $f0
/* FBFCC 802D761C 8E050000 */  lw        $a1, ($s0)
/* FBFD0 802D7620 26100004 */  addiu     $s0, $s0, 4
/* FBFD4 802D7624 0220202D */  daddu     $a0, $s1, $zero
/* FBFD8 802D7628 0C0B210B */  jal       get_float_variable
/* FBFDC 802D762C 46000586 */   mov.s    $f22, $f0
/* FBFE0 802D7630 0220202D */  daddu     $a0, $s1, $zero
/* FBFE4 802D7634 8E050000 */  lw        $a1, ($s0)
/* FBFE8 802D7638 0C0B1EAF */  jal       get_variable
/* FBFEC 802D763C 46000506 */   mov.s    $f20, $f0
/* FBFF0 802D7640 0040382D */  daddu     $a3, $v0, $zero
/* FBFF4 802D7644 4600C306 */  mov.s     $f12, $f24
/* FBFF8 802D7648 4406A000 */  mfc1      $a2, $f20
/* FBFFC 802D764C 0C0B5D30 */  jal       func_802D74C0
/* FC000 802D7650 4600B386 */   mov.s    $f14, $f22
/* FC004 802D7654 24040378 */  addiu     $a0, $zero, 0x378
/* FC008 802D7658 4406C000 */  mfc1      $a2, $f24
/* FC00C 802D765C 4407B000 */  mfc1      $a3, $f22
/* FC010 802D7660 0000282D */  daddu     $a1, $zero, $zero
/* FC014 802D7664 0C052757 */  jal       play_sound_at_position
/* FC018 802D7668 E7B40010 */   swc1     $f20, 0x10($sp)
/* FC01C 802D766C 8FBF0020 */  lw        $ra, 0x20($sp)
/* FC020 802D7670 8FB1001C */  lw        $s1, 0x1c($sp)
/* FC024 802D7674 8FB00018 */  lw        $s0, 0x18($sp)
/* FC028 802D7678 D7B80038 */  ldc1      $f24, 0x38($sp)
/* FC02C 802D767C D7B60030 */  ldc1      $f22, 0x30($sp)
/* FC030 802D7680 D7B40028 */  ldc1      $f20, 0x28($sp)
/* FC034 802D7684 24020002 */  addiu     $v0, $zero, 2
/* FC038 802D7688 03E00008 */  jr        $ra
/* FC03C 802D768C 27BD0040 */   addiu    $sp, $sp, 0x40
