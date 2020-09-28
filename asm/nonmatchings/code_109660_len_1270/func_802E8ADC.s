.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E8ADC
/* 10A35C 802E8ADC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10A360 802E8AE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 10A364 802E8AE4 0080802D */  daddu     $s0, $a0, $zero
/* 10A368 802E8AE8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 10A36C 802E8AEC 92020006 */  lbu       $v0, 6($s0)
/* 10A370 802E8AF0 3C078011 */  lui       $a3, %hi(gPlayerStatus)
/* 10A374 802E8AF4 24E7EFC8 */  addiu     $a3, $a3, %lo(gPlayerStatus)
/* 10A378 802E8AF8 30420001 */  andi      $v0, $v0, 1
/* 10A37C 802E8AFC 10400027 */  beqz      $v0, .L802E8B9C
/* 10A380 802E8B00 2404FFBF */   addiu    $a0, $zero, -0x41
/* 10A384 802E8B04 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 10A388 802E8B08 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 10A38C 802E8B0C 8C430000 */  lw        $v1, ($v0)
/* 10A390 802E8B10 8CE40000 */  lw        $a0, ($a3)
/* 10A394 802E8B14 34630040 */  ori       $v1, $v1, 0x40
/* 10A398 802E8B18 30843000 */  andi      $a0, $a0, 0x3000
/* 10A39C 802E8B1C 14800024 */  bnez      $a0, .L802E8BB0
/* 10A3A0 802E8B20 AC430000 */   sw       $v1, ($v0)
/* 10A3A4 802E8B24 8CE200E8 */  lw        $v0, 0xe8($a3)
/* 10A3A8 802E8B28 8CE400EC */  lw        $a0, 0xec($a3)
/* 10A3AC 802E8B2C 04420001 */  bltzl     $v0, .L802E8B34
/* 10A3B0 802E8B30 00021023 */   negu     $v0, $v0
.L802E8B34:
/* 10A3B4 802E8B34 14400003 */  bnez      $v0, .L802E8B44
/* 10A3B8 802E8B38 00000000 */   nop      
/* 10A3BC 802E8B3C 1080001C */  beqz      $a0, .L802E8BB0
/* 10A3C0 802E8B40 00000000 */   nop      
.L802E8B44:
/* 10A3C4 802E8B44 44822000 */  mtc1      $v0, $f4
/* 10A3C8 802E8B48 00000000 */  nop       
/* 10A3CC 802E8B4C 46802120 */  cvt.s.w   $f4, $f4
/* 10A3D0 802E8B50 44062000 */  mfc1      $a2, $f4
/* 10A3D4 802E8B54 44842000 */  mtc1      $a0, $f4
/* 10A3D8 802E8B58 00000000 */  nop       
/* 10A3DC 802E8B5C 46802120 */  cvt.s.w   $f4, $f4
/* 10A3E0 802E8B60 44806000 */  mtc1      $zero, $f12
/* 10A3E4 802E8B64 44072000 */  mfc1      $a3, $f4
/* 10A3E8 802E8B68 0C00A720 */  jal       atan2
/* 10A3EC 802E8B6C 46006386 */   mov.s    $f14, $f12
/* 10A3F0 802E8B70 3C014270 */  lui       $at, 0x4270
/* 10A3F4 802E8B74 44811000 */  mtc1      $at, $f2
/* 10A3F8 802E8B78 00000000 */  nop       
/* 10A3FC 802E8B7C 4602003C */  c.lt.s    $f0, $f2
/* 10A400 802E8B80 00000000 */  nop       
/* 10A404 802E8B84 4500000A */  bc1f      .L802E8BB0
/* 10A408 802E8B88 00000000 */   nop      
/* 10A40C 802E8B8C 0C043F5A */  jal       func_8010FD68
/* 10A410 802E8B90 0200202D */   daddu    $a0, $s0, $zero
/* 10A414 802E8B94 080BA2EC */  j         .L802E8BB0
/* 10A418 802E8B98 00000000 */   nop      
.L802E8B9C:
/* 10A41C 802E8B9C 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 10A420 802E8BA0 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 10A424 802E8BA4 8C430000 */  lw        $v1, ($v0)
/* 10A428 802E8BA8 00641824 */  and       $v1, $v1, $a0
/* 10A42C 802E8BAC AC430000 */  sw        $v1, ($v0)
.L802E8BB0:
/* 10A430 802E8BB0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 10A434 802E8BB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 10A438 802E8BB8 03E00008 */  jr        $ra
/* 10A43C 802E8BBC 27BD0018 */   addiu    $sp, $sp, 0x18
