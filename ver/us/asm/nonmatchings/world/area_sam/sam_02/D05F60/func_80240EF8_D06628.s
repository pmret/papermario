.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EF8_D06628
/* D06628 80240EF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D0662C 80240EFC 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D06630 80240F00 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D06634 80240F04 3C05800B */  lui       $a1, %hi(gCameras)
/* D06638 80240F08 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* D0663C 80240F0C AFBF0010 */  sw        $ra, 0x10($sp)
/* D06640 80240F10 00031080 */  sll       $v0, $v1, 2
/* D06644 80240F14 00431021 */  addu      $v0, $v0, $v1
/* D06648 80240F18 00021080 */  sll       $v0, $v0, 2
/* D0664C 80240F1C 00431023 */  subu      $v0, $v0, $v1
/* D06650 80240F20 000218C0 */  sll       $v1, $v0, 3
/* D06654 80240F24 00431021 */  addu      $v0, $v0, $v1
/* D06658 80240F28 8C830020 */  lw        $v1, 0x20($a0)
/* D0665C 80240F2C 000210C0 */  sll       $v0, $v0, 3
/* D06660 80240F30 8C630000 */  lw        $v1, ($v1)
/* D06664 80240F34 30630001 */  andi      $v1, $v1, 1
/* D06668 80240F38 10600004 */  beqz      $v1, .L80240F4C
/* D0666C 80240F3C 00451021 */   addu     $v0, $v0, $a1
/* D06670 80240F40 C44C006C */  lwc1      $f12, 0x6c($v0)
/* D06674 80240F44 0C00A6C9 */  jal       clamp_angle
/* D06678 80240F48 46006307 */   neg.s    $f12, $f12
.L80240F4C:
/* D0667C 80240F4C 8FBF0010 */  lw        $ra, 0x10($sp)
/* D06680 80240F50 03E00008 */  jr        $ra
/* D06684 80240F54 27BD0018 */   addiu    $sp, $sp, 0x18
