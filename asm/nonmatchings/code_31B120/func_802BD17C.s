.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD17C
/* 31B19C 802BD17C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31B1A0 802BD180 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31B1A4 802BD184 848200A6 */  lh        $v0, 0xa6($a0)
/* 31B1A8 802BD188 C48C0038 */  lwc1      $f12, 0x38($a0)
/* 31B1AC 802BD18C C48E003C */  lwc1      $f14, 0x3c($a0)
/* 31B1B0 802BD190 8C860040 */  lw        $a2, 0x40($a0)
/* 31B1B4 802BD194 44820000 */  mtc1      $v0, $f0
/* 31B1B8 802BD198 00000000 */  nop       
/* 31B1BC 802BD19C 46800020 */  cvt.s.w   $f0, $f0
/* 31B1C0 802BD1A0 44070000 */  mfc1      $a3, $f0
/* 31B1C4 802BD1A4 0C04CFF2 */  jal       func_80133FC8
/* 31B1C8 802BD1A8 00000000 */   nop      
/* 31B1CC 802BD1AC 0040282D */  daddu     $a1, $v0, $zero
/* 31B1D0 802BD1B0 3C01802C */  lui       $at, %hi(D_802BEC68)
/* 31B1D4 802BD1B4 AC25EC68 */  sw        $a1, %lo(D_802BEC68)($at)
/* 31B1D8 802BD1B8 04A0000D */  bltz      $a1, .L802BD1F0
/* 31B1DC 802BD1BC 24040001 */   addiu    $a0, $zero, 1
/* 31B1E0 802BD1C0 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 31B1E4 802BD1C4 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 31B1E8 802BD1C8 8C430000 */  lw        $v1, ($v0)
/* 31B1EC 802BD1CC 3C01802C */  lui       $at, %hi(D_802BEC6C)
/* 31B1F0 802BD1D0 AC24EC6C */  sw        $a0, %lo(D_802BEC6C)($at)
/* 31B1F4 802BD1D4 00A0202D */  daddu     $a0, $a1, $zero
/* 31B1F8 802BD1D8 3C050020 */  lui       $a1, 0x20
/* 31B1FC 802BD1DC 34630040 */  ori       $v1, $v1, 0x40
/* 31B200 802BD1E0 0C04D052 */  jal       set_item_entity_flags
/* 31B204 802BD1E4 AC430000 */   sw       $v1, ($v0)
/* 31B208 802BD1E8 080AF47D */  j         .L802BD1F4
/* 31B20C 802BD1EC 24020001 */   addiu    $v0, $zero, 1
.L802BD1F0:
/* 31B210 802BD1F0 0000102D */  daddu     $v0, $zero, $zero
.L802BD1F4:
/* 31B214 802BD1F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31B218 802BD1F8 03E00008 */  jr        $ra
/* 31B21C 802BD1FC 27BD0018 */   addiu    $sp, $sp, 0x18
