.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mgm_00_UnkFunc16
/* E0F554 80240DB4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E0F558 80240DB8 AFB10014 */  sw        $s1, 0x14($sp)
/* E0F55C 80240DBC 0080882D */  daddu     $s1, $a0, $zero
/* E0F560 80240DC0 AFBF001C */  sw        $ra, 0x1c($sp)
/* E0F564 80240DC4 AFB20018 */  sw        $s2, 0x18($sp)
/* E0F568 80240DC8 AFB00010 */  sw        $s0, 0x10($sp)
/* E0F56C 80240DCC 8E300148 */  lw        $s0, 0x148($s1)
/* E0F570 80240DD0 86040008 */  lh        $a0, 8($s0)
/* E0F574 80240DD4 0C00EABB */  jal       get_npc_unsafe
/* E0F578 80240DD8 00A0902D */   daddu    $s2, $a1, $zero
/* E0F57C 80240DDC 8E0300D0 */  lw        $v1, 0xd0($s0)
/* E0F580 80240DE0 8E240078 */  lw        $a0, 0x78($s1)
/* E0F584 80240DE4 8C630000 */  lw        $v1, ($v1)
/* E0F588 80240DE8 0083182A */  slt       $v1, $a0, $v1
/* E0F58C 80240DEC 10600013 */  beqz      $v1, .L80240E3C
/* E0F590 80240DF0 0040302D */   daddu    $a2, $v0, $zero
/* E0F594 80240DF4 00041040 */  sll       $v0, $a0, 1
/* E0F598 80240DF8 00441021 */  addu      $v0, $v0, $a0
/* E0F59C 80240DFC 00022880 */  sll       $a1, $v0, 2
.L80240E00:
/* E0F5A0 80240E00 8E0300D0 */  lw        $v1, 0xd0($s0)
/* E0F5A4 80240E04 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* E0F5A8 80240E08 00A31021 */  addu      $v0, $a1, $v1
/* E0F5AC 80240E0C C4400008 */  lwc1      $f0, 8($v0)
/* E0F5B0 80240E10 46800020 */  cvt.s.w   $f0, $f0
/* E0F5B4 80240E14 4602003E */  c.le.s    $f0, $f2
/* E0F5B8 80240E18 00000000 */  nop
/* E0F5BC 80240E1C 45020003 */  bc1fl     .L80240E2C
/* E0F5C0 80240E20 24840001 */   addiu    $a0, $a0, 1
/* E0F5C4 80240E24 0809038F */  j         .L80240E3C
/* E0F5C8 80240E28 AE240078 */   sw       $a0, 0x78($s1)
.L80240E2C:
/* E0F5CC 80240E2C 8C620000 */  lw        $v0, ($v1)
/* E0F5D0 80240E30 0082102A */  slt       $v0, $a0, $v0
/* E0F5D4 80240E34 1440FFF2 */  bnez      $v0, .L80240E00
/* E0F5D8 80240E38 24A5000C */   addiu    $a1, $a1, 0xc
.L80240E3C:
/* E0F5DC 80240E3C C6400000 */  lwc1      $f0, ($s2)
/* E0F5E0 80240E40 E4C00018 */  swc1      $f0, 0x18($a2)
/* E0F5E4 80240E44 8E0200CC */  lw        $v0, 0xcc($s0)
/* E0F5E8 80240E48 8C420004 */  lw        $v0, 4($v0)
/* E0F5EC 80240E4C ACC20028 */  sw        $v0, 0x28($a2)
/* E0F5F0 80240E50 24020001 */  addiu     $v0, $zero, 1
/* E0F5F4 80240E54 AE200074 */  sw        $zero, 0x74($s1)
/* E0F5F8 80240E58 AE220070 */  sw        $v0, 0x70($s1)
/* E0F5FC 80240E5C 8FBF001C */  lw        $ra, 0x1c($sp)
/* E0F600 80240E60 8FB20018 */  lw        $s2, 0x18($sp)
/* E0F604 80240E64 8FB10014 */  lw        $s1, 0x14($sp)
/* E0F608 80240E68 8FB00010 */  lw        $s0, 0x10($sp)
/* E0F60C 80240E6C 03E00008 */  jr        $ra
/* E0F610 80240E70 27BD0020 */   addiu    $sp, $sp, 0x20
