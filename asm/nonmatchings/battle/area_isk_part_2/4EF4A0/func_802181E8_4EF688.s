.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181E8_4EF688
/* 4EF688 802181E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4EF68C 802181EC F7B60020 */  sdc1      $f22, 0x20($sp)
/* 4EF690 802181F0 4485B000 */  mtc1      $a1, $f22
/* 4EF694 802181F4 3C0140C9 */  lui       $at, 0x40c9
/* 4EF698 802181F8 34210FD0 */  ori       $at, $at, 0xfd0
/* 4EF69C 802181FC 44810000 */  mtc1      $at, $f0
/* 4EF6A0 80218200 44861000 */  mtc1      $a2, $f2
/* 4EF6A4 80218204 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 4EF6A8 80218208 46001502 */  mul.s     $f20, $f2, $f0
/* 4EF6AC 8021820C 00000000 */  nop       
/* 4EF6B0 80218210 AFB00010 */  sw        $s0, 0x10($sp)
/* 4EF6B4 80218214 3C0143B4 */  lui       $at, 0x43b4
/* 4EF6B8 80218218 44810000 */  mtc1      $at, $f0
/* 4EF6BC 8021821C 0080802D */  daddu     $s0, $a0, $zero
/* 4EF6C0 80218220 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4EF6C4 80218224 4600A503 */  div.s     $f20, $f20, $f0
/* 4EF6C8 80218228 0C00A85B */  jal       sin_rad
/* 4EF6CC 8021822C 4600A306 */   mov.s    $f12, $f20
/* 4EF6D0 80218230 0C00A874 */  jal       cos_rad
/* 4EF6D4 80218234 4600A306 */   mov.s    $f12, $f20
/* 4EF6D8 80218238 4600B582 */  mul.s     $f22, $f22, $f0
/* 4EF6DC 8021823C 00000000 */  nop       
/* 4EF6E0 80218240 E6160000 */  swc1      $f22, ($s0)
/* 4EF6E4 80218244 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4EF6E8 80218248 8FB00010 */  lw        $s0, 0x10($sp)
/* 4EF6EC 8021824C D7B60020 */  ldc1      $f22, 0x20($sp)
/* 4EF6F0 80218250 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 4EF6F4 80218254 03E00008 */  jr        $ra
/* 4EF6F8 80218258 27BD0028 */   addiu    $sp, $sp, 0x28
