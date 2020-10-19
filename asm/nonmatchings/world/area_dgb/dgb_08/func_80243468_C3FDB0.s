.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243468_C43218
/* C43218 80243468 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C4321C 8024346C AFB00010 */  sw        $s0, 0x10($sp)
/* C43220 80243470 0080802D */  daddu     $s0, $a0, $zero
/* C43224 80243474 AFBF0014 */  sw        $ra, 0x14($sp)
/* C43228 80243478 8E020148 */  lw        $v0, 0x148($s0)
/* C4322C 8024347C 0C00EABB */  jal       get_npc_unsafe
/* C43230 80243480 84440008 */   lh       $a0, 8($v0)
/* C43234 80243484 9443008E */  lhu       $v1, 0x8e($v0)
/* C43238 80243488 2463FFFF */  addiu     $v1, $v1, -1
/* C4323C 8024348C A443008E */  sh        $v1, 0x8e($v0)
/* C43240 80243490 00031C00 */  sll       $v1, $v1, 0x10
/* C43244 80243494 1C600002 */  bgtz      $v1, .L802434A0
/* C43248 80243498 2402001E */   addiu    $v0, $zero, 0x1e
/* C4324C 8024349C AE020070 */  sw        $v0, 0x70($s0)
.L802434A0:
/* C43250 802434A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* C43254 802434A4 8FB00010 */  lw        $s0, 0x10($sp)
/* C43258 802434A8 03E00008 */  jr        $ra
/* C4325C 802434AC 27BD0018 */   addiu    $sp, $sp, 0x18
