.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E0_ED00D0
/* ED00D0 802400E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* ED00D4 802400E4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* ED00D8 802400E8 4485A000 */  mtc1      $a1, $f20
/* ED00DC 802400EC F7B60020 */  sdc1      $f22, 0x20($sp)
/* ED00E0 802400F0 4486B000 */  mtc1      $a2, $f22
/* ED00E4 802400F4 AFB00010 */  sw        $s0, 0x10($sp)
/* ED00E8 802400F8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* ED00EC 802400FC 4487C000 */  mtc1      $a3, $f24
/* ED00F0 80240100 AFBF0014 */  sw        $ra, 0x14($sp)
/* ED00F4 80240104 0C01B198 */  jal       osGetCause
/* ED00F8 80240108 0080802D */   daddu    $s0, $a0, $zero
/* ED00FC 8024010C 4616A582 */  mul.s     $f22, $f20, $f22
/* ED0100 80240110 00000000 */  nop
/* ED0104 80240114 4618A502 */  mul.s     $f20, $f20, $f24
/* ED0108 80240118 00000000 */  nop
/* ED010C 8024011C 3C013F80 */  lui       $at, 0x3f80
/* ED0110 80240120 44810000 */  mtc1      $at, $f0
/* ED0114 80240124 00000000 */  nop
/* ED0118 80240128 E6000014 */  swc1      $f0, 0x14($s0)
/* ED011C 8024012C E6160010 */  swc1      $f22, 0x10($s0)
/* ED0120 80240130 E6140018 */  swc1      $f20, 0x18($s0)
/* ED0124 80240134 8FBF0014 */  lw        $ra, 0x14($sp)
/* ED0128 80240138 8FB00010 */  lw        $s0, 0x10($sp)
/* ED012C 8024013C D7B80028 */  ldc1      $f24, 0x28($sp)
/* ED0130 80240140 D7B60020 */  ldc1      $f22, 0x20($sp)
/* ED0134 80240144 D7B40018 */  ldc1      $f20, 0x18($sp)
/* ED0138 80240148 03E00008 */  jr        $ra
/* ED013C 8024014C 27BD0030 */   addiu    $sp, $sp, 0x30
