.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C6A0
/* 47AA0 8006C6A0 3C02A404 */  lui       $v0, 0xa404
/* 47AA4 8006C6A4 34420010 */  ori       $v0, $v0, 0x10
/* 47AA8 8006C6A8 8C420000 */  lw        $v0, ($v0)
/* 47AAC 8006C6AC 3042001C */  andi      $v0, $v0, 0x1c
/* 47AB0 8006C6B0 03E00008 */  jr        $ra
/* 47AB4 8006C6B4 0002102B */   sltu     $v0, $zero, $v0
/* 47AB8 8006C6B8 00000000 */  nop
/* 47ABC 8006C6BC 00000000 */  nop
