.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052614
/* 2DA14 80052614 0000282D */  daddu     $a1, $zero, $zero
/* 2DA18 80052618 24060080 */  addiu     $a2, $zero, 0x80
/* 2DA1C 8005261C 24031320 */  addiu     $v1, $zero, 0x1320
.L80052620:
/* 2DA20 80052620 00831021 */  addu      $v0, $a0, $v1
/* 2DA24 80052624 24A50001 */  addiu     $a1, $a1, 1
/* 2DA28 80052628 AC40001C */  sw        $zero, 0x1c($v0)
/* 2DA2C 8005262C AC400020 */  sw        $zero, 0x20($v0)
/* 2DA30 80052630 AC400024 */  sw        $zero, 0x24($v0)
/* 2DA34 80052634 AC400028 */  sw        $zero, 0x28($v0)
/* 2DA38 80052638 A040003B */  sb        $zero, 0x3b($v0)
/* 2DA3C 8005263C A040003C */  sb        $zero, 0x3c($v0)
/* 2DA40 80052640 A040003D */  sb        $zero, 0x3d($v0)
/* 2DA44 80052644 A040003E */  sb        $zero, 0x3e($v0)
/* 2DA48 80052648 A046003F */  sb        $a2, 0x3f($v0)
/* 2DA4C 8005264C 28A20018 */  slti      $v0, $a1, 0x18
/* 2DA50 80052650 1440FFF3 */  bnez      $v0, .L80052620
/* 2DA54 80052654 24630048 */   addiu    $v1, $v1, 0x48
/* 2DA58 80052658 03E00008 */  jr        $ra
/* 2DA5C 8005265C 00000000 */   nop      
