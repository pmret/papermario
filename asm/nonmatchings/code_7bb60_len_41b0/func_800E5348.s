.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E5348
/* 7E7F8 800E5348 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7E7FC 800E534C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7E800 800E5350 3C018011 */  lui       $at, %hi(gPlayerStatus+0x84)
/* 7E804 800E5354 C42EF04C */  lwc1      $f14, %lo(gPlayerStatus+0x84)($at)
/* 7E808 800E5358 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E80C 800E535C AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E810 800E5360 00031080 */  sll       $v0, $v1, 2
/* 7E814 800E5364 00431021 */  addu      $v0, $v0, $v1
/* 7E818 800E5368 00021080 */  sll       $v0, $v0, 2
/* 7E81C 800E536C 00431023 */  subu      $v0, $v0, $v1
/* 7E820 800E5370 000218C0 */  sll       $v1, $v0, 3
/* 7E824 800E5374 00431021 */  addu      $v0, $v0, $v1
/* 7E828 800E5378 000210C0 */  sll       $v0, $v0, 3
/* 7E82C 800E537C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 7E830 800E5380 00220821 */  addu      $at, $at, $v0
/* 7E834 800E5384 C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* 7E838 800E5388 0C00A70A */  jal       get_clamped_angle_diff
/* 7E83C 800E538C 00000000 */   nop
/* 7E840 800E5390 3C01C0A0 */  lui       $at, 0xc0a0
/* 7E844 800E5394 44811000 */  mtc1      $at, $f2
/* 7E848 800E5398 46000106 */  mov.s     $f4, $f0
/* 7E84C 800E539C 4602203C */  c.lt.s    $f4, $f2
/* 7E850 800E53A0 00000000 */  nop
/* 7E854 800E53A4 4500000B */  bc1f      .L800E53D4
/* 7E858 800E53A8 00000000 */   nop
/* 7E85C 800E53AC 3C01C32F */  lui       $at, 0xc32f
/* 7E860 800E53B0 44810000 */  mtc1      $at, $f0
/* 7E864 800E53B4 00000000 */  nop
/* 7E868 800E53B8 4604003C */  c.lt.s    $f0, $f4
/* 7E86C 800E53BC 00000000 */  nop
/* 7E870 800E53C0 45000004 */  bc1f      .L800E53D4
/* 7E874 800E53C4 00000000 */   nop
/* 7E878 800E53C8 44802000 */  mtc1      $zero, $f4
/* 7E87C 800E53CC 08039507 */  j         .L800E541C
/* 7E880 800E53D0 00000000 */   nop
.L800E53D4:
/* 7E884 800E53D4 3C0140A0 */  lui       $at, 0x40a0
/* 7E888 800E53D8 44810000 */  mtc1      $at, $f0
/* 7E88C 800E53DC 00000000 */  nop
/* 7E890 800E53E0 4604003C */  c.lt.s    $f0, $f4
/* 7E894 800E53E4 00000000 */  nop
/* 7E898 800E53E8 45000009 */  bc1f      .L800E5410
/* 7E89C 800E53EC 00000000 */   nop
/* 7E8A0 800E53F0 3C01432F */  lui       $at, 0x432f
/* 7E8A4 800E53F4 44810000 */  mtc1      $at, $f0
/* 7E8A8 800E53F8 00000000 */  nop
/* 7E8AC 800E53FC 4600203C */  c.lt.s    $f4, $f0
/* 7E8B0 800E5400 3C014334 */  lui       $at, 0x4334
/* 7E8B4 800E5404 44812000 */  mtc1      $at, $f4
/* 7E8B8 800E5408 45010004 */  bc1t      .L800E541C
/* 7E8BC 800E540C 00000000 */   nop
.L800E5410:
/* 7E8C0 800E5410 3C01800F */  lui       $at, %hi(D_800F7B40)
/* 7E8C4 800E5414 C4247B40 */  lwc1      $f4, %lo(D_800F7B40)($at)
/* 7E8C8 800E5418 46802120 */  cvt.s.w   $f4, $f4
.L800E541C:
/* 7E8CC 800E541C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7E8D0 800E5420 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7E8D4 800E5424 3C0142B4 */  lui       $at, 0x42b4
/* 7E8D8 800E5428 44816000 */  mtc1      $at, $f12
/* 7E8DC 800E542C 00031080 */  sll       $v0, $v1, 2
/* 7E8E0 800E5430 00431021 */  addu      $v0, $v0, $v1
/* 7E8E4 800E5434 00021080 */  sll       $v0, $v0, 2
/* 7E8E8 800E5438 00431023 */  subu      $v0, $v0, $v1
/* 7E8EC 800E543C 000218C0 */  sll       $v1, $v0, 3
/* 7E8F0 800E5440 00431021 */  addu      $v0, $v0, $v1
/* 7E8F4 800E5444 000210C0 */  sll       $v0, $v0, 3
/* 7E8F8 800E5448 460C2301 */  sub.s     $f12, $f4, $f12
/* 7E8FC 800E544C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 7E900 800E5450 00220821 */  addu      $at, $at, $v0
/* 7E904 800E5454 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 7E908 800E5458 0C00A6C9 */  jal       clamp_angle
/* 7E90C 800E545C 46006300 */   add.s    $f12, $f12, $f0
/* 7E910 800E5460 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E914 800E5464 03E00008 */  jr        $ra
/* 7E918 800E5468 27BD0018 */   addiu    $sp, $sp, 0x18
