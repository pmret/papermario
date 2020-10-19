.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240994_A0C684
/* A0C684 80240994 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A0C688 80240998 2404FFFC */  addiu     $a0, $zero, -4
/* A0C68C 8024099C AFBF0020 */  sw        $ra, 0x20($sp)
/* A0C690 802409A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* A0C694 802409A4 AFB20018 */  sw        $s2, 0x18($sp)
/* A0C698 802409A8 AFB10014 */  sw        $s1, 0x14($sp)
/* A0C69C 802409AC 0C00EABB */  jal       get_npc_unsafe
/* A0C6A0 802409B0 AFB00010 */   sw       $s0, 0x10($sp)
/* A0C6A4 802409B4 0000202D */  daddu     $a0, $zero, $zero
/* A0C6A8 802409B8 0C00EABB */  jal       get_npc_unsafe
/* A0C6AC 802409BC 0040882D */   daddu    $s1, $v0, $zero
/* A0C6B0 802409C0 0040802D */  daddu     $s0, $v0, $zero
/* A0C6B4 802409C4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* A0C6B8 802409C8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* A0C6BC 802409CC 8E060038 */  lw        $a2, 0x38($s0)
/* A0C6C0 802409D0 0C00A720 */  jal       atan2
/* A0C6C4 802409D4 8E070040 */   lw       $a3, 0x40($s0)
/* A0C6C8 802409D8 E620000C */  swc1      $f0, 0xc($s1)
/* A0C6CC 802409DC 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* A0C6D0 802409E0 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* A0C6D4 802409E4 C62C0028 */  lwc1      $f12, 0x28($s1)
/* A0C6D8 802409E8 C62E0030 */  lwc1      $f14, 0x30($s1)
/* A0C6DC 802409EC 8E060038 */  lw        $a2, 0x38($s0)
/* A0C6E0 802409F0 0C00A720 */  jal       atan2
/* A0C6E4 802409F4 8E070040 */   lw       $a3, 0x40($s0)
/* A0C6E8 802409F8 3C138024 */  lui       $s3, 0x8024
/* A0C6EC 802409FC 26732B9C */  addiu     $s3, $s3, 0x2b9c
/* A0C6F0 80240A00 3C128024 */  lui       $s2, %hi(pause_set_cursor_opacity)
/* A0C6F4 80240A04 26522BA0 */  addiu     $s2, $s2, %lo(pause_set_cursor_opacity)
/* A0C6F8 80240A08 C66C0000 */  lwc1      $f12, ($s3)
/* A0C6FC 80240A0C C64E0000 */  lwc1      $f14, ($s2)
/* A0C700 80240A10 E6200080 */  swc1      $f0, 0x80($s1)
/* A0C704 80240A14 8E060038 */  lw        $a2, 0x38($s0)
/* A0C708 80240A18 0C00A720 */  jal       atan2
/* A0C70C 80240A1C 8E070040 */   lw       $a3, 0x40($s0)
/* A0C710 80240A20 C6020038 */  lwc1      $f2, 0x38($s0)
/* A0C714 80240A24 C6040040 */  lwc1      $f4, 0x40($s0)
/* A0C718 80240A28 E600000C */  swc1      $f0, 0xc($s0)
/* A0C71C 80240A2C E6620000 */  swc1      $f2, ($s3)
/* A0C720 80240A30 E6440000 */  swc1      $f4, ($s2)
/* A0C724 80240A34 8FBF0020 */  lw        $ra, 0x20($sp)
/* A0C728 80240A38 8FB3001C */  lw        $s3, 0x1c($sp)
/* A0C72C 80240A3C 8FB20018 */  lw        $s2, 0x18($sp)
/* A0C730 80240A40 8FB10014 */  lw        $s1, 0x14($sp)
/* A0C734 80240A44 8FB00010 */  lw        $s0, 0x10($sp)
/* A0C738 80240A48 24020002 */  addiu     $v0, $zero, 2
/* A0C73C 80240A4C 03E00008 */  jr        $ra
/* A0C740 80240A50 27BD0028 */   addiu    $sp, $sp, 0x28
