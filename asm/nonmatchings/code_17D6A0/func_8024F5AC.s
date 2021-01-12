.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024F5AC
/* 17DE8C 8024F5AC 27BDFD60 */  addiu     $sp, $sp, -0x2a0
/* 17DE90 8024F5B0 AFB40278 */  sw        $s4, 0x278($sp)
/* 17DE94 8024F5B4 AFBF028C */  sw        $ra, 0x28c($sp)
/* 17DE98 8024F5B8 AFBE0288 */  sw        $fp, 0x288($sp)
/* 17DE9C 8024F5BC AFB70284 */  sw        $s7, 0x284($sp)
/* 17DEA0 8024F5C0 AFB60280 */  sw        $s6, 0x280($sp)
/* 17DEA4 8024F5C4 AFB5027C */  sw        $s5, 0x27c($sp)
/* 17DEA8 8024F5C8 AFB30274 */  sw        $s3, 0x274($sp)
/* 17DEAC 8024F5CC AFB20270 */  sw        $s2, 0x270($sp)
/* 17DEB0 8024F5D0 AFB1026C */  sw        $s1, 0x26c($sp)
/* 17DEB4 8024F5D4 AFB00268 */  sw        $s0, 0x268($sp)
/* 17DEB8 8024F5D8 F7B60298 */  sdc1      $f22, 0x298($sp)
/* 17DEBC 8024F5DC F7B40290 */  sdc1      $f20, 0x290($sp)
/* 17DEC0 8024F5E0 AFA40258 */  sw        $a0, 0x258($sp)
/* 17DEC4 8024F5E4 84820012 */  lh        $v0, 0x12($a0)
/* 17DEC8 8024F5E8 8C930018 */  lw        $s3, 0x18($a0)
/* 17DECC 8024F5EC 18400050 */  blez      $v0, .L8024F730
/* 17DED0 8024F5F0 0000A02D */   daddu    $s4, $zero, $zero
/* 17DED4 8024F5F4 27A30058 */  addiu     $v1, $sp, 0x58
/* 17DED8 8024F5F8 AFA3025C */  sw        $v1, 0x25c($sp)
/* 17DEDC 8024F5FC 27A30098 */  addiu     $v1, $sp, 0x98
/* 17DEE0 8024F600 AFA30260 */  sw        $v1, 0x260($sp)
/* 17DEE4 8024F604 27A300D8 */  addiu     $v1, $sp, 0xd8
/* 17DEE8 8024F608 27BE01D8 */  addiu     $fp, $sp, 0x1d8
/* 17DEEC 8024F60C 27B20158 */  addiu     $s2, $sp, 0x158
/* 17DEF0 8024F610 27B70118 */  addiu     $s7, $sp, 0x118
/* 17DEF4 8024F614 27B60198 */  addiu     $s6, $sp, 0x198
/* 17DEF8 8024F618 27B50218 */  addiu     $s5, $sp, 0x218
/* 17DEFC 8024F61C 4480A000 */  mtc1      $zero, $f20
/* 17DF00 8024F620 3C013F80 */  lui       $at, 0x3f80
/* 17DF04 8024F624 4481B000 */  mtc1      $at, $f22
/* 17DF08 8024F628 26710034 */  addiu     $s1, $s3, 0x34
/* 17DF0C 8024F62C AFA30264 */  sw        $v1, 0x264($sp)
.L8024F630:
/* 17DF10 8024F630 8E620000 */  lw        $v0, ($s3)
/* 17DF14 8024F634 50400038 */  beql      $v0, $zero, .L8024F718
/* 17DF18 8024F638 26940001 */   addiu    $s4, $s4, 1
/* 17DF1C 8024F63C 8E22FFF0 */  lw        $v0, -0x10($s1)
/* 17DF20 8024F640 1440003B */  bnez      $v0, .L8024F730
/* 17DF24 8024F644 00000000 */   nop
/* 17DF28 8024F648 8E250004 */  lw        $a1, 4($s1)
/* 17DF2C 8024F64C 8E260008 */  lw        $a2, 8($s1)
/* 17DF30 8024F650 8E27000C */  lw        $a3, 0xc($s1)
/* 17DF34 8024F654 8E30FFD0 */  lw        $s0, -0x30($s1)
/* 17DF38 8024F658 0C019E40 */  jal       guTranslateF
/* 17DF3C 8024F65C 27A40018 */   addiu    $a0, $sp, 0x18
/* 17DF40 8024F660 4405A000 */  mfc1      $a1, $f20
/* 17DF44 8024F664 4406B000 */  mfc1      $a2, $f22
/* 17DF48 8024F668 4407A000 */  mfc1      $a3, $f20
/* 17DF4C 8024F66C 8FA4025C */  lw        $a0, 0x25c($sp)
/* 17DF50 8024F670 0C019EC8 */  jal       guRotateF
/* 17DF54 8024F674 E7B40010 */   swc1     $f20, 0x10($sp)
/* 17DF58 8024F678 E7B40010 */  swc1      $f20, 0x10($sp)
/* 17DF5C 8024F67C 8E25FFFC */  lw        $a1, -4($s1)
/* 17DF60 8024F680 4406A000 */  mfc1      $a2, $f20
/* 17DF64 8024F684 4407B000 */  mfc1      $a3, $f22
/* 17DF68 8024F688 8FA40260 */  lw        $a0, 0x260($sp)
/* 17DF6C 8024F68C 0C019EC8 */  jal       guRotateF
/* 17DF70 8024F690 26940001 */   addiu    $s4, $s4, 1
/* 17DF74 8024F694 E7B60010 */  swc1      $f22, 0x10($sp)
/* 17DF78 8024F698 8E25FFF4 */  lw        $a1, -0xc($s1)
/* 17DF7C 8024F69C 4406A000 */  mfc1      $a2, $f20
/* 17DF80 8024F6A0 4407A000 */  mfc1      $a3, $f20
/* 17DF84 8024F6A4 0C019EC8 */  jal       guRotateF
/* 17DF88 8024F6A8 8FA40264 */   lw       $a0, 0x264($sp)
/* 17DF8C 8024F6AC 8E250000 */  lw        $a1, ($s1)
/* 17DF90 8024F6B0 03C0202D */  daddu     $a0, $fp, $zero
/* 17DF94 8024F6B4 00A0302D */  daddu     $a2, $a1, $zero
/* 17DF98 8024F6B8 0C019DF0 */  jal       guScaleF
/* 17DF9C 8024F6BC 00A0382D */   daddu    $a3, $a1, $zero
/* 17DFA0 8024F6C0 8FA40264 */  lw        $a0, 0x264($sp)
/* 17DFA4 8024F6C4 8FA5025C */  lw        $a1, 0x25c($sp)
/* 17DFA8 8024F6C8 0C019D80 */  jal       guMtxCatF
/* 17DFAC 8024F6CC 0240302D */   daddu    $a2, $s2, $zero
/* 17DFB0 8024F6D0 0240202D */  daddu     $a0, $s2, $zero
/* 17DFB4 8024F6D4 8FA50260 */  lw        $a1, 0x260($sp)
/* 17DFB8 8024F6D8 0C019D80 */  jal       guMtxCatF
/* 17DFBC 8024F6DC 02E0302D */   daddu    $a2, $s7, $zero
/* 17DFC0 8024F6E0 03C0202D */  daddu     $a0, $fp, $zero
/* 17DFC4 8024F6E4 02E0282D */  daddu     $a1, $s7, $zero
/* 17DFC8 8024F6E8 0C019D80 */  jal       guMtxCatF
/* 17DFCC 8024F6EC 0240302D */   daddu    $a2, $s2, $zero
/* 17DFD0 8024F6F0 0240202D */  daddu     $a0, $s2, $zero
/* 17DFD4 8024F6F4 27A50018 */  addiu     $a1, $sp, 0x18
/* 17DFD8 8024F6F8 0C019D80 */  jal       guMtxCatF
/* 17DFDC 8024F6FC 02C0302D */   daddu    $a2, $s6, $zero
/* 17DFE0 8024F700 02C0202D */  daddu     $a0, $s6, $zero
/* 17DFE4 8024F704 0C019D40 */  jal       guMtxF2L
/* 17DFE8 8024F708 02A0282D */   daddu    $a1, $s5, $zero
/* 17DFEC 8024F70C 0200202D */  daddu     $a0, $s0, $zero
/* 17DFF0 8024F710 0C04873A */  jal       func_80121CE8
/* 17DFF4 8024F714 02A0282D */   daddu    $a1, $s5, $zero
.L8024F718:
/* 17DFF8 8024F718 8FA30258 */  lw        $v1, 0x258($sp)
/* 17DFFC 8024F71C 2631004C */  addiu     $s1, $s1, 0x4c
/* 17E000 8024F720 84620012 */  lh        $v0, 0x12($v1)
/* 17E004 8024F724 0282102A */  slt       $v0, $s4, $v0
/* 17E008 8024F728 1440FFC1 */  bnez      $v0, .L8024F630
/* 17E00C 8024F72C 2673004C */   addiu    $s3, $s3, 0x4c
.L8024F730:
/* 17E010 8024F730 8FBF028C */  lw        $ra, 0x28c($sp)
/* 17E014 8024F734 8FBE0288 */  lw        $fp, 0x288($sp)
/* 17E018 8024F738 8FB70284 */  lw        $s7, 0x284($sp)
/* 17E01C 8024F73C 8FB60280 */  lw        $s6, 0x280($sp)
/* 17E020 8024F740 8FB5027C */  lw        $s5, 0x27c($sp)
/* 17E024 8024F744 8FB40278 */  lw        $s4, 0x278($sp)
/* 17E028 8024F748 8FB30274 */  lw        $s3, 0x274($sp)
/* 17E02C 8024F74C 8FB20270 */  lw        $s2, 0x270($sp)
/* 17E030 8024F750 8FB1026C */  lw        $s1, 0x26c($sp)
/* 17E034 8024F754 8FB00268 */  lw        $s0, 0x268($sp)
/* 17E038 8024F758 D7B60298 */  ldc1      $f22, 0x298($sp)
/* 17E03C 8024F75C D7B40290 */  ldc1      $f20, 0x290($sp)
/* 17E040 8024F760 03E00008 */  jr        $ra
/* 17E044 8024F764 27BD02A0 */   addiu    $sp, $sp, 0x2a0
