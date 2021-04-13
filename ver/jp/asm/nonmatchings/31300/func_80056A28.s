.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056A28
/* 31E28 80056A28 308400FF */  andi      $a0, $a0, 0xff
/* 31E2C 80056A2C 00041040 */  sll       $v0, $a0, 1
/* 31E30 80056A30 00441021 */  addu      $v0, $v0, $a0
/* 31E34 80056A34 3C038008 */  lui       $v1, %hi(D_80078E24)
/* 31E38 80056A38 8C638E24 */  lw        $v1, %lo(D_80078E24)($v1)
/* 31E3C 80056A3C 000210C0 */  sll       $v0, $v0, 3
/* 31E40 80056A40 8C630020 */  lw        $v1, 0x20($v1)
/* 31E44 80056A44 30A57FFF */  andi      $a1, $a1, 0x7fff
/* 31E48 80056A48 00621821 */  addu      $v1, $v1, $v0
/* 31E4C 80056A4C 03E00008 */  jr        $ra
/* 31E50 80056A50 A4650000 */   sh       $a1, ($v1)
