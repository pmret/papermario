.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80247BE0_EE65A0
.ascii "party_pokopi\0\0\0\0"

.section .text

glabel func_80243680_EE2040
/* EE2040 80243680 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EE2044 80243684 3C048024 */  lui       $a0, %hi(D_80247BE0_EE65A0)
/* EE2048 80243688 24847BE0 */  addiu     $a0, $a0, %lo(D_80247BE0_EE65A0)
/* EE204C 8024368C 27A50010 */  addiu     $a1, $sp, 0x10
/* EE2050 80243690 AFBF0020 */  sw        $ra, 0x20($sp)
/* EE2054 80243694 AFB1001C */  sw        $s1, 0x1c($sp)
/* EE2058 80243698 0C017C8E */  jal       func_8005F238
/* EE205C 8024369C AFB00018 */   sw       $s0, 0x18($sp)
/* EE2060 802436A0 0040802D */  daddu     $s0, $v0, $zero
/* EE2064 802436A4 0200202D */  daddu     $a0, $s0, $zero
/* EE2068 802436A8 3C118024 */  lui       $s1, %hi(D_80247BF0)
/* EE206C 802436AC 26317BF0 */  addiu     $s1, $s1, %lo(D_80247BF0)
/* EE2070 802436B0 0C01D01C */  jal       func_80074070
/* EE2074 802436B4 0220282D */   daddu    $a1, $s1, $zero
/* EE2078 802436B8 0C00AFDA */  jal       func_8002BF68
/* EE207C 802436BC 0200202D */   daddu    $a0, $s0, $zero
/* EE2080 802436C0 3C048025 */  lui       $a0, %hi(D_8024BB80)
/* EE2084 802436C4 2484BB80 */  addiu     $a0, $a0, %lo(D_8024BB80)
/* EE2088 802436C8 3C028024 */  lui       $v0, %hi(D_80247DF0)
/* EE208C 802436CC 24427DF0 */  addiu     $v0, $v0, %lo(D_80247DF0)
/* EE2090 802436D0 AC820000 */  sw        $v0, ($a0)
/* EE2094 802436D4 24020096 */  addiu     $v0, $zero, 0x96
/* EE2098 802436D8 A4820008 */  sh        $v0, 8($a0)
/* EE209C 802436DC 24020069 */  addiu     $v0, $zero, 0x69
/* EE20A0 802436E0 A482000A */  sh        $v0, 0xa($a0)
/* EE20A4 802436E4 24020002 */  addiu     $v0, $zero, 2
/* EE20A8 802436E8 AC82000C */  sw        $v0, 0xc($a0)
/* EE20AC 802436EC 24020001 */  addiu     $v0, $zero, 1
/* EE20B0 802436F0 AC910004 */  sw        $s1, 4($a0)
/* EE20B4 802436F4 0C04C319 */  jal       func_80130C64
/* EE20B8 802436F8 AC820010 */   sw       $v0, 0x10($a0)
/* EE20BC 802436FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* EE20C0 80243700 8FB1001C */  lw        $s1, 0x1c($sp)
/* EE20C4 80243704 8FB00018 */  lw        $s0, 0x18($sp)
/* EE20C8 80243708 24020002 */  addiu     $v0, $zero, 2
/* EE20CC 8024370C 03E00008 */  jr        $ra
/* EE20D0 80243710 27BD0028 */   addiu    $sp, $sp, 0x28
/* EE20D4 80243714 00000000 */  nop
/* EE20D8 80243718 00000000 */  nop
/* EE20DC 8024371C 00000000 */  nop
