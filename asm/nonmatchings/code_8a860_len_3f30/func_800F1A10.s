.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800F1A10
/* 08AEC0 800F1A10 3C028011 */  lui   $v0, 0x8011
/* 08AEC4 800F1A14 8C42D640 */  lw    $v0, -0x29c0($v0)
/* 08AEC8 800F1A18 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 08AECC 800F1A1C AFBF0038 */  sw    $ra, 0x38($sp)
/* 08AED0 800F1A20 AFB30034 */  sw    $s3, 0x34($sp)
/* 08AED4 800F1A24 AFB20030 */  sw    $s2, 0x30($sp)
/* 08AED8 800F1A28 AFB1002C */  sw    $s1, 0x2c($sp)
/* 08AEDC 800F1A2C 24430007 */  addiu $v1, $v0, 7
/* 08AEE0 800F1A30 2C62006F */  sltiu $v0, $v1, 0x6f
/* 08AEE4 800F1A34 10400707 */  beqz  $v0, .L800F3654
/* 08AEE8 800F1A38 AFB00028 */   sw    $s0, 0x28($sp)
/* 08AEEC 800F1A3C 00031080 */  sll   $v0, $v1, 2
/* 08AEF0 800F1A40 3C018011 */  lui   $at, 0x8011
/* 08AEF4 800F1A44 00220821 */  addu  $at, $at, $v0
/* 08AEF8 800F1A48 8C22C410 */  lw    $v0, -0x3bf0($at)
/* 08AEFC 800F1A4C 00400008 */  jr    $v0
/* 08AF00 800F1A50 00000000 */   nop   
/* 08AF04 800F1A54 3C048011 */  lui   $a0, 0x8011
/* 08AF08 800F1A58 2484D67C */  addiu $a0, $a0, -0x2984
/* 08AF0C 800F1A5C 24030014 */  addiu $v1, $zero, 0x14
/* 08AF10 800F1A60 3C058011 */  lui   $a1, 0x8011
/* 08AF14 800F1A64 24A5D67E */  addiu $a1, $a1, -0x2982
/* 08AF18 800F1A68 24020048 */  addiu $v0, $zero, 0x48
/* 08AF1C 800F1A6C A4830000 */  sh    $v1, ($a0)
/* 08AF20 800F1A70 A4A20000 */  sh    $v0, ($a1)
/* 08AF24 800F1A74 3C018011 */  lui   $at, 0x8011
/* 08AF28 800F1A78 A423D680 */  sh    $v1, -0x2980($at)
/* 08AF2C 800F1A7C 3C038011 */  lui   $v1, 0x8011
/* 08AF30 800F1A80 8063D68E */  lb    $v1, -0x2972($v1)
/* 08AF34 800F1A84 240200BA */  addiu $v0, $zero, 0xba
/* 08AF38 800F1A88 3C018011 */  lui   $at, 0x8011
/* 08AF3C 800F1A8C A422D682 */  sh    $v0, -0x297e($at)
/* 08AF40 800F1A90 24020010 */  addiu $v0, $zero, 0x10
/* 08AF44 800F1A94 3C018011 */  lui   $at, 0x8011
/* 08AF48 800F1A98 A422D684 */  sh    $v0, -0x297c($at)
/* 08AF4C 800F1A9C 24020058 */  addiu $v0, $zero, 0x58
/* 08AF50 800F1AA0 3C018011 */  lui   $at, 0x8011
/* 08AF54 800F1AA4 A422D686 */  sh    $v0, -0x297a($at)
/* 08AF58 800F1AA8 24020020 */  addiu $v0, $zero, 0x20
/* 08AF5C 800F1AAC 3C018011 */  lui   $at, 0x8011
/* 08AF60 800F1AB0 A422D688 */  sh    $v0, -0x2978($at)
/* 08AF64 800F1AB4 240200A4 */  addiu $v0, $zero, 0xa4
/* 08AF68 800F1AB8 3C018011 */  lui   $at, 0x8011
/* 08AF6C 800F1ABC A422D68A */  sh    $v0, -0x2976($at)
/* 08AF70 800F1AC0 1060000A */  beqz  $v1, .L800F1AEC
/* 08AF74 800F1AC4 00000000 */   nop   
/* 08AF78 800F1AC8 3C028011 */  lui   $v0, 0x8011
/* 08AF7C 800F1ACC 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08AF80 800F1AD0 8C420318 */  lw    $v0, 0x318($v0)
/* 08AF84 800F1AD4 00021040 */  sll   $v0, $v0, 1
/* 08AF88 800F1AD8 3C018011 */  lui   $at, 0x8011
/* 08AF8C 800F1ADC 00220821 */  addu  $at, $at, $v0
/* 08AF90 800F1AE0 942298A0 */  lhu   $v0, -0x6760($at)
/* 08AF94 800F1AE4 24420014 */  addiu $v0, $v0, 0x14
/* 08AF98 800F1AE8 A4820000 */  sh    $v0, ($a0)
.L800F1AEC:
/* 08AF9C 800F1AEC 3C028011 */  lui   $v0, 0x8011
/* 08AFA0 800F1AF0 8042D68F */  lb    $v0, -0x2971($v0)
/* 08AFA4 800F1AF4 28420007 */  slti  $v0, $v0, 7
/* 08AFA8 800F1AF8 14400002 */  bnez  $v0, .L800F1B04
/* 08AFAC 800F1AFC 2402003E */   addiu $v0, $zero, 0x3e
/* 08AFB0 800F1B00 A4A20000 */  sh    $v0, ($a1)
.L800F1B04:
/* 08AFB4 800F1B04 3C048010 */  lui   $a0, 0x8010
/* 08AFB8 800F1B08 2484790C */  addiu $a0, $a0, 0x790c
/* 08AFBC 800F1B0C 3C018011 */  lui   $at, 0x8011
/* 08AFC0 800F1B10 A420D68C */  sh    $zero, -0x2974($at)
/* 08AFC4 800F1B14 0C050529 */  jal   create_icon
/* 08AFC8 800F1B18 00000000 */   nop   
/* 08AFCC 800F1B1C 0040802D */  daddu $s0, $v0, $zero
/* 08AFD0 800F1B20 0200202D */  daddu $a0, $s0, $zero
/* 08AFD4 800F1B24 3C018011 */  lui   $at, 0x8011
/* 08AFD8 800F1B28 AC30D65C */  sw    $s0, -0x29a4($at)
/* 08AFDC 800F1B2C 0C051280 */  jal   set_icon_flags
/* 08AFE0 800F1B30 24050080 */   addiu $a1, $zero, 0x80
/* 08AFE4 800F1B34 0200202D */  daddu $a0, $s0, $zero
/* 08AFE8 800F1B38 240500FF */  addiu $a1, $zero, 0xff
/* 08AFEC 800F1B3C 00A0302D */  daddu $a2, $a1, $zero
/* 08AFF0 800F1B40 0C0513BF */  jal   func_80144EFC
/* 08AFF4 800F1B44 00A0382D */   daddu $a3, $a1, $zero
/* 08AFF8 800F1B48 3C118011 */  lui   $s1, 0x8011
/* 08AFFC 800F1B4C 2631D69C */  addiu $s1, $s1, -0x2964
/* 08B000 800F1B50 8E220000 */  lw    $v0, ($s1)
/* 08B004 800F1B54 8C430318 */  lw    $v1, 0x318($v0)
/* 08B008 800F1B58 24020002 */  addiu $v0, $zero, 2
/* 08B00C 800F1B5C 10620004 */  beq   $v1, $v0, .L800F1B70
/* 08B010 800F1B60 00000000 */   nop   
/* 08B014 800F1B64 0200202D */  daddu $a0, $s0, $zero
/* 08B018 800F1B68 0C051280 */  jal   set_icon_flags
/* 08B01C 800F1B6C 0040282D */   daddu $a1, $v0, $zero
.L800F1B70:
/* 08B020 800F1B70 8E220000 */  lw    $v0, ($s1)
/* 08B024 800F1B74 8C440000 */  lw    $a0, ($v0)
/* 08B028 800F1B78 0C050529 */  jal   create_icon
/* 08B02C 800F1B7C 24130001 */   addiu $s3, $zero, 1
/* 08B030 800F1B80 0040802D */  daddu $s0, $v0, $zero
/* 08B034 800F1B84 3C053EE6 */  lui   $a1, 0x3ee6
/* 08B038 800F1B88 34A56666 */  ori   $a1, $a1, 0x6666
/* 08B03C 800F1B8C 3C018011 */  lui   $at, 0x8011
/* 08B040 800F1B90 AC30D678 */  sw    $s0, -0x2988($at)
/* 08B044 800F1B94 0C051308 */  jal   func_80144C20
/* 08B048 800F1B98 0200202D */   daddu $a0, $s0, $zero
/* 08B04C 800F1B9C 0200202D */  daddu $a0, $s0, $zero
/* 08B050 800F1BA0 0C051280 */  jal   set_icon_flags
/* 08B054 800F1BA4 34058080 */   ori   $a1, $zero, 0x8080
/* 08B058 800F1BA8 3C048010 */  lui   $a0, 0x8010
/* 08B05C 800F1BAC 24844A28 */  addiu $a0, $a0, 0x4a28
/* 08B060 800F1BB0 0C050529 */  jal   create_icon
/* 08B064 800F1BB4 00000000 */   nop   
/* 08B068 800F1BB8 0040802D */  daddu $s0, $v0, $zero
/* 08B06C 800F1BBC 0200202D */  daddu $a0, $s0, $zero
/* 08B070 800F1BC0 3C052000 */  lui   $a1, 0x2000
/* 08B074 800F1BC4 3C018011 */  lui   $at, 0x8011
/* 08B078 800F1BC8 AC24D66C */  sw    $a0, -0x2994($at)
/* 08B07C 800F1BCC 0C051280 */  jal   set_icon_flags
/* 08B080 800F1BD0 34A50080 */   ori   $a1, $a1, 0x80
/* 08B084 800F1BD4 3C048010 */  lui   $a0, 0x8010
/* 08B088 800F1BD8 248477E4 */  addiu $a0, $a0, 0x77e4
/* 08B08C 800F1BDC 0C050529 */  jal   create_icon
/* 08B090 800F1BE0 00000000 */   nop   
/* 08B094 800F1BE4 0040802D */  daddu $s0, $v0, $zero
/* 08B098 800F1BE8 0200202D */  daddu $a0, $s0, $zero
/* 08B09C 800F1BEC 3C052000 */  lui   $a1, 0x2000
/* 08B0A0 800F1BF0 3C018011 */  lui   $at, 0x8011
/* 08B0A4 800F1BF4 AC24D670 */  sw    $a0, -0x2990($at)
/* 08B0A8 800F1BF8 0C051280 */  jal   set_icon_flags
/* 08B0AC 800F1BFC 34A50080 */   ori   $a1, $a1, 0x80
/* 08B0B0 800F1C00 3C048010 */  lui   $a0, 0x8010
/* 08B0B4 800F1C04 24847798 */  addiu $a0, $a0, 0x7798
/* 08B0B8 800F1C08 0C050529 */  jal   create_icon
/* 08B0BC 800F1C0C 00000000 */   nop   
/* 08B0C0 800F1C10 0040802D */  daddu $s0, $v0, $zero
/* 08B0C4 800F1C14 0200202D */  daddu $a0, $s0, $zero
/* 08B0C8 800F1C18 3C052000 */  lui   $a1, 0x2000
/* 08B0CC 800F1C1C 3C018011 */  lui   $at, 0x8011
/* 08B0D0 800F1C20 AC24D674 */  sw    $a0, -0x298c($at)
/* 08B0D4 800F1C24 0C051280 */  jal   set_icon_flags
/* 08B0D8 800F1C28 34A50080 */   ori   $a1, $a1, 0x80
/* 08B0DC 800F1C2C 8E220000 */  lw    $v0, ($s1)
/* 08B0E0 800F1C30 8C430318 */  lw    $v1, 0x318($v0)
/* 08B0E4 800F1C34 24020003 */  addiu $v0, $zero, 3
/* 08B0E8 800F1C38 14620010 */  bne   $v1, $v0, .L800F1C7C
/* 08B0EC 800F1C3C 00000000 */   nop   
/* 08B0F0 800F1C40 3C048010 */  lui   $a0, 0x8010
/* 08B0F4 800F1C44 24844C10 */  addiu $a0, $a0, 0x4c10
/* 08B0F8 800F1C48 0C050529 */  jal   create_icon
/* 08B0FC 800F1C4C 00000000 */   nop   
/* 08B100 800F1C50 3C018011 */  lui   $at, 0x8011
/* 08B104 800F1C54 AC22D660 */  sw    $v0, -0x29a0($at)
/* 08B108 800F1C58 0040802D */  daddu $s0, $v0, $zero
/* 08B10C 800F1C5C 0040202D */  daddu $a0, $v0, $zero
/* 08B110 800F1C60 0C051280 */  jal   set_icon_flags
/* 08B114 800F1C64 24050080 */   addiu $a1, $zero, 0x80
/* 08B118 800F1C68 0200202D */  daddu $a0, $s0, $zero
/* 08B11C 800F1C6C 240500FF */  addiu $a1, $zero, 0xff
/* 08B120 800F1C70 00A0302D */  daddu $a2, $a1, $zero
/* 08B124 800F1C74 0C0513BF */  jal   func_80144EFC
/* 08B128 800F1C78 00A0382D */   daddu $a3, $a1, $zero
.L800F1C7C:
/* 08B12C 800F1C7C 8E220000 */  lw    $v0, ($s1)
/* 08B130 800F1C80 8C420318 */  lw    $v0, 0x318($v0)
/* 08B134 800F1C84 24120004 */  addiu $s2, $zero, 4
/* 08B138 800F1C88 14520010 */  bne   $v0, $s2, .L800F1CCC
/* 08B13C 800F1C8C 00000000 */   nop   
/* 08B140 800F1C90 3C048010 */  lui   $a0, 0x8010
/* 08B144 800F1C94 24844C10 */  addiu $a0, $a0, 0x4c10
/* 08B148 800F1C98 0C050529 */  jal   create_icon
/* 08B14C 800F1C9C 00000000 */   nop   
/* 08B150 800F1CA0 3C018011 */  lui   $at, 0x8011
/* 08B154 800F1CA4 AC22D660 */  sw    $v0, -0x29a0($at)
/* 08B158 800F1CA8 0040802D */  daddu $s0, $v0, $zero
/* 08B15C 800F1CAC 0040202D */  daddu $a0, $v0, $zero
/* 08B160 800F1CB0 0C051280 */  jal   set_icon_flags
/* 08B164 800F1CB4 34058080 */   ori   $a1, $zero, 0x8080
/* 08B168 800F1CB8 0200202D */  daddu $a0, $s0, $zero
/* 08B16C 800F1CBC 240500FF */  addiu $a1, $zero, 0xff
/* 08B170 800F1CC0 00A0302D */  daddu $a2, $a1, $zero
/* 08B174 800F1CC4 0C0513BF */  jal   func_80144EFC
/* 08B178 800F1CC8 00A0382D */   daddu $a3, $a1, $zero
.L800F1CCC:
/* 08B17C 800F1CCC 8E220000 */  lw    $v0, ($s1)
/* 08B180 800F1CD0 8C430318 */  lw    $v1, 0x318($v0)
/* 08B184 800F1CD4 24020005 */  addiu $v0, $zero, 5
/* 08B188 800F1CD8 14620010 */  bne   $v1, $v0, .L800F1D1C
/* 08B18C 800F1CDC 00000000 */   nop   
/* 08B190 800F1CE0 3C048011 */  lui   $a0, 0x8011
/* 08B194 800F1CE4 24848558 */  addiu $a0, $a0, -0x7aa8
/* 08B198 800F1CE8 0C050529 */  jal   create_icon
/* 08B19C 800F1CEC 00000000 */   nop   
/* 08B1A0 800F1CF0 3C018011 */  lui   $at, 0x8011
/* 08B1A4 800F1CF4 AC22D660 */  sw    $v0, -0x29a0($at)
/* 08B1A8 800F1CF8 0040802D */  daddu $s0, $v0, $zero
/* 08B1AC 800F1CFC 0040202D */  daddu $a0, $v0, $zero
/* 08B1B0 800F1D00 0C051280 */  jal   set_icon_flags
/* 08B1B4 800F1D04 24050080 */   addiu $a1, $zero, 0x80
/* 08B1B8 800F1D08 0200202D */  daddu $a0, $s0, $zero
/* 08B1BC 800F1D0C 240500FF */  addiu $a1, $zero, 0xff
/* 08B1C0 800F1D10 00A0302D */  daddu $a2, $a1, $zero
/* 08B1C4 800F1D14 0C0513BF */  jal   func_80144EFC
/* 08B1C8 800F1D18 00A0382D */   daddu $a3, $a1, $zero
.L800F1D1C:
/* 08B1CC 800F1D1C 8E220000 */  lw    $v0, ($s1)
/* 08B1D0 800F1D20 8C420318 */  lw    $v0, 0x318($v0)
/* 08B1D4 800F1D24 2442FFFD */  addiu $v0, $v0, -3
/* 08B1D8 800F1D28 2C420002 */  sltiu $v0, $v0, 2
/* 08B1DC 800F1D2C 10400010 */  beqz  $v0, .L800F1D70
/* 08B1E0 800F1D30 00000000 */   nop   
/* 08B1E4 800F1D34 3C048011 */  lui   $a0, 0x8011
/* 08B1E8 800F1D38 24849270 */  addiu $a0, $a0, -0x6d90
/* 08B1EC 800F1D3C 0C050529 */  jal   create_icon
/* 08B1F0 800F1D40 00000000 */   nop   
/* 08B1F4 800F1D44 3C018011 */  lui   $at, 0x8011
/* 08B1F8 800F1D48 AC22D664 */  sw    $v0, -0x299c($at)
/* 08B1FC 800F1D4C 0040802D */  daddu $s0, $v0, $zero
/* 08B200 800F1D50 0040202D */  daddu $a0, $v0, $zero
/* 08B204 800F1D54 0C051280 */  jal   set_icon_flags
/* 08B208 800F1D58 24050080 */   addiu $a1, $zero, 0x80
/* 08B20C 800F1D5C 0200202D */  daddu $a0, $s0, $zero
/* 08B210 800F1D60 240500FF */  addiu $a1, $zero, 0xff
/* 08B214 800F1D64 00A0302D */  daddu $a2, $a1, $zero
/* 08B218 800F1D68 0C0513BF */  jal   func_80144EFC
/* 08B21C 800F1D6C 00A0382D */   daddu $a3, $a1, $zero
.L800F1D70:
/* 08B220 800F1D70 8E220000 */  lw    $v0, ($s1)
/* 08B224 800F1D74 8C420318 */  lw    $v0, 0x318($v0)
/* 08B228 800F1D78 10530003 */  beq   $v0, $s3, .L800F1D88
/* 08B22C 800F1D7C 00000000 */   nop   
/* 08B230 800F1D80 14520010 */  bne   $v0, $s2, .L800F1DC4
/* 08B234 800F1D84 2402FF38 */   addiu $v0, $zero, -0xc8
.L800F1D88:
/* 08B238 800F1D88 3C048011 */  lui   $a0, 0x8011
/* 08B23C 800F1D8C 0C050529 */  jal   create_icon
/* 08B240 800F1D90 8C849890 */   lw    $a0, -0x6770($a0)
/* 08B244 800F1D94 0040802D */  daddu $s0, $v0, $zero
/* 08B248 800F1D98 0200202D */  daddu $a0, $s0, $zero
/* 08B24C 800F1D9C 3C018011 */  lui   $at, 0x8011
/* 08B250 800F1DA0 AC30D668 */  sw    $s0, -0x2998($at)
/* 08B254 800F1DA4 0C051280 */  jal   set_icon_flags
/* 08B258 800F1DA8 24050080 */   addiu $a1, $zero, 0x80
/* 08B25C 800F1DAC 0200202D */  daddu $a0, $s0, $zero
/* 08B260 800F1DB0 240500FF */  addiu $a1, $zero, 0xff
/* 08B264 800F1DB4 00A0302D */  daddu $a2, $a1, $zero
/* 08B268 800F1DB8 0C0513BF */  jal   func_80144EFC
/* 08B26C 800F1DBC 00A0382D */   daddu $a3, $a1, $zero
/* 08B270 800F1DC0 2402FF38 */  addiu $v0, $zero, -0xc8
.L800F1DC4:
/* 08B274 800F1DC4 3C018011 */  lui   $at, 0x8011
/* 08B278 800F1DC8 A422D65A */  sh    $v0, -0x29a6($at)
/* 08B27C 800F1DCC 3C028011 */  lui   $v0, 0x8011
/* 08B280 800F1DD0 8042D691 */  lb    $v0, -0x296f($v0)
/* 08B284 800F1DD4 3C038011 */  lui   $v1, 0x8011
/* 08B288 800F1DD8 8063D68E */  lb    $v1, -0x2972($v1)
/* 08B28C 800F1DDC 3C048011 */  lui   $a0, 0x8011
/* 08B290 800F1DE0 2484D644 */  addiu $a0, $a0, -0x29bc
/* 08B294 800F1DE4 14600003 */  bnez  $v1, .L800F1DF4
/* 08B298 800F1DE8 AC820000 */   sw    $v0, ($a0)
/* 08B29C 800F1DEC 24020001 */  addiu $v0, $zero, 1
/* 08B2A0 800F1DF0 AC820000 */  sw    $v0, ($a0)
.L800F1DF4:
/* 08B2A4 800F1DF4 3C058011 */  lui   $a1, 0x8011
/* 08B2A8 800F1DF8 84A5D67C */  lh    $a1, -0x2984($a1)
/* 08B2AC 800F1DFC 3C028011 */  lui   $v0, 0x8011
/* 08B2B0 800F1E00 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08B2B4 800F1E04 3C068011 */  lui   $a2, 0x8011
/* 08B2B8 800F1E08 84C6D67E */  lh    $a2, -0x2982($a2)
/* 08B2BC 800F1E0C 8C430318 */  lw    $v1, 0x318($v0)
/* 08B2C0 800F1E10 2402000A */  addiu $v0, $zero, 0xa
/* 08B2C4 800F1E14 3C018011 */  lui   $at, 0x8011
/* 08B2C8 800F1E18 A022D690 */  sb    $v0, -0x2970($at)
/* 08B2CC 800F1E1C 2C62000E */  sltiu $v0, $v1, 0xe
/* 08B2D0 800F1E20 1040017B */  beqz  $v0, .L800F2410
/* 08B2D4 800F1E24 00031080 */   sll   $v0, $v1, 2
/* 08B2D8 800F1E28 3C018011 */  lui   $at, 0x8011
/* 08B2DC 800F1E2C 00220821 */  addu  $at, $at, $v0
/* 08B2E0 800F1E30 8C22C5D0 */  lw    $v0, -0x3a30($at)
/* 08B2E4 800F1E34 00400008 */  jr    $v0
/* 08B2E8 800F1E38 00000000 */   nop   
/* 08B2EC 800F1E3C 2404000E */  addiu $a0, $zero, 0xe
/* 08B2F0 800F1E40 24070091 */  addiu $a3, $zero, 0x91
/* 08B2F4 800F1E44 3C038011 */  lui   $v1, 0x8011
/* 08B2F8 800F1E48 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B2FC 800F1E4C 24020014 */  addiu $v0, $zero, 0x14
/* 08B300 800F1E50 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B304 800F1E54 3C02800F */  lui   $v0, 0x800f
/* 08B308 800F1E58 24423680 */  addiu $v0, $v0, 0x3680
/* 08B30C 800F1E5C AFA20018 */  sw    $v0, 0x18($sp)
/* 08B310 800F1E60 2402FFFF */  addiu $v0, $zero, -1
/* 08B314 800F1E64 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B318 800F1E68 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B31C 800F1E6C 00031040 */  sll   $v0, $v1, 1
/* 08B320 800F1E70 00431021 */  addu  $v0, $v0, $v1
/* 08B324 800F1E74 00021080 */  sll   $v0, $v0, 2
/* 08B328 800F1E78 00431021 */  addu  $v0, $v0, $v1
/* 08B32C 800F1E7C 2442001A */  addiu $v0, $v0, 0x1a
/* 08B330 800F1E80 0C051F32 */  jal   func_80147CC8
/* 08B334 800F1E84 AFA20010 */   sw    $v0, 0x10($sp)
/* 08B338 800F1E88 3C028011 */  lui   $v0, 0x8011
/* 08B33C 800F1E8C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08B340 800F1E90 8C42031C */  lw    $v0, 0x31c($v0)
/* 08B344 800F1E94 14400005 */  bnez  $v0, .L800F1EAC
/* 08B348 800F1E98 2404000F */   addiu $a0, $zero, 0xf
/* 08B34C 800F1E9C 24050019 */  addiu $a1, $zero, 0x19
/* 08B350 800F1EA0 2406FFFA */  addiu $a2, $zero, -6
/* 08B354 800F1EA4 0803C7AE */  j     .L800F1EB8
/* 08B358 800F1EA8 2407005F */   addiu $a3, $zero, 0x5f

.L800F1EAC:
/* 08B35C 800F1EAC 2405000C */  addiu $a1, $zero, 0xc
/* 08B360 800F1EB0 2406FFFA */  addiu $a2, $zero, -6
/* 08B364 800F1EB4 24070079 */  addiu $a3, $zero, 0x79
.L800F1EB8:
/* 08B368 800F1EB8 24020010 */  addiu $v0, $zero, 0x10
/* 08B36C 800F1EBC AFA20010 */  sw    $v0, 0x10($sp)
/* 08B370 800F1EC0 24020015 */  addiu $v0, $zero, 0x15
/* 08B374 800F1EC4 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B378 800F1EC8 3C02800F */  lui   $v0, 0x800f
/* 08B37C 800F1ECC 24424648 */  addiu $v0, $v0, 0x4648
/* 08B380 800F1ED0 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B384 800F1ED4 2402000E */  addiu $v0, $zero, 0xe
/* 08B388 800F1ED8 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B38C 800F1EDC 0C051F32 */  jal   func_80147CC8
/* 08B390 800F1EE0 AFA20020 */   sw    $v0, 0x20($sp)
/* 08B394 800F1EE4 2404000F */  addiu $a0, $zero, 0xf
/* 08B398 800F1EE8 0C051F9F */  jal   func_80147E7C
/* 08B39C 800F1EEC 24050001 */   addiu $a1, $zero, 1
/* 08B3A0 800F1EF0 24040011 */  addiu $a0, $zero, 0x11
/* 08B3A4 800F1EF4 0803C902 */  j     .L800F2408
/* 08B3A8 800F1EF8 24050002 */   addiu $a1, $zero, 2

/* 08B3AC 800F1EFC 2404000E */  addiu $a0, $zero, 0xe
/* 08B3B0 800F1F00 2407008B */  addiu $a3, $zero, 0x8b
/* 08B3B4 800F1F04 3C038011 */  lui   $v1, 0x8011
/* 08B3B8 800F1F08 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B3BC 800F1F0C 24020014 */  addiu $v0, $zero, 0x14
/* 08B3C0 800F1F10 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B3C4 800F1F14 3C02800F */  lui   $v0, 0x800f
/* 08B3C8 800F1F18 24423680 */  addiu $v0, $v0, 0x3680
/* 08B3CC 800F1F1C AFA20018 */  sw    $v0, 0x18($sp)
/* 08B3D0 800F1F20 2402FFFF */  addiu $v0, $zero, -1
/* 08B3D4 800F1F24 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B3D8 800F1F28 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B3DC 800F1F2C 00031040 */  sll   $v0, $v1, 1
/* 08B3E0 800F1F30 00431021 */  addu  $v0, $v0, $v1
/* 08B3E4 800F1F34 00021080 */  sll   $v0, $v0, 2
/* 08B3E8 800F1F38 00431021 */  addu  $v0, $v0, $v1
/* 08B3EC 800F1F3C 2442001A */  addiu $v0, $v0, 0x1a
/* 08B3F0 800F1F40 0C051F32 */  jal   func_80147CC8
/* 08B3F4 800F1F44 AFA20010 */   sw    $v0, 0x10($sp)
/* 08B3F8 800F1F48 24040011 */  addiu $a0, $zero, 0x11
/* 08B3FC 800F1F4C 0803C8F0 */  j     .L800F23C0
/* 08B400 800F1F50 2405000D */   addiu $a1, $zero, 0xd

