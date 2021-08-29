.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B20_CF9690
/* CF9690 80241B20 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CF9694 80241B24 AFB10014 */  sw        $s1, 0x14($sp)
/* CF9698 80241B28 0080882D */  daddu     $s1, $a0, $zero
/* CF969C 80241B2C AFBF0020 */  sw        $ra, 0x20($sp)
/* CF96A0 80241B30 AFB3001C */  sw        $s3, 0x1c($sp)
/* CF96A4 80241B34 AFB20018 */  sw        $s2, 0x18($sp)
/* CF96A8 80241B38 AFB00010 */  sw        $s0, 0x10($sp)
/* CF96AC 80241B3C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* CF96B0 80241B40 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* CF96B4 80241B44 F7B80038 */  sdc1      $f24, 0x38($sp)
/* CF96B8 80241B48 F7B60030 */  sdc1      $f22, 0x30($sp)
/* CF96BC 80241B4C F7B40028 */  sdc1      $f20, 0x28($sp)
/* CF96C0 80241B50 8E30000C */  lw        $s0, 0xc($s1)
/* CF96C4 80241B54 8E050000 */  lw        $a1, ($s0)
/* CF96C8 80241B58 0C0B1EAF */  jal       evt_get_variable
/* CF96CC 80241B5C 26100004 */   addiu    $s0, $s0, 4
/* CF96D0 80241B60 8E050000 */  lw        $a1, ($s0)
/* CF96D4 80241B64 26100004 */  addiu     $s0, $s0, 4
/* CF96D8 80241B68 0220202D */  daddu     $a0, $s1, $zero
/* CF96DC 80241B6C 0C0B1EAF */  jal       evt_get_variable
/* CF96E0 80241B70 0040902D */   daddu    $s2, $v0, $zero
/* CF96E4 80241B74 0220202D */  daddu     $a0, $s1, $zero
/* CF96E8 80241B78 8E050000 */  lw        $a1, ($s0)
/* CF96EC 80241B7C 0C0B1EAF */  jal       evt_get_variable
/* CF96F0 80241B80 0040982D */   daddu    $s3, $v0, $zero
/* CF96F4 80241B84 3C10800B */  lui       $s0, %hi(gCameras)
/* CF96F8 80241B88 26101D80 */  addiu     $s0, $s0, %lo(gCameras)
/* CF96FC 80241B8C C60C006C */  lwc1      $f12, 0x6c($s0)
/* CF9700 80241B90 3C014387 */  lui       $at, 0x4387
/* CF9704 80241B94 4481B000 */  mtc1      $at, $f22
/* CF9708 80241B98 00000000 */  nop
/* CF970C 80241B9C 46166300 */  add.s     $f12, $f12, $f22
/* CF9710 80241BA0 4482C000 */  mtc1      $v0, $f24
/* CF9714 80241BA4 00000000 */  nop
/* CF9718 80241BA8 4680C620 */  cvt.s.w   $f24, $f24
/* CF971C 80241BAC 3C0142C8 */  lui       $at, 0x42c8
/* CF9720 80241BB0 4481D000 */  mtc1      $at, $f26
/* CF9724 80241BB4 0C00A8BB */  jal       sin_deg
/* CF9728 80241BB8 46186300 */   add.s    $f12, $f12, $f24
/* CF972C 80241BBC 461A0002 */  mul.s     $f0, $f0, $f26
/* CF9730 80241BC0 00000000 */  nop
/* CF9734 80241BC4 4492A000 */  mtc1      $s2, $f20
/* CF9738 80241BC8 00000000 */  nop
/* CF973C 80241BCC 4680A520 */  cvt.s.w   $f20, $f20
/* CF9740 80241BD0 4600A000 */  add.s     $f0, $f20, $f0
/* CF9744 80241BD4 4600008D */  trunc.w.s $f2, $f0
/* CF9748 80241BD8 E6220084 */  swc1      $f2, 0x84($s1)
/* CF974C 80241BDC C60C006C */  lwc1      $f12, 0x6c($s0)
/* CF9750 80241BE0 46166300 */  add.s     $f12, $f12, $f22
/* CF9754 80241BE4 0C00A8D4 */  jal       cos_deg
/* CF9758 80241BE8 46186300 */   add.s    $f12, $f12, $f24
/* CF975C 80241BEC 461A0002 */  mul.s     $f0, $f0, $f26
/* CF9760 80241BF0 00000000 */  nop
/* CF9764 80241BF4 4493B000 */  mtc1      $s3, $f22
/* CF9768 80241BF8 00000000 */  nop
/* CF976C 80241BFC 4680B5A0 */  cvt.s.w   $f22, $f22
/* CF9770 80241C00 4600B001 */  sub.s     $f0, $f22, $f0
/* CF9774 80241C04 3C0142B4 */  lui       $at, 0x42b4
/* CF9778 80241C08 4481E000 */  mtc1      $at, $f28
/* CF977C 80241C0C 4600008D */  trunc.w.s $f2, $f0
/* CF9780 80241C10 E6220088 */  swc1      $f2, 0x88($s1)
/* CF9784 80241C14 C60C006C */  lwc1      $f12, 0x6c($s0)
/* CF9788 80241C18 461C6300 */  add.s     $f12, $f12, $f28
/* CF978C 80241C1C 0C00A8BB */  jal       sin_deg
/* CF9790 80241C20 46186300 */   add.s    $f12, $f12, $f24
/* CF9794 80241C24 461A0002 */  mul.s     $f0, $f0, $f26
/* CF9798 80241C28 00000000 */  nop
/* CF979C 80241C2C 4600A500 */  add.s     $f20, $f20, $f0
/* CF97A0 80241C30 4600A08D */  trunc.w.s $f2, $f20
/* CF97A4 80241C34 E622008C */  swc1      $f2, 0x8c($s1)
/* CF97A8 80241C38 C60C006C */  lwc1      $f12, 0x6c($s0)
/* CF97AC 80241C3C 461C6300 */  add.s     $f12, $f12, $f28
/* CF97B0 80241C40 0C00A8D4 */  jal       cos_deg
/* CF97B4 80241C44 46186300 */   add.s    $f12, $f12, $f24
/* CF97B8 80241C48 461A0002 */  mul.s     $f0, $f0, $f26
/* CF97BC 80241C4C 00000000 */  nop
/* CF97C0 80241C50 4600B581 */  sub.s     $f22, $f22, $f0
/* CF97C4 80241C54 4600B08D */  trunc.w.s $f2, $f22
/* CF97C8 80241C58 E6220090 */  swc1      $f2, 0x90($s1)
/* CF97CC 80241C5C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CF97D0 80241C60 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF97D4 80241C64 8FB20018 */  lw        $s2, 0x18($sp)
/* CF97D8 80241C68 8FB10014 */  lw        $s1, 0x14($sp)
/* CF97DC 80241C6C 8FB00010 */  lw        $s0, 0x10($sp)
/* CF97E0 80241C70 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* CF97E4 80241C74 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* CF97E8 80241C78 D7B80038 */  ldc1      $f24, 0x38($sp)
/* CF97EC 80241C7C D7B60030 */  ldc1      $f22, 0x30($sp)
/* CF97F0 80241C80 D7B40028 */  ldc1      $f20, 0x28($sp)
/* CF97F4 80241C84 24020002 */  addiu     $v0, $zero, 2
/* CF97F8 80241C88 03E00008 */  jr        $ra
/* CF97FC 80241C8C 27BD0050 */   addiu    $sp, $sp, 0x50
