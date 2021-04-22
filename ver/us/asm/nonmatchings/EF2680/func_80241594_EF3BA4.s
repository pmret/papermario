.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241594_EF3BA4
/* EF3BA4 80241594 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EF3BA8 80241598 AFB00010 */  sw        $s0, 0x10($sp)
/* EF3BAC 8024159C 24100032 */  addiu     $s0, $zero, 0x32
/* EF3BB0 802415A0 AFBF0014 */  sw        $ra, 0x14($sp)
.L802415A4:
/* EF3BB4 802415A4 0C010ABD */  jal       func_80042AF4
/* EF3BB8 802415A8 0200202D */   daddu    $a0, $s0, $zero
/* EF3BBC 802415AC 8C420094 */  lw        $v0, 0x94($v0)
/* EF3BC0 802415B0 54400003 */  bnel      $v0, $zero, .L802415C0
/* EF3BC4 802415B4 26100001 */   addiu    $s0, $s0, 1
/* EF3BC8 802415B8 08090573 */  j         .L802415CC
/* EF3BCC 802415BC 0200102D */   daddu    $v0, $s0, $zero
.L802415C0:
/* EF3BD0 802415C0 2A020036 */  slti      $v0, $s0, 0x36
/* EF3BD4 802415C4 1440FFF7 */  bnez      $v0, .L802415A4
/* EF3BD8 802415C8 2402FFFF */   addiu    $v0, $zero, -1
.L802415CC:
/* EF3BDC 802415CC 8FBF0014 */  lw        $ra, 0x14($sp)
/* EF3BE0 802415D0 8FB00010 */  lw        $s0, 0x10($sp)
/* EF3BE4 802415D4 03E00008 */  jr        $ra
/* EF3BE8 802415D8 27BD0018 */   addiu    $sp, $sp, 0x18
