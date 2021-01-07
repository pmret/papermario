.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021887C_557C5C
/* 557C5C 8021887C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 557C60 80218880 AFB40020 */  sw        $s4, 0x20($sp)
/* 557C64 80218884 0080A02D */  daddu     $s4, $a0, $zero
/* 557C68 80218888 AFBF0024 */  sw        $ra, 0x24($sp)
/* 557C6C 8021888C AFB3001C */  sw        $s3, 0x1c($sp)
/* 557C70 80218890 AFB20018 */  sw        $s2, 0x18($sp)
/* 557C74 80218894 AFB10014 */  sw        $s1, 0x14($sp)
/* 557C78 80218898 AFB00010 */  sw        $s0, 0x10($sp)
/* 557C7C 8021889C 8E92000C */  lw        $s2, 0xc($s4)
/* 557C80 802188A0 8E450000 */  lw        $a1, ($s2)
/* 557C84 802188A4 0C0B1EAF */  jal       get_variable
/* 557C88 802188A8 26520004 */   addiu    $s2, $s2, 4
/* 557C8C 802188AC 8E450000 */  lw        $a1, ($s2)
/* 557C90 802188B0 26520004 */  addiu     $s2, $s2, 4
/* 557C94 802188B4 0280202D */  daddu     $a0, $s4, $zero
/* 557C98 802188B8 0C0B1EAF */  jal       get_variable
/* 557C9C 802188BC 0040802D */   daddu    $s0, $v0, $zero
/* 557CA0 802188C0 8E450000 */  lw        $a1, ($s2)
/* 557CA4 802188C4 26520004 */  addiu     $s2, $s2, 4
/* 557CA8 802188C8 0280202D */  daddu     $a0, $s4, $zero
/* 557CAC 802188CC 0C0B1EAF */  jal       get_variable
/* 557CB0 802188D0 0040882D */   daddu    $s1, $v0, $zero
/* 557CB4 802188D4 0040982D */  daddu     $s3, $v0, $zero
/* 557CB8 802188D8 8E450000 */  lw        $a1, ($s2)
/* 557CBC 802188DC 26520004 */  addiu     $s2, $s2, 4
/* 557CC0 802188E0 0280202D */  daddu     $a0, $s4, $zero
/* 557CC4 802188E4 0C0B1EAF */  jal       get_variable
/* 557CC8 802188E8 02709823 */   subu     $s3, $s3, $s0
/* 557CCC 802188EC 0040802D */  daddu     $s0, $v0, $zero
/* 557CD0 802188F0 0280202D */  daddu     $a0, $s4, $zero
/* 557CD4 802188F4 8E450000 */  lw        $a1, ($s2)
/* 557CD8 802188F8 0C0B1EAF */  jal       get_variable
/* 557CDC 802188FC 02118023 */   subu     $s0, $s0, $s1
/* 557CE0 80218900 16600006 */  bnez      $s3, .L8021891C
/* 557CE4 80218904 00000000 */   nop      
/* 557CE8 80218908 16000004 */  bnez      $s0, .L8021891C
/* 557CEC 8021890C 0280202D */   daddu    $a0, $s4, $zero
/* 557CF0 80218910 8E450000 */  lw        $a1, ($s2)
/* 557CF4 80218914 08086251 */  j         .L80218944
/* 557CF8 80218918 0040302D */   daddu    $a2, $v0, $zero
.L8021891C:
/* 557CFC 8021891C 44936000 */  mtc1      $s3, $f12
/* 557D00 80218920 00000000 */  nop       
/* 557D04 80218924 46806320 */  cvt.s.w   $f12, $f12
/* 557D08 80218928 44907000 */  mtc1      $s0, $f14
/* 557D0C 8021892C 00000000 */  nop       
/* 557D10 80218930 0C0861BC */  jal       func_802186F0_557AD0
/* 557D14 80218934 468073A0 */   cvt.s.w  $f14, $f14
/* 557D18 80218938 0280202D */  daddu     $a0, $s4, $zero
/* 557D1C 8021893C 8E450000 */  lw        $a1, ($s2)
/* 557D20 80218940 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L80218944:
/* 557D24 80218944 0C0B2026 */  jal       set_variable
/* 557D28 80218948 00000000 */   nop      
/* 557D2C 8021894C 24020002 */  addiu     $v0, $zero, 2
/* 557D30 80218950 8FBF0024 */  lw        $ra, 0x24($sp)
/* 557D34 80218954 8FB40020 */  lw        $s4, 0x20($sp)
/* 557D38 80218958 8FB3001C */  lw        $s3, 0x1c($sp)
/* 557D3C 8021895C 8FB20018 */  lw        $s2, 0x18($sp)
/* 557D40 80218960 8FB10014 */  lw        $s1, 0x14($sp)
/* 557D44 80218964 8FB00010 */  lw        $s0, 0x10($sp)
/* 557D48 80218968 03E00008 */  jr        $ra
/* 557D4C 8021896C 27BD0028 */   addiu    $sp, $sp, 0x28