/* 08B404 800F1F54 2404000E */  addiu $a0, $zero, 0xe
/* 08B408 800F1F58 240700A2 */  addiu $a3, $zero, 0xa2
/* 08B40C 800F1F5C 3C038011 */  lui   $v1, 0x8011
/* 08B410 800F1F60 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B414 800F1F64 24020014 */  addiu $v0, $zero, 0x14
/* 08B418 800F1F68 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B41C 800F1F6C 3C02800F */  lui   $v0, 0x800f
/* 08B420 800F1F70 24423680 */  addiu $v0, $v0, 0x3680
/* 08B424 800F1F74 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B428 800F1F78 2402FFFF */  addiu $v0, $zero, -1
/* 08B42C 800F1F7C AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B430 800F1F80 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B434 800F1F84 00031040 */  sll   $v0, $v1, 1
/* 08B438 800F1F88 00431021 */  addu  $v0, $v0, $v1
/* 08B43C 800F1F8C 00021080 */  sll   $v0, $v0, 2
/* 08B440 800F1F90 00431021 */  addu  $v0, $v0, $v1
/* 08B444 800F1F94 2442001A */  addiu $v0, $v0, 0x1a
/* 08B448 800F1F98 0C051F32 */  jal   func_80147CC8
/* 08B44C 800F1F9C AFA20010 */   sw    $v0, 0x10($sp)
/* 08B450 800F1FA0 2404000F */  addiu $a0, $zero, 0xf
/* 08B454 800F1FA4 24050011 */  addiu $a1, $zero, 0x11
/* 08B458 800F1FA8 2406FFFA */  addiu $a2, $zero, -6
/* 08B45C 800F1FAC 24070060 */  addiu $a3, $zero, 0x60
/* 08B460 800F1FB0 24020010 */  addiu $v0, $zero, 0x10
/* 08B464 800F1FB4 AFA20010 */  sw    $v0, 0x10($sp)
/* 08B468 800F1FB8 24020015 */  addiu $v0, $zero, 0x15
/* 08B46C 800F1FBC AFA20014 */  sw    $v0, 0x14($sp)
/* 08B470 800F1FC0 3C02800F */  lui   $v0, 0x800f
/* 08B474 800F1FC4 24424648 */  addiu $v0, $v0, 0x4648
/* 08B478 800F1FC8 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B47C 800F1FCC 2402000E */  addiu $v0, $zero, 0xe
/* 08B480 800F1FD0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B484 800F1FD4 0C051F32 */  jal   func_80147CC8
/* 08B488 800F1FD8 AFA20020 */   sw    $v0, 0x20($sp)
/* 08B48C 800F1FDC 2404000F */  addiu $a0, $zero, 0xf
/* 08B490 800F1FE0 0C051F9F */  jal   func_80147E7C
/* 08B494 800F1FE4 24050001 */   addiu $a1, $zero, 1
/* 08B498 800F1FE8 24040011 */  addiu $a0, $zero, 0x11
/* 08B49C 800F1FEC 0803C902 */  j     .L800F2408
/* 08B4A0 800F1FF0 24050002 */   addiu $a1, $zero, 2

/* 08B4A4 800F1FF4 2404000E */  addiu $a0, $zero, 0xe
/* 08B4A8 800F1FF8 24070092 */  addiu $a3, $zero, 0x92
/* 08B4AC 800F1FFC 3C038011 */  lui   $v1, 0x8011
/* 08B4B0 800F2000 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B4B4 800F2004 24020014 */  addiu $v0, $zero, 0x14
/* 08B4B8 800F2008 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B4BC 800F200C 3C02800F */  lui   $v0, 0x800f
/* 08B4C0 800F2010 24423680 */  addiu $v0, $v0, 0x3680
/* 08B4C4 800F2014 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B4C8 800F2018 2402FFFF */  addiu $v0, $zero, -1
/* 08B4CC 800F201C AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B4D0 800F2020 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B4D4 800F2024 00031040 */  sll   $v0, $v1, 1
/* 08B4D8 800F2028 00431021 */  addu  $v0, $v0, $v1
/* 08B4DC 800F202C 00021080 */  sll   $v0, $v0, 2
/* 08B4E0 800F2030 00431021 */  addu  $v0, $v0, $v1
/* 08B4E4 800F2034 2442001A */  addiu $v0, $v0, 0x1a
/* 08B4E8 800F2038 0C051F32 */  jal   func_80147CC8
/* 08B4EC 800F203C AFA20010 */   sw    $v0, 0x10($sp)
/* 08B4F0 800F2040 24040011 */  addiu $a0, $zero, 0x11
/* 08B4F4 800F2044 0803C8F0 */  j     .L800F23C0
/* 08B4F8 800F2048 2405000C */   addiu $a1, $zero, 0xc

/* 08B4FC 800F204C 2404000E */  addiu $a0, $zero, 0xe
/* 08B500 800F2050 240700A7 */  addiu $a3, $zero, 0xa7
/* 08B504 800F2054 3C038011 */  lui   $v1, 0x8011
/* 08B508 800F2058 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B50C 800F205C 24020014 */  addiu $v0, $zero, 0x14
/* 08B510 800F2060 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B514 800F2064 3C02800F */  lui   $v0, 0x800f
/* 08B518 800F2068 24423680 */  addiu $v0, $v0, 0x3680
/* 08B51C 800F206C AFA20018 */  sw    $v0, 0x18($sp)
/* 08B520 800F2070 2402FFFF */  addiu $v0, $zero, -1
/* 08B524 800F2074 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B528 800F2078 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B52C 800F207C 00031040 */  sll   $v0, $v1, 1
/* 08B530 800F2080 00431021 */  addu  $v0, $v0, $v1
/* 08B534 800F2084 00021080 */  sll   $v0, $v0, 2
/* 08B538 800F2088 00431021 */  addu  $v0, $v0, $v1
/* 08B53C 800F208C 2442001A */  addiu $v0, $v0, 0x1a
/* 08B540 800F2090 0C051F32 */  jal   func_80147CC8
/* 08B544 800F2094 AFA20010 */   sw    $v0, 0x10($sp)
/* 08B548 800F2098 2404000F */  addiu $a0, $zero, 0xf
/* 08B54C 800F209C 24050016 */  addiu $a1, $zero, 0x16
/* 08B550 800F20A0 2406FFFA */  addiu $a2, $zero, -6
/* 08B554 800F20A4 2407005F */  addiu $a3, $zero, 0x5f
/* 08B558 800F20A8 24020010 */  addiu $v0, $zero, 0x10
/* 08B55C 800F20AC AFA20010 */  sw    $v0, 0x10($sp)
/* 08B560 800F20B0 24020015 */  addiu $v0, $zero, 0x15
/* 08B564 800F20B4 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B568 800F20B8 3C02800F */  lui   $v0, 0x800f
/* 08B56C 800F20BC 24424648 */  addiu $v0, $v0, 0x4648
/* 08B570 800F20C0 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B574 800F20C4 2402000E */  addiu $v0, $zero, 0xe
/* 08B578 800F20C8 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B57C 800F20CC 0C051F32 */  jal   func_80147CC8
/* 08B580 800F20D0 AFA20020 */   sw    $v0, 0x20($sp)
/* 08B584 800F20D4 2404000F */  addiu $a0, $zero, 0xf
/* 08B588 800F20D8 0C051F9F */  jal   func_80147E7C
/* 08B58C 800F20DC 24050001 */   addiu $a1, $zero, 1
/* 08B590 800F20E0 24040011 */  addiu $a0, $zero, 0x11
/* 08B594 800F20E4 0803C902 */  j     .L800F2408
/* 08B598 800F20E8 24050002 */   addiu $a1, $zero, 2

/* 08B59C 800F20EC 2404000E */  addiu $a0, $zero, 0xe
/* 08B5A0 800F20F0 240700AA */  addiu $a3, $zero, 0xaa
/* 08B5A4 800F20F4 3C038011 */  lui   $v1, 0x8011
/* 08B5A8 800F20F8 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B5AC 800F20FC 24020014 */  addiu $v0, $zero, 0x14
/* 08B5B0 800F2100 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B5B4 800F2104 3C02800F */  lui   $v0, 0x800f
/* 08B5B8 800F2108 24423680 */  addiu $v0, $v0, 0x3680
/* 08B5BC 800F210C AFA20018 */  sw    $v0, 0x18($sp)
/* 08B5C0 800F2110 2402FFFF */  addiu $v0, $zero, -1
/* 08B5C4 800F2114 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B5C8 800F2118 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B5CC 800F211C 00031040 */  sll   $v0, $v1, 1
/* 08B5D0 800F2120 00431021 */  addu  $v0, $v0, $v1
/* 08B5D4 800F2124 00021080 */  sll   $v0, $v0, 2
/* 08B5D8 800F2128 00431021 */  addu  $v0, $v0, $v1
/* 08B5DC 800F212C 2442001A */  addiu $v0, $v0, 0x1a
/* 08B5E0 800F2130 0C051F32 */  jal   func_80147CC8
/* 08B5E4 800F2134 AFA20010 */   sw    $v0, 0x10($sp)
/* 08B5E8 800F2138 2404000F */  addiu $a0, $zero, 0xf
/* 08B5EC 800F213C 24050020 */  addiu $a1, $zero, 0x20
/* 08B5F0 800F2140 2406FFFA */  addiu $a2, $zero, -6
/* 08B5F4 800F2144 24070068 */  addiu $a3, $zero, 0x68
/* 08B5F8 800F2148 24020010 */  addiu $v0, $zero, 0x10
/* 08B5FC 800F214C AFA20010 */  sw    $v0, 0x10($sp)
/* 08B600 800F2150 24020015 */  addiu $v0, $zero, 0x15
/* 08B604 800F2154 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B608 800F2158 3C02800F */  lui   $v0, 0x800f
/* 08B60C 800F215C 24424648 */  addiu $v0, $v0, 0x4648
/* 08B610 800F2160 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B614 800F2164 2402000E */  addiu $v0, $zero, 0xe
/* 08B618 800F2168 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B61C 800F216C 0C051F32 */  jal   func_80147CC8
/* 08B620 800F2170 AFA20020 */   sw    $v0, 0x20($sp)
/* 08B624 800F2174 2404000F */  addiu $a0, $zero, 0xf
/* 08B628 800F2178 0C051F9F */  jal   func_80147E7C
/* 08B62C 800F217C 24050001 */   addiu $a1, $zero, 1
/* 08B630 800F2180 24040011 */  addiu $a0, $zero, 0x11
/* 08B634 800F2184 0803C902 */  j     .L800F2408
/* 08B638 800F2188 24050002 */   addiu $a1, $zero, 2

/* 08B63C 800F218C 2404000E */  addiu $a0, $zero, 0xe
/* 08B640 800F2190 24070091 */  addiu $a3, $zero, 0x91
/* 08B644 800F2194 3C038011 */  lui   $v1, 0x8011
/* 08B648 800F2198 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B64C 800F219C 24020014 */  addiu $v0, $zero, 0x14
/* 08B650 800F21A0 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B654 800F21A4 3C02800F */  lui   $v0, 0x800f
/* 08B658 800F21A8 24423680 */  addiu $v0, $v0, 0x3680
/* 08B65C 800F21AC AFA20018 */  sw    $v0, 0x18($sp)
/* 08B660 800F21B0 2402FFFF */  addiu $v0, $zero, -1
/* 08B664 800F21B4 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B668 800F21B8 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B66C 800F21BC 00031040 */  sll   $v0, $v1, 1
/* 08B670 800F21C0 00431021 */  addu  $v0, $v0, $v1
/* 08B674 800F21C4 00021080 */  sll   $v0, $v0, 2
/* 08B678 800F21C8 00431021 */  addu  $v0, $v0, $v1
/* 08B67C 800F21CC 2442001A */  addiu $v0, $v0, 0x1a
/* 08B680 800F21D0 0C051F32 */  jal   func_80147CC8
/* 08B684 800F21D4 AFA20010 */   sw    $v0, 0x10($sp)
/* 08B688 800F21D8 2404000F */  addiu $a0, $zero, 0xf
/* 08B68C 800F21DC 2405000C */  addiu $a1, $zero, 0xc
/* 08B690 800F21E0 2406FFFA */  addiu $a2, $zero, -6
/* 08B694 800F21E4 24070079 */  addiu $a3, $zero, 0x79
/* 08B698 800F21E8 24020010 */  addiu $v0, $zero, 0x10
/* 08B69C 800F21EC AFA20010 */  sw    $v0, 0x10($sp)
/* 08B6A0 800F21F0 24020015 */  addiu $v0, $zero, 0x15
/* 08B6A4 800F21F4 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B6A8 800F21F8 3C02800F */  lui   $v0, 0x800f
/* 08B6AC 800F21FC 24424648 */  addiu $v0, $v0, 0x4648
/* 08B6B0 800F2200 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B6B4 800F2204 2402000E */  addiu $v0, $zero, 0xe
/* 08B6B8 800F2208 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B6BC 800F220C 0C051F32 */  jal   func_80147CC8
/* 08B6C0 800F2210 AFA20020 */   sw    $v0, 0x20($sp)
/* 08B6C4 800F2214 2404000F */  addiu $a0, $zero, 0xf
/* 08B6C8 800F2218 0C051F9F */  jal   func_80147E7C
/* 08B6CC 800F221C 24050001 */   addiu $a1, $zero, 1
/* 08B6D0 800F2220 24040011 */  addiu $a0, $zero, 0x11
/* 08B6D4 800F2224 0803C902 */  j     .L800F2408
/* 08B6D8 800F2228 24050002 */   addiu $a1, $zero, 2

/* 08B6DC 800F222C 2404000E */  addiu $a0, $zero, 0xe
/* 08B6E0 800F2230 24070080 */  addiu $a3, $zero, 0x80
/* 08B6E4 800F2234 3C038011 */  lui   $v1, 0x8011
/* 08B6E8 800F2238 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B6EC 800F223C 24020014 */  addiu $v0, $zero, 0x14
/* 08B6F0 800F2240 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B6F4 800F2244 3C02800F */  lui   $v0, 0x800f
/* 08B6F8 800F2248 24423680 */  addiu $v0, $v0, 0x3680
/* 08B6FC 800F224C AFA20018 */  sw    $v0, 0x18($sp)
/* 08B700 800F2250 2402FFFF */  addiu $v0, $zero, -1
/* 08B704 800F2254 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B708 800F2258 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B70C 800F225C 00031040 */  sll   $v0, $v1, 1
/* 08B710 800F2260 00431021 */  addu  $v0, $v0, $v1
/* 08B714 800F2264 00021080 */  sll   $v0, $v0, 2
/* 08B718 800F2268 00431021 */  addu  $v0, $v0, $v1
/* 08B71C 800F226C 2442001A */  addiu $v0, $v0, 0x1a
/* 08B720 800F2270 0C051F32 */  jal   func_80147CC8
/* 08B724 800F2274 AFA20010 */   sw    $v0, 0x10($sp)
/* 08B728 800F2278 2404000F */  addiu $a0, $zero, 0xf
/* 08B72C 800F227C 2405000C */  addiu $a1, $zero, 0xc
/* 08B730 800F2280 2406FFFA */  addiu $a2, $zero, -6
/* 08B734 800F2284 24070068 */  addiu $a3, $zero, 0x68
/* 08B738 800F2288 24020010 */  addiu $v0, $zero, 0x10
/* 08B73C 800F228C AFA20010 */  sw    $v0, 0x10($sp)
/* 08B740 800F2290 24020015 */  addiu $v0, $zero, 0x15
/* 08B744 800F2294 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B748 800F2298 3C02800F */  lui   $v0, 0x800f
/* 08B74C 800F229C 24424648 */  addiu $v0, $v0, 0x4648
/* 08B750 800F22A0 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B754 800F22A4 2402000E */  addiu $v0, $zero, 0xe
/* 08B758 800F22A8 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B75C 800F22AC 0C051F32 */  jal   func_80147CC8
/* 08B760 800F22B0 AFA20020 */   sw    $v0, 0x20($sp)
/* 08B764 800F22B4 2404000F */  addiu $a0, $zero, 0xf
/* 08B768 800F22B8 0C051F9F */  jal   func_80147E7C
/* 08B76C 800F22BC 24050001 */   addiu $a1, $zero, 1
/* 08B770 800F22C0 24040011 */  addiu $a0, $zero, 0x11
/* 08B774 800F22C4 0803C902 */  j     .L800F2408
/* 08B778 800F22C8 24050002 */   addiu $a1, $zero, 2

/* 08B77C 800F22CC 2404000E */  addiu $a0, $zero, 0xe
/* 08B780 800F22D0 24070095 */  addiu $a3, $zero, 0x95
/* 08B784 800F22D4 3C038011 */  lui   $v1, 0x8011
/* 08B788 800F22D8 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B78C 800F22DC 24020014 */  addiu $v0, $zero, 0x14
/* 08B790 800F22E0 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B794 800F22E4 3C02800F */  lui   $v0, 0x800f
/* 08B798 800F22E8 24423680 */  addiu $v0, $v0, 0x3680
/* 08B79C 800F22EC AFA20018 */  sw    $v0, 0x18($sp)
/* 08B7A0 800F22F0 2402FFFF */  addiu $v0, $zero, -1
/* 08B7A4 800F22F4 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B7A8 800F22F8 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B7AC 800F22FC 00031040 */  sll   $v0, $v1, 1
/* 08B7B0 800F2300 00431021 */  addu  $v0, $v0, $v1
/* 08B7B4 800F2304 00021080 */  sll   $v0, $v0, 2
/* 08B7B8 800F2308 00431021 */  addu  $v0, $v0, $v1
/* 08B7BC 800F230C 2442001A */  addiu $v0, $v0, 0x1a
/* 08B7C0 800F2310 0C051F32 */  jal   func_80147CC8
/* 08B7C4 800F2314 AFA20010 */   sw    $v0, 0x10($sp)
/* 08B7C8 800F2318 2404000F */  addiu $a0, $zero, 0xf
/* 08B7CC 800F231C 24050006 */  addiu $a1, $zero, 6
/* 08B7D0 800F2320 2406FFFA */  addiu $a2, $zero, -6
/* 08B7D4 800F2324 2407008B */  addiu $a3, $zero, 0x8b
/* 08B7D8 800F2328 24020010 */  addiu $v0, $zero, 0x10
/* 08B7DC 800F232C AFA20010 */  sw    $v0, 0x10($sp)
/* 08B7E0 800F2330 24020015 */  addiu $v0, $zero, 0x15
/* 08B7E4 800F2334 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B7E8 800F2338 3C02800F */  lui   $v0, 0x800f
/* 08B7EC 800F233C 24424648 */  addiu $v0, $v0, 0x4648
/* 08B7F0 800F2340 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B7F4 800F2344 2402000E */  addiu $v0, $zero, 0xe
/* 08B7F8 800F2348 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B7FC 800F234C 0C051F32 */  jal   func_80147CC8
/* 08B800 800F2350 AFA20020 */   sw    $v0, 0x20($sp)
/* 08B804 800F2354 2404000F */  addiu $a0, $zero, 0xf
/* 08B808 800F2358 0C051F9F */  jal   func_80147E7C
/* 08B80C 800F235C 24050001 */   addiu $a1, $zero, 1
/* 08B810 800F2360 24040011 */  addiu $a0, $zero, 0x11
/* 08B814 800F2364 0803C902 */  j     .L800F2408
/* 08B818 800F2368 24050002 */   addiu $a1, $zero, 2

/* 08B81C 800F236C 2404000E */  addiu $a0, $zero, 0xe
/* 08B820 800F2370 24070083 */  addiu $a3, $zero, 0x83
/* 08B824 800F2374 3C038011 */  lui   $v1, 0x8011
/* 08B828 800F2378 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08B82C 800F237C 24020014 */  addiu $v0, $zero, 0x14
/* 08B830 800F2380 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B834 800F2384 3C02800F */  lui   $v0, 0x800f
/* 08B838 800F2388 24423680 */  addiu $v0, $v0, 0x3680
/* 08B83C 800F238C AFA20018 */  sw    $v0, 0x18($sp)
/* 08B840 800F2390 2402FFFF */  addiu $v0, $zero, -1
/* 08B844 800F2394 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B848 800F2398 AFA20020 */  sw    $v0, 0x20($sp)
/* 08B84C 800F239C 00031040 */  sll   $v0, $v1, 1
/* 08B850 800F23A0 00431021 */  addu  $v0, $v0, $v1
/* 08B854 800F23A4 00021080 */  sll   $v0, $v0, 2
/* 08B858 800F23A8 00431021 */  addu  $v0, $v0, $v1
/* 08B85C 800F23AC 2442001A */  addiu $v0, $v0, 0x1a
/* 08B860 800F23B0 0C051F32 */  jal   func_80147CC8
/* 08B864 800F23B4 AFA20010 */   sw    $v0, 0x10($sp)
/* 08B868 800F23B8 24040011 */  addiu $a0, $zero, 0x11
/* 08B86C 800F23BC 2405000A */  addiu $a1, $zero, 0xa
.L800F23C0:
/* 08B870 800F23C0 2406FFFA */  addiu $a2, $zero, -6
/* 08B874 800F23C4 24070072 */  addiu $a3, $zero, 0x72
/* 08B878 800F23C8 24020010 */  addiu $v0, $zero, 0x10
/* 08B87C 800F23CC AFA20010 */  sw    $v0, 0x10($sp)
/* 08B880 800F23D0 24020015 */  addiu $v0, $zero, 0x15
/* 08B884 800F23D4 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B888 800F23D8 3C02800F */  lui   $v0, 0x800f
/* 08B88C 800F23DC 24424648 */  addiu $v0, $v0, 0x4648
/* 08B890 800F23E0 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B894 800F23E4 2402000E */  addiu $v0, $zero, 0xe
/* 08B898 800F23E8 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B89C 800F23EC 0C051F32 */  jal   func_80147CC8
/* 08B8A0 800F23F0 AFA20020 */   sw    $v0, 0x20($sp)
/* 08B8A4 800F23F4 2404000F */  addiu $a0, $zero, 0xf
/* 08B8A8 800F23F8 0C051F9F */  jal   func_80147E7C
/* 08B8AC 800F23FC 24050002 */   addiu $a1, $zero, 2
/* 08B8B0 800F2400 24040011 */  addiu $a0, $zero, 0x11
/* 08B8B4 800F2404 24050001 */  addiu $a1, $zero, 1
.L800F2408:
/* 08B8B8 800F2408 0C051F9F */  jal   func_80147E7C
/* 08B8BC 800F240C 00000000 */   nop   
.L800F2410:
/* 08B8C0 800F2410 3C028011 */  lui   $v0, 0x8011
/* 08B8C4 800F2414 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08B8C8 800F2418 8C430318 */  lw    $v1, 0x318($v0)
/* 08B8CC 800F241C 24020003 */  addiu $v0, $zero, 3
/* 08B8D0 800F2420 10620005 */  beq   $v1, $v0, .L800F2438
/* 08B8D4 800F2424 24020005 */   addiu $v0, $zero, 5
/* 08B8D8 800F2428 10620006 */  beq   $v1, $v0, .L800F2444
/* 08B8DC 800F242C 24040010 */   addiu $a0, $zero, 0x10
/* 08B8E0 800F2430 0803C91F */  j     .L800F247C
/* 08B8E4 800F2434 00000000 */   nop   

.L800F2438:
/* 08B8E8 800F2438 24040010 */  addiu $a0, $zero, 0x10
/* 08B8EC 800F243C 0803C912 */  j     .L800F2448
/* 08B8F0 800F2440 2405007E */   addiu $a1, $zero, 0x7e

.L800F2444:
/* 08B8F4 800F2444 24050083 */  addiu $a1, $zero, 0x83
.L800F2448:
/* 08B8F8 800F2448 2406FFF2 */  addiu $a2, $zero, -0xe
/* 08B8FC 800F244C 24070020 */  addiu $a3, $zero, 0x20
/* 08B900 800F2450 00E0102D */  daddu $v0, $a3, $zero
/* 08B904 800F2454 AFA20010 */  sw    $v0, 0x10($sp)
/* 08B908 800F2458 24020015 */  addiu $v0, $zero, 0x15
/* 08B90C 800F245C AFA20014 */  sw    $v0, 0x14($sp)
/* 08B910 800F2460 3C02800F */  lui   $v0, 0x800f
/* 08B914 800F2464 24424C6C */  addiu $v0, $v0, 0x4c6c
/* 08B918 800F2468 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B91C 800F246C 2402000E */  addiu $v0, $zero, 0xe
/* 08B920 800F2470 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B924 800F2474 0C051F32 */  jal   func_80147CC8
/* 08B928 800F2478 AFA20020 */   sw    $v0, 0x20($sp)
.L800F247C:
/* 08B92C 800F247C 3C108011 */  lui   $s0, 0x8011
/* 08B930 800F2480 2610D69C */  addiu $s0, $s0, -0x2964
/* 08B934 800F2484 8E020000 */  lw    $v0, ($s0)
/* 08B938 800F2488 8C430318 */  lw    $v1, 0x318($v0)
/* 08B93C 800F248C 24020003 */  addiu $v0, $zero, 3
/* 08B940 800F2490 14620011 */  bne   $v1, $v0, .L800F24D8
/* 08B944 800F2494 24040014 */   addiu $a0, $zero, 0x14
/* 08B948 800F2498 24070040 */  addiu $a3, $zero, 0x40
/* 08B94C 800F249C 3C058011 */  lui   $a1, 0x8011
/* 08B950 800F24A0 84A5D688 */  lh    $a1, -0x2978($a1)
/* 08B954 800F24A4 3C068011 */  lui   $a2, 0x8011
/* 08B958 800F24A8 84C6D68A */  lh    $a2, -0x2976($a2)
/* 08B95C 800F24AC 0080102D */  daddu $v0, $a0, $zero
/* 08B960 800F24B0 AFA20010 */  sw    $v0, 0x10($sp)
/* 08B964 800F24B4 24020015 */  addiu $v0, $zero, 0x15
/* 08B968 800F24B8 AFA20014 */  sw    $v0, 0x14($sp)
/* 08B96C 800F24BC 3C02800F */  lui   $v0, 0x800f
/* 08B970 800F24C0 24424D28 */  addiu $v0, $v0, 0x4d28
/* 08B974 800F24C4 AFA20018 */  sw    $v0, 0x18($sp)
/* 08B978 800F24C8 2402FFFF */  addiu $v0, $zero, -1
/* 08B97C 800F24CC AFA0001C */  sw    $zero, 0x1c($sp)
/* 08B980 800F24D0 0C051F32 */  jal   func_80147CC8
/* 08B984 800F24D4 AFA20020 */   sw    $v0, 0x20($sp)
.L800F24D8:
/* 08B988 800F24D8 3C078011 */  lui   $a3, 0x8011
/* 08B98C 800F24DC 24E7D654 */  addiu $a3, $a3, -0x29ac
/* 08B990 800F24E0 0200582D */  daddu $t3, $s0, $zero
/* 08B994 800F24E4 3C0A8011 */  lui   $t2, 0x8011
/* 08B998 800F24E8 254AD68F */  addiu $t2, $t2, -0x2971
/* 08B99C 800F24EC 3C098011 */  lui   $t1, 0x8011
/* 08B9A0 800F24F0 8129D655 */  lb    $t1, -0x29ab($t1)
/* 08B9A4 800F24F4 3C088011 */  lui   $t0, 0x8011
/* 08B9A8 800F24F8 8D08D648 */  lw    $t0, -0x29b8($t0)
.L800F24FC:
/* 08B9AC 800F24FC 80E20000 */  lb    $v0, ($a3)
/* 08B9B0 800F2500 90E30000 */  lbu   $v1, ($a3)
/* 08B9B4 800F2504 00491021 */  addu  $v0, $v0, $t1
/* 08B9B8 800F2508 2442FFFF */  addiu $v0, $v0, -1
/* 08B9BC 800F250C 0102102A */  slt   $v0, $t0, $v0
/* 08B9C0 800F2510 14400013 */  bnez  $v0, .L800F2560
/* 08B9C4 800F2514 0000302D */   daddu $a2, $zero, $zero
/* 08B9C8 800F2518 24620001 */  addiu $v0, $v1, 1
/* 08B9CC 800F251C A0E20000 */  sb    $v0, ($a3)
/* 08B9D0 800F2520 00021600 */  sll   $v0, $v0, 0x18
/* 08B9D4 800F2524 8D650000 */  lw    $a1, ($t3)
/* 08B9D8 800F2528 81440000 */  lb    $a0, ($t2)
/* 08B9DC 800F252C 8CA30324 */  lw    $v1, 0x324($a1)
/* 08B9E0 800F2530 00021603 */  sra   $v0, $v0, 0x18
/* 08B9E4 800F2534 00641823 */  subu  $v1, $v1, $a0
/* 08B9E8 800F2538 0062182A */  slt   $v1, $v1, $v0
/* 08B9EC 800F253C 91440000 */  lbu   $a0, ($t2)
/* 08B9F0 800F2540 50600007 */  beql  $v1, $zero, .L800F2560
/* 08B9F4 800F2544 24060001 */   addiu $a2, $zero, 1
/* 08B9F8 800F2548 90A20327 */  lbu   $v0, 0x327($a1)
/* 08B9FC 800F254C 00441023 */  subu  $v0, $v0, $a0
/* 08BA00 800F2550 A0E20000 */  sb    $v0, ($a3)
/* 08BA04 800F2554 00021600 */  sll   $v0, $v0, 0x18
/* 08BA08 800F2558 04420001 */  bltzl $v0, .L800F2560
/* 08BA0C 800F255C A0E00000 */   sb    $zero, ($a3)
.L800F2560:
/* 08BA10 800F2560 14C0FFE6 */  bnez  $a2, .L800F24FC
/* 08BA14 800F2564 00000000 */   nop   
/* 08BA18 800F2568 3C038011 */  lui   $v1, 0x8011
/* 08BA1C 800F256C 9063D654 */  lbu   $v1, -0x29ac($v1)
/* 08BA20 800F2570 3C028011 */  lui   $v0, 0x8011
/* 08BA24 800F2574 9042D68F */  lbu   $v0, -0x2971($v0)
/* 08BA28 800F2578 3C048011 */  lui   $a0, 0x8011
/* 08BA2C 800F257C 8C84D69C */  lw    $a0, -0x2964($a0)
/* 08BA30 800F2580 00621021 */  addu  $v0, $v1, $v0
/* 08BA34 800F2584 00031E00 */  sll   $v1, $v1, 0x18
/* 08BA38 800F2588 00031E03 */  sra   $v1, $v1, 0x18
/* 08BA3C 800F258C 00031823 */  negu  $v1, $v1
/* 08BA40 800F2590 3C018011 */  lui   $at, 0x8011
/* 08BA44 800F2594 A022D655 */  sb    $v0, -0x29ab($at)
/* 08BA48 800F2598 00031040 */  sll   $v0, $v1, 1
/* 08BA4C 800F259C 00431021 */  addu  $v0, $v0, $v1
/* 08BA50 800F25A0 00021080 */  sll   $v0, $v0, 2
/* 08BA54 800F25A4 8C840318 */  lw    $a0, 0x318($a0)
/* 08BA58 800F25A8 00431021 */  addu  $v0, $v0, $v1
/* 08BA5C 800F25AC 3C018011 */  lui   $at, 0x8011
/* 08BA60 800F25B0 A422D658 */  sh    $v0, -0x29a8($at)
/* 08BA64 800F25B4 04800016 */  bltz  $a0, .L800F2610
/* 08BA68 800F25B8 2882000A */   slti  $v0, $a0, 0xa
/* 08BA6C 800F25BC 54400004 */  bnezl $v0, .L800F25D0
/* 08BA70 800F25C0 24040013 */   addiu $a0, $zero, 0x13
/* 08BA74 800F25C4 2402000C */  addiu $v0, $zero, 0xc
/* 08BA78 800F25C8 14820011 */  bne   $a0, $v0, .L800F2610
/* 08BA7C 800F25CC 24040013 */   addiu $a0, $zero, 0x13
.L800F25D0:
/* 08BA80 800F25D0 24070118 */  addiu $a3, $zero, 0x118
/* 08BA84 800F25D4 3C058011 */  lui   $a1, 0x8011
/* 08BA88 800F25D8 84A5D680 */  lh    $a1, -0x2980($a1)
/* 08BA8C 800F25DC 3C068011 */  lui   $a2, 0x8011
/* 08BA90 800F25E0 84C6D682 */  lh    $a2, -0x297e($a2)
/* 08BA94 800F25E4 24020020 */  addiu $v0, $zero, 0x20
/* 08BA98 800F25E8 AFA20010 */  sw    $v0, 0x10($sp)
/* 08BA9C 800F25EC 24020014 */  addiu $v0, $zero, 0x14
/* 08BAA0 800F25F0 AFA20014 */  sw    $v0, 0x14($sp)
/* 08BAA4 800F25F4 3C02800F */  lui   $v0, 0x800f
/* 08BAA8 800F25F8 244248F4 */  addiu $v0, $v0, 0x48f4
/* 08BAAC 800F25FC AFA20018 */  sw    $v0, 0x18($sp)
/* 08BAB0 800F2600 2402FFFF */  addiu $v0, $zero, -1
/* 08BAB4 800F2604 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08BAB8 800F2608 0C051F32 */  jal   func_80147CC8
/* 08BABC 800F260C AFA20020 */   sw    $v0, 0x20($sp)
.L800F2610:
/* 08BAC0 800F2610 3C028011 */  lui   $v0, 0x8011
/* 08BAC4 800F2614 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08BAC8 800F2618 3C058011 */  lui   $a1, 0x8011
/* 08BACC 800F261C 84A5D684 */  lh    $a1, -0x297c($a1)
/* 08BAD0 800F2620 8C430318 */  lw    $v1, 0x318($v0)
/* 08BAD4 800F2624 3C068011 */  lui   $a2, 0x8011
/* 08BAD8 800F2628 84C6D686 */  lh    $a2, -0x297a($a2)
/* 08BADC 800F262C 2C62000E */  sltiu $v0, $v1, 0xe
/* 08BAE0 800F2630 10400026 */  beqz  $v0, .L800F26CC
/* 08BAE4 800F2634 00031080 */   sll   $v0, $v1, 2
/* 08BAE8 800F2638 3C018011 */  lui   $at, 0x8011
/* 08BAEC 800F263C 00220821 */  addu  $at, $at, $v0
/* 08BAF0 800F2640 8C22C608 */  lw    $v0, -0x39f8($at)
/* 08BAF4 800F2644 00400008 */  jr    $v0
/* 08BAF8 800F2648 00000000 */   nop   
/* 08BAFC 800F264C 24040015 */  addiu $a0, $zero, 0x15
/* 08BB00 800F2650 0803C9A8 */  j     .L800F26A0
/* 08BB04 800F2654 24070090 */   addiu $a3, $zero, 0x90

