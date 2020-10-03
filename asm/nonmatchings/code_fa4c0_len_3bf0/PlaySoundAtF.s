.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlaySoundAtF
/* FAD1C 802D636C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* FAD20 802D6370 AFB1001C */  sw        $s1, 0x1c($sp)
/* FAD24 802D6374 0080882D */  daddu     $s1, $a0, $zero
/* FAD28 802D6378 AFBF0028 */  sw        $ra, 0x28($sp)
/* FAD2C 802D637C AFB30024 */  sw        $s3, 0x24($sp)
/* FAD30 802D6380 AFB20020 */  sw        $s2, 0x20($sp)
/* FAD34 802D6384 AFB00018 */  sw        $s0, 0x18($sp)
/* FAD38 802D6388 F7B60038 */  sdc1      $f22, 0x38($sp)
/* FAD3C 802D638C F7B40030 */  sdc1      $f20, 0x30($sp)
/* FAD40 802D6390 8E30000C */  lw        $s0, 0xc($s1)
/* FAD44 802D6394 8E130000 */  lw        $s3, ($s0)
/* FAD48 802D6398 26100004 */  addiu     $s0, $s0, 4
/* FAD4C 802D639C 8E050000 */  lw        $a1, ($s0)
/* FAD50 802D63A0 0C0B1EAF */  jal       get_variable
/* FAD54 802D63A4 26100004 */   addiu    $s0, $s0, 4
/* FAD58 802D63A8 8E050000 */  lw        $a1, ($s0)
/* FAD5C 802D63AC 26100004 */  addiu     $s0, $s0, 4
/* FAD60 802D63B0 0220202D */  daddu     $a0, $s1, $zero
/* FAD64 802D63B4 0C0B210B */  jal       get_float_variable
/* FAD68 802D63B8 0040902D */   daddu    $s2, $v0, $zero
/* FAD6C 802D63BC 8E050000 */  lw        $a1, ($s0)
/* FAD70 802D63C0 26100004 */  addiu     $s0, $s0, 4
/* FAD74 802D63C4 0220202D */  daddu     $a0, $s1, $zero
/* FAD78 802D63C8 0C0B210B */  jal       get_float_variable
/* FAD7C 802D63CC 46000586 */   mov.s    $f22, $f0
/* FAD80 802D63D0 0220202D */  daddu     $a0, $s1, $zero
/* FAD84 802D63D4 8E050000 */  lw        $a1, ($s0)
/* FAD88 802D63D8 0C0B210B */  jal       get_float_variable
/* FAD8C 802D63DC 46000506 */   mov.s    $f20, $f0
/* FAD90 802D63E0 0260202D */  daddu     $a0, $s3, $zero
/* FAD94 802D63E4 4406B000 */  mfc1      $a2, $f22
/* FAD98 802D63E8 4407A000 */  mfc1      $a3, $f20
/* FAD9C 802D63EC 3245FFFF */  andi      $a1, $s2, 0xffff
/* FADA0 802D63F0 0C052757 */  jal       play_sound_at_position
/* FADA4 802D63F4 E7A00010 */   swc1     $f0, 0x10($sp)
/* FADA8 802D63F8 8FBF0028 */  lw        $ra, 0x28($sp)
/* FADAC 802D63FC 8FB30024 */  lw        $s3, 0x24($sp)
/* FADB0 802D6400 8FB20020 */  lw        $s2, 0x20($sp)
/* FADB4 802D6404 8FB1001C */  lw        $s1, 0x1c($sp)
/* FADB8 802D6408 8FB00018 */  lw        $s0, 0x18($sp)
/* FADBC 802D640C D7B60038 */  ldc1      $f22, 0x38($sp)
/* FADC0 802D6410 D7B40030 */  ldc1      $f20, 0x30($sp)
/* FADC4 802D6414 24020002 */  addiu     $v0, $zero, 2
/* FADC8 802D6418 03E00008 */  jr        $ra
/* FADCC 802D641C 27BD0040 */   addiu    $sp, $sp, 0x40
