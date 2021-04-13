.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060784
/* 3BB84 80060784 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BB88 80060788 AFB00010 */  sw        $s0, 0x10($sp)
/* 3BB8C 8006078C 0080802D */  daddu     $s0, $a0, $zero
/* 3BB90 80060790 3C04800B */  lui       $a0, %hi(D_800B0E98)
/* 3BB94 80060794 24840E98 */  addiu     $a0, $a0, %lo(D_800B0E98)
/* 3BB98 80060798 0000282D */  daddu     $a1, $zero, $zero
/* 3BB9C 8006079C AFBF0014 */  sw        $ra, 0x14($sp)
/* 3BBA0 800607A0 0C0195B0 */  jal       func_800656C0
/* 3BBA4 800607A4 00A0302D */   daddu    $a2, $a1, $zero
/* 3BBA8 800607A8 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3BBAC 800607AC 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3BBB0 800607B0 0C01865C */  jal       func_80061970
/* 3BBB4 800607B4 00000000 */   nop
/* 3BBB8 800607B8 14400013 */  bnez      $v0, .L80060808
/* 3BBBC 800607BC 0000282D */   daddu    $a1, $zero, $zero
/* 3BBC0 800607C0 3C04800E */  lui       $a0, %hi(D_800DAC58)
/* 3BBC4 800607C4 2484AC58 */  addiu     $a0, $a0, %lo(D_800DAC58)
/* 3BBC8 800607C8 0C0195B0 */  jal       func_800656C0
/* 3BBCC 800607CC 24060001 */   addiu    $a2, $zero, 1
/* 3BBD0 800607D0 3C04800E */  lui       $a0, %hi(D_800DC020)
/* 3BBD4 800607D4 2484C020 */  addiu     $a0, $a0, %lo(D_800DC020)
/* 3BBD8 800607D8 0000282D */  daddu     $a1, $zero, $zero
/* 3BBDC 800607DC 0C0195FC */  jal       func_800657F0
/* 3BBE0 800607E0 24060001 */   addiu    $a2, $zero, 1
/* 3BBE4 800607E4 3C04800B */  lui       $a0, %hi(D_800B1D48)
/* 3BBE8 800607E8 0C01867E */  jal       func_800619F8
/* 3BBEC 800607EC 24841D48 */   addiu    $a0, $a0, %lo(D_800B1D48)
/* 3BBF0 800607F0 3C04800E */  lui       $a0, %hi(D_800DC020)
/* 3BBF4 800607F4 2484C020 */  addiu     $a0, $a0, %lo(D_800DC020)
/* 3BBF8 800607F8 0000282D */  daddu     $a1, $zero, $zero
/* 3BBFC 800607FC 0C0195B0 */  jal       func_800656C0
/* 3BC00 80060800 24060001 */   addiu    $a2, $zero, 1
/* 3BC04 80060804 0000102D */  daddu     $v0, $zero, $zero
.L80060808:
/* 3BC08 80060808 14400009 */  bnez      $v0, .L80060830
/* 3BC0C 8006080C 00000000 */   nop
/* 3BC10 80060810 3C028009 */  lui       $v0, %hi(D_80093D00)
/* 3BC14 80060814 8C423D00 */  lw        $v0, %lo(D_80093D00)($v0)
/* 3BC18 80060818 50400005 */  beql      $v0, $zero, .L80060830
/* 3BC1C 8006081C 0000102D */   daddu    $v0, $zero, $zero
/* 3BC20 80060820 86040000 */  lh        $a0, ($s0)
/* 3BC24 80060824 0040F809 */  jalr      $v0
/* 3BC28 80060828 00000000 */   nop
/* 3BC2C 8006082C 0000102D */  daddu     $v0, $zero, $zero
.L80060830:
/* 3BC30 80060830 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3BC34 80060834 8FB00010 */  lw        $s0, 0x10($sp)
/* 3BC38 80060838 03E00008 */  jr        $ra
/* 3BC3C 8006083C 27BD0018 */   addiu    $sp, $sp, 0x18
