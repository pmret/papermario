.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282700
/* 7E3580 80282700 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E3584 80282704 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E3588 80282708 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E358C 8028270C AFB00010 */  sw        $s0, 0x10($sp)
/* 7E3590 80282710 8C820074 */  lw        $v0, 0x74($a0)
/* 7E3594 80282714 8C42005C */  lw        $v0, 0x5c($v0)
/* 7E3598 80282718 10400010 */  beqz      $v0, .L8028275C
/* 7E359C 8028271C 0000802D */   daddu    $s0, $zero, $zero
/* 7E35A0 80282720 3C11FF7F */  lui       $s1, 0xff7f
/* 7E35A4 80282724 3631FFFF */  ori       $s1, $s1, 0xffff
.L80282728:
/* 7E35A8 80282728 0C00E2B7 */  jal       get_npc_by_index
/* 7E35AC 8028272C 0200202D */   daddu    $a0, $s0, $zero
/* 7E35B0 80282730 0040182D */  daddu     $v1, $v0, $zero
/* 7E35B4 80282734 10600006 */  beqz      $v1, .L80282750
/* 7E35B8 80282738 26100001 */   addiu    $s0, $s0, 1
/* 7E35BC 8028273C 8C620000 */  lw        $v0, ($v1)
/* 7E35C0 80282740 10400003 */  beqz      $v0, .L80282750
/* 7E35C4 80282744 00000000 */   nop
/* 7E35C8 80282748 00511024 */  and       $v0, $v0, $s1
/* 7E35CC 8028274C AC620000 */  sw        $v0, ($v1)
.L80282750:
/* 7E35D0 80282750 2A020040 */  slti      $v0, $s0, 0x40
/* 7E35D4 80282754 1440FFF4 */  bnez      $v0, .L80282728
/* 7E35D8 80282758 00000000 */   nop
.L8028275C:
/* 7E35DC 8028275C 24020002 */  addiu     $v0, $zero, 2
/* 7E35E0 80282760 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E35E4 80282764 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E35E8 80282768 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E35EC 8028276C 03E00008 */  jr        $ra
/* 7E35F0 80282770 27BD0020 */   addiu    $sp, $sp, 0x20
