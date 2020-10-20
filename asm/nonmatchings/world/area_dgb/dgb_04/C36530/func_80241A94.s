.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A94
/* C37FC4 80241A94 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C37FC8 80241A98 AFB20028 */  sw        $s2, 0x28($sp)
/* C37FCC 80241A9C 0080902D */  daddu     $s2, $a0, $zero
/* C37FD0 80241AA0 AFBF002C */  sw        $ra, 0x2c($sp)
/* C37FD4 80241AA4 AFB10024 */  sw        $s1, 0x24($sp)
/* C37FD8 80241AA8 AFB00020 */  sw        $s0, 0x20($sp)
/* C37FDC 80241AAC 8E500148 */  lw        $s0, 0x148($s2)
/* C37FE0 80241AB0 0C00EABB */  jal       get_npc_unsafe
/* C37FE4 80241AB4 86040008 */   lh       $a0, 8($s0)
/* C37FE8 80241AB8 2404FEFF */  addiu     $a0, $zero, -0x101
/* C37FEC 80241ABC 0040882D */  daddu     $s1, $v0, $zero
/* C37FF0 80241AC0 0000282D */  daddu     $a1, $zero, $zero
/* C37FF4 80241AC4 8E03006C */  lw        $v1, 0x6c($s0)
/* C37FF8 80241AC8 00A0302D */  daddu     $a2, $a1, $zero
/* C37FFC 80241ACC 00641824 */  and       $v1, $v1, $a0
/* C38000 80241AD0 AE03006C */  sw        $v1, 0x6c($s0)
/* C38004 80241AD4 AFA00010 */  sw        $zero, 0x10($sp)
/* C38008 80241AD8 AFA00014 */  sw        $zero, 0x14($sp)
/* C3800C 80241ADC AFA00018 */  sw        $zero, 0x18($sp)
/* C38010 80241AE0 8E240024 */  lw        $a0, 0x24($s1)
/* C38014 80241AE4 0C0B7A25 */  jal       func_802DE894
/* C38018 80241AE8 00A0382D */   daddu    $a3, $a1, $zero
/* C3801C 80241AEC 8E02006C */  lw        $v0, 0x6c($s0)
/* C38020 80241AF0 30421000 */  andi      $v0, $v0, 0x1000
/* C38024 80241AF4 10400008 */  beqz      $v0, .L80241B18
/* C38028 80241AF8 00000000 */   nop      
/* C3802C 80241AFC 3C048000 */  lui       $a0, 0x8000
/* C38030 80241B00 0C05271B */  jal       stop_sound
/* C38034 80241B04 34840011 */   ori      $a0, $a0, 0x11
/* C38038 80241B08 8E02006C */  lw        $v0, 0x6c($s0)
/* C3803C 80241B0C 2403EFFF */  addiu     $v1, $zero, -0x1001
/* C38040 80241B10 00431024 */  and       $v0, $v0, $v1
/* C38044 80241B14 AE02006C */  sw        $v0, 0x6c($s0)
.L80241B18:
/* C38048 80241B18 8E0200CC */  lw        $v0, 0xcc($s0)
/* C3804C 80241B1C 8C430024 */  lw        $v1, 0x24($v0)
/* C38050 80241B20 24020014 */  addiu     $v0, $zero, 0x14
/* C38054 80241B24 A622008E */  sh        $v0, 0x8e($s1)
/* C38058 80241B28 24020011 */  addiu     $v0, $zero, 0x11
/* C3805C 80241B2C AE230028 */  sw        $v1, 0x28($s1)
/* C38060 80241B30 AE420070 */  sw        $v0, 0x70($s2)
/* C38064 80241B34 8FBF002C */  lw        $ra, 0x2c($sp)
/* C38068 80241B38 8FB20028 */  lw        $s2, 0x28($sp)
/* C3806C 80241B3C 8FB10024 */  lw        $s1, 0x24($sp)
/* C38070 80241B40 8FB00020 */  lw        $s0, 0x20($sp)
/* C38074 80241B44 03E00008 */  jr        $ra
/* C38078 80241B48 27BD0030 */   addiu    $sp, $sp, 0x30
