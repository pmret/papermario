.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283D6C
/* 7E4BEC 80283D6C 0080282D */  daddu     $a1, $a0, $zero
/* 7E4BF0 80283D70 8CA20090 */  lw        $v0, 0x90($a1)
/* 7E4BF4 80283D74 0440000C */  bltz      $v0, .L80283DA8
/* 7E4BF8 80283D78 00000000 */   nop      
/* 7E4BFC 80283D7C 8CA2008C */  lw        $v0, 0x8c($a1)
/* 7E4C00 80283D80 3C03802E */  lui       $v1, 0x802e
/* 7E4C04 80283D84 2463BD28 */  addiu     $v1, $v1, -0x42d8
/* 7E4C08 80283D88 AC620000 */  sw        $v0, ($v1)
/* 7E4C0C 80283D8C 8CA40094 */  lw        $a0, 0x94($a1)
/* 7E4C10 80283D90 2402FFFF */  addiu     $v0, $zero, -1
/* 7E4C14 80283D94 AC620008 */  sw        $v0, 8($v1)
/* 7E4C18 80283D98 3C01802E */  lui       $at, 0x802e
/* 7E4C1C 80283D9C AC22BC7C */  sw        $v0, -0x4384($at)
/* 7E4C20 80283DA0 080A0F74 */  j         .L80283DD0
/* 7E4C24 80283DA4 AC640004 */   sw       $a0, 4($v1)
.L80283DA8:
/* 7E4C28 80283DA8 8CA2008C */  lw        $v0, 0x8c($a1)
/* 7E4C2C 80283DAC 3C03802E */  lui       $v1, 0x802e
/* 7E4C30 80283DB0 2463BC7C */  addiu     $v1, $v1, -0x4384
/* 7E4C34 80283DB4 AC620000 */  sw        $v0, ($v1)
/* 7E4C38 80283DB8 8CA40094 */  lw        $a0, 0x94($a1)
/* 7E4C3C 80283DBC 2402FFFF */  addiu     $v0, $zero, -1
/* 7E4C40 80283DC0 AC620008 */  sw        $v0, 8($v1)
/* 7E4C44 80283DC4 3C01802E */  lui       $at, 0x802e
/* 7E4C48 80283DC8 AC22BD28 */  sw        $v0, -0x42d8($at)
/* 7E4C4C 80283DCC AC640004 */  sw        $a0, 4($v1)
.L80283DD0:
/* 7E4C50 80283DD0 3C02802E */  lui       $v0, 0x802e
/* 7E4C54 80283DD4 2442BD28 */  addiu     $v0, $v0, -0x42d8
/* 7E4C58 80283DD8 ACA2008C */  sw        $v0, 0x8c($a1)
/* 7E4C5C 80283DDC 3C02802E */  lui       $v0, 0x802e
/* 7E4C60 80283DE0 2442BC7C */  addiu     $v0, $v0, -0x4384
/* 7E4C64 80283DE4 ACA20090 */  sw        $v0, 0x90($a1)
/* 7E4C68 80283DE8 03E00008 */  jr        $ra
/* 7E4C6C 80283DEC 24020002 */   addiu    $v0, $zero, 2
