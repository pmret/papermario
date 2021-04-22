.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241134_9C6514
/* 9C6514 80241134 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C6518 80241138 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* 9C651C 8024113C 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* 9C6520 80241140 3C05800B */  lui       $a1, %hi(gCameras)
/* 9C6524 80241144 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 9C6528 80241148 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C652C 8024114C 00031080 */  sll       $v0, $v1, 2
/* 9C6530 80241150 00431021 */  addu      $v0, $v0, $v1
/* 9C6534 80241154 00021080 */  sll       $v0, $v0, 2
/* 9C6538 80241158 00431023 */  subu      $v0, $v0, $v1
/* 9C653C 8024115C 000218C0 */  sll       $v1, $v0, 3
/* 9C6540 80241160 00431021 */  addu      $v0, $v0, $v1
/* 9C6544 80241164 8C830020 */  lw        $v1, 0x20($a0)
/* 9C6548 80241168 000210C0 */  sll       $v0, $v0, 3
/* 9C654C 8024116C 8C630000 */  lw        $v1, ($v1)
/* 9C6550 80241170 30630001 */  andi      $v1, $v1, 1
/* 9C6554 80241174 10600004 */  beqz      $v1, .L80241188
/* 9C6558 80241178 00451021 */   addu     $v0, $v0, $a1
/* 9C655C 8024117C C44C006C */  lwc1      $f12, 0x6c($v0)
/* 9C6560 80241180 0C00A6C9 */  jal       clamp_angle
/* 9C6564 80241184 46006307 */   neg.s    $f12, $f12
.L80241188:
/* 9C6568 80241188 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C656C 8024118C 03E00008 */  jr        $ra
/* 9C6570 80241190 27BD0018 */   addiu    $sp, $sp, 0x18
