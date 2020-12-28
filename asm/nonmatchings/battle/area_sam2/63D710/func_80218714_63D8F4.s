.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218714_63D8F4
/* 63D8F4 80218714 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 63D8F8 80218718 AFB40020 */  sw        $s4, 0x20($sp)
/* 63D8FC 8021871C 0080A02D */  daddu     $s4, $a0, $zero
/* 63D900 80218720 AFBF0024 */  sw        $ra, 0x24($sp)
/* 63D904 80218724 AFB3001C */  sw        $s3, 0x1c($sp)
/* 63D908 80218728 AFB20018 */  sw        $s2, 0x18($sp)
/* 63D90C 8021872C AFB10014 */  sw        $s1, 0x14($sp)
/* 63D910 80218730 AFB00010 */  sw        $s0, 0x10($sp)
/* 63D914 80218734 8E92000C */  lw        $s2, 0xc($s4)
/* 63D918 80218738 8E450000 */  lw        $a1, ($s2)
/* 63D91C 8021873C 0C0B1EAF */  jal       get_variable
/* 63D920 80218740 26520004 */   addiu    $s2, $s2, 4
/* 63D924 80218744 8E450000 */  lw        $a1, ($s2)
/* 63D928 80218748 26520004 */  addiu     $s2, $s2, 4
/* 63D92C 8021874C 0280202D */  daddu     $a0, $s4, $zero
/* 63D930 80218750 0C0B1EAF */  jal       get_variable
/* 63D934 80218754 0040802D */   daddu    $s0, $v0, $zero
/* 63D938 80218758 8E450000 */  lw        $a1, ($s2)
/* 63D93C 8021875C 26520004 */  addiu     $s2, $s2, 4
/* 63D940 80218760 0280202D */  daddu     $a0, $s4, $zero
/* 63D944 80218764 0C0B1EAF */  jal       get_variable
/* 63D948 80218768 0040882D */   daddu    $s1, $v0, $zero
/* 63D94C 8021876C 0040982D */  daddu     $s3, $v0, $zero
/* 63D950 80218770 8E450000 */  lw        $a1, ($s2)
/* 63D954 80218774 26520004 */  addiu     $s2, $s2, 4
/* 63D958 80218778 0280202D */  daddu     $a0, $s4, $zero
/* 63D95C 8021877C 0C0B1EAF */  jal       get_variable
/* 63D960 80218780 02709823 */   subu     $s3, $s3, $s0
/* 63D964 80218784 0040802D */  daddu     $s0, $v0, $zero
/* 63D968 80218788 0280202D */  daddu     $a0, $s4, $zero
/* 63D96C 8021878C 8E450000 */  lw        $a1, ($s2)
/* 63D970 80218790 0C0B1EAF */  jal       get_variable
/* 63D974 80218794 02118023 */   subu     $s0, $s0, $s1
/* 63D978 80218798 16600006 */  bnez      $s3, .L802187B4
/* 63D97C 8021879C 00000000 */   nop      
/* 63D980 802187A0 16000004 */  bnez      $s0, .L802187B4
/* 63D984 802187A4 0280202D */   daddu    $a0, $s4, $zero
/* 63D988 802187A8 8E450000 */  lw        $a1, ($s2)
/* 63D98C 802187AC 080861F7 */  j         .L802187DC
/* 63D990 802187B0 0040302D */   daddu    $a2, $v0, $zero
.L802187B4:
/* 63D994 802187B4 44936000 */  mtc1      $s3, $f12
/* 63D998 802187B8 00000000 */  nop       
/* 63D99C 802187BC 46806320 */  cvt.s.w   $f12, $f12
/* 63D9A0 802187C0 44907000 */  mtc1      $s0, $f14
/* 63D9A4 802187C4 00000000 */  nop       
/* 63D9A8 802187C8 0C086162 */  jal       func_80218588_63D768
/* 63D9AC 802187CC 468073A0 */   cvt.s.w  $f14, $f14
/* 63D9B0 802187D0 0280202D */  daddu     $a0, $s4, $zero
/* 63D9B4 802187D4 8E450000 */  lw        $a1, ($s2)
/* 63D9B8 802187D8 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L802187DC:
/* 63D9BC 802187DC 0C0B2026 */  jal       set_variable
/* 63D9C0 802187E0 00000000 */   nop      
/* 63D9C4 802187E4 24020002 */  addiu     $v0, $zero, 2
/* 63D9C8 802187E8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 63D9CC 802187EC 8FB40020 */  lw        $s4, 0x20($sp)
/* 63D9D0 802187F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 63D9D4 802187F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 63D9D8 802187F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 63D9DC 802187FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 63D9E0 80218800 03E00008 */  jr        $ra
/* 63D9E4 80218804 27BD0028 */   addiu    $sp, $sp, 0x28
/* 63D9E8 80218808 00000000 */  nop       
/* 63D9EC 8021880C 00000000 */  nop       
