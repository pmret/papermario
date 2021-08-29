.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel evt_set_float_variable
/* ECFF0 802C8640 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ECFF4 802C8644 AFB10014 */  sw        $s1, 0x14($sp)
/* ECFF8 802C8648 0080882D */  daddu     $s1, $a0, $zero
/* ECFFC 802C864C 3C02EFE8 */  lui       $v0, 0xefe8
/* ED000 802C8650 34422080 */  ori       $v0, $v0, 0x2080
/* ED004 802C8654 44866000 */  mtc1      $a2, $f12
/* ED008 802C8658 0045102A */  slt       $v0, $v0, $a1
/* ED00C 802C865C AFBF001C */  sw        $ra, 0x1c($sp)
/* ED010 802C8660 AFB20018 */  sw        $s2, 0x18($sp)
/* ED014 802C8664 1040003D */  beqz      $v0, .L802C875C
/* ED018 802C8668 AFB00010 */   sw       $s0, 0x10($sp)
/* ED01C 802C866C 3C02F2E3 */  lui       $v0, 0xf2e3
/* ED020 802C8670 34421100 */  ori       $v0, $v0, 0x1100
/* ED024 802C8674 0045102A */  slt       $v0, $v0, $a1
/* ED028 802C8678 10400038 */  beqz      $v0, .L802C875C
/* ED02C 802C867C 3C02F545 */   lui      $v0, 0xf545
/* ED030 802C8680 34426B00 */  ori       $v0, $v0, 0x6b00
/* ED034 802C8684 0045102A */  slt       $v0, $v0, $a1
/* ED038 802C8688 1440000E */  bnez      $v0, .L802C86C4
/* ED03C 802C868C 3C02FB3B */   lui      $v0, 0xfb3b
/* ED040 802C8690 3C020B53 */  lui       $v0, 0xb53
/* ED044 802C8694 34422B80 */  ori       $v0, $v0, 0x2b80
/* ED048 802C8698 00A22821 */  addu      $a1, $a1, $v0
/* ED04C 802C869C 8E22013C */  lw        $v0, 0x13c($s1)
/* ED050 802C86A0 00058080 */  sll       $s0, $a1, 2
/* ED054 802C86A4 02021021 */  addu      $v0, $s0, $v0
/* ED058 802C86A8 0C0B125B */  jal       evt_float_to_fixed_var
/* ED05C 802C86AC 8C520000 */   lw       $s2, ($v0)
/* ED060 802C86B0 8E23013C */  lw        $v1, 0x13c($s1)
/* ED064 802C86B4 0240202D */  daddu     $a0, $s2, $zero
/* ED068 802C86B8 02038021 */  addu      $s0, $s0, $v1
/* ED06C 802C86BC 080B221C */  j         .L802C8870
/* ED070 802C86C0 AE020000 */   sw       $v0, ($s0)
.L802C86C4:
/* ED074 802C86C4 34424C00 */  ori       $v0, $v0, 0x4c00
/* ED078 802C86C8 0045102A */  slt       $v0, $v0, $a1
/* ED07C 802C86CC 54400025 */  bnel      $v0, $zero, .L802C8764
/* ED080 802C86D0 3C02FC6C */   lui      $v0, 0xfc6c
/* ED084 802C86D4 3C02055D */  lui       $v0, 0x55d
/* ED088 802C86D8 34424A80 */  ori       $v0, $v0, 0x4a80
/* ED08C 802C86DC 00A22821 */  addu      $a1, $a1, $v0
/* ED090 802C86E0 04A10002 */  bgez      $a1, .L802C86EC
/* ED094 802C86E4 00A0102D */   daddu    $v0, $a1, $zero
/* ED098 802C86E8 24A2001F */  addiu     $v0, $a1, 0x1f
.L802C86EC:
/* ED09C 802C86EC 00023143 */  sra       $a2, $v0, 5
/* ED0A0 802C86F0 00C0202D */  daddu     $a0, $a2, $zero
/* ED0A4 802C86F4 00041140 */  sll       $v0, $a0, 5
/* ED0A8 802C86F8 44800000 */  mtc1      $zero, $f0
/* ED0AC 802C86FC 00000000 */  nop
/* ED0B0 802C8700 46006032 */  c.eq.s    $f12, $f0
/* ED0B4 802C8704 00000000 */  nop
/* ED0B8 802C8708 4501000A */  bc1t      .L802C8734
/* ED0BC 802C870C 00A23023 */   subu     $a2, $a1, $v0
/* ED0C0 802C8710 3C02802E */  lui       $v0, %hi(gMapFlags)
/* ED0C4 802C8714 8C42A480 */  lw        $v0, %lo(gMapFlags)($v0)
/* ED0C8 802C8718 00042080 */  sll       $a0, $a0, 2
/* ED0CC 802C871C 00822021 */  addu      $a0, $a0, $v0
/* ED0D0 802C8720 24020001 */  addiu     $v0, $zero, 1
/* ED0D4 802C8724 8C830000 */  lw        $v1, ($a0)
/* ED0D8 802C8728 00C21004 */  sllv      $v0, $v0, $a2
/* ED0DC 802C872C 080B21D6 */  j         .L802C8758
/* ED0E0 802C8730 00621825 */   or       $v1, $v1, $v0
.L802C8734:
/* ED0E4 802C8734 3C02802E */  lui       $v0, %hi(gMapFlags)
/* ED0E8 802C8738 8C42A480 */  lw        $v0, %lo(gMapFlags)($v0)
/* ED0EC 802C873C 00042080 */  sll       $a0, $a0, 2
/* ED0F0 802C8740 00822021 */  addu      $a0, $a0, $v0
/* ED0F4 802C8744 24020001 */  addiu     $v0, $zero, 1
/* ED0F8 802C8748 00C21004 */  sllv      $v0, $v0, $a2
/* ED0FC 802C874C 8C830000 */  lw        $v1, ($a0)
/* ED100 802C8750 00021027 */  nor       $v0, $zero, $v0
/* ED104 802C8754 00621824 */  and       $v1, $v1, $v0
.L802C8758:
/* ED108 802C8758 AC830000 */  sw        $v1, ($a0)
.L802C875C:
/* ED10C 802C875C 080B221E */  j         .L802C8878
/* ED110 802C8760 46006006 */   mov.s    $f0, $f12
.L802C8764:
/* ED114 802C8764 34427900 */  ori       $v0, $v0, 0x7900
/* ED118 802C8768 0045102A */  slt       $v0, $v0, $a1
/* ED11C 802C876C 54400020 */  bnel      $v0, $zero, .L802C87F0
/* ED120 802C8770 3C02FD9D */   lui      $v0, 0xfd9d
/* ED124 802C8774 3C02042C */  lui       $v0, 0x42c
/* ED128 802C8778 34421D80 */  ori       $v0, $v0, 0x1d80
/* ED12C 802C877C 00A22821 */  addu      $a1, $a1, $v0
/* ED130 802C8780 04A10002 */  bgez      $a1, .L802C878C
/* ED134 802C8784 00A0102D */   daddu    $v0, $a1, $zero
/* ED138 802C8788 24A2001F */  addiu     $v0, $a1, 0x1f
.L802C878C:
/* ED13C 802C878C 00023143 */  sra       $a2, $v0, 5
/* ED140 802C8790 00C0182D */  daddu     $v1, $a2, $zero
/* ED144 802C8794 00031140 */  sll       $v0, $v1, 5
/* ED148 802C8798 44800000 */  mtc1      $zero, $f0
/* ED14C 802C879C 00000000 */  nop
/* ED150 802C87A0 46006032 */  c.eq.s    $f12, $f0
/* ED154 802C87A4 00000000 */  nop
/* ED158 802C87A8 45010008 */  bc1t      .L802C87CC
/* ED15C 802C87AC 00A23023 */   subu     $a2, $a1, $v0
/* ED160 802C87B0 00031080 */  sll       $v0, $v1, 2
/* ED164 802C87B4 02221021 */  addu      $v0, $s1, $v0
/* ED168 802C87B8 24030001 */  addiu     $v1, $zero, 1
/* ED16C 802C87BC 8C4400C4 */  lw        $a0, 0xc4($v0)
/* ED170 802C87C0 00C31804 */  sllv      $v1, $v1, $a2
/* ED174 802C87C4 080B21FA */  j         .L802C87E8
/* ED178 802C87C8 00832025 */   or       $a0, $a0, $v1
.L802C87CC:
/* ED17C 802C87CC 00031080 */  sll       $v0, $v1, 2
/* ED180 802C87D0 02221021 */  addu      $v0, $s1, $v0
/* ED184 802C87D4 24030001 */  addiu     $v1, $zero, 1
/* ED188 802C87D8 00C31804 */  sllv      $v1, $v1, $a2
/* ED18C 802C87DC 8C4400C4 */  lw        $a0, 0xc4($v0)
/* ED190 802C87E0 00031827 */  nor       $v1, $zero, $v1
/* ED194 802C87E4 00832024 */  and       $a0, $a0, $v1
.L802C87E8:
/* ED198 802C87E8 080B21D7 */  j         .L802C875C
/* ED19C 802C87EC AC4400C4 */   sw       $a0, 0xc4($v0)
.L802C87F0:
/* ED1A0 802C87F0 3442A600 */  ori       $v0, $v0, 0xa600
/* ED1A4 802C87F4 0045102A */  slt       $v0, $v0, $a1
/* ED1A8 802C87F8 14400010 */  bnez      $v0, .L802C883C
/* ED1AC 802C87FC 3C02FECE */   lui      $v0, 0xfece
/* ED1B0 802C8800 3C0202FA */  lui       $v0, 0x2fa
/* ED1B4 802C8804 3442F080 */  ori       $v0, $v0, 0xf080
/* ED1B8 802C8808 00A22821 */  addu      $a1, $a1, $v0
/* ED1BC 802C880C 3C11802E */  lui       $s1, %hi(gMapVars)
/* ED1C0 802C8810 2631A484 */  addiu     $s1, $s1, %lo(gMapVars)
/* ED1C4 802C8814 8E220000 */  lw        $v0, ($s1)
/* ED1C8 802C8818 00058080 */  sll       $s0, $a1, 2
/* ED1CC 802C881C 02021021 */  addu      $v0, $s0, $v0
/* ED1D0 802C8820 0C0B125B */  jal       evt_float_to_fixed_var
/* ED1D4 802C8824 8C520000 */   lw       $s2, ($v0)
/* ED1D8 802C8828 8E230000 */  lw        $v1, ($s1)
/* ED1DC 802C882C 0240202D */  daddu     $a0, $s2, $zero
/* ED1E0 802C8830 02038021 */  addu      $s0, $s0, $v1
/* ED1E4 802C8834 080B221C */  j         .L802C8870
/* ED1E8 802C8838 AE020000 */   sw       $v0, ($s0)
.L802C883C:
/* ED1EC 802C883C 3442D300 */  ori       $v0, $v0, 0xd300
/* ED1F0 802C8840 0045102A */  slt       $v0, $v0, $a1
/* ED1F4 802C8844 1440000C */  bnez      $v0, .L802C8878
/* ED1F8 802C8848 46006006 */   mov.s    $f0, $f12
/* ED1FC 802C884C 3C0201C9 */  lui       $v0, 0x1c9
/* ED200 802C8850 3442C380 */  ori       $v0, $v0, 0xc380
/* ED204 802C8854 00A22821 */  addu      $a1, $a1, $v0
/* ED208 802C8858 00058080 */  sll       $s0, $a1, 2
/* ED20C 802C885C 02308021 */  addu      $s0, $s1, $s0
/* ED210 802C8860 0C0B125B */  jal       evt_float_to_fixed_var
/* ED214 802C8864 8E120084 */   lw       $s2, 0x84($s0)
/* ED218 802C8868 AE020084 */  sw        $v0, 0x84($s0)
/* ED21C 802C886C 0240202D */  daddu     $a0, $s2, $zero
.L802C8870:
/* ED220 802C8870 0C0B1248 */  jal       evt_fixed_var_to_float
/* ED224 802C8874 00000000 */   nop
.L802C8878:
/* ED228 802C8878 8FBF001C */  lw        $ra, 0x1c($sp)
/* ED22C 802C887C 8FB20018 */  lw        $s2, 0x18($sp)
/* ED230 802C8880 8FB10014 */  lw        $s1, 0x14($sp)
/* ED234 802C8884 8FB00010 */  lw        $s0, 0x10($sp)
/* ED238 802C8888 03E00008 */  jr        $ra
/* ED23C 802C888C 27BD0020 */   addiu    $sp, $sp, 0x20
