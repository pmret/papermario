.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F3A8
/* 1A7A8 8003F3A8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1A7AC 8003F3AC AFB00020 */  sw        $s0, 0x20($sp)
/* 1A7B0 8003F3B0 0080802D */  daddu     $s0, $a0, $zero
/* 1A7B4 8003F3B4 AFB10024 */  sw        $s1, 0x24($sp)
/* 1A7B8 8003F3B8 3C118011 */  lui       $s1, %hi(D_8010F188)
/* 1A7BC 8003F3BC 2631F188 */  addiu     $s1, $s1, %lo(D_8010F188)
/* 1A7C0 8003F3C0 AFB20028 */  sw        $s2, 0x28($sp)
/* 1A7C4 8003F3C4 3C128011 */  lui       $s2, %hi(D_8010F450)
/* 1A7C8 8003F3C8 2652F450 */  addiu     $s2, $s2, %lo(D_8010F450)
/* 1A7CC 8003F3CC 10A00005 */  beqz      $a1, .L8003F3E4
/* 1A7D0 8003F3D0 AFBF002C */   sw       $ra, 0x2c($sp)
/* 1A7D4 8003F3D4 24020028 */  addiu     $v0, $zero, 0x28
/* 1A7D8 8003F3D8 AE000070 */  sw        $zero, 0x70($s0)
/* 1A7DC 8003F3DC AE020074 */  sw        $v0, 0x74($s0)
/* 1A7E0 8003F3E0 AE000078 */  sw        $zero, 0x78($s0)
.L8003F3E4:
/* 1A7E4 8003F3E4 8E020078 */  lw        $v0, 0x78($s0)
/* 1A7E8 8003F3E8 24420001 */  addiu     $v0, $v0, 1
/* 1A7EC 8003F3EC AE020078 */  sw        $v0, 0x78($s0)
/* 1A7F0 8003F3F0 28420005 */  slti      $v0, $v0, 5
/* 1A7F4 8003F3F4 1440001B */  bnez      $v0, .L8003F464
/* 1A7F8 8003F3F8 00000000 */   nop
/* 1A7FC 8003F3FC 0C00A66F */  jal       func_800299BC
/* 1A800 8003F400 24040064 */   addiu    $a0, $zero, 0x64
/* 1A804 8003F404 28420032 */  slti      $v0, $v0, 0x32
/* 1A808 8003F408 50400016 */  beql      $v0, $zero, .L8003F464
/* 1A80C 8003F40C AE000078 */   sw       $zero, 0x78($s0)
/* 1A810 8003F410 8642000C */  lh        $v0, 0xc($s2)
/* 1A814 8003F414 9643000C */  lhu       $v1, 0xc($s2)
/* 1A818 8003F418 10400011 */  beqz      $v0, .L8003F460
/* 1A81C 8003F41C 2462FFFF */   addiu    $v0, $v1, -1
/* 1A820 8003F420 A642000C */  sh        $v0, 0xc($s2)
/* 1A824 8003F424 862300B0 */  lh        $v1, 0xb0($s1)
/* 1A828 8003F428 24020003 */  addiu     $v0, $zero, 3
/* 1A82C 8003F42C AFA20010 */  sw        $v0, 0x10($sp)
/* 1A830 8003F430 C620002C */  lwc1      $f0, 0x2c($s1)
/* 1A834 8003F434 44831000 */  mtc1      $v1, $f2
/* 1A838 8003F438 00000000 */  nop
/* 1A83C 8003F43C 468010A0 */  cvt.s.w   $f2, $f2
/* 1A840 8003F440 46020000 */  add.s     $f0, $f0, $f2
/* 1A844 8003F444 8E250028 */  lw        $a1, 0x28($s1)
/* 1A848 8003F448 8E270030 */  lw        $a3, 0x30($s1)
/* 1A84C 8003F44C 44060000 */  mfc1      $a2, $f0
/* 1A850 8003F450 24040157 */  addiu     $a0, $zero, 0x157
/* 1A854 8003F454 AFA00014 */  sw        $zero, 0x14($sp)
/* 1A858 8003F458 0C04DB0E */  jal       func_80136C38
/* 1A85C 8003F45C AFA00018 */   sw       $zero, 0x18($sp)
.L8003F460:
/* 1A860 8003F460 AE000078 */  sw        $zero, 0x78($s0)
.L8003F464:
/* 1A864 8003F464 8E030074 */  lw        $v1, 0x74($s0)
/* 1A868 8003F468 2463FFFF */  addiu     $v1, $v1, -1
/* 1A86C 8003F46C AE030074 */  sw        $v1, 0x74($s0)
/* 1A870 8003F470 8FBF002C */  lw        $ra, 0x2c($sp)
/* 1A874 8003F474 8FB20028 */  lw        $s2, 0x28($sp)
/* 1A878 8003F478 8FB10024 */  lw        $s1, 0x24($sp)
/* 1A87C 8003F47C 8FB00020 */  lw        $s0, 0x20($sp)
/* 1A880 8003F480 2C620001 */  sltiu     $v0, $v1, 1
/* 1A884 8003F484 03E00008 */  jr        $ra
/* 1A888 8003F488 27BD0030 */   addiu    $sp, $sp, 0x30
