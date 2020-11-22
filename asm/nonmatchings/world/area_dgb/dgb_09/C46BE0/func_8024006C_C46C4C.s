.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* C46C4C 8024006C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C46C50 80240070 AFB10014 */  sw        $s1, 0x14($sp)
/* C46C54 80240074 0080882D */  daddu     $s1, $a0, $zero
/* C46C58 80240078 AFBF0018 */  sw        $ra, 0x18($sp)
/* C46C5C 8024007C AFB00010 */  sw        $s0, 0x10($sp)
/* C46C60 80240080 8E300148 */  lw        $s0, 0x148($s1)
/* C46C64 80240084 0C00EABB */  jal       get_npc_unsafe
/* C46C68 80240088 86040008 */   lh       $a0, 8($s0)
/* C46C6C 8024008C 0040202D */  daddu     $a0, $v0, $zero
/* C46C70 80240090 9482008E */  lhu       $v0, 0x8e($a0)
/* C46C74 80240094 2442FFFF */  addiu     $v0, $v0, -1
/* C46C78 80240098 A482008E */  sh        $v0, 0x8e($a0)
/* C46C7C 8024009C 00021400 */  sll       $v0, $v0, 0x10
/* C46C80 802400A0 1C400009 */  bgtz      $v0, .L802400C8
/* C46C84 802400A4 24020003 */   addiu    $v0, $zero, 3
/* C46C88 802400A8 96030076 */  lhu       $v1, 0x76($s0)
/* C46C8C 802400AC AE02006C */  sw        $v0, 0x6c($s0)
/* C46C90 802400B0 A483008E */  sh        $v1, 0x8e($a0)
/* C46C94 802400B4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C46C98 802400B8 8C420024 */  lw        $v0, 0x24($v0)
/* C46C9C 802400BC AC820028 */  sw        $v0, 0x28($a0)
/* C46CA0 802400C0 24020020 */  addiu     $v0, $zero, 0x20
/* C46CA4 802400C4 AE220070 */  sw        $v0, 0x70($s1)
.L802400C8:
/* C46CA8 802400C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C46CAC 802400CC 8FB10014 */  lw        $s1, 0x14($sp)
/* C46CB0 802400D0 8FB00010 */  lw        $s0, 0x10($sp)
/* C46CB4 802400D4 03E00008 */  jr        $ra
/* C46CB8 802400D8 27BD0020 */   addiu    $sp, $sp, 0x20
