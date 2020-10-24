.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245CF4_806574
/* 806574 80245CF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 806578 80245CF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 80657C 80245CFC 0080802D */  daddu     $s0, $a0, $zero
/* 806580 80245D00 AFBF0014 */  sw        $ra, 0x14($sp)
/* 806584 80245D04 8E020148 */  lw        $v0, 0x148($s0)
/* 806588 80245D08 0C00EABB */  jal       get_npc_unsafe
/* 80658C 80245D0C 84440008 */   lh       $a0, 8($v0)
/* 806590 80245D10 0040202D */  daddu     $a0, $v0, $zero
/* 806594 80245D14 C482003C */  lwc1      $f2, 0x3c($a0)
/* 806598 80245D18 C480001C */  lwc1      $f0, 0x1c($a0)
/* 80659C 80245D1C 46001080 */  add.s     $f2, $f2, $f0
/* 8065A0 80245D20 C4840014 */  lwc1      $f4, 0x14($a0)
/* 8065A4 80245D24 46040001 */  sub.s     $f0, $f0, $f4
/* 8065A8 80245D28 C4840064 */  lwc1      $f4, 0x64($a0)
/* 8065AC 80245D2C 4602203C */  c.lt.s    $f4, $f2
/* 8065B0 80245D30 E482003C */  swc1      $f2, 0x3c($a0)
/* 8065B4 80245D34 45010009 */  bc1t      .L80245D5C
/* 8065B8 80245D38 E480001C */   swc1     $f0, 0x1c($a0)
/* 8065BC 80245D3C 8C820000 */  lw        $v0, ($a0)
/* 8065C0 80245D40 2403F7FF */  addiu     $v1, $zero, -0x801
/* 8065C4 80245D44 E484003C */  swc1      $f4, 0x3c($a0)
/* 8065C8 80245D48 AC80001C */  sw        $zero, 0x1c($a0)
/* 8065CC 80245D4C 00431024 */  and       $v0, $v0, $v1
/* 8065D0 80245D50 AC820000 */  sw        $v0, ($a0)
/* 8065D4 80245D54 2402000C */  addiu     $v0, $zero, 0xc
/* 8065D8 80245D58 AE020070 */  sw        $v0, 0x70($s0)
.L80245D5C:
/* 8065DC 80245D5C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8065E0 80245D60 8FB00010 */  lw        $s0, 0x10($sp)
/* 8065E4 80245D64 03E00008 */  jr        $ra
/* 8065E8 80245D68 27BD0018 */   addiu    $sp, $sp, 0x18
