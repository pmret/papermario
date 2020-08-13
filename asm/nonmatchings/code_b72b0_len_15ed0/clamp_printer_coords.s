.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel clamp_printer_coords
/* 0BC1B8 80125AB8 A485050A */  sh    $a1, 0x50a($a0)
/* 0BC1BC 80125ABC 8482050A */  lh    $v0, 0x50a($a0)
/* 0BC1C0 80125AC0 04410002 */  bgez  $v0, .L80125ACC
/* 0BC1C4 80125AC4 A486050C */   sh    $a2, 0x50c($a0)
/* 0BC1C8 80125AC8 A480050A */  sh    $zero, 0x50a($a0)
.L80125ACC:
/* 0BC1CC 80125ACC 8482050A */  lh    $v0, 0x50a($a0)
/* 0BC1D0 80125AD0 28420141 */  slti  $v0, $v0, 0x141
/* 0BC1D4 80125AD4 14400002 */  bnez  $v0, .L80125AE0
/* 0BC1D8 80125AD8 24020140 */   addiu $v0, $zero, 0x140
/* 0BC1DC 80125ADC A482050A */  sh    $v0, 0x50a($a0)
.L80125AE0:
/* 0BC1E0 80125AE0 8482050C */  lh    $v0, 0x50c($a0)
/* 0BC1E4 80125AE4 04420001 */  bltzl $v0, .L80125AEC
/* 0BC1E8 80125AE8 A480050C */   sh    $zero, 0x50c($a0)
.L80125AEC:
/* 0BC1EC 80125AEC 8482050C */  lh    $v0, 0x50c($a0)
/* 0BC1F0 80125AF0 284200DD */  slti  $v0, $v0, 0xdd
/* 0BC1F4 80125AF4 14400002 */  bnez  $v0, .L80125B00
/* 0BC1F8 80125AF8 240200DC */   addiu $v0, $zero, 0xdc
/* 0BC1FC 80125AFC A482050C */  sh    $v0, 0x50c($a0)
.L80125B00:
/* 0BC200 80125B00 03E00008 */  jr    $ra
/* 0BC204 80125B04 00000000 */   nop   

