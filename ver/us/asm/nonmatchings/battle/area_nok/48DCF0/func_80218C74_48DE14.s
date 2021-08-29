.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218C74_48DE14
/* 48DE14 80218C74 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 48DE18 80218C78 AFB10014 */  sw        $s1, 0x14($sp)
/* 48DE1C 80218C7C 0080882D */  daddu     $s1, $a0, $zero
/* 48DE20 80218C80 AFBF0024 */  sw        $ra, 0x24($sp)
/* 48DE24 80218C84 AFB40020 */  sw        $s4, 0x20($sp)
/* 48DE28 80218C88 AFB3001C */  sw        $s3, 0x1c($sp)
/* 48DE2C 80218C8C AFB20018 */  sw        $s2, 0x18($sp)
/* 48DE30 80218C90 AFB00010 */  sw        $s0, 0x10($sp)
/* 48DE34 80218C94 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 48DE38 80218C98 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 48DE3C 80218C9C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 48DE40 80218CA0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 48DE44 80218CA4 8E30000C */  lw        $s0, 0xc($s1)
/* 48DE48 80218CA8 8E050000 */  lw        $a1, ($s0)
/* 48DE4C 80218CAC 0C0B1EAF */  jal       get_variable
/* 48DE50 80218CB0 26100004 */   addiu    $s0, $s0, 4
/* 48DE54 80218CB4 0220202D */  daddu     $a0, $s1, $zero
/* 48DE58 80218CB8 8E050000 */  lw        $a1, ($s0)
/* 48DE5C 80218CBC 0C0B1EAF */  jal       get_variable
/* 48DE60 80218CC0 0040902D */   daddu    $s2, $v0, $zero
/* 48DE64 80218CC4 24040168 */  addiu     $a0, $zero, 0x168
/* 48DE68 80218CC8 0C00A67F */  jal       rand_int
/* 48DE6C 80218CCC 0040982D */   daddu    $s3, $v0, $zero
/* 48DE70 80218CD0 4482B000 */  mtc1      $v0, $f22
/* 48DE74 80218CD4 00000000 */  nop
/* 48DE78 80218CD8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 48DE7C 80218CDC 3C014238 */  lui       $at, 0x4238
/* 48DE80 80218CE0 4481C000 */  mtc1      $at, $f24
/* 48DE84 80218CE4 0C00A8D4 */  jal       cos_deg
/* 48DE88 80218CE8 4600B306 */   mov.s    $f12, $f22
/* 48DE8C 80218CEC 46180002 */  mul.s     $f0, $f0, $f24
/* 48DE90 80218CF0 00000000 */  nop
/* 48DE94 80218CF4 4492A000 */  mtc1      $s2, $f20
/* 48DE98 80218CF8 00000000 */  nop
/* 48DE9C 80218CFC 4680A520 */  cvt.s.w   $f20, $f20
/* 48DEA0 80218D00 4600A000 */  add.s     $f0, $f20, $f0
/* 48DEA4 80218D04 4600008D */  trunc.w.s $f2, $f0
/* 48DEA8 80218D08 44121000 */  mfc1      $s2, $f2
/* 48DEAC 80218D0C 0C00A8BB */  jal       sin_deg
/* 48DEB0 80218D10 4600B306 */   mov.s    $f12, $f22
/* 48DEB4 80218D14 46180002 */  mul.s     $f0, $f0, $f24
/* 48DEB8 80218D18 00000000 */  nop
/* 48DEBC 80218D1C 4493C000 */  mtc1      $s3, $f24
/* 48DEC0 80218D20 00000000 */  nop
/* 48DEC4 80218D24 4680C620 */  cvt.s.w   $f24, $f24
/* 48DEC8 80218D28 4600C000 */  add.s     $f0, $f24, $f0
/* 48DECC 80218D2C 3C014278 */  lui       $at, 0x4278
/* 48DED0 80218D30 4481D000 */  mtc1      $at, $f26
/* 48DED4 80218D34 4600008D */  trunc.w.s $f2, $f0
/* 48DED8 80218D38 44131000 */  mfc1      $s3, $f2
/* 48DEDC 80218D3C 0C00A8D4 */  jal       cos_deg
/* 48DEE0 80218D40 4600B306 */   mov.s    $f12, $f22
/* 48DEE4 80218D44 461A0002 */  mul.s     $f0, $f0, $f26
/* 48DEE8 80218D48 00000000 */  nop
/* 48DEEC 80218D4C 4600A500 */  add.s     $f20, $f20, $f0
/* 48DEF0 80218D50 4600A08D */  trunc.w.s $f2, $f20
/* 48DEF4 80218D54 44141000 */  mfc1      $s4, $f2
/* 48DEF8 80218D58 0C00A8BB */  jal       sin_deg
/* 48DEFC 80218D5C 4600B306 */   mov.s    $f12, $f22
/* 48DF00 80218D60 461A0002 */  mul.s     $f0, $f0, $f26
/* 48DF04 80218D64 00000000 */  nop
/* 48DF08 80218D68 26100004 */  addiu     $s0, $s0, 4
/* 48DF0C 80218D6C 8E050000 */  lw        $a1, ($s0)
/* 48DF10 80218D70 26100004 */  addiu     $s0, $s0, 4
/* 48DF14 80218D74 4600C600 */  add.s     $f24, $f24, $f0
/* 48DF18 80218D78 0240302D */  daddu     $a2, $s2, $zero
/* 48DF1C 80218D7C 4600C08D */  trunc.w.s $f2, $f24
/* 48DF20 80218D80 44121000 */  mfc1      $s2, $f2
/* 48DF24 80218D84 0C0B2026 */  jal       evt_set_variable
/* 48DF28 80218D88 0220202D */   daddu    $a0, $s1, $zero
/* 48DF2C 80218D8C 8E050000 */  lw        $a1, ($s0)
/* 48DF30 80218D90 26100004 */  addiu     $s0, $s0, 4
/* 48DF34 80218D94 0220202D */  daddu     $a0, $s1, $zero
/* 48DF38 80218D98 0C0B2026 */  jal       evt_set_variable
/* 48DF3C 80218D9C 0260302D */   daddu    $a2, $s3, $zero
/* 48DF40 80218DA0 8E050000 */  lw        $a1, ($s0)
/* 48DF44 80218DA4 26100004 */  addiu     $s0, $s0, 4
/* 48DF48 80218DA8 0220202D */  daddu     $a0, $s1, $zero
/* 48DF4C 80218DAC 0C0B2026 */  jal       evt_set_variable
/* 48DF50 80218DB0 0280302D */   daddu    $a2, $s4, $zero
/* 48DF54 80218DB4 0220202D */  daddu     $a0, $s1, $zero
/* 48DF58 80218DB8 8E050000 */  lw        $a1, ($s0)
/* 48DF5C 80218DBC 0C0B2026 */  jal       evt_set_variable
/* 48DF60 80218DC0 0240302D */   daddu    $a2, $s2, $zero
/* 48DF64 80218DC4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 48DF68 80218DC8 8FB40020 */  lw        $s4, 0x20($sp)
/* 48DF6C 80218DCC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 48DF70 80218DD0 8FB20018 */  lw        $s2, 0x18($sp)
/* 48DF74 80218DD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 48DF78 80218DD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 48DF7C 80218DDC D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 48DF80 80218DE0 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 48DF84 80218DE4 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 48DF88 80218DE8 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 48DF8C 80218DEC 24020002 */  addiu     $v0, $zero, 2
/* 48DF90 80218DF0 03E00008 */  jr        $ra
/* 48DF94 80218DF4 27BD0048 */   addiu    $sp, $sp, 0x48
