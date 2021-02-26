.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065F00
/* 41300 80065F00 14800003 */  bnez      $a0, .L80065F10
/* 41304 80065F04 00000000 */   nop
/* 41308 80065F08 3C048009 */  lui       $a0, %hi(D_80094640)
/* 4130C 80065F0C 8C844640 */  lw        $a0, %lo(D_80094640)($a0)
.L80065F10:
/* 41310 80065F10 03E00008 */  jr        $ra
/* 41314 80065F14 8C820004 */   lw       $v0, 4($a0)
/* 41318 80065F18 00000000 */  nop
/* 4131C 80065F1C 00000000 */  nop
