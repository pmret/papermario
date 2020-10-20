.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421D0
/* 7ECEE0 802421D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7ECEE4 802421D4 2404008A */  addiu     $a0, $zero, 0x8a
/* 7ECEE8 802421D8 2405FFFF */  addiu     $a1, $zero, -1
/* 7ECEEC 802421DC 24060001 */  addiu     $a2, $zero, 1
/* 7ECEF0 802421E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7ECEF4 802421E4 0C046E54 */  jal       func_8011B950
/* 7ECEF8 802421E8 00C0382D */   daddu    $a3, $a2, $zero
/* 7ECEFC 802421EC 0000202D */  daddu     $a0, $zero, $zero
/* 7ECF00 802421F0 0080282D */  daddu     $a1, $a0, $zero
/* 7ECF04 802421F4 0080302D */  daddu     $a2, $a0, $zero
/* 7ECF08 802421F8 0C046F97 */  jal       set_background_color_blend
/* 7ECF0C 802421FC 240700FF */   addiu    $a3, $zero, 0xff
/* 7ECF10 80242200 3C02800B */  lui       $v0, %hi(gCameras)
/* 7ECF14 80242204 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 7ECF18 80242208 A440002C */  sh        $zero, 0x2c($v0)
/* 7ECF1C 8024220C A440002E */  sh        $zero, 0x2e($v0)
/* 7ECF20 80242210 A4400030 */  sh        $zero, 0x30($v0)
/* 7ECF24 80242214 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7ECF28 80242218 24020002 */  addiu     $v0, $zero, 2
/* 7ECF2C 8024221C 03E00008 */  jr        $ra
/* 7ECF30 80242220 27BD0018 */   addiu    $sp, $sp, 0x18