/* 08BB08 800F2658 24040015 */  addiu $a0, $zero, 0x15
/* 08BB0C 800F265C 24070090 */  addiu $a3, $zero, 0x90
/* 08BB10 800F2660 0803C9A9 */  j     .L800F26A4
/* 08BB14 800F2664 24020028 */   addiu $v0, $zero, 0x28

/* 08BB18 800F2668 24040015 */  addiu $a0, $zero, 0x15
/* 08BB1C 800F266C 24070080 */  addiu $a3, $zero, 0x80
/* 08BB20 800F2670 0803C9A9 */  j     .L800F26A4
/* 08BB24 800F2674 24020028 */   addiu $v0, $zero, 0x28

/* 08BB28 800F2678 24040015 */  addiu $a0, $zero, 0x15
/* 08BB2C 800F267C 24070088 */  addiu $a3, $zero, 0x88
/* 08BB30 800F2680 0803C9A9 */  j     .L800F26A4
/* 08BB34 800F2684 24020028 */   addiu $v0, $zero, 0x28

/* 08BB38 800F2688 24040015 */  addiu $a0, $zero, 0x15
/* 08BB3C 800F268C 24070070 */  addiu $a3, $zero, 0x70
/* 08BB40 800F2690 0803C9A9 */  j     .L800F26A4
/* 08BB44 800F2694 24020028 */   addiu $v0, $zero, 0x28

/* 08BB48 800F2698 24040015 */  addiu $a0, $zero, 0x15
/* 08BB4C 800F269C 24070078 */  addiu $a3, $zero, 0x78
.L800F26A0:
/* 08BB50 800F26A0 24020020 */  addiu $v0, $zero, 0x20
.L800F26A4:
/* 08BB54 800F26A4 AFA20010 */  sw    $v0, 0x10($sp)
/* 08BB58 800F26A8 24020014 */  addiu $v0, $zero, 0x14
/* 08BB5C 800F26AC AFA20014 */  sw    $v0, 0x14($sp)
/* 08BB60 800F26B0 3C02800F */  lui   $v0, 0x800f
/* 08BB64 800F26B4 24424944 */  addiu $v0, $v0, 0x4944
/* 08BB68 800F26B8 AFA20018 */  sw    $v0, 0x18($sp)
/* 08BB6C 800F26BC 2402FFFF */  addiu $v0, $zero, -1
/* 08BB70 800F26C0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08BB74 800F26C4 0C051F32 */  jal   func_80147CC8
/* 08BB78 800F26C8 AFA20020 */   sw    $v0, 0x20($sp)
.L800F26CC:
/* 08BB7C 800F26CC 3C028011 */  lui   $v0, 0x8011
/* 08BB80 800F26D0 8042D68E */  lb    $v0, -0x2972($v0)
/* 08BB84 800F26D4 14400018 */  bnez  $v0, .L800F2738
/* 08BB88 800F26D8 00000000 */   nop   
/* 08BB8C 800F26DC 3C028011 */  lui   $v0, 0x8011
/* 08BB90 800F26E0 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08BB94 800F26E4 8C430318 */  lw    $v1, 0x318($v0)
/* 08BB98 800F26E8 2C62000E */  sltiu $v0, $v1, 0xe
/* 08BB9C 800F26EC 1040003A */  beqz  $v0, .L800F27D8
/* 08BBA0 800F26F0 00031080 */   sll   $v0, $v1, 2
/* 08BBA4 800F26F4 3C018011 */  lui   $at, 0x8011
/* 08BBA8 800F26F8 00220821 */  addu  $at, $at, $v0
/* 08BBAC 800F26FC 8C22C640 */  lw    $v0, -0x39c0($at)
/* 08BBB0 800F2700 00400008 */  jr    $v0
/* 08BBB4 800F2704 00000000 */   nop   
/* 08BBB8 800F2708 2404000E */  addiu $a0, $zero, 0xe
/* 08BBBC 800F270C 0C051F9F */  jal   func_80147E7C
/* 08BBC0 800F2710 24050001 */   addiu $a1, $zero, 1
/* 08BBC4 800F2714 0803C9F4 */  j     .L800F27D0
/* 08BBC8 800F2718 24040013 */   addiu $a0, $zero, 0x13

/* 08BBCC 800F271C 2404000E */  addiu $a0, $zero, 0xe
/* 08BBD0 800F2720 0C051F9F */  jal   func_80147E7C
/* 08BBD4 800F2724 24050001 */   addiu $a1, $zero, 1
/* 08BBD8 800F2728 0803C9F4 */  j     .L800F27D0
/* 08BBDC 800F272C 24040013 */   addiu $a0, $zero, 0x13

/* 08BBE0 800F2730 0803C9F4 */  j     .L800F27D0
/* 08BBE4 800F2734 2404000E */   addiu $a0, $zero, 0xe

.L800F2738:
/* 08BBE8 800F2738 3C028011 */  lui   $v0, 0x8011
/* 08BBEC 800F273C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08BBF0 800F2740 8C430318 */  lw    $v1, 0x318($v0)
/* 08BBF4 800F2744 2C62000E */  sltiu $v0, $v1, 0xe
/* 08BBF8 800F2748 10400020 */  beqz  $v0, .L800F27CC
/* 08BBFC 800F274C 00031080 */   sll   $v0, $v1, 2
/* 08BC00 800F2750 3C018011 */  lui   $at, 0x8011
/* 08BC04 800F2754 00220821 */  addu  $at, $at, $v0
/* 08BC08 800F2758 8C22C678 */  lw    $v0, -0x3988($at)
/* 08BC0C 800F275C 00400008 */  jr    $v0
/* 08BC10 800F2760 00000000 */   nop   
/* 08BC14 800F2764 2404000E */  addiu $a0, $zero, 0xe
/* 08BC18 800F2768 3C108014 */  lui   $s0, 0x8014
/* 08BC1C 800F276C 26107474 */  addiu $s0, $s0, 0x7474
/* 08BC20 800F2770 0C051F9F */  jal   func_80147E7C
/* 08BC24 800F2774 0200282D */   daddu $a1, $s0, $zero
/* 08BC28 800F2778 0803C9E6 */  j     .L800F2798
/* 08BC2C 800F277C 24040001 */   addiu $a0, $zero, 1

/* 08BC30 800F2780 2404000E */  addiu $a0, $zero, 0xe
/* 08BC34 800F2784 3C108014 */  lui   $s0, 0x8014
/* 08BC38 800F2788 26107474 */  addiu $s0, $s0, 0x7474
/* 08BC3C 800F278C 0C051F9F */  jal   func_80147E7C
/* 08BC40 800F2790 0200282D */   daddu $a1, $s0, $zero
/* 08BC44 800F2794 24040002 */  addiu $a0, $zero, 2
.L800F2798:
/* 08BC48 800F2798 0C05272D */  jal   play_sound
/* 08BC4C 800F279C 00000000 */   nop   
/* 08BC50 800F27A0 24040013 */  addiu $a0, $zero, 0x13
/* 08BC54 800F27A4 0C051F9F */  jal   func_80147E7C
/* 08BC58 800F27A8 0200282D */   daddu $a1, $s0, $zero
/* 08BC5C 800F27AC 0803C9F4 */  j     .L800F27D0
/* 08BC60 800F27B0 24040015 */   addiu $a0, $zero, 0x15

/* 08BC64 800F27B4 3C058014 */  lui   $a1, 0x8014
/* 08BC68 800F27B8 24A57474 */  addiu $a1, $a1, 0x7474
/* 08BC6C 800F27BC 0C051F9F */  jal   func_80147E7C
/* 08BC70 800F27C0 2404000E */   addiu $a0, $zero, 0xe
/* 08BC74 800F27C4 0C05272D */  jal   play_sound
/* 08BC78 800F27C8 24040001 */   addiu $a0, $zero, 1
.L800F27CC:
/* 08BC7C 800F27CC 24040015 */  addiu $a0, $zero, 0x15
.L800F27D0:
/* 08BC80 800F27D0 0C051F9F */  jal   func_80147E7C
/* 08BC84 800F27D4 24050001 */   addiu $a1, $zero, 1
.L800F27D8:
/* 08BC88 800F27D8 3C118011 */  lui   $s1, 0x8011
/* 08BC8C 800F27DC 2631D69C */  addiu $s1, $s1, -0x2964
/* 08BC90 800F27E0 8E220000 */  lw    $v0, ($s1)
/* 08BC94 800F27E4 8C430318 */  lw    $v1, 0x318($v0)
/* 08BC98 800F27E8 24020003 */  addiu $v0, $zero, 3
/* 08BC9C 800F27EC 14620008 */  bne   $v1, $v0, .L800F2810
/* 08BCA0 800F27F0 24040010 */   addiu $a0, $zero, 0x10
/* 08BCA4 800F27F4 3C108014 */  lui   $s0, 0x8014
/* 08BCA8 800F27F8 26107474 */  addiu $s0, $s0, 0x7474
/* 08BCAC 800F27FC 0C051F9F */  jal   func_80147E7C
/* 08BCB0 800F2800 0200282D */   daddu $a1, $s0, $zero
/* 08BCB4 800F2804 24040014 */  addiu $a0, $zero, 0x14
/* 08BCB8 800F2808 0C051F9F */  jal   func_80147E7C
/* 08BCBC 800F280C 0200282D */   daddu $a1, $s0, $zero
.L800F2810:
/* 08BCC0 800F2810 8E220000 */  lw    $v0, ($s1)
/* 08BCC4 800F2814 8C430318 */  lw    $v1, 0x318($v0)
/* 08BCC8 800F2818 24020004 */  addiu $v0, $zero, 4
/* 08BCCC 800F281C 14620005 */  bne   $v1, $v0, .L800F2834
/* 08BCD0 800F2820 00000000 */   nop   
/* 08BCD4 800F2824 3C058014 */  lui   $a1, 0x8014
/* 08BCD8 800F2828 24A57474 */  addiu $a1, $a1, 0x7474
/* 08BCDC 800F282C 0C051F9F */  jal   func_80147E7C
/* 08BCE0 800F2830 24040012 */   addiu $a0, $zero, 0x12
.L800F2834:
/* 08BCE4 800F2834 8E220000 */  lw    $v0, ($s1)
/* 08BCE8 800F2838 8C430318 */  lw    $v1, 0x318($v0)
/* 08BCEC 800F283C 24020005 */  addiu $v0, $zero, 5
/* 08BCF0 800F2840 14620382 */  bne   $v1, $v0, .L800F364C
/* 08BCF4 800F2844 24020001 */   addiu $v0, $zero, 1
/* 08BCF8 800F2848 3C058014 */  lui   $a1, 0x8014
/* 08BCFC 800F284C 24A57474 */  addiu $a1, $a1, 0x7474
/* 08BD00 800F2850 0C051F9F */  jal   func_80147E7C
/* 08BD04 800F2854 24040010 */   addiu $a0, $zero, 0x10
/* 08BD08 800F2858 0803CD93 */  j     .L800F364C
/* 08BD0C 800F285C 24020001 */   addiu $v0, $zero, 1

/* 08BD10 800F2860 3C038011 */  lui   $v1, 0x8011
/* 08BD14 800F2864 2463D644 */  addiu $v1, $v1, -0x29bc
/* 08BD18 800F2868 8C620000 */  lw    $v0, ($v1)
/* 08BD1C 800F286C 10400003 */  beqz  $v0, .L800F287C
/* 08BD20 800F2870 2442FFFF */   addiu $v0, $v0, -1
/* 08BD24 800F2874 0803CD95 */  j     .L800F3654
/* 08BD28 800F2878 AC620000 */   sw    $v0, ($v1)

.L800F287C:
/* 08BD2C 800F287C 3C060001 */  lui   $a2, 1
/* 08BD30 800F2880 3C058011 */  lui   $a1, 0x8011
/* 08BD34 800F2884 24A5D648 */  addiu $a1, $a1, -0x29b8
/* 08BD38 800F2888 3C048007 */  lui   $a0, 0x8007
/* 08BD3C 800F288C 8C84419C */  lw    $a0, 0x419c($a0)
/* 08BD40 800F2890 8CA30000 */  lw    $v1, ($a1)
/* 08BD44 800F2894 8C820020 */  lw    $v0, 0x20($a0)
/* 08BD48 800F2898 34C62000 */  ori   $a2, $a2, 0x2000
/* 08BD4C 800F289C 3C018011 */  lui   $at, 0x8011
/* 08BD50 800F28A0 AC23D64C */  sw    $v1, -0x29b4($at)
/* 08BD54 800F28A4 00461024 */  and   $v0, $v0, $a2
/* 08BD58 800F28A8 10400008 */  beqz  $v0, .L800F28CC
/* 08BD5C 800F28AC 00000000 */   nop   
/* 08BD60 800F28B0 1C600005 */  bgtz  $v1, .L800F28C8
/* 08BD64 800F28B4 2462FFFF */   addiu $v0, $v1, -1
/* 08BD68 800F28B8 8C820010 */  lw    $v0, 0x10($a0)
/* 08BD6C 800F28BC 00461024 */  and   $v0, $v0, $a2
/* 08BD70 800F28C0 10400002 */  beqz  $v0, .L800F28CC
/* 08BD74 800F28C4 2462FFFF */   addiu $v0, $v1, -1
.L800F28C8:
/* 08BD78 800F28C8 ACA20000 */  sw    $v0, ($a1)
.L800F28CC:
/* 08BD7C 800F28CC 3C058007 */  lui   $a1, 0x8007
/* 08BD80 800F28D0 8CA5419C */  lw    $a1, 0x419c($a1)
/* 08BD84 800F28D4 3C060002 */  lui   $a2, 2
/* 08BD88 800F28D8 8CA20020 */  lw    $v0, 0x20($a1)
/* 08BD8C 800F28DC 34C60010 */  ori   $a2, $a2, 0x10
/* 08BD90 800F28E0 00461024 */  and   $v0, $v0, $a2
/* 08BD94 800F28E4 10400010 */  beqz  $v0, .L800F2928
/* 08BD98 800F28E8 00000000 */   nop   
/* 08BD9C 800F28EC 3C028011 */  lui   $v0, 0x8011
/* 08BDA0 800F28F0 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08BDA4 800F28F4 3C048011 */  lui   $a0, 0x8011
/* 08BDA8 800F28F8 2484D648 */  addiu $a0, $a0, -0x29b8
/* 08BDAC 800F28FC 8C420324 */  lw    $v0, 0x324($v0)
/* 08BDB0 800F2900 8C830000 */  lw    $v1, ($a0)
/* 08BDB4 800F2904 2442FFFF */  addiu $v0, $v0, -1
/* 08BDB8 800F2908 0062102A */  slt   $v0, $v1, $v0
/* 08BDBC 800F290C 14400005 */  bnez  $v0, .L800F2924
/* 08BDC0 800F2910 24620001 */   addiu $v0, $v1, 1
/* 08BDC4 800F2914 8CA20010 */  lw    $v0, 0x10($a1)
/* 08BDC8 800F2918 00461024 */  and   $v0, $v0, $a2
/* 08BDCC 800F291C 10400002 */  beqz  $v0, .L800F2928
/* 08BDD0 800F2920 24620001 */   addiu $v0, $v1, 1
.L800F2924:
/* 08BDD4 800F2924 AC820000 */  sw    $v0, ($a0)
.L800F2928:
/* 08BDD8 800F2928 3C108011 */  lui   $s0, 0x8011
/* 08BDDC 800F292C 2610D648 */  addiu $s0, $s0, -0x29b8
/* 08BDE0 800F2930 8E020000 */  lw    $v0, ($s0)
/* 08BDE4 800F2934 04410006 */  bgez  $v0, .L800F2950
/* 08BDE8 800F2938 00000000 */   nop   
/* 08BDEC 800F293C 3C028011 */  lui   $v0, 0x8011
/* 08BDF0 800F2940 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08BDF4 800F2944 8C420324 */  lw    $v0, 0x324($v0)
/* 08BDF8 800F2948 2442FFFF */  addiu $v0, $v0, -1
/* 08BDFC 800F294C AE020000 */  sw    $v0, ($s0)
.L800F2950:
/* 08BE00 800F2950 3C028011 */  lui   $v0, 0x8011
/* 08BE04 800F2954 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08BE08 800F2958 8C420324 */  lw    $v0, 0x324($v0)
/* 08BE0C 800F295C 8E030000 */  lw    $v1, ($s0)
/* 08BE10 800F2960 2442FFFF */  addiu $v0, $v0, -1
/* 08BE14 800F2964 0043102A */  slt   $v0, $v0, $v1
/* 08BE18 800F2968 54400001 */  bnezl $v0, .L800F2970
/* 08BE1C 800F296C AE000000 */   sw    $zero, ($s0)
.L800F2970:
/* 08BE20 800F2970 3C038011 */  lui   $v1, 0x8011
/* 08BE24 800F2974 8C63D64C */  lw    $v1, -0x29b4($v1)
/* 08BE28 800F2978 8E020000 */  lw    $v0, ($s0)
/* 08BE2C 800F297C 10620004 */  beq   $v1, $v0, .L800F2990
/* 08BE30 800F2980 0000302D */   daddu $a2, $zero, $zero
/* 08BE34 800F2984 0C05272D */  jal   play_sound
/* 08BE38 800F2988 240400C7 */   addiu $a0, $zero, 0xc7
/* 08BE3C 800F298C 0000302D */  daddu $a2, $zero, $zero
.L800F2990:
/* 08BE40 800F2990 3C058011 */  lui   $a1, 0x8011
/* 08BE44 800F2994 24A5D654 */  addiu $a1, $a1, -0x29ac
/* 08BE48 800F2998 8E030000 */  lw    $v1, ($s0)
.L800F299C:
/* 08BE4C 800F299C 80A20000 */  lb    $v0, ($a1)
/* 08BE50 800F29A0 90A40000 */  lbu   $a0, ($a1)
/* 08BE54 800F29A4 24420001 */  addiu $v0, $v0, 1
/* 08BE58 800F29A8 0062102A */  slt   $v0, $v1, $v0
/* 08BE5C 800F29AC 50400007 */  beql  $v0, $zero, .L800F29CC
/* 08BE60 800F29B0 24C60001 */   addiu $a2, $a2, 1
/* 08BE64 800F29B4 2482FFFF */  addiu $v0, $a0, -1
/* 08BE68 800F29B8 A0A20000 */  sb    $v0, ($a1)
/* 08BE6C 800F29BC 00021600 */  sll   $v0, $v0, 0x18
/* 08BE70 800F29C0 04420001 */  bltzl $v0, .L800F29C8
/* 08BE74 800F29C4 A0A00000 */   sb    $zero, ($a1)
.L800F29C8:
/* 08BE78 800F29C8 24C60001 */  addiu $a2, $a2, 1
.L800F29CC:
/* 08BE7C 800F29CC 28C20004 */  slti  $v0, $a2, 4
/* 08BE80 800F29D0 1440FFF2 */  bnez  $v0, .L800F299C
/* 08BE84 800F29D4 00000000 */   nop   
/* 08BE88 800F29D8 0000302D */  daddu $a2, $zero, $zero
/* 08BE8C 800F29DC 3C098011 */  lui   $t1, 0x8011
/* 08BE90 800F29E0 2529D655 */  addiu $t1, $t1, -0x29ab
/* 08BE94 800F29E4 3C0A8011 */  lui   $t2, 0x8011
/* 08BE98 800F29E8 8D4AD648 */  lw    $t2, -0x29b8($t2)
/* 08BE9C 800F29EC 3C078011 */  lui   $a3, 0x8011
/* 08BEA0 800F29F0 24E7D654 */  addiu $a3, $a3, -0x29ac
/* 08BEA4 800F29F4 3C0B8011 */  lui   $t3, 0x8011
/* 08BEA8 800F29F8 256BD69C */  addiu $t3, $t3, -0x2964
/* 08BEAC 800F29FC 3C088011 */  lui   $t0, 0x8011
/* 08BEB0 800F2A00 2508D68F */  addiu $t0, $t0, -0x2971
.L800F2A04:
/* 08BEB4 800F2A04 81220000 */  lb    $v0, ($t1)
/* 08BEB8 800F2A08 2442FFFF */  addiu $v0, $v0, -1
/* 08BEBC 800F2A0C 0142102A */  slt   $v0, $t2, $v0
/* 08BEC0 800F2A10 14400013 */  bnez  $v0, .L800F2A60
/* 08BEC4 800F2A14 00000000 */   nop   
/* 08BEC8 800F2A18 90E20000 */  lbu   $v0, ($a3)
/* 08BECC 800F2A1C 24420001 */  addiu $v0, $v0, 1
/* 08BED0 800F2A20 A0E20000 */  sb    $v0, ($a3)
/* 08BED4 800F2A24 00021600 */  sll   $v0, $v0, 0x18
/* 08BED8 800F2A28 8D650000 */  lw    $a1, ($t3)
/* 08BEDC 800F2A2C 81040000 */  lb    $a0, ($t0)
/* 08BEE0 800F2A30 8CA30324 */  lw    $v1, 0x324($a1)
/* 08BEE4 800F2A34 00021603 */  sra   $v0, $v0, 0x18
/* 08BEE8 800F2A38 00641823 */  subu  $v1, $v1, $a0
/* 08BEEC 800F2A3C 0062182A */  slt   $v1, $v1, $v0
/* 08BEF0 800F2A40 10600007 */  beqz  $v1, .L800F2A60
/* 08BEF4 800F2A44 91040000 */   lbu   $a0, ($t0)
/* 08BEF8 800F2A48 90A20327 */  lbu   $v0, 0x327($a1)
/* 08BEFC 800F2A4C 00441023 */  subu  $v0, $v0, $a0
/* 08BF00 800F2A50 A0E20000 */  sb    $v0, ($a3)
/* 08BF04 800F2A54 00021600 */  sll   $v0, $v0, 0x18
/* 08BF08 800F2A58 04420001 */  bltzl $v0, .L800F2A60
/* 08BF0C 800F2A5C A0E00000 */   sb    $zero, ($a3)
.L800F2A60:
/* 08BF10 800F2A60 90E20000 */  lbu   $v0, ($a3)
/* 08BF14 800F2A64 91030000 */  lbu   $v1, ($t0)
/* 08BF18 800F2A68 24C60001 */  addiu $a2, $a2, 1
/* 08BF1C 800F2A6C 00431021 */  addu  $v0, $v0, $v1
/* 08BF20 800F2A70 A1220000 */  sb    $v0, ($t1)
/* 08BF24 800F2A74 28C20004 */  slti  $v0, $a2, 4
/* 08BF28 800F2A78 1440FFE2 */  bnez  $v0, .L800F2A04
/* 08BF2C 800F2A7C 00000000 */   nop   
/* 08BF30 800F2A80 3C028007 */  lui   $v0, 0x8007
/* 08BF34 800F2A84 8C42419C */  lw    $v0, 0x419c($v0)
/* 08BF38 800F2A88 8C420010 */  lw    $v0, 0x10($v0)
/* 08BF3C 800F2A8C 30428000 */  andi  $v0, $v0, 0x8000
/* 08BF40 800F2A90 1040003F */  beqz  $v0, .L800F2B90
/* 08BF44 800F2A94 00000000 */   nop   
/* 08BF48 800F2A98 3C028011 */  lui   $v0, 0x8011
/* 08BF4C 800F2A9C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08BF50 800F2AA0 8C430318 */  lw    $v1, 0x318($v0)
/* 08BF54 800F2AA4 24020008 */  addiu $v0, $zero, 8
/* 08BF58 800F2AA8 10620005 */  beq   $v1, $v0, .L800F2AC0
/* 08BF5C 800F2AAC 2402000D */   addiu $v0, $zero, 0xd
/* 08BF60 800F2AB0 1062000B */  beq   $v1, $v0, .L800F2AE0
/* 08BF64 800F2AB4 00000000 */   nop   
/* 08BF68 800F2AB8 0803CAC0 */  j     .L800F2B00
/* 08BF6C 800F2ABC 00000000 */   nop   

.L800F2AC0:
/* 08BF70 800F2AC0 0C05272D */  jal   play_sound
/* 08BF74 800F2AC4 240400C9 */   addiu $a0, $zero, 0xc9
/* 08BF78 800F2AC8 3C028011 */  lui   $v0, 0x8011
/* 08BF7C 800F2ACC 8042D68E */  lb    $v0, -0x2972($v0)
/* 08BF80 800F2AD0 144002DE */  bnez  $v0, .L800F364C
/* 08BF84 800F2AD4 2402FFFE */   addiu $v0, $zero, -2
/* 08BF88 800F2AD8 0803CD93 */  j     .L800F364C
/* 08BF8C 800F2ADC 2402FFFF */   addiu $v0, $zero, -1

.L800F2AE0:
/* 08BF90 800F2AE0 0C05272D */  jal   play_sound
/* 08BF94 800F2AE4 240400C9 */   addiu $a0, $zero, 0xc9
/* 08BF98 800F2AE8 3C028011 */  lui   $v0, 0x8011
/* 08BF9C 800F2AEC 8042D68E */  lb    $v0, -0x2972($v0)
/* 08BFA0 800F2AF0 144002D6 */  bnez  $v0, .L800F364C
/* 08BFA4 800F2AF4 2402FFFE */   addiu $v0, $zero, -2
/* 08BFA8 800F2AF8 0803CD93 */  j     .L800F364C
/* 08BFAC 800F2AFC 2402FFFF */   addiu $v0, $zero, -1

