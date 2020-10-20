.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C9C
/* B3586C 80240C9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B35870 80240CA0 AFB10014 */  sw        $s1, 0x14($sp)
/* B35874 80240CA4 0080882D */  daddu     $s1, $a0, $zero
/* B35878 80240CA8 AFBF001C */  sw        $ra, 0x1c($sp)
/* B3587C 80240CAC AFB20018 */  sw        $s2, 0x18($sp)
/* B35880 80240CB0 AFB00010 */  sw        $s0, 0x10($sp)
/* B35884 80240CB4 8E300148 */  lw        $s0, 0x148($s1)
/* B35888 80240CB8 86040008 */  lh        $a0, 8($s0)
/* B3588C 80240CBC 0C00EABB */  jal       get_npc_unsafe
/* B35890 80240CC0 00A0902D */   daddu    $s2, $a1, $zero
/* B35894 80240CC4 8E230078 */  lw        $v1, 0x78($s1)
/* B35898 80240CC8 24630001 */  addiu     $v1, $v1, 1
/* B3589C 80240CCC AE230078 */  sw        $v1, 0x78($s1)
/* B358A0 80240CD0 8E0400D0 */  lw        $a0, 0xd0($s0)
/* B358A4 80240CD4 8C840000 */  lw        $a0, ($a0)
/* B358A8 80240CD8 0064182A */  slt       $v1, $v1, $a0
/* B358AC 80240CDC 14600002 */  bnez      $v1, .L80240CE8
/* B358B0 80240CE0 0040282D */   daddu    $a1, $v0, $zero
/* B358B4 80240CE4 AE200078 */  sw        $zero, 0x78($s1)
.L80240CE8:
/* B358B8 80240CE8 8E0200CC */  lw        $v0, 0xcc($s0)
/* B358BC 80240CEC 8C420004 */  lw        $v0, 4($v0)
/* B358C0 80240CF0 ACA20028 */  sw        $v0, 0x28($a1)
/* B358C4 80240CF4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* B358C8 80240CF8 8C42007C */  lw        $v0, 0x7c($v0)
/* B358CC 80240CFC 04410004 */  bgez      $v0, .L80240D10
/* B358D0 80240D00 00000000 */   nop      
/* B358D4 80240D04 C6400000 */  lwc1      $f0, ($s2)
/* B358D8 80240D08 0809034C */  j         .L80240D30
/* B358DC 80240D0C E4A00018 */   swc1     $f0, 0x18($a1)
.L80240D10:
/* B358E0 80240D10 3C018025 */  lui       $at, 0x8025
/* B358E4 80240D14 D422F9F8 */  ldc1      $f2, -0x608($at)
/* B358E8 80240D18 44820000 */  mtc1      $v0, $f0
/* B358EC 80240D1C 00000000 */  nop       
/* B358F0 80240D20 46800021 */  cvt.d.w   $f0, $f0
/* B358F4 80240D24 46220003 */  div.d     $f0, $f0, $f2
/* B358F8 80240D28 46200020 */  cvt.s.d   $f0, $f0
/* B358FC 80240D2C E4A00018 */  swc1      $f0, 0x18($a1)
.L80240D30:
/* B35900 80240D30 24020001 */  addiu     $v0, $zero, 1
/* B35904 80240D34 AE220070 */  sw        $v0, 0x70($s1)
/* B35908 80240D38 8FBF001C */  lw        $ra, 0x1c($sp)
/* B3590C 80240D3C 8FB20018 */  lw        $s2, 0x18($sp)
/* B35910 80240D40 8FB10014 */  lw        $s1, 0x14($sp)
/* B35914 80240D44 8FB00010 */  lw        $s0, 0x10($sp)
/* B35918 80240D48 03E00008 */  jr        $ra
/* B3591C 80240D4C 27BD0020 */   addiu    $sp, $sp, 0x20
