.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D3C_BBDEDC
/* BBDEDC 80240D3C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BBDEE0 80240D40 AFB1001C */  sw        $s1, 0x1c($sp)
/* BBDEE4 80240D44 0080882D */  daddu     $s1, $a0, $zero
/* BBDEE8 80240D48 AFBF0034 */  sw        $ra, 0x34($sp)
/* BBDEEC 80240D4C AFB60030 */  sw        $s6, 0x30($sp)
/* BBDEF0 80240D50 AFB5002C */  sw        $s5, 0x2c($sp)
/* BBDEF4 80240D54 AFB40028 */  sw        $s4, 0x28($sp)
/* BBDEF8 80240D58 AFB30024 */  sw        $s3, 0x24($sp)
/* BBDEFC 80240D5C AFB20020 */  sw        $s2, 0x20($sp)
/* BBDF00 80240D60 AFB00018 */  sw        $s0, 0x18($sp)
/* BBDF04 80240D64 F7B60040 */  sdc1      $f22, 0x40($sp)
/* BBDF08 80240D68 F7B40038 */  sdc1      $f20, 0x38($sp)
/* BBDF0C 80240D6C 8E30000C */  lw        $s0, 0xc($s1)
/* BBDF10 80240D70 8E160000 */  lw        $s6, ($s0)
/* BBDF14 80240D74 26100004 */  addiu     $s0, $s0, 4
/* BBDF18 80240D78 0C0B1EAF */  jal       get_variable
/* BBDF1C 80240D7C 02C0282D */   daddu    $a1, $s6, $zero
/* BBDF20 80240D80 44820000 */  mtc1      $v0, $f0
/* BBDF24 80240D84 00000000 */  nop       
/* BBDF28 80240D88 46800020 */  cvt.s.w   $f0, $f0
/* BBDF2C 80240D8C E7A00010 */  swc1      $f0, 0x10($sp)
/* BBDF30 80240D90 8E140000 */  lw        $s4, ($s0)
/* BBDF34 80240D94 26100004 */  addiu     $s0, $s0, 4
/* BBDF38 80240D98 0220202D */  daddu     $a0, $s1, $zero
/* BBDF3C 80240D9C 0C0B1EAF */  jal       get_variable
/* BBDF40 80240DA0 0280282D */   daddu    $a1, $s4, $zero
/* BBDF44 80240DA4 0220202D */  daddu     $a0, $s1, $zero
/* BBDF48 80240DA8 8E150000 */  lw        $s5, ($s0)
/* BBDF4C 80240DAC 4482B000 */  mtc1      $v0, $f22
/* BBDF50 80240DB0 00000000 */  nop       
/* BBDF54 80240DB4 4680B5A0 */  cvt.s.w   $f22, $f22
/* BBDF58 80240DB8 0C0B1EAF */  jal       get_variable
/* BBDF5C 80240DBC 02A0282D */   daddu    $a1, $s5, $zero
/* BBDF60 80240DC0 2404FFFC */  addiu     $a0, $zero, -4
/* BBDF64 80240DC4 44820000 */  mtc1      $v0, $f0
/* BBDF68 80240DC8 00000000 */  nop       
/* BBDF6C 80240DCC 46800020 */  cvt.s.w   $f0, $f0
/* BBDF70 80240DD0 0C00EABB */  jal       get_npc_unsafe
/* BBDF74 80240DD4 E7A00014 */   swc1     $f0, 0x14($sp)
/* BBDF78 80240DD8 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* BBDF7C 80240DDC 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* BBDF80 80240DE0 3C014334 */  lui       $at, 0x4334
/* BBDF84 80240DE4 44816000 */  mtc1      $at, $f12
/* BBDF88 80240DE8 00041880 */  sll       $v1, $a0, 2
/* BBDF8C 80240DEC 00641821 */  addu      $v1, $v1, $a0
/* BBDF90 80240DF0 00031880 */  sll       $v1, $v1, 2
/* BBDF94 80240DF4 00641823 */  subu      $v1, $v1, $a0
/* BBDF98 80240DF8 000320C0 */  sll       $a0, $v1, 3
/* BBDF9C 80240DFC 00641821 */  addu      $v1, $v1, $a0
/* BBDFA0 80240E00 000318C0 */  sll       $v1, $v1, 3
/* BBDFA4 80240E04 3C01800B */  lui       $at, 0x800b
/* BBDFA8 80240E08 00230821 */  addu      $at, $at, $v1
/* BBDFAC 80240E0C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* BBDFB0 80240E10 460C0300 */  add.s     $f12, $f0, $f12
/* BBDFB4 80240E14 0C00A6C9 */  jal       clamp_angle
/* BBDFB8 80240E18 0040982D */   daddu    $s3, $v0, $zero
/* BBDFBC 80240E1C 27B00010 */  addiu     $s0, $sp, 0x10
/* BBDFC0 80240E20 0200202D */  daddu     $a0, $s0, $zero
/* BBDFC4 80240E24 27B20014 */  addiu     $s2, $sp, 0x14
/* BBDFC8 80240E28 0240282D */  daddu     $a1, $s2, $zero
/* BBDFCC 80240E2C 3C064170 */  lui       $a2, 0x4170
/* BBDFD0 80240E30 8E67000C */  lw        $a3, 0xc($s3)
/* BBDFD4 80240E34 0C00A7E7 */  jal       add_vec2D_polar
/* BBDFD8 80240E38 46000506 */   mov.s    $f20, $f0
/* BBDFDC 80240E3C 0200202D */  daddu     $a0, $s0, $zero
/* BBDFE0 80240E40 3C064120 */  lui       $a2, 0x4120
/* BBDFE4 80240E44 4407A000 */  mfc1      $a3, $f20
/* BBDFE8 80240E48 0C00A7E7 */  jal       add_vec2D_polar
/* BBDFEC 80240E4C 0240282D */   daddu    $a1, $s2, $zero
/* BBDFF0 80240E50 0220202D */  daddu     $a0, $s1, $zero
/* BBDFF4 80240E54 C7A00010 */  lwc1      $f0, 0x10($sp)
/* BBDFF8 80240E58 4600008D */  trunc.w.s $f2, $f0
/* BBDFFC 80240E5C 44061000 */  mfc1      $a2, $f2
/* BBE000 80240E60 0C0B2026 */  jal       set_variable
/* BBE004 80240E64 02C0282D */   daddu    $a1, $s6, $zero
/* BBE008 80240E68 0220202D */  daddu     $a0, $s1, $zero
/* BBE00C 80240E6C 4600B08D */  trunc.w.s $f2, $f22
/* BBE010 80240E70 44061000 */  mfc1      $a2, $f2
/* BBE014 80240E74 0C0B2026 */  jal       set_variable
/* BBE018 80240E78 0280282D */   daddu    $a1, $s4, $zero
/* BBE01C 80240E7C 0220202D */  daddu     $a0, $s1, $zero
/* BBE020 80240E80 C7A00014 */  lwc1      $f0, 0x14($sp)
/* BBE024 80240E84 4600008D */  trunc.w.s $f2, $f0
/* BBE028 80240E88 44061000 */  mfc1      $a2, $f2
/* BBE02C 80240E8C 0C0B2026 */  jal       set_variable
/* BBE030 80240E90 02A0282D */   daddu    $a1, $s5, $zero
/* BBE034 80240E94 8FBF0034 */  lw        $ra, 0x34($sp)
/* BBE038 80240E98 8FB60030 */  lw        $s6, 0x30($sp)
/* BBE03C 80240E9C 8FB5002C */  lw        $s5, 0x2c($sp)
/* BBE040 80240EA0 8FB40028 */  lw        $s4, 0x28($sp)
/* BBE044 80240EA4 8FB30024 */  lw        $s3, 0x24($sp)
/* BBE048 80240EA8 8FB20020 */  lw        $s2, 0x20($sp)
/* BBE04C 80240EAC 8FB1001C */  lw        $s1, 0x1c($sp)
/* BBE050 80240EB0 8FB00018 */  lw        $s0, 0x18($sp)
/* BBE054 80240EB4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* BBE058 80240EB8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* BBE05C 80240EBC 24020002 */  addiu     $v0, $zero, 2
/* BBE060 80240EC0 03E00008 */  jr        $ra
/* BBE064 80240EC4 27BD0048 */   addiu    $sp, $sp, 0x48
