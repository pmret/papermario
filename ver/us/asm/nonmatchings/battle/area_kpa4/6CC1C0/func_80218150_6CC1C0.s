.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218150_6CC1C0
/* 6CC1C0 80218150 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 6CC1C4 80218154 AFB10024 */  sw        $s1, 0x24($sp)
/* 6CC1C8 80218158 0080882D */  daddu     $s1, $a0, $zero
/* 6CC1CC 8021815C AFBF0028 */  sw        $ra, 0x28($sp)
/* 6CC1D0 80218160 AFB00020 */  sw        $s0, 0x20($sp)
/* 6CC1D4 80218164 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 6CC1D8 80218168 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 6CC1DC 8021816C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 6CC1E0 80218170 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6CC1E4 80218174 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6CC1E8 80218178 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6CC1EC 8021817C 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC1F0 80218180 8E050000 */  lw        $a1, ($s0)
/* 6CC1F4 80218184 0C0B210B */  jal       get_float_variable
/* 6CC1F8 80218188 26100004 */   addiu    $s0, $s0, 4
/* 6CC1FC 8021818C 8E050000 */  lw        $a1, ($s0)
/* 6CC200 80218190 26100004 */  addiu     $s0, $s0, 4
/* 6CC204 80218194 0220202D */  daddu     $a0, $s1, $zero
/* 6CC208 80218198 0C0B210B */  jal       get_float_variable
/* 6CC20C 8021819C 46000786 */   mov.s    $f30, $f0
/* 6CC210 802181A0 8E050000 */  lw        $a1, ($s0)
/* 6CC214 802181A4 26100004 */  addiu     $s0, $s0, 4
/* 6CC218 802181A8 0220202D */  daddu     $a0, $s1, $zero
/* 6CC21C 802181AC 0C0B210B */  jal       get_float_variable
/* 6CC220 802181B0 46000506 */   mov.s    $f20, $f0
/* 6CC224 802181B4 8E050000 */  lw        $a1, ($s0)
/* 6CC228 802181B8 26100004 */  addiu     $s0, $s0, 4
/* 6CC22C 802181BC 0220202D */  daddu     $a0, $s1, $zero
/* 6CC230 802181C0 0C0B210B */  jal       get_float_variable
/* 6CC234 802181C4 46000706 */   mov.s    $f28, $f0
/* 6CC238 802181C8 8E050000 */  lw        $a1, ($s0)
/* 6CC23C 802181CC 26100004 */  addiu     $s0, $s0, 4
/* 6CC240 802181D0 0220202D */  daddu     $a0, $s1, $zero
/* 6CC244 802181D4 0C0B210B */  jal       get_float_variable
/* 6CC248 802181D8 46000686 */   mov.s    $f26, $f0
/* 6CC24C 802181DC 8E050000 */  lw        $a1, ($s0)
/* 6CC250 802181E0 26100004 */  addiu     $s0, $s0, 4
/* 6CC254 802181E4 0220202D */  daddu     $a0, $s1, $zero
/* 6CC258 802181E8 0C0B210B */  jal       get_float_variable
/* 6CC25C 802181EC 46000606 */   mov.s    $f24, $f0
/* 6CC260 802181F0 0220202D */  daddu     $a0, $s1, $zero
/* 6CC264 802181F4 8E050000 */  lw        $a1, ($s0)
/* 6CC268 802181F8 0C0B1EAF */  jal       get_variable
/* 6CC26C 802181FC 46000586 */   mov.s    $f22, $f0
/* 6CC270 80218200 8E240148 */  lw        $a0, 0x148($s1)
/* 6CC274 80218204 0C09A75B */  jal       get_actor
/* 6CC278 80218208 0040802D */   daddu    $s0, $v0, $zero
/* 6CC27C 8021820C 4600A521 */  cvt.d.s   $f20, $f20
/* 6CC280 80218210 4405F000 */  mfc1      $a1, $f30
/* 6CC284 80218214 3C014014 */  lui       $at, 0x4014
/* 6CC288 80218218 44810800 */  mtc1      $at, $f1
/* 6CC28C 8021821C 44800000 */  mtc1      $zero, $f0
/* 6CC290 80218220 4407E000 */  mfc1      $a3, $f28
/* 6CC294 80218224 4620A500 */  add.d     $f20, $f20, $f0
/* 6CC298 80218228 0000202D */  daddu     $a0, $zero, $zero
/* 6CC29C 8021822C AFB0001C */  sw        $s0, 0x1c($sp)
/* 6CC2A0 80218230 4620A520 */  cvt.s.d   $f20, $f20
/* 6CC2A4 80218234 4406A000 */  mfc1      $a2, $f20
/* 6CC2A8 80218238 0040802D */  daddu     $s0, $v0, $zero
/* 6CC2AC 8021823C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 6CC2B0 80218240 E7B80014 */  swc1      $f24, 0x14($sp)
/* 6CC2B4 80218244 0C01BFD4 */  jal       func_8006FF50
/* 6CC2B8 80218248 E7B60018 */   swc1     $f22, 0x18($sp)
/* 6CC2BC 8021824C 0040202D */  daddu     $a0, $v0, $zero
/* 6CC2C0 80218250 82030210 */  lb        $v1, 0x210($s0)
/* 6CC2C4 80218254 2402000A */  addiu     $v0, $zero, 0xa
/* 6CC2C8 80218258 14620007 */  bne       $v1, $v0, .L80218278
/* 6CC2CC 8021825C 00000000 */   nop
/* 6CC2D0 80218260 8C82000C */  lw        $v0, 0xc($a0)
/* 6CC2D4 80218264 3C013ECC */  lui       $at, 0x3ecc
/* 6CC2D8 80218268 3421CCCD */  ori       $at, $at, 0xcccd
/* 6CC2DC 8021826C 44810000 */  mtc1      $at, $f0
/* 6CC2E0 80218270 00000000 */  nop
/* 6CC2E4 80218274 E4400028 */  swc1      $f0, 0x28($v0)
.L80218278:
/* 6CC2E8 80218278 8FBF0028 */  lw        $ra, 0x28($sp)
/* 6CC2EC 8021827C 8FB10024 */  lw        $s1, 0x24($sp)
/* 6CC2F0 80218280 8FB00020 */  lw        $s0, 0x20($sp)
/* 6CC2F4 80218284 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 6CC2F8 80218288 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 6CC2FC 8021828C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 6CC300 80218290 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6CC304 80218294 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6CC308 80218298 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6CC30C 8021829C 24020002 */  addiu     $v0, $zero, 2
/* 6CC310 802182A0 03E00008 */  jr        $ra
/* 6CC314 802182A4 27BD0060 */   addiu    $sp, $sp, 0x60
