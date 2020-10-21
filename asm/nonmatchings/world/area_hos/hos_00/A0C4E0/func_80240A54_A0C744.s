.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A54_A0C744
/* A0C744 80240A54 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A0C748 80240A58 AFB10014 */  sw        $s1, 0x14($sp)
/* A0C74C 80240A5C 0080882D */  daddu     $s1, $a0, $zero
/* A0C750 80240A60 24040001 */  addiu     $a0, $zero, 1
/* A0C754 80240A64 AFBF0018 */  sw        $ra, 0x18($sp)
/* A0C758 80240A68 0C00EABB */  jal       get_npc_unsafe
/* A0C75C 80240A6C AFB00010 */   sw       $s0, 0x10($sp)
/* A0C760 80240A70 0040802D */  daddu     $s0, $v0, $zero
/* A0C764 80240A74 C602000C */  lwc1      $f2, 0xc($s0)
/* A0C768 80240A78 3C014334 */  lui       $at, 0x4334
/* A0C76C 80240A7C 44810000 */  mtc1      $at, $f0
/* A0C770 80240A80 00000000 */  nop       
/* A0C774 80240A84 4600103C */  c.lt.s    $f2, $f0
/* A0C778 80240A88 00000000 */  nop       
/* A0C77C 80240A8C 45000006 */  bc1f      .L80240AA8
/* A0C780 80240A90 00000000 */   nop      
/* A0C784 80240A94 C6000038 */  lwc1      $f0, 0x38($s0)
/* A0C788 80240A98 3C014220 */  lui       $at, 0x4220
/* A0C78C 80240A9C 44811000 */  mtc1      $at, $f2
/* A0C790 80240AA0 080902AF */  j         .L80240ABC
/* A0C794 80240AA4 46020001 */   sub.s    $f0, $f0, $f2
.L80240AA8:
/* A0C798 80240AA8 C6000038 */  lwc1      $f0, 0x38($s0)
/* A0C79C 80240AAC 3C014220 */  lui       $at, 0x4220
/* A0C7A0 80240AB0 44811000 */  mtc1      $at, $f2
/* A0C7A4 80240AB4 00000000 */  nop       
/* A0C7A8 80240AB8 46020000 */  add.s     $f0, $f0, $f2
.L80240ABC:
/* A0C7AC 80240ABC 3C014120 */  lui       $at, 0x4120
/* A0C7B0 80240AC0 44811000 */  mtc1      $at, $f2
/* A0C7B4 80240AC4 4600010D */  trunc.w.s $f4, $f0
/* A0C7B8 80240AC8 E6240084 */  swc1      $f4, 0x84($s1)
/* A0C7BC 80240ACC C600003C */  lwc1      $f0, 0x3c($s0)
/* A0C7C0 80240AD0 46020000 */  add.s     $f0, $f0, $f2
/* A0C7C4 80240AD4 4600010D */  trunc.w.s $f4, $f0
/* A0C7C8 80240AD8 E6240088 */  swc1      $f4, 0x88($s1)
/* A0C7CC 80240ADC C6000040 */  lwc1      $f0, 0x40($s0)
/* A0C7D0 80240AE0 4600010D */  trunc.w.s $f4, $f0
/* A0C7D4 80240AE4 E624008C */  swc1      $f4, 0x8c($s1)
/* A0C7D8 80240AE8 C62C009C */  lwc1      $f12, 0x9c($s1)
/* A0C7DC 80240AEC 46806320 */  cvt.s.w   $f12, $f12
/* A0C7E0 80240AF0 8E060038 */  lw        $a2, 0x38($s0)
/* A0C7E4 80240AF4 8E070040 */  lw        $a3, 0x40($s0)
/* A0C7E8 80240AF8 C62E00A4 */  lwc1      $f14, 0xa4($s1)
/* A0C7EC 80240AFC 0C00A720 */  jal       atan2
/* A0C7F0 80240B00 468073A0 */   cvt.s.w  $f14, $f14
/* A0C7F4 80240B04 E600000C */  swc1      $f0, 0xc($s0)
/* A0C7F8 80240B08 8FBF0018 */  lw        $ra, 0x18($sp)
/* A0C7FC 80240B0C 8FB10014 */  lw        $s1, 0x14($sp)
/* A0C800 80240B10 8FB00010 */  lw        $s0, 0x10($sp)
/* A0C804 80240B14 24020002 */  addiu     $v0, $zero, 2
/* A0C808 80240B18 03E00008 */  jr        $ra
/* A0C80C 80240B1C 27BD0020 */   addiu    $sp, $sp, 0x20
