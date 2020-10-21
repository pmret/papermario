.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C18_8B1C88
/* 8B1C88 80241C18 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 8B1C8C 80241C1C AFB40040 */  sw        $s4, 0x40($sp)
/* 8B1C90 80241C20 0080A02D */  daddu     $s4, $a0, $zero
/* 8B1C94 80241C24 AFBF0048 */  sw        $ra, 0x48($sp)
/* 8B1C98 80241C28 AFB50044 */  sw        $s5, 0x44($sp)
/* 8B1C9C 80241C2C AFB3003C */  sw        $s3, 0x3c($sp)
/* 8B1CA0 80241C30 AFB20038 */  sw        $s2, 0x38($sp)
/* 8B1CA4 80241C34 AFB10034 */  sw        $s1, 0x34($sp)
/* 8B1CA8 80241C38 AFB00030 */  sw        $s0, 0x30($sp)
/* 8B1CAC 80241C3C 8E920148 */  lw        $s2, 0x148($s4)
/* 8B1CB0 80241C40 86440008 */  lh        $a0, 8($s2)
/* 8B1CB4 80241C44 8E90000C */  lw        $s0, 0xc($s4)
/* 8B1CB8 80241C48 0C00EABB */  jal       get_npc_unsafe
/* 8B1CBC 80241C4C 00A0882D */   daddu    $s1, $a1, $zero
/* 8B1CC0 80241C50 0280202D */  daddu     $a0, $s4, $zero
/* 8B1CC4 80241C54 8E050000 */  lw        $a1, ($s0)
/* 8B1CC8 80241C58 0C0B1EAF */  jal       get_variable
/* 8B1CCC 80241C5C 0040802D */   daddu    $s0, $v0, $zero
/* 8B1CD0 80241C60 AFA00010 */  sw        $zero, 0x10($sp)
/* 8B1CD4 80241C64 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8B1CD8 80241C68 8C630030 */  lw        $v1, 0x30($v1)
/* 8B1CDC 80241C6C AFA30014 */  sw        $v1, 0x14($sp)
/* 8B1CE0 80241C70 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8B1CE4 80241C74 8C63001C */  lw        $v1, 0x1c($v1)
/* 8B1CE8 80241C78 AFA30018 */  sw        $v1, 0x18($sp)
/* 8B1CEC 80241C7C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8B1CF0 80241C80 8C630024 */  lw        $v1, 0x24($v1)
/* 8B1CF4 80241C84 AFA3001C */  sw        $v1, 0x1c($sp)
/* 8B1CF8 80241C88 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8B1CFC 80241C8C 8C630028 */  lw        $v1, 0x28($v1)
/* 8B1D00 80241C90 27B50010 */  addiu     $s5, $sp, 0x10
/* 8B1D04 80241C94 AFA30020 */  sw        $v1, 0x20($sp)
/* 8B1D08 80241C98 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8B1D0C 80241C9C 3C014282 */  lui       $at, 0x4282
/* 8B1D10 80241CA0 44810000 */  mtc1      $at, $f0
/* 8B1D14 80241CA4 8C63002C */  lw        $v1, 0x2c($v1)
/* 8B1D18 80241CA8 0040982D */  daddu     $s3, $v0, $zero
/* 8B1D1C 80241CAC E7A00028 */  swc1      $f0, 0x28($sp)
/* 8B1D20 80241CB0 A7A0002C */  sh        $zero, 0x2c($sp)
/* 8B1D24 80241CB4 16200005 */  bnez      $s1, .L80241CCC
/* 8B1D28 80241CB8 AFA30024 */   sw       $v1, 0x24($sp)
/* 8B1D2C 80241CBC 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 8B1D30 80241CC0 30420004 */  andi      $v0, $v0, 4
/* 8B1D34 80241CC4 1040002F */  beqz      $v0, .L80241D84
/* 8B1D38 80241CC8 00000000 */   nop      
.L80241CCC:
/* 8B1D3C 80241CCC AE800070 */  sw        $zero, 0x70($s4)
/* 8B1D40 80241CD0 C600000C */  lwc1      $f0, 0xc($s0)
/* 8B1D44 80241CD4 A600008E */  sh        $zero, 0x8e($s0)
/* 8B1D48 80241CD8 8E4200CC */  lw        $v0, 0xcc($s2)
/* 8B1D4C 80241CDC 4600008D */  trunc.w.s $f2, $f0
/* 8B1D50 80241CE0 E642006C */  swc1      $f2, 0x6c($s2)
/* 8B1D54 80241CE4 8C420000 */  lw        $v0, ($v0)
/* 8B1D58 80241CE8 8E030000 */  lw        $v1, ($s0)
/* 8B1D5C 80241CEC AE020028 */  sw        $v0, 0x28($s0)
/* 8B1D60 80241CF0 2402F7FF */  addiu     $v0, $zero, -0x801
/* 8B1D64 80241CF4 00621824 */  and       $v1, $v1, $v0
/* 8B1D68 80241CF8 AE030000 */  sw        $v1, ($s0)
/* 8B1D6C 80241CFC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 8B1D70 80241D00 8C420034 */  lw        $v0, 0x34($v0)
/* 8B1D74 80241D04 54400005 */  bnel      $v0, $zero, .L80241D1C
/* 8B1D78 80241D08 2402FDFF */   addiu    $v0, $zero, -0x201
/* 8B1D7C 80241D0C 34620200 */  ori       $v0, $v1, 0x200
/* 8B1D80 80241D10 2403FFF7 */  addiu     $v1, $zero, -9
/* 8B1D84 80241D14 08090749 */  j         .L80241D24
/* 8B1D88 80241D18 00431024 */   and      $v0, $v0, $v1
.L80241D1C:
/* 8B1D8C 80241D1C 00621024 */  and       $v0, $v1, $v0
/* 8B1D90 80241D20 34420008 */  ori       $v0, $v0, 8
.L80241D24:
/* 8B1D94 80241D24 AE020000 */  sw        $v0, ($s0)
/* 8B1D98 80241D28 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 8B1D9C 80241D2C 30420004 */  andi      $v0, $v0, 4
/* 8B1DA0 80241D30 10400009 */  beqz      $v0, .L80241D58
/* 8B1DA4 80241D34 24020063 */   addiu    $v0, $zero, 0x63
/* 8B1DA8 80241D38 AE820070 */  sw        $v0, 0x70($s4)
/* 8B1DAC 80241D3C 2402000F */  addiu     $v0, $zero, 0xf
/* 8B1DB0 80241D40 AE820074 */  sw        $v0, 0x74($s4)
/* 8B1DB4 80241D44 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 8B1DB8 80241D48 2403FFFB */  addiu     $v1, $zero, -5
/* 8B1DBC 80241D4C 00431024 */  and       $v0, $v0, $v1
/* 8B1DC0 80241D50 08090761 */  j         .L80241D84
/* 8B1DC4 80241D54 AE4200B0 */   sw       $v0, 0xb0($s2)
.L80241D58:
/* 8B1DC8 80241D58 8E420000 */  lw        $v0, ($s2)
/* 8B1DCC 80241D5C 3C034000 */  lui       $v1, 0x4000
/* 8B1DD0 80241D60 00431024 */  and       $v0, $v0, $v1
/* 8B1DD4 80241D64 10400007 */  beqz      $v0, .L80241D84
/* 8B1DD8 80241D68 3C03BFFF */   lui      $v1, 0xbfff
/* 8B1DDC 80241D6C 2402000C */  addiu     $v0, $zero, 0xc
/* 8B1DE0 80241D70 AE820070 */  sw        $v0, 0x70($s4)
/* 8B1DE4 80241D74 8E420000 */  lw        $v0, ($s2)
/* 8B1DE8 80241D78 3463FFFF */  ori       $v1, $v1, 0xffff
/* 8B1DEC 80241D7C 00431024 */  and       $v0, $v0, $v1
/* 8B1DF0 80241D80 AE420000 */  sw        $v0, ($s2)
.L80241D84:
/* 8B1DF4 80241D84 8E830070 */  lw        $v1, 0x70($s4)
/* 8B1DF8 80241D88 2C620064 */  sltiu     $v0, $v1, 0x64
/* 8B1DFC 80241D8C 10400036 */  beqz      $v0, .L80241E68
/* 8B1E00 80241D90 00031080 */   sll      $v0, $v1, 2
/* 8B1E04 80241D94 3C018025 */  lui       $at, 0x8025
/* 8B1E08 80241D98 00220821 */  addu      $at, $at, $v0
/* 8B1E0C 80241D9C 8C227D58 */  lw        $v0, 0x7d58($at)
/* 8B1E10 80241DA0 00400008 */  jr        $v0
/* 8B1E14 80241DA4 00000000 */   nop      
/* 8B1E18 80241DA8 0280202D */  daddu     $a0, $s4, $zero
/* 8B1E1C 80241DAC 0260282D */  daddu     $a1, $s3, $zero
/* 8B1E20 80241DB0 0C090509 */  jal       func_80241424_8B1494
/* 8B1E24 80241DB4 02A0302D */   daddu    $a2, $s5, $zero
/* 8B1E28 80241DB8 0280202D */  daddu     $a0, $s4, $zero
/* 8B1E2C 80241DBC 0260282D */  daddu     $a1, $s3, $zero
/* 8B1E30 80241DC0 0C090536 */  jal       func_802414D8_8B1548
/* 8B1E34 80241DC4 02A0302D */   daddu    $a2, $s5, $zero
/* 8B1E38 80241DC8 0809079A */  j         .L80241E68
/* 8B1E3C 80241DCC 00000000 */   nop      
/* 8B1E40 80241DD0 0280202D */  daddu     $a0, $s4, $zero
/* 8B1E44 80241DD4 0260282D */  daddu     $a1, $s3, $zero
/* 8B1E48 80241DD8 0C09057E */  jal       func_802415F8_8B1668
/* 8B1E4C 80241DDC 02A0302D */   daddu    $a2, $s5, $zero
/* 8B1E50 80241DE0 0280202D */  daddu     $a0, $s4, $zero
/* 8B1E54 80241DE4 0260282D */  daddu     $a1, $s3, $zero
/* 8B1E58 80241DE8 0C090596 */  jal       func_80241658_8B16C8
/* 8B1E5C 80241DEC 02A0302D */   daddu    $a2, $s5, $zero
/* 8B1E60 80241DF0 0809079A */  j         .L80241E68
/* 8B1E64 80241DF4 00000000 */   nop      
/* 8B1E68 80241DF8 0280202D */  daddu     $a0, $s4, $zero
/* 8B1E6C 80241DFC 0260282D */  daddu     $a1, $s3, $zero
/* 8B1E70 80241E00 0C0905B4 */  jal       func_802416D0_8B1740
/* 8B1E74 80241E04 02A0302D */   daddu    $a2, $s5, $zero
/* 8B1E78 80241E08 0280202D */  daddu     $a0, $s4, $zero
/* 8B1E7C 80241E0C 0260282D */  daddu     $a1, $s3, $zero
/* 8B1E80 80241E10 0C090600 */  jal       func_80241800_8B1870
/* 8B1E84 80241E14 02A0302D */   daddu    $a2, $s5, $zero
/* 8B1E88 80241E18 0809079A */  j         .L80241E68
/* 8B1E8C 80241E1C 00000000 */   nop      
/* 8B1E90 80241E20 0280202D */  daddu     $a0, $s4, $zero
/* 8B1E94 80241E24 0260282D */  daddu     $a1, $s3, $zero
/* 8B1E98 80241E28 0C090647 */  jal       func_8024191C_8B198C
/* 8B1E9C 80241E2C 02A0302D */   daddu    $a2, $s5, $zero
/* 8B1EA0 80241E30 0809079A */  j         .L80241E68
/* 8B1EA4 80241E34 00000000 */   nop      
/* 8B1EA8 80241E38 0280202D */  daddu     $a0, $s4, $zero
/* 8B1EAC 80241E3C 0260282D */  daddu     $a1, $s3, $zero
/* 8B1EB0 80241E40 0C090659 */  jal       func_80241964_8B19D4
/* 8B1EB4 80241E44 02A0302D */   daddu    $a2, $s5, $zero
/* 8B1EB8 80241E48 0280202D */  daddu     $a0, $s4, $zero
/* 8B1EBC 80241E4C 0260282D */  daddu     $a1, $s3, $zero
/* 8B1EC0 80241E50 0C090684 */  jal       func_80241A10_8B1A80
/* 8B1EC4 80241E54 02A0302D */   daddu    $a2, $s5, $zero
/* 8B1EC8 80241E58 0809079A */  j         .L80241E68
/* 8B1ECC 80241E5C 00000000 */   nop      
/* 8B1ED0 80241E60 0C0129CF */  jal       func_8004A73C
/* 8B1ED4 80241E64 0280202D */   daddu    $a0, $s4, $zero
.L80241E68:
/* 8B1ED8 80241E68 8FBF0048 */  lw        $ra, 0x48($sp)
/* 8B1EDC 80241E6C 8FB50044 */  lw        $s5, 0x44($sp)
/* 8B1EE0 80241E70 8FB40040 */  lw        $s4, 0x40($sp)
/* 8B1EE4 80241E74 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8B1EE8 80241E78 8FB20038 */  lw        $s2, 0x38($sp)
/* 8B1EEC 80241E7C 8FB10034 */  lw        $s1, 0x34($sp)
/* 8B1EF0 80241E80 8FB00030 */  lw        $s0, 0x30($sp)
/* 8B1EF4 80241E84 0000102D */  daddu     $v0, $zero, $zero
/* 8B1EF8 80241E88 03E00008 */  jr        $ra
/* 8B1EFC 80241E8C 27BD0050 */   addiu    $sp, $sp, 0x50
