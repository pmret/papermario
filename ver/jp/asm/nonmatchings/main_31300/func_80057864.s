.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057864
/* 32C64 80057864 308400FF */  andi      $a0, $a0, 0xff
/* 32C68 80057868 00041940 */  sll       $v1, $a0, 5
/* 32C6C 8005786C 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 32C70 80057870 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 32C74 80057874 00641823 */  subu      $v1, $v1, $a0
/* 32C78 80057878 8C42001C */  lw        $v0, 0x1c($v0)
/* 32C7C 8005787C 00031880 */  sll       $v1, $v1, 2
/* 32C80 80057880 00431021 */  addu      $v0, $v0, $v1
/* 32C84 80057884 03E00008 */  jr        $ra
/* 32C88 80057888 C440003C */   lwc1     $f0, 0x3c($v0)
