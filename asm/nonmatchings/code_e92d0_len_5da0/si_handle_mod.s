.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_mod
/* 0EA36C 802C59BC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EA370 802C59C0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA374 802C59C4 0080882D */  daddu $s1, $a0, $zero
/* 0EA378 802C59C8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EA37C 802C59CC AFB20018 */  sw    $s2, 0x18($sp)
/* 0EA380 802C59D0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA384 802C59D4 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0EA388 802C59D8 8E22000C */  lw    $v0, 0xc($s1)
/* 0EA38C 802C59DC 8C450004 */  lw    $a1, 4($v0)
/* 0EA390 802C59E0 0C0B1EAF */  jal   get_variable
/* 0EA394 802C59E4 8C520000 */   lw    $s2, ($v0)
/* 0EA398 802C59E8 3C013FE0 */  lui   $at, 0x3fe0
/* 0EA39C 802C59EC 4481A800 */  mtc1  $at, $f21
/* 0EA3A0 802C59F0 4480A000 */  mtc1  $zero, $f20
/* 0EA3A4 802C59F4 44820000 */  mtc1  $v0, $f0
/* 0EA3A8 802C59F8 00000000 */  nop   
/* 0EA3AC 802C59FC 46800021 */  cvt.d.w $f0, $f0
/* 0EA3B0 802C5A00 46340000 */  add.d $f0, $f0, $f20
/* 0EA3B4 802C5A04 0220202D */  daddu $a0, $s1, $zero
/* 0EA3B8 802C5A08 4620008D */  trunc.w.d $f2, $f0
/* 0EA3BC 802C5A0C 44101000 */  mfc1  $s0, $f2
/* 0EA3C0 802C5A10 0C0B1EAF */  jal   get_variable
/* 0EA3C4 802C5A14 0240282D */   daddu $a1, $s2, $zero
/* 0EA3C8 802C5A18 44820000 */  mtc1  $v0, $f0
/* 0EA3CC 802C5A1C 00000000 */  nop   
/* 0EA3D0 802C5A20 46800021 */  cvt.d.w $f0, $f0
/* 0EA3D4 802C5A24 46340000 */  add.d $f0, $f0, $f20
/* 0EA3D8 802C5A28 4620008D */  trunc.w.d $f2, $f0
/* 0EA3DC 802C5A2C 44021000 */  mfc1  $v0, $f2
/* 0EA3E0 802C5A30 16000002 */  bnez  $s0, .L802C5A3C
/* 0EA3E4 802C5A34 0050001A */   div   $zero, $v0, $s0
/* 0EA3E8 802C5A38 0007000D */  break 7
.L802C5A3C:
/* 0EA3EC 802C5A3C 2401FFFF */  addiu $at, $zero, -1
/* 0EA3F0 802C5A40 16010004 */  bne   $s0, $at, .L802C5A54
/* 0EA3F4 802C5A44 3C018000 */   lui   $at, 0x8000
/* 0EA3F8 802C5A48 14410002 */  bne   $v0, $at, .L802C5A54
/* 0EA3FC 802C5A4C 00000000 */   nop   
/* 0EA400 802C5A50 0006000D */  break 6
.L802C5A54:
/* 0EA404 802C5A54 00003010 */  mfhi  $a2
/* 0EA408 802C5A58 0220202D */  daddu $a0, $s1, $zero
/* 0EA40C 802C5A5C 0C0B2026 */  jal   set_variable
/* 0EA410 802C5A60 0240282D */   daddu $a1, $s2, $zero
/* 0EA414 802C5A64 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EA418 802C5A68 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EA41C 802C5A6C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA420 802C5A70 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA424 802C5A74 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0EA428 802C5A78 24020002 */  addiu $v0, $zero, 2
/* 0EA42C 802C5A7C 03E00008 */  jr    $ra
/* 0EA430 802C5A80 27BD0028 */   addiu $sp, $sp, 0x28

