.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C30
/* B666E0 80240C30 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B666E4 80240C34 AFB10034 */  sw        $s1, 0x34($sp)
/* B666E8 80240C38 0080882D */  daddu     $s1, $a0, $zero
/* B666EC 80240C3C AFBF0038 */  sw        $ra, 0x38($sp)
/* B666F0 80240C40 AFB00030 */  sw        $s0, 0x30($sp)
/* B666F4 80240C44 8E300148 */  lw        $s0, 0x148($s1)
/* B666F8 80240C48 0C00EABB */  jal       get_npc_unsafe
/* B666FC 80240C4C 86040008 */   lh       $a0, 8($s0)
/* B66700 80240C50 0040282D */  daddu     $a1, $v0, $zero
/* B66704 80240C54 94A2008E */  lhu       $v0, 0x8e($a1)
/* B66708 80240C58 2442FFFF */  addiu     $v0, $v0, -1
/* B6670C 80240C5C A4A2008E */  sh        $v0, 0x8e($a1)
/* B66710 80240C60 00021400 */  sll       $v0, $v0, 0x10
/* B66714 80240C64 1C400023 */  bgtz      $v0, .L80240CF4
/* B66718 80240C68 24020004 */   addiu    $v0, $zero, 4
/* B6671C 80240C6C 8E0300CC */  lw        $v1, 0xcc($s0)
/* B66720 80240C70 AE02006C */  sw        $v0, 0x6c($s0)
/* B66724 80240C74 8C620000 */  lw        $v0, ($v1)
/* B66728 80240C78 ACA20028 */  sw        $v0, 0x28($a1)
/* B6672C 80240C7C 9602007A */  lhu       $v0, 0x7a($s0)
/* B66730 80240C80 A4A2008E */  sh        $v0, 0x8e($a1)
/* B66734 80240C84 8E020078 */  lw        $v0, 0x78($s0)
/* B66738 80240C88 28420008 */  slti      $v0, $v0, 8
/* B6673C 80240C8C 14400018 */  bnez      $v0, .L80240CF0
/* B66740 80240C90 24020021 */   addiu    $v0, $zero, 0x21
/* B66744 80240C94 24040003 */  addiu     $a0, $zero, 3
/* B66748 80240C98 27A30028 */  addiu     $v1, $sp, 0x28
/* B6674C 80240C9C 84A700A8 */  lh        $a3, 0xa8($a1)
/* B66750 80240CA0 3C013F80 */  lui       $at, 0x3f80
/* B66754 80240CA4 44810000 */  mtc1      $at, $f0
/* B66758 80240CA8 3C014000 */  lui       $at, 0x4000
/* B6675C 80240CAC 44811000 */  mtc1      $at, $f2
/* B66760 80240CB0 3C01C1A0 */  lui       $at, 0xc1a0
/* B66764 80240CB4 44812000 */  mtc1      $at, $f4
/* B66768 80240CB8 44873000 */  mtc1      $a3, $f6
/* B6676C 80240CBC 00000000 */  nop       
/* B66770 80240CC0 468031A0 */  cvt.s.w   $f6, $f6
/* B66774 80240CC4 E7A00010 */  swc1      $f0, 0x10($sp)
/* B66778 80240CC8 E7A20014 */  swc1      $f2, 0x14($sp)
/* B6677C 80240CCC E7A40018 */  swc1      $f4, 0x18($sp)
/* B66780 80240CD0 8E020078 */  lw        $v0, 0x78($s0)
/* B66784 80240CD4 44073000 */  mfc1      $a3, $f6
/* B66788 80240CD8 0000302D */  daddu     $a2, $zero, $zero
/* B6678C 80240CDC AFA30020 */  sw        $v1, 0x20($sp)
/* B66790 80240CE0 2442FFFF */  addiu     $v0, $v0, -1
/* B66794 80240CE4 0C01BFA4 */  jal       fx_emote
/* B66798 80240CE8 AFA2001C */   sw       $v0, 0x1c($sp)
/* B6679C 80240CEC 24020021 */  addiu     $v0, $zero, 0x21
.L80240CF0:
/* B667A0 80240CF0 AE220070 */  sw        $v0, 0x70($s1)
.L80240CF4:
/* B667A4 80240CF4 8FBF0038 */  lw        $ra, 0x38($sp)
/* B667A8 80240CF8 8FB10034 */  lw        $s1, 0x34($sp)
/* B667AC 80240CFC 8FB00030 */  lw        $s0, 0x30($sp)
/* B667B0 80240D00 03E00008 */  jr        $ra
/* B667B4 80240D04 27BD0040 */   addiu    $sp, $sp, 0x40
