.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283E2C
/* 7E4CAC 80283E2C 8C82008C */  lw        $v0, 0x8c($a0)
/* 7E4CB0 80283E30 3C05802E */  lui       $a1, %hi(D_802DBD28)
/* 7E4CB4 80283E34 24A5BD28 */  addiu     $a1, $a1, %lo(D_802DBD28)
/* 7E4CB8 80283E38 ACA20000 */  sw        $v0, ($a1)
/* 7E4CBC 80283E3C 8C820094 */  lw        $v0, 0x94($a0)
/* 7E4CC0 80283E40 2406FFFF */  addiu     $a2, $zero, -1
/* 7E4CC4 80283E44 ACA60008 */  sw        $a2, 8($a1)
/* 7E4CC8 80283E48 ACA20004 */  sw        $v0, 4($a1)
/* 7E4CCC 80283E4C 8C830090 */  lw        $v1, 0x90($a0)
/* 7E4CD0 80283E50 3C02802E */  lui       $v0, %hi(D_802DBC7C)
/* 7E4CD4 80283E54 2442BC7C */  addiu     $v0, $v0, %lo(D_802DBC7C)
/* 7E4CD8 80283E58 AC430000 */  sw        $v1, ($v0)
/* 7E4CDC 80283E5C 8C830098 */  lw        $v1, 0x98($a0)
/* 7E4CE0 80283E60 AC460008 */  sw        $a2, 8($v0)
/* 7E4CE4 80283E64 AC430004 */  sw        $v1, 4($v0)
/* 7E4CE8 80283E68 AC820090 */  sw        $v0, 0x90($a0)
/* 7E4CEC 80283E6C 24020002 */  addiu     $v0, $zero, 2
/* 7E4CF0 80283E70 03E00008 */  jr        $ra
/* 7E4CF4 80283E74 AC85008C */   sw       $a1, 0x8c($a0)
/* 7E4CF8 80283E78 00000000 */  nop       
/* 7E4CFC 80283E7C 00000000 */  nop       
