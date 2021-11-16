.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802479B8_DF6858
.double 180.0

dlabel D_802479C0_DF6860
.double 90.0

dlabel D_802479C8_DF6868
.double 1.2

.section .text

glabel func_80242F44_DF1DE4
/* DF1DE4 80242F44 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* DF1DE8 80242F48 AFB3003C */  sw        $s3, 0x3c($sp)
/* DF1DEC 80242F4C 0080982D */  daddu     $s3, $a0, $zero
/* DF1DF0 80242F50 AFB40040 */  sw        $s4, 0x40($sp)
/* DF1DF4 80242F54 0000A02D */  daddu     $s4, $zero, $zero
/* DF1DF8 80242F58 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* DF1DFC 80242F5C 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* DF1E00 80242F60 3C04800B */  lui       $a0, %hi(gCameras)
/* DF1E04 80242F64 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* DF1E08 80242F68 AFBF0044 */  sw        $ra, 0x44($sp)
/* DF1E0C 80242F6C AFB20038 */  sw        $s2, 0x38($sp)
/* DF1E10 80242F70 AFB10034 */  sw        $s1, 0x34($sp)
/* DF1E14 80242F74 AFB00030 */  sw        $s0, 0x30($sp)
/* DF1E18 80242F78 F7B80058 */  sdc1      $f24, 0x58($sp)
/* DF1E1C 80242F7C F7B60050 */  sdc1      $f22, 0x50($sp)
/* DF1E20 80242F80 F7B40048 */  sdc1      $f20, 0x48($sp)
/* DF1E24 80242F84 8E710148 */  lw        $s1, 0x148($s3)
/* DF1E28 80242F88 00031080 */  sll       $v0, $v1, 2
/* DF1E2C 80242F8C 00431021 */  addu      $v0, $v0, $v1
/* DF1E30 80242F90 00021080 */  sll       $v0, $v0, 2
/* DF1E34 80242F94 00431023 */  subu      $v0, $v0, $v1
/* DF1E38 80242F98 000218C0 */  sll       $v1, $v0, 3
/* DF1E3C 80242F9C 00431021 */  addu      $v0, $v0, $v1
/* DF1E40 80242FA0 000210C0 */  sll       $v0, $v0, 3
/* DF1E44 80242FA4 10A00002 */  beqz      $a1, .L80242FB0
/* DF1E48 80242FA8 00449021 */   addu     $s2, $v0, $a0
/* DF1E4C 80242FAC AE600070 */  sw        $zero, 0x70($s3)
.L80242FB0:
/* DF1E50 80242FB0 0C00FB5A */  jal       get_enemy_safe
/* DF1E54 80242FB4 86240008 */   lh       $a0, 8($s1)
/* DF1E58 80242FB8 14400006 */  bnez      $v0, .L80242FD4
/* DF1E5C 80242FBC 24020005 */   addiu    $v0, $zero, 5
/* DF1E60 80242FC0 0260202D */  daddu     $a0, $s3, $zero
/* DF1E64 80242FC4 3C05FE36 */  lui       $a1, 0xfe36
/* DF1E68 80242FC8 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DF1E6C 80242FCC 08090CCD */  j         .L80243334
/* DF1E70 80242FD0 0000302D */   daddu    $a2, $zero, $zero
.L80242FD4:
/* DF1E74 80242FD4 8E23006C */  lw        $v1, 0x6c($s1)
/* DF1E78 80242FD8 14620005 */  bne       $v1, $v0, .L80242FF0
/* DF1E7C 80242FDC 0260202D */   daddu    $a0, $s3, $zero
/* DF1E80 80242FE0 3C05FE36 */  lui       $a1, 0xfe36
/* DF1E84 80242FE4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DF1E88 80242FE8 08090CCD */  j         .L80243334
/* DF1E8C 80242FEC 0000302D */   daddu    $a2, $zero, $zero
.L80242FF0:
/* DF1E90 80242FF0 86240008 */  lh        $a0, 8($s1)
/* DF1E94 80242FF4 0C00FB5A */  jal       get_enemy_safe
/* DF1E98 80242FF8 00000000 */   nop
/* DF1E9C 80242FFC 14400005 */  bnez      $v0, .L80243014
/* DF1EA0 80243000 0260202D */   daddu    $a0, $s3, $zero
/* DF1EA4 80243004 3C05FE36 */  lui       $a1, 0xfe36
/* DF1EA8 80243008 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DF1EAC 8024300C 08090CCD */  j         .L80243334
/* DF1EB0 80243010 0000302D */   daddu    $a2, $zero, $zero
.L80243014:
/* DF1EB4 80243014 86240008 */  lh        $a0, 8($s1)
/* DF1EB8 80243018 0C00EABB */  jal       get_npc_unsafe
/* DF1EBC 8024301C 00000000 */   nop
/* DF1EC0 80243020 8E630070 */  lw        $v1, 0x70($s3)
/* DF1EC4 80243024 10600006 */  beqz      $v1, .L80243040
/* DF1EC8 80243028 0040802D */   daddu    $s0, $v0, $zero
/* DF1ECC 8024302C 24020001 */  addiu     $v0, $zero, 1
/* DF1ED0 80243030 1062003F */  beq       $v1, $v0, .L80243130
/* DF1ED4 80243034 0000102D */   daddu    $v0, $zero, $zero
/* DF1ED8 80243038 08090CDD */  j         .L80243374
/* DF1EDC 8024303C 00000000 */   nop
.L80243040:
/* DF1EE0 80243040 AFA00010 */  sw        $zero, 0x10($sp)
/* DF1EE4 80243044 AFA00014 */  sw        $zero, 0x14($sp)
/* DF1EE8 80243048 8E050038 */  lw        $a1, 0x38($s0)
/* DF1EEC 8024304C 8E06003C */  lw        $a2, 0x3c($s0)
/* DF1EF0 80243050 8E070040 */  lw        $a3, 0x40($s0)
/* DF1EF4 80243054 0C01BECC */  jal       fx_walk
/* DF1EF8 80243058 24040002 */   addiu    $a0, $zero, 2
/* DF1EFC 8024305C C64C006C */  lwc1      $f12, 0x6c($s2)
/* DF1F00 80243060 0C00A6C9 */  jal       clamp_angle
/* DF1F04 80243064 00000000 */   nop
/* DF1F08 80243068 3C018024 */  lui       $at, %hi(D_802479B8_DF6858)
/* DF1F0C 8024306C D43879B8 */  ldc1      $f24, %lo(D_802479B8_DF6858)($at)
/* DF1F10 80243070 46000521 */  cvt.d.s   $f20, $f0
/* DF1F14 80243074 4638A300 */  add.d     $f12, $f20, $f24
/* DF1F18 80243078 3C018024 */  lui       $at, %hi(D_802479C0_DF6860)
/* DF1F1C 8024307C D43679C0 */  ldc1      $f22, %lo(D_802479C0_DF6860)($at)
/* DF1F20 80243080 0C00A6C9 */  jal       clamp_angle
/* DF1F24 80243084 46206320 */   cvt.s.d  $f12, $f12
/* DF1F28 80243088 4636A500 */  add.d     $f20, $f20, $f22
/* DF1F2C 8024308C 4620A320 */  cvt.s.d   $f12, $f20
/* DF1F30 80243090 0C00A6C9 */  jal       clamp_angle
/* DF1F34 80243094 46000506 */   mov.s    $f20, $f0
/* DF1F38 80243098 4600A521 */  cvt.d.s   $f20, $f20
/* DF1F3C 8024309C 4636A500 */  add.d     $f20, $f20, $f22
/* DF1F40 802430A0 46000586 */  mov.s     $f22, $f0
/* DF1F44 802430A4 0C00A6C9 */  jal       clamp_angle
/* DF1F48 802430A8 4620A320 */   cvt.s.d  $f12, $f20
/* DF1F4C 802430AC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DF1F50 802430B0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DF1F54 802430B4 C64C006C */  lwc1      $f12, 0x6c($s2)
/* DF1F58 802430B8 C44E0084 */  lwc1      $f14, 0x84($v0)
/* DF1F5C 802430BC 0C00A70A */  jal       get_clamped_angle_diff
/* DF1F60 802430C0 46000506 */   mov.s    $f20, $f0
/* DF1F64 802430C4 0C00A6C9 */  jal       clamp_angle
/* DF1F68 802430C8 46000306 */   mov.s    $f12, $f0
/* DF1F6C 802430CC 46000021 */  cvt.d.s   $f0, $f0
/* DF1F70 802430D0 4638003C */  c.lt.d    $f0, $f24
/* DF1F74 802430D4 00000000 */  nop
/* DF1F78 802430D8 45020002 */  bc1fl     .L802430E4
/* DF1F7C 802430DC E614000C */   swc1     $f20, 0xc($s0)
/* DF1F80 802430E0 E616000C */  swc1      $f22, 0xc($s0)
.L802430E4:
/* DF1F84 802430E4 C6000018 */  lwc1      $f0, 0x18($s0)
/* DF1F88 802430E8 3C018024 */  lui       $at, %hi(D_802479C8_DF6868)
/* DF1F8C 802430EC D42279C8 */  ldc1      $f2, %lo(D_802479C8_DF6868)($at)
/* DF1F90 802430F0 46000021 */  cvt.d.s   $f0, $f0
/* DF1F94 802430F4 46220002 */  mul.d     $f0, $f0, $f2
/* DF1F98 802430F8 00000000 */  nop
/* DF1F9C 802430FC 3C013F66 */  lui       $at, 0x3f66
/* DF1FA0 80243100 34216666 */  ori       $at, $at, 0x6666
/* DF1FA4 80243104 44812000 */  mtc1      $at, $f4
/* DF1FA8 80243108 2402001E */  addiu     $v0, $zero, 0x1e
/* DF1FAC 8024310C A602008E */  sh        $v0, 0x8e($s0)
/* DF1FB0 80243110 3C014120 */  lui       $at, 0x4120
/* DF1FB4 80243114 44811000 */  mtc1      $at, $f2
/* DF1FB8 80243118 24020001 */  addiu     $v0, $zero, 1
/* DF1FBC 8024311C E6040014 */  swc1      $f4, 0x14($s0)
/* DF1FC0 80243120 E602001C */  swc1      $f2, 0x1c($s0)
/* DF1FC4 80243124 46200020 */  cvt.s.d   $f0, $f0
/* DF1FC8 80243128 E6000018 */  swc1      $f0, 0x18($s0)
/* DF1FCC 8024312C AE620070 */  sw        $v0, 0x70($s3)
.L80243130:
/* DF1FD0 80243130 C6000038 */  lwc1      $f0, 0x38($s0)
/* DF1FD4 80243134 C602003C */  lwc1      $f2, 0x3c($s0)
/* DF1FD8 80243138 C6040040 */  lwc1      $f4, 0x40($s0)
/* DF1FDC 8024313C C6060018 */  lwc1      $f6, 0x18($s0)
/* DF1FE0 80243140 0000202D */  daddu     $a0, $zero, $zero
/* DF1FE4 80243144 E7A00020 */  swc1      $f0, 0x20($sp)
/* DF1FE8 80243148 E7A20024 */  swc1      $f2, 0x24($sp)
/* DF1FEC 8024314C E7A40028 */  swc1      $f4, 0x28($sp)
/* DF1FF0 80243150 E7A60010 */  swc1      $f6, 0x10($sp)
/* DF1FF4 80243154 C600000C */  lwc1      $f0, 0xc($s0)
/* DF1FF8 80243158 27A50020 */  addiu     $a1, $sp, 0x20
/* DF1FFC 8024315C E7A00014 */  swc1      $f0, 0x14($sp)
/* DF2000 80243160 860200A6 */  lh        $v0, 0xa6($s0)
/* DF2004 80243164 27A60024 */  addiu     $a2, $sp, 0x24
/* DF2008 80243168 44820000 */  mtc1      $v0, $f0
/* DF200C 8024316C 00000000 */  nop
/* DF2010 80243170 46800020 */  cvt.s.w   $f0, $f0
/* DF2014 80243174 E7A00018 */  swc1      $f0, 0x18($sp)
/* DF2018 80243178 860200A8 */  lh        $v0, 0xa8($s0)
/* DF201C 8024317C 27A70028 */  addiu     $a3, $sp, 0x28
/* DF2020 80243180 44820000 */  mtc1      $v0, $f0
/* DF2024 80243184 00000000 */  nop
/* DF2028 80243188 46800020 */  cvt.s.w   $f0, $f0
/* DF202C 8024318C 0C037711 */  jal       npc_test_move_simple_with_slipping
/* DF2030 80243190 E7A0001C */   swc1     $f0, 0x1c($sp)
/* DF2034 80243194 54400007 */  bnel      $v0, $zero, .L802431B4
/* DF2038 80243198 24140001 */   addiu    $s4, $zero, 1
/* DF203C 8024319C 8E050018 */  lw        $a1, 0x18($s0)
/* DF2040 802431A0 8E06000C */  lw        $a2, 0xc($s0)
/* DF2044 802431A4 0C00EA95 */  jal       npc_move_heading
/* DF2048 802431A8 0200202D */   daddu    $a0, $s0, $zero
/* DF204C 802431AC 08090C6E */  j         .L802431B8
/* DF2050 802431B0 0000902D */   daddu    $s2, $zero, $zero
.L802431B4:
/* DF2054 802431B4 0000902D */  daddu     $s2, $zero, $zero
.L802431B8:
/* DF2058 802431B8 C600001C */  lwc1      $f0, 0x1c($s0)
/* DF205C 802431BC 44801000 */  mtc1      $zero, $f2
/* DF2060 802431C0 44801800 */  mtc1      $zero, $f3
/* DF2064 802431C4 46000021 */  cvt.d.s   $f0, $f0
/* DF2068 802431C8 4622003C */  c.lt.d    $f0, $f2
/* DF206C 802431CC 00000000 */  nop
/* DF2070 802431D0 45000028 */  bc1f      .L80243274
/* DF2074 802431D4 27A50020 */   addiu    $a1, $sp, 0x20
/* DF2078 802431D8 27A60024 */  addiu     $a2, $sp, 0x24
/* DF207C 802431DC 27A2002C */  addiu     $v0, $sp, 0x2c
/* DF2080 802431E0 C602003C */  lwc1      $f2, 0x3c($s0)
/* DF2084 802431E4 C6060038 */  lwc1      $f6, 0x38($s0)
/* DF2088 802431E8 3C01402A */  lui       $at, 0x402a
/* DF208C 802431EC 4481A800 */  mtc1      $at, $f21
/* DF2090 802431F0 4480A000 */  mtc1      $zero, $f20
/* DF2094 802431F4 460010A1 */  cvt.d.s   $f2, $f2
/* DF2098 802431F8 46341080 */  add.d     $f2, $f2, $f20
/* DF209C 802431FC C600001C */  lwc1      $f0, 0x1c($s0)
/* DF20A0 80243200 C6040040 */  lwc1      $f4, 0x40($s0)
/* DF20A4 80243204 46000005 */  abs.s     $f0, $f0
/* DF20A8 80243208 E7A40028 */  swc1      $f4, 0x28($sp)
/* DF20AC 8024320C 3C014030 */  lui       $at, 0x4030
/* DF20B0 80243210 44812800 */  mtc1      $at, $f5
/* DF20B4 80243214 44802000 */  mtc1      $zero, $f4
/* DF20B8 80243218 46000021 */  cvt.d.s   $f0, $f0
/* DF20BC 8024321C E7A60020 */  swc1      $f6, 0x20($sp)
/* DF20C0 80243220 46240000 */  add.d     $f0, $f0, $f4
/* DF20C4 80243224 462010A0 */  cvt.s.d   $f2, $f2
/* DF20C8 80243228 E7A20024 */  swc1      $f2, 0x24($sp)
/* DF20CC 8024322C 46200020 */  cvt.s.d   $f0, $f0
/* DF20D0 80243230 E7A0002C */  swc1      $f0, 0x2c($sp)
/* DF20D4 80243234 AFA20010 */  sw        $v0, 0x10($sp)
/* DF20D8 80243238 8E040080 */  lw        $a0, 0x80($s0)
/* DF20DC 8024323C 0C0372DF */  jal       npc_raycast_down_sides
/* DF20E0 80243240 27A70028 */   addiu    $a3, $sp, 0x28
/* DF20E4 80243244 1040000B */  beqz      $v0, .L80243274
/* DF20E8 80243248 00000000 */   nop
/* DF20EC 8024324C C600001C */  lwc1      $f0, 0x1c($s0)
/* DF20F0 80243250 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* DF20F4 80243254 46000005 */  abs.s     $f0, $f0
/* DF20F8 80243258 46000021 */  cvt.d.s   $f0, $f0
/* DF20FC 8024325C 46340000 */  add.d     $f0, $f0, $f20
/* DF2100 80243260 460010A1 */  cvt.d.s   $f2, $f2
/* DF2104 80243264 4620103E */  c.le.d    $f2, $f0
/* DF2108 80243268 00000000 */  nop
/* DF210C 8024326C 45030001 */  bc1tl     .L80243274
/* DF2110 80243270 24120001 */   addiu    $s2, $zero, 1
.L80243274:
/* DF2114 80243274 56400008 */  bnel      $s2, $zero, .L80243298
/* DF2118 80243278 2414000A */   addiu    $s4, $zero, 0xa
/* DF211C 8024327C C604003C */  lwc1      $f4, 0x3c($s0)
/* DF2120 80243280 C600001C */  lwc1      $f0, 0x1c($s0)
/* DF2124 80243284 46002100 */  add.s     $f4, $f4, $f0
/* DF2128 80243288 C6020014 */  lwc1      $f2, 0x14($s0)
/* DF212C 8024328C 46020001 */  sub.s     $f0, $f0, $f2
/* DF2130 80243290 E604003C */  swc1      $f4, 0x3c($s0)
/* DF2134 80243294 E600001C */  swc1      $f0, 0x1c($s0)
.L80243298:
/* DF2138 80243298 9602008E */  lhu       $v0, 0x8e($s0)
/* DF213C 8024329C 2442FFFF */  addiu     $v0, $v0, -1
/* DF2140 802432A0 A602008E */  sh        $v0, 0x8e($s0)
/* DF2144 802432A4 00021400 */  sll       $v0, $v0, 0x10
/* DF2148 802432A8 58400001 */  blezl     $v0, .L802432B0
/* DF214C 802432AC 2414000B */   addiu    $s4, $zero, 0xb
.L802432B0:
/* DF2150 802432B0 12800024 */  beqz      $s4, .L80243344
/* DF2154 802432B4 00000000 */   nop
/* DF2158 802432B8 AFA00010 */  sw        $zero, 0x10($sp)
/* DF215C 802432BC AFA00014 */  sw        $zero, 0x14($sp)
/* DF2160 802432C0 8E050038 */  lw        $a1, 0x38($s0)
/* DF2164 802432C4 8E06003C */  lw        $a2, 0x3c($s0)
/* DF2168 802432C8 8E070040 */  lw        $a3, 0x40($s0)
/* DF216C 802432CC 0C01BECC */  jal       fx_walk
/* DF2170 802432D0 24040002 */   addiu    $a0, $zero, 2
/* DF2174 802432D4 3C01C47A */  lui       $at, 0xc47a
/* DF2178 802432D8 44810000 */  mtc1      $at, $f0
/* DF217C 802432DC AE20006C */  sw        $zero, 0x6c($s1)
/* DF2180 802432E0 8E020000 */  lw        $v0, ($s0)
/* DF2184 802432E4 0200202D */  daddu     $a0, $s0, $zero
/* DF2188 802432E8 AE000038 */  sw        $zero, 0x38($s0)
/* DF218C 802432EC AE000040 */  sw        $zero, 0x40($s0)
/* DF2190 802432F0 34420002 */  ori       $v0, $v0, 2
/* DF2194 802432F4 E600003C */  swc1      $f0, 0x3c($s0)
/* DF2198 802432F8 0C00EAFF */  jal       disable_npc_shadow
/* DF219C 802432FC AE020000 */   sw       $v0, ($s0)
/* DF21A0 80243300 0260202D */  daddu     $a0, $s3, $zero
/* DF21A4 80243304 3C05FE36 */  lui       $a1, 0xfe36
/* DF21A8 80243308 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DF21AC 8024330C 24060001 */  addiu     $a2, $zero, 1
/* DF21B0 80243310 8E020000 */  lw        $v0, ($s0)
/* DF21B4 80243314 2403F7FF */  addiu     $v1, $zero, -0x801
/* DF21B8 80243318 00431024 */  and       $v0, $v0, $v1
/* DF21BC 8024331C AE020000 */  sw        $v0, ($s0)
/* DF21C0 80243320 8E220000 */  lw        $v0, ($s1)
/* DF21C4 80243324 3C031F00 */  lui       $v1, 0x1f00
/* DF21C8 80243328 00431025 */  or        $v0, $v0, $v1
/* DF21CC 8024332C AE220000 */  sw        $v0, ($s1)
/* DF21D0 80243330 AC800070 */  sw        $zero, 0x70($a0)
.L80243334:
/* DF21D4 80243334 0C0B2026 */  jal       evt_set_variable
/* DF21D8 80243338 00000000 */   nop
/* DF21DC 8024333C 08090CDD */  j         .L80243374
/* DF21E0 80243340 24020002 */   addiu    $v0, $zero, 2
.L80243344:
/* DF21E4 80243344 8E220070 */  lw        $v0, 0x70($s1)
/* DF21E8 80243348 30420001 */  andi      $v0, $v0, 1
/* DF21EC 8024334C 10400009 */  beqz      $v0, .L80243374
/* DF21F0 80243350 0000102D */   daddu    $v0, $zero, $zero
/* DF21F4 80243354 C600004C */  lwc1      $f0, 0x4c($s0)
/* DF21F8 80243358 3C01404E */  lui       $at, 0x404e
/* DF21FC 8024335C 44811800 */  mtc1      $at, $f3
/* DF2200 80243360 44801000 */  mtc1      $zero, $f2
/* DF2204 80243364 46000021 */  cvt.d.s   $f0, $f0
/* DF2208 80243368 46220000 */  add.d     $f0, $f0, $f2
/* DF220C 8024336C 46200020 */  cvt.s.d   $f0, $f0
/* DF2210 80243370 E600004C */  swc1      $f0, 0x4c($s0)
.L80243374:
/* DF2214 80243374 8FBF0044 */  lw        $ra, 0x44($sp)
/* DF2218 80243378 8FB40040 */  lw        $s4, 0x40($sp)
/* DF221C 8024337C 8FB3003C */  lw        $s3, 0x3c($sp)
/* DF2220 80243380 8FB20038 */  lw        $s2, 0x38($sp)
/* DF2224 80243384 8FB10034 */  lw        $s1, 0x34($sp)
/* DF2228 80243388 8FB00030 */  lw        $s0, 0x30($sp)
/* DF222C 8024338C D7B80058 */  ldc1      $f24, 0x58($sp)
/* DF2230 80243390 D7B60050 */  ldc1      $f22, 0x50($sp)
/* DF2234 80243394 D7B40048 */  ldc1      $f20, 0x48($sp)
/* DF2238 80243398 03E00008 */  jr        $ra
/* DF223C 8024339C 27BD0060 */   addiu    $sp, $sp, 0x60
