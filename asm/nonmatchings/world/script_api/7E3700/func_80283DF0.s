.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283DF0
/* 7E4C70 80283DF0 3C03802E */  lui       $v1, %hi(D_802DBD28)
/* 7E4C74 80283DF4 2463BD28 */  addiu     $v1, $v1, %lo(D_802DBD28)
/* 7E4C78 80283DF8 8C82008C */  lw        $v0, 0x8c($a0)
/* 7E4C7C 80283DFC 2406FFFF */  addiu     $a2, $zero, -1
/* 7E4C80 80283E00 AC660004 */  sw        $a2, 4($v1)
/* 7E4C84 80283E04 AC620000 */  sw        $v0, ($v1)
/* 7E4C88 80283E08 8C850090 */  lw        $a1, 0x90($a0)
/* 7E4C8C 80283E0C 3C02802E */  lui       $v0, %hi(D_802DBC7C)
/* 7E4C90 80283E10 2442BC7C */  addiu     $v0, $v0, %lo(D_802DBC7C)
/* 7E4C94 80283E14 AC460004 */  sw        $a2, 4($v0)
/* 7E4C98 80283E18 AC450000 */  sw        $a1, ($v0)
/* 7E4C9C 80283E1C AC820090 */  sw        $v0, 0x90($a0)
/* 7E4CA0 80283E20 24020002 */  addiu     $v0, $zero, 2
/* 7E4CA4 80283E24 03E00008 */  jr        $ra
/* 7E4CA8 80283E28 AC83008C */   sw       $v1, 0x8c($a0)
