.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021868C_43A11C
/* 43A11C 8021868C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 43A120 80218690 AFB40020 */  sw        $s4, 0x20($sp)
/* 43A124 80218694 0080A02D */  daddu     $s4, $a0, $zero
/* 43A128 80218698 AFBF0024 */  sw        $ra, 0x24($sp)
/* 43A12C 8021869C AFB3001C */  sw        $s3, 0x1c($sp)
/* 43A130 802186A0 AFB20018 */  sw        $s2, 0x18($sp)
/* 43A134 802186A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 43A138 802186A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 43A13C 802186AC 8E92000C */  lw        $s2, 0xc($s4)
/* 43A140 802186B0 8E450000 */  lw        $a1, ($s2)
/* 43A144 802186B4 0C0B1EAF */  jal       get_variable
/* 43A148 802186B8 26520004 */   addiu    $s2, $s2, 4
/* 43A14C 802186BC 8E450000 */  lw        $a1, ($s2)
/* 43A150 802186C0 26520004 */  addiu     $s2, $s2, 4
/* 43A154 802186C4 0280202D */  daddu     $a0, $s4, $zero
/* 43A158 802186C8 0C0B1EAF */  jal       get_variable
/* 43A15C 802186CC 0040802D */   daddu    $s0, $v0, $zero
/* 43A160 802186D0 8E450000 */  lw        $a1, ($s2)
/* 43A164 802186D4 26520004 */  addiu     $s2, $s2, 4
/* 43A168 802186D8 0280202D */  daddu     $a0, $s4, $zero
/* 43A16C 802186DC 0C0B1EAF */  jal       get_variable
/* 43A170 802186E0 0040882D */   daddu    $s1, $v0, $zero
/* 43A174 802186E4 0040982D */  daddu     $s3, $v0, $zero
/* 43A178 802186E8 8E450000 */  lw        $a1, ($s2)
/* 43A17C 802186EC 26520004 */  addiu     $s2, $s2, 4
/* 43A180 802186F0 0280202D */  daddu     $a0, $s4, $zero
/* 43A184 802186F4 0C0B1EAF */  jal       get_variable
/* 43A188 802186F8 02709823 */   subu     $s3, $s3, $s0
/* 43A18C 802186FC 0040802D */  daddu     $s0, $v0, $zero
/* 43A190 80218700 0280202D */  daddu     $a0, $s4, $zero
/* 43A194 80218704 8E450000 */  lw        $a1, ($s2)
/* 43A198 80218708 0C0B1EAF */  jal       get_variable
/* 43A19C 8021870C 02118023 */   subu     $s0, $s0, $s1
/* 43A1A0 80218710 16600006 */  bnez      $s3, .L8021872C
/* 43A1A4 80218714 00000000 */   nop      
/* 43A1A8 80218718 16000004 */  bnez      $s0, .L8021872C
/* 43A1AC 8021871C 0280202D */   daddu    $a0, $s4, $zero
/* 43A1B0 80218720 8E450000 */  lw        $a1, ($s2)
/* 43A1B4 80218724 080861D5 */  j         .L80218754
/* 43A1B8 80218728 0040302D */   daddu    $a2, $v0, $zero
.L8021872C:
/* 43A1BC 8021872C 44936000 */  mtc1      $s3, $f12
/* 43A1C0 80218730 00000000 */  nop       
/* 43A1C4 80218734 46806320 */  cvt.s.w   $f12, $f12
/* 43A1C8 80218738 44907000 */  mtc1      $s0, $f14
/* 43A1CC 8021873C 00000000 */  nop       
/* 43A1D0 80218740 0C086140 */  jal       func_80218500_439F90
/* 43A1D4 80218744 468073A0 */   cvt.s.w  $f14, $f14
/* 43A1D8 80218748 0280202D */  daddu     $a0, $s4, $zero
/* 43A1DC 8021874C 8E450000 */  lw        $a1, ($s2)
/* 43A1E0 80218750 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L80218754:
/* 43A1E4 80218754 0C0B2026 */  jal       set_variable
/* 43A1E8 80218758 00000000 */   nop      
/* 43A1EC 8021875C 24020002 */  addiu     $v0, $zero, 2
/* 43A1F0 80218760 8FBF0024 */  lw        $ra, 0x24($sp)
/* 43A1F4 80218764 8FB40020 */  lw        $s4, 0x20($sp)
/* 43A1F8 80218768 8FB3001C */  lw        $s3, 0x1c($sp)
/* 43A1FC 8021876C 8FB20018 */  lw        $s2, 0x18($sp)
/* 43A200 80218770 8FB10014 */  lw        $s1, 0x14($sp)
/* 43A204 80218774 8FB00010 */  lw        $s0, 0x10($sp)
/* 43A208 80218778 03E00008 */  jr        $ra
/* 43A20C 8021877C 27BD0028 */   addiu    $sp, $sp, 0x28
