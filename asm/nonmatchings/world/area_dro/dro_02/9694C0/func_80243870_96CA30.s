.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243870_96CA30
/* 96CA30 80243870 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 96CA34 80243874 AFB1001C */  sw        $s1, 0x1c($sp)
/* 96CA38 80243878 0080882D */  daddu     $s1, $a0, $zero
/* 96CA3C 8024387C AFBF0034 */  sw        $ra, 0x34($sp)
/* 96CA40 80243880 AFB60030 */  sw        $s6, 0x30($sp)
/* 96CA44 80243884 AFB5002C */  sw        $s5, 0x2c($sp)
/* 96CA48 80243888 AFB40028 */  sw        $s4, 0x28($sp)
/* 96CA4C 8024388C AFB30024 */  sw        $s3, 0x24($sp)
/* 96CA50 80243890 AFB20020 */  sw        $s2, 0x20($sp)
/* 96CA54 80243894 AFB00018 */  sw        $s0, 0x18($sp)
/* 96CA58 80243898 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 96CA5C 8024389C F7B40038 */  sdc1      $f20, 0x38($sp)
/* 96CA60 802438A0 8E30000C */  lw        $s0, 0xc($s1)
/* 96CA64 802438A4 8E160000 */  lw        $s6, ($s0)
/* 96CA68 802438A8 26100004 */  addiu     $s0, $s0, 4
/* 96CA6C 802438AC 0C0B1EAF */  jal       get_variable
/* 96CA70 802438B0 02C0282D */   daddu    $a1, $s6, $zero
/* 96CA74 802438B4 44820000 */  mtc1      $v0, $f0
/* 96CA78 802438B8 00000000 */  nop       
/* 96CA7C 802438BC 46800020 */  cvt.s.w   $f0, $f0
/* 96CA80 802438C0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 96CA84 802438C4 8E140000 */  lw        $s4, ($s0)
/* 96CA88 802438C8 26100004 */  addiu     $s0, $s0, 4
/* 96CA8C 802438CC 0220202D */  daddu     $a0, $s1, $zero
/* 96CA90 802438D0 0C0B1EAF */  jal       get_variable
/* 96CA94 802438D4 0280282D */   daddu    $a1, $s4, $zero
/* 96CA98 802438D8 0220202D */  daddu     $a0, $s1, $zero
/* 96CA9C 802438DC 8E150000 */  lw        $s5, ($s0)
/* 96CAA0 802438E0 4482B000 */  mtc1      $v0, $f22
/* 96CAA4 802438E4 00000000 */  nop       
/* 96CAA8 802438E8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 96CAAC 802438EC 0C0B1EAF */  jal       get_variable
/* 96CAB0 802438F0 02A0282D */   daddu    $a1, $s5, $zero
/* 96CAB4 802438F4 2404FFFC */  addiu     $a0, $zero, -4
/* 96CAB8 802438F8 44820000 */  mtc1      $v0, $f0
/* 96CABC 802438FC 00000000 */  nop       
/* 96CAC0 80243900 46800020 */  cvt.s.w   $f0, $f0
/* 96CAC4 80243904 0C00EABB */  jal       get_npc_unsafe
/* 96CAC8 80243908 E7A00014 */   swc1     $f0, 0x14($sp)
/* 96CACC 8024390C 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 96CAD0 80243910 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 96CAD4 80243914 3C014334 */  lui       $at, 0x4334
/* 96CAD8 80243918 44816000 */  mtc1      $at, $f12
/* 96CADC 8024391C 00041880 */  sll       $v1, $a0, 2
/* 96CAE0 80243920 00641821 */  addu      $v1, $v1, $a0
/* 96CAE4 80243924 00031880 */  sll       $v1, $v1, 2
/* 96CAE8 80243928 00641823 */  subu      $v1, $v1, $a0
/* 96CAEC 8024392C 000320C0 */  sll       $a0, $v1, 3
/* 96CAF0 80243930 00641821 */  addu      $v1, $v1, $a0
/* 96CAF4 80243934 000318C0 */  sll       $v1, $v1, 3
/* 96CAF8 80243938 3C01800B */  lui       $at, 0x800b
/* 96CAFC 8024393C 00230821 */  addu      $at, $at, $v1
/* 96CB00 80243940 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 96CB04 80243944 460C0300 */  add.s     $f12, $f0, $f12
/* 96CB08 80243948 0C00A6C9 */  jal       clamp_angle
/* 96CB0C 8024394C 0040982D */   daddu    $s3, $v0, $zero
/* 96CB10 80243950 27B00010 */  addiu     $s0, $sp, 0x10
/* 96CB14 80243954 0200202D */  daddu     $a0, $s0, $zero
/* 96CB18 80243958 27B20014 */  addiu     $s2, $sp, 0x14
/* 96CB1C 8024395C 0240282D */  daddu     $a1, $s2, $zero
/* 96CB20 80243960 3C064170 */  lui       $a2, 0x4170
/* 96CB24 80243964 8E67000C */  lw        $a3, 0xc($s3)
/* 96CB28 80243968 0C00A7E7 */  jal       add_vec2D_polar
/* 96CB2C 8024396C 46000506 */   mov.s    $f20, $f0
/* 96CB30 80243970 0200202D */  daddu     $a0, $s0, $zero
/* 96CB34 80243974 3C064120 */  lui       $a2, 0x4120
/* 96CB38 80243978 4407A000 */  mfc1      $a3, $f20
/* 96CB3C 8024397C 0C00A7E7 */  jal       add_vec2D_polar
/* 96CB40 80243980 0240282D */   daddu    $a1, $s2, $zero
/* 96CB44 80243984 0220202D */  daddu     $a0, $s1, $zero
/* 96CB48 80243988 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 96CB4C 8024398C 4600008D */  trunc.w.s $f2, $f0
/* 96CB50 80243990 44061000 */  mfc1      $a2, $f2
/* 96CB54 80243994 0C0B2026 */  jal       set_variable
/* 96CB58 80243998 02C0282D */   daddu    $a1, $s6, $zero
/* 96CB5C 8024399C 0220202D */  daddu     $a0, $s1, $zero
/* 96CB60 802439A0 4600B08D */  trunc.w.s $f2, $f22
/* 96CB64 802439A4 44061000 */  mfc1      $a2, $f2
/* 96CB68 802439A8 0C0B2026 */  jal       set_variable
/* 96CB6C 802439AC 0280282D */   daddu    $a1, $s4, $zero
/* 96CB70 802439B0 0220202D */  daddu     $a0, $s1, $zero
/* 96CB74 802439B4 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 96CB78 802439B8 4600008D */  trunc.w.s $f2, $f0
/* 96CB7C 802439BC 44061000 */  mfc1      $a2, $f2
/* 96CB80 802439C0 0C0B2026 */  jal       set_variable
/* 96CB84 802439C4 02A0282D */   daddu    $a1, $s5, $zero
/* 96CB88 802439C8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 96CB8C 802439CC 8FB60030 */  lw        $s6, 0x30($sp)
/* 96CB90 802439D0 8FB5002C */  lw        $s5, 0x2c($sp)
/* 96CB94 802439D4 8FB40028 */  lw        $s4, 0x28($sp)
/* 96CB98 802439D8 8FB30024 */  lw        $s3, 0x24($sp)
/* 96CB9C 802439DC 8FB20020 */  lw        $s2, 0x20($sp)
/* 96CBA0 802439E0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 96CBA4 802439E4 8FB00018 */  lw        $s0, 0x18($sp)
/* 96CBA8 802439E8 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 96CBAC 802439EC D7B40038 */  ldc1      $f20, 0x38($sp)
/* 96CBB0 802439F0 24020002 */  addiu     $v0, $zero, 2
/* 96CBB4 802439F4 03E00008 */  jr        $ra
/* 96CBB8 802439F8 27BD0048 */   addiu    $sp, $sp, 0x48