.L800F2B00:
/* 08BFB0 800F2B00 3C028011 */  lui   $v0, 0x8011
/* 08BFB4 800F2B04 8C42D648 */  lw    $v0, -0x29b8($v0)
/* 08BFB8 800F2B08 3C038011 */  lui   $v1, 0x8011
/* 08BFBC 800F2B0C 8C63D69C */  lw    $v1, -0x2964($v1)
/* 08BFC0 800F2B10 00021080 */  sll   $v0, $v0, 2
/* 08BFC4 800F2B14 00621021 */  addu  $v0, $v1, $v0
/* 08BFC8 800F2B18 8C42018C */  lw    $v0, 0x18c($v0)
/* 08BFCC 800F2B1C 10400009 */  beqz  $v0, .L800F2B44
/* 08BFD0 800F2B20 24020001 */   addiu $v0, $zero, 1
/* 08BFD4 800F2B24 0C05272D */  jal   play_sound
/* 08BFD8 800F2B28 240400C9 */   addiu $a0, $zero, 0xc9
/* 08BFDC 800F2B2C 3C028011 */  lui   $v0, 0x8011
/* 08BFE0 800F2B30 8042D68E */  lb    $v0, -0x2972($v0)
/* 08BFE4 800F2B34 144002C5 */  bnez  $v0, .L800F364C
/* 08BFE8 800F2B38 2402FFFE */   addiu $v0, $zero, -2
/* 08BFEC 800F2B3C 0803CD93 */  j     .L800F364C
/* 08BFF0 800F2B40 2402FFFF */   addiu $v0, $zero, -1

.L800F2B44:
/* 08BFF4 800F2B44 8C630318 */  lw    $v1, 0x318($v1)
/* 08BFF8 800F2B48 14620005 */  bne   $v1, $v0, .L800F2B60
/* 08BFFC 800F2B4C 00000000 */   nop   
/* 08C000 800F2B50 0C05272D */  jal   play_sound
/* 08C004 800F2B54 2404021D */   addiu $a0, $zero, 0x21d
/* 08C008 800F2B58 0803CD93 */  j     .L800F364C
/* 08C00C 800F2B5C 2402001E */   addiu $v0, $zero, 0x1e

.L800F2B60:
/* 08C010 800F2B60 3C028011 */  lui   $v0, 0x8011
/* 08C014 800F2B64 8042D68E */  lb    $v0, -0x2972($v0)
/* 08C018 800F2B68 104002BA */  beqz  $v0, .L800F3654
/* 08C01C 800F2B6C 00000000 */   nop   
/* 08C020 800F2B70 10600003 */  beqz  $v1, .L800F2B80
/* 08C024 800F2B74 24020003 */   addiu $v0, $zero, 3
/* 08C028 800F2B78 146202B6 */  bne   $v1, $v0, .L800F3654
/* 08C02C 800F2B7C 00000000 */   nop   
.L800F2B80:
/* 08C030 800F2B80 0C05272D */  jal   play_sound
/* 08C034 800F2B84 2404021D */   addiu $a0, $zero, 0x21d
/* 08C038 800F2B88 0803CD95 */  j     .L800F3654
/* 08C03C 800F2B8C 00000000 */   nop   

.L800F2B90:
/* 08C040 800F2B90 3C028011 */  lui   $v0, 0x8011
/* 08C044 800F2B94 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08C048 800F2B98 8C430318 */  lw    $v1, 0x318($v0)
/* 08C04C 800F2B9C 2C62000E */  sltiu $v0, $v1, 0xe
/* 08C050 800F2BA0 10400014 */  beqz  $v0, .L800F2BF4
/* 08C054 800F2BA4 00031080 */   sll   $v0, $v1, 2
/* 08C058 800F2BA8 3C018011 */  lui   $at, 0x8011
/* 08C05C 800F2BAC 00220821 */  addu  $at, $at, $v0
/* 08C060 800F2BB0 8C22C6B0 */  lw    $v0, -0x3950($at)
/* 08C064 800F2BB4 00400008 */  jr    $v0
/* 08C068 800F2BB8 00000000 */   nop   
/* 08C06C 800F2BBC 3C028011 */  lui   $v0, 0x8011
/* 08C070 800F2BC0 8042D68E */  lb    $v0, -0x2972($v0)
/* 08C074 800F2BC4 1040000C */  beqz  $v0, .L800F2BF8
/* 08C078 800F2BC8 24034000 */   addiu $v1, $zero, 0x4000
/* 08C07C 800F2BCC 0803CAFE */  j     .L800F2BF8
/* 08C080 800F2BD0 24034002 */   addiu $v1, $zero, 0x4002

/* 08C084 800F2BD4 3C028011 */  lui   $v0, 0x8011
/* 08C088 800F2BD8 8042D68E */  lb    $v0, -0x2972($v0)
/* 08C08C 800F2BDC 10400006 */  beqz  $v0, .L800F2BF8
/* 08C090 800F2BE0 24034000 */   addiu $v1, $zero, 0x4000
/* 08C094 800F2BE4 0803CAFE */  j     .L800F2BF8
/* 08C098 800F2BE8 24034001 */   addiu $v1, $zero, 0x4001

/* 08C09C 800F2BEC 0803CAFE */  j     .L800F2BF8
/* 08C0A0 800F2BF0 24034000 */   addiu $v1, $zero, 0x4000

.L800F2BF4:
/* 08C0A4 800F2BF4 0000182D */  daddu $v1, $zero, $zero
.L800F2BF8:
/* 08C0A8 800F2BF8 3C028007 */  lui   $v0, 0x8007
/* 08C0AC 800F2BFC 8C42419C */  lw    $v0, 0x419c($v0)
/* 08C0B0 800F2C00 8C420010 */  lw    $v0, 0x10($v0)
/* 08C0B4 800F2C04 00431024 */  and   $v0, $v0, $v1
/* 08C0B8 800F2C08 10400013 */  beqz  $v0, .L800F2C58
/* 08C0BC 800F2C0C 00000000 */   nop   
/* 08C0C0 800F2C10 0C05272D */  jal   play_sound
/* 08C0C4 800F2C14 240400CA */   addiu $a0, $zero, 0xca
/* 08C0C8 800F2C18 3C028011 */  lui   $v0, 0x8011
/* 08C0CC 800F2C1C 8042D698 */  lb    $v0, -0x2968($v0)
/* 08C0D0 800F2C20 10400007 */  beqz  $v0, .L800F2C40
/* 08C0D4 800F2C24 00000000 */   nop   
/* 08C0D8 800F2C28 3C028011 */  lui   $v0, 0x8011
/* 08C0DC 800F2C2C 8042D68E */  lb    $v0, -0x2972($v0)
/* 08C0E0 800F2C30 14400286 */  bnez  $v0, .L800F364C
/* 08C0E4 800F2C34 2402FFF9 */   addiu $v0, $zero, -7
/* 08C0E8 800F2C38 0803CD93 */  j     .L800F364C
/* 08C0EC 800F2C3C 2402FFFD */   addiu $v0, $zero, -3

.L800F2C40:
/* 08C0F0 800F2C40 3C028011 */  lui   $v0, 0x8011
/* 08C0F4 800F2C44 8042D699 */  lb    $v0, -0x2967($v0)
/* 08C0F8 800F2C48 14400280 */  bnez  $v0, .L800F364C
/* 08C0FC 800F2C4C 24020064 */   addiu $v0, $zero, 0x64
/* 08C100 800F2C50 0803CD93 */  j     .L800F364C
/* 08C104 800F2C54 2402001E */   addiu $v0, $zero, 0x1e

.L800F2C58:
/* 08C108 800F2C58 3C028011 */  lui   $v0, 0x8011
/* 08C10C 800F2C5C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08C110 800F2C60 8C430318 */  lw    $v1, 0x318($v0)
/* 08C114 800F2C64 10600005 */  beqz  $v1, .L800F2C7C
/* 08C118 800F2C68 24020001 */   addiu $v0, $zero, 1
/* 08C11C 800F2C6C 10620005 */  beq   $v1, $v0, .L800F2C84
/* 08C120 800F2C70 0000182D */   daddu $v1, $zero, $zero
/* 08C124 800F2C74 0803CB22 */  j     .L800F2C88
/* 08C128 800F2C78 00000000 */   nop   

.L800F2C7C:
/* 08C12C 800F2C7C 0803CB22 */  j     .L800F2C88
/* 08C130 800F2C80 24030001 */   addiu $v1, $zero, 1

.L800F2C84:
/* 08C134 800F2C84 24030002 */  addiu $v1, $zero, 2
.L800F2C88:
/* 08C138 800F2C88 3C028011 */  lui   $v0, 0x8011
/* 08C13C 800F2C8C 8042D68E */  lb    $v0, -0x2972($v0)
/* 08C140 800F2C90 10400270 */  beqz  $v0, .L800F3654
/* 08C144 800F2C94 00000000 */   nop   
/* 08C148 800F2C98 3C028007 */  lui   $v0, 0x8007
/* 08C14C 800F2C9C 8C42419C */  lw    $v0, 0x419c($v0)
/* 08C150 800F2CA0 8C420010 */  lw    $v0, 0x10($v0)
/* 08C154 800F2CA4 00431024 */  and   $v0, $v0, $v1
/* 08C158 800F2CA8 1040026A */  beqz  $v0, .L800F3654
/* 08C15C 800F2CAC 00000000 */   nop   
/* 08C160 800F2CB0 0C05272D */  jal   play_sound
/* 08C164 800F2CB4 240400CA */   addiu $a0, $zero, 0xca
/* 08C168 800F2CB8 0803CD93 */  j     .L800F364C
/* 08C16C 800F2CBC 2402FFFA */   addiu $v0, $zero, -6

/* 08C170 800F2CC0 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C174 800F2CC4 00A0302D */  daddu $a2, $a1, $zero
/* 08C178 800F2CC8 3C048011 */  lui   $a0, 0x8011
/* 08C17C 800F2CCC 8C84D65C */  lw    $a0, -0x29a4($a0)
/* 08C180 800F2CD0 0C0513BF */  jal   func_80144EFC
/* 08C184 800F2CD4 00A0382D */   daddu $a3, $a1, $zero
/* 08C188 800F2CD8 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C18C 800F2CDC 00A0302D */  daddu $a2, $a1, $zero
/* 08C190 800F2CE0 3C048011 */  lui   $a0, 0x8011
/* 08C194 800F2CE4 8C84D678 */  lw    $a0, -0x2988($a0)
/* 08C198 800F2CE8 0C0513BF */  jal   func_80144EFC
/* 08C19C 800F2CEC 00A0382D */   daddu $a3, $a1, $zero
/* 08C1A0 800F2CF0 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C1A4 800F2CF4 00A0302D */  daddu $a2, $a1, $zero
/* 08C1A8 800F2CF8 3C108011 */  lui   $s0, 0x8011
/* 08C1AC 800F2CFC 2610D66C */  addiu $s0, $s0, -0x2994
/* 08C1B0 800F2D00 8E040000 */  lw    $a0, ($s0)
/* 08C1B4 800F2D04 0C0513BF */  jal   func_80144EFC
/* 08C1B8 800F2D08 00A0382D */   daddu $a3, $a1, $zero
/* 08C1BC 800F2D0C 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C1C0 800F2D10 00A0302D */  daddu $a2, $a1, $zero
/* 08C1C4 800F2D14 3C048011 */  lui   $a0, 0x8011
/* 08C1C8 800F2D18 8C84D670 */  lw    $a0, -0x2990($a0)
/* 08C1CC 800F2D1C 0C0513BF */  jal   func_80144EFC
/* 08C1D0 800F2D20 00A0382D */   daddu $a3, $a1, $zero
/* 08C1D4 800F2D24 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C1D8 800F2D28 00A0302D */  daddu $a2, $a1, $zero
/* 08C1DC 800F2D2C 3C048011 */  lui   $a0, 0x8011
/* 08C1E0 800F2D30 8C84D674 */  lw    $a0, -0x298c($a0)
/* 08C1E4 800F2D34 0C0513BF */  jal   func_80144EFC
/* 08C1E8 800F2D38 00A0382D */   daddu $a3, $a1, $zero
/* 08C1EC 800F2D3C 8E040000 */  lw    $a0, ($s0)
/* 08C1F0 800F2D40 3C058010 */  lui   $a1, 0x8010
/* 08C1F4 800F2D44 24A54A00 */  addiu $a1, $a1, 0x4a00
/* 08C1F8 800F2D48 0C0511FF */  jal   set_menu_icon_script
/* 08C1FC 800F2D4C 00000000 */   nop   
/* 08C200 800F2D50 3C108011 */  lui   $s0, 0x8011
/* 08C204 800F2D54 2610D69C */  addiu $s0, $s0, -0x2964
/* 08C208 800F2D58 8E020000 */  lw    $v0, ($s0)
/* 08C20C 800F2D5C 8C430318 */  lw    $v1, 0x318($v0)
/* 08C210 800F2D60 24020003 */  addiu $v0, $zero, 3
/* 08C214 800F2D64 1462000C */  bne   $v1, $v0, .L800F2D98
/* 08C218 800F2D68 240500A0 */   addiu $a1, $zero, 0xa0
/* 08C21C 800F2D6C 00A0302D */  daddu $a2, $a1, $zero
/* 08C220 800F2D70 3C048011 */  lui   $a0, 0x8011
/* 08C224 800F2D74 8C84D660 */  lw    $a0, -0x29a0($a0)
/* 08C228 800F2D78 0C0513BF */  jal   func_80144EFC
/* 08C22C 800F2D7C 00A0382D */   daddu $a3, $a1, $zero
/* 08C230 800F2D80 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C234 800F2D84 00A0302D */  daddu $a2, $a1, $zero
/* 08C238 800F2D88 3C048011 */  lui   $a0, 0x8011
/* 08C23C 800F2D8C 8C84D664 */  lw    $a0, -0x299c($a0)
/* 08C240 800F2D90 0C0513BF */  jal   func_80144EFC
/* 08C244 800F2D94 00A0382D */   daddu $a3, $a1, $zero
.L800F2D98:
/* 08C248 800F2D98 8E020000 */  lw    $v0, ($s0)
/* 08C24C 800F2D9C 8C420318 */  lw    $v0, 0x318($v0)
/* 08C250 800F2DA0 24110004 */  addiu $s1, $zero, 4
/* 08C254 800F2DA4 1451000C */  bne   $v0, $s1, .L800F2DD8
/* 08C258 800F2DA8 240500A0 */   addiu $a1, $zero, 0xa0
/* 08C25C 800F2DAC 00A0302D */  daddu $a2, $a1, $zero
/* 08C260 800F2DB0 3C048011 */  lui   $a0, 0x8011
/* 08C264 800F2DB4 8C84D660 */  lw    $a0, -0x29a0($a0)
/* 08C268 800F2DB8 0C0513BF */  jal   func_80144EFC
/* 08C26C 800F2DBC 00A0382D */   daddu $a3, $a1, $zero
/* 08C270 800F2DC0 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C274 800F2DC4 00A0302D */  daddu $a2, $a1, $zero
/* 08C278 800F2DC8 3C048011 */  lui   $a0, 0x8011
/* 08C27C 800F2DCC 8C84D664 */  lw    $a0, -0x299c($a0)
/* 08C280 800F2DD0 0C0513BF */  jal   func_80144EFC
/* 08C284 800F2DD4 00A0382D */   daddu $a3, $a1, $zero
.L800F2DD8:
/* 08C288 800F2DD8 8E020000 */  lw    $v0, ($s0)
/* 08C28C 800F2DDC 8C430318 */  lw    $v1, 0x318($v0)
/* 08C290 800F2DE0 24020001 */  addiu $v0, $zero, 1
/* 08C294 800F2DE4 10620003 */  beq   $v1, $v0, .L800F2DF4
/* 08C298 800F2DE8 00000000 */   nop   
/* 08C29C 800F2DEC 14710007 */  bne   $v1, $s1, .L800F2E0C
/* 08C2A0 800F2DF0 00000000 */   nop   
.L800F2DF4:
/* 08C2A4 800F2DF4 3C048011 */  lui   $a0, 0x8011
/* 08C2A8 800F2DF8 8C84D668 */  lw    $a0, -0x2998($a0)
/* 08C2AC 800F2DFC 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C2B0 800F2E00 00A0302D */  daddu $a2, $a1, $zero
/* 08C2B4 800F2E04 0C0513BF */  jal   func_80144EFC
/* 08C2B8 800F2E08 00A0382D */   daddu $a3, $a1, $zero
.L800F2E0C:
/* 08C2BC 800F2E0C 3C108011 */  lui   $s0, 0x8011
/* 08C2C0 800F2E10 2610D69C */  addiu $s0, $s0, -0x2964
/* 08C2C4 800F2E14 8E020000 */  lw    $v0, ($s0)
/* 08C2C8 800F2E18 8C430318 */  lw    $v1, 0x318($v0)
/* 08C2CC 800F2E1C 24020005 */  addiu $v0, $zero, 5
/* 08C2D0 800F2E20 14620006 */  bne   $v1, $v0, .L800F2E3C
/* 08C2D4 800F2E24 240500A0 */   addiu $a1, $zero, 0xa0
/* 08C2D8 800F2E28 3C048011 */  lui   $a0, 0x8011
/* 08C2DC 800F2E2C 8C84D660 */  lw    $a0, -0x29a0($a0)
/* 08C2E0 800F2E30 00A0302D */  daddu $a2, $a1, $zero
/* 08C2E4 800F2E34 0C0513BF */  jal   func_80144EFC
/* 08C2E8 800F2E38 00A0382D */   daddu $a3, $a1, $zero
.L800F2E3C:
/* 08C2EC 800F2E3C 3C048011 */  lui   $a0, 0x8011
/* 08C2F0 800F2E40 2484D648 */  addiu $a0, $a0, -0x29b8
/* 08C2F4 800F2E44 8C820000 */  lw    $v0, ($a0)
/* 08C2F8 800F2E48 2403000D */  addiu $v1, $zero, 0xd
/* 08C2FC 800F2E4C 3C018011 */  lui   $at, 0x8011
/* 08C300 800F2E50 A023D690 */  sb    $v1, -0x2970($at)
/* 08C304 800F2E54 94830002 */  lhu   $v1, 2($a0)
/* 08C308 800F2E58 8E040000 */  lw    $a0, ($s0)
/* 08C30C 800F2E5C 0803CC01 */  j     .L800F3004
/* 08C310 800F2E60 24420001 */   addiu $v0, $v0, 1

/* 08C314 800F2E64 3C038011 */  lui   $v1, 0x8011
/* 08C318 800F2E68 2463D648 */  addiu $v1, $v1, -0x29b8
/* 08C31C 800F2E6C 8C620000 */  lw    $v0, ($v1)
/* 08C320 800F2E70 94630002 */  lhu   $v1, 2($v1)
/* 08C324 800F2E74 3C048011 */  lui   $a0, 0x8011
/* 08C328 800F2E78 8C84D69C */  lw    $a0, -0x2964($a0)
/* 08C32C 800F2E7C 0803CC01 */  j     .L800F3004
/* 08C330 800F2E80 24420001 */   addiu $v0, $v0, 1

/* 08C334 800F2E84 3C028011 */  lui   $v0, 0x8011
/* 08C338 800F2E88 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08C33C 800F2E8C 8C430318 */  lw    $v1, 0x318($v0)
/* 08C340 800F2E90 2C62000E */  sltiu $v0, $v1, 0xe
/* 08C344 800F2E94 10400013 */  beqz  $v0, .L800F2EE4
/* 08C348 800F2E98 00031080 */   sll   $v0, $v1, 2
/* 08C34C 800F2E9C 3C018011 */  lui   $at, 0x8011
/* 08C350 800F2EA0 00220821 */  addu  $at, $at, $v0
/* 08C354 800F2EA4 8C22C6E8 */  lw    $v0, -0x3918($at)
/* 08C358 800F2EA8 00400008 */  jr    $v0
/* 08C35C 800F2EAC 00000000 */   nop   
/* 08C360 800F2EB0 2404000E */  addiu $a0, $zero, 0xe
/* 08C364 800F2EB4 0C051F9F */  jal   func_80147E7C
/* 08C368 800F2EB8 24050002 */   addiu $a1, $zero, 2
/* 08C36C 800F2EBC 0803CBB7 */  j     .L800F2EDC
/* 08C370 800F2EC0 24040013 */   addiu $a0, $zero, 0x13

/* 08C374 800F2EC4 2404000E */  addiu $a0, $zero, 0xe
/* 08C378 800F2EC8 0C051F9F */  jal   func_80147E7C
/* 08C37C 800F2ECC 24050002 */   addiu $a1, $zero, 2
/* 08C380 800F2ED0 0803CBB7 */  j     .L800F2EDC
/* 08C384 800F2ED4 24040013 */   addiu $a0, $zero, 0x13

/* 08C388 800F2ED8 2404000E */  addiu $a0, $zero, 0xe
.L800F2EDC:
/* 08C38C 800F2EDC 0C051F9F */  jal   func_80147E7C
/* 08C390 800F2EE0 24050002 */   addiu $a1, $zero, 2
.L800F2EE4:
/* 08C394 800F2EE4 0C03C54E */  jal   func_800F1538
/* 08C398 800F2EE8 00000000 */   nop   
/* 08C39C 800F2EEC 3C048011 */  lui   $a0, 0x8011
/* 08C3A0 800F2EF0 8C84D694 */  lw    $a0, -0x296c($a0)
/* 08C3A4 800F2EF4 0C048D70 */  jal   func_801235C0
/* 08C3A8 800F2EF8 00000000 */   nop   
/* 08C3AC 800F2EFC 3C048011 */  lui   $a0, 0x8011
/* 08C3B0 800F2F00 8C84D69C */  lw    $a0, -0x2964($a0)
/* 08C3B4 800F2F04 2403FFFB */  addiu $v1, $zero, -5
/* 08C3B8 800F2F08 3C018011 */  lui   $at, 0x8011
/* 08C3BC 800F2F0C AC23D640 */  sw    $v1, -0x29c0($at)
/* 08C3C0 800F2F10 0803CBDA */  j     .L800F2F68
/* 08C3C4 800F2F14 240200FF */   addiu $v0, $zero, 0xff

/* 08C3C8 800F2F18 3C048011 */  lui   $a0, 0x8011
/* 08C3CC 800F2F1C 8C84D694 */  lw    $a0, -0x296c($a0)
/* 08C3D0 800F2F20 0C048D70 */  jal   func_801235C0
/* 08C3D4 800F2F24 00000000 */   nop   
/* 08C3D8 800F2F28 3C048011 */  lui   $a0, 0x8011
/* 08C3DC 800F2F2C 8C84D69C */  lw    $a0, -0x2964($a0)
/* 08C3E0 800F2F30 2403FFFB */  addiu $v1, $zero, -5
/* 08C3E4 800F2F34 3C018011 */  lui   $at, 0x8011
/* 08C3E8 800F2F38 AC23D640 */  sw    $v1, -0x29c0($at)
/* 08C3EC 800F2F3C 0803CBDA */  j     .L800F2F68
/* 08C3F0 800F2F40 240200FF */   addiu $v0, $zero, 0xff

/* 08C3F4 800F2F44 240200FF */  addiu $v0, $zero, 0xff
/* 08C3F8 800F2F48 3C048011 */  lui   $a0, 0x8011
/* 08C3FC 800F2F4C 8C84D69C */  lw    $a0, -0x2964($a0)
/* 08C400 800F2F50 2403FFFE */  addiu $v1, $zero, -2
/* 08C404 800F2F54 0803CD99 */  j     .L800F3664
/* 08C408 800F2F58 A483032C */   sh    $v1, 0x32c($a0)

/* 08C40C 800F2F5C 240200FF */  addiu $v0, $zero, 0xff
/* 08C410 800F2F60 3C048011 */  lui   $a0, 0x8011
/* 08C414 800F2F64 8C84D69C */  lw    $a0, -0x2964($a0)
.L800F2F68:
/* 08C418 800F2F68 0040182D */  daddu $v1, $v0, $zero
/* 08C41C 800F2F6C 0803CD99 */  j     .L800F3664
/* 08C420 800F2F70 A483032C */   sh    $v1, 0x32c($a0)

/* 08C424 800F2F74 3C038011 */  lui   $v1, 0x8011
/* 08C428 800F2F78 2463D644 */  addiu $v1, $v1, -0x29bc
/* 08C42C 800F2F7C 8C620000 */  lw    $v0, ($v1)
/* 08C430 800F2F80 2442FFFF */  addiu $v0, $v0, -1
/* 08C434 800F2F84 144001B3 */  bnez  $v0, .L800F3654
/* 08C438 800F2F88 AC620000 */   sw    $v0, ($v1)
/* 08C43C 800F2F8C 3C048011 */  lui   $a0, 0x8011
/* 08C440 800F2F90 2484D648 */  addiu $a0, $a0, -0x29b8
/* 08C444 800F2F94 8C820000 */  lw    $v0, ($a0)
/* 08C448 800F2F98 2403000B */  addiu $v1, $zero, 0xb
/* 08C44C 800F2F9C 3C018011 */  lui   $at, 0x8011
/* 08C450 800F2FA0 AC23D640 */  sw    $v1, -0x29c0($at)
/* 08C454 800F2FA4 94830002 */  lhu   $v1, 2($a0)
/* 08C458 800F2FA8 3C048011 */  lui   $a0, 0x8011
/* 08C45C 800F2FAC 8C84D69C */  lw    $a0, -0x2964($a0)
/* 08C460 800F2FB0 0803CC01 */  j     .L800F3004
/* 08C464 800F2FB4 24420001 */   addiu $v0, $v0, 1

/* 08C468 800F2FB8 3C028011 */  lui   $v0, 0x8011
/* 08C46C 800F2FBC 2442D644 */  addiu $v0, $v0, -0x29bc
/* 08C470 800F2FC0 8C430000 */  lw    $v1, ($v0)
/* 08C474 800F2FC4 3C048011 */  lui   $a0, 0x8011
/* 08C478 800F2FC8 8084D692 */  lb    $a0, -0x296e($a0)
/* 08C47C 800F2FCC 24630001 */  addiu $v1, $v1, 1
/* 08C480 800F2FD0 AC430000 */  sw    $v1, ($v0)
/* 08C484 800F2FD4 0064182A */  slt   $v1, $v1, $a0
/* 08C488 800F2FD8 1460019E */  bnez  $v1, .L800F3654
/* 08C48C 800F2FDC 24030001 */   addiu $v1, $zero, 1
/* 08C490 800F2FE0 3C048011 */  lui   $a0, 0x8011
/* 08C494 800F2FE4 2484D648 */  addiu $a0, $a0, -0x29b8
/* 08C498 800F2FE8 8C820000 */  lw    $v0, ($a0)
/* 08C49C 800F2FEC 3C018011 */  lui   $at, 0x8011
/* 08C4A0 800F2FF0 AC23D640 */  sw    $v1, -0x29c0($at)
/* 08C4A4 800F2FF4 00431021 */  addu  $v0, $v0, $v1
/* 08C4A8 800F2FF8 94830002 */  lhu   $v1, 2($a0)
/* 08C4AC 800F2FFC 3C048011 */  lui   $a0, 0x8011
/* 08C4B0 800F3000 8C84D69C */  lw    $a0, -0x2964($a0)
.L800F3004:
/* 08C4B4 800F3004 24630001 */  addiu $v1, $v1, 1
/* 08C4B8 800F3008 0803CD99 */  j     .L800F3664
/* 08C4BC 800F300C A483032C */   sh    $v1, 0x32c($a0)

/* 08C4C0 800F3010 0000102D */  daddu $v0, $zero, $zero
/* 08C4C4 800F3014 3C048011 */  lui   $a0, 0x8011
/* 08C4C8 800F3018 8C84D69C */  lw    $a0, -0x2964($a0)
/* 08C4CC 800F301C 2403001F */  addiu $v1, $zero, 0x1f
/* 08C4D0 800F3020 3C018011 */  lui   $at, 0x8011
/* 08C4D4 800F3024 AC23D640 */  sw    $v1, -0x29c0($at)
/* 08C4D8 800F3028 2403FFFF */  addiu $v1, $zero, -1
/* 08C4DC 800F302C 0803CD99 */  j     .L800F3664
/* 08C4E0 800F3030 A483032C */   sh    $v1, 0x32c($a0)

