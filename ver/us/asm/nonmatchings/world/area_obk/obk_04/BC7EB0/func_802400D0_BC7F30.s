.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400D0_BC7F30
/* BC7F30 802400D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BC7F34 802400D4 AFB00020 */  sw        $s0, 0x20($sp)
/* BC7F38 802400D8 0080802D */  daddu     $s0, $a0, $zero
/* BC7F3C 802400DC AFBF0024 */  sw        $ra, 0x24($sp)
/* BC7F40 802400E0 C602000C */  lwc1      $f2, 0xc($s0)
/* BC7F44 802400E4 3C0143AA */  lui       $at, 0x43aa
/* BC7F48 802400E8 44810000 */  mtc1      $at, $f0
/* BC7F4C 802400EC 00000000 */  nop
/* BC7F50 802400F0 4602003C */  c.lt.s    $f0, $f2
/* BC7F54 802400F4 00000000 */  nop
/* BC7F58 802400F8 45010008 */  bc1t      .L8024011C
/* BC7F5C 802400FC 0200202D */   daddu    $a0, $s0, $zero
/* BC7F60 80240100 3C0141A0 */  lui       $at, 0x41a0
/* BC7F64 80240104 44810000 */  mtc1      $at, $f0
/* BC7F68 80240108 00000000 */  nop
/* BC7F6C 8024010C 4600103C */  c.lt.s    $f2, $f0
/* BC7F70 80240110 00000000 */  nop
/* BC7F74 80240114 4500000E */  bc1f      .L80240150
/* BC7F78 80240118 24020016 */   addiu    $v0, $zero, 0x16
.L8024011C:
/* BC7F7C 8024011C 0000282D */  daddu     $a1, $zero, $zero
/* BC7F80 80240120 00A0302D */  daddu     $a2, $a1, $zero
/* BC7F84 80240124 2402000D */  addiu     $v0, $zero, 0xd
/* BC7F88 80240128 A08200AA */  sb        $v0, 0xaa($a0)
/* BC7F8C 8024012C A48000A2 */  sh        $zero, 0xa2($a0)
/* BC7F90 80240130 AFA00010 */  sw        $zero, 0x10($sp)
/* BC7F94 80240134 AFA00014 */  sw        $zero, 0x14($sp)
/* BC7F98 80240138 948200A2 */  lhu       $v0, 0xa2($a0)
/* BC7F9C 8024013C 00A0382D */  daddu     $a3, $a1, $zero
/* BC7FA0 80240140 0C00F589 */  jal       func_8003D624
/* BC7FA4 80240144 AFA20018 */   sw       $v0, 0x18($sp)
/* BC7FA8 80240148 08090062 */  j         .L80240188
/* BC7FAC 8024014C 00000000 */   nop
.L80240150:
/* BC7FB0 80240150 A20200AA */  sb        $v0, 0xaa($s0)
/* BC7FB4 80240154 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BC7FB8 80240158 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BC7FBC 8024015C 0200202D */  daddu     $a0, $s0, $zero
/* BC7FC0 80240160 9046000E */  lbu       $a2, 0xe($v0)
/* BC7FC4 80240164 24050007 */  addiu     $a1, $zero, 7
/* BC7FC8 80240168 AFA00010 */  sw        $zero, 0x10($sp)
/* BC7FCC 8024016C AFA00014 */  sw        $zero, 0x14($sp)
/* BC7FD0 80240170 960200A2 */  lhu       $v0, 0xa2($s0)
/* BC7FD4 80240174 240700FF */  addiu     $a3, $zero, 0xff
/* BC7FD8 80240178 0C00F589 */  jal       func_8003D624
/* BC7FDC 8024017C AFA20018 */   sw       $v0, 0x18($sp)
/* BC7FE0 80240180 240200FF */  addiu     $v0, $zero, 0xff
/* BC7FE4 80240184 A602009A */  sh        $v0, 0x9a($s0)
.L80240188:
/* BC7FE8 80240188 8FBF0024 */  lw        $ra, 0x24($sp)
/* BC7FEC 8024018C 8FB00020 */  lw        $s0, 0x20($sp)
/* BC7FF0 80240190 03E00008 */  jr        $ra
/* BC7FF4 80240194 27BD0028 */   addiu    $sp, $sp, 0x28
