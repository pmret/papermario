.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0092000
/* 391D30 E0092000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 391D34 E0092004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 391D38 E0092008 4485A000 */  mtc1      $a1, $f20
/* 391D3C E009200C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 391D40 E0092010 4486B000 */  mtc1      $a2, $f22
/* 391D44 E0092014 AFB20030 */  sw        $s2, 0x30($sp)
/* 391D48 E0092018 0080902D */  daddu     $s2, $a0, $zero
/* 391D4C E009201C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 391D50 E0092020 4487C000 */  mtc1      $a3, $f24
/* 391D54 E0092024 27A40010 */  addiu     $a0, $sp, 0x10
/* 391D58 E0092028 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 391D5C E009202C C7BA0068 */  lwc1      $f26, 0x68($sp)
/* 391D60 E0092030 3C02E009 */  lui       $v0, %hi(func_E00921AC)
/* 391D64 E0092034 244221AC */  addiu     $v0, $v0, %lo(func_E00921AC)
/* 391D68 E0092038 AFA20018 */  sw        $v0, 0x18($sp)
/* 391D6C E009203C 3C02E009 */  lui       $v0, %hi(func_E00921B4)
/* 391D70 E0092040 244221B4 */  addiu     $v0, $v0, %lo(func_E00921B4)
/* 391D74 E0092044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 391D78 E0092048 3C02E009 */  lui       $v0, %hi(func_E0092258)
/* 391D7C E009204C 24422258 */  addiu     $v0, $v0, %lo(func_E0092258)
/* 391D80 E0092050 AFA20020 */  sw        $v0, 0x20($sp)
/* 391D84 E0092054 24020049 */  addiu     $v0, $zero, 0x49
/* 391D88 E0092058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 391D8C E009205C AFB1002C */  sw        $s1, 0x2c($sp)
/* 391D90 E0092060 AFB00028 */  sw        $s0, 0x28($sp)
/* 391D94 E0092064 AFA00010 */  sw        $zero, 0x10($sp)
/* 391D98 E0092068 AFA00024 */  sw        $zero, 0x24($sp)
/* 391D9C E009206C 0C080124 */  jal       func_E0200490
/* 391DA0 E0092070 AFA20014 */   sw       $v0, 0x14($sp)
/* 391DA4 E0092074 240400B4 */  addiu     $a0, $zero, 0xb4
/* 391DA8 E0092078 24110005 */  addiu     $s1, $zero, 5
/* 391DAC E009207C 0040802D */  daddu     $s0, $v0, $zero
/* 391DB0 E0092080 0C08012C */  jal       func_E02004B0
/* 391DB4 E0092084 AE110008 */   sw       $s1, 8($s0)
/* 391DB8 E0092088 0040182D */  daddu     $v1, $v0, $zero
/* 391DBC E009208C 14600003 */  bnez      $v1, .LE009209C
/* 391DC0 E0092090 AE03000C */   sw       $v1, 0xc($s0)
.LE0092094:
/* 391DC4 E0092094 08024825 */  j         .LE0092094
/* 391DC8 E0092098 00000000 */   nop      
.LE009209C:
/* 391DCC E009209C 2402000E */  addiu     $v0, $zero, 0xe
/* 391DD0 E00920A0 AC720000 */  sw        $s2, ($v1)
/* 391DD4 E00920A4 AC600018 */  sw        $zero, 0x18($v1)
/* 391DD8 E00920A8 AC620014 */  sw        $v0, 0x14($v1)
/* 391DDC E00920AC E4740008 */  swc1      $f20, 8($v1)
/* 391DE0 E00920B0 E476000C */  swc1      $f22, 0xc($v1)
/* 391DE4 E00920B4 E4780010 */  swc1      $f24, 0x10($v1)
/* 391DE8 E00920B8 24040001 */  addiu     $a0, $zero, 1
/* 391DEC E00920BC 0091102A */  slt       $v0, $a0, $s1
/* 391DF0 E00920C0 1040002F */  beqz      $v0, .LE0092180
/* 391DF4 E00920C4 24630024 */   addiu    $v1, $v1, 0x24
/* 391DF8 E00920C8 3C08E009 */  lui       $t0, %hi(D_E00926A4)
/* 391DFC E00920CC 250826A4 */  addiu     $t0, $t0, %lo(D_E00926A4)
/* 391E00 E00920D0 240BFFFF */  addiu     $t3, $zero, -1
/* 391E04 E00920D4 3C01E009 */  lui       $at, %hi(D_E0092700)
/* 391E08 E00920D8 D4222700 */  ldc1      $f2, %lo(D_E0092700)($at)
/* 391E0C E00920DC 2463001C */  addiu     $v1, $v1, 0x1c
/* 391E10 E00920E0 240A0010 */  addiu     $t2, $zero, 0x10
/* 391E14 E00920E4 0000482D */  daddu     $t1, $zero, $zero
/* 391E18 E00920E8 2407000C */  addiu     $a3, $zero, 0xc
/* 391E1C E00920EC 24060008 */  addiu     $a2, $zero, 8
/* 391E20 E00920F0 24050004 */  addiu     $a1, $zero, 4
.LE00920F4:
/* 391E24 E00920F4 00A81021 */  addu      $v0, $a1, $t0
/* 391E28 E00920F8 C4400000 */  lwc1      $f0, ($v0)
/* 391E2C E00920FC 46800020 */  cvt.s.w   $f0, $f0
/* 391E30 E0092100 00C81021 */  addu      $v0, $a2, $t0
/* 391E34 E0092104 E460FFEC */  swc1      $f0, -0x14($v1)
/* 391E38 E0092108 C4400000 */  lwc1      $f0, ($v0)
/* 391E3C E009210C 46800020 */  cvt.s.w   $f0, $f0
/* 391E40 E0092110 00E81021 */  addu      $v0, $a3, $t0
/* 391E44 E0092114 E460FFF0 */  swc1      $f0, -0x10($v1)
/* 391E48 E0092118 C4400000 */  lwc1      $f0, ($v0)
/* 391E4C E009211C 46800020 */  cvt.s.w   $f0, $f0
/* 391E50 E0092120 01281021 */  addu      $v0, $t1, $t0
/* 391E54 E0092124 E460FFF4 */  swc1      $f0, -0xc($v1)
/* 391E58 E0092128 AC6BFFE8 */  sw        $t3, -0x18($v1)
/* 391E5C E009212C 8C420000 */  lw        $v0, ($v0)
/* 391E60 E0092130 AC620004 */  sw        $v0, 4($v1)
/* 391E64 E0092134 01481021 */  addu      $v0, $t2, $t0
/* 391E68 E0092138 C4400000 */  lwc1      $f0, ($v0)
/* 391E6C E009213C 46800020 */  cvt.s.w   $f0, $f0
/* 391E70 E0092140 4600D002 */  mul.s     $f0, $f26, $f0
/* 391E74 E0092144 00000000 */  nop       
/* 391E78 E0092148 46000021 */  cvt.d.s   $f0, $f0
/* 391E7C E009214C 46220002 */  mul.d     $f0, $f0, $f2
/* 391E80 E0092150 00000000 */  nop       
/* 391E84 E0092154 25290014 */  addiu     $t1, $t1, 0x14
/* 391E88 E0092158 24E70014 */  addiu     $a3, $a3, 0x14
/* 391E8C E009215C 24C60014 */  addiu     $a2, $a2, 0x14
/* 391E90 E0092160 24A50014 */  addiu     $a1, $a1, 0x14
/* 391E94 E0092164 24840001 */  addiu     $a0, $a0, 1
/* 391E98 E0092168 254A0014 */  addiu     $t2, $t2, 0x14
/* 391E9C E009216C 0091102A */  slt       $v0, $a0, $s1
/* 391EA0 E0092170 46200020 */  cvt.s.d   $f0, $f0
/* 391EA4 E0092174 E4600000 */  swc1      $f0, ($v1)
/* 391EA8 E0092178 1440FFDE */  bnez      $v0, .LE00920F4
/* 391EAC E009217C 24630024 */   addiu    $v1, $v1, 0x24
.LE0092180:
/* 391EB0 E0092180 0200102D */  daddu     $v0, $s0, $zero
/* 391EB4 E0092184 8FBF0034 */  lw        $ra, 0x34($sp)
/* 391EB8 E0092188 8FB20030 */  lw        $s2, 0x30($sp)
/* 391EBC E009218C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 391EC0 E0092190 8FB00028 */  lw        $s0, 0x28($sp)
/* 391EC4 E0092194 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 391EC8 E0092198 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 391ECC E009219C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 391ED0 E00921A0 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 391ED4 E00921A4 03E00008 */  jr        $ra
/* 391ED8 E00921A8 27BD0058 */   addiu    $sp, $sp, 0x58
