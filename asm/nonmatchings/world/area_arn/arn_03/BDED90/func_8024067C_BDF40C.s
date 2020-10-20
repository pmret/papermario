.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024067C_BDF40C
/* BDF40C 8024067C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDF410 80240680 AFB10014 */  sw        $s1, 0x14($sp)
/* BDF414 80240684 0080882D */  daddu     $s1, $a0, $zero
/* BDF418 80240688 AFBF001C */  sw        $ra, 0x1c($sp)
/* BDF41C 8024068C AFB20018 */  sw        $s2, 0x18($sp)
/* BDF420 80240690 AFB00010 */  sw        $s0, 0x10($sp)
/* BDF424 80240694 8E300148 */  lw        $s0, 0x148($s1)
/* BDF428 80240698 86040008 */  lh        $a0, 8($s0)
/* BDF42C 8024069C 0C00EABB */  jal       get_npc_unsafe
/* BDF430 802406A0 00A0902D */   daddu    $s2, $a1, $zero
/* BDF434 802406A4 8E230078 */  lw        $v1, 0x78($s1)
/* BDF438 802406A8 24630001 */  addiu     $v1, $v1, 1
/* BDF43C 802406AC AE230078 */  sw        $v1, 0x78($s1)
/* BDF440 802406B0 8E0400D0 */  lw        $a0, 0xd0($s0)
/* BDF444 802406B4 8C840000 */  lw        $a0, ($a0)
/* BDF448 802406B8 0064182A */  slt       $v1, $v1, $a0
/* BDF44C 802406BC 14600002 */  bnez      $v1, .L802406C8
/* BDF450 802406C0 0040282D */   daddu    $a1, $v0, $zero
/* BDF454 802406C4 AE200078 */  sw        $zero, 0x78($s1)
.L802406C8:
/* BDF458 802406C8 8E0200CC */  lw        $v0, 0xcc($s0)
/* BDF45C 802406CC 8C420004 */  lw        $v0, 4($v0)
/* BDF460 802406D0 ACA20028 */  sw        $v0, 0x28($a1)
/* BDF464 802406D4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BDF468 802406D8 8C42007C */  lw        $v0, 0x7c($v0)
/* BDF46C 802406DC 04410004 */  bgez      $v0, .L802406F0
/* BDF470 802406E0 00000000 */   nop      
/* BDF474 802406E4 C6400000 */  lwc1      $f0, ($s2)
/* BDF478 802406E8 080901C4 */  j         .L80240710
/* BDF47C 802406EC E4A00018 */   swc1     $f0, 0x18($a1)
.L802406F0:
/* BDF480 802406F0 3C018024 */  lui       $at, 0x8024
/* BDF484 802406F4 D4224868 */  ldc1      $f2, 0x4868($at)
/* BDF488 802406F8 44820000 */  mtc1      $v0, $f0
/* BDF48C 802406FC 00000000 */  nop       
/* BDF490 80240700 46800021 */  cvt.d.w   $f0, $f0
/* BDF494 80240704 46220003 */  div.d     $f0, $f0, $f2
/* BDF498 80240708 46200020 */  cvt.s.d   $f0, $f0
/* BDF49C 8024070C E4A00018 */  swc1      $f0, 0x18($a1)
.L80240710:
/* BDF4A0 80240710 24020001 */  addiu     $v0, $zero, 1
/* BDF4A4 80240714 AE220070 */  sw        $v0, 0x70($s1)
/* BDF4A8 80240718 8FBF001C */  lw        $ra, 0x1c($sp)
/* BDF4AC 8024071C 8FB20018 */  lw        $s2, 0x18($sp)
/* BDF4B0 80240720 8FB10014 */  lw        $s1, 0x14($sp)
/* BDF4B4 80240724 8FB00010 */  lw        $s0, 0x10($sp)
/* BDF4B8 80240728 03E00008 */  jr        $ra
/* BDF4BC 8024072C 27BD0020 */   addiu    $sp, $sp, 0x20
