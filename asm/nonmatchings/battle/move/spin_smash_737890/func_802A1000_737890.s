.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_737890
/* 737890 802A1000 3C02800E */  lui       $v0, %hi(gBattleStatus+0xD8)
/* 737894 802A1004 8C42C148 */  lw        $v0, %lo(gBattleStatus+0xD8)($v0)
/* 737898 802A1008 3C0141A0 */  lui       $at, 0x41a0
/* 73789C 802A100C 44810000 */  mtc1      $at, $f0
/* 7378A0 802A1010 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7378A4 802A1014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7378A8 802A1018 C4420144 */  lwc1      $f2, 0x144($v0)
/* 7378AC 802A101C 46001080 */  add.s     $f2, $f2, $f0
/* 7378B0 802A1020 0000202D */  daddu     $a0, $zero, $zero
/* 7378B4 802A1024 3C014170 */  lui       $at, 0x4170
/* 7378B8 802A1028 44810000 */  mtc1      $at, $f0
/* 7378BC 802A102C 44051000 */  mfc1      $a1, $f2
/* 7378C0 802A1030 C4420148 */  lwc1      $f2, 0x148($v0)
/* 7378C4 802A1034 C444014C */  lwc1      $f4, 0x14c($v0)
/* 7378C8 802A1038 46001080 */  add.s     $f2, $f2, $f0
/* 7378CC 802A103C 3C0140A0 */  lui       $at, 0x40a0
/* 7378D0 802A1040 44810000 */  mtc1      $at, $f0
/* 7378D4 802A1044 24020006 */  addiu     $v0, $zero, 6
/* 7378D8 802A1048 46002100 */  add.s     $f4, $f4, $f0
/* 7378DC 802A104C AFA20010 */  sw        $v0, 0x10($sp)
/* 7378E0 802A1050 44061000 */  mfc1      $a2, $f2
/* 7378E4 802A1054 44072000 */  mfc1      $a3, $f4
/* 7378E8 802A1058 24020014 */  addiu     $v0, $zero, 0x14
/* 7378EC 802A105C 0C01C25C */  jal       func_80070970
/* 7378F0 802A1060 AFA20014 */   sw       $v0, 0x14($sp)
/* 7378F4 802A1064 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7378F8 802A1068 24020002 */  addiu     $v0, $zero, 2
/* 7378FC 802A106C 03E00008 */  jr        $ra
/* 737900 802A1070 27BD0020 */   addiu    $sp, $sp, 0x20
