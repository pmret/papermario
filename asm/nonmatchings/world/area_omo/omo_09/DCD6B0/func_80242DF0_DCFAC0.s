.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242DF0_DCFAC0
/* DCFAC0 80242DF0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* DCFAC4 80242DF4 AFB3003C */  sw        $s3, 0x3c($sp)
/* DCFAC8 80242DF8 0080982D */  daddu     $s3, $a0, $zero
/* DCFACC 80242DFC AFB40040 */  sw        $s4, 0x40($sp)
/* DCFAD0 80242E00 0000A02D */  daddu     $s4, $zero, $zero
/* DCFAD4 80242E04 3C03800A */  lui       $v1, %hi(D_8009A634)
/* DCFAD8 80242E08 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* DCFADC 80242E0C 3C04800B */  lui       $a0, %hi(gCameras)
/* DCFAE0 80242E10 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* DCFAE4 80242E14 AFBF0044 */  sw        $ra, 0x44($sp)
/* DCFAE8 80242E18 AFB20038 */  sw        $s2, 0x38($sp)
/* DCFAEC 80242E1C AFB10034 */  sw        $s1, 0x34($sp)
/* DCFAF0 80242E20 AFB00030 */  sw        $s0, 0x30($sp)
/* DCFAF4 80242E24 F7B80058 */  sdc1      $f24, 0x58($sp)
/* DCFAF8 80242E28 F7B60050 */  sdc1      $f22, 0x50($sp)
/* DCFAFC 80242E2C F7B40048 */  sdc1      $f20, 0x48($sp)
/* DCFB00 80242E30 8E710148 */  lw        $s1, 0x148($s3)
/* DCFB04 80242E34 00031080 */  sll       $v0, $v1, 2
/* DCFB08 80242E38 00431021 */  addu      $v0, $v0, $v1
/* DCFB0C 80242E3C 00021080 */  sll       $v0, $v0, 2
/* DCFB10 80242E40 00431023 */  subu      $v0, $v0, $v1
/* DCFB14 80242E44 000218C0 */  sll       $v1, $v0, 3
/* DCFB18 80242E48 00431021 */  addu      $v0, $v0, $v1
/* DCFB1C 80242E4C 000210C0 */  sll       $v0, $v0, 3
/* DCFB20 80242E50 10A00002 */  beqz      $a1, .L80242E5C
/* DCFB24 80242E54 00449021 */   addu     $s2, $v0, $a0
/* DCFB28 80242E58 AE600070 */  sw        $zero, 0x70($s3)
.L80242E5C:
/* DCFB2C 80242E5C 0C00FB5A */  jal       get_enemy_safe
/* DCFB30 80242E60 86240008 */   lh       $a0, 8($s1)
/* DCFB34 80242E64 14400006 */  bnez      $v0, .L80242E80
/* DCFB38 80242E68 24020005 */   addiu    $v0, $zero, 5
/* DCFB3C 80242E6C 0260202D */  daddu     $a0, $s3, $zero
/* DCFB40 80242E70 3C05FE36 */  lui       $a1, 0xfe36
/* DCFB44 80242E74 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DCFB48 80242E78 08090C78 */  j         .L802431E0
/* DCFB4C 80242E7C 0000302D */   daddu    $a2, $zero, $zero
.L80242E80:
/* DCFB50 80242E80 8E23006C */  lw        $v1, 0x6c($s1)
/* DCFB54 80242E84 14620005 */  bne       $v1, $v0, .L80242E9C
/* DCFB58 80242E88 0260202D */   daddu    $a0, $s3, $zero
/* DCFB5C 80242E8C 3C05FE36 */  lui       $a1, 0xfe36
/* DCFB60 80242E90 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DCFB64 80242E94 08090C78 */  j         .L802431E0
/* DCFB68 80242E98 0000302D */   daddu    $a2, $zero, $zero
.L80242E9C:
/* DCFB6C 80242E9C 86240008 */  lh        $a0, 8($s1)
/* DCFB70 80242EA0 0C00FB5A */  jal       get_enemy_safe
/* DCFB74 80242EA4 00000000 */   nop
/* DCFB78 80242EA8 14400005 */  bnez      $v0, .L80242EC0
/* DCFB7C 80242EAC 0260202D */   daddu    $a0, $s3, $zero
/* DCFB80 80242EB0 3C05FE36 */  lui       $a1, 0xfe36
/* DCFB84 80242EB4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DCFB88 80242EB8 08090C78 */  j         .L802431E0
/* DCFB8C 80242EBC 0000302D */   daddu    $a2, $zero, $zero
.L80242EC0:
/* DCFB90 80242EC0 86240008 */  lh        $a0, 8($s1)
/* DCFB94 80242EC4 0C00EABB */  jal       get_npc_unsafe
/* DCFB98 80242EC8 00000000 */   nop
/* DCFB9C 80242ECC 8E630070 */  lw        $v1, 0x70($s3)
/* DCFBA0 80242ED0 10600006 */  beqz      $v1, .L80242EEC
/* DCFBA4 80242ED4 0040802D */   daddu    $s0, $v0, $zero
/* DCFBA8 80242ED8 24020001 */  addiu     $v0, $zero, 1
/* DCFBAC 80242EDC 1062003F */  beq       $v1, $v0, .L80242FDC
/* DCFBB0 80242EE0 0000102D */   daddu    $v0, $zero, $zero
/* DCFBB4 80242EE4 08090C88 */  j         .L80243220
/* DCFBB8 80242EE8 00000000 */   nop
.L80242EEC:
/* DCFBBC 80242EEC AFA00010 */  sw        $zero, 0x10($sp)
/* DCFBC0 80242EF0 AFA00014 */  sw        $zero, 0x14($sp)
/* DCFBC4 80242EF4 8E050038 */  lw        $a1, 0x38($s0)
/* DCFBC8 80242EF8 8E06003C */  lw        $a2, 0x3c($s0)
/* DCFBCC 80242EFC 8E070040 */  lw        $a3, 0x40($s0)
/* DCFBD0 80242F00 0C01BECC */  jal       fx_walk_normal
/* DCFBD4 80242F04 24040002 */   addiu    $a0, $zero, 2
/* DCFBD8 80242F08 C64C006C */  lwc1      $f12, 0x6c($s2)
/* DCFBDC 80242F0C 0C00A6C9 */  jal       clamp_angle
/* DCFBE0 80242F10 00000000 */   nop
/* DCFBE4 80242F14 3C018025 */  lui       $at, %hi(D_8024AB20)
/* DCFBE8 80242F18 D438AB20 */  ldc1      $f24, %lo(D_8024AB20)($at)
/* DCFBEC 80242F1C 46000521 */  cvt.d.s   $f20, $f0
/* DCFBF0 80242F20 4638A300 */  add.d     $f12, $f20, $f24
/* DCFBF4 80242F24 3C018025 */  lui       $at, %hi(D_8024AB28)
/* DCFBF8 80242F28 D436AB28 */  ldc1      $f22, %lo(D_8024AB28)($at)
/* DCFBFC 80242F2C 0C00A6C9 */  jal       clamp_angle
/* DCFC00 80242F30 46206320 */   cvt.s.d  $f12, $f12
/* DCFC04 80242F34 4636A500 */  add.d     $f20, $f20, $f22
/* DCFC08 80242F38 4620A320 */  cvt.s.d   $f12, $f20
/* DCFC0C 80242F3C 0C00A6C9 */  jal       clamp_angle
/* DCFC10 80242F40 46000506 */   mov.s    $f20, $f0
/* DCFC14 80242F44 4600A521 */  cvt.d.s   $f20, $f20
/* DCFC18 80242F48 4636A500 */  add.d     $f20, $f20, $f22
/* DCFC1C 80242F4C 46000586 */  mov.s     $f22, $f0
/* DCFC20 80242F50 0C00A6C9 */  jal       clamp_angle
/* DCFC24 80242F54 4620A320 */   cvt.s.d  $f12, $f20
/* DCFC28 80242F58 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DCFC2C 80242F5C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DCFC30 80242F60 C64C006C */  lwc1      $f12, 0x6c($s2)
/* DCFC34 80242F64 C44E0084 */  lwc1      $f14, 0x84($v0)
/* DCFC38 80242F68 0C00A70A */  jal       get_clamped_angle_diff
/* DCFC3C 80242F6C 46000506 */   mov.s    $f20, $f0
/* DCFC40 80242F70 0C00A6C9 */  jal       clamp_angle
/* DCFC44 80242F74 46000306 */   mov.s    $f12, $f0
/* DCFC48 80242F78 46000021 */  cvt.d.s   $f0, $f0
/* DCFC4C 80242F7C 4638003C */  c.lt.d    $f0, $f24
/* DCFC50 80242F80 00000000 */  nop
/* DCFC54 80242F84 45020002 */  bc1fl     .L80242F90
/* DCFC58 80242F88 E614000C */   swc1     $f20, 0xc($s0)
/* DCFC5C 80242F8C E616000C */  swc1      $f22, 0xc($s0)
.L80242F90:
/* DCFC60 80242F90 C6000018 */  lwc1      $f0, 0x18($s0)
/* DCFC64 80242F94 3C018025 */  lui       $at, %hi(D_8024AB30)
/* DCFC68 80242F98 D422AB30 */  ldc1      $f2, %lo(D_8024AB30)($at)
/* DCFC6C 80242F9C 46000021 */  cvt.d.s   $f0, $f0
/* DCFC70 80242FA0 46220002 */  mul.d     $f0, $f0, $f2
/* DCFC74 80242FA4 00000000 */  nop
/* DCFC78 80242FA8 3C013F66 */  lui       $at, 0x3f66
/* DCFC7C 80242FAC 34216666 */  ori       $at, $at, 0x6666
/* DCFC80 80242FB0 44812000 */  mtc1      $at, $f4
/* DCFC84 80242FB4 2402001E */  addiu     $v0, $zero, 0x1e
/* DCFC88 80242FB8 A602008E */  sh        $v0, 0x8e($s0)
/* DCFC8C 80242FBC 3C014120 */  lui       $at, 0x4120
/* DCFC90 80242FC0 44811000 */  mtc1      $at, $f2
/* DCFC94 80242FC4 24020001 */  addiu     $v0, $zero, 1
/* DCFC98 80242FC8 E6040014 */  swc1      $f4, 0x14($s0)
/* DCFC9C 80242FCC E602001C */  swc1      $f2, 0x1c($s0)
/* DCFCA0 80242FD0 46200020 */  cvt.s.d   $f0, $f0
/* DCFCA4 80242FD4 E6000018 */  swc1      $f0, 0x18($s0)
/* DCFCA8 80242FD8 AE620070 */  sw        $v0, 0x70($s3)
.L80242FDC:
/* DCFCAC 80242FDC C6000038 */  lwc1      $f0, 0x38($s0)
/* DCFCB0 80242FE0 C602003C */  lwc1      $f2, 0x3c($s0)
/* DCFCB4 80242FE4 C6040040 */  lwc1      $f4, 0x40($s0)
/* DCFCB8 80242FE8 C6060018 */  lwc1      $f6, 0x18($s0)
/* DCFCBC 80242FEC 0000202D */  daddu     $a0, $zero, $zero
/* DCFCC0 80242FF0 E7A00020 */  swc1      $f0, 0x20($sp)
/* DCFCC4 80242FF4 E7A20024 */  swc1      $f2, 0x24($sp)
/* DCFCC8 80242FF8 E7A40028 */  swc1      $f4, 0x28($sp)
/* DCFCCC 80242FFC E7A60010 */  swc1      $f6, 0x10($sp)
/* DCFCD0 80243000 C600000C */  lwc1      $f0, 0xc($s0)
/* DCFCD4 80243004 27A50020 */  addiu     $a1, $sp, 0x20
/* DCFCD8 80243008 E7A00014 */  swc1      $f0, 0x14($sp)
/* DCFCDC 8024300C 860200A6 */  lh        $v0, 0xa6($s0)
/* DCFCE0 80243010 27A60024 */  addiu     $a2, $sp, 0x24
/* DCFCE4 80243014 44820000 */  mtc1      $v0, $f0
/* DCFCE8 80243018 00000000 */  nop
/* DCFCEC 8024301C 46800020 */  cvt.s.w   $f0, $f0
/* DCFCF0 80243020 E7A00018 */  swc1      $f0, 0x18($sp)
/* DCFCF4 80243024 860200A8 */  lh        $v0, 0xa8($s0)
/* DCFCF8 80243028 27A70028 */  addiu     $a3, $sp, 0x28
/* DCFCFC 8024302C 44820000 */  mtc1      $v0, $f0
/* DCFD00 80243030 00000000 */  nop
/* DCFD04 80243034 46800020 */  cvt.s.w   $f0, $f0
/* DCFD08 80243038 0C037711 */  jal       func_800DDC44
/* DCFD0C 8024303C E7A0001C */   swc1     $f0, 0x1c($sp)
/* DCFD10 80243040 54400007 */  bnel      $v0, $zero, .L80243060
/* DCFD14 80243044 24140001 */   addiu    $s4, $zero, 1
/* DCFD18 80243048 8E050018 */  lw        $a1, 0x18($s0)
/* DCFD1C 8024304C 8E06000C */  lw        $a2, 0xc($s0)
/* DCFD20 80243050 0C00EA95 */  jal       npc_move_heading
/* DCFD24 80243054 0200202D */   daddu    $a0, $s0, $zero
/* DCFD28 80243058 08090C19 */  j         .L80243064
/* DCFD2C 8024305C 0000902D */   daddu    $s2, $zero, $zero
.L80243060:
/* DCFD30 80243060 0000902D */  daddu     $s2, $zero, $zero
.L80243064:
/* DCFD34 80243064 C600001C */  lwc1      $f0, 0x1c($s0)
/* DCFD38 80243068 44801000 */  mtc1      $zero, $f2
/* DCFD3C 8024306C 44801800 */  mtc1      $zero, $f3
/* DCFD40 80243070 46000021 */  cvt.d.s   $f0, $f0
/* DCFD44 80243074 4622003C */  c.lt.d    $f0, $f2
/* DCFD48 80243078 00000000 */  nop
/* DCFD4C 8024307C 45000028 */  bc1f      .L80243120
/* DCFD50 80243080 27A50020 */   addiu    $a1, $sp, 0x20
/* DCFD54 80243084 27A60024 */  addiu     $a2, $sp, 0x24
/* DCFD58 80243088 27A2002C */  addiu     $v0, $sp, 0x2c
/* DCFD5C 8024308C C602003C */  lwc1      $f2, 0x3c($s0)
/* DCFD60 80243090 C6060038 */  lwc1      $f6, 0x38($s0)
/* DCFD64 80243094 3C01402A */  lui       $at, 0x402a
/* DCFD68 80243098 4481A800 */  mtc1      $at, $f21
/* DCFD6C 8024309C 4480A000 */  mtc1      $zero, $f20
/* DCFD70 802430A0 460010A1 */  cvt.d.s   $f2, $f2
/* DCFD74 802430A4 46341080 */  add.d     $f2, $f2, $f20
/* DCFD78 802430A8 C600001C */  lwc1      $f0, 0x1c($s0)
/* DCFD7C 802430AC C6040040 */  lwc1      $f4, 0x40($s0)
/* DCFD80 802430B0 46000005 */  abs.s     $f0, $f0
/* DCFD84 802430B4 E7A40028 */  swc1      $f4, 0x28($sp)
/* DCFD88 802430B8 3C014030 */  lui       $at, 0x4030
/* DCFD8C 802430BC 44812800 */  mtc1      $at, $f5
/* DCFD90 802430C0 44802000 */  mtc1      $zero, $f4
/* DCFD94 802430C4 46000021 */  cvt.d.s   $f0, $f0
/* DCFD98 802430C8 E7A60020 */  swc1      $f6, 0x20($sp)
/* DCFD9C 802430CC 46240000 */  add.d     $f0, $f0, $f4
/* DCFDA0 802430D0 462010A0 */  cvt.s.d   $f2, $f2
/* DCFDA4 802430D4 E7A20024 */  swc1      $f2, 0x24($sp)
/* DCFDA8 802430D8 46200020 */  cvt.s.d   $f0, $f0
/* DCFDAC 802430DC E7A0002C */  swc1      $f0, 0x2c($sp)
/* DCFDB0 802430E0 AFA20010 */  sw        $v0, 0x10($sp)
/* DCFDB4 802430E4 8E040080 */  lw        $a0, 0x80($s0)
/* DCFDB8 802430E8 0C0372DF */  jal       func_800DCB7C
/* DCFDBC 802430EC 27A70028 */   addiu    $a3, $sp, 0x28
/* DCFDC0 802430F0 1040000B */  beqz      $v0, .L80243120
/* DCFDC4 802430F4 00000000 */   nop
/* DCFDC8 802430F8 C600001C */  lwc1      $f0, 0x1c($s0)
/* DCFDCC 802430FC C7A2002C */  lwc1      $f2, 0x2c($sp)
/* DCFDD0 80243100 46000005 */  abs.s     $f0, $f0
/* DCFDD4 80243104 46000021 */  cvt.d.s   $f0, $f0
/* DCFDD8 80243108 46340000 */  add.d     $f0, $f0, $f20
/* DCFDDC 8024310C 460010A1 */  cvt.d.s   $f2, $f2
/* DCFDE0 80243110 4620103E */  c.le.d    $f2, $f0
/* DCFDE4 80243114 00000000 */  nop
/* DCFDE8 80243118 45030001 */  bc1tl     .L80243120
/* DCFDEC 8024311C 24120001 */   addiu    $s2, $zero, 1
.L80243120:
/* DCFDF0 80243120 56400008 */  bnel      $s2, $zero, .L80243144
/* DCFDF4 80243124 2414000A */   addiu    $s4, $zero, 0xa
/* DCFDF8 80243128 C604003C */  lwc1      $f4, 0x3c($s0)
/* DCFDFC 8024312C C600001C */  lwc1      $f0, 0x1c($s0)
/* DCFE00 80243130 46002100 */  add.s     $f4, $f4, $f0
/* DCFE04 80243134 C6020014 */  lwc1      $f2, 0x14($s0)
/* DCFE08 80243138 46020001 */  sub.s     $f0, $f0, $f2
/* DCFE0C 8024313C E604003C */  swc1      $f4, 0x3c($s0)
/* DCFE10 80243140 E600001C */  swc1      $f0, 0x1c($s0)
.L80243144:
/* DCFE14 80243144 9602008E */  lhu       $v0, 0x8e($s0)
/* DCFE18 80243148 2442FFFF */  addiu     $v0, $v0, -1
/* DCFE1C 8024314C A602008E */  sh        $v0, 0x8e($s0)
/* DCFE20 80243150 00021400 */  sll       $v0, $v0, 0x10
/* DCFE24 80243154 58400001 */  blezl     $v0, .L8024315C
/* DCFE28 80243158 2414000B */   addiu    $s4, $zero, 0xb
.L8024315C:
/* DCFE2C 8024315C 12800024 */  beqz      $s4, .L802431F0
/* DCFE30 80243160 00000000 */   nop
/* DCFE34 80243164 AFA00010 */  sw        $zero, 0x10($sp)
/* DCFE38 80243168 AFA00014 */  sw        $zero, 0x14($sp)
/* DCFE3C 8024316C 8E050038 */  lw        $a1, 0x38($s0)
/* DCFE40 80243170 8E06003C */  lw        $a2, 0x3c($s0)
/* DCFE44 80243174 8E070040 */  lw        $a3, 0x40($s0)
/* DCFE48 80243178 0C01BECC */  jal       fx_walk_normal
/* DCFE4C 8024317C 24040002 */   addiu    $a0, $zero, 2
/* DCFE50 80243180 3C01C47A */  lui       $at, 0xc47a
/* DCFE54 80243184 44810000 */  mtc1      $at, $f0
/* DCFE58 80243188 AE20006C */  sw        $zero, 0x6c($s1)
/* DCFE5C 8024318C 8E020000 */  lw        $v0, ($s0)
/* DCFE60 80243190 0200202D */  daddu     $a0, $s0, $zero
/* DCFE64 80243194 AE000038 */  sw        $zero, 0x38($s0)
/* DCFE68 80243198 AE000040 */  sw        $zero, 0x40($s0)
/* DCFE6C 8024319C 34420002 */  ori       $v0, $v0, 2
/* DCFE70 802431A0 E600003C */  swc1      $f0, 0x3c($s0)
/* DCFE74 802431A4 0C00EAFF */  jal       disable_npc_shadow
/* DCFE78 802431A8 AE020000 */   sw       $v0, ($s0)
/* DCFE7C 802431AC 0260202D */  daddu     $a0, $s3, $zero
/* DCFE80 802431B0 3C05FE36 */  lui       $a1, 0xfe36
/* DCFE84 802431B4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DCFE88 802431B8 24060001 */  addiu     $a2, $zero, 1
/* DCFE8C 802431BC 8E020000 */  lw        $v0, ($s0)
/* DCFE90 802431C0 2403F7FF */  addiu     $v1, $zero, -0x801
/* DCFE94 802431C4 00431024 */  and       $v0, $v0, $v1
/* DCFE98 802431C8 AE020000 */  sw        $v0, ($s0)
/* DCFE9C 802431CC 8E220000 */  lw        $v0, ($s1)
/* DCFEA0 802431D0 3C031F00 */  lui       $v1, 0x1f00
/* DCFEA4 802431D4 00431025 */  or        $v0, $v0, $v1
/* DCFEA8 802431D8 AE220000 */  sw        $v0, ($s1)
/* DCFEAC 802431DC AC800070 */  sw        $zero, 0x70($a0)
.L802431E0:
/* DCFEB0 802431E0 0C0B2026 */  jal       set_variable
/* DCFEB4 802431E4 00000000 */   nop
/* DCFEB8 802431E8 08090C88 */  j         .L80243220
/* DCFEBC 802431EC 24020002 */   addiu    $v0, $zero, 2
.L802431F0:
/* DCFEC0 802431F0 8E220070 */  lw        $v0, 0x70($s1)
/* DCFEC4 802431F4 30420001 */  andi      $v0, $v0, 1
/* DCFEC8 802431F8 10400009 */  beqz      $v0, .L80243220
/* DCFECC 802431FC 0000102D */   daddu    $v0, $zero, $zero
/* DCFED0 80243200 C600004C */  lwc1      $f0, 0x4c($s0)
/* DCFED4 80243204 3C01404E */  lui       $at, 0x404e
/* DCFED8 80243208 44811800 */  mtc1      $at, $f3
/* DCFEDC 8024320C 44801000 */  mtc1      $zero, $f2
/* DCFEE0 80243210 46000021 */  cvt.d.s   $f0, $f0
/* DCFEE4 80243214 46220000 */  add.d     $f0, $f0, $f2
/* DCFEE8 80243218 46200020 */  cvt.s.d   $f0, $f0
/* DCFEEC 8024321C E600004C */  swc1      $f0, 0x4c($s0)
.L80243220:
/* DCFEF0 80243220 8FBF0044 */  lw        $ra, 0x44($sp)
/* DCFEF4 80243224 8FB40040 */  lw        $s4, 0x40($sp)
/* DCFEF8 80243228 8FB3003C */  lw        $s3, 0x3c($sp)
/* DCFEFC 8024322C 8FB20038 */  lw        $s2, 0x38($sp)
/* DCFF00 80243230 8FB10034 */  lw        $s1, 0x34($sp)
/* DCFF04 80243234 8FB00030 */  lw        $s0, 0x30($sp)
/* DCFF08 80243238 D7B80058 */  ldc1      $f24, 0x58($sp)
/* DCFF0C 8024323C D7B60050 */  ldc1      $f22, 0x50($sp)
/* DCFF10 80243240 D7B40048 */  ldc1      $f20, 0x48($sp)
/* DCFF14 80243244 03E00008 */  jr        $ra
/* DCFF18 80243248 27BD0060 */   addiu    $sp, $sp, 0x60
