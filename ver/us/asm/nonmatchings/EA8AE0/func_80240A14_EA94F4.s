.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A14_EA94F4
/* EA94F4 80240A14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA94F8 80240A18 AFBF0014 */  sw        $ra, 0x14($sp)
/* EA94FC 80240A1C AFB00010 */  sw        $s0, 0x10($sp)
/* EA9500 80240A20 8C900084 */  lw        $s0, 0x84($a0)
/* EA9504 80240A24 8602004C */  lh        $v0, 0x4c($s0)
/* EA9508 80240A28 44826000 */  mtc1      $v0, $f12
/* EA950C 80240A2C 00000000 */  nop
/* EA9510 80240A30 0C00AD77 */  jal       func_8002B5DC
/* EA9514 80240A34 46806320 */   cvt.s.w  $f12, $f12
/* EA9518 80240A38 3C013F80 */  lui       $at, 0x3f80
/* EA951C 80240A3C 44811000 */  mtc1      $at, $f2
/* EA9520 80240A40 00000000 */  nop
/* EA9524 80240A44 46020000 */  add.s     $f0, $f0, $f2
/* EA9528 80240A48 46000000 */  add.s     $f0, $f0, $f0
/* EA952C 80240A4C C6020024 */  lwc1      $f2, 0x24($s0)
/* EA9530 80240A50 8602004C */  lh        $v0, 0x4c($s0)
/* EA9534 80240A54 46001080 */  add.s     $f2, $f2, $f0
/* EA9538 80240A58 24420008 */  addiu     $v0, $v0, 8
/* EA953C 80240A5C 44826000 */  mtc1      $v0, $f12
/* EA9540 80240A60 00000000 */  nop
/* EA9544 80240A64 46806320 */  cvt.s.w   $f12, $f12
/* EA9548 80240A68 0C00AB85 */  jal       dead_clamp_angle
/* EA954C 80240A6C E6020004 */   swc1     $f2, 4($s0)
/* EA9550 80240A70 4600010D */  trunc.w.s $f4, $f0
/* EA9554 80240A74 44022000 */  mfc1      $v0, $f4
/* EA9558 80240A78 00000000 */  nop
/* EA955C 80240A7C A602004C */  sh        $v0, 0x4c($s0)
/* EA9560 80240A80 3C028011 */  lui       $v0, %hi(D_80117578)
/* EA9564 80240A84 24427578 */  addiu     $v0, $v0, %lo(D_80117578)
/* EA9568 80240A88 C44C0028 */  lwc1      $f12, 0x28($v0)
/* EA956C 80240A8C C44E0030 */  lwc1      $f14, 0x30($v0)
/* EA9570 80240A90 8E060018 */  lw        $a2, 0x18($s0)
/* EA9574 80240A94 0C00AC71 */  jal       func_8002B1C4
/* EA9578 80240A98 8E070020 */   lw       $a3, 0x20($s0)
/* EA957C 80240A9C 3C0141F0 */  lui       $at, 0x41f0
/* EA9580 80240AA0 44811000 */  mtc1      $at, $f2
/* EA9584 80240AA4 00000000 */  nop
/* EA9588 80240AA8 4602003E */  c.le.s    $f0, $f2
/* EA958C 80240AAC 00000000 */  nop
/* EA9590 80240AB0 45000002 */  bc1f      .L80240ABC
/* EA9594 80240AB4 24020003 */   addiu    $v0, $zero, 3
/* EA9598 80240AB8 A602004E */  sh        $v0, 0x4e($s0)
.L80240ABC:
/* EA959C 80240ABC 8E020054 */  lw        $v0, 0x54($s0)
/* EA95A0 80240AC0 C6000018 */  lwc1      $f0, 0x18($s0)
/* EA95A4 80240AC4 8C42000C */  lw        $v0, 0xc($v0)
/* EA95A8 80240AC8 E4400004 */  swc1      $f0, 4($v0)
/* EA95AC 80240ACC 8E020054 */  lw        $v0, 0x54($s0)
/* EA95B0 80240AD0 C6000004 */  lwc1      $f0, 4($s0)
/* EA95B4 80240AD4 8C42000C */  lw        $v0, 0xc($v0)
/* EA95B8 80240AD8 E4400008 */  swc1      $f0, 8($v0)
/* EA95BC 80240ADC 8E020054 */  lw        $v0, 0x54($s0)
/* EA95C0 80240AE0 C6000020 */  lwc1      $f0, 0x20($s0)
/* EA95C4 80240AE4 8C42000C */  lw        $v0, 0xc($v0)
/* EA95C8 80240AE8 E440000C */  swc1      $f0, 0xc($v0)
/* EA95CC 80240AEC 8FBF0014 */  lw        $ra, 0x14($sp)
/* EA95D0 80240AF0 8FB00010 */  lw        $s0, 0x10($sp)
/* EA95D4 80240AF4 0000102D */  daddu     $v0, $zero, $zero
/* EA95D8 80240AF8 03E00008 */  jr        $ra
/* EA95DC 80240AFC 27BD0018 */   addiu    $sp, $sp, 0x18
