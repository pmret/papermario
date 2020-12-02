.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057C04
/* 33004 80057C04 308400FF */  andi      $a0, $a0, 0xff
/* 33008 80057C08 00041940 */  sll       $v1, $a0, 5
/* 3300C 80057C0C 3C028008 */  lui       $v0, %hi(D_80078E54)
/* 33010 80057C10 8C428E54 */  lw        $v0, %lo(D_80078E54)($v0)
/* 33014 80057C14 00641823 */  subu      $v1, $v1, $a0
/* 33018 80057C18 8C42001C */  lw        $v0, 0x1c($v0)
/* 3301C 80057C1C 00031880 */  sll       $v1, $v1, 2
/* 33020 80057C20 00431021 */  addu      $v0, $v0, $v1
/* 33024 80057C24 03E00008 */  jr        $ra
/* 33028 80057C28 84420054 */   lh       $v0, 0x54($v0)
