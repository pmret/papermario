.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80034BFC
/* FFFC 80034BFC 3C02800A */  lui       $v0, 0x800a
/* 10000 80034C00 84420922 */  lh        $v0, 0x922($v0)
/* 10004 80034C04 18400005 */  blez      $v0, .L80034C1C
/* 10008 80034C08 24020004 */   addiu    $v0, $zero, 4
/* 1000C 80034C0C 3C01800A */  lui       $at, 0x800a
/* 10010 80034C10 A0200921 */  sb        $zero, 0x921($at)
/* 10014 80034C14 0800D30B */  j         .L80034C2C
/* 10018 80034C18 00000000 */   nop      
.L80034C1C:
/* 1001C 80034C1C 24020001 */  addiu     $v0, $zero, 1
/* 10020 80034C20 3C01800A */  lui       $at, 0x800a
/* 10024 80034C24 A0220921 */  sb        $v0, 0x921($at)
/* 10028 80034C28 24020004 */  addiu     $v0, $zero, 4
.L80034C2C:
/* 1002C 80034C2C 3C01800A */  lui       $at, 0x800a
/* 10030 80034C30 A0220920 */  sb        $v0, 0x920($at)
/* 10034 80034C34 03E00008 */  jr        $ra
/* 10038 80034C38 00000000 */   nop      
