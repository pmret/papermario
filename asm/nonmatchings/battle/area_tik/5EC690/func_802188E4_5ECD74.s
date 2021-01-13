.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188E4_5ECD74
/* 5ECD74 802188E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5ECD78 802188E8 AFB40020 */  sw        $s4, 0x20($sp)
/* 5ECD7C 802188EC 0080A02D */  daddu     $s4, $a0, $zero
/* 5ECD80 802188F0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 5ECD84 802188F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5ECD88 802188F8 AFB20018 */  sw        $s2, 0x18($sp)
/* 5ECD8C 802188FC AFB10014 */  sw        $s1, 0x14($sp)
/* 5ECD90 80218900 AFB00010 */  sw        $s0, 0x10($sp)
/* 5ECD94 80218904 8E92000C */  lw        $s2, 0xc($s4)
/* 5ECD98 80218908 8E450000 */  lw        $a1, ($s2)
/* 5ECD9C 8021890C 0C0B1EAF */  jal       get_variable
/* 5ECDA0 80218910 26520004 */   addiu    $s2, $s2, 4
/* 5ECDA4 80218914 8E450000 */  lw        $a1, ($s2)
/* 5ECDA8 80218918 26520004 */  addiu     $s2, $s2, 4
/* 5ECDAC 8021891C 0280202D */  daddu     $a0, $s4, $zero
/* 5ECDB0 80218920 0C0B1EAF */  jal       get_variable
/* 5ECDB4 80218924 0040802D */   daddu    $s0, $v0, $zero
/* 5ECDB8 80218928 8E450000 */  lw        $a1, ($s2)
/* 5ECDBC 8021892C 26520004 */  addiu     $s2, $s2, 4
/* 5ECDC0 80218930 0280202D */  daddu     $a0, $s4, $zero
/* 5ECDC4 80218934 0C0B1EAF */  jal       get_variable
/* 5ECDC8 80218938 0040882D */   daddu    $s1, $v0, $zero
/* 5ECDCC 8021893C 0040982D */  daddu     $s3, $v0, $zero
/* 5ECDD0 80218940 8E450000 */  lw        $a1, ($s2)
/* 5ECDD4 80218944 26520004 */  addiu     $s2, $s2, 4
/* 5ECDD8 80218948 0280202D */  daddu     $a0, $s4, $zero
/* 5ECDDC 8021894C 0C0B1EAF */  jal       get_variable
/* 5ECDE0 80218950 02709823 */   subu     $s3, $s3, $s0
/* 5ECDE4 80218954 0040802D */  daddu     $s0, $v0, $zero
/* 5ECDE8 80218958 0280202D */  daddu     $a0, $s4, $zero
/* 5ECDEC 8021895C 8E450000 */  lw        $a1, ($s2)
/* 5ECDF0 80218960 0C0B1EAF */  jal       get_variable
/* 5ECDF4 80218964 02118023 */   subu     $s0, $s0, $s1
/* 5ECDF8 80218968 16600006 */  bnez      $s3, .L80218984
/* 5ECDFC 8021896C 00000000 */   nop
/* 5ECE00 80218970 16000004 */  bnez      $s0, .L80218984
/* 5ECE04 80218974 0280202D */   daddu    $a0, $s4, $zero
/* 5ECE08 80218978 8E450000 */  lw        $a1, ($s2)
/* 5ECE0C 8021897C 0808626B */  j         .L802189AC
/* 5ECE10 80218980 0040302D */   daddu    $a2, $v0, $zero
.L80218984:
/* 5ECE14 80218984 44936000 */  mtc1      $s3, $f12
/* 5ECE18 80218988 00000000 */  nop
/* 5ECE1C 8021898C 46806320 */  cvt.s.w   $f12, $f12
/* 5ECE20 80218990 44907000 */  mtc1      $s0, $f14
/* 5ECE24 80218994 00000000 */  nop
/* 5ECE28 80218998 0C0861D6 */  jal       func_80218758_5ECBE8
/* 5ECE2C 8021899C 468073A0 */   cvt.s.w  $f14, $f14
/* 5ECE30 802189A0 0280202D */  daddu     $a0, $s4, $zero
/* 5ECE34 802189A4 8E450000 */  lw        $a1, ($s2)
/* 5ECE38 802189A8 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L802189AC:
/* 5ECE3C 802189AC 0C0B2026 */  jal       set_variable
/* 5ECE40 802189B0 00000000 */   nop
/* 5ECE44 802189B4 24020002 */  addiu     $v0, $zero, 2
/* 5ECE48 802189B8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 5ECE4C 802189BC 8FB40020 */  lw        $s4, 0x20($sp)
/* 5ECE50 802189C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5ECE54 802189C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 5ECE58 802189C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 5ECE5C 802189CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 5ECE60 802189D0 03E00008 */  jr        $ra
/* 5ECE64 802189D4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 5ECE68 802189D8 00000000 */  nop
/* 5ECE6C 802189DC 00000000 */  nop
