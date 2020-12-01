.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801489B8
/* DF0B8 801489B8 27BDFF90 */  addiu     $sp, $sp, -0x70
/* DF0BC 801489BC F7B60048 */  sdc1      $f22, 0x48($sp)
/* DF0C0 801489C0 C7B60088 */  lwc1      $f22, 0x88($sp)
/* DF0C4 801489C4 F7B80050 */  sdc1      $f24, 0x50($sp)
/* DF0C8 801489C8 C7B8008C */  lwc1      $f24, 0x8c($sp)
/* DF0CC 801489CC F7B40040 */  sdc1      $f20, 0x40($sp)
/* DF0D0 801489D0 C7B40090 */  lwc1      $f20, 0x90($sp)
/* DF0D4 801489D4 AFB30024 */  sw        $s3, 0x24($sp)
/* DF0D8 801489D8 8FB30094 */  lw        $s3, 0x94($sp)
/* DF0DC 801489DC AFB20020 */  sw        $s2, 0x20($sp)
/* DF0E0 801489E0 8FB20098 */  lw        $s2, 0x98($sp)
/* DF0E4 801489E4 AFB40028 */  sw        $s4, 0x28($sp)
/* DF0E8 801489E8 8FB4009C */  lw        $s4, 0x9c($sp)
/* DF0EC 801489EC AFB60030 */  sw        $s6, 0x30($sp)
/* DF0F0 801489F0 8FB600A0 */  lw        $s6, 0xa0($sp)
/* DF0F4 801489F4 AFB5002C */  sw        $s5, 0x2c($sp)
/* DF0F8 801489F8 8FB500A4 */  lw        $s5, 0xa4($sp)
/* DF0FC 801489FC AFB00018 */  sw        $s0, 0x18($sp)
/* DF100 80148A00 8FB000AC */  lw        $s0, 0xac($sp)
/* DF104 80148A04 AFB1001C */  sw        $s1, 0x1c($sp)
/* DF108 80148A08 0080882D */  daddu     $s1, $a0, $zero
/* DF10C 80148A0C F7BC0060 */  sdc1      $f28, 0x60($sp)
/* DF110 80148A10 4480E000 */  mtc1      $zero, $f28
/* DF114 80148A14 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* DF118 80148A18 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* DF11C 80148A1C 3C04800B */  lui       $a0, %hi(gCameras)
/* DF120 80148A20 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* DF124 80148A24 AFBF003C */  sw        $ra, 0x3c($sp)
/* DF128 80148A28 4616B002 */  mul.s     $f0, $f22, $f22
/* DF12C 80148A2C 00000000 */  nop       
/* DF130 80148A30 AFBE0038 */  sw        $fp, 0x38($sp)
/* DF134 80148A34 AFB70034 */  sw        $s7, 0x34($sp)
/* DF138 80148A38 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* DF13C 80148A3C F7BA0058 */  sdc1      $f26, 0x58($sp)
/* DF140 80148A40 4618C082 */  mul.s     $f2, $f24, $f24
/* DF144 80148A44 00000000 */  nop       
/* DF148 80148A48 AFA50074 */  sw        $a1, 0x74($sp)
/* DF14C 80148A4C AFA60078 */  sw        $a2, 0x78($sp)
/* DF150 80148A50 AFA7007C */  sw        $a3, 0x7c($sp)
/* DF154 80148A54 00031080 */  sll       $v0, $v1, 2
/* DF158 80148A58 4614A102 */  mul.s     $f4, $f20, $f20
/* DF15C 80148A5C 00000000 */  nop       
/* DF160 80148A60 00431021 */  addu      $v0, $v0, $v1
/* DF164 80148A64 00021080 */  sll       $v0, $v0, 2
/* DF168 80148A68 00431023 */  subu      $v0, $v0, $v1
/* DF16C 80148A6C 000218C0 */  sll       $v1, $v0, 3
/* DF170 80148A70 46020000 */  add.s     $f0, $f0, $f2
/* DF174 80148A74 00431021 */  addu      $v0, $v0, $v1
/* DF178 80148A78 000210C0 */  sll       $v0, $v0, 3
/* DF17C 80148A7C 46040300 */  add.s     $f12, $f0, $f4
/* DF180 80148A80 3C013FF0 */  lui       $at, 0x3ff0
/* DF184 80148A84 44811800 */  mtc1      $at, $f3
/* DF188 80148A88 44801000 */  mtc1      $zero, $f2
/* DF18C 80148A8C 46006021 */  cvt.d.s   $f0, $f12
/* DF190 80148A90 4622003C */  c.lt.d    $f0, $f2
/* DF194 80148A94 00000000 */  nop       
/* DF198 80148A98 45000008 */  bc1f      .L80148ABC
/* DF19C 80148A9C 0044F021 */   addu     $fp, $v0, $a0
/* DF1A0 80148AA0 44900000 */  mtc1      $s0, $f0
/* DF1A4 80148AA4 00000000 */  nop       
/* DF1A8 80148AA8 46800020 */  cvt.s.w   $f0, $f0
/* DF1AC 80148AAC 460C0002 */  mul.s     $f0, $f0, $f12
/* DF1B0 80148AB0 00000000 */  nop       
/* DF1B4 80148AB4 4600028D */  trunc.w.s $f10, $f0
/* DF1B8 80148AB8 44105000 */  mfc1      $s0, $f10
.L80148ABC:
/* DF1BC 80148ABC 461C6032 */  c.eq.s    $f12, $f28
/* DF1C0 80148AC0 00000000 */  nop       
/* DF1C4 80148AC4 4501000D */  bc1t      .L80148AFC
/* DF1C8 80148AC8 00000000 */   nop      
/* DF1CC 80148ACC 46006084 */  sqrt.s    $f2, $f12
/* DF1D0 80148AD0 46021032 */  c.eq.s    $f2, $f2
/* DF1D4 80148AD4 00000000 */  nop       
/* DF1D8 80148AD8 45010004 */  bc1t      .L80148AEC
/* DF1DC 80148ADC 00000000 */   nop      
/* DF1E0 80148AE0 0C0187BC */  jal       sqrtf
/* DF1E4 80148AE4 00000000 */   nop      
/* DF1E8 80148AE8 46000086 */  mov.s     $f2, $f0
.L80148AEC:
/* DF1EC 80148AEC 3C013F80 */  lui       $at, 0x3f80
/* DF1F0 80148AF0 44810000 */  mtc1      $at, $f0
/* DF1F4 80148AF4 00000000 */  nop       
/* DF1F8 80148AF8 46020303 */  div.s     $f12, $f0, $f2
.L80148AFC:
/* DF1FC 80148AFC 460CB582 */  mul.s     $f22, $f22, $f12
/* DF200 80148B00 00000000 */  nop       
/* DF204 80148B04 460CC602 */  mul.s     $f24, $f24, $f12
/* DF208 80148B08 00000000 */  nop       
/* DF20C 80148B0C 460CA502 */  mul.s     $f20, $f20, $f12
/* DF210 80148B10 00000000 */  nop       
/* DF214 80148B14 C6260008 */  lwc1      $f6, 8($s1)
/* DF218 80148B18 C7C200DC */  lwc1      $f2, 0xdc($fp)
/* DF21C 80148B1C 46003107 */  neg.s     $f4, $f6
/* DF220 80148B20 46022082 */  mul.s     $f2, $f4, $f2
/* DF224 80148B24 00000000 */  nop       
/* DF228 80148B28 C6280028 */  lwc1      $f8, 0x28($s1)
/* DF22C 80148B2C C7C000FC */  lwc1      $f0, 0xfc($fp)
/* DF230 80148B30 46004002 */  mul.s     $f0, $f8, $f0
/* DF234 80148B34 00000000 */  nop       
/* DF238 80148B38 46001080 */  add.s     $f2, $f2, $f0
/* DF23C 80148B3C 44800000 */  mtc1      $zero, $f0
/* DF240 80148B40 3C01BF80 */  lui       $at, 0xbf80
/* DF244 80148B44 4481F000 */  mtc1      $at, $f30
/* DF248 80148B48 4600103C */  c.lt.s    $f2, $f0
/* DF24C 80148B4C 00000000 */  nop       
/* DF250 80148B50 45000004 */  bc1f      .L80148B64
/* DF254 80148B54 00000000 */   nop      
/* DF258 80148B58 3C013F80 */  lui       $at, 0x3f80
/* DF25C 80148B5C 4481F000 */  mtc1      $at, $f30
/* DF260 80148B60 00000000 */  nop       
.L80148B64:
/* DF264 80148B64 4600F03C */  c.lt.s    $f30, $f0
/* DF268 80148B68 00000000 */  nop       
/* DF26C 80148B6C 45000004 */  bc1f      .L80148B80
/* DF270 80148B70 46003086 */   mov.s    $f2, $f6
/* DF274 80148B74 C6200018 */  lwc1      $f0, 0x18($s1)
/* DF278 80148B78 080522E2 */  j         .L80148B88
/* DF27C 80148B7C 46004207 */   neg.s    $f8, $f8
.L80148B80:
/* DF280 80148B80 46002086 */  mov.s     $f2, $f4
/* DF284 80148B84 C6200018 */  lwc1      $f0, 0x18($s1)
.L80148B88:
/* DF288 80148B88 46161102 */  mul.s     $f4, $f2, $f22
/* DF28C 80148B8C 00000000 */  nop       
/* DF290 80148B90 46180002 */  mul.s     $f0, $f0, $f24
/* DF294 80148B94 00000000 */  nop       
/* DF298 80148B98 46144202 */  mul.s     $f8, $f8, $f20
/* DF29C 80148B9C 00000000 */  nop       
/* DF2A0 80148BA0 C7C200FC */  lwc1      $f2, 0xfc($fp)
/* DF2A4 80148BA4 46001087 */  neg.s     $f2, $f2
/* DF2A8 80148BA8 4602B082 */  mul.s     $f2, $f22, $f2
/* DF2AC 80148BAC 00000000 */  nop       
/* DF2B0 80148BB0 C7C600DC */  lwc1      $f6, 0xdc($fp)
/* DF2B4 80148BB4 4606A182 */  mul.s     $f6, $f20, $f6
/* DF2B8 80148BB8 00000000 */  nop       
/* DF2BC 80148BBC 46002100 */  add.s     $f4, $f4, $f0
/* DF2C0 80148BC0 46082100 */  add.s     $f4, $f4, $f8
/* DF2C4 80148BC4 44800000 */  mtc1      $zero, $f0
/* DF2C8 80148BC8 00000000 */  nop       
/* DF2CC 80148BCC 4604003C */  c.lt.s    $f0, $f4
/* DF2D0 80148BD0 00000000 */  nop       
/* DF2D4 80148BD4 45000007 */  bc1f      .L80148BF4
/* DF2D8 80148BD8 46061180 */   add.s    $f6, $f2, $f6
/* DF2DC 80148BDC 44900000 */  mtc1      $s0, $f0
/* DF2E0 80148BE0 00000000 */  nop       
/* DF2E4 80148BE4 46800020 */  cvt.s.w   $f0, $f0
/* DF2E8 80148BE8 46060682 */  mul.s     $f26, $f0, $f6
/* DF2EC 80148BEC 08052302 */  j         .L80148C08
/* DF2F0 80148BF0 00000000 */   nop      
.L80148BF4:
/* DF2F4 80148BF4 44901000 */  mtc1      $s0, $f2
/* DF2F8 80148BF8 00000000 */  nop       
/* DF2FC 80148BFC 468010A0 */  cvt.s.w   $f2, $f2
/* DF300 80148C00 46061682 */  mul.s     $f26, $f2, $f6
/* DF304 80148C04 00000000 */  nop       
.L80148C08:
/* DF308 80148C08 4616B002 */  mul.s     $f0, $f22, $f22
/* DF30C 80148C0C 00000000 */  nop       
/* DF310 80148C10 4614A082 */  mul.s     $f2, $f20, $f20
/* DF314 80148C14 00000000 */  nop       
/* DF318 80148C18 46020500 */  add.s     $f20, $f0, $f2
/* DF31C 80148C1C 44800000 */  mtc1      $zero, $f0
/* DF320 80148C20 00000000 */  nop       
/* DF324 80148C24 4600A032 */  c.eq.s    $f20, $f0
/* DF328 80148C28 00000000 */  nop       
/* DF32C 80148C2C 45010009 */  bc1t      .L80148C54
/* DF330 80148C30 00000000 */   nop      
/* DF334 80148C34 4600A004 */  sqrt.s    $f0, $f20
/* DF338 80148C38 46000032 */  c.eq.s    $f0, $f0
/* DF33C 80148C3C 00000000 */  nop       
/* DF340 80148C40 45030004 */  bc1tl     .L80148C54
/* DF344 80148C44 46000506 */   mov.s    $f20, $f0
/* DF348 80148C48 0C0187BC */  jal       sqrtf
/* DF34C 80148C4C 4600A306 */   mov.s    $f12, $f20
/* DF350 80148C50 46000506 */  mov.s     $f20, $f0
.L80148C54:
/* DF354 80148C54 C6200004 */  lwc1      $f0, 4($s1)
/* DF358 80148C58 46000007 */  neg.s     $f0, $f0
/* DF35C 80148C5C 46000002 */  mul.s     $f0, $f0, $f0
/* DF360 80148C60 00000000 */  nop       
/* DF364 80148C64 C6220024 */  lwc1      $f2, 0x24($s1)
/* DF368 80148C68 46021082 */  mul.s     $f2, $f2, $f2
/* DF36C 80148C6C 00000000 */  nop       
/* DF370 80148C70 46020300 */  add.s     $f12, $f0, $f2
/* DF374 80148C74 44800000 */  mtc1      $zero, $f0
/* DF378 80148C78 C6360014 */  lwc1      $f22, 0x14($s1)
/* DF37C 80148C7C 46006032 */  c.eq.s    $f12, $f0
/* DF380 80148C80 00000000 */  nop       
/* DF384 80148C84 45010009 */  bc1t      .L80148CAC
/* DF388 80148C88 00000000 */   nop      
/* DF38C 80148C8C 46006004 */  sqrt.s    $f0, $f12
/* DF390 80148C90 46000032 */  c.eq.s    $f0, $f0
/* DF394 80148C94 00000000 */  nop       
/* DF398 80148C98 45030004 */  bc1tl     .L80148CAC
/* DF39C 80148C9C 46000306 */   mov.s    $f12, $f0
/* DF3A0 80148CA0 0C0187BC */  jal       sqrtf
/* DF3A4 80148CA4 00000000 */   nop      
/* DF3A8 80148CA8 46000306 */  mov.s     $f12, $f0
.L80148CAC:
/* DF3AC 80148CAC 460CA002 */  mul.s     $f0, $f20, $f12
/* DF3B0 80148CB0 00000000 */  nop       
/* DF3B4 80148CB4 4616C082 */  mul.s     $f2, $f24, $f22
/* DF3B8 80148CB8 00000000 */  nop       
/* DF3BC 80148CBC 46020000 */  add.s     $f0, $f0, $f2
/* DF3C0 80148CC0 2A620100 */  slti      $v0, $s3, 0x100
/* DF3C4 80148CC4 44901000 */  mtc1      $s0, $f2
/* DF3C8 80148CC8 00000000 */  nop       
/* DF3CC 80148CCC 468010A0 */  cvt.s.w   $f2, $f2
/* DF3D0 80148CD0 46000007 */  neg.s     $f0, $f0
/* DF3D4 80148CD4 46020702 */  mul.s     $f28, $f0, $f2
/* DF3D8 80148CD8 00000000 */  nop       
/* DF3DC 80148CDC 50400001 */  beql      $v0, $zero, .L80148CE4
/* DF3E0 80148CE0 241300FF */   addiu    $s3, $zero, 0xff
.L80148CE4:
/* DF3E4 80148CE4 2A420100 */  slti      $v0, $s2, 0x100
/* DF3E8 80148CE8 50400001 */  beql      $v0, $zero, .L80148CF0
/* DF3EC 80148CEC 241200FF */   addiu    $s2, $zero, 0xff
.L80148CF0:
/* DF3F0 80148CF0 2A820100 */  slti      $v0, $s4, 0x100
/* DF3F4 80148CF4 50400001 */  beql      $v0, $zero, .L80148CFC
/* DF3F8 80148CF8 241400FF */   addiu    $s4, $zero, 0xff
.L80148CFC:
/* DF3FC 80148CFC 2AC20100 */  slti      $v0, $s6, 0x100
/* DF400 80148D00 50400001 */  beql      $v0, $zero, .L80148D08
/* DF404 80148D04 241600FF */   addiu    $s6, $zero, 0xff
.L80148D08:
/* DF408 80148D08 2AA20100 */  slti      $v0, $s5, 0x100
/* DF40C 80148D0C 50400001 */  beql      $v0, $zero, .L80148D14
/* DF410 80148D10 241500FF */   addiu    $s5, $zero, 0xff
.L80148D14:
/* DF414 80148D14 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* DF418 80148D18 29E20100 */  slti      $v0, $t7, 0x100
/* DF41C 80148D1C 14400003 */  bnez      $v0, .L80148D2C
/* DF420 80148D20 3C07FC21 */   lui      $a3, 0xfc21
/* DF424 80148D24 240F00FF */  addiu     $t7, $zero, 0xff
/* DF428 80148D28 AFAF00A8 */  sw        $t7, 0xa8($sp)
.L80148D2C:
/* DF42C 80148D2C 34E7FE07 */  ori       $a3, $a3, 0xfe07
/* DF430 80148D30 3C06F167 */  lui       $a2, 0xf167
/* DF434 80148D34 34C6F27F */  ori       $a2, $a2, 0xf27f
/* DF438 80148D38 3C0DFF10 */  lui       $t5, 0xff10
/* DF43C 80148D3C 35AD013F */  ori       $t5, $t5, 0x13f
/* DF440 80148D40 3C080004 */  lui       $t0, 4
/* DF444 80148D44 35080004 */  ori       $t0, $t0, 4
/* DF448 80148D48 3C0FE300 */  lui       $t7, 0xe300
/* DF44C 80148D4C 35EF0A11 */  ori       $t7, $t7, 0xa11
/* DF450 80148D50 AFAF0010 */  sw        $t7, 0x10($sp)
/* DF454 80148D54 3C0FE200 */  lui       $t7, 0xe200
/* DF458 80148D58 35EF001C */  ori       $t7, $t7, 0x1c
/* DF45C 80148D5C 3C090F0A */  lui       $t1, 0xf0a
/* DF460 80148D60 35294000 */  ori       $t1, $t1, 0x4000
/* DF464 80148D64 3C0BFC34 */  lui       $t3, 0xfc34
/* DF468 80148D68 356B7E68 */  ori       $t3, $t3, 0x7e68
/* DF46C 80148D6C 3C0A55FE */  lui       $t2, 0x55fe
/* DF470 80148D70 354AFD7E */  ori       $t2, $t2, 0xfd7e
/* DF474 80148D74 3C0CE404 */  lui       $t4, 0xe404
/* DF478 80148D78 358C0004 */  ori       $t4, $t4, 4
/* DF47C 80148D7C 3C0E1000 */  lui       $t6, 0x1000
/* DF480 80148D80 3C17800A */  lui       $s7, %hi(D_8009A66C)
/* DF484 80148D84 26F7A66C */  addiu     $s7, $s7, %lo(D_8009A66C)
/* DF488 80148D88 35CE0400 */  ori       $t6, $t6, 0x400
/* DF48C 80148D8C 3C05FA00 */  lui       $a1, 0xfa00
/* DF490 80148D90 00131E00 */  sll       $v1, $s3, 0x18
/* DF494 80148D94 324200FF */  andi      $v0, $s2, 0xff
/* DF498 80148D98 00021400 */  sll       $v0, $v0, 0x10
/* DF49C 80148D9C 00621825 */  or        $v1, $v1, $v0
/* DF4A0 80148DA0 328200FF */  andi      $v0, $s4, 0xff
/* DF4A4 80148DA4 00021200 */  sll       $v0, $v0, 8
/* DF4A8 80148DA8 00621825 */  or        $v1, $v1, $v0
/* DF4AC 80148DAC 3C138016 */  lui       $s3, %hi(D_80159880)
/* DF4B0 80148DB0 26739880 */  addiu     $s3, $s3, %lo(D_80159880)
/* DF4B4 80148DB4 3C12ED00 */  lui       $s2, 0xed00
/* DF4B8 80148DB8 AFAF0014 */  sw        $t7, 0x14($sp)
/* DF4BC 80148DBC 8EF00000 */  lw        $s0, ($s7)
/* DF4C0 80148DC0 3C14FB00 */  lui       $s4, 0xfb00
/* DF4C4 80148DC4 0200202D */  daddu     $a0, $s0, $zero
/* DF4C8 80148DC8 26100008 */  addiu     $s0, $s0, 8
/* DF4CC 80148DCC AEF00000 */  sw        $s0, ($s7)
/* DF4D0 80148DD0 AC850000 */  sw        $a1, ($a0)
/* DF4D4 80148DD4 8FAF0084 */  lw        $t7, 0x84($sp)
/* DF4D8 80148DD8 3C11E700 */  lui       $s1, 0xe700
/* DF4DC 80148DDC 31E200FF */  andi      $v0, $t7, 0xff
/* DF4E0 80148DE0 00621825 */  or        $v1, $v1, $v0
/* DF4E4 80148DE4 26020008 */  addiu     $v0, $s0, 8
/* DF4E8 80148DE8 AC830004 */  sw        $v1, 4($a0)
/* DF4EC 80148DEC AEE20000 */  sw        $v0, ($s7)
/* DF4F0 80148DF0 26020010 */  addiu     $v0, $s0, 0x10
/* DF4F4 80148DF4 AE070000 */  sw        $a3, ($s0)
/* DF4F8 80148DF8 AE060004 */  sw        $a2, 4($s0)
/* DF4FC 80148DFC AEE20000 */  sw        $v0, ($s7)
/* DF500 80148E00 26020018 */  addiu     $v0, $s0, 0x18
/* DF504 80148E04 AE0D0008 */  sw        $t5, 8($s0)
/* DF508 80148E08 AE13000C */  sw        $s3, 0xc($s0)
/* DF50C 80148E0C AEE20000 */  sw        $v0, ($s7)
/* DF510 80148E10 26020020 */  addiu     $v0, $s0, 0x20
/* DF514 80148E14 AE120010 */  sw        $s2, 0x10($s0)
/* DF518 80148E18 AE080014 */  sw        $t0, 0x14($s0)
/* DF51C 80148E1C AEE20000 */  sw        $v0, ($s7)
/* DF520 80148E20 8FAF0010 */  lw        $t7, 0x10($sp)
/* DF524 80148E24 24020CF0 */  addiu     $v0, $zero, 0xcf0
/* DF528 80148E28 AE02001C */  sw        $v0, 0x1c($s0)
/* DF52C 80148E2C 26020028 */  addiu     $v0, $s0, 0x28
/* DF530 80148E30 AE0F0018 */  sw        $t7, 0x18($s0)
/* DF534 80148E34 AEE20000 */  sw        $v0, ($s7)
/* DF538 80148E38 8FAF0014 */  lw        $t7, 0x14($sp)
/* DF53C 80148E3C 26020030 */  addiu     $v0, $s0, 0x30
/* DF540 80148E40 AE090024 */  sw        $t1, 0x24($s0)
/* DF544 80148E44 AE0F0020 */  sw        $t7, 0x20($s0)
/* DF548 80148E48 AEE20000 */  sw        $v0, ($s7)
/* DF54C 80148E4C 26020038 */  addiu     $v0, $s0, 0x38
/* DF550 80148E50 AE03002C */  sw        $v1, 0x2c($s0)
/* DF554 80148E54 00161E00 */  sll       $v1, $s6, 0x18
/* DF558 80148E58 AE050028 */  sw        $a1, 0x28($s0)
/* DF55C 80148E5C AEE20000 */  sw        $v0, ($s7)
/* DF560 80148E60 32A200FF */  andi      $v0, $s5, 0xff
/* DF564 80148E64 00021400 */  sll       $v0, $v0, 0x10
/* DF568 80148E68 AE140030 */  sw        $s4, 0x30($s0)
/* DF56C 80148E6C 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* DF570 80148E70 00621825 */  or        $v1, $v1, $v0
/* DF574 80148E74 31E200FF */  andi      $v0, $t7, 0xff
/* DF578 80148E78 00021200 */  sll       $v0, $v0, 8
/* DF57C 80148E7C 00621825 */  or        $v1, $v1, $v0
/* DF580 80148E80 26020040 */  addiu     $v0, $s0, 0x40
/* DF584 80148E84 AE030034 */  sw        $v1, 0x34($s0)
/* DF588 80148E88 AEE20000 */  sw        $v0, ($s7)
/* DF58C 80148E8C 26020048 */  addiu     $v0, $s0, 0x48
/* DF590 80148E90 AE0B0038 */  sw        $t3, 0x38($s0)
/* DF594 80148E94 AE0A003C */  sw        $t2, 0x3c($s0)
/* DF598 80148E98 AEE20000 */  sw        $v0, ($s7)
/* DF59C 80148E9C 3C020200 */  lui       $v0, 0x200
/* DF5A0 80148EA0 AE020044 */  sw        $v0, 0x44($s0)
/* DF5A4 80148EA4 26020050 */  addiu     $v0, $s0, 0x50
/* DF5A8 80148EA8 AE0C0040 */  sw        $t4, 0x40($s0)
/* DF5AC 80148EAC AEE20000 */  sw        $v0, ($s7)
/* DF5B0 80148EB0 3C02E100 */  lui       $v0, 0xe100
/* DF5B4 80148EB4 AE020048 */  sw        $v0, 0x48($s0)
/* DF5B8 80148EB8 26020058 */  addiu     $v0, $s0, 0x58
/* DF5BC 80148EBC AE00004C */  sw        $zero, 0x4c($s0)
/* DF5C0 80148EC0 AEE20000 */  sw        $v0, ($s7)
/* DF5C4 80148EC4 3C02F100 */  lui       $v0, 0xf100
/* DF5C8 80148EC8 AE020050 */  sw        $v0, 0x50($s0)
/* DF5CC 80148ECC 26020060 */  addiu     $v0, $s0, 0x60
/* DF5D0 80148ED0 AE0E0054 */  sw        $t6, 0x54($s0)
/* DF5D4 80148ED4 AEE20000 */  sw        $v0, ($s7)
/* DF5D8 80148ED8 3C04800A */  lui       $a0, %hi(D_8009A64C)
/* DF5DC 80148EDC 8C84A64C */  lw        $a0, %lo(D_8009A64C)($a0)
/* DF5E0 80148EE0 26020068 */  addiu     $v0, $s0, 0x68
/* DF5E4 80148EE4 AE110058 */  sw        $s1, 0x58($s0)
/* DF5E8 80148EE8 AE00005C */  sw        $zero, 0x5c($s0)
/* DF5EC 80148EEC AEE20000 */  sw        $v0, ($s7)
/* DF5F0 80148EF0 0C0187A4 */  jal       osVirtualToPhysical
/* DF5F4 80148EF4 AE0D0060 */   sw       $t5, 0x60($s0)
/* DF5F8 80148EF8 3C06F500 */  lui       $a2, 0xf500
/* DF5FC 80148EFC 34C60110 */  ori       $a2, $a2, 0x110
/* DF600 80148F00 3C070703 */  lui       $a3, 0x703
/* DF604 80148F04 34E7C000 */  ori       $a3, $a3, 0xc000
/* DF608 80148F08 3C080018 */  lui       $t0, 0x18
/* DF60C 80148F0C 8EEA0000 */  lw        $t2, ($s7)
/* DF610 80148F10 3C014080 */  lui       $at, 0x4080
/* DF614 80148F14 44812000 */  mtc1      $at, $f4
/* DF618 80148F18 3508AC30 */  ori       $t0, $t0, 0xac30
/* DF61C 80148F1C AE020064 */  sw        $v0, 0x64($s0)
/* DF620 80148F20 0140282D */  daddu     $a1, $t2, $zero
/* DF624 80148F24 254A0008 */  addiu     $t2, $t2, 8
/* DF628 80148F28 25420008 */  addiu     $v0, $t2, 8
/* DF62C 80148F2C AEEA0000 */  sw        $t2, ($s7)
/* DF630 80148F30 AEE20000 */  sw        $v0, ($s7)
/* DF634 80148F34 25420010 */  addiu     $v0, $t2, 0x10
/* DF638 80148F38 AEE20000 */  sw        $v0, ($s7)
/* DF63C 80148F3C 25420018 */  addiu     $v0, $t2, 0x18
/* DF640 80148F40 AEE20000 */  sw        $v0, ($s7)
/* DF644 80148F44 87C2000E */  lh        $v0, 0xe($fp)
/* DF648 80148F48 87C30010 */  lh        $v1, 0x10($fp)
/* DF64C 80148F4C 44821000 */  mtc1      $v0, $f2
/* DF650 80148F50 00000000 */  nop       
/* DF654 80148F54 468010A0 */  cvt.s.w   $f2, $f2
/* DF658 80148F58 46041082 */  mul.s     $f2, $f2, $f4
/* DF65C 80148F5C 00000000 */  nop       
/* DF660 80148F60 25420020 */  addiu     $v0, $t2, 0x20
/* DF664 80148F64 44830000 */  mtc1      $v1, $f0
/* DF668 80148F68 00000000 */  nop       
/* DF66C 80148F6C 46800020 */  cvt.s.w   $f0, $f0
/* DF670 80148F70 AEE20000 */  sw        $v0, ($s7)
/* DF674 80148F74 25420028 */  addiu     $v0, $t2, 0x28
/* DF678 80148F78 46040002 */  mul.s     $f0, $f0, $f4
/* DF67C 80148F7C 00000000 */  nop       
/* DF680 80148F80 AEE20000 */  sw        $v0, ($s7)
/* DF684 80148F84 4600128D */  trunc.w.s $f10, $f2
/* DF688 80148F88 44035000 */  mfc1      $v1, $f10
/* DF68C 80148F8C 00000000 */  nop       
/* DF690 80148F90 30630FFF */  andi      $v1, $v1, 0xfff
/* DF694 80148F94 00031B00 */  sll       $v1, $v1, 0xc
/* DF698 80148F98 4600028D */  trunc.w.s $f10, $f0
/* DF69C 80148F9C 44025000 */  mfc1      $v0, $f10
/* DF6A0 80148FA0 00000000 */  nop       
/* DF6A4 80148FA4 30420FFF */  andi      $v0, $v0, 0xfff
/* DF6A8 80148FA8 00521025 */  or        $v0, $v0, $s2
/* DF6AC 80148FAC 00621825 */  or        $v1, $v1, $v0
/* DF6B0 80148FB0 ACA30000 */  sw        $v1, ($a1)
/* DF6B4 80148FB4 87C3000E */  lh        $v1, 0xe($fp)
/* DF6B8 80148FB8 87C4000A */  lh        $a0, 0xa($fp)
/* DF6BC 80148FBC 25420030 */  addiu     $v0, $t2, 0x30
/* DF6C0 80148FC0 AEE20000 */  sw        $v0, ($s7)
/* DF6C4 80148FC4 87C20010 */  lh        $v0, 0x10($fp)
/* DF6C8 80148FC8 00641821 */  addu      $v1, $v1, $a0
/* DF6CC 80148FCC 44831000 */  mtc1      $v1, $f2
/* DF6D0 80148FD0 00000000 */  nop       
/* DF6D4 80148FD4 468010A0 */  cvt.s.w   $f2, $f2
/* DF6D8 80148FD8 25440038 */  addiu     $a0, $t2, 0x38
/* DF6DC 80148FDC 87C3000C */  lh        $v1, 0xc($fp)
/* DF6E0 80148FE0 46041082 */  mul.s     $f2, $f2, $f4
/* DF6E4 80148FE4 00000000 */  nop       
/* DF6E8 80148FE8 AEE40000 */  sw        $a0, ($s7)
/* DF6EC 80148FEC 00431021 */  addu      $v0, $v0, $v1
/* DF6F0 80148FF0 44820000 */  mtc1      $v0, $f0
/* DF6F4 80148FF4 00000000 */  nop       
/* DF6F8 80148FF8 46800020 */  cvt.s.w   $f0, $f0
/* DF6FC 80148FFC 25420040 */  addiu     $v0, $t2, 0x40
/* DF700 80149000 46040002 */  mul.s     $f0, $f0, $f4
/* DF704 80149004 00000000 */  nop       
/* DF708 80149008 AEE20000 */  sw        $v0, ($s7)
/* DF70C 8014900C 4600128D */  trunc.w.s $f10, $f2
/* DF710 80149010 44025000 */  mfc1      $v0, $f10
/* DF714 80149014 00000000 */  nop       
/* DF718 80149018 30420FFF */  andi      $v0, $v0, 0xfff
/* DF71C 8014901C 00021300 */  sll       $v0, $v0, 0xc
/* DF720 80149020 4600028D */  trunc.w.s $f10, $f0
/* DF724 80149024 44035000 */  mfc1      $v1, $f10
/* DF728 80149028 00000000 */  nop       
/* DF72C 8014902C 30630FFF */  andi      $v1, $v1, 0xfff
/* DF730 80149030 00431025 */  or        $v0, $v0, $v1
/* DF734 80149034 ACA20004 */  sw        $v0, 4($a1)
/* DF738 80149038 3C02FD10 */  lui       $v0, 0xfd10
/* DF73C 8014903C AD420000 */  sw        $v0, ($t2)
/* DF740 80149040 3C02E800 */  lui       $v0, 0xe800
/* DF744 80149044 AD420008 */  sw        $v0, 8($t2)
/* DF748 80149048 3C020700 */  lui       $v0, 0x700
/* DF74C 8014904C AD420014 */  sw        $v0, 0x14($t2)
/* DF750 80149050 3C02E600 */  lui       $v0, 0xe600
/* DF754 80149054 AD420018 */  sw        $v0, 0x18($t2)
/* DF758 80149058 3C02F000 */  lui       $v0, 0xf000
/* DF75C 8014905C AD530004 */  sw        $s3, 4($t2)
/* DF760 80149060 AD40000C */  sw        $zero, 0xc($t2)
/* DF764 80149064 AD460010 */  sw        $a2, 0x10($t2)
/* DF768 80149068 AD40001C */  sw        $zero, 0x1c($t2)
/* DF76C 8014906C AD420020 */  sw        $v0, 0x20($t2)
/* DF770 80149070 AD470024 */  sw        $a3, 0x24($t2)
/* DF774 80149074 AD510028 */  sw        $s1, 0x28($t2)
/* DF778 80149078 AD40002C */  sw        $zero, 0x2c($t2)
/* DF77C 8014907C 8FAF0010 */  lw        $t7, 0x10($sp)
/* DF780 80149080 3C096464 */  lui       $t1, 0x6464
/* DF784 80149084 AD4F0030 */  sw        $t7, 0x30($t2)
/* DF788 80149088 AD480034 */  sw        $t0, 0x34($t2)
/* DF78C 8014908C 8FAF0014 */  lw        $t7, 0x14($sp)
/* DF790 80149090 352964FF */  ori       $t1, $t1, 0x64ff
/* DF794 80149094 AD4F0038 */  sw        $t7, 0x38($t2)
/* DF798 80149098 8FA200B0 */  lw        $v0, 0xb0($sp)
/* DF79C 8014909C 3C030C08 */  lui       $v1, 0xc08
/* DF7A0 801490A0 00431025 */  or        $v0, $v0, $v1
/* DF7A4 801490A4 AD42003C */  sw        $v0, 0x3c($t2)
/* DF7A8 801490A8 25420048 */  addiu     $v0, $t2, 0x48
/* DF7AC 801490AC AEE20000 */  sw        $v0, ($s7)
/* DF7B0 801490B0 AD540040 */  sw        $s4, 0x40($t2)
/* DF7B4 801490B4 AD490044 */  sw        $t1, 0x44($t2)
/* DF7B8 801490B8 8FAF0084 */  lw        $t7, 0x84($sp)
/* DF7BC 801490BC 240200FF */  addiu     $v0, $zero, 0xff
/* DF7C0 801490C0 15E20005 */  bne       $t7, $v0, .L801490D8
/* DF7C4 801490C4 3C04FC11 */   lui      $a0, 0xfc11
/* DF7C8 801490C8 34847E80 */  ori       $a0, $a0, 0x7e80
/* DF7CC 801490CC 3C03F5FF */  lui       $v1, 0xf5ff
/* DF7D0 801490D0 08052439 */  j         .L801490E4
/* DF7D4 801490D4 3463F438 */   ori      $v1, $v1, 0xf438
.L801490D8:
/* DF7D8 801490D8 34843480 */  ori       $a0, $a0, 0x3480
/* DF7DC 801490DC 3C03F5FF */  lui       $v1, %hi(D_F5FEA66C)
/* DF7E0 801490E0 3463FE38 */  ori       $v1, $v1, 0xfe38
.L801490E4:
/* DF7E4 801490E4 25420050 */  addiu     $v0, $t2, 0x50
/* DF7E8 801490E8 AEE20000 */  sw        $v0, ($s7)
/* DF7EC 801490EC AD440048 */  sw        $a0, 0x48($t2)
/* DF7F0 801490F0 AD43004C */  sw        $v1, 0x4c($t2)
/* DF7F4 801490F4 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* DF7F8 801490F8 2463A66C */  addiu     $v1, $v1, %lo(D_F5FEA66C)
/* DF7FC 801490FC 8C620000 */  lw        $v0, ($v1)
/* DF800 80149100 461ED002 */  mul.s     $f0, $f26, $f30
/* DF804 80149104 00000000 */  nop       
/* DF808 80149108 0040382D */  daddu     $a3, $v0, $zero
/* DF80C 8014910C 24420008 */  addiu     $v0, $v0, 8
/* DF810 80149110 AC620000 */  sw        $v0, ($v1)
/* DF814 80149114 8FAF0074 */  lw        $t7, 0x74($sp)
/* DF818 80149118 3C04F200 */  lui       $a0, 0xf200
/* DF81C 8014911C 25E30100 */  addiu     $v1, $t7, 0x100
/* DF820 80149120 00031880 */  sll       $v1, $v1, 2
/* DF824 80149124 4600028D */  trunc.w.s $f10, $f0
/* DF828 80149128 44055000 */  mfc1      $a1, $f10
/* DF82C 8014912C 00000000 */  nop       
/* DF830 80149130 00651821 */  addu      $v1, $v1, $a1
/* DF834 80149134 30630FFF */  andi      $v1, $v1, 0xfff
/* DF838 80149138 8FAF0078 */  lw        $t7, 0x78($sp)
/* DF83C 8014913C 00031B00 */  sll       $v1, $v1, 0xc
/* DF840 80149140 25E20100 */  addiu     $v0, $t7, 0x100
/* DF844 80149144 00021080 */  sll       $v0, $v0, 2
/* DF848 80149148 4600E28D */  trunc.w.s $f10, $f28
/* DF84C 8014914C 44065000 */  mfc1      $a2, $f10
/* DF850 80149150 00000000 */  nop       
/* DF854 80149154 00461021 */  addu      $v0, $v0, $a2
/* DF858 80149158 30420FFF */  andi      $v0, $v0, 0xfff
/* DF85C 8014915C 00441025 */  or        $v0, $v0, $a0
/* DF860 80149160 00621825 */  or        $v1, $v1, $v0
/* DF864 80149164 ACE30000 */  sw        $v1, ($a3)
/* DF868 80149168 8FAF007C */  lw        $t7, 0x7c($sp)
/* DF86C 8014916C 8FA20080 */  lw        $v0, 0x80($sp)
/* DF870 80149170 25E300FF */  addiu     $v1, $t7, 0xff
/* DF874 80149174 00031880 */  sll       $v1, $v1, 2
/* DF878 80149178 00651821 */  addu      $v1, $v1, $a1
/* DF87C 8014917C 30630FFF */  andi      $v1, $v1, 0xfff
/* DF880 80149180 00031B00 */  sll       $v1, $v1, 0xc
/* DF884 80149184 244200FF */  addiu     $v0, $v0, 0xff
/* DF888 80149188 00021080 */  sll       $v0, $v0, 2
/* DF88C 8014918C 00461021 */  addu      $v0, $v0, $a2
/* DF890 80149190 30420FFF */  andi      $v0, $v0, 0xfff
/* DF894 80149194 00621825 */  or        $v1, $v1, $v0
/* DF898 80149198 ACE30004 */  sw        $v1, 4($a3)
/* DF89C 8014919C 8FBF003C */  lw        $ra, 0x3c($sp)
/* DF8A0 801491A0 8FBE0038 */  lw        $fp, 0x38($sp)
/* DF8A4 801491A4 8FB70034 */  lw        $s7, 0x34($sp)
/* DF8A8 801491A8 8FB60030 */  lw        $s6, 0x30($sp)
/* DF8AC 801491AC 8FB5002C */  lw        $s5, 0x2c($sp)
/* DF8B0 801491B0 8FB40028 */  lw        $s4, 0x28($sp)
/* DF8B4 801491B4 8FB30024 */  lw        $s3, 0x24($sp)
/* DF8B8 801491B8 8FB20020 */  lw        $s2, 0x20($sp)
/* DF8BC 801491BC 8FB1001C */  lw        $s1, 0x1c($sp)
/* DF8C0 801491C0 8FB00018 */  lw        $s0, 0x18($sp)
/* DF8C4 801491C4 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* DF8C8 801491C8 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* DF8CC 801491CC D7BA0058 */  ldc1      $f26, 0x58($sp)
/* DF8D0 801491D0 D7B80050 */  ldc1      $f24, 0x50($sp)
/* DF8D4 801491D4 D7B60048 */  ldc1      $f22, 0x48($sp)
/* DF8D8 801491D8 D7B40040 */  ldc1      $f20, 0x40($sp)
/* DF8DC 801491DC 03E00008 */  jr        $ra
/* DF8E0 801491E0 27BD0070 */   addiu    $sp, $sp, 0x70
