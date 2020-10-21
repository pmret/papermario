.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A0_8AC430
/* 8AC430 802404A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8AC434 802404A4 2402001E */  addiu     $v0, $zero, 0x1e
/* 8AC438 802404A8 44801000 */  mtc1      $zero, $f2
/* 8AC43C 802404AC 3C013E99 */  lui       $at, 0x3e99
/* 8AC440 802404B0 3421999A */  ori       $at, $at, 0x999a
/* 8AC444 802404B4 44810000 */  mtc1      $at, $f0
/* 8AC448 802404B8 44051000 */  mfc1      $a1, $f2
/* 8AC44C 802404BC 24040004 */  addiu     $a0, $zero, 4
/* 8AC450 802404C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8AC454 802404C4 AFA20014 */  sw        $v0, 0x14($sp)
/* 8AC458 802404C8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8AC45C 802404CC 00A0302D */  daddu     $a2, $a1, $zero
/* 8AC460 802404D0 0C01C5D4 */  jal       func_80071750
/* 8AC464 802404D4 00A0382D */   daddu    $a3, $a1, $zero
/* 8AC468 802404D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8AC46C 802404DC 24020002 */  addiu     $v0, $zero, 2
/* 8AC470 802404E0 03E00008 */  jr        $ra
/* 8AC474 802404E4 27BD0020 */   addiu    $sp, $sp, 0x20
