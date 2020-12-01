.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C5C_95BE5C
/* 95BE5C 80240C5C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95BE60 80240C60 AFB10014 */  sw        $s1, 0x14($sp)
/* 95BE64 80240C64 0080882D */  daddu     $s1, $a0, $zero
/* 95BE68 80240C68 AFBF001C */  sw        $ra, 0x1c($sp)
/* 95BE6C 80240C6C AFB20018 */  sw        $s2, 0x18($sp)
/* 95BE70 80240C70 AFB00010 */  sw        $s0, 0x10($sp)
/* 95BE74 80240C74 8E300148 */  lw        $s0, 0x148($s1)
/* 95BE78 80240C78 86040008 */  lh        $a0, 8($s0)
/* 95BE7C 80240C7C 0C00EABB */  jal       get_npc_unsafe
/* 95BE80 80240C80 00A0902D */   daddu    $s2, $a1, $zero
/* 95BE84 80240C84 8E230078 */  lw        $v1, 0x78($s1)
/* 95BE88 80240C88 24630001 */  addiu     $v1, $v1, 1
/* 95BE8C 80240C8C AE230078 */  sw        $v1, 0x78($s1)
/* 95BE90 80240C90 8E0400D0 */  lw        $a0, 0xd0($s0)
/* 95BE94 80240C94 8C840000 */  lw        $a0, ($a0)
/* 95BE98 80240C98 0064182A */  slt       $v1, $v1, $a0
/* 95BE9C 80240C9C 14600002 */  bnez      $v1, .L80240CA8
/* 95BEA0 80240CA0 0040282D */   daddu    $a1, $v0, $zero
/* 95BEA4 80240CA4 AE200078 */  sw        $zero, 0x78($s1)
.L80240CA8:
/* 95BEA8 80240CA8 8E0200CC */  lw        $v0, 0xcc($s0)
/* 95BEAC 80240CAC 8C420004 */  lw        $v0, 4($v0)
/* 95BEB0 80240CB0 ACA20028 */  sw        $v0, 0x28($a1)
/* 95BEB4 80240CB4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 95BEB8 80240CB8 8C42007C */  lw        $v0, 0x7c($v0)
/* 95BEBC 80240CBC 04410004 */  bgez      $v0, .L80240CD0
/* 95BEC0 80240CC0 00000000 */   nop      
/* 95BEC4 80240CC4 C6400000 */  lwc1      $f0, ($s2)
/* 95BEC8 80240CC8 0809033C */  j         .L80240CF0
/* 95BECC 80240CCC E4A00018 */   swc1     $f0, 0x18($a1)
.L80240CD0:
/* 95BED0 80240CD0 3C018025 */  lui       $at, %hi(D_8024DDE8)
/* 95BED4 80240CD4 D422DDE8 */  ldc1      $f2, %lo(D_8024DDE8)($at)
/* 95BED8 80240CD8 44820000 */  mtc1      $v0, $f0
/* 95BEDC 80240CDC 00000000 */  nop       
/* 95BEE0 80240CE0 46800021 */  cvt.d.w   $f0, $f0
/* 95BEE4 80240CE4 46220003 */  div.d     $f0, $f0, $f2
/* 95BEE8 80240CE8 46200020 */  cvt.s.d   $f0, $f0
/* 95BEEC 80240CEC E4A00018 */  swc1      $f0, 0x18($a1)
.L80240CF0:
/* 95BEF0 80240CF0 24020001 */  addiu     $v0, $zero, 1
/* 95BEF4 80240CF4 AE220070 */  sw        $v0, 0x70($s1)
/* 95BEF8 80240CF8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 95BEFC 80240CFC 8FB20018 */  lw        $s2, 0x18($sp)
/* 95BF00 80240D00 8FB10014 */  lw        $s1, 0x14($sp)
/* 95BF04 80240D04 8FB00010 */  lw        $s0, 0x10($sp)
/* 95BF08 80240D08 03E00008 */  jr        $ra
/* 95BF0C 80240D0C 27BD0020 */   addiu    $sp, $sp, 0x20
