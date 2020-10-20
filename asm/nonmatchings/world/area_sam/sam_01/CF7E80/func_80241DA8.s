.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DA8
/* CF9918 80241DA8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF991C 80241DAC AFB10014 */  sw        $s1, 0x14($sp)
/* CF9920 80241DB0 0080882D */  daddu     $s1, $a0, $zero
/* CF9924 80241DB4 AFBF001C */  sw        $ra, 0x1c($sp)
/* CF9928 80241DB8 AFB20018 */  sw        $s2, 0x18($sp)
/* CF992C 80241DBC AFB00010 */  sw        $s0, 0x10($sp)
/* CF9930 80241DC0 8E240084 */  lw        $a0, 0x84($s1)
/* CF9934 80241DC4 0C04C3D6 */  jal       get_item_entity
/* CF9938 80241DC8 00A0802D */   daddu    $s0, $a1, $zero
/* CF993C 80241DCC 12000005 */  beqz      $s0, .L80241DE4
/* CF9940 80241DD0 0040902D */   daddu    $s2, $v0, $zero
/* CF9944 80241DD4 C640000C */  lwc1      $f0, 0xc($s2)
/* CF9948 80241DD8 AE200074 */  sw        $zero, 0x74($s1)
/* CF994C 80241DDC AE20007C */  sw        $zero, 0x7c($s1)
/* CF9950 80241DE0 E6200078 */  swc1      $f0, 0x78($s1)
.L80241DE4:
/* CF9954 80241DE4 8E230074 */  lw        $v1, 0x74($s1)
/* CF9958 80241DE8 10600005 */  beqz      $v1, .L80241E00
/* CF995C 80241DEC 24020001 */   addiu    $v0, $zero, 1
/* CF9960 80241DF0 10620024 */  beq       $v1, $v0, .L80241E84
/* CF9964 80241DF4 00000000 */   nop      
/* CF9968 80241DF8 080907B7 */  j         .L80241EDC
/* CF996C 80241DFC 00000000 */   nop      
.L80241E00:
/* CF9970 80241E00 3C013FC9 */  lui       $at, 0x3fc9
/* CF9974 80241E04 34210FD8 */  ori       $at, $at, 0xfd8
/* CF9978 80241E08 44810000 */  mtc1      $at, $f0
/* CF997C 80241E0C C62C007C */  lwc1      $f12, 0x7c($s1)
/* CF9980 80241E10 46806320 */  cvt.s.w   $f12, $f12
/* CF9984 80241E14 46006302 */  mul.s     $f12, $f12, $f0
/* CF9988 80241E18 00000000 */  nop       
/* CF998C 80241E1C 3C0141F0 */  lui       $at, 0x41f0
/* CF9990 80241E20 44810000 */  mtc1      $at, $f0
/* CF9994 80241E24 0C00A874 */  jal       cos_rad
/* CF9998 80241E28 46006303 */   div.s    $f12, $f12, $f0
/* CF999C 80241E2C 3C013F80 */  lui       $at, 0x3f80
/* CF99A0 80241E30 44811000 */  mtc1      $at, $f2
/* CF99A4 80241E34 00000000 */  nop       
/* CF99A8 80241E38 46001081 */  sub.s     $f2, $f2, $f0
/* CF99AC 80241E3C 3C0141A0 */  lui       $at, 0x41a0
/* CF99B0 80241E40 44810000 */  mtc1      $at, $f0
/* CF99B4 80241E44 00000000 */  nop       
/* CF99B8 80241E48 46001082 */  mul.s     $f2, $f2, $f0
/* CF99BC 80241E4C 00000000 */  nop       
/* CF99C0 80241E50 C6200078 */  lwc1      $f0, 0x78($s1)
/* CF99C4 80241E54 46020000 */  add.s     $f0, $f0, $f2
/* CF99C8 80241E58 E640000C */  swc1      $f0, 0xc($s2)
/* CF99CC 80241E5C 8E23007C */  lw        $v1, 0x7c($s1)
/* CF99D0 80241E60 2402001E */  addiu     $v0, $zero, 0x1e
/* CF99D4 80241E64 14620005 */  bne       $v1, $v0, .L80241E7C
/* CF99D8 80241E68 24620001 */   addiu    $v0, $v1, 1
/* CF99DC 80241E6C 24020001 */  addiu     $v0, $zero, 1
/* CF99E0 80241E70 AE220074 */  sw        $v0, 0x74($s1)
/* CF99E4 80241E74 080907B7 */  j         .L80241EDC
/* CF99E8 80241E78 AE20007C */   sw       $zero, 0x7c($s1)
.L80241E7C:
/* CF99EC 80241E7C 080907B7 */  j         .L80241EDC
/* CF99F0 80241E80 AE22007C */   sw       $v0, 0x7c($s1)
.L80241E84:
/* CF99F4 80241E84 C62C007C */  lwc1      $f12, 0x7c($s1)
/* CF99F8 80241E88 0C00A8D4 */  jal       cos_deg
/* CF99FC 80241E8C 46806320 */   cvt.s.w  $f12, $f12
/* CF9A00 80241E90 3C014040 */  lui       $at, 0x4040
/* CF9A04 80241E94 44811000 */  mtc1      $at, $f2
/* CF9A08 80241E98 00000000 */  nop       
/* CF9A0C 80241E9C 46020002 */  mul.s     $f0, $f0, $f2
/* CF9A10 80241EA0 00000000 */  nop       
/* CF9A14 80241EA4 3C014188 */  lui       $at, 0x4188
/* CF9A18 80241EA8 44812000 */  mtc1      $at, $f4
/* CF9A1C 80241EAC C6220078 */  lwc1      $f2, 0x78($s1)
/* CF9A20 80241EB0 46041080 */  add.s     $f2, $f2, $f4
/* CF9A24 80241EB4 46001080 */  add.s     $f2, $f2, $f0
/* CF9A28 80241EB8 E642000C */  swc1      $f2, 0xc($s2)
/* CF9A2C 80241EBC 8E22007C */  lw        $v0, 0x7c($s1)
/* CF9A30 80241EC0 24420009 */  addiu     $v0, $v0, 9
/* CF9A34 80241EC4 44826000 */  mtc1      $v0, $f12
/* CF9A38 80241EC8 00000000 */  nop       
/* CF9A3C 80241ECC 0C00A6C9 */  jal       clamp_angle
/* CF9A40 80241ED0 46806320 */   cvt.s.w  $f12, $f12
/* CF9A44 80241ED4 4600018D */  trunc.w.s $f6, $f0
/* CF9A48 80241ED8 E626007C */  swc1      $f6, 0x7c($s1)
.L80241EDC:
/* CF9A4C 80241EDC 8FBF001C */  lw        $ra, 0x1c($sp)
/* CF9A50 80241EE0 8FB20018 */  lw        $s2, 0x18($sp)
/* CF9A54 80241EE4 8FB10014 */  lw        $s1, 0x14($sp)
/* CF9A58 80241EE8 8FB00010 */  lw        $s0, 0x10($sp)
/* CF9A5C 80241EEC 0000102D */  daddu     $v0, $zero, $zero
/* CF9A60 80241EF0 03E00008 */  jr        $ra
/* CF9A64 80241EF4 27BD0020 */   addiu    $sp, $sp, 0x20
