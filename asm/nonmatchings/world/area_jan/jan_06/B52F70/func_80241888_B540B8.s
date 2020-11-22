.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* B540B8 80241888 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B540BC 8024188C AFB10014 */  sw        $s1, 0x14($sp)
/* B540C0 80241890 0080882D */  daddu     $s1, $a0, $zero
/* B540C4 80241894 AFBF0018 */  sw        $ra, 0x18($sp)
/* B540C8 80241898 AFB00010 */  sw        $s0, 0x10($sp)
/* B540CC 8024189C 8E300148 */  lw        $s0, 0x148($s1)
/* B540D0 802418A0 0C00EABB */  jal       get_npc_unsafe
/* B540D4 802418A4 86040008 */   lh       $a0, 8($s0)
/* B540D8 802418A8 0040202D */  daddu     $a0, $v0, $zero
/* B540DC 802418AC 9482008E */  lhu       $v0, 0x8e($a0)
/* B540E0 802418B0 2442FFFF */  addiu     $v0, $v0, -1
/* B540E4 802418B4 A482008E */  sh        $v0, 0x8e($a0)
/* B540E8 802418B8 00021400 */  sll       $v0, $v0, 0x10
/* B540EC 802418BC 1C400009 */  bgtz      $v0, .L802418E4
/* B540F0 802418C0 24020003 */   addiu    $v0, $zero, 3
/* B540F4 802418C4 96030076 */  lhu       $v1, 0x76($s0)
/* B540F8 802418C8 AE02006C */  sw        $v0, 0x6c($s0)
/* B540FC 802418CC A483008E */  sh        $v1, 0x8e($a0)
/* B54100 802418D0 8E0200CC */  lw        $v0, 0xcc($s0)
/* B54104 802418D4 8C420024 */  lw        $v0, 0x24($v0)
/* B54108 802418D8 AC820028 */  sw        $v0, 0x28($a0)
/* B5410C 802418DC 24020020 */  addiu     $v0, $zero, 0x20
/* B54110 802418E0 AE220070 */  sw        $v0, 0x70($s1)
.L802418E4:
/* B54114 802418E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* B54118 802418E8 8FB10014 */  lw        $s1, 0x14($sp)
/* B5411C 802418EC 8FB00010 */  lw        $s0, 0x10($sp)
/* B54120 802418F0 03E00008 */  jr        $ra
/* B54124 802418F4 27BD0020 */   addiu    $sp, $sp, 0x20