/* 08C4E4 800F3034 2404000E */  addiu $a0, $zero, 0xe
/* 08C4E8 800F3038 0C051F9F */  jal   func_80147E7C
/* 08C4EC 800F303C 24050002 */   addiu $a1, $zero, 2
/* 08C4F0 800F3040 24040013 */  addiu $a0, $zero, 0x13
/* 08C4F4 800F3044 0C051F9F */  jal   func_80147E7C
/* 08C4F8 800F3048 24050002 */   addiu $a1, $zero, 2
/* 08C4FC 800F304C 3C028011 */  lui   $v0, 0x8011
/* 08C500 800F3050 8042D68E */  lb    $v0, -0x2972($v0)
/* 08C504 800F3054 10400003 */  beqz  $v0, .L800F3064
/* 08C508 800F3058 24040015 */   addiu $a0, $zero, 0x15
/* 08C50C 800F305C 0C051F9F */  jal   func_80147E7C
/* 08C510 800F3060 24050002 */   addiu $a1, $zero, 2
.L800F3064:
/* 08C514 800F3064 3C04001D */  lui   $a0, 0x1d
/* 08C518 800F3068 3484006B */  ori   $a0, $a0, 0x6b
/* 08C51C 800F306C 0C04991D */  jal   get_string_width
/* 08C520 800F3070 0000282D */   daddu $a1, $zero, $zero
/* 08C524 800F3074 24470017 */  addiu $a3, $v0, 0x17
/* 08C528 800F3078 24040009 */  addiu $a0, $zero, 9
/* 08C52C 800F307C 00072FC2 */  srl   $a1, $a3, 0x1f
/* 08C530 800F3080 00E52821 */  addu  $a1, $a3, $a1
/* 08C534 800F3084 00052843 */  sra   $a1, $a1, 1
/* 08C538 800F3088 240200A0 */  addiu $v0, $zero, 0xa0
/* 08C53C 800F308C 00452823 */  subu  $a1, $v0, $a1
/* 08C540 800F3090 24060050 */  addiu $a2, $zero, 0x50
/* 08C544 800F3094 24020028 */  addiu $v0, $zero, 0x28
/* 08C548 800F3098 AFA20010 */  sw    $v0, 0x10($sp)
/* 08C54C 800F309C 24020014 */  addiu $v0, $zero, 0x14
/* 08C550 800F30A0 AFA20014 */  sw    $v0, 0x14($sp)
/* 08C554 800F30A4 3C02800F */  lui   $v0, 0x800f
/* 08C558 800F30A8 24424CF0 */  addiu $v0, $v0, 0x4cf0
/* 08C55C 800F30AC AFA20018 */  sw    $v0, 0x18($sp)
/* 08C560 800F30B0 2402FFFF */  addiu $v0, $zero, -1
/* 08C564 800F30B4 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08C568 800F30B8 0C051F32 */  jal   func_80147CC8
/* 08C56C 800F30BC AFA20020 */   sw    $v0, 0x20($sp)
/* 08C570 800F30C0 24040009 */  addiu $a0, $zero, 9
/* 08C574 800F30C4 0C051F9F */  jal   func_80147E7C
/* 08C578 800F30C8 24050001 */   addiu $a1, $zero, 1
/* 08C57C 800F30CC 2403003C */  addiu $v1, $zero, 0x3c
/* 08C580 800F30D0 3C018011 */  lui   $at, 0x8011
/* 08C584 800F30D4 AC23D644 */  sw    $v1, -0x29bc($at)
/* 08C588 800F30D8 24030020 */  addiu $v1, $zero, 0x20
/* 08C58C 800F30DC 3C018011 */  lui   $at, 0x8011
/* 08C590 800F30E0 AC23D640 */  sw    $v1, -0x29c0($at)
/* 08C594 800F30E4 0803CD99 */  j     .L800F3664
/* 08C598 800F30E8 0000102D */   daddu $v0, $zero, $zero

/* 08C59C 800F30EC 3C028007 */  lui   $v0, 0x8007
/* 08C5A0 800F30F0 8C42419C */  lw    $v0, 0x419c($v0)
/* 08C5A4 800F30F4 8C420010 */  lw    $v0, 0x10($v0)
/* 08C5A8 800F30F8 3042C001 */  andi  $v0, $v0, 0xc001
/* 08C5AC 800F30FC 10400003 */  beqz  $v0, .L800F310C
/* 08C5B0 800F3100 00000000 */   nop   
/* 08C5B4 800F3104 3C018011 */  lui   $at, 0x8011
/* 08C5B8 800F3108 AC20D644 */  sw    $zero, -0x29bc($at)
.L800F310C:
/* 08C5BC 800F310C 3C038011 */  lui   $v1, 0x8011
/* 08C5C0 800F3110 2463D644 */  addiu $v1, $v1, -0x29bc
/* 08C5C4 800F3114 8C620000 */  lw    $v0, ($v1)
/* 08C5C8 800F3118 10400004 */  beqz  $v0, .L800F312C
/* 08C5CC 800F311C 2442FFFF */   addiu $v0, $v0, -1
/* 08C5D0 800F3120 AC620000 */  sw    $v0, ($v1)
/* 08C5D4 800F3124 0803CD99 */  j     .L800F3664
/* 08C5D8 800F3128 0000102D */   daddu $v0, $zero, $zero

.L800F312C:
/* 08C5DC 800F312C 24040009 */  addiu $a0, $zero, 9
/* 08C5E0 800F3130 0C051F9F */  jal   func_80147E7C
/* 08C5E4 800F3134 24050002 */   addiu $a1, $zero, 2
/* 08C5E8 800F3138 2404000E */  addiu $a0, $zero, 0xe
/* 08C5EC 800F313C 0C051F9F */  jal   func_80147E7C
/* 08C5F0 800F3140 24050001 */   addiu $a1, $zero, 1
/* 08C5F4 800F3144 24040013 */  addiu $a0, $zero, 0x13
/* 08C5F8 800F3148 0C051F9F */  jal   func_80147E7C
/* 08C5FC 800F314C 24050001 */   addiu $a1, $zero, 1
/* 08C600 800F3150 3C028011 */  lui   $v0, 0x8011
/* 08C604 800F3154 8042D68E */  lb    $v0, -0x2972($v0)
/* 08C608 800F3158 10400003 */  beqz  $v0, .L800F3168
/* 08C60C 800F315C 24040015 */   addiu $a0, $zero, 0x15
/* 08C610 800F3160 0C051F9F */  jal   func_80147E7C
/* 08C614 800F3164 24050001 */   addiu $a1, $zero, 1
.L800F3168:
/* 08C618 800F3168 3C038011 */  lui   $v1, 0x8011
/* 08C61C 800F316C 8C63D69C */  lw    $v1, -0x2964($v1)
/* 08C620 800F3170 24020001 */  addiu $v0, $zero, 1
/* 08C624 800F3174 3C018011 */  lui   $at, 0x8011
/* 08C628 800F3178 AC22D640 */  sw    $v0, -0x29c0($at)
/* 08C62C 800F317C 0803CD95 */  j     .L800F3654
/* 08C630 800F3180 A460032C */   sh    $zero, 0x32c($v1)

/* 08C634 800F3184 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C638 800F3188 00A0302D */  daddu $a2, $a1, $zero
/* 08C63C 800F318C 3C048011 */  lui   $a0, 0x8011
/* 08C640 800F3190 8C84D65C */  lw    $a0, -0x29a4($a0)
/* 08C644 800F3194 0C0513BF */  jal   func_80144EFC
/* 08C648 800F3198 00A0382D */   daddu $a3, $a1, $zero
/* 08C64C 800F319C 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C650 800F31A0 00A0302D */  daddu $a2, $a1, $zero
/* 08C654 800F31A4 3C048011 */  lui   $a0, 0x8011
/* 08C658 800F31A8 8C84D678 */  lw    $a0, -0x2988($a0)
/* 08C65C 800F31AC 0C0513BF */  jal   func_80144EFC
/* 08C660 800F31B0 00A0382D */   daddu $a3, $a1, $zero
/* 08C664 800F31B4 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C668 800F31B8 00A0302D */  daddu $a2, $a1, $zero
/* 08C66C 800F31BC 3C108011 */  lui   $s0, 0x8011
/* 08C670 800F31C0 2610D66C */  addiu $s0, $s0, -0x2994
/* 08C674 800F31C4 8E040000 */  lw    $a0, ($s0)
/* 08C678 800F31C8 0C0513BF */  jal   func_80144EFC
/* 08C67C 800F31CC 00A0382D */   daddu $a3, $a1, $zero
/* 08C680 800F31D0 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C684 800F31D4 00A0302D */  daddu $a2, $a1, $zero
/* 08C688 800F31D8 3C048011 */  lui   $a0, 0x8011
/* 08C68C 800F31DC 8C84D670 */  lw    $a0, -0x2990($a0)
/* 08C690 800F31E0 0C0513BF */  jal   func_80144EFC
/* 08C694 800F31E4 00A0382D */   daddu $a3, $a1, $zero
/* 08C698 800F31E8 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C69C 800F31EC 00A0302D */  daddu $a2, $a1, $zero
/* 08C6A0 800F31F0 3C048011 */  lui   $a0, 0x8011
/* 08C6A4 800F31F4 8C84D674 */  lw    $a0, -0x298c($a0)
/* 08C6A8 800F31F8 0C0513BF */  jal   func_80144EFC
/* 08C6AC 800F31FC 00A0382D */   daddu $a3, $a1, $zero
/* 08C6B0 800F3200 8E040000 */  lw    $a0, ($s0)
/* 08C6B4 800F3204 3C058010 */  lui   $a1, 0x8010
/* 08C6B8 800F3208 24A54A00 */  addiu $a1, $a1, 0x4a00
/* 08C6BC 800F320C 0C0511FF */  jal   set_menu_icon_script
/* 08C6C0 800F3210 00000000 */   nop   
/* 08C6C4 800F3214 3C108011 */  lui   $s0, 0x8011
/* 08C6C8 800F3218 2610D69C */  addiu $s0, $s0, -0x2964
/* 08C6CC 800F321C 8E020000 */  lw    $v0, ($s0)
/* 08C6D0 800F3220 8C430318 */  lw    $v1, 0x318($v0)
/* 08C6D4 800F3224 24020003 */  addiu $v0, $zero, 3
/* 08C6D8 800F3228 1462000C */  bne   $v1, $v0, .L800F325C
/* 08C6DC 800F322C 240500A0 */   addiu $a1, $zero, 0xa0
/* 08C6E0 800F3230 00A0302D */  daddu $a2, $a1, $zero
/* 08C6E4 800F3234 3C048011 */  lui   $a0, 0x8011
/* 08C6E8 800F3238 8C84D660 */  lw    $a0, -0x29a0($a0)
/* 08C6EC 800F323C 0C0513BF */  jal   func_80144EFC
/* 08C6F0 800F3240 00A0382D */   daddu $a3, $a1, $zero
/* 08C6F4 800F3244 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C6F8 800F3248 00A0302D */  daddu $a2, $a1, $zero
/* 08C6FC 800F324C 3C048011 */  lui   $a0, 0x8011
/* 08C700 800F3250 8C84D664 */  lw    $a0, -0x299c($a0)
/* 08C704 800F3254 0C0513BF */  jal   func_80144EFC
/* 08C708 800F3258 00A0382D */   daddu $a3, $a1, $zero
.L800F325C:
/* 08C70C 800F325C 8E020000 */  lw    $v0, ($s0)
/* 08C710 800F3260 8C420318 */  lw    $v0, 0x318($v0)
/* 08C714 800F3264 24110004 */  addiu $s1, $zero, 4
/* 08C718 800F3268 1451000C */  bne   $v0, $s1, .L800F329C
/* 08C71C 800F326C 240500A0 */   addiu $a1, $zero, 0xa0
/* 08C720 800F3270 00A0302D */  daddu $a2, $a1, $zero
/* 08C724 800F3274 3C048011 */  lui   $a0, 0x8011
/* 08C728 800F3278 8C84D660 */  lw    $a0, -0x29a0($a0)
/* 08C72C 800F327C 0C0513BF */  jal   func_80144EFC
/* 08C730 800F3280 00A0382D */   daddu $a3, $a1, $zero
/* 08C734 800F3284 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C738 800F3288 00A0302D */  daddu $a2, $a1, $zero
/* 08C73C 800F328C 3C048011 */  lui   $a0, 0x8011
/* 08C740 800F3290 8C84D664 */  lw    $a0, -0x299c($a0)
/* 08C744 800F3294 0C0513BF */  jal   func_80144EFC
/* 08C748 800F3298 00A0382D */   daddu $a3, $a1, $zero
.L800F329C:
/* 08C74C 800F329C 8E020000 */  lw    $v0, ($s0)
/* 08C750 800F32A0 8C430318 */  lw    $v1, 0x318($v0)
/* 08C754 800F32A4 24020001 */  addiu $v0, $zero, 1
/* 08C758 800F32A8 10620003 */  beq   $v1, $v0, .L800F32B8
/* 08C75C 800F32AC 00000000 */   nop   
/* 08C760 800F32B0 14710007 */  bne   $v1, $s1, .L800F32D0
/* 08C764 800F32B4 00000000 */   nop   
.L800F32B8:
/* 08C768 800F32B8 3C048011 */  lui   $a0, 0x8011
/* 08C76C 800F32BC 8C84D668 */  lw    $a0, -0x2998($a0)
/* 08C770 800F32C0 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C774 800F32C4 00A0302D */  daddu $a2, $a1, $zero
/* 08C778 800F32C8 0C0513BF */  jal   func_80144EFC
/* 08C77C 800F32CC 00A0382D */   daddu $a3, $a1, $zero
.L800F32D0:
/* 08C780 800F32D0 3C108011 */  lui   $s0, 0x8011
/* 08C784 800F32D4 2610D69C */  addiu $s0, $s0, -0x2964
/* 08C788 800F32D8 8E020000 */  lw    $v0, ($s0)
/* 08C78C 800F32DC 8C430318 */  lw    $v1, 0x318($v0)
/* 08C790 800F32E0 24020005 */  addiu $v0, $zero, 5
/* 08C794 800F32E4 14620006 */  bne   $v1, $v0, .L800F3300
/* 08C798 800F32E8 240500A0 */   addiu $a1, $zero, 0xa0
/* 08C79C 800F32EC 3C048011 */  lui   $a0, 0x8011
/* 08C7A0 800F32F0 8C84D660 */  lw    $a0, -0x29a0($a0)
/* 08C7A4 800F32F4 00A0302D */  daddu $a2, $a1, $zero
/* 08C7A8 800F32F8 0C0513BF */  jal   func_80144EFC
/* 08C7AC 800F32FC 00A0382D */   daddu $a3, $a1, $zero
.L800F3300:
/* 08C7B0 800F3300 8E020000 */  lw    $v0, ($s0)
/* 08C7B4 800F3304 8C430318 */  lw    $v1, 0x318($v0)
/* 08C7B8 800F3308 2C62000E */  sltiu $v0, $v1, 0xe
/* 08C7BC 800F330C 10400013 */  beqz  $v0, .L800F335C
/* 08C7C0 800F3310 00031080 */   sll   $v0, $v1, 2
/* 08C7C4 800F3314 3C018011 */  lui   $at, 0x8011
/* 08C7C8 800F3318 00220821 */  addu  $at, $at, $v0
/* 08C7CC 800F331C 8C22C720 */  lw    $v0, -0x38e0($at)
/* 08C7D0 800F3320 00400008 */  jr    $v0
/* 08C7D4 800F3324 00000000 */   nop   
/* 08C7D8 800F3328 2404000E */  addiu $a0, $zero, 0xe
/* 08C7DC 800F332C 0C051F9F */  jal   func_80147E7C
/* 08C7E0 800F3330 24050002 */   addiu $a1, $zero, 2
/* 08C7E4 800F3334 0803CCD5 */  j     .L800F3354
/* 08C7E8 800F3338 24040013 */   addiu $a0, $zero, 0x13

/* 08C7EC 800F333C 2404000E */  addiu $a0, $zero, 0xe
/* 08C7F0 800F3340 0C051F9F */  jal   func_80147E7C
/* 08C7F4 800F3344 24050002 */   addiu $a1, $zero, 2
/* 08C7F8 800F3348 0803CCD5 */  j     .L800F3354
/* 08C7FC 800F334C 24040013 */   addiu $a0, $zero, 0x13

/* 08C800 800F3350 2404000E */  addiu $a0, $zero, 0xe
.L800F3354:
/* 08C804 800F3354 0C051F9F */  jal   func_80147E7C
/* 08C808 800F3358 24050002 */   addiu $a1, $zero, 2
.L800F335C:
/* 08C80C 800F335C 3C04001D */  lui   $a0, 0x1d
/* 08C810 800F3360 3C038011 */  lui   $v1, 0x8011
/* 08C814 800F3364 8063D699 */  lb    $v1, -0x2967($v1)
/* 08C818 800F3368 2402000D */  addiu $v0, $zero, 0xd
/* 08C81C 800F336C 3C018011 */  lui   $at, 0x8011
/* 08C820 800F3370 A022D690 */  sb    $v0, -0x2970($at)
/* 08C824 800F3374 24020001 */  addiu $v0, $zero, 1
/* 08C828 800F3378 14620003 */  bne   $v1, $v0, .L800F3388
/* 08C82C 800F337C 34840069 */   ori   $a0, $a0, 0x69
/* 08C830 800F3380 3C04001D */  lui   $a0, 0x1d
/* 08C834 800F3384 34840068 */  ori   $a0, $a0, 0x68
.L800F3388:
/* 08C838 800F3388 0C04991D */  jal   get_string_width
/* 08C83C 800F338C 0000282D */   daddu $a1, $zero, $zero
/* 08C840 800F3390 24470017 */  addiu $a3, $v0, 0x17
/* 08C844 800F3394 24040015 */  addiu $a0, $zero, 0x15
/* 08C848 800F3398 00072FC2 */  srl   $a1, $a3, 0x1f
/* 08C84C 800F339C 00E52821 */  addu  $a1, $a3, $a1
/* 08C850 800F33A0 00052843 */  sra   $a1, $a1, 1
/* 08C854 800F33A4 240200A0 */  addiu $v0, $zero, 0xa0
/* 08C858 800F33A8 00452823 */  subu  $a1, $v0, $a1
/* 08C85C 800F33AC 2406004C */  addiu $a2, $zero, 0x4c
/* 08C860 800F33B0 24020020 */  addiu $v0, $zero, 0x20
/* 08C864 800F33B4 AFA20010 */  sw    $v0, 0x10($sp)
/* 08C868 800F33B8 24020013 */  addiu $v0, $zero, 0x13
/* 08C86C 800F33BC AFA20014 */  sw    $v0, 0x14($sp)
/* 08C870 800F33C0 3C02800F */  lui   $v0, 0x800f
/* 08C874 800F33C4 24424C1C */  addiu $v0, $v0, 0x4c1c
/* 08C878 800F33C8 AFA20018 */  sw    $v0, 0x18($sp)
/* 08C87C 800F33CC 2402FFFF */  addiu $v0, $zero, -1
/* 08C880 800F33D0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 08C884 800F33D4 0C051F32 */  jal   func_80147CC8
/* 08C888 800F33D8 AFA20020 */   sw    $v0, 0x20($sp)
/* 08C88C 800F33DC 24040015 */  addiu $a0, $zero, 0x15
/* 08C890 800F33E0 0C051F9F */  jal   func_80147E7C
/* 08C894 800F33E4 24050001 */   addiu $a1, $zero, 1
/* 08C898 800F33E8 3C04001E */  lui   $a0, 0x1e
/* 08C89C 800F33EC 3C058011 */  lui   $a1, 0x8011
/* 08C8A0 800F33F0 24A5D6A4 */  addiu $a1, $a1, -0x295c
/* 08C8A4 800F33F4 0C049640 */  jal   load_string
/* 08C8A8 800F33F8 3484001D */   ori   $a0, $a0, 0x1d
/* 08C8AC 800F33FC 0040202D */  daddu $a0, $v0, $zero
/* 08C8B0 800F3400 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C8B4 800F3404 3C018011 */  lui   $at, 0x8011
/* 08C8B8 800F3408 AC24D6A0 */  sw    $a0, -0x2960($at)
/* 08C8BC 800F340C 0C0496AE */  jal   clamp_printer_coords
/* 08C8C0 800F3410 24060090 */   addiu $a2, $zero, 0x90
/* 08C8C4 800F3414 0803CD93 */  j     .L800F364C
/* 08C8C8 800F3418 24020065 */   addiu $v0, $zero, 0x65

/* 08C8CC 800F341C 3C108011 */  lui   $s0, 0x8011
/* 08C8D0 800F3420 8E10D6A4 */  lw    $s0, -0x295c($s0)
/* 08C8D4 800F3424 24020001 */  addiu $v0, $zero, 1
/* 08C8D8 800F3428 1602008A */  bne   $s0, $v0, .L800F3654
/* 08C8DC 800F342C 24040015 */   addiu $a0, $zero, 0x15
/* 08C8E0 800F3430 0C051F9F */  jal   func_80147E7C
/* 08C8E4 800F3434 24050002 */   addiu $a1, $zero, 2
/* 08C8E8 800F3438 3C028011 */  lui   $v0, 0x8011
/* 08C8EC 800F343C 8C42D6A0 */  lw    $v0, -0x2960($v0)
/* 08C8F0 800F3440 904204E8 */  lbu   $v0, 0x4e8($v0)
/* 08C8F4 800F3444 50400081 */  beql  $v0, $zero, .L800F364C
/* 08C8F8 800F3448 24020066 */   addiu $v0, $zero, 0x66
/* 08C8FC 800F344C 1050007F */  beq   $v0, $s0, .L800F364C
/* 08C900 800F3450 24020067 */   addiu $v0, $zero, 0x67
/* 08C904 800F3454 0803CD95 */  j     .L800F3654
/* 08C908 800F3458 00000000 */   nop   

/* 08C90C 800F345C 0803CD93 */  j     .L800F364C
/* 08C910 800F3460 2402FFFD */   addiu $v0, $zero, -3

/* 08C914 800F3464 240500FF */  addiu $a1, $zero, 0xff
/* 08C918 800F3468 00A0302D */  daddu $a2, $a1, $zero
/* 08C91C 800F346C 3C048011 */  lui   $a0, 0x8011
/* 08C920 800F3470 8C84D65C */  lw    $a0, -0x29a4($a0)
/* 08C924 800F3474 0C0513BF */  jal   func_80144EFC
/* 08C928 800F3478 00A0382D */   daddu $a3, $a1, $zero
/* 08C92C 800F347C 240500FF */  addiu $a1, $zero, 0xff
/* 08C930 800F3480 00A0302D */  daddu $a2, $a1, $zero
/* 08C934 800F3484 3C048011 */  lui   $a0, 0x8011
/* 08C938 800F3488 8C84D678 */  lw    $a0, -0x2988($a0)
/* 08C93C 800F348C 0C0513BF */  jal   func_80144EFC
/* 08C940 800F3490 00A0382D */   daddu $a3, $a1, $zero
/* 08C944 800F3494 240500FF */  addiu $a1, $zero, 0xff
/* 08C948 800F3498 00A0302D */  daddu $a2, $a1, $zero
/* 08C94C 800F349C 3C048011 */  lui   $a0, 0x8011
/* 08C950 800F34A0 8C84D66C */  lw    $a0, -0x2994($a0)
/* 08C954 800F34A4 0C0513BF */  jal   func_80144EFC
/* 08C958 800F34A8 00A0382D */   daddu $a3, $a1, $zero
/* 08C95C 800F34AC 240500FF */  addiu $a1, $zero, 0xff
/* 08C960 800F34B0 00A0302D */  daddu $a2, $a1, $zero
/* 08C964 800F34B4 3C048011 */  lui   $a0, 0x8011
/* 08C968 800F34B8 8C84D670 */  lw    $a0, -0x2990($a0)
/* 08C96C 800F34BC 0C0513BF */  jal   func_80144EFC
/* 08C970 800F34C0 00A0382D */   daddu $a3, $a1, $zero
/* 08C974 800F34C4 240500FF */  addiu $a1, $zero, 0xff
/* 08C978 800F34C8 00A0302D */  daddu $a2, $a1, $zero
/* 08C97C 800F34CC 3C048011 */  lui   $a0, 0x8011
/* 08C980 800F34D0 8C84D674 */  lw    $a0, -0x298c($a0)
/* 08C984 800F34D4 0C0513BF */  jal   func_80144EFC
/* 08C988 800F34D8 00A0382D */   daddu $a3, $a1, $zero
/* 08C98C 800F34DC 3C108011 */  lui   $s0, 0x8011
/* 08C990 800F34E0 2610D69C */  addiu $s0, $s0, -0x2964
/* 08C994 800F34E4 8E020000 */  lw    $v0, ($s0)
/* 08C998 800F34E8 8C430318 */  lw    $v1, 0x318($v0)
/* 08C99C 800F34EC 24020003 */  addiu $v0, $zero, 3
/* 08C9A0 800F34F0 1462000C */  bne   $v1, $v0, .L800F3524
/* 08C9A4 800F34F4 240500A0 */   addiu $a1, $zero, 0xa0
/* 08C9A8 800F34F8 00A0302D */  daddu $a2, $a1, $zero
/* 08C9AC 800F34FC 3C048011 */  lui   $a0, 0x8011
/* 08C9B0 800F3500 8C84D660 */  lw    $a0, -0x29a0($a0)
/* 08C9B4 800F3504 0C0513BF */  jal   func_80144EFC
/* 08C9B8 800F3508 00A0382D */   daddu $a3, $a1, $zero
/* 08C9BC 800F350C 240500A0 */  addiu $a1, $zero, 0xa0
/* 08C9C0 800F3510 00A0302D */  daddu $a2, $a1, $zero
/* 08C9C4 800F3514 3C048011 */  lui   $a0, 0x8011
/* 08C9C8 800F3518 8C84D664 */  lw    $a0, -0x299c($a0)
/* 08C9CC 800F351C 0C0513BF */  jal   func_80144EFC
/* 08C9D0 800F3520 00A0382D */   daddu $a3, $a1, $zero
.L800F3524:
/* 08C9D4 800F3524 8E020000 */  lw    $v0, ($s0)
/* 08C9D8 800F3528 8C420318 */  lw    $v0, 0x318($v0)
/* 08C9DC 800F352C 24110004 */  addiu $s1, $zero, 4
/* 08C9E0 800F3530 1451000C */  bne   $v0, $s1, .L800F3564
/* 08C9E4 800F3534 240500A0 */   addiu $a1, $zero, 0xa0
/* 08C9E8 800F3538 00A0302D */  daddu $a2, $a1, $zero
/* 08C9EC 800F353C 3C048011 */  lui   $a0, 0x8011
/* 08C9F0 800F3540 8C84D660 */  lw    $a0, -0x29a0($a0)
/* 08C9F4 800F3544 0C0513BF */  jal   func_80144EFC
/* 08C9F8 800F3548 00A0382D */   daddu $a3, $a1, $zero
/* 08C9FC 800F354C 240500A0 */  addiu $a1, $zero, 0xa0
/* 08CA00 800F3550 00A0302D */  daddu $a2, $a1, $zero
/* 08CA04 800F3554 3C048011 */  lui   $a0, 0x8011
/* 08CA08 800F3558 8C84D664 */  lw    $a0, -0x299c($a0)
/* 08CA0C 800F355C 0C0513BF */  jal   func_80144EFC
/* 08CA10 800F3560 00A0382D */   daddu $a3, $a1, $zero
.L800F3564:
/* 08CA14 800F3564 8E020000 */  lw    $v0, ($s0)
/* 08CA18 800F3568 8C430318 */  lw    $v1, 0x318($v0)
/* 08CA1C 800F356C 24020001 */  addiu $v0, $zero, 1
/* 08CA20 800F3570 10620003 */  beq   $v1, $v0, .L800F3580
/* 08CA24 800F3574 00000000 */   nop   
/* 08CA28 800F3578 14710007 */  bne   $v1, $s1, .L800F3598
/* 08CA2C 800F357C 00000000 */   nop   
.L800F3580:
/* 08CA30 800F3580 3C048011 */  lui   $a0, 0x8011
/* 08CA34 800F3584 8C84D668 */  lw    $a0, -0x2998($a0)
/* 08CA38 800F3588 240500A0 */  addiu $a1, $zero, 0xa0
/* 08CA3C 800F358C 00A0302D */  daddu $a2, $a1, $zero
/* 08CA40 800F3590 0C0513BF */  jal   func_80144EFC
/* 08CA44 800F3594 00A0382D */   daddu $a3, $a1, $zero
.L800F3598:
/* 08CA48 800F3598 3C108011 */  lui   $s0, 0x8011
/* 08CA4C 800F359C 2610D69C */  addiu $s0, $s0, -0x2964
/* 08CA50 800F35A0 8E020000 */  lw    $v0, ($s0)
/* 08CA54 800F35A4 8C430318 */  lw    $v1, 0x318($v0)
/* 08CA58 800F35A8 24020005 */  addiu $v0, $zero, 5
/* 08CA5C 800F35AC 14620006 */  bne   $v1, $v0, .L800F35C8
/* 08CA60 800F35B0 240500A0 */   addiu $a1, $zero, 0xa0
/* 08CA64 800F35B4 3C048011 */  lui   $a0, 0x8011
/* 08CA68 800F35B8 8C84D660 */  lw    $a0, -0x29a0($a0)
/* 08CA6C 800F35BC 00A0302D */  daddu $a2, $a1, $zero
/* 08CA70 800F35C0 0C0513BF */  jal   func_80144EFC
/* 08CA74 800F35C4 00A0382D */   daddu $a3, $a1, $zero
.L800F35C8:
/* 08CA78 800F35C8 3C048011 */  lui   $a0, 0x8011
/* 08CA7C 800F35CC 8C84D66C */  lw    $a0, -0x2994($a0)
/* 08CA80 800F35D0 3C058010 */  lui   $a1, 0x8010
/* 08CA84 800F35D4 24A54A00 */  addiu $a1, $a1, 0x4a00
/* 08CA88 800F35D8 0C0511FF */  jal   set_menu_icon_script
/* 08CA8C 800F35DC 00000000 */   nop   
/* 08CA90 800F35E0 8E020000 */  lw    $v0, ($s0)
/* 08CA94 800F35E4 8C430318 */  lw    $v1, 0x318($v0)
/* 08CA98 800F35E8 2C62000E */  sltiu $v0, $v1, 0xe
/* 08CA9C 800F35EC 10400013 */  beqz  $v0, .L800F363C
/* 08CAA0 800F35F0 00031080 */   sll   $v0, $v1, 2
/* 08CAA4 800F35F4 3C018011 */  lui   $at, 0x8011
/* 08CAA8 800F35F8 00220821 */  addu  $at, $at, $v0
/* 08CAAC 800F35FC 8C22C758 */  lw    $v0, -0x38a8($at)
/* 08CAB0 800F3600 00400008 */  jr    $v0
/* 08CAB4 800F3604 00000000 */   nop   
/* 08CAB8 800F3608 2404000E */  addiu $a0, $zero, 0xe
/* 08CABC 800F360C 0C051F9F */  jal   func_80147E7C
/* 08CAC0 800F3610 24050001 */   addiu $a1, $zero, 1
/* 08CAC4 800F3614 0803CD8D */  j     .L800F3634
/* 08CAC8 800F3618 24040013 */   addiu $a0, $zero, 0x13

