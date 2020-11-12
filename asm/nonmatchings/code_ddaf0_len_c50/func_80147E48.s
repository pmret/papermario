.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80147E48
/* DE548 80147E48 3C028016 */  lui       $v0, %hi(gUIPanels)
/* DE54C 80147E4C 24429D50 */  addiu     $v0, $v0, %lo(gUIPanels)
/* DE550 80147E50 00042140 */  sll       $a0, $a0, 5
/* DE554 80147E54 00822021 */  addu      $a0, $a0, $v0
/* DE558 80147E58 90830000 */  lbu       $v1, ($a0)
/* DE55C 80147E5C 30620001 */  andi      $v0, $v1, 1
/* DE560 80147E60 10400004 */  beqz      $v0, .L80147E74
/* DE564 80147E64 3462000A */   ori      $v0, $v1, 0xa
/* DE568 80147E68 A0820000 */  sb        $v0, ($a0)
/* DE56C 80147E6C AC860008 */  sw        $a2, 8($a0)
/* DE570 80147E70 A0850002 */  sb        $a1, 2($a0)
.L80147E74:
/* DE574 80147E74 03E00008 */  jr        $ra
/* DE578 80147E78 00000000 */   nop      
