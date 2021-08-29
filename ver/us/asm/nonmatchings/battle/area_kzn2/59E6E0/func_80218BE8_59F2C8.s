.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218BE8_59F2C8
/* 59F2C8 80218BE8 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 59F2CC 80218BEC AFB20018 */  sw        $s2, 0x18($sp)
/* 59F2D0 80218BF0 0080902D */  daddu     $s2, $a0, $zero
/* 59F2D4 80218BF4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 59F2D8 80218BF8 AFB50024 */  sw        $s5, 0x24($sp)
/* 59F2DC 80218BFC AFB40020 */  sw        $s4, 0x20($sp)
/* 59F2E0 80218C00 AFB3001C */  sw        $s3, 0x1c($sp)
/* 59F2E4 80218C04 AFB10014 */  sw        $s1, 0x14($sp)
/* 59F2E8 80218C08 AFB00010 */  sw        $s0, 0x10($sp)
/* 59F2EC 80218C0C F7B60038 */  sdc1      $f22, 0x38($sp)
/* 59F2F0 80218C10 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 59F2F4 80218C14 8E50000C */  lw        $s0, 0xc($s2)
/* 59F2F8 80218C18 8E050000 */  lw        $a1, ($s0)
/* 59F2FC 80218C1C 0C0B1EAF */  jal       get_variable
/* 59F300 80218C20 26100004 */   addiu    $s0, $s0, 4
/* 59F304 80218C24 0040A82D */  daddu     $s5, $v0, $zero
/* 59F308 80218C28 8E050000 */  lw        $a1, ($s0)
/* 59F30C 80218C2C 26100004 */  addiu     $s0, $s0, 4
/* 59F310 80218C30 0C0B1EAF */  jal       get_variable
/* 59F314 80218C34 0240202D */   daddu    $a0, $s2, $zero
/* 59F318 80218C38 0040A02D */  daddu     $s4, $v0, $zero
/* 59F31C 80218C3C 8E050000 */  lw        $a1, ($s0)
/* 59F320 80218C40 26100004 */  addiu     $s0, $s0, 4
/* 59F324 80218C44 0C0B1EAF */  jal       get_variable
/* 59F328 80218C48 0240202D */   daddu    $a0, $s2, $zero
/* 59F32C 80218C4C 8E050000 */  lw        $a1, ($s0)
/* 59F330 80218C50 26100004 */  addiu     $s0, $s0, 4
/* 59F334 80218C54 4482B000 */  mtc1      $v0, $f22
/* 59F338 80218C58 00000000 */  nop
/* 59F33C 80218C5C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 59F340 80218C60 0C0B1EAF */  jal       get_variable
/* 59F344 80218C64 0240202D */   daddu    $a0, $s2, $zero
/* 59F348 80218C68 0240202D */  daddu     $a0, $s2, $zero
/* 59F34C 80218C6C 8E050000 */  lw        $a1, ($s0)
/* 59F350 80218C70 0C0B1EAF */  jal       get_variable
/* 59F354 80218C74 0040982D */   daddu    $s3, $v0, $zero
/* 59F358 80218C78 4600B306 */  mov.s     $f12, $f22
/* 59F35C 80218C7C 0C00A8D4 */  jal       cos_deg
/* 59F360 80218C80 0040882D */   daddu    $s1, $v0, $zero
/* 59F364 80218C84 4493A000 */  mtc1      $s3, $f20
/* 59F368 80218C88 00000000 */  nop
/* 59F36C 80218C8C 4680A520 */  cvt.s.w   $f20, $f20
/* 59F370 80218C90 46140002 */  mul.s     $f0, $f0, $f20
/* 59F374 80218C94 00000000 */  nop
/* 59F378 80218C98 44951000 */  mtc1      $s5, $f2
/* 59F37C 80218C9C 00000000 */  nop
/* 59F380 80218CA0 468010A0 */  cvt.s.w   $f2, $f2
/* 59F384 80218CA4 46001081 */  sub.s     $f2, $f2, $f0
/* 59F388 80218CA8 26100004 */  addiu     $s0, $s0, 4
/* 59F38C 80218CAC 4600110D */  trunc.w.s $f4, $f2
/* 59F390 80218CB0 44152000 */  mfc1      $s5, $f4
/* 59F394 80218CB4 0C00A8BB */  jal       sin_deg
/* 59F398 80218CB8 4600B306 */   mov.s    $f12, $f22
/* 59F39C 80218CBC 46140002 */  mul.s     $f0, $f0, $f20
/* 59F3A0 80218CC0 00000000 */  nop
/* 59F3A4 80218CC4 8E050000 */  lw        $a1, ($s0)
/* 59F3A8 80218CC8 26100004 */  addiu     $s0, $s0, 4
/* 59F3AC 80218CCC 02918821 */  addu      $s1, $s4, $s1
/* 59F3B0 80218CD0 44911000 */  mtc1      $s1, $f2
/* 59F3B4 80218CD4 00000000 */  nop
/* 59F3B8 80218CD8 468010A0 */  cvt.s.w   $f2, $f2
/* 59F3BC 80218CDC 46001081 */  sub.s     $f2, $f2, $f0
/* 59F3C0 80218CE0 0240202D */  daddu     $a0, $s2, $zero
/* 59F3C4 80218CE4 4600110D */  trunc.w.s $f4, $f2
/* 59F3C8 80218CE8 44142000 */  mfc1      $s4, $f4
/* 59F3CC 80218CEC 0C0B2026 */  jal       evt_set_variable
/* 59F3D0 80218CF0 02A0302D */   daddu    $a2, $s5, $zero
/* 59F3D4 80218CF4 0240202D */  daddu     $a0, $s2, $zero
/* 59F3D8 80218CF8 8E050000 */  lw        $a1, ($s0)
/* 59F3DC 80218CFC 0C0B2026 */  jal       evt_set_variable
/* 59F3E0 80218D00 0280302D */   daddu    $a2, $s4, $zero
/* 59F3E4 80218D04 8FBF0028 */  lw        $ra, 0x28($sp)
/* 59F3E8 80218D08 8FB50024 */  lw        $s5, 0x24($sp)
/* 59F3EC 80218D0C 8FB40020 */  lw        $s4, 0x20($sp)
/* 59F3F0 80218D10 8FB3001C */  lw        $s3, 0x1c($sp)
/* 59F3F4 80218D14 8FB20018 */  lw        $s2, 0x18($sp)
/* 59F3F8 80218D18 8FB10014 */  lw        $s1, 0x14($sp)
/* 59F3FC 80218D1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 59F400 80218D20 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 59F404 80218D24 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 59F408 80218D28 24020002 */  addiu     $v0, $zero, 2
/* 59F40C 80218D2C 03E00008 */  jr        $ra
/* 59F410 80218D30 27BD0040 */   addiu    $sp, $sp, 0x40
/* 59F414 80218D34 00000000 */  nop
/* 59F418 80218D38 00000000 */  nop
/* 59F41C 80218D3C 00000000 */  nop
