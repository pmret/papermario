.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024043C_D37C3C
/* D37C3C 8024043C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D37C40 80240440 AFB10014 */  sw        $s1, 0x14($sp)
/* D37C44 80240444 0080882D */  daddu     $s1, $a0, $zero
/* D37C48 80240448 AFBF0018 */  sw        $ra, 0x18($sp)
/* D37C4C 8024044C AFB00010 */  sw        $s0, 0x10($sp)
/* D37C50 80240450 8E300148 */  lw        $s0, 0x148($s1)
/* D37C54 80240454 0C00EABB */  jal       get_npc_unsafe
/* D37C58 80240458 86040008 */   lh       $a0, 8($s0)
/* D37C5C 8024045C 0040202D */  daddu     $a0, $v0, $zero
/* D37C60 80240460 9482008E */  lhu       $v0, 0x8e($a0)
/* D37C64 80240464 2442FFFF */  addiu     $v0, $v0, -1
/* D37C68 80240468 A482008E */  sh        $v0, 0x8e($a0)
/* D37C6C 8024046C 00021400 */  sll       $v0, $v0, 0x10
/* D37C70 80240470 1C400009 */  bgtz      $v0, .L80240498
/* D37C74 80240474 24020003 */   addiu    $v0, $zero, 3
/* D37C78 80240478 96030076 */  lhu       $v1, 0x76($s0)
/* D37C7C 8024047C AE02006C */  sw        $v0, 0x6c($s0)
/* D37C80 80240480 A483008E */  sh        $v1, 0x8e($a0)
/* D37C84 80240484 8E0200CC */  lw        $v0, 0xcc($s0)
/* D37C88 80240488 8C420024 */  lw        $v0, 0x24($v0)
/* D37C8C 8024048C AC820028 */  sw        $v0, 0x28($a0)
/* D37C90 80240490 24020020 */  addiu     $v0, $zero, 0x20
/* D37C94 80240494 AE220070 */  sw        $v0, 0x70($s1)
.L80240498:
/* D37C98 80240498 8FBF0018 */  lw        $ra, 0x18($sp)
/* D37C9C 8024049C 8FB10014 */  lw        $s1, 0x14($sp)
/* D37CA0 802404A0 8FB00010 */  lw        $s0, 0x10($sp)
/* D37CA4 802404A4 03E00008 */  jr        $ra
/* D37CA8 802404A8 27BD0020 */   addiu    $sp, $sp, 0x20
