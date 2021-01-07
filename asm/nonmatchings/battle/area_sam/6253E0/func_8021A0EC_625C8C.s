.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A0EC_625C8C
/* 625C8C 8021A0EC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 625C90 8021A0F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 625C94 8021A0F4 0080882D */  daddu     $s1, $a0, $zero
/* 625C98 8021A0F8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 625C9C 8021A0FC AFB3001C */  sw        $s3, 0x1c($sp)
/* 625CA0 8021A100 AFB20018 */  sw        $s2, 0x18($sp)
/* 625CA4 8021A104 AFB00010 */  sw        $s0, 0x10($sp)
/* 625CA8 8021A108 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 625CAC 8021A10C 8E30000C */  lw        $s0, 0xc($s1)
/* 625CB0 8021A110 8E050000 */  lw        $a1, ($s0)
/* 625CB4 8021A114 0C0B1EAF */  jal       get_variable
/* 625CB8 8021A118 26100004 */   addiu    $s0, $s0, 4
/* 625CBC 8021A11C 3C036666 */  lui       $v1, 0x6666
/* 625CC0 8021A120 34636667 */  ori       $v1, $v1, 0x6667
/* 625CC4 8021A124 00430018 */  mult      $v0, $v1
/* 625CC8 8021A128 000217C3 */  sra       $v0, $v0, 0x1f
/* 625CCC 8021A12C 3C0140C9 */  lui       $at, 0x40c9
/* 625CD0 8021A130 34210FD0 */  ori       $at, $at, 0xfd0
/* 625CD4 8021A134 44810000 */  mtc1      $at, $f0
/* 625CD8 8021A138 00003810 */  mfhi      $a3
/* 625CDC 8021A13C 00071883 */  sra       $v1, $a3, 2
/* 625CE0 8021A140 00621823 */  subu      $v1, $v1, $v0
/* 625CE4 8021A144 44836000 */  mtc1      $v1, $f12
/* 625CE8 8021A148 00000000 */  nop       
/* 625CEC 8021A14C 46806320 */  cvt.s.w   $f12, $f12
/* 625CF0 8021A150 46006302 */  mul.s     $f12, $f12, $f0
/* 625CF4 8021A154 00000000 */  nop       
/* 625CF8 8021A158 3C0143B4 */  lui       $at, 0x43b4
/* 625CFC 8021A15C 44810000 */  mtc1      $at, $f0
/* 625D00 8021A160 3C014100 */  lui       $at, 0x4100
/* 625D04 8021A164 44811000 */  mtc1      $at, $f2
/* 625D08 8021A168 46006303 */  div.s     $f12, $f12, $f0
/* 625D0C 8021A16C 46026302 */  mul.s     $f12, $f12, $f2
/* 625D10 8021A170 00000000 */  nop       
/* 625D14 8021A174 8E120000 */  lw        $s2, ($s0)
/* 625D18 8021A178 26100004 */  addiu     $s0, $s0, 4
/* 625D1C 8021A17C 8E130000 */  lw        $s3, ($s0)
/* 625D20 8021A180 0C00A85B */  jal       sin_rad
/* 625D24 8021A184 8E100004 */   lw       $s0, 4($s0)
/* 625D28 8021A188 0220202D */  daddu     $a0, $s1, $zero
/* 625D2C 8021A18C 3C014120 */  lui       $at, 0x4120
/* 625D30 8021A190 44811000 */  mtc1      $at, $f2
/* 625D34 8021A194 0240282D */  daddu     $a1, $s2, $zero
/* 625D38 8021A198 46020502 */  mul.s     $f20, $f0, $f2
/* 625D3C 8021A19C 00000000 */  nop       
/* 625D40 8021A1A0 0C0B2026 */  jal       set_variable
/* 625D44 8021A1A4 0000302D */   daddu    $a2, $zero, $zero
/* 625D48 8021A1A8 0220202D */  daddu     $a0, $s1, $zero
/* 625D4C 8021A1AC 4600A10D */  trunc.w.s $f4, $f20
/* 625D50 8021A1B0 44062000 */  mfc1      $a2, $f4
/* 625D54 8021A1B4 0C0B2026 */  jal       set_variable
/* 625D58 8021A1B8 0260282D */   daddu    $a1, $s3, $zero
/* 625D5C 8021A1BC 0220202D */  daddu     $a0, $s1, $zero
/* 625D60 8021A1C0 0200282D */  daddu     $a1, $s0, $zero
/* 625D64 8021A1C4 0C0B2026 */  jal       set_variable
/* 625D68 8021A1C8 0000302D */   daddu    $a2, $zero, $zero
/* 625D6C 8021A1CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 625D70 8021A1D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 625D74 8021A1D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 625D78 8021A1D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 625D7C 8021A1DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 625D80 8021A1E0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 625D84 8021A1E4 24020002 */  addiu     $v0, $zero, 2
/* 625D88 8021A1E8 03E00008 */  jr        $ra
/* 625D8C 8021A1EC 27BD0030 */   addiu    $sp, $sp, 0x30
