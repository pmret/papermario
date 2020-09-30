.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056D78
/* 32178 80056D78 308400FF */  andi      $a0, $a0, 0xff
/* 3217C 80056D7C 00041040 */  sll       $v0, $a0, 1
/* 32180 80056D80 00441021 */  addu      $v0, $v0, $a0
/* 32184 80056D84 3C038008 */  lui       $v1, 0x8008
/* 32188 80056D88 8C638E54 */  lw        $v1, -0x71ac($v1)
/* 3218C 80056D8C 000210C0 */  sll       $v0, $v0, 3
/* 32190 80056D90 8C630020 */  lw        $v1, 0x20($v1)
/* 32194 80056D94 30A57FFF */  andi      $a1, $a1, 0x7fff
/* 32198 80056D98 00621821 */  addu      $v1, $v1, $v0
/* 3219C 80056D9C 03E00008 */  jr        $ra
/* 321A0 80056DA0 A4650000 */   sh       $a1, ($v1)
