.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241478
/* D19C58 80241478 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D19C5C 8024147C AFB10014 */  sw        $s1, 0x14($sp)
/* D19C60 80241480 0080882D */  daddu     $s1, $a0, $zero
/* D19C64 80241484 AFBF0018 */  sw        $ra, 0x18($sp)
/* D19C68 80241488 AFB00010 */  sw        $s0, 0x10($sp)
/* D19C6C 8024148C 8E300148 */  lw        $s0, 0x148($s1)
/* D19C70 80241490 0C00EABB */  jal       get_npc_unsafe
/* D19C74 80241494 86040008 */   lh       $a0, 8($s0)
/* D19C78 80241498 0040202D */  daddu     $a0, $v0, $zero
/* D19C7C 8024149C 9482008E */  lhu       $v0, 0x8e($a0)
/* D19C80 802414A0 2442FFFF */  addiu     $v0, $v0, -1
/* D19C84 802414A4 A482008E */  sh        $v0, 0x8e($a0)
/* D19C88 802414A8 00021400 */  sll       $v0, $v0, 0x10
/* D19C8C 802414AC 8E030098 */  lw        $v1, 0x98($s0)
/* D19C90 802414B0 00021403 */  sra       $v0, $v0, 0x10
/* D19C94 802414B4 0062182A */  slt       $v1, $v1, $v0
/* D19C98 802414B8 14600005 */  bnez      $v1, .L802414D0
/* D19C9C 802414BC 3C03E0EF */   lui      $v1, 0xe0ef
/* D19CA0 802414C0 8E020000 */  lw        $v0, ($s0)
/* D19CA4 802414C4 3463FFFF */  ori       $v1, $v1, 0xffff
/* D19CA8 802414C8 00431024 */  and       $v0, $v0, $v1
/* D19CAC 802414CC AE020000 */  sw        $v0, ($s0)
.L802414D0:
/* D19CB0 802414D0 8482008E */  lh        $v0, 0x8e($a0)
/* D19CB4 802414D4 14400007 */  bnez      $v0, .L802414F4
/* D19CB8 802414D8 00000000 */   nop      
/* D19CBC 802414DC 8E0200CC */  lw        $v0, 0xcc($s0)
/* D19CC0 802414E0 8C420028 */  lw        $v0, 0x28($v0)
/* D19CC4 802414E4 A480008E */  sh        $zero, 0x8e($a0)
/* D19CC8 802414E8 AC820028 */  sw        $v0, 0x28($a0)
/* D19CCC 802414EC 2402000C */  addiu     $v0, $zero, 0xc
/* D19CD0 802414F0 AE220070 */  sw        $v0, 0x70($s1)
.L802414F4:
/* D19CD4 802414F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D19CD8 802414F8 8FB10014 */  lw        $s1, 0x14($sp)
/* D19CDC 802414FC 8FB00010 */  lw        $s0, 0x10($sp)
/* D19CE0 80241500 03E00008 */  jr        $ra
/* D19CE4 80241504 27BD0020 */   addiu    $sp, $sp, 0x20
