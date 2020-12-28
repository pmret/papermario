.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802186EC_48D88C
/* 48D88C 802186EC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 48D890 802186F0 AFB40020 */  sw        $s4, 0x20($sp)
/* 48D894 802186F4 0080A02D */  daddu     $s4, $a0, $zero
/* 48D898 802186F8 AFBF0024 */  sw        $ra, 0x24($sp)
/* 48D89C 802186FC AFB3001C */  sw        $s3, 0x1c($sp)
/* 48D8A0 80218700 AFB20018 */  sw        $s2, 0x18($sp)
/* 48D8A4 80218704 AFB10014 */  sw        $s1, 0x14($sp)
/* 48D8A8 80218708 AFB00010 */  sw        $s0, 0x10($sp)
/* 48D8AC 8021870C 8E92000C */  lw        $s2, 0xc($s4)
/* 48D8B0 80218710 8E450000 */  lw        $a1, ($s2)
/* 48D8B4 80218714 0C0B1EAF */  jal       get_variable
/* 48D8B8 80218718 26520004 */   addiu    $s2, $s2, 4
/* 48D8BC 8021871C 8E450000 */  lw        $a1, ($s2)
/* 48D8C0 80218720 26520004 */  addiu     $s2, $s2, 4
/* 48D8C4 80218724 0280202D */  daddu     $a0, $s4, $zero
/* 48D8C8 80218728 0C0B1EAF */  jal       get_variable
/* 48D8CC 8021872C 0040802D */   daddu    $s0, $v0, $zero
/* 48D8D0 80218730 8E450000 */  lw        $a1, ($s2)
/* 48D8D4 80218734 26520004 */  addiu     $s2, $s2, 4
/* 48D8D8 80218738 0280202D */  daddu     $a0, $s4, $zero
/* 48D8DC 8021873C 0C0B1EAF */  jal       get_variable
/* 48D8E0 80218740 0040882D */   daddu    $s1, $v0, $zero
/* 48D8E4 80218744 0040982D */  daddu     $s3, $v0, $zero
/* 48D8E8 80218748 8E450000 */  lw        $a1, ($s2)
/* 48D8EC 8021874C 26520004 */  addiu     $s2, $s2, 4
/* 48D8F0 80218750 0280202D */  daddu     $a0, $s4, $zero
/* 48D8F4 80218754 0C0B1EAF */  jal       get_variable
/* 48D8F8 80218758 02709823 */   subu     $s3, $s3, $s0
/* 48D8FC 8021875C 0040802D */  daddu     $s0, $v0, $zero
/* 48D900 80218760 0280202D */  daddu     $a0, $s4, $zero
/* 48D904 80218764 8E450000 */  lw        $a1, ($s2)
/* 48D908 80218768 0C0B1EAF */  jal       get_variable
/* 48D90C 8021876C 02118023 */   subu     $s0, $s0, $s1
/* 48D910 80218770 16600006 */  bnez      $s3, .L8021878C
/* 48D914 80218774 00000000 */   nop      
/* 48D918 80218778 16000004 */  bnez      $s0, .L8021878C
/* 48D91C 8021877C 0280202D */   daddu    $a0, $s4, $zero
/* 48D920 80218780 8E450000 */  lw        $a1, ($s2)
/* 48D924 80218784 080861ED */  j         .L802187B4
/* 48D928 80218788 0040302D */   daddu    $a2, $v0, $zero
.L8021878C:
/* 48D92C 8021878C 44936000 */  mtc1      $s3, $f12
/* 48D930 80218790 00000000 */  nop       
/* 48D934 80218794 46806320 */  cvt.s.w   $f12, $f12
/* 48D938 80218798 44907000 */  mtc1      $s0, $f14
/* 48D93C 8021879C 00000000 */  nop       
/* 48D940 802187A0 0C086158 */  jal       func_80218560_48D700
/* 48D944 802187A4 468073A0 */   cvt.s.w  $f14, $f14
/* 48D948 802187A8 0280202D */  daddu     $a0, $s4, $zero
/* 48D94C 802187AC 8E450000 */  lw        $a1, ($s2)
/* 48D950 802187B0 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L802187B4:
/* 48D954 802187B4 0C0B2026 */  jal       set_variable
/* 48D958 802187B8 00000000 */   nop      
/* 48D95C 802187BC 24020002 */  addiu     $v0, $zero, 2
/* 48D960 802187C0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 48D964 802187C4 8FB40020 */  lw        $s4, 0x20($sp)
/* 48D968 802187C8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 48D96C 802187CC 8FB20018 */  lw        $s2, 0x18($sp)
/* 48D970 802187D0 8FB10014 */  lw        $s1, 0x14($sp)
/* 48D974 802187D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 48D978 802187D8 03E00008 */  jr        $ra
/* 48D97C 802187DC 27BD0028 */   addiu    $sp, $sp, 0x28
