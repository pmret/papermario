.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80151270
.double 127.0

dlabel D_80151278
.double 90.0

dlabel D_80151280
.double 6.283180236816406

dlabel D_80151288
.double 360.0

.section .text

glabel sfx_compute_spatialized_sound_params_0
/* E0658 80149F58 44860000 */  mtc1      $a2, $f0
/* E065C 80149F5C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* E0660 80149F60 AFB00030 */  sw        $s0, 0x30($sp)
/* E0664 80149F64 00E0802D */  daddu     $s0, $a3, $zero
/* E0668 80149F68 AFB10034 */  sw        $s1, 0x34($sp)
/* E066C 80149F6C 8FB10058 */  lw        $s1, 0x58($sp)
/* E0670 80149F70 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* E0674 80149F74 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* E0678 80149F78 44056000 */  mfc1      $a1, $f12
/* E067C 80149F7C 44067000 */  mfc1      $a2, $f14
/* E0680 80149F80 27A20020 */  addiu     $v0, $sp, 0x20
/* E0684 80149F84 AFA20010 */  sw        $v0, 0x10($sp)
/* E0688 80149F88 27A20024 */  addiu     $v0, $sp, 0x24
/* E068C 80149F8C AFA20014 */  sw        $v0, 0x14($sp)
/* E0690 80149F90 44070000 */  mfc1      $a3, $f0
/* E0694 80149F94 27A20028 */  addiu     $v0, $sp, 0x28
/* E0698 80149F98 AFBF0038 */  sw        $ra, 0x38($sp)
/* E069C 80149F9C F7B40040 */  sdc1      $f20, 0x40($sp)
/* E06A0 80149FA0 0C00B94E */  jal       get_screen_coords
/* E06A4 80149FA4 AFA20018 */   sw       $v0, 0x18($sp)
/* E06A8 80149FA8 8FA20020 */  lw        $v0, 0x20($sp)
/* E06AC 80149FAC 24420BB8 */  addiu     $v0, $v0, 0xbb8
/* E06B0 80149FB0 2C421771 */  sltiu     $v0, $v0, 0x1771
/* E06B4 80149FB4 10400008 */  beqz      $v0, .L80149FD8
/* E06B8 80149FB8 24020001 */   addiu    $v0, $zero, 1
/* E06BC 80149FBC 8FA30024 */  lw        $v1, 0x24($sp)
/* E06C0 80149FC0 28620BB9 */  slti      $v0, $v1, 0xbb9
/* E06C4 80149FC4 10400003 */  beqz      $v0, .L80149FD4
/* E06C8 80149FC8 2862F448 */   slti     $v0, $v1, -0xbb8
/* E06CC 80149FCC 10400005 */  beqz      $v0, .L80149FE4
/* E06D0 80149FD0 2402007F */   addiu    $v0, $zero, 0x7f
.L80149FD4:
/* E06D4 80149FD4 24020001 */  addiu     $v0, $zero, 1
.L80149FD8:
/* E06D8 80149FD8 A6020000 */  sh        $v0, ($s0)
/* E06DC 80149FDC 08052867 */  j         .L8014A19C
/* E06E0 80149FE0 A6200000 */   sh       $zero, ($s1)
.L80149FE4:
/* E06E4 80149FE4 A6020000 */  sh        $v0, ($s0)
/* E06E8 80149FE8 8FA20020 */  lw        $v0, 0x20($sp)
/* E06EC 80149FEC 04410012 */  bgez      $v0, .L8014A038
/* E06F0 80149FF0 00000000 */   nop
/* E06F4 80149FF4 3C013E99 */  lui       $at, 0x3e99
/* E06F8 80149FF8 3421999A */  ori       $at, $at, 0x999a
/* E06FC 80149FFC 44811000 */  mtc1      $at, $f2
/* E0700 8014A000 44820000 */  mtc1      $v0, $f0
/* E0704 8014A004 00000000 */  nop
/* E0708 8014A008 46800020 */  cvt.s.w   $f0, $f0
/* E070C 8014A00C 46020002 */  mul.s     $f0, $f0, $f2
/* E0710 8014A010 00000000 */  nop
/* E0714 8014A014 3C0142FE */  lui       $at, 0x42fe
/* E0718 8014A018 44811000 */  mtc1      $at, $f2
/* E071C 8014A01C 00000000 */  nop
/* E0720 8014A020 46020000 */  add.s     $f0, $f0, $f2
/* E0724 8014A024 4600010D */  trunc.w.s $f4, $f0
/* E0728 8014A028 44022000 */  mfc1      $v0, $f4
/* E072C 8014A02C 00000000 */  nop
/* E0730 8014A030 A6020000 */  sh        $v0, ($s0)
/* E0734 8014A034 AFA00020 */  sw        $zero, 0x20($sp)
.L8014A038:
/* E0738 8014A038 8FA30020 */  lw        $v1, 0x20($sp)
/* E073C 8014A03C 28620141 */  slti      $v0, $v1, 0x141
/* E0740 8014A040 14400013 */  bnez      $v0, .L8014A090
/* E0744 8014A044 2462FEC0 */   addiu    $v0, $v1, -0x140
/* E0748 8014A048 3C013E99 */  lui       $at, 0x3e99
/* E074C 8014A04C 3421999A */  ori       $at, $at, 0x999a
/* E0750 8014A050 44810000 */  mtc1      $at, $f0
/* E0754 8014A054 44821000 */  mtc1      $v0, $f2
/* E0758 8014A058 00000000 */  nop
/* E075C 8014A05C 468010A0 */  cvt.s.w   $f2, $f2
/* E0760 8014A060 46001082 */  mul.s     $f2, $f2, $f0
/* E0764 8014A064 00000000 */  nop
/* E0768 8014A068 3C0142FE */  lui       $at, 0x42fe
/* E076C 8014A06C 44810000 */  mtc1      $at, $f0
/* E0770 8014A070 00000000 */  nop
/* E0774 8014A074 46020001 */  sub.s     $f0, $f0, $f2
/* E0778 8014A078 4600010D */  trunc.w.s $f4, $f0
/* E077C 8014A07C 44022000 */  mfc1      $v0, $f4
/* E0780 8014A080 00000000 */  nop
/* E0784 8014A084 A6020000 */  sh        $v0, ($s0)
/* E0788 8014A088 24020140 */  addiu     $v0, $zero, 0x140
/* E078C 8014A08C AFA20020 */  sw        $v0, 0x20($sp)
.L8014A090:
/* E0790 8014A090 86020000 */  lh        $v0, ($s0)
/* E0794 8014A094 1C400002 */  bgtz      $v0, .L8014A0A0
/* E0798 8014A098 24020001 */   addiu    $v0, $zero, 1
/* E079C 8014A09C A6020000 */  sh        $v0, ($s0)
.L8014A0A0:
/* E07A0 8014A0A0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E07A4 8014A0A4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E07A8 8014A0A8 80420070 */  lb        $v0, 0x70($v0)
/* E07AC 8014A0AC 14400010 */  bnez      $v0, .L8014A0F0
/* E07B0 8014A0B0 00000000 */   nop
/* E07B4 8014A0B4 3C013E4C */  lui       $at, 0x3e4c
/* E07B8 8014A0B8 3421CCCD */  ori       $at, $at, 0xcccd
/* E07BC 8014A0BC 44811000 */  mtc1      $at, $f2
/* E07C0 8014A0C0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* E07C4 8014A0C4 46800020 */  cvt.s.w   $f0, $f0
/* E07C8 8014A0C8 46020002 */  mul.s     $f0, $f0, $f2
/* E07CC 8014A0CC 00000000 */  nop
/* E07D0 8014A0D0 3C014200 */  lui       $at, 0x4200
/* E07D4 8014A0D4 44811000 */  mtc1      $at, $f2
/* E07D8 8014A0D8 00000000 */  nop
/* E07DC 8014A0DC 46020000 */  add.s     $f0, $f0, $f2
/* E07E0 8014A0E0 4600010D */  trunc.w.s $f4, $f0
/* E07E4 8014A0E4 44022000 */  mfc1      $v0, $f4
/* E07E8 8014A0E8 08052867 */  j         .L8014A19C
/* E07EC 8014A0EC A6220000 */   sh       $v0, ($s1)
.L8014A0F0:
/* E07F0 8014A0F0 3C018015 */  lui       $at, %hi(D_80151270)
/* E07F4 8014A0F4 D4201270 */  ldc1      $f0, %lo(D_80151270)($at)
/* E07F8 8014A0F8 C7B40020 */  lwc1      $f20, 0x20($sp)
/* E07FC 8014A0FC 4680A521 */  cvt.d.w   $f20, $f20
/* E0800 8014A100 4620A502 */  mul.d     $f20, $f20, $f0
/* E0804 8014A104 00000000 */  nop
/* E0808 8014A108 3C014074 */  lui       $at, 0x4074
/* E080C 8014A10C 44810800 */  mtc1      $at, $f1
/* E0810 8014A110 44800000 */  mtc1      $zero, $f0
/* E0814 8014A114 3C014050 */  lui       $at, 0x4050
/* E0818 8014A118 44811800 */  mtc1      $at, $f3
/* E081C 8014A11C 44801000 */  mtc1      $zero, $f2
/* E0820 8014A120 4620A503 */  div.d     $f20, $f20, $f0
/* E0824 8014A124 4622A501 */  sub.d     $f20, $f20, $f2
/* E0828 8014A128 3C018015 */  lui       $at, %hi(D_80151278)
/* E082C 8014A12C D4201278 */  ldc1      $f0, %lo(D_80151278)($at)
/* E0830 8014A130 4620A520 */  cvt.s.d   $f20, $f20
/* E0834 8014A134 4600A321 */  cvt.d.s   $f12, $f20
/* E0838 8014A138 46206305 */  abs.d     $f12, $f12
/* E083C 8014A13C 46206302 */  mul.d     $f12, $f12, $f0
/* E0840 8014A140 00000000 */  nop
/* E0844 8014A144 3C013F90 */  lui       $at, 0x3f90
/* E0848 8014A148 44810800 */  mtc1      $at, $f1
/* E084C 8014A14C 44800000 */  mtc1      $zero, $f0
/* E0850 8014A150 00000000 */  nop
/* E0854 8014A154 46206302 */  mul.d     $f12, $f12, $f0
/* E0858 8014A158 00000000 */  nop
/* E085C 8014A15C 3C018015 */  lui       $at, %hi(D_80151280)
/* E0860 8014A160 D4201280 */  ldc1      $f0, %lo(D_80151280)($at)
/* E0864 8014A164 46206302 */  mul.d     $f12, $f12, $f0
/* E0868 8014A168 00000000 */  nop
/* E086C 8014A16C 3C018015 */  lui       $at, %hi(D_80151288)
/* E0870 8014A170 D4201288 */  ldc1      $f0, %lo(D_80151288)($at)
/* E0874 8014A174 46206303 */  div.d     $f12, $f12, $f0
/* E0878 8014A178 0C00A85B */  jal       sin_rad
/* E087C 8014A17C 46206320 */   cvt.s.d  $f12, $f12
/* E0880 8014A180 4600A502 */  mul.s     $f20, $f20, $f0
/* E0884 8014A184 00000000 */  nop
/* E0888 8014A188 4600A10D */  trunc.w.s $f4, $f20
/* E088C 8014A18C 44022000 */  mfc1      $v0, $f4
/* E0890 8014A190 00000000 */  nop
/* E0894 8014A194 24420040 */  addiu     $v0, $v0, 0x40
/* E0898 8014A198 A6220000 */  sh        $v0, ($s1)
.L8014A19C:
/* E089C 8014A19C 8FBF0038 */  lw        $ra, 0x38($sp)
/* E08A0 8014A1A0 8FB10034 */  lw        $s1, 0x34($sp)
/* E08A4 8014A1A4 8FB00030 */  lw        $s0, 0x30($sp)
/* E08A8 8014A1A8 D7B40040 */  ldc1      $f20, 0x40($sp)
/* E08AC 8014A1AC 03E00008 */  jr        $ra
/* E08B0 8014A1B0 27BD0048 */   addiu    $sp, $sp, 0x48
