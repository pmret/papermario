.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243760_8B37D0
/* 8B37D0 80243760 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8B37D4 80243764 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8B37D8 80243768 4485A000 */  mtc1      $a1, $f20
/* 8B37DC 8024376C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8B37E0 80243770 4486B000 */  mtc1      $a2, $f22
/* 8B37E4 80243774 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B37E8 80243778 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8B37EC 8024377C 4487C000 */  mtc1      $a3, $f24
/* 8B37F0 80243780 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8B37F4 80243784 0C019D28 */  jal       guMtxIdentF
/* 8B37F8 80243788 0080802D */   daddu    $s0, $a0, $zero
/* 8B37FC 8024378C 4616A582 */  mul.s     $f22, $f20, $f22
/* 8B3800 80243790 00000000 */  nop       
/* 8B3804 80243794 4618A502 */  mul.s     $f20, $f20, $f24
/* 8B3808 80243798 00000000 */  nop       
/* 8B380C 8024379C 3C013F80 */  lui       $at, 0x3f80
/* 8B3810 802437A0 44810000 */  mtc1      $at, $f0
/* 8B3814 802437A4 00000000 */  nop       
/* 8B3818 802437A8 E6000014 */  swc1      $f0, 0x14($s0)
/* 8B381C 802437AC E6160010 */  swc1      $f22, 0x10($s0)
/* 8B3820 802437B0 E6140018 */  swc1      $f20, 0x18($s0)
/* 8B3824 802437B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8B3828 802437B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B382C 802437BC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8B3830 802437C0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8B3834 802437C4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8B3838 802437C8 03E00008 */  jr        $ra
/* 8B383C 802437CC 27BD0030 */   addiu    $sp, $sp, 0x30
