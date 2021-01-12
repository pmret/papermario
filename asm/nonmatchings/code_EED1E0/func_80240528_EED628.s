.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240528_EED628
/* EED628 80240528 3C028011 */  lui       $v0, %hi(D_80117852)
/* EED62C 8024052C 80427852 */  lb        $v0, %lo(D_80117852)($v0)
/* EED630 80240530 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EED634 80240534 AFBF0010 */  sw        $ra, 0x10($sp)
/* EED638 80240538 00021100 */  sll       $v0, $v0, 4
/* EED63C 8024053C 3C048009 */  lui       $a0, %hi(D_80094900)
/* EED640 80240540 00822021 */  addu      $a0, $a0, $v0
/* EED644 80240544 8C844900 */  lw        $a0, %lo(D_80094900)($a0)
/* EED648 80240548 0C04C31D */  jal       func_80130C74
/* EED64C 8024054C 0000282D */   daddu    $a1, $zero, $zero
/* EED650 80240550 8FBF0010 */  lw        $ra, 0x10($sp)
/* EED654 80240554 24020002 */  addiu     $v0, $zero, 2
/* EED658 80240558 03E00008 */  jr        $ra
/* EED65C 8024055C 27BD0018 */   addiu    $sp, $sp, 0x18
