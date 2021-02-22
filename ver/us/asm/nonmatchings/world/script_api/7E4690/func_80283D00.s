.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283D00
/* 7E4B80 80283D00 0080282D */  daddu     $a1, $a0, $zero
/* 7E4B84 80283D04 8CA20090 */  lw        $v0, 0x90($a1)
/* 7E4B88 80283D08 04400009 */  bltz      $v0, .L80283D30
/* 7E4B8C 80283D0C 2403FFFF */   addiu    $v1, $zero, -1
/* 7E4B90 80283D10 3C02802E */  lui       $v0, %hi(D_802DBD28)
/* 7E4B94 80283D14 2442BD28 */  addiu     $v0, $v0, %lo(D_802DBD28)
/* 7E4B98 80283D18 8CA4008C */  lw        $a0, 0x8c($a1)
/* 7E4B9C 80283D1C AC430004 */  sw        $v1, 4($v0)
/* 7E4BA0 80283D20 3C01802E */  lui       $at, %hi(D_802DBC7C)
/* 7E4BA4 80283D24 AC23BC7C */  sw        $v1, %lo(D_802DBC7C)($at)
/* 7E4BA8 80283D28 080A0F55 */  j         .L80283D54
/* 7E4BAC 80283D2C AC440000 */   sw       $a0, ($v0)
.L80283D30:
/* 7E4BB0 80283D30 3C02802E */  lui       $v0, %hi(D_802DBC7C)
/* 7E4BB4 80283D34 2442BC7C */  addiu     $v0, $v0, %lo(D_802DBC7C)
/* 7E4BB8 80283D38 8CA4008C */  lw        $a0, 0x8c($a1)
/* 7E4BBC 80283D3C AC430004 */  sw        $v1, 4($v0)
/* 7E4BC0 80283D40 3C01802E */  lui       $at, %hi(D_802DBD28)
/* 7E4BC4 80283D44 AC23BD28 */  sw        $v1, %lo(D_802DBD28)($at)
/* 7E4BC8 80283D48 AC440000 */  sw        $a0, ($v0)
/* 7E4BCC 80283D4C 3C02802E */  lui       $v0, %hi(D_802DBD28)
/* 7E4BD0 80283D50 2442BD28 */  addiu     $v0, $v0, %lo(D_802DBD28)
.L80283D54:
/* 7E4BD4 80283D54 ACA2008C */  sw        $v0, 0x8c($a1)
/* 7E4BD8 80283D58 3C02802E */  lui       $v0, %hi(D_802DBC7C)
/* 7E4BDC 80283D5C 2442BC7C */  addiu     $v0, $v0, %lo(D_802DBC7C)
/* 7E4BE0 80283D60 ACA20090 */  sw        $v0, 0x90($a1)
/* 7E4BE4 80283D64 03E00008 */  jr        $ra
/* 7E4BE8 80283D68 24020002 */   addiu    $v0, $zero, 2
