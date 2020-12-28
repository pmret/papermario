.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218C40_5CF2D0
/* 5CF2D0 80218C40 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 5CF2D4 80218C44 AFB20018 */  sw        $s2, 0x18($sp)
/* 5CF2D8 80218C48 0080902D */  daddu     $s2, $a0, $zero
/* 5CF2DC 80218C4C AFBF0028 */  sw        $ra, 0x28($sp)
/* 5CF2E0 80218C50 AFB50024 */  sw        $s5, 0x24($sp)
/* 5CF2E4 80218C54 AFB40020 */  sw        $s4, 0x20($sp)
/* 5CF2E8 80218C58 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5CF2EC 80218C5C AFB10014 */  sw        $s1, 0x14($sp)
/* 5CF2F0 80218C60 AFB00010 */  sw        $s0, 0x10($sp)
/* 5CF2F4 80218C64 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5CF2F8 80218C68 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5CF2FC 80218C6C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5CF300 80218C70 8E50000C */  lw        $s0, 0xc($s2)
/* 5CF304 80218C74 8E140000 */  lw        $s4, ($s0)
/* 5CF308 80218C78 26100004 */  addiu     $s0, $s0, 4
/* 5CF30C 80218C7C 0C0B1EAF */  jal       get_variable
/* 5CF310 80218C80 0280282D */   daddu    $a1, $s4, $zero
/* 5CF314 80218C84 0040982D */  daddu     $s3, $v0, $zero
/* 5CF318 80218C88 8E150000 */  lw        $s5, ($s0)
/* 5CF31C 80218C8C 26100004 */  addiu     $s0, $s0, 4
/* 5CF320 80218C90 8E050000 */  lw        $a1, ($s0)
/* 5CF324 80218C94 26100004 */  addiu     $s0, $s0, 4
/* 5CF328 80218C98 0C0B210B */  jal       get_float_variable
/* 5CF32C 80218C9C 0240202D */   daddu    $a0, $s2, $zero
/* 5CF330 80218CA0 8E050000 */  lw        $a1, ($s0)
/* 5CF334 80218CA4 26100004 */  addiu     $s0, $s0, 4
/* 5CF338 80218CA8 0240202D */  daddu     $a0, $s2, $zero
/* 5CF33C 80218CAC 0C0B210B */  jal       get_float_variable
/* 5CF340 80218CB0 46000606 */   mov.s    $f24, $f0
/* 5CF344 80218CB4 8E050000 */  lw        $a1, ($s0)
/* 5CF348 80218CB8 26100004 */  addiu     $s0, $s0, 4
/* 5CF34C 80218CBC 0240202D */  daddu     $a0, $s2, $zero
/* 5CF350 80218CC0 0C0B1EAF */  jal       get_variable
/* 5CF354 80218CC4 46000506 */   mov.s    $f20, $f0
/* 5CF358 80218CC8 8E050000 */  lw        $a1, ($s0)
/* 5CF35C 80218CCC 26100004 */  addiu     $s0, $s0, 4
/* 5CF360 80218CD0 0240202D */  daddu     $a0, $s2, $zero
/* 5CF364 80218CD4 0C0B1EAF */  jal       get_variable
/* 5CF368 80218CD8 0040882D */   daddu    $s1, $v0, $zero
/* 5CF36C 80218CDC 0240202D */  daddu     $a0, $s2, $zero
/* 5CF370 80218CE0 8E050000 */  lw        $a1, ($s0)
/* 5CF374 80218CE4 0C0B210B */  jal       get_float_variable
/* 5CF378 80218CE8 0040802D */   daddu    $s0, $v0, $zero
/* 5CF37C 80218CEC 3C014334 */  lui       $at, 0x4334
/* 5CF380 80218CF0 44811000 */  mtc1      $at, $f2
/* 5CF384 80218CF4 3C014049 */  lui       $at, 0x4049
/* 5CF388 80218CF8 34210FD8 */  ori       $at, $at, 0xfd8
/* 5CF38C 80218CFC 44812000 */  mtc1      $at, $f4
/* 5CF390 80218D00 46020003 */  div.s     $f0, $f0, $f2
/* 5CF394 80218D04 46040582 */  mul.s     $f22, $f0, $f4
/* 5CF398 80218D08 00000000 */  nop       
/* 5CF39C 80218D0C 4618A501 */  sub.s     $f20, $f20, $f24
/* 5CF3A0 80218D10 3C013F00 */  lui       $at, 0x3f00
/* 5CF3A4 80218D14 44810000 */  mtc1      $at, $f0
/* 5CF3A8 80218D18 00000000 */  nop       
/* 5CF3AC 80218D1C 4600A502 */  mul.s     $f20, $f20, $f0
/* 5CF3B0 80218D20 00000000 */  nop       
/* 5CF3B4 80218D24 12000007 */  beqz      $s0, .L80218D44
/* 5CF3B8 80218D28 0233102A */   slt      $v0, $s1, $s3
/* 5CF3BC 80218D2C 10400005 */  beqz      $v0, .L80218D44
/* 5CF3C0 80218D30 0240202D */   daddu    $a0, $s2, $zero
/* 5CF3C4 80218D34 0220982D */  daddu     $s3, $s1, $zero
/* 5CF3C8 80218D38 0280282D */  daddu     $a1, $s4, $zero
/* 5CF3CC 80218D3C 0C0B2026 */  jal       set_variable
/* 5CF3D0 80218D40 0220302D */   daddu    $a2, $s1, $zero
.L80218D44:
/* 5CF3D4 80218D44 3C014049 */  lui       $at, 0x4049
/* 5CF3D8 80218D48 34210FD8 */  ori       $at, $at, 0xfd8
/* 5CF3DC 80218D4C 44810000 */  mtc1      $at, $f0
/* 5CF3E0 80218D50 44936000 */  mtc1      $s3, $f12
/* 5CF3E4 80218D54 00000000 */  nop       
/* 5CF3E8 80218D58 46806320 */  cvt.s.w   $f12, $f12
/* 5CF3EC 80218D5C 46006302 */  mul.s     $f12, $f12, $f0
/* 5CF3F0 80218D60 00000000 */  nop       
/* 5CF3F4 80218D64 44910000 */  mtc1      $s1, $f0
/* 5CF3F8 80218D68 00000000 */  nop       
/* 5CF3FC 80218D6C 46800020 */  cvt.s.w   $f0, $f0
/* 5CF400 80218D70 46006303 */  div.s     $f12, $f12, $f0
/* 5CF404 80218D74 0C00A874 */  jal       cos_rad
/* 5CF408 80218D78 46166300 */   add.s    $f12, $f12, $f22
/* 5CF40C 80218D7C 4600A002 */  mul.s     $f0, $f20, $f0
/* 5CF410 80218D80 00000000 */  nop       
/* 5CF414 80218D84 4614C080 */  add.s     $f2, $f24, $f20
/* 5CF418 80218D88 46001081 */  sub.s     $f2, $f2, $f0
/* 5CF41C 80218D8C 0240202D */  daddu     $a0, $s2, $zero
/* 5CF420 80218D90 44061000 */  mfc1      $a2, $f2
/* 5CF424 80218D94 0C0B2190 */  jal       set_float_variable
/* 5CF428 80218D98 02A0282D */   daddu    $a1, $s5, $zero
/* 5CF42C 80218D9C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF430 80218DA0 8FB50024 */  lw        $s5, 0x24($sp)
/* 5CF434 80218DA4 8FB40020 */  lw        $s4, 0x20($sp)
/* 5CF438 80218DA8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5CF43C 80218DAC 8FB20018 */  lw        $s2, 0x18($sp)
/* 5CF440 80218DB0 8FB10014 */  lw        $s1, 0x14($sp)
/* 5CF444 80218DB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CF448 80218DB8 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5CF44C 80218DBC D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5CF450 80218DC0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5CF454 80218DC4 24020002 */  addiu     $v0, $zero, 2
/* 5CF458 80218DC8 03E00008 */  jr        $ra
/* 5CF45C 80218DCC 27BD0048 */   addiu    $sp, $sp, 0x48
