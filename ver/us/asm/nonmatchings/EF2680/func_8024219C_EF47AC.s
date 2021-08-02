.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024219C_EF47AC
/* EF47AC 8024219C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EF47B0 802421A0 AFB20018 */  sw        $s2, 0x18($sp)
/* EF47B4 802421A4 0080902D */  daddu     $s2, $a0, $zero
/* EF47B8 802421A8 AFBF001C */  sw        $ra, 0x1c($sp)
/* EF47BC 802421AC AFB10014 */  sw        $s1, 0x14($sp)
/* EF47C0 802421B0 AFB00010 */  sw        $s0, 0x10($sp)
/* EF47C4 802421B4 8E510148 */  lw        $s1, 0x148($s2)
/* EF47C8 802421B8 0C00F92F */  jal       dead_get_npc_unsafe
/* EF47CC 802421BC 86240008 */   lh       $a0, 8($s1)
/* EF47D0 802421C0 0040802D */  daddu     $s0, $v0, $zero
/* EF47D4 802421C4 8E2300CC */  lw        $v1, 0xcc($s1)
/* EF47D8 802421C8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EF47DC 802421CC 8C630020 */  lw        $v1, 0x20($v1)
/* EF47E0 802421D0 AE030028 */  sw        $v1, 0x28($s0)
/* EF47E4 802421D4 96220076 */  lhu       $v0, 0x76($s1)
/* EF47E8 802421D8 A602008E */  sh        $v0, 0x8e($s0)
/* EF47EC 802421DC 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EF47F0 802421E0 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EF47F4 802421E4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EF47F8 802421E8 8C460028 */  lw        $a2, 0x28($v0)
/* EF47FC 802421EC 0C00ABDC */  jal       fio_validate_header_checksums
/* EF4800 802421F0 8C470030 */   lw       $a3, 0x30($v0)
/* EF4804 802421F4 2402000D */  addiu     $v0, $zero, 0xd
/* EF4808 802421F8 E600000C */  swc1      $f0, 0xc($s0)
/* EF480C 802421FC AE420070 */  sw        $v0, 0x70($s2)
/* EF4810 80242200 8FBF001C */  lw        $ra, 0x1c($sp)
/* EF4814 80242204 8FB20018 */  lw        $s2, 0x18($sp)
/* EF4818 80242208 8FB10014 */  lw        $s1, 0x14($sp)
/* EF481C 8024220C 8FB00010 */  lw        $s0, 0x10($sp)
/* EF4820 80242210 03E00008 */  jr        $ra
/* EF4824 80242214 27BD0020 */   addiu    $sp, $sp, 0x20
