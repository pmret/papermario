.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BC4_99D554
/* 99D554 80240BC4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 99D558 80240BC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 99D55C 80240BCC 0080802D */  daddu     $s0, $a0, $zero
/* 99D560 80240BD0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 99D564 80240BD4 AFB20018 */  sw        $s2, 0x18($sp)
/* 99D568 80240BD8 AFB10014 */  sw        $s1, 0x14($sp)
/* 99D56C 80240BDC 8E110148 */  lw        $s1, 0x148($s0)
/* 99D570 80240BE0 86240008 */  lh        $a0, 8($s1)
/* 99D574 80240BE4 0C00EABB */  jal       get_npc_unsafe
/* 99D578 80240BE8 00A0902D */   daddu    $s2, $a1, $zero
/* 99D57C 80240BEC 8E2300CC */  lw        $v1, 0xcc($s1)
/* 99D580 80240BF0 0040202D */  daddu     $a0, $v0, $zero
/* 99D584 80240BF4 8C630000 */  lw        $v1, ($v1)
/* 99D588 80240BF8 24020001 */  addiu     $v0, $zero, 1
/* 99D58C 80240BFC AC830028 */  sw        $v1, 0x28($a0)
/* 99D590 80240C00 AE020070 */  sw        $v0, 0x70($s0)
/* 99D594 80240C04 8E220000 */  lw        $v0, ($s1)
/* 99D598 80240C08 3C030010 */  lui       $v1, 0x10
/* 99D59C 80240C0C 00431024 */  and       $v0, $v0, $v1
/* 99D5A0 80240C10 10400004 */  beqz      $v0, .L80240C24
/* 99D5A4 80240C14 00000000 */   nop      
/* 99D5A8 80240C18 C620006C */  lwc1      $f0, 0x6c($s1)
/* 99D5AC 80240C1C 46800020 */  cvt.s.w   $f0, $f0
/* 99D5B0 80240C20 E480000C */  swc1      $f0, 0xc($a0)
.L80240C24:
/* 99D5B4 80240C24 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 99D5B8 80240C28 8C420014 */  lw        $v0, 0x14($v0)
/* 99D5BC 80240C2C 1C400004 */  bgtz      $v0, .L80240C40
/* 99D5C0 80240C30 00000000 */   nop      
/* 99D5C4 80240C34 C640000C */  lwc1      $f0, 0xc($s2)
/* 99D5C8 80240C38 08090318 */  j         .L80240C60
/* 99D5CC 80240C3C E4800018 */   swc1     $f0, 0x18($a0)
.L80240C40:
/* 99D5D0 80240C40 3C018024 */  lui       $at, %hi(D_802444A0)
/* 99D5D4 80240C44 D42244A0 */  ldc1      $f2, %lo(D_802444A0)($at)
/* 99D5D8 80240C48 44820000 */  mtc1      $v0, $f0
/* 99D5DC 80240C4C 00000000 */  nop       
/* 99D5E0 80240C50 46800021 */  cvt.d.w   $f0, $f0
/* 99D5E4 80240C54 46220003 */  div.d     $f0, $f0, $f2
/* 99D5E8 80240C58 46200020 */  cvt.s.d   $f0, $f0
/* 99D5EC 80240C5C E4800018 */  swc1      $f0, 0x18($a0)
.L80240C60:
/* 99D5F0 80240C60 8FBF001C */  lw        $ra, 0x1c($sp)
/* 99D5F4 80240C64 8FB20018 */  lw        $s2, 0x18($sp)
/* 99D5F8 80240C68 8FB10014 */  lw        $s1, 0x14($sp)
/* 99D5FC 80240C6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 99D600 80240C70 03E00008 */  jr        $ra
/* 99D604 80240C74 27BD0020 */   addiu    $sp, $sp, 0x20
