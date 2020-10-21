.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EB8_C49A98
/* C49A98 80242EB8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C49A9C 80242EBC AFB20028 */  sw        $s2, 0x28($sp)
/* C49AA0 80242EC0 0080902D */  daddu     $s2, $a0, $zero
/* C49AA4 80242EC4 AFBF002C */  sw        $ra, 0x2c($sp)
/* C49AA8 80242EC8 AFB10024 */  sw        $s1, 0x24($sp)
/* C49AAC 80242ECC AFB00020 */  sw        $s0, 0x20($sp)
/* C49AB0 80242ED0 8E500148 */  lw        $s0, 0x148($s2)
/* C49AB4 80242ED4 0C00EABB */  jal       get_npc_unsafe
/* C49AB8 80242ED8 86040008 */   lh       $a0, 8($s0)
/* C49ABC 80242EDC 2404FEFF */  addiu     $a0, $zero, -0x101
/* C49AC0 80242EE0 0040882D */  daddu     $s1, $v0, $zero
/* C49AC4 80242EE4 0000282D */  daddu     $a1, $zero, $zero
/* C49AC8 80242EE8 8E03006C */  lw        $v1, 0x6c($s0)
/* C49ACC 80242EEC 00A0302D */  daddu     $a2, $a1, $zero
/* C49AD0 80242EF0 00641824 */  and       $v1, $v1, $a0
/* C49AD4 80242EF4 AE03006C */  sw        $v1, 0x6c($s0)
/* C49AD8 80242EF8 AFA00010 */  sw        $zero, 0x10($sp)
/* C49ADC 80242EFC AFA00014 */  sw        $zero, 0x14($sp)
/* C49AE0 80242F00 AFA00018 */  sw        $zero, 0x18($sp)
/* C49AE4 80242F04 8E240024 */  lw        $a0, 0x24($s1)
/* C49AE8 80242F08 0C0B7A25 */  jal       func_802DE894
/* C49AEC 80242F0C 00A0382D */   daddu    $a3, $a1, $zero
/* C49AF0 80242F10 8E02006C */  lw        $v0, 0x6c($s0)
/* C49AF4 80242F14 30421000 */  andi      $v0, $v0, 0x1000
/* C49AF8 80242F18 10400008 */  beqz      $v0, .L80242F3C
/* C49AFC 80242F1C 00000000 */   nop      
/* C49B00 80242F20 3C048000 */  lui       $a0, 0x8000
/* C49B04 80242F24 0C05271B */  jal       stop_sound
/* C49B08 80242F28 34840011 */   ori      $a0, $a0, 0x11
/* C49B0C 80242F2C 8E02006C */  lw        $v0, 0x6c($s0)
/* C49B10 80242F30 2403EFFF */  addiu     $v1, $zero, -0x1001
/* C49B14 80242F34 00431024 */  and       $v0, $v0, $v1
/* C49B18 80242F38 AE02006C */  sw        $v0, 0x6c($s0)
.L80242F3C:
/* C49B1C 80242F3C 8E0200CC */  lw        $v0, 0xcc($s0)
/* C49B20 80242F40 8C430024 */  lw        $v1, 0x24($v0)
/* C49B24 80242F44 24020014 */  addiu     $v0, $zero, 0x14
/* C49B28 80242F48 A622008E */  sh        $v0, 0x8e($s1)
/* C49B2C 80242F4C 24020011 */  addiu     $v0, $zero, 0x11
/* C49B30 80242F50 AE230028 */  sw        $v1, 0x28($s1)
/* C49B34 80242F54 AE420070 */  sw        $v0, 0x70($s2)
/* C49B38 80242F58 8FBF002C */  lw        $ra, 0x2c($sp)
/* C49B3C 80242F5C 8FB20028 */  lw        $s2, 0x28($sp)
/* C49B40 80242F60 8FB10024 */  lw        $s1, 0x24($sp)
/* C49B44 80242F64 8FB00020 */  lw        $s0, 0x20($sp)
/* C49B48 80242F68 03E00008 */  jr        $ra
/* C49B4C 80242F6C 27BD0030 */   addiu    $sp, $sp, 0x30