/* 08CACC 800F361C 2404000E */  addiu $a0, $zero, 0xe
/* 08CAD0 800F3620 0C051F9F */  jal   func_80147E7C
/* 08CAD4 800F3624 24050001 */   addiu $a1, $zero, 1
/* 08CAD8 800F3628 0803CD8D */  j     .L800F3634
/* 08CADC 800F362C 24040013 */   addiu $a0, $zero, 0x13

/* 08CAE0 800F3630 2404000E */  addiu $a0, $zero, 0xe
.L800F3634:
/* 08CAE4 800F3634 0C051F9F */  jal   func_80147E7C
/* 08CAE8 800F3638 24050001 */   addiu $a1, $zero, 1
.L800F363C:
/* 08CAEC 800F363C 2402000A */  addiu $v0, $zero, 0xa
/* 08CAF0 800F3640 3C018011 */  lui   $at, 0x8011
/* 08CAF4 800F3644 A022D690 */  sb    $v0, -0x2970($at)
/* 08CAF8 800F3648 24020001 */  addiu $v0, $zero, 1
.L800F364C:
/* 08CAFC 800F364C 3C018011 */  lui   $at, 0x8011
/* 08CB00 800F3650 AC22D640 */  sw    $v0, -0x29c0($at)
.L800F3654:
/* 08CB04 800F3654 3C038011 */  lui   $v1, 0x8011
/* 08CB08 800F3658 8C63D69C */  lw    $v1, -0x2964($v1)
/* 08CB0C 800F365C 0000102D */  daddu $v0, $zero, $zero
/* 08CB10 800F3660 A460032C */  sh    $zero, 0x32c($v1)
.L800F3664:
/* 08CB14 800F3664 8FBF0038 */  lw    $ra, 0x38($sp)
/* 08CB18 800F3668 8FB30034 */  lw    $s3, 0x34($sp)
/* 08CB1C 800F366C 8FB20030 */  lw    $s2, 0x30($sp)
/* 08CB20 800F3670 8FB1002C */  lw    $s1, 0x2c($sp)
/* 08CB24 800F3674 8FB00028 */  lw    $s0, 0x28($sp)
/* 08CB28 800F3678 03E00008 */  jr    $ra
/* 08CB2C 800F367C 27BD0040 */   addiu $sp, $sp, 0x40

/* 08CB30 800F3680 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 08CB34 800F3684 3C038011 */  lui   $v1, 0x8011
/* 08CB38 800F3688 8C63D640 */  lw    $v1, -0x29c0($v1)
/* 08CB3C 800F368C 2402000A */  addiu $v0, $zero, 0xa
/* 08CB40 800F3690 AFBF0054 */  sw    $ra, 0x54($sp)
/* 08CB44 800F3694 AFBE0050 */  sw    $fp, 0x50($sp)
/* 08CB48 800F3698 AFB7004C */  sw    $s7, 0x4c($sp)
/* 08CB4C 800F369C AFB60048 */  sw    $s6, 0x48($sp)
/* 08CB50 800F36A0 AFB50044 */  sw    $s5, 0x44($sp)
/* 08CB54 800F36A4 AFB40040 */  sw    $s4, 0x40($sp)
/* 08CB58 800F36A8 AFB3003C */  sw    $s3, 0x3c($sp)
/* 08CB5C 800F36AC AFB20038 */  sw    $s2, 0x38($sp)
/* 08CB60 800F36B0 AFB10034 */  sw    $s1, 0x34($sp)
/* 08CB64 800F36B4 AFB00030 */  sw    $s0, 0x30($sp)
/* 08CB68 800F36B8 AFA5005C */  sw    $a1, 0x5c($sp)
/* 08CB6C 800F36BC 1062001E */  beq   $v1, $v0, .L800F3738
/* 08CB70 800F36C0 AFA60060 */   sw    $a2, 0x60($sp)
/* 08CB74 800F36C4 2862000B */  slti  $v0, $v1, 0xb
/* 08CB78 800F36C8 1040000E */  beqz  $v0, .L800F3704
/* 08CB7C 800F36CC 28620020 */   slti  $v0, $v1, 0x20
/* 08CB80 800F36D0 04610008 */  bgez  $v1, .L800F36F4
/* 08CB84 800F36D4 24020001 */   addiu $v0, $zero, 1
/* 08CB88 800F36D8 2862FFFE */  slti  $v0, $v1, -2
/* 08CB8C 800F36DC 10400016 */  beqz  $v0, .L800F3738
/* 08CB90 800F36E0 2862FFFB */   slti  $v0, $v1, -5
/* 08CB94 800F36E4 104003CC */  beqz  $v0, .L800F4618
/* 08CB98 800F36E8 2862FFF8 */   slti  $v0, $v1, -8
/* 08CB9C 800F36EC 0803CDCC */  j     .L800F3730
/* 08CBA0 800F36F0 00000000 */   nop   

.L800F36F4:
/* 08CBA4 800F36F4 10620010 */  beq   $v1, $v0, .L800F3738
/* 08CBA8 800F36F8 00000000 */   nop   
/* 08CBAC 800F36FC 0803D186 */  j     .L800F4618
/* 08CBB0 800F3700 00000000 */   nop   

.L800F3704:
/* 08CBB4 800F3704 10400007 */  beqz  $v0, .L800F3724
/* 08CBB8 800F3708 2862001E */   slti  $v0, $v1, 0x1e
/* 08CBBC 800F370C 1040000A */  beqz  $v0, .L800F3738
/* 08CBC0 800F3710 24020014 */   addiu $v0, $zero, 0x14
/* 08CBC4 800F3714 10620008 */  beq   $v1, $v0, .L800F3738
/* 08CBC8 800F3718 00000000 */   nop   
/* 08CBCC 800F371C 0803D186 */  j     .L800F4618
/* 08CBD0 800F3720 00000000 */   nop   

.L800F3724:
/* 08CBD4 800F3724 2862006A */  slti  $v0, $v1, 0x6a
/* 08CBD8 800F3728 104003BB */  beqz  $v0, .L800F4618
/* 08CBDC 800F372C 28620064 */   slti  $v0, $v1, 0x64
.L800F3730:
/* 08CBE0 800F3730 144003B9 */  bnez  $v0, .L800F4618
/* 08CBE4 800F3734 00000000 */   nop   
.L800F3738:
/* 08CBE8 800F3738 8FAA005C */  lw    $t2, 0x5c($sp)
/* 08CBEC 800F373C 8FAB0060 */  lw    $t3, 0x60($sp)
/* 08CBF0 800F3740 3C028011 */  lui   $v0, 0x8011
/* 08CBF4 800F3744 8042D654 */  lb    $v0, -0x29ac($v0)
/* 08CBF8 800F3748 3C088011 */  lui   $t0, 0x8011
/* 08CBFC 800F374C 8508D658 */  lh    $t0, -0x29a8($t0)
/* 08CC00 800F3750 254A0002 */  addiu $t2, $t2, 2
/* 08CC04 800F3754 256B000F */  addiu $t3, $t3, 0xf
/* 08CC08 800F3758 00021023 */  negu  $v0, $v0
/* 08CC0C 800F375C 00021840 */  sll   $v1, $v0, 1
/* 08CC10 800F3760 00621821 */  addu  $v1, $v1, $v0
/* 08CC14 800F3764 00031880 */  sll   $v1, $v1, 2
/* 08CC18 800F3768 00628821 */  addu  $s1, $v1, $v0
/* 08CC1C 800F376C 02282023 */  subu  $a0, $s1, $t0
/* 08CC20 800F3770 28820082 */  slti  $v0, $a0, 0x82
/* 08CC24 800F3774 AFAA005C */  sw    $t2, 0x5c($sp)
/* 08CC28 800F3778 1040000D */  beqz  $v0, .L800F37B0
/* 08CC2C 800F377C AFAB0060 */   sw    $t3, 0x60($sp)
/* 08CC30 800F3780 3C013FE0 */  lui   $at, 0x3fe0
/* 08CC34 800F3784 44811800 */  mtc1  $at, $f3
/* 08CC38 800F3788 44801000 */  mtc1  $zero, $f2
/* 08CC3C 800F378C 44840000 */  mtc1  $a0, $f0
/* 08CC40 800F3790 00000000 */  nop   
/* 08CC44 800F3794 46800021 */  cvt.d.w $f0, $f0
/* 08CC48 800F3798 46220002 */  mul.d $f0, $f0, $f2
/* 08CC4C 800F379C 00000000 */  nop   
/* 08CC50 800F37A0 4620018D */  trunc.w.d $f6, $f0
/* 08CC54 800F37A4 44043000 */  mfc1  $a0, $f6
/* 08CC58 800F37A8 0803CDF8 */  j     .L800F37E0
/* 08CC5C 800F37AC 00000000 */   nop   

.L800F37B0:
/* 08CC60 800F37B0 3C031B4E */  lui   $v1, 0x1b4e
/* 08CC64 800F37B4 346381B5 */  ori   $v1, $v1, 0x81b5
/* 08CC68 800F37B8 00041040 */  sll   $v0, $a0, 1
/* 08CC6C 800F37BC 00441021 */  addu  $v0, $v0, $a0
/* 08CC70 800F37C0 000210C0 */  sll   $v0, $v0, 3
/* 08CC74 800F37C4 00441021 */  addu  $v0, $v0, $a0
/* 08CC78 800F37C8 00021080 */  sll   $v0, $v0, 2
/* 08CC7C 800F37CC 00430018 */  mult  $v0, $v1
/* 08CC80 800F37D0 000217C3 */  sra   $v0, $v0, 0x1f
/* 08CC84 800F37D4 00005010 */  mfhi  $t2
/* 08CC88 800F37D8 000A1903 */  sra   $v1, $t2, 4
/* 08CC8C 800F37DC 00622023 */  subu  $a0, $v1, $v0
.L800F37E0:
/* 08CC90 800F37E0 14800002 */  bnez  $a0, .L800F37EC
/* 08CC94 800F37E4 01044021 */   addu  $t0, $t0, $a0
/* 08CC98 800F37E8 0220402D */  daddu $t0, $s1, $zero
.L800F37EC:
/* 08CC9C 800F37EC 3C054EC4 */  lui   $a1, 0x4ec4
/* 08CCA0 800F37F0 34A5EC4F */  ori   $a1, $a1, 0xec4f
/* 08CCA4 800F37F4 00081C00 */  sll   $v1, $t0, 0x10
/* 08CCA8 800F37F8 00031C03 */  sra   $v1, $v1, 0x10
/* 08CCAC 800F37FC 8FAB005C */  lw    $t3, 0x5c($sp)
/* 08CCB0 800F3800 8FB10060 */  lw    $s1, 0x60($sp)
/* 08CCB4 800F3804 3C048011 */  lui   $a0, 0x8011
/* 08CCB8 800F3808 8084D656 */  lb    $a0, -0x29aa($a0)
/* 08CCBC 800F380C 00031823 */  negu  $v1, $v1
/* 08CCC0 800F3810 3C018011 */  lui   $at, 0x8011
/* 08CCC4 800F3814 A428D658 */  sh    $t0, -0x29a8($at)
/* 08CCC8 800F3818 00041040 */  sll   $v0, $a0, 1
/* 08CCCC 800F381C 00441021 */  addu  $v0, $v0, $a0
/* 08CCD0 800F3820 00021080 */  sll   $v0, $v0, 2
/* 08CCD4 800F3824 00441021 */  addu  $v0, $v0, $a0
/* 08CCD8 800F3828 02221021 */  addu  $v0, $s1, $v0
/* 08CCDC 800F382C 24480004 */  addiu $t0, $v0, 4
/* 08CCE0 800F3830 3C028011 */  lui   $v0, 0x8011
/* 08CCE4 800F3834 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08CCE8 800F3838 00650018 */  mult  $v1, $a1
/* 08CCEC 800F383C AFAB0020 */  sw    $t3, 0x20($sp)
/* 08CCF0 800F3840 8C450318 */  lw    $a1, 0x318($v0)
/* 08CCF4 800F3844 00031FC3 */  sra   $v1, $v1, 0x1f
/* 08CCF8 800F3848 2CA2000E */  sltiu $v0, $a1, 0xe
/* 08CCFC 800F384C 00005010 */  mfhi  $t2
/* 08CD00 800F3850 000A2083 */  sra   $a0, $t2, 2
/* 08CD04 800F3854 00832023 */  subu  $a0, $a0, $v1
/* 08CD08 800F3858 10400064 */  beqz  $v0, .L800F39EC
/* 08CD0C 800F385C AFA40028 */   sw    $a0, 0x28($sp)
/* 08CD10 800F3860 00051080 */  sll   $v0, $a1, 2
/* 08CD14 800F3864 3C018011 */  lui   $at, 0x8011
/* 08CD18 800F3868 00220821 */  addu  $at, $at, $v0
/* 08CD1C 800F386C 8C22C790 */  lw    $v0, -0x3870($at)
/* 08CD20 800F3870 00400008 */  jr    $v0
/* 08CD24 800F3874 00000000 */   nop   
/* 08CD28 800F3878 3C03800A */  lui   $v1, 0x800a
/* 08CD2C 800F387C 2463A66C */  addiu $v1, $v1, -0x5994
/* 08CD30 800F3880 C7A20020 */  lwc1  $f2, 0x20($sp)
/* 08CD34 800F3884 468010A0 */  cvt.s.w $f2, $f2
/* 08CD38 800F3888 44910000 */  mtc1  $s1, $f0
/* 08CD3C 800F388C 00000000 */  nop   
/* 08CD40 800F3890 46800020 */  cvt.s.w $f0, $f0
/* 08CD44 800F3894 3C014080 */  lui   $at, 0x4080
/* 08CD48 800F3898 44812000 */  mtc1  $at, $f4
/* 08CD4C 800F389C 8C620000 */  lw    $v0, ($v1)
/* 08CD50 800F38A0 46041082 */  mul.s $f2, $f2, $f4
/* 08CD54 800F38A4 00000000 */  nop   
/* 08CD58 800F38A8 0040282D */  daddu $a1, $v0, $zero
/* 08CD5C 800F38AC 24420008 */  addiu $v0, $v0, 8
/* 08CD60 800F38B0 AC620000 */  sw    $v0, ($v1)
/* 08CD64 800F38B4 8FAB0020 */  lw    $t3, 0x20($sp)
/* 08CD68 800F38B8 46040002 */  mul.s $f0, $f0, $f4
/* 08CD6C 800F38BC 00000000 */  nop   
/* 08CD70 800F38C0 0803CE59 */  j     .L800F3964
/* 08CD74 800F38C4 25620070 */   addiu $v0, $t3, 0x70

/* 08CD78 800F38C8 3C03800A */  lui   $v1, 0x800a
/* 08CD7C 800F38CC 2463A66C */  addiu $v1, $v1, -0x5994
/* 08CD80 800F38D0 C7A20020 */  lwc1  $f2, 0x20($sp)
/* 08CD84 800F38D4 468010A0 */  cvt.s.w $f2, $f2
/* 08CD88 800F38D8 44910000 */  mtc1  $s1, $f0
/* 08CD8C 800F38DC 00000000 */  nop   
/* 08CD90 800F38E0 46800020 */  cvt.s.w $f0, $f0
/* 08CD94 800F38E4 3C014080 */  lui   $at, 0x4080
/* 08CD98 800F38E8 44812000 */  mtc1  $at, $f4
/* 08CD9C 800F38EC 8C620000 */  lw    $v0, ($v1)
/* 08CDA0 800F38F0 46041082 */  mul.s $f2, $f2, $f4
/* 08CDA4 800F38F4 00000000 */  nop   
/* 08CDA8 800F38F8 0040282D */  daddu $a1, $v0, $zero
/* 08CDAC 800F38FC 24420008 */  addiu $v0, $v0, 8
/* 08CDB0 800F3900 AC620000 */  sw    $v0, ($v1)
/* 08CDB4 800F3904 8FAB0020 */  lw    $t3, 0x20($sp)
/* 08CDB8 800F3908 46040002 */  mul.s $f0, $f0, $f4
/* 08CDBC 800F390C 00000000 */  nop   
/* 08CDC0 800F3910 0803CE59 */  j     .L800F3964
/* 08CDC4 800F3914 2562005A */   addiu $v0, $t3, 0x5a

/* 08CDC8 800F3918 3C03800A */  lui   $v1, 0x800a
/* 08CDCC 800F391C 2463A66C */  addiu $v1, $v1, -0x5994
/* 08CDD0 800F3920 C7A20020 */  lwc1  $f2, 0x20($sp)
/* 08CDD4 800F3924 468010A0 */  cvt.s.w $f2, $f2
/* 08CDD8 800F3928 44910000 */  mtc1  $s1, $f0
/* 08CDDC 800F392C 00000000 */  nop   
/* 08CDE0 800F3930 46800020 */  cvt.s.w $f0, $f0
/* 08CDE4 800F3934 3C014080 */  lui   $at, 0x4080
/* 08CDE8 800F3938 44812000 */  mtc1  $at, $f4
/* 08CDEC 800F393C 8C620000 */  lw    $v0, ($v1)
/* 08CDF0 800F3940 46041082 */  mul.s $f2, $f2, $f4
/* 08CDF4 800F3944 00000000 */  nop   
/* 08CDF8 800F3948 0040282D */  daddu $a1, $v0, $zero
/* 08CDFC 800F394C 24420008 */  addiu $v0, $v0, 8
/* 08CE00 800F3950 AC620000 */  sw    $v0, ($v1)
/* 08CE04 800F3954 8FAB0020 */  lw    $t3, 0x20($sp)
/* 08CE08 800F3958 46040002 */  mul.s $f0, $f0, $f4
/* 08CE0C 800F395C 00000000 */  nop   
/* 08CE10 800F3960 256200A0 */  addiu $v0, $t3, 0xa0
.L800F3964:
/* 08CE14 800F3964 4600118D */  trunc.w.s $f6, $f2
/* 08CE18 800F3968 44033000 */  mfc1  $v1, $f6
/* 08CE1C 800F396C 00000000 */  nop   
/* 08CE20 800F3970 30630FFF */  andi  $v1, $v1, 0xfff
/* 08CE24 800F3974 00031B00 */  sll   $v1, $v1, 0xc
/* 08CE28 800F3978 4600018D */  trunc.w.s $f6, $f0
/* 08CE2C 800F397C 44043000 */  mfc1  $a0, $f6
/* 08CE30 800F3980 00000000 */  nop   
/* 08CE34 800F3984 30840FFF */  andi  $a0, $a0, 0xfff
/* 08CE38 800F3988 44821000 */  mtc1  $v0, $f2
/* 08CE3C 800F398C 00000000 */  nop   
/* 08CE40 800F3990 468010A0 */  cvt.s.w $f2, $f2
/* 08CE44 800F3994 46041082 */  mul.s $f2, $f2, $f4
/* 08CE48 800F3998 00000000 */  nop   
/* 08CE4C 800F399C 3C02ED00 */  lui   $v0, 0xed00
/* 08CE50 800F39A0 00822025 */  or    $a0, $a0, $v0
/* 08CE54 800F39A4 00641825 */  or    $v1, $v1, $a0
/* 08CE58 800F39A8 44880000 */  mtc1  $t0, $f0
/* 08CE5C 800F39AC 00000000 */  nop   
/* 08CE60 800F39B0 46800020 */  cvt.s.w $f0, $f0
/* 08CE64 800F39B4 46040002 */  mul.s $f0, $f0, $f4
/* 08CE68 800F39B8 00000000 */  nop   
/* 08CE6C 800F39BC ACA30000 */  sw    $v1, ($a1)
/* 08CE70 800F39C0 4600118D */  trunc.w.s $f6, $f2
/* 08CE74 800F39C4 44023000 */  mfc1  $v0, $f6
/* 08CE78 800F39C8 00000000 */  nop   
/* 08CE7C 800F39CC 30420FFF */  andi  $v0, $v0, 0xfff
/* 08CE80 800F39D0 00021300 */  sll   $v0, $v0, 0xc
/* 08CE84 800F39D4 4600018D */  trunc.w.s $f6, $f0
/* 08CE88 800F39D8 44033000 */  mfc1  $v1, $f6
/* 08CE8C 800F39DC 00000000 */  nop   
/* 08CE90 800F39E0 30630FFF */  andi  $v1, $v1, 0xfff
/* 08CE94 800F39E4 00431025 */  or    $v0, $v0, $v1
/* 08CE98 800F39E8 ACA20004 */  sw    $v0, 4($a1)
.L800F39EC:
/* 08CE9C 800F39EC 3C028011 */  lui   $v0, 0x8011
/* 08CEA0 800F39F0 8442D658 */  lh    $v0, -0x29a8($v0)
/* 08CEA4 800F39F4 8FAB0060 */  lw    $t3, 0x60($sp)
/* 08CEA8 800F39F8 3C128011 */  lui   $s2, 0x8011
/* 08CEAC 800F39FC 2652D69C */  addiu $s2, $s2, -0x2964
/* 08CEB0 800F3A00 01621821 */  addu  $v1, $t3, $v0
/* 08CEB4 800F3A04 8E420000 */  lw    $v0, ($s2)
/* 08CEB8 800F3A08 24130002 */  addiu $s3, $zero, 2
/* 08CEBC 800F3A0C 8C420318 */  lw    $v0, 0x318($v0)
/* 08CEC0 800F3A10 14530002 */  bne   $v0, $s3, .L800F3A1C
/* 08CEC4 800F3A14 24710008 */   addiu $s1, $v1, 8
/* 08CEC8 800F3A18 24710015 */  addiu $s1, $v1, 0x15
.L800F3A1C:
/* 08CECC 800F3A1C 2626FFFD */  addiu $a2, $s1, -3
/* 08CED0 800F3A20 8FAA005C */  lw    $t2, 0x5c($sp)
/* 08CED4 800F3A24 3C108011 */  lui   $s0, 0x8011
/* 08CED8 800F3A28 8E10D65C */  lw    $s0, -0x29a4($s0)
/* 08CEDC 800F3A2C 25450049 */  addiu $a1, $t2, 0x49
/* 08CEE0 800F3A30 0C051261 */  jal   set_icon_render_pos
/* 08CEE4 800F3A34 0200202D */   daddu $a0, $s0, $zero
/* 08CEE8 800F3A38 3C058011 */  lui   $a1, 0x8011
/* 08CEEC 800F3A3C 8CA5D650 */  lw    $a1, -0x29b0($a1)
/* 08CEF0 800F3A40 0C0513AC */  jal   func_80144EB0
/* 08CEF4 800F3A44 0200202D */   daddu $a0, $s0, $zero
/* 08CEF8 800F3A48 8E420000 */  lw    $v0, ($s2)
/* 08CEFC 800F3A4C 3C038011 */  lui   $v1, 0x8011
/* 08CF00 800F3A50 8063D68F */  lb    $v1, -0x2971($v1)
/* 08CF04 800F3A54 8C420324 */  lw    $v0, 0x324($v0)
/* 08CF08 800F3A58 0062182A */  slt   $v1, $v1, $v0
/* 08CF0C 800F3A5C 10600003 */  beqz  $v1, .L800F3A6C
/* 08CF10 800F3A60 00000000 */   nop   
/* 08CF14 800F3A64 0C0511F8 */  jal   func_801447E0
/* 08CF18 800F3A68 0200202D */   daddu $a0, $s0, $zero
.L800F3A6C:
/* 08CF1C 800F3A6C 8FAB005C */  lw    $t3, 0x5c($sp)
/* 08CF20 800F3A70 8FAA0060 */  lw    $t2, 0x60($sp)
/* 08CF24 800F3A74 3C038011 */  lui   $v1, 0x8011
/* 08CF28 800F3A78 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08CF2C 800F3A7C 25510002 */  addiu $s1, $t2, 2
/* 08CF30 800F3A80 00031040 */  sll   $v0, $v1, 1
/* 08CF34 800F3A84 00431021 */  addu  $v0, $v0, $v1
/* 08CF38 800F3A88 00021080 */  sll   $v0, $v0, 2
/* 08CF3C 800F3A8C AFAB0020 */  sw    $t3, 0x20($sp)
/* 08CF40 800F3A90 8E440000 */  lw    $a0, ($s2)
/* 08CF44 800F3A94 00431021 */  addu  $v0, $v0, $v1
/* 08CF48 800F3A98 8C830318 */  lw    $v1, 0x318($a0)
/* 08CF4C 800F3A9C 14730008 */  bne   $v1, $s3, .L800F3AC0
/* 08CF50 800F3AA0 02224021 */   addu  $t0, $s1, $v0
/* 08CF54 800F3AA4 3C028011 */  lui   $v0, 0x8011
/* 08CF58 800F3AA8 8042D654 */  lb    $v0, -0x29ac($v0)
/* 08CF5C 800F3AAC 28420002 */  slti  $v0, $v0, 2
/* 08CF60 800F3AB0 10400003 */  beqz  $v0, .L800F3AC0
/* 08CF64 800F3AB4 00000000 */   nop   
/* 08CF68 800F3AB8 0140882D */  daddu $s1, $t2, $zero
/* 08CF6C 800F3ABC 25080001 */  addiu $t0, $t0, 1
.L800F3AC0:
/* 08CF70 800F3AC0 C7A20020 */  lwc1  $f2, 0x20($sp)
/* 08CF74 800F3AC4 468010A0 */  cvt.s.w $f2, $f2
/* 08CF78 800F3AC8 3C014080 */  lui   $at, 0x4080
/* 08CF7C 800F3ACC 44812000 */  mtc1  $at, $f4
/* 08CF80 800F3AD0 3C06800A */  lui   $a2, 0x800a
/* 08CF84 800F3AD4 24C6A66C */  addiu $a2, $a2, -0x5994
/* 08CF88 800F3AD8 46041082 */  mul.s $f2, $f2, $f4
/* 08CF8C 800F3ADC 00000000 */  nop   
/* 08CF90 800F3AE0 44910000 */  mtc1  $s1, $f0
/* 08CF94 800F3AE4 00000000 */  nop   
/* 08CF98 800F3AE8 46800020 */  cvt.s.w $f0, $f0
/* 08CF9C 800F3AEC 8CC50000 */  lw    $a1, ($a2)
/* 08CFA0 800F3AF0 3C04ED00 */  lui   $a0, 0xed00
/* 08CFA4 800F3AF4 00A0382D */  daddu $a3, $a1, $zero
/* 08CFA8 800F3AF8 46040002 */  mul.s $f0, $f0, $f4
/* 08CFAC 800F3AFC 00000000 */  nop   
/* 08CFB0 800F3B00 24A50008 */  addiu $a1, $a1, 8
/* 08CFB4 800F3B04 4600118D */  trunc.w.s $f6, $f2
/* 08CFB8 800F3B08 44023000 */  mfc1  $v0, $f6
/* 08CFBC 800F3B0C 00000000 */  nop   
/* 08CFC0 800F3B10 30420FFF */  andi  $v0, $v0, 0xfff
/* 08CFC4 800F3B14 00021300 */  sll   $v0, $v0, 0xc
/* 08CFC8 800F3B18 4600018D */  trunc.w.s $f6, $f0
/* 08CFCC 800F3B1C 44033000 */  mfc1  $v1, $f6
/* 08CFD0 800F3B20 00000000 */  nop   
/* 08CFD4 800F3B24 30630FFF */  andi  $v1, $v1, 0xfff
/* 08CFD8 800F3B28 00641825 */  or    $v1, $v1, $a0
/* 08CFDC 800F3B2C 00431025 */  or    $v0, $v0, $v1
/* 08CFE0 800F3B30 3C048011 */  lui   $a0, 0x8011
/* 08CFE4 800F3B34 8C84D69C */  lw    $a0, -0x2964($a0)
/* 08CFE8 800F3B38 44880000 */  mtc1  $t0, $f0
/* 08CFEC 800F3B3C 00000000 */  nop   
/* 08CFF0 800F3B40 46800020 */  cvt.s.w $f0, $f0
/* 08CFF4 800F3B44 ACE20000 */  sw    $v0, ($a3)
/* 08CFF8 800F3B48 8FAB0020 */  lw    $t3, 0x20($sp)
/* 08CFFC 800F3B4C 8C820318 */  lw    $v0, 0x318($a0)
/* 08D000 800F3B50 46040002 */  mul.s $f0, $f0, $f4
/* 08D004 800F3B54 00000000 */  nop   
/* 08D008 800F3B58 AFA00024 */  sw    $zero, 0x24($sp)
/* 08D00C 800F3B5C 00021040 */  sll   $v0, $v0, 1
/* 08D010 800F3B60 3C018011 */  lui   $at, 0x8011
/* 08D014 800F3B64 00220821 */  addu  $at, $at, $v0
/* 08D018 800F3B68 842298BC */  lh    $v0, -0x6744($at)
/* 08D01C 800F3B6C 8FAA0060 */  lw    $t2, 0x60($sp)
/* 08D020 800F3B70 01621021 */  addu  $v0, $t3, $v0
/* 08D024 800F3B74 44821000 */  mtc1  $v0, $f2
/* 08D028 800F3B78 00000000 */  nop   
/* 08D02C 800F3B7C 468010A0 */  cvt.s.w $f2, $f2
/* 08D030 800F3B80 3C028011 */  lui   $v0, 0x8011
/* 08D034 800F3B84 8442D658 */  lh    $v0, -0x29a8($v0)
/* 08D038 800F3B88 46041082 */  mul.s $f2, $f2, $f4
/* 08D03C 800F3B8C 00000000 */  nop   
/* 08D040 800F3B90 ACC50000 */  sw    $a1, ($a2)
/* 08D044 800F3B94 8FAB005C */  lw    $t3, 0x5c($sp)
/* 08D048 800F3B98 01424821 */  addu  $t1, $t2, $v0
/* 08D04C 800F3B9C 256B0020 */  addiu $t3, $t3, 0x20
/* 08D050 800F3BA0 AFAB0020 */  sw    $t3, 0x20($sp)
/* 08D054 800F3BA4 4600118D */  trunc.w.s $f6, $f2
/* 08D058 800F3BA8 44023000 */  mfc1  $v0, $f6
/* 08D05C 800F3BAC 00000000 */  nop   
/* 08D060 800F3BB0 30420FFF */  andi  $v0, $v0, 0xfff
/* 08D064 800F3BB4 00021300 */  sll   $v0, $v0, 0xc
/* 08D068 800F3BB8 4600018D */  trunc.w.s $f6, $f0
/* 08D06C 800F3BBC 44033000 */  mfc1  $v1, $f6
/* 08D070 800F3BC0 00000000 */  nop   
/* 08D074 800F3BC4 30630FFF */  andi  $v1, $v1, 0xfff
/* 08D078 800F3BC8 00431025 */  or    $v0, $v0, $v1
/* 08D07C 800F3BCC ACE20004 */  sw    $v0, 4($a3)
/* 08D080 800F3BD0 8C830318 */  lw    $v1, 0x318($a0)
/* 08D084 800F3BD4 24020002 */  addiu $v0, $zero, 2
/* 08D088 800F3BD8 14620004 */  bne   $v1, $v0, .L800F3BEC
/* 08D08C 800F3BDC 25310002 */   addiu $s1, $t1, 2
/* 08D090 800F3BE0 0120882D */  daddu $s1, $t1, $zero
/* 08D094 800F3BE4 0040582D */  daddu $t3, $v0, $zero
/* 08D098 800F3BE8 AFAB0024 */  sw    $t3, 0x24($sp)
.L800F3BEC:
/* 08D09C 800F3BEC 8C820324 */  lw    $v0, 0x324($a0)
/* 08D0A0 800F3BF0 184000EA */  blez  $v0, .L800F3F9C
/* 08D0A4 800F3BF4 0000902D */   daddu $s2, $zero, $zero
/* 08D0A8 800F3BF8 AFA0002C */  sw    $zero, 0x2c($sp)
.L800F3BFC:
/* 08D0AC 800F3BFC 8FAA0028 */  lw    $t2, 0x28($sp)
/* 08D0B0 800F3C00 2542FFFF */  addiu $v0, $t2, -1
/* 08D0B4 800F3C04 0242102A */  slt   $v0, $s2, $v0
/* 08D0B8 800F3C08 14400007 */  bnez  $v0, .L800F3C28
/* 08D0BC 800F3C0C 00000000 */   nop   
/* 08D0C0 800F3C10 3C028011 */  lui   $v0, 0x8011
/* 08D0C4 800F3C14 8042D656 */  lb    $v0, -0x29aa($v0)
/* 08D0C8 800F3C18 01421021 */  addu  $v0, $t2, $v0
/* 08D0CC 800F3C1C 0052102A */  slt   $v0, $v0, $s2
/* 08D0D0 800F3C20 10400006 */  beqz  $v0, .L800F3C3C
/* 08D0D4 800F3C24 240A0001 */   addiu $t2, $zero, 1
.L800F3C28:
/* 08D0D8 800F3C28 164000D3 */  bnez  $s2, .L800F3F78
/* 08D0DC 800F3C2C 2631000D */   addiu $s1, $s1, 0xd
/* 08D0E0 800F3C30 8FAB0024 */  lw    $t3, 0x24($sp)
/* 08D0E4 800F3C34 0803CFDE */  j     .L800F3F78
/* 08D0E8 800F3C38 022B8821 */   addu  $s1, $s1, $t3

