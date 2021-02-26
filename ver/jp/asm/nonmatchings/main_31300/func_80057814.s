.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057814
/* 32C14 80057814 308400FF */  andi      $a0, $a0, 0xff
/* 32C18 80057818 00041940 */  sll       $v1, $a0, 5
/* 32C1C 8005781C 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 32C20 80057820 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 32C24 80057824 00641823 */  subu      $v1, $v1, $a0
/* 32C28 80057828 8C42001C */  lw        $v0, 0x1c($v0)
/* 32C2C 8005782C 00031880 */  sll       $v1, $v1, 2
/* 32C30 80057830 00431021 */  addu      $v0, $v0, $v1
/* 32C34 80057834 03E00008 */  jr        $ra
/* 32C38 80057838 8C420070 */   lw       $v0, 0x70($v0)
