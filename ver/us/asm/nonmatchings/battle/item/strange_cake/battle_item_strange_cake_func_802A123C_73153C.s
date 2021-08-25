.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel battle_item_strange_cake_func_802A123C_73153C
/* 73153C 802A123C 3C03802A */  lui       $v1, %hi(D_802A2DEC)
/* 731540 802A1240 8C632DEC */  lw        $v1, %lo(D_802A2DEC)($v1)
/* 731544 802A1244 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 731548 802A1248 AFBF0064 */  sw        $ra, 0x64($sp)
/* 73154C 802A124C AFB40060 */  sw        $s4, 0x60($sp)
/* 731550 802A1250 AFB3005C */  sw        $s3, 0x5c($sp)
/* 731554 802A1254 AFB20058 */  sw        $s2, 0x58($sp)
/* 731558 802A1258 AFB10054 */  sw        $s1, 0x54($sp)
/* 73155C 802A125C 28620006 */  slti      $v0, $v1, 6
/* 731560 802A1260 10400058 */  beqz      $v0, .L802A13C4
/* 731564 802A1264 AFB00050 */   sw       $s0, 0x50($sp)
/* 731568 802A1268 18600056 */  blez      $v1, .L802A13C4
/* 73156C 802A126C 24050007 */   addiu    $a1, $zero, 7
/* 731570 802A1270 0000202D */  daddu     $a0, $zero, $zero
/* 731574 802A1274 2406006A */  addiu     $a2, $zero, 0x6a
/* 731578 802A1278 24020024 */  addiu     $v0, $zero, 0x24
/* 73157C 802A127C AFA20014 */  sw        $v0, 0x14($sp)
/* 731580 802A1280 AFA20018 */  sw        $v0, 0x18($sp)
/* 731584 802A1284 240200FF */  addiu     $v0, $zero, 0xff
/* 731588 802A1288 AFA2001C */  sw        $v0, 0x1c($sp)
/* 73158C 802A128C 24020140 */  addiu     $v0, $zero, 0x140
/* 731590 802A1290 AFA20044 */  sw        $v0, 0x44($sp)
/* 731594 802A1294 240200F0 */  addiu     $v0, $zero, 0xf0
/* 731598 802A1298 24070056 */  addiu     $a3, $zero, 0x56
/* 73159C 802A129C AFA00010 */  sw        $zero, 0x10($sp)
/* 7315A0 802A12A0 AFA00020 */  sw        $zero, 0x20($sp)
/* 7315A4 802A12A4 AFA00024 */  sw        $zero, 0x24($sp)
/* 7315A8 802A12A8 AFA00028 */  sw        $zero, 0x28($sp)
/* 7315AC 802A12AC AFA0002C */  sw        $zero, 0x2c($sp)
/* 7315B0 802A12B0 AFA00030 */  sw        $zero, 0x30($sp)
/* 7315B4 802A12B4 AFA00034 */  sw        $zero, 0x34($sp)
/* 7315B8 802A12B8 AFA00038 */  sw        $zero, 0x38($sp)
/* 7315BC 802A12BC AFA0003C */  sw        $zero, 0x3c($sp)
/* 7315C0 802A12C0 AFA00040 */  sw        $zero, 0x40($sp)
/* 7315C4 802A12C4 AFA20048 */  sw        $v0, 0x48($sp)
/* 7315C8 802A12C8 0C03D4B8 */  jal       draw_box
/* 7315CC 802A12CC AFA0004C */   sw       $zero, 0x4c($sp)
/* 7315D0 802A12D0 3C06ED1B */  lui       $a2, 0xed1b
/* 7315D4 802A12D4 34C60168 */  ori       $a2, $a2, 0x168
/* 7315D8 802A12D8 3C050022 */  lui       $a1, 0x22
/* 7315DC 802A12DC 34A5C1D8 */  ori       $a1, $a1, 0xc1d8
/* 7315E0 802A12E0 0000882D */  daddu     $s1, $zero, $zero
/* 7315E4 802A12E4 3C1451EB */  lui       $s4, 0x51eb
/* 7315E8 802A12E8 3694851F */  ori       $s4, $s4, 0x851f
/* 7315EC 802A12EC 0220982D */  daddu     $s3, $s1, $zero
/* 7315F0 802A12F0 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 7315F4 802A12F4 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 7315F8 802A12F8 8C820000 */  lw        $v0, ($a0)
/* 7315FC 802A12FC 3C12802A */  lui       $s2, %hi(D_802A2DD8)
/* 731600 802A1300 26522DD8 */  addiu     $s2, $s2, %lo(D_802A2DD8)
/* 731604 802A1304 0040182D */  daddu     $v1, $v0, $zero
/* 731608 802A1308 24420008 */  addiu     $v0, $v0, 8
/* 73160C 802A130C AC820000 */  sw        $v0, ($a0)
/* 731610 802A1310 AC660000 */  sw        $a2, ($v1)
/* 731614 802A1314 AC650004 */  sw        $a1, 4($v1)
.L802A1318:
/* 731618 802A1318 2405007C */  addiu     $a1, $zero, 0x7c
/* 73161C 802A131C 3C02802A */  lui       $v0, %hi(D_802A2DF4)
/* 731620 802A1320 8C422DF4 */  lw        $v0, %lo(D_802A2DF4)($v0)
/* 731624 802A1324 8E500000 */  lw        $s0, ($s2)
/* 731628 802A1328 00540018 */  mult      $v0, $s4
/* 73162C 802A132C 26520004 */  addiu     $s2, $s2, 4
/* 731630 802A1330 26310001 */  addiu     $s1, $s1, 1
/* 731634 802A1334 0200202D */  daddu     $a0, $s0, $zero
/* 731638 802A1338 000217C3 */  sra       $v0, $v0, 0x1f
/* 73163C 802A133C 00004010 */  mfhi      $t0
/* 731640 802A1340 00083143 */  sra       $a2, $t0, 5
/* 731644 802A1344 00C23023 */  subu      $a2, $a2, $v0
/* 731648 802A1348 24C6FF98 */  addiu     $a2, $a2, -0x68
/* 73164C 802A134C 0C051261 */  jal       set_hud_element_render_pos
/* 731650 802A1350 02663023 */   subu     $a2, $s3, $a2
/* 731654 802A1354 0C0511F8 */  jal       draw_hud_element_3
/* 731658 802A1358 0200202D */   daddu    $a0, $s0, $zero
/* 73165C 802A135C 2A220005 */  slti      $v0, $s1, 5
/* 731660 802A1360 1440FFED */  bnez      $v0, .L802A1318
/* 731664 802A1364 2673001A */   addiu    $s3, $s3, 0x1a
/* 731668 802A1368 3C0251EB */  lui       $v0, 0x51eb
/* 73166C 802A136C 3442851F */  ori       $v0, $v0, 0x851f
/* 731670 802A1370 2405007C */  addiu     $a1, $zero, 0x7c
/* 731674 802A1374 00113040 */  sll       $a2, $s1, 1
/* 731678 802A1378 00D13021 */  addu      $a2, $a2, $s1
/* 73167C 802A137C 00063080 */  sll       $a2, $a2, 2
/* 731680 802A1380 3C03802A */  lui       $v1, %hi(D_802A2DF4)
/* 731684 802A1384 8C632DF4 */  lw        $v1, %lo(D_802A2DF4)($v1)
/* 731688 802A1388 00D13021 */  addu      $a2, $a2, $s1
/* 73168C 802A138C 00620018 */  mult      $v1, $v0
/* 731690 802A1390 3C10802A */  lui       $s0, %hi(D_802A2DD8)
/* 731694 802A1394 8E102DD8 */  lw        $s0, %lo(D_802A2DD8)($s0)
/* 731698 802A1398 00063040 */  sll       $a2, $a2, 1
/* 73169C 802A139C 0200202D */  daddu     $a0, $s0, $zero
/* 7316A0 802A13A0 00031FC3 */  sra       $v1, $v1, 0x1f
/* 7316A4 802A13A4 00004010 */  mfhi      $t0
/* 7316A8 802A13A8 00081143 */  sra       $v0, $t0, 5
/* 7316AC 802A13AC 00431023 */  subu      $v0, $v0, $v1
/* 7316B0 802A13B0 2442FF98 */  addiu     $v0, $v0, -0x68
/* 7316B4 802A13B4 0C051261 */  jal       set_hud_element_render_pos
/* 7316B8 802A13B8 00C23023 */   subu     $a2, $a2, $v0
/* 7316BC 802A13BC 0C0511F8 */  jal       draw_hud_element_3
/* 7316C0 802A13C0 0200202D */   daddu    $a0, $s0, $zero
.L802A13C4:
/* 7316C4 802A13C4 8FBF0064 */  lw        $ra, 0x64($sp)
/* 7316C8 802A13C8 8FB40060 */  lw        $s4, 0x60($sp)
/* 7316CC 802A13CC 8FB3005C */  lw        $s3, 0x5c($sp)
/* 7316D0 802A13D0 8FB20058 */  lw        $s2, 0x58($sp)
/* 7316D4 802A13D4 8FB10054 */  lw        $s1, 0x54($sp)
/* 7316D8 802A13D8 8FB00050 */  lw        $s0, 0x50($sp)
/* 7316DC 802A13DC 03E00008 */  jr        $ra
/* 7316E0 802A13E0 27BD0068 */   addiu    $sp, $sp, 0x68
