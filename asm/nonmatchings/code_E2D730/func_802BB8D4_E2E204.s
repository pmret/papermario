.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB8D4_E2E204
/* E2E204 802BB8D4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E2E208 802BB8D8 AFB00010 */  sw        $s0, 0x10($sp)
/* E2E20C 802BB8DC 0080802D */  daddu     $s0, $a0, $zero
/* E2E210 802BB8E0 AFBF001C */  sw        $ra, 0x1c($sp)
/* E2E214 802BB8E4 AFB20018 */  sw        $s2, 0x18($sp)
/* E2E218 802BB8E8 AFB10014 */  sw        $s1, 0x14($sp)
/* E2E21C 802BB8EC F7B40020 */  sdc1      $f20, 0x20($sp)
/* E2E220 802BB8F0 C60C0048 */  lwc1      $f12, 0x48($s0)
/* E2E224 802BB8F4 3C014000 */  lui       $at, 0x4000
/* E2E228 802BB8F8 4481A000 */  mtc1      $at, $f20
/* E2E22C 802BB8FC 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E2E230 802BB900 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E2E234 802BB904 46146301 */  sub.s     $f12, $f12, $f20
/* E2E238 802BB908 C60E0050 */  lwc1      $f14, 0x50($s0)
/* E2E23C 802BB90C 8E260028 */  lw        $a2, 0x28($s1)
/* E2E240 802BB910 8E270030 */  lw        $a3, 0x30($s1)
/* E2E244 802BB914 8E120040 */  lw        $s2, 0x40($s0)
/* E2E248 802BB918 0C00A7B5 */  jal       dist2D
/* E2E24C 802BB91C 46147381 */   sub.s    $f14, $f14, $f20
/* E2E250 802BB920 3C013FD0 */  lui       $at, 0x3fd0
/* E2E254 802BB924 44811800 */  mtc1      $at, $f3
/* E2E258 802BB928 44801000 */  mtc1      $zero, $f2
/* E2E25C 802BB92C 46000021 */  cvt.d.s   $f0, $f0
/* E2E260 802BB930 46220002 */  mul.d     $f0, $f0, $f2
/* E2E264 802BB934 00000000 */  nop       
/* E2E268 802BB938 46200005 */  abs.d     $f0, $f0
/* E2E26C 802BB93C 46200020 */  cvt.s.d   $f0, $f0
/* E2E270 802BB940 E6400008 */  swc1      $f0, 8($s2)
/* E2E274 802BB944 C6000048 */  lwc1      $f0, 0x48($s0)
/* E2E278 802BB948 46140001 */  sub.s     $f0, $f0, $f20
/* E2E27C 802BB94C 44060000 */  mfc1      $a2, $f0
/* E2E280 802BB950 C6000050 */  lwc1      $f0, 0x50($s0)
/* E2E284 802BB954 46140001 */  sub.s     $f0, $f0, $f20
/* E2E288 802BB958 C62C0028 */  lwc1      $f12, 0x28($s1)
/* E2E28C 802BB95C C62E0030 */  lwc1      $f14, 0x30($s1)
/* E2E290 802BB960 44070000 */  mfc1      $a3, $f0
/* E2E294 802BB964 0C00A720 */  jal       atan2
/* E2E298 802BB968 00000000 */   nop      
/* E2E29C 802BB96C E6400004 */  swc1      $f0, 4($s2)
/* E2E2A0 802BB970 8FBF001C */  lw        $ra, 0x1c($sp)
/* E2E2A4 802BB974 8FB20018 */  lw        $s2, 0x18($sp)
/* E2E2A8 802BB978 8FB10014 */  lw        $s1, 0x14($sp)
/* E2E2AC 802BB97C 8FB00010 */  lw        $s0, 0x10($sp)
/* E2E2B0 802BB980 D7B40020 */  ldc1      $f20, 0x20($sp)
/* E2E2B4 802BB984 03E00008 */  jr        $ra
/* E2E2B8 802BB988 27BD0028 */   addiu    $sp, $sp, 0x28
