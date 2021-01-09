.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E005A3B0
/* 360670 E005A3B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 360674 E005A3B4 3C02E006 */  lui       $v0, %hi(func_E005A3F4)
/* 360678 E005A3B8 2442A3F4 */  addiu     $v0, $v0, %lo(func_E005A3F4)
/* 36067C E005A3BC AFA2001C */  sw        $v0, 0x1c($sp)
/* 360680 E005A3C0 24020028 */  addiu     $v0, $zero, 0x28
/* 360684 E005A3C4 AFA40018 */  sw        $a0, 0x18($sp)
/* 360688 E005A3C8 27A40010 */  addiu     $a0, $sp, 0x10
/* 36068C E005A3CC AFBF0020 */  sw        $ra, 0x20($sp)
/* 360690 E005A3D0 AFA00014 */  sw        $zero, 0x14($sp)
/* 360694 E005A3D4 0C080120 */  jal       func_E0200480
/* 360698 E005A3D8 AFA20010 */   sw       $v0, 0x10($sp)
/* 36069C E005A3DC 8C430000 */  lw        $v1, ($v0)
/* 3606A0 E005A3E0 34630002 */  ori       $v1, $v1, 2
/* 3606A4 E005A3E4 AC430000 */  sw        $v1, ($v0)
/* 3606A8 E005A3E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3606AC E005A3EC 03E00008 */  jr        $ra
/* 3606B0 E005A3F0 27BD0028 */   addiu    $sp, $sp, 0x28
