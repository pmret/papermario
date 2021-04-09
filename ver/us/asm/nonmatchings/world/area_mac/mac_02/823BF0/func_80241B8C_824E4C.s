.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_02_UnkFunc28
/* 824E4C 80241B8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 824E50 80241B90 3C03800A */  lui       $v1, %hi(D_8009A634)
/* 824E54 80241B94 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* 824E58 80241B98 3C05800B */  lui       $a1, %hi(gCameras)
/* 824E5C 80241B9C 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 824E60 80241BA0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 824E64 80241BA4 00031080 */  sll       $v0, $v1, 2
/* 824E68 80241BA8 00431021 */  addu      $v0, $v0, $v1
/* 824E6C 80241BAC 00021080 */  sll       $v0, $v0, 2
/* 824E70 80241BB0 00431023 */  subu      $v0, $v0, $v1
/* 824E74 80241BB4 000218C0 */  sll       $v1, $v0, 3
/* 824E78 80241BB8 00431021 */  addu      $v0, $v0, $v1
/* 824E7C 80241BBC 8C830020 */  lw        $v1, 0x20($a0)
/* 824E80 80241BC0 000210C0 */  sll       $v0, $v0, 3
/* 824E84 80241BC4 8C630000 */  lw        $v1, ($v1)
/* 824E88 80241BC8 30630001 */  andi      $v1, $v1, 1
/* 824E8C 80241BCC 10600004 */  beqz      $v1, .L80241BE0
/* 824E90 80241BD0 00451021 */   addu     $v0, $v0, $a1
/* 824E94 80241BD4 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 824E98 80241BD8 0C00A6C9 */  jal       clamp_angle
/* 824E9C 80241BDC 46006307 */   neg.s    $f12, $f12
.L80241BE0:
/* 824EA0 80241BE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 824EA4 80241BE4 03E00008 */  jr        $ra
/* 824EA8 80241BE8 27BD0018 */   addiu    $sp, $sp, 0x18
