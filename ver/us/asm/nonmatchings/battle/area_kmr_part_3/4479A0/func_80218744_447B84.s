.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218744_447B84
/* 447B84 80218744 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 447B88 80218748 AFB40020 */  sw        $s4, 0x20($sp)
/* 447B8C 8021874C 0080A02D */  daddu     $s4, $a0, $zero
/* 447B90 80218750 AFBF0024 */  sw        $ra, 0x24($sp)
/* 447B94 80218754 AFB3001C */  sw        $s3, 0x1c($sp)
/* 447B98 80218758 AFB20018 */  sw        $s2, 0x18($sp)
/* 447B9C 8021875C AFB10014 */  sw        $s1, 0x14($sp)
/* 447BA0 80218760 AFB00010 */  sw        $s0, 0x10($sp)
/* 447BA4 80218764 8E92000C */  lw        $s2, 0xc($s4)
/* 447BA8 80218768 8E450000 */  lw        $a1, ($s2)
/* 447BAC 8021876C 0C0B1EAF */  jal       get_variable
/* 447BB0 80218770 26520004 */   addiu    $s2, $s2, 4
/* 447BB4 80218774 8E450000 */  lw        $a1, ($s2)
/* 447BB8 80218778 26520004 */  addiu     $s2, $s2, 4
/* 447BBC 8021877C 0280202D */  daddu     $a0, $s4, $zero
/* 447BC0 80218780 0C0B1EAF */  jal       get_variable
/* 447BC4 80218784 0040802D */   daddu    $s0, $v0, $zero
/* 447BC8 80218788 8E450000 */  lw        $a1, ($s2)
/* 447BCC 8021878C 26520004 */  addiu     $s2, $s2, 4
/* 447BD0 80218790 0280202D */  daddu     $a0, $s4, $zero
/* 447BD4 80218794 0C0B1EAF */  jal       get_variable
/* 447BD8 80218798 0040882D */   daddu    $s1, $v0, $zero
/* 447BDC 8021879C 0040982D */  daddu     $s3, $v0, $zero
/* 447BE0 802187A0 8E450000 */  lw        $a1, ($s2)
/* 447BE4 802187A4 26520004 */  addiu     $s2, $s2, 4
/* 447BE8 802187A8 0280202D */  daddu     $a0, $s4, $zero
/* 447BEC 802187AC 0C0B1EAF */  jal       get_variable
/* 447BF0 802187B0 02709823 */   subu     $s3, $s3, $s0
/* 447BF4 802187B4 0040802D */  daddu     $s0, $v0, $zero
/* 447BF8 802187B8 0280202D */  daddu     $a0, $s4, $zero
/* 447BFC 802187BC 8E450000 */  lw        $a1, ($s2)
/* 447C00 802187C0 0C0B1EAF */  jal       get_variable
/* 447C04 802187C4 02118023 */   subu     $s0, $s0, $s1
/* 447C08 802187C8 16600006 */  bnez      $s3, .L802187E4
/* 447C0C 802187CC 00000000 */   nop
/* 447C10 802187D0 16000004 */  bnez      $s0, .L802187E4
/* 447C14 802187D4 0280202D */   daddu    $a0, $s4, $zero
/* 447C18 802187D8 8E450000 */  lw        $a1, ($s2)
/* 447C1C 802187DC 08086203 */  j         .L8021880C
/* 447C20 802187E0 0040302D */   daddu    $a2, $v0, $zero
.L802187E4:
/* 447C24 802187E4 44936000 */  mtc1      $s3, $f12
/* 447C28 802187E8 00000000 */  nop
/* 447C2C 802187EC 46806320 */  cvt.s.w   $f12, $f12
/* 447C30 802187F0 44907000 */  mtc1      $s0, $f14
/* 447C34 802187F4 00000000 */  nop
/* 447C38 802187F8 0C08616E */  jal       func_802185B8_4479F8
/* 447C3C 802187FC 468073A0 */   cvt.s.w  $f14, $f14
/* 447C40 80218800 0280202D */  daddu     $a0, $s4, $zero
/* 447C44 80218804 8E450000 */  lw        $a1, ($s2)
/* 447C48 80218808 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L8021880C:
/* 447C4C 8021880C 0C0B2026 */  jal       set_variable
/* 447C50 80218810 00000000 */   nop
/* 447C54 80218814 24020002 */  addiu     $v0, $zero, 2
/* 447C58 80218818 8FBF0024 */  lw        $ra, 0x24($sp)
/* 447C5C 8021881C 8FB40020 */  lw        $s4, 0x20($sp)
/* 447C60 80218820 8FB3001C */  lw        $s3, 0x1c($sp)
/* 447C64 80218824 8FB20018 */  lw        $s2, 0x18($sp)
/* 447C68 80218828 8FB10014 */  lw        $s1, 0x14($sp)
/* 447C6C 8021882C 8FB00010 */  lw        $s0, 0x10($sp)
/* 447C70 80218830 03E00008 */  jr        $ra
/* 447C74 80218834 27BD0028 */   addiu    $sp, $sp, 0x28
/* 447C78 80218838 00000000 */  nop
/* 447C7C 8021883C 00000000 */  nop
