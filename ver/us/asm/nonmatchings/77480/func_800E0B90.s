.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0B90
/* 7A040 800E0B90 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7A044 800E0B94 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7A048 800E0B98 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 7A04C 800E0B9C AFB10014 */  sw        $s1, 0x14($sp)
/* 7A050 800E0BA0 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 7A054 800E0BA4 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 7A058 800E0BA8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7A05C 800E0BAC AFB00010 */  sw        $s0, 0x10($sp)
/* 7A060 800E0BB0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 7A064 800E0BB4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 7A068 800E0BB8 00031080 */  sll       $v0, $v1, 2
/* 7A06C 800E0BBC 00431021 */  addu      $v0, $v0, $v1
/* 7A070 800E0BC0 00021080 */  sll       $v0, $v0, 2
/* 7A074 800E0BC4 00431023 */  subu      $v0, $v0, $v1
/* 7A078 800E0BC8 000218C0 */  sll       $v1, $v0, 3
/* 7A07C 800E0BCC 00431021 */  addu      $v0, $v0, $v1
/* 7A080 800E0BD0 000210C0 */  sll       $v0, $v0, 3
/* 7A084 800E0BD4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 7A088 800E0BD8 00220821 */  addu      $at, $at, $v0
/* 7A08C 800E0BDC C4361DEC */  lwc1      $f22, %lo(gCameras+0x6C)($at)
/* 7A090 800E0BE0 C62E0084 */  lwc1      $f14, 0x84($s1)
/* 7A094 800E0BE4 0C00A70A */  jal       get_clamped_angle_diff
/* 7A098 800E0BE8 4600B306 */   mov.s    $f12, $f22
/* 7A09C 800E0BEC 46000506 */  mov.s     $f20, $f0
/* 7A0A0 800E0BF0 3C01C0A0 */  lui       $at, 0xc0a0
/* 7A0A4 800E0BF4 44810000 */  mtc1      $at, $f0
/* 7A0A8 800E0BF8 3C02800F */  lui       $v0, %hi(D_800F7B48)
/* 7A0AC 800E0BFC 24427B48 */  addiu     $v0, $v0, %lo(D_800F7B48)
/* 7A0B0 800E0C00 4600A03C */  c.lt.s    $f20, $f0
/* 7A0B4 800E0C04 00000000 */  nop
/* 7A0B8 800E0C08 4500000B */  bc1f      .L800E0C38
/* 7A0BC 800E0C0C AC400000 */   sw       $zero, ($v0)
/* 7A0C0 800E0C10 3C01C32F */  lui       $at, 0xc32f
/* 7A0C4 800E0C14 44810000 */  mtc1      $at, $f0
/* 7A0C8 800E0C18 00000000 */  nop
/* 7A0CC 800E0C1C 4614003C */  c.lt.s    $f0, $f20
/* 7A0D0 800E0C20 00000000 */  nop
/* 7A0D4 800E0C24 45000004 */  bc1f      .L800E0C38
/* 7A0D8 800E0C28 0000182D */   daddu    $v1, $zero, $zero
/* 7A0DC 800E0C2C C4540000 */  lwc1      $f20, ($v0)
/* 7A0E0 800E0C30 08038324 */  j         .L800E0C90
/* 7A0E4 800E0C34 00000000 */   nop
.L800E0C38:
/* 7A0E8 800E0C38 3C0140A0 */  lui       $at, 0x40a0
/* 7A0EC 800E0C3C 44810000 */  mtc1      $at, $f0
/* 7A0F0 800E0C40 00000000 */  nop
/* 7A0F4 800E0C44 4614003C */  c.lt.s    $f0, $f20
/* 7A0F8 800E0C48 00000000 */  nop
/* 7A0FC 800E0C4C 4500000C */  bc1f      .L800E0C80
/* 7A100 800E0C50 00000000 */   nop
/* 7A104 800E0C54 3C01432F */  lui       $at, 0x432f
/* 7A108 800E0C58 44810000 */  mtc1      $at, $f0
/* 7A10C 800E0C5C 00000000 */  nop
/* 7A110 800E0C60 4600A03C */  c.lt.s    $f20, $f0
/* 7A114 800E0C64 00000000 */  nop
/* 7A118 800E0C68 45000005 */  bc1f      .L800E0C80
/* 7A11C 800E0C6C 24030001 */   addiu    $v1, $zero, 1
/* 7A120 800E0C70 3C014334 */  lui       $at, 0x4334
/* 7A124 800E0C74 4481A000 */  mtc1      $at, $f20
/* 7A128 800E0C78 08038324 */  j         .L800E0C90
/* 7A12C 800E0C7C 00000000 */   nop
.L800E0C80:
/* 7A130 800E0C80 3C01800F */  lui       $at, %hi(D_800F7B40)
/* 7A134 800E0C84 C4347B40 */  lwc1      $f20, %lo(D_800F7B40)($at)
/* 7A138 800E0C88 4680A520 */  cvt.s.w   $f20, $f20
/* 7A13C 800E0C8C 24030002 */  addiu     $v1, $zero, 2
.L800E0C90:
/* 7A140 800E0C90 3C048011 */  lui       $a0, %hi(D_8010C95C)
/* 7A144 800E0C94 2484C95C */  addiu     $a0, $a0, %lo(D_8010C95C)
/* 7A148 800E0C98 8C820000 */  lw        $v0, ($a0)
/* 7A14C 800E0C9C 10430022 */  beq       $v0, $v1, .L800E0D28
/* 7A150 800E0CA0 24020002 */   addiu    $v0, $zero, 2
/* 7A154 800E0CA4 10620020 */  beq       $v1, $v0, .L800E0D28
/* 7A158 800E0CA8 00000000 */   nop
/* 7A15C 800E0CAC 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 7A160 800E0CB0 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 7A164 800E0CB4 AC830000 */  sw        $v1, ($a0)
/* 7A168 800E0CB8 00021080 */  sll       $v0, $v0, 2
/* 7A16C 800E0CBC 10600005 */  beqz      $v1, .L800E0CD4
/* 7A170 800E0CC0 02221021 */   addu     $v0, $s1, $v0
/* 7A174 800E0CC4 3C014334 */  lui       $at, 0x4334
/* 7A178 800E0CC8 44810000 */  mtc1      $at, $f0
/* 7A17C 800E0CCC 08038339 */  j         .L800E0CE4
/* 7A180 800E0CD0 E4400090 */   swc1     $f0, 0x90($v0)
.L800E0CD4:
/* 7A184 800E0CD4 3C01C334 */  lui       $at, 0xc334
/* 7A188 800E0CD8 44810000 */  mtc1      $at, $f0
/* 7A18C 800E0CDC 00000000 */  nop
/* 7A190 800E0CE0 E4400090 */  swc1      $f0, 0x90($v0)
.L800E0CE4:
/* 7A194 800E0CE4 C62E0084 */  lwc1      $f14, 0x84($s1)
/* 7A198 800E0CE8 0C00A70A */  jal       get_clamped_angle_diff
/* 7A19C 800E0CEC 4600B306 */   mov.s    $f12, $f22
/* 7A1A0 800E0CF0 3C0142B4 */  lui       $at, 0x42b4
/* 7A1A4 800E0CF4 44811000 */  mtc1      $at, $f2
/* 7A1A8 800E0CF8 46000005 */  abs.s     $f0, $f0
/* 7A1AC 800E0CFC 4600103E */  c.le.s    $f2, $f0
/* 7A1B0 800E0D00 00000000 */  nop
/* 7A1B4 800E0D04 45000008 */  bc1f      .L800E0D28
/* 7A1B8 800E0D08 00000000 */   nop
/* 7A1BC 800E0D0C 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 7A1C0 800E0D10 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 7A1C4 800E0D14 00021080 */  sll       $v0, $v0, 2
/* 7A1C8 800E0D18 02221021 */  addu      $v0, $s1, $v0
/* 7A1CC 800E0D1C C4400090 */  lwc1      $f0, 0x90($v0)
/* 7A1D0 800E0D20 46000007 */  neg.s     $f0, $f0
/* 7A1D4 800E0D24 E4400090 */  swc1      $f0, 0x90($v0)
.L800E0D28:
/* 7A1D8 800E0D28 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 7A1DC 800E0D2C 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 7A1E0 800E0D30 44801000 */  mtc1      $zero, $f2
/* 7A1E4 800E0D34 00021080 */  sll       $v0, $v0, 2
/* 7A1E8 800E0D38 02221021 */  addu      $v0, $s1, $v0
/* 7A1EC 800E0D3C C4440090 */  lwc1      $f4, 0x90($v0)
/* 7A1F0 800E0D40 46022032 */  c.eq.s    $f4, $f2
/* 7A1F4 800E0D44 00000000 */  nop
/* 7A1F8 800E0D48 4501001B */  bc1t      .L800E0DB8
/* 7A1FC 800E0D4C 00000000 */   nop
/* 7A200 800E0D50 4602203C */  c.lt.s    $f4, $f2
/* 7A204 800E0D54 00000000 */  nop
/* 7A208 800E0D58 4500000B */  bc1f      .L800E0D88
/* 7A20C 800E0D5C 00000000 */   nop
/* 7A210 800E0D60 3C0141E0 */  lui       $at, 0x41e0
/* 7A214 800E0D64 44810000 */  mtc1      $at, $f0
/* 7A218 800E0D68 00000000 */  nop
/* 7A21C 800E0D6C 46002100 */  add.s     $f4, $f4, $f0
/* 7A220 800E0D70 4604103C */  c.lt.s    $f2, $f4
/* 7A224 800E0D74 00000000 */  nop
/* 7A228 800E0D78 45030003 */  bc1tl     .L800E0D88
/* 7A22C 800E0D7C 46001106 */   mov.s    $f4, $f2
/* 7A230 800E0D80 44801000 */  mtc1      $zero, $f2
/* 7A234 800E0D84 00000000 */  nop
.L800E0D88:
/* 7A238 800E0D88 4604103C */  c.lt.s    $f2, $f4
/* 7A23C 800E0D8C 00000000 */  nop
/* 7A240 800E0D90 45000009 */  bc1f      .L800E0DB8
/* 7A244 800E0D94 00000000 */   nop
/* 7A248 800E0D98 3C0141E0 */  lui       $at, 0x41e0
/* 7A24C 800E0D9C 44810000 */  mtc1      $at, $f0
/* 7A250 800E0DA0 00000000 */  nop
/* 7A254 800E0DA4 46002101 */  sub.s     $f4, $f4, $f0
/* 7A258 800E0DA8 4602203C */  c.lt.s    $f4, $f2
/* 7A25C 800E0DAC 00000000 */  nop
/* 7A260 800E0DB0 45030001 */  bc1tl     .L800E0DB8
/* 7A264 800E0DB4 46001106 */   mov.s    $f4, $f2
.L800E0DB8:
/* 7A268 800E0DB8 8E220000 */  lw        $v0, ($s1)
/* 7A26C 800E0DBC 3C030020 */  lui       $v1, 0x20
/* 7A270 800E0DC0 00431024 */  and       $v0, $v0, $v1
/* 7A274 800E0DC4 10400002 */  beqz      $v0, .L800E0DD0
/* 7A278 800E0DC8 00000000 */   nop
/* 7A27C 800E0DCC 44802000 */  mtc1      $zero, $f4
.L800E0DD0:
/* 7A280 800E0DD0 3C108007 */  lui       $s0, %hi(gCurrentCameraID)
/* 7A284 800E0DD4 26107410 */  addiu     $s0, $s0, %lo(gCurrentCameraID)
/* 7A288 800E0DD8 8E020000 */  lw        $v0, ($s0)
/* 7A28C 800E0DDC 4600A306 */  mov.s     $f12, $f20
/* 7A290 800E0DE0 00021080 */  sll       $v0, $v0, 2
/* 7A294 800E0DE4 02221021 */  addu      $v0, $s1, $v0
/* 7A298 800E0DE8 0C00A6C9 */  jal       clamp_angle
/* 7A29C 800E0DEC E4440090 */   swc1     $f4, 0x90($v0)
/* 7A2A0 800E0DF0 8E020000 */  lw        $v0, ($s0)
/* 7A2A4 800E0DF4 00021080 */  sll       $v0, $v0, 2
/* 7A2A8 800E0DF8 02221021 */  addu      $v0, $s1, $v0
/* 7A2AC 800E0DFC C44C0090 */  lwc1      $f12, 0x90($v0)
/* 7A2B0 800E0E00 46000106 */  mov.s     $f4, $f0
/* 7A2B4 800E0E04 4600220D */  trunc.w.s $f8, $f4
/* 7A2B8 800E0E08 3C01800F */  lui       $at, %hi(D_800F7B40)
/* 7A2BC 800E0E0C E4287B40 */  swc1      $f8, %lo(D_800F7B40)($at)
/* 7A2C0 800E0E10 0C00A6C9 */  jal       clamp_angle
/* 7A2C4 800E0E14 46046300 */   add.s    $f12, $f12, $f4
/* 7A2C8 800E0E18 C6220054 */  lwc1      $f2, 0x54($s1)
/* 7A2CC 800E0E1C 44803000 */  mtc1      $zero, $f6
/* 7A2D0 800E0E20 00000000 */  nop
/* 7A2D4 800E0E24 46061032 */  c.eq.s    $f2, $f6
/* 7A2D8 800E0E28 00000000 */  nop
/* 7A2DC 800E0E2C 45000003 */  bc1f      .L800E0E3C
/* 7A2E0 800E0E30 46000106 */   mov.s    $f4, $f0
/* 7A2E4 800E0E34 3C01800F */  lui       $at, %hi(D_800F7B48)
/* 7A2E8 800E0E38 E4267B48 */  swc1      $f6, %lo(D_800F7B48)($at)
.L800E0E3C:
/* 7A2EC 800E0E3C 3C020002 */  lui       $v0, 2
/* 7A2F0 800E0E40 8E250000 */  lw        $a1, ($s1)
/* 7A2F4 800E0E44 8E3000B8 */  lw        $s0, 0xb8($s1)
/* 7A2F8 800E0E48 00A21024 */  and       $v0, $a1, $v0
/* 7A2FC 800E0E4C 5440004A */  bnel      $v0, $zero, .L800E0F78
/* 7A300 800E0E50 AE3000A4 */   sw       $s0, 0xa4($s1)
/* 7A304 800E0E54 00101403 */  sra       $v0, $s0, 0x10
/* 7A308 800E0E58 304400FF */  andi      $a0, $v0, 0xff
/* 7A30C 800E0E5C 822300B4 */  lb        $v1, 0xb4($s1)
/* 7A310 800E0E60 2402000F */  addiu     $v0, $zero, 0xf
/* 7A314 800E0E64 10620024 */  beq       $v1, $v0, .L800E0EF8
/* 7A318 800E0E68 3C020010 */   lui      $v0, 0x10
/* 7A31C 800E0E6C 00A21024 */  and       $v0, $a1, $v0
/* 7A320 800E0E70 14400022 */  bnez      $v0, .L800E0EFC
/* 7A324 800E0E74 3C031000 */   lui      $v1, 0x1000
/* 7A328 800E0E78 3C01800F */  lui       $at, %hi(D_800F7B48)
/* 7A32C 800E0E7C C4207B48 */  lwc1      $f0, %lo(D_800F7B48)($at)
/* 7A330 800E0E80 8E220000 */  lw        $v0, ($s1)
/* 7A334 800E0E84 46002000 */  add.s     $f0, $f4, $f0
/* 7A338 800E0E88 8E3000B8 */  lw        $s0, 0xb8($s1)
/* 7A33C 800E0E8C 00431024 */  and       $v0, $v0, $v1
/* 7A340 800E0E90 14400015 */  bnez      $v0, .L800E0EE8
/* 7A344 800E0E94 E62000A8 */   swc1     $f0, 0xa8($s1)
/* 7A348 800E0E98 24020001 */  addiu     $v0, $zero, 1
/* 7A34C 800E0E9C 10820005 */  beq       $a0, $v0, .L800E0EB4
/* 7A350 800E0EA0 24020006 */   addiu    $v0, $zero, 6
/* 7A354 800E0EA4 10820003 */  beq       $a0, $v0, .L800E0EB4
/* 7A358 800E0EA8 2402000A */   addiu    $v0, $zero, 0xa
/* 7A35C 800E0EAC 1482000E */  bne       $a0, $v0, .L800E0EE8
/* 7A360 800E0EB0 00000000 */   nop
.L800E0EB4:
/* 7A364 800E0EB4 C62E0084 */  lwc1      $f14, 0x84($s1)
/* 7A368 800E0EB8 0C00A70A */  jal       get_clamped_angle_diff
/* 7A36C 800E0EBC 4600B306 */   mov.s    $f12, $f22
/* 7A370 800E0EC0 3C014270 */  lui       $at, 0x4270
/* 7A374 800E0EC4 44811000 */  mtc1      $at, $f2
/* 7A378 800E0EC8 46000005 */  abs.s     $f0, $f0
/* 7A37C 800E0ECC 4602003C */  c.lt.s    $f0, $f2
/* 7A380 800E0ED0 00000000 */  nop
/* 7A384 800E0ED4 45000004 */  bc1f      .L800E0EE8
/* 7A388 800E0ED8 00000000 */   nop
/* 7A38C 800E0EDC 0C0383FB */  jal       get_player_back_anim
/* 7A390 800E0EE0 0200202D */   daddu    $a0, $s0, $zero
/* 7A394 800E0EE4 0040802D */  daddu     $s0, $v0, $zero
.L800E0EE8:
/* 7A398 800E0EE8 C6200080 */  lwc1      $f0, 0x80($s1)
/* 7A39C 800E0EEC AE3000A4 */  sw        $s0, 0xa4($s1)
/* 7A3A0 800E0EF0 080383DE */  j         .L800E0F78
/* 7A3A4 800E0EF4 E6200084 */   swc1     $f0, 0x84($s1)
.L800E0EF8:
/* 7A3A8 800E0EF8 3C031000 */  lui       $v1, 0x1000
.L800E0EFC:
/* 7A3AC 800E0EFC 8E220000 */  lw        $v0, ($s1)
/* 7A3B0 800E0F00 8E3000B8 */  lw        $s0, 0xb8($s1)
/* 7A3B4 800E0F04 00431024 */  and       $v0, $v0, $v1
/* 7A3B8 800E0F08 5440001B */  bnel      $v0, $zero, .L800E0F78
/* 7A3BC 800E0F0C AE3000A4 */   sw       $s0, 0xa4($s1)
/* 7A3C0 800E0F10 24020001 */  addiu     $v0, $zero, 1
/* 7A3C4 800E0F14 10820005 */  beq       $a0, $v0, .L800E0F2C
/* 7A3C8 800E0F18 24020006 */   addiu    $v0, $zero, 6
/* 7A3CC 800E0F1C 10820003 */  beq       $a0, $v0, .L800E0F2C
/* 7A3D0 800E0F20 2402000A */   addiu    $v0, $zero, 0xa
/* 7A3D4 800E0F24 54820014 */  bnel      $a0, $v0, .L800E0F78
/* 7A3D8 800E0F28 AE3000A4 */   sw       $s0, 0xa4($s1)
.L800E0F2C:
/* 7A3DC 800E0F2C C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 7A3E0 800E0F30 3C0143AF */  lui       $at, 0x43af
/* 7A3E4 800E0F34 44810000 */  mtc1      $at, $f0
/* 7A3E8 800E0F38 00000000 */  nop
/* 7A3EC 800E0F3C 4600103C */  c.lt.s    $f2, $f0
/* 7A3F0 800E0F40 00000000 */  nop
/* 7A3F4 800E0F44 4502000C */  bc1fl     .L800E0F78
/* 7A3F8 800E0F48 AE3000A4 */   sw       $s0, 0xa4($s1)
/* 7A3FC 800E0F4C 3C01433E */  lui       $at, 0x433e
/* 7A400 800E0F50 44810000 */  mtc1      $at, $f0
/* 7A404 800E0F54 00000000 */  nop
/* 7A408 800E0F58 4602003C */  c.lt.s    $f0, $f2
/* 7A40C 800E0F5C 00000000 */  nop
/* 7A410 800E0F60 45020005 */  bc1fl     .L800E0F78
/* 7A414 800E0F64 AE3000A4 */   sw       $s0, 0xa4($s1)
/* 7A418 800E0F68 0C0383FB */  jal       get_player_back_anim
/* 7A41C 800E0F6C 0200202D */   daddu    $a0, $s0, $zero
/* 7A420 800E0F70 0040802D */  daddu     $s0, $v0, $zero
/* 7A424 800E0F74 AE3000A4 */  sw        $s0, 0xa4($s1)
.L800E0F78:
/* 7A428 800E0F78 3C020004 */  lui       $v0, 4
/* 7A42C 800E0F7C 8E230000 */  lw        $v1, ($s1)
/* 7A430 800E0F80 3C013F80 */  lui       $at, 0x3f80
/* 7A434 800E0F84 44810000 */  mtc1      $at, $f0
/* 7A438 800E0F88 00621024 */  and       $v0, $v1, $v0
/* 7A43C 800E0F8C 10400003 */  beqz      $v0, .L800E0F9C
/* 7A440 800E0F90 3C022000 */   lui      $v0, 0x2000
/* 7A444 800E0F94 3C013F00 */  lui       $at, 0x3f00
/* 7A448 800E0F98 44810000 */  mtc1      $at, $f0
.L800E0F9C:
/* 7A44C 800E0F9C 00621024 */  and       $v0, $v1, $v0
/* 7A450 800E0FA0 10400002 */  beqz      $v0, .L800E0FAC
/* 7A454 800E0FA4 00000000 */   nop
/* 7A458 800E0FA8 44800000 */  mtc1      $zero, $f0
.L800E0FAC:
/* 7A45C 800E0FAC 8E2500A4 */  lw        $a1, 0xa4($s1)
/* 7A460 800E0FB0 44060000 */  mfc1      $a2, $f0
/* 7A464 800E0FB4 0C0B76A3 */  jal       spr_update_player_sprite
/* 7A468 800E0FB8 0000202D */   daddu    $a0, $zero, $zero
/* 7A46C 800E0FBC A62200BC */  sh        $v0, 0xbc($s1)
/* 7A470 800E0FC0 8E220000 */  lw        $v0, ($s1)
/* 7A474 800E0FC4 3C034000 */  lui       $v1, 0x4000
/* 7A478 800E0FC8 00431025 */  or        $v0, $v0, $v1
/* 7A47C 800E0FCC AE220000 */  sw        $v0, ($s1)
/* 7A480 800E0FD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7A484 800E0FD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 7A488 800E0FD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 7A48C 800E0FDC D7B60028 */  ldc1      $f22, 0x28($sp)
/* 7A490 800E0FE0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 7A494 800E0FE4 03E00008 */  jr        $ra
/* 7A498 800E0FE8 27BD0030 */   addiu    $sp, $sp, 0x30
