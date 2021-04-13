.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035DB0
/* 111B0 80035DB0 3C058007 */  lui       $a1, %hi(D_8007417C)
/* 111B4 80035DB4 8CA5417C */  lw        $a1, %lo(D_8007417C)($a1)
/* 111B8 80035DB8 84A40088 */  lh        $a0, 0x88($a1)
/* 111BC 80035DBC 84A30086 */  lh        $v1, 0x86($a1)
/* 111C0 80035DC0 24020014 */  addiu     $v0, $zero, 0x14
/* 111C4 80035DC4 3C01800A */  lui       $at, %hi(D_8009E750)
/* 111C8 80035DC8 A420E750 */  sh        $zero, %lo(D_8009E750)($at)
/* 111CC 80035DCC 3C01800A */  lui       $at, %hi(D_8009E752)
/* 111D0 80035DD0 A422E752 */  sh        $v0, %lo(D_8009E752)($at)
/* 111D4 80035DD4 3C01800A */  lui       $at, %hi(D_8009E754)
/* 111D8 80035DD8 A420E754 */  sh        $zero, %lo(D_8009E754)($at)
/* 111DC 80035DDC 10830005 */  beq       $a0, $v1, .L80035DF4
/* 111E0 80035DE0 24020001 */   addiu    $v0, $zero, 1
/* 111E4 80035DE4 94A30086 */  lhu       $v1, 0x86($a1)
/* 111E8 80035DE8 A4A2008A */  sh        $v0, 0x8a($a1)
/* 111EC 80035DEC 03E00008 */  jr        $ra
/* 111F0 80035DF0 A4A30088 */   sh       $v1, 0x88($a1)
.L80035DF4:
/* 111F4 80035DF4 03E00008 */  jr        $ra
/* 111F8 80035DF8 A4A0008A */   sh       $zero, 0x8a($a1)
