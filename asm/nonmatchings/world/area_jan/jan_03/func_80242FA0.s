.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FA0
/* B37B70 80242FA0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B37B74 80242FA4 AFB00010 */  sw        $s0, 0x10($sp)
/* B37B78 80242FA8 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* B37B7C 80242FAC 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* B37B80 80242FB0 AFBF0018 */  sw        $ra, 0x18($sp)
/* B37B84 80242FB4 AFB10014 */  sw        $s1, 0x14($sp)
/* B37B88 80242FB8 F7B60028 */  sdc1      $f22, 0x28($sp)
/* B37B8C 80242FBC F7B40020 */  sdc1      $f20, 0x20($sp)
/* B37B90 80242FC0 C60C0080 */  lwc1      $f12, 0x80($s0)
/* B37B94 80242FC4 0C00A8BB */  jal       sin_deg
/* B37B98 80242FC8 0080882D */   daddu    $s1, $a0, $zero
/* B37B9C 80242FCC C6140054 */  lwc1      $f20, 0x54($s0)
/* B37BA0 80242FD0 3C0140A0 */  lui       $at, 0x40a0
/* B37BA4 80242FD4 4481B000 */  mtc1      $at, $f22
/* B37BA8 80242FD8 00000000 */  nop       
/* B37BAC 80242FDC 4616A502 */  mul.s     $f20, $f20, $f22
/* B37BB0 80242FE0 00000000 */  nop       
/* B37BB4 80242FE4 C60C0080 */  lwc1      $f12, 0x80($s0)
/* B37BB8 80242FE8 4600A502 */  mul.s     $f20, $f20, $f0
/* B37BBC 80242FEC 0C00A8D4 */  jal       cos_deg
/* B37BC0 80242FF0 00000000 */   nop      
/* B37BC4 80242FF4 C6040054 */  lwc1      $f4, 0x54($s0)
/* B37BC8 80242FF8 46162102 */  mul.s     $f4, $f4, $f22
/* B37BCC 80242FFC 00000000 */  nop       
/* B37BD0 80243000 C6020028 */  lwc1      $f2, 0x28($s0)
/* B37BD4 80243004 46141080 */  add.s     $f2, $f2, $f20
/* B37BD8 80243008 46000007 */  neg.s     $f0, $f0
/* B37BDC 8024300C 46002102 */  mul.s     $f4, $f4, $f0
/* B37BE0 80243010 00000000 */  nop       
/* B37BE4 80243014 4600118D */  trunc.w.s $f6, $f2
/* B37BE8 80243018 E6260084 */  swc1      $f6, 0x84($s1)
/* B37BEC 8024301C C6000030 */  lwc1      $f0, 0x30($s0)
/* B37BF0 80243020 46040000 */  add.s     $f0, $f0, $f4
/* B37BF4 80243024 4600018D */  trunc.w.s $f6, $f0
/* B37BF8 80243028 E6260088 */  swc1      $f6, 0x88($s1)
/* B37BFC 8024302C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B37C00 80243030 8FB10014 */  lw        $s1, 0x14($sp)
/* B37C04 80243034 8FB00010 */  lw        $s0, 0x10($sp)
/* B37C08 80243038 D7B60028 */  ldc1      $f22, 0x28($sp)
/* B37C0C 8024303C D7B40020 */  ldc1      $f20, 0x20($sp)
/* B37C10 80243040 24020002 */  addiu     $v0, $zero, 2
/* B37C14 80243044 03E00008 */  jr        $ra
/* B37C18 80243048 27BD0030 */   addiu    $sp, $sp, 0x30
/* B37C1C 8024304C 00000000 */  nop       
