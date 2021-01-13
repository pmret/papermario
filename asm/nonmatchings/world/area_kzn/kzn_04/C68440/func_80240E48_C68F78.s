.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E48_C68F78
/* C68F78 80240E48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C68F7C 80240E4C AFB10014 */  sw        $s1, 0x14($sp)
/* C68F80 80240E50 0080882D */  daddu     $s1, $a0, $zero
/* C68F84 80240E54 AFB20018 */  sw        $s2, 0x18($sp)
/* C68F88 80240E58 AFBF001C */  sw        $ra, 0x1c($sp)
/* C68F8C 80240E5C AFB00010 */  sw        $s0, 0x10($sp)
/* C68F90 80240E60 8E30000C */  lw        $s0, 0xc($s1)
/* C68F94 80240E64 10A00010 */  beqz      $a1, .L80240EA8
/* C68F98 80240E68 0000902D */   daddu    $s2, $zero, $zero
/* C68F9C 80240E6C 8E050000 */  lw        $a1, ($s0)
/* C68FA0 80240E70 0C0B1EAF */  jal       get_variable
/* C68FA4 80240E74 26100004 */   addiu    $s0, $s0, 4
/* C68FA8 80240E78 AE220084 */  sw        $v0, 0x84($s1)
/* C68FAC 80240E7C 8E050000 */  lw        $a1, ($s0)
/* C68FB0 80240E80 0C0B1EAF */  jal       get_variable
/* C68FB4 80240E84 0220202D */   daddu    $a0, $s1, $zero
/* C68FB8 80240E88 0240202D */  daddu     $a0, $s2, $zero
/* C68FBC 80240E8C 240500D0 */  addiu     $a1, $zero, 0xd0
/* C68FC0 80240E90 00A0302D */  daddu     $a2, $a1, $zero
/* C68FC4 80240E94 00A0382D */  daddu     $a3, $a1, $zero
/* C68FC8 80240E98 AE220088 */  sw        $v0, 0x88($s1)
/* C68FCC 80240E9C AE200070 */  sw        $zero, 0x70($s1)
/* C68FD0 80240EA0 0C04DF84 */  jal       func_80137E10
/* C68FD4 80240EA4 AE200074 */   sw       $zero, 0x74($s1)
.L80240EA8:
/* C68FD8 80240EA8 8E230070 */  lw        $v1, 0x70($s1)
/* C68FDC 80240EAC 24040001 */  addiu     $a0, $zero, 1
/* C68FE0 80240EB0 10640019 */  beq       $v1, $a0, .L80240F18
/* C68FE4 80240EB4 28620002 */   slti     $v0, $v1, 2
/* C68FE8 80240EB8 10400005 */  beqz      $v0, .L80240ED0
/* C68FEC 80240EBC 24020002 */   addiu    $v0, $zero, 2
/* C68FF0 80240EC0 10600007 */  beqz      $v1, .L80240EE0
/* C68FF4 80240EC4 240500FF */   addiu    $a1, $zero, 0xff
/* C68FF8 80240EC8 080903D6 */  j         .L80240F58
/* C68FFC 80240ECC 00000000 */   nop
.L80240ED0:
/* C69000 80240ED0 10620019 */  beq       $v1, $v0, .L80240F38
/* C69004 80240ED4 00000000 */   nop
/* C69008 80240ED8 080903D6 */  j         .L80240F58
/* C6900C 80240EDC 00000000 */   nop
.L80240EE0:
/* C69010 80240EE0 8E220074 */  lw        $v0, 0x74($s1)
/* C69014 80240EE4 14450004 */  bne       $v0, $a1, .L80240EF8
/* C69018 80240EE8 00000000 */   nop
/* C6901C 80240EEC AE240070 */  sw        $a0, 0x70($s1)
/* C69020 80240EF0 AE200078 */  sw        $zero, 0x78($s1)
/* C69024 80240EF4 8E220074 */  lw        $v0, 0x74($s1)
.L80240EF8:
/* C69028 80240EF8 8E230084 */  lw        $v1, 0x84($s1)
/* C6902C 80240EFC 00431021 */  addu      $v0, $v0, $v1
/* C69030 80240F00 AE220074 */  sw        $v0, 0x74($s1)
/* C69034 80240F04 28420100 */  slti      $v0, $v0, 0x100
/* C69038 80240F08 50400013 */  beql      $v0, $zero, .L80240F58
/* C6903C 80240F0C AE250074 */   sw       $a1, 0x74($s1)
/* C69040 80240F10 080903D6 */  j         .L80240F58
/* C69044 80240F14 00000000 */   nop
.L80240F18:
/* C69048 80240F18 8E220078 */  lw        $v0, 0x78($s1)
/* C6904C 80240F1C 24420001 */  addiu     $v0, $v0, 1
/* C69050 80240F20 AE220078 */  sw        $v0, 0x78($s1)
/* C69054 80240F24 28420002 */  slti      $v0, $v0, 2
/* C69058 80240F28 1440000B */  bnez      $v0, .L80240F58
/* C6905C 80240F2C 24020002 */   addiu    $v0, $zero, 2
/* C69060 80240F30 080903D6 */  j         .L80240F58
/* C69064 80240F34 AE220070 */   sw       $v0, 0x70($s1)
.L80240F38:
/* C69068 80240F38 8E230074 */  lw        $v1, 0x74($s1)
/* C6906C 80240F3C 50600001 */  beql      $v1, $zero, .L80240F44
/* C69070 80240F40 24120001 */   addiu    $s2, $zero, 1
.L80240F44:
/* C69074 80240F44 8E220088 */  lw        $v0, 0x88($s1)
/* C69078 80240F48 00621023 */  subu      $v0, $v1, $v0
/* C6907C 80240F4C 04410002 */  bgez      $v0, .L80240F58
/* C69080 80240F50 AE220074 */   sw       $v0, 0x74($s1)
/* C69084 80240F54 AE200074 */  sw        $zero, 0x74($s1)
.L80240F58:
/* C69088 80240F58 C6200074 */  lwc1      $f0, 0x74($s1)
/* C6908C 80240F5C 46800020 */  cvt.s.w   $f0, $f0
/* C69090 80240F60 44050000 */  mfc1      $a1, $f0
/* C69094 80240F64 0C04DF62 */  jal       func_80137D88
/* C69098 80240F68 24040001 */   addiu    $a0, $zero, 1
/* C6909C 80240F6C 0240102D */  daddu     $v0, $s2, $zero
/* C690A0 80240F70 8FBF001C */  lw        $ra, 0x1c($sp)
/* C690A4 80240F74 8FB20018 */  lw        $s2, 0x18($sp)
/* C690A8 80240F78 8FB10014 */  lw        $s1, 0x14($sp)
/* C690AC 80240F7C 8FB00010 */  lw        $s0, 0x10($sp)
/* C690B0 80240F80 03E00008 */  jr        $ra
/* C690B4 80240F84 27BD0020 */   addiu    $sp, $sp, 0x20
