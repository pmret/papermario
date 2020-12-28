.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021AA4C_6265EC
/* 6265EC 8021AA4C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 6265F0 8021AA50 AFB10014 */  sw        $s1, 0x14($sp)
/* 6265F4 8021AA54 0080882D */  daddu     $s1, $a0, $zero
/* 6265F8 8021AA58 AFBF0020 */  sw        $ra, 0x20($sp)
/* 6265FC 8021AA5C AFB3001C */  sw        $s3, 0x1c($sp)
/* 626600 8021AA60 AFB20018 */  sw        $s2, 0x18($sp)
/* 626604 8021AA64 AFB00010 */  sw        $s0, 0x10($sp)
/* 626608 8021AA68 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 62660C 8021AA6C 8E30000C */  lw        $s0, 0xc($s1)
/* 626610 8021AA70 8E050000 */  lw        $a1, ($s0)
/* 626614 8021AA74 0C0B1EAF */  jal       get_variable
/* 626618 8021AA78 26100004 */   addiu    $s0, $s0, 4
/* 62661C 8021AA7C 3C036666 */  lui       $v1, 0x6666
/* 626620 8021AA80 34636667 */  ori       $v1, $v1, 0x6667
/* 626624 8021AA84 00430018 */  mult      $v0, $v1
/* 626628 8021AA88 000217C3 */  sra       $v0, $v0, 0x1f
/* 62662C 8021AA8C 3C0140C9 */  lui       $at, 0x40c9
/* 626630 8021AA90 34210FD0 */  ori       $at, $at, 0xfd0
/* 626634 8021AA94 44810000 */  mtc1      $at, $f0
/* 626638 8021AA98 00003810 */  mfhi      $a3
/* 62663C 8021AA9C 00071883 */  sra       $v1, $a3, 2
/* 626640 8021AAA0 00621823 */  subu      $v1, $v1, $v0
/* 626644 8021AAA4 44836000 */  mtc1      $v1, $f12
/* 626648 8021AAA8 00000000 */  nop       
/* 62664C 8021AAAC 46806320 */  cvt.s.w   $f12, $f12
/* 626650 8021AAB0 46006302 */  mul.s     $f12, $f12, $f0
/* 626654 8021AAB4 00000000 */  nop       
/* 626658 8021AAB8 3C0143B4 */  lui       $at, 0x43b4
/* 62665C 8021AABC 44810000 */  mtc1      $at, $f0
/* 626660 8021AAC0 3C014100 */  lui       $at, 0x4100
/* 626664 8021AAC4 44811000 */  mtc1      $at, $f2
/* 626668 8021AAC8 46006303 */  div.s     $f12, $f12, $f0
/* 62666C 8021AACC 46026302 */  mul.s     $f12, $f12, $f2
/* 626670 8021AAD0 00000000 */  nop       
/* 626674 8021AAD4 8E120000 */  lw        $s2, ($s0)
/* 626678 8021AAD8 26100004 */  addiu     $s0, $s0, 4
/* 62667C 8021AADC 8E130000 */  lw        $s3, ($s0)
/* 626680 8021AAE0 0C00A85B */  jal       sin_rad
/* 626684 8021AAE4 8E100004 */   lw       $s0, 4($s0)
/* 626688 8021AAE8 0220202D */  daddu     $a0, $s1, $zero
/* 62668C 8021AAEC 3C014120 */  lui       $at, 0x4120
/* 626690 8021AAF0 44811000 */  mtc1      $at, $f2
/* 626694 8021AAF4 0240282D */  daddu     $a1, $s2, $zero
/* 626698 8021AAF8 46020502 */  mul.s     $f20, $f0, $f2
/* 62669C 8021AAFC 00000000 */  nop       
/* 6266A0 8021AB00 0C0B2026 */  jal       set_variable
/* 6266A4 8021AB04 0000302D */   daddu    $a2, $zero, $zero
/* 6266A8 8021AB08 0220202D */  daddu     $a0, $s1, $zero
/* 6266AC 8021AB0C 4600A10D */  trunc.w.s $f4, $f20
/* 6266B0 8021AB10 44062000 */  mfc1      $a2, $f4
/* 6266B4 8021AB14 0C0B2026 */  jal       set_variable
/* 6266B8 8021AB18 0260282D */   daddu    $a1, $s3, $zero
/* 6266BC 8021AB1C 0220202D */  daddu     $a0, $s1, $zero
/* 6266C0 8021AB20 0200282D */  daddu     $a1, $s0, $zero
/* 6266C4 8021AB24 0C0B2026 */  jal       set_variable
/* 6266C8 8021AB28 0000302D */   daddu    $a2, $zero, $zero
/* 6266CC 8021AB2C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6266D0 8021AB30 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6266D4 8021AB34 8FB20018 */  lw        $s2, 0x18($sp)
/* 6266D8 8021AB38 8FB10014 */  lw        $s1, 0x14($sp)
/* 6266DC 8021AB3C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6266E0 8021AB40 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 6266E4 8021AB44 24020002 */  addiu     $v0, $zero, 2
/* 6266E8 8021AB48 03E00008 */  jr        $ra
/* 6266EC 8021AB4C 27BD0030 */   addiu    $sp, $sp, 0x30
