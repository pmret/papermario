.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00826C4
/* 385D04 E00826C4 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 385D08 E00826C8 AFB1009C */  sw        $s1, 0x9c($sp)
/* 385D0C E00826CC 0080882D */  daddu     $s1, $a0, $zero
/* 385D10 E00826D0 27A40018 */  addiu     $a0, $sp, 0x18
/* 385D14 E00826D4 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 385D18 E00826D8 3C130001 */  lui       $s3, 1
/* 385D1C E00826DC AFBF00A8 */  sw        $ra, 0xa8($sp)
/* 385D20 E00826E0 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 385D24 E00826E4 AFB00098 */  sw        $s0, 0x98($sp)
/* 385D28 E00826E8 F7B400B0 */  sdc1      $f20, 0xb0($sp)
/* 385D2C E00826EC 8E250008 */  lw        $a1, 8($s1)
/* 385D30 E00826F0 8E26000C */  lw        $a2, 0xc($s1)
/* 385D34 E00826F4 8E270010 */  lw        $a3, 0x10($s1)
/* 385D38 E00826F8 0C080108 */  jal       func_E0200420
/* 385D3C E00826FC 36731630 */   ori      $s3, $s3, 0x1630
/* 385D40 E0082700 27B00058 */  addiu     $s0, $sp, 0x58
/* 385D44 E0082704 0200202D */  daddu     $a0, $s0, $zero
/* 385D48 E0082708 3C013F80 */  lui       $at, 0x3f80
/* 385D4C E008270C 4481A000 */  mtc1      $at, $f20
/* 385D50 E0082710 8E250030 */  lw        $a1, 0x30($s1)
/* 385D54 E0082714 4407A000 */  mfc1      $a3, $f20
/* 385D58 E0082718 0C080110 */  jal       func_E0200440
/* 385D5C E008271C 00A0302D */   daddu    $a2, $a1, $zero
/* 385D60 E0082720 0200202D */  daddu     $a0, $s0, $zero
/* 385D64 E0082724 27A50018 */  addiu     $a1, $sp, 0x18
/* 385D68 E0082728 0C080114 */  jal       func_E0200450
/* 385D6C E008272C 00A0302D */   daddu    $a2, $a1, $zero
/* 385D70 E0082730 E7B40010 */  swc1      $f20, 0x10($sp)
/* 385D74 E0082734 4480A000 */  mtc1      $zero, $f20
/* 385D78 E0082738 8E250040 */  lw        $a1, 0x40($s1)
/* 385D7C E008273C 4406A000 */  mfc1      $a2, $f20
/* 385D80 E0082740 4407A000 */  mfc1      $a3, $f20
/* 385D84 E0082744 0C080104 */  jal       func_E0200410
/* 385D88 E0082748 0200202D */   daddu    $a0, $s0, $zero
/* 385D8C E008274C 0200202D */  daddu     $a0, $s0, $zero
/* 385D90 E0082750 27A50018 */  addiu     $a1, $sp, 0x18
/* 385D94 E0082754 0C080114 */  jal       func_E0200450
/* 385D98 E0082758 00A0302D */   daddu    $a2, $a1, $zero
/* 385D9C E008275C 0200202D */  daddu     $a0, $s0, $zero
/* 385DA0 E0082760 4405A000 */  mfc1      $a1, $f20
/* 385DA4 E0082764 8E260020 */  lw        $a2, 0x20($s1)
/* 385DA8 E0082768 0C080108 */  jal       func_E0200420
/* 385DAC E008276C 00A0382D */   daddu    $a3, $a1, $zero
/* 385DB0 E0082770 0200202D */  daddu     $a0, $s0, $zero
/* 385DB4 E0082774 27A50018 */  addiu     $a1, $sp, 0x18
/* 385DB8 E0082778 0C080114 */  jal       func_E0200450
/* 385DBC E008277C 00A0302D */   daddu    $a2, $a1, $zero
/* 385DC0 E0082780 27A40018 */  addiu     $a0, $sp, 0x18
/* 385DC4 E0082784 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 385DC8 E0082788 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 385DCC E008278C 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 385DD0 E0082790 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 385DD4 E0082794 96050000 */  lhu       $a1, ($s0)
/* 385DD8 E0082798 8E420000 */  lw        $v0, ($s2)
/* 385DDC E008279C 00052980 */  sll       $a1, $a1, 6
/* 385DE0 E00827A0 00B32821 */  addu      $a1, $a1, $s3
/* 385DE4 E00827A4 0C080118 */  jal       func_E0200460
/* 385DE8 E00827A8 00452821 */   addu     $a1, $v0, $a1
/* 385DEC E00827AC 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 385DF0 E00827B0 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 385DF4 E00827B4 8D070000 */  lw        $a3, ($t0)
/* 385DF8 E00827B8 00E0202D */  daddu     $a0, $a3, $zero
/* 385DFC E00827BC 24E70008 */  addiu     $a3, $a3, 8
/* 385E00 E00827C0 AD070000 */  sw        $a3, ($t0)
/* 385E04 E00827C4 96020000 */  lhu       $v0, ($s0)
/* 385E08 E00827C8 3C03DA38 */  lui       $v1, 0xda38
/* 385E0C E00827CC AC830000 */  sw        $v1, ($a0)
/* 385E10 E00827D0 24430001 */  addiu     $v1, $v0, 1
/* 385E14 E00827D4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 385E18 E00827D8 00021180 */  sll       $v0, $v0, 6
/* 385E1C E00827DC A6030000 */  sh        $v1, ($s0)
/* 385E20 E00827E0 8E430000 */  lw        $v1, ($s2)
/* 385E24 E00827E4 00531021 */  addu      $v0, $v0, $s3
/* 385E28 E00827E8 00621821 */  addu      $v1, $v1, $v0
/* 385E2C E00827EC 24E20008 */  addiu     $v0, $a3, 8
/* 385E30 E00827F0 AC830004 */  sw        $v1, 4($a0)
/* 385E34 E00827F4 AD020000 */  sw        $v0, ($t0)
/* 385E38 E00827F8 3C02FA00 */  lui       $v0, 0xfa00
/* 385E3C E00827FC ACE20000 */  sw        $v0, ($a3)
/* 385E40 E0082800 92220027 */  lbu       $v0, 0x27($s1)
/* 385E44 E0082804 ACE20004 */  sw        $v0, 4($a3)
/* 385E48 E0082808 8E230024 */  lw        $v1, 0x24($s1)
/* 385E4C E008280C 240200FF */  addiu     $v0, $zero, 0xff
/* 385E50 E0082810 14620011 */  bne       $v1, $v0, .LE0082858
/* 385E54 E0082814 3C05E200 */   lui      $a1, 0xe200
/* 385E58 E0082818 3C04E200 */  lui       $a0, 0xe200
/* 385E5C E008281C 3484001C */  ori       $a0, $a0, 0x1c
/* 385E60 E0082820 3C030055 */  lui       $v1, 0x55
/* 385E64 E0082824 34631208 */  ori       $v1, $v1, 0x1208
/* 385E68 E0082828 3C05FC12 */  lui       $a1, 0xfc12
/* 385E6C E008282C 34A57E24 */  ori       $a1, $a1, 0x7e24
/* 385E70 E0082830 24E20010 */  addiu     $v0, $a3, 0x10
/* 385E74 E0082834 AD020000 */  sw        $v0, ($t0)
/* 385E78 E0082838 24E20018 */  addiu     $v0, $a3, 0x18
/* 385E7C E008283C ACE40008 */  sw        $a0, 8($a3)
/* 385E80 E0082840 ACE3000C */  sw        $v1, 0xc($a3)
/* 385E84 E0082844 AD020000 */  sw        $v0, ($t0)
/* 385E88 E0082848 2402F3F9 */  addiu     $v0, $zero, -0xc07
/* 385E8C E008284C ACE50010 */  sw        $a1, 0x10($a3)
/* 385E90 E0082850 08020A25 */  j         .LE0082894
/* 385E94 E0082854 ACE20014 */   sw       $v0, 0x14($a3)
.LE0082858:
/* 385E98 E0082858 34A5001C */  ori       $a1, $a1, 0x1c
/* 385E9C E008285C 3C030050 */  lui       $v1, 0x50
/* 385EA0 E0082860 34634340 */  ori       $v1, $v1, 0x4340
/* 385EA4 E0082864 3C06FC12 */  lui       $a2, 0xfc12
/* 385EA8 E0082868 34C63224 */  ori       $a2, $a2, 0x3224
/* 385EAC E008286C 3C04FF67 */  lui       $a0, 0xff67
/* 385EB0 E0082870 3484FFFF */  ori       $a0, $a0, 0xffff
/* 385EB4 E0082874 24E20010 */  addiu     $v0, $a3, 0x10
/* 385EB8 E0082878 AD020000 */  sw        $v0, ($t0)
/* 385EBC E008287C 24E20018 */  addiu     $v0, $a3, 0x18
/* 385EC0 E0082880 ACE50008 */  sw        $a1, 8($a3)
/* 385EC4 E0082884 ACE3000C */  sw        $v1, 0xc($a3)
/* 385EC8 E0082888 AD020000 */  sw        $v0, ($t0)
/* 385ECC E008288C ACE60010 */  sw        $a2, 0x10($a3)
/* 385ED0 E0082890 ACE40014 */  sw        $a0, 0x14($a3)
.LE0082894:
/* 385ED4 E0082894 8FBF00A8 */  lw        $ra, 0xa8($sp)
/* 385ED8 E0082898 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 385EDC E008289C 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 385EE0 E00828A0 8FB1009C */  lw        $s1, 0x9c($sp)
/* 385EE4 E00828A4 8FB00098 */  lw        $s0, 0x98($sp)
/* 385EE8 E00828A8 D7B400B0 */  ldc1      $f20, 0xb0($sp)
/* 385EEC E00828AC 03E00008 */  jr        $ra
/* 385EF0 E00828B0 27BD00B8 */   addiu    $sp, $sp, 0xb8
