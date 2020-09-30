.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel save_ground_pos
/* 7E990 800E54E0 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 7E994 800E54E4 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 7E998 800E54E8 C4600028 */  lwc1      $f0, 0x28($v1)
/* 7E99C 800E54EC C4620030 */  lwc1      $f2, 0x30($v1)
/* 7E9A0 800E54F0 4600010D */  trunc.w.s $f4, $f0
/* 7E9A4 800E54F4 44022000 */  mfc1      $v0, $f4
/* 7E9A8 800E54F8 C460002C */  lwc1      $f0, 0x2c($v1)
/* 7E9AC 800E54FC A4620016 */  sh        $v0, 0x16($v1)
/* 7E9B0 800E5500 4600010D */  trunc.w.s $f4, $f0
/* 7E9B4 800E5504 44022000 */  mfc1      $v0, $f4
/* 7E9B8 800E5508 00000000 */  nop       
/* 7E9BC 800E550C A4620018 */  sh        $v0, 0x18($v1)
/* 7E9C0 800E5510 4600110D */  trunc.w.s $f4, $f2
/* 7E9C4 800E5514 44022000 */  mfc1      $v0, $f4
/* 7E9C8 800E5518 03E00008 */  jr        $ra
/* 7E9CC 800E551C A462001A */   sh       $v0, 0x1a($v1)
