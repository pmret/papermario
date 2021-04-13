.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800578B4
/* 32CB4 800578B4 308400FF */  andi      $a0, $a0, 0xff
/* 32CB8 800578B8 00041940 */  sll       $v1, $a0, 5
/* 32CBC 800578BC 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 32CC0 800578C0 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 32CC4 800578C4 00641823 */  subu      $v1, $v1, $a0
/* 32CC8 800578C8 8C42001C */  lw        $v0, 0x1c($v0)
/* 32CCC 800578CC 00031880 */  sll       $v1, $v1, 2
/* 32CD0 800578D0 00431021 */  addu      $v0, $v0, $v1
/* 32CD4 800578D4 03E00008 */  jr        $ra
/* 32CD8 800578D8 84420054 */   lh       $v0, 0x54($v0)
