.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054264
/* 2F664 80054264 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 2F668 80054268 AFB20028 */  sw        $s2, 0x28($sp)
/* 2F66C 8005426C 0080902D */  daddu     $s2, $a0, $zero
/* 2F670 80054270 AFB00020 */  sw        $s0, 0x20($sp)
/* 2F674 80054274 00A0802D */  daddu     $s0, $a1, $zero
/* 2F678 80054278 0200202D */  daddu     $a0, $s0, $zero
/* 2F67C 8005427C 27A50010 */  addiu     $a1, $sp, 0x10
/* 2F680 80054280 24060010 */  addiu     $a2, $zero, 0x10
/* 2F684 80054284 AFBF002C */  sw        $ra, 0x2c($sp)
/* 2F688 80054288 0C0152AC */  jal       func_80054AB0
/* 2F68C 8005428C AFB10024 */   sw       $s1, 0x24($sp)
/* 2F690 80054290 8FA20014 */  lw        $v0, 0x14($sp)
/* 2F694 80054294 2451FFF0 */  addiu     $s1, $v0, -0x10
/* 2F698 80054298 2E220201 */  sltiu     $v0, $s1, 0x201
/* 2F69C 8005429C 14400002 */  bnez      $v0, .L800542A8
/* 2F6A0 800542A0 26040010 */   addiu    $a0, $s0, 0x10
/* 2F6A4 800542A4 24110200 */  addiu     $s1, $zero, 0x200
.L800542A8:
/* 2F6A8 800542A8 8E450058 */  lw        $a1, 0x58($s2)
/* 2F6AC 800542AC 0C0152AC */  jal       func_80054AB0
/* 2F6B0 800542B0 0220302D */   daddu    $a2, $s1, $zero
/* 2F6B4 800542B4 001118C2 */  srl       $v1, $s1, 3
/* 2F6B8 800542B8 24020040 */  addiu     $v0, $zero, 0x40
/* 2F6BC 800542BC 00438823 */  subu      $s1, $v0, $v1
/* 2F6C0 800542C0 1A20000C */  blez      $s1, .L800542F4
/* 2F6C4 800542C4 26440014 */   addiu    $a0, $s2, 0x14
/* 2F6C8 800542C8 24060008 */  addiu     $a2, $zero, 8
/* 2F6CC 800542CC 8E500058 */  lw        $s0, 0x58($s2)
/* 2F6D0 800542D0 000310C0 */  sll       $v0, $v1, 3
/* 2F6D4 800542D4 02028021 */  addu      $s0, $s0, $v0
/* 2F6D8 800542D8 0C015309 */  jal       func_80054C24
/* 2F6DC 800542DC 0200282D */   daddu    $a1, $s0, $zero
/* 2F6E0 800542E0 0200202D */  daddu     $a0, $s0, $zero
/* 2F6E4 800542E4 24850008 */  addiu     $a1, $a0, 8
/* 2F6E8 800542E8 001130C0 */  sll       $a2, $s1, 3
/* 2F6EC 800542EC 0C015309 */  jal       func_80054C24
/* 2F6F0 800542F0 24C6FFF8 */   addiu    $a2, $a2, -8
.L800542F4:
/* 2F6F4 800542F4 8FBF002C */  lw        $ra, 0x2c($sp)
/* 2F6F8 800542F8 8FB20028 */  lw        $s2, 0x28($sp)
/* 2F6FC 800542FC 8FB10024 */  lw        $s1, 0x24($sp)
/* 2F700 80054300 8FB00020 */  lw        $s0, 0x20($sp)
/* 2F704 80054304 03E00008 */  jr        $ra
/* 2F708 80054308 27BD0030 */   addiu    $sp, $sp, 0x30
