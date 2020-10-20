.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427B0_BE5F60
/* BE5F60 802427B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE5F64 802427B4 AFB10014 */  sw        $s1, 0x14($sp)
/* BE5F68 802427B8 0080882D */  daddu     $s1, $a0, $zero
/* BE5F6C 802427BC AFBF001C */  sw        $ra, 0x1c($sp)
/* BE5F70 802427C0 AFB20018 */  sw        $s2, 0x18($sp)
/* BE5F74 802427C4 AFB00010 */  sw        $s0, 0x10($sp)
/* BE5F78 802427C8 8E320148 */  lw        $s2, 0x148($s1)
/* BE5F7C 802427CC 0C00EABB */  jal       get_npc_unsafe
/* BE5F80 802427D0 86440008 */   lh       $a0, 8($s2)
/* BE5F84 802427D4 240400B4 */  addiu     $a0, $zero, 0xb4
/* BE5F88 802427D8 0C00A67F */  jal       rand_int
/* BE5F8C 802427DC 0040802D */   daddu    $s0, $v0, $zero
/* BE5F90 802427E0 C60C000C */  lwc1      $f12, 0xc($s0)
/* BE5F94 802427E4 44820000 */  mtc1      $v0, $f0
/* BE5F98 802427E8 00000000 */  nop       
/* BE5F9C 802427EC 46800020 */  cvt.s.w   $f0, $f0
/* BE5FA0 802427F0 46006300 */  add.s     $f12, $f12, $f0
/* BE5FA4 802427F4 3C0142B4 */  lui       $at, 0x42b4
/* BE5FA8 802427F8 44810000 */  mtc1      $at, $f0
/* BE5FAC 802427FC 0C00A6C9 */  jal       clamp_angle
/* BE5FB0 80242800 46006301 */   sub.s    $f12, $f12, $f0
/* BE5FB4 80242804 E600000C */  swc1      $f0, 0xc($s0)
/* BE5FB8 80242808 8E4200CC */  lw        $v0, 0xcc($s2)
/* BE5FBC 8024280C 8C420000 */  lw        $v0, ($v0)
/* BE5FC0 80242810 240403E8 */  addiu     $a0, $zero, 0x3e8
/* BE5FC4 80242814 0C00A67F */  jal       rand_int
/* BE5FC8 80242818 AE020028 */   sw       $v0, 0x28($s0)
/* BE5FCC 8024281C 00021FC2 */  srl       $v1, $v0, 0x1f
/* BE5FD0 80242820 00431821 */  addu      $v1, $v0, $v1
/* BE5FD4 80242824 00031843 */  sra       $v1, $v1, 1
/* BE5FD8 80242828 00031840 */  sll       $v1, $v1, 1
/* BE5FDC 8024282C 00431023 */  subu      $v0, $v0, $v1
/* BE5FE0 80242830 24420002 */  addiu     $v0, $v0, 2
/* BE5FE4 80242834 AE220074 */  sw        $v0, 0x74($s1)
/* BE5FE8 80242838 24020005 */  addiu     $v0, $zero, 5
/* BE5FEC 8024283C AE220070 */  sw        $v0, 0x70($s1)
/* BE5FF0 80242840 8FBF001C */  lw        $ra, 0x1c($sp)
/* BE5FF4 80242844 8FB20018 */  lw        $s2, 0x18($sp)
/* BE5FF8 80242848 8FB10014 */  lw        $s1, 0x14($sp)
/* BE5FFC 8024284C 8FB00010 */  lw        $s0, 0x10($sp)
/* BE6000 80242850 03E00008 */  jr        $ra
/* BE6004 80242854 27BD0020 */   addiu    $sp, $sp, 0x20
