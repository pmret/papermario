.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BC0_B66670
/* B66670 80240BC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B66674 80240BC4 AFB10014 */  sw        $s1, 0x14($sp)
/* B66678 80240BC8 0080882D */  daddu     $s1, $a0, $zero
/* B6667C 80240BCC AFBF0018 */  sw        $ra, 0x18($sp)
/* B66680 80240BD0 AFB00010 */  sw        $s0, 0x10($sp)
/* B66684 80240BD4 8E300148 */  lw        $s0, 0x148($s1)
/* B66688 80240BD8 0C00EABB */  jal       get_npc_unsafe
/* B6668C 80240BDC 86040008 */   lh       $a0, 8($s0)
/* B66690 80240BE0 0040202D */  daddu     $a0, $v0, $zero
/* B66694 80240BE4 9482008E */  lhu       $v0, 0x8e($a0)
/* B66698 80240BE8 2442FFFF */  addiu     $v0, $v0, -1
/* B6669C 80240BEC A482008E */  sh        $v0, 0x8e($a0)
/* B666A0 80240BF0 00021400 */  sll       $v0, $v0, 0x10
/* B666A4 80240BF4 1C400009 */  bgtz      $v0, .L80240C1C
/* B666A8 80240BF8 24020003 */   addiu    $v0, $zero, 3
/* B666AC 80240BFC 96030076 */  lhu       $v1, 0x76($s0)
/* B666B0 80240C00 AE02006C */  sw        $v0, 0x6c($s0)
/* B666B4 80240C04 A483008E */  sh        $v1, 0x8e($a0)
/* B666B8 80240C08 8E0200CC */  lw        $v0, 0xcc($s0)
/* B666BC 80240C0C 8C420024 */  lw        $v0, 0x24($v0)
/* B666C0 80240C10 AC820028 */  sw        $v0, 0x28($a0)
/* B666C4 80240C14 24020020 */  addiu     $v0, $zero, 0x20
/* B666C8 80240C18 AE220070 */  sw        $v0, 0x70($s1)
.L80240C1C:
/* B666CC 80240C1C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B666D0 80240C20 8FB10014 */  lw        $s1, 0x14($sp)
/* B666D4 80240C24 8FB00010 */  lw        $s0, 0x10($sp)
/* B666D8 80240C28 03E00008 */  jr        $ra
/* B666DC 80240C2C 27BD0020 */   addiu    $sp, $sp, 0x20
