.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419A4_D1A184
/* D1A184 802419A4 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* D1A188 802419A8 AFBE00A0 */  sw        $fp, 0xa0($sp)
/* D1A18C 802419AC 0080F02D */  daddu     $fp, $a0, $zero
/* D1A190 802419B0 AFBF00A4 */  sw        $ra, 0xa4($sp)
/* D1A194 802419B4 AFB7009C */  sw        $s7, 0x9c($sp)
/* D1A198 802419B8 AFB60098 */  sw        $s6, 0x98($sp)
/* D1A19C 802419BC AFB50094 */  sw        $s5, 0x94($sp)
/* D1A1A0 802419C0 AFB40090 */  sw        $s4, 0x90($sp)
/* D1A1A4 802419C4 AFB3008C */  sw        $s3, 0x8c($sp)
/* D1A1A8 802419C8 AFB20088 */  sw        $s2, 0x88($sp)
/* D1A1AC 802419CC AFB10084 */  sw        $s1, 0x84($sp)
/* D1A1B0 802419D0 AFB00080 */  sw        $s0, 0x80($sp)
/* D1A1B4 802419D4 F7B800B8 */  sdc1      $f24, 0xb8($sp)
/* D1A1B8 802419D8 F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* D1A1BC 802419DC F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* D1A1C0 802419E0 8FD70148 */  lw        $s7, 0x148($fp)
/* D1A1C4 802419E4 86E40008 */  lh        $a0, 8($s7)
/* D1A1C8 802419E8 0C00EABB */  jal       get_npc_unsafe
/* D1A1CC 802419EC 00A0802D */   daddu    $s0, $a1, $zero
/* D1A1D0 802419F0 12000003 */  beqz      $s0, .L80241A00
/* D1A1D4 802419F4 0040B02D */   daddu    $s6, $v0, $zero
/* D1A1D8 802419F8 A6C0008E */  sh        $zero, 0x8e($s6)
/* D1A1DC 802419FC AFC00070 */  sw        $zero, 0x70($fp)
.L80241A00:
/* D1A1E0 80241A00 8EE20078 */  lw        $v0, 0x78($s7)
/* D1A1E4 80241A04 1440000B */  bnez      $v0, .L80241A34
/* D1A1E8 80241A08 0000282D */   daddu    $a1, $zero, $zero
/* D1A1EC 80241A0C 24050001 */  addiu     $a1, $zero, 1
/* D1A1F0 80241A10 24060007 */  addiu     $a2, $zero, 7
/* D1A1F4 80241A14 240200FF */  addiu     $v0, $zero, 0xff
/* D1A1F8 80241A18 AFA20010 */  sw        $v0, 0x10($sp)
/* D1A1FC 80241A1C AFA20014 */  sw        $v0, 0x14($sp)
/* D1A200 80241A20 AFA00018 */  sw        $zero, 0x18($sp)
/* D1A204 80241A24 AFA0001C */  sw        $zero, 0x1c($sp)
/* D1A208 80241A28 8EC40024 */  lw        $a0, 0x24($s6)
/* D1A20C 80241A2C 08090736 */  j         .L80241CD8
/* D1A210 80241A30 0040382D */   daddu    $a3, $v0, $zero
.L80241A34:
/* D1A214 80241A34 24060011 */  addiu     $a2, $zero, 0x11
/* D1A218 80241A38 240200FF */  addiu     $v0, $zero, 0xff
/* D1A21C 80241A3C AFA00010 */  sw        $zero, 0x10($sp)
/* D1A220 80241A40 AFA00014 */  sw        $zero, 0x14($sp)
/* D1A224 80241A44 AFA20018 */  sw        $v0, 0x18($sp)
/* D1A228 80241A48 AFA0001C */  sw        $zero, 0x1c($sp)
/* D1A22C 80241A4C 8EC40024 */  lw        $a0, 0x24($s6)
/* D1A230 80241A50 0C0B79E0 */  jal       func_802DE780
/* D1A234 80241A54 24070014 */   addiu    $a3, $zero, 0x14
/* D1A238 80241A58 8FC20070 */  lw        $v0, 0x70($fp)
/* D1A23C 80241A5C 2444000A */  addiu     $a0, $v0, 0xa
/* D1A240 80241A60 28820168 */  slti      $v0, $a0, 0x168
/* D1A244 80241A64 14400010 */  bnez      $v0, .L80241AA8
/* D1A248 80241A68 AFC40070 */   sw       $a0, 0x70($fp)
/* D1A24C 80241A6C 3C02B60B */  lui       $v0, 0xb60b
/* D1A250 80241A70 344260B7 */  ori       $v0, $v0, 0x60b7
/* D1A254 80241A74 00820018 */  mult      $a0, $v0
/* D1A258 80241A78 00041FC3 */  sra       $v1, $a0, 0x1f
/* D1A25C 80241A7C 00004810 */  mfhi      $t1
/* D1A260 80241A80 01241021 */  addu      $v0, $t1, $a0
/* D1A264 80241A84 00021203 */  sra       $v0, $v0, 8
/* D1A268 80241A88 00431023 */  subu      $v0, $v0, $v1
/* D1A26C 80241A8C 00021840 */  sll       $v1, $v0, 1
/* D1A270 80241A90 00621821 */  addu      $v1, $v1, $v0
/* D1A274 80241A94 00031100 */  sll       $v0, $v1, 4
/* D1A278 80241A98 00431023 */  subu      $v0, $v0, $v1
/* D1A27C 80241A9C 000210C0 */  sll       $v0, $v0, 3
/* D1A280 80241AA0 00821023 */  subu      $v0, $a0, $v0
/* D1A284 80241AA4 AFC20070 */  sw        $v0, 0x70($fp)
.L80241AA8:
/* D1A288 80241AA8 0000882D */  daddu     $s1, $zero, $zero
/* D1A28C 80241AAC 27B50050 */  addiu     $s5, $sp, 0x50
/* D1A290 80241AB0 27B40038 */  addiu     $s4, $sp, 0x38
/* D1A294 80241AB4 27B20020 */  addiu     $s2, $sp, 0x20
/* D1A298 80241AB8 0220802D */  daddu     $s0, $s1, $zero
/* D1A29C 80241ABC 3C013FF0 */  lui       $at, 0x3ff0
/* D1A2A0 80241AC0 4481C800 */  mtc1      $at, $f25
/* D1A2A4 80241AC4 4480C000 */  mtc1      $zero, $f24
/* D1A2A8 80241AC8 3C01404C */  lui       $at, 0x404c
/* D1A2AC 80241ACC 4481B800 */  mtc1      $at, $f23
/* D1A2B0 80241AD0 4480B000 */  mtc1      $zero, $f22
/* D1A2B4 80241AD4 3C0141E0 */  lui       $at, 0x41e0
/* D1A2B8 80241AD8 4481A800 */  mtc1      $at, $f21
/* D1A2BC 80241ADC 4480A000 */  mtc1      $zero, $f20
.L80241AE0:
/* D1A2C0 80241AE0 97C40072 */  lhu       $a0, 0x72($fp)
/* D1A2C4 80241AE4 00902021 */  addu      $a0, $a0, $s0
/* D1A2C8 80241AE8 00042400 */  sll       $a0, $a0, 0x10
/* D1A2CC 80241AEC 0C00A4F5 */  jal       cosine
/* D1A2D0 80241AF0 00042403 */   sra      $a0, $a0, 0x10
/* D1A2D4 80241AF4 46000021 */  cvt.d.s   $f0, $f0
/* D1A2D8 80241AF8 46380000 */  add.d     $f0, $f0, $f24
/* D1A2DC 80241AFC 46360002 */  mul.d     $f0, $f0, $f22
/* D1A2E0 80241B00 00000000 */  nop       
/* D1A2E4 80241B04 4620A03E */  c.le.d    $f20, $f0
/* D1A2E8 80241B08 00000000 */  nop       
/* D1A2EC 80241B0C 45030005 */  bc1tl     .L80241B24
/* D1A2F0 80241B10 46340001 */   sub.d    $f0, $f0, $f20
/* D1A2F4 80241B14 4620008D */  trunc.w.d $f2, $f0
/* D1A2F8 80241B18 44021000 */  mfc1      $v0, $f2
/* D1A2FC 80241B1C 080906CE */  j         .L80241B38
/* D1A300 80241B20 A2420000 */   sb       $v0, ($s2)
.L80241B24:
/* D1A304 80241B24 4620008D */  trunc.w.d $f2, $f0
/* D1A308 80241B28 44021000 */  mfc1      $v0, $f2
/* D1A30C 80241B2C 3C098000 */  lui       $t1, 0x8000
/* D1A310 80241B30 00491025 */  or        $v0, $v0, $t1
/* D1A314 80241B34 A2420000 */  sb        $v0, ($s2)
.L80241B38:
/* D1A318 80241B38 97C40072 */  lhu       $a0, 0x72($fp)
/* D1A31C 80241B3C 00902021 */  addu      $a0, $a0, $s0
/* D1A320 80241B40 2484002D */  addiu     $a0, $a0, 0x2d
/* D1A324 80241B44 00042400 */  sll       $a0, $a0, 0x10
/* D1A328 80241B48 0C00A4F5 */  jal       cosine
/* D1A32C 80241B4C 00042403 */   sra      $a0, $a0, 0x10
/* D1A330 80241B50 46000021 */  cvt.d.s   $f0, $f0
/* D1A334 80241B54 46380000 */  add.d     $f0, $f0, $f24
/* D1A338 80241B58 46360002 */  mul.d     $f0, $f0, $f22
/* D1A33C 80241B5C 00000000 */  nop       
/* D1A340 80241B60 4620A03E */  c.le.d    $f20, $f0
/* D1A344 80241B64 00000000 */  nop       
/* D1A348 80241B68 45010005 */  bc1t      .L80241B80
/* D1A34C 80241B6C 0280182D */   daddu    $v1, $s4, $zero
/* D1A350 80241B70 4620008D */  trunc.w.d $f2, $f0
/* D1A354 80241B74 44021000 */  mfc1      $v0, $f2
/* D1A358 80241B78 080906E6 */  j         .L80241B98
/* D1A35C 80241B7C A0620000 */   sb       $v0, ($v1)
.L80241B80:
/* D1A360 80241B80 46340001 */  sub.d     $f0, $f0, $f20
/* D1A364 80241B84 4620008D */  trunc.w.d $f2, $f0
/* D1A368 80241B88 44021000 */  mfc1      $v0, $f2
/* D1A36C 80241B8C 3C098000 */  lui       $t1, 0x8000
/* D1A370 80241B90 00491025 */  or        $v0, $v0, $t1
/* D1A374 80241B94 A0620000 */  sb        $v0, ($v1)
.L80241B98:
/* D1A378 80241B98 97C40072 */  lhu       $a0, 0x72($fp)
/* D1A37C 80241B9C 00902021 */  addu      $a0, $a0, $s0
/* D1A380 80241BA0 2484005A */  addiu     $a0, $a0, 0x5a
/* D1A384 80241BA4 00042400 */  sll       $a0, $a0, 0x10
/* D1A388 80241BA8 0C00A4F5 */  jal       cosine
/* D1A38C 80241BAC 00042403 */   sra      $a0, $a0, 0x10
/* D1A390 80241BB0 46000021 */  cvt.d.s   $f0, $f0
/* D1A394 80241BB4 46380000 */  add.d     $f0, $f0, $f24
/* D1A398 80241BB8 46360002 */  mul.d     $f0, $f0, $f22
/* D1A39C 80241BBC 00000000 */  nop       
/* D1A3A0 80241BC0 4620A03E */  c.le.d    $f20, $f0
/* D1A3A4 80241BC4 00000000 */  nop       
/* D1A3A8 80241BC8 45010005 */  bc1t      .L80241BE0
/* D1A3AC 80241BCC 02A0182D */   daddu    $v1, $s5, $zero
/* D1A3B0 80241BD0 4620008D */  trunc.w.d $f2, $f0
/* D1A3B4 80241BD4 44021000 */  mfc1      $v0, $f2
/* D1A3B8 80241BD8 080906FE */  j         .L80241BF8
/* D1A3BC 80241BDC 0000282D */   daddu    $a1, $zero, $zero
.L80241BE0:
/* D1A3C0 80241BE0 46340001 */  sub.d     $f0, $f0, $f20
/* D1A3C4 80241BE4 4620008D */  trunc.w.d $f2, $f0
/* D1A3C8 80241BE8 44021000 */  mfc1      $v0, $f2
/* D1A3CC 80241BEC 3C098000 */  lui       $t1, 0x8000
/* D1A3D0 80241BF0 00491025 */  or        $v0, $v0, $t1
/* D1A3D4 80241BF4 0000282D */  daddu     $a1, $zero, $zero
.L80241BF8:
/* D1A3D8 80241BF8 2406000C */  addiu     $a2, $zero, 0xc
/* D1A3DC 80241BFC 0220382D */  daddu     $a3, $s1, $zero
/* D1A3E0 80241C00 26100019 */  addiu     $s0, $s0, 0x19
/* D1A3E4 80241C04 A0620000 */  sb        $v0, ($v1)
/* D1A3E8 80241C08 27A30068 */  addiu     $v1, $sp, 0x68
/* D1A3EC 80241C0C 00711821 */  addu      $v1, $v1, $s1
/* D1A3F0 80241C10 26310001 */  addiu     $s1, $s1, 1
/* D1A3F4 80241C14 92E2007B */  lbu       $v0, 0x7b($s7)
/* D1A3F8 80241C18 241300FF */  addiu     $s3, $zero, 0xff
/* D1A3FC 80241C1C A0620000 */  sb        $v0, ($v1)
/* D1A400 80241C20 92A80000 */  lbu       $t0, ($s5)
/* D1A404 80241C24 26B50001 */  addiu     $s5, $s5, 1
/* D1A408 80241C28 92420000 */  lbu       $v0, ($s2)
/* D1A40C 80241C2C 92840000 */  lbu       $a0, ($s4)
/* D1A410 80241C30 90630000 */  lbu       $v1, ($v1)
/* D1A414 80241C34 26940001 */  addiu     $s4, $s4, 1
/* D1A418 80241C38 AFA00014 */  sw        $zero, 0x14($sp)
/* D1A41C 80241C3C AFB30018 */  sw        $s3, 0x18($sp)
/* D1A420 80241C40 AFA0001C */  sw        $zero, 0x1c($sp)
/* D1A424 80241C44 00021600 */  sll       $v0, $v0, 0x18
/* D1A428 80241C48 00042400 */  sll       $a0, $a0, 0x10
/* D1A42C 80241C4C 00441025 */  or        $v0, $v0, $a0
/* D1A430 80241C50 00084200 */  sll       $t0, $t0, 8
/* D1A434 80241C54 00481025 */  or        $v0, $v0, $t0
/* D1A438 80241C58 00431025 */  or        $v0, $v0, $v1
/* D1A43C 80241C5C AFA20010 */  sw        $v0, 0x10($sp)
/* D1A440 80241C60 8EC40024 */  lw        $a0, 0x24($s6)
/* D1A444 80241C64 0C0B79E0 */  jal       func_802DE780
/* D1A448 80241C68 26520001 */   addiu    $s2, $s2, 1
/* D1A44C 80241C6C 2A220014 */  slti      $v0, $s1, 0x14
/* D1A450 80241C70 1440FF9B */  bnez      $v0, .L80241AE0
/* D1A454 80241C74 00000000 */   nop      
/* D1A458 80241C78 8EE30078 */  lw        $v1, 0x78($s7)
/* D1A45C 80241C7C 1473000A */  bne       $v1, $s3, .L80241CA8
/* D1A460 80241C80 24020016 */   addiu    $v0, $zero, 0x16
/* D1A464 80241C84 24050001 */  addiu     $a1, $zero, 1
/* D1A468 80241C88 2406000F */  addiu     $a2, $zero, 0xf
/* D1A46C 80241C8C 2402000D */  addiu     $v0, $zero, 0xd
/* D1A470 80241C90 A2C200AA */  sb        $v0, 0xaa($s6)
/* D1A474 80241C94 AFA30010 */  sw        $v1, 0x10($sp)
/* D1A478 80241C98 AFA00014 */  sw        $zero, 0x14($sp)
/* D1A47C 80241C9C AFA30018 */  sw        $v1, 0x18($sp)
/* D1A480 80241CA0 08090733 */  j         .L80241CCC
/* D1A484 80241CA4 AFA0001C */   sw       $zero, 0x1c($sp)
.L80241CA8:
/* D1A488 80241CA8 A2C200AA */  sb        $v0, 0xaa($s6)
/* D1A48C 80241CAC 8EE20078 */  lw        $v0, 0x78($s7)
/* D1A490 80241CB0 24050001 */  addiu     $a1, $zero, 1
/* D1A494 80241CB4 AFA00014 */  sw        $zero, 0x14($sp)
/* D1A498 80241CB8 AFA20010 */  sw        $v0, 0x10($sp)
/* D1A49C 80241CBC 8EE20078 */  lw        $v0, 0x78($s7)
/* D1A4A0 80241CC0 2406000F */  addiu     $a2, $zero, 0xf
/* D1A4A4 80241CC4 AFA0001C */  sw        $zero, 0x1c($sp)
/* D1A4A8 80241CC8 AFA20018 */  sw        $v0, 0x18($sp)
.L80241CCC:
/* D1A4AC 80241CCC 8EC40024 */  lw        $a0, 0x24($s6)
/* D1A4B0 80241CD0 3C078024 */  lui       $a3, 0x8024
/* D1A4B4 80241CD4 24E72F90 */  addiu     $a3, $a3, 0x2f90
.L80241CD8:
/* D1A4B8 80241CD8 0C0B79E0 */  jal       func_802DE780
/* D1A4BC 80241CDC 00000000 */   nop      
/* D1A4C0 80241CE0 0000102D */  daddu     $v0, $zero, $zero
/* D1A4C4 80241CE4 8FBF00A4 */  lw        $ra, 0xa4($sp)
/* D1A4C8 80241CE8 8FBE00A0 */  lw        $fp, 0xa0($sp)
/* D1A4CC 80241CEC 8FB7009C */  lw        $s7, 0x9c($sp)
/* D1A4D0 80241CF0 8FB60098 */  lw        $s6, 0x98($sp)
/* D1A4D4 80241CF4 8FB50094 */  lw        $s5, 0x94($sp)
/* D1A4D8 80241CF8 8FB40090 */  lw        $s4, 0x90($sp)
/* D1A4DC 80241CFC 8FB3008C */  lw        $s3, 0x8c($sp)
/* D1A4E0 80241D00 8FB20088 */  lw        $s2, 0x88($sp)
/* D1A4E4 80241D04 8FB10084 */  lw        $s1, 0x84($sp)
/* D1A4E8 80241D08 8FB00080 */  lw        $s0, 0x80($sp)
/* D1A4EC 80241D0C D7B800B8 */  ldc1      $f24, 0xb8($sp)
/* D1A4F0 80241D10 D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* D1A4F4 80241D14 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* D1A4F8 80241D18 03E00008 */  jr        $ra
/* D1A4FC 80241D1C 27BD00C0 */   addiu    $sp, $sp, 0xc0