.L800F3C3C:
/* 08D0EC 800F3C3C 3C028011 */  lui   $v0, 0x8011
/* 08D0F0 800F3C40 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D0F4 800F3C44 8C430318 */  lw    $v1, 0x318($v0)
/* 08D0F8 800F3C48 3C108011 */  lui   $s0, 0x8011
/* 08D0FC 800F3C4C 8210D690 */  lb    $s0, -0x2970($s0)
/* 08D100 800F3C50 506A0001 */  beql  $v1, $t2, .L800F3C58
/* 08D104 800F3C54 2410000A */   addiu $s0, $zero, 0xa
.L800F3C58:
/* 08D108 800F3C58 8FAB002C */  lw    $t3, 0x2c($sp)
/* 08D10C 800F3C5C 004B1021 */  addu  $v0, $v0, $t3
/* 08D110 800F3C60 8C42018C */  lw    $v0, 0x18c($v0)
/* 08D114 800F3C64 50400001 */  beql  $v0, $zero, .L800F3C6C
/* 08D118 800F3C68 2410000B */   addiu $s0, $zero, 0xb
.L800F3C6C:
/* 08D11C 800F3C6C 2C62000E */  sltiu $v0, $v1, 0xe
/* 08D120 800F3C70 1040005A */  beqz  $v0, .L800F3DDC
/* 08D124 800F3C74 00031080 */   sll   $v0, $v1, 2
/* 08D128 800F3C78 3C018011 */  lui   $at, 0x8011
/* 08D12C 800F3C7C 00220821 */  addu  $at, $at, $v0
/* 08D130 800F3C80 8C22C7C8 */  lw    $v0, -0x3838($at)
/* 08D134 800F3C84 00400008 */  jr    $v0
/* 08D138 800F3C88 00000000 */   nop   
/* 08D13C 800F3C8C 3C078011 */  lui   $a3, 0x8011
/* 08D140 800F3C90 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08D144 800F3C94 3C028011 */  lui   $v0, 0x8011
/* 08D148 800F3C98 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D14C 800F3C9C 8FA50020 */  lw    $a1, 0x20($sp)
/* 08D150 800F3CA0 8FAB002C */  lw    $t3, 0x2c($sp)
/* 08D154 800F3CA4 240A0001 */  addiu $t2, $zero, 1
/* 08D158 800F3CA8 AFB00010 */  sw    $s0, 0x10($sp)
/* 08D15C 800F3CAC AFAA0014 */  sw    $t2, 0x14($sp)
/* 08D160 800F3CB0 004B1021 */  addu  $v0, $v0, $t3
/* 08D164 800F3CB4 8C440084 */  lw    $a0, 0x84($v0)
/* 08D168 800F3CB8 0803CF75 */  j     .L800F3DD4
/* 08D16C 800F3CBC 0220302D */   daddu $a2, $s1, $zero

/* 08D170 800F3CC0 3C078011 */  lui   $a3, 0x8011
/* 08D174 800F3CC4 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08D178 800F3CC8 3C028011 */  lui   $v0, 0x8011
/* 08D17C 800F3CCC 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D180 800F3CD0 8FA50020 */  lw    $a1, 0x20($sp)
/* 08D184 800F3CD4 8FAB002C */  lw    $t3, 0x2c($sp)
/* 08D188 800F3CD8 240A0001 */  addiu $t2, $zero, 1
/* 08D18C 800F3CDC AFB00010 */  sw    $s0, 0x10($sp)
/* 08D190 800F3CE0 AFAA0014 */  sw    $t2, 0x14($sp)
/* 08D194 800F3CE4 004B1021 */  addu  $v0, $v0, $t3
/* 08D198 800F3CE8 8C440084 */  lw    $a0, 0x84($v0)
/* 08D19C 800F3CEC 0803CF75 */  j     .L800F3DD4
/* 08D1A0 800F3CF0 0220302D */   daddu $a2, $s1, $zero

/* 08D1A4 800F3CF4 3C028011 */  lui   $v0, 0x8011
/* 08D1A8 800F3CF8 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D1AC 800F3CFC 8FAA002C */  lw    $t2, 0x2c($sp)
/* 08D1B0 800F3D00 004A2021 */  addu  $a0, $v0, $t2
/* 08D1B4 800F3D04 8C83018C */  lw    $v1, 0x18c($a0)
/* 08D1B8 800F3D08 24020002 */  addiu $v0, $zero, 2
/* 08D1BC 800F3D0C 50620001 */  beql  $v1, $v0, .L800F3D14
/* 08D1C0 800F3D10 24100022 */   addiu $s0, $zero, 0x22
.L800F3D14:
/* 08D1C4 800F3D14 8FA50020 */  lw    $a1, 0x20($sp)
/* 08D1C8 800F3D18 240B0001 */  addiu $t3, $zero, 1
/* 08D1CC 800F3D1C AFB00010 */  sw    $s0, 0x10($sp)
/* 08D1D0 800F3D20 AFAB0014 */  sw    $t3, 0x14($sp)
/* 08D1D4 800F3D24 8C840084 */  lw    $a0, 0x84($a0)
/* 08D1D8 800F3D28 3C078011 */  lui   $a3, 0x8011
/* 08D1DC 800F3D2C 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08D1E0 800F3D30 0803CF75 */  j     .L800F3DD4
/* 08D1E4 800F3D34 0220302D */   daddu $a2, $s1, $zero

/* 08D1E8 800F3D38 3C028011 */  lui   $v0, 0x8011
/* 08D1EC 800F3D3C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D1F0 800F3D40 8FAA002C */  lw    $t2, 0x2c($sp)
/* 08D1F4 800F3D44 004A1821 */  addu  $v1, $v0, $t2
/* 08D1F8 800F3D48 8C620210 */  lw    $v0, 0x210($v1)
/* 08D1FC 800F3D4C 10400002 */  beqz  $v0, .L800F3D58
/* 08D200 800F3D50 2410000A */   addiu $s0, $zero, 0xa
/* 08D204 800F3D54 2410000B */  addiu $s0, $zero, 0xb
.L800F3D58:
/* 08D208 800F3D58 8C640108 */  lw    $a0, 0x108($v1)
/* 08D20C 800F3D5C 0000282D */  daddu $a1, $zero, $zero
/* 08D210 800F3D60 0C0496FA */  jal   set_message_value
/* 08D214 800F3D64 24840001 */   addiu $a0, $a0, 1
/* 08D218 800F3D68 3C04001D */  lui   $a0, 0x1d
/* 08D21C 800F3D6C 348400CD */  ori   $a0, $a0, 0xcd
/* 08D220 800F3D70 0220302D */  daddu $a2, $s1, $zero
/* 08D224 800F3D74 8FAB0020 */  lw    $t3, 0x20($sp)
/* 08D228 800F3D78 3C078011 */  lui   $a3, 0x8011
/* 08D22C 800F3D7C 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08D230 800F3D80 240A0001 */  addiu $t2, $zero, 1
/* 08D234 800F3D84 AFB00010 */  sw    $s0, 0x10($sp)
/* 08D238 800F3D88 AFAA0014 */  sw    $t2, 0x14($sp)
/* 08D23C 800F3D8C 0803CF75 */  j     .L800F3DD4
/* 08D240 800F3D90 25650008 */   addiu $a1, $t3, 8

/* 08D244 800F3D94 3C028011 */  lui   $v0, 0x8011
/* 08D248 800F3D98 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D24C 800F3D9C 8FAB002C */  lw    $t3, 0x2c($sp)
/* 08D250 800F3DA0 004B1821 */  addu  $v1, $v0, $t3
/* 08D254 800F3DA4 8C620210 */  lw    $v0, 0x210($v1)
/* 08D258 800F3DA8 10400002 */  beqz  $v0, .L800F3DB4
/* 08D25C 800F3DAC 2410000A */   addiu $s0, $zero, 0xa
/* 08D260 800F3DB0 2410000B */  addiu $s0, $zero, 0xb
.L800F3DB4:
/* 08D264 800F3DB4 0220302D */  daddu $a2, $s1, $zero
/* 08D268 800F3DB8 8FA50020 */  lw    $a1, 0x20($sp)
/* 08D26C 800F3DBC 3C078011 */  lui   $a3, 0x8011
/* 08D270 800F3DC0 8CE7D650 */  lw    $a3, -0x29b0($a3)
/* 08D274 800F3DC4 8C640084 */  lw    $a0, 0x84($v1)
/* 08D278 800F3DC8 240A0001 */  addiu $t2, $zero, 1
/* 08D27C 800F3DCC AFB00010 */  sw    $s0, 0x10($sp)
/* 08D280 800F3DD0 AFAA0014 */  sw    $t2, 0x14($sp)
.L800F3DD4:
/* 08D284 800F3DD4 0C04993B */  jal   draw_string
/* 08D288 800F3DD8 00000000 */   nop   
.L800F3DDC:
/* 08D28C 800F3DDC 3C048011 */  lui   $a0, 0x8011
/* 08D290 800F3DE0 8C84D69C */  lw    $a0, -0x2964($a0)
/* 08D294 800F3DE4 8C830318 */  lw    $v1, 0x318($a0)
/* 08D298 800F3DE8 240B0003 */  addiu $t3, $zero, 3
/* 08D29C 800F3DEC 106B0045 */  beq   $v1, $t3, .L800F3F04
/* 08D2A0 800F3DF0 0220302D */   daddu $a2, $s1, $zero
/* 08D2A4 800F3DF4 28620004 */  slti  $v0, $v1, 4
/* 08D2A8 800F3DF8 10400005 */  beqz  $v0, .L800F3E10
/* 08D2AC 800F3DFC 240A0001 */   addiu $t2, $zero, 1
/* 08D2B0 800F3E00 106A000B */  beq   $v1, $t2, .L800F3E30
/* 08D2B4 800F3E04 0000982D */   daddu $s3, $zero, $zero
/* 08D2B8 800F3E08 0803CFDA */  j     .L800F3F68
/* 08D2BC 800F3E0C 2631000D */   addiu $s1, $s1, 0xd

.L800F3E10:
/* 08D2C0 800F3E10 24020004 */  addiu $v0, $zero, 4
/* 08D2C4 800F3E14 10620005 */  beq   $v1, $v0, .L800F3E2C
/* 08D2C8 800F3E18 24020005 */   addiu $v0, $zero, 5
/* 08D2CC 800F3E1C 10620044 */  beq   $v1, $v0, .L800F3F30
/* 08D2D0 800F3E20 0220302D */   daddu $a2, $s1, $zero
/* 08D2D4 800F3E24 0803CFDA */  j     .L800F3F68
/* 08D2D8 800F3E28 2631000D */   addiu $s1, $s1, 0xd

.L800F3E2C:
/* 08D2DC 800F3E2C 0000982D */  daddu $s3, $zero, $zero
.L800F3E30:
/* 08D2E0 800F3E30 0012F080 */  sll   $fp, $s2, 2
/* 08D2E4 800F3E34 2417005B */  addiu $s7, $zero, 0x5b
/* 08D2E8 800F3E38 24160055 */  addiu $s6, $zero, 0x55
/* 08D2EC 800F3E3C 3C158011 */  lui   $s5, 0x8011
/* 08D2F0 800F3E40 26B59898 */  addiu $s5, $s5, -0x6768
/* 08D2F4 800F3E44 3C148011 */  lui   $s4, 0x8011
/* 08D2F8 800F3E48 26949890 */  addiu $s4, $s4, -0x6770
.L800F3E4C:
/* 08D2FC 800F3E4C 3C028011 */  lui   $v0, 0x8011
/* 08D300 800F3E50 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D304 800F3E54 005E1021 */  addu  $v0, $v0, $fp
/* 08D308 800F3E58 8C42018C */  lw    $v0, 0x18c($v0)
/* 08D30C 800F3E5C 3C108011 */  lui   $s0, 0x8011
/* 08D310 800F3E60 8E10D668 */  lw    $s0, -0x2998($s0)
/* 08D314 800F3E64 10400003 */  beqz  $v0, .L800F3E74
/* 08D318 800F3E68 00000000 */   nop   
/* 08D31C 800F3E6C 0803CF9E */  j     .L800F3E78
/* 08D320 800F3E70 8E850000 */   lw    $a1, ($s4)

.L800F3E74:
/* 08D324 800F3E74 8EA50000 */  lw    $a1, ($s5)
.L800F3E78:
/* 08D328 800F3E78 0C0511FF */  jal   set_menu_icon_script
/* 08D32C 800F3E7C 0200202D */   daddu $a0, $s0, $zero
/* 08D330 800F3E80 3C028011 */  lui   $v0, 0x8011
/* 08D334 800F3E84 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D338 800F3E88 8C420318 */  lw    $v0, 0x318($v0)
/* 08D33C 800F3E8C 240B0001 */  addiu $t3, $zero, 1
/* 08D340 800F3E90 144B0005 */  bne   $v0, $t3, .L800F3EA8
/* 08D344 800F3E94 0200202D */   daddu $a0, $s0, $zero
/* 08D348 800F3E98 8FAA0020 */  lw    $t2, 0x20($sp)
/* 08D34C 800F3E9C 2626000A */  addiu $a2, $s1, 0xa
/* 08D350 800F3EA0 0803CFAD */  j     .L800F3EB4
/* 08D354 800F3EA4 01562821 */   addu  $a1, $t2, $s6

.L800F3EA8:
/* 08D358 800F3EA8 8FAB0020 */  lw    $t3, 0x20($sp)
/* 08D35C 800F3EAC 2626000A */  addiu $a2, $s1, 0xa
/* 08D360 800F3EB0 01772821 */  addu  $a1, $t3, $s7
.L800F3EB4:
/* 08D364 800F3EB4 0C051261 */  jal   set_icon_render_pos
/* 08D368 800F3EB8 00000000 */   nop   
/* 08D36C 800F3EBC 3C028011 */  lui   $v0, 0x8011
/* 08D370 800F3EC0 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D374 800F3EC4 005E1021 */  addu  $v0, $v0, $fp
/* 08D378 800F3EC8 8C420210 */  lw    $v0, 0x210($v0)
/* 08D37C 800F3ECC 0262102A */  slt   $v0, $s3, $v0
/* 08D380 800F3ED0 50400004 */  beql  $v0, $zero, .L800F3EE4
/* 08D384 800F3ED4 26F7000D */   addiu $s7, $s7, 0xd
/* 08D388 800F3ED8 0C0511F1 */  jal   draw_icon_1
/* 08D38C 800F3EDC 0200202D */   daddu $a0, $s0, $zero
/* 08D390 800F3EE0 26F7000D */  addiu $s7, $s7, 0xd
.L800F3EE4:
/* 08D394 800F3EE4 26D6000D */  addiu $s6, $s6, 0xd
/* 08D398 800F3EE8 26B50004 */  addiu $s5, $s5, 4
/* 08D39C 800F3EEC 26730001 */  addiu $s3, $s3, 1
/* 08D3A0 800F3EF0 2A620002 */  slti  $v0, $s3, 2
/* 08D3A4 800F3EF4 1440FFD5 */  bnez  $v0, .L800F3E4C
/* 08D3A8 800F3EF8 26940004 */   addiu $s4, $s4, 4
/* 08D3AC 800F3EFC 0803CFDA */  j     .L800F3F68
/* 08D3B0 800F3F00 2631000D */   addiu $s1, $s1, 0xd

.L800F3F04:
/* 08D3B4 800F3F04 8FAA0020 */  lw    $t2, 0x20($sp)
/* 08D3B8 800F3F08 3C028011 */  lui   $v0, 0x8011
/* 08D3BC 800F3F0C 8C42D650 */  lw    $v0, -0x29b0($v0)
/* 08D3C0 800F3F10 25450073 */  addiu $a1, $t2, 0x73
/* 08D3C4 800F3F14 8FAA002C */  lw    $t2, 0x2c($sp)
/* 08D3C8 800F3F18 240B0003 */  addiu $t3, $zero, 3
/* 08D3CC 800F3F1C AFB00010 */  sw    $s0, 0x10($sp)
/* 08D3D0 800F3F20 AFAB0018 */  sw    $t3, 0x18($sp)
/* 08D3D4 800F3F24 AFA20014 */  sw    $v0, 0x14($sp)
/* 08D3D8 800F3F28 0803CFD6 */  j     .L800F3F58
/* 08D3DC 800F3F2C 008A1021 */   addu  $v0, $a0, $t2

.L800F3F30:
/* 08D3E0 800F3F30 8FAB0020 */  lw    $t3, 0x20($sp)
/* 08D3E4 800F3F34 3C028011 */  lui   $v0, 0x8011
/* 08D3E8 800F3F38 8C42D650 */  lw    $v0, -0x29b0($v0)
/* 08D3EC 800F3F3C 25650079 */  addiu $a1, $t3, 0x79
/* 08D3F0 800F3F40 8FAB002C */  lw    $t3, 0x2c($sp)
/* 08D3F4 800F3F44 240A0003 */  addiu $t2, $zero, 3
/* 08D3F8 800F3F48 AFB00010 */  sw    $s0, 0x10($sp)
/* 08D3FC 800F3F4C AFAA0018 */  sw    $t2, 0x18($sp)
/* 08D400 800F3F50 AFA20014 */  sw    $v0, 0x14($sp)
/* 08D404 800F3F54 008B1021 */  addu  $v0, $a0, $t3
.L800F3F58:
/* 08D408 800F3F58 8C440210 */  lw    $a0, 0x210($v0)
/* 08D40C 800F3F5C 0C049DA7 */  jal   draw_number
/* 08D410 800F3F60 24070001 */   addiu $a3, $zero, 1
/* 08D414 800F3F64 2631000D */  addiu $s1, $s1, 0xd
.L800F3F68:
/* 08D418 800F3F68 56400004 */  bnezl $s2, .L800F3F7C
/* 08D41C 800F3F6C 26520001 */   addiu $s2, $s2, 1
/* 08D420 800F3F70 8FAA0024 */  lw    $t2, 0x24($sp)
/* 08D424 800F3F74 022A8821 */  addu  $s1, $s1, $t2
.L800F3F78:
/* 08D428 800F3F78 26520001 */  addiu $s2, $s2, 1
.L800F3F7C:
/* 08D42C 800F3F7C 3C028011 */  lui   $v0, 0x8011
/* 08D430 800F3F80 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D434 800F3F84 8FAB002C */  lw    $t3, 0x2c($sp)
/* 08D438 800F3F88 8C420324 */  lw    $v0, 0x324($v0)
/* 08D43C 800F3F8C 256B0004 */  addiu $t3, $t3, 4
/* 08D440 800F3F90 0242102A */  slt   $v0, $s2, $v0
/* 08D444 800F3F94 1440FF19 */  bnez  $v0, .L800F3BFC
/* 08D448 800F3F98 AFAB002C */   sw    $t3, 0x2c($sp)
.L800F3F9C:
/* 08D44C 800F3F9C 8FAA005C */  lw    $t2, 0x5c($sp)
/* 08D450 800F3FA0 3C028011 */  lui   $v0, 0x8011
/* 08D454 800F3FA4 8442D658 */  lh    $v0, -0x29a8($v0)
/* 08D458 800F3FA8 8FAB0060 */  lw    $t3, 0x60($sp)
/* 08D45C 800F3FAC AFA00024 */  sw    $zero, 0x24($sp)
/* 08D460 800F3FB0 254A0018 */  addiu $t2, $t2, 0x18
/* 08D464 800F3FB4 01622021 */  addu  $a0, $t3, $v0
/* 08D468 800F3FB8 3C028011 */  lui   $v0, 0x8011
/* 08D46C 800F3FBC 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D470 800F3FC0 AFAA0020 */  sw    $t2, 0x20($sp)
/* 08D474 800F3FC4 8C430318 */  lw    $v1, 0x318($v0)
/* 08D478 800F3FC8 24020002 */  addiu $v0, $zero, 2
/* 08D47C 800F3FCC 14620004 */  bne   $v1, $v0, .L800F3FE0
/* 08D480 800F3FD0 24910008 */   addiu $s1, $a0, 8
/* 08D484 800F3FD4 24910006 */  addiu $s1, $a0, 6
/* 08D488 800F3FD8 0040502D */  daddu $t2, $v0, $zero
/* 08D48C 800F3FDC AFAA0024 */  sw    $t2, 0x24($sp)
.L800F3FE0:
/* 08D490 800F3FE0 2C62000E */  sltiu $v0, $v1, 0xe
/* 08D494 800F3FE4 104000B2 */  beqz  $v0, .L800F42B0
/* 08D498 800F3FE8 00031080 */   sll   $v0, $v1, 2
/* 08D49C 800F3FEC 3C018011 */  lui   $at, 0x8011
/* 08D4A0 800F3FF0 00220821 */  addu  $at, $at, $v0
/* 08D4A4 800F3FF4 8C22C800 */  lw    $v0, -0x3800($at)
/* 08D4A8 800F3FF8 00400008 */  jr    $v0
/* 08D4AC 800F3FFC 00000000 */   nop   
/* 08D4B0 800F4000 3C028011 */  lui   $v0, 0x8011
/* 08D4B4 800F4004 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D4B8 800F4008 8C420324 */  lw    $v0, 0x324($v0)
/* 08D4BC 800F400C 184000A8 */  blez  $v0, .L800F42B0
/* 08D4C0 800F4010 0000902D */   daddu $s2, $zero, $zero
/* 08D4C4 800F4014 8FAB0028 */  lw    $t3, 0x28($sp)
/* 08D4C8 800F4018 2573FFFF */  addiu $s3, $t3, -1
/* 08D4CC 800F401C 0253102A */  slt   $v0, $s2, $s3
.L800F4020:
/* 08D4D0 800F4020 14400008 */  bnez  $v0, .L800F4044
/* 08D4D4 800F4024 00000000 */   nop   
/* 08D4D8 800F4028 3C028011 */  lui   $v0, 0x8011
/* 08D4DC 800F402C 8042D656 */  lb    $v0, -0x29aa($v0)
/* 08D4E0 800F4030 8FAA0028 */  lw    $t2, 0x28($sp)
/* 08D4E4 800F4034 01421021 */  addu  $v0, $t2, $v0
/* 08D4E8 800F4038 0052102A */  slt   $v0, $v0, $s2
/* 08D4EC 800F403C 10400006 */  beqz  $v0, .L800F4058
/* 08D4F0 800F4040 00121880 */   sll   $v1, $s2, 2
.L800F4044:
/* 08D4F4 800F4044 1640001F */  bnez  $s2, .L800F40C4
/* 08D4F8 800F4048 2631000D */   addiu $s1, $s1, 0xd
/* 08D4FC 800F404C 8FAB0024 */  lw    $t3, 0x24($sp)
/* 08D500 800F4050 0803D031 */  j     .L800F40C4
/* 08D504 800F4054 022B8821 */   addu  $s1, $s1, $t3

.L800F4058:
/* 08D508 800F4058 3C028011 */  lui   $v0, 0x8011
/* 08D50C 800F405C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D510 800F4060 3C108011 */  lui   $s0, 0x8011
/* 08D514 800F4064 8E10D678 */  lw    $s0, -0x2988($s0)
/* 08D518 800F4068 00431021 */  addu  $v0, $v0, $v1
/* 08D51C 800F406C 8C450000 */  lw    $a1, ($v0)
/* 08D520 800F4070 0C0511FF */  jal   set_menu_icon_script
/* 08D524 800F4074 0200202D */   daddu $a0, $s0, $zero
/* 08D528 800F4078 0200202D */  daddu $a0, $s0, $zero
/* 08D52C 800F407C 8FA50020 */  lw    $a1, 0x20($sp)
/* 08D530 800F4080 0C051261 */  jal   set_icon_render_pos
/* 08D534 800F4084 0220302D */   daddu $a2, $s1, $zero
/* 08D538 800F4088 0200202D */  daddu $a0, $s0, $zero
/* 08D53C 800F408C 3C058011 */  lui   $a1, 0x8011
/* 08D540 800F4090 8CA5D650 */  lw    $a1, -0x29b0($a1)
/* 08D544 800F4094 0C0513AC */  jal   func_80144EB0
/* 08D548 800F4098 2631000D */   addiu $s1, $s1, 0xd
/* 08D54C 800F409C 3C053EE6 */  lui   $a1, 0x3ee6
/* 08D550 800F40A0 34A56666 */  ori   $a1, $a1, 0x6666
/* 08D554 800F40A4 0C051308 */  jal   func_80144C20
/* 08D558 800F40A8 0200202D */   daddu $a0, $s0, $zero
/* 08D55C 800F40AC 0C0511F8 */  jal   func_801447E0
/* 08D560 800F40B0 0200202D */   daddu $a0, $s0, $zero
/* 08D564 800F40B4 16400003 */  bnez  $s2, .L800F40C4
/* 08D568 800F40B8 00000000 */   nop   
/* 08D56C 800F40BC 8FAA0024 */  lw    $t2, 0x24($sp)
/* 08D570 800F40C0 022A8821 */  addu  $s1, $s1, $t2
.L800F40C4:
/* 08D574 800F40C4 3C028011 */  lui   $v0, 0x8011
/* 08D578 800F40C8 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D57C 800F40CC 8C420324 */  lw    $v0, 0x324($v0)
/* 08D580 800F40D0 26520001 */  addiu $s2, $s2, 1
/* 08D584 800F40D4 0242102A */  slt   $v0, $s2, $v0
/* 08D588 800F40D8 1440FFD1 */  bnez  $v0, .L800F4020
/* 08D58C 800F40DC 0253102A */   slt   $v0, $s2, $s3
/* 08D590 800F40E0 0803D0AC */  j     .L800F42B0
/* 08D594 800F40E4 00000000 */   nop   

