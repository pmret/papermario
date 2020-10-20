.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C84_BE5434
/* BE5434 80241C84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BE5438 80241C88 AFB00010 */  sw        $s0, 0x10($sp)
/* BE543C 80241C8C 0080802D */  daddu     $s0, $a0, $zero
/* BE5440 80241C90 AFBF0014 */  sw        $ra, 0x14($sp)
/* BE5444 80241C94 8E020148 */  lw        $v0, 0x148($s0)
/* BE5448 80241C98 0C00EABB */  jal       get_npc_unsafe
/* BE544C 80241C9C 84440008 */   lh       $a0, 8($v0)
/* BE5450 80241CA0 0040202D */  daddu     $a0, $v0, $zero
/* BE5454 80241CA4 8482008E */  lh        $v0, 0x8e($a0)
/* BE5458 80241CA8 9483008E */  lhu       $v1, 0x8e($a0)
/* BE545C 80241CAC 18400005 */  blez      $v0, .L80241CC4
/* BE5460 80241CB0 2462FFFF */   addiu    $v0, $v1, -1
/* BE5464 80241CB4 A482008E */  sh        $v0, 0x8e($a0)
/* BE5468 80241CB8 00021400 */  sll       $v0, $v0, 0x10
/* BE546C 80241CBC 1C400006 */  bgtz      $v0, .L80241CD8
/* BE5470 80241CC0 00000000 */   nop      
.L80241CC4:
/* BE5474 80241CC4 8482008C */  lh        $v0, 0x8c($a0)
/* BE5478 80241CC8 14400003 */  bnez      $v0, .L80241CD8
/* BE547C 80241CCC 2402000E */   addiu    $v0, $zero, 0xe
/* BE5480 80241CD0 A480008E */  sh        $zero, 0x8e($a0)
/* BE5484 80241CD4 AE020070 */  sw        $v0, 0x70($s0)
.L80241CD8:
/* BE5488 80241CD8 8FBF0014 */  lw        $ra, 0x14($sp)
/* BE548C 80241CDC 8FB00010 */  lw        $s0, 0x10($sp)
/* BE5490 80241CE0 03E00008 */  jr        $ra
/* BE5494 80241CE4 27BD0018 */   addiu    $sp, $sp, 0x18
