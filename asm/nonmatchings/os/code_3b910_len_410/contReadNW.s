.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel contReadNW
/* 3BBB4 800607B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BBB8 800607B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 3BBBC 800607BC 0080802D */  daddu     $s0, $a0, $zero
/* 3BBC0 800607C0 3C04800B */  lui       $a0, 0x800b
/* 3BBC4 800607C4 24840EB8 */  addiu     $a0, $a0, 0xeb8
/* 3BBC8 800607C8 0000282D */  daddu     $a1, $zero, $zero
/* 3BBCC 800607CC AFBF0014 */  sw        $ra, 0x14($sp)
/* 3BBD0 800607D0 0C0195BC */  jal       osRecvMesg
/* 3BBD4 800607D4 00A0302D */   daddu    $a2, $a1, $zero
/* 3BBD8 800607D8 3C04800E */  lui       $a0, 0x800e
/* 3BBDC 800607DC 2484AC78 */  addiu     $a0, $a0, -0x5388
/* 3BBE0 800607E0 0C018668 */  jal       osContStartReadData
/* 3BBE4 800607E4 00000000 */   nop      
/* 3BBE8 800607E8 14400013 */  bnez      $v0, .L80060838
/* 3BBEC 800607EC 0000282D */   daddu    $a1, $zero, $zero
/* 3BBF0 800607F0 3C04800E */  lui       $a0, 0x800e
/* 3BBF4 800607F4 2484AC78 */  addiu     $a0, $a0, -0x5388
/* 3BBF8 800607F8 0C0195BC */  jal       osRecvMesg
/* 3BBFC 800607FC 24060001 */   addiu    $a2, $zero, 1
/* 3BC00 80060800 3C04800E */  lui       $a0, 0x800e
/* 3BC04 80060804 2484C040 */  addiu     $a0, $a0, -0x3fc0
/* 3BC08 80060808 0000282D */  daddu     $a1, $zero, $zero
/* 3BC0C 8006080C 0C019608 */  jal       osSendMesg
/* 3BC10 80060810 24060001 */   addiu    $a2, $zero, 1
/* 3BC14 80060814 3C04800B */  lui       $a0, 0x800b
/* 3BC18 80060818 0C01868A */  jal       osContGetReadData
/* 3BC1C 8006081C 24841D68 */   addiu    $a0, $a0, 0x1d68
/* 3BC20 80060820 3C04800E */  lui       $a0, 0x800e
/* 3BC24 80060824 2484C040 */  addiu     $a0, $a0, -0x3fc0
/* 3BC28 80060828 0000282D */  daddu     $a1, $zero, $zero
/* 3BC2C 8006082C 0C0195BC */  jal       osRecvMesg
/* 3BC30 80060830 24060001 */   addiu    $a2, $zero, 1
/* 3BC34 80060834 0000102D */  daddu     $v0, $zero, $zero
.L80060838:
/* 3BC38 80060838 14400009 */  bnez      $v0, .L80060860
/* 3BC3C 8006083C 00000000 */   nop      
/* 3BC40 80060840 3C028009 */  lui       $v0, 0x8009
/* 3BC44 80060844 8C423D20 */  lw        $v0, 0x3d20($v0)
/* 3BC48 80060848 50400005 */  beql      $v0, $zero, .L80060860
/* 3BC4C 8006084C 0000102D */   daddu    $v0, $zero, $zero
/* 3BC50 80060850 86040000 */  lh        $a0, ($s0)
/* 3BC54 80060854 0040F809 */  jalr      $v0
/* 3BC58 80060858 00000000 */   nop      
/* 3BC5C 8006085C 0000102D */  daddu     $v0, $zero, $zero
.L80060860:
/* 3BC60 80060860 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3BC64 80060864 8FB00010 */  lw        $s0, 0x10($sp)
/* 3BC68 80060868 03E00008 */  jr        $ra
/* 3BC6C 8006086C 27BD0018 */   addiu    $sp, $sp, 0x18