/* 08D598 800F40E8 3C028011 */  lui   $v0, 0x8011
/* 08D59C 800F40EC 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D5A0 800F40F0 8C420324 */  lw    $v0, 0x324($v0)
/* 08D5A4 800F40F4 1840006E */  blez  $v0, .L800F42B0
/* 08D5A8 800F40F8 0000902D */   daddu $s2, $zero, $zero
/* 08D5AC 800F40FC 8FAB0028 */  lw    $t3, 0x28($sp)
/* 08D5B0 800F4100 2573FFFF */  addiu $s3, $t3, -1
/* 08D5B4 800F4104 0253102A */  slt   $v0, $s2, $s3
.L800F4108:
/* 08D5B8 800F4108 14400008 */  bnez  $v0, .L800F412C
/* 08D5BC 800F410C 00000000 */   nop   
/* 08D5C0 800F4110 3C028011 */  lui   $v0, 0x8011
/* 08D5C4 800F4114 8042D656 */  lb    $v0, -0x29aa($v0)
/* 08D5C8 800F4118 8FAA0028 */  lw    $t2, 0x28($sp)
/* 08D5CC 800F411C 01421021 */  addu  $v0, $t2, $v0
/* 08D5D0 800F4120 0052102A */  slt   $v0, $v0, $s2
/* 08D5D4 800F4124 10400006 */  beqz  $v0, .L800F4140
/* 08D5D8 800F4128 00121880 */   sll   $v1, $s2, 2
.L800F412C:
/* 08D5DC 800F412C 1640001F */  bnez  $s2, .L800F41AC
/* 08D5E0 800F4130 2631000D */   addiu $s1, $s1, 0xd
/* 08D5E4 800F4134 8FAB0024 */  lw    $t3, 0x24($sp)
/* 08D5E8 800F4138 0803D06B */  j     .L800F41AC
/* 08D5EC 800F413C 022B8821 */   addu  $s1, $s1, $t3

.L800F4140:
/* 08D5F0 800F4140 3C028011 */  lui   $v0, 0x8011
/* 08D5F4 800F4144 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D5F8 800F4148 3C108011 */  lui   $s0, 0x8011
/* 08D5FC 800F414C 8E10D678 */  lw    $s0, -0x2988($s0)
/* 08D600 800F4150 00431021 */  addu  $v0, $v0, $v1
/* 08D604 800F4154 8C450000 */  lw    $a1, ($v0)
/* 08D608 800F4158 0C0511FF */  jal   set_menu_icon_script
/* 08D60C 800F415C 0200202D */   daddu $a0, $s0, $zero
/* 08D610 800F4160 0200202D */  daddu $a0, $s0, $zero
/* 08D614 800F4164 8FA50020 */  lw    $a1, 0x20($sp)
/* 08D618 800F4168 0C051261 */  jal   set_icon_render_pos
/* 08D61C 800F416C 0220302D */   daddu $a2, $s1, $zero
/* 08D620 800F4170 0200202D */  daddu $a0, $s0, $zero
/* 08D624 800F4174 3C058011 */  lui   $a1, 0x8011
/* 08D628 800F4178 8CA5D650 */  lw    $a1, -0x29b0($a1)
/* 08D62C 800F417C 0C0513AC */  jal   func_80144EB0
/* 08D630 800F4180 2631000D */   addiu $s1, $s1, 0xd
/* 08D634 800F4184 3C053EE6 */  lui   $a1, 0x3ee6
/* 08D638 800F4188 34A56666 */  ori   $a1, $a1, 0x6666
/* 08D63C 800F418C 0C051308 */  jal   func_80144C20
/* 08D640 800F4190 0200202D */   daddu $a0, $s0, $zero
/* 08D644 800F4194 0C0511F8 */  jal   func_801447E0
/* 08D648 800F4198 0200202D */   daddu $a0, $s0, $zero
/* 08D64C 800F419C 16400003 */  bnez  $s2, .L800F41AC
/* 08D650 800F41A0 00000000 */   nop   
/* 08D654 800F41A4 8FAA0024 */  lw    $t2, 0x24($sp)
/* 08D658 800F41A8 022A8821 */  addu  $s1, $s1, $t2
.L800F41AC:
/* 08D65C 800F41AC 3C028011 */  lui   $v0, 0x8011
/* 08D660 800F41B0 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D664 800F41B4 8C420324 */  lw    $v0, 0x324($v0)
/* 08D668 800F41B8 26520001 */  addiu $s2, $s2, 1
/* 08D66C 800F41BC 0242102A */  slt   $v0, $s2, $v0
/* 08D670 800F41C0 1440FFD1 */  bnez  $v0, .L800F4108
/* 08D674 800F41C4 0253102A */   slt   $v0, $s2, $s3
/* 08D678 800F41C8 0803D0AC */  j     .L800F42B0
/* 08D67C 800F41CC 00000000 */   nop   

/* 08D680 800F41D0 3C028011 */  lui   $v0, 0x8011
/* 08D684 800F41D4 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D688 800F41D8 8C420324 */  lw    $v0, 0x324($v0)
/* 08D68C 800F41DC 18400034 */  blez  $v0, .L800F42B0
/* 08D690 800F41E0 0000902D */   daddu $s2, $zero, $zero
/* 08D694 800F41E4 8FAB0028 */  lw    $t3, 0x28($sp)
/* 08D698 800F41E8 2573FFFF */  addiu $s3, $t3, -1
/* 08D69C 800F41EC 0253102A */  slt   $v0, $s2, $s3
.L800F41F0:
/* 08D6A0 800F41F0 14400008 */  bnez  $v0, .L800F4214
/* 08D6A4 800F41F4 00000000 */   nop   
/* 08D6A8 800F41F8 3C028011 */  lui   $v0, 0x8011
/* 08D6AC 800F41FC 8042D656 */  lb    $v0, -0x29aa($v0)
/* 08D6B0 800F4200 8FAA0028 */  lw    $t2, 0x28($sp)
/* 08D6B4 800F4204 01421021 */  addu  $v0, $t2, $v0
/* 08D6B8 800F4208 0052102A */  slt   $v0, $v0, $s2
/* 08D6BC 800F420C 10400006 */  beqz  $v0, .L800F4228
/* 08D6C0 800F4210 00121880 */   sll   $v1, $s2, 2
.L800F4214:
/* 08D6C4 800F4214 1640001F */  bnez  $s2, .L800F4294
/* 08D6C8 800F4218 2631000D */   addiu $s1, $s1, 0xd
/* 08D6CC 800F421C 8FAB0024 */  lw    $t3, 0x24($sp)
/* 08D6D0 800F4220 0803D0A5 */  j     .L800F4294
/* 08D6D4 800F4224 022B8821 */   addu  $s1, $s1, $t3

.L800F4228:
/* 08D6D8 800F4228 3C028011 */  lui   $v0, 0x8011
/* 08D6DC 800F422C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D6E0 800F4230 3C108011 */  lui   $s0, 0x8011
/* 08D6E4 800F4234 8E10D678 */  lw    $s0, -0x2988($s0)
/* 08D6E8 800F4238 00431021 */  addu  $v0, $v0, $v1
/* 08D6EC 800F423C 8C450000 */  lw    $a1, ($v0)
/* 08D6F0 800F4240 0C0511FF */  jal   set_menu_icon_script
/* 08D6F4 800F4244 0200202D */   daddu $a0, $s0, $zero
/* 08D6F8 800F4248 0200202D */  daddu $a0, $s0, $zero
/* 08D6FC 800F424C 8FA50020 */  lw    $a1, 0x20($sp)
/* 08D700 800F4250 0C051261 */  jal   set_icon_render_pos
/* 08D704 800F4254 0220302D */   daddu $a2, $s1, $zero
/* 08D708 800F4258 0200202D */  daddu $a0, $s0, $zero
/* 08D70C 800F425C 3C058011 */  lui   $a1, 0x8011
/* 08D710 800F4260 8CA5D650 */  lw    $a1, -0x29b0($a1)
/* 08D714 800F4264 0C0513AC */  jal   func_80144EB0
/* 08D718 800F4268 2631000D */   addiu $s1, $s1, 0xd
/* 08D71C 800F426C 3C053EE6 */  lui   $a1, 0x3ee6
/* 08D720 800F4270 34A56666 */  ori   $a1, $a1, 0x6666
/* 08D724 800F4274 0C051308 */  jal   func_80144C20
/* 08D728 800F4278 0200202D */   daddu $a0, $s0, $zero
/* 08D72C 800F427C 0C0511F8 */  jal   func_801447E0
/* 08D730 800F4280 0200202D */   daddu $a0, $s0, $zero
/* 08D734 800F4284 16400003 */  bnez  $s2, .L800F4294
/* 08D738 800F4288 00000000 */   nop   
/* 08D73C 800F428C 8FAA0024 */  lw    $t2, 0x24($sp)
/* 08D740 800F4290 022A8821 */  addu  $s1, $s1, $t2
.L800F4294:
/* 08D744 800F4294 3C028011 */  lui   $v0, 0x8011
/* 08D748 800F4298 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D74C 800F429C 8C420324 */  lw    $v0, 0x324($v0)
/* 08D750 800F42A0 26520001 */  addiu $s2, $s2, 1
/* 08D754 800F42A4 0242102A */  slt   $v0, $s2, $v0
/* 08D758 800F42A8 1440FFD1 */  bnez  $v0, .L800F41F0
/* 08D75C 800F42AC 0253102A */   slt   $v0, $s2, $s3
.L800F42B0:
/* 08D760 800F42B0 8FAB005C */  lw    $t3, 0x5c($sp)
/* 08D764 800F42B4 3C038011 */  lui   $v1, 0x8011
/* 08D768 800F42B8 8063D654 */  lb    $v1, -0x29ac($v1)
/* 08D76C 800F42BC 3C048011 */  lui   $a0, 0x8011
/* 08D770 800F42C0 8C84D648 */  lw    $a0, -0x29b8($a0)
/* 08D774 800F42C4 3C108011 */  lui   $s0, 0x8011
/* 08D778 800F42C8 8E10D66C */  lw    $s0, -0x2994($s0)
/* 08D77C 800F42CC 8FAA0060 */  lw    $t2, 0x60($sp)
/* 08D780 800F42D0 256B0008 */  addiu $t3, $t3, 8
/* 08D784 800F42D4 00831823 */  subu  $v1, $a0, $v1
/* 08D788 800F42D8 00031040 */  sll   $v0, $v1, 1
/* 08D78C 800F42DC 00431021 */  addu  $v0, $v0, $v1
/* 08D790 800F42E0 00021080 */  sll   $v0, $v0, 2
/* 08D794 800F42E4 00431021 */  addu  $v0, $v0, $v1
/* 08D798 800F42E8 24420009 */  addiu $v0, $v0, 9
/* 08D79C 800F42EC 3C038011 */  lui   $v1, 0x8011
/* 08D7A0 800F42F0 8C63D69C */  lw    $v1, -0x2964($v1)
/* 08D7A4 800F42F4 01428821 */  addu  $s1, $t2, $v0
/* 08D7A8 800F42F8 AFAB0020 */  sw    $t3, 0x20($sp)
/* 08D7AC 800F42FC 8C630318 */  lw    $v1, 0x318($v1)
/* 08D7B0 800F4300 24020002 */  addiu $v0, $zero, 2
/* 08D7B4 800F4304 54620004 */  bnel  $v1, $v0, .L800F4318
/* 08D7B8 800F4308 0200202D */   daddu $a0, $s0, $zero
/* 08D7BC 800F430C 50800001 */  beql  $a0, $zero, .L800F4314
/* 08D7C0 800F4310 2631FFFE */   addiu $s1, $s1, -2
.L800F4314:
/* 08D7C4 800F4314 0200202D */  daddu $a0, $s0, $zero
.L800F4318:
/* 08D7C8 800F4318 8FA50020 */  lw    $a1, 0x20($sp)
/* 08D7CC 800F431C 0C051261 */  jal   set_icon_render_pos
/* 08D7D0 800F4320 0220302D */   daddu $a2, $s1, $zero
/* 08D7D4 800F4324 3C058011 */  lui   $a1, 0x8011
/* 08D7D8 800F4328 8CA5D650 */  lw    $a1, -0x29b0($a1)
/* 08D7DC 800F432C 0C0513AC */  jal   func_80144EB0
/* 08D7E0 800F4330 0200202D */   daddu $a0, $s0, $zero
/* 08D7E4 800F4334 0C0511F8 */  jal   func_801447E0
/* 08D7E8 800F4338 0200202D */   daddu $a0, $s0, $zero
/* 08D7EC 800F433C 8FAB005C */  lw    $t3, 0x5c($sp)
/* 08D7F0 800F4340 8FAA0060 */  lw    $t2, 0x60($sp)
/* 08D7F4 800F4344 3C038011 */  lui   $v1, 0x8011
/* 08D7F8 800F4348 8063D656 */  lb    $v1, -0x29aa($v1)
/* 08D7FC 800F434C 2551FFFA */  addiu $s1, $t2, -6
/* 08D800 800F4350 00031040 */  sll   $v0, $v1, 1
/* 08D804 800F4354 00431021 */  addu  $v0, $v0, $v1
/* 08D808 800F4358 00021080 */  sll   $v0, $v0, 2
/* 08D80C 800F435C 00431021 */  addu  $v0, $v0, $v1
/* 08D810 800F4360 3C038011 */  lui   $v1, 0x8011
/* 08D814 800F4364 8C63D69C */  lw    $v1, -0x2964($v1)
/* 08D818 800F4368 02221021 */  addu  $v0, $s1, $v0
/* 08D81C 800F436C AFAB0020 */  sw    $t3, 0x20($sp)
/* 08D820 800F4370 8C630318 */  lw    $v1, 0x318($v1)
/* 08D824 800F4374 24480010 */  addiu $t0, $v0, 0x10
/* 08D828 800F4378 2C62000E */  sltiu $v0, $v1, 0xe
/* 08D82C 800F437C 1040004F */  beqz  $v0, .L800F44BC
/* 08D830 800F4380 00031080 */   sll   $v0, $v1, 2
/* 08D834 800F4384 3C018011 */  lui   $at, 0x8011
/* 08D838 800F4388 00220821 */  addu  $at, $at, $v0
/* 08D83C 800F438C 8C22C838 */  lw    $v0, -0x37c8($at)
/* 08D840 800F4390 00400008 */  jr    $v0
/* 08D844 800F4394 00000000 */   nop   
/* 08D848 800F4398 3C03800A */  lui   $v1, 0x800a
/* 08D84C 800F439C 2463A66C */  addiu $v1, $v1, -0x5994
/* 08D850 800F43A0 C7A20020 */  lwc1  $f2, 0x20($sp)
/* 08D854 800F43A4 468010A0 */  cvt.s.w $f2, $f2
/* 08D858 800F43A8 44910000 */  mtc1  $s1, $f0
/* 08D85C 800F43AC 00000000 */  nop   
/* 08D860 800F43B0 46800020 */  cvt.s.w $f0, $f0
/* 08D864 800F43B4 3C014080 */  lui   $at, 0x4080
/* 08D868 800F43B8 44812000 */  mtc1  $at, $f4
/* 08D86C 800F43BC 8C620000 */  lw    $v0, ($v1)
/* 08D870 800F43C0 46041082 */  mul.s $f2, $f2, $f4
/* 08D874 800F43C4 00000000 */  nop   
/* 08D878 800F43C8 0040282D */  daddu $a1, $v0, $zero
/* 08D87C 800F43CC 24420008 */  addiu $v0, $v0, 8
/* 08D880 800F43D0 AC620000 */  sw    $v0, ($v1)
/* 08D884 800F43D4 8FAB0020 */  lw    $t3, 0x20($sp)
/* 08D888 800F43D8 46040002 */  mul.s $f0, $f0, $f4
/* 08D88C 800F43DC 00000000 */  nop   
/* 08D890 800F43E0 0803D10D */  j     .L800F4434
/* 08D894 800F43E4 25620070 */   addiu $v0, $t3, 0x70

/* 08D898 800F43E8 3C03800A */  lui   $v1, 0x800a
/* 08D89C 800F43EC 2463A66C */  addiu $v1, $v1, -0x5994
/* 08D8A0 800F43F0 C7A20020 */  lwc1  $f2, 0x20($sp)
/* 08D8A4 800F43F4 468010A0 */  cvt.s.w $f2, $f2
/* 08D8A8 800F43F8 44910000 */  mtc1  $s1, $f0
/* 08D8AC 800F43FC 00000000 */  nop   
/* 08D8B0 800F4400 46800020 */  cvt.s.w $f0, $f0
/* 08D8B4 800F4404 3C014080 */  lui   $at, 0x4080
/* 08D8B8 800F4408 44812000 */  mtc1  $at, $f4
/* 08D8BC 800F440C 8C620000 */  lw    $v0, ($v1)
/* 08D8C0 800F4410 46041082 */  mul.s $f2, $f2, $f4
/* 08D8C4 800F4414 00000000 */  nop   
/* 08D8C8 800F4418 0040282D */  daddu $a1, $v0, $zero
/* 08D8CC 800F441C 24420008 */  addiu $v0, $v0, 8
/* 08D8D0 800F4420 AC620000 */  sw    $v0, ($v1)
/* 08D8D4 800F4424 8FAB0020 */  lw    $t3, 0x20($sp)
/* 08D8D8 800F4428 46040002 */  mul.s $f0, $f0, $f4
/* 08D8DC 800F442C 00000000 */  nop   
/* 08D8E0 800F4430 25620064 */  addiu $v0, $t3, 0x64
.L800F4434:
/* 08D8E4 800F4434 4600118D */  trunc.w.s $f6, $f2
/* 08D8E8 800F4438 44033000 */  mfc1  $v1, $f6
/* 08D8EC 800F443C 00000000 */  nop   
/* 08D8F0 800F4440 30630FFF */  andi  $v1, $v1, 0xfff
/* 08D8F4 800F4444 00031B00 */  sll   $v1, $v1, 0xc
/* 08D8F8 800F4448 4600018D */  trunc.w.s $f6, $f0
/* 08D8FC 800F444C 44043000 */  mfc1  $a0, $f6
/* 08D900 800F4450 00000000 */  nop   
/* 08D904 800F4454 30840FFF */  andi  $a0, $a0, 0xfff
/* 08D908 800F4458 44821000 */  mtc1  $v0, $f2
/* 08D90C 800F445C 00000000 */  nop   
/* 08D910 800F4460 468010A0 */  cvt.s.w $f2, $f2
/* 08D914 800F4464 46041082 */  mul.s $f2, $f2, $f4
/* 08D918 800F4468 00000000 */  nop   
/* 08D91C 800F446C 3C02ED00 */  lui   $v0, 0xed00
/* 08D920 800F4470 00822025 */  or    $a0, $a0, $v0
/* 08D924 800F4474 00641825 */  or    $v1, $v1, $a0
/* 08D928 800F4478 44880000 */  mtc1  $t0, $f0
/* 08D92C 800F447C 00000000 */  nop   
/* 08D930 800F4480 46800020 */  cvt.s.w $f0, $f0
/* 08D934 800F4484 46040002 */  mul.s $f0, $f0, $f4
/* 08D938 800F4488 00000000 */  nop   
/* 08D93C 800F448C ACA30000 */  sw    $v1, ($a1)
/* 08D940 800F4490 4600118D */  trunc.w.s $f6, $f2
/* 08D944 800F4494 44023000 */  mfc1  $v0, $f6
/* 08D948 800F4498 00000000 */  nop   
/* 08D94C 800F449C 30420FFF */  andi  $v0, $v0, 0xfff
/* 08D950 800F44A0 00021300 */  sll   $v0, $v0, 0xc
/* 08D954 800F44A4 4600018D */  trunc.w.s $f6, $f0
/* 08D958 800F44A8 44033000 */  mfc1  $v1, $f6
/* 08D95C 800F44AC 00000000 */  nop   
/* 08D960 800F44B0 30630FFF */  andi  $v1, $v1, 0xfff
/* 08D964 800F44B4 00431025 */  or    $v0, $v0, $v1
/* 08D968 800F44B8 ACA20004 */  sw    $v0, 4($a1)
.L800F44BC:
/* 08D96C 800F44BC 3C028011 */  lui   $v0, 0x8011
/* 08D970 800F44C0 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08D974 800F44C4 8C420318 */  lw    $v0, 0x318($v0)
/* 08D978 800F44C8 2443FFFF */  addiu $v1, $v0, -1
/* 08D97C 800F44CC 2C62000D */  sltiu $v0, $v1, 0xd
/* 08D980 800F44D0 10400012 */  beqz  $v0, .L800F451C
/* 08D984 800F44D4 00031080 */   sll   $v0, $v1, 2
/* 08D988 800F44D8 3C018011 */  lui   $at, 0x8011
/* 08D98C 800F44DC 00220821 */  addu  $at, $at, $v0
/* 08D990 800F44E0 8C22C870 */  lw    $v0, -0x3790($at)
/* 08D994 800F44E4 00400008 */  jr    $v0
/* 08D998 800F44E8 00000000 */   nop   
/* 08D99C 800F44EC 0803D150 */  j     .L800F4540
/* 08D9A0 800F44F0 240B0023 */   addiu $t3, $zero, 0x23

/* 08D9A4 800F44F4 240A0023 */  addiu $t2, $zero, 0x23
/* 08D9A8 800F44F8 0803D151 */  j     .L800F4544
/* 08D9AC 800F44FC AFAA0024 */   sw    $t2, 0x24($sp)

/* 08D9B0 800F4500 0803D150 */  j     .L800F4540
/* 08D9B4 800F4504 240B001F */   addiu $t3, $zero, 0x1f

/* 08D9B8 800F4508 240A001F */  addiu $t2, $zero, 0x1f
/* 08D9BC 800F450C 0803D151 */  j     .L800F4544
/* 08D9C0 800F4510 AFAA0024 */   sw    $t2, 0x24($sp)

/* 08D9C4 800F4514 0803D150 */  j     .L800F4540
/* 08D9C8 800F4518 240B001F */   addiu $t3, $zero, 0x1f

.L800F451C:
/* 08D9CC 800F451C 240A0025 */  addiu $t2, $zero, 0x25
/* 08D9D0 800F4520 0803D151 */  j     .L800F4544
/* 08D9D4 800F4524 AFAA0024 */   sw    $t2, 0x24($sp)

/* 08D9D8 800F4528 0803D150 */  j     .L800F4540
/* 08D9DC 800F452C 240B001D */   addiu $t3, $zero, 0x1d

/* 08D9E0 800F4530 240A0015 */  addiu $t2, $zero, 0x15
/* 08D9E4 800F4534 0803D151 */  j     .L800F4544
/* 08D9E8 800F4538 AFAA0024 */   sw    $t2, 0x24($sp)

/* 08D9EC 800F453C 240B001E */  addiu $t3, $zero, 0x1e
.L800F4540:
/* 08D9F0 800F4540 AFAB0024 */  sw    $t3, 0x24($sp)
.L800F4544:
/* 08D9F4 800F4544 3C028011 */  lui   $v0, 0x8011
/* 08D9F8 800F4548 8042D654 */  lb    $v0, -0x29ac($v0)
/* 08D9FC 800F454C 18400012 */  blez  $v0, .L800F4598
/* 08DA00 800F4550 00000000 */   nop   
/* 08DA04 800F4554 8FAA005C */  lw    $t2, 0x5c($sp)
/* 08DA08 800F4558 8FAB0024 */  lw    $t3, 0x24($sp)
/* 08DA0C 800F455C 3C108011 */  lui   $s0, 0x8011
/* 08DA10 800F4560 8E10D670 */  lw    $s0, -0x2990($s0)
/* 08DA14 800F4564 014B5021 */  addu  $t2, $t2, $t3
/* 08DA18 800F4568 AFAA0020 */  sw    $t2, 0x20($sp)
/* 08DA1C 800F456C 25450023 */  addiu $a1, $t2, 0x23
/* 08DA20 800F4570 8FAA0060 */  lw    $t2, 0x60($sp)
/* 08DA24 800F4574 0200202D */  daddu $a0, $s0, $zero
/* 08DA28 800F4578 0C051261 */  jal   set_icon_render_pos
/* 08DA2C 800F457C 2546FFFF */   addiu $a2, $t2, -1
/* 08DA30 800F4580 3C058011 */  lui   $a1, 0x8011
/* 08DA34 800F4584 8CA5D650 */  lw    $a1, -0x29b0($a1)
/* 08DA38 800F4588 0C0513AC */  jal   func_80144EB0
/* 08DA3C 800F458C 0200202D */   daddu $a0, $s0, $zero
/* 08DA40 800F4590 0C0511F8 */  jal   func_801447E0
/* 08DA44 800F4594 0200202D */   daddu $a0, $s0, $zero
.L800F4598:
/* 08DA48 800F4598 3C028011 */  lui   $v0, 0x8011
/* 08DA4C 800F459C 8C42D69C */  lw    $v0, -0x2964($v0)
/* 08DA50 800F45A0 3C038011 */  lui   $v1, 0x8011
/* 08DA54 800F45A4 8063D655 */  lb    $v1, -0x29ab($v1)
/* 08DA58 800F45A8 8C420324 */  lw    $v0, 0x324($v0)
/* 08DA5C 800F45AC 0062182A */  slt   $v1, $v1, $v0
/* 08DA60 800F45B0 10600019 */  beqz  $v1, .L800F4618
/* 08DA64 800F45B4 00000000 */   nop   
/* 08DA68 800F45B8 8FAB005C */  lw    $t3, 0x5c($sp)
/* 08DA6C 800F45BC 8FAA0024 */  lw    $t2, 0x24($sp)
/* 08DA70 800F45C0 3C038011 */  lui   $v1, 0x8011
/* 08DA74 800F45C4 8063D68F */  lb    $v1, -0x2971($v1)
/* 08DA78 800F45C8 3C108011 */  lui   $s0, 0x8011
/* 08DA7C 800F45CC 8E10D674 */  lw    $s0, -0x298c($s0)
/* 08DA80 800F45D0 016A5821 */  addu  $t3, $t3, $t2
/* 08DA84 800F45D4 AFAB0020 */  sw    $t3, 0x20($sp)
/* 08DA88 800F45D8 25650023 */  addiu $a1, $t3, 0x23
/* 08DA8C 800F45DC 00031040 */  sll   $v0, $v1, 1
/* 08DA90 800F45E0 00431021 */  addu  $v0, $v0, $v1
/* 08DA94 800F45E4 00021080 */  sll   $v0, $v0, 2
/* 08DA98 800F45E8 00431021 */  addu  $v0, $v0, $v1
/* 08DA9C 800F45EC 8FAB0060 */  lw    $t3, 0x60($sp)
/* 08DAA0 800F45F0 0200202D */  daddu $a0, $s0, $zero
/* 08DAA4 800F45F4 01628821 */  addu  $s1, $t3, $v0
/* 08DAA8 800F45F8 0C051261 */  jal   set_icon_render_pos
/* 08DAAC 800F45FC 26260005 */   addiu $a2, $s1, 5
/* 08DAB0 800F4600 3C058011 */  lui   $a1, 0x8011
/* 08DAB4 800F4604 8CA5D650 */  lw    $a1, -0x29b0($a1)
/* 08DAB8 800F4608 0C0513AC */  jal   func_80144EB0
/* 08DABC 800F460C 0200202D */   daddu $a0, $s0, $zero
/* 08DAC0 800F4610 0C0511F8 */  jal   func_801447E0
/* 08DAC4 800F4614 0200202D */   daddu $a0, $s0, $zero
.L800F4618:
/* 08DAC8 800F4618 8FBF0054 */  lw    $ra, 0x54($sp)
/* 08DACC 800F461C 8FBE0050 */  lw    $fp, 0x50($sp)
/* 08DAD0 800F4620 8FB7004C */  lw    $s7, 0x4c($sp)
/* 08DAD4 800F4624 8FB60048 */  lw    $s6, 0x48($sp)
/* 08DAD8 800F4628 8FB50044 */  lw    $s5, 0x44($sp)
/* 08DADC 800F462C 8FB40040 */  lw    $s4, 0x40($sp)
/* 08DAE0 800F4630 8FB3003C */  lw    $s3, 0x3c($sp)
/* 08DAE4 800F4634 8FB20038 */  lw    $s2, 0x38($sp)
/* 08DAE8 800F4638 8FB10034 */  lw    $s1, 0x34($sp)
/* 08DAEC 800F463C 8FB00030 */  lw    $s0, 0x30($sp)
/* 08DAF0 800F4640 03E00008 */  jr    $ra
/* 08DAF4 800F4644 27BD0058 */   addiu $sp, $sp, 0x58

