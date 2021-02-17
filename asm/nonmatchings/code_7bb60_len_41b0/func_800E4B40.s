.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E4B40
/* 7DFF0 800E4B40 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7DFF4 800E4B44 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7DFF8 800E4B48 3C018011 */  lui       $at, %hi(gPlayerStatus+0xA8)
/* 7DFFC 800E4B4C C420F070 */  lwc1      $f0, %lo(gPlayerStatus+0xA8)($at)
/* 7E000 800E4B50 3C0142B4 */  lui       $at, 0x42b4
/* 7E004 800E4B54 44811000 */  mtc1      $at, $f2
/* 7E008 800E4B58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E00C 800E4B5C AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E010 800E4B60 00031080 */  sll       $v0, $v1, 2
/* 7E014 800E4B64 00431021 */  addu      $v0, $v0, $v1
/* 7E018 800E4B68 00021080 */  sll       $v0, $v0, 2
/* 7E01C 800E4B6C 00431023 */  subu      $v0, $v0, $v1
/* 7E020 800E4B70 000218C0 */  sll       $v1, $v0, 3
/* 7E024 800E4B74 00431021 */  addu      $v0, $v0, $v1
/* 7E028 800E4B78 000210C0 */  sll       $v0, $v0, 3
/* 7E02C 800E4B7C 46020001 */  sub.s     $f0, $f0, $f2
/* 7E030 800E4B80 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 7E034 800E4B84 00220821 */  addu      $at, $at, $v0
/* 7E038 800E4B88 C4241DEC */  lwc1      $f4, %lo(gCameras+0x6C)($at)
/* 7E03C 800E4B8C 00A0402D */  daddu     $t0, $a1, $zero
/* 7E040 800E4B90 AFA60010 */  sw        $a2, 0x10($sp)
/* 7E044 800E4B94 46040000 */  add.s     $f0, $f0, $f4
/* 7E048 800E4B98 0000282D */  daddu     $a1, $zero, $zero
/* 7E04C 800E4B9C AFA70014 */  sw        $a3, 0x14($sp)
/* 7E050 800E4BA0 44060000 */  mfc1      $a2, $f0
/* 7E054 800E4BA4 0C039101 */  jal       func_800E4404
/* 7E058 800E4BA8 0100382D */   daddu    $a3, $t0, $zero
/* 7E05C 800E4BAC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E060 800E4BB0 03E00008 */  jr        $ra
/* 7E064 800E4BB4 27BD0020 */   addiu    $sp, $sp, 0x20
