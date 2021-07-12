.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_restore_world_cameras
/* 16F388 80240AA8 3C088011 */  lui       $t0, %hi(gPlayerStatus)
/* 16F38C 80240AAC 2508EFC8 */  addiu     $t0, $t0, %lo(gPlayerStatus)
/* 16F390 80240AB0 0000382D */  daddu     $a3, $zero, $zero
/* 16F394 80240AB4 3C04802A */  lui       $a0, %hi(D_8029DA50)
/* 16F398 80240AB8 2484DA50 */  addiu     $a0, $a0, %lo(D_8029DA50)
/* 16F39C 80240ABC 3C06800B */  lui       $a2, %hi(gCameras)
/* 16F3A0 80240AC0 24C61D80 */  addiu     $a2, $a2, %lo(gCameras)
.L80240AC4:
/* 16F3A4 80240AC4 00C0182D */  daddu     $v1, $a2, $zero
/* 16F3A8 80240AC8 0080102D */  daddu     $v0, $a0, $zero
/* 16F3AC 80240ACC 24850550 */  addiu     $a1, $a0, 0x550
.L80240AD0:
/* 16F3B0 80240AD0 8C490000 */  lw        $t1, ($v0)
/* 16F3B4 80240AD4 8C4A0004 */  lw        $t2, 4($v0)
/* 16F3B8 80240AD8 8C4B0008 */  lw        $t3, 8($v0)
/* 16F3BC 80240ADC 8C4C000C */  lw        $t4, 0xc($v0)
/* 16F3C0 80240AE0 AC690000 */  sw        $t1, ($v1)
/* 16F3C4 80240AE4 AC6A0004 */  sw        $t2, 4($v1)
/* 16F3C8 80240AE8 AC6B0008 */  sw        $t3, 8($v1)
/* 16F3CC 80240AEC AC6C000C */  sw        $t4, 0xc($v1)
/* 16F3D0 80240AF0 24420010 */  addiu     $v0, $v0, 0x10
/* 16F3D4 80240AF4 1445FFF6 */  bne       $v0, $a1, .L80240AD0
/* 16F3D8 80240AF8 24630010 */   addiu    $v1, $v1, 0x10
/* 16F3DC 80240AFC 8C490000 */  lw        $t1, ($v0)
/* 16F3E0 80240B00 8C4A0004 */  lw        $t2, 4($v0)
/* 16F3E4 80240B04 AC690000 */  sw        $t1, ($v1)
/* 16F3E8 80240B08 AC6A0004 */  sw        $t2, 4($v1)
/* 16F3EC 80240B0C 24840558 */  addiu     $a0, $a0, 0x558
/* 16F3F0 80240B10 24E70001 */  addiu     $a3, $a3, 1
/* 16F3F4 80240B14 28E20004 */  slti      $v0, $a3, 4
/* 16F3F8 80240B18 1440FFEA */  bnez      $v0, .L80240AC4
/* 16F3FC 80240B1C 24C60558 */   addiu    $a2, $a2, 0x558
/* 16F400 80240B20 3C01802A */  lui       $at, %hi(D_8029EFB0)
/* 16F404 80240B24 C420EFB0 */  lwc1      $f0, %lo(D_8029EFB0)($at)
/* 16F408 80240B28 3C01802A */  lui       $at, %hi(D_8029EFB4)
/* 16F40C 80240B2C C422EFB4 */  lwc1      $f2, %lo(D_8029EFB4)($at)
/* 16F410 80240B30 3C01802A */  lui       $at, %hi(D_8029EFB8)
/* 16F414 80240B34 C424EFB8 */  lwc1      $f4, %lo(D_8029EFB8)($at)
/* 16F418 80240B38 3C02802A */  lui       $v0, %hi(D_8029DA34)
/* 16F41C 80240B3C 8C42DA34 */  lw        $v0, %lo(D_8029DA34)($v0)
/* 16F420 80240B40 3C018007 */  lui       $at, %hi(gCurrentCameraID)
/* 16F424 80240B44 AC207410 */  sw        $zero, %lo(gCurrentCameraID)($at)
/* 16F428 80240B48 30420080 */  andi      $v0, $v0, 0x80
/* 16F42C 80240B4C E5000028 */  swc1      $f0, 0x28($t0)
/* 16F430 80240B50 E502002C */  swc1      $f2, 0x2c($t0)
/* 16F434 80240B54 10400007 */  beqz      $v0, .L80240B74
/* 16F438 80240B58 E5040030 */   swc1     $f4, 0x30($t0)
/* 16F43C 80240B5C 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* 16F440 80240B60 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* 16F444 80240B64 8C620000 */  lw        $v0, ($v1)
/* 16F448 80240B68 34420080 */  ori       $v0, $v0, 0x80
/* 16F44C 80240B6C 080902E3 */  j         .L80240B8C
/* 16F450 80240B70 AC620000 */   sw       $v0, ($v1)
.L80240B74:
/* 16F454 80240B74 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* 16F458 80240B78 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* 16F45C 80240B7C 8C430000 */  lw        $v1, ($v0)
/* 16F460 80240B80 2404FF7F */  addiu     $a0, $zero, -0x81
/* 16F464 80240B84 00641824 */  and       $v1, $v1, $a0
/* 16F468 80240B88 AC430000 */  sw        $v1, ($v0)
.L80240B8C:
/* 16F46C 80240B8C 3C02800E */  lui       $v0, %hi(gBattleStatus+0x4)
/* 16F470 80240B90 8C42C074 */  lw        $v0, %lo(gBattleStatus+0x4)($v0)
/* 16F474 80240B94 30420040 */  andi      $v0, $v0, 0x40
/* 16F478 80240B98 10400006 */  beqz      $v0, .L80240BB4
/* 16F47C 80240B9C 00000000 */   nop
/* 16F480 80240BA0 3C03802A */  lui       $v1, %hi(D_8029DA33)
/* 16F484 80240BA4 9063DA33 */  lbu       $v1, %lo(D_8029DA33)($v1)
/* 16F488 80240BA8 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 16F48C 80240BAC 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 16F490 80240BB0 A0430012 */  sb        $v1, 0x12($v0)
.L80240BB4:
/* 16F494 80240BB4 03E00008 */  jr        $ra
/* 16F498 80240BB8 00000000 */   nop
