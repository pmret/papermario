.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242498_C79178
/* C79178 80242498 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C7917C 8024249C AFB10014 */  sw        $s1, 0x14($sp)
/* C79180 802424A0 0080882D */  daddu     $s1, $a0, $zero
/* C79184 802424A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* C79188 802424A8 AFB00010 */  sw        $s0, 0x10($sp)
/* C7918C 802424AC 8E300148 */  lw        $s0, 0x148($s1)
/* C79190 802424B0 0C00EABB */  jal       get_npc_unsafe
/* C79194 802424B4 86040008 */   lh       $a0, 8($s0)
/* C79198 802424B8 0040202D */  daddu     $a0, $v0, $zero
/* C7919C 802424BC 9482008E */  lhu       $v0, 0x8e($a0)
/* C791A0 802424C0 2442FFFF */  addiu     $v0, $v0, -1
/* C791A4 802424C4 A482008E */  sh        $v0, 0x8e($a0)
/* C791A8 802424C8 00021400 */  sll       $v0, $v0, 0x10
/* C791AC 802424CC 8E030098 */  lw        $v1, 0x98($s0)
/* C791B0 802424D0 00021403 */  sra       $v0, $v0, 0x10
/* C791B4 802424D4 0062182A */  slt       $v1, $v1, $v0
/* C791B8 802424D8 14600005 */  bnez      $v1, .L802424F0
/* C791BC 802424DC 3C03E0EF */   lui      $v1, 0xe0ef
/* C791C0 802424E0 8E020000 */  lw        $v0, ($s0)
/* C791C4 802424E4 3463FFFF */  ori       $v1, $v1, 0xffff
/* C791C8 802424E8 00431024 */  and       $v0, $v0, $v1
/* C791CC 802424EC AE020000 */  sw        $v0, ($s0)
.L802424F0:
/* C791D0 802424F0 8482008E */  lh        $v0, 0x8e($a0)
/* C791D4 802424F4 14400007 */  bnez      $v0, .L80242514
/* C791D8 802424F8 00000000 */   nop      
/* C791DC 802424FC 8E0200CC */  lw        $v0, 0xcc($s0)
/* C791E0 80242500 8C420028 */  lw        $v0, 0x28($v0)
/* C791E4 80242504 A480008E */  sh        $zero, 0x8e($a0)
/* C791E8 80242508 AC820028 */  sw        $v0, 0x28($a0)
/* C791EC 8024250C 2402000C */  addiu     $v0, $zero, 0xc
/* C791F0 80242510 AE220070 */  sw        $v0, 0x70($s1)
.L80242514:
/* C791F4 80242514 8FBF0018 */  lw        $ra, 0x18($sp)
/* C791F8 80242518 8FB10014 */  lw        $s1, 0x14($sp)
/* C791FC 8024251C 8FB00010 */  lw        $s0, 0x10($sp)
/* C79200 80242520 03E00008 */  jr        $ra
/* C79204 80242524 27BD0020 */   addiu    $sp, $sp, 0x20
