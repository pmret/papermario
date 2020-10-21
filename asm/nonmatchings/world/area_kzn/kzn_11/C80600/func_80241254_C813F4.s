.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241254_C813F4
/* C813F4 80241254 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C813F8 80241258 AFB00010 */  sw        $s0, 0x10($sp)
/* C813FC 8024125C 0080802D */  daddu     $s0, $a0, $zero
/* C81400 80241260 AFBF0014 */  sw        $ra, 0x14($sp)
/* C81404 80241264 8E020148 */  lw        $v0, 0x148($s0)
/* C81408 80241268 0C00EABB */  jal       get_npc_unsafe
/* C8140C 8024126C 84440008 */   lh       $a0, 8($v0)
/* C81410 80241270 0040202D */  daddu     $a0, $v0, $zero
/* C81414 80241274 8482008E */  lh        $v0, 0x8e($a0)
/* C81418 80241278 9483008E */  lhu       $v1, 0x8e($a0)
/* C8141C 8024127C 18400005 */  blez      $v0, .L80241294
/* C81420 80241280 2462FFFF */   addiu    $v0, $v1, -1
/* C81424 80241284 A482008E */  sh        $v0, 0x8e($a0)
/* C81428 80241288 00021400 */  sll       $v0, $v0, 0x10
/* C8142C 8024128C 1C400006 */  bgtz      $v0, .L802412A8
/* C81430 80241290 00000000 */   nop      
.L80241294:
/* C81434 80241294 8482008C */  lh        $v0, 0x8c($a0)
/* C81438 80241298 14400003 */  bnez      $v0, .L802412A8
/* C8143C 8024129C 2402000E */   addiu    $v0, $zero, 0xe
/* C81440 802412A0 A480008E */  sh        $zero, 0x8e($a0)
/* C81444 802412A4 AE020070 */  sw        $v0, 0x70($s0)
.L802412A8:
/* C81448 802412A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* C8144C 802412AC 8FB00010 */  lw        $s0, 0x10($sp)
/* C81450 802412B0 03E00008 */  jr        $ra
/* C81454 802412B4 27BD0018 */   addiu    $sp, $sp, 0x18
