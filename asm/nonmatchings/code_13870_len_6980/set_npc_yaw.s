.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_npc_yaw
/* 16740 8003B340 44857000 */  mtc1      $a1, $f14
/* 16744 8003B344 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 16748 8003B348 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 1674C 8003B34C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 16750 8003B350 AFB00010 */  sw        $s0, 0x10($sp)
/* 16754 8003B354 0080802D */  daddu     $s0, $a0, $zero
/* 16758 8003B358 AFBF0014 */  sw        $ra, 0x14($sp)
/* 1675C 8003B35C 00031080 */  sll       $v0, $v1, 2
/* 16760 8003B360 00431021 */  addu      $v0, $v0, $v1
/* 16764 8003B364 00021080 */  sll       $v0, $v0, 2
/* 16768 8003B368 00431023 */  subu      $v0, $v0, $v1
/* 1676C 8003B36C 000218C0 */  sll       $v1, $v0, 3
/* 16770 8003B370 00431021 */  addu      $v0, $v0, $v1
/* 16774 8003B374 000210C0 */  sll       $v0, $v0, 3
/* 16778 8003B378 E60E000C */  swc1      $f14, 0xc($s0)
/* 1677C 8003B37C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 16780 8003B380 00220821 */  addu      $at, $at, $v0
/* 16784 8003B384 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* 16788 8003B388 0C00A70A */  jal       get_clamped_angle_diff
/* 1678C 8003B38C 00000000 */   nop      
/* 16790 8003B390 44801000 */  mtc1      $zero, $f2
/* 16794 8003B394 00000000 */  nop       
/* 16798 8003B398 4600103E */  c.le.s    $f2, $f0
/* 1679C 8003B39C 00000000 */  nop       
/* 167A0 8003B3A0 45000005 */  bc1f      .L8003B3B8
/* 167A4 8003B3A4 240200B4 */   addiu    $v0, $zero, 0xb4
/* 167A8 8003B3A8 A602008A */  sh        $v0, 0x8a($s0)
/* 167AC 8003B3AC 24020001 */  addiu     $v0, $zero, 1
/* 167B0 8003B3B0 0800ECF0 */  j         .L8003B3C0
/* 167B4 8003B3B4 A6020088 */   sh       $v0, 0x88($s0)
.L8003B3B8:
/* 167B8 8003B3B8 A600008A */  sh        $zero, 0x8a($s0)
/* 167BC 8003B3BC A6000088 */  sh        $zero, 0x88($s0)
.L8003B3C0:
/* 167C0 8003B3C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 167C4 8003B3C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 167C8 8003B3C8 03E00008 */  jr        $ra
/* 167CC 8003B3CC 27BD0018 */   addiu    $sp, $sp, 0x18
