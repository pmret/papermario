.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F04_B2D374
/* B2D374 80240F04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2D378 80240F08 AFB10014 */  sw        $s1, 0x14($sp)
/* B2D37C 80240F0C 0080882D */  daddu     $s1, $a0, $zero
/* B2D380 80240F10 AFBF001C */  sw        $ra, 0x1c($sp)
/* B2D384 80240F14 AFB20018 */  sw        $s2, 0x18($sp)
/* B2D388 80240F18 AFB00010 */  sw        $s0, 0x10($sp)
/* B2D38C 80240F1C 8E300148 */  lw        $s0, 0x148($s1)
/* B2D390 80240F20 86040008 */  lh        $a0, 8($s0)
/* B2D394 80240F24 0C00EABB */  jal       get_npc_unsafe
/* B2D398 80240F28 00A0902D */   daddu    $s2, $a1, $zero
/* B2D39C 80240F2C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* B2D3A0 80240F30 8E240078 */  lw        $a0, 0x78($s1)
/* B2D3A4 80240F34 8C630000 */  lw        $v1, ($v1)
/* B2D3A8 80240F38 0083182A */  slt       $v1, $a0, $v1
/* B2D3AC 80240F3C 10600013 */  beqz      $v1, .L80240F8C
/* B2D3B0 80240F40 0040302D */   daddu    $a2, $v0, $zero
/* B2D3B4 80240F44 00041040 */  sll       $v0, $a0, 1
/* B2D3B8 80240F48 00441021 */  addu      $v0, $v0, $a0
/* B2D3BC 80240F4C 00022880 */  sll       $a1, $v0, 2
.L80240F50:
/* B2D3C0 80240F50 8E0300D0 */  lw        $v1, 0xd0($s0)
/* B2D3C4 80240F54 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* B2D3C8 80240F58 00A31021 */  addu      $v0, $a1, $v1
/* B2D3CC 80240F5C C4400008 */  lwc1      $f0, 8($v0)
/* B2D3D0 80240F60 46800020 */  cvt.s.w   $f0, $f0
/* B2D3D4 80240F64 4602003E */  c.le.s    $f0, $f2
/* B2D3D8 80240F68 00000000 */  nop       
/* B2D3DC 80240F6C 45020003 */  bc1fl     .L80240F7C
/* B2D3E0 80240F70 24840001 */   addiu    $a0, $a0, 1
/* B2D3E4 80240F74 080903E3 */  j         .L80240F8C
/* B2D3E8 80240F78 AE240078 */   sw       $a0, 0x78($s1)
.L80240F7C:
/* B2D3EC 80240F7C 8C620000 */  lw        $v0, ($v1)
/* B2D3F0 80240F80 0082102A */  slt       $v0, $a0, $v0
/* B2D3F4 80240F84 1440FFF2 */  bnez      $v0, .L80240F50
/* B2D3F8 80240F88 24A5000C */   addiu    $a1, $a1, 0xc
.L80240F8C:
/* B2D3FC 80240F8C C6400000 */  lwc1      $f0, ($s2)
/* B2D400 80240F90 E4C00018 */  swc1      $f0, 0x18($a2)
/* B2D404 80240F94 8E0200CC */  lw        $v0, 0xcc($s0)
/* B2D408 80240F98 8C420004 */  lw        $v0, 4($v0)
/* B2D40C 80240F9C ACC20028 */  sw        $v0, 0x28($a2)
/* B2D410 80240FA0 24020001 */  addiu     $v0, $zero, 1
/* B2D414 80240FA4 AE200074 */  sw        $zero, 0x74($s1)
/* B2D418 80240FA8 AE220070 */  sw        $v0, 0x70($s1)
/* B2D41C 80240FAC 8FBF001C */  lw        $ra, 0x1c($sp)
/* B2D420 80240FB0 8FB20018 */  lw        $s2, 0x18($sp)
/* B2D424 80240FB4 8FB10014 */  lw        $s1, 0x14($sp)
/* B2D428 80240FB8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2D42C 80240FBC 03E00008 */  jr        $ra
/* B2D430 80240FC0 27BD0020 */   addiu    $sp, $sp, 0x20
