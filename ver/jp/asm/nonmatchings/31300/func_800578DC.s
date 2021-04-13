.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800578DC
/* 32CDC 800578DC 308400FF */  andi      $a0, $a0, 0xff
/* 32CE0 800578E0 00041940 */  sll       $v1, $a0, 5
/* 32CE4 800578E4 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 32CE8 800578E8 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 32CEC 800578EC 00641823 */  subu      $v1, $v1, $a0
/* 32CF0 800578F0 8C42001C */  lw        $v0, 0x1c($v0)
/* 32CF4 800578F4 00031880 */  sll       $v1, $v1, 2
/* 32CF8 800578F8 00431021 */  addu      $v0, $v0, $v1
/* 32CFC 800578FC 03E00008 */  jr        $ra
/* 32D00 80057900 84420056 */   lh       $v0, 0x56($v0)
