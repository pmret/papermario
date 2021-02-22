.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004E8B4
/* 29CB4 8004E8B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 29CB8 8004E8B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 29CBC 8004E8BC 0080802D */  daddu     $s0, $a0, $zero
/* 29CC0 8004E8C0 2403000F */  addiu     $v1, $zero, 0xf
/* 29CC4 8004E8C4 260205A0 */  addiu     $v0, $s0, 0x5a0
/* 29CC8 8004E8C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 29CCC 8004E8CC A2000220 */  sb        $zero, 0x220($s0)
/* 29CD0 8004E8D0 AE00001C */  sw        $zero, 0x1c($s0)
/* 29CD4 8004E8D4 AE000020 */  sw        $zero, 0x20($s0)
/* 29CD8 8004E8D8 A6000058 */  sh        $zero, 0x58($s0)
/* 29CDC 8004E8DC A600005A */  sh        $zero, 0x5a($s0)
.L8004E8E0:
/* 29CE0 8004E8E0 AC40025C */  sw        $zero, 0x25c($v0)
/* 29CE4 8004E8E4 2463FFFF */  addiu     $v1, $v1, -1
/* 29CE8 8004E8E8 0461FFFD */  bgez      $v1, .L8004E8E0
/* 29CEC 8004E8EC 2442FFA0 */   addiu    $v0, $v0, -0x60
/* 29CF0 8004E8F0 0C01416C */  jal       func_800505B0
/* 29CF4 8004E8F4 0200202D */   daddu    $a0, $s0, $zero
/* 29CF8 8004E8F8 3C020002 */  lui       $v0, 2
/* 29CFC 8004E8FC 3442625A */  ori       $v0, $v0, 0x625a
/* 29D00 8004E900 A2000221 */  sb        $zero, 0x221($s0)
/* 29D04 8004E904 AE020008 */  sw        $v0, 8($s0)
/* 29D08 8004E908 8FBF0014 */  lw        $ra, 0x14($sp)
/* 29D0C 8004E90C 8FB00010 */  lw        $s0, 0x10($sp)
/* 29D10 8004E910 03E00008 */  jr        $ra
/* 29D14 8004E914 27BD0018 */   addiu    $sp, $sp, 0x18
