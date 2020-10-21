.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243310_9AB700
/* 9AB700 80243310 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9AB704 80243314 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9AB708 80243318 0080982D */  daddu     $s3, $a0, $zero
/* 9AB70C 8024331C AFBF0020 */  sw        $ra, 0x20($sp)
/* 9AB710 80243320 AFB20018 */  sw        $s2, 0x18($sp)
/* 9AB714 80243324 AFB10014 */  sw        $s1, 0x14($sp)
/* 9AB718 80243328 AFB00010 */  sw        $s0, 0x10($sp)
/* 9AB71C 8024332C 8E710148 */  lw        $s1, 0x148($s3)
/* 9AB720 80243330 0C00EABB */  jal       get_npc_unsafe
/* 9AB724 80243334 86240008 */   lh       $a0, 8($s1)
/* 9AB728 80243338 0040802D */  daddu     $s0, $v0, $zero
/* 9AB72C 8024333C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9AB730 80243340 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9AB734 80243344 3C01C0A0 */  lui       $at, 0xc0a0
/* 9AB738 80243348 44811000 */  mtc1      $at, $f2
/* 9AB73C 8024334C 3C013E19 */  lui       $at, 0x3e19
/* 9AB740 80243350 3421999A */  ori       $at, $at, 0x999a
/* 9AB744 80243354 44810000 */  mtc1      $at, $f0
/* 9AB748 80243358 8C420024 */  lw        $v0, 0x24($v0)
/* 9AB74C 8024335C 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* 9AB750 80243360 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* 9AB754 80243364 E602001C */  swc1      $f2, 0x1c($s0)
/* 9AB758 80243368 E6000014 */  swc1      $f0, 0x14($s0)
/* 9AB75C 8024336C AE020028 */  sw        $v0, 0x28($s0)
/* 9AB760 80243370 8E22008C */  lw        $v0, 0x8c($s1)
/* 9AB764 80243374 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9AB768 80243378 00021FC2 */  srl       $v1, $v0, 0x1f
/* 9AB76C 8024337C 00431021 */  addu      $v0, $v0, $v1
/* 9AB770 80243380 8E430000 */  lw        $v1, ($s2)
/* 9AB774 80243384 00021043 */  sra       $v0, $v0, 1
/* 9AB778 80243388 A60200A8 */  sh        $v0, 0xa8($s0)
/* 9AB77C 8024338C 8C660028 */  lw        $a2, 0x28($v1)
/* 9AB780 80243390 0C00A7B5 */  jal       dist2D
/* 9AB784 80243394 8C670030 */   lw       $a3, 0x30($v1)
/* 9AB788 80243398 0200202D */  daddu     $a0, $s0, $zero
/* 9AB78C 8024339C 0000302D */  daddu     $a2, $zero, $zero
/* 9AB790 802433A0 C6020038 */  lwc1      $f2, 0x38($s0)
/* 9AB794 802433A4 3C0140E0 */  lui       $at, 0x40e0
/* 9AB798 802433A8 44810000 */  mtc1      $at, $f0
/* 9AB79C 802433AC 4600110D */  trunc.w.s $f4, $f2
/* 9AB7A0 802433B0 44022000 */  mfc1      $v0, $f4
/* 9AB7A4 802433B4 E6000018 */  swc1      $f0, 0x18($s0)
/* 9AB7A8 802433B8 A6220010 */  sh        $v0, 0x10($s1)
/* 9AB7AC 802433BC C600003C */  lwc1      $f0, 0x3c($s0)
/* 9AB7B0 802433C0 240502C1 */  addiu     $a1, $zero, 0x2c1
/* 9AB7B4 802433C4 4600010D */  trunc.w.s $f4, $f0
/* 9AB7B8 802433C8 44022000 */  mfc1      $v0, $f4
/* 9AB7BC 802433CC 00000000 */  nop       
/* 9AB7C0 802433D0 A6220012 */  sh        $v0, 0x12($s1)
/* 9AB7C4 802433D4 C6000040 */  lwc1      $f0, 0x40($s0)
/* 9AB7C8 802433D8 24020001 */  addiu     $v0, $zero, 1
/* 9AB7CC 802433DC A2220007 */  sb        $v0, 7($s1)
/* 9AB7D0 802433E0 4600010D */  trunc.w.s $f4, $f0
/* 9AB7D4 802433E4 44022000 */  mfc1      $v0, $f4
/* 9AB7D8 802433E8 0C012530 */  jal       func_800494C0
/* 9AB7DC 802433EC A6220014 */   sh       $v0, 0x14($s1)
/* 9AB7E0 802433F0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9AB7E4 802433F4 8E420000 */  lw        $v0, ($s2)
/* 9AB7E8 802433F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9AB7EC 802433FC 8C460028 */  lw        $a2, 0x28($v0)
/* 9AB7F0 80243400 0C00A720 */  jal       atan2
/* 9AB7F4 80243404 8C470030 */   lw       $a3, 0x30($v0)
/* 9AB7F8 80243408 2402000C */  addiu     $v0, $zero, 0xc
/* 9AB7FC 8024340C A602008E */  sh        $v0, 0x8e($s0)
/* 9AB800 80243410 2402000D */  addiu     $v0, $zero, 0xd
/* 9AB804 80243414 E600000C */  swc1      $f0, 0xc($s0)
/* 9AB808 80243418 AE620070 */  sw        $v0, 0x70($s3)
/* 9AB80C 8024341C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9AB810 80243420 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9AB814 80243424 8FB20018 */  lw        $s2, 0x18($sp)
/* 9AB818 80243428 8FB10014 */  lw        $s1, 0x14($sp)
/* 9AB81C 8024342C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AB820 80243430 03E00008 */  jr        $ra
/* 9AB824 80243434 27BD0028 */   addiu    $sp, $sp, 0x28
