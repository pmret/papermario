.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

/* Generated by spimdisasm 1.11.1 */

glabel appendGfx_shading_palette
/* DE028 80147148 27BDFF90 */  addiu     $sp, $sp, -0x70
/* DE02C 8014714C F7B60048 */  sdc1      $f22, 0x48($sp)
/* DE030 80147150 C7B60088 */  lwc1      $f22, 0x88($sp)
/* DE034 80147154 F7B80050 */  sdc1      $f24, 0x50($sp)
/* DE038 80147158 C7B8008C */  lwc1      $f24, 0x8C($sp)
/* DE03C 8014715C F7B40040 */  sdc1      $f20, 0x40($sp)
/* DE040 80147160 C7B40090 */  lwc1      $f20, 0x90($sp)
/* DE044 80147164 AFB30024 */  sw        $s3, 0x24($sp)
/* DE048 80147168 8FB30094 */  lw        $s3, 0x94($sp)
/* DE04C 8014716C AFB20020 */  sw        $s2, 0x20($sp)
/* DE050 80147170 8FB20098 */  lw        $s2, 0x98($sp)
/* DE054 80147174 AFB40028 */  sw        $s4, 0x28($sp)
/* DE058 80147178 8FB4009C */  lw        $s4, 0x9C($sp)
/* DE05C 8014717C AFB60030 */  sw        $s6, 0x30($sp)
/* DE060 80147180 8FB600A0 */  lw        $s6, 0xA0($sp)
/* DE064 80147184 AFB5002C */  sw        $s5, 0x2C($sp)
/* DE068 80147188 8FB500A4 */  lw        $s5, 0xA4($sp)
/* DE06C 8014718C AFB00018 */  sw        $s0, 0x18($sp)
/* DE070 80147190 8FB000AC */  lw        $s0, 0xAC($sp)
/* DE074 80147194 AFB1001C */  sw        $s1, 0x1C($sp)
/* DE078 80147198 0080882D */  daddu     $s1, $a0, $zero
/* DE07C 8014719C F7BC0060 */  sdc1      $f28, 0x60($sp)
/* DE080 801471A0 4480E000 */  mtc1      $zero, $f28
/* DE084 801471A4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* DE088 801471A8 8C636070 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* DE08C 801471AC 3C04800B */  lui       $a0, %hi(gCameras)
/* DE090 801471B0 248407D0 */  addiu     $a0, $a0, %lo(gCameras)
/* DE094 801471B4 AFBF003C */  sw        $ra, 0x3C($sp)
/* DE098 801471B8 4616B002 */  mul.s     $f0, $f22, $f22
/* DE09C 801471BC 00000000 */  nop
/* DE0A0 801471C0 AFBE0038 */  sw        $fp, 0x38($sp)
/* DE0A4 801471C4 AFB70034 */  sw        $s7, 0x34($sp)
/* DE0A8 801471C8 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* DE0AC 801471CC F7BA0058 */  sdc1      $f26, 0x58($sp)
/* DE0B0 801471D0 4618C082 */  mul.s     $f2, $f24, $f24
/* DE0B4 801471D4 00000000 */  nop
/* DE0B8 801471D8 AFA50074 */  sw        $a1, 0x74($sp)
/* DE0BC 801471DC AFA60078 */  sw        $a2, 0x78($sp)
/* DE0C0 801471E0 AFA7007C */  sw        $a3, 0x7C($sp)
/* DE0C4 801471E4 00031080 */  sll       $v0, $v1, 2
/* DE0C8 801471E8 4614A102 */  mul.s     $f4, $f20, $f20
/* DE0CC 801471EC 00000000 */  nop
/* DE0D0 801471F0 00431021 */  addu      $v0, $v0, $v1
/* DE0D4 801471F4 00021080 */  sll       $v0, $v0, 2
/* DE0D8 801471F8 00431023 */  subu      $v0, $v0, $v1
/* DE0DC 801471FC 000218C0 */  sll       $v1, $v0, 3
/* DE0E0 80147200 46020000 */  add.s     $f0, $f0, $f2
/* DE0E4 80147204 00431021 */  addu      $v0, $v0, $v1
/* DE0E8 80147208 000210C0 */  sll       $v0, $v0, 3
/* DE0EC 8014720C 46040300 */  add.s     $f12, $f0, $f4
/* DE0F0 80147210 3C013FF0 */  lui       $at, (0x3FF00000 >> 16)
/* DE0F4 80147214 44811800 */  mtc1      $at, $f3
/* DE0F8 80147218 44801000 */  mtc1      $zero, $f2
/* DE0FC 8014721C 46006021 */  cvt.d.s   $f0, $f12
/* DE100 80147220 4622003C */  c.lt.d    $f0, $f2
/* DE104 80147224 00000000 */  nop
/* DE108 80147228 45000008 */  bc1f      .LIQUE_8014724C
/* DE10C 8014722C 0044F021 */   addu     $fp, $v0, $a0
/* DE110 80147230 44900000 */  mtc1      $s0, $f0
/* DE114 80147234 00000000 */  nop
/* DE118 80147238 46800020 */  cvt.s.w   $f0, $f0
/* DE11C 8014723C 460C0002 */  mul.s     $f0, $f0, $f12
/* DE120 80147240 00000000 */  nop
/* DE124 80147244 4600028D */  trunc.w.s $f10, $f0
/* DE128 80147248 44105000 */  mfc1      $s0, $f10
.LIQUE_8014724C:
/* DE12C 8014724C 461C6032 */  c.eq.s    $f12, $f28
/* DE130 80147250 00000000 */  nop
/* DE134 80147254 4501000D */  bc1t      .LIQUE_8014728C
/* DE138 80147258 00000000 */   nop
/* DE13C 8014725C 46006084 */  sqrt.s    $f2, $f12
/* DE140 80147260 46021032 */  c.eq.s    $f2, $f2
/* DE144 80147264 00000000 */  nop
/* DE148 80147268 45010004 */  bc1t      .LIQUE_8014727C
/* DE14C 8014726C 00000000 */   nop
/* DE150 80147270 0C0183A0 */  jal       sqrtf
/* DE154 80147274 00000000 */   nop
/* DE158 80147278 46000086 */  mov.s     $f2, $f0
.LIQUE_8014727C:
/* DE15C 8014727C 3C013F80 */  lui       $at, (0x3F800000 >> 16)
/* DE160 80147280 44810000 */  mtc1      $at, $f0
/* DE164 80147284 00000000 */  nop
/* DE168 80147288 46020303 */  div.s     $f12, $f0, $f2
.LIQUE_8014728C:
/* DE16C 8014728C 460CB582 */  mul.s     $f22, $f22, $f12
/* DE170 80147290 00000000 */  nop
/* DE174 80147294 460CC602 */  mul.s     $f24, $f24, $f12
/* DE178 80147298 00000000 */  nop
/* DE17C 8014729C 460CA502 */  mul.s     $f20, $f20, $f12
/* DE180 801472A0 00000000 */  nop
/* DE184 801472A4 C6260008 */  lwc1      $f6, 0x8($s1)
/* DE188 801472A8 C7C200DC */  lwc1      $f2, 0xDC($fp)
/* DE18C 801472AC 46003107 */  neg.s     $f4, $f6
/* DE190 801472B0 46022082 */  mul.s     $f2, $f4, $f2
/* DE194 801472B4 00000000 */  nop
/* DE198 801472B8 C6280028 */  lwc1      $f8, 0x28($s1)
/* DE19C 801472BC C7C000FC */  lwc1      $f0, 0xFC($fp)
/* DE1A0 801472C0 46004002 */  mul.s     $f0, $f8, $f0
/* DE1A4 801472C4 00000000 */  nop
/* DE1A8 801472C8 46001080 */  add.s     $f2, $f2, $f0
/* DE1AC 801472CC 44800000 */  mtc1      $zero, $f0
/* DE1B0 801472D0 3C01BF80 */  lui       $at, (0xBF800000 >> 16)
/* DE1B4 801472D4 4481F000 */  mtc1      $at, $f30
/* DE1B8 801472D8 4600103C */  c.lt.s    $f2, $f0
/* DE1BC 801472DC 00000000 */  nop
/* DE1C0 801472E0 45000004 */  bc1f      .LIQUE_801472F4
/* DE1C4 801472E4 00000000 */   nop
/* DE1C8 801472E8 3C013F80 */  lui       $at, (0x3F800000 >> 16)
/* DE1CC 801472EC 4481F000 */  mtc1      $at, $f30
/* DE1D0 801472F0 00000000 */  nop
.LIQUE_801472F4:
/* DE1D4 801472F4 4600F03C */  c.lt.s    $f30, $f0
/* DE1D8 801472F8 00000000 */  nop
/* DE1DC 801472FC 45000004 */  bc1f      .LIQUE_80147310
/* DE1E0 80147300 46003086 */   mov.s    $f2, $f6
/* DE1E4 80147304 C6200018 */  lwc1      $f0, 0x18($s1)
/* DE1E8 80147308 08051CC6 */  j         .LIQUE_80147318
/* DE1EC 8014730C 46004207 */   neg.s    $f8, $f8
.LIQUE_80147310:
/* DE1F0 80147310 46002086 */  mov.s     $f2, $f4
/* DE1F4 80147314 C6200018 */  lwc1      $f0, 0x18($s1)
.LIQUE_80147318:
/* DE1F8 80147318 46161102 */  mul.s     $f4, $f2, $f22
/* DE1FC 8014731C 00000000 */  nop
/* DE200 80147320 46180002 */  mul.s     $f0, $f0, $f24
/* DE204 80147324 00000000 */  nop
/* DE208 80147328 46144202 */  mul.s     $f8, $f8, $f20
/* DE20C 8014732C 00000000 */  nop
/* DE210 80147330 C7C200FC */  lwc1      $f2, 0xFC($fp)
/* DE214 80147334 46001087 */  neg.s     $f2, $f2
/* DE218 80147338 4602B082 */  mul.s     $f2, $f22, $f2
/* DE21C 8014733C 00000000 */  nop
/* DE220 80147340 C7C600DC */  lwc1      $f6, 0xDC($fp)
/* DE224 80147344 4606A182 */  mul.s     $f6, $f20, $f6
/* DE228 80147348 00000000 */  nop
/* DE22C 8014734C 46002100 */  add.s     $f4, $f4, $f0
/* DE230 80147350 46082100 */  add.s     $f4, $f4, $f8
/* DE234 80147354 44800000 */  mtc1      $zero, $f0
/* DE238 80147358 00000000 */  nop
/* DE23C 8014735C 4604003C */  c.lt.s    $f0, $f4
/* DE240 80147360 00000000 */  nop
/* DE244 80147364 45000007 */  bc1f      .LIQUE_80147384
/* DE248 80147368 46061180 */   add.s    $f6, $f2, $f6
/* DE24C 8014736C 44900000 */  mtc1      $s0, $f0
/* DE250 80147370 00000000 */  nop
/* DE254 80147374 46800020 */  cvt.s.w   $f0, $f0
/* DE258 80147378 46060682 */  mul.s     $f26, $f0, $f6
/* DE25C 8014737C 08051CE6 */  j         .LIQUE_80147398
/* DE260 80147380 00000000 */   nop
.LIQUE_80147384:
/* DE264 80147384 44901000 */  mtc1      $s0, $f2
/* DE268 80147388 00000000 */  nop
/* DE26C 8014738C 468010A0 */  cvt.s.w   $f2, $f2
/* DE270 80147390 46061682 */  mul.s     $f26, $f2, $f6
/* DE274 80147394 00000000 */  nop
.LIQUE_80147398:
/* DE278 80147398 4616B002 */  mul.s     $f0, $f22, $f22
/* DE27C 8014739C 00000000 */  nop
/* DE280 801473A0 4614A082 */  mul.s     $f2, $f20, $f20
/* DE284 801473A4 00000000 */  nop
/* DE288 801473A8 46020500 */  add.s     $f20, $f0, $f2
/* DE28C 801473AC 44800000 */  mtc1      $zero, $f0
/* DE290 801473B0 00000000 */  nop
/* DE294 801473B4 4600A032 */  c.eq.s    $f20, $f0
/* DE298 801473B8 00000000 */  nop
/* DE29C 801473BC 45010009 */  bc1t      .LIQUE_801473E4
/* DE2A0 801473C0 00000000 */   nop
/* DE2A4 801473C4 4600A004 */  sqrt.s    $f0, $f20
/* DE2A8 801473C8 46000032 */  c.eq.s    $f0, $f0
/* DE2AC 801473CC 00000000 */  nop
/* DE2B0 801473D0 45030004 */  bc1tl     .LIQUE_801473E4
/* DE2B4 801473D4 46000506 */   mov.s    $f20, $f0
/* DE2B8 801473D8 0C0183A0 */  jal       sqrtf
/* DE2BC 801473DC 4600A306 */   mov.s    $f12, $f20
/* DE2C0 801473E0 46000506 */  mov.s     $f20, $f0
.LIQUE_801473E4:
/* DE2C4 801473E4 C6200004 */  lwc1      $f0, 0x4($s1)
/* DE2C8 801473E8 46000007 */  neg.s     $f0, $f0
/* DE2CC 801473EC 46000002 */  mul.s     $f0, $f0, $f0
/* DE2D0 801473F0 00000000 */  nop
/* DE2D4 801473F4 C6220024 */  lwc1      $f2, 0x24($s1)
/* DE2D8 801473F8 46021082 */  mul.s     $f2, $f2, $f2
/* DE2DC 801473FC 00000000 */  nop
/* DE2E0 80147400 46020300 */  add.s     $f12, $f0, $f2
/* DE2E4 80147404 44800000 */  mtc1      $zero, $f0
/* DE2E8 80147408 C6360014 */  lwc1      $f22, 0x14($s1)
/* DE2EC 8014740C 46006032 */  c.eq.s    $f12, $f0
/* DE2F0 80147410 00000000 */  nop
/* DE2F4 80147414 45010009 */  bc1t      .LIQUE_8014743C
/* DE2F8 80147418 00000000 */   nop
/* DE2FC 8014741C 46006004 */  sqrt.s    $f0, $f12
/* DE300 80147420 46000032 */  c.eq.s    $f0, $f0
/* DE304 80147424 00000000 */  nop
/* DE308 80147428 45030004 */  bc1tl     .LIQUE_8014743C
/* DE30C 8014742C 46000306 */   mov.s    $f12, $f0
/* DE310 80147430 0C0183A0 */  jal       sqrtf
/* DE314 80147434 00000000 */   nop
/* DE318 80147438 46000306 */  mov.s     $f12, $f0
.LIQUE_8014743C:
/* DE31C 8014743C 460CA002 */  mul.s     $f0, $f20, $f12
/* DE320 80147440 00000000 */  nop
/* DE324 80147444 4616C082 */  mul.s     $f2, $f24, $f22
/* DE328 80147448 00000000 */  nop
/* DE32C 8014744C 46020000 */  add.s     $f0, $f0, $f2
/* DE330 80147450 2A620100 */  slti      $v0, $s3, 0x100
/* DE334 80147454 44901000 */  mtc1      $s0, $f2
/* DE338 80147458 00000000 */  nop
/* DE33C 8014745C 468010A0 */  cvt.s.w   $f2, $f2
/* DE340 80147460 46000007 */  neg.s     $f0, $f0
/* DE344 80147464 46020702 */  mul.s     $f28, $f0, $f2
/* DE348 80147468 00000000 */  nop
/* DE34C 8014746C 50400001 */  beql      $v0, $zero, .LIQUE_80147474
/* DE350 80147470 241300FF */   addiu    $s3, $zero, 0xFF
.LIQUE_80147474:
/* DE354 80147474 2A420100 */  slti      $v0, $s2, 0x100
/* DE358 80147478 50400001 */  beql      $v0, $zero, .LIQUE_80147480
/* DE35C 8014747C 241200FF */   addiu    $s2, $zero, 0xFF
.LIQUE_80147480:
/* DE360 80147480 2A820100 */  slti      $v0, $s4, 0x100
/* DE364 80147484 50400001 */  beql      $v0, $zero, .LIQUE_8014748C
/* DE368 80147488 241400FF */   addiu    $s4, $zero, 0xFF
.LIQUE_8014748C:
/* DE36C 8014748C 2AC20100 */  slti      $v0, $s6, 0x100
/* DE370 80147490 50400001 */  beql      $v0, $zero, .LIQUE_80147498
/* DE374 80147494 241600FF */   addiu    $s6, $zero, 0xFF
.LIQUE_80147498:
/* DE378 80147498 2AA20100 */  slti      $v0, $s5, 0x100
/* DE37C 8014749C 50400001 */  beql      $v0, $zero, .LIQUE_801474A4
/* DE380 801474A0 241500FF */   addiu    $s5, $zero, 0xFF
.LIQUE_801474A4:
/* DE384 801474A4 8FAF00A8 */  lw        $t7, 0xA8($sp)
/* DE388 801474A8 29E20100 */  slti      $v0, $t7, 0x100
/* DE38C 801474AC 14400003 */  bnez      $v0, .LIQUE_801474BC
/* DE390 801474B0 3C07FC21 */   lui      $a3, (0xFC21FE07 >> 16)
/* DE394 801474B4 240F00FF */  addiu     $t7, $zero, 0xFF
/* DE398 801474B8 AFAF00A8 */  sw        $t7, 0xA8($sp)
.LIQUE_801474BC:
/* DE39C 801474BC 34E7FE07 */  ori       $a3, $a3, (0xFC21FE07 & 0xFFFF)
/* DE3A0 801474C0 3C06F167 */  lui       $a2, (0xF167F27F >> 16)
/* DE3A4 801474C4 34C6F27F */  ori       $a2, $a2, (0xF167F27F & 0xFFFF)
/* DE3A8 801474C8 3C0DFF10 */  lui       $t5, (0xFF10013F >> 16)
/* DE3AC 801474CC 35AD013F */  ori       $t5, $t5, (0xFF10013F & 0xFFFF)
/* DE3B0 801474D0 3C080004 */  lui       $t0, (0x40004 >> 16)
/* DE3B4 801474D4 35080004 */  ori       $t0, $t0, (0x40004 & 0xFFFF)
/* DE3B8 801474D8 3C0FE300 */  lui       $t7, (0xE3000A11 >> 16)
/* DE3BC 801474DC 35EF0A11 */  ori       $t7, $t7, (0xE3000A11 & 0xFFFF)
/* DE3C0 801474E0 AFAF0010 */  sw        $t7, 0x10($sp)
/* DE3C4 801474E4 3C0FE200 */  lui       $t7, (0xE200001C >> 16)
/* DE3C8 801474E8 35EF001C */  ori       $t7, $t7, (0xE200001C & 0xFFFF)
/* DE3CC 801474EC 3C090F0A */  lui       $t1, (0xF0A4000 >> 16)
/* DE3D0 801474F0 35294000 */  ori       $t1, $t1, (0xF0A4000 & 0xFFFF)
/* DE3D4 801474F4 3C0BFC34 */  lui       $t3, (0xFC347E68 >> 16)
/* DE3D8 801474F8 356B7E68 */  ori       $t3, $t3, (0xFC347E68 & 0xFFFF)
/* DE3DC 801474FC 3C0A55FE */  lui       $t2, (0x55FEFD7E >> 16)
/* DE3E0 80147500 354AFD7E */  ori       $t2, $t2, (0x55FEFD7E & 0xFFFF)
/* DE3E4 80147504 3C0CE404 */  lui       $t4, (0xE4040004 >> 16)
/* DE3E8 80147508 358C0004 */  ori       $t4, $t4, (0xE4040004 & 0xFFFF)
/* DE3EC 8014750C 3C0E1000 */  lui       $t6, (0x10000400 >> 16)
/* DE3F0 80147510 3C17800A */  lui       $s7, %hi(gMainGfxPos)
/* DE3F4 80147514 26F79244 */  addiu     $s7, $s7, %lo(gMainGfxPos)
/* DE3F8 80147518 35CE0400 */  ori       $t6, $t6, (0x10000400 & 0xFFFF)
/* DE3FC 8014751C 3C05FA00 */  lui       $a1, (0xFA000000 >> 16)
/* DE400 80147520 00131E00 */  sll       $v1, $s3, 24
/* DE404 80147524 324200FF */  andi      $v0, $s2, 0xFF
/* DE408 80147528 00021400 */  sll       $v0, $v0, 16
/* DE40C 8014752C 00621825 */  or        $v1, $v1, $v0
/* DE410 80147530 328200FF */  andi      $v0, $s4, 0xFF
/* DE414 80147534 00021200 */  sll       $v0, $v0, 8
/* DE418 80147538 00621825 */  or        $v1, $v1, $v0
/* DE41C 8014753C 3C138016 */  lui       $s3, %hi(D_80159880)
/* DE420 80147540 2673BC00 */  addiu     $s3, $s3, %lo(D_80159880)
/* DE424 80147544 3C12ED00 */  lui       $s2, (0xED000000 >> 16)
/* DE428 80147548 AFAF0014 */  sw        $t7, 0x14($sp)
/* DE42C 8014754C 8EF00000 */  lw        $s0, 0x0($s7)
/* DE430 80147550 3C14FB00 */  lui       $s4, (0xFB000000 >> 16)
/* DE434 80147554 0200202D */  daddu     $a0, $s0, $zero
/* DE438 80147558 26100008 */  addiu     $s0, $s0, 0x8
/* DE43C 8014755C AEF00000 */  sw        $s0, 0x0($s7)
/* DE440 80147560 AC850000 */  sw        $a1, 0x0($a0)
/* DE444 80147564 8FAF0084 */  lw        $t7, 0x84($sp)
/* DE448 80147568 3C11E700 */  lui       $s1, (0xE7000000 >> 16)
/* DE44C 8014756C 31E200FF */  andi      $v0, $t7, 0xFF
/* DE450 80147570 00621825 */  or        $v1, $v1, $v0
/* DE454 80147574 26020008 */  addiu     $v0, $s0, 0x8
/* DE458 80147578 AC830004 */  sw        $v1, 0x4($a0)
/* DE45C 8014757C AEE20000 */  sw        $v0, 0x0($s7)
/* DE460 80147580 26020010 */  addiu     $v0, $s0, 0x10
/* DE464 80147584 AE070000 */  sw        $a3, 0x0($s0)
/* DE468 80147588 AE060004 */  sw        $a2, 0x4($s0)
/* DE46C 8014758C AEE20000 */  sw        $v0, 0x0($s7)
/* DE470 80147590 26020018 */  addiu     $v0, $s0, 0x18
/* DE474 80147594 AE0D0008 */  sw        $t5, 0x8($s0)
/* DE478 80147598 AE13000C */  sw        $s3, 0xC($s0)
/* DE47C 8014759C AEE20000 */  sw        $v0, 0x0($s7)
/* DE480 801475A0 26020020 */  addiu     $v0, $s0, 0x20
/* DE484 801475A4 AE120010 */  sw        $s2, 0x10($s0)
/* DE488 801475A8 AE080014 */  sw        $t0, 0x14($s0)
/* DE48C 801475AC AEE20000 */  sw        $v0, 0x0($s7)
/* DE490 801475B0 8FAF0010 */  lw        $t7, 0x10($sp)
/* DE494 801475B4 24020CF0 */  addiu     $v0, $zero, 0xCF0
/* DE498 801475B8 AE02001C */  sw        $v0, 0x1C($s0)
/* DE49C 801475BC 26020028 */  addiu     $v0, $s0, 0x28
/* DE4A0 801475C0 AE0F0018 */  sw        $t7, 0x18($s0)
/* DE4A4 801475C4 AEE20000 */  sw        $v0, 0x0($s7)
/* DE4A8 801475C8 8FAF0014 */  lw        $t7, 0x14($sp)
/* DE4AC 801475CC 26020030 */  addiu     $v0, $s0, 0x30
/* DE4B0 801475D0 AE090024 */  sw        $t1, 0x24($s0)
/* DE4B4 801475D4 AE0F0020 */  sw        $t7, 0x20($s0)
/* DE4B8 801475D8 AEE20000 */  sw        $v0, 0x0($s7)
/* DE4BC 801475DC 26020038 */  addiu     $v0, $s0, 0x38
/* DE4C0 801475E0 AE03002C */  sw        $v1, 0x2C($s0)
/* DE4C4 801475E4 00161E00 */  sll       $v1, $s6, 24
/* DE4C8 801475E8 AE050028 */  sw        $a1, 0x28($s0)
/* DE4CC 801475EC AEE20000 */  sw        $v0, 0x0($s7)
/* DE4D0 801475F0 32A200FF */  andi      $v0, $s5, 0xFF
/* DE4D4 801475F4 00021400 */  sll       $v0, $v0, 16
/* DE4D8 801475F8 AE140030 */  sw        $s4, 0x30($s0)
/* DE4DC 801475FC 8FAF00A8 */  lw        $t7, 0xA8($sp)
/* DE4E0 80147600 00621825 */  or        $v1, $v1, $v0
/* DE4E4 80147604 31E200FF */  andi      $v0, $t7, 0xFF
/* DE4E8 80147608 00021200 */  sll       $v0, $v0, 8
/* DE4EC 8014760C 00621825 */  or        $v1, $v1, $v0
/* DE4F0 80147610 26020040 */  addiu     $v0, $s0, 0x40
/* DE4F4 80147614 AE030034 */  sw        $v1, 0x34($s0)
/* DE4F8 80147618 AEE20000 */  sw        $v0, 0x0($s7)
/* DE4FC 8014761C 26020048 */  addiu     $v0, $s0, 0x48
/* DE500 80147620 AE0B0038 */  sw        $t3, 0x38($s0)
/* DE504 80147624 AE0A003C */  sw        $t2, 0x3C($s0)
/* DE508 80147628 AEE20000 */  sw        $v0, 0x0($s7)
/* DE50C 8014762C 3C020200 */  lui       $v0, (0x2000000 >> 16)
/* DE510 80147630 AE020044 */  sw        $v0, 0x44($s0)
/* DE514 80147634 26020050 */  addiu     $v0, $s0, 0x50
/* DE518 80147638 AE0C0040 */  sw        $t4, 0x40($s0)
/* DE51C 8014763C AEE20000 */  sw        $v0, 0x0($s7)
/* DE520 80147640 3C02E100 */  lui       $v0, (0xE1000000 >> 16)
/* DE524 80147644 AE020048 */  sw        $v0, 0x48($s0)
/* DE528 80147648 26020058 */  addiu     $v0, $s0, 0x58
/* DE52C 8014764C AE00004C */  sw        $zero, 0x4C($s0)
/* DE530 80147650 AEE20000 */  sw        $v0, 0x0($s7)
/* DE534 80147654 3C02F100 */  lui       $v0, (0xF1000000 >> 16)
/* DE538 80147658 AE020050 */  sw        $v0, 0x50($s0)
/* DE53C 8014765C 26020060 */  addiu     $v0, $s0, 0x60
/* DE540 80147660 AE0E0054 */  sw        $t6, 0x54($s0)
/* DE544 80147664 AEE20000 */  sw        $v0, 0x0($s7)
/* DE548 80147668 3C04800A */  lui       $a0, %hi(nuGfxCfb_ptr)
/* DE54C 8014766C 8C849224 */  lw        $a0, %lo(nuGfxCfb_ptr)($a0)
/* DE550 80147670 26020068 */  addiu     $v0, $s0, 0x68
/* DE554 80147674 AE110058 */  sw        $s1, 0x58($s0)
/* DE558 80147678 AE00005C */  sw        $zero, 0x5C($s0)
/* DE55C 8014767C AEE20000 */  sw        $v0, 0x0($s7)
/* DE560 80147680 0C01836C */  jal       osVirtualToPhysical
/* DE564 80147684 AE0D0060 */   sw       $t5, 0x60($s0)
/* DE568 80147688 3C06F500 */  lui       $a2, (0xF5000110 >> 16)
/* DE56C 8014768C 34C60110 */  ori       $a2, $a2, (0xF5000110 & 0xFFFF)
/* DE570 80147690 3C070703 */  lui       $a3, (0x703C000 >> 16)
/* DE574 80147694 34E7C000 */  ori       $a3, $a3, (0x703C000 & 0xFFFF)
/* DE578 80147698 3C080018 */  lui       $t0, (0x18AC30 >> 16)
/* DE57C 8014769C 8EEA0000 */  lw        $t2, 0x0($s7)
/* DE580 801476A0 3C014080 */  lui       $at, (0x40800000 >> 16)
/* DE584 801476A4 44812000 */  mtc1      $at, $f4
/* DE588 801476A8 3508AC30 */  ori       $t0, $t0, (0x18AC30 & 0xFFFF)
/* DE58C 801476AC AE020064 */  sw        $v0, 0x64($s0)
/* DE590 801476B0 0140282D */  daddu     $a1, $t2, $zero
/* DE594 801476B4 254A0008 */  addiu     $t2, $t2, 0x8
/* DE598 801476B8 25420008 */  addiu     $v0, $t2, 0x8
/* DE59C 801476BC AEEA0000 */  sw        $t2, 0x0($s7)
/* DE5A0 801476C0 AEE20000 */  sw        $v0, 0x0($s7)
/* DE5A4 801476C4 25420010 */  addiu     $v0, $t2, 0x10
/* DE5A8 801476C8 AEE20000 */  sw        $v0, 0x0($s7)
/* DE5AC 801476CC 25420018 */  addiu     $v0, $t2, 0x18
/* DE5B0 801476D0 AEE20000 */  sw        $v0, 0x0($s7)
/* DE5B4 801476D4 87C2000E */  lh        $v0, 0xE($fp)
/* DE5B8 801476D8 87C30010 */  lh        $v1, 0x10($fp)
/* DE5BC 801476DC 44821000 */  mtc1      $v0, $f2
/* DE5C0 801476E0 00000000 */  nop
/* DE5C4 801476E4 468010A0 */  cvt.s.w   $f2, $f2
/* DE5C8 801476E8 46041082 */  mul.s     $f2, $f2, $f4
/* DE5CC 801476EC 00000000 */  nop
/* DE5D0 801476F0 25420020 */  addiu     $v0, $t2, 0x20
/* DE5D4 801476F4 44830000 */  mtc1      $v1, $f0
/* DE5D8 801476F8 00000000 */  nop
/* DE5DC 801476FC 46800020 */  cvt.s.w   $f0, $f0
/* DE5E0 80147700 AEE20000 */  sw        $v0, 0x0($s7)
/* DE5E4 80147704 25420028 */  addiu     $v0, $t2, 0x28
/* DE5E8 80147708 46040002 */  mul.s     $f0, $f0, $f4
/* DE5EC 8014770C 00000000 */  nop
/* DE5F0 80147710 AEE20000 */  sw        $v0, 0x0($s7)
/* DE5F4 80147714 4600128D */  trunc.w.s $f10, $f2
/* DE5F8 80147718 44035000 */  mfc1      $v1, $f10
/* DE5FC 8014771C 00000000 */  nop
/* DE600 80147720 30630FFF */  andi      $v1, $v1, 0xFFF
/* DE604 80147724 00031B00 */  sll       $v1, $v1, 12
/* DE608 80147728 4600028D */  trunc.w.s $f10, $f0
/* DE60C 8014772C 44025000 */  mfc1      $v0, $f10
/* DE610 80147730 00000000 */  nop
/* DE614 80147734 30420FFF */  andi      $v0, $v0, 0xFFF
/* DE618 80147738 00521025 */  or        $v0, $v0, $s2
/* DE61C 8014773C 00621825 */  or        $v1, $v1, $v0
/* DE620 80147740 ACA30000 */  sw        $v1, 0x0($a1)
/* DE624 80147744 87C3000E */  lh        $v1, 0xE($fp)
/* DE628 80147748 87C4000A */  lh        $a0, 0xA($fp)
/* DE62C 8014774C 25420030 */  addiu     $v0, $t2, 0x30
/* DE630 80147750 AEE20000 */  sw        $v0, 0x0($s7)
/* DE634 80147754 87C20010 */  lh        $v0, 0x10($fp)
/* DE638 80147758 00641821 */  addu      $v1, $v1, $a0
/* DE63C 8014775C 44831000 */  mtc1      $v1, $f2
/* DE640 80147760 00000000 */  nop
/* DE644 80147764 468010A0 */  cvt.s.w   $f2, $f2
/* DE648 80147768 25440038 */  addiu     $a0, $t2, 0x38
/* DE64C 8014776C 87C3000C */  lh        $v1, 0xC($fp)
/* DE650 80147770 46041082 */  mul.s     $f2, $f2, $f4
/* DE654 80147774 00000000 */  nop
/* DE658 80147778 AEE40000 */  sw        $a0, 0x0($s7)
/* DE65C 8014777C 00431021 */  addu      $v0, $v0, $v1
/* DE660 80147780 44820000 */  mtc1      $v0, $f0
/* DE664 80147784 00000000 */  nop
/* DE668 80147788 46800020 */  cvt.s.w   $f0, $f0
/* DE66C 8014778C 25420040 */  addiu     $v0, $t2, 0x40
/* DE670 80147790 46040002 */  mul.s     $f0, $f0, $f4
/* DE674 80147794 00000000 */  nop
/* DE678 80147798 AEE20000 */  sw        $v0, 0x0($s7)
/* DE67C 8014779C 4600128D */  trunc.w.s $f10, $f2
/* DE680 801477A0 44025000 */  mfc1      $v0, $f10
/* DE684 801477A4 00000000 */  nop
/* DE688 801477A8 30420FFF */  andi      $v0, $v0, 0xFFF
/* DE68C 801477AC 00021300 */  sll       $v0, $v0, 12
/* DE690 801477B0 4600028D */  trunc.w.s $f10, $f0
/* DE694 801477B4 44035000 */  mfc1      $v1, $f10
/* DE698 801477B8 00000000 */  nop
/* DE69C 801477BC 30630FFF */  andi      $v1, $v1, 0xFFF
/* DE6A0 801477C0 00431025 */  or        $v0, $v0, $v1
/* DE6A4 801477C4 ACA20004 */  sw        $v0, 0x4($a1)
/* DE6A8 801477C8 3C02FD10 */  lui       $v0, (0xFD100000 >> 16)
/* DE6AC 801477CC AD420000 */  sw        $v0, 0x0($t2)
/* DE6B0 801477D0 3C02E800 */  lui       $v0, (0xE8000000 >> 16)
/* DE6B4 801477D4 AD420008 */  sw        $v0, 0x8($t2)
/* DE6B8 801477D8 3C020700 */  lui       $v0, (0x7000000 >> 16)
/* DE6BC 801477DC AD420014 */  sw        $v0, 0x14($t2)
/* DE6C0 801477E0 3C02E600 */  lui       $v0, (0xE6000000 >> 16)
/* DE6C4 801477E4 AD420018 */  sw        $v0, 0x18($t2)
/* DE6C8 801477E8 3C02F000 */  lui       $v0, (0xF0000000 >> 16)
/* DE6CC 801477EC AD530004 */  sw        $s3, 0x4($t2)
/* DE6D0 801477F0 AD40000C */  sw        $zero, 0xC($t2)
/* DE6D4 801477F4 AD460010 */  sw        $a2, 0x10($t2)
/* DE6D8 801477F8 AD40001C */  sw        $zero, 0x1C($t2)
/* DE6DC 801477FC AD420020 */  sw        $v0, 0x20($t2)
/* DE6E0 80147800 AD470024 */  sw        $a3, 0x24($t2)
/* DE6E4 80147804 AD510028 */  sw        $s1, 0x28($t2)
/* DE6E8 80147808 AD40002C */  sw        $zero, 0x2C($t2)
/* DE6EC 8014780C 8FAF0010 */  lw        $t7, 0x10($sp)
/* DE6F0 80147810 3C096464 */  lui       $t1, (0x646464FF >> 16)
/* DE6F4 80147814 AD4F0030 */  sw        $t7, 0x30($t2)
/* DE6F8 80147818 AD480034 */  sw        $t0, 0x34($t2)
/* DE6FC 8014781C 8FAF0014 */  lw        $t7, 0x14($sp)
/* DE700 80147820 352964FF */  ori       $t1, $t1, (0x646464FF & 0xFFFF)
/* DE704 80147824 AD4F0038 */  sw        $t7, 0x38($t2)
/* DE708 80147828 8FA200B0 */  lw        $v0, 0xB0($sp)
/* DE70C 8014782C 3C030C08 */  lui       $v1, (0xC080000 >> 16)
/* DE710 80147830 00431025 */  or        $v0, $v0, $v1
/* DE714 80147834 AD42003C */  sw        $v0, 0x3C($t2)
/* DE718 80147838 25420048 */  addiu     $v0, $t2, 0x48
/* DE71C 8014783C AEE20000 */  sw        $v0, 0x0($s7)
/* DE720 80147840 AD540040 */  sw        $s4, 0x40($t2)
/* DE724 80147844 AD490044 */  sw        $t1, 0x44($t2)
/* DE728 80147848 8FAF0084 */  lw        $t7, 0x84($sp)
/* DE72C 8014784C 240200FF */  addiu     $v0, $zero, 0xFF
/* DE730 80147850 15E20005 */  bne       $t7, $v0, .LIQUE_80147868
/* DE734 80147854 3C04FC11 */   lui      $a0, (0xFC117E80 >> 16)
/* DE738 80147858 34847E80 */  ori       $a0, $a0, (0xFC117E80 & 0xFFFF)
/* DE73C 8014785C 3C03F5FF */  lui       $v1, (0xF5FFF438 >> 16)
/* DE740 80147860 08051E1D */  j         .LIQUE_80147874
/* DE744 80147864 3463F438 */   ori      $v1, $v1, (0xF5FFF438 & 0xFFFF)
.LIQUE_80147868:
/* DE748 80147868 34843480 */  ori       $a0, $a0, (0xFC113480 & 0xFFFF)
/* DE74C 8014786C 3C03F5FF */  lui       $v1, (0xF5FFFE38 >> 16)
/* DE750 80147870 3463FE38 */  ori       $v1, $v1, (0xF5FFFE38 & 0xFFFF)
.LIQUE_80147874:
/* DE754 80147874 25420050 */  addiu     $v0, $t2, 0x50
/* DE758 80147878 AEE20000 */  sw        $v0, 0x0($s7)
/* DE75C 8014787C AD440048 */  sw        $a0, 0x48($t2)
/* DE760 80147880 AD43004C */  sw        $v1, 0x4C($t2)
/* DE764 80147884 3C03800A */  lui       $v1, %hi(gMainGfxPos)
/* DE768 80147888 24639244 */  addiu     $v1, $v1, %lo(gMainGfxPos)
/* DE76C 8014788C 8C620000 */  lw        $v0, 0x0($v1)
/* DE770 80147890 461ED002 */  mul.s     $f0, $f26, $f30
/* DE774 80147894 00000000 */  nop
/* DE778 80147898 0040382D */  daddu     $a3, $v0, $zero
/* DE77C 8014789C 24420008 */  addiu     $v0, $v0, 0x8
/* DE780 801478A0 AC620000 */  sw        $v0, 0x0($v1)
/* DE784 801478A4 8FAF0074 */  lw        $t7, 0x74($sp)
/* DE788 801478A8 3C04F200 */  lui       $a0, (0xF2000000 >> 16)
/* DE78C 801478AC 25E30100 */  addiu     $v1, $t7, 0x100
/* DE790 801478B0 00031880 */  sll       $v1, $v1, 2
/* DE794 801478B4 4600028D */  trunc.w.s $f10, $f0
/* DE798 801478B8 44055000 */  mfc1      $a1, $f10
/* DE79C 801478BC 00000000 */  nop
/* DE7A0 801478C0 00651821 */  addu      $v1, $v1, $a1
/* DE7A4 801478C4 30630FFF */  andi      $v1, $v1, 0xFFF
/* DE7A8 801478C8 8FAF0078 */  lw        $t7, 0x78($sp)
/* DE7AC 801478CC 00031B00 */  sll       $v1, $v1, 12
/* DE7B0 801478D0 25E20100 */  addiu     $v0, $t7, 0x100
/* DE7B4 801478D4 00021080 */  sll       $v0, $v0, 2
/* DE7B8 801478D8 4600E28D */  trunc.w.s $f10, $f28
/* DE7BC 801478DC 44065000 */  mfc1      $a2, $f10
/* DE7C0 801478E0 00000000 */  nop
/* DE7C4 801478E4 00461021 */  addu      $v0, $v0, $a2
/* DE7C8 801478E8 30420FFF */  andi      $v0, $v0, 0xFFF
/* DE7CC 801478EC 00441025 */  or        $v0, $v0, $a0
/* DE7D0 801478F0 00621825 */  or        $v1, $v1, $v0
/* DE7D4 801478F4 ACE30000 */  sw        $v1, 0x0($a3)
/* DE7D8 801478F8 8FAF007C */  lw        $t7, 0x7C($sp)
/* DE7DC 801478FC 8FA20080 */  lw        $v0, 0x80($sp)
/* DE7E0 80147900 25E300FF */  addiu     $v1, $t7, 0xFF
/* DE7E4 80147904 00031880 */  sll       $v1, $v1, 2
/* DE7E8 80147908 00651821 */  addu      $v1, $v1, $a1
/* DE7EC 8014790C 30630FFF */  andi      $v1, $v1, 0xFFF
/* DE7F0 80147910 00031B00 */  sll       $v1, $v1, 12
/* DE7F4 80147914 244200FF */  addiu     $v0, $v0, 0xFF
/* DE7F8 80147918 00021080 */  sll       $v0, $v0, 2
/* DE7FC 8014791C 00461021 */  addu      $v0, $v0, $a2
/* DE800 80147920 30420FFF */  andi      $v0, $v0, 0xFFF
/* DE804 80147924 00621825 */  or        $v1, $v1, $v0
/* DE808 80147928 ACE30004 */  sw        $v1, 0x4($a3)
/* DE80C 8014792C 8FBF003C */  lw        $ra, 0x3C($sp)
/* DE810 80147930 8FBE0038 */  lw        $fp, 0x38($sp)
/* DE814 80147934 8FB70034 */  lw        $s7, 0x34($sp)
/* DE818 80147938 8FB60030 */  lw        $s6, 0x30($sp)
/* DE81C 8014793C 8FB5002C */  lw        $s5, 0x2C($sp)
/* DE820 80147940 8FB40028 */  lw        $s4, 0x28($sp)
/* DE824 80147944 8FB30024 */  lw        $s3, 0x24($sp)
/* DE828 80147948 8FB20020 */  lw        $s2, 0x20($sp)
/* DE82C 8014794C 8FB1001C */  lw        $s1, 0x1C($sp)
/* DE830 80147950 8FB00018 */  lw        $s0, 0x18($sp)
/* DE834 80147954 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* DE838 80147958 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* DE83C 8014795C D7BA0058 */  ldc1      $f26, 0x58($sp)
/* DE840 80147960 D7B80050 */  ldc1      $f24, 0x50($sp)
/* DE844 80147964 D7B60048 */  ldc1      $f22, 0x48($sp)
/* DE848 80147968 D7B40040 */  ldc1      $f20, 0x40($sp)
/* DE84C 8014796C 03E00008 */  jr        $ra
/* DE850 80147970 27BD0070 */   addiu    $sp, $sp, 0x70
