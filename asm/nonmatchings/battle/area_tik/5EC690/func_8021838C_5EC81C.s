.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021838C_5EC81C
/* 5EC81C 8021838C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5EC820 80218390 AFB40020 */  sw        $s4, 0x20($sp)
/* 5EC824 80218394 0080A02D */  daddu     $s4, $a0, $zero
/* 5EC828 80218398 AFBF0024 */  sw        $ra, 0x24($sp)
/* 5EC82C 8021839C AFB3001C */  sw        $s3, 0x1c($sp)
/* 5EC830 802183A0 AFB20018 */  sw        $s2, 0x18($sp)
/* 5EC834 802183A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 5EC838 802183A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 5EC83C 802183AC 8E92000C */  lw        $s2, 0xc($s4)
/* 5EC840 802183B0 8E450000 */  lw        $a1, ($s2)
/* 5EC844 802183B4 0C0B1EAF */  jal       get_variable
/* 5EC848 802183B8 26520004 */   addiu    $s2, $s2, 4
/* 5EC84C 802183BC 8E450000 */  lw        $a1, ($s2)
/* 5EC850 802183C0 26520004 */  addiu     $s2, $s2, 4
/* 5EC854 802183C4 0280202D */  daddu     $a0, $s4, $zero
/* 5EC858 802183C8 0C0B1EAF */  jal       get_variable
/* 5EC85C 802183CC 0040802D */   daddu    $s0, $v0, $zero
/* 5EC860 802183D0 8E450000 */  lw        $a1, ($s2)
/* 5EC864 802183D4 26520004 */  addiu     $s2, $s2, 4
/* 5EC868 802183D8 0280202D */  daddu     $a0, $s4, $zero
/* 5EC86C 802183DC 0C0B1EAF */  jal       get_variable
/* 5EC870 802183E0 0040882D */   daddu    $s1, $v0, $zero
/* 5EC874 802183E4 0040982D */  daddu     $s3, $v0, $zero
/* 5EC878 802183E8 8E450000 */  lw        $a1, ($s2)
/* 5EC87C 802183EC 26520004 */  addiu     $s2, $s2, 4
/* 5EC880 802183F0 0280202D */  daddu     $a0, $s4, $zero
/* 5EC884 802183F4 0C0B1EAF */  jal       get_variable
/* 5EC888 802183F8 02709823 */   subu     $s3, $s3, $s0
/* 5EC88C 802183FC 0040802D */  daddu     $s0, $v0, $zero
/* 5EC890 80218400 0280202D */  daddu     $a0, $s4, $zero
/* 5EC894 80218404 8E450000 */  lw        $a1, ($s2)
/* 5EC898 80218408 0C0B1EAF */  jal       get_variable
/* 5EC89C 8021840C 02118023 */   subu     $s0, $s0, $s1
/* 5EC8A0 80218410 16600006 */  bnez      $s3, .L8021842C
/* 5EC8A4 80218414 00000000 */   nop      
/* 5EC8A8 80218418 16000004 */  bnez      $s0, .L8021842C
/* 5EC8AC 8021841C 0280202D */   daddu    $a0, $s4, $zero
/* 5EC8B0 80218420 8E450000 */  lw        $a1, ($s2)
/* 5EC8B4 80218424 08086115 */  j         .L80218454
/* 5EC8B8 80218428 0040302D */   daddu    $a2, $v0, $zero
.L8021842C:
/* 5EC8BC 8021842C 44936000 */  mtc1      $s3, $f12
/* 5EC8C0 80218430 00000000 */  nop       
/* 5EC8C4 80218434 46806320 */  cvt.s.w   $f12, $f12
/* 5EC8C8 80218438 44907000 */  mtc1      $s0, $f14
/* 5EC8CC 8021843C 00000000 */  nop       
/* 5EC8D0 80218440 0C086080 */  jal       func_80218200_5EC690
/* 5EC8D4 80218444 468073A0 */   cvt.s.w  $f14, $f14
/* 5EC8D8 80218448 0280202D */  daddu     $a0, $s4, $zero
/* 5EC8DC 8021844C 8E450000 */  lw        $a1, ($s2)
/* 5EC8E0 80218450 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L80218454:
/* 5EC8E4 80218454 0C0B2026 */  jal       set_variable
/* 5EC8E8 80218458 00000000 */   nop      
/* 5EC8EC 8021845C 24020002 */  addiu     $v0, $zero, 2
/* 5EC8F0 80218460 8FBF0024 */  lw        $ra, 0x24($sp)
/* 5EC8F4 80218464 8FB40020 */  lw        $s4, 0x20($sp)
/* 5EC8F8 80218468 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5EC8FC 8021846C 8FB20018 */  lw        $s2, 0x18($sp)
/* 5EC900 80218470 8FB10014 */  lw        $s1, 0x14($sp)
/* 5EC904 80218474 8FB00010 */  lw        $s0, 0x10($sp)
/* 5EC908 80218478 03E00008 */  jr        $ra
/* 5EC90C 8021847C 27BD0028 */   addiu    $sp, $sp, 0x28
