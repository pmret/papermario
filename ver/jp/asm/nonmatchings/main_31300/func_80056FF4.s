.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056FF4
/* 323F4 80056FF4 308400FF */  andi      $a0, $a0, 0xff
/* 323F8 80056FF8 00041940 */  sll       $v1, $a0, 5
/* 323FC 80056FFC 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 32400 80057000 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 32404 80057004 00641823 */  subu      $v1, $v1, $a0
/* 32408 80057008 8C42001C */  lw        $v0, 0x1c($v0)
/* 3240C 8005700C 00031880 */  sll       $v1, $v1, 2
/* 32410 80057010 00431021 */  addu      $v0, $v0, $v1
/* 32414 80057014 03E00008 */  jr        $ra
/* 32418 80057018 AC45003C */   sw       $a1, 0x3c($v0)
