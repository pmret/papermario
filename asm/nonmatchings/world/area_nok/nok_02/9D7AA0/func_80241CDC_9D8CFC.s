.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CDC_9D8CFC
/* 9D8CFC 80241CDC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D8D00 80241CE0 3C03800A */  lui       $v1, %hi(D_8009A634)
/* 9D8D04 80241CE4 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* 9D8D08 80241CE8 3C05800B */  lui       $a1, %hi(gCameras)
/* 9D8D0C 80241CEC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 9D8D10 80241CF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D8D14 80241CF4 00031080 */  sll       $v0, $v1, 2
/* 9D8D18 80241CF8 00431021 */  addu      $v0, $v0, $v1
/* 9D8D1C 80241CFC 00021080 */  sll       $v0, $v0, 2
/* 9D8D20 80241D00 00431023 */  subu      $v0, $v0, $v1
/* 9D8D24 80241D04 000218C0 */  sll       $v1, $v0, 3
/* 9D8D28 80241D08 00431021 */  addu      $v0, $v0, $v1
/* 9D8D2C 80241D0C 8C830020 */  lw        $v1, 0x20($a0)
/* 9D8D30 80241D10 000210C0 */  sll       $v0, $v0, 3
/* 9D8D34 80241D14 8C630000 */  lw        $v1, ($v1)
/* 9D8D38 80241D18 30630001 */  andi      $v1, $v1, 1
/* 9D8D3C 80241D1C 10600004 */  beqz      $v1, .L80241D30
/* 9D8D40 80241D20 00451021 */   addu     $v0, $v0, $a1
/* 9D8D44 80241D24 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 9D8D48 80241D28 0C00A6C9 */  jal       clamp_angle
/* 9D8D4C 80241D2C 46006307 */   neg.s    $f12, $f12
.L80241D30:
/* 9D8D50 80241D30 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D8D54 80241D34 03E00008 */  jr        $ra
/* 9D8D58 80241D38 27BD0018 */   addiu    $sp, $sp, 0x18
