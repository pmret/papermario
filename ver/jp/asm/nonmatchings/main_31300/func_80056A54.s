.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056A54
/* 31E54 80056A54 308400FF */  andi      $a0, $a0, 0xff
/* 31E58 80056A58 00041840 */  sll       $v1, $a0, 1
/* 31E5C 80056A5C 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 31E60 80056A60 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 31E64 80056A64 00641821 */  addu      $v1, $v1, $a0
/* 31E68 80056A68 8C420020 */  lw        $v0, 0x20($v0)
/* 31E6C 80056A6C 000318C0 */  sll       $v1, $v1, 3
/* 31E70 80056A70 00431021 */  addu      $v0, $v0, $v1
/* 31E74 80056A74 03E00008 */  jr        $ra
/* 31E78 80056A78 94420000 */   lhu      $v0, ($v0)
