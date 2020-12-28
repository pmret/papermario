.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021840C_430DAC
/* 430DAC 8021840C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 430DB0 80218410 AFB40020 */  sw        $s4, 0x20($sp)
/* 430DB4 80218414 0080A02D */  daddu     $s4, $a0, $zero
/* 430DB8 80218418 AFBF0024 */  sw        $ra, 0x24($sp)
/* 430DBC 8021841C AFB3001C */  sw        $s3, 0x1c($sp)
/* 430DC0 80218420 AFB20018 */  sw        $s2, 0x18($sp)
/* 430DC4 80218424 AFB10014 */  sw        $s1, 0x14($sp)
/* 430DC8 80218428 AFB00010 */  sw        $s0, 0x10($sp)
/* 430DCC 8021842C 8E92000C */  lw        $s2, 0xc($s4)
/* 430DD0 80218430 8E450000 */  lw        $a1, ($s2)
/* 430DD4 80218434 0C0B1EAF */  jal       get_variable
/* 430DD8 80218438 26520004 */   addiu    $s2, $s2, 4
/* 430DDC 8021843C 8E450000 */  lw        $a1, ($s2)
/* 430DE0 80218440 26520004 */  addiu     $s2, $s2, 4
/* 430DE4 80218444 0280202D */  daddu     $a0, $s4, $zero
/* 430DE8 80218448 0C0B1EAF */  jal       get_variable
/* 430DEC 8021844C 0040802D */   daddu    $s0, $v0, $zero
/* 430DF0 80218450 8E450000 */  lw        $a1, ($s2)
/* 430DF4 80218454 26520004 */  addiu     $s2, $s2, 4
/* 430DF8 80218458 0280202D */  daddu     $a0, $s4, $zero
/* 430DFC 8021845C 0C0B1EAF */  jal       get_variable
/* 430E00 80218460 0040882D */   daddu    $s1, $v0, $zero
/* 430E04 80218464 0040982D */  daddu     $s3, $v0, $zero
/* 430E08 80218468 8E450000 */  lw        $a1, ($s2)
/* 430E0C 8021846C 26520004 */  addiu     $s2, $s2, 4
/* 430E10 80218470 0280202D */  daddu     $a0, $s4, $zero
/* 430E14 80218474 0C0B1EAF */  jal       get_variable
/* 430E18 80218478 02709823 */   subu     $s3, $s3, $s0
/* 430E1C 8021847C 0040802D */  daddu     $s0, $v0, $zero
/* 430E20 80218480 0280202D */  daddu     $a0, $s4, $zero
/* 430E24 80218484 8E450000 */  lw        $a1, ($s2)
/* 430E28 80218488 0C0B1EAF */  jal       get_variable
/* 430E2C 8021848C 02118023 */   subu     $s0, $s0, $s1
/* 430E30 80218490 16600006 */  bnez      $s3, .L802184AC
/* 430E34 80218494 00000000 */   nop      
/* 430E38 80218498 16000004 */  bnez      $s0, .L802184AC
/* 430E3C 8021849C 0280202D */   daddu    $a0, $s4, $zero
/* 430E40 802184A0 8E450000 */  lw        $a1, ($s2)
/* 430E44 802184A4 08086135 */  j         .L802184D4
/* 430E48 802184A8 0040302D */   daddu    $a2, $v0, $zero
.L802184AC:
/* 430E4C 802184AC 44936000 */  mtc1      $s3, $f12
/* 430E50 802184B0 00000000 */  nop       
/* 430E54 802184B4 46806320 */  cvt.s.w   $f12, $f12
/* 430E58 802184B8 44907000 */  mtc1      $s0, $f14
/* 430E5C 802184BC 00000000 */  nop       
/* 430E60 802184C0 0C0860A0 */  jal       func_80218280_430C20
/* 430E64 802184C4 468073A0 */   cvt.s.w  $f14, $f14
/* 430E68 802184C8 0280202D */  daddu     $a0, $s4, $zero
/* 430E6C 802184CC 8E450000 */  lw        $a1, ($s2)
/* 430E70 802184D0 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L802184D4:
/* 430E74 802184D4 0C0B2026 */  jal       set_variable
/* 430E78 802184D8 00000000 */   nop      
/* 430E7C 802184DC 24020002 */  addiu     $v0, $zero, 2
/* 430E80 802184E0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 430E84 802184E4 8FB40020 */  lw        $s4, 0x20($sp)
/* 430E88 802184E8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 430E8C 802184EC 8FB20018 */  lw        $s2, 0x18($sp)
/* 430E90 802184F0 8FB10014 */  lw        $s1, 0x14($sp)
/* 430E94 802184F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 430E98 802184F8 03E00008 */  jr        $ra
/* 430E9C 802184FC 27BD0028 */   addiu    $sp, $sp, 0x28
