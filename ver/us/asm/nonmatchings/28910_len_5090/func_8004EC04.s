.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004EC04
/* 2A004 8004EC04 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2A008 8004EC08 AFB00010 */  sw        $s0, 0x10($sp)
/* 2A00C 8004EC0C 0080802D */  daddu     $s0, $a0, $zero
/* 2A010 8004EC10 2403000F */  addiu     $v1, $zero, 0xf
/* 2A014 8004EC14 260205A0 */  addiu     $v0, $s0, 0x5a0
/* 2A018 8004EC18 AFBF0014 */  sw        $ra, 0x14($sp)
/* 2A01C 8004EC1C A2000220 */  sb        $zero, 0x220($s0)
/* 2A020 8004EC20 AE00001C */  sw        $zero, 0x1c($s0)
/* 2A024 8004EC24 AE000020 */  sw        $zero, 0x20($s0)
/* 2A028 8004EC28 A6000058 */  sh        $zero, 0x58($s0)
/* 2A02C 8004EC2C A600005A */  sh        $zero, 0x5a($s0)
.L8004EC30:
/* 2A030 8004EC30 AC40025C */  sw        $zero, 0x25c($v0)
/* 2A034 8004EC34 2463FFFF */  addiu     $v1, $v1, -1
/* 2A038 8004EC38 0461FFFD */  bgez      $v1, .L8004EC30
/* 2A03C 8004EC3C 2442FFA0 */   addiu    $v0, $v0, -0x60
/* 2A040 8004EC40 0C014240 */  jal       func_80050900
/* 2A044 8004EC44 0200202D */   daddu    $a0, $s0, $zero
/* 2A048 8004EC48 3C020002 */  lui       $v0, 2
/* 2A04C 8004EC4C 3442625A */  ori       $v0, $v0, 0x625a
/* 2A050 8004EC50 A2000221 */  sb        $zero, 0x221($s0)
/* 2A054 8004EC54 AE020008 */  sw        $v0, 8($s0)
/* 2A058 8004EC58 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2A05C 8004EC5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 2A060 8004EC60 03E00008 */  jr        $ra
/* 2A064 8004EC64 27BD0018 */   addiu    $sp, $sp, 0x18
