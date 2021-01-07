.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D4BC
/* 288BC 8004D4BC 0000282D */  daddu     $a1, $zero, $zero
/* 288C0 8004D4C0 3C088008 */  lui       $t0, %hi(D_80078464)
/* 288C4 8004D4C4 25088464 */  addiu     $t0, $t0, %lo(D_80078464)
/* 288C8 8004D4C8 24070001 */  addiu     $a3, $zero, 1
/* 288CC 8004D4CC 24060001 */  addiu     $a2, $zero, 1
/* 288D0 8004D4D0 2403016C */  addiu     $v1, $zero, 0x16c
.L8004D4D4:
/* 288D4 8004D4D4 00831021 */  addu      $v0, $a0, $v1
/* 288D8 8004D4D8 24A50001 */  addiu     $a1, $a1, 1
/* 288DC 8004D4DC AC480000 */  sw        $t0, ($v0)
/* 288E0 8004D4E0 AC400080 */  sw        $zero, 0x80($v0)
/* 288E4 8004D4E4 A047009A */  sb        $a3, 0x9a($v0)
/* 288E8 8004D4E8 A04000A9 */  sb        $zero, 0xa9($v0)
/* 288EC 8004D4EC A446008E */  sh        $a2, 0x8e($v0)
/* 288F0 8004D4F0 A0400098 */  sb        $zero, 0x98($v0)
/* 288F4 8004D4F4 A0400099 */  sb        $zero, 0x99($v0)
/* 288F8 8004D4F8 28A20008 */  slti      $v0, $a1, 8
/* 288FC 8004D4FC 1440FFF5 */  bnez      $v0, .L8004D4D4
/* 28900 8004D500 246300AC */   addiu    $v1, $v1, 0xac
/* 28904 8004D504 03E00008 */  jr        $ra
/* 28908 8004D508 00000000 */   nop      
/* 2890C 8004D50C 00000000 */  nop       
