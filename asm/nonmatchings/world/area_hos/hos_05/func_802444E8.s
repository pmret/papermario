.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802444E8
/* A2E728 802444E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2E72C 802444EC AFBF0010 */  sw        $ra, 0x10($sp)
/* A2E730 802444F0 0C0B36B0 */  jal       resolve_npc
/* A2E734 802444F4 2405000A */   addiu    $a1, $zero, 0xa
/* A2E738 802444F8 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* A2E73C 802444FC 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* A2E740 80244500 3C014334 */  lui       $at, 0x4334
/* A2E744 80244504 44810000 */  mtc1      $at, $f0
/* A2E748 80244508 00041880 */  sll       $v1, $a0, 2
/* A2E74C 8024450C 00641821 */  addu      $v1, $v1, $a0
/* A2E750 80244510 00031880 */  sll       $v1, $v1, 2
/* A2E754 80244514 00641823 */  subu      $v1, $v1, $a0
/* A2E758 80244518 000320C0 */  sll       $a0, $v1, 3
/* A2E75C 8024451C 00641821 */  addu      $v1, $v1, $a0
/* A2E760 80244520 000318C0 */  sll       $v1, $v1, 3
/* A2E764 80244524 3C01800B */  lui       $at, 0x800b
/* A2E768 80244528 00230821 */  addu      $at, $at, $v1
/* A2E76C 8024452C C4221DEC */  lwc1      $f2, 0x1dec($at)
/* A2E770 80244530 46020001 */  sub.s     $f0, $f0, $f2
/* A2E774 80244534 0040182D */  daddu     $v1, $v0, $zero
/* A2E778 80244538 E4600034 */  swc1      $f0, 0x34($v1)
/* A2E77C 8024453C E460000C */  swc1      $f0, 0xc($v1)
/* A2E780 80244540 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2E784 80244544 0000102D */  daddu     $v0, $zero, $zero
/* A2E788 80244548 03E00008 */  jr        $ra
/* A2E78C 8024454C 27BD0018 */   addiu    $sp, $sp, 0x18
