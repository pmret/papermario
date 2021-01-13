.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238C58_70C968
/* 70C968 80238C58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 70C96C 80238C5C AFB00018 */  sw        $s0, 0x18($sp)
/* 70C970 80238C60 0080802D */  daddu     $s0, $a0, $zero
/* 70C974 80238C64 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 70C978 80238C68 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 70C97C 80238C6C AFBF001C */  sw        $ra, 0x1c($sp)
/* 70C980 80238C70 8CC400D8 */  lw        $a0, 0xd8($a2)
/* 70C984 80238C74 54A00001 */  bnel      $a1, $zero, .L80238C7C
/* 70C988 80238C78 AE000070 */   sw       $zero, 0x70($s0)
.L80238C7C:
/* 70C98C 80238C7C 8E030070 */  lw        $v1, 0x70($s0)
/* 70C990 80238C80 10600005 */  beqz      $v1, .L80238C98
/* 70C994 80238C84 24020001 */   addiu    $v0, $zero, 1
/* 70C998 80238C88 10620013 */  beq       $v1, $v0, .L80238CD8
/* 70C99C 80238C8C 0000102D */   daddu    $v0, $zero, $zero
/* 70C9A0 80238C90 0808E34E */  j         .L80238D38
/* 70C9A4 80238C94 00000000 */   nop
.L80238C98:
/* 70C9A8 80238C98 3C013DCC */  lui       $at, 0x3dcc
/* 70C9AC 80238C9C 3421CCCD */  ori       $at, $at, 0xcccd
/* 70C9B0 80238CA0 44810000 */  mtc1      $at, $f0
/* 70C9B4 80238CA4 24C200A8 */  addiu     $v0, $a2, 0xa8
/* 70C9B8 80238CA8 AFA20014 */  sw        $v0, 0x14($sp)
/* 70C9BC 80238CAC E7A00010 */  swc1      $f0, 0x10($sp)
/* 70C9C0 80238CB0 8C850144 */  lw        $a1, 0x144($a0)
/* 70C9C4 80238CB4 8C860148 */  lw        $a2, 0x148($a0)
/* 70C9C8 80238CB8 8C87014C */  lw        $a3, 0x14c($a0)
/* 70C9CC 80238CBC 3C018024 */  lui       $at, %hi(D_8023D1E0)
/* 70C9D0 80238CC0 E420D1E0 */  swc1      $f0, %lo(D_8023D1E0)($at)
/* 70C9D4 80238CC4 0C01C304 */  jal       func_80070C10
/* 70C9D8 80238CC8 0000202D */   daddu    $a0, $zero, $zero
/* 70C9DC 80238CCC 24020001 */  addiu     $v0, $zero, 1
/* 70C9E0 80238CD0 0808E34D */  j         .L80238D34
/* 70C9E4 80238CD4 AE020070 */   sw       $v0, 0x70($s0)
.L80238CD8:
/* 70C9E8 80238CD8 3C038024 */  lui       $v1, %hi(D_8023D1E0)
/* 70C9EC 80238CDC 2463D1E0 */  addiu     $v1, $v1, %lo(D_8023D1E0)
/* 70C9F0 80238CE0 C4620000 */  lwc1      $f2, ($v1)
/* 70C9F4 80238CE4 3C013FF0 */  lui       $at, 0x3ff0
/* 70C9F8 80238CE8 44810800 */  mtc1      $at, $f1
/* 70C9FC 80238CEC 44800000 */  mtc1      $zero, $f0
/* 70CA00 80238CF0 460010A1 */  cvt.d.s   $f2, $f2
/* 70CA04 80238CF4 4622003E */  c.le.d    $f0, $f2
/* 70CA08 80238CF8 00000000 */  nop
/* 70CA0C 80238CFC 4501000E */  bc1t      .L80238D38
/* 70CA10 80238D00 24020002 */   addiu    $v0, $zero, 2
/* 70CA14 80238D04 8CC200A8 */  lw        $v0, 0xa8($a2)
/* 70CA18 80238D08 3C018024 */  lui       $at, %hi(D_8023D1B8)
/* 70CA1C 80238D0C D424D1B8 */  ldc1      $f4, %lo(D_8023D1B8)($at)
/* 70CA20 80238D10 8C42000C */  lw        $v0, 0xc($v0)
/* 70CA24 80238D14 46241080 */  add.d     $f2, $f2, $f4
/* 70CA28 80238D18 C4400010 */  lwc1      $f0, 0x10($v0)
/* 70CA2C 80238D1C 46000021 */  cvt.d.s   $f0, $f0
/* 70CA30 80238D20 46240000 */  add.d     $f0, $f0, $f4
/* 70CA34 80238D24 462010A0 */  cvt.s.d   $f2, $f2
/* 70CA38 80238D28 E4620000 */  swc1      $f2, ($v1)
/* 70CA3C 80238D2C 46200020 */  cvt.s.d   $f0, $f0
/* 70CA40 80238D30 E4400010 */  swc1      $f0, 0x10($v0)
.L80238D34:
/* 70CA44 80238D34 0000102D */  daddu     $v0, $zero, $zero
.L80238D38:
/* 70CA48 80238D38 8FBF001C */  lw        $ra, 0x1c($sp)
/* 70CA4C 80238D3C 8FB00018 */  lw        $s0, 0x18($sp)
/* 70CA50 80238D40 03E00008 */  jr        $ra
/* 70CA54 80238D44 27BD0020 */   addiu    $sp, $sp, 0x20
