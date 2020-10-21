.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BF0_BFF470
/* BFF470 80241BF0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BFF474 80241BF4 AFB20028 */  sw        $s2, 0x28($sp)
/* BFF478 80241BF8 0080902D */  daddu     $s2, $a0, $zero
/* BFF47C 80241BFC AFBF002C */  sw        $ra, 0x2c($sp)
/* BFF480 80241C00 AFB10024 */  sw        $s1, 0x24($sp)
/* BFF484 80241C04 AFB00020 */  sw        $s0, 0x20($sp)
/* BFF488 80241C08 8E500148 */  lw        $s0, 0x148($s2)
/* BFF48C 80241C0C 0C00EABB */  jal       get_npc_unsafe
/* BFF490 80241C10 86040008 */   lh       $a0, 8($s0)
/* BFF494 80241C14 2404FEFF */  addiu     $a0, $zero, -0x101
/* BFF498 80241C18 0040882D */  daddu     $s1, $v0, $zero
/* BFF49C 80241C1C 0000282D */  daddu     $a1, $zero, $zero
/* BFF4A0 80241C20 8E03006C */  lw        $v1, 0x6c($s0)
/* BFF4A4 80241C24 00A0302D */  daddu     $a2, $a1, $zero
/* BFF4A8 80241C28 00641824 */  and       $v1, $v1, $a0
/* BFF4AC 80241C2C AE03006C */  sw        $v1, 0x6c($s0)
/* BFF4B0 80241C30 AFA00010 */  sw        $zero, 0x10($sp)
/* BFF4B4 80241C34 AFA00014 */  sw        $zero, 0x14($sp)
/* BFF4B8 80241C38 AFA00018 */  sw        $zero, 0x18($sp)
/* BFF4BC 80241C3C 8E240024 */  lw        $a0, 0x24($s1)
/* BFF4C0 80241C40 0C0B7A25 */  jal       func_802DE894
/* BFF4C4 80241C44 00A0382D */   daddu    $a3, $a1, $zero
/* BFF4C8 80241C48 8E02006C */  lw        $v0, 0x6c($s0)
/* BFF4CC 80241C4C 30421000 */  andi      $v0, $v0, 0x1000
/* BFF4D0 80241C50 10400008 */  beqz      $v0, .L80241C74
/* BFF4D4 80241C54 00000000 */   nop      
/* BFF4D8 80241C58 3C048000 */  lui       $a0, 0x8000
/* BFF4DC 80241C5C 0C05271B */  jal       stop_sound
/* BFF4E0 80241C60 34840011 */   ori      $a0, $a0, 0x11
/* BFF4E4 80241C64 8E02006C */  lw        $v0, 0x6c($s0)
/* BFF4E8 80241C68 2403EFFF */  addiu     $v1, $zero, -0x1001
/* BFF4EC 80241C6C 00431024 */  and       $v0, $v0, $v1
/* BFF4F0 80241C70 AE02006C */  sw        $v0, 0x6c($s0)
.L80241C74:
/* BFF4F4 80241C74 8E0200CC */  lw        $v0, 0xcc($s0)
/* BFF4F8 80241C78 8C430024 */  lw        $v1, 0x24($v0)
/* BFF4FC 80241C7C 24020014 */  addiu     $v0, $zero, 0x14
/* BFF500 80241C80 A622008E */  sh        $v0, 0x8e($s1)
/* BFF504 80241C84 24020011 */  addiu     $v0, $zero, 0x11
/* BFF508 80241C88 AE230028 */  sw        $v1, 0x28($s1)
/* BFF50C 80241C8C AE420070 */  sw        $v0, 0x70($s2)
/* BFF510 80241C90 8FBF002C */  lw        $ra, 0x2c($sp)
/* BFF514 80241C94 8FB20028 */  lw        $s2, 0x28($sp)
/* BFF518 80241C98 8FB10024 */  lw        $s1, 0x24($sp)
/* BFF51C 80241C9C 8FB00020 */  lw        $s0, 0x20($sp)
/* BFF520 80241CA0 03E00008 */  jr        $ra
/* BFF524 80241CA4 27BD0030 */   addiu    $sp, $sp, 0x30
