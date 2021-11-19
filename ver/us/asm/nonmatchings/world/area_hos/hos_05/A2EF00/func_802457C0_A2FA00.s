.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_8024F280_A394C0
.double 0.01, 1.1479345624872949e+195, 1.1479345581702053e+195, 0.0

.section .text

glabel func_802457C0_A2FA00
/* A2FA00 802457C0 3C06800B */  lui       $a2, %hi(gCameras)
/* A2FA04 802457C4 24C61D80 */  addiu     $a2, $a2, %lo(gCameras)
/* A2FA08 802457C8 10A00003 */  beqz      $a1, .L802457D8
/* A2FA0C 802457CC 00C0382D */   daddu    $a3, $a2, $zero
/* A2FA10 802457D0 24020028 */  addiu     $v0, $zero, 0x28
/* A2FA14 802457D4 AC820070 */  sw        $v0, 0x70($a0)
.L802457D8:
/* A2FA18 802457D8 8C820070 */  lw        $v0, 0x70($a0)
/* A2FA1C 802457DC 2443FFFF */  addiu     $v1, $v0, -1
/* A2FA20 802457E0 AC830070 */  sw        $v1, 0x70($a0)
/* A2FA24 802457E4 8CC50448 */  lw        $a1, 0x448($a2)
/* A2FA28 802457E8 54A00005 */  bnel      $a1, $zero, .L80245800
/* A2FA2C 802457EC 24020028 */   addiu    $v0, $zero, 0x28
/* A2FA30 802457F0 8CE50444 */  lw        $a1, 0x444($a3)
/* A2FA34 802457F4 10A00014 */  beqz      $a1, .L80245848
/* A2FA38 802457F8 00000000 */   nop
/* A2FA3C 802457FC 24020028 */  addiu     $v0, $zero, 0x28
.L80245800:
/* A2FA40 80245800 00431023 */  subu      $v0, $v0, $v1
/* A2FA44 80245804 44821000 */  mtc1      $v0, $f2
/* A2FA48 80245808 00000000 */  nop
/* A2FA4C 8024580C 468010A0 */  cvt.s.w   $f2, $f2
/* A2FA50 80245810 3C018025 */  lui       $at, %hi(D_8024F280_A394C0)
/* A2FA54 80245814 D420F280 */  ldc1      $f0, %lo(D_8024F280_A394C0)($at)
/* A2FA58 80245818 460010A1 */  cvt.d.s   $f2, $f2
/* A2FA5C 8024581C 46201082 */  mul.d     $f2, $f2, $f0
/* A2FA60 80245820 00000000 */  nop
/* A2FA64 80245824 3C013FF0 */  lui       $at, 0x3ff0
/* A2FA68 80245828 44812800 */  mtc1      $at, $f5
/* A2FA6C 8024582C 44802000 */  mtc1      $zero, $f4
/* A2FA70 80245830 C4A00024 */  lwc1      $f0, 0x24($a1)
/* A2FA74 80245834 46222101 */  sub.d     $f4, $f4, $f2
/* A2FA78 80245838 46000021 */  cvt.d.s   $f0, $f0
/* A2FA7C 8024583C 46240001 */  sub.d     $f0, $f0, $f4
/* A2FA80 80245840 46200020 */  cvt.s.d   $f0, $f0
/* A2FA84 80245844 E4A00024 */  swc1      $f0, 0x24($a1)
.L80245848:
/* A2FA88 80245848 8C820070 */  lw        $v0, 0x70($a0)
/* A2FA8C 8024584C 2C420001 */  sltiu     $v0, $v0, 1
/* A2FA90 80245850 03E00008 */  jr        $ra
/* A2FA94 80245854 00021040 */   sll      $v0, $v0, 1
/* A2FA98 80245858 00000000 */  nop
/* A2FA9C 8024585C 00000000 */  nop
