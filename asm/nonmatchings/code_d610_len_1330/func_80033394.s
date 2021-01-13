.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033394
/* E794 80033394 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E798 80033398 AFB00010 */  sw        $s0, 0x10($sp)
/* E79C 8003339C 0080802D */  daddu     $s0, $a0, $zero
/* E7A0 800333A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* E7A4 800333A4 F7B60020 */  sdc1      $f22, 0x20($sp)
/* E7A8 800333A8 F7B40018 */  sdc1      $f20, 0x18($sp)
/* E7AC 800333AC C602003C */  lwc1      $f2, 0x3c($s0)
/* E7B0 800333B0 C6000048 */  lwc1      $f0, 0x48($s0)
/* E7B4 800333B4 46001081 */  sub.s     $f2, $f2, $f0
/* E7B8 800333B8 46021082 */  mul.s     $f2, $f2, $f2
/* E7BC 800333BC 00000000 */  nop
/* E7C0 800333C0 C6060040 */  lwc1      $f6, 0x40($s0)
/* E7C4 800333C4 C600004C */  lwc1      $f0, 0x4c($s0)
/* E7C8 800333C8 46003181 */  sub.s     $f6, $f6, $f0
/* E7CC 800333CC 46063182 */  mul.s     $f6, $f6, $f6
/* E7D0 800333D0 00000000 */  nop
/* E7D4 800333D4 C6040050 */  lwc1      $f4, 0x50($s0)
/* E7D8 800333D8 C6000044 */  lwc1      $f0, 0x44($s0)
/* E7DC 800333DC 46040001 */  sub.s     $f0, $f0, $f4
/* E7E0 800333E0 46000002 */  mul.s     $f0, $f0, $f0
/* E7E4 800333E4 00000000 */  nop
/* E7E8 800333E8 46061080 */  add.s     $f2, $f2, $f6
/* E7EC 800333EC 46001300 */  add.s     $f12, $f2, $f0
/* E7F0 800333F0 46006584 */  sqrt.s    $f22, $f12
/* E7F4 800333F4 4616B032 */  c.eq.s    $f22, $f22
/* E7F8 800333F8 00000000 */  nop
/* E7FC 800333FC 45010004 */  bc1t      .L80033410
/* E800 80033400 00000000 */   nop
/* E804 80033404 0C0187BC */  jal       sqrtf
/* E808 80033408 00000000 */   nop
/* E80C 8003340C 46000586 */  mov.s     $f22, $f0
.L80033410:
/* E810 80033410 C6140018 */  lwc1      $f20, 0x18($s0)
/* E814 80033414 3C013F00 */  lui       $at, 0x3f00
/* E818 80033418 44810000 */  mtc1      $at, $f0
/* E81C 8003341C 00000000 */  nop
/* E820 80033420 4600A502 */  mul.s     $f20, $f20, $f0
/* E824 80033424 00000000 */  nop
/* E828 80033428 3C014334 */  lui       $at, 0x4334
/* E82C 8003342C 44810000 */  mtc1      $at, $f0
/* E830 80033430 3C014049 */  lui       $at, 0x4049
/* E834 80033434 34210FD8 */  ori       $at, $at, 0xfd8
/* E838 80033438 44811000 */  mtc1      $at, $f2
/* E83C 8003343C 4600A503 */  div.s     $f20, $f20, $f0
/* E840 80033440 4602A502 */  mul.s     $f20, $f20, $f2
/* E844 80033444 00000000 */  nop
/* E848 80033448 0C00A85B */  jal       sin_rad
/* E84C 8003344C 4600A306 */   mov.s    $f12, $f20
/* E850 80033450 4600B582 */  mul.s     $f22, $f22, $f0
/* E854 80033454 00000000 */  nop
/* E858 80033458 0C00A874 */  jal       cos_rad
/* E85C 8003345C 4600A306 */   mov.s    $f12, $f20
/* E860 80033460 8602000A */  lh        $v0, 0xa($s0)
/* E864 80033464 4600B583 */  div.s     $f22, $f22, $f0
/* E868 80033468 44820000 */  mtc1      $v0, $f0
/* E86C 8003346C 00000000 */  nop
/* E870 80033470 46800020 */  cvt.s.w   $f0, $f0
/* E874 80033474 4600B582 */  mul.s     $f22, $f22, $f0
/* E878 80033478 00000000 */  nop
/* E87C 8003347C 8602000C */  lh        $v0, 0xc($s0)
/* E880 80033480 C6020520 */  lwc1      $f2, 0x520($s0)
/* E884 80033484 44820000 */  mtc1      $v0, $f0
/* E888 80033488 00000000 */  nop
/* E88C 8003348C 46800020 */  cvt.s.w   $f0, $f0
/* E890 80033490 4600B583 */  div.s     $f22, $f22, $f0
/* E894 80033494 4602B582 */  mul.s     $f22, $f22, $f2
/* E898 80033498 00000000 */  nop
/* E89C 8003349C 4405B000 */  mfc1      $a1, $f22
/* E8A0 800334A0 0C00CA5C */  jal       func_80032970
/* E8A4 800334A4 0200202D */   daddu    $a0, $s0, $zero
/* E8A8 800334A8 0C00CB19 */  jal       func_80032C64
/* E8AC 800334AC 0200202D */   daddu    $a0, $s0, $zero
/* E8B0 800334B0 26040154 */  addiu     $a0, $s0, 0x154
/* E8B4 800334B4 C602050C */  lwc1      $f2, 0x50c($s0)
/* E8B8 800334B8 44800000 */  mtc1      $zero, $f0
/* E8BC 800334BC 46001087 */  neg.s     $f2, $f2
/* E8C0 800334C0 44060000 */  mfc1      $a2, $f0
/* E8C4 800334C4 44051000 */  mfc1      $a1, $f2
/* E8C8 800334C8 0C019E40 */  jal       guTranslateF
/* E8CC 800334CC 00C0382D */   daddu    $a3, $a2, $zero
/* E8D0 800334D0 8FBF0014 */  lw        $ra, 0x14($sp)
/* E8D4 800334D4 8FB00010 */  lw        $s0, 0x10($sp)
/* E8D8 800334D8 D7B60020 */  ldc1      $f22, 0x20($sp)
/* E8DC 800334DC D7B40018 */  ldc1      $f20, 0x18($sp)
/* E8E0 800334E0 03E00008 */  jr        $ra
/* E8E4 800334E4 27BD0028 */   addiu    $sp, $sp, 0x28
