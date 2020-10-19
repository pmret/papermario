.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024067C_BE3E2C
/* BE3E2C 8024067C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE3E30 80240680 AFB10014 */  sw        $s1, 0x14($sp)
/* BE3E34 80240684 0080882D */  daddu     $s1, $a0, $zero
/* BE3E38 80240688 AFBF001C */  sw        $ra, 0x1c($sp)
/* BE3E3C 8024068C AFB20018 */  sw        $s2, 0x18($sp)
/* BE3E40 80240690 AFB00010 */  sw        $s0, 0x10($sp)
/* BE3E44 80240694 8E300148 */  lw        $s0, 0x148($s1)
/* BE3E48 80240698 86040008 */  lh        $a0, 8($s0)
/* BE3E4C 8024069C 0C00EABB */  jal       get_npc_unsafe
/* BE3E50 802406A0 00A0902D */   daddu    $s2, $a1, $zero
/* BE3E54 802406A4 8E230078 */  lw        $v1, 0x78($s1)
/* BE3E58 802406A8 24630001 */  addiu     $v1, $v1, 1
/* BE3E5C 802406AC AE230078 */  sw        $v1, 0x78($s1)
/* BE3E60 802406B0 8E0400D0 */  lw        $a0, 0xd0($s0)
/* BE3E64 802406B4 8C840000 */  lw        $a0, ($a0)
/* BE3E68 802406B8 0064182A */  slt       $v1, $v1, $a0
/* BE3E6C 802406BC 14600002 */  bnez      $v1, .L802406C8
/* BE3E70 802406C0 0040282D */   daddu    $a1, $v0, $zero
/* BE3E74 802406C4 AE200078 */  sw        $zero, 0x78($s1)
.L802406C8:
/* BE3E78 802406C8 8E0200CC */  lw        $v0, 0xcc($s0)
/* BE3E7C 802406CC 8C420004 */  lw        $v0, 4($v0)
/* BE3E80 802406D0 ACA20028 */  sw        $v0, 0x28($a1)
/* BE3E84 802406D4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BE3E88 802406D8 8C42007C */  lw        $v0, 0x7c($v0)
/* BE3E8C 802406DC 04410004 */  bgez      $v0, .L802406F0
/* BE3E90 802406E0 00000000 */   nop      
/* BE3E94 802406E4 C6400000 */  lwc1      $f0, ($s2)
/* BE3E98 802406E8 080901C4 */  j         .L80240710
/* BE3E9C 802406EC E4A00018 */   swc1     $f0, 0x18($a1)
.L802406F0:
/* BE3EA0 802406F0 3C018024 */  lui       $at, 0x8024
/* BE3EA4 802406F4 D4224138 */  ldc1      $f2, 0x4138($at)
/* BE3EA8 802406F8 44820000 */  mtc1      $v0, $f0
/* BE3EAC 802406FC 00000000 */  nop       
/* BE3EB0 80240700 46800021 */  cvt.d.w   $f0, $f0
/* BE3EB4 80240704 46220003 */  div.d     $f0, $f0, $f2
/* BE3EB8 80240708 46200020 */  cvt.s.d   $f0, $f0
/* BE3EBC 8024070C E4A00018 */  swc1      $f0, 0x18($a1)
.L80240710:
/* BE3EC0 80240710 24020001 */  addiu     $v0, $zero, 1
/* BE3EC4 80240714 AE220070 */  sw        $v0, 0x70($s1)
/* BE3EC8 80240718 8FBF001C */  lw        $ra, 0x1c($sp)
/* BE3ECC 8024071C 8FB20018 */  lw        $s2, 0x18($sp)
/* BE3ED0 80240720 8FB10014 */  lw        $s1, 0x14($sp)
/* BE3ED4 80240724 8FB00010 */  lw        $s0, 0x10($sp)
/* BE3ED8 80240728 03E00008 */  jr        $ra
/* BE3EDC 8024072C 27BD0020 */   addiu    $sp, $sp, 0x20
