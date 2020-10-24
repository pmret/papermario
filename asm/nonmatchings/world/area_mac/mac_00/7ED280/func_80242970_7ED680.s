.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242970_7ED680
/* 7ED680 80242970 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7ED684 80242974 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7ED688 80242978 0080982D */  daddu     $s3, $a0, $zero
/* 7ED68C 8024297C AFBF0020 */  sw        $ra, 0x20($sp)
/* 7ED690 80242980 AFB20018 */  sw        $s2, 0x18($sp)
/* 7ED694 80242984 AFB10014 */  sw        $s1, 0x14($sp)
/* 7ED698 80242988 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ED69C 8024298C 8E720148 */  lw        $s2, 0x148($s3)
/* 7ED6A0 80242990 86440008 */  lh        $a0, 8($s2)
/* 7ED6A4 80242994 0C00EABB */  jal       get_npc_unsafe
/* 7ED6A8 80242998 00A0882D */   daddu    $s1, $a1, $zero
/* 7ED6AC 8024299C 8E240008 */  lw        $a0, 8($s1)
/* 7ED6B0 802429A0 0040802D */  daddu     $s0, $v0, $zero
/* 7ED6B4 802429A4 00041FC2 */  srl       $v1, $a0, 0x1f
/* 7ED6B8 802429A8 00832021 */  addu      $a0, $a0, $v1
/* 7ED6BC 802429AC 00042043 */  sra       $a0, $a0, 1
/* 7ED6C0 802429B0 0C00A67F */  jal       rand_int
/* 7ED6C4 802429B4 24840001 */   addiu    $a0, $a0, 1
/* 7ED6C8 802429B8 8E230008 */  lw        $v1, 8($s1)
/* 7ED6CC 802429BC 240400B4 */  addiu     $a0, $zero, 0xb4
/* 7ED6D0 802429C0 00032FC2 */  srl       $a1, $v1, 0x1f
/* 7ED6D4 802429C4 00651821 */  addu      $v1, $v1, $a1
/* 7ED6D8 802429C8 00031843 */  sra       $v1, $v1, 1
/* 7ED6DC 802429CC 00621821 */  addu      $v1, $v1, $v0
/* 7ED6E0 802429D0 0C00A67F */  jal       rand_int
/* 7ED6E4 802429D4 A603008E */   sh       $v1, 0x8e($s0)
/* 7ED6E8 802429D8 C60C000C */  lwc1      $f12, 0xc($s0)
/* 7ED6EC 802429DC 44820000 */  mtc1      $v0, $f0
/* 7ED6F0 802429E0 00000000 */  nop       
/* 7ED6F4 802429E4 46800020 */  cvt.s.w   $f0, $f0
/* 7ED6F8 802429E8 46006300 */  add.s     $f12, $f12, $f0
/* 7ED6FC 802429EC 3C0142B4 */  lui       $at, 0x42b4
/* 7ED700 802429F0 44810000 */  mtc1      $at, $f0
/* 7ED704 802429F4 0C00A6C9 */  jal       clamp_angle
/* 7ED708 802429F8 46006301 */   sub.s    $f12, $f12, $f0
/* 7ED70C 802429FC E600000C */  swc1      $f0, 0xc($s0)
/* 7ED710 80242A00 8E4200CC */  lw        $v0, 0xcc($s2)
/* 7ED714 80242A04 8C420000 */  lw        $v0, ($v0)
/* 7ED718 80242A08 AE020028 */  sw        $v0, 0x28($s0)
/* 7ED71C 80242A0C 24020003 */  addiu     $v0, $zero, 3
/* 7ED720 80242A10 AE620070 */  sw        $v0, 0x70($s3)
/* 7ED724 80242A14 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7ED728 80242A18 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7ED72C 80242A1C 8FB20018 */  lw        $s2, 0x18($sp)
/* 7ED730 80242A20 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ED734 80242A24 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ED738 80242A28 03E00008 */  jr        $ra
/* 7ED73C 80242A2C 27BD0028 */   addiu    $sp, $sp, 0x28
