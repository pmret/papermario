.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80133FC8
/* CA6C8 80133FC8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CA6CC 80133FCC F7B80038 */  sdc1      $f24, 0x38($sp)
/* CA6D0 80133FD0 4486C000 */  mtc1      $a2, $f24
/* CA6D4 80133FD4 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* CA6D8 80133FD8 4487D000 */  mtc1      $a3, $f26
/* CA6DC 80133FDC F7B40028 */  sdc1      $f20, 0x28($sp)
/* CA6E0 80133FE0 46006506 */  mov.s     $f20, $f12
/* CA6E4 80133FE4 F7B60030 */  sdc1      $f22, 0x30($sp)
/* CA6E8 80133FE8 46007586 */  mov.s     $f22, $f14
/* CA6EC 80133FEC AFBF0020 */  sw        $ra, 0x20($sp)
/* CA6F0 80133FF0 AFB3001C */  sw        $s3, 0x1c($sp)
/* CA6F4 80133FF4 AFB20018 */  sw        $s2, 0x18($sp)
/* CA6F8 80133FF8 AFB10014 */  sw        $s1, 0x14($sp)
/* CA6FC 80133FFC 0C011052 */  jal       is_starting_conversation
/* CA700 80134000 AFB00010 */   sw       $s0, 0x10($sp)
/* CA704 80134004 14400045 */  bnez      $v0, .L8013411C
/* CA708 80134008 2402FFFF */   addiu    $v0, $zero, -1
/* CA70C 8013400C 3C028015 */  lui       $v0, %hi(D_801565A4)
/* CA710 80134010 844265A4 */  lh        $v0, %lo(D_801565A4)($v0)
/* CA714 80134014 14400041 */  bnez      $v0, .L8013411C
/* CA718 80134018 2402FFFF */   addiu    $v0, $zero, -1
/* CA71C 8013401C 0C009C64 */  jal       get_time_freeze_mode
/* CA720 80134020 00000000 */   nop
/* CA724 80134024 1440003D */  bnez      $v0, .L8013411C
/* CA728 80134028 2402FFFF */   addiu    $v0, $zero, -1
/* CA72C 8013402C 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* CA730 80134030 8C42A650 */  lw        $v0, %lo(gOverrideFlags)($v0)
/* CA734 80134034 3C030020 */  lui       $v1, 0x20
/* CA738 80134038 00431024 */  and       $v0, $v0, $v1
/* CA73C 8013403C 14400037 */  bnez      $v0, .L8013411C
/* CA740 80134040 2402FFFF */   addiu    $v0, $zero, -1
/* CA744 80134044 0000802D */  daddu     $s0, $zero, $zero
/* CA748 80134048 24130001 */  addiu     $s3, $zero, 1
/* CA74C 8013404C 24120002 */  addiu     $s2, $zero, 2
/* CA750 80134050 3C110020 */  lui       $s1, 0x20
.L80134054:
/* CA754 80134054 3C038015 */  lui       $v1, %hi(D_801565A0)
/* CA758 80134058 8C6365A0 */  lw        $v1, %lo(D_801565A0)($v1)
/* CA75C 8013405C 00101080 */  sll       $v0, $s0, 2
/* CA760 80134060 00431021 */  addu      $v0, $v0, $v1
/* CA764 80134064 8C440000 */  lw        $a0, ($v0)
/* CA768 80134068 50800029 */  beql      $a0, $zero, .L80134110
/* CA76C 8013406C 26100001 */   addiu    $s0, $s0, 1
/* CA770 80134070 8C830000 */  lw        $v1, ($a0)
/* CA774 80134074 50600026 */  beql      $v1, $zero, .L80134110
/* CA778 80134078 26100001 */   addiu    $s0, $s0, 1
/* CA77C 8013407C 8082001B */  lb        $v0, 0x1b($a0)
/* CA780 80134080 50530023 */  beql      $v0, $s3, .L80134110
/* CA784 80134084 26100001 */   addiu    $s0, $s0, 1
/* CA788 80134088 50520021 */  beql      $v0, $s2, .L80134110
/* CA78C 8013408C 26100001 */   addiu    $s0, $s0, 1
/* CA790 80134090 30620040 */  andi      $v0, $v1, 0x40
/* CA794 80134094 5440001E */  bnel      $v0, $zero, .L80134110
/* CA798 80134098 26100001 */   addiu    $s0, $s0, 1
/* CA79C 8013409C 00711024 */  and       $v0, $v1, $s1
/* CA7A0 801340A0 5440001B */  bnel      $v0, $zero, .L80134110
/* CA7A4 801340A4 26100001 */   addiu    $s0, $s0, 1
/* CA7A8 801340A8 C4800008 */  lwc1      $f0, 8($a0)
/* CA7AC 801340AC 46140001 */  sub.s     $f0, $f0, $f20
/* CA7B0 801340B0 46000002 */  mul.s     $f0, $f0, $f0
/* CA7B4 801340B4 00000000 */  nop
/* CA7B8 801340B8 C484000C */  lwc1      $f4, 0xc($a0)
/* CA7BC 801340BC 46162101 */  sub.s     $f4, $f4, $f22
/* CA7C0 801340C0 46042102 */  mul.s     $f4, $f4, $f4
/* CA7C4 801340C4 00000000 */  nop
/* CA7C8 801340C8 C4820010 */  lwc1      $f2, 0x10($a0)
/* CA7CC 801340CC 46181081 */  sub.s     $f2, $f2, $f24
/* CA7D0 801340D0 46021082 */  mul.s     $f2, $f2, $f2
/* CA7D4 801340D4 00000000 */  nop
/* CA7D8 801340D8 46040000 */  add.s     $f0, $f0, $f4
/* CA7DC 801340DC 46020300 */  add.s     $f12, $f0, $f2
/* CA7E0 801340E0 46006004 */  sqrt.s    $f0, $f12
/* CA7E4 801340E4 46000032 */  c.eq.s    $f0, $f0
/* CA7E8 801340E8 00000000 */  nop
/* CA7EC 801340EC 45010003 */  bc1t      .L801340FC
/* CA7F0 801340F0 00000000 */   nop
/* CA7F4 801340F4 0C0187BC */  jal       sqrtf
/* CA7F8 801340F8 00000000 */   nop
.L801340FC:
/* CA7FC 801340FC 461A003C */  c.lt.s    $f0, $f26
/* CA800 80134100 00000000 */  nop
/* CA804 80134104 45010005 */  bc1t      .L8013411C
/* CA808 80134108 0200102D */   daddu    $v0, $s0, $zero
/* CA80C 8013410C 26100001 */  addiu     $s0, $s0, 1
.L80134110:
/* CA810 80134110 2A020100 */  slti      $v0, $s0, 0x100
/* CA814 80134114 1440FFCF */  bnez      $v0, .L80134054
/* CA818 80134118 2402FFFF */   addiu    $v0, $zero, -1
.L8013411C:
/* CA81C 8013411C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CA820 80134120 8FB3001C */  lw        $s3, 0x1c($sp)
/* CA824 80134124 8FB20018 */  lw        $s2, 0x18($sp)
/* CA828 80134128 8FB10014 */  lw        $s1, 0x14($sp)
/* CA82C 8013412C 8FB00010 */  lw        $s0, 0x10($sp)
/* CA830 80134130 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* CA834 80134134 D7B80038 */  ldc1      $f24, 0x38($sp)
/* CA838 80134138 D7B60030 */  ldc1      $f22, 0x30($sp)
/* CA83C 8013413C D7B40028 */  ldc1      $f20, 0x28($sp)
/* CA840 80134140 03E00008 */  jr        $ra
/* CA844 80134144 27BD0048 */   addiu    $sp, $sp, 0x48
