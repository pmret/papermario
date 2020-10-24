.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240ACC_CF863C
/* CF863C 80240ACC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF8640 80240AD0 3C03800A */  lui       $v1, 0x800a
/* CF8644 80240AD4 8463A634 */  lh        $v1, -0x59cc($v1)
/* CF8648 80240AD8 3C05800B */  lui       $a1, %hi(gCameras)
/* CF864C 80240ADC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* CF8650 80240AE0 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF8654 80240AE4 00031080 */  sll       $v0, $v1, 2
/* CF8658 80240AE8 00431021 */  addu      $v0, $v0, $v1
/* CF865C 80240AEC 00021080 */  sll       $v0, $v0, 2
/* CF8660 80240AF0 00431023 */  subu      $v0, $v0, $v1
/* CF8664 80240AF4 000218C0 */  sll       $v1, $v0, 3
/* CF8668 80240AF8 00431021 */  addu      $v0, $v0, $v1
/* CF866C 80240AFC 8C830020 */  lw        $v1, 0x20($a0)
/* CF8670 80240B00 000210C0 */  sll       $v0, $v0, 3
/* CF8674 80240B04 8C630000 */  lw        $v1, ($v1)
/* CF8678 80240B08 30630001 */  andi      $v1, $v1, 1
/* CF867C 80240B0C 10600004 */  beqz      $v1, .L80240B20
/* CF8680 80240B10 00451021 */   addu     $v0, $v0, $a1
/* CF8684 80240B14 C44C006C */  lwc1      $f12, 0x6c($v0)
/* CF8688 80240B18 0C00A6C9 */  jal       clamp_angle
/* CF868C 80240B1C 46006307 */   neg.s    $f12, $f12
.L80240B20:
/* CF8690 80240B20 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF8694 80240B24 03E00008 */  jr        $ra
/* CF8698 80240B28 27BD0018 */   addiu    $sp, $sp, 0x18
