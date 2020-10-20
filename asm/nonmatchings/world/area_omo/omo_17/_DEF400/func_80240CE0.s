.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CE0
/* DEFB80 80240CE0 27BDFF98 */  addiu     $sp, $sp, -0x68
/* DEFB84 80240CE4 AFB30054 */  sw        $s3, 0x54($sp)
/* DEFB88 80240CE8 0080982D */  daddu     $s3, $a0, $zero
/* DEFB8C 80240CEC AFBF0060 */  sw        $ra, 0x60($sp)
/* DEFB90 80240CF0 AFB5005C */  sw        $s5, 0x5c($sp)
/* DEFB94 80240CF4 AFB40058 */  sw        $s4, 0x58($sp)
/* DEFB98 80240CF8 AFB20050 */  sw        $s2, 0x50($sp)
/* DEFB9C 80240CFC AFB1004C */  sw        $s1, 0x4c($sp)
/* DEFBA0 80240D00 AFB00048 */  sw        $s0, 0x48($sp)
/* DEFBA4 80240D04 8E710148 */  lw        $s1, 0x148($s3)
/* DEFBA8 80240D08 86240008 */  lh        $a0, 8($s1)
/* DEFBAC 80240D0C 0C00EABB */  jal       get_npc_unsafe
/* DEFBB0 80240D10 00A0802D */   daddu    $s0, $a1, $zero
/* DEFBB4 80240D14 8E63000C */  lw        $v1, 0xc($s3)
/* DEFBB8 80240D18 0260202D */  daddu     $a0, $s3, $zero
/* DEFBBC 80240D1C 8C650000 */  lw        $a1, ($v1)
/* DEFBC0 80240D20 0C0B1EAF */  jal       get_variable
/* DEFBC4 80240D24 0040902D */   daddu    $s2, $v0, $zero
/* DEFBC8 80240D28 AFA00018 */  sw        $zero, 0x18($sp)
/* DEFBCC 80240D2C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DEFBD0 80240D30 8C630030 */  lw        $v1, 0x30($v1)
/* DEFBD4 80240D34 AFA3001C */  sw        $v1, 0x1c($sp)
/* DEFBD8 80240D38 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DEFBDC 80240D3C 8C63001C */  lw        $v1, 0x1c($v1)
/* DEFBE0 80240D40 AFA30020 */  sw        $v1, 0x20($sp)
/* DEFBE4 80240D44 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DEFBE8 80240D48 8C630024 */  lw        $v1, 0x24($v1)
/* DEFBEC 80240D4C AFA30024 */  sw        $v1, 0x24($sp)
/* DEFBF0 80240D50 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DEFBF4 80240D54 8C630028 */  lw        $v1, 0x28($v1)
/* DEFBF8 80240D58 27B50018 */  addiu     $s5, $sp, 0x18
/* DEFBFC 80240D5C AFA30028 */  sw        $v1, 0x28($sp)
/* DEFC00 80240D60 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DEFC04 80240D64 3C014282 */  lui       $at, 0x4282
/* DEFC08 80240D68 44810000 */  mtc1      $at, $f0
/* DEFC0C 80240D6C 8C63002C */  lw        $v1, 0x2c($v1)
/* DEFC10 80240D70 0040A02D */  daddu     $s4, $v0, $zero
/* DEFC14 80240D74 E7A00030 */  swc1      $f0, 0x30($sp)
/* DEFC18 80240D78 A7A00034 */  sh        $zero, 0x34($sp)
/* DEFC1C 80240D7C 16000005 */  bnez      $s0, .L80240D94
/* DEFC20 80240D80 AFA3002C */   sw       $v1, 0x2c($sp)
/* DEFC24 80240D84 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DEFC28 80240D88 30420004 */  andi      $v0, $v0, 4
/* DEFC2C 80240D8C 10400044 */  beqz      $v0, .L80240EA0
/* DEFC30 80240D90 00000000 */   nop      
.L80240D94:
/* DEFC34 80240D94 2404F7FF */  addiu     $a0, $zero, -0x801
/* DEFC38 80240D98 AE600070 */  sw        $zero, 0x70($s3)
/* DEFC3C 80240D9C A640008E */  sh        $zero, 0x8e($s2)
/* DEFC40 80240DA0 8E2200CC */  lw        $v0, 0xcc($s1)
/* DEFC44 80240DA4 8E430000 */  lw        $v1, ($s2)
/* DEFC48 80240DA8 8C420000 */  lw        $v0, ($v0)
/* DEFC4C 80240DAC 00641824 */  and       $v1, $v1, $a0
/* DEFC50 80240DB0 AE430000 */  sw        $v1, ($s2)
/* DEFC54 80240DB4 AE420028 */  sw        $v0, 0x28($s2)
/* DEFC58 80240DB8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DEFC5C 80240DBC 8C420034 */  lw        $v0, 0x34($v0)
/* DEFC60 80240DC0 54400005 */  bnel      $v0, $zero, .L80240DD8
/* DEFC64 80240DC4 2402FDFF */   addiu    $v0, $zero, -0x201
/* DEFC68 80240DC8 34620200 */  ori       $v0, $v1, 0x200
/* DEFC6C 80240DCC 2403FFF7 */  addiu     $v1, $zero, -9
/* DEFC70 80240DD0 08090378 */  j         .L80240DE0
/* DEFC74 80240DD4 00431024 */   and      $v0, $v0, $v1
.L80240DD8:
/* DEFC78 80240DD8 00621024 */  and       $v0, $v1, $v0
/* DEFC7C 80240DDC 34420008 */  ori       $v0, $v0, 8
.L80240DE0:
/* DEFC80 80240DE0 AE420000 */  sw        $v0, ($s2)
/* DEFC84 80240DE4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DEFC88 80240DE8 30420004 */  andi      $v0, $v0, 4
/* DEFC8C 80240DEC 10400004 */  beqz      $v0, .L80240E00
/* DEFC90 80240DF0 24020063 */   addiu    $v0, $zero, 0x63
/* DEFC94 80240DF4 AE620070 */  sw        $v0, 0x70($s3)
/* DEFC98 80240DF8 08090386 */  j         .L80240E18
/* DEFC9C 80240DFC AE600074 */   sw       $zero, 0x74($s3)
.L80240E00:
/* DEFCA0 80240E00 8E220000 */  lw        $v0, ($s1)
/* DEFCA4 80240E04 3C034000 */  lui       $v1, 0x4000
/* DEFCA8 80240E08 00431024 */  and       $v0, $v0, $v1
/* DEFCAC 80240E0C 10400002 */  beqz      $v0, .L80240E18
/* DEFCB0 80240E10 2402000C */   addiu    $v0, $zero, 0xc
/* DEFCB4 80240E14 AE620070 */  sw        $v0, 0x70($s3)
.L80240E18:
/* DEFCB8 80240E18 3C06BFFF */  lui       $a2, 0xbfff
/* DEFCBC 80240E1C 34C6FFFF */  ori       $a2, $a2, 0xffff
/* DEFCC0 80240E20 27A50038 */  addiu     $a1, $sp, 0x38
/* DEFCC4 80240E24 2404FFFB */  addiu     $a0, $zero, -5
/* DEFCC8 80240E28 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DEFCCC 80240E2C 8E230000 */  lw        $v1, ($s1)
/* DEFCD0 80240E30 3C0142C8 */  lui       $at, 0x42c8
/* DEFCD4 80240E34 44810000 */  mtc1      $at, $f0
/* DEFCD8 80240E38 00441024 */  and       $v0, $v0, $a0
/* DEFCDC 80240E3C 00661824 */  and       $v1, $v1, $a2
/* DEFCE0 80240E40 AE2200B0 */  sw        $v0, 0xb0($s1)
/* DEFCE4 80240E44 AE230000 */  sw        $v1, ($s1)
/* DEFCE8 80240E48 864200A8 */  lh        $v0, 0xa8($s2)
/* DEFCEC 80240E4C 27A70040 */  addiu     $a3, $sp, 0x40
/* DEFCF0 80240E50 E7A00044 */  swc1      $f0, 0x44($sp)
/* DEFCF4 80240E54 C6460038 */  lwc1      $f6, 0x38($s2)
/* DEFCF8 80240E58 C640003C */  lwc1      $f0, 0x3c($s2)
/* DEFCFC 80240E5C C6420040 */  lwc1      $f2, 0x40($s2)
/* DEFD00 80240E60 44822000 */  mtc1      $v0, $f4
/* DEFD04 80240E64 00000000 */  nop       
/* DEFD08 80240E68 46802120 */  cvt.s.w   $f4, $f4
/* DEFD0C 80240E6C 27A20044 */  addiu     $v0, $sp, 0x44
/* DEFD10 80240E70 46040000 */  add.s     $f0, $f0, $f4
/* DEFD14 80240E74 E7A60038 */  swc1      $f6, 0x38($sp)
/* DEFD18 80240E78 E7A20040 */  swc1      $f2, 0x40($sp)
/* DEFD1C 80240E7C E7A0003C */  swc1      $f0, 0x3c($sp)
/* DEFD20 80240E80 AFA20010 */  sw        $v0, 0x10($sp)
/* DEFD24 80240E84 8E440080 */  lw        $a0, 0x80($s2)
/* DEFD28 80240E88 0C0372DF */  jal       func_800DCB7C
/* DEFD2C 80240E8C 27A6003C */   addiu    $a2, $sp, 0x3c
/* DEFD30 80240E90 10400003 */  beqz      $v0, .L80240EA0
/* DEFD34 80240E94 00000000 */   nop      
/* DEFD38 80240E98 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* DEFD3C 80240E9C E640003C */  swc1      $f0, 0x3c($s2)
.L80240EA0:
/* DEFD40 80240EA0 8E630070 */  lw        $v1, 0x70($s3)
/* DEFD44 80240EA4 2C620064 */  sltiu     $v0, $v1, 0x64
/* DEFD48 80240EA8 10400038 */  beqz      $v0, .L80240F8C
/* DEFD4C 80240EAC 00031080 */   sll      $v0, $v1, 2
/* DEFD50 80240EB0 3C018024 */  lui       $at, 0x8024
/* DEFD54 80240EB4 00220821 */  addu      $at, $at, $v0
/* DEFD58 80240EB8 8C2277C0 */  lw        $v0, 0x77c0($at)
/* DEFD5C 80240EBC 00400008 */  jr        $v0
/* DEFD60 80240EC0 00000000 */   nop      
/* DEFD64 80240EC4 0260202D */  daddu     $a0, $s3, $zero
/* DEFD68 80240EC8 0280282D */  daddu     $a1, $s4, $zero
/* DEFD6C 80240ECC 0C012568 */  jal       func_800495A0
/* DEFD70 80240ED0 02A0302D */   daddu    $a2, $s5, $zero
/* DEFD74 80240ED4 0260202D */  daddu     $a0, $s3, $zero
/* DEFD78 80240ED8 0280282D */  daddu     $a1, $s4, $zero
/* DEFD7C 80240EDC 0C0125AE */  jal       func_800496B8
/* DEFD80 80240EE0 02A0302D */   daddu    $a2, $s5, $zero
/* DEFD84 80240EE4 080903E3 */  j         .L80240F8C
/* DEFD88 80240EE8 00000000 */   nop      
/* DEFD8C 80240EEC 0260202D */  daddu     $a0, $s3, $zero
/* DEFD90 80240EF0 0280282D */  daddu     $a1, $s4, $zero
/* DEFD94 80240EF4 0C0902B3 */  jal       func_80240ACC
/* DEFD98 80240EF8 02A0302D */   daddu    $a2, $s5, $zero
/* DEFD9C 80240EFC 0260202D */  daddu     $a0, $s3, $zero
/* DEFDA0 80240F00 0280282D */  daddu     $a1, $s4, $zero
/* DEFDA4 80240F04 0C0902C7 */  jal       func_80240B1C
/* DEFDA8 80240F08 02A0302D */   daddu    $a2, $s5, $zero
/* DEFDAC 80240F0C 080903E3 */  j         .L80240F8C
/* DEFDB0 80240F10 00000000 */   nop      
/* DEFDB4 80240F14 0260202D */  daddu     $a0, $s3, $zero
/* DEFDB8 80240F18 0280282D */  daddu     $a1, $s4, $zero
/* DEFDBC 80240F1C 0C01278F */  jal       func_80049E3C
/* DEFDC0 80240F20 02A0302D */   daddu    $a2, $s5, $zero
/* DEFDC4 80240F24 0260202D */  daddu     $a0, $s3, $zero
/* DEFDC8 80240F28 0280282D */  daddu     $a1, $s4, $zero
/* DEFDCC 80240F2C 0C0127B3 */  jal       func_80049ECC
/* DEFDD0 80240F30 02A0302D */   daddu    $a2, $s5, $zero
/* DEFDD4 80240F34 080903E3 */  j         .L80240F8C
/* DEFDD8 80240F38 00000000 */   nop      
/* DEFDDC 80240F3C 0260202D */  daddu     $a0, $s3, $zero
/* DEFDE0 80240F40 0280282D */  daddu     $a1, $s4, $zero
/* DEFDE4 80240F44 0C0127DF */  jal       func_80049F7C
/* DEFDE8 80240F48 02A0302D */   daddu    $a2, $s5, $zero
/* DEFDEC 80240F4C 0260202D */  daddu     $a0, $s3, $zero
/* DEFDF0 80240F50 0280282D */  daddu     $a1, $s4, $zero
/* DEFDF4 80240F54 0C012849 */  jal       func_8004A124
/* DEFDF8 80240F58 02A0302D */   daddu    $a2, $s5, $zero
/* DEFDFC 80240F5C 8E630070 */  lw        $v1, 0x70($s3)
/* DEFE00 80240F60 2402000E */  addiu     $v0, $zero, 0xe
/* DEFE04 80240F64 14620009 */  bne       $v1, $v0, .L80240F8C
/* DEFE08 80240F68 00000000 */   nop      
/* DEFE0C 80240F6C 0260202D */  daddu     $a0, $s3, $zero
/* DEFE10 80240F70 0280282D */  daddu     $a1, $s4, $zero
/* DEFE14 80240F74 0C0128FA */  jal       func_8004A3E8
/* DEFE18 80240F78 02A0302D */   daddu    $a2, $s5, $zero
/* DEFE1C 80240F7C 080903E3 */  j         .L80240F8C
/* DEFE20 80240F80 00000000 */   nop      
/* DEFE24 80240F84 0C0129CF */  jal       func_8004A73C
/* DEFE28 80240F88 0260202D */   daddu    $a0, $s3, $zero
.L80240F8C:
/* DEFE2C 80240F8C 8FBF0060 */  lw        $ra, 0x60($sp)
/* DEFE30 80240F90 8FB5005C */  lw        $s5, 0x5c($sp)
/* DEFE34 80240F94 8FB40058 */  lw        $s4, 0x58($sp)
/* DEFE38 80240F98 8FB30054 */  lw        $s3, 0x54($sp)
/* DEFE3C 80240F9C 8FB20050 */  lw        $s2, 0x50($sp)
/* DEFE40 80240FA0 8FB1004C */  lw        $s1, 0x4c($sp)
/* DEFE44 80240FA4 8FB00048 */  lw        $s0, 0x48($sp)
/* DEFE48 80240FA8 0000102D */  daddu     $v0, $zero, $zero
/* DEFE4C 80240FAC 03E00008 */  jr        $ra
/* DEFE50 80240FB0 27BD0068 */   addiu    $sp, $sp, 0x68
