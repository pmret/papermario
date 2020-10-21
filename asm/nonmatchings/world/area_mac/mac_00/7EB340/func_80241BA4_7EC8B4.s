.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BA4_7EC8B4
/* 7EC8B4 80241BA4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7EC8B8 80241BA8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7EC8BC 80241BAC 0080882D */  daddu     $s1, $a0, $zero
/* 7EC8C0 80241BB0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 7EC8C4 80241BB4 AFB60030 */  sw        $s6, 0x30($sp)
/* 7EC8C8 80241BB8 AFB5002C */  sw        $s5, 0x2c($sp)
/* 7EC8CC 80241BBC AFB40028 */  sw        $s4, 0x28($sp)
/* 7EC8D0 80241BC0 AFB30024 */  sw        $s3, 0x24($sp)
/* 7EC8D4 80241BC4 AFB20020 */  sw        $s2, 0x20($sp)
/* 7EC8D8 80241BC8 AFB00018 */  sw        $s0, 0x18($sp)
/* 7EC8DC 80241BCC F7B60040 */  sdc1      $f22, 0x40($sp)
/* 7EC8E0 80241BD0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 7EC8E4 80241BD4 8E30000C */  lw        $s0, 0xc($s1)
/* 7EC8E8 80241BD8 8E160000 */  lw        $s6, ($s0)
/* 7EC8EC 80241BDC 26100004 */  addiu     $s0, $s0, 4
/* 7EC8F0 80241BE0 0C0B1EAF */  jal       get_variable
/* 7EC8F4 80241BE4 02C0282D */   daddu    $a1, $s6, $zero
/* 7EC8F8 80241BE8 44820000 */  mtc1      $v0, $f0
/* 7EC8FC 80241BEC 00000000 */  nop       
/* 7EC900 80241BF0 46800020 */  cvt.s.w   $f0, $f0
/* 7EC904 80241BF4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 7EC908 80241BF8 8E140000 */  lw        $s4, ($s0)
/* 7EC90C 80241BFC 26100004 */  addiu     $s0, $s0, 4
/* 7EC910 80241C00 0220202D */  daddu     $a0, $s1, $zero
/* 7EC914 80241C04 0C0B1EAF */  jal       get_variable
/* 7EC918 80241C08 0280282D */   daddu    $a1, $s4, $zero
/* 7EC91C 80241C0C 0220202D */  daddu     $a0, $s1, $zero
/* 7EC920 80241C10 8E150000 */  lw        $s5, ($s0)
/* 7EC924 80241C14 4482B000 */  mtc1      $v0, $f22
/* 7EC928 80241C18 00000000 */  nop       
/* 7EC92C 80241C1C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 7EC930 80241C20 0C0B1EAF */  jal       get_variable
/* 7EC934 80241C24 02A0282D */   daddu    $a1, $s5, $zero
/* 7EC938 80241C28 2404FFFC */  addiu     $a0, $zero, -4
/* 7EC93C 80241C2C 44820000 */  mtc1      $v0, $f0
/* 7EC940 80241C30 00000000 */  nop       
/* 7EC944 80241C34 46800020 */  cvt.s.w   $f0, $f0
/* 7EC948 80241C38 0C00EABB */  jal       get_npc_unsafe
/* 7EC94C 80241C3C E7A00014 */   swc1     $f0, 0x14($sp)
/* 7EC950 80241C40 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 7EC954 80241C44 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 7EC958 80241C48 3C014334 */  lui       $at, 0x4334
/* 7EC95C 80241C4C 44816000 */  mtc1      $at, $f12
/* 7EC960 80241C50 00041880 */  sll       $v1, $a0, 2
/* 7EC964 80241C54 00641821 */  addu      $v1, $v1, $a0
/* 7EC968 80241C58 00031880 */  sll       $v1, $v1, 2
/* 7EC96C 80241C5C 00641823 */  subu      $v1, $v1, $a0
/* 7EC970 80241C60 000320C0 */  sll       $a0, $v1, 3
/* 7EC974 80241C64 00641821 */  addu      $v1, $v1, $a0
/* 7EC978 80241C68 000318C0 */  sll       $v1, $v1, 3
/* 7EC97C 80241C6C 3C01800B */  lui       $at, 0x800b
/* 7EC980 80241C70 00230821 */  addu      $at, $at, $v1
/* 7EC984 80241C74 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 7EC988 80241C78 460C0300 */  add.s     $f12, $f0, $f12
/* 7EC98C 80241C7C 0C00A6C9 */  jal       clamp_angle
/* 7EC990 80241C80 0040982D */   daddu    $s3, $v0, $zero
/* 7EC994 80241C84 27B00010 */  addiu     $s0, $sp, 0x10
/* 7EC998 80241C88 0200202D */  daddu     $a0, $s0, $zero
/* 7EC99C 80241C8C 27B20014 */  addiu     $s2, $sp, 0x14
/* 7EC9A0 80241C90 0240282D */  daddu     $a1, $s2, $zero
/* 7EC9A4 80241C94 3C064170 */  lui       $a2, 0x4170
/* 7EC9A8 80241C98 8E67000C */  lw        $a3, 0xc($s3)
/* 7EC9AC 80241C9C 0C00A7E7 */  jal       add_vec2D_polar
/* 7EC9B0 80241CA0 46000506 */   mov.s    $f20, $f0
/* 7EC9B4 80241CA4 0200202D */  daddu     $a0, $s0, $zero
/* 7EC9B8 80241CA8 3C064120 */  lui       $a2, 0x4120
/* 7EC9BC 80241CAC 4407A000 */  mfc1      $a3, $f20
/* 7EC9C0 80241CB0 0C00A7E7 */  jal       add_vec2D_polar
/* 7EC9C4 80241CB4 0240282D */   daddu    $a1, $s2, $zero
/* 7EC9C8 80241CB8 0220202D */  daddu     $a0, $s1, $zero
/* 7EC9CC 80241CBC C7A00010 */  lwc1      $f0, 0x10($sp)
/* 7EC9D0 80241CC0 4600008D */  trunc.w.s $f2, $f0
/* 7EC9D4 80241CC4 44061000 */  mfc1      $a2, $f2
/* 7EC9D8 80241CC8 0C0B2026 */  jal       set_variable
/* 7EC9DC 80241CCC 02C0282D */   daddu    $a1, $s6, $zero
/* 7EC9E0 80241CD0 0220202D */  daddu     $a0, $s1, $zero
/* 7EC9E4 80241CD4 4600B08D */  trunc.w.s $f2, $f22
/* 7EC9E8 80241CD8 44061000 */  mfc1      $a2, $f2
/* 7EC9EC 80241CDC 0C0B2026 */  jal       set_variable
/* 7EC9F0 80241CE0 0280282D */   daddu    $a1, $s4, $zero
/* 7EC9F4 80241CE4 0220202D */  daddu     $a0, $s1, $zero
/* 7EC9F8 80241CE8 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 7EC9FC 80241CEC 4600008D */  trunc.w.s $f2, $f0
/* 7ECA00 80241CF0 44061000 */  mfc1      $a2, $f2
/* 7ECA04 80241CF4 0C0B2026 */  jal       set_variable
/* 7ECA08 80241CF8 02A0282D */   daddu    $a1, $s5, $zero
/* 7ECA0C 80241CFC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 7ECA10 80241D00 8FB60030 */  lw        $s6, 0x30($sp)
/* 7ECA14 80241D04 8FB5002C */  lw        $s5, 0x2c($sp)
/* 7ECA18 80241D08 8FB40028 */  lw        $s4, 0x28($sp)
/* 7ECA1C 80241D0C 8FB30024 */  lw        $s3, 0x24($sp)
/* 7ECA20 80241D10 8FB20020 */  lw        $s2, 0x20($sp)
/* 7ECA24 80241D14 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7ECA28 80241D18 8FB00018 */  lw        $s0, 0x18($sp)
/* 7ECA2C 80241D1C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 7ECA30 80241D20 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 7ECA34 80241D24 24020002 */  addiu     $v0, $zero, 2
/* 7ECA38 80241D28 03E00008 */  jr        $ra
/* 7ECA3C 80241D2C 27BD0048 */   addiu    $sp, $sp, 0x48
