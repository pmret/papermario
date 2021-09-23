.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416E8_EE00A8
/* EE00A8 802416E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE00AC 802416EC AFB00010 */  sw        $s0, 0x10($sp)
/* EE00B0 802416F0 24100032 */  addiu     $s0, $zero, 0x32
/* EE00B4 802416F4 AFBF0014 */  sw        $ra, 0x14($sp)
.L802416F8:
/* EE00B8 802416F8 0C010ABD */  jal       dead_get_enemy
/* EE00BC 802416FC 0200202D */   daddu    $a0, $s0, $zero
/* EE00C0 80241700 8C420094 */  lw        $v0, 0x94($v0)
/* EE00C4 80241704 54400003 */  bnel      $v0, $zero, .L80241714
/* EE00C8 80241708 26100001 */   addiu    $s0, $s0, 1
/* EE00CC 8024170C 080905C8 */  j         .L80241720
/* EE00D0 80241710 0200102D */   daddu    $v0, $s0, $zero
.L80241714:
/* EE00D4 80241714 2A020038 */  slti      $v0, $s0, 0x38
/* EE00D8 80241718 1440FFF7 */  bnez      $v0, .L802416F8
/* EE00DC 8024171C 2402FFFF */   addiu    $v0, $zero, -1
.L80241720:
/* EE00E0 80241720 8FBF0014 */  lw        $ra, 0x14($sp)
/* EE00E4 80241724 8FB00010 */  lw        $s0, 0x10($sp)
/* EE00E8 80241728 03E00008 */  jr        $ra
/* EE00EC 8024172C 27BD0018 */   addiu    $sp, $sp, 0x18
