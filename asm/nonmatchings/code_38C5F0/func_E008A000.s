.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008A000
/* 38C5F0 E008A000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 38C5F4 E008A004 AFB10014 */  sw        $s1, 0x14($sp)
/* 38C5F8 E008A008 0080882D */  daddu     $s1, $a0, $zero
/* 38C5FC E008A00C 240407D0 */  addiu     $a0, $zero, 0x7d0
/* 38C600 E008A010 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 38C604 E008A014 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 38C608 E008A018 3C03800B */  lui       $v1, %hi(gCameras)
/* 38C60C E008A01C 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 38C610 E008A020 AFBF0018 */  sw        $ra, 0x18($sp)
/* 38C614 E008A024 AFB00010 */  sw        $s0, 0x10($sp)
/* 38C618 E008A028 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 38C61C E008A02C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 38C620 E008A030 00028080 */  sll       $s0, $v0, 2
/* 38C624 E008A034 02028021 */  addu      $s0, $s0, $v0
/* 38C628 E008A038 00108080 */  sll       $s0, $s0, 2
/* 38C62C E008A03C 02028023 */  subu      $s0, $s0, $v0
/* 38C630 E008A040 001010C0 */  sll       $v0, $s0, 3
/* 38C634 E008A044 02028021 */  addu      $s0, $s0, $v0
/* 38C638 E008A048 001080C0 */  sll       $s0, $s0, 3
/* 38C63C E008A04C 0C080000 */  jal       func_E0200000
/* 38C640 E008A050 02038021 */   addu     $s0, $s0, $v1
/* 38C644 E008A054 C600003C */  lwc1      $f0, 0x3c($s0)
/* 38C648 E008A058 44821000 */  mtc1      $v0, $f2
/* 38C64C E008A05C 00000000 */  nop       
/* 38C650 E008A060 468010A0 */  cvt.s.w   $f2, $f2
/* 38C654 E008A064 46020000 */  add.s     $f0, $f0, $f2
/* 38C658 E008A068 3C01447A */  lui       $at, 0x447a
/* 38C65C E008A06C 4481A000 */  mtc1      $at, $f20
/* 38C660 E008A070 00000000 */  nop       
/* 38C664 E008A074 46140001 */  sub.s     $f0, $f0, $f20
/* 38C668 E008A078 240407D0 */  addiu     $a0, $zero, 0x7d0
/* 38C66C E008A07C 0C080000 */  jal       func_E0200000
/* 38C670 E008A080 E6200008 */   swc1     $f0, 8($s1)
/* 38C674 E008A084 C6000040 */  lwc1      $f0, 0x40($s0)
/* 38C678 E008A088 44821000 */  mtc1      $v0, $f2
/* 38C67C E008A08C 00000000 */  nop       
/* 38C680 E008A090 468010A0 */  cvt.s.w   $f2, $f2
/* 38C684 E008A094 46020000 */  add.s     $f0, $f0, $f2
/* 38C688 E008A098 46140001 */  sub.s     $f0, $f0, $f20
/* 38C68C E008A09C 240407D0 */  addiu     $a0, $zero, 0x7d0
/* 38C690 E008A0A0 0C080000 */  jal       func_E0200000
/* 38C694 E008A0A4 E620000C */   swc1     $f0, 0xc($s1)
/* 38C698 E008A0A8 C6000044 */  lwc1      $f0, 0x44($s0)
/* 38C69C E008A0AC 44821000 */  mtc1      $v0, $f2
/* 38C6A0 E008A0B0 00000000 */  nop       
/* 38C6A4 E008A0B4 468010A0 */  cvt.s.w   $f2, $f2
/* 38C6A8 E008A0B8 46020000 */  add.s     $f0, $f0, $f2
/* 38C6AC E008A0BC 46140001 */  sub.s     $f0, $f0, $f20
/* 38C6B0 E008A0C0 24040014 */  addiu     $a0, $zero, 0x14
/* 38C6B4 E008A0C4 0C080000 */  jal       func_E0200000
/* 38C6B8 E008A0C8 E6200010 */   swc1     $f0, 0x10($s1)
/* 38C6BC E008A0CC 3C014120 */  lui       $at, 0x4120
/* 38C6C0 E008A0D0 4481B000 */  mtc1      $at, $f22
/* 38C6C4 E008A0D4 44820000 */  mtc1      $v0, $f0
/* 38C6C8 E008A0D8 00000000 */  nop       
/* 38C6CC E008A0DC 46800020 */  cvt.s.w   $f0, $f0
/* 38C6D0 E008A0E0 46160001 */  sub.s     $f0, $f0, $f22
/* 38C6D4 E008A0E4 3C01E009 */  lui       $at, %hi(D_E008AA60)
/* 38C6D8 E008A0E8 D434AA60 */  ldc1      $f20, %lo(D_E008AA60)($at)
/* 38C6DC E008A0EC 46000021 */  cvt.d.s   $f0, $f0
/* 38C6E0 E008A0F0 46340002 */  mul.d     $f0, $f0, $f20
/* 38C6E4 E008A0F4 00000000 */  nop       
/* 38C6E8 E008A0F8 24040050 */  addiu     $a0, $zero, 0x50
/* 38C6EC E008A0FC 46200020 */  cvt.s.d   $f0, $f0
/* 38C6F0 E008A100 0C080000 */  jal       func_E0200000
/* 38C6F4 E008A104 E6200014 */   swc1     $f0, 0x14($s1)
/* 38C6F8 E008A108 3C01E009 */  lui       $at, %hi(D_E008AA68)
/* 38C6FC E008A10C D420AA68 */  ldc1      $f0, %lo(D_E008AA68)($at)
/* 38C700 E008A110 44821000 */  mtc1      $v0, $f2
/* 38C704 E008A114 00000000 */  nop       
/* 38C708 E008A118 468010A1 */  cvt.d.w   $f2, $f2
/* 38C70C E008A11C 46201082 */  mul.d     $f2, $f2, $f0
/* 38C710 E008A120 00000000 */  nop       
/* 38C714 E008A124 3C01E009 */  lui       $at, %hi(D_E008AA70)
/* 38C718 E008A128 D420AA70 */  ldc1      $f0, %lo(D_E008AA70)($at)
/* 38C71C E008A12C 46220001 */  sub.d     $f0, $f0, $f2
/* 38C720 E008A130 24040014 */  addiu     $a0, $zero, 0x14
/* 38C724 E008A134 46200020 */  cvt.s.d   $f0, $f0
/* 38C728 E008A138 0C080000 */  jal       func_E0200000
/* 38C72C E008A13C E6200018 */   swc1     $f0, 0x18($s1)
/* 38C730 E008A140 44820000 */  mtc1      $v0, $f0
/* 38C734 E008A144 00000000 */  nop       
/* 38C738 E008A148 46800020 */  cvt.s.w   $f0, $f0
/* 38C73C E008A14C 46160001 */  sub.s     $f0, $f0, $f22
/* 38C740 E008A150 46000021 */  cvt.d.s   $f0, $f0
/* 38C744 E008A154 46340002 */  mul.d     $f0, $f0, $f20
/* 38C748 E008A158 00000000 */  nop       
/* 38C74C E008A15C 240200FF */  addiu     $v0, $zero, 0xff
/* 38C750 E008A160 AE220028 */  sw        $v0, 0x28($s1)
/* 38C754 E008A164 46200020 */  cvt.s.d   $f0, $f0
/* 38C758 E008A168 E620001C */  swc1      $f0, 0x1c($s1)
/* 38C75C E008A16C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 38C760 E008A170 8FB10014 */  lw        $s1, 0x14($sp)
/* 38C764 E008A174 8FB00010 */  lw        $s0, 0x10($sp)
/* 38C768 E008A178 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 38C76C E008A17C D7B40020 */  ldc1      $f20, 0x20($sp)
/* 38C770 E008A180 03E00008 */  jr        $ra
/* 38C774 E008A184 27BD0030 */   addiu    $sp, $sp, 0x30
