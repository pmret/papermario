.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406BC_D2C3EC
/* D2C3EC 802406BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D2C3F0 802406C0 AFB10014 */  sw        $s1, 0x14($sp)
/* D2C3F4 802406C4 0080882D */  daddu     $s1, $a0, $zero
/* D2C3F8 802406C8 AFBF0018 */  sw        $ra, 0x18($sp)
/* D2C3FC 802406CC AFB00010 */  sw        $s0, 0x10($sp)
/* D2C400 802406D0 8E300148 */  lw        $s0, 0x148($s1)
/* D2C404 802406D4 0C00EABB */  jal       get_npc_unsafe
/* D2C408 802406D8 86040008 */   lh       $a0, 8($s0)
/* D2C40C 802406DC 0040202D */  daddu     $a0, $v0, $zero
/* D2C410 802406E0 9482008E */  lhu       $v0, 0x8e($a0)
/* D2C414 802406E4 2442FFFF */  addiu     $v0, $v0, -1
/* D2C418 802406E8 A482008E */  sh        $v0, 0x8e($a0)
/* D2C41C 802406EC 00021400 */  sll       $v0, $v0, 0x10
/* D2C420 802406F0 1C400009 */  bgtz      $v0, .L80240718
/* D2C424 802406F4 24020003 */   addiu    $v0, $zero, 3
/* D2C428 802406F8 96030076 */  lhu       $v1, 0x76($s0)
/* D2C42C 802406FC AE02006C */  sw        $v0, 0x6c($s0)
/* D2C430 80240700 A483008E */  sh        $v1, 0x8e($a0)
/* D2C434 80240704 8E0200CC */  lw        $v0, 0xcc($s0)
/* D2C438 80240708 8C420024 */  lw        $v0, 0x24($v0)
/* D2C43C 8024070C AC820028 */  sw        $v0, 0x28($a0)
/* D2C440 80240710 24020020 */  addiu     $v0, $zero, 0x20
/* D2C444 80240714 AE220070 */  sw        $v0, 0x70($s1)
.L80240718:
/* D2C448 80240718 8FBF0018 */  lw        $ra, 0x18($sp)
/* D2C44C 8024071C 8FB10014 */  lw        $s1, 0x14($sp)
/* D2C450 80240720 8FB00010 */  lw        $s0, 0x10($sp)
/* D2C454 80240724 03E00008 */  jr        $ra
/* D2C458 80240728 27BD0020 */   addiu    $sp, $sp, 0x20
