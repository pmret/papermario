.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel reset_all_actor_sounds
/* 19637C 80267A9C 90830136 */  lbu       $v1, 0x136($a0)
/* 196380 80267AA0 8C8501F4 */  lw        $a1, 0x1f4($a0)
/* 196384 80267AA4 000310C0 */  sll       $v0, $v1, 3
/* 196388 80267AA8 00431023 */  subu      $v0, $v0, $v1
/* 19638C 80267AAC 00021080 */  sll       $v0, $v0, 2
/* 196390 80267AB0 3C018028 */  lui       $at, %hi(bActorSoundTable)
/* 196394 80267AB4 00220821 */  addu      $at, $at, $v0
/* 196398 80267AB8 8C221468 */  lw        $v0, %lo(bActorSoundTable)($at)
/* 19639C 80267ABC AC82019C */  sw        $v0, 0x19c($a0)
/* 1963A0 80267AC0 000310C0 */  sll       $v0, $v1, 3
/* 1963A4 80267AC4 00431023 */  subu      $v0, $v0, $v1
/* 1963A8 80267AC8 00021080 */  sll       $v0, $v0, 2
/* 1963AC 80267ACC 3C018028 */  lui       $at, %hi(bActorSoundTable+0x4)
/* 1963B0 80267AD0 00220821 */  addu      $at, $at, $v0
/* 1963B4 80267AD4 8C22146C */  lw        $v0, %lo(bActorSoundTable+0x4)($at)
/* 1963B8 80267AD8 AC8201A0 */  sw        $v0, 0x1a0($a0)
/* 1963BC 80267ADC 000310C0 */  sll       $v0, $v1, 3
/* 1963C0 80267AE0 00431023 */  subu      $v0, $v0, $v1
/* 1963C4 80267AE4 00021080 */  sll       $v0, $v0, 2
/* 1963C8 80267AE8 3C018028 */  lui       $at, %hi(bActorSoundTable+0x8)
/* 1963CC 80267AEC 00220821 */  addu      $at, $at, $v0
/* 1963D0 80267AF0 8C221470 */  lw        $v0, %lo(bActorSoundTable+0x8)($at)
/* 1963D4 80267AF4 AC8201A4 */  sw        $v0, 0x1a4($a0)
/* 1963D8 80267AF8 000310C0 */  sll       $v0, $v1, 3
/* 1963DC 80267AFC 00431023 */  subu      $v0, $v0, $v1
/* 1963E0 80267B00 00021080 */  sll       $v0, $v0, 2
/* 1963E4 80267B04 3C018028 */  lui       $at, %hi(bActorSoundTable+0xC)
/* 1963E8 80267B08 00220821 */  addu      $at, $at, $v0
/* 1963EC 80267B0C 8C221474 */  lw        $v0, %lo(bActorSoundTable+0xC)($at)
/* 1963F0 80267B10 AC8201A8 */  sw        $v0, 0x1a8($a0)
/* 1963F4 80267B14 000310C0 */  sll       $v0, $v1, 3
/* 1963F8 80267B18 00431023 */  subu      $v0, $v0, $v1
/* 1963FC 80267B1C 00021080 */  sll       $v0, $v0, 2
/* 196400 80267B20 3C018028 */  lui       $at, %hi(bActorSoundTable+0x10)
/* 196404 80267B24 00220821 */  addu      $at, $at, $v0
/* 196408 80267B28 8C221478 */  lw        $v0, %lo(bActorSoundTable+0x10)($at)
/* 19640C 80267B2C AC8201AC */  sw        $v0, 0x1ac($a0)
/* 196410 80267B30 000310C0 */  sll       $v0, $v1, 3
/* 196414 80267B34 00431023 */  subu      $v0, $v0, $v1
/* 196418 80267B38 00021080 */  sll       $v0, $v0, 2
/* 19641C 80267B3C 3C018028 */  lui       $at, %hi(bActorSoundTable+0x14)
/* 196420 80267B40 00220821 */  addu      $at, $at, $v0
/* 196424 80267B44 8C22147C */  lw        $v0, %lo(bActorSoundTable+0x14)($at)
/* 196428 80267B48 AC8201B0 */  sw        $v0, 0x1b0($a0)
/* 19642C 80267B4C 000310C0 */  sll       $v0, $v1, 3
/* 196430 80267B50 00431023 */  subu      $v0, $v0, $v1
/* 196434 80267B54 00021080 */  sll       $v0, $v0, 2
/* 196438 80267B58 3C018028 */  lui       $at, %hi(bActorSoundTable+0x18)
/* 19643C 80267B5C 00220821 */  addu      $at, $at, $v0
/* 196440 80267B60 94221480 */  lhu       $v0, %lo(bActorSoundTable+0x18)($at)
/* 196444 80267B64 A48201B4 */  sh        $v0, 0x1b4($a0)
/* 196448 80267B68 000310C0 */  sll       $v0, $v1, 3
/* 19644C 80267B6C 00431023 */  subu      $v0, $v0, $v1
/* 196450 80267B70 00021080 */  sll       $v0, $v0, 2
/* 196454 80267B74 3C018028 */  lui       $at, %hi(bActorSoundTable+0x1A)
/* 196458 80267B78 00220821 */  addu      $at, $at, $v0
/* 19645C 80267B7C 94221482 */  lhu       $v0, %lo(bActorSoundTable+0x1A)($at)
/* 196460 80267B80 10A00014 */  beqz      $a1, .L80267BD4
/* 196464 80267B84 A48201B6 */   sh       $v0, 0x1b6($a0)
.L80267B88:
/* 196468 80267B88 8C82019C */  lw        $v0, 0x19c($a0)
/* 19646C 80267B8C ACA200A4 */  sw        $v0, 0xa4($a1)
/* 196470 80267B90 8C8201A0 */  lw        $v0, 0x1a0($a0)
/* 196474 80267B94 ACA200A8 */  sw        $v0, 0xa8($a1)
/* 196478 80267B98 8C8201A4 */  lw        $v0, 0x1a4($a0)
/* 19647C 80267B9C ACA200AC */  sw        $v0, 0xac($a1)
/* 196480 80267BA0 8C8201A8 */  lw        $v0, 0x1a8($a0)
/* 196484 80267BA4 ACA200B0 */  sw        $v0, 0xb0($a1)
/* 196488 80267BA8 8C8201AC */  lw        $v0, 0x1ac($a0)
/* 19648C 80267BAC ACA200B4 */  sw        $v0, 0xb4($a1)
/* 196490 80267BB0 8C8201B0 */  lw        $v0, 0x1b0($a0)
/* 196494 80267BB4 ACA200B8 */  sw        $v0, 0xb8($a1)
/* 196498 80267BB8 948201B4 */  lhu       $v0, 0x1b4($a0)
/* 19649C 80267BBC A4A200BC */  sh        $v0, 0xbc($a1)
/* 1964A0 80267BC0 948201B6 */  lhu       $v0, 0x1b6($a0)
/* 1964A4 80267BC4 A4A200BE */  sh        $v0, 0xbe($a1)
/* 1964A8 80267BC8 8CA5000C */  lw        $a1, 0xc($a1)
/* 1964AC 80267BCC 14A0FFEE */  bnez      $a1, .L80267B88
/* 1964B0 80267BD0 00000000 */   nop
.L80267BD4:
/* 1964B4 80267BD4 03E00008 */  jr        $ra
/* 1964B8 80267BD8 00000000 */   nop
