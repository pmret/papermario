.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416C0_9B8040
/* 9B8040 802416C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9B8044 802416C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 9B8048 802416C8 0080902D */  daddu     $s2, $a0, $zero
/* 9B804C 802416CC AFBF001C */  sw        $ra, 0x1c($sp)
/* 9B8050 802416D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9B8054 802416D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B8058 802416D8 8E510148 */  lw        $s1, 0x148($s2)
/* 9B805C 802416DC 0C00EABB */  jal       get_npc_unsafe
/* 9B8060 802416E0 86240008 */   lh       $a0, 8($s1)
/* 9B8064 802416E4 0040802D */  daddu     $s0, $v0, $zero
/* 9B8068 802416E8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9B806C 802416EC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9B8070 802416F0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9B8074 802416F4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9B8078 802416F8 A600008E */  sh        $zero, 0x8e($s0)
/* 9B807C 802416FC 8C460028 */  lw        $a2, 0x28($v0)
/* 9B8080 80241700 0C00A720 */  jal       atan2
/* 9B8084 80241704 8C470030 */   lw       $a3, 0x30($v0)
/* 9B8088 80241708 E600000C */  swc1      $f0, 0xc($s0)
/* 9B808C 8024170C 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9B8090 80241710 8C420020 */  lw        $v0, 0x20($v0)
/* 9B8094 80241714 AE020028 */  sw        $v0, 0x28($s0)
/* 9B8098 80241718 2402000B */  addiu     $v0, $zero, 0xb
/* 9B809C 8024171C AE420070 */  sw        $v0, 0x70($s2)
/* 9B80A0 80241720 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9B80A4 80241724 8FB20018 */  lw        $s2, 0x18($sp)
/* 9B80A8 80241728 8FB10014 */  lw        $s1, 0x14($sp)
/* 9B80AC 8024172C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B80B0 80241730 03E00008 */  jr        $ra
/* 9B80B4 80241734 27BD0020 */   addiu    $sp, $sp, 0x20
