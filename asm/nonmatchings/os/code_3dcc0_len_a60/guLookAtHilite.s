.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel guLookAtHilite
/* 3E644 80063244 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 3E648 80063248 C7A000C8 */  lwc1      $f0, 0xc8($sp)
/* 3E64C 8006324C C7A200CC */  lwc1      $f2, 0xcc($sp)
/* 3E650 80063250 C7A400D0 */  lwc1      $f4, 0xd0($sp)
/* 3E654 80063254 C7A600D4 */  lwc1      $f6, 0xd4($sp)
/* 3E658 80063258 C7A800D8 */  lwc1      $f8, 0xd8($sp)
/* 3E65C 8006325C C7AA00DC */  lwc1      $f10, 0xdc($sp)
/* 3E660 80063260 C7AC00E0 */  lwc1      $f12, 0xe0($sp)
/* 3E664 80063264 C7AE00E4 */  lwc1      $f14, 0xe4($sp)
/* 3E668 80063268 C7B000E8 */  lwc1      $f16, 0xe8($sp)
/* 3E66C 8006326C C7B200EC */  lwc1      $f18, 0xec($sp)
/* 3E670 80063270 F7B40098 */  sdc1      $f20, 0x98($sp)
/* 3E674 80063274 C7B400F0 */  lwc1      $f20, 0xf0($sp)
/* 3E678 80063278 F7B600A0 */  sdc1      $f22, 0xa0($sp)
/* 3E67C 8006327C C7B600F4 */  lwc1      $f22, 0xf4($sp)
/* 3E680 80063280 F7B800A8 */  sdc1      $f24, 0xa8($sp)
/* 3E684 80063284 C7B800F8 */  lwc1      $f24, 0xf8($sp)
/* 3E688 80063288 F7BA00B0 */  sdc1      $f26, 0xb0($sp)
/* 3E68C 8006328C C7BA00FC */  lwc1      $f26, 0xfc($sp)
/* 3E690 80063290 8FA20100 */  lw        $v0, 0x100($sp)
/* 3E694 80063294 8FA30104 */  lw        $v1, 0x104($sp)
/* 3E698 80063298 AFB00090 */  sw        $s0, 0x90($sp)
/* 3E69C 8006329C 00808021 */  addu      $s0, $a0, $zero
/* 3E6A0 800632A0 27A40050 */  addiu     $a0, $sp, 0x50
/* 3E6A4 800632A4 AFBF0094 */  sw        $ra, 0x94($sp)
/* 3E6A8 800632A8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3E6AC 800632AC E7A20014 */  swc1      $f2, 0x14($sp)
/* 3E6B0 800632B0 E7A40018 */  swc1      $f4, 0x18($sp)
/* 3E6B4 800632B4 E7A6001C */  swc1      $f6, 0x1c($sp)
/* 3E6B8 800632B8 E7A80020 */  swc1      $f8, 0x20($sp)
/* 3E6BC 800632BC E7AA0024 */  swc1      $f10, 0x24($sp)
/* 3E6C0 800632C0 E7AC0028 */  swc1      $f12, 0x28($sp)
/* 3E6C4 800632C4 E7AE002C */  swc1      $f14, 0x2c($sp)
/* 3E6C8 800632C8 E7B00030 */  swc1      $f16, 0x30($sp)
/* 3E6CC 800632CC E7B20034 */  swc1      $f18, 0x34($sp)
/* 3E6D0 800632D0 E7B40038 */  swc1      $f20, 0x38($sp)
/* 3E6D4 800632D4 E7B6003C */  swc1      $f22, 0x3c($sp)
/* 3E6D8 800632D8 E7B80040 */  swc1      $f24, 0x40($sp)
/* 3E6DC 800632DC E7BA0044 */  swc1      $f26, 0x44($sp)
/* 3E6E0 800632E0 AFA20048 */  sw        $v0, 0x48($sp)
/* 3E6E4 800632E4 0C018A30 */  jal       guLookAtHiliteF
/* 3E6E8 800632E8 AFA3004C */   sw       $v1, 0x4c($sp)
/* 3E6EC 800632EC 27A40050 */  addiu     $a0, $sp, 0x50
/* 3E6F0 800632F0 0C019D40 */  jal       guMtxF2L
/* 3E6F4 800632F4 02002821 */   addu     $a1, $s0, $zero
/* 3E6F8 800632F8 8FBF0094 */  lw        $ra, 0x94($sp)
/* 3E6FC 800632FC 8FB00090 */  lw        $s0, 0x90($sp)
/* 3E700 80063300 D7BA00B0 */  ldc1      $f26, 0xb0($sp)
/* 3E704 80063304 D7B800A8 */  ldc1      $f24, 0xa8($sp)
/* 3E708 80063308 D7B600A0 */  ldc1      $f22, 0xa0($sp)
/* 3E70C 8006330C D7B40098 */  ldc1      $f20, 0x98($sp)
/* 3E710 80063310 03E00008 */  jr        $ra
/* 3E714 80063314 27BD00B8 */   addiu    $sp, $sp, 0xb8
/* 3E718 80063318 00000000 */  nop
/* 3E71C 8006331C 00000000 */  nop
